#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
void jiedong()
{
    FILE *ABC = popen("adb shell pm list packages -d","r");
    char BACK[1024];
    vector<string> appInfo;
    while(fgets(BACK, sizeof(BACK), ABC)!=NULL)
    {
        appInfo.push_back(BACK);
    }
    for(auto i=appInfo.begin();i!=appInfo.end();++i)
    {
        i->erase(0,8);
        *i="adb shell pm enable "+(*i);
    }
    for(auto i=appInfo.begin();i!=appInfo.end();++i)
    {
       system(i->c_str());
    }
    pclose(ABC);
}
int main()
{
    int choice;
    cout<<"****************************************************************"<<endl<<endl<<"酷安:WF_Belief 吾爱:辰某"<<endl<<"1.本程序完全免费 如您是购买所得 请立即退款"<<endl<<"2.优化前，请备份好数据，以防出现问题"<<endl<<"3.使用本程序则代表您同意接受可能带来的风险,如:数据丢失、卡米等"<<endl<<endl<<"****************************************************************"<<endl<<endl<<"本程序发布前已经过测试，但不保证您使用过程中不会出现意外情况，如有BUG或意见，欢迎私信作者反馈"<<endl;
    cout<<"请确保手机可以进入Fastboot模式"<<"进入Fastboot模式后请按回车继续"<<endl;
    getchar();
    system("adb devices");
    cout<<endl<<"如List of devices attached后无内容,请检查是否给予电脑USB调试权限、更换数据线、更换电脑接口并重新打开程序"<<endl<<"如有内容，请按回车继续";
    cout<<"请选择救砖模式"<<endl<<"输入1 = 删除所有Magisk模块"<<endl<<"输入2 = 解除所有应用的禁用"<<endl<<"输入3 = 我不清楚为何变砖"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        system("adb shell magisk --remove-modules");
        cout<<"执行成功 程序将于30s后自动关闭 您也可以手动关闭"<<endl;
        _sleep(30000);
        break;
    case 2:
        jiedong();
        cout<<"执行成功 程序将于30s后自动关闭 您也可以手动关闭"<<endl;
        _sleep(30000);
        break;
    case 3:
    	cout<<"请问您的手机是否已经root"<<endl<<"输入1 = 是 输入2 = 否"<<endl;
    	int YN;
		cin>>YN;
		if(YN==1)
		{
			system("adb shell magisk --remove-modules");
			jiedong();
			cout<<"执行成功 程序将于30s后自动关闭 您也可以手动关闭"<<endl;
			_sleep(30000);
			break;
		}
		else jiedong();
		cout<<"执行成功 程序将于30s后自动关闭 您也可以手动关闭"<<endl;
		_sleep(30000);
		break;
    }
}
