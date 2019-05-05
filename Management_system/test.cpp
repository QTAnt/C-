/*���:1.�����ļ���ʽ�洢���е�Ա��;2.ʹ��C++��STL����в��ҹ���;*/
#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include <vector>
#include <algorithm>//STL���Һ���
using namespace std;

#define STROEFILE "Employ.txt"//�洢��Ա���ı��ļ���//��Ա����ö��

enum Enum_EmployType
{ 
	EmptyEmployType,//������ 
	Manager,//��ͨ���� 
	Technician,//����Ա 
	Seller,//����Ա 
	SalesManager,//���۾���
};

//�Ա�ö��
enum Enum_Gender{ 
	EmptyGender,//������ 
	Male,//�� 
	Female,//Ů
};

//��Ա��
class Employ
{
public: Enum_EmployType m_Type;//��Ա����ö�� 
		int m_Number;//���� 
		string m_Name;//���� 
		float m_Salary;//�¹��� 
		string m_Post;//��λ 
		int m_Age;//���� 
		Enum_Gender m_Gender;//�Ա�
public: 
	//�޲ι��캯�� 
	Employ() 
	{  
		m_Type = EmptyEmployType;  
		m_Number = 0;  m_Name = "";  
		m_Salary = 0.0;  m_Post = "";  
		m_Age = 0;  
		m_Gender = EmptyGender;
	} 

	//�������캯�� 
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
	
	//���ַ��Ŵ�ת��Ϊ�����,�Ա���ļ��ж���Ա����Ϣ 
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
				case 0://��1���ֶ�Ϊ ��Ա����ö��    
					{     
						m_Type = (Enum_EmployType)(atoi(token));     
						break;   
					}
				case 1://��2���ֶ�Ϊ ����    
					{    
						m_Number = atoi(token);
						break;    
					}   
				case 2://��3���ֶ�Ϊ ����    
					{     
						m_Name = token;     
						break;    
					}   
				case 3://��4���ֶ�Ϊ �¹���    
					{     
						m_Salary = atof(token);     
						break;    
					}   
				case 4://��5���ֶ�Ϊ ��λ    
					{     
						m_Post = token;
						break;    
					}   
				case 5://��6���ֶ�Ϊ ����    
					{     
						m_Age = atoi(token);     
						break;    
					}   
				case 6://��7���ֶ�Ϊ �Ա�    
				{     
					m_Gender = (Enum_Gender)(atoi(token));
					break;    
				}   
			}   
		
		//��ȡ��һ���ֶ�   
		token = strtok( NULL, seps ); // C4996   
		i++;  
		} 
	} //������ת��Ϊ�ַ���,�Ա��¼���ļ�,���ֶ�֮����|(����)�ָ� 
	
	void ToStringForSave(string *outStr) 
	{  
		if ( NULL == outStr )  
			{   
				return;  
			}  
		char tmpValue[1024];//����һ����ʱ�ַ���ת�������ַ����͵����ݵ��ַ���  
		
		//Ա������  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Type);  
		*outStr = tmpValue; 
		*outStr += "|";  //Ա������  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Number);  
		*outStr += tmpValue;  
		*outStr += "|";  //Ա������  
		*outStr += m_Name;  
		*outStr += "|";  //Ա���¹���  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%.2f",m_Salary);  
		*outStr += tmpValue;  
		*outStr += "|";  //Ա����λ  
		*outStr += m_Post;  
		*outStr += "|";  //Ա������  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Age);  
		*outStr += tmpValue;  
		*outStr += "|";  //Ա���Ա�  
		memset(tmpValue,0x0,1024);  
		sprintf(tmpValue,"%d",m_Gender);  
		*outStr += tmpValue; 
	} 
	
