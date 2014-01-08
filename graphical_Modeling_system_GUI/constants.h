#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using namespace std;

//紀錄一些會用到常數值
class Constants
{
public:
    static void SetComponentWidthHeight(int* height,int* width,string type);

    //Component時繪製的座標
    class DrawComponenPositiontData{
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

        //繪製的起始位置與偏差位移
        static float COMPONENT_BEGIN_X ;
        static float COMPONENT_BEGIN_Y;
        static float COMPONENT_DIFF_Y;
    };
    //Group時繪製的座標
    class DrawGroupsPositionData{
    public:
        static float GROUP_BEGIN_X;
        static float GROUP_BEGIN_Y;
        static float GROUP_DIFF_Y;
    };

    class ComponentType{
    public:
        //Console用 由number對應
        static int SphereType;
        static int PyramidType;
        static int CubeType;
        static int LineType;

        //繪製的類型(字串)
        static string SphereTypeString;
        static string PyramidTypeString;
        static string CubeTypeString;
        static string LineTypeString;

    };


    class GUIMainWindowParameter{
    public:
        static string XML_FILES_PATH; //紀錄讀檔的資料夾路徑
        static string COMPONENTS_LIST_WIDGET_HEADER; //Component ListWidget顯示的表頭字串
        static string GROUPS_LIST_WIDGET_HEADER; //Group ListWidget顯示的表頭字串
    };

    //State pattern用
    enum DrawViewStateEnum{
        DRAW_LINE_STATE = 0,
        DRAW_NORMAL_STATE
    };
};
//紀錄要繪製的座標與寬高
struct DrawableData{
public:
    int x;
    int y;
    int width;
    int height;
    //Line才用
    int x2;
    int y2;
};

#endif // CONSTANTS_H
