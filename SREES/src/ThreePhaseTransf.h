//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/View.h>
#include <gui/VerticalLayout.h>
#include <gui/Label.h>
#include <gui/LineEdit.h>
#include <gui/TextEdit.h>
#include <gui/Button.h>

#include "ViewTransformators.h"

class ThreePhaseTransf : public gui::View
{
private:
protected:
    gui::Button _btn;
    gui::GridLayout _gl;
    gui::GridLayout _gl1;
    gui::GridLayout _gl2;
    gui::Label _izbor1;
    gui::ComboBox _comboBox1;
    gui::TextEdit _textEdit;

    gui::Label _unos1;
    gui::Label _unos2;
    gui::Label _unos3;
    gui::Label _unos4;
    gui::Label _unos5;
    gui::Label _unos6;
    gui::Label _unos7;
    gui::Label _unos8;
    gui::Label _unos9;
    gui::Label _unos10;
    gui::Label _unos11;
    gui::Label _unos12;
    gui::Label _unos13;
    gui::Label _poz;
    gui::Label _nul;
    gui::NumericEdit _S;
    gui::NumericEdit _Unp;
    gui::NumericEdit _Uns;
    gui::NumericEdit _uk1;
    gui::NumericEdit _I01;
    gui::NumericEdit _PPH1;
    gui::NumericEdit _PKS1;
    gui::NumericEdit _uk0;
    gui::NumericEdit _I00;
    gui::NumericEdit _PPH0;
    gui::NumericEdit _PKS0;
    gui::NumericEdit _zgp;
    gui::NumericEdit _zgs;

    gui::Label _check;
    gui::CheckBox _VF;

    gui::Label _rez1;
    gui::Label _rez1_n;
    gui::Label _rez1_p;
    gui::TextEdit _z0y0;
    gui::TextEdit _z1y1;

    gui::Label _rez2;
    gui::TextEdit _pnz;
    gui::Label _rez3;
    gui::TextEdit _pnz_sim;

    gui::Label _rez4;
    gui::TextEdit _Y;

