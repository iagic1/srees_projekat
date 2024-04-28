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

class ViewGrid : public gui::View
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

    gui::LineEdit _lineEdit;
    gui::LineEdit _lineEdit2;
    gui::NumericEdit _kol;
    gui::Label _lblCij;
    gui::NumericEdit _cij;
    gui::Label _lblIzn;
    gui::NumericEdit _iznos;
    gui::Label _lblKupiti;
    gui::CheckBox _cbKupiti;
    gui::Label _lblSlider;
    gui::Slider _slider;
    gui::ProgressIndicator _progIndicator;
    gui::Label _lblCB;
    gui::Label _lblDate;
    gui::DateEdit _date;
    gui::Label _lblTime;
    gui::TimeEdit _time;
    //gui::Label _lbl3;
    gui::HorizontalLayout _hl;
    gui::Button _btnClearText;
    gui::Button _btnGetDT;
    gui::TextEdit _textEdit;




    gui::GridLayout _gl;
    gui::GridLayout _gl1;
    gui::GridLayout _gl2;

    td::Decimal4 ks, kp;
    td::Decimal4 Rdc;

public:
    ViewGrid()
    : _lbl("Materijal provodnika: ")
    , _lbl2("Tip provodnika: ")
    , _lbl3("Suha impregnirana izolacija: ")
    , _lbl4("Frekvencija napajanja [Hz]: ")
    , _lbl5("Poluprečnik provodnika [mm]: ")
    , _lbl6("Udaljenost između osa poluprovodnika [mm]: ")
    , _lbl7("Specifična otpornost provodnika: ")
    , _lbl8("Dužina provodnika: ")
    , _lbl9("Površina poprečnog presjeka provodnika: ")
    , _r(td::decimal4, gui::LineEdit::Messages::Send)
    , _d(td::decimal4, gui::LineEdit::Messages::Send)
    , _f(td::decimal4, gui::LineEdit::Messages::Send)
    , _ro(td::decimal4, gui::LineEdit::Messages::Send)
    , _l(td::decimal4, gui::LineEdit::Messages::Send)
    , _s(td::decimal4, gui::LineEdit::Messages::Send)
    , _btn("Izračunaj")
    , _btn1("Izračunaj")
    , _btn2("Izračunaj")
    , _btn3("Izračunaj")
    , _R("Proračun otpora provodnika za istosmjernu struju")
    , _M("Model prenosne linije sa raspodijeljenim parametrima")
    , _R2("Proračun otpora provodnika za izmjeničnu struju")
    , _M2("Model prenosne linije sa koncentrisanim parametrima")

    , _kol(td::decimal3, gui::LineEdit::Messages::Send)
    , _lblCij("Cijena:")
    , _cij(td::decimal4, gui::LineEdit::Messages::Send)
    , _lblIzn("Iznos:")
    , _iznos(td::decimal2)
    , _lblKupiti("Kupiti:")
    , _lblSlider("Slider:")
    , _cbKupiti(nullptr)
    , _lblCB("Kombo:")
    , _lblDate("Datum:")
    , _lblTime("Vrijeme:")
    , _hl(4)
    
    , _btnClearText("Brisi")
    , _btnGetDT("Date&Time->TE")
    , _gl(18, 8)
    , _gl1(16, 3)
    , _gl2(1, 2)
    {
        _comboBox.addItem("-");
        _comboBox.addItem("Bakar");
        _comboBox.addItem("Aluminijum");
        _comboBox.selectIndex(0);
        
        _gl.insert(0, 0, _R, 3); _gl.insert(0, 3, _btn);
        _gl.insert(1, 0, _lbl7); _gl.insert(1, 1, _ro);
        _gl.insert(2, 0, _lbl8); _gl.insert(2, 1, _l);
        _gl.insert(3, 0, _lbl9); _gl.insert(3, 1, _s);
        _gl.insert(4, 0, _R2, 3); _gl.insert(4, 3, _btn1);
        _gl.insert(5, 0, _lbl); _gl.insert(5, 1, _comboBox); _gl.insert(5, 2, _lbl4); _gl.insert(5, 3, _f);
        _gl.insert(6, 0, _lbl2); _gl.insert(6, 1, _comboBox2); _gl.insert(6, 2, _lbl5); _gl.insert(6, 3, _r);
        _gl.insert(7, 0, _lbl3); _gl.insert(7, 1, _comboBox3); _gl.insert(7, 2, _lbl6); _gl.insert(7, 3, _d);
        

        _gl.insert(9, 0, _M, 3); _gl.insert(9, 3, _btn2);

       // _gl.insert(7, 0, _textEdit);
        
        _gl2.insert(0, 0, _gl); _gl2.insert(0, 1, _gl1);

        gui::View::setLayout(&_gl);
        gui::View::setLayout(&_gl1);
        gui::View::setLayout(&_gl2);
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
        }
        if (pBtn == &_btn1)
        {
            if (Rdc == 0) {
                showAlert("Nemoguć proračun", "Za proračun otpora provodnika za izmjeničnu struju ovisi od otpora provodnika za istosmjernu struju!");
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
        }
        if (pBtn == &_btn2)
        {
            // step3: raspodijeljeni
        }
        if (pBtn == &_btn3)
        {
            // step4: koncentrisani
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
