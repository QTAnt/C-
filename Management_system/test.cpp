/*设计:1.采用文件方式存储所有的员工;2.使用C++的STL库进行查找功能;*/
#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include <vector>
#include <algorithm>//STL查找函数
using namespace std;

#define STROEFILE "Employ.txt"//存储雇员的文本文件名//雇员类型枚举

enum Enum_EmployType
{ 
	EmptyEmployType,//空类型 
	Manager,//普通经理 
	Technician,//技术员 
	Seller,//销售员 
	SalesManager,//销售经理
};

//性别枚举
enum Enum_Gender{ 
	EmptyGender,//空类型 
	Male,//男 
	Female,//女
};

//雇员类
class Employ
{
public: Enum_EmployType m_Type;//雇员类型枚举 
		int m_Number;//工号 
		string m_Name;//姓名 
		float m_Salary;//月工资 
		string m_Post;//岗位 
		int m_Age;//年龄 
		Enum_Gender m_Gender;//性别
public: 
	//无参构造函数 
	Employ() 
	{  
		m_Type = EmptyEmployType;  
		m_Number = 0;  m_Name = "";  
		m_Salary = 0.0;  m_Post = "";  
		m_Age = 0;  
		m_Gender = EmptyGender;
	} 

	//拷贝构造函数 
	Employ(const Employ &otherData) 
	{  
		this->m_Age = otherData.m_Age;  
		this->m_Gender = otherData.m_Gender;  
		this->m_Name = otherData.m_Name;  
		this->m_Number = otherData.m_Number;  
		this->m_Post = otherData.m_Post;  
		this->m_Salary = otherData.m_Salary;  
		this->m_Type = otherData.m_Type; 
	} 
	
	//将字符号串转化为类对象,以便从文件中读出员工信息 
	void FromString(const char *inStr) 
	{  
		if ( NULL == inStr )  
		{   return;  }  
		char seps[]   = "|"; 
		char *token = NULL;  
		int i = 0;  
		token = strtok( (char *)inStr, seps );  
		while( token != NULL )  
		{   switch(i)   
			{   
				case 0://第1个字段为 雇员类型枚举    
					{     
						m_Type = (Enum_EmployType)(atoi(token));     
						break;   
					}
				case 1://第2个字段为 工号    
					{    
						m_Number = atoi(token);
						break;    
					}   
				case 2://第3个字段为 姓名    
					{     
						m_Name = token;     
						break;    
					}   
				case 3://第4个字段为 月工资    
					{     
						m_Salary = atof(token);     
						break;    
					}   
				case 4://第5个字段为 岗位    
					{     
						m_Post = token;
						break;    
					}   
				case 5://第6个字段为 年龄    
					{     
						m_Age = atoi(token);     
						break;    
					}   
				case 6://第7个字段为 性别    
				{     
					m_Gender = (Enum_Gender)(atoi(token));
					break;    
				}   
			}   
		
		//获取下一个字段   
		token = strtok( NULL, seps ); // C4996   
		i++;  
		} 
	} //将本类转化为字符串,以便记录到文件,各字段之间用|(竖线)分隔 
	