//������ת��Ϊ�ַ���,�Ա���ʾ����Ļ�� 
void ToStringForShow(string *outStr) 
{  
	if ( NULL == outStr )  
	{   
		return;  
	}  
		
	char tmpValue[1024];//����һ����ʱ�ַ���ת�������ַ����͵����ݵ��ַ��� 

	//Ա������  
	memset(tmpValue,0x0,1024);  
	switch(m_Type)  
	{  
		case 0:   
			sprintf(tmpValue,"Ա������:������");   
			break;  
		case 1:   
			sprintf(tmpValue,"Ա������:��ͨ����");   
			break;  
		case 2:   
			sprintf(tmpValue,"Ա������:����Ա");   
			break;  
		case 3:   
			sprintf(tmpValue,"Ա������:����Ա");  
			break;  
		case 4:   
			sprintf(tmpValue,"Ա������:���۾���");   
			break;  
	}  
	*outStr = tmpValue;  
	*outStr += "\n";  //Ա������  
	memset(tmpValue,0x0,1024);  
	sprintf(tmpValue,"Ա������%d",m_Number);  
	*outStr += tmpValue;  
	*outStr += "\n";  //Ա������  
	*outStr += "Ա������:";  
	*outStr += m_Name;  
	*outStr += "\n";  //Ա���¹���  
	memset(tmpValue,0x0,1024);  
	sprintf(tmpValue,"Ա���¹���:%.2f",m_Salary);  
	*outStr += tmpValue;  
	*outStr += "\n";  //Ա����λ  
	*outStr += "Ա����λ:"; 
	*outStr += m_Post; 
	*outStr += "\n";  //Ա������  
	memset(tmpValue,0x0,1024); 
	sprintf(tmpValue,"Ա������:%d",m_Age); 
	*outStr += tmpValue; 
	*outStr += "\n";  //Ա���Ա� 
	memset(tmpValue,0x0,1024);  
	switch(m_Gender)  
	{  
		case 0:   
			sprintf(tmpValue,"Ա���Ա�:����");  
			break;  
		case 1:   
			sprintf(tmpValue,"Ա���Ա�:��");  
			break;  
		case 2:  
			sprintf(tmpValue,"Ա���Ա�:Ů");   
			break; 
	}   
	*outStr += tmpValue;
	*outStr += "\n---"; 
} 

//�ֶ�����Ա����Ϣ 
void HandEnterInfo() 
{  
	char tmpInput[1024];  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("Ա������(1-��ͨ����,2-����Ա,3-����Ա,4-���۾���,����ֵ-������) = ");  
	scanf("%s",tmpInput);  
	m_Type = (Enum_EmployType)(atoi(tmpInput));  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("Ա������ = ");  
	scanf("%s",tmpInput);  
	m_Number = atoi(tmpInput);  
	fflush(stdin); 
	memset(tmpInput,0x0,1024);  
	printf("Ա������ = ");  
	scanf("%s",tmpInput); 
	m_Name = tmpInput;  
	fflush(stdin);  
	memset(tmpInput,0x0,1024); 
	printf("Ա���¹��� = ");  
	scanf("%s",tmpInput);  
	m_Salary = atof(tmpInput);  
	fflush(stdin);  
	memset(tmpInput,0x0,1024); 
	printf("Ա����λ = ");  
	scanf("%s",tmpInput);  
	m_Post = tmpInput;  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("Ա������ = ");  
	scanf("%s",tmpInput);  
	m_Age = atoi(tmpInput);  
	fflush(stdin);  
	memset(tmpInput,0x0,1024);  
	printf("Ա���Ա�(1-��,2-Ů,����ֵ-����) = ");  
	scanf("%s",tmpInput); 
	m_Gender = (Enum_Gender)(atoi(tmpInput));  
	fflush(stdin);
}
public: //���ظ�ֵ������ 
				
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

	//���ص���(�ж����)������ //���Լ�����Ϊ���������Ȼ���������ȼ�Ϊ���� 
	bool operator == (const Employ &otherData) 
	{ 
		if ( this->m_Name == otherData.m_Name || this->m_Number == otherData.m_Number )  
		{   
			return true; 
		}  
		return false;
	}
};
	
