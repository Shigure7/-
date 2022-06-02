#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h> 
#include<stdlib.h> 
#include<conio.h>
#include<time.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")



/*定义结构体*/
//定义饮品（配料）结构体 
typedef struct drink
{
	char name[30];           //名字 
	int price;               //价格 
	struct drink* next;
}drink;


//定义顾客点单结构体 
typedef struct drink_order
{
	char drink_name[10];           //饮品名字
	char ingredient_name[2][10];   //原料名字
	int temperature;               //饮品温度
	int sweetness;                 //饮品甜度 
	int money;                     //饮品价格 
	struct drink_order* next;
}drink_order;

drink_order* o_head = NULL;   //顾客订单头指针
drink_order* o_end = NULL;    //顾客订单尾指针 

//定义顾客会员信息
typedef struct vip
{
	int num;                 //会员编号
	char name[30];           //会员姓名 
	char phone[20];          //会员手机号
	long int money;          //消费金额
	struct vip* next;
}vip;

//定义礼品信息
struct gift
{
	int num;               //礼品编号
	char name[30];         //礼品名字
	int score;            //礼品所需积分
	int stock;           //礼品库存数量
	struct gift* next;
};

vip* v_head = NULL;   //会员头指针
vip* v_end = NULL;    //会员尾指针
vip* v_user = NULL;   //指向会员

gift* g_head;//礼品头指针
gift* g_end;//礼品尾指针
gift* g_user;//指向礼品

//储存每杯的序号 
struct id
{
	int id1;
	int id2;
	int id3;
}idi[9];

//存储原料损耗后的数据；
struct Using_Id {
	int id;   //原料的id
	wchar_t name[20];    //原料的名字 
	int weight;   //原料重量 
}bridge[17];    //以bridge来命名过渡结构体 


//定义关于原料链表 
typedef struct drink_material   //产品原料 
{
	int id;
	int weight;
	wchar_t name[20];
	int purchasing_price;   //进价
	struct drink_material* next;
}Drink_Material;  //将drink_material命名为Drink_Material; 
typedef Drink_Material* material;   //将Drink_Material*命名为material;

//构建购买原料的链表 
typedef struct buy
{
	int id;     //原料的编号； 
	wchar_t name[20];     //原料的名字 ； 
	int weight;     //质量 ； 
	struct buy* next;
}buy_materials;    //将buy链表命名为buy_materials ； 

typedef buy_materials* Buy;     //将nuy_materials*类型命名为Buy；

typedef struct best_drink
{
	int week,month,quater,year;   //分别表示日度，月度，季度，年度的销售量
	struct best_drink* next; 
}best_drink;

best_drink* b_head=NULL;   //最佳饮品头指针 


//关于购买原料的结构体；
struct buy_weights
{
	int buy_id;   //购买原料的序号；
	int BUY_weight;   //购买原料的重量； 
}weights[17];

//订单记录结构体 
struct order{  //订单记录结构体 
	int id;  //序号 
	char name[30];  //商品名称
	int price;  //售价 
	int cost;  //成本 
	int month;  //月
	int day;  //日
	char order_num[30];  //订单号 
	struct order *next;
};

typedef struct order_now{  //订单记录结构体 
	int id;  //序号 
	char name[30];  //商品名称
	int price;  //售价 
	int cost;  //成本 
	int month;  //月
	int day;  //日
	char order_num[30];  //订单号 
	struct order_now *next;
}Order_Now;
typedef Order_Now* Order_now;

/*定义全局变量*/
struct drink list1[30]; //存放饮品信息
int num1 = 0; //存放饮品数量
int* p1 = &num1;
struct drink list2[30]; //存放配料信息
int num2 = 0; //存放配料数量
int* p2 = &num2;
struct drink_order list3[30]; //存放顾客点饮料信息
int num3 = 0; //存放顾客点饮料数量
int* p3 = &num3;
int num4 = 0; //存放今日所点饮料总数量
int* p4 = &num4;
int day = 0;  //储存日期 
int* p5 = &day;
int mon = 0;  //储存月份
int* p6 = &mon;
//饮品对应原料的消耗；
int drinks[10][6] ;
//饮品的成本；
int cost[9] = { 3,4,5,3,5,4,3,6,5 };
//原料警戒线；
int guard[17]={1000,500,1000,1250,1250,500,500,250,250,250,250,250,750,250,500,250,500} ;


/*菜单部分*/
//选项一
void function1();
//选项二
void function2();
//选项三
void function3();
//功能四
void function4();
//功能五
void function5();



/*功能部分*/
//欢迎菜单
void main_menu1(void);
//显示主菜单 
void main_menu2(void);
//实现点饮料的函数（将点饮料的结构体写入数据）
void ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int i, struct id idi[]);
//实现点配料的函数（将点配料的结构体写入数据） 
void ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int i, int n, struct id idi[]);
//实现点温度和甜度的函数（将点温度和甜度的结构体写入数据）
void ordering3(struct drink_order list3[], int num3, int i);
//打印顾客所点饮料信息
int print_order(struct drink_order list3[], int num3,bool flag);


/*函数部分*/
//创建程序运行所需的txt文件
void create_file(void);
//加载饮品及配料信息到结构体数组（读取txt写入到当个结构体中数组中）
void load_drink(struct drink list1[], int* p1, struct drink list2[], int* p2);
//读取txt写入到单个结构体数组中
int function_read(struct drink list[], FILE* fp);
//实现饮品的结构体数组写入数据
void function_ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int choice, int i);
//实现原料的结构体数组写入数据
void function_ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int choice, int i, int n);
//输出饮品菜单（包括提示输入语句）
void output_1(struct drink list[], int num);
//输出配料菜单（包括提示输入语句）
void output_2(struct drink list[], int num);
//将结构体输入链表（）
drink_order* input_order(struct drink_order list3[], int num3);
//储存最佳饮品 
best_drink* input_best_drink(struct drink_order list3[],int num3);
//返回编号
int Return_num();
//将单日销售记录存入文件
void save_order_file(drink_order* head);
//读取密码位数 
int password_num(); 
//实现输入密码并验证的函数
bool Input_code();
//从文件中读取系统密码
char* Read_password();
//修改文件中的密码（如修改成功则返回为bool型）
bool Change_password();
//实现输出日期的函数
void print_time(int* p5, int* p6);
//修改订单 
void modify_order(struct drink_order list3[],int num3,bool flag,struct id idi[]);
//返回编号
int Return_defaultnum();
//记录未点单成功的饮料
void save_default_order(struct drink_order list3[], int num3); 
//记录点单成功的饮料
void save_success_order(struct drink_order list3[], int num3); 
//仅打印顾客所点饮料信息
void print_order1(struct drink_order list3[], int num3);
//从文件中读取日度、周度、月度、季度、年度最佳饮品存入链表
best_drink* read_best_drink();
//将时间存入数组
void input_time(int a[]);
//定时刷新最佳饮品文件
void refresh_best_drink(best_drink* head);
//从文件读取上次修改日期并返回
int *read_modify_time();
//将顾客点单存入最佳饮品中
void save_best_drink(struct drink_order list3[],int num3,best_drink* head);
//返回最佳饮品序号以及返回链节
int* return_best_num(best_drink* head,char ch);
//显示最佳饮品
void show_best_drink(best_drink* head,struct drink list2[]); 
//显示日志
void show_log(); 


//判断顾客是否为VIP
bool If_vip();
//会员文件写入
void save_vip();
//从文件中加载会员信息到链表
vip* load_vip();
//会员登录
int login_vip();
//登录结果反馈
int login_out();
//返回会员编号
int Return_vipnum(); 
//添加新会员信息
vip* add_vip();
//查看会员信息
bool observe_vip(char a);
//查询功能扩展
bool obpro_vip(char a);
//修改会员信息
void modify_vip();
//删除会员信息
void delete_vip();
//会员界面
void user_vip();
//礼品信息加载
gift* load_gift();
//礼品信息存储
void save_gift();
//会员积分兑换界面
void exchange_gift();
//抽奖界面
int roll(int i);
//查看礼品兑换记录
void history_gift();



//实现原料的初始化以及重置
void data_refresh();
//关于原料链表的创建
material creat();
//实现原料的消耗
material  material_delete(material head, int num1, struct id q[]);
//实现原料数据的储存
void material_file(material head);
//实现剩余原料的显示输出
void material_print(struct Using_Id bridge[]);
//购买原料所利用的总函数
void purchase();
//实现购买的函数 
void buy_material();
//购买原料的链表创建； 
Buy buy_creat();
//本函数用于购置原料；
Buy buy_add(Buy head, struct buy_weights weights[]);
//将购买原料里链表的数据录入文件中
void buy_material_file(Buy head);
//本函数用于录入需要购买的原料种数并美化
int output_3();
//购买原料的时间的储存； 
void print_time2(int a[]);
//打开购买记录的文件；
void open_history_file();
//金额计算
void sum_money();
//金额存入文件
void save_money_file(int our_money); 
//将文件中的数据存入drinks[][]之中；
void read_material_al(int drinks[][6]); 
//原料警戒线； 
void judge_material(int guard[],struct Using_Id bridge[]);
//判断现在原料与警戒线的差距；
int judge_now_material(material head,int guard[],struct Using_Id bridge[]); 
//计算月、季利润；
void calculate_profit(Order_now h);
//创建原料链表； 
Order_now build_file_now();
//输出剩下的原料份数；
void material_fen(int drinks[][6]);
//比较函数； 
void compare(int i,int drink[][6],int ma[]);