	void ToStringForSave(string *outStr) 
	{  
		if ( NULL == outStr )  
			{   
				return;  
			}  
		char tmpValue[1024];//定义一个临时字符串转换不是字符串型的数据到字符串  
		
		//员工类型  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Type);  
		*outStr = tmpValue; 
		*outStr += "|";  //员工工号  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Number);  
		*outStr += tmpValue;  
		*outStr += "|";  //员工姓名  
		*outStr += m_Name;  
		*outStr += "|";  //员工月工资  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%.2f",m_Salary);  
		*outStr += tmpValue;  
		*outStr += "|";  //员工岗位  
		*outStr += m_Post;  
		*outStr += "|";  //员工年龄  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Age);  
		*outStr += tmpValue;  
		*outStr += "|";  //员工性别  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Gender);  
		*outStr += tmpValue; 
	} 
	
//将本类转化为字符串,以变显示在屏幕上 
void ToStringForShow(string *outStr) 
{  
	if ( NULL == outStr )  
	{   
		return;  
	}  
		
	char tmpValue[1024];//定义一个临时字符串转换不是字符串型的数据到字符串 

	//员工类型  
	memset(tmpValue,0x0,1024);  
	switch(m_Type)  
	{  
		case 0:   
			sprintf(tmpValue,"员工类型:空类型");   
			break;  
		case 1:   
			sprintf(tmpValue,"员工类型:普通经理");   
			break;  
		case 2:   
			sprintf(tmpValue,"员工类型:技术员");   
			break;  
		case 3:   
			sprintf(tmpValue,"员工类型:销售员");  
			break;  
		case 4:   
			sprintf(tmpValue,"员工类型:销售经理");   
			break;  
	}  
	*outStr = tmpValue;  
	*outStr += "\n";  //员工工号  
	memset(tmpValue,0x0,1024);  
	sprintf(tmpValue,"员工工号%d",m_Number);  
	*outStr += tmpValue;  
	*outStr += "\n";  //员工姓名  
	*outStr += "员工姓名:";  
	*outStr += m_Name;  
	*outStr += "\n";  //员工月工资  
	memset(tmpValue,0x0,1024);  
	sprintf(tmpValue,"员工月工资:%.2f",m_Salary);  
	*outStr += tmpValue;  
	*outStr += "\n";  //员工岗位  
	*outStr += "员工岗位:"; 
	*outStr += m_Post; 
	*outStr += "\n";  //员工年龄  
	memset(tmpValue,0x0,1024); 
	sprintf(tmpValue,"员工年龄:%d",m_Age); 
	*outStr += tmpValue; 
	*outStr += "\n";  //员工性别 
	memset(tmpValue,0x0,1024);  
	switch(m_Gender)  
	{  
		case 0:   
			sprintf(tmpValue,"员工性别:保密");  
			break;  
		case 1:   
			sprintf(tmpValue,"员工性别:男");  
			break;  
		case 2:  
			sprintf(tmpValue,"员工性别:女");   
			break; 
	}   
	*outStr += tmpValue;
	*outStr += "\n---"; 
} 

//手动输入员工信息 
void HandEnterInfo() 
{  
	char tmpInput[1024];  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("员工类型(1-普通经理,2-技术员,3-销售员,4-销售经理,其他值-无类型) = ");  
	scanf("%s",tmpInput);  
	m_Type = (Enum_EmployType)(atoi(tmpInput));  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("员工工号 = ");  
	scanf("%s",tmpInput);  
	m_Number = atoi(tmpInput);  
	fflush(stdin); 
	memset(tmpInput,0x0,1024);  
	printf("员工姓名 = ");  
	scanf("%s",tmpInput); 
	m_Name = tmpInput;  
	fflush(stdin);  
	memset(tmpInput,0x0,1024); 
	printf("员工月工资 = ");  
	scanf("%s",tmpInput);  
	m_Salary = atof(tmpInput);  
	fflush(stdin);  
	memset(tmpInput,0x0,1024); 
	printf("员工岗位 = ");  
	scanf("%s",tmpInput);  
	m_Post = tmpInput;  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("员工年龄 = ");  
	scanf("%s",tmpInput);  
	m_Age = atoi(tmpInput);  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("员工性别(1-男,2-女,其他值-保密) = ");  
	scanf("%s",tmpInput); 
	m_Gender = (Enum_Gender)(atoi(tmpInput));  
	fflush(stdin);
}
public: //重载赋值操作符 
				
	Employ & operator = (const Employ &otherData) 
	{  
		this->m_Age = otherData.m_Age;  
		this->m_Gender = otherData.m_Gender; 
		this->m_Name = otherData.m_Name;
		this->m_Number = otherData.m_Number;  
		this->m_Post = otherData.m_Post; 
		this->m_Salary = otherData.m_Salary; 
		this->m_Type = otherData.m_Type; 
		return *this; 
	} 

	//重载等于(判断相等)操作符 //我自己定义为如果工号相等或者名字相等即为等于 
	bool operator == (const Employ &otherData) 
	{ 
		if ( this->m_Name == otherData.m_Name || this->m_Number == otherData.m_Number )  
		{   
			return true; 
		}  
		return false;
	}
};
	
