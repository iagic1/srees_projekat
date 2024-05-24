//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/View.h>
#include <gui/Label.h>
#include <gui/LineEdit.h>
#include <gui/TextEdit.h>
#include <gui/NumericEdit.h>
#include <gui/CheckBox.h>
#include <gui/Slider.h>
#include <gui/ComboBox.h>
#include <gui/Button.h>
#include <gui/DateEdit.h>
#include <gui/TimeEdit.h>

#include <gui/HorizontalLayout.h>
#include <gui/ProgressIndicator.h>

#include <gui/GridLayout.h>

class ViewCables : public gui::View
{
private:
protected:
    gui::Label _lbl;
    gui::Label _lbl2;
    gui::Label _lbl3;
    gui::ComboBox _comboBox;
    gui::ComboBox _comboBox2;
    gui::ComboBox _comboBox3;

    gui::Label _lbl4;
    gui::Label _lbl5;
    gui::Label _lbl6;
    gui::NumericEdit _f;
    gui::NumericEdit _r;
    gui::NumericEdit _d;

    gui::Button _btn;
    gui::Button _btn1;
    gui::Button _btn2;
    gui::Button _btn3;

    gui::Label _R;
    gui::Label _M;
    gui::Label _R2;
    gui::Label _M2;

    gui::Label _lbl7;
    gui::Label _lbl8;
    gui::Label _lbl9;
    gui::NumericEdit _ro;
    gui::NumericEdit _l;
    gui::NumericEdit _s;

    gui::Label _lbl10;
    gui::Label _lbl11;
    gui::Label _lbl12;
    gui::Label _lbl13;
    gui::Label _lbl14;
    gui::NumericEdit _u1r;
    gui::NumericEdit _i1r;
    gui::NumericEdit _u1i;
    gui::NumericEdit _i1i;
    gui::NumericEdit _z;
    gui::NumericEdit _y;
    gui::NumericEdit _l1;

    gui::Label _lbl15;
    gui::Label _lbl16;
    gui::Label _lbl17;
    gui::Label _lbl18;
    gui::Label _lbl19;
    gui::Label _lbl20;
    gui::Label _lbl21;
    gui::NumericEdit _z0;
    gui::NumericEdit _y0;
    gui::NumericEdit _z1;
    gui::NumericEdit _y1;
    gui::NumericEdit _l11;

    gui::GridLayout _gl;
    gui::GridLayout _gl1;
    gui::GridLayout _gl2;

    td::Decimal4 ks, kp;
    td::Decimal4 Rdc=0;

    gui::Label _lbl22;
    gui::Label _lbl23;
    gui::Label _lbl24;
    gui::Label _lbl25;