    ViewTransformators _ViewTransformators;
public:
    ThreePhaseTransf()
    : _btn("Izračunaj")
    , _gl(16, 5)
    , _gl1(16, 3)
    , _gl2(1, 2)
    , _izbor1("Odaberite konekciju:")
    , _unos1("Nominalna snaga [VA]: ")
    , _unos2("Nominalni linijski napon primara [V]: ")
    , _unos3("Nominalni linijski napon sekundara [V]: ")
    , _unos4("uk(%) [V]: ")
    , _unos5("I0 [A]: ")
    , _unos6("PPH [W]: ")
    , _unos7("PKS [W]: ")
    , _unos8("uk(%) [V]: ")
    , _unos9("I0 [A]: ")
    , _unos10("PPH [W]: ")
    , _unos11("PKS [W]: ")
    , _unos12("zg primara (ako ima) [Ohm]: ")
    , _unos13("zg sekundara (ako ima) [Ohm]: ")
    , _check("Sa koje strane je vršen eksperiment - VF: ")
    , _poz("Pozitivna sekvenca")
    , _nul("Nulta sekvenca")
    , _rez1("Rezultati eksperimenata praznog hoda i kratkog spoja: ")
    , _rez1_p("Pozitivna sekvenca")
    , _rez1_n("Nulta sekvenca")
    , _rez2("P, N i Z matrice: ")
    , _rez3("Model u simetričnim koordinatama")
    , _rez4("Model u faznim koordinatama")
    , _S(td::decimal4, gui::LineEdit::Messages::Send)
    , _Unp(td::decimal4, gui::LineEdit::Messages::Send)
    , _Uns(td::decimal4, gui::LineEdit::Messages::Send)
    , _uk1(td::decimal4, gui::LineEdit::Messages::Send)
    , _I01(td::decimal4, gui::LineEdit::Messages::Send)
    , _PPH1(td::decimal4, gui::LineEdit::Messages::Send)
    , _PKS1(td::decimal4, gui::LineEdit::Messages::Send)
    , _uk0(td::decimal4, gui::LineEdit::Messages::Send)
    , _I00(td::decimal4, gui::LineEdit::Messages::Send)
    , _PPH0(td::decimal4, gui::LineEdit::Messages::Send)
    , _PKS0(td::decimal4, gui::LineEdit::Messages::Send)
    , _zgp(td::decimal4, gui::LineEdit::Messages::Send)
    , _zgs(td::decimal4, gui::LineEdit::Messages::Send)
    , _VF(nullptr)
    {

        _textEdit.setAsReadOnly();
        _z0y0.setAsReadOnly();
        _z1y1.setAsReadOnly();
        _pnz.setAsReadOnly();
        _pnz_sim.setAsReadOnly();

        _gl.insert(0, 0, _ViewTransformators, 4);
        _gl.insert(1, 0, _izbor1, 2); _gl.insert(1, 2, _comboBox1, 2);
        _gl.insert(3, 0, _textEdit, 4);

        _gl.insert(4, 0, _unos1); _gl.insert(4, 1, _S);
        _gl.insert(5, 0, _unos2); _gl.insert(5, 1, _Unp);
        _gl.insert(6, 0, _unos3); _gl.insert(6, 1, _Uns);
        _gl.insert(7, 0, _unos12); _gl.insert(7, 1, _zgp);
        _gl.insert(8, 0, _unos13); _gl.insert(8, 1, _zgs);
        _gl.insert(9, 0, _check); _gl.insert(9, 1, _VF);

        _gl.insert(10, 0, _nul); _gl.insert(10, 2, _poz);
        _gl.insert(11, 0, _unos4); _gl.insert(11, 1, _uk0);
        _gl.insert(12, 0, _unos5); _gl.insert(12, 1, _I00);
        _gl.insert(13, 0, _unos6); _gl.insert(13, 1, _PPH0);
        _gl.insert(14, 0, _unos7); _gl.insert(14, 1, _PKS0);
        _gl.insert(11, 2, _unos8); _gl.insert(11, 3, _uk1);
        _gl.insert(12, 2, _unos9); _gl.insert(12, 3, _I01);
        _gl.insert(13, 2, _unos10); _gl.insert(13, 3, _PPH1);
        _gl.insert(14, 2, _unos11); _gl.insert(14, 3, _PKS1);

        _gl.insert(15, 0, _btn);

        _gl1.insert(0, 0, _rez1, 2); _gl1.insert(1, 0, _rez1_n); _gl1.insert(1, 1, _rez1_p);
        _gl1.insert(2, 0, _z0y0); _gl1.insert(2, 1, _z1y1);
        _gl1.insert(3, 0, _rez2); _gl1.insert(4, 0, _pnz);
        _gl1.insert(3, 1, _rez3); _gl1.insert(4, 1, _pnz_sim);
        _gl1.insert(5, 0, _rez4, 2); _gl1.insert(6, 0, _Y, 2);

        _gl2.insert(0, 0, _gl); _gl2.insert(0, 1, _gl1);
        
        gui::View::setLayout(&_gl);
        gui::View::setLayout(&_gl1);
        gui::View::setLayout(&_gl2);

        populateData();
    }
    

    bool onChangedSelection(gui::ComboBox* pCB) override
    {
        if (pCB == &_comboBox1)
        {
            _textEdit.clean();
            _textEdit.appendString("Vektorska grupa primara-sekundara: \n");
            _textEdit.appendString(t.at(_comboBox1.getSelectedIndex()).description);

            _textEdit.appendString("\n\nNapomene:\n- Pretpostavljeno je zajedničko feromagnetno jezgro za sve namotaje primara i sekundara.");
            switch (t.at(_comboBox1.getSelectedIndex()).id) {
                case 3: case 10: case 12: case 13:
                    _textEdit.appendString("\n- Crvena boja označava da presjek sa ostalim granama ne podrazumijeva njihov spoj!");
                    break;
                default:
                    break;
            }
            _ViewTransformators.updateOption(_comboBox1.getSelectedIndex());
            return true;
        }
        return false;
    }

    void populateData() {
        for (auto item : t) _comboBox1.addItem(item.name);
        _comboBox1.selectIndex(0);
    }