//显示菜单的函数,返回选择项
//type为 1-表示显示主菜单
int ShowMenu()
{ 
	printf("\t\t***************************************\n"); 
	printf("\t\t\t员工管理系统\n");
	printf("\t\t***************************************\n"); 
	printf("\t\t1.增加员工.\n"); 
	printf("\t\t2.修改员工信息.\n"); 
	printf("\t\t3.删除员工信息.\n");
	printf("\t\t4.显示所有员工信息.\n"); 
	printf("\t\t5.按条件查找员工.\n"); 
	printf("\t\t0.退出.\n\n"); 
	fflush(stdin); 
	char Choose[1024]; 
	int iChose = -1;
	memset(Choose,0x0,1024);
	printf("选择 = ");
	scanf("%s",Choose); 
	try { 
		iChose = atoi(Choose); 
		if ( iChose < 0 || iChose > 5 )  
		{  
			return ShowMenu(); 
		} 
		return iChose;
	} 
	catch(...)
	{ 
		return ShowMenu(); 
	}
}
	
//将所有员工数据从文件读到内存
void ReadEmployData(vector<Employ> *pInOutEmploys)
{ 
	if ( NULL == pInOutEmploys ) 
	{  
		return;
	} 
	pInOutEmploys->clear();
	FILE *pf = fopen(STROEFILE,"rt");
	if ( NULL == pf )
	{  
		if ( 2 == errno )//文件不存在  
		{  
			pf = fopen(STROEFILE,"wt");  
			if ( pf == NULL )   
			{    perror("打开员工存储文件失败:");    
				return;   
			} 
		}  
		else 
		{   
			perror("打开员工存储文件失败:");  
			return; 
		}
	}
	char tmpLineData[1024]; 
	while ( ! feof(pf) )
	{  
		//从文件中读取所有员工信息  
		memset(tmpLineData,0x0,1024);  
		fscanf(pf,"%s\n",tmpLineData);  
		if ( strlen(tmpLineData) < 1 )  
		{   
			break;  
		}  
		Employ aEmploy;//定义员工对象  
		aEmploy.FromString(tmpLineData);//调用将字符串转换为对象的函数 
		pInOutEmploys->push_back(aEmploy);//将获取到的一个员工信息添加到内存中 
	} 
	fclose(pf);
}
		
//将所有员工数据从内存写到文件
void WriteEmployData(const vector<Employ> *pInEmploys)
{ 
	if ( NULL == pInEmploys )
	{ 
		return; 
	} 
	FILE *pf = fopen(STROEFILE,"wt"); 
	if ( NULL == pf ) 
	{  
		perror("打开员工存储文件失败:"); 
		return;
	}
	for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )
	{ 
		Employ tmpEmploy = pInEmploys->at(i);//此时调用拷贝构造函数  
		string tmpLine;  
		tmpEmploy.ToStringForSave(&tmpLine);//将对象转换为字符串 
		fprintf(pf,"%s\n",tmpLine.c_str());//将字符串写到文件 
	} 
	fclose(pf);
}
		
//增加员工的函数
void AddEmploy(vector<Employ> *pInEmploys)
{ 
	if ( NULL == pInEmploys ) 
	{  
		return;
	} 
	Employ tmpEmploy; 
	tmpEmploy.HandEnterInfo();
	//查找函数调用了Employ类的==操作符 
	vector<Employ>::iterator found = find(pInEmploys->begin(),pInEmploys->end(),tmpEmploy); 
	if ( found == pInEmploys->end() )//没找到相同名字或相同工号的员工 
	{ 
		pInEmploys->push_back(tmpEmploy); 
	} 
	else 
	{  
		string tmpOut;  found->ToStringForShow(&tmpOut);  
		printf("您输入的新员工与如下员工的姓名或工号重复,因此,不能添加您输入的员工.\n%s",tmpOut.c_str()); 
	}
}


		//显示所有员工信息函数
void ShowAllEmploy(const vector<Employ> *pInEmploys)
{ 
	if ( NULL == pInEmploys ) 
		{ 
			return; 
		}
	printf("所有员工信息如下:\n===================================================\n"); 

	if ( pInEmploys->size() < 1 ) 
		{  
			printf("暂无信息\n"); 
		} 
	else 
	{ 
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )  
		{  
			Employ tmpEmploy = pInEmploys->at(i); 
			string tmpStr; 
			tmpEmploy.ToStringForShow(&tmpStr);  
			printf("%s\n",tmpStr.c_str());
		}
	}
	printf("===================================================\n");
}

