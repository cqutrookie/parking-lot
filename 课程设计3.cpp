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
		printf("��ȡ�ļ�ʧ��\n");
		return NULL;
	}

	while( !feof(fp) )
	{
		if((p = (struct car *)malloc(sizeof(struct car))) == NULL)
		{
			printf("�ڴ治�㣬���ͷ��ڴ�֮�����ԣ�");	
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
			printf("���������");
		scanf("%d",&p->num);
		fflush(stdin);
		printf("�����복��");
		gets(p->carname);
		fflush(stdin);
		printf("�����복������");
		gets(p->id);
		fflush(stdin);
		printf("������ͣ��λ��");
		gets(p->pos);
		fflush(stdin);
		p->money=0;
		p->next=NULL;
		return p;
		}
		else
		{
		printf("���������");
		scanf("%d",&p->num);
			while((p1->num!=p->num)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->num==p->num)
			{
				printf("      �������Ѿ���������������\n");
				printf("       ���������\n");
				scanf("%d",&p->num);
			}
		/*while(1)
		{	
			if(p1->num==p->num)
			{
			printf("����ظ�����������\n");
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
		printf("�����복��");
		gets(p->carname);
		fflush(stdin);
		printf("�����복������");
		gets(p->id);
		fflush(stdin);
		printf("������ͣ��λ��");
		gets(p->pos);
		while((p1->pos!=p->pos)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->pos==p->pos)
			{
				printf("      �����λ�Ѿ���������������\n");
				printf("       �������������\n");
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
			printf("����1�����������0����\n");
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

	void print(struct car *head)	//�������
	{
		struct car *p;
		p = head;
		if(head==NULL)
			printf("û�г�\n");
		if(head != NULL)	//������ǿ�����
		{
			do
			{
				system("color 5C");
				printf("�����%d,������%s,������%s,ͣ����%s�������%d\n",p->num,p->carname,p->id,p->pos,p->money);
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
			printf("û�г�\n");
		else
		{
			printf("��������Ҫ��ֵ��id");
			scanf("%s",ch);
			while(strcmp(p->id,ch)!=0&&p->next!=NULL)
			{
				p=p->next;
			}
			if(strcmp(p->id,ch)==0)
			{
				printf("�����������ֵ�Ľ��:");
				scanf("%d",&a);
				p->money+=a;
				printf("��ֵ�ɹ�����\n");
			}
			else
				printf("û�������������Ϣ\n");
		}
		return head;
	}


	struct car *del(struct car *head)
{
	struct car *p1,*p2;
	int num;
    
	if(head==NULL)
	{
		printf("û�г�\n");
	}
	else
	{
		p1=head;
        print(p1);
		printf("������Ҫɾ�������:");
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
			printf("ɾ��%d����Ϣ�ɹ���\n",num);
		}
		else
		{
			printf("�Ҳ���%d������Ϣ��",num);
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
			printf("û�г�\n");
		if(head!=NULL)
		{
			print(p);
			printf("�����������޸ĳ������");
			scanf("%d",&a);
			while(p->num!=a&&p->next!=NULL)
			{
				p=p->next;
			}
			if(p==NULL)
			printf("û�иó�����Ϣ¼��\n");
			else if(p->num==a)
			{
				printf("�����������޸ĵ���Ϣ\n");
				printf("���������");
		scanf("%d",&p->num);
		fflush(stdin);
		printf("�����복��");
		gets(p->carname);
		fflush(stdin);
		printf("�����복������");
		gets(p->id);
		fflush(stdin);
		printf("������ͣ��λ��");
		gets(p->pos);
		fflush(stdin);
		printf("�޸ĳɹ�!\n");
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
		printf("д���ļ�ʧ�ܣ������ԣ�");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct car),1,fp);
		p = p->next;
	}

	fclose(fp);     //�رմ����ļ�
}

			void Save2(struct car * list)
{
	struct car *p = list;
	FILE * fp = NULL;

	if((fp=fopen("lxy.txt","wb"))==NULL)
	{
		printf("д���ļ�ʧ�ܣ������ԣ�");
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
			printf("û�г����Կۿ�\n");
		if(head!=NULL)
		{
			printf("����enter��ȷ�Ͻ��ճ���ͣ���ۿ�\n");
			fflush(stdin);
			getchar();
			while(p->next!=NULL)
			{
				p->money-=20;
				p=p->next;
			}
			p->money-=20;
			if(p->next==NULL)
			printf("�ۿ���ɣ���\n");
		
		}
		return head;
	}







			//�ֿ�       





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
		printf("��ȡ�ļ�ʧ��\n");
		return NULL;
	}

	while( !feof(fp1) )
	{
		if((p = (struct cartem *)malloc(sizeof(struct cartem))) == NULL)
		{
			printf("�ڴ治�㣬���ͷ��ڴ�֮�����ԣ�");	
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
			printf("���������");
		scanf("%d",&p->num);
		fflush(stdin);
		printf("�����복��");
		gets(p->carname);
		fflush(stdin);
		printf("�����복������");
		gets(p->id);
		fflush(stdin);
		printf("��������ʱͣ��λ��");
		gets(p->pos);
		fflush(stdin);
		printf("��������ʱͣ��ʱ�䣨���㼸�֣�");
		scanf("%d%d",&p->a,&p->b);
		p->next=NULL;
		return p;
		}
		else
		{
		printf("���������");
		scanf("%d",&p->num);
		while((p1->num!=p->num)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->num==p->num)
			{
				printf("      �������Ѿ���������������\n");
				printf("       ���������\n");
				scanf("%d",&p->num);
			}
		fflush(stdin);
		printf("�����복��");
		gets(p->carname);
		fflush(stdin);
		printf("�����복������");
		gets(p->id);
		fflush(stdin);
		printf("������ͣ��λ��");
		gets(p->pos);
		while((p1->pos!=p->pos)&&(p1->next!=NULL))
		{
			p1=p1->next;
		}
		if(p1->pos==p->pos)
			{
				printf("      �����λ�Ѿ���������������\n");
				printf("       �������������\n");
				scanf("%s",p->pos);
			}
		fflush(stdin);
		printf("��������ʱͣ��ʱ�䣨���㼸�֣�");
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
			printf("����1�����������0����\n");
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


	void print1(struct cartem *head)	//�������
	{
		struct cartem *p;
		p = head;
		if(head==NULL)
			printf("û�г�\n");
		if(head != NULL)	//������ǿ�����
		{
			do
			{
				system("color 5C");
				printf("�����%d,������%s,������%s,ͣ����%s,��ʼͣ��ʱ����%d��%d��\n",p->num,p->carname,p->id,p->pos,p->a,p->b);
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
			printf("û�г�\n");
		}
		else
		{
		p1=head;
        print1(p1);
		printf("������Ҫɾ�������:");
		scanf("%d",&num);
		printf("�Ƿ�����Ϊ��ʱͣ��������ɾ����Ϣ?\n");
		printf("�ǵ�������1����������2\n");
		printf("������:");
		scanf("%d",&x);
		switch(x)
		{
		case 1:
			printf("�����������ʱͣ��ʱ��(���㼸��)\n");
			scanf("%d%d",&c,&d);
		while(p1->num!=num&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(num==p1->num)
		{
			s=((c-(p1->a))*60+(d-(p1->a)))*0.6;
			printf("��%s�����ɷ�%.2fԪ\n",p1->id,s);
			if(p1==head)
			{
				head=p1->next;
			}
			else
			{
				p2->next=p1->next;
			}
			printf("ɾ��%d����Ϣ�ɹ���\n",num);
		}
		else
		{
			printf("�Ҳ���%d������Ϣ��",num);
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
			printf("ɾ��%d����Ϣ�ɹ���\n",num);
		}
		else
		{
			printf("�Ҳ���%d������Ϣ��",num);
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
			printf("û�г�\n");
		if(head!=NULL)
		{
			print1(p);
			printf("�����������޸ĳ������");
			scanf("%d",&a);
			while(p->num!=a&&p->next!=NULL)
			{
				p=p->next;
			}
			if(p==NULL)
			printf("û�иó�����Ϣ¼��\n");
			else if(p->num==a)
			{
				printf("�����������޸ĵ���Ϣ\n");
				printf("���������");
				scanf("%d",&p->num);
				fflush(stdin);
				printf("�����복��");
				gets(p->carname);
				fflush(stdin);
				printf("�����복������");
				gets(p->id);
				fflush(stdin);
				printf("������ͣ��λ��");
				gets(p->pos);
				fflush(stdin);
				printf("������ͣ��ʱ��(���㼸��)");
				scanf("%d%d",&p->a,&p->b);
				fflush(stdin);
				printf("�޸ĳɹ�!\n");
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
		printf("д���ļ�ʧ�ܣ������ԣ�");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct cartem),1,fp1);
		p = p->next;
	}

	fclose(fp1);     //�رմ����ļ�
}

			void Save4(struct cartem * list)
{
	struct cartem *p = list;
	FILE * fp1 = NULL;

	if((fp1=fopen("tsh.txt","wb"))==NULL)
	{
		printf("д���ļ�ʧ�ܣ������ԣ�");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct cartem),1,fp1);
		p = p->next;
	}

	fclose(fp1);     //�رմ����ļ�
}
	
		//���ļ��ж�ȡ���ݣ��Գ�ʼ��û��ͷ��������



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
		printf("                   *       ����ͣ��������ϵͳ   *\n");
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
		printf("                            ���������Ա����\n");
		printf("                      (�����޸�����������ĳ����!!!)\n");
		printf("                            �����ǣ�");
		scanf("%d",&n);
		if(n!=1234)
		printf("                            �������!\n");
		if(n==1234)
		{	system("cls");
		    break;
		}
		}
		system("color 7C");
		printf("                            �ɹ��������ϵͳ!!!\n");
		printf("                            ��ʱͣ������������1\n");
		printf("                            ����ͣ������������2\n");
		printf("                            ������:");
		scanf("%d",&y);
		system("cls");
		switch(y)
		{
		case 2:
			printf("                       �ɹ����볤��ͣ������ϵͳ!!!\n");
			printf("              ������ͣ��ҵ���ڵ�һ��ͣ��ʱ��Ҫ��ֵ100Ԫ����\n");
			system("pause");
			system("cls");
start:
		printf("                            ����1�鿴ͣ����Ϣ\n");
		printf("                            ����2���ͣ����Ϣ\n");
		printf("                            ����3ɾ��ͣ����Ϣ\n");
		printf("                            ����4�޸�ͣ����Ϣ\n");
		printf("                            ����5��ѯ������Ϣ\n");
		printf("                            ����6��ֵ����\n");
		printf("                            ����7��ʼ���н��տۿ�(��Գ�ʱ��ͣ���û��Ŀۿ�)\n");
		printf("                            ����8�˳�ϵͳ\n");

		printf("                            �������������������");
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
			printf("                           ������������ҳ��ĳ���\n");
			scanf("%s",ch);
			while((strcmp(p->carname,ch)!=0)&&(p->next!=NULL))
			{
				p=p->next;
			}
			if(strcmp(p->carname,ch)==0)
				printf("�����%d,������%s,����������%s,ͣ��λ����%s\n",p->num,p->carname,p->id,p->pos);
			else
				printf("                       û�������������Ϣ\n");
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
			printf("                        �ɹ�������ʱͣ��ϵͳ!!!\n");
			printf("                        ��ʱͣ��ʱ�䲻�ܳ���һ�죡\n");
			system("pause");
			system("cls");
start1:
		printf("                            ����1�鿴ͣ����Ϣ\n");
		printf("                            ����2���ͣ����Ϣ\n");
		printf("                            ����3ɾ��ͣ����Ϣ\n");
		printf("                            ����4�޸�ͣ����Ϣ\n");
		printf("                            ����5��ѯ������Ϣ\n");
		printf("                            ����6�˳�ϵͳ\n");

		printf("                            �������������������");
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
			printf("                           ������������ҳ��ĳ���\n");
			scanf("%s",ch);
			while((strcmp(p1->carname,ch)!=0)&&(p1->next!=NULL))
			{
				p1=p1->next;
			}
			if(strcmp(p1->carname,ch)==0)
				printf("�����%d,������%s,����������%s,ͣ��λ����%s\n,ͣ��ʱ����%d��%d��\n",p1->num,p1->carname,p1->id,p1->pos,p1->a,p1->b);
			else
				printf("                       û�������������Ϣ\n");
			system("pause");
			system("cls");
			goto start1;
		case 6:
			system("cls");
			goto end;
		}
		default:
			printf("�������\n\n");
			break;

	}

}