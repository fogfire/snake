//*************************************************************************************************************

//**************************************̰����С��Ϸ��˫�˽�ϼ�ǿ��********************************************
//
//                      **********************************************************
//                      **********************************************************
//                      **      ____         _____                 ˫      ��   **
//                      **    _/    \_    __/     \__	                        **
//                      **   /   #@   \++/           \             ��  +   ��   **
//                      **   \==/  __     _/+/-/  \    \____                    **
//                      **     ��_/  \___/         --\_____/       ��      ��   **
//                      **                                                      **
//                      **                                                      **
//                      **********************************************************
//                      **********************************************************
#include<graphics.h>
#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#define M 75
void surprise();
int i,k=0;
int n=1;

struct snake_class{
	int snakex[M];
	int snakey[M];
	int life;
	int fangxiang;
	int snakelen;
	}snake[2];

struct food_class{
	int foodx;
	int foody;
	int yes_no;
	}food;


void fx_panduan(){



			if(GetAsyncKeyState('D')){
				if(snake[0].fangxiang!=3)
					snake[0].fangxiang=1;
			}
			if(GetAsyncKeyState('S')){
				if(snake[0].fangxiang!=4)
					snake[0].fangxiang=2;
				}
			if(GetAsyncKeyState('A')){
				if(snake[0].fangxiang!=1)
					snake[0].fangxiang=3;
			}
			if(GetAsyncKeyState('W')){
				if(snake[0].fangxiang!=2)
				snake[0].fangxiang=4;
			}

			if(GetAsyncKeyState(VK_RIGHT)){
				if(snake[n].fangxiang!=3)
					snake[n].fangxiang=1;
			}
			if(GetAsyncKeyState(VK_DOWN)){
				if(snake[n].fangxiang!=4)
					snake[n].fangxiang=2;
			}
			if(GetAsyncKeyState(VK_LEFT)){
				if(snake[n].fangxiang!=1)
					snake[n].fangxiang=3;
			}
			if(GetAsyncKeyState(VK_UP)){
				if(snake[n].fangxiang!=2)
				snake[n].fangxiang=4;
			}

			if(GetAsyncKeyState(VK_ESCAPE)){
				while(1){
					
					if(GetAsyncKeyState(VK_SPACE))
						break;
				}
			}
}


void food_new(){
		if(food.yes_no==0){
zh:
			food.foodx=rand()%590+20;
			while(food.foodx%10!=0)
				food.foodx++;

			food.foody=rand()%440+20;
			while(food.foody%10!=0)
				food.foody--;

			for(i=0;i<snake[n].snakelen;i++)
				if((snake[n].snakex[i]==food.foodx)&&(snake[n].snakey[i]==food.foody))
					goto zh;

			for(i=0;i<snake[0].snakelen;i++)
				if((snake[0].snakex[i]==food.foodx)&&(snake[0].snakey[i]==food.foody))
					goto zh;
				
			setfillcolor(RED);
			setbkcolor(GREEN);
			fillcircle(food.foodx+5,food.foody+5,5);
			food.yes_no=1;
		}
}

void init(){
	PlaySound("tcsbj.wav", NULL, SND_FILENAME | SND_ASYNC);
	initgraph(640,480);

	IMAGE zhuan;
	loadimage(&zhuan, "zhuan.gif");
	setfillstyle(BS_DIBPATTERN, NULL, &zhuan);


	fillrectangle(0,0,640,480);
	setbkcolor(WHITE);
	setfillcolor(WHITE);
	setfillstyle(BS_HATCHED,HS_DIAGCROSS);
	fillrectangle(20,20,620,460);

	srand(time(NULL));

	snake[0].snakelen=2;
	snake[0].life=1;
	snake[0].fangxiang=2;
	snake[0].snakex[0]=50+rand()%350/10*10;
	snake[0].snakey[0]=30;
	snake[0].snakex[1]=snake[0].snakex[0]-10;
	snake[0].snakey[1]=30;
	if(n!=0){
		snake[n].snakelen=2;
		snake[n].life=1;
		snake[n].fangxiang=4;
		snake[n].snakex[0]=430-rand()%350/10*10;
		snake[n].snakey[0]=330;
		snake[n].snakex[1]=snake[n].snakex[0]+10;
		snake[n].snakey[1]=330;
	}
	food.yes_no=0;
	
}