    gui::TextEdit _t1;
    gui::TextEdit _t2;
    gui::TextEdit _t3;
    gui::TextEdit _t4;

public:
    ViewCables()
    : _lbl("Materijal provodnika: ")
    , _lbl2("Tip provodnika: ")
    , _lbl3("Suha impregnirana izolacija: ")
    , _lbl4("Frekvencija napajanja [Hz]: ")
    , _lbl5("Poluprečnik provodnika [mm]: ")
    , _lbl6("Udaljenost između osa poluprovodnika [mm]: ")
    , _lbl7("Specifična otpornost provodnika: ")
    , _lbl8("Dužina provodnika: ")
    , _lbl9("Površina poprečnog presjeka provodnika: ")
    , _lbl10("Napon na jednom kraju linije (Re + j Im): ")
    , _lbl11("Struja na jednom kraju linije (Re + j Im): ")
    , _lbl12("Podužna impedansa linije: ")
    , _lbl13("Podužna admitansa linije: ")
    , _lbl14("Dužina provodnika: ")
    , _lbl15("Dužina provodnika: ")
    , _lbl16("Nulta komponenta")
    , _lbl17("Pozitivna komponenta")
    , _lbl18("Podužna admitansa linije: ")
    , _lbl19("Podužna impedansa linije: ")
    , _lbl20("Podužna admitansa linije: ")
    , _lbl21("Podužna impedansa linije: ")
    , _lbl22("Otpor provodnika za istosmjernu struju: ")
    , _lbl23("Otpor provodnika za izmjeničnu struju, faktor skin efekta i efekta blizine:  ")
    , _lbl24("Napon U2 i struja I2 na drugom kraju linije: ")
    , _lbl25("PI ekvivalent prenosne linije: ")
    , _r(td::decimal4, gui::LineEdit::Messages::Send)
    , _d(td::decimal4, gui::LineEdit::Messages::Send)
    , _f(td::decimal4, gui::LineEdit::Messages::Send)
    , _ro(td::decimal4, gui::LineEdit::Messages::Send)
    , _l(td::decimal4, gui::LineEdit::Messages::Send)
    , _s(td::decimal4, gui::LineEdit::Messages::Send)
    , _u1r(td::decimal4, gui::LineEdit::Messages::Send)
    , _i1r(td::decimal4, gui::LineEdit::Messages::Send)
    , _u1i(td::decimal4, gui::LineEdit::Messages::Send)
    , _i1i(td::decimal4, gui::LineEdit::Messages::Send)
    , _z(td::decimal4, gui::LineEdit::Messages::Send)
    , _y(td::decimal4, gui::LineEdit::Messages::Send)
    , _l1(td::decimal4, gui::LineEdit::Messages::Send)
    , _z0(td::decimal4, gui::LineEdit::Messages::Send)
    , _y0(td::decimal4, gui::LineEdit::Messages::Send)
    , _z1(td::decimal4, gui::LineEdit::Messages::Send)
    , _y1(td::decimal4, gui::LineEdit::Messages::Send)
    , _l11(td::decimal4, gui::LineEdit::Messages::Send)
    , _btn("Izračunaj")
    , _btn1("Izračunaj")
    , _btn2("Izračunaj")
    , _btn3("Izračunaj")
    , _R("Proračun otpora provodnika za istosmjernu struju")
    , _M("Model prenosne linije sa raspodijeljenim parametrima")
    , _R2("Proračun otpora provodnika za izmjeničnu struju")
    , _M2("Model prenosne linije sa koncentrisanim parametrima")
    , _gl(21, 8)
    , _gl1(16, 3)
    , _gl2(1, 2)
    {
        _comboBox.addItem("-");
        _comboBox.addItem("Bakar");
        _comboBox.addItem("Aluminijum");
        _comboBox.selectIndex(0);

        _t1.setAsReadOnly();
        _t2.setAsReadOnly();
        _t3.setAsReadOnly();
        _t4.setAsReadOnly();
        
        _gl.insert(0, 0, _R, 3); _gl.insert(0, 3, _btn, td::HAlignment::Right);
        _gl.insert(1, 0, _lbl7); _gl.insert(1, 1, _ro);
        _gl.insert(2, 0, _lbl8); _gl.insert(2, 1, _l);
        _gl.insert(3, 0, _lbl9); _gl.insert(3, 1, _s);
        _gl.insert(4, 0, _R2, 3); _gl.insert(4, 3, _btn1, td::HAlignment::Right);
        _gl.insert(5, 0, _lbl); _gl.insert(5, 1, _comboBox); _gl.insert(5, 2, _lbl4); _gl.insert(5, 3, _f);
        _gl.insert(6, 0, _lbl2); _gl.insert(6, 1, _comboBox2); _gl.insert(6, 2, _lbl5); _gl.insert(6, 3, _r);
        _gl.insert(7, 0, _lbl3); _gl.insert(7, 1, _comboBox3); _gl.insert(7, 2, _lbl6); _gl.insert(7, 3, _d);
        
        _gl.insert(9, 0, _M, 3); _gl.insert(9, 3, _btn2, td::HAlignment::Right);
        _gl.insert(10, 0, _lbl10); _gl.insert(10, 1, _u1r); _gl.insert(10, 2, _u1i);
        _gl.insert(11, 0, _lbl11); _gl.insert(11, 1, _i1r); _gl.insert(11, 2, _i1i);
        _gl.insert(12, 0, _lbl12); _gl.insert(12, 1, _z);
        _gl.insert(13, 0, _lbl13); _gl.insert(13, 1, _y);
        _gl.insert(14, 0, _lbl14); _gl.insert(14, 1, _l1);

        _gl.insert(15, 0, _M2, 3); _gl.insert(15, 3, _btn3, td::HAlignment::Right);
        _gl.insert(16, 0, _lbl15); _gl.insert(16, 1, _l11);
        _gl.insert(17, 0, _lbl16); _gl.insert(17, 2, _lbl17);
        _gl.insert(18, 0, _lbl19); _gl.insert(18, 1, _z0); _gl.insert(18, 2, _lbl21); _gl.insert(18, 3, _z1);
        _gl.insert(19, 0, _lbl18); _gl.insert(19, 1, _y0); _gl.insert(19, 2, _lbl20); _gl.insert(19, 3, _y1);
        
        _gl1.insert(0, 0, _lbl22); _gl1.insert(1, 0, _t1);
        _gl1.insert(2, 0, _lbl23); _gl1.insert(3, 0, _t2);
        _gl1.insert(4, 0, _lbl24); _gl1.insert(5, 0, _t3);
        _gl1.insert(6, 0, _lbl25); _gl1.insert(7, 0, _t4);

        _gl2.insert(0, 0, _gl); _gl2.insert(0, 1, _gl1);

        gui::View::setLayout(&_gl);
        gui::View::setLayout(&_gl1);
        gui::View::setLayout(&_gl2);
    }

