# include "iGraphics.h"
#include<stdio.h>

int x = 100, y = 400, r = 15,k=0,s=0,k1=0,flag=0,w=40,s5=0,k2=0,x1,x2,r1=0;
int dx,dy, rec_x=760,rec_y=0,rec_x1=360,rec_x2=1160,rec_x3=1560,k3=0,k4=0;
int dy1=100,dy2=250,dy3,dy4,space=150;
char s1[4],highscore[4];
FILE *f1;
/*
	function iDraw() is called again and again by the system.

	*/

void random()
{
    srand(time(NULL));
     x1=(rand()%300); //generating a random number that increases the height of blocks
     x2=(rand()%300);
}

void leftshift()
{
    rec_x -= dx;
    rec_x1 -= dx;
    rec_x2 -= dx;
    rec_x3-=dx;

    if(rec_x<-40)
    {
        flag=0;                 //this flag remains zero when birdenters the wall
        rec_x=rec_x+800;

        dy1=dy1+x1;
        if(dy1>450)
        {
            dy1=dy1-350;
        }
    }
    if(rec_x1<-40)
    {
        flag=0;
        rec_x1=rec_x1+800;
         dy2=dy2+x2;
        if(dy2>450)
        {
            dy2=dy2-350;
        }
    }


}


void score()
{
    if(flag==0&&((( y+r)<(rec_y+dy1+space) && (y-r)>(rec_y+dy1) && (x+r)==rec_x+40 )|| ((y+r)<(rec_y+dy2+space) && (y-r)>(rec_y+dy2) && (x+r)==rec_x1+40 )))// || (( y+r)<(rec_y+dy3+space) && (y-r)>(rec_y+dy3) && (x+r)==rec_x+w )|| ((y+r)<(rec_y+dy4+space) && (y-r)>(rec_y+dy4) && (x+r)==rec_x3+w )))

    {
        s=s+1;
        flag=1; //the bird passes the wallspace and score increases
    }
    itoa(s,s1,10);
    iSetColor(255,255,255);
    iText(740,30,s1,GLUT_BITMAP_TIMES_ROMAN_24);
}


void gameover()
{
    if(((x+r)>=rec_x  &&  (x-r)<=rec_x+w && (y-r)<=(rec_y+dy1))||((x+r)>=rec_x  &&  (x-r)<=rec_x+w && (y+r)>=(rec_y+dy1+space))||((x+r)>=rec_x1  &&  (x-r)<=rec_x1+w && (y-15)<=(rec_y+dy2))||((x+r)>=rec_x1  &&  (x-r)<=rec_x1+w && (y+r)>=(rec_y+dy2+150)))//||((x+r)>=rec_x2  &&  (x-r)<=rec_x2+w && (y-r)<=(rec_y+dy3))||((x+r)>=rec_x  &&  (x-r)<=rec_x+w && (y-r)<=(rec_y+dy1)))
    //co ordinnates of wall and bird position is same
    {
        k=1;        //flag that makes a collision;
        iPauseTimer(0);
        //drawTexture(0,0,game_over);

       PlaySound( NULL,0 , 0);

    }
}

void ballChange(){
    if(r1==0)           //flag variable that remains bird flying, if ri=1; bird stops moving
        {
            y -= dy;

	if(y<15)
    {
        y=15;
        k=1;
        iPauseTimer(0);
    }
    if((y-r)==(rec_y+dy1) && (x+r)>=rec_x+40 && (x-r)<=rec_x)
    {
        y=rec_y+dy1+r;
    }
    if((y-r)==(rec_y+dy2) && (x+r)>=rec_x1+40 && (x-r)<=rec_x1)
    {
        y=rec_y+dy2+r;
    }
    }

}