//订单链表的创建 
struct order* build();
//输入月份 
int input_month();
//输入日期
int input_day();
//检索并输出某月某日订单记录 
void output_order_list(struct order* p, int x/*月*/, int y/*日*/);
//订单链表的创建 
struct order* history_build();
//输出所有订单记录
int output_list(struct order* h);
//检查输入链表序号是否有非数字字符
int check(struct order* top);
//检查confirm中的输入合法性
int check2(struct order* pt);
//输入序号及合法性判断 
int judge_id(int len/*链表长度*/, struct order* top/*链表头指针*/);
//最终确定是否删除
int confirm(int x/*所要删除的序号*/, struct order* pt/*接受链表头的指针*/);
//密码的验证；
int password();
//删除指定序号的记录 
struct order* Delete(struct order* top, int x/*指定的序号*/);
//新链表写入文件
void write(struct order* pt/*接收链表头的指针*/);
//查看某一类饮品的记录、查看某段时间所有记录、查看某一天的所有记录、查看所有记录  菜单输出
char output_check_choice_function2();
//建立所有销售记录链表 
struct order* build_function2();
//输出记录 
void output_list_function2(struct order*);
//月份合法性判断
int judge_month_function2(int,int,int);
//日期合法性判断 
int judge_day_function2(int,int,int,int); 
/*case 1:查看一种饮品的全部销售记录*/
//输出饮品种类选择菜单 
char output_drink_type_choice_function2();
//删除总链表中非此类饮品的部分
struct order* delete_case_1_function2(char,struct order*);
/*case 2:查看一段时间的所有销售记录*/
//输出时间段选择菜单
struct order* output_time_quantum_choice_function2(struct order*);
//删除非此时间段的订单部分
struct order* delete_case_2_function2(int,int,int,int,struct order*); 
/*case 3:查看某天的所有销售记录*/
//选择时间
struct order* select_time_function2(struct order *);
//删除非此日的订单部分
struct order* delete_case_3_function2(int,int,struct order *);
/*播放音乐*/
void playMusic();

int main()
{
diandan: 
	v_head = load_vip();
	g_head = load_gift();
	int choice;
	char a;     //a表示开始的第二次选择 
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
			printf("   \t\t进入点餐系统中");
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
			printf("   \t\t正在进入管理员系统");
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
			printf("  \t\t您的输入有问题，请重新输入:"); 
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
		if (a >= '0' && a <= '4')     //操作规范 
		{
			switch (a)
			{
			case '1':     	//功能：查看原料库存以及购入原料。 
				printf("   \t\t进入库存系统中");
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
			//功能：查看进货信息、顾客信息、余额信息，查看所有订单记录以及某日营业额与盈利额记录、修改删除顾客信息
				printf("   \t\t进入查询系统中");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				function3();
				break;
			case '3':      //功能：删除部分历史记录（仅管理员能操作此部分）。
				printf("   \t\t进入删除系统中");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				function4();
				getchar();
				break;
			case '4':       
				printf("   \t\t进入密码修改系统中");
				for (int t = 0; t < 5; t++)
				{
					printf("~");
					Sleep(200);
				}
				function5();
				getchar();
				break;
			case '0':        //功能：退出系统。  
				printf("   \t\t退出系统中");
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
		else      //操作不规范 
		{
			system("cls");
			printf("  \t\t您的操作不符合规范哟！(＾Ｕ＾)ノ~ＹＯ\n");
			printf("  \t\t请返回上一界面：");
			system("pause");
			continue;
		}
	}
	return 0;
}

/*菜单部分*/
//选项一
void function1()
{
	vip* p;
	bool flag;
	flag=If_vip();       //判断顾客是否为VIP
	if (flag == true) {
		int result = login_out();
		if (result == 0) {
			// 用户取消返回主菜单
			return;
		}
		else {
			p = v_user;
		}
	}
	else 
	{ 
		system("cls");
		printf("\t\t 请问您是否要成为会员？\n");
		printf("\t\t     1、是\n");
		printf("\t\t     2、否\n");
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
				printf("\t\t  您的输入有问题，请重新输入:\n");
			}
		}	
	}
	system("cls");
	material_fen(drinks);
	system("pause");
