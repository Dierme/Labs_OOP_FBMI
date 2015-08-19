#pragma once
#include "Software.h"

class Text_editor:public Software
{
public:
	Text_editor(std::string,bool);
	virtual ~Text_editor();
	virtual void output();
private:
	bool pdf_support;
};

