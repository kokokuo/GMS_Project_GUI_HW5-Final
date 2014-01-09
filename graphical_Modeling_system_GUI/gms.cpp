#include "gms.h"


GMS::GMS()
{
    isWorking = true;

}
//把components 與groups存入檔案
int GMS::SaveXMLFormatRecord(string path){
    return model.SaveXMLFormatRecord(path);
}
//載入components與groups
int GMS::LoadXMLFormatRecord(string path){
    int code = model.LoadXMLFormatRecord(path);
    if(code == XMLErrorCode::OK){
        cmdManager.ClearCmd();
    }
    return code;
}

//編輯Component 名稱與Type
void GMS::EditComponentNameAndTypeByCommand(int id,string newName,string newType){
    EditComponentCommand *editNameAndTypeCmd = new EditComponentCommand(&model,id,newName,newType);
    cmdManager.execute(editNameAndTypeCmd);
}

void GMS::EditComponentNameByCommand(int id, string newName){
    EditComponentCommand *editNameCmd = new EditComponentCommand(&model,id,newName);
    cmdManager.execute(editNameCmd);
}
void GMS::EditComponentTypeByCommand(int id, string newType){
    EditComponentCommand *editTypeCmd = new EditComponentCommand(&model,newType,id);
    cmdManager.execute(editTypeCmd);
}
void GMS::AddComponentsByCommand(string componentType, string componentName){
    //使用Command加入
    AddComponentCommand* addCmd = new AddComponentCommand(&model,componentType,componentName);
    cmdManager.execute(addCmd);

}
void GMS::AddDrawableComponentsByCommand(string componentType, string componentName,DrawableData data){
    //使用Command加入
    AddComponentCommand* addCmd = new AddComponentCommand(&model,componentType,componentName,data);
    cmdManager.execute(addCmd);

}

void GMS::MoveComponentByCommand(int moveId, int x,int y,int oriX,int oriY){
    MoveComponentCommand* moveComponentCmd = new MoveComponentCommand(&model,moveId,x,y,oriX,oriY);
    cmdManager.execute(moveComponentCmd);
}
void GMS::MoveGroupByCommand(int moveId, int x, int y, int oriX, int oriY){
    MoveGroupCommand* moveGroupCmd = new MoveGroupCommand(&model,moveId,x,y,oriX,oriY);
    cmdManager.execute(moveGroupCmd);
}
//刪除Component與判斷有無存在
bool GMS::DeleteComponentByCommand(int id){
    if(this->model.GetComponents().CheckIDHasBeenExisted(id)){
        //使用Command刪除
        DeleteComponentCommand* delCmd = new DeleteComponentCommand(&model,id);
        cmdManager.execute(delCmd);

        return true; //告知有刪除掉
    }
    return false; //沒有刪除掉 因為不存在
}
//取得所有Components
Components GMS::GetComponents(){
    return this->model.GetComponents();
}
//取得目前生產的ComponentsID
int GMS::GetCurrentComponentMakerID(){
    return this->model.GetComponents().GetCurrentGeneratedComponentID();
}
//取得目前生產的GroupID
int GMS::GetCurrentGroupMakerID(){
    return this->model.GetGroups().GetCurrentGeneratedGroupId();
}

//判斷group有無存在
bool GMS::CheckGroupHasBeenExisted(int groupId){
    return this->model.GetGroups().CheckGroupHasBeenExisted(groupId);
}

//判斷這個ComponentID有無存在Components
bool GMS::CheckComponentIDHasBeenExisted(int id){
    return this->model.GetComponents().CheckIDHasBeenExisted(id);
}
//取得所有Group
Groups GMS::GetGroups(){
    return this->model.GetGroups();
}


//判斷這個MemberId是否存在指定的groupId(使用前請先透過 CheckGroupHasBeenExisted判斷Group有無存在)
bool GMS::CheckMemberIDHasBeenTheGroup(int groupId, int memberId){
    Group* g =  this->model.GetGroups().GetGroup(groupId);
    return  g->CheckMemberHasBeenExisted(memberId);

}
//加入新的Group
void GMS::AddNewGroupByCommand(string name, vector<int> members){
    //使用Command加入新的Group
    AddNewGroupCommand* addGroupCmd = new AddNewGroupCommand(&model,name,members);
    cmdManager.execute(addGroupCmd);

}
void GMS::AddDrawableNewGroupByCommand(string name, vector<int> members,DrawableData data){
    //使用Command加入新的Group
    AddNewGroupCommand* addGroupCmd = new AddNewGroupCommand(&model,name,members,data);
    cmdManager.execute(addGroupCmd);
}


//取得想要的Group
Group* GMS::FindGroupByGroupId(int groupId){
    return this->model.GetGroups().GetGroup(groupId);

}
//加入members ID到Group
void GMS::AddMembersToGroupByCommand(int groupId, vector<int> members){
    //使用Command加入Members到指定的Group
    AddMembersToGroupCommand* addMembersCmd = new AddMembersToGroupCommand(&model,groupId,members);
    cmdManager.execute(addMembersCmd);

}
bool GMS::Redo(){
   return cmdManager.redo();
}
bool GMS::Undo(){
   return cmdManager.undo();
}
void GMS::ClearCommand(){
   cmdManager.ClearCmd();
}
void GMS::OutputComponentsDataByConsole(){
    vector<Component*> components = this->model.GetComponents().GetAllComponent();
    cout << "Components:" << endl;
    cout << "------------------------------------------------------" <<endl;
    cout << "   Type   |   ID    |    Name    " <<endl;
    cout << "------------------------------------------------------" <<endl;
    for(vector<Component*>::iterator it = components.begin();it != components.end();it++){
        //使用C語言印出,為了能夠讓印出的格式排版整齊,[0]是擷取自串的字首
        printf("    %c     |   %2d    |    %s\n",(*it)->GetType()[0],(*it)->GetID(),(*it)->GetName().c_str());

    }
}

void GMS::OutputGroupsDataByConsole(){
    map<string,Group*> groups = this->model.GetGroups().GetAllGroups();
    cout << "Groups:" << endl;
    cout << "------------------------------------------------------" <<endl;
    cout << "   GID   |   Name    |    Member    " <<endl;
    cout << "------------------------------------------------------" <<endl;
    for(map<string,Group*>::iterator it = groups.begin();it != groups.end();it++){
        printf("    %s     |   %s    |    %s\n",it->first.c_str(),(it->second)->GetName().c_str(),(it->second)->GetMembersIdByStringFormat().c_str());
    }
}