dianbeishu:		
	system("cls");
	int n;    //储存顾客顾客每杯配料数
	char b;   //b暂存顾客所选杯数 
	printf("\t\t*******************************************************************\n");
	printf("\t\t                   请输入您要点的杯数:                             \n");
	while(1)
	{
		b = getch();
		if (b>='1'&&b<='9')
		{
			break;
		}
		else
		{
			printf("\t\t输入有问题，请您重新输入!");
			Sleep(2000); 
			system("cls");
			printf("\t\t*******************************************************************\n");
			printf("\t\t                   请输入您要点的杯数:                             \n");
		}
	}
	printf("\t\t                          %c杯\n", b);
	printf("\t\t*******************************************************************\n");
	Sleep(500); 
	printf("\n\t\t\t请问您是否确定点%c杯",b);
	printf("\n\t\t\t      1、是；");
	printf("\n\t\t\t      2、否；\n");
	char a;
	while(1)
	{
		a=getch();
		if(a=='1')
		{
			printf("\t\t\t\t       是!\n");
			Sleep(1000);
			break; 
		} 
		else if (a=='2')
		{
			printf("\t\t\t\t        否!\n");
			Sleep(1000);
			goto dianbeishu;
		}
		else
		{
			printf("\t\t  您的输入有误，请重新输入：\n"); 
		}
	}
	num3 = b - '0';
	material mat1, mat2; 		 //定义material类型的mat1和mat2
	mat1 = creat(); 		 //关于原料的链表创建 
	for (int i = 0; i < num3; i++)
	{
		n = 0;
		ordering1(list1, num1, list3, p3, i ,idi);      //点饮料
		ordering2(list2, num2, list3, p3, i, n, idi);   //点配料
		ordering3(list3, num3, i);                 //点甜度和温度	
	}
	print_order1(list3,num3);
	printf("\n\t\t请问您是否确定点单");
	printf("\n\t\t      1、是；");
	printf("\n\t\t      2、否；\n");
	printf("\t\t");
	while(1)
	{
		a=getch();
		if(a=='1')
		{
			printf("        是!\n");
			break;
		} 
		else if (a=='2')
		{
			printf("        否!\n");
			printf("\n\t\t请输入您想要进行的操作：\n"); 
			printf("\t\t     1、重新点单；\n");
			printf("\t\t     2、修改订单；\n"); 
			printf("\t\t     0、取消操作；\n"); 
			char ch;
			while(1)
			{
				ch=getch();
				if (ch=='1')
				{
					printf("\t\t正在返回点单界面，请稍等");
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
			printf("\t\t  您的输入有误，请重新输入：\n"); 
		}
	}
	mat2 = material_delete(mat1, num1, idi);
	material_file(mat2);  //原料的储存 
	if(p!=NULL)
	{
	p->money += print_order(list3, num3,flag);    //打印顾客订单
	system("pause");
	save_vip();
    } 
    else print_order(list3, num3,flag);
    system("pause");
	drink_order* list4;
	list4 = input_order(list3, num3);
	save_success_order(list3, num3);    //冲账 
	save_best_drink(list3,num3,b_head);
	save_order_file(list4);  //顾客订单存入今日订单
}

//功能二 
void function2()
{
	system("cls");
	material_print(bridge);
	purchase();
	system("cls");
	material_print(bridge);
	system("pause");
}

//功能三 
void function3()
{
chakan:
	system("cls");
	char ch,ch1,ch2;
	printf("\t\t\t\t请输入您想查看的部分：\n");
	printf("\t\t\t\t 1、订单；\n");
	printf("\t\t\t\t 2、库存；\n");
	printf("\t\t\t\t 3、顾客；\n");
	printf("\t\t\t\t 4、金额；\n"); 
	printf("\t\t\t\t 5、最佳饮品；\n");
	printf("\t\t\t\t 6、日志；\n");
	printf("\t\t\t\t 0、返回主菜单\n");
	while(1)
	{
		ch=getch();
		if (ch=='1')
		{
			printf("\t\t\t\t 正在进入订单系统");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			struct order *head;
			char ch;
			char ch_2;  //case 1
			int month_0/*起始月*/,day_0/*起始日*/,month_1/*截至月*/,day_1/*截至日*/;  //case 2
			int month/*月份*/,day/*日期*/;  //case 3
			head=build_function2();
			ch=output_check_choice_function2();
			switch(ch){
				case '1':ch_2=output_drink_type_choice_function2();
						 head=delete_case_1_function2(ch_2,head);
						 break;
				case '2':month_0=judge_month_function2(20,0,0);  //起始月份输入
						 day_0=judge_day_function2(20,month_0,0,0);  //起始日期输入	  
						 month_1=judge_month_function2(21,month_0,day_0);  //截至月份输入 
						 day_1=judge_day_function2(21,month_0,day_0,month_1);  //截至日期输入 
						 head=delete_case_2_function2(month_0,day_0,month_1,day_1,head);
						 break;
				case '3':month=judge_month_function2(3,0,0);  //月份输入
						 day=judge_day_function2(3,month,0,0);  //日期输入 
						 head=delete_case_3_function2(month,day,head);
						 break;
				case '0':goto chakan;
			}
			system("cls");
			if(ch=='1'){
				switch(ch_2){
					case '1':printf("\t\t  果茶的全部销售记录\n\n");break;
					case '2':printf("\t\t  奶茶的全部销售记录\n\n");break;
					case '3':printf("\t\t  酸奶的全部销售记录\n\n");break;
					case '4':printf("\t\t  奶绿的全部销售记录\n\n");break;
					case '5':printf("\t\t  咖啡的全部销售记录\n\n");break;
					case '6':printf("\t\t  椰奶的全部销售记录\n\n");break;
					case '7':printf("\t\t  牛奶的全部销售记录\n\n");break;
					case '8':printf("\t\t  可可的全部销售记录\n\n");break;
					case '9':printf("\t\t益菌多的全部销售记录\n\n");
				}
			}else if(ch=='2'){
				printf("\t      %d月%d日至%d月%d日的销售记录\n\n",month_0,day_0,month_1,day_1); 
			}else if(ch=='3'){
				printf("\t\t  %d月%d日的销售记录\n\n",month,day);
			}else{
				printf("\t\t    全部销售记录\n\n");
			}
			if(head!=NULL){
				output_list_function2(head);
			}else{
				printf("\t\t    没有销售记录\n");
				system("pause");
			}
			goto chakan;
		} 
		else if (ch=='2')
		{
			printf("\t\t\t\t 正在进入库存系统");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			printf("\t\t\t\t 请选择您要查看的部分：\n");
			printf("\t\t\t\t     1、库存信息；\n");
			printf("\t\t\t\t     2、原料购买记录；\n");
			printf("\t\t\t\t     0、返回上一界面；\n"); 
			char c;
			while(1)
			{
				c=getch();
				if (c=='1')
				{
					printf("\t\t\t\t      请稍等");
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
					printf("\t\t\t\t      请稍等");
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
					printf("\t\t\t\t 返回上一界面");
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
			printf("\t\t\t\t 正在进入顾客系统");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			} 
			system("cls");
			printf("\t\t\t\t请输入您想要进行的操作：\n");
			printf("\t\t\t\t 1、查询会员信息；\n");
			printf("\t\t\t\t 2、修改会员信息；\n");
			printf("\t\t\t\t 3、删除会员信息；\n");
			printf("\t\t\t\t 4、礼品兑换历史记录；\n");
			printf("\t\t\t\t 0、返回上一界面\n");
			ch1 = getch();
			while(1)
			{ 
				if (ch1=='1')
				{
					printf("\t\t\t\t进入查询会员系统");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					printf("\t\t\t\t 1、查看所有会员信息；\n");
					printf("\t\t\t\t 2、查看特定会员信息；\n");
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
							printf("\t\t\t\t您的输入有误，请重新输入:\n");
						}
					}
					system("pause");
					system("cls");
					goto chakan;
				}
				else if (ch1=='2')
				{
					printf("\t\t\t\t进入修改系统");
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
					printf("\t\t\t\t 进入删除系统");
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
					printf("\t\t\t\t 进入礼物历史查询系统");
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
					printf("\t\t\t\t 返回上一界面");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					goto chakan;
				}
				else 
				{
					printf("\t\t\t\t 您的输入有误，请重新输入：\n");
				}
			}
		}
		else if (ch=='4')
		{
			printf("\t\t\t\t 正在进入余额系统"); 
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
			printf("\t\t\t\t 正在进入最佳饮品系统");
			for (int k=0;k<5;k++)
			{
				printf("~");
				Sleep(200);
			}
			int num[2]; 
			int* p;
			system("cls");
			printf("\t\t\t\t请输入您要查询最佳饮品的方式：\n");
			printf("\t\t\t\t     1、周度；\n");
			printf("\t\t\t\t     2、月度；\n");
			printf("\t\t\t\t     3、季度；\n");
			printf("\t\t\t\t     4、年度；\n");
			printf("\t\t\t\t     0、返回上一界面；\n");
			char a;
			while(1)
			{
				a=getch();
				if (a=='1')
				{
					printf("\t\t\t\t 即将为您显示周度最佳饮品，请稍等");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t 本周最佳饮品为：%s\n",list1[num[1]].name);
					printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='2')
				{
					printf("\t\t\t\t   即将为您显示月度最佳饮品，请稍等");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t 本月最佳饮品为：%s\n",list1[num[1]].name);
					printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='3')
				{
					printf("\t\t\t\t   即将为您显示季度最佳饮品，请稍等");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t 本季最佳饮品为：%s\n",list1[num[1]].name);
					printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='4')
				{
					printf("\t\t\t\t   即将为您显示年度最佳饮品，请稍等");
					for (int t = 0; t < 5; t++)
					{
						printf("~");
						Sleep(200);
					}
					system("cls");
					p=return_best_num(b_head,a);
					num[0]=*p;
					num[1]=*(p+1);
					printf("\t\t\t\t 本年最佳饮品为：%s \n",list1[num[1]-1].name);
					printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
					system("pause");
					goto chakan;
				}
				else if (a=='0')
				{
					printf("\t\t\t\t 返回上一界面");
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
			printf("\t\t\t\t 正在进入日志系统");
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
			printf("\t\t\t\t 您的输入有误，请重新输入:\n");
		}
	}
}

//功能四 
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
		if (flag == 1) {  //进入删除操作 
			head = Delete(head, x);
			write(head);
			system("cls");
			printf("\n      删除成功\n");
			system("pause");
			Sleep(1000);
			system("cls");
			output_list(head);
			Sleep(2000);
		}
		else {
			system("cls");
			printf("\n      终止删除\n");
		}
	}
	return;
}

//功能五 
void function5()
{
	system("cls");
	system("color 9E");
	if (password() == 0)
	{
		return;
	}
	while (Change_password());   //结束表示密码修改成功
	system("pause");
}


/*功能部分*/
//欢迎界面 
void main_menu1()
{
	int time[5];
	int n;    //操作选项 
	system("cls");
	system("color 9E");
	printf("\t\t*******************************************************************\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t**                   ※※              ※※                      **\n");
	printf("\t\t**                            ※※                               **\n");
	printf("\t\t**             ※※  欢迎来大鸟转转转饮品店!   ※※              **\n");
	printf("\t\t**            ※※                              ※※             **\n");
	printf("\t\t**              ※※welcome to Dicky Twister! ※※               **\n");
	printf("\t\t**                  ※※                 ※※                    **\n");
	printf("\t\t**                       ※※      ※※                          **\n");
	printf("\t\t**                            ※※                               **\n");
	printf("\t\t**                                                               **\n");
	printf("\t\t**                      今天日期：");
	print_time2(time);
	printf("%d月%d日",time[0],time[1]);
	printf("                      \t **\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t*******************************************************************\n");
}

void main_menu2()
{
	system("cls");
	system("color 9E");
	//输入选择的操作 
	printf("\t\t*******************************************************************\n");
	printf("\t\t**                  请选择您要进行的操作:                        **\n");
	printf("\t\t**                    1、购入原料；                              **\n");
	//功能：查看原料库存（购入原料）。 
	printf("\t\t**                    2、查询与修改信息；                        **\n");
	//功能：查看进货信息、顾客信息，修改删除顾客信息 
	printf("\t\t**                    3、删除记录；                              **\n");
	//功能：删除部分历史记录（仅管理员能操作此部分）。 
	printf("\t\t**                    4、修改密码；                              **\n");
	//功能：修改系统密码。 
	printf("\t\t**                    0、退出系统；                              **\n");
	//功能：退出系统。  
	printf("\t\t*******************************************************************\n");
}

//实现点饮料的函数（将点饮料的结构体写入数据） 
void ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int i, struct id idi[])
{
	int choice = 0;
	char a;
	system("cls");
	system("color 9E");
	printf("\t\t请选择饮品：\n");
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
			printf("\t\t输入序号有误，请重新输入：\n");
	}
}

//实现点配料的函数（将点配料的结构体写入数据） 
void ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int i, int n, struct id idi[])
{
	int choice = 0;    //n为配料数量
	char a;    //a暂存输入选项 
	system("cls");
	system("color 9E");
	printf("\t\t请选择配料：\n");
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
			printf("\t\t输入序号有误，请重新输入：\n");
	}
}

//实现点温度和甜度的函数（将点温度和甜度的结构体写入数据）
void ordering3(struct drink_order list3[], int num3, int i)
{
	system("cls");
	system("color 9E");
	char a;     //a表示顾客的选择
	printf("\t\t*******************************************************************\n");
	printf("\t\t请选择您的饮品的甜度：\n");
	printf("\t\t        1、无糖\n");
	printf("\t\t        2、少糖\n");
	printf("\t\t        3、正常\n");
	printf("\t\t您的选择：\n");
	while (1)
	{
		a = getch();
		if (a - '0' == 1)
		{
			printf("\t\t        1、无糖\n");
			list3[i].sweetness = 1;
			break;
		}
		else if (a - '0' == 2)
		{
			printf("\t\t        2、少糖\n");
			list3[i].sweetness = 2;
			break;
		}
		else if (a - '0' == 3)
		{
			printf("\t\t        3、正常\n");
			list3[i].sweetness = 3;
			break;
		}
		else
			printf("\t\t您的输入不符合规范，请重新输入:\n");
	}
	system("pause");
	printf("\t\t请选择您的饮品的温度：\n");
	printf("\t\t        1、加冰\n");
	printf("\t\t        2、常温\n");
	printf("\t\t        3、热\n");
	printf("\t\t您的选择：\n");
	while (1)
	{
		a = getch();
		if (a - '0' == 1)
		{
			printf("\t\t        1、加冰\n");
			list3[i].temperature = 1;
			break;
		}
		else if (a - '0' == 2)
		{
			printf("\t\t        2、常温\n");
			list3[i].temperature = 2;
			break;
		}
		else if (a - '0' == 3)
		{
			printf("\t\t        3、热\n");
			list3[i].temperature = 3;
			break;
		}
		else
			printf("\t\t您的输入不符合规范，请重新输入\n");
	}
	system("pause");
}