//按条件查找员工(ShowInFunc为真时在本函数内部显示找到的员工并忽略pInOutFound参数,为假时不显示找到的符合条件的员工由pInOutFound参数带回)
void FindEmploy(const vector<Employ> *pInEmploys,vector<int> *pInOutFound,bool ShowInFunc)
{ 
	if ( NULL == pInEmploys) 
	{ 
		return; 
	} 
	vector<int> ForShowInThisFunc;
	if ( ! ShowInFunc )
	{ 
		if ( NULL == pInOutFound )  
		{   
			return; 
		} 
	else  
	{ 
		pInOutFound->clear(); 
	}
	}
	else 
	{ 
		pInOutFound = &ForShowInThisFunc; 
	}
	fflush(stdin);
	char Choose[1024];
	int iChose = -1;
	memset(Choose,0x0,1024);
	while ( iChose == -1 )
	{  
		printf("请选择条件(1-按雇员类型,2-工号,3-姓名,4-月工资,5-岗位,6-年龄,7-性别) = "); 
		scanf("%s",Choose);  
		try  {   iChose = atoi(Choose);  } 
		catch(...) 
		{   iChose = -1;  } 
	} 
	switch( iChose ) 
{
	case 1://按雇员类型  
	{   
		printf("请选择类型(1-普通经理,2-技术员,3-销售员,4-销售经理,其他值-无类型) = ");   
		memset(Choose,0x0,1024);  
		scanf("%s",Choose);  
		try  
		{    
			iChose = atoi(Choose);   
		}  
		catch(...)   
		{   
			iChose = 0; 
		}   
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )   
		{   
			if ( pInEmploys->at(i).m_Type == iChose )    
			{    
				pInOutFound->push_back(i);    
			}  
		}   
		break; 
	} 
	case 2://工号  
	{   
		printf("请输入工号 = ");  
		memset(Choose,0x0,1024); 
		scanf("%s",Choose);   
		try  
		{   
			iChose = atoi(Choose);  
		}  
		catch(...)  
		{   
			iChose = 0;  
		}  
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )   
		{  
			if ( pInEmploys->at(i).m_Number == iChose )   
			{     pInOutFound->push_back(i);    
			}   
		}  
		break;
	} 

	case 3://姓名  
	{   
		printf("请输入姓名 = "); 
		memset(Choose,0x0,1024);   
		scanf("%s",Choose);  
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )  
		{   
			if ( pInEmploys->at(i).m_Name == Choose )    
			{     pInOutFound->push_back(i);   
			}  
		}  
		break;  
	} 
	case 4://月工资  
	{  
		printf("请输入月工资 = ");  
		memset(Choose,0x0,1024);  
		scanf("%s",Choose);  
		float gz = 0.0;
		try  
		{    gz = atof(Choose);   }  
		catch(...)  
		{    gz = 0.0;   }  
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )  
		{   
			if ( pInEmploys->at(i).m_Salary == gz )  
			{    
				pInOutFound->push_back(i);  
			}  
		} 
		break; 
	}
	case 5://岗位  
	{  
		printf("请输入岗位 = ");  
		memset(Choose,0x0,1024);
		scanf("%s",Choose); 
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )  
		{    
			if ( pInEmploys->at(i).m_Post == Choose ) 
			{   
				pInOutFound->push_back(i);  
			}
		} 
		break; 
	}
	case 6://年龄  
	{   printf("请输入年龄 = ");   
		memset(Choose,0x0,1024);
		scanf("%s",Choose);  
		try  
		{    iChose = atoi(Choose); 
		} 
		catch(...)  
		{    iChose = -1;   }  
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ ) 
		{    if ( pInEmploys->at(i).m_Age == iChose ) 
		{     
			pInOutFound->push_back(i);  
		}  
		}  
		break; 
	} 
	case 7://性别  
	{   
		printf("请选择类型(1-男,2-女,其他值-保密) = "); 
		memset(Choose,0x0,1024);  
		scanf("%s",Choose);  
		try   {    iChose = atoi(Choose);   }  
		catch(...)   {    iChose = 0;   } 
		for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ ) 
		{    if ( pInEmploys->at(i).m_Gender == iChose ) 
		{     pInOutFound->push_back(i);    }  
		} 
		break; 
	}
} 
	if( ShowInFunc )
	{ 
		printf("找到如下员工符合条件:\n=================================================\n"); 
		if ( pInOutFound->size() < 1 )  
		{  
			printf("无员工符合.\n"); 
		} 
		else  
		{ 
			for ( unsigned int i = 0 ; i < pInOutFound->size() ; i++ ) 
			{    
				string tmpOut; 
				Employ tmpEpl = pInEmploys->at(pInOutFound->at(i));  
				tmpEpl.ToStringForShow(&tmpOut); 
				printf("%s\n",tmpOut.c_str()); 
			} 
		}  
		printf("=================================================\n"); 
	}
}

