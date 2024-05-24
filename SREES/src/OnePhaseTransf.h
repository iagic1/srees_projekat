//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/View.h>
#include <gui/Label.h>
#include <gui/LineEdit.h>
#include <gui/TextEdit.h>
#include <gui/HorizontalLayout.h>

class OnePhaseTransf : public gui::View
{
private:
protected:
    gui::GridLayout _gl;
    gui::GridLayout _gl1;
    gui::GridLayout _gl2;
    gui::Label _unos1;
    gui::Label _unos2;
    gui::Label _unos3;
    gui::Label _unos4;
    gui::Label _unos5;
    gui::Label _unos6;
    gui::Label _unos7;
    gui::NumericEdit _S;
    gui::NumericEdit _Unp;
    gui::NumericEdit _Uns;
    gui::NumericEdit _uk1;
    gui::NumericEdit _PPH1;
    gui::NumericEdit _PKS1;
    gui::NumericEdit _I01;

    gui::Button _btn;
    gui::Label _check;
    gui::CheckBox _VF;

    gui::Label _rez1_ks;
    gui::Label _rez1_ph;
    gui::TextEdit _z;
    gui::TextEdit _y;
    gui::Label _rez4;
    gui::TextEdit _Y;

public:
    OnePhaseTransf()
    : _gl(10, 8)
    , _gl1(10, 8)
    , _gl2(1, 2)
    , _unos1("Nominalna snaga [VA]: ")
    , _unos2("Nominalni linijski napon primara [V]: ")
    , _unos3("Nominalni linijski napon sekundara [V]: ")
    , _unos4("uk(%) [V]: ")
    , _unos5("I0 [A]: ")
    , _unos6("PPH [W]: ")
    , _unos7("PKS [W]: ")
    , _check("Sa koje strane je vršen eksperiment - VF: ")
    , _rez1_ks("Rezultati eksperimenata kratkog spoja: ")
    , _rez1_ph("Rezultati eksperimenata praznog hoda: ")
    , _rez4("PI ekvivalent transformatora: ")
    , _S(td::decimal4, gui::LineEdit::Messages::Send)
    , _Unp(td::decimal4, gui::LineEdit::Messages::Send)
    , _Uns(td::decimal4, gui::LineEdit::Messages::Send)
    , _uk1(td::decimal4, gui::LineEdit::Messages::Send)
    , _I01(td::decimal4, gui::LineEdit::Messages::Send)
    , _PPH1(td::decimal4, gui::LineEdit::Messages::Send)
    , _PKS1(td::decimal4, gui::LineEdit::Messages::Send)
    , _VF(nullptr)
    , _btn("Izračunaj")
    {
        _z.setAsReadOnly();
        _y.setAsReadOnly();
        _Y.setAsReadOnly();
        
        _gl.insert(1, 0, _unos1); _gl.insert(1, 1, _S);
        _gl.insert(2, 0, _unos2); _gl.insert(2, 1, _Unp);
        _gl.insert(3, 0, _unos3); _gl.insert(3, 1, _Uns);
        _gl.insert(4, 0, _check); _gl.insert(4, 1, _VF);

        _gl.insert(5, 0, _unos4); _gl.insert(5, 1, _uk1);
        _gl.insert(6, 0, _unos5); _gl.insert(6, 1, _I01);
        _gl.insert(7, 0, _unos6); _gl.insert(7, 1, _PPH1);
        _gl.insert(8, 0, _unos7); _gl.insert(8, 1, _PKS1);

        _gl.insert(9, 0, _btn);

        _gl1.insert(0, 0, _rez1_ks); _gl1.insert(1, 0, _z);
        _gl1.insert(2, 0, _rez1_ph); _gl1.insert(3, 0, _y);
        _gl1.insert(4, 0, _rez4); _gl1.insert(5, 0, _Y);

        _gl2.insert(0, 0, _gl); _gl2.insert(0, 1, _gl1);

        gui::View::setLayout(&_gl);
        gui::View::setLayout(&_gl1);
        gui::View::setLayout(&_gl2);
    }

