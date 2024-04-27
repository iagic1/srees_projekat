//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/Controls.h>
#include <gui/Navigator.h>
#include "SwitcherView.h"

class MainView: public gui::View
{
private:
protected:
    gui::HorizontalLayout _hl;
    gui::Navigator _navigator;
    gui::Image _navImg1;
    gui::Image _navImg2;
    gui::Symbol _navSymb3;
    gui::Image _navImg4;
    gui::Image _navImg5;
    SwitcherView _switcherView;
public:
    MainView()
    : _hl(2)
    , _navigator(5, true)
    , _navImg1(":grid")
    , _navImg2(":canvas")
    , _navSymb3(":Xfmr4")
    , _navImg4(":connOK")
    , _navImg5(":settings")
    {
        setMargins(0,0,0,0);
        _navigator.setItem(0, &_navImg1, "O nama");
        _navigator.setItem(1, &_navImg2, "Kablovi");
        _navigator.setItem(2, &_navImg4, "Nadzemni vodovi");
        _navigator.setItem(3, &_navSymb3, "1F transformatori");
        _navigator.setItem(4, &_navSymb3, "3F transformatori");
        _hl.append(_navigator);
        
        //_imgView.setImage(_navImg1);
        _hl.append(_switcherView);
        setLayout(&_hl);
    }
protected:
    bool onActionItem(td::BYTE menuID, td::BYTE firstSubMenuID, td::BYTE lastSubMenuID, td::BYTE actionID, gui::ActionItem* pAI) override
    {
        td::String msgText("Handling onActionItem");
        td::String informativeText;
        informativeText.format("Handled onActionItem(subMenuID=%d, firstSubSubMenuID=%d, lastSubSubMenuID=%d, actionID=%d)", menuID, firstSubMenuID, lastSubMenuID, actionID);
        
       showAlert(msgText, informativeText);
        return false;
    }
    
    
    bool onChangedSelection(gui::Navigator* pNav) override
    {
        td::UINT2 currSelection = pNav->getCurrentSelection();
        _switcherView.showView((int) currSelection);
        //mu::dbgLog("Navigator selChanged. New Sel =%d", currSelection);
        return true;
    }
    
};