    td::cmplx find_z(int component, td::Variant Unn) {
        td::Decimal4 S(_S.getValue().dec4Val());
        td::Decimal4 uk;
        td::Decimal4 PKS;
        td::Decimal4 Un(Unn.dec4Val());
        if (S.getAsFloat() == 0 || Un.getAsFloat() == 0) return (0, 0);
        
        (component) ? (uk = _uk1.getValue().dec4Val(), PKS = _PKS1.getValue().dec4Val()) : 
                        (uk = _uk0.getValue().dec4Val(), PKS = _PKS0.getValue().dec4Val());

        td::Decimal4 z_modul = uk * Un * Un / (100 * S);
        td::Decimal4 r = Un * Un * PKS / (S * S);
        td::Decimal4 x = (sqrt(z_modul.getAsFloat() * z_modul.getAsFloat() - r.getAsFloat() * r.getAsFloat()));
        td::cmplx z(r.getAsFloat(), x.getAsFloat());
        return z;
    }

    td::cmplx find_y(int component, const td::Variant& Unn) {
        td::Decimal4 I0;
        td::Decimal4 PPH;
        td::Decimal4 Un(Unn.dec4Val());
        if (Un.getAsFloat() == 0) return (0, 0);

        (component) ? (I0=_I01.getValue().dec4Val(), PPH=_PPH1.getValue().dec4Val()) : 
                        (I0=_I00.getValue().dec4Val(), PPH=_PPH0.getValue().dec4Val());

        td::Decimal4 y_modul = sqrt(3) * I0 / Un;
        td::Decimal4 g = PPH / (Un * Un);
        td::Decimal4 b = (sqrt(y_modul.getAsFloat() * y_modul.getAsFloat() - g.getAsFloat() * g.getAsFloat()));
        td::cmplx y(g.getAsFloat(), b.getAsFloat());
        return y;
    }

    std::vector<std::vector<td::cmplx>> elementWise(std::vector<std::vector<td::cmplx>> M, std::vector<std::vector<td::cmplx>> N) {
        std::vector<std::vector<td::cmplx>> res=M;
        if (M.at(0).size() != N.at(0).size() || M.size() != N.size()) return { {{0}, {0}}, {{0}, {0}} };
        for (int i = 0; i < M.size(); i++)
            for (int j = 0; j < M.at(0).size(); j++)
                res.at(i).at(j) *= N.at(i).at(j);
        return res;
    }

