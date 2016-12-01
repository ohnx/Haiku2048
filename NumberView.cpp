/*
 * Copyright (c) 2015 Markus Himmel
 * This file is distributed under the terms of the MIT license
 */

#include "NumberView.h"
#include <Rect.h>
#include <String.h>
#include <iostream>

NumberView::NumberView(uint32 number)
	:
	BView("noname", B_WILL_DRAW),
	fNumber(number)
{
	SetExplicitMinSize(BSize(100, 100));
	SetExplicitMaxSize(BSize(100, 100));
	SetExplicitPreferredSize(BSize(100, 100));
	BFont *font = new BFont(be_bold_font);
	font->SetSize(20.0);
	SetFont(font);
}

void
NumberView::SetNumber(uint32 number)
{
	fNumber = number;
}

void
NumberView::Draw(BRect r)
{
	BRect bounds = Bounds();
	if (fNumber < 2) {
		SetHighColor(205,193,180);
		FillRect(bounds);
		return;
	}

	BString c;
	c << fNumber;
	float width = StringWidth(c.String());
	rgb_color color_foreground = {255,255,255}, color_background;
	
	switch (fNumber) {
	case 2: color_background = {238,228,218}; color_foreground = {119,110,101}; break;
	case 4: color_background = {237,224,200}; color_foreground = {119,110,101}; break;
	case 8: color_background = {242,177,121}; break;
	case 16: color_background = {245,149,99}; break;
	case 32: color_background = {246,124,95}; break;
	case 64: color_background = {246,94,59}; break;
	case 128: color_background = {237,207,114}; break;
	case 256: color_background = {237,204,97}; break;
	case 512: color_background = {237,200,80}; break;
	case 1024: color_background = {237,197,63}; break;
	default: color_background = {237,194,46}; break;
	}
	
	SetHighColor(color_background);
	FillRect(bounds);
	SetHighColor(color_foreground);
	DrawString(c.String(),
		BPoint(bounds.left + 50 - width / 2, bounds.bottom - 50 + 10));
}

NumberView::~NumberView()
{
}
