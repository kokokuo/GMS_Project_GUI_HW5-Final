#include "constants.h"

float Constants::DrawComponentData::CUBE_WIDTH = 60;
float Constants::DrawComponentData::CUBE_HEIGHT = 60;
float Constants::DrawComponentData::PYRAMID_WIDTH = 80;
float Constants::DrawComponentData::PYRAMID_HEIGHT = 50;
float Constants::DrawComponentData::SPHERE_WIDTH = 50;
float Constants::DrawComponentData::SPHERE_HEIGHT = 50;
float Constants::DrawComponentData::LINE_WIDTH = 50;
float Constants::DrawComponentData::LINE_HEIGHT = 1;

string Constants::DrawComponentData::SphereTypeString ="Sphere";
string Constants::DrawComponentData::PyramidTypeString ="Pyramid";
string Constants::DrawComponentData::CubeTypeString = "Cube";
string Constants::DrawComponentData::LineTypeString = "Line";

float Constants::DrawComponentData::COMPONENT_BEGIN_X = 50;
float Constants::DrawComponentData::COMPONENT_BEGIN_Y = 50;
float Constants::DrawComponentData::COMPONENT_DIFF_Y = 70;

float Constants::DrawComponentData::GROUP_BEGIN_X = 250;
float Constants::DrawComponentData::GROUP_BEGIN_Y = 50;
float Constants::DrawComponentData::GROUP_DIFF_Y = 50;

//ComponentType靜態類別參數設定
int Constants::ComponentType::CubeType =1;
int Constants::ComponentType::PyramidType = 2;
int Constants::ComponentType::SphereType = 3;
int Constants::ComponentType::LineType = 4;

string Constants::GUIMainWindowParameter::XML_FILES_PATH = "graphical_Modeling_system_GUI/GMS XML Files";
string Constants::GUIMainWindowParameter::COMPONENTS_LIST_WIDGET_HEADER = "Type , ID , Name\n======================";
string Constants::GUIMainWindowParameter::GROUPS_LIST_WIDGET_HEADER = "GID , Name , Members\n=====================";
