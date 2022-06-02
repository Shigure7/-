#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h> 
#include<stdlib.h> 
#include<conio.h>
#include<time.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")



/*����ṹ��*/
//������Ʒ�����ϣ��ṹ�� 
typedef struct drink
{
	char name[30];           //���� 
	int price;               //�۸� 
	struct drink* next;
}drink;


//����˿͵㵥�ṹ�� 
typedef struct drink_order
{
	char drink_name[10];           //��Ʒ����
	char ingredient_name[2][10];   //ԭ������
	int temperature;               //��Ʒ�¶�
	int sweetness;                 //��Ʒ��� 
	int money;                     //��Ʒ�۸� 
	struct drink_order* next;
}drink_order;

drink_order* o_head = NULL;   //�˿Ͷ���ͷָ��
drink_order* o_end = NULL;    //�˿Ͷ���βָ�� 

//����˿ͻ�Ա��Ϣ
typedef struct vip
{
	int num;                 //��Ա���
	char name[30];           //��Ա���� 
	char phone[20];          //��Ա�ֻ���
	long int money;          //���ѽ��
	struct vip* next;
}vip;

//������Ʒ��Ϣ
struct gift
{
	int num;               //��Ʒ���
	char name[30];         //��Ʒ����
	int score;            //��Ʒ�������
	int stock;           //��Ʒ�������
	struct gift* next;
};

vip* v_head = NULL;   //��Աͷָ��
vip* v_end = NULL;    //��Աβָ��
vip* v_user = NULL;   //ָ���Ա

gift* g_head;//��Ʒͷָ��
gift* g_end;//��Ʒβָ��
gift* g_user;//ָ����Ʒ

//����ÿ������� 
struct id
{
	int id1;
	int id2;
	int id3;
}idi[9];

//�洢ԭ����ĺ�����ݣ�
struct Using_Id {
	int id;   //ԭ�ϵ�id
	wchar_t name[20];    //ԭ�ϵ����� 
	int weight;   //ԭ������ 
}bridge[17];    //��bridge���������ɽṹ�� 


//�������ԭ������ 
typedef struct drink_material   //��Ʒԭ�� 
{
	int id;
	int weight;
	wchar_t name[20];
	int purchasing_price;   //����
	struct drink_material* next;
}Drink_Material;  //��drink_material����ΪDrink_Material; 
typedef Drink_Material* material;   //��Drink_Material*����Ϊmaterial;

//��������ԭ�ϵ����� 
typedef struct buy
{
	int id;     //ԭ�ϵı�ţ� 
	wchar_t name[20];     //ԭ�ϵ����� �� 
	int weight;     //���� �� 
	struct buy* next;
}buy_materials;    //��buy��������Ϊbuy_materials �� 

typedef buy_materials* Buy;     //��nuy_materials*��������ΪBuy��

typedef struct best_drink
{
	int week,month,quater,year;   //�ֱ��ʾ�նȣ��¶ȣ����ȣ���ȵ�������
	struct best_drink* next; 
}best_drink;

best_drink* b_head=NULL;   //�����Ʒͷָ�� 


//���ڹ���ԭ�ϵĽṹ�壻
struct buy_weights
{
	int buy_id;   //����ԭ�ϵ���ţ�
	int BUY_weight;   //����ԭ�ϵ������� 
}weights[17];

//������¼�ṹ�� 
struct order{  //������¼�ṹ�� 
	int id;  //��� 
	char name[30];  //��Ʒ����
	int price;  //�ۼ� 
	int cost;  //�ɱ� 
	int month;  //��
	int day;  //��
	char order_num[30];  //������ 
	struct order *next;
};

typedef struct order_now{  //������¼�ṹ�� 
	int id;  //��� 
	char name[30];  //��Ʒ����
	int price;  //�ۼ� 
	int cost;  //�ɱ� 
	int month;  //��
	int day;  //��
	char order_num[30];  //������ 
	struct order_now *next;
}Order_Now;
typedef Order_Now* Order_now;

/*����ȫ�ֱ���*/
struct drink list1[30]; //�����Ʒ��Ϣ
int num1 = 0; //�����Ʒ����
int* p1 = &num1;
struct drink list2[30]; //���������Ϣ
int num2 = 0; //�����������
int* p2 = &num2;
struct drink_order list3[30]; //��Ź˿͵�������Ϣ
int num3 = 0; //��Ź˿͵���������
int* p3 = &num3;
int num4 = 0; //��Ž�����������������
int* p4 = &num4;
int day = 0;  //�������� 
int* p5 = &day;
int mon = 0;  //�����·�
int* p6 = &mon;
//��Ʒ��Ӧԭ�ϵ����ģ�
int drinks[10][6] ;
//��Ʒ�ĳɱ���
int cost[9] = { 3,4,5,3,5,4,3,6,5 };
//ԭ�Ͼ����ߣ�
int guard[17]={1000,500,1000,1250,1250,500,500,250,250,250,250,250,750,250,500,250,500} ;


/*�˵�����*/
//ѡ��һ
void function1();
//ѡ���
void function2();
//ѡ����
void function3();
//������
void function4();
//������
void function5();



/*���ܲ���*/
//��ӭ�˵�
void main_menu1(void);
//��ʾ���˵� 
void main_menu2(void);
//ʵ�ֵ����ϵĺ������������ϵĽṹ��д�����ݣ�
void ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int i, struct id idi[]);
//ʵ�ֵ����ϵĺ������������ϵĽṹ��д�����ݣ� 
void ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int i, int n, struct id idi[]);
//ʵ�ֵ��¶Ⱥ���ȵĺ����������¶Ⱥ���ȵĽṹ��д�����ݣ�
void ordering3(struct drink_order list3[], int num3, int i);
//��ӡ�˿�����������Ϣ
int print_order(struct drink_order list3[], int num3,bool flag);


/*��������*/
//�����������������txt�ļ�
void create_file(void);
//������Ʒ��������Ϣ���ṹ�����飨��ȡtxtд�뵽�����ṹ���������У�
void load_drink(struct drink list1[], int* p1, struct drink list2[], int* p2);
//��ȡtxtд�뵽�����ṹ��������
int function_read(struct drink list[], FILE* fp);
//ʵ����Ʒ�Ľṹ������д������
void function_ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int choice, int i);
//ʵ��ԭ�ϵĽṹ������д������
void function_ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int choice, int i, int n);
//�����Ʒ�˵���������ʾ������䣩
void output_1(struct drink list[], int num);
//������ϲ˵���������ʾ������䣩
void output_2(struct drink list[], int num);
//���ṹ������������
drink_order* input_order(struct drink_order list3[], int num3);
//���������Ʒ 
best_drink* input_best_drink(struct drink_order list3[],int num3);
//���ر��
int Return_num();
//���������ۼ�¼�����ļ�
void save_order_file(drink_order* head);
//��ȡ����λ�� 
int password_num(); 
//ʵ���������벢��֤�ĺ���
bool Input_code();
//���ļ��ж�ȡϵͳ����
char* Read_password();
//�޸��ļ��е����루���޸ĳɹ��򷵻�Ϊbool�ͣ�
bool Change_password();
//ʵ��������ڵĺ���
void print_time(int* p5, int* p6);
//�޸Ķ��� 
void modify_order(struct drink_order list3[],int num3,bool flag,struct id idi[]);
//���ر��
int Return_defaultnum();
//��¼δ�㵥�ɹ�������
void save_default_order(struct drink_order list3[], int num3); 
//��¼�㵥�ɹ�������
void save_success_order(struct drink_order list3[], int num3); 
//����ӡ�˿�����������Ϣ
void print_order1(struct drink_order list3[], int num3);
//���ļ��ж�ȡ�նȡ��ܶȡ��¶ȡ����ȡ���������Ʒ��������
best_drink* read_best_drink();
//��ʱ���������
void input_time(int a[]);
//��ʱˢ�������Ʒ�ļ�
void refresh_best_drink(best_drink* head);
//���ļ���ȡ�ϴ��޸����ڲ�����
int *read_modify_time();
//���˿͵㵥���������Ʒ��
void save_best_drink(struct drink_order list3[],int num3,best_drink* head);
//���������Ʒ����Լ���������
int* return_best_num(best_drink* head,char ch);
//��ʾ�����Ʒ
void show_best_drink(best_drink* head,struct drink list2[]); 
//��ʾ��־
void show_log(); 


//�жϹ˿��Ƿ�ΪVIP
bool If_vip();
//��Ա�ļ�д��
void save_vip();
//���ļ��м��ػ�Ա��Ϣ������
vip* load_vip();
//��Ա��¼
int login_vip();
//��¼�������
int login_out();
//���ػ�Ա���
int Return_vipnum(); 
//����»�Ա��Ϣ
vip* add_vip();
//�鿴��Ա��Ϣ
bool observe_vip(char a);
//��ѯ������չ
bool obpro_vip(char a);
//�޸Ļ�Ա��Ϣ
void modify_vip();
//ɾ����Ա��Ϣ
void delete_vip();
//��Ա����
void user_vip();
//��Ʒ��Ϣ����
gift* load_gift();
//��Ʒ��Ϣ�洢
void save_gift();
//��Ա���ֶһ�����
void exchange_gift();
//�齱����
int roll(int i);
//�鿴��Ʒ�һ���¼
void history_gift();



//ʵ��ԭ�ϵĳ�ʼ���Լ�����
void data_refresh();
//����ԭ������Ĵ���
material creat();
//ʵ��ԭ�ϵ�����
material  material_delete(material head, int num1, struct id q[]);
//ʵ��ԭ�����ݵĴ���
void material_file(material head);
//ʵ��ʣ��ԭ�ϵ���ʾ���
void material_print(struct Using_Id bridge[]);
//����ԭ�������õ��ܺ���
void purchase();
//ʵ�ֹ���ĺ��� 
void buy_material();
//����ԭ�ϵ��������� 
Buy buy_creat();
//���������ڹ���ԭ�ϣ�
Buy buy_add(Buy head, struct buy_weights weights[]);
//������ԭ�������������¼���ļ���
void buy_material_file(Buy head);
//����������¼����Ҫ�����ԭ������������
int output_3();
//����ԭ�ϵ�ʱ��Ĵ��棻 
void print_time2(int a[]);
//�򿪹����¼���ļ���
void open_history_file();
//������
void sum_money();
//�������ļ�
void save_money_file(int our_money); 
//���ļ��е����ݴ���drinks[][]֮�У�
void read_material_al(int drinks[][6]); 
//ԭ�Ͼ����ߣ� 
void judge_material(int guard[],struct Using_Id bridge[]);
//�ж�����ԭ���뾯���ߵĲ�ࣻ
int judge_now_material(material head,int guard[],struct Using_Id bridge[]); 
//�����¡�������
void calculate_profit(Order_now h);
//����ԭ������ 
Order_now build_file_now();
//���ʣ�µ�ԭ�Ϸ�����
void material_fen(int drinks[][6]);
//�ȽϺ����� 
void compare(int i,int drink[][6],int ma[]);


//��������Ĵ��� 
struct order* build();
//�����·� 
int input_month();
//��������
int input_day();
//���������ĳ��ĳ�ն�����¼ 
void output_order_list(struct order* p, int x/*��*/, int y/*��*/);
//��������Ĵ��� 
struct order* history_build();
//������ж�����¼
int output_list(struct order* h);
//���������������Ƿ��з������ַ�
int check(struct order* top);
//���confirm�е�����Ϸ���
int check2(struct order* pt);
//������ż��Ϸ����ж� 
int judge_id(int len/*������*/, struct order* top/*����ͷָ��*/);
//����ȷ���Ƿ�ɾ��
int confirm(int x/*��Ҫɾ�������*/, struct order* pt/*��������ͷ��ָ��*/);
//�������֤��
int password();
//ɾ��ָ����ŵļ�¼ 
struct order* Delete(struct order* top, int x/*ָ�������*/);
//������д���ļ�
void write(struct order* pt/*��������ͷ��ָ��*/);
//�鿴ĳһ����Ʒ�ļ�¼���鿴ĳ��ʱ�����м�¼���鿴ĳһ������м�¼���鿴���м�¼  �˵����
char output_check_choice_function2();
//�����������ۼ�¼���� 
struct order* build_function2();
//�����¼ 
void output_list_function2(struct order*);
//�·ݺϷ����ж�
int judge_month_function2(int,int,int);
//���ںϷ����ж� 
int judge_day_function2(int,int,int,int); 
/*case 1:�鿴һ����Ʒ��ȫ�����ۼ�¼*/
//�����Ʒ����ѡ��˵� 
char output_drink_type_choice_function2();
//ɾ���������зǴ�����Ʒ�Ĳ���
struct order* delete_case_1_function2(char,struct order*);
/*case 2:�鿴һ��ʱ����������ۼ�¼*/
//���ʱ���ѡ��˵�
struct order* output_time_quantum_choice_function2(struct order*);
//ɾ���Ǵ�ʱ��εĶ�������
struct order* delete_case_2_function2(int,int,int,int,struct order*); 
/*case 3:�鿴ĳ����������ۼ�¼*/
//ѡ��ʱ��
struct order* select_time_function2(struct order *);
//ɾ���Ǵ��յĶ�������
struct order* delete_case_3_function2(int,int,struct order *);
/*��������*/
void playMusic();