void play(){
		while(1){
		
			setbkcolor(WHITE);
			setfillcolor(WHITE);

			for(i=0;i<snake[0].snakelen;i++)
			fillrectangle(snake[0].snakex[i],snake[0].snakey[i],snake[0].snakex[i]+10,snake[0].snakey[i]+10);


			if(n!=0){
				for(i=0;i<snake[n].snakelen;i++)
				fillrectangle(snake[n].snakex[i],snake[n].snakey[i],snake[n].snakex[i]+10,snake[n].snakey[i]+10);
			}
			for(i=snake[0].snakelen-1;i>0;i--){
				snake[0].snakex[i]=snake[0].snakex[i-1];
				snake[0].snakey[i]=snake[0].snakey[i-1];
			}
			if(n!=0){
				for(i=snake[n].snakelen-1;i>0;i--){
					snake[n].snakex[i]=snake[n].snakex[i-1];
					snake[n].snakey[i]=snake[n].snakey[i-1];
				}
			}
			if(snake[0].fangxiang==1)
				snake[0].snakex[0]=snake[0].snakex[0]+10;
			if(snake[0].fangxiang==2)
				snake[0].snakey[0]=snake[0].snakey[0]+10;
			if(snake[0].fangxiang==3)
				snake[0].snakex[0]=snake[0].snakex[0]-10;
			if(snake[0].fangxiang==4)
				snake[0].snakey[0]=snake[0].snakey[0]-10;
			if(n!=0){
				if(snake[n].fangxiang==1)
					snake[n].snakex[0]=snake[n].snakex[0]+10;
				if(snake[n].fangxiang==2)
					snake[n].snakey[0]=snake[n].snakey[0]+10;
				if(snake[n].fangxiang==3)
					snake[n].snakex[0]=snake[n].snakex[0]-10;
				if(snake[n].fangxiang==4)
					snake[n].snakey[0]=snake[n].snakey[0]-10;
			}		
			setbkcolor(YELLOW);
			setfillcolor(GREEN);

			for(i=0;i<snake[0].snakelen;i++)
				fillrectangle(snake[0].snakex[i],snake[0].snakey[i],snake[0].snakex[i]+10,snake[0].snakey[i]+10);
			if(n!=0){
				setbkcolor(BLUE);
				setfillcolor(RED);

				for(i=0;i<snake[n].snakelen;i++)
					fillrectangle(snake[n].snakex[i],snake[n].snakey[i],snake[n].snakex[i]+10,snake[n].snakey[i]+10);
			}


			fx_panduan();
			food_new();

			if((snake[0].snakex[0]==food.foodx)&&(snake[0].snakey[0]==food.foody)){
				PlaySound("cd.wav", NULL, SND_FILENAME | SND_ASYNC);
				food.yes_no=0;
				snake[0].snakelen++;
			}
			if(n!=0)
				if((snake[n].snakex[0]==food.foodx)&&(snake[n].snakey[0]==food.foody)){
					PlaySound("cd.wav", NULL, SND_FILENAME | SND_ASYNC);
					food.yes_no=0;
					snake[n].snakelen++;	
				}
			if(snake[0].snakex[0]>610||snake[0].snakex[0]<20||snake[0].snakey[0]>450||snake[0].snakey[0]<20)
				snake[0].life=0;
			if(n!=0)
				if(snake[n].snakex[0]>610||snake[n].snakex[0]<20||snake[n].snakey[0]>450||snake[n].snakey[0]<20)
					snake[n].life=0;
					
			for(i=4;i<snake[0].snakelen;i++)
				if(snake[0].snakex[0]==snake[0].snakex[i]&&snake[0].snakey[0]==snake[0].snakey[i])
					snake[0].life=0;
			if(n!=0){
				for(i=4;i<snake[n].snakelen;i++)
					if(snake[n].snakex[0]==snake[n].snakex[i]&&snake[n].snakey[0]==snake[n].snakey[i])
						snake[n].life=0;
			}
			if(n!=0){
				if((snake[0].snakex[0]==snake[n].snakex[0])&&(snake[0].snakey[0]==snake[n].snakey[0])){
					surprise();
					  k=1;
					  snake[n].life=0;
				}
				for(i=0;i<snake[0].snakelen;i++)
					if((snake[n].snakex[0]==snake[0].snakex[i])&&(snake[n].snakey[0]==snake[0].snakey[i]))
						snake[n].life=0;

				for(i=0;i<snake[n].snakelen;i++)
					if((snake[0].snakex[0]==snake[n].snakex[i])&&(snake[0].snakey[0]==snake[n].snakey[i]))
						snake[0].life=0;

			}


			if(snake[0].life==0||snake[n].life==0)
				break;

			Sleep(150-snake[n].snakelen-snake[0].snakelen);
				
		}
}