//主函数
int main(void){ 
	//所有员工数据 
	vector<Employ> AllEmployDatas; 

	//程序启动时将所有员工数据从文件读到内存 
	ReadEmployData(&AllEmployDatas); 
	int Choose = ShowMenu(); 
	while ( 0 != Choose )
	{  
		switch( Choose ) 
		{  
			case 1://增加员工  
		{    AddEmploy(&AllEmployDatas);   
			break;  
		}
		case 2://修改员工信息  
		{   
			vector<int> FoundEmploysIndex;    
			FindEmploy(&AllEmployDatas,&FoundEmploysIndex,false);  
			if ( FoundEmploysIndex.size() > 1 )  
			{    
				printf("暂时不支持一次修改多个员工信息,请更改查询条件查询到一个员工再修改!\n");    
				break;   
			}   
			else if ( FoundEmploysIndex.size() == 0 )    
			{    
				printf("没找到你想修改的员工信息,请更改查询条件查询到一个员工再修改!\n");    
				break;   
			}    
			int index = FoundEmploysIndex[0];  
			string tmpFound;  
			AllEmployDatas[index].ToStringForShow(&tmpFound);  
			printf("已找到你想修改的员工信息为:\n%s\n请重新录入此员工的信息:\n",tmpFound.c_str()); AllEmployDatas[index].HandEnterInfo();    
				break;   
		}  
		case 3://删除员工信息   
		{  
			vector<int> FoundEmploysIndex;   
			FindEmploy(&AllEmployDatas,&FoundEmploysIndex,false); 
			if ( FoundEmploysIndex.size() > 1 ) 
			{    
				printf("暂时不支持一次删除多个员工信息,请更改查询条件查询到一个员工再删除!\n");    
				break;    
			}  
			else if ( FoundEmploysIndex.size() == 0 )    
			{    
				printf("没找到你想删除的员工信息,请更改查询条件查询到一个员工再删除!\n");   
				break;   
			}   

			int index = FoundEmploysIndex[0];  
			string tmpFound; 
			AllEmployDatas[index].ToStringForShow(&tmpFound);   
			printf("已找到你想删除的员工信息为:\n%s\n请确认删除此员工的信息[y/n]: = ",tmpFound.c_str());    
			fflush(stdin);  
			char Choose[1024];   
			memset(Choose,0x0,1024); 
			scanf("%s",Choose);   
			if ( strcmp("Y",Choose) == 0 || strcmp("y",Choose) == 0 ) 
			{     
				vector<Employ>::iterator pointer = AllEmployDatas.begin()+index; 
				AllEmployDatas.erase(pointer);    
			}    
			break;  
		}  
				
		case 4://显示所有员工信息  
		{    
			ShowAllEmploy(&AllEmployDatas);   
			break;  
		}  
		case 5://按条件查找员工  
		{ 
			FindEmploy(&AllEmployDatas,NULL,true); 
			break;  
		} 
	}  
	fflush(stdin); 
	printf("操作完成,按回车键继续..."); 
	getchar(); 
	Choose = ShowMenu();
}
	//程序结束时将所有员工数据从内存写到文件 
	WriteEmployData(&AllEmployDatas);
	//写完后清理
	AllEmployDatas.clear(); 

	return 0;
}