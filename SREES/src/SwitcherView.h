 //
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/ViewSwitcher.h>
#include "ViewFormulas.h"
#include "ViewTransformators.h"
#include "ViewGrid.h"
#include "ThreePhaseTransf.h"
#include "OnePhaseTransf.h"
#include "WelcomeScreen.h"

class SwitcherView : public gui::ViewSwitcher
{
private:
protected:
    ViewFormulas _ViewFormulas;
    WelcomeScreen _WelcomeScreen;
    ViewGrid _ViewGrid;
    ThreePhaseTransf _ThreePhaseTransf;
    OnePhaseTransf _OnePhaseTransf;
    int _viewPos = 0;
public:
    SwitcherView()
    : gui::ViewSwitcher(3)
    {
        addView(&_WelcomeScreen, true);
        addView(&_ViewGrid, false);
        addView(&_OnePhaseTransf, false);
        addView(&_ThreePhaseTransf, false);
        addView(&_ViewFormulas, false);
    }
    
    std::tuple<int, int> showPrev(gui::ActionItem* pAI)
    {
        int nElems = getNoOfViews();
        
        --_viewPos;
        if (_viewPos < 0)
        {
            _viewPos = 0;
            return {0, nElems};
        }
        showView(_viewPos);
        if (_viewPos <= 0)
            pAI->disable();
        return {_viewPos, nElems};
    }
    
    std::tuple<int, int> showNext(gui::ActionItem* pAI)
    {
        int nElems = getNoOfViews();
        ++_viewPos;
        if (_viewPos >= nElems)
        {
            _viewPos = nElems - 1;
            return {0, nElems};
        }
        showView(_viewPos);
        
        if (_viewPos + 1 >= nElems)
            pAI->disable();
        
        return {_viewPos, nElems};
    }
    
    std::tuple<int, int> removeCurrent()
    {
        int nElems = getNoOfViews();
        if (nElems < 1)
            return {-1,0};

        const auto pCurrView = getCurrentView();
        int iPos = removeView(pCurrView);        
        return {iPos, nElems-1};
    }
    
};
