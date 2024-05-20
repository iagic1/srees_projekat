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
#include "ScrolledCanvasView.h"

class WelcomeScreen : public gui::View
{
private:
protected:
    gui::GridLayout _gl;
    gui::TextEdit _textEdit;
    gui::Label _lbl;
public:
    WelcomeScreen()
        : _lbl(" ")
        , _gl(3, 2)
    {
        _textEdit.setBold();
        _textEdit.setAsReadOnly();
        
        _gl.insert(0, 0, _lbl);
        _gl.insert(1, 0, _textEdit);
        _gl.insert(2, 0, _lbl);

        gui::View::setLayout(&_gl);

        _textEdit.appendString("Dobrodošli!\n\n\n");
        _textEdit.appendString("Pomoć:\n\n");
        _textEdit.appendString("Nadzemni vodovi i kablovi - alat za proračun parametara nadzemnih vodova i kablova\n");
        _textEdit.appendString("                                       - otpor provodnika pri izmjeničnoj i istosmjernoj struji\n");
        _textEdit.appendString("                                       - modeli prenosne linije sa raspodijeljenim i koncentrisanim parametrima\n\n");
        _textEdit.appendString("1F transformatori - alat za proračun modela jednofaznog transformatora\n");
        _textEdit.appendString("                               - eksperimenti kratkog spoja i praznog hoda\n");
        _textEdit.appendString("                               - PI ekvivalent transformatora\n\n");
        _textEdit.appendString("3F transformatori - alat za proračun modela trofaznog transformatora\n");
        _textEdit.appendString("                               - račun za posebne konfiguracije transformatora (Yy, Yd, Dy, Dd)\n");
        _textEdit.appendString("                               - eksperimenti kratkog spoja i praznog hoda\n");
        _textEdit.appendString("                               - račun matrica svih komponenti u simetričnim i faznim komponentama\n\n");
        _textEdit.appendString("Korištene formule - prikaz formula sa kojim se računaju parametri na svim prethodnim prozorima\n\n");
        _textEdit.appendString("\nSretno računanje modela!");
    }
};

