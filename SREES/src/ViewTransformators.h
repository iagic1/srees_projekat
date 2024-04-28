//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/Canvas.h>
#include <gui/Shape.h>
#include <math/math.h>
#include <gui/Image.h>
#include <gui/Symbol.h>
#include <gui/DrawableString.h>
#include <gui/Context.h>
#include <gui/Transformation.h>

class ViewTransformators : public gui::Canvas
{
protected:
    gui::Shape _shapeRect;

    gui::Symbol _symbol;
    gui::Symbol _symbol2;
    gui::Symbol _symbol3;
    gui::Symbol _symbol4;
    gui::Symbol _symbol5;
    gui::Symbol _symbol6;/*
    gui::Symbol _symbol7;
    gui::Symbol _symbol8;
    gui::Symbol _symbol9;
    gui::Symbol _symbol10;*/

    gui::Size _size;
    int _option;
public:
    ViewTransformators()
    : Canvas({gui::InputDevice::Event::PrimaryClicks, gui::InputDevice::Event::SecondaryClicks, gui::InputDevice::Event::Zoom})
    , _symbol(":y0y0")
    , _symbol2(":y0d11")
    , _symbol3(":y0d7")
    , _symbol4(":y0y6")
    , _symbol5(":y0d5")
    , _symbol6(":y0d1")
    {
        gui::Rect r(0, 0, 600, 200);
        float lw = 5;
        _shapeRect.createRect(r, lw);

        _option = 0;
        setScale(1.5);

        enableResizeEvent(true);
    }
    
    bool getModelSize(gui::Size& modelSize) const override
    {
        modelSize.width = 600;
        modelSize.height = 200;
        return true;
    }
    
    void onPrimaryButtonPressed(const gui::InputDevice& inputDevice) override
    {
        double scale = 2;
        double oldScale = getScale();
        double newScale = oldScale * scale;
        const gui::Point& modelPoint = inputDevice.getModelPoint();
        scaleToPoint(newScale, modelPoint);
    }
    
    void onSecondaryButtonPressed(const gui::InputDevice& inputDevice) override
    {
        double scale = 2;
        double oldScale = getScale();
        double newScale = oldScale / scale;
        const gui::Point& modelPoint = inputDevice.getModelPoint();
        scaleToPoint(newScale, modelPoint);
    }
    
    bool onZoom(const gui::InputDevice& inputDevice) override
    {
        auto& modelPoint = inputDevice.getModelPoint();
        double scale = inputDevice.getScale();
        double oldScale = getScale();
        double newScale = oldScale * scale;
        scaleToPoint(newScale, modelPoint);
        return true;
    }

    void onResize(const gui::Size& newSize) override
    {
        _size = newSize;
    }

    void updateOption(int input) {
        _option = input;
        reDraw();
    }
    
    void onDraw(const gui::Rect& rect) override
    {
        _shapeRect.drawFillAndWire(td::ColorID::Black, td::ColorID::Black);
        _syarray.at(_option).draw(_size.width*0.22, _size.height*0.15);
    }
    
    void toolbarZoomIn()
    {
        double scale = getScale();
        scale *= 2;
        setScale(scale);
    }
    
    void toolbarZoomOut()
    {
        double scale = getScale();
        scale /= 2;
        setScale(scale);
    }

    std::vector<gui::Symbol> _syarray{_symbol, _symbol2, _symbol3, _symbol4, _symbol5, _symbol6};

};
