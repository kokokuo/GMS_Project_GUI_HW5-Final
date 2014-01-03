#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using namespace std;

class Constants
{
public:
    //紀錄一些資料與參數
    class DrawComponentData{
    public:
        //繪製的寬與高
        static float CUBE_WIDTH;
        static float CUBE_HEIGHT;
        static float PYRAMID_WIDTH ;
        static float PYRAMID_HEIGHT;
        static float SPHERE_WIDTH;
        static float SPHERE_HEIGHT;
        static float LINE_WIDTH;
        static float LINE_HEIGHT;
        //繪製的類型
        static string SphereTypeString;
        static string PyramidTypeString;
        static string CubeTypeString;
        static string LineTypeString;

        //繪製的起始位置與偏差位移
        static float COMPONENT_BEGIN_X ;
        static float COMPONENT_BEGIN_Y;
        static float COMPONENT_DIFF_Y;

        static float GROUP_BEGIN_X;
        static float GROUP_BEGIN_Y;
        static float GROUP_DIFF_Y;
    };

    class ComponentType{
    public:
        static int SphereType;
        static int PyramidType;
        static int CubeType;
        static int LineType;
    };

    class GUIMainWindowParameter{
    public:
        static string XML_FILES_PATH;
        static string COMPONENTS_LIST_WIDGET_HEADER;
        static string GROUPS_LIST_WIDGET_HEADER;
    };
};

#endif // CONSTANTS_H