    std::vector<std::vector<td::cmplx>> matrixMultiplication(std::vector<std::vector<td::cmplx>> M, std::vector<std::vector<td::cmplx>> N) {
        std::vector<std::vector<td::cmplx>> res = M;
        if (M.at(0).size() != N.size()) return { {{0}, {0}}, {{0}, {0}} };
        for (int i = 0; i<M.size(); i++) {
            for (int j = 0; j<M.at(0).size(); j++) {
                td::cmplx sum(0, 0);
                for (int k = 0; k<M.at(0).size(); k++) {
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

    void writeComplex(gui::TextEdit &txt, td::cmplx z, std::string var_name="", std::string unit = "") {
        td::Decimal4 x = z.real(), y=z.imag();
        if (var_name != "") txt.appendString(var_name);
        txt.appendString(x.toString());
        if (y >= 0) txt.appendString(" + ");
        else {
            txt.appendString(" - ");
            y = 0. - y;
        }
        txt.appendString(y.toString());
        txt.appendString("j ");
        if (unit!="") txt.appendString(unit);
    }

    void writeMatrix(gui::TextEdit& txt, std::vector<std::vector<td::cmplx>> M, int placement=0, std::string var_name = "", std::string unit = "") {
        for (int i = 0; i < M.size(); i++) {
            if (i == placement && var_name != "") txt.appendString(var_name);
            if (i != placement && var_name != "") {
                for (int k = 0; k <= var_name.size()+2; k++) txt.appendString(" ");
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
            td::cmplx z1 = find_z(1, Unn);
            td::cmplx z0 = find_z(0, Unn);

            td::cmplx y1 = find_y(1, Unn);
            td::cmplx y0 = find_y(0, Unn);

            // step 3.0: ako je Dd abort mission
            if (t.at(_comboBox1.getSelectedIndex()).type == 4) {
                std::vector<std::vector<td::cmplx>> Y11(3, std::vector<td::cmplx>(3)), Y12 = Y11, Y21 = Y11, Y22 = Y11;
                Y11 = { {0,0,0}, {0,1. / z1 + y1 / 2.,0}, {0,0,1. / z1 + y1 / 2.} };
                Y12 = { {0,0,0}, {0,-1. / z1 - y1 / 2.,0}, {0,0,-1. / z1 - y1 / 2.} };
                Y21 = Y11;
                Y22 = Y12;

                _z0y0.clean();
                _z1y1.clean();
                _pnz.clean();
                _pnz_sim.clean();
                _Y.clean();


                writeComplex(_z0y0, z0, "z0 = ", "[Ohm]\n");
                writeComplex(_z0y0, y0, "y0 = ", "[Ohm]");

                writeComplex(_z1y1, z1, "z1 = ", "[Ohm]\n");
                writeComplex(_z1y1, y1, "y1 = ", "[Ohm]");

                writeMatrix(_Y, Y11, 1, "Y11 = ", "[S]");
                writeMatrix(_Y, Y12, 1, "Y12 = ", "[S]");
                writeMatrix(_Y, Y21, 1, "Y21 = ", "[S]");
                writeMatrix(_Y, Y22, 1, "Y22 = ", "[S]");
                return false;
            }

            // step3: P, N, Z matrice
            int c = t.at(_comboBox1.getSelectedIndex()).clocknum;
            td::Decimal4 nn = _Unp.getValue().dec4Val() / _Uns.getValue().dec4Val();
            td::cmplx n(nn*cos(c*3.14/6), nn * sin(c * 3.14 / 6)), n_conj(n.real(), -n.imag());
            std::vector<std::vector<td::cmplx>> P{ {{1. / z1 + y1 / 2.}, {-1. / z1}}, {{-1. / z1}, {1. / z1 + y1 / 2.}} }, N = P, Z;
           
            td::cmplx z;
            switch (t.at(_comboBox1.getSelectedIndex()).type) {
                case 1: // Yy
                    z = z = z0 + 3. * (_zgp.getValue().dec4Val().getAsFloat() + n * n * _zgs.getValue().dec4Val().getAsFloat());
                    Z = { {{1. / z + y0 / 2.}, {-1. / z}}, {{-1. / z}, {1. / z + y0 / 2.}} };
                    break;
                case 2: // Yd
                    z = 3 * _zgp.getValue().dec4Val().getAsFloat() + z0;
                    Z = { {{1. / z}, {0}}, {{0}, {0}} };
                    break;
                case 3: // Dy
                    z = 3 * _zgs.getValue().dec4Val().getAsFloat() + z0;
                    Z = { {{0}, {0}}, {{0}, {1. / z}} };
                    break;
                case 4: // Dd
                    break;
                default:
                    break;
            }

            // step4: prebacivanje modela u simetricne koordinate
            std::vector<std::vector<td::cmplx>> Ps, Ns, Zs, matrix_n;
            switch (t.at(_comboBox1.getSelectedIndex()).type) {
            case 1: case 2: // Yy, Yd
                matrix_n = { {{1}, {n}}, {{n_conj}, {n * n}} };
                Ps = elementWise(P, matrix_n);
                Zs = Ps;
                matrix_n = { {{1}, {n_conj}}, {{n}, {n * n}} };
                Ns = elementWise(N, matrix_n);
                break;
            case 3: // Dy
                matrix_n = { {{1. / (n * n)}, {1. / n_conj}}, {{1. / n}, {1}} };
                Ps = elementWise(P, matrix_n);
                Zs = Ps;
                matrix_n = { {{1. / (n * n_conj)}, {1. / n}}, {{1. / n_conj}, {1}} };
                Ns = elementWise(N, matrix_n);
                break;
            case 4: // Dd
                break;
            default:
                break;
            }

            // step5: prebacivanje modela u fazne koordinate
            std::vector<std::vector<td::cmplx>> Y11(3, std::vector<td::cmplx>(3)), Y12=Y11, Y21 = Y11, Y22 = Y11;
            Y11.at(0).at(0) = Zs.at(0).at(0);
            Y11.at(1).at(1) = Ps.at(0).at(0);
            Y11.at(2).at(2) = Ns.at(0).at(0);

            Y12.at(0).at(0) = Zs.at(0).at(1);
            Y12.at(1).at(1) = Ps.at(0).at(1);
            Y12.at(2).at(2) = Ns.at(0).at(1);

            Y21.at(0).at(0) = Zs.at(1).at(0);
            Y21.at(1).at(1) = Ps.at(1).at(0);
            Y21.at(2).at(2) = Ns.at(1).at(0);

            Y22.at(0).at(0) = Zs.at(1).at(1);
            Y22.at(1).at(1) = Ps.at(1).at(1);
            Y22.at(2).at(2) = Ns.at(1).at(1);

            td::cmplx a(cos(2 * 3.14 / 3), sin(2 * 3.14 / 3));
            std::vector<std::vector<td::cmplx>> T = { {{1. / 3}, {1. / 3}, {1. / 3}}, {{1. / 3}, {a / 3.}, {a * a / 3.}}, {{1. / 3}, {a * a / 3.}, {a / 3.}} };
            std::vector<std::vector<td::cmplx>> T1 = matrixInversion(T);
            Y11 = matrixMultiplication(T1, Y11);
            Y11 = matrixMultiplication(Y11, T);

            Y12 = matrixMultiplication(T1, Y12);
            Y12 = matrixMultiplication(Y12, T);

            Y21 = matrixMultiplication(T1, Y21);
            Y21 = matrixMultiplication(Y21, T);

            Y22 = matrixMultiplication(T1, Y22);
            Y22 = matrixMultiplication(Y22, T);

            // ispis rezultata
            _z0y0.clean();
            _z1y1.clean();
            _pnz.clean();
            _pnz_sim.clean();
            _Y.clean();

            writeComplex(_z0y0, z0, "z0 = ", "[Ohm]\n");
            writeComplex(_z0y0, y0, "y0 = ", "[Ohm]");

            writeComplex(_z1y1, z1, "z1 = ", "[Ohm]\n");
            writeComplex(_z1y1, y1, "y1 = ", "[Ohm]");

            writeMatrix(_pnz, P, 0, "P = ", "[S]");
            writeMatrix(_pnz, N, 0, "N = ", "[S]");
            writeMatrix(_pnz, Z, 0, "Z = ", "[S]");

            writeMatrix(_pnz_sim, Ps, 0, "Ps = ", "[S]");
            writeMatrix(_pnz_sim, Ns, 0, "Ns = ", "[S]");
            writeMatrix(_pnz_sim, Zs, 0, "Zs = ", "[S]");

            writeMatrix(_Y, Y11, 1, "Y11 = ", "[S]");
            writeMatrix(_Y, Y12, 1, "Y12 = ", "[S]");
            writeMatrix(_Y, Y21, 1, "Y21 = ", "[S]");
            writeMatrix(_Y, Y22, 1, "Y22 = ", "[S]");
        }
        return false;
    }

    struct Transformer {
        int id;
        std::string name;
        std::string description;
        int type;
        int clocknum;
    };
    std::vector<Transformer> t{ {0, "Yy0", "Y0-Y0", 1, 0},
                                {1, "Yd1", "Y0-D11", 2, 1},
                                {2, "Yd5", "Y0-D7", 2, 5},
                                {3, "Yy6", "Y0-Y6", 1, 6},
                                {4, "Yd7", "Y0-D5", 2, 7},
                                {5, "Yd11", "Y0-D1", 2, 11},
                                {6, "Dd0", "D11-D11", 4, 0},
                                {7, "Dy1", "D1-Y0", 3, 1},
                                {8, "Dd2", "D1-D11", 4, 2},
                                {9, "Dd4", "D11-D7", 4, 4},
                                {10, "Dy5", "D11-Y6", 3, 5},
                                {11, "Dd6", "D11-D5", 4, 6},
                                {12, "Dy7", "D1-Y6", 3, 7},
                                {13, "Dd8", "D11-D3", 4, 8},
                                {14, "Dd10", "D11-D1", 4, 10},
                                {15, "Dy11", "D11-Y0", 3, 11} };
};
