#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

struct car
	{
		int num;
		char carname[20];
		char id[20];
		char pos[20];
		int money;
		struct car *next;
	};

	struct car *insertNode(struct car *list,struct car *node)
{
	struct car *p=list;
	if(list==NULL)
		return list=node;
	if(list->num!=node->num)
	{
		node->next=list;
		list=node;
		return list;
	}
	while(p->next!=NULL)
	{
		if(p->next->num!=node->num)
			break;
		p=p->next;
	}	
	node->next=p->next;
	p->next=node;

	return list;
}

	struct car *Get()
{
	FILE *fp = NULL;
	struct car *p = NULL;
	struct car *list = NULL;

	if((fp=fopen("lxy.txt","rb"))==NULL)
	{
		printf("读取文件失败\n");
		return NULL;
	}

	while( !feof(fp) )
	{
		if((p = (struct car *)malloc(sizeof(struct car))) == NULL)
		{
			printf("内存不足，请释放内存之后重试！");	
			return NULL;
		}	
		memset(p,0,sizeof(struct car));
		if(fread(p,sizeof(struct car),1,fp))
		{
			p->next = NULL;	
			list = insertNode(list,p);
		}
	}
    
	fclose(fp);
	return list;
}

	struct car *getNode()
	{
		struct car *p=NULL;
		struct car *p1=NULL;
		p1=Get();
		p=(struct car *)malloc(sizeof(struct car));
		memset(p,0,sizeof(struct car));
		if(p1==NULL)
		{
			printf("请输入序号");
		scanf("%d",&p->num);
		fflush(stdin);
		printf("请输入车牌");
		gets(p->carname);
		fflush(stdin);
		printf("请输入车主姓名");
		gets(p->id);
		fflush(stdin);
		printf("请输入停车位置");
		gets(p->pos);
		fflush(stdin);
		p->money=0;
		p->next=NULL;
		return p;
		}
		else
		{
		printf("请输入序号");
		scanf("%d",&p->num);
			while((p1->num!=p->num)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->num==p->num)
			{
				printf("      这个序号已经有了请重新输入\n");
				printf("       请输入序号\n");
				scanf("%d",&p->num);
			}
		/*while(1)
		{	
			if(p1->num==p->num)
			{
			printf("序号重复请重新输入\n");
			scanf("%d",&p->num);
			}
			if(p1->num!=p->num)
			{
				p1=p1->next;
			}
			if(p1->next==NULL)
				break;
		}*/
		fflush(stdin);
		printf("请输入车牌");
		gets(p->carname);
		fflush(stdin);
		printf("请输入车主姓名");
		gets(p->id);
		fflush(stdin);
		printf("请输入停车位置");
		gets(p->pos);
		while((p1->pos!=p->pos)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->pos==p->pos)
			{
				printf("      这个车位已经有了请重新输入\n");
				printf("       请重新输入序号\n");
				scanf("%s",p->pos);
			}
		fflush(stdin);
		
		p->next=NULL;
		return p;
		}
	}

	struct car * insert()
	{   
		struct car *head=NULL;
		struct car *p=NULL;
		int flag=0;
		while(1)
		{
			printf("输入1继续添加输入0结束\n");
			scanf("%d",&flag);
			fflush(stdin);
			if(flag==0)
				break;
			if(flag==1)
			{
			p=getNode();
			p->next=head;
			head=p;
			}
		}
		return head;
	}

	void print(struct car *head)	//输出链表
	{
		struct car *p;
		p = head;
		if(head==NULL)
			printf("没有车\n");
		if(head != NULL)	//如果不是空链表
		{
			do
			{
				system("color 5C");
				printf("序号是%d,车牌是%s,车主是%s,停在了%s，余额是%d\n",p->num,p->carname,p->id,p->pos,p->money);
				p = p->next;
			}while( p );
		}
	}

	struct car *charge(struct car *head)
	{
		struct car *p;
		int a;
		char ch[20];
		p=head;
		if(head==NULL)
			printf("没有车\n");
		else
		{
			printf("请输入你要充值的id");
			scanf("%s",ch);
			while(strcmp(p->id,ch)!=0&&p->next!=NULL)
			{
				p=p->next;
			}
			if(strcmp(p->id,ch)==0)
			{
				printf("请输入你想充值的金额:");
				scanf("%d",&a);
				p->money+=a;
				printf("充值成功！！\n");
			}
			else
				printf("没有这个车主的信息\n");
		}
		return head;
	}


	struct car *del(struct car *head)
{
	struct car *p1,*p2;
	int num;
    