int main()
{
diandan: 
	v_head = load_vip();
	g_head = load_gift();
	int choice;
	char a;     //a��ʾ��ʼ�ĵڶ���ѡ�� 
	playMusic();
	read_material_al(drinks);
	create_file();
	load_drink(list1, p1, list2, p2);
	b_head=read_best_drink();
	refresh_best_drink(b_head); 
	char ch;
	while(1)
	{
		system("cls");
		main_menu1();
		ch=getch(); 
		if (ch=='\r')
		{
			printf("   \t\t������ϵͳ��");
			for (int t=0;t<5;t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			function1();
		}
		else if (ch=='a')
		{
			printf("   \t\t���ڽ������Աϵͳ");
			for (int t=0;t<5;t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			goto guanliyuan;
		}
		else 
		{
			printf("  \t\t�������������⣬����������:"); 
			Sleep(1000);
		}
	}
guanliyuan:
	judge_material(guard,bridge);
	system("pause");
	while (1)
	{
		main_menu2();
		a = getch();
		if (a >= '0' && a <= '4')     //�����淶 
		{
			switch (a)
			{
			case '1':     	//���ܣ��鿴ԭ�Ͽ���Լ�����ԭ�ϡ� 
				printf("   \t\t������ϵͳ��");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				system("cls");
				function2();
				getchar();
				break;
			case '2':      
			//���ܣ��鿴������Ϣ���˿���Ϣ�������Ϣ���鿴���ж�����¼�Լ�ĳ��Ӫҵ����ӯ�����¼���޸�ɾ���˿���Ϣ
				printf("   \t\t�����ѯϵͳ��");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				function3();
				break;
			case '3':      //���ܣ�ɾ��������ʷ��¼��������Ա�ܲ����˲��֣���
				printf("   \t\t����ɾ��ϵͳ��");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				function4();
				getchar();
				break;
			case '4':       
				printf("   \t\t���������޸�ϵͳ��");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				function5();
				getchar();
				break;
			case '0':        //���ܣ��˳�ϵͳ��  
				printf("   \t\t�˳�ϵͳ��");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				exit(0);
			}
		}
		else if (a==27)
		{
			goto diandan;
		}
		else      //�������淶 
		{
			system("cls");
			printf("  \t\t���Ĳ��������Ϲ淶Ӵ��(�ޣգ�)��~�٣�\n");
			printf("  \t\t�뷵����һ���棺");
			system("pause");
			continue;
		}
	}
	return 0;
}

/*�˵�����*/
//ѡ��һ
void function1()
{
	vip* p;
	bool flag;
	flag=If_vip();       //�жϹ˿��Ƿ�ΪVIP
	if (flag == true) {
		int result = login_out();
		if (result == 0) {
			// �û�ȡ���������˵�
			return;
		}
		else {
			p = v_user;
		}
	}
	else 
	{ 
		system("cls");
		printf("\t\t �������Ƿ�Ҫ��Ϊ��Ա��\n");
		printf("\t\t     1����\n");
		printf("\t\t     2����\n");
		char asdf;
		while(1)
		{
			asdf=getch();
			if (asdf=='1')
			{
				p = add_vip();
				break;
			}
			else if(asdf=='2')
			{
				p=NULL;
				break;
			}
			else 
			{
				printf("\t\t  �������������⣬����������:\n");
			}
		}	
	}
	system("cls");
	material_fen(drinks);
	system("pause");
dianbeishu:		
	system("cls");
	int n;    //����˿͹˿�ÿ��������
	char b;   //b�ݴ�˿���ѡ���� 
	printf("\t\t*******************************************************************\n");
	printf("\t\t                   ��������Ҫ��ı���:                             \n");
	while(1)
	{
		b = getch();
		if (b>='1'&&b<='9')
		{
			break;
		}
		else
		{
			printf("\t\t���������⣬������������!");
			Sleep(2000); 
			system("cls");
			printf("\t\t*******************************************************************\n");
			printf("\t\t                   ��������Ҫ��ı���:                             \n");
		}
	}
	printf("\t\t                          %c��\n", b);
	printf("\t\t*******************************************************************\n");
	Sleep(500); 
	printf("\n\t\t\t�������Ƿ�ȷ����%c��",b);
	printf("\n\t\t\t      1���ǣ�");
	printf("\n\t\t\t      2����\n");
	char a;
	while(1)
	{
		a=getch();
		if(a=='1')
		{
			printf("\t\t\t\t       ��!\n");
			Sleep(1000);
			break; 
		} 
		else if (a=='2')
		{
			printf("\t\t\t\t        ��!\n");
			Sleep(1000);
			goto dianbeishu;
		}
		else
		{
			printf("\t\t  ���������������������룺\n"); 
		}
	}
	num3 = b - '0';
	material mat1, mat2; 		 //����material���͵�mat1��mat2
	mat1 = creat(); 		 //����ԭ�ϵ������� 
	for (int i = 0; i < num3; i++)
	{
		n = 0;
		ordering1(list1, num1, list3, p3, i ,idi);      //������
		ordering2(list2, num2, list3, p3, i, n, idi);   //������
		ordering3(list3, num3, i);                 //����Ⱥ��¶�	
	}
	print_order1(list3,num3);
	printf("\n\t\t�������Ƿ�ȷ���㵥");
	printf("\n\t\t      1���ǣ�");
	printf("\n\t\t      2����\n");
	printf("\t\t");
	while(1)
	{
		a=getch();
		if(a=='1')
		{
			printf("        ��!\n");
			break;
		} 
		else if (a=='2')
		{
			printf("        ��!\n");
			printf("\n\t\t����������Ҫ���еĲ�����\n"); 
			printf("\t\t     1�����µ㵥��\n");
			printf("\t\t     2���޸Ķ�����\n"); 
			printf("\t\t     0��ȡ��������\n"); 
			char ch;
			while(1)
			{
				ch=getch();
				if (ch=='1')
				{
					printf("\t\t���ڷ��ص㵥���棬���Ե�");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					goto dianbeishu;
				} 
				else if (ch=='2')
				{
					save_default_order(list3, num3);
					modify_order(list3,num3,flag,idi);
					break;
				}
				else if (ch=='0')
				{
					break;
				}
			}
			break;
		}
		else
		{
			printf("\t\t  ���������������������룺\n"); 
		}
	}
	mat2 = material_delete(mat1, num1, idi);
	material_file(mat2);  //ԭ�ϵĴ��� 
	if(p!=NULL)
	{
	p->money += print_order(list3, num3,flag);    //��ӡ�˿Ͷ���
	system("pause");
	save_vip();
    } 
    else print_order(list3, num3,flag);
    system("pause");
	drink_order* list4;
	list4 = input_order(list3, num3);
	save_success_order(list3, num3);    //���� 
	save_best_drink(list3,num3,b_head);
	save_order_file(list4);  //�˿Ͷ���������ն���
}

//���ܶ� 
void function2()
{
	system("cls");
	material_print(bridge);
	purchase();
	system("cls");
	material_print(bridge);
	system("pause");
}

//������ 
void function3()
{
chakan:
	system("cls");
	char ch,ch1,ch2;
	printf("\t\t\t\t����������鿴�Ĳ��֣�\n");
	printf("\t\t\t\t 1��������\n");
	printf("\t\t\t\t 2����棻\n");
	printf("\t\t\t\t 3���˿ͣ�\n");
	printf("\t\t\t\t 4����\n"); 
	printf("\t\t\t\t 5�������Ʒ��\n");
	printf("\t\t\t\t 6����־��\n");
	printf("\t\t\t\t 0���������˵�\n");
	while(1)
	{
		ch=getch();
		if (ch=='1')
		{
			printf("\t\t\t\t ���ڽ��붩��ϵͳ");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			struct order *head;
			char ch;
			char ch_2;  //case 1
			int month_0/*��ʼ��*/,day_0/*��ʼ��*/,month_1/*������*/,day_1/*������*/;  //case 2
			int month/*�·�*/,day/*����*/;  //case 3
			head=build_function2();
			ch=output_check_choice_function2();
			switch(ch){
				case '1':ch_2=output_drink_type_choice_function2();
						 head=delete_case_1_function2(ch_2,head);
						 break;
				case '2':month_0=judge_month_function2(20,0,0);  //��ʼ�·�����
						 day_0=judge_day_function2(20,month_0,0,0);  //��ʼ��������	  
						 month_1=judge_month_function2(21,month_0,day_0);  //�����·����� 
						 day_1=judge_day_function2(21,month_0,day_0,month_1);  //������������ 
						 head=delete_case_2_function2(month_0,day_0,month_1,day_1,head);
						 break;
				case '3':month=judge_month_function2(3,0,0);  //�·�����
						 day=judge_day_function2(3,month,0,0);  //�������� 
						 head=delete_case_3_function2(month,day,head);
						 break;
				case '0':goto chakan;
			}
			system("cls");
			if(ch=='1'){
				switch(ch_2){
					case '1':printf("\t\t  �����ȫ�����ۼ�¼\n\n");break;
					case '2':printf("\t\t  �̲��ȫ�����ۼ�¼\n\n");break;
					case '3':printf("\t\t  ���̵�ȫ�����ۼ�¼\n\n");break;
					case '4':printf("\t\t  ���̵�ȫ�����ۼ�¼\n\n");break;
					case '5':printf("\t\t  ���ȵ�ȫ�����ۼ�¼\n\n");break;
					case '6':printf("\t\t  Ҭ�̵�ȫ�����ۼ�¼\n\n");break;
					case '7':printf("\t\t  ţ�̵�ȫ�����ۼ�¼\n\n");break;
					case '8':printf("\t\t  �ɿɵ�ȫ�����ۼ�¼\n\n");break;
					case '9':printf("\t\t������ȫ�����ۼ�¼\n\n");
				}
			}else if(ch=='2'){
				printf("\t      %d��%d����%d��%d�յ����ۼ�¼\n\n",month_0,day_0,month_1,day_1); 
			}else if(ch=='3'){
				printf("\t\t  %d��%d�յ����ۼ�¼\n\n",month,day);
			}else{
				printf("\t\t    ȫ�����ۼ�¼\n\n");
			}
			if(head!=NULL){
				output_list_function2(head);
			}else{
				printf("\t\t    û�����ۼ�¼\n");
				system("pause");
			}
			goto chakan;
		} 
		else if (ch=='2')
		{
			printf("\t\t\t\t ���ڽ�����ϵͳ");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			printf("\t\t\t\t ��ѡ����Ҫ�鿴�Ĳ��֣�\n");
			printf("\t\t\t\t     1�������Ϣ��\n");
			printf("\t\t\t\t     2��ԭ�Ϲ����¼��\n");
			printf("\t\t\t\t     0��������һ���棻\n"); 
			char c;
			while(1)
			{
				c=getch();
				if (c=='1')
				{
					printf("\t\t\t\t      ���Ե�");
					for (int k=0;k<5;k++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					material_print(bridge);
					system("pause");
					goto chakan;
				}
				else if (c=='2')
				{
					printf("\t\t\t\t      ���Ե�");
					for (int k=0;k<5;k++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					open_history_file();
					system("pause"); 
					goto chakan;
				}
				else if (c=='0')
				{
					printf("\t\t\t\t ������һ����");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					goto chakan;
				}
			}
			goto chakan; 
		}
		else if (ch=='3')
		{
			printf("\t\t\t\t ���ڽ���˿�ϵͳ");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			} 
			system("cls");
			printf("\t\t\t\t����������Ҫ���еĲ�����\n");
			printf("\t\t\t\t 1����ѯ��Ա��Ϣ��\n");
			printf("\t\t\t\t 2���޸Ļ�Ա��Ϣ��\n");
			printf("\t\t\t\t 3��ɾ����Ա��Ϣ��\n");
			printf("\t\t\t\t 4����Ʒ�һ���ʷ��¼��\n");
			printf("\t\t\t\t 0��������һ����\n");
			ch1 = getch();
			while(1)
			{ 
				if (ch1=='1')
				{
					printf("\t\t\t\t�����ѯ��Աϵͳ");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					printf("\t\t\t\t 1���鿴���л�Ա��Ϣ��\n");
					printf("\t\t\t\t 2���鿴�ض���Ա��Ϣ��\n");
					while(1)
					{
						ch2 = getch();
						if (ch2 == '1' || ch2 == '2')
						{
							bool t=observe_vip(ch2);
							system("pause");
							goto chakan;
						}
						else
						{
							printf("\t\t\t\t����������������������:\n");
						}
					}
					system("pause");
					system("cls");
					goto chakan;
				}
				else if (ch1=='2')
				{
					printf("\t\t\t\t�����޸�ϵͳ");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					modify_vip();
					system("pause");
					goto chakan;
				}
				else if(ch1=='3')
				{
					printf("\t\t\t\t ����ɾ��ϵͳ");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					delete_vip();
					system("pause");
					goto chakan;
				}
				else if (ch1=='4')
				{
					printf("\t\t\t\t ����������ʷ��ѯϵͳ");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					history_gift();
					system("pause");
					goto chakan;
				}
				else if (ch1=='0')
				{
					printf("\t\t\t\t ������һ����");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					goto chakan;
				}
				else 
				{
					printf("\t\t\t\t ���������������������룺\n");
				}
			}
		}
		else if (ch=='4')
		{
			printf("\t\t\t\t ���ڽ������ϵͳ"); 
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			} 
			if (password() == 0)
			{
				return;
			}
			system("cls");
			system("color 9E");
			sum_money();
			Order_now t1;
			t1=build_file_now();
			calculate_profit(t1);
			getchar();
			goto chakan;
		}
		else if (ch=='5')
		{
			printf("\t\t\t\t ���ڽ��������Ʒϵͳ");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			}
			int num[2]; 
			int* p;
			system("cls");
			printf("\t\t\t\t��������Ҫ��ѯ�����Ʒ�ķ�ʽ��\n");
			printf("\t\t\t\t     1���ܶȣ�\n");
			printf("\t\t\t\t     2���¶ȣ�\n");
			printf("\t\t\t\t     3�����ȣ�\n");
			printf("\t\t\t\t     4����ȣ�\n");
			printf("\t\t\t\t     0��������һ���棻\n");
			char a;
			while(1)
			{
				a=getch();
				if (a=='1')
				{
					printf("\t\t\t\t ����Ϊ����ʾ�ܶ������Ʒ�����Ե�");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t ���������ƷΪ��%s\n",list1[num[1]].name);
					printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='2')
				{
					printf("\t\t\t\t   ����Ϊ����ʾ�¶������Ʒ�����Ե�");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t ���������ƷΪ��%s\n",list1[num[1]].name);
					printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='3')
				{
					printf("\t\t\t\t   ����Ϊ����ʾ���������Ʒ�����Ե�");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t ���������ƷΪ��%s\n",list1[num[1]].name);
					printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='4')
				{
					printf("\t\t\t\t   ����Ϊ����ʾ��������Ʒ�����Ե�");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t ���������ƷΪ��%s \n",list1[num[1]-1].name);
					printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='0')
				{
					printf("\t\t\t\t ������һ����");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					goto chakan;
				}
			}
			goto chakan;
		}
		else if (ch=='6')
		{
			printf("\t\t\t\t ���ڽ�����־ϵͳ");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			}
			if (password() == 0)
			{
				goto chakan;
			}
			show_log();
			system("pause");
			goto chakan;
		} 
		else if (ch=='0')
		{
			break;
		}
		else
		{
			printf("\t\t\t\t ����������������������:\n");
		}
	}
}

//������ 
void function4()
{
	system("cls");
	if (password() == 0)
	{
		return;
	}
	else
	{
		struct order* head;
		int len, x, flag;
		head = history_build();
		len = output_list(head);
		x = judge_id(len, head);
		flag = confirm(x, head);
		if (flag == 1) {  //����ɾ������ 
			head = Delete(head, x);
			write(head);
			system("cls");
			printf("\n      ɾ���ɹ�\n");
			system("pause");
			Sleep(1000);
			system("cls");
			output_list(head);
			Sleep(2000);
		}
		else {
			system("cls");
			printf("\n      ��ֹɾ��\n");
		}
	}
	return;
}

//������ 
void function5()
{
	system("cls");
	system("color 9E");
	if (password() == 0)
	{
		return;
	}
	while (Change_password());   //������ʾ�����޸ĳɹ�
	system("pause");
}


/*���ܲ���*/
//��ӭ���� 
void main_menu1()
{
	int time[5];
	int n;    //����ѡ�� 
	system("cls");
	system("color 9E");
	printf("\t\t*******************************************************************\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t**                   ����              ����                      **\n");
	printf("\t\t**                            ����                               **\n");
	printf("\t\t**             ����  ��ӭ������תתת��Ʒ��!   ����              **\n");
	printf("\t\t**            ����                              ����             **\n");
	printf("\t\t**              ����welcome to Dicky Twister! ����               **\n");
	printf("\t\t**                  ����                 ����                    **\n");
	printf("\t\t**                       ����      ����                          **\n");
	printf("\t\t**                            ����                               **\n");
	printf("\t\t**                                                               **\n");
	printf("\t\t**                      �������ڣ�");
	print_time2(time);
	printf("%d��%d��",time[0],time[1]);
	printf("                      \t **\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t*******************************************************************\n");
}