//打印顾客所点饮料信息
int print_order(struct drink_order list3[], int num3,bool flag)
{
	system("cls");
	system("color 9E");
	int sum = 0;
	printf("\t\t******************************************************************\n");
	printf("\t\t**序号\t饮料\t温度\t甜度\t配料\t\t价格\t\t**\n");
	printf("\t\t******************************************************************\n");
	for (int i = 0; i < num3; i++)
	{
		printf("\t\t** %d\t%s\t", i + 1, list3[i].drink_name);
		if (list3[i].temperature == 1)
			printf("加冰\t");
		else if (list3[i].temperature == 2)
			printf("常温\t");
		else if (list3[i].temperature == 3)
			printf("热  \t");
		if (list3[i].sweetness == 1)
			printf("无糖\t");
		else if (list3[i].sweetness == 2)
			printf("少糖\t");
		else if (list3[i].sweetness == 3)
			printf("正常\t");
		printf("%s\t%s", list3[i].ingredient_name[0], list3[i].ingredient_name[1]);
		if (flag)
			list3[i].money -= 2;
		printf("\t %d         \t**\n", list3[i].money);
		sum += list3[i].money;
	}
	printf("\t\t******************************************************************\n");
	printf("\t\t总价格为：%d\n", sum);
	return sum;
}


//密码的验证； 
int password()
{
	system("cls");
	system("color 9E");
	printf("\t\t*******************************************************************\n");
	printf("\t\t**     请你输入密码验证身份：                                    **\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t                ");
	bool flag = Input_code();      //标记输入是否错误 
	int n = 0;    //记录输入密码错误次数
	while (!flag && n < 3)      //输入错误但错误次数少于三次 
	{
		n++;
		system("cls");
		system("color 4F");
		printf("\t\t*******************************************************************\n");
		printf("\t\t                           密码错误！                              \n");
		printf("\t\t                          请重新输入:                              \n");
		printf("\t\t                     ");
		flag = Input_code();
	}
	if (n == 3)
	{
		system("cls");
		system("color 4F");
		printf("\t\t                         密码错误，强制退出");
		return 0;
	}
	system("cls");
	system("color 9E"); 
	return 1;
}

//实现删除功能 
struct order* Delete(struct order* top, int x/*指定的序号*/)
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
	struct order sentry/*哨兵*/, * h = top, * h0/*h的前继指针*/;
	sentry.next = top;
	while (h != NULL) {  //历史记录链表的遍历  
		if (x == h->id) {  //删除操作 
			if (h == top)  //删除链表头
			{ 
				fprintf(fp, "%d %s %d %d %d %d %s ", num, h->name, h->price,h->cost,h->month,h->day,h->order_num);
				fprintf(fp,"(已删除)\n"); 
				h = h->next;
				free(sentry.next);
				sentry.next = h;
			}
			else {  //删除链表中间部分 
				fprintf(fp, "%d %s %d %d %d %d %s ", num, h->name, h->price,h->cost,h->month,h->day,h->order_num);
				fprintf(fp,"(已删除)\n"); 
				h = h->next;
				free(h0->next);
				h0->next = h;
			}
			break;  //删除后立刻终止循环 
		}
		h0 = h;
		h = h->next;
	}
	return sentry.next;
}

/*函数部分*/

//创建程序运行所需的txt文件
void create_file()
{
	FILE* fp = fopen("饮料.txt", "a");
	if (fp == NULL)
		return;
	fclose(fp);
	fp = fopen("原料.txt", "a");
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

//加载饮品及配料信息到结构体数组（读取txt写入到当个结构体中数组中）
void load_drink(struct drink list1[], int* p1, struct drink list2[], int* p2)
{
	FILE* fp;
	fp = fopen("饮料.txt", "r");
	*p1 = function_read(list1, fp);
	fp = fopen("原料.txt", "r");
	*p2 = function_read(list2, fp);
	fclose(fp);
}

//读取txt写入到单个结构体数组中
int function_read(struct drink list[], FILE* fp)
{
	int line = 0, t;
	char temp, ark[30];
	int i;
	if (fp == NULL)
	{
		printf("不能打开\n");
		exit(1);
	}
	while (!feof(fp)) //检测流上的文件是否结束，如果文件结束，则返回非0值，否则返回0
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

//实现点餐的结构体数组写入数据
void function_ordering1(struct drink list1[], int num1, struct drink_order list3[], int* p3, int choice, int i)
{
	strcpy(list3[i].drink_name, list1[choice - 1].name);
	list3[i].money = list1[choice - 1].price;
}

//实现原料的结构体数组写入数据
void function_ordering2(struct drink list2[], int num2, struct drink_order list3[], int* p3, int choice, int i, int n)
{
	strcpy(list3[i].ingredient_name[n], list2[choice - 1].name);
	list3[i].money += list2[choice - 1].price;
}

//输出饮品菜单（包括提示语句）
void output_1(struct drink list1[], int num)
{
	printf("\t\t*******************************************************************\n");
	printf("\t\t**\t序号\t饮料\t\t价格\t\t\t\t **\n");
	printf("\t\t*******************************************************************\n");
	for (int i = 0; i < num; i++)
	{
		printf("\t\t**\t%d\t%s\t\t%d\t\t\t\t **\n", i + 1, list1[i].name, list1[i].price);
	}
	printf("\t\t*******************************************************************\n");
	printf("\t\t请输入序号：\n");
}

//输出配料菜单（包括提示输入语句）
void output_2(struct drink list2[], int num)
{
	printf("\t\t*******************************************************************\n");
	printf("\t\t**\t序号\t配料\t价格\t\t\t\t\t **\n");
	printf("\t\t*******************************************************************\n");
	for (int i = 0; i < num; i++)
	{
		printf("\t\t**\t%d\t%s\t\t%d\t\t\t\t **\n", i + 1, list2[i].name, list2[i].price);
	}
	printf("\t\t**\t0\t返回\t\t\t\t\t\t **\n");
	printf("\t\t*******************************************************************\n");
	printf("\t\t请输入序号：\n");
}

//将结构体输入链表（）
drink_order* input_order(struct drink_order list3[], int num3)
{
	drink_order* p0 = NULL;   //p0为哨兵 
	drink_order* p;          //链表尾 
	drink_order* head;        //头结点
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

//返回编号
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

//将单日销售记录存入文件
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

//实现输入密码并验证的函数 
bool Input_code()
{
	printf("\t\t");
	char ch[20], t = 0;    //t为计数器
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

//读取密码位数 
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

//从文件中读取系统密码
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

//修改文件中的密码
bool Change_password()
{
	xiugaimima:
	system("cls");
	system("color 9E");
	printf("\t\t*******************************************************************\n"); 	
	printf("\t\t 请输入修改后的密码：\n"); 	
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
	printf("\t\t请您再次输入密码确认：\n");
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
		return true; //true表示密码修改失败 	
	}
	rewind(fp);
	fprintf(fp, "%s", newcode); 	
	fclose(fp); 	
	system("cls");
	printf("\t\t*******************************************************************\n"); 		
	printf("\t\t恭喜您,密码修改成功!\n"); 	
	printf("\t\t新密码为：\n"); 	
	printf("\t\t %s\n", newcode);
	printf("\t\t*******************************************************************\n"); 	
	return false; //false表示密码修改成功
}


//修改订单 
void modify_order(struct drink_order list3[],int num3,bool flag,struct id idi[])
{
chongxinxuanze:	
	system("cls");
	print_order1(list3,num3); 
	int n=0,temp;
	char a,b,c,num='0';
	printf("\n\t\t\t请输入您要修改的杯数：\n\t\t\t\t");
	while(1)
	{
		num=getch();
		if (num<='0'||num>num3+'0')
		{
			printf("\n\t\t\t 您的输入有问题，请重新输入:\n\t\t\t\t");
		}
		else
		{
			printf(" %c杯\n",num);
			break;
		}
	}
	printf("\t\t\t 是否确认修改%c杯\n",num);
	printf("\t\t\t     1、是；\n");
	printf("\t\t\t     2、否；\n");
	while(1)
	{
		c=getch();
		if (c=='1')
		{
			printf("\t\t\t       是；\n");
			Sleep(1000);
			break; 
		}
		else if (c=='2')
		{
			printf("\t\t\t       否；\n");
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
	printf("\n\t\t\t请输入您想要修改的订单序号:\n");
		while(1)
		{
			a=getch();
			if (a>='1'&&a<=num3+'0')
			{
				printf("\t\t\t确定修改第%c号订单吗\n",a);
				printf("\t\t\t   1、确定；\n");
				printf("\t\t\t   2、重新选择；\n");
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
						printf("\t\t\t您的输入不规范，请重新输入：\n");
					}
				}
				break; 
			}
			else
			{
				printf("\t\t\t您的输入不规范,请重新输入:\n");
			}
		}
	}
}

//返回编号
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

//记录未点单成功的饮料
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
		fprintf(fp,"(未完成)\n"); 
		num++;
	}
	fclose(fp);
}

