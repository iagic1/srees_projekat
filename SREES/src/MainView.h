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
    gui::Symbol _navSymb;
    gui::Symbol _navSymb2;
    gui::Symbol _navSymb3;
    SwitcherView _switcherView;
public:
    MainView()
    : _hl(2)
    , _navigator(5, true)
    , _navImg1(":logo")
    , _navSymb3(":Xfmr4")
    , _navSymb2(":linija")
    , _navSymb(":calc")
    {
        setMargins(0,0,0,0);
        _navigator.setItem(0, &_navImg1, "Dobrodošli");
        _navigator.setItem(1, &_navSymb2, "Nadzemni vodovi i kablovi");
        _navigator.setItem(2, &_navSymb3, "1F transformatori");
        _navigator.setItem(3, &_navSymb3, "3F transformatori");
        _navigator.setItem(4, &_navSymb, "Korištene formule");
        _hl.append(_navigator);
        
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
        return true;
    }
public:    
    bool getView(int option) {
        _switcherView.showView(option, false);
        return true;
    }
    
};