void main_menu2()
{
	system("cls");
	system("color 9E");
	//����ѡ��Ĳ��� 
	printf("\t\t*******************************************************************\n");
	printf("\t\t**                  ��ѡ����Ҫ���еĲ���:                        **\n");
	printf("\t\t**                    1������ԭ�ϣ�                              **\n");
	//���ܣ��鿴ԭ�Ͽ�棨����ԭ�ϣ��� 
	printf("\t\t**                    2����ѯ���޸���Ϣ��                        **\n");
	//���ܣ��鿴������Ϣ���˿���Ϣ���޸�ɾ���˿���Ϣ 
	printf("\t\t**                    3��ɾ����¼��                              **\n");
	//���ܣ�ɾ��������ʷ��¼��������Ա�ܲ����˲��֣��� 
	printf("\t\t**                    4���޸����룻                              **\n");
	//���ܣ��޸�ϵͳ���롣 
	printf("\t\t**                    0���˳�ϵͳ��                              **\n");
	//���ܣ��˳�ϵͳ��  
	printf("\t\t*******************************************************************\n");
}

//ʵ�ֵ����ϵĺ������������ϵĽṹ��д�����ݣ� 
void ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int i, struct id idi[])
{
	int choice = 0;
	char a;
	system("cls");
	system("color 9E");
	printf("\t\t��ѡ����Ʒ��\n");
	output_1(list1, num1);
	while (1)
	{
		a = getch();
		choice = a - '0';
		if (choice > 0 && choice <= num1)
		{
			idi[i].id1=choice;
			function_ordering1(list1, num1, list3, p3, choice, i);
			printf("\t\t**\t\t%s\t\t%d\t\t\t\t **\n", list1[choice - 1].name, list1[choice - 1].price);
			system("pause");
			break;
		}
		else
			printf("\t\t��������������������룺\n");
	}
}

//ʵ�ֵ����ϵĺ������������ϵĽṹ��д�����ݣ� 
void ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int i, int n, struct id idi[])
{
	int choice = 0;    //nΪ��������
	char a;    //a�ݴ�����ѡ�� 
	system("cls");
	system("color 9E");
	printf("\t\t��ѡ�����ϣ�\n");
	output_2(list2, num2);
	while (1)
	{
		a = getch();
		choice = a - '0';
		if (choice >= 0 && choice <= num2)
		{
			if(n==0)
			{
				idi[i].id2=choice;
			}
			if(n==1)
			{
				idi[i].id3=choice;
			}
			if (choice != 0 && n < 2)
			{
				function_ordering2(list2, num2, list3, p3, choice, i, n);
				n++;
				printf("\t\t**\t%d\t%s\t\t%d\t\t\t\t **\n", n, list2[choice - 1].name, list2[choice - 1].price);
			}
			else if (n == 2)
				return;
			else
				break;
		}
		else
			printf("\t\t��������������������룺\n");
	}
}

//ʵ�ֵ��¶Ⱥ���ȵĺ����������¶Ⱥ���ȵĽṹ��д�����ݣ�
void ordering3(struct drink_order list3[], int num3, int i)
{
	system("cls");
	system("color 9E");
	char a;     //a��ʾ�˿͵�ѡ��
	printf("\t\t*******************************************************************\n");
	printf("\t\t��ѡ��������Ʒ����ȣ�\n");
	printf("\t\t        1������\n");
	printf("\t\t        2������\n");
	printf("\t\t        3������\n");
	printf("\t\t����ѡ��\n");
	while (1)
	{
		a = getch();
		if (a - '0' == 1)
		{
			printf("\t\t        1������\n");
			list3[i].sweetness = 1;
			break;
		}
		else if (a - '0' == 2)
		{
			printf("\t\t        2������\n");
			list3[i].sweetness = 2;
			break;
		}
		else if (a - '0' == 3)
		{
			printf("\t\t        3������\n");
			list3[i].sweetness = 3;
			break;
		}
		else
			printf("\t\t�������벻���Ϲ淶������������:\n");
	}
	system("pause");
	printf("\t\t��ѡ��������Ʒ���¶ȣ�\n");
	printf("\t\t        1���ӱ�\n");
	printf("\t\t        2������\n");
	printf("\t\t        3����\n");
	printf("\t\t����ѡ��\n");
	while (1)
	{
		a = getch();
		if (a - '0' == 1)
		{
			printf("\t\t        1���ӱ�\n");
			list3[i].temperature = 1;
			break;
		}
		else if (a - '0' == 2)
		{
			printf("\t\t        2������\n");
			list3[i].temperature = 2;
			break;
		}
		else if (a - '0' == 3)
		{
			printf("\t\t        3����\n");
			list3[i].temperature = 3;
			break;
		}
		else
			printf("\t\t�������벻���Ϲ淶������������\n");
	}
	system("pause");
}

//��ӡ�˿�����������Ϣ
int print_order(struct drink_order list3[], int num3,bool flag)
{
	system("cls");
	system("color 9E");
	int sum = 0;
	printf("\t\t******************************************************************\n");
	printf("\t\t**���\t����\t�¶�\t���\t����\t\t�۸�\t\t**\n");
	printf("\t\t******************************************************************\n");
	for (int i = 0; i < num3; i++)
	{
		printf("\t\t** %d\t%s\t", i + 1, list3[i].drink_name);
		if (list3[i].temperature == 1)
			printf("�ӱ�\t");
		else if (list3[i].temperature == 2)
			printf("����\t");
		else if (list3[i].temperature == 3)
			printf("��  \t");
		if (list3[i].sweetness == 1)
			printf("����\t");
		else if (list3[i].sweetness == 2)
			printf("����\t");
		else if (list3[i].sweetness == 3)
			printf("����\t");
		printf("%s\t%s", list3[i].ingredient_name[0], list3[i].ingredient_name[1]);
		if (flag)
			list3[i].money -= 2;
		printf("\t %d         \t**\n", list3[i].money);
		sum += list3[i].money;
	}
	printf("\t\t******************************************************************\n");
	printf("\t\t�ܼ۸�Ϊ��%d\n", sum);
	return sum;
}


//�������֤�� 
int password()
{
	system("cls");
	system("color 9E");
	printf("\t\t*******************************************************************\n");
	printf("\t\t**     ��������������֤��ݣ�                                    **\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t                ");
	bool flag = Input_code();      //��������Ƿ���� 
	int n = 0;    //��¼��������������
	while (!flag && n < 3)      //������󵫴�������������� 
	{
		n++;
		system("cls");
		system("color 4F");
		printf("\t\t*******************************************************************\n");
		printf("\t\t                           �������                              \n");
		printf("\t\t                          ����������:                              \n");
		printf("\t\t                     ");
		flag = Input_code();
	}
	if (n == 3)
	{
		system("cls");
		system("color 4F");
		printf("\t\t                         �������ǿ���˳�");
		return 0;
	}
	system("cls");
	system("color 9E"); 
	return 1;
}

//ʵ��ɾ������ 
struct order* Delete(struct order* top, int x/*ָ�������*/)
{
	FILE *fp;
	fp=fopen("beverage sales list.txt","a");
	if (fp==NULL)
	{
		printf("Can't open this file!"); 
	}
	int num=Return_defaultnum()+1,j=0;
	int time[5];
	print_time2(time);
	struct order sentry/*�ڱ�*/, * h = top, * h0/*h��ǰ��ָ��*/;
	sentry.next = top;
	while (h != NULL) {  //��ʷ��¼����ı���  
		if (x == h->id) {  //ɾ������ 
			if (h == top)  //ɾ������ͷ
			{ 
				fprintf(fp, "%d %s %d %d %d %d %s ", num, h->name, h->price,h->cost,h->month,h->day,h->order_num);
				fprintf(fp,"(��ɾ��)\n"); 
				h = h->next;
				free(sentry.next);
				sentry.next = h;
			}
			else {  //ɾ�������м䲿�� 
				fprintf(fp, "%d %s %d %d %d %d %s ", num, h->name, h->price,h->cost,h->month,h->day,h->order_num);
				fprintf(fp,"(��ɾ��)\n"); 
				h = h->next;
				free(h0->next);
				h0->next = h;
			}
			break;  //ɾ����������ֹѭ�� 
		}
		h0 = h;
		h = h->next;
	}
	return sentry.next;
}

/*��������*/

//�����������������txt�ļ�
void create_file()
{
	FILE* fp = fopen("����.txt", "a");
	if (fp == NULL)
		return;
	fclose(fp);
	fp = fopen("ԭ��.txt", "a");
	if (fp == NULL)
		return;
	fclose(fp);
	fp = fopen("vip.txt", "a");
	if (fp == NULL)
		return;
	fclose(fp);
	fp = fopen("gift.txt", "a");
	if (fp == NULL)
		return;
	fclose(fp);
	fp = fopen("history_gift.txt", "a");
	if (fp == NULL)
		return;
	fclose(fp);
}

//������Ʒ��������Ϣ���ṹ�����飨��ȡtxtд�뵽�����ṹ���������У�
void load_drink(struct drink list1[], int* p1, struct drink list2[], int* p2)
{
	FILE* fp;
	fp = fopen("����.txt", "r");
	*p1 = function_read(list1, fp);
	fp = fopen("ԭ��.txt", "r");
	*p2 = function_read(list2, fp);
	fclose(fp);
}

//��ȡtxtд�뵽�����ṹ��������
int function_read(struct drink list[], FILE* fp)
{
	int line = 0, t;
	char temp, ark[30];
	int i;
	if (fp == NULL)
	{
		printf("���ܴ�\n");
		exit(1);
	}
	while (!feof(fp)) //������ϵ��ļ��Ƿ����������ļ��������򷵻ط�0ֵ�����򷵻�0
	{
		temp = fgetc(fp);
		if (temp == '\n')
			line++;
	}
	rewind(fp);
	for (i = 0; i < line; i++)
	{
		fgets(ark, 30, fp);
		sscanf(ark, "%s %s %d", &t, list[i].name, &list[i].price);
	}
	fclose(fp);
	return line;
}

//ʵ�ֵ�͵Ľṹ������д������
void function_ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int choice, int i)
{
	strcpy(list3[i].drink_name, list1[choice - 1].name);
	list3[i].money = list1[choice - 1].price;
}

//ʵ��ԭ�ϵĽṹ������д������
void function_ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int choice, int i, int n)
{
	strcpy(list3[i].ingredient_name[n], list2[choice - 1].name);
	list3[i].money += list2[choice - 1].price;
}

//�����Ʒ�˵���������ʾ��䣩
void output_1(struct drink list1[], int num)
{
	printf("\t\t*******************************************************************\n");
	printf("\t\t**\t���\t����\t\t�۸�\t\t\t\t **\n");
	printf("\t\t*******************************************************************\n");
	for (int i = 0; i < num; i++)
	{
		printf("\t\t**\t%d\t%s\t\t%d\t\t\t\t **\n", i + 1, list1[i].name, list1[i].price);
	}
	printf("\t\t*******************************************************************\n");
	printf("\t\t��������ţ�\n");
}

//������ϲ˵���������ʾ������䣩
void output_2(struct drink list2[], int num)
{
	printf("\t\t*******************************************************************\n");
	printf("\t\t**\t���\t����\t�۸�\t\t\t\t\t **\n");
	printf("\t\t*******************************************************************\n");
	for (int i = 0; i < num; i++)
	{
		printf("\t\t**\t%d\t%s\t\t%d\t\t\t\t **\n", i + 1, list2[i].name, list2[i].price);
	}
	printf("\t\t**\t0\t����\t\t\t\t\t\t **\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t��������ţ�\n");
}

//���ṹ������������
drink_order* input_order(struct drink_order list3[], int num3)
{
	drink_order* p0 = NULL;   //p0Ϊ�ڱ� 
	drink_order* p;          //����β 
	drink_order* head;        //ͷ���
	head = (drink_order*)malloc(sizeof(drink_order));
	p0 = head;
	p0->next = NULL;
	int i = 0;
	do
	{
		p = (drink_order*)malloc(sizeof(drink_order));
		strcpy(p->drink_name, list3[i].drink_name);
		strcpy(p->ingredient_name[0], list3[i].ingredient_name[0]);
		strcpy(p->ingredient_name[1], list3[i].ingredient_name[1]);
		p->money = list3[i].money;
		i++;
		p0->next = p;
		p0 = p;
		p0->next = NULL;
	} while (i < num3);
	return head;
}

//���ر��
int Return_num()
{
	int num=1,temp1,temp2,temp3,temp4;
	char temp[10],temp5[10];
	FILE* sp;
	sp = fopen("history order record.txt", "r");
	if (sp == NULL)
	{
		printf("Can't open this file!");
		exit(0);
	}
	while (fscanf(sp, "%d %s %d %d %d %d %s", &num, temp, &temp1, &temp2, &temp3, &temp4, temp5) != EOF);
	fclose(sp);
	return num;
} 

//���������ۼ�¼�����ļ�
void save_order_file(drink_order* head)
{
	FILE* fp,*so;
	int num=Return_num()+1;
	fp = fopen("history order record.txt", "a");
	so = fopen("money.txt","r");
	if (fp == NULL)
	{
		printf("Can't open this file!");
		return ;
	}
	if (so == NULL)
	{
		printf("Can't open this file!");
		return ;
	}
	int time[5],j,our_money=0;
	char str1[63];
	fgets(str1,63,so);
	sscanf(str1,"%d",&our_money);
	drink_order* p = head->next,* p0 = NULL;
	print_time2(time);
	while (p != NULL)
	{	
		j=0;
		for (;j<9;j++)
		{
			if (strcmp(list1[j].name,p->drink_name)==0)
			{
				break;
			}
		}
		fprintf(fp, "%d %s %d %d %d %d %02d%02d%02d%02d%02d\n", num, p->drink_name, p->money,cost[j],time[0],time[1],time[0],time[1],time[2],time[3],time[4]);
		our_money=our_money+p->money-cost[j];
		num++;
		p0 = p;
		p = p->next;
	}
	save_money_file(our_money);
	fclose(so);
	fclose(fp);
}

//ʵ���������벢��֤�ĺ��� 
bool Input_code()
{
	printf("\t\t");
	char ch[20], t = 0;    //tΪ������
	int i;  
	for (i = 0; i < 20; i++)
	{
		ch[i] = getch();
		if (ch[i] == '\b')
		{
			printf("\b \b");
			i = i - 2;
		}
		else if (ch[i]=='\r')
		{
			break;
		}
		else
		{
			printf("*");
		}
	}
	ch[i] = '\0';
	char* p;
	int f=password_num();
	char password[20];
	p = Read_password();
	for (i = 0; i < f; i++)
	{
		password[i] = *(p + i);
	}
	i++;
	password[i] = '\0';
	if (strcmp(ch, password) == 0)
		return true;
	else
		return false;
}