//记录点单成功的饮料
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
		fprintf(fp,"(完成)\n"); 
		num++;
	}
	fclose(fp);
}

//仅打印顾客所点饮料信息
void print_order1(struct drink_order list3[], int num3)
{
	system("cls");
	printf("\t\t******************************************************************\n");
	printf("\t\t**序号\t饮料\t温度\t甜度\t配料\t\t价格\t\t**\n");
	printf("\t\t******************************************************************\n");
	for (int i = 0; i < num3; i++)
	{
		printf("\t\t** %d\t%s\t", i + 1, list3[i].drink_name);
		if (list3[i].temperature == 1)
			printf("加冰\t");
		else if (list3[i].temperature == 2)
			printf("常温\t");
		else if (list3[i].temperature == 3)
			printf("热  \t");
		if (list3[i].sweetness == 1)
			printf("无糖\t");
		else if (list3[i].sweetness == 2)
			printf("少糖\t");
		else if (list3[i].sweetness == 3)
			printf("正常\t");
		printf("%s\t%s", list3[i].ingredient_name[0], list3[i].ingredient_name[1]);
		printf("\t %d         \t**\n", list3[i].money-2);
	}
	printf("\t\t******************************************************************\n");
} 


//从文件中读取日度、周度、月度、季度、年度最佳饮品存入链表
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
	best_drink* p0=NULL;  //哨兵节点
	best_drink* p;       //链表尾
	best_drink* head;    //头节点
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

//将时间存入数组
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

//定时刷新最佳饮品文件
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

//从文件读取上次修改日期并返回
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

//将顾客点单存入最佳饮品中
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

//返回最佳饮品序号以及返回链节
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

//显示最佳饮品
void show_best_drink(best_drink* head,struct drink list1[])
{
	int num[2]; 
	int* p;
	system("cls");
	printf("\t\t\t\t请输入您要查询最佳饮品的方式：\n");
	printf("\t\t\t\t     1、周度；\n");
	printf("\t\t\t\t     2、月度；\n");
	printf("\t\t\t\t     3、季度；\n");
	printf("\t\t\t\t     4、年度；\n");
	printf("\t\t\t\t     0、取消；\n");
	char a;
	while(1)
	{
		a=getch();
		if (a=='1')
		{
			printf("\t\t\t\t 即将为您显示周度最佳饮品，请稍等");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*p+1;
			printf("\t\t\t\t 本周最佳饮品为：%ls\n",list1[num[1]].name);
			printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
		}
		else if (a=='2')
		{
			printf("\t\t\t\t   即将为您显示月度最佳饮品，请稍等");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*p+1;
			printf("\t\t\t\t 本月最佳饮品为：%ls\n",list1[num[1]].name);
			printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
		}
		else if (a=='3')
		{
			printf("\t\t\t\t   即将为您显示季度最佳饮品，请稍等");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*p+1;
			printf("\t\t\t\t 本季最佳饮品为：%ls\n",list1[num[1]].name);
			printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
		}
		else if (a=='4')
		{
			printf("\t\t\t\t   即将为您显示年度最佳饮品，请稍等");
			for (int t = 0; t < 5; t++)
			{
				printf("~");
				Sleep(200);
			}
			system("cls");
			p=return_best_num(head,a);
			num[0]=*p;
			num[1]=*(p+1);
			printf("\t\t\t\t 本年最佳饮品为：%ls\n",list1[num[1]-1].name);
			printf("\t\t\t\t   共售出 %d 杯\n",num[0]);
		}
		else if (a=='0')
		{
			return;
		}
	}
} 

//显示日志
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


//判断顾客是否为VIP 
bool If_vip()
{
	printf("\t\t\t*******************************************************************\n");
	bool flag;
	char a;
	while (1)
	{
		system("cls");
		printf("\t\t请问您是否为VIP：\n");
		printf("\t\t  1、是；\n");
		printf("\t\t  2、不是；\n");
		printf("\t\t  3、忘记是否为会员；\n"); 
		a = _getch();
		if (a >= '1' && a <= '3')
		{
			switch (a)
			{
			case '1':
				printf("\t\t\t是\n");
				printf("\t\t  ");
				Sleep(700);
				return true;
			case '2':
				printf("\t\t\t否\n");
				printf("\t\t  ");
				Sleep(700);
				return false;
			case '3':
				printf("\t\t\t忘记是否为会员\n");
				printf("\t\t  ");
				Sleep(700);
				flag = observe_vip('2');
				system("pause");
				return flag;
			}
		}
		else
		{
			printf("\t\t您的输入不符合规范，返回上一界面");
			getchar();
		}
	}

}

//文件写入
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

//从文件中加载会员信息到链表
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

//返回编号
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

//添加新会员信息
vip* add_vip()
{
	int n, num=Return_vipnum()+1, money=0;
	char name[30], phone[20];
	vip* p = v_end;
		system("cls");
		vip* t = (vip*)malloc(sizeof(vip));
		printf("\t\t请输入顾客的姓名：\n\t\t   ");
		scanf("%s", name);
		printf("\t\t请输入顾客的手机号：\n\t\t   ");
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

//会员登录
int login_vip()
{
	vip* p = v_head->next;
	bool flag = false;
	char name[30], phone[20];
	system("cls");
	printf("\t\t\t请输入会员的姓名，输入q返回主菜单：\n");
	printf("\t\t\t  "); 
	scanf("%s", name);
	// 如果输入是q就返回主菜单
	if (strcmp(name, "q") == 0)
	{
		return -1;
	}
	printf("\t\t\t请输入会员的手机号，输入q返回主菜单：\n");
	printf("\t\t\t  "); 
	scanf("%s", phone);
	// 如果输入是q就返回主菜单
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

//登录结果反馈
int login_out()
{
	int flag = login_vip();
	while (flag == 0)
	{
		system("cls");
		printf("\t姓名或手机号码错误，请重试!\n");
		flag = login_vip();
	}
	if (flag == -1) {
		// 返回主菜单
		return 0;
	}
	if (flag == 1)
	{
		system("cls");
		printf("\t\t\t\t欢迎您，尊敬的金鸟会员！\n");
		user_vip();
		return 1;
	}
	return 0;
}

//查看会员信息
bool observe_vip(char ch)
{
	vip* p = v_head->next;
	system("cls");
	if (p == NULL)
	{
		system("cls");
		printf("  \t\t无会员信息！(＾Ｕ＾)ノ~ＹＯ\n");
		return false;
	}
	else
	{
		if (ch == '1') //打印全部会员信息
		{
			printf("\t\t*******************************************************************\n");
			printf("\t\t**会员编号\t会员姓名\t手机号码\t消费金额\t **\n");
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
		if (ch == '2')//打印特定会员信息
		{
			bool flag;
			char a;
			printf("\t请选择查询方式：\n");
			printf("\t 1、通过会员编号查询；\n");
			printf("\t 2、通过会员姓名查询；\n");
			printf("\t 3、通过手机号码查询；\n");
			a = _getch();
			if (a >= '1' && a <= '3')
			{
				system("cls");
				flag = obpro_vip(a);
				return flag;
			}
			else
			{
				printf("\t您的输入有误，请重新输入:\n");
			}
		}
	}
}

//查询功能扩展
bool obpro_vip(char a)
{
	vip* p = v_head->next;
	int num;
	char phone[20], name[10];
	if (a == '1')
	{
		printf("\t请输入会员编号：\n");
		printf("\t  ");
		scanf("%d", &num);
		while (p != NULL)
		{
			if (num == p->num)
			{
				printf("\t\t*******************************************************************\n");
				printf("\t\t**会员编号\t会员姓名\t手机号码\t消费金额\t **\n");
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
		printf("无会员信息！(＾Ｕ＾)ノ~ＹＯ\n");
		return false;
	}
	if (a == '2')
	{
		int i = 0;
		printf("\t\t\t请输入会员姓名：\n");
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
			printf("无会员信息！(＾Ｕ＾)ノ~ＹＯ\n");
			return false;
		}
		else
		{
			system("cls");
			printf("\t\t*******************************************************************\n");
			printf("\t\t**会员编号\t会员姓名\t手机号码\t消费金额\t **\n");
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
		printf("\t\t\t请输入手机号码：\n");
		printf("\t\t\t  ");
		scanf("%s", phone);
		while (p != NULL)
		{
			if (strcmp(phone, p->phone) == 0)
			{
				printf("\t\t*******************************************************************\n");
				printf("\t\t**会员编号\t会员姓名\t手机号码\t消费金额\t **\n");
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
		printf("无会员信息！(＾Ｕ＾)ノ~ＹＯ\n");
		return false;
	}
}

//修改会员信息
void modify_vip()
{
	int num;
	int money;
	char e='8'; 
	char name[30], phone[20];
	vip* p = v_head, * q = p->next;
	printf("\t\t*******************************************************************\n");
	printf("\t\t                  请输入要修改的会员编号:");
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
				printf("\t\t**                  请选择您要修改的信息:                        **\n");
				printf("\t\t**                    1、会员名；                                **\n");
				printf("\t\t**                    2、手机号码；                              **\n");
				printf("\t\t**                    3、会员积分；                              **\n");
				printf("\t\t**                    0、退出系统；                              **\n");
				printf("\t\t*******************************************************************\n");
				e=getch();
				if (e >= '0' && e <= '3')
				{
					switch (e)
					{
					case '1':
						system("cls");
						printf("修改前会员姓名:%s\n", q->name);
						printf("修改后会员姓名:");
						scanf("%s", name);
						strcpy(q->name, name);
						printf("\n修改成功");
						system("pause");
						break;
					case '2':
						system("cls");
						printf("修改前手机号码:%s\n", q->phone);
						printf("修改后手机号码:");
						scanf("%s", phone);
						strcpy(q->phone, phone);
						printf("\n修改成功");
						system("pause");
						break;
					case '3':
						system("cls");
						printf("修改前会员积分:%d\n", q->money);
						printf("修改后会员积分:");
						scanf("%d", &money);
						q->money = money;
						printf("\n修改成功!");
						system("pause");
						break;
					case '0':
						break;
					}
				}
				else
				{
					system("cls");
					printf("您的操作不符合规范哟！(＾Ｕ＾)ノ~ＹＯ\n");
					printf("即将返回上一界面\n");
					system("pause");
					continue;
				}
			}
		}
		q = q->next;
	}
	save_vip();
}
//删除会员信息
void delete_vip()
{
	int num;
	vip* p = v_head, *q = p->next;
	bool t=observe_vip(1);
	printf("若不想删除请按0返回\n");
	printf("请输入想要删除的编号：");
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
				printf("删除成功!\n");
			}
			q = q->next;
			p = p->next;
		}
	}
	save_vip();
}
//会员积分兑换界面
void exchange_gift()
{
	int e = 8;
	while (e != 0)
	{
		gift* p = g_head->next, * q = p;
		system("cls");
		printf("\t\t*******************************************************************\n");
		printf("\t\t**礼品编号\t礼品名字\t所需积分\t库存数量\t **\n");
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
		printf("\t\t若想结束兑换请按0\n");
		printf("\t\t请输入您想要兑换的礼品编号：");
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
				printf("\t\t兑换成功！");
				system("pause");
			}
			else
			{
				if (q->stock == 0) printf("\t\t礼品库存不足\n");
				if (v_user->money < q->score) printf("\t\t会员积分不足");
				system("pause");
			}
		}
		else
		{
			if (e != 0)
			{
				printf("\t\t您的输入有误，即将返回上一界面");
				system("pause");
			}
			else
			{
				system("pause");
			}
		}
	}
}
//查看礼品兑换记录
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
		printf("\t\t\t\t 暂无礼品兑换记录");
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
//抽奖界面
int roll(int num)
{
	struct tm* local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	if (local->tm_mday % 5 != 0)
	{
		printf("\t\t今日非活动时间！");
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
			printf("\t\t本次抽奖幸运数字为：%d\n", n);
			printf("\t\t请按任意键进行抽奖~\n");
			getchar();
			printf("\t\t您本次抽得的数字为：%d", a);
			if (a == n)
			{
				v_user->money += 10;
				printf("\t\t恭喜您本次中奖，获得10会员积分！");
			}
			else
			{
				printf("\t\t谢谢参与！");
			}
			num--;
			return num;
		}
		else
		{
			printf("\t\t您的抽奖次数已用完\n");
			printf("\t\t");
			system("pause");
			return num;
		}
	}
}
//会员界面
void user_vip()
{
	int i = 3;
	char e = 8;
	while (e != '0')
	{
		system("cls");
		printf("\t\t----------------------会员积分兑换功能已开启----------------------\n");
		printf("\t\t*******************************************************************\n");
		printf("\t\t**会员编号\t会员姓名\t手机号码\t消费金额\t **\n");
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
		printf("\t\t--------------------05幸运大抽奖活动绝赞进行中--------------------\n");
		printf("\t\t请选择您想要进行的操作：\n");
		printf("\t\t1、会员积分兑换；\n");
		printf("\t\t2、05幸运大抽奖；\n");
		printf("\t\t0、进入点单界面；\n");
		e = _getch();
		if (e >= '0' && e <= '2')
		{
			switch (e)
			{
			case'1':
				printf("\t\t正在进入兑换系统");
				for (int k = 0; k < 5; k++)
				{
					printf("~");
					Sleep(200);
				}
				system("cls");
				exchange_gift();
				break;
			case'2':
				printf("\t\t正在进入抽奖系统");
				for (int k = 0; k < 5; k++)
				{
					printf("~");
					Sleep(200);
				}
				system("cls");
				printf("\t\t您还拥有%d次抽奖机会\n", i);
				i = roll(i);
				break;
			case'0':
				break;
			}
		}
		else
		{
			system("cls");
			printf("\t\t您的输入不符合规范,即将返回上一界面");
			system("pause");
			system("cls");
		}
	}
	printf("\t\t\t正在进入点餐系统");
	for (int k = 0; k < 5; k++)
	{
		printf("~");
		Sleep(200);
	}
}
//礼品信息存储
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
//礼品信息加载
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

