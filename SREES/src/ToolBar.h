//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/ToolBar.h>

class ToolBar : public gui::ToolBar
{
protected:
    gui::Symbol _sy1;
    gui::Symbol _sy2;
    gui::Symbol _sy3;
    gui::Image _logo;
public:
    ToolBar()
    : gui::ToolBar("mainTB", 6)
    , _logo(":logo")
    , _sy1(":linija")
    , _sy2(":Xfmr4")
    , _sy3(":calc")
    {
        initItem(0, "", "", &_logo, "", 255, 0, 0, 10);
        initItemAsSpace(1);
        initItem(2, "N. vodovi i kablovi", "N. vodovi i kablovi", &_sy1, "N. vodovi i kablovi", 255, 0, 0, 20);
        initItem(3, "1F Trans.", "1F Trans.", &_sy2, "F Trans.", 255, 0, 0, 30);
        initItem(4, "3F Trans.", "3F Trans.", &_sy2, "3F Trans.", 255, 0, 0, 40);
        initItem(5, "Formule", "Formule", &_sy3, "Formule", 255, 0, 0, 50);
    }
    
};