    std::vector<std::vector<td::cmplx>> matrixMultiplication(std::vector<std::vector<td::cmplx>> M, std::vector<std::vector<td::cmplx>> N) {
        std::vector<std::vector<td::cmplx>> res = M;
        if (M.at(0).size() != N.size()) return { {{0}, {0}}, {{0}, {0}} };
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M.at(0).size(); j++) {
                td::cmplx sum(0, 0);
                for (int k = 0; k < M.at(0).size(); k++) {
                    sum += M.at(i).at(k) * N.at(k).at(j);
                }
                res.at(i).at(j) = sum;
            }
        }
        return res;
    }
    std::vector<std::vector<td::cmplx>> matrixInversion(std::vector<std::vector<td::cmplx>> M) {
        std::vector<std::vector<td::cmplx>> res = M;
        td::cmplx det(0, 0);
        for (int i = 0; i < M.size(); i++)
            det = det + (M.at(0).at(i) * (M.at(1).at((i + 1) % 3) * M.at(2).at((i + 2) % 3) - M.at(1).at((i + 2) % 3) * M.at(2).at((i + 1) % 3)));
        if (det == td::cmplx(0, 0)) return { {{0}, {0}}, {{0}, {0}} };
        for (int i = 0; i < M.size(); i++)
            for (int j = 0; j < M.at(0).size(); j++)
                res.at(i).at(j) = ((M.at((j + 1) % 3).at((i + 1) % 3) * M.at((j + 2) % 3).at((i + 2) % 3)) - (M.at((j + 1) % 3).at((i + 2) % 3) * M.at((j + 2) % 3).at((i + 1) % 3))) / det;
        return res;
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
            if (_s.getValue().dec4Val() == 0) {
                showAlert("Nemoguć proračun", "Površina poprečnog presjeka provodnika ne može biti 0!");
                return true;
            }
            // step1: Rdc
            td::Decimal4 ro(_ro.getValue().dec4Val());
            td::Decimal4 l(_l.getValue().dec4Val());
            td::Decimal4 s(_s.getValue().dec4Val());
            Rdc = ro * l / s;

            // ispis
            _t1.clean();
            _t1.appendString("Rdc = "); _t1.appendString(Rdc.toString()); _t1.appendString(" [Ohm]");
        }
        if (pBtn == &_btn1)
        {
            if (Rdc == 0) {
                showAlert("Nemoguć proračun", "Proračun otpora provodnika za izmjeničnu struju ovisi od otpora provodnika za istosmjernu struju!");
                return true;
            }
            // step2: Rac
            td::Decimal4 f(_f.getValue().dec4Val());
            td::Decimal4 r(_r.getValue().dec4Val());
            td::Decimal4 d(_d.getValue().dec4Val());

            td::Decimal4 xp = ((8 * 3.14 * f * kp) / (Rdc * 10000000)) * ((8 * 3.14 * f * kp) / (Rdc * 10000000));
            td::Decimal4 gama_p = (xp / (192 + 0.8 * xp)) * (2 * r / d) * (2 * r / d) * (0.312 * (2 * r / d) * (2 * r / d) + (1.18 / (0.27 + (xp / (192 + 0.8 * xp)))));
            /*if (sqrt(xp.getAsFloat()) > 2.8) gama_p *= 2 / 3;*/

            td::Decimal4 xs = ((8 * 3.14 * f * kp) / (Rdc * 10000000)) * ((8 * 3.14 * f * kp) / (Rdc * 10000000));
            td::Decimal4 gama_s = (xs / (192 + 0.8 * xs));

            td::Decimal4 Rac = Rdc * (1 + gama_s + gama_p);

            // ispis
            _t2.clean();
            _t2.appendString("Rac = "); _t2.appendString(Rac.toString()); _t2.appendString(" [Ohm]\n");
            _t2.appendString("gama s = "); _t2.appendString(gama_s.toString()); _t2.appendString(" [m]\n");
            _t2.appendString("gama p = "); _t2.appendString(gama_p.toString()); _t2.appendString(" [m]\n");
        }
        if (pBtn == &_btn2)
        {
            // step3: raspodijeljeni
            td::Decimal4 u1_r(_u1r.getValue().dec4Val());
            td::Decimal4 i1_r(_i1r.getValue().dec4Val());
            td::Decimal4 u1_i(_u1i.getValue().dec4Val());
            td::Decimal4 i1_i(_i1i.getValue().dec4Val());
            td::Decimal4 z(_z.getValue().dec4Val());
            td::Decimal4 y(_y.getValue().dec4Val());
            td::Decimal4 l(_l1.getValue().dec4Val());

            td::cmplx u1(u1_r.getAsFloat(), u1_i.getAsFloat()), i1(i1_r.getAsFloat(), i1_i.getAsFloat());
            td::Decimal4 zc = sqrt(z.getAsFloat() / y.getAsFloat()), gama = sqrt(z.getAsFloat() * y.getAsFloat());
            td::cmplx A = (u1 - zc.getAsFloat() * i1) / 2., B = (u1 - zc.getAsFloat() * i1) / 2.;

            td::cmplx I2 = A * td::cmplx(cos(gama * l), sin(gama * l)) - B * td::cmplx(cos((-1) * gama * l), sin((-1) * gama * l));
            td::cmplx U2 = I2 / zc.getAsFloat();

            // ispis
            _t3.clean();
            writeComplex(_t3, U2, "U2 = ", "[V]\n");
            writeComplex(_t3, I2, "I2 = ", "[A]");
        }
        if (pBtn == &_btn3)
        {
            if (_z0.getValue().dec4Val() == 0 || _z1.getValue().dec4Val() == 0) {
                showAlert("Nemoguć proračun", "Impedanse ne mogu biti jednake 0!");
                return true;
            }
            // step4: koncentrisani
            td::Decimal4 z0(_z0.getValue().dec4Val());
            td::Decimal4 y0(_y0.getValue().dec4Val());
            td::Decimal4 z1(_z1.getValue().dec4Val());
            td::Decimal4 y1(_y1.getValue().dec4Val());
            td::Decimal4 l(_l11.getValue().dec4Val());
            z0 *= l; z1 *= l; y0 *= l; y1 *= l;

            std::vector<std::vector<td::cmplx>> Y11{ {{1. / z0 + y0 / 2.}, {0}, {0}}, {{0}, {1. / z1 + y1 / 2.}, {0}}, {{0}, {0}, {1. / z1 + y1 / 2.}} }, Y22;
            std::vector<std::vector<td::cmplx>> Y12{ {{(-1.) / z0}, {0}, {0}}, {{0}, {(-1.) / z1 }, {0}}, {{0}, {0}, {(-1.) / z1}} }, Y21;
            td::cmplx a(cos(2 * 3.14 / 3), sin(2 * 3.14 / 3));
            std::vector<std::vector<td::cmplx>> T = { {{1. / 3}, {1. / 3}, {1. / 3}}, {{1. / 3}, {a / 3.}, {a * a / 3.}}, {{1. / 3}, {a * a / 3.}, {a / 3.}} };
            std::vector<std::vector<td::cmplx>> T1 = matrixInversion(T);
            Y11 = matrixMultiplication(T1, Y11);
            Y11 = matrixMultiplication(Y11, T);
            Y22 = Y11;

            Y12 = matrixMultiplication(T1, Y12);
            Y12 = matrixMultiplication(Y12, T);
            Y21 = Y12;

            // ispis
            _t4.clean();
            writeMatrix(_t4, Y11, 1, "Y11 = ", "[S]");
            writeMatrix(_t4, Y12, 1, "Y12 = ", "[S]");
            writeMatrix(_t4, Y21, 1, "Y21 = ", "[S]");
            writeMatrix(_t4, Y22, 1, "Y22 = ", "[S]");
        }
        return false;
    }
    
    bool onChangedSelection(gui::ComboBox* pCB) override
    {
        if (pCB == &_comboBox)
        {
            switch (_comboBox.getSelectedIndex()) {
                case 0: default:
                    _comboBox2.clean();
                    break;
                case 1:
                    _comboBox2.clean();
                    _comboBox2.addItem("Upredeni, kružnog popr. presjeka");
                    _comboBox2.addItem("Segmentirani kružnog popr. presjeka");
                    _comboBox2.addItem("Sektorski");
                    _comboBox2.selectIndex(0);
                    break;
                case 2:
                    _comboBox2.clean();
                    _comboBox2.addItem("Upredeni, kružnog popr. presjeka");
                    _comboBox2.addItem("Segmentirani (4 seg.) kružnog popr. presjeka");
                    _comboBox2.addItem("Segmentirani (5 seg.) kružnog popr. presjeka");
                    _comboBox2.addItem("Segmentirani (6 seg.) kružnog popr. presjeka");
                    _comboBox2.selectIndex(0);
                    break;
            }
        }
        if (pCB == &_comboBox2)
        {
            if (_comboBox.getSelectedIndex() == 1 && (_comboBox2.getSelectedIndex() == 0 || _comboBox2.getSelectedIndex() == 2)) {
                _comboBox3.clean();
                _comboBox3.addItem("Da");
                _comboBox3.addItem("Ne");
                _comboBox3.selectIndex(0);
            }
            else _comboBox3.clean();
        }

        switch (_comboBox.getSelectedIndex()) {
            case 1:
                switch (_comboBox2.getSelectedIndex()) {
                    case 0: case 2:
                        switch (_comboBox3.getSelectedIndex()) {
                            case 0: ks = 1; kp = 0.8; break;
                            case 1: ks = 1; kp = 1; break;
                        }
                        break;
                    case 1: ks = 0.435; kp = 0.37; break;
                }
                break;
            case 2:
                switch (_comboBox2.getSelectedIndex()) {
                    case 0: ks = 1; kp = 1; break;
                    case 1: ks = 0.28; kp = 0.37; break;
                    case 2: ks = 0.19; kp = 0.37; break;
                    case 3: ks = 0.12; kp = 0.37; break;
                }
                break;
            default:
                break;
        }
        return false;
    }
    
    
    
};