//��ȡ����λ�� 
int password_num()
{
	FILE* fp=fopen("password.txt","r");
	if (fp==NULL)
	{
		printf("Can't find this file!");
	}
	char code[20];
	int i=0;
	while(fscanf(fp,"%c",&code[i])!=EOF)
	{
		i++;
	}
	i++;
	return i;
} 

//���ļ��ж�ȡϵͳ����
char* Read_password()
{
	FILE* fp=fopen("password.txt","r");
	if (fp==NULL)
	{
		printf("Can't find this file!");
	}
	char code[20];
	int i=0;
	while(fscanf(fp,"%c",&code[i])!=EOF)
	{
		i++;
	}
	i++;
	code[i]='\0';
	fclose(fp);
	return code;
}

//�޸��ļ��е�����
bool Change_password()
{
	xiugaimima:
	system("cls");
	system("color 9E");
	printf("\t\t*******************************************************************\n"); 	
	printf("\t\t �������޸ĺ�����룺\n"); 	
	printf("\t\t   "); 	
	char newcode[20],temp[20];
	int i;
	for (i=0;i<20;i++)
	{
		scanf("%c",&newcode[i]);
		if (newcode[i]=='\n')
		{
			break;
		} 
	} 
	printf("\t\t*******************************************************************\n"); 	
	newcode[i]='\0';
	Sleep(1000); 
	printf("\t\t�����ٴ���������ȷ�ϣ�\n");
	printf("\t\t   "); 
	for (i=0;i<20;i++)
	{
		scanf("%c",&temp[i]);
		if (temp[i]=='\n')
		{
			break;
		} 
	} 
	temp[i]='\0';
	if (strcmp(temp,newcode)!=0)
	{
		goto xiugaimima;
	}
	FILE* fp= fopen("password.txt", "w"); 	
	if (fp == NULL) 	
	{ 		
		printf("Can't open file!\n"); 		
		return true; //true��ʾ�����޸�ʧ�� 	
	}
	rewind(fp);
	fprintf(fp, "%s", newcode); 	
	fclose(fp); 	
	system("cls");
	printf("\t\t*******************************************************************\n"); 		
	printf("\t\t��ϲ��,�����޸ĳɹ�!\n"); 	
	printf("\t\t������Ϊ��\n"); 	
	printf("\t\t %s\n", newcode);
	printf("\t\t*******************************************************************\n"); 	
	return false; //false��ʾ�����޸ĳɹ�
}


//�޸Ķ��� 
void modify_order(struct drink_order list3[],int num3,bool flag,struct id idi[])
{
chongxinxuanze:	
	system("cls");
	print_order1(list3,num3); 
	int n=0,temp;
	char a,b,c,num='0';
	printf("\n\t\t\t��������Ҫ�޸ĵı�����\n\t\t\t\t");
	while(1)
	{
		num=getch();
		if (num<='0'||num>num3+'0')
		{
			printf("\n\t\t\t �������������⣬����������:\n\t\t\t\t");
		}
		else
		{
			printf(" %c��\n",num);
			break;
		}
	}
	printf("\t\t\t �Ƿ�ȷ���޸�%c��\n",num);
	printf("\t\t\t     1���ǣ�\n");
	printf("\t\t\t     2����\n");
	while(1)
	{
		c=getch();
		if (c=='1')
		{
			printf("\t\t\t       �ǣ�\n");
			Sleep(1000);
			break; 
		}
		else if (c=='2')
		{
			printf("\t\t\t       ��\n");
			Sleep(1000);
			goto  chongxinxuanze;
		}
	} 
	temp=num-'0';
	for (int j=0;j<temp;j++)
	{
		system("cls");
		print_order1(list3,num3);
		n=0;
xiugaidingdan:	
	printf("\n\t\t\t����������Ҫ�޸ĵĶ������:\n");
		while(1)
		{
			a=getch();
			if (a>='1'&&a<=num3+'0')
			{
				printf("\t\t\tȷ���޸ĵ�%c�Ŷ�����\n",a);
				printf("\t\t\t   1��ȷ����\n");
				printf("\t\t\t   2������ѡ��\n");
				while(1)
				{
					b=getch();
					if (b=='1')
					{
						memset(list3[a-'1'].drink_name,0,sizeof(list3[a-'i'].drink_name));
						memset(list3[a-'1'].ingredient_name[0],0,sizeof(list3[a-'1'].ingredient_name[0]));
						memset(list3[a-'1'].ingredient_name[1],0,sizeof(list3[a-'1'].ingredient_name[1]));
						list3[a-'1'].money=0;
						ordering1(list1,num1,list3,p3,a-'1',idi);
						ordering2(list2,num2,list3,p3,a-'1',n,idi);
						ordering3(list3,num3,a-'1');
						break;
					}
					else if (b=='2')
					{
						goto xiugaidingdan;
					}
					else
					{
						printf("\t\t\t�������벻�淶�����������룺\n");
					}
				}
				break; 
			}
			else
			{
				printf("\t\t\t�������벻�淶,����������:\n");
			}
		}
	}
}

//���ر��
int Return_defaultnum()
{
	int num=0,temp1,temp2,temp3,temp4;
	char temp[10],temp5[10],temp6[10];
	FILE* sp;
	sp = fopen("beverage sales list.txt", "r");
	if (sp == NULL)
	{
		printf("Can't open this file!");
		exit(0);
	}
	while (fscanf(sp, "%d %s %d %d %d %d %s %s", &num, temp, &temp1, &temp2, &temp3, &temp4, temp5, temp6) != EOF);
	fclose(sp);
	return num;
} 

//��¼δ�㵥�ɹ�������
void save_default_order(struct drink_order list3[], int num3)
{
	FILE *fp;
	fp=fopen("beverage sales list.txt","a");
	if (fp==NULL)
	{
		printf("Can't open this file!"); 
		return ;
	}
	int num=Return_defaultnum()+1,j=0;
	int time[5];
	print_time2(time);
	for (int i=0;i<num3;i++)
	{
		j=0;
		for (;j<9;j++)
		{
			if (strcmp(list1[j].name,list3[i].drink_name)==0)
			{
				break;
			}
		}
		fprintf(fp, "%d %s %d %d %d %d %02d%02d%02d%02d%02d ", num, list3[i].drink_name, list3[i].money-2,cost[j],time[0],time[1],time[0],time[1],time[2],time[3],time[4]);
		fprintf(fp,"(δ���)\n"); 
		num++;
	}
	fclose(fp);
}

//��¼�㵥�ɹ�������
void save_success_order(struct drink_order list3[], int num3)
{
	FILE *fp;
	fp=fopen("beverage sales list.txt","a");
	if (fp==NULL)
	{
		printf("Can't open this file!"); 
		return ;
	}
	int num=Return_defaultnum()+1,j=0;
	int time[5];
	print_time2(time);
	for (int i=0;i<num3;i++)
	{
		j=0;
		for (;j<9;j++)
		{
			if (strcmp(list1[j].name,list3[i].drink_name)==0)
			{
				break;
			}
		}
		fprintf(fp, "%d %s %d %d %d %d %02d%02d%02d%02d%02d ", num, list3[i].drink_name, list3[i].money,cost[j],time[0],time[1],time[0],time[1],time[2],time[3],time[4]);
		fprintf(fp,"(���)\n"); 
		num++;
	}
	fclose(fp);
}

//����ӡ�˿�����������Ϣ
void print_order1(struct drink_order list3[], int num3)
{
	system("cls");
	printf("\t\t******************************************************************\n");
	printf("\t\t**���\t����\t�¶�\t���\t����\t\t�۸�\t\t**\n");
	printf("\t\t******************************************************************\n");
	for (int i = 0; i < num3; i++)
	{
		printf("\t\t** %d\t%s\t", i + 1, list3[i].drink_name);
		if (list3[i].temperature == 1)
			printf("�ӱ�\t");
		else if (list3[i].temperature == 2)
			printf("����\t");
		else if (list3[i].temperature == 3)
			printf("��  \t");
		if (list3[i].sweetness == 1)
			printf("����\t");
		else if (list3[i].sweetness == 2)
			printf("����\t");
		else if (list3[i].sweetness == 3)
			printf("����\t");
		printf("%s\t%s", list3[i].ingredient_name[0], list3[i].ingredient_name[1]);
		printf("\t %d         \t**\n", list3[i].money-2);
	}
	printf("\t\t******************************************************************\n");
} 


//���ļ��ж�ȡ�նȡ��ܶȡ��¶ȡ����ȡ���������Ʒ��������
best_drink* read_best_drink()
{
	FILE* fp;
	fp=fopen("best drink.txt","r");
	if (NULL==fp)
	{
		printf("can't find this file!");
		exit(0) ;
	}
	int temp1, temp2, temp3;
	fscanf(fp,"%d %d %d",&temp1,&temp2,&temp3); 
	best_drink* p0=NULL;  //�ڱ��ڵ�
	best_drink* p;       //����β
	best_drink* head;    //ͷ�ڵ�
	head=(best_drink*)malloc(sizeof(best_drink));
	p0=head;
	p0->next=NULL;
	int temp4,temp5;
	while(fscanf(fp,"%d %d %d %d %d",&temp1,&temp2,&temp3,&temp4,&temp5)!=EOF)
	{
		p=(best_drink*)malloc(sizeof(best_drink));
		p->week=temp2;
		p->month=temp3;
		p->quater=temp4;
		p->year=temp5;
		p0->next=p;
		p0=p;
		p0->next=NULL; 
	}
	fclose(fp);
	return head;
}

//��ʱ���������
void input_time(int a[])
{
	struct tm* local;
	time_t t;
	t=time(NULL);
	local=localtime(&t);
	a[0]=local->tm_year+1900;
	a[1]=local->tm_mon+1;
	a[2]=local->tm_wday;
	a[3]=local->tm_mday;
}

//��ʱˢ�������Ʒ�ļ�
void refresh_best_drink(best_drink* head)
{
	int time[4];
	int temp1, temp2, temp3;
	input_time(time);
	FILE* fp;
	int *ti;
	ti=read_modify_time();
	temp1=*ti;
	temp2=*(ti+1);
	temp3=*(ti+2); 
	best_drink* p=head->next,*p0=NULL;
	fp=fopen("best drink.txt","w");
	if (NULL==fp)
	{
		printf("can't find this file!");
		return ;
	} 
	if(time[2]==1&&time[3]!=temp3)
	{
		for (int i=0;i<9;i++)
		{
			p->week=0;
			p0=p;
			p=p->next; 
		}
		fprintf(fp,"%d %d %d\n",time[0],time[1],time[3]);
	}
	p=head->next,p0=NULL;
	if (time[3]==1&&time[1]!=temp2)
	{
		for (int i=0;i<9;i++)
		{
			p->month=0;
			p0=p;
			p=p->next;
		} 
		fprintf(fp,"%d %d %d\n",time[0],time[1],time[3]);
	} 
	p=head->next,p0=NULL;
	if (time[3]==1&&(time[1]==1||time[1]==4||time[1]==7||time[1]==10)&&time[1]!=temp2)
	{
		for (int i=0;i<9;i++)
		{
			p->quater=0;
			p0=p;
			p=p->next; 
		} 
		fprintf(fp,"%d %d %d\n",time[0],time[1],time[3]);
	} 
	p=head->next,p0=NULL;
	if (time[3]==1&&time[1]==1&&time[0]!=temp1) 
	{
		for (int i=0;i<9;i++)
		{
			p->year=0;
			p0=p;
			p=p->next; 
		} 
		fprintf(fp,"%d %d %d\n",time[0],time[1],time[3]);
	}
	else
	{
		fprintf(fp,"%d %d %d\n",temp1,temp2,temp3);
	}
	p=head->next,p0=NULL;
	int j=0;
	while(p)
	{
		if (p->next)
		{
			j++;
			fprintf(fp,"%d %d %d %d %d\n",j,p->week,p->month,p->quater,p->year);
			p0=p;
			p=p->next;
		}
		else
		{
			j++;
			fprintf(fp,"%d %d %d %d %d",j,p->week,p->month,p->quater,p->year); 
			p0=p;
			p=p->next;
		} 
	}
	fclose(fp); 
}

//���ļ���ȡ�ϴ��޸����ڲ�����
int *read_modify_time()
{
	FILE* fp;
	if ((fp = fopen("best drink.txt", "r")) == NULL)
		printf("Can't open file!\n");
	int time[3];
	int i = 0;
	fp = fopen("best drink.txt", "r");
	fscanf(fp,"%d %d %d",&time[0],&time[1],&time[2]);
	fclose(fp);
	return time;
} 

//���˿͵㵥���������Ʒ��
void save_best_drink(struct drink_order list3[],int num3,best_drink* head)
{
	int temp1, temp2, temp3;
	int *ti;
	ti=read_modify_time();
	temp1=*ti;
	temp2=*(ti+1);
	temp3=*(ti+2);
	FILE* fp=NULL;
	fp=fopen("best drink.txt","w");
	if (NULL==fp)
	{
		printf("can't find this file!");
		exit(0) ;
	}
	fprintf(fp,"%d %d %d\n",temp1,temp2,temp3);
	int num[num3];
	for (int i=0;i<num3;i++)
	{
		for (int j=0;j<9;j++)
		{
			if (strcmp(list3[i].drink_name,list1[j].name)==0)
			{
				num[i]=j;
				break;
			}
		}
	}
	best_drink* p,*p0;
	for (int i=0;i<num3;i++)
	{
		p=head->next,p0=NULL;
		for (int j=0;j<num[i];j++)
		{
			p0=p;
			p=p->next;
		}
		p->month++;
		p->quater++;
		p->week++;
		p->year++; 
	} 
	p=head->next,p0=NULL;
	int i=1;
	do
	{
		if (p->next!=NULL){
			fseek(fp, 0L, SEEK_CUR);
			fprintf(fp,"%d %d %d %d %d\n",i,p->week,p->month,p->quater,p->year);
		}
		else{
			fseek(fp, 0L, SEEK_CUR);
			fprintf(fp,"%d %d %d %d %d",i,p->week,p->month,p->quater,p->year);	
		}
		i++;
		p0=p;
		p=p->next;
	}while(p);
	fclose(fp);
}

//���������Ʒ����Լ���������
int* return_best_num(best_drink* head,char ch)
{
	int max=0,maxnum=0,i=0;
	best_drink* p=head->next,*p0=NULL;
	if (ch=='1')
	{
		max=p->week;
		maxnum=1;
		i=1;
		p0=p;
		p=p->next;
		while(p!=NULL)
		{
			i++;
			if (p->week>max)
			{
				max=p->week;
				maxnum=i;
			}
			p0=p;
			p=p->next;
		}
	}
	else if (ch=='2')
	{
		max=p->month;
		maxnum=1;
		i=1;
		p0=p;
		p=p->next;
		while(p!=NULL)
		{
			i++;
			if (p->month>max)
			{
				max=p->month;
				maxnum=i;
			}
			p0=p;
			p=p->next;
		}
	}
	else if (ch=='3')
	{
		max=p->quater;
		maxnum=1;
		i=1;
		p0=p;
		p=p->next;
		while(p)
		{
			i++;
			if (p->quater>max)
			{
				max=p->quater;
				maxnum=i;
			}
			p0=p;
			p=p->next;
		}
	}
	else if (ch=='4')
	{
		max=p->year;
		maxnum=1;
		i=1;
		p0=p;
		p=p->next;
		while(p)
		{
			i++;
			if (p->year>max)
			{
				max=p->year;
				maxnum=i;
			}
			p0=p;
			p=p->next;
		}
	}
	int NUM[2];
	NUM[0]=max,NUM[1]=maxnum;   
	return NUM; 
} 