	if(head==NULL)
	{
		printf("没有车\n");
	}
	else
	{
		p1=head;
        print(p1);
		printf("输入需要删除的序号:");
		scanf("%d",&num);

		while(p1->num!=num&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(num==p1->num)
		{
			if(p1==head)
			{
				head=p1->next;
			}
			else
			{
				p2->next=p1->next;
			}
			printf("删除%d车信息成功！\n",num);
		}
		else
		{
			printf("找不到%d车的信息！",num);
		}
	}

	return head;
}


	struct car *change(struct car *head)
	{
		int a;
		struct car *p1=NULL;
		p1=Get();
		struct car *p=NULL;
		p=head;
		if(head==NULL)
			printf("没有车\n");
		if(head!=NULL)
		{
			print(p);
			printf("请输入你想修改车的序号");
			scanf("%d",&a);
			while(p->num!=a&&p->next!=NULL)
			{
				p=p->next;
			}
			if(p==NULL)
			printf("没有该车的信息录入\n");
			else if(p->num==a)
			{
				printf("请输入你想修改的信息\n");
				printf("请输入序号");
		scanf("%d",&p->num);
		fflush(stdin);
		printf("请输入车牌");
		gets(p->carname);
		fflush(stdin);
		printf("请输入车主姓名");
		gets(p->id);
		fflush(stdin);
		printf("请输入停车位置");
		gets(p->pos);
		fflush(stdin);
		printf("修改成功!\n");
			}
		}
		return head;
			

	}


		void Save(struct car * list)
{
	struct car *p = list;
	FILE * fp = NULL;

	if((fp=fopen("lxy.txt","ab"))==NULL)
	{
		printf("写入文件失败，请重试！");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct car),1,fp);
		p = p->next;
	}

	fclose(fp);     //关闭磁盘文件
}

			void Save2(struct car * list)
{
	struct car *p = list;
	FILE * fp = NULL;

	if((fp=fopen("lxy.txt","wb"))==NULL)
	{
		printf("写入文件失败，请重试！");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct car),1,fp);
		p = p->next;
	}

	fclose(fp);     
}
	struct car *reduce(struct car *head)
	{
		struct car *p=NULL;
		p=head;
		if(head==NULL)
			printf("没有车可以扣款\n");
		if(head!=NULL)
		{
			printf("按下enter键确认今日长期停车扣款\n");
			fflush(stdin);
			getchar();
			while(p->next!=NULL)
			{
				p->money-=20;
				p=p->next;
			}
			p->money-=20;
			if(p->next==NULL)
			printf("扣款完成！！\n");
		
		}
		return head;
	}







			//分开       





	struct cartem
	{
		int num;
		char carname[20];
		char id[20];
		char pos[20];
		int a,b;
		struct cartem *next;
	};
	
	struct cartem *insertNode1(struct cartem *list,struct cartem *node)
{
	struct cartem *p=list;
	if(list==NULL)
		return list=node;
	if(list->num!=node->num)
	{
		node->next=list;
		list=node;
		return list;
	}
	while(p->next!=NULL)
	{
		if(p->next->num!=node->num)
			break;
		p=p->next;
	}	
	node->next=p->next;
	p->next=node;

	return list;
}

	struct cartem *Get1()
{
	FILE *fp1 = NULL;
	struct cartem *p = NULL;
	struct cartem *list = NULL;

