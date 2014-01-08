#include "constants.h"

float Constants::DrawComponenPositiontData::CUBE_WIDTH = 60;
float Constants::DrawComponenPositiontData::CUBE_HEIGHT = 60;
float Constants::DrawComponenPositiontData::PYRAMID_WIDTH = 80;
float Constants::DrawComponenPositiontData::PYRAMID_HEIGHT = 80;
float Constants::DrawComponenPositiontData::SPHERE_WIDTH = 50;
float Constants::DrawComponenPositiontData::SPHERE_HEIGHT = 50;
float Constants::DrawComponenPositiontData::LINE_WIDTH = 50;
float Constants::DrawComponenPositiontData::LINE_HEIGHT = 1;

float Constants::DrawComponenPositiontData::COMPONENT_BEGIN_X = 50;
float Constants::DrawComponenPositiontData::COMPONENT_BEGIN_Y = 50;
float Constants::DrawComponenPositiontData::COMPONENT_DIFF_Y = 70;

float Constants::DrawGroupsPositionData::GROUP_BEGIN_X = 400;
float Constants::DrawGroupsPositionData::GROUP_BEGIN_Y = 50;
float Constants::DrawGroupsPositionData::GROUP_DIFF_Y = 50;

//ComponentType靜態類別參數設定
int Constants::ComponentType::CubeType =1;
int Constants::ComponentType::PyramidType = 2;
int Constants::ComponentType::SphereType = 3;
int Constants::ComponentType::LineType = 4;
string Constants::ComponentType::SphereTypeString ="Sphere";
string Constants::ComponentType::PyramidTypeString ="Pyramid";
string Constants::ComponentType::CubeTypeString = "Cube";
string Constants::ComponentType::LineTypeString = "Line";

string Constants::GUIMainWindowParameter::XML_FILES_PATH = "graphical_Modeling_system_GUI/GMS XML Files";
string Constants::GUIMainWindowParameter::COMPONENTS_LIST_WIDGET_HEADER = "Type , ID , Name\n======================";
string Constants::GUIMainWindowParameter::GROUPS_LIST_WIDGET_HEADER = "GID , Name , Members\n=====================";


void Constants::SetComponentWidthHeight(int* width,int* height,string type){
    if(type == Constants::ComponentType::CubeTypeString){
        *width = Constants::DrawComponenPositiontData::CUBE_WIDTH;
        *height = Constants::DrawComponenPositiontData::CUBE_HEIGHT;
    }
    else if(type == Constants::ComponentType::PyramidTypeString){
        *width = Constants::DrawComponenPositiontData::PYRAMID_WIDTH;
        *height = Constants::DrawComponenPositiontData::PYRAMID_HEIGHT;
    }
    else if(type == Constants::ComponentType::SphereTypeString){
        *width = Constants::DrawComponenPositiontData::SPHERE_WIDTH;
        *height = Constants::DrawComponenPositiontData::SPHERE_HEIGHT;
    }
    else if(type == Constants::ComponentType::LineTypeString){
        *width = Constants::DrawComponenPositiontData::LINE_WIDTH;
        *height = Constants::DrawComponenPositiontData::LINE_HEIGHT;
    }
}
