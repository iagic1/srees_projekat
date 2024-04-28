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

class ViewFormulas : public gui::View
{
private:
protected:
    gui::GridLayout _gl;
    gui::Label _lblCB;
    gui::ComboBox _comboBox;
    ScrolledCanvasView _viewScrolledCanvas;
public:
    ViewFormulas()
    : _lblCB("Za koji tab želite vidjeti korištene formule:")
    , _gl(3,2)
    {
        _comboBox.addItem("Jednofazni transformatori");
        _comboBox.addItem("Trofazni transformatori");
        _comboBox.addItem("-");
        _comboBox.selectIndex(0);
        
        _gl.insert(0, 0, _lblCB);
        _gl.insert(0, 1, _comboBox);        
        _gl.insert(1,0, _viewScrolledCanvas, 2);
                       
        gui::View::setLayout(&_gl);
    }
 
    bool onChangedSelection(gui::ComboBox* pCB) override
    {
        if (pCB == &_comboBox)
        {
            _viewScrolledCanvas.updateOption(_comboBox.getSelectedIndex());
            return true;
        }
        return false;
    }
};
