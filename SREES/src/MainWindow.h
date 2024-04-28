//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/Window.h>
#include <gui/ActionItem.h>
#include "MenuBar.h"
#include "MainView.h"
#include <gui/FileDialog.h>
#include "ToolBar.h"


class MainWindow : public gui::Window
{
private:
protected:
    MenuBar _mainMenuBar;
    ToolBar _toolBar;
    MainView _mainView;
public:
    MainWindow()
    : gui::Window(gui::Geometry(50, 50, 1000, 600))
    {
        setTitle("SREES");
        _mainMenuBar.setAsMain(this);
        _toolBar.forwardMessagesTo(this);
        _toolBar.setIconSize(gui::ToolBar::IconSize::SystemDefault);
        setToolBar(_toolBar);
        
        setCentralView(&_mainView);
    }
    
    ~MainWindow()
    {
    }
    
    bool shouldClose() override
    {
        return true;
    }
    
    void onClose() override
    {
        gui::Window::onClose();
    }
    

    virtual bool onActionItem(td::BYTE menuID, td::BYTE firstSubMenuID, td::BYTE lastSubMenuID, td::BYTE actionID, gui::ActionItem* pAI)
    {
        if (menuID == 255)
        {
            if (actionID == 10)
            {
                _mainView.getView(0);
                return true;
            }
            if (actionID == 20)
            {
                _mainView.getView(1);
                return true;
            }
            if (actionID == 30)
            {
                _mainView.getView(2);
                return true;
            }
            if (actionID == 40)
            {
                _mainView.getView(3);
                return true;
            }
            if (actionID == 50)
            {
                _mainView.getView(4);
                return true;
            }
            return true;
        }
    }
    
};