//��ʾ�����Ʒ
void show_best_drink(best_drink* head,struct drink list1[])
{
	int num[2]; 
	int* p;
	system("cls");
	printf("\t\t\t\t��������Ҫ��ѯ�����Ʒ�ķ�ʽ��\n");
	printf("\t\t\t\t     1���ܶȣ�\n");
	printf("\t\t\t\t     2���¶ȣ�\n");
	printf("\t\t\t\t     3�����ȣ�\n");
	printf("\t\t\t\t     4����ȣ�\n");
	printf("\t\t\t\t     0��ȡ����\n");
	char a;
	while(1)
	{
		a=getch();
		if (a=='1')
		{
			printf("\t\t\t\t ����Ϊ����ʾ�ܶ������Ʒ�����Ե�");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*p+1;
			printf("\t\t\t\t ���������ƷΪ��%ls\n",list1[num[1]].name);
			printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
		}
		else if (a=='2')
		{
			printf("\t\t\t\t   ����Ϊ����ʾ�¶������Ʒ�����Ե�");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*p+1;
			printf("\t\t\t\t ���������ƷΪ��%ls\n",list1[num[1]].name);
			printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
		}
		else if (a=='3')
		{
			printf("\t\t\t\t   ����Ϊ����ʾ���������Ʒ�����Ե�");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*p+1;
			printf("\t\t\t\t ���������ƷΪ��%ls\n",list1[num[1]].name);
			printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
		}
		else if (a=='4')
		{
			printf("\t\t\t\t   ����Ϊ����ʾ��������Ʒ�����Ե�");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*(p+1);
			printf("\t\t\t\t ���������ƷΪ��%ls\n",list1[num[1]-1].name);
			printf("\t\t\t\t   ���۳� %d ��\n",num[0]);
		}
		else if (a=='0')
		{
			return;
		}
	}
} 

//��ʾ��־
void show_log()
{
	system("cls");
	FILE* fp;
	fp=fopen("beverage sales list.txt","r");
	char s[60];
	printf("\t\t\t*******************************************************************\n");
	while(fgets(s,50,fp)!=NULL)
	{
		printf("\t\t\t  ");
		printf("%s",s);
	}
	printf("\t\t\t*******************************************************************\n");
	fclose(fp);
}


//�жϹ˿��Ƿ�ΪVIP 
bool If_vip()
{
	printf("\t\t\t*******************************************************************\n");
	bool flag;
	char a;
	while (1)
	{
		system("cls");
		printf("\t\t�������Ƿ�ΪVIP��\n");
		printf("\t\t  1���ǣ�\n");
		printf("\t\t  2�����ǣ�\n");
		printf("\t\t  3�������Ƿ�Ϊ��Ա��\n"); 
		a = _getch();
		if (a >= '1' && a <= '3')
		{
			switch (a)
			{
			case '1':
				printf("\t\t\t��\n");
				printf("\t\t  ");
				Sleep(700);
				return true;
			case '2':
				printf("\t\t\t��\n");
				printf("\t\t  ");
				Sleep(700);
				return false;
			case '3':
				printf("\t\t\t�����Ƿ�Ϊ��Ա\n");
				printf("\t\t  ");
				Sleep(700);
				flag = observe_vip('2');
				system("pause");
				return flag;
			}
		}
		else
		{
			printf("\t\t�������벻���Ϲ淶��������һ����");
			getchar();
		}
	}

}

//�ļ�д��
void save_vip()
{
	vip* temp = v_head->next;
	FILE* fp = fopen("vip.txt", "w");
	while (temp)
	{
		fprintf(fp, "%d %s %s %d\n", temp->num, temp->name, temp->phone, temp->money);
		temp = temp->next;
	}
	fclose(fp);
}

//���ļ��м��ػ�Ա��Ϣ������
vip* load_vip()
{
	int num, money;
	char name[30], phone[20];
	vip* head = (vip*)malloc(sizeof(vip));
	vip* p;
	FILE* fp = fopen("vip.txt", "r");
	p = head;
	if (fp == NULL)
	{
		printf("Error code:114514");
	}
	else
	{
		while (fscanf(fp, "%d %s %s %d", &num, name, phone, &money) != EOF)
		{
			vip* q = (vip*)malloc(sizeof(vip));
			q->num = num;
			strcpy(q->name, name);
			strcpy(q->phone, phone);
			q->money = money;
			p->next = q;
			p = q;
		}
		p->next = NULL;
		v_end = p;
	}
	fclose(fp);
	return head;
}

//���ر��
int Return_vipnum()
{
	int num=1,temp1,temp2,temp3,temp4;
	char temp[20],temp5[20];
	FILE* sp;
	sp = fopen("vip.txt", "r");
	if (sp == NULL)
	{
		printf("Can't open this file!");
		exit(0);
	}
	while (fscanf(sp, "%d %s %s %d ", &num, temp, temp5, &temp2) != EOF);
	fclose(sp);
	return num;
} 

//����»�Ա��Ϣ
vip* add_vip()
{
	int n, num=Return_vipnum()+1, money=0;
	char name[30], phone[20];
	vip* p = v_end;
		system("cls");
		vip* t = (vip*)malloc(sizeof(vip));
		printf("\t\t������˿͵�������\n\t\t   ");
		scanf("%s", name);
		printf("\t\t������˿͵��ֻ��ţ�\n\t\t   ");
		scanf("%s",phone);
		t->num = num;
		strcpy(t->name, name);
		strcpy(t->phone, phone);
		t->money = money;
		p->next = t;
		t->next = NULL;
		p = t;
	p->next = NULL;
	v_end = p;
	save_vip();
	return v_end;
}

//��Ա��¼
int login_vip()
{
	vip* p = v_head->next;
	bool flag = false;
	char name[30], phone[20];
	system("cls");
	printf("\t\t\t�������Ա������������q�������˵���\n");
	printf("\t\t\t  "); 
	scanf("%s", name);
	// ���������q�ͷ������˵�
	if (strcmp(name, "q") == 0)
	{
		return -1;
	}
	printf("\t\t\t�������Ա���ֻ��ţ�����q�������˵���\n");
	printf("\t\t\t  "); 
	scanf("%s", phone);
	// ���������q�ͷ������˵�
	if (strcmp(phone, "q") == 0)
	{
		return -1;
	}
	while (p)
	{
		if (strcmp(name, p->name) == 0 && strcmp(phone, p->phone) == 0)
		{
			v_user = p;
			flag = true;
			break;
		}
		p = p->next;
	}
	if (flag) {
		return 1;
	}
	else return 0;
}

//��¼�������
int login_out()
{
	int flag = login_vip();
	while (flag == 0)
	{
		system("cls");
		printf("\t�������ֻ��������������!\n");
		flag = login_vip();
	}
	if (flag == -1) {
		// �������˵�
		return 0;
	}
	if (flag == 1)
	{
		system("cls");
		printf("\t\t\t\t��ӭ�����𾴵Ľ����Ա��\n");
		user_vip();
		return 1;
	}
	return 0;
}

