//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/MenuBar.h>
#include <gui/Image.h>

class MenuBar : public gui::MenuBar
{
private:
    gui::SubMenu subApp;
    gui::SubMenu subFile;
    gui::SubMenu subView;
    //gui::Image _imgFullScreen;
protected:
    void populateSubAppMenu()
    {
        auto& items = subApp.getItems();
        items[0].initAsQuitAppActionItem(tr("Quit"), "q");
    }
    
public:
    MenuBar()
    : gui::MenuBar(3)
    , subApp(10, "Izlaz", 3)
    , subFile(20, "Umre kad se obriše", 3)
    , subView(30, "Također", 0)
    {
        populateSubAppMenu();
        _menus[0] = &subApp;
        _menus[1] = &subFile;
        _menus[2] = &subView;
    }
    
    ~MenuBar()
    {
    }
};