void iDraw() {
	//place your drawing codes here
	iClear();
	glClearColor(1.0,1.0,1.0,1.0);
	itoa(s5,highscore,10);

	if (k1==0)//homescreen shows
    {
        drawTexture(0,0,frontpage);
        iSetColor(0,0,0);
        iText(400,350,"START",GLUT_BITMAP_HELVETICA_18);
        iText(400,320,"HIGH SCORE",GLUT_BITMAP_HELVETICA_18);
        //iText(400,290,"HELP",GLUT_BITMAP_HELVETICA_18);
        iText(400,290,"QUIT",GLUT_BITMAP_HELVETICA_18);


    }

    if(k1==1)//gameplay starts
    {
        iSetColor(20, 200, 300);

        iFilledRectangle(0,400,800,400);
        drawTexture(0,0,character);
        drawTexture(x-r,y-r,smurfTexture);

       // iFilledCircle(x, y, r);
	//iFilledRectangle(10, 30, 20, 20);
        iSetColor(20, 200, 0);


	iFilledRectangle(rec_x,rec_y, w, dy1);
    iFilledRectangle(rec_x,rec_y+dy1+space, w, 600-space-dy1);
    iFilledRectangle(rec_x1, rec_y, w, dy2);
    iFilledRectangle(rec_x1,rec_y+dy2+space, w, 600-space-dy2);

    iSetColor(0,0,0);

    //iFilledRectangle(0, 0, 800, 70);
    //iSetColor(0,0,0);
    iFilledRectangle(700,10,100,65);
    iText(720,12,"SCORE");



    score();
    if(s>=s5)
        {
            s5=s;//s5=highscore
            f1=fopen("High Score.txt","w");
            fprintf(f1,"%d",s5);
            fclose(f1);
        }

    gameover();
    if(k==1)
    {
        //k4=1;
        iClear();
        iSetColor(0,0,0);
         drawTexture(0,0,game_over);
        iText(400,300,"Game over",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,250,"You have scored",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(575,250,s1,GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(400,60,"Press c to continue");
        iText(400,20,"Press q to quit");


    }
    }
    if(k3==1)
    {
        iClear();
        iSetColor(0,0,0);

        iText(400,250,"High Score",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(525,250,highscore,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,50,"Back",GLUT_BITMAP_TIMES_ROMAN_24);

    }

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}
void mouseOver(int mx,int my){
printf("%d %d",mx,my);
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    if(k1==0)//homescreen shows
    {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  &&  mx>= 400  &&  mx<=465  &&  my>=350  &&  my<=375)
    {
        //place your codes here
        k1=1;
        iSetTimer(35,leftshift);//rectangle moves
        dx=5;
        if(s>10)
        {
            iSetTimer(25,leftshift);
            dx=8;
        }
        iSetTimer(40,ballChange);//bird moves due to gravity
        dy=5;
        random();
        PlaySound("sound.wav", NULL, SND_ASYNC | SND_LOOP);

    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  &&  mx>= 400  &&  mx<=690  &&  my>=315  &&  my<=345)
    {
        k3=1;
    }
    }
    if(k3==1 && k1==0)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  &&  mx>= 400  &&  mx<=450  &&  my>=50  &&  my<=75)
    {
        k3=0;
    }

    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=396  && mx<=475  && my>=286  &&my<=318)
    {
        //place your codes here
    exit(0);

    }
}


/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	else if (key== 'w')
    {
        y+=10;
    }

    else if (key== 'p')
    {
        iPauseTimer(0);
        r1=1;
        PlaySound(NULL,0,0);
    }
    else if (key== 'r')
    {
       iResumeTimer(0);
       r1=0;
        PlaySound("sound.wav", NULL, SND_ASYNC | SND_LOOP);
    }
    if (key=='c')
    {
       //k=0;
       k1=0;
       //k4=0
    }


	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	if (key == GLUT_KEY_UP) {
		y+=50;
		if(y>585)
        {
            y=585;
            k=1;
        }
        if(k==1)
        {
           y=y;
        }
	}


	//place your codes for other keys here
}


int main() {
        f1=fopen("High Score.txt","r");
        fscanf(f1,"%d",&s5);
        fclose(f1);
   /* iSetTimer(60,leftshift);
    dx=5;
    random();
    iSetTimer(40,ballChange);
    dy=3;*/
    //random();

   // PlaySound("sound.wav", NULL, SND_ASYNC | SND_LOOP);

	//place your own initialization codes here.
	iInitialize(800, 600, "demo");
	return 0;
}
