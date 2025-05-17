#include "pch.h"
#include "Editor.hpp"

using namespace Builder;

Editor::Editor(void)
{

}

Editor::Editor(const Editor& copy) :
    Player(copy)
{

}

Editor& Editor::operator=(const Editor& copy)
{
    if (this == &copy) return *this;



    return *this;
}

Editor::~Editor(void)
{

}

void Editor::v_Init(void)
{

}

void Editor::v_Activate(void)
{

}

void Editor::v_Deactivate(void)
{

}

void Editor::v_Update(F32 delta)
{

}