//��ʾ�˵��ĺ���,����ѡ����
//typeΪ 1-��ʾ��ʾ���˵�
int ShowMenu()
{ 
	printf("\t\t***************************************\n"); 
	printf("\t\t\tԱ������ϵͳ\n");
	printf("\t\t***************************************\n"); 
	printf("\t\t1.����Ա��.\n"); 
	printf("\t\t2.�޸�Ա����Ϣ.\n"); 
	printf("\t\t3.ɾ��Ա����Ϣ.\n");
	printf("\t\t4.��ʾ����Ա����Ϣ.\n"); 
	printf("\t\t5.����������Ա��.\n"); 
	printf("\t\t0.�˳�.\n\n"); 
	fflush(stdin); 
	char Choose[1024]; 
	int iChose = -1;
	memset(Choose,0x0,1024);
	printf("ѡ�� = ");
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
	
//������Ա�����ݴ��ļ������ڴ�
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
		if ( 2 == errno )//�ļ�������  
		{  
			pf = fopen(STROEFILE,"wt");  
			if ( pf == NULL )   
			{    perror("��Ա���洢�ļ�ʧ��:");    
				return;   
			} 
		}  
		else 
		{   
			perror("��Ա���洢�ļ�ʧ��:");  
			return; 
		}
	}
	char tmpLineData[1024]; 
	while ( ! feof(pf) )
	{  
		//���ļ��ж�ȡ����Ա����Ϣ  
		memset(tmpLineData,0x0,1024);  
		fscanf(pf,"%s\n",tmpLineData);  
		if ( strlen(tmpLineData) < 1 )  
		{   
			break;  
		}  
		Employ aEmploy;//����Ա������  
		aEmploy.FromString(tmpLineData);//���ý��ַ���ת��Ϊ����ĺ��� 
		pInOutEmploys->push_back(aEmploy);//����ȡ����һ��Ա����Ϣ��ӵ��ڴ��� 
	} 
	fclose(pf);
}
		
//������Ա�����ݴ��ڴ�д���ļ�
void WriteEmployData(const vector<Employ> *pInEmploys)
{ 
	if ( NULL == pInEmploys )
	{ 
		return; 
	} 
	FILE *pf = fopen(STROEFILE,"wt"); 
	if ( NULL == pf ) 
	{  
		perror("��Ա���洢�ļ�ʧ��:"); 
		return;
	}
	for ( unsigned int i = 0 ; i < pInEmploys->size() ; i++ )
	{ 
		Employ tmpEmploy = pInEmploys->at(i);//��ʱ���ÿ������캯��  
		string tmpLine;  
		tmpEmploy.ToStringForSave(&tmpLine);//������ת��Ϊ�ַ��� 
		fprintf(pf,"%s\n",tmpLine.c_str());//���ַ���д���ļ� 
	} 
	fclose(pf);
}
		
//����Ա���ĺ���
void AddEmploy(vector<Employ> *pInEmploys)
{ 
	if ( NULL == pInEmploys ) 
	{  
		return;
	} 
	Employ tmpEmploy; 
	tmpEmploy.HandEnterInfo();
	//���Һ���������Employ���==������ 
	vector<Employ>::iterator found = find(pInEmploys->begin(),pInEmploys->end(),tmpEmploy); 
	if ( found == pInEmploys->end() )//û�ҵ���ͬ���ֻ���ͬ���ŵ�Ա�� 
	{ 
		pInEmploys->push_back(tmpEmploy); 
	} 
	else 
	{  
		string tmpOut;  found->ToStringForShow(&tmpOut);  
		printf("���������Ա��������Ա���������򹤺��ظ�,���,��������������Ա��.\n%s",tmpOut.c_str()); 
	}
}


		//��ʾ����Ա����Ϣ����
