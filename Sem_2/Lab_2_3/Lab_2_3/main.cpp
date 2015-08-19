#include <iostream>
#include <conio.h>
#include "Software.h"
#include "Games.h"
#include "Text_editor.h"
#include <vld.h>

int main()
{
	Software Program("Firefox");
	Games *Mass_Effect = new Games("Mass_effect", 16);
	Text_editor *Adobe_reader = new Text_editor("Adobe_Reader",1);
	Text_editor *Microsoft_Word= new Text_editor("Microsoft_Word", 0);
	Software *ptrSoftware;

	Program.output();

	ptrSoftware = Mass_Effect; 
	ptrSoftware->output();

	ptrSoftware = Adobe_reader;
	ptrSoftware->output();

	ptrSoftware = Microsoft_Word;
	ptrSoftware->output();

	delete Mass_Effect;
	delete Adobe_reader;
	delete ptrSoftware;

	_getch();
}