//原料链表创建；
material creat()
{
	char c[64];  //以c[]为媒介来传递数据； 
	FILE* sp;
	sp = fopen("material record.txt", "r");  //打开原料表,sp指向文件； 
	if (sp == NULL)
	{
		printf("Can not open this file\n");
		exit(0);
	}
	rewind(sp);
	material head, p, p0 = NULL;  //p0为哨兵，head为链表头，p为链表末尾； 
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


//函数用于原料的消耗；
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
			while (p != NULL)   //检索链表，利用其中id（即所存编号来判断所需配料）； 
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

//将数据存储在文件中；
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


//将原料剩余输出在屏幕上；
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
	printf("\t\t\t编号\t\t名字\t\t\t库存\n");
	printf("\t\t*******************************************************************\n");
	for (int i = 0; i < 17; i++)
	{
		printf("\t\t\t%d\t\t%ls\t\t\t%d\n", bridge[i].id, bridge[i].name, bridge[i].weight);
	}
	printf("\t\t*******************************************************************\n");
	printf("\t\t*******************************************************************\n");
	return;
}


//实现购买原料的总函数； 
void purchase()
{
	char a;
	int b, c;
	printf("\n\t\t是否要购置原料？\n");
	printf("\t\t购置： Y \t不购置： N\n");
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
			printf("\t\t您的输入不符合规范，请重新输入：\n");
			continue;
		}
	}
}

//实现购买原料
void buy_material()
{
	Buy bu1, bu2;
	bu1 = buy_creat();
	bu2 = buy_add(bu1, weights);
	buy_material_file(bu2);
	return;
}

//实现关于购买原料链表的创建；
Buy buy_creat()
{
	char c[64];  //以c[]为媒介来传递数据； 
	FILE* sp;
	FILE* so;
	sp = fopen("material record.txt", "r");  //打开原料表,sp指向文件； 
	if (sp == NULL)
	{
		printf("Can not open this file\n");
		exit(0);
	}
	rewind(sp);
	Buy head, p, p0 = NULL;  //p0为哨兵，head为链表头，p为链表末尾； 
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


//购置原料；
Buy buy_add(Buy head, struct buy_weights weights[])
{
	int material_money[17]={10,5,8,14,6,7,3,5,4,9,2,12,15,4,9,8,15};  //每100克原料的价格； 
	FILE* sj = fopen("history material file.txt", "a");   //history material file.txt文件是储存历史购买原料记录; 
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
	int a, time[5];    //a为原料购置的总数，time记录时间； 
	a = output_3();
	printf("\t\t请输入您需要购置的原料的序号:\n");
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &weights[i].buy_id);
		if(weights[i].buy_id>17)
		{
			printf("输入错误，请重新输入。");
			i--;
			continue;
		}
	}
	print_time2(time);   //记录当前的时间； 
	fprintf(sj, "%d 月%d 日  %d:%d\n", time[0], time[1], time[2], time[3]);
	Buy p = head->next, p0 = NULL;
	for (int i = 0; i < a; i++)
	{
		printf("\t\t请输入%d号原料的购买量：（单位：g ,以100g的倍数购买）", weights[i].buy_id);
		scanf("%d", &weights[i].BUY_weight);
		while(((weights[i].BUY_weight)/100)*(material_money[weights[i].buy_id-1])>our_money)
		{
			printf("金额不足,无法购置,请重新输入：\n");
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


//将购买原料里链表的数据录入文件中
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

//实现录入需要购买的原料种数并美化
int output_3()
{
	int a = 0;
	char b[3];
	printf("\t\t*******************************************************************\n");
	printf("\t\t           请输入你要购买的原料种数：(原料共有17种)                \n");
	printf("\t\t                               ");
	scanf("%d", &a);
	while(a>17)
	{
		printf("输入错误，应输入小于17的数字。\n");
		printf("请重新输入：\n"); 
		scanf("%d",&a);
	}
	system("cls");
	printf("\t\t*******************************************************************\n");
	printf("\t\t                        购买种数为：%d                                \n", a);
	printf("\t\t*******************************************************************\n");
	printf("\n");
	material_print(bridge);
	return a;
}


//购买原料的时间的储存； 
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


//打开购买原料的历史记录 ；
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

//将文件中的数据存入数组drinks[][]中;
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


//输出钱数; 
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
	printf("\t\t**\t\t饮品店的余额为：");
	printf("%d\t\t\t\t **\n",our_money);
	printf("\t\t*******************************************************************\n");
	fclose(so);
	return ;
}

//将金额存入文件;
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

//读取订单；
Order_now build_file_now() {  //订单链表的创建 
	FILE* fp;
	fp = fopen("history order record.txt", "r");  //打开历史记录文件夹 
	if (fp == NULL) {
		printf("Can not open this file\n");
		exit(1);
	}
	rewind(fp);
	Order_now p,head=NULL,p0;
	head=(Order_now)malloc(sizeof(Order_Now));
	p0 = head;
	p0->next = NULL;
	char str[100];	//以其为媒介转递数据 
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


//读取原料； 
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

//判断原料警戒线；
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
			printf("\t\t\t是否现在购买原料?\n");
			printf("\t\t\t是：Y       否：N\n"); 
			printf("\n");
			printf("\t\t*******************************************\n");
			printf("\t\t*******************************************\n");
			printf("\t\t\t共有%d种原料不足\n",q); 
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
					printf("\t\t\t您的输入不符合规范，请重新输入：\n");
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
		printf("\t\t\t\t原料充足。\n");
		printf("\n");
		printf("\t\t*******************************************\n");
		return ;
	}
}