void ShowAllEmploy(const vector<Employ> *pInEmploys)
{ 
	if ( NULL == pInEmploys ) 
		{ 
			return; 
		}
	printf("����Ա����Ϣ����:\n===================================================\n"); 

	if ( pInEmploys->size() < 1 ) 
		{  
			printf("������Ϣ\n"); 
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

//����������Ա��(ShowInFuncΪ��ʱ�ڱ������ڲ���ʾ�ҵ���Ա��������pInOutFound����,Ϊ��ʱ����ʾ�ҵ��ķ���������Ա����pInOutFound��������)
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
		printf("��ѡ������(1-����Ա����,2-����,3-����,4-�¹���,5-��λ,6-����,7-�Ա�) = "); 
		scanf("%s",Choose);  
		try  {   iChose = atoi(Choose);  } 
		catch(...) 
		{   iChose = -1;  } 
	} 
	switch( iChose ) 
{
	case 1://����Ա����  
	{   
		printf("��ѡ������(1-��ͨ����,2-����Ա,3-����Ա,4-���۾���,����ֵ-������) = ");   
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
	case 2://����  
	{   
		printf("�����빤�� = ");  
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

	case 3://����  
	{   
		printf("���������� = "); 
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
	case 4://�¹���  
	{  
		printf("�������¹��� = ");  
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
	case 5://��λ  
	{  
		printf("�������λ = ");  
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
	case 6://����  
	{   printf("���������� = ");   
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
	case 7://�Ա�  
	{   
		printf("��ѡ������(1-��,2-Ů,����ֵ-����) = "); 
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
		printf("�ҵ�����Ա����������:\n=================================================\n"); 
		if ( pInOutFound->size() < 1 )  
		{  
			printf("��Ա������.\n"); 
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

//������
int main(void){ 
	//����Ա������ 
	vector<Employ> AllEmployDatas; 

	//��������ʱ������Ա�����ݴ��ļ������ڴ� 
	ReadEmployData(&AllEmployDatas); 
	int Choose = ShowMenu(); 
	while ( 0 != Choose )
	{  
		switch( Choose ) 
		{  
			case 1://����Ա��  
		{    AddEmploy(&AllEmployDatas);   
			break;  
		}
		case 2://�޸�Ա����Ϣ  
		{   
			vector<int> FoundEmploysIndex;    
			FindEmploy(&AllEmployDatas,&FoundEmploysIndex,false);  
			if ( FoundEmploysIndex.size() > 1 )  
			{    
				printf("��ʱ��֧��һ���޸Ķ��Ա����Ϣ,����Ĳ�ѯ������ѯ��һ��Ա�����޸�!\n");    
				break;   
			}   
			else if ( FoundEmploysIndex.size() == 0 )    
			{    
				printf("û�ҵ������޸ĵ�Ա����Ϣ,����Ĳ�ѯ������ѯ��һ��Ա�����޸�!\n");    
				break;   
			}    
			int index = FoundEmploysIndex[0];  
			string tmpFound;  
			AllEmployDatas[index].ToStringForShow(&tmpFound);  
			printf("���ҵ������޸ĵ�Ա����ϢΪ:\n%s\n������¼���Ա������Ϣ:\n",tmpFound.c_str()); AllEmployDatas[index].HandEnterInfo();    
				break;   
		}  
		case 3://ɾ��Ա����Ϣ   
		{  
			vector<int> FoundEmploysIndex;   
			FindEmploy(&AllEmployDatas,&FoundEmploysIndex,false); 
			if ( FoundEmploysIndex.size() > 1 ) 
			{    
				printf("��ʱ��֧��һ��ɾ�����Ա����Ϣ,����Ĳ�ѯ������ѯ��һ��Ա����ɾ��!\n");    
				break;    
			}  
			else if ( FoundEmploysIndex.size() == 0 )    
			{    
				printf("û�ҵ�����ɾ����Ա����Ϣ,����Ĳ�ѯ������ѯ��һ��Ա����ɾ��!\n");   
				break;   
			}   

			int index = FoundEmploysIndex[0];  
			string tmpFound; 
			AllEmployDatas[index].ToStringForShow(&tmpFound);   
			printf("���ҵ�����ɾ����Ա����ϢΪ:\n%s\n��ȷ��ɾ����Ա������Ϣ[y/n]: = ",tmpFound.c_str());    
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
				
		case 4://��ʾ����Ա����Ϣ  
		{    
			ShowAllEmploy(&AllEmployDatas);   
			break;  
		}  
		case 5://����������Ա��  
		{ 
			FindEmploy(&AllEmployDatas,NULL,true); 
			break;  
		} 
	}  
	fflush(stdin); 
	printf("�������,���س�������..."); 
	getchar(); 
	Choose = ShowMenu();
}
	//�������ʱ������Ա�����ݴ��ڴ�д���ļ� 
	WriteEmployData(&AllEmployDatas);
	//д�������
	AllEmployDatas.clear(); 

	return 0;
}