void gameover(){
	
	if(k==0){
	PlaySound("js.wav", NULL, SND_FILENAME | SND_ASYNC);
	outtextxy(200,200,"��Ϸ����,���ڴ����������Ժ�");
	Sleep(5000);
	}
	closegraph();
	system("cls");
	
	if(k==0){
		printf("\n\n\n\n\n\t\t\t���ߵķ����ǣ�%d��ɫ�ߵ��ǣ�%d\n\n\n\n\n\n",100*(snake[0].snakelen-2),100*(snake[n].snakelen-2));
		if(snake[0].life==1)
			printf("\t\t\t\t��ɫ��ʤ����\n");
		else printf("\t\t\t\t��ɫ��ʤ��\n");
		printf("\n\n\t\ts������һ�Σ�q���˳���");
	}
	
	else {
		system("color d4");
		printf("\n\n\n\n\n\n\t\t�氮�޼ۣ�û����Ӯ��������������Ӯ�ң�ף�Ҹ�");
		Sleep(500);
		printf("\n\n\n\n\n\n   �������ǲ��ܺ��Լ�����ϲ��������һ����ô���㽫�������е���ҫ�ͲƸ������������ȵ�ҹ���λأ��޷�����ʱ����Ҳͬ�������ᡣ");
		Sleep(4000);
		system("cls");
		system("color a0");
		printf("\n\n\n\n\n\n\t\t�氮�޼ۣ�û����Ӯ��������������Ӯ�ң�ף�Ҹ�");
		printf("\n\n\n\n\n\n   һ�������飬���Բ��������İ��ˡ��������İ��ˣ����Ա��˲Ż������İ����������Ǵ�������һ���ľ�ս֮�У�Ҳ������ƾ��һ�ݶ������������氮���ܴݻٶԷ�����־������Ϊʤ��");
		Sleep(4000);
		system("cls");
		system("color 54");
		printf("\n\n\n\n\n\n\t\t�氮�޼ۣ�û����Ӯ��������������Ӯ�ң�ף�Ҹ�");
		printf("\n\n\n\n\n\n   �����ǳ�ʵ�˵������� ����ʢ���˾ƵľƱ���--ӡ�� ��̩���");
		Sleep(4000);
		system("cls");
		system("color b1");
		printf("\n\n\n\n\n\n\t\t�氮�޼ۣ�û����Ӯ��������������Ӯ�ң�ף�Ҹ�");
		printf("\n\n\n\n\n\n   ���ݻٵİ�, һ�������޽���, �ͱ�ԭ������ΰ, ����, ����ǿ��--Ӣ��ɯʿ����\n\n\n\n\n��Ϸ�������¼��أ����Ժ󣺣���������");
		Sleep(6000);
		printf("\n\n\n\t\t\t\t\t\t\t��S�����¿�ʼ��\n\t\t\t\t\t\t\tq���˳�������");
	}
	fflush(stdin);
	
}

void load(){
	system("color b1");
	PlaySound("tcs.wav", NULL, SND_FILENAME | SND_ASYNC);
	printf("\n\n\n\t\t\t��ӭ���汾��С��Ϸ��\n\n\n\n");
	printf("\t\t\t��Ϸ��λ˵����\n\n\n\n");
	printf("\t���1��w a s d��\t\t\t���2���������\n\tesc:��ͣ\t\t\t�ո��������\n\n\n\n");
	printf("�緢��bug���֮���ߡ�\n");
	printf("�����������������\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t���ߣ���Ƥ��\n\t\t\t\t\t\t\t\tqq:1191785897");
	fflush(stdin);
	getch();
	system("cls");
	printf("��Ϸ����\n\n\n\n\t��ҷֱ�����Լ�������ʳ���\n\t˭����ͷײǽ����˭�䣬��������\n\t�ȼ��㣬�����ֿ�λʱ�Ż��÷���\n\t�ж���Ӯ��\n\n\n\n\n\n\n\n\n\n\n\n\t\t����ǿ�ҽ���˫�˰棬���˰�Ϊ�������ģʽ����˫��ģʽ��\n���ǵ�������������ܴ��������벻����Ч��Ŷ�������Բ⣬�о�ϲ(��o��)Ŷ");
	fflush(stdin);
	getch();
}

void surprise(){
	setbkcolor(COLORREF RGB(255,181,197));
	cleardevice();
	IMAGE zyq;
	loadimage(&zyq, "zyq.gif");
	setfillstyle(BS_DIBPATTERN, NULL, &zyq);
	fillrectangle(20,20,620,460);
	PlaySound("zyq.wav", NULL, SND_FILENAME | SND_ASYNC);
	IMAGE sur;
	loadimage(&sur,"sur.GIF");
	putimage(90,90,&sur);
	Sleep(7000);

	
}

void select(){
	system("cls");
	printf("\n\n\n\t��ѡ����Ϸģʽ��\n\n\n\t1   ����\t\t  2   ˫��\n");
	n=getch()-'0';
	n--;

}



int main (){
	
		load();
		select();
cs:
		init();
		play();
		gameover();
		while(1){
			if(GetAsyncKeyState('Q'))
				break;
			if(GetAsyncKeyState('S'))
				goto cs;
		}
		return 0;
}