	if((fp1=fopen("tsh.txt","rb"))==NULL)
	{
		printf("读取文件失败\n");
		return NULL;
	}

	while( !feof(fp1) )
	{
		if((p = (struct cartem *)malloc(sizeof(struct cartem))) == NULL)
		{
			printf("内存不足，请释放内存之后重试！");	
			return NULL;
		}	
		memset(p,0,sizeof(struct cartem));
		if(fread(p,sizeof(struct cartem),1,fp1))
		{
			p->next = NULL;	
			list = insertNode1(list,p);
		}
	}
    
	fclose(fp1);
	return list;
}
	
	struct cartem *getNode1()
	{
		struct cartem *p=NULL;
		struct cartem *p1=NULL;
		p1=Get1();
		p=(struct cartem *)malloc(sizeof(struct cartem));
		memset(p,0,sizeof(struct cartem));
		if(p1==NULL)
		{
			printf("请输入序号");
		scanf("%d",&p->num);
		fflush(stdin);
		printf("请输入车牌");
		gets(p->carname);
		fflush(stdin);
		printf("请输入车主姓名");
		gets(p->id);
		fflush(stdin);
		printf("请输入临时停车位置");
		gets(p->pos);
		fflush(stdin);
		printf("请输入临时停车时间（几点几分）");
		scanf("%d%d",&p->a,&p->b);
		p->next=NULL;
		return p;
		}
		else
		{
		printf("请输入序号");
		scanf("%d",&p->num);
		while((p1->num!=p->num)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->num==p->num)
			{
				printf("      这个序号已经有了请重新输入\n");
				printf("       请输入序号\n");
				scanf("%d",&p->num);
			}
		fflush(stdin);
		printf("请输入车牌");
		gets(p->carname);
		fflush(stdin);
		printf("请输入车主姓名");
		gets(p->id);
		fflush(stdin);
		printf("请输入停车位置");
		gets(p->pos);
		while((p1->pos!=p->pos)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->pos==p->pos)
			{
				printf("      这个车位已经有了请重新输入\n");
				printf("       请重新输入序号\n");
				scanf("%s",p->pos);
			}
		fflush(stdin);
		printf("请输入临时停车时间（几点几分）");
		scanf("%d%d",&p->a,&p->b);
		p->next=NULL;
		return p;
		}
	}


	struct cartem * insert1()
	{   
		struct cartem *head=NULL;
		struct cartem *p=NULL;
		int flag=0;
		while(1)
		{
			printf("输入1继续添加输入0结束\n");
			scanf("%d",&flag);
			fflush(stdin);
			if(flag==0)
				break;
			if(flag==1)
			{
			p=getNode1();
			p->next=head;
			head=p;
			}
		}
		return head;
	}


	void print1(struct cartem *head)	//输出链表
	{
		struct cartem *p;
		p = head;
		if(head==NULL)
			printf("没有车\n");
		if(head != NULL)	//如果不是空链表
		{
			do
			{
				system("color 5C");
				printf("序号是%d,车牌是%s,车主是%s,停在了%s,开始停车时间是%d点%d分\n",p->num,p->carname,p->id,p->pos,p->a,p->b);
				p = p->next;
			}while( p );
		}
	}
	

	struct cartem *del1(struct cartem *head)
{
		struct cartem *p1,*p2;
		int num;
		int x,c,d;
		float s;
		if(head==NULL)
		{
			printf("没有车\n");
		}
		else
		{
		p1=head;
        print1(p1);
		printf("输入需要删除的序号:");
		scanf("%d",&num);
		printf("是否是因为暂时停车结束而删除信息?\n");
		printf("是的请输入1，否请输入2\n");
		printf("我输入:");
		scanf("%d",&x);
		switch(x)
		{
		case 1:
			printf("请输入结束暂时停车时间(几点几分)\n");
			scanf("%d%d",&c,&d);
		while(p1->num!=num&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(num==p1->num)
		{
			s=((c-(p1->a))*60+(d-(p1->a)))*0.6;
			printf("请%s车主缴费%.2f元\n",p1->id,s);
			if(p1==head)
			{
				head=p1->next;
			}
			else
			{
				p2->next=p1->next;
			}
			printf("删除%d车信息成功！\n",num);
		}
		else
		{
			printf("找不到%d车的信息！",num);
		}
		break;
		case 2:
			while(p1->num!=num&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(num==p1->num)
		{
			if(p1==head)
			{
				head=p1->next;
			}
			else
			{
				p2->next=p1->next;
			}
			printf("删除%d车信息成功！\n",num);
		}
		else
		{
			printf("找不到%d车的信息！",num);
		}
		break;
		}

	}

	return head;
}


	struct cartem *change1(struct cartem *head)
	{
		int a;
		struct cartem *p1=NULL;
		p1=Get1();
		struct cartem *p=NULL;
		p=head;
		if(head==NULL)
			printf("没有车\n");
		if(head!=NULL)
		{
			print1(p);
			printf("请输入你想修改车的序号");
			scanf("%d",&a);
			while(p->num!=a&&p->next!=NULL)
			{
				p=p->next;
			}
			if(p==NULL)
			printf("没有该车的信息录入\n");
			else if(p->num==a)
			{
				printf("请输入你想修改的信息\n");
				printf("请输入序号");
				scanf("%d",&p->num);
				fflush(stdin);
				printf("请输入车牌");
				gets(p->carname);
				fflush(stdin);
				printf("请输入车主姓名");
				gets(p->id);
				fflush(stdin);
				printf("请输入停车位置");
				gets(p->pos);
				fflush(stdin);
				printf("请输入停车时间(几点几分)");
				scanf("%d%d",&p->a,&p->b);
				fflush(stdin);
				printf("修改成功!\n");
			}
		}
		return head;
		}


		void Save3(struct cartem * list)
{
	struct cartem *p = list;
	FILE * fp1 = NULL;

	if((fp1=fopen("tsh.txt","ab"))==NULL)
	{
		printf("写入文件失败，请重试！");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct cartem),1,fp1);
		p = p->next;
	}