//判断原料与警戒线的差距；
int judge_now_material(material head,int guard[],struct Using_Id bridge[])
{
	int li=0; 
	material p0=NULL,p=head->next;
	printf("\t\t*******************************************\n");
	for(int i=0;i<17;i++)
	{
		if(p->weight<=guard[i])
		{
			printf("\t\t\t第 %d 号原料：%ls 即将耗尽，请尽快购买。\n",i+1,p->name);
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

//计算月、季利润；
void calculate_profit(Order_now head)
{
	int turnover[12]={0},/*营业额*/profit[12]={0}/*盈利额*/;
	Order_now p=head->next,p0=NULL; 
	printf("1.查询月度营业额/利润\n");
	printf("2.查询季度营业额/利润\n");
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
		printf("请输入月份:");
		scanf("%d",&o1);
		printf("\t*************************************\n");
		printf("\n");
		printf("\t\t营业额:%d     利润:%d",turnover[o1-1],profit[o1-1]);
		printf("\n");
		printf("\t*************************************\n");
		system("pause");
	}
	else if(b=='2')
	{
		int o2;
		system("cls");
		printf("请输入季度:");
		scanf("%d",&o2);
		printf("\t*************************************\n");
		printf("\n");
		printf("\t\t营业额:%d     利润:%d",turnover2[o2-1],profit2[o2-1]);
		printf("\n");
		printf("\t*************************************\n");
		system("pause");
	}
	else
	{
		printf("输入错误，请重试：");
		goto fing;
	}
}
//订单链表的创建 
struct order* build() {
	FILE* fp;
	fp = fopen("history order record.txt", "r");  //打开历史记录文件夹 
	if (fp == NULL) {
		printf("Can not open this file\n");
		exit(1);
	}
	struct order* top = NULL, * rear = NULL, * p;
	char str[100];	//以其为媒介转递数据 
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

//输入月份 
int input_month() {
	int x;
	printf("请输入您想要查看的订单记录的月份：\n");
	scanf("%d", &x);
	while (x < 1 || x>12) {
		system("cls");
		printf("        输入的月份不合法\n           请重新输入");
		Sleep(1);
		system("cls");
		printf("请输入您想要查看的订单记录的月份：\n");
		scanf("%d", &x);
	}
	return x;
}

//输入日期
int input_day() {
	int y;
	system("cls");
	printf("请输入您想要查看的订单记录的日期：\n");
	scanf("%d", &y);
	while (y < 1 || y>30) {
		system("cls");
		printf("        输入的日期不合法\n           请重新输入");
		Sleep(1);
		system("cls");
		printf("请输入您想要查看的订单记录的日期：\n");
		scanf("%d", &y);
	}
	return y;
}

//检索并输出某月某日订单记录
void output_order_list(struct order* p, int x/*月*/, int y/*日*/) {
	system("cls");
	printf("%10d月%d日\n\n", x, y);
	printf("序号 饮品名称 售价 成本\n");
	int turnover = 0/*营业额*/, profit = 0/*盈利额*/;
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
		printf("\n            营业%5d元\n            盈利%5d元", turnover, profit);
	else {
		system("cls");
		printf("  %d月%d日没有销售记录", x, y);
	}
}

struct order* history_build() {  //订单链表的创建 
	FILE* fp;
	fp = fopen("history order record.txt", "r");  //打开历史记录文件夹 
	if (fp == NULL) {
		printf("Can not open this file\n");
		exit(1);
	}
	struct order* top = NULL, * rear = NULL, * p;
	char str[100];	//以其为媒介转递数据 
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

int output_list(struct order* h) {  //输出所有订单记录 
	system("cls");
	int len = 0;
	printf("    序号 商品名称 售价 成本   日期\n");
	while (h) {
		printf("      %-3d %-9s%-5d%-5d%d月%d日\n", h->id, h->name, h->price, h->cost, h->month, h->day);
		len++;
		h = h->next;
	}
	return len/*链表长度*/;
}

int check(struct order* top) {  //检查输入链表序号是否有非数字字符
	char s[30], * p = s;
	int flag = 0;//假设没有非数字字符 
	scanf("%s", s);
	while (*p != '\0') {
		if (*p < '0' || *p>'9') {
			flag = 1;
			break;
		}
		p++;
	}
	while (flag) {  //含非数字字符 
		system("cls");
		p = s; flag = 0;
		printf("\n       输入不合法\n");
		printf("       请重新输入\n");
		Sleep(1);
		system("cls");
		output_list(top);
		printf("\n请输入需要删除的记录的序号：\n");
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
	while (*p != '\0') {  //将数字字符转换为整型数字 
		f = f * 10 + (*p - '0');
		p++;
	}
	return f;
}

int check2(struct order* pt) {  //检查confirm中的输入合法性
	char s[30], * p = s;
	int flag, i = 1;
	printf("\n         确定要删除此记录吗：\n");
	printf("           1 是      2 否\n");
	printf("请输入：\n");
	scanf("%s", s);
	while (*p != '\0') {  //检查长度和非法字符 
		if (i > 1) {  //长度大于1 非法 
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
		printf("\n       输入不合法\n");
		printf("       请重新输入\n");
		Sleep(1);
		system("cls");
		printf("    序号 商品名称 售价 成本   日期\n");
		printf("      %-3d %-9s%-5d%-5d%d月%d日\n", pt->id, pt->name, pt->price, pt->cost, pt->month, pt->day);
		printf("\n         确定要删除此记录吗：\n");
		printf("           1 是      2 否\n");
		printf("请输入：\n");
		scanf("%s", s);
		p = s; flag = 0; i = 1;  //重置 
		while (*p != '\0') {  //检查长度和非法字符 
			if (i > 1) {  //长度大于1 非法 
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

int judge_id(int len/*链表长度*/, struct order* top/*链表头指针*/) {  //输入序号及合法性判断 
	int x;
	printf("\n请输入需要删除的记录的序号：\n");
	x = check(top);
	while (x<1 || x>len) {  //输入不合法 
		system("cls");
		printf("\n    输入的序号不存在\n");
		printf("       请重新输入\n");
		Sleep(1);
		system("cls");
		output_list(top);
		printf("\n请输入需要删除的记录的序号：\n");
		x = check(top);
	}
	return x;  //返回要删除的序号 
}

int confirm(int x/*所要删除的序号*/, struct order* pt/*接受链表头的指针*/) {  //最终确定是否删除
	system("cls");
	printf("    序号 商品名称 售价 成本   日期\n");
	while (1) {  //输出需要删除的记录 
		if (x == pt->id) {
			printf("      %-3d %-9s%-5d%-5d%d月%d日\n", pt->id, pt->name, pt->price, pt->cost, pt->month, pt->day);
			break;
		}
		pt = pt->next;
	}
	int flag;
	flag = check2(pt);
	return flag;
}

void write(struct order* pt/*接收链表头的指针*/) {  //新链表写入文件 
	FILE* fp;
	fp = fopen("history order record.txt", "w");  //打开历史记录文件夹 
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

//查看某一类饮品的记录、查看某段时间所有记录、查看某一天的所有记录、查看所有记录  菜单输出
char output_check_choice_function2(){
	char ch;
	do{
		system("cls");
		printf("请输入您想查看记录的方式：\n\n");
		printf("1 查看一种饮品的全部销售记录 \n");
		printf("2 查看一段时间的所有销售记录 \n");
		printf("3 查看某天的所有销售记录 \n");
		printf("4 查看截至目前所有的销售记录 \n");
		printf("0 返回上一界面 \n");
		printf("\n请选择：");
		ch=getch(); 
	}while(ch<'0'||ch>'4');
	return ch;
}

//建立所有销售记录链表 
struct order* build_function2(){
	FILE *fp;
	fp=fopen("history order record.txt","r");  //打开历史记录文件夹 
	if(fp==NULL){
		printf("Can not open this file\n");
		exit(1);
	}
	struct order *top=NULL,*rear=NULL,*p;	
	char str[100];	//以其为媒介转递数据 
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

//输出记录 
void output_list_function2(struct order* h){
	int i=1;
	int turnover=0/*营业额*/,profit=0/*盈利额*/;
	printf("    序号 商品名称 售价 成本   日期        订单号\n");
	while(h)
	{
		printf("      %-3d %-9s%-5d%-5d%d月%d日    %s\n",i++,h->name,h->price,h->cost,h->month,h->day,h->order_num);
		turnover=turnover+h->price;
		profit=profit+h->price-h->cost;
		h=h->next;
	}
	printf("\n\t\t\t\t\t营业%d元",turnover);
	printf("\n\t\t\t\t\t盈利%d元",profit);
	system("pause");
}
//月份合法性判断
int judge_month_function2(int x/*用于分别case 1、case 2起始和case 2截至*/,int month_0,int day_0){
	char str[10],*p;
	int f;
	while(1){
		p=str;
		while(1){
			system("cls");
			if(x==3){
				printf("查看  月  日的记录\n"); 
				printf("\n请输入月份:\n");
			}else if(x==20){
				printf("查看  月  日至  月  日的记录\n");
				printf("\n请输起始入月份:\n");
			}else{
				printf("查看%2d月%2d日至  月  日的记录\n",month_0,day_0);
				printf("\n请输截至入月份:\n"); 
			}
			scanf("%s",str);
			if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
			else if(*p=='1'&&*(p+1)>='0'&&*(p+1)<='2'&&*(p+2)=='\0') break;  //10~12
		}
		f=0;
		while(*p!='\0'){  //字符转换为整型数字
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
//日期合法性判断 
int judge_day_function2(int x/*用于分别case 1、case 2起始和case 2截至*/,int month_0,int day_0,int month_1){
	char str[10],*p;
	int f;
	while(1){
		p=str;
		while(1){
			system("cls");
			if(x==3){
				printf("查看%2d月  日的记录\n",month_0); 
				printf("\n请输入日期:\n");
			}else if(x==20){
				printf("查看%2d月  日至  月  日的记录\n",month_0);
				if(month_0==12)
					printf("(注：起始日期不能为12月31日)\n");
				printf("\n请输入起始日期:\n");
			}else{
				printf("查看%2d月%2d日至%2d月  日的记录\n",month_0,day_0,month_1);
				printf("\n请输入截至日期:\n");
			}
			scanf("%s",str);
			
			if(x==3){
				
				if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
				else if(*p>='1'&&*p<='2'&&*(p+1)>='0'&&*(p+1)<='8'&&*(p+2)=='\0') break;  //10~18、20~28
				else if(*p=='1'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //19
				 
				if(month_0==1||month_0==3||month_0==5||month_0==7||month_0==8||month_0==10||month_0==12){  //大月31天
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
					else if(*p=='3'&&*(p+1)=='1'&&*(p+2)=='\0') break;  //31
				}else if(month_0==4||month_0==6||month_0==9||month_0==11){  //小月30天 
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
				}
				
			}else if(x==20){
				
				if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
				else if(*p>='1'&&*p<='2'&&*(p+1)>='0'&&*(p+1)<='8'&&*(p+2)=='\0') break;  //10~18、20~28
				else if(*p=='1'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //19
				 
				if(month_0==1||month_0==3||month_0==5||month_0==7||month_0==8||month_0==10){  //大月31天
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
					else if(*p=='3'&&*(p+1)=='1'&&*(p+2)=='\0') break;  //31
				}else if(month_0==4||month_0==6||month_0==9||month_0==11||month_0==12/*起始日期不能为12月31日*/){  //小月30天 
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
				}
				
			}else if(x==21){
				
				if(*p>='1'&&*p<='9'&&*(p+1)=='\0') break;  //1~9
				else if(*p>='1'&&*p<='2'&&*(p+1)>='0'&&*(p+1)<='8'&&*(p+2)=='\0') break;  //10~18、20~28
				else if(*p=='1'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //19
				 
				if(month_1==1||month_1==3||month_1==5||month_1==7||month_1==8||month_1==10||month_1==12){  //大月31天
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
					else if(*p=='3'&&*(p+1)=='1'&&*(p+2)=='\0') break;  //31
				}else if(month_1==4||month_1==6||month_1==9||month_1==11){  //小月30天 
					if(*p=='2'&&*(p+1)=='9'&&*(p+2)=='\0') break;  //29
					else if(*p=='3'&&*(p+1)=='0'&&*(p+2)=='\0') break;  //30
				}
				
			}
		}
		f=0;
		while(*p!='\0'){  //字符转换为整型数字
			f=f*10+(*p-'0');
			p++; 
		}
		if(x==3||x==20)
			break;
		else if(month_0==month_1&&f>day_0)  //同月份 
			break;
		else if(month_0<month_1)  //不同月份 
			break;
	}
	return f;
}

/*查看某一类饮品的记录*/
//输出饮品种类
char output_drink_type_choice_function2(){
	char ch;
	do{
		system("cls");
		printf("请选择想要查看相应记录的饮品：\n\n");
		printf("1 果茶\n");
		printf("2 奶茶\n");
		printf("3 酸奶\n");
		printf("4 奶绿\n");
		printf("5 咖啡\n");
		printf("6 椰奶\n");
		printf("7 牛奶\n");
		printf("8 可可\n");
		printf("9 益菌多\n");
		printf("\n请选择：");
		ch=getch();
    }while(ch<'1'||ch>'9');
	return ch;
}

//删除总链表中非此类饮品的部分
struct order* delete_case_1_function2(char ch,struct order *top){
	char temp[30];
	switch(ch){
		case '1':strcpy(temp,"果茶");break;
		case '2':strcpy(temp,"奶茶");break;
		case '3':strcpy(temp,"酸奶");break;
		case '4':strcpy(temp,"奶绿");break;
		case '5':strcpy(temp,"咖啡");break;
		case '6':strcpy(temp,"椰奶");break;
		case '7':strcpy(temp,"牛奶");break;
		case '8':strcpy(temp,"可可");break;
		case '9':strcpy(temp,"益菌多");
	}
	struct order sentry/*哨兵*/,*h=top,*h0/*h的前继指针*/;
	sentry.next=top;	
	while(h!=NULL){  //历史记录链表的遍历  
		if(strcmp(temp,h->name)==0){
			h0=h;
			h=h->next;
		}else{
			if(h==top){  //删除链表头
				h=h->next;
				free(sentry.next);
				sentry.next=h;
				top=h;
			}else{  //删除链表中间部分 
				h=h->next;
				free(h0->next);
				h0->next=h;
			}
		}			
	}
	return sentry.next;
}

/*查看一段时间的所有销售记录*/
//删除非此时间段的订单部分
struct order* delete_case_2_function2(int month_0,int day_0,int month_1,int day_1,struct order* top){
	struct order sentry/*哨兵*/,*h=top,*h0/*h的前继指针*/; 
	sentry.next=top;	
	while(h!=NULL){  //历史记录链表的遍历  
		if((h->month==month_0&&h->day<day_0)||(h->month==month_1&&h->day>day_1)||h->month<month_0||h->month>month_1){  //删除操作 
			if(h==top){  //删除链表头
				h=h->next;
				free(sentry.next);
				sentry.next=h;
				top=h;
			}else{  //删除链表中间部分 
				h=h->next;
				free(h0->next);
				h0->next=h;
			}
		}else{  //未进行删除 
			h0=h;
			h=h->next;
		}
	}
	return sentry.next;
}

/*查看某天的所有销售记录*/
//删除非此日的订单部分
struct order* delete_case_3_function2(int month,int day,struct order *top){
	struct order sentry/*哨兵*/,*h=top,*h0/*h的前继指针*/; 
	sentry.next=top;	
	while(h!=NULL){  //历史记录链表的遍历  
		if(h->month!=month||h->day!=day){  //删除操作 
			if(h==top){  //删除链表头
				h=h->next;
				free(sentry.next);
				sentry.next=h;
				top=h;
			}else{  //删除链表中间部分 
				h=h->next;
				free(h0->next);
				h0->next=h;
			}
		}else{  //未进行删除 
			h0=h;
			h=h->next;
		}
	}
	return sentry.next;
}

/*播放音乐*/
void playMusic()
{
	PlaySound(TEXT("music.wav"),0,SND_FILENAME | SND_ASYNC);
}

//输出剩下的原料份数；
void material_fen(int drinks[][6])
{
	FILE* sp=fopen("饮品.txt","r");
	if(sp==NULL)
	{
		printf("Can not open this 饮品.txt file.");
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
	while (p != NULL)   //检索链表，利用其中id（即所存编号来判断所剩余配料）； 
	{
		if(p->id==1||p->id==2||p->id==6)
		{
			ma[p->id-1]=p->weight/30;
			printf("\t\t\t%ls\t\t%d份\n",p->name,(p->weight/30));
		}
		if(p->id==3||p->id==4||p->id==5)
		{
			ma[p->id-1]=p->weight/50;
			printf("\t\t\t%ls\t\t%d份\n",p->name,(p->weight/50));
		}
		if(p->id==7||p->id==8||p->id==9)
		{
			ma[p->id-1]=p->weight/10;
			printf("\t\t\t%ls\t\t%d份\n",p->name,(p->weight/10));
		}
		if(p->id==10||p->id==12||p->id==14||p->id==17)
		{
			ma[p->id-1]=p->weight/20;
			printf("\t\t\t%ls\t\t%d份\n",p->name,(p->weight/20));
		}
		if(p->id==15||p->id==11)
		{
			ma[p->id-1]=p->weight/40;
			printf("\t\t\t%ls\t\t%d份\n",p->name,(p->weight/40));
		}
		if(p->id==13||p->id==16)
		{
			ma[p->id-1]=p->weight/10;
			printf("\t\t\t%ls\t\t%d份\n",p->name,(p->weight/10));
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
		printf("\t\t\t%ls剩余可购买的饮品数: ",name[i]);
		compare(i,drinks,ma);
	}
	printf("\n");
	printf("\t\t******************************************\n");
}

//比较函数； 
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
			printf("%d杯\n",b[i]);
			break;
		}
	}
	return ;
}