//�鿴��Ա��Ϣ
bool observe_vip(char ch)
{
	vip* p = v_head->next;
	system("cls");
	if (p == NULL)
	{
		system("cls");
		printf("  \t\t�޻�Ա��Ϣ��(�ޣգ�)��~�٣�\n");
		return false;
	}
	else
	{
		if (ch == '1') //��ӡȫ����Ա��Ϣ
		{
			printf("\t\t*******************************************************************\n");
			printf("\t\t**��Ա���\t��Ա����\t�ֻ�����\t���ѽ��\t **\n");
			printf("\t\t*******************************************************************\n");
			while (p != NULL)
			{
				if(strlen(p->name)==4)
				{
					printf("\t\t**  %d\t\t %s   \t %s  \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
				}
				else
				{ 
					printf("\t\t**  %d\t\t %s \t %s \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
				}
				p = p->next;
			}
			printf("\t\t*******************************************************************\n");
			return true;
		}
		if (ch == '2')//��ӡ�ض���Ա��Ϣ
		{
			bool flag;
			char a;
			printf("\t��ѡ���ѯ��ʽ��\n");
			printf("\t 1��ͨ����Ա��Ų�ѯ��\n");
			printf("\t 2��ͨ����Ա������ѯ��\n");
			printf("\t 3��ͨ���ֻ������ѯ��\n");
			a = _getch();
			if (a >= '1' && a <= '3')
			{
				system("cls");
				flag = obpro_vip(a);
				return flag;
			}
			else
			{
				printf("\t����������������������:\n");
			}
		}
	}
}

//��ѯ������չ
bool obpro_vip(char a)
{
	vip* p = v_head->next;
	int num;
	char phone[20], name[10];
	if (a == '1')
	{
		printf("\t�������Ա��ţ�\n");
		printf("\t  ");
		scanf("%d", &num);
		while (p != NULL)
		{
			if (num == p->num)
			{
				printf("\t\t*******************************************************************\n");
				printf("\t\t**��Ա���\t��Ա����\t�ֻ�����\t���ѽ��\t **\n");
				printf("\t\t*******************************************************************\n");
				if(strlen(p->name)==4)
				{
					printf("\t\t**  %d\t\t %s   \t %s  \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
				}
				else
				{ 
					printf("\t\t**  %d\t\t %s \t %s \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
				}
				printf("\t\t*******************************************************************\n");
				return true;
			}
			p = p->next;
		}
		printf("�޻�Ա��Ϣ��(�ޣգ�)��~�٣�\n");
		return false;
	}
	if (a == '2')
	{
		int i = 0;
		printf("\t\t\t�������Ա������\n");
		printf("\t\t\t  ");
		scanf("%s", name);
		while (p != NULL)
		{
			if (strcmp(name, p->name) == 0)
			{
				i++;
				break;
			}
			p = p->next;
		}
		if (i == 0)
		{
			system("cls");
			printf("�޻�Ա��Ϣ��(�ޣգ�)��~�٣�\n");
			return false;
		}
		else
		{
			system("cls");
			printf("\t\t*******************************************************************\n");
			printf("\t\t**��Ա���\t��Ա����\t�ֻ�����\t���ѽ��\t **\n");
			printf("\t\t*******************************************************************\n");
			while (p != NULL)
			{
				if (strcmp(name, p->name) == 0)
				{
					if(strlen(p->name)==4)
					{
						printf("\t\t**  %d\t\t %s   \t %s  \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
					}
					else
					{ 
						printf("\t\t**  %d\t\t %s \t %s \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
					}
				}
				p = p->next;
			}
			printf("\t\t*******************************************************************\n");
			return true;
		}
	}
	if (a == '3')
	{
		printf("\t\t\t�������ֻ����룺\n");
		printf("\t\t\t  ");
		scanf("%s", phone);
		while (p != NULL)
		{
			if (strcmp(phone, p->phone) == 0)
			{
				printf("\t\t*******************************************************************\n");
				printf("\t\t**��Ա���\t��Ա����\t�ֻ�����\t���ѽ��\t **\n");
				printf("\t\t*******************************************************************\n");
				if(strlen(p->name)==4)
				{
					printf("\t\t**  %d\t\t %s   \t %s  \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
				}
				else
				{ 
					printf("\t\t**  %d\t\t %s \t %s \t %d\t\t **\n", p->num, p->name, p->phone, p->money);
				}
				printf("\t\t*******************************************************************\n");
				return true;
			}
			p = p->next;
		}
		printf("�޻�Ա��Ϣ��(�ޣգ�)��~�٣�\n");
		return false;
	}
}

//�޸Ļ�Ա��Ϣ
void modify_vip()
{
	int num;
	int money;
	char e='8'; 
	char name[30], phone[20];
	vip* p = v_head, * q = p->next;
	printf("\t\t*******************************************************************\n");
	printf("\t\t                  ������Ҫ�޸ĵĻ�Ա���:");
	scanf("%d", &num);
	printf("\t\t                          %d\n", num);
	printf("\t\t*******************************************************************\n");
	while (q)
	{
		if (q->num == num)
		{
			while (e != '0')
			{
				system("cls");
				printf("\t\t*******************************************************************\n");
				printf("\t\t**                  ��ѡ����Ҫ�޸ĵ���Ϣ:                        **\n");
				printf("\t\t**                    1����Ա����                                **\n");
				printf("\t\t**                    2���ֻ����룻                              **\n");
				printf("\t\t**                    3����Ա���֣�                              **\n");
				printf("\t\t**                    0���˳�ϵͳ��                              **\n");
				printf("\t\t*******************************************************************\n");
				e=getch();
				if (e >= '0' && e <= '3')
				{
					switch (e)
					{
					case '1':
						system("cls");
						printf("�޸�ǰ��Ա����:%s\n", q->name);
						printf("�޸ĺ��Ա����:");
						scanf("%s", name);
						strcpy(q->name, name);
						printf("\n�޸ĳɹ�");
						system("pause");
						break;
					case '2':
						system("cls");
						printf("�޸�ǰ�ֻ�����:%s\n", q->phone);
						printf("�޸ĺ��ֻ�����:");
						scanf("%s", phone);
						strcpy(q->phone, phone);
						printf("\n�޸ĳɹ�");
						system("pause");
						break;
					case '3':
						system("cls");
						printf("�޸�ǰ��Ա����:%d\n", q->money);
						printf("�޸ĺ��Ա����:");
						scanf("%d", &money);
						q->money = money;
						printf("\n�޸ĳɹ�!");
						system("pause");
						break;
					case '0':
						break;
					}
				}
				else
				{
					system("cls");
					printf("���Ĳ��������Ϲ淶Ӵ��(�ޣգ�)��~�٣�\n");
					printf("����������һ����\n");
					system("pause");
					continue;
				}
			}
		}
		q = q->next;
	}
	save_vip();
}
//ɾ����Ա��Ϣ
void delete_vip()
{
	int num;
	vip* p = v_head, *q = p->next;
	bool t=observe_vip(1);
	printf("������ɾ���밴0����\n");
	printf("��������Ҫɾ���ı�ţ�");
	scanf("%d", &num);
	if (num == 0)
	{

	}
	else {
		while (p)
		{
			if (q->num == num)
			{
				p->next = q->next;
				printf("ɾ���ɹ�!\n");
			}
			q = q->next;
			p = p->next;
		}
	}
	save_vip();
}
//��Ա���ֶһ�����
void exchange_gift()
{
	int e = 8;
	while (e != 0)
	{
		gift* p = g_head->next, * q = p;
		system("cls");
		printf("\t\t*******************************************************************\n");
		printf("\t\t**��Ʒ���\t��Ʒ����\t�������\t�������\t **\n");
		printf("\t\t*******************************************************************\n");
		while (p != NULL)
		{
			if (strlen(p->name)==6) 
			{
				printf("\t\t**  %d\t\t %s \t %d \t\t %d\t\t **\n", p->num, p->name, p->score, p->stock);
			}
			else 
			{
				printf("\t\t**  %d\t\t %s   \t %d \t\t %d\t\t **\n", p->num, p->name, p->score, p->stock);
			}
			p = p->next;
		}
		printf("\t\t*******************************************************************\n");
		printf("\t\t��������һ��밴0\n");
		printf("\t\t����������Ҫ�һ�����Ʒ��ţ�");
		scanf("%d", &e);
		while (q != NULL)
		{
			if (q->num == e) break;
			q = q->next;
		}
		if (q != NULL)
		{
			if (q->stock != 0 && v_user->money >= q->score)
			{
				struct tm* local;
				time_t t;
				t = time(NULL);
				local = localtime(&t);
				FILE* fp = fopen("history_gift.txt", "at");
				v_user->money -= q->score;
				q->stock--;
				save_gift();
				save_vip();
				fprintf(fp, "%d%02d%d%02d%02d%02d %s %s\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec, v_user->name, q->name);
				fclose(fp);
				printf("\t\t�һ��ɹ���");
				system("pause");
			}
			else
			{
				if (q->stock == 0) printf("\t\t��Ʒ��治��\n");
				if (v_user->money < q->score) printf("\t\t��Ա���ֲ���");
				system("pause");
			}
		}
		else
		{
			if (e != 0)
			{
				printf("\t\t�����������󣬼���������һ����");
				system("pause");
			}
			else
			{
				system("pause");
			}
		}
	}
}
//�鿴��Ʒ�һ���¼
void history_gift()
{
	char* temp;
	int f, t, r;
	FILE* fp = fopen("history_gift.txt", "r");
	if (fp == NULL) {
		printf("Error");
	}
	fseek(fp, 0, SEEK_END);
	f = ftell(fp);
	if (f == 0)
	{
		printf("\t\t\t\t ������Ʒ�һ���¼");
	}
	else
	{
		rewind(fp);
		t = f * sizeof(char) + 1;
		temp = (char*)malloc(t);
		memset(temp, 0, t);
		r = fread(temp, 1, f, fp);
		printf(temp);
		free(temp);
	}
	fclose(fp);
}
//�齱����
int roll(int num)
{
	struct tm* local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	if (local->tm_mday % 5 != 0)
	{
		printf("\t\t���շǻʱ�䣡");
		getchar();
		return num;
	}
	else
	{
		if (num != 0)
		{
			int a, n;
			srand((int)time(0));
			a = rand() % 10 + 1;
			n = local->tm_sec % 10 + 1;
			printf("\t\t���γ齱��������Ϊ��%d\n", n);
			printf("\t\t�밴��������г齱~\n");
			getchar();
			printf("\t\t�����γ�õ�����Ϊ��%d", a);
			if (a == n)
			{
				v_user->money += 10;
				printf("\t\t��ϲ�������н������10��Ա���֣�");
			}
			else
			{
				printf("\t\tлл���룡");
			}
			num--;
			return num;
		}
		else
		{
			printf("\t\t���ĳ齱����������\n");
			printf("\t\t");
			system("pause");
			return num;
		}
	}
}
//��Ա����
void user_vip()
{
	int i = 3;
	char e = 8;
	while (e != '0')
	{
		system("cls");
		printf("\t\t----------------------��Ա���ֶһ������ѿ���----------------------\n");
		printf("\t\t*******************************************************************\n");
		printf("\t\t**��Ա���\t��Ա����\t�ֻ�����\t���ѽ��\t **\n");
		printf("\t\t*******************************************************************\n");
		if(strlen(v_user->name)==4)
		{
			printf("\t\t**  %d\t\t %s   \t %s  \t %d\t\t **\n", v_user->num, v_user->name, v_user->phone, v_user->money);
		}
		else
		{ 
			printf("\t\t**  %d\t\t %s \t %s \t %d\t\t **\n", v_user->num, v_user->name, v_user->phone, v_user->money);
		}
		printf("\t\t*******************************************************************\n");
		printf("\t\t--------------------05���˴�齱����޽�����--------------------\n");
		printf("\t\t��ѡ������Ҫ���еĲ�����\n");
		printf("\t\t1����Ա���ֶһ���\n");
		printf("\t\t2��05���˴�齱��\n");
		printf("\t\t0������㵥���棻\n");
		e = _getch();
		if (e >= '0' && e <= '2')
		{
			switch (e)
			{
			case'1':
				printf("\t\t���ڽ���һ�ϵͳ");
				for (int k = 0; k < 5; k++)
				{
					printf("~");
					Sleep(200);
				}
				system("cls");
				exchange_gift();
				break;
			case'2':
				printf("\t\t���ڽ���齱ϵͳ");
				for (int k = 0; k < 5; k++)
				{
					printf("~");
					Sleep(200);
				}
				system("cls");
				printf("\t\t����ӵ��%d�γ齱����\n", i);
				i = roll(i);
				break;
			case'0':
				break;
			}
		}
		else
		{
			system("cls");
			printf("\t\t�������벻���Ϲ淶,����������һ����");
			system("pause");
			system("cls");
		}
	}
	printf("\t\t\t���ڽ�����ϵͳ");
	for (int k = 0; k < 5; k++)
	{
		printf("~");
		Sleep(200);
	}
}
//��Ʒ��Ϣ�洢
void save_gift()
{
	gift* temp = g_head->next;
	FILE* fp = fopen("gift.txt", "w");
	while (temp)
	{
		fprintf(fp, "%d %s %d %d\n", temp->num, temp->name, temp->score, temp->stock);
		temp = temp->next;
	}
	fclose(fp);
}
//��Ʒ��Ϣ����
gift* load_gift()
{
	int num, score, stock;
	char name[30];
	gift* head = (gift*)malloc(sizeof(gift));
	gift* p;
	FILE* fp = fopen("gift.txt", "r");
	p = head;
	if (fp == NULL)
	{
		printf("Error");
	}
	else
	{
		while (fscanf(fp, "%d %s %d %d", &num, name, &score, &stock) != EOF)
		{
			gift* q = (gift*)malloc(sizeof(gift));
			q->num = num;
			strcpy(q->name, name);
			q->score = score;
			q->stock = stock;
			p->next = q;
			p = q;
		}
		p->next = NULL;
		g_end = p;
	}
	fclose(fp);
	return head;
}

//ԭ����������
material creat()
{
	char c[64];  //��c[]Ϊý�����������ݣ� 
	FILE* sp;
	sp = fopen("material record.txt", "r");  //��ԭ�ϱ�,spָ���ļ��� 
	if (sp == NULL)
	{
		printf("Can not open this file\n");
		exit(0);
	}
	rewind(sp);
	material head, p, p0 = NULL;  //p0Ϊ�ڱ���headΪ����ͷ��pΪ����ĩβ�� 
	head = (material)malloc(sizeof(Drink_Material));
	p0 = head;
	p0->next = NULL;
	do
	{
		fgets(c, 64, sp);
		p = (material)malloc(sizeof(Drink_Material));
		sscanf(c, "%d %ls %d", &p->id, &p->name, &p->weight);
		p0->next = p;
		p0 = p;
		p0->next = NULL;
	} while (p->id < 17);
	fclose(sp);
	return head;
}


//��������ԭ�ϵ����ģ�
material material_delete(material head, int num1, struct id* q)
{
	for (int j = 0; j < num1; j++)
	{
		if (q[j].id2 != 0)
		{
			drinks[q[j].id1 - 1][4] = q[j].id2 + 8;
		}
		if (q[j].id3 != 0)
		{
			drinks[q[j].id1 - 1][5] = q[j].id3 + 8;
		}
	}
	material p0 = NULL, p = head->next;
	for (int k = 0; k < num1; k++)
	{
		for (int i = 0; i < 6; i++)
		{
			p = head->next;
			p0 = NULL;
			while (p != NULL)   //����������������id�������������ж��������ϣ��� 
			{
				if (p->id == drinks[q[k].id1 - 1][i])
				{
					if (i < 4)
					{
						if(p->id==1||p->id==2||p->id==6)
						{
							p->weight = p->weight - 30;
						}
						else if(p->id==3||p->id==4||p->id==5)
						{
							p->weight = p->weight - 50;
						}
						else
						{
							p->weight = p->weight - 10;
						}
					}
					else
					{
						if(p->id==10||p->id==12||p->id==14||p->id==17)
						{
							p->weight = p->weight - 20;
						}
						else if(p->id==15||p->id==11)
						{
							p->weight = p->weight - 40;
						}
						else
						{
							p->weight = p->weight - 10;
						}
					}
					p0 = p;
					p = p->next;
				}
				else
				{
					p0 = p;
					p = p->next;
				}
			}
		}
	}
	return head;
}

//�����ݴ洢���ļ��У�
void material_file(material head)
{
	FILE* st;
	st = fopen("material record.txt", "w");
	if (NULL == st)
	{
		printf("Can not open this file\n");
		return;
	}
	material p = head->next, p0 = NULL;
	int q = 0;
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			fprintf(st, "%d     %ls     %d", p->id, p->name, p->weight);
			p0 = p;
			p = p->next;
		}
		else
		{
			fprintf(st, "%d     %ls     %d\n", p->id, p->name, p->weight);
			p0 = p;
			p = p->next;
		}
		q++;
	}
	fclose(st);
}


//��ԭ��ʣ���������Ļ�ϣ�
void material_print(struct Using_Id bridge[])
{
	system("color 9E");
	char c[63];
	FILE* sz;
	sz = fopen("material record.txt", "r");
	if (sz == NULL)
	{
		printf("Can not open this file\n");
		return;
	}
	for (int i = 0; i < 17; i++)
	{
		fgets(c, 65, sz);
		sscanf(c, "%d %ls %d", &bridge[i].id, &bridge[i].name, &bridge[i].weight);
	}
	printf("\t\t*******************************************************************\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t\t���\t\t����\t\t\t���\n");
	printf("\t\t*******************************************************************\n");
	for (int i = 0; i < 17; i++)
	{
		printf("\t\t\t%d\t\t%ls\t\t\t%d\n", bridge[i].id, bridge[i].name, bridge[i].weight);
	}
	printf("\t\t*******************************************************************\n");
	printf("\t\t*******************************************************************\n");
	return;
}


//ʵ�ֹ���ԭ�ϵ��ܺ����� 
void purchase()
{
	char a;
	int b, c;
	printf("\n\t\t�Ƿ�Ҫ����ԭ�ϣ�\n");
	printf("\t\t���ã� Y \t�����ã� N\n");
	while (1)
	{
		a = getch();
		if (a == 'Y' || a == 'y')
		{
			system("cls");
			buy_material();
			return;
		}
		else if (a == 'N' || a == 'n')
		{

			return;
		}
		else
		{
			printf("\t\t�������벻���Ϲ淶�����������룺\n");
			continue;
		}
	}
}

//ʵ�ֹ���ԭ��
void buy_material()
{
	Buy bu1, bu2;
	bu1 = buy_creat();
	bu2 = buy_add(bu1, weights);
	buy_material_file(bu2);
	return;
}

//ʵ�ֹ��ڹ���ԭ������Ĵ�����
Buy buy_creat()
{
	char c[64];  //��c[]Ϊý�����������ݣ� 
	FILE* sp;
	FILE* so;
	sp = fopen("material record.txt", "r");  //��ԭ�ϱ�,spָ���ļ��� 
	if (sp == NULL)
	{
		printf("Can not open this file\n");
		exit(0);
	}
	rewind(sp);
	Buy head, p, p0 = NULL;  //p0Ϊ�ڱ���headΪ����ͷ��pΪ����ĩβ�� 
	head = (Buy)malloc(sizeof(buy_materials));
	p0 = head;
	p0->next = NULL;
	do
	{
		fgets(c, 64, sp);
		p = (Buy)malloc(sizeof(buy_materials));
		sscanf(c, "%d %ls %d", &p->id, &p->name, &p->weight);
		p0->next = p;
		p0 = p;
		p0->next = NULL;
	} while (p->id < 17);
	fclose(sp);
	return head;
}


//����ԭ�ϣ�
Buy buy_add(Buy head, struct buy_weights weights[])
{
	int material_money[17]={10,5,8,14,6,7,3,5,4,9,2,12,15,4,9,8,15};  //ÿ100��ԭ�ϵļ۸� 
	FILE* sj = fopen("history material file.txt", "a");   //history material file.txt�ļ��Ǵ�����ʷ����ԭ�ϼ�¼; 
	FILE* so = fopen("money.txt","r");
	if (sj == NULL)
	{
		printf("Can not open this file.");
		exit(0);
	}
	if (so == NULL)
	{
		printf("Can not open this file\n");
		exit(0);
	}
	int our_money=0;
	char str1[63];
	fgets(str1,63,so);
	sscanf(str1,"%d",&our_money);
	int a, time[5];    //aΪԭ�Ϲ��õ�������time��¼ʱ�䣻 
	a = output_3();
	printf("\t\t����������Ҫ���õ�ԭ�ϵ����:\n");
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &weights[i].buy_id);
		if(weights[i].buy_id>17)
		{
			printf("����������������롣");
			i--;
			continue;
		}
	}
	print_time2(time);   //��¼��ǰ��ʱ�䣻 
	fprintf(sj, "%d ��%d ��  %d:%d\n", time[0], time[1], time[2], time[3]);
	Buy p = head->next, p0 = NULL;
	for (int i = 0; i < a; i++)
	{
		printf("\t\t������%d��ԭ�ϵĹ�����������λ��g ,��100g�ı�������", weights[i].buy_id);
		scanf("%d", &weights[i].BUY_weight);
		while(((weights[i].BUY_weight)/100)*(material_money[weights[i].buy_id-1])>our_money)
		{
			printf("����,�޷�����,���������룺\n");
			scanf("%d", &weights[i].BUY_weight);
		}
		our_money=our_money-((weights[i].BUY_weight)/100)*(material_money[weights[i].buy_id-1]);
		p0 = NULL;
		p = head->next;
		while (p != NULL)
		{
			if (p->id == weights[i].buy_id)
			{
				fprintf(sj, "%d\t%ls\t%d\n", weights[i].buy_id, p->name, weights[i].BUY_weight);
				p->weight = p->weight + weights[i].BUY_weight;
				p0 = p;
				p = p->next;
			}
			else
			{
				p0 = p;
				p = p->next;
			}
		}
	}
	save_money_file(our_money);
	fclose(sj);
	fclose(so);
	return head;
}


//������ԭ�������������¼���ļ���
void buy_material_file(Buy head)
{
	FILE* sl;
	sl = fopen("material record.txt", "w");
	if (NULL == sl)
	{
		printf("Can not open this file\n");
		return;
	}
	Buy p = head->next, p0 = NULL;
	int q = 1;
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			fprintf(sl, "%d       %ls      %d",  p->id, p->name, p->weight);
			p0 = p;
			p = p->next;
		}
		else
		{
			fprintf(sl, "%d       %ls      %d\n", p->id, p->name, p->weight);
			p0 = p;
			p = p->next;
		}
		q++;
	}
	fclose(sl);
}

//ʵ��¼����Ҫ�����ԭ������������
int output_3()
{
	int a = 0;
	char b[3];
	printf("\t\t*******************************************************************\n");
	printf("\t\t           ��������Ҫ�����ԭ��������(ԭ�Ϲ���17��)                \n");
	printf("\t\t                               ");
	scanf("%d", &a);
	while(a>17)
	{
		printf("�������Ӧ����С��17�����֡�\n");
		printf("���������룺\n"); 
		scanf("%d",&a);
	}
	system("cls");
	printf("\t\t*******************************************************************\n");
	printf("\t\t                        ��������Ϊ��%d                                \n", a);
	printf("\t\t*******************************************************************\n");
	printf("\n");
	material_print(bridge);
	return a;
}


//����ԭ�ϵ�ʱ��Ĵ��棻 
void print_time2(int a[])
{
	struct tm* local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	a[0] = local->tm_mon + 1;
	a[1] = local->tm_mday;
	a[2] = local->tm_hour;
	a[3] = local->tm_min;
	a[4] = local->tm_sec; 
}


//�򿪹���ԭ�ϵ���ʷ��¼ ��
void open_history_file()
{
	char c[255];
	FILE* sr = fopen("history material file.txt", "r");
	if (sr == NULL)
	{
		printf("Can not open this file.");
		exit(0);
	}
	printf("\t\t*******************************************************************\n");
	while (fgets(c, 255, sr) != NULL)
	{
		for (int i = 0; i < 255; i++)
		{
			if (c[i] == '\n')
			{
				c[i] = ' ';
			}
		}
		printf("\t\t                          %s\n", c);
	}
	printf("\t\t*******************************************************************\n\n");
}

//���ļ��е����ݴ�������drinks[][]��;
void read_material(int drinks[][6])
{
	FILE* sp=fopen("drinks material.txt","r");
	if(sp==NULL)
	{
		printf("Can not find this file .");
		return ;
	}
	rewind(sp);
	char c[63];
	int i=0;
	while(fgets(c,63,sp)!=NULL)
	{
		sscanf(c,"%d %d %d %d %d %d", &drinks[i][0], &drinks[i][1], &drinks[i][2], &drinks[i][3], &drinks[i][4], &drinks[i][5]);
		i++;
	}
	return ;
}


//���Ǯ��; 
void sum_money()
{
	FILE* so=fopen("money.txt","r");
	if(so==NULL)
	{
		printf("Can not open this file.");
		return ;
	}
	int our_money;
	char c[63];
	fgets(c,63,so);
	sscanf(c,"%d",&our_money);
	printf("\t\t*******************************************************************\n");
	printf("\t\t**\t\t��Ʒ������Ϊ��");
	printf("%d\t\t\t\t **\n",our_money);
	printf("\t\t*******************************************************************\n");
	fclose(so);
	return ;
}

//���������ļ�;
void save_money_file(int our_money)
{
	FILE* sp=fopen("money.txt","w");
	if(sp==NULL)
	{
		printf("Can not find this file.");
		return ;
	}
	fprintf(sp,"%d",our_money);
	fclose(sp);
	return ;
}

//��ȡ������
Order_now build_file_now() {  //��������Ĵ��� 
	FILE* fp;
	fp = fopen("history order record.txt", "r");  //����ʷ��¼�ļ��� 
	if (fp == NULL) {
		printf("Can not open this file\n");
		exit(1);
	}
	rewind(fp);
	Order_now p,head=NULL,p0;
	head=(Order_now)malloc(sizeof(Order_Now));
	p0 = head;
	p0->next = NULL;
	char str[100];	//����Ϊý��ת������ 
	while (fgets(str, 100, fp) != NULL) 
	{
		p = (Order_now)malloc(sizeof(Order_Now));
		sscanf(str, "%d %s %d %d %d %d %s", &p->id, &p->name, &p->price, &p->cost, &p->month, &p->day,&p->order_num);
		p0->next = p;
		p0 = p;
		p0->next = NULL;
	}
	fclose(fp);
	return head;
}


//��ȡԭ�ϣ� 
void read_material_al(int drinks[][6])
{
	FILE* sp=fopen("drink formulation.txt","r");
	if(sp==NULL)
	{
		printf("Can not find this file .");
		return ;
	}
	rewind(sp);
	char c[63];
	int i=0;
	while(fgets(c,63,sp)!=NULL)
	{
		sscanf(c,"%d %d %d %d %d %d", &drinks[i][0], &drinks[i][1], &drinks[i][2], &drinks[i][3], &drinks[i][4], &drinks[i][5]);
		i++;
	}
	fclose(sp);
	return ;
}

//�ж�ԭ�Ͼ����ߣ�
void judge_material(int guard[],struct Using_Id bridge[])
{
	material t1,t2;
	t1=creat();
	int q=0;
	while(q=judge_now_material(t1,guard,bridge))
	{
		if(q!=0)
		{
			printf("\n");
			printf("\n");
			printf("\t\t\t�Ƿ����ڹ���ԭ��?\n");
			printf("\t\t\t�ǣ�Y       ��N\n"); 
			printf("\n");
			printf("\t\t*******************************************\n");
			printf("\t\t*******************************************\n");
			printf("\t\t\t����%d��ԭ�ϲ���\n",q); 
			printf("\n");
			printf("\n");
			while (1)
			{
				int a = getch();
				if (a == 'Y' || a == 'y')
				{
					system("cls");
					buy_material();
					system("cls");
					material_print(bridge);
					t1=creat();	
					break;
				}
				else if (a == 'N' || a == 'n')
				{
		
					return;
				}
				else
				{
					printf("\t\t\t�������벻���Ϲ淶�����������룺\n");
					continue;
				}
			}
		}
		else
		{
			break ;
		}
	}
	if(q==0)
	{
		printf("\n");
		printf("\t\t\t\tԭ�ϳ��㡣\n");
		printf("\n");
		printf("\t\t*******************************************\n");
		return ;
	}
}

//�ж�ԭ���뾯���ߵĲ�ࣻ
int judge_now_material(material head,int guard[],struct Using_Id bridge[])
{
	int li=0; 
	material p0=NULL,p=head->next;
	printf("\t\t*******************************************\n");
	for(int i=0;i<17;i++)
	{
		if(p->weight<=guard[i])
		{
			printf("\t\t\t�� %d ��ԭ�ϣ�%ls �����ľ����뾡�칺��\n",i+1,p->name);
			p0=p;
			p=p->next;
			li++;
		}
		else
		{
			p0=p;
			p=p->next;
		}
	}
	return li;
}

//�����¡�������
void calculate_profit(Order_now head)
{
	int turnover[12]={0},/*Ӫҵ��*/profit[12]={0}/*ӯ����*/;
	Order_now p=head->next,p0=NULL; 
	printf("1.��ѯ�¶�Ӫҵ��/����\n");
	printf("2.��ѯ����Ӫҵ��/����\n");
	for(int i=0;i<12;i++)
	{
		p=head->next;
		p0=NULL;
		while(p!=NULL)
		{
			if(p->month==i+1)
			{
				profit[i]=profit[i]+p->price-p->cost;
				turnover[i]=turnover[i]+p->price;
				p0=p;
				p=p->next;
			}
			else
			{
				p0=p;
				p=p->next;
			}
		}
	}
	int turnover2[4]={0},profit2[4]={0}; 
	for(int i=0;i<4;i++)
	{
		turnover2[i]=turnover[i*3]+turnover[i*3+1]+turnover[i*3+2];
		profit2[i]=profit[i*3]+profit[i*3+1]+profit[i*3+2];
	}
fing:
	char b=getch();
	if(b=='1')
	{
		int o1;
		system("cls");
		printf("�������·�:");
		scanf("%d",&o1);
		printf("\t*************************************\n");
		printf("\n");
		printf("\t\tӪҵ��:%d     ����:%d",turnover[o1-1],profit[o1-1]);
		printf("\n");
		printf("\t*************************************\n");
		system("pause");
	}
	else if(b=='2')
	{
		int o2;
		system("cls");
		printf("�����뼾��:");
		scanf("%d",&o2);
		printf("\t*************************************\n");
		printf("\n");
		printf("\t\tӪҵ��:%d     ����:%d",turnover2[o2-1],profit2[o2-1]);
		printf("\n");
		printf("\t*************************************\n");
		system("pause");
	}
	else
	{
		printf("������������ԣ�");
		goto fing;
	}
}
//��������Ĵ��� 
struct order* build() {
	FILE* fp;
	fp = fopen("history order record.txt", "r");  //����ʷ��¼�ļ��� 
	if (fp == NULL) {
		printf("Can not open this file\n");
		exit(1);
	}
	struct order* top = NULL, * rear = NULL, * p;
	char str[100];	//����Ϊý��ת������ 
	while (fgets(str, 60, fp) != NULL) {
		p = (struct order*)malloc(sizeof(struct order));
		sscanf(str, "%s %d %d %d %d", &p->name, &p->price, &p->cost, &p->month, &p->day);
		p->next = NULL;
		if (rear == NULL)
			top = rear = p;
		else {
			rear->next = p;
			rear = p;
		}
	}
	fclose(fp);
	return top;
}

//�����·� 
int input_month() {
	int x;
	printf("����������Ҫ�鿴�Ķ�����¼���·ݣ�\n");
	scanf("%d", &x);
	while (x < 1 || x>12) {
		system("cls");
		printf("        ������·ݲ��Ϸ�\n           ����������");
		Sleep(1);
		system("cls");
		printf("����������Ҫ�鿴�Ķ�����¼���·ݣ�\n");
		scanf("%d", &x);
	}
	return x;
}

//��������
int input_day() {
	int y;
	system("cls");
	printf("����������Ҫ�鿴�Ķ�����¼�����ڣ�\n");
	scanf("%d", &y);
	while (y < 1 || y>30) {
		system("cls");
		printf("        ��������ڲ��Ϸ�\n           ����������");
		Sleep(1);
		system("cls");
		printf("����������Ҫ�鿴�Ķ�����¼�����ڣ�\n");
		scanf("%d", &y);
	}
	return y;
}

//���������ĳ��ĳ�ն�����¼
void output_order_list(struct order* p, int x/*��*/, int y/*��*/) {
	system("cls");
	printf("%10d��%d��\n\n", x, y);
	printf("��� ��Ʒ���� �ۼ� �ɱ�\n");
	int turnover = 0/*Ӫҵ��*/, profit = 0/*ӯ����*/;
	int i = 1, flag = 0;
	while (p != NULL) {
		if ((p->month == x) && (p->day == y)) {
			printf(" %-5d%-9s%-5d%d\n", i++, p->name, p->price, p->cost);
			turnover = turnover + p->price;
			profit = profit + p->price - p->cost;
			flag = 1;
		}
		p = p->next;
	}
	if (flag)
		printf("\n            Ӫҵ%5dԪ\n            ӯ��%5dԪ", turnover, profit);
	else {
		system("cls");
		printf("  %d��%d��û�����ۼ�¼", x, y);
	}
}

struct order* history_build() {  //��������Ĵ��� 
	FILE* fp;
	fp = fopen("history order record.txt", "r");  //����ʷ��¼�ļ��� 
	if (fp == NULL) {
		printf("Can not open this file\n");
		exit(1);
	}
	struct order* top = NULL, * rear = NULL, * p;
	char str[100];	//����Ϊý��ת������ 
	while (fgets(str, 60, fp) != NULL) {
		p = (struct order*)malloc(sizeof(struct order));
		sscanf(str, "%d %s %d %d %d %d %s", &p->id, &p->name, &p->price, &p->cost, &p->month, &p->day,&p->order_num);
		p->next = NULL;
		if (rear == NULL)
			top = rear = p;
		else {
			rear->next = p;
			rear = p;
		}
	}
	fclose(fp);
	return top;
}

int output_list(struct order* h) {  //������ж�����¼ 
	system("cls");
	int len = 0;
	printf("    ��� ��Ʒ���� �ۼ� �ɱ�   ����\n");
	while (h) {
		printf("      %-3d %-9s%-5d%-5d%d��%d��\n", h->id, h->name, h->price, h->cost, h->month, h->day);
		len++;
		h = h->next;
	}
	return len/*������*/;
}

int check(struct order* top) {  //���������������Ƿ��з������ַ�
	char s[30], * p = s;
	int flag = 0;//����û�з������ַ� 
	scanf("%s", s);
	while (*p != '\0') {
		if (*p < '0' || *p>'9') {
			flag = 1;
			break;
		}
		p++;
	}
	while (flag) {  //���������ַ� 
		system("cls");
		p = s; flag = 0;
		printf("\n       ���벻�Ϸ�\n");
		printf("       ����������\n");
		Sleep(1);
		system("cls");
		output_list(top);
		printf("\n��������Ҫɾ���ļ�¼����ţ�\n");
		scanf("%s", s);
		while (*p != '\0') {
			if (*p < '0' || *p>'9') {
				flag = 1;
				break;
			}
			p++;
		}
	}
	p = s;
	int f = 0;
	while (*p != '\0') {  //�������ַ�ת��Ϊ�������� 
		f = f * 10 + (*p - '0');
		p++;
	}
	return f;
}

int check2(struct order* pt) {  //���confirm�е�����Ϸ���
	char s[30], * p = s;
	int flag, i = 1;
	printf("\n         ȷ��Ҫɾ���˼�¼��\n");
	printf("           1 ��      2 ��\n");
	printf("�����룺\n");
	scanf("%s", s);
	while (*p != '\0') {  //��鳤�ȺͷǷ��ַ� 
		if (i > 1) {  //���ȴ���1 �Ƿ� 
			flag = 1;
			break;
		}
		else if (!(*p == '1' || *p == '2')) {  //
			flag = 1;
			break;
		}
		i++;
		p++;
	}
	while (flag) {
		system("cls");
		printf("\n       ���벻�Ϸ�\n");
		printf("       ����������\n");
		Sleep(1);
		system("cls");
		printf("    ��� ��Ʒ���� �ۼ� �ɱ�   ����\n");
		printf("      %-3d %-9s%-5d%-5d%d��%d��\n", pt->id, pt->name, pt->price, pt->cost, pt->month, pt->day);
		printf("\n         ȷ��Ҫɾ���˼�¼��\n");
		printf("           1 ��      2 ��\n");
		printf("�����룺\n");
		scanf("%s", s);
		p = s; flag = 0; i = 1;  //���� 
		while (*p != '\0') {  //��鳤�ȺͷǷ��ַ� 
			if (i > 1) {  //���ȴ���1 �Ƿ� 
				flag = 1;
				break;
			}
			else if (!(*p == '1' || *p == '2')) {  //
				flag = 1;
				break;
			}
			i++;
			p++;
		}
	}
	p = s;
	return *p - '0';
}

int judge_id(int len/*������*/, struct order* top/*����ͷָ��*/) {  //������ż��Ϸ����ж� 
	int x;
	printf("\n��������Ҫɾ���ļ�¼����ţ�\n");
	x = check(top);
	while (x<1 || x>len) {  //���벻�Ϸ� 
		system("cls");
		printf("\n    �������Ų�����\n");
		printf("       ����������\n");
		Sleep(1);
		system("cls");
		output_list(top);
		printf("\n��������Ҫɾ���ļ�¼����ţ�\n");
		x = check(top);
	}
	return x;  //����Ҫɾ������� 
}

int confirm(int x/*��Ҫɾ�������*/, struct order* pt/*��������ͷ��ָ��*/) {  //����ȷ���Ƿ�ɾ��
	system("cls");
	printf("    ��� ��Ʒ���� �ۼ� �ɱ�   ����\n");
	while (1) {  //�����Ҫɾ���ļ�¼ 
		if (x == pt->id) {
			printf("      %-3d %-9s%-5d%-5d%d��%d��\n", pt->id, pt->name, pt->price, pt->cost, pt->month, pt->day);
			break;
		}
		pt = pt->next;
	}
	int flag;
	flag = check2(pt);
	return flag;
}

void write(struct order* pt/*��������ͷ��ָ��*/) {  //������д���ļ� 
	FILE* fp;
	fp = fopen("history order record.txt", "w");  //����ʷ��¼�ļ��� 
	if (fp == NULL) {
		printf("Can not open this file\n");
		exit(1);
	}
	int i = 1;
	while (pt) {
		fprintf(fp, "%d %s %d %d %d %d %s\n", i++, pt->name, pt->price, pt->cost, pt->month, pt->day,pt->order_num);
		pt = pt->next;
	}
	fclose(fp);
}

//�鿴ĳһ����Ʒ�ļ�¼���鿴ĳ��ʱ�����м�¼���鿴ĳһ������м�¼���鿴���м�¼  �˵����
char output_check_choice_function2(){
	char ch;
	do{
		system("cls");
		printf("����������鿴��¼�ķ�ʽ��\n\n");
		printf("1 �鿴һ����Ʒ��ȫ�����ۼ�¼ \n");
		printf("2 �鿴һ��ʱ����������ۼ�¼ \n");
		printf("3 �鿴ĳ����������ۼ�¼ \n");
		printf("4 �鿴����Ŀǰ���е����ۼ�¼ \n");
		printf("0 ������һ���� \n");
		printf("\n��ѡ��");
		ch=getch(); 
	}while(ch<'0'||ch>'4');
	return ch;
}

//�����������ۼ�¼���� 
struct order* build_function2(){
	FILE *fp;
	fp=fopen("history order record.txt","r");  //����ʷ��¼�ļ��� 
	if(fp==NULL){
		printf("Can not open this file\n");
		exit(1);
	}
	struct order *top=NULL,*rear=NULL,*p;	
	char str[100];	//����Ϊý��ת������ 
	while(fgets(str,60,fp)!=NULL){
		p=(struct order*)malloc(sizeof(struct order));
		sscanf(str,"%d %s %d %d %d %d %s",&p->id,&p->name,&p->price,&p->cost,&p->month,&p->day,&p->order_num);
		p->next=NULL;
		if(rear==NULL)
			top=rear=p;
		else{
			rear->next=p;
			rear=p;
		}
	}
	fclose(fp);
	return top;
}

//�����¼ 
void output_list_function2(struct order* h){
	int i=1;
	int turnover=0/*Ӫҵ��*/,profit=0/*ӯ����*/;
	printf("    ��� ��Ʒ���� �ۼ� �ɱ�   ����        ������\n");
	while(h)
	{
		printf("      %-3d %-9s%-5d%-5d%d��%d��    %s\n",i++,h->name,h->price,h->cost,h->month,h->day,h->order_num);
		turnover=turnover+h->price;
		profit=profit+h->price-h->cost;
		h=h->next;
	}
	printf("\n\t\t\t\t\tӪҵ%dԪ",turnover);
	printf("\n\t\t\t\t\tӯ��%dԪ",profit);
	system("pause");
}
//�·ݺϷ����ж�
int judge_month_function2(int x/*���ڷֱ�case 1��case 2��ʼ��case 2����*/,int month_0,int day_0){
	char str[10],*p;
	int f;
	while(1){
		p=str;
		while(1){
			system("cls");
			if(x==3){
				printf("�鿴  ��  �յļ�¼\n"); 
				printf("\n�������·�:\n");
			}else if(x==20){
				printf("�鿴  ��  ����  ��  �յļ�¼\n");
				printf("\n������ʼ���·�:\n");
			}else{
				printf("�鿴%2d��%2d����  ��  �յļ�¼\n",month_0,day_0);
				printf("\n����������·�:\n"); 
			}
			scanf("%s",str);
			if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
			else if(*p=='1'&&*(p+1)>='0'&&*(p+1)<='2'&&*(p+2)=='\0') break;  //10~12
		}
		f=0;
		while(*p!='\0'){  //�ַ�ת��Ϊ��������
			f=f*10+(*p-'0');
			p++; 
		}
		if(x==3||x==20){
			break;
		}else if(x==21){
			if(f==month_0&&(f==1||f==3||f==5||f==7||f==8||f==10)&&day_0<=30){
				break;
			}else if(f==month_0&&(f==4||f==6||f==9||f==11)&&day_0<=29){
				break;
			}else if(f==month_0&&f==2&&day_0<=27){
				break;
			}else if(f==month_0&&f==12){
				break;
			}else if(f>month_0){
				break;
			}
		}
	}
	return f;
}
//���ںϷ����ж� 
int judge_day_function2(int x/*���ڷֱ�case 1��case 2��ʼ��case 2����*/,int month_0,int day_0,int month_1){
	char str[10],*p;
	int f;
	while(1){
		p=str;
		while(1){
			system("cls");
			if(x==3){
				printf("�鿴%2d��  �յļ�¼\n",month_0); 
				printf("\n����������:\n");
			}else if(x==20){
				printf("�鿴%2d��  ����  ��  �յļ�¼\n",month_0);
				if(month_0==12)
					printf("(ע����ʼ���ڲ���Ϊ12��31��)\n");
				printf("\n��������ʼ����:\n");
			}else{
				printf("�鿴%2d��%2d����%2d��  �յļ�¼\n",month_0,day_0,month_1);
				printf("\n�������������:\n");
			}
			scanf("%s",str);
			
			if(x==3){
				
				if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
				else if(*p>='1'&&*p<='2'&&*(p+1)>='0'&&*(p+1)<='8'&&*(p+2)=='\0') break;  //10~18��20~28
				else if(*p=='1'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //19
				 
				if(month_0==1||month_0==3||month_0==5||month_0==7||month_0==8||month_0==10||month_0==12){  //����31��
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
					else if(*p=='3'&&*(p+1)=='1'&&*(p+2)=='\0') break;  //31
				}else if(month_0==4||month_0==6||month_0==9||month_0==11){  //С��30�� 
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
				}
				
			}else if(x==20){
				
				if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
				else if(*p>='1'&&*p<='2'&&*(p+1)>='0'&&*(p+1)<='8'&&*(p+2)=='\0') break;  //10~18��20~28
				else if(*p=='1'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //19
				 
				if(month_0==1||month_0==3||month_0==5||month_0==7||month_0==8||month_0==10){  //����31��
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
					else if(*p=='3'&&*(p+1)=='1'&&*(p+2)=='\0') break;  //31
				}else if(month_0==4||month_0==6||month_0==9||month_0==11||month_0==12/*��ʼ���ڲ���Ϊ12��31��*/){  //С��30�� 
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
				}
				
			}else if(x==21){
				
				if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
				else if(*p>='1'&&*p<='2'&&*(p+1)>='0'&&*(p+1)<='8'&&*(p+2)=='\0') break;  //10~18��20~28
				else if(*p=='1'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //19
				 
				if(month_1==1||month_1==3||month_1==5||month_1==7||month_1==8||month_1==10||month_1==12){  //����31��
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
					else if(*p=='3'&&*(p+1)=='1'&&*(p+2)=='\0') break;  //31
				}else if(month_1==4||month_1==6||month_1==9||month_1==11){  //С��30�� 
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
				}
				
			}
		}
		f=0;
		while(*p!='\0'){  //�ַ�ת��Ϊ��������
			f=f*10+(*p-'0');
			p++; 
		}
		if(x==3||x==20)
			break;
		else if(month_0==month_1&&f>day_0)  //ͬ�·� 
			break;
		else if(month_0<month_1)  //��ͬ�·� 
			break;
	}
	return f;
}

/*�鿴ĳһ����Ʒ�ļ�¼*/
//�����Ʒ����
char output_drink_type_choice_function2(){
	char ch;
	do{
		system("cls");
		printf("��ѡ����Ҫ�鿴��Ӧ��¼����Ʒ��\n\n");
		printf("1 ����\n");
		printf("2 �̲�\n");
		printf("3 ����\n");
		printf("4 ����\n");
		printf("5 ����\n");
		printf("6 Ҭ��\n");
		printf("7 ţ��\n");
		printf("8 �ɿ�\n");
		printf("9 �����\n");
		printf("\n��ѡ��");
		ch=getch();
    }while(ch<'1'||ch>'9');
	return ch;
}

//ɾ���������зǴ�����Ʒ�Ĳ���
struct order* delete_case_1_function2(char ch,struct order *top){
	char temp[30];
	switch(ch){
		case '1':strcpy(temp,"����");break;
		case '2':strcpy(temp,"�̲�");break;
		case '3':strcpy(temp,"����");break;
		case '4':strcpy(temp,"����");break;
		case '5':strcpy(temp,"����");break;
		case '6':strcpy(temp,"Ҭ��");break;
		case '7':strcpy(temp,"ţ��");break;
		case '8':strcpy(temp,"�ɿ�");break;
		case '9':strcpy(temp,"�����");
	}
	struct order sentry/*�ڱ�*/,*h=top,*h0/*h��ǰ��ָ��*/;
	sentry.next=top;	
	while(h!=NULL){  //��ʷ��¼����ı���  
		if(strcmp(temp,h->name)==0){
			h0=h;
			h=h->next;
		}else{
			if(h==top){  //ɾ������ͷ
				h=h->next;
				free(sentry.next);
				sentry.next=h;
				top=h;
			}else{  //ɾ�������м䲿�� 
				h=h->next;
				free(h0->next);
				h0->next=h;
			}
		}			
	}
	return sentry.next;
}

/*�鿴һ��ʱ����������ۼ�¼*/
//ɾ���Ǵ�ʱ��εĶ�������
struct order* delete_case_2_function2(int month_0,int day_0,int month_1,int day_1,struct order* top){
	struct order sentry/*�ڱ�*/,*h=top,*h0/*h��ǰ��ָ��*/; 
	sentry.next=top;	
	while(h!=NULL){  //��ʷ��¼����ı���  
		if((h->month==month_0&&h->day<day_0)||(h->month==month_1&&h->day>day_1)||h->month<month_0||h->month>month_1){  //ɾ������ 
			if(h==top){  //ɾ������ͷ
				h=h->next;
				free(sentry.next);
				sentry.next=h;
				top=h;
			}else{  //ɾ�������м䲿�� 
				h=h->next;
				free(h0->next);
				h0->next=h;
			}
		}else{  //δ����ɾ�� 
			h0=h;
			h=h->next;
		}
	}
	return sentry.next;
}

/*�鿴ĳ����������ۼ�¼*/
//ɾ���Ǵ��յĶ�������
struct order* delete_case_3_function2(int month,int day,struct order *top){
	struct order sentry/*�ڱ�*/,*h=top,*h0/*h��ǰ��ָ��*/; 
	sentry.next=top;	
	while(h!=NULL){  //��ʷ��¼����ı���  
		if(h->month!=month||h->day!=day){  //ɾ������ 
			if(h==top){  //ɾ������ͷ
				h=h->next;
				free(sentry.next);
				sentry.next=h;
				top=h;
			}else{  //ɾ�������м䲿�� 
				h=h->next;
				free(h0->next);
				h0->next=h;
			}
		}else{  //δ����ɾ�� 
			h0=h;
			h=h->next;
		}
	}
	return sentry.next;
}

/*��������*/
void playMusic()
{
	PlaySound(TEXT("music.wav"),0,SND_FILENAME | SND_ASYNC);
}

//���ʣ�µ�ԭ�Ϸ�����
void material_fen(int drinks[][6])
{
	FILE* sp=fopen("��Ʒ.txt","r");
	if(sp==NULL)
	{
		printf("Can not open this ��Ʒ.txt file.");
		return ;
	}
	int o=0;
	char c[32];
	wchar_t name[9][20];
	while(fgets(c,32,sp)!=NULL)
	{
		sscanf(c,"%ls",name[o++]);
	}
	int ma[17];
	material head;
	head=creat();
	material p=head->next,p0=NULL;
	printf("\t\t******************************************\n");
	printf("\n");
	while (p != NULL)   //����������������id�������������ж���ʣ�����ϣ��� 
	{
		if(p->id==1||p->id==2||p->id==6)
		{
			ma[p->id-1]=p->weight/30;
			printf("\t\t\t%ls\t\t%d��\n",p->name,(p->weight/30));
		}
		if(p->id==3||p->id==4||p->id==5)
		{
			ma[p->id-1]=p->weight/50;
			printf("\t\t\t%ls\t\t%d��\n",p->name,(p->weight/50));
		}
		if(p->id==7||p->id==8||p->id==9)
		{
			ma[p->id-1]=p->weight/10;
			printf("\t\t\t%ls\t\t%d��\n",p->name,(p->weight/10));
		}
		if(p->id==10||p->id==12||p->id==14||p->id==17)
		{
			ma[p->id-1]=p->weight/20;
			printf("\t\t\t%ls\t\t%d��\n",p->name,(p->weight/20));
		}
		if(p->id==15||p->id==11)
		{
			ma[p->id-1]=p->weight/40;
			printf("\t\t\t%ls\t\t%d��\n",p->name,(p->weight/40));
		}
		if(p->id==13||p->id==16)
		{
			ma[p->id-1]=p->weight/10;
			printf("\t\t\t%ls\t\t%d��\n",p->name,(p->weight/10));
		}
		p0 = p;
		p = p->next;
	}
	printf("\n");
	printf("\t\t******************************************\n");
	printf("\n");
	printf("\n");
	printf("\t\t******************************************\n");
	printf("\n");
	for(int i=0;i<9;i++)
	{
		printf("\t\t\t%lsʣ��ɹ������Ʒ��: ",name[i]);
		compare(i,drinks,ma);
	}
	printf("\n");
	printf("\t\t******************************************\n");
}

//�ȽϺ����� 
void compare(int i,int drink[][6],int ma[])
{
	int b[4]={0},p=0,o;
	for(int j=0;j<4;j++)
	{
		if(drink[i][j]!=0)
		{
			b[p++]=ma[drink[i][j]-1];
		}
	}
	for(int k=0;k<3;k++)
	{
		for(int q=k+1;q<4;q++)
		{
			if(b[k]>b[q])
			{
				o=b[k];
				b[k]=b[q];
				b[q]=o;
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		if(b[i]!=0)
		{
			printf("%d��\n",b[i]);
			break;
		}
	}
	return ;
}