	fclose(fp1);     //关闭磁盘文件
}

			void Save4(struct cartem * list)
{
	struct cartem *p = list;
	FILE * fp1 = NULL;

	if((fp1=fopen("tsh.txt","wb"))==NULL)
	{
		printf("写入文件失败，请重试！");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct cartem),1,fp1);
		p = p->next;
	}

	fclose(fp1);     //关闭磁盘文件
}
	
		//从文件中读取数据，以初始化没有头结点的链表



void main()
	{
		int n,i,x,y;
		char ch[20];
		struct car *p;
		struct cartem *p1;
end:
		system("mode con cols=75 lines=25");
		system("color 8F");
		printf("                   ******************************\n");
		Sleep(100);
		printf("                   *                            *\n");
		Sleep(100);
		printf("                   *                            *\n");
		Sleep(100);
		printf("                   *                            *\n");
		Sleep(100);
		printf("                   *       茵茵停车场管理系统   *\n");
		Sleep(100);
		printf("                   *                            *\n");
		Sleep(100);
		printf("                   *                            *\n");
		Sleep(100);
		printf("                   *                            *\n");
		Sleep(100);
		printf("                   ******************************\n");
		Sleep(100);
		for(i=0;i<999;i++)
		{
		printf("                            请输入管理员密码\n");
		printf("                      (若想修改密码请找雷某本人!!!)\n");
		printf("                            密码是：");
		scanf("%d",&n);
		if(n!=1234)
		printf("                            密码错误!\n");
		if(n==1234)
		{	system("cls");
		    break;
		}
		}
		system("color 7C");
		printf("                            成功进入管理系统!!!\n");
		printf("                            临时停车管理请输入1\n");
		printf("                            长期停车管理请输入2\n");
		printf("                            我输入:");
		scanf("%d",&y);
		system("cls");
		switch(y)
		{
		case 2:
			printf("                       成功进入长期停车管理系统!!!\n");
			printf("              办理长期停车业务在第一次停车时需要充值100元以上\n");
			system("pause");
			system("cls");
start:
		printf("                            输入1查看停车信息\n");
		printf("                            输入2添加停车信息\n");
		printf("                            输入3删除停车信息\n");
		printf("                            输入4修改停车信息\n");
		printf("                            输入5查询车辆信息\n");
		printf("                            输入6充值服务\n");
		printf("                            输入7开始进行今日扣款(针对长时间停车用户的扣款)\n");
		printf("                            输入8退出系统\n");

		printf("                            请输入你想输入的数字");
		scanf("%d",&x);
		system("cls");
		switch(x)
		{
		case 1:
			p=Get();
			print(p);
			system("pause");
			system("cls");
			goto start;
		case 2:
			p=insert();
			Save(p);
			system("pause");
			system("cls");
			goto start;
		case 3:
			p=Get();
			p=del(p);
			Save2(p);
			system("pause");
			system("cls");
			goto start;
		case 4:
			p=Get();
			change(p);
			Save2(p);
			system("pause");
			system("cls");
			goto start;
		case 5:
			p=Get();
			printf("                           请输入你想查找车的车牌\n");
			scanf("%s",ch);
			while((strcmp(p->carname,ch)!=0)&&(p->next!=NULL))
			{
				p=p->next;
			}
			if(strcmp(p->carname,ch)==0)
				printf("序号是%d,车牌是%s,车主姓名是%s,停车位置是%s\n",p->num,p->carname,p->id,p->pos);
			else
				printf("                       没有这个车辆的信息\n");
			system("pause");
			system("cls");
			goto start;
		case 6:
			p=Get();
			charge(p);
			Save2(p);
			system("pause");
			system("cls");
			goto start;
		case 7:
			p=Get();
			reduce(p);
			Save2(p);
			system("pause");
			system("cls");
			goto start;
		case 8:
			system("cls");
			goto end;
		}
		goto start;
		case 1:
			printf("                        成功进入暂时停车系统!!!\n");
			printf("                        暂时停车时间不能超过一天！\n");
			system("pause");
			system("cls");
start1:
		printf("                            输入1查看停车信息\n");
		printf("                            输入2添加停车信息\n");
		printf("                            输入3删除停车信息\n");
		printf("                            输入4修改停车信息\n");
		printf("                            输入5查询车辆信息\n");
		printf("                            输入6退出系统\n");

		printf("                            请输入你想输入的数字");
		scanf("%d",&x);
		system("cls");
		switch(x)
		{
		case 1:
			p1=Get1();
			print1(p1);
			system("pause");
			system("cls");
			goto start1;
		case 2:
			p1=insert1();
			Save3(p1);
			system("pause");
			system("cls");
			goto start1;
		case 3:
			p1=Get1();
			p1=del1(p1);
			Save4(p1);
			system("pause");
			system("cls");
			goto start1;
		case 4:
			p1=Get1();
			change1(p1);
			Save4(p1);
			system("pause");
			system("cls");
			goto start1;
		case 5:
			p1=Get1();
			printf("                           请输入你想查找车的车牌\n");
			scanf("%s",ch);
			while((strcmp(p1->carname,ch)!=0)&&(p1->next!=NULL))
			{
				p1=p1->next;
			}
			if(strcmp(p1->carname,ch)==0)
				printf("序号是%d,车牌是%s,车主姓名是%s,停车位置是%s\n,停车时间是%d点%d分\n",p1->num,p1->carname,p1->id,p1->pos,p1->a,p1->b);
			else
				printf("                       没有这个车辆的信息\n");
			system("pause");
			system("cls");
			goto start1;
		case 6:
			system("cls");
			goto end;
		}
		default:
			printf("输入错误\n\n");
			break;

	}

}