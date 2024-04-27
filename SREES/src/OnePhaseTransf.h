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
    gui::Label _lbl;
    gui::LineEdit _lineEdit;
    gui::Label _lbl2;
    gui::LineEdit _lineEdit2;
    gui::Label _lbl3;
    gui::TextEdit _textEdit;



    gui::GridLayout _gl;
    gui::Label _unos1;
    gui::Label _unos2;
    gui::Label _unos3;
    gui::Label _unos4;
    gui::Label _unos5;
    gui::Label _unos6;
    gui::NumericEdit _S;
    gui::NumericEdit _Unp;
    gui::NumericEdit _Uns;
    gui::NumericEdit _uk1;
    gui::NumericEdit _PPH1;
    gui::NumericEdit _PKS1;

    gui::Button _btn;
    gui::Label _check;
    gui::CheckBox _VF;
public:
    OnePhaseTransf()
    : _lbl("This is a label:")
    , _lbl2("This is another label:")
    , _lbl3("Label for text edit:")
    , _gl(16,8)
    , _unos1("Nominalna snaga: ")
    , _unos2("Nominalni linijski napon primara: ")
    , _unos3("Nominalni linijski napon sekundara: ")
    , _unos4("uk(%): ")
    , _unos5("PPH: ")
    , _unos6("PKS: ")
    , _check("Sa koje strane je vršen eksperiment - VF: ")
    , _S(td::decimal4, gui::LineEdit::Messages::Send)
    , _Unp(td::decimal4, gui::LineEdit::Messages::Send)
    , _Uns(td::decimal4, gui::LineEdit::Messages::Send)
    , _uk1(td::decimal4, gui::LineEdit::Messages::Send)
    , _PPH1(td::decimal4, gui::LineEdit::Messages::Send)
    , _PKS1(td::decimal4, gui::LineEdit::Messages::Send)
    , _VF(nullptr)
    , _btn("Izračunaj")
    {
        
        _gl.insert(1, 0, _unos1); _gl.insert(1, 1, _S);
        _gl.insert(2, 0, _unos2); _gl.insert(2, 1, _Unp);
        _gl.insert(3, 0, _unos3); _gl.insert(3, 1, _Uns);
        _gl.insert(4, 0, _check); _gl.insert(4, 1, _VF);

        _gl.insert(5, 0, _unos4); _gl.insert(5, 1, _uk1);
        _gl.insert(6, 0, _unos5); _gl.insert(6, 1, _PPH1);
        _gl.insert(7, 0, _unos6); _gl.insert(7, 1, _PKS1);

        _gl.insert(15, 0, _btn);
        gui::View::setLayout(&_gl);
    }
    
    bool onClick(gui::Button* pBtn) override
    {
        if (pBtn == &_btn)
        {
            //
        }
        return false;
    }

};
