//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/ViewScroller.h>
#include "ViewFormulasCanvas.h"

class ScrolledCanvasView : public gui::ViewScroller
{
private:
protected:
    ViewFormulasCanvas _canvas;

public:
    ScrolledCanvasView()
    : gui::ViewScroller(gui::ViewScroller::Type::ScrollAndAutoHide, gui::ViewScroller::Type::ScrollAndAutoHide)
    {
        setContentView(&_canvas);
    }
    
    ViewFormulasCanvas& getView()
    {
        return _canvas;
    }

    void updateOption(int input) {
        _canvas.updateOption(input);
    }
};
