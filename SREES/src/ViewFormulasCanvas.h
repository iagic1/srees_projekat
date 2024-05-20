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

class ViewFormulasCanvas : public gui::Canvas
{
protected:
    gui::Shape _shapeRect;
    gui::Image _img1;
    gui::Image _img2;
    gui::Image _img3;
    gui::Image _img4;
    gui::Image _img5;

    gui::Size _size;
    int _option;
public:
    ViewFormulasCanvas()
    : Canvas({gui::InputDevice::Event::PrimaryClicks, gui::InputDevice::Event::SecondaryClicks, gui::InputDevice::Event::Zoom})
    , _img1(":f1")
    , _img2(":f2")
    , _img3(":f3")
    , _img4(":f4")
    , _img5(":f5")
    {
        gui::Rect r(0, 0, 2000, 2000);
        float lw = 0;
        _shapeRect.createRect(r, lw);

        _option = 0;

        enableResizeEvent(true);
    }
    
    bool getModelSize(gui::Size& modelSize) const override
    {
        modelSize.width = 2000;
        modelSize.height = 2000;
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
        gui::Rect imgRect(1750, 500, 0, 0);
        gui::Rect imgRect2(1750, 905, 0, 500);
        gui::Rect imgRect3(1750, 402, 0, 0);
        gui::Rect imgRect4(1750, 900, 0, 402);
        switch (_option) {
        case 0:
            _img1.draw(imgRect);
            _img2.draw(imgRect2);            
            break;
        case 1:
            _img3.draw(imgRect);
            break;
        case 2:
            _img4.draw(imgRect3);
            _img5.draw(imgRect4);
            break;
        default:
            break;
        }
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

};