    void writeComplex(gui::TextEdit& txt, td::cmplx z, std::string var_name = "", std::string unit = "") {
        td::Decimal4 x = z.real(), y = z.imag();
        if (var_name != "") txt.appendString(var_name);

        if (x == 0 && y == 0) {
            txt.appendString("0 ");
            if (unit != "") txt.appendString(unit);
            return;
        }
        txt.appendString(x.toString());
        if (y > 0) txt.appendString(" + ");
        else if (y < 0) {
            txt.appendString(" - ");
            y = 0. - y;
        }
        if (y > 0) {
            txt.appendString(y.toString());
            txt.appendString("j");
        }
        txt.appendString(" ");
        if (unit != "") txt.appendString(unit);
    }

    void writeMatrix(gui::TextEdit& txt, std::vector<std::vector<td::cmplx>> M, int placement = 0, std::string var_name = "", std::string unit = "") {
        for (int i = 0; i < M.size(); i++) {
            if (i == placement && var_name != "") txt.appendString(var_name);
            if (i != placement && var_name != "") {
                for (int k = 0; k <= var_name.size() + 2; k++) txt.appendString(" ");
                if (M.size() == 3) txt.appendString(" ");
            }
            txt.appendString("| ");
            for (int j = 0; j < M.at(0).size(); j++) {
                writeComplex(txt, M.at(i).at(j));
                if (j != M.at(0).size() - 1) txt.appendString("      ");
            }
            txt.appendString("| ");
            if (i == placement && unit != "") txt.appendString(unit);
            txt.appendString("\n");
        }
        txt.appendString("\n");
    }
    
    bool onClick(gui::Button* pBtn) override
    {
        if (pBtn == &_btn)
        {
            if (_Unp.getValue().dec4Val() == 0 || _Uns.getValue().dec4Val() == 0 || _S.getValue().dec4Val() == 0) {
                showAlert("Nemoguć proračun", "Nominalna snaga i naponi primara i sekundara ne mogu biti 0!");
                return true;
            }
            // step1: sa koje strane je vrsen eksperiment
            bool isChecked = _VF.isChecked();

            td::Variant Unn;
            if (isChecked) Unn = (((_Unp.getValue()) > (_Uns.getValue())) ? (_Unp.getValue()) : (_Uns.getValue()));
            else Unn = (((_Unp.getValue()) < (_Uns.getValue())) ? (_Unp.getValue()) : (_Uns.getValue()));

            // step2: racunanje z i y
            td::Decimal4 S(_S.getValue().dec4Val());
            td::Decimal4 uk(_uk1.getValue().dec4Val());
            td::Decimal4 PKS(_PKS1.getValue().dec4Val());
            td::Decimal4 Un(Unn.dec4Val());
            td::Decimal4 I0(_I01.getValue().dec4Val());
            td::Decimal4 PPH(_PPH1.getValue().dec4Val());

            td::Decimal4 z_modul = uk * Un * Un / (100 * S);
            td::Decimal4 r = Un * Un * PKS / (S * S);
            td::Decimal4 x = (sqrt(z_modul.getAsFloat() * z_modul.getAsFloat() - r.getAsFloat() * r.getAsFloat()));
            td::cmplx z(r.getAsFloat(), x.getAsFloat());
            
            td::Decimal4 y_modul = I0 / Un;
            td::Decimal4 g = PPH / (Un * Un);
            td::Decimal4 b = (sqrt(y_modul.getAsFloat() * y_modul.getAsFloat() - g.getAsFloat() * g.getAsFloat()));
            td::cmplx y(g.getAsFloat(), b.getAsFloat());

            // step3: proracun matrice
            td::cmplx n(_Unp.getValue().dec4Val() / _Uns.getValue().dec4Val(), 0);
            std::vector<std::vector<td::cmplx>> Y{ {{1. / z + y / 2.}, {n * (-1. / z)}}, {{n * (-1. / z)}, {n * n * (1. / z + y / 2.)}} };

            
            // ispis rezultata
            _z.clean();
            _y.clean();
            _Y.clean();

            writeComplex(_z, z, "z = ", "[Ohm]");
            writeComplex(_y, y, "y = ", "[Ohm]");
            writeMatrix(_Y, Y, 0, "Y = ", "[S]");

            //
            /*gui::NumericEdit _S;
            gui::NumericEdit _Unp;
            gui::NumericEdit _Uns;
            gui::NumericEdit _uk1;
            gui::NumericEdit _PPH1;
            gui::NumericEdit _PKS1;*/

        }
        return false;
    }

};
