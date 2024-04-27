//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/ToolBar.h>
#include "SymbolsPopover.h"

class ToolBar : public gui::ToolBar
{
protected:
//    gui::Image _img1;
//    gui::Image _img2;
    gui::Image _imgIncrease;
    gui::Image _imgDecrease;
    gui::Image _imgFromFile;
    gui::Symbol _xfmr;
    //gui::Image _img3;
    SymbolsPopover _symbolsPopover;
public:
    ToolBar()
    : gui::ToolBar("mainTB", 6)
    , _imgIncrease(":zoomIn")
    , _imgDecrease(":zoomOut")
    , _imgFromFile("/Users/idzafic/Work/Common/Icons/bh_flag.png")
    , _xfmr(":Xfmr4")
    {
        initItem(0, "zoomIn", tr("zoomIn"), &_imgIncrease, tr("zoomInTT"), 255, 0, 0, 10);
        //_defaultItems[0]=0;
        
        initItem(1, "zoomOut", tr("zoomOut"), &_imgDecrease, tr("zoomOutTT"), 255, 0, 0, 20);
        //_defaultItems[1]=1;
        
        initItem(2, "file", tr("fileLbl"), &_imgFromFile, tr("file"), 255, 0, 0, 30);
        //_defaultItems[2]=2;
        
        initItemAsSpace(3);
        //_defaultItems[3]=3;
        
        initItem(4, "symbol", tr("SymbolLBL"), &_xfmr, tr("symbolTT"), 255, 0, 0, 40);
        
        td::UINT2 ctrlPopoverID = 100;
        _allowedItems[5].init("popoverTool", &_symbolsPopover, ctrlPopoverID);
        //_defaultItems[5]=5;
    }
    
};
