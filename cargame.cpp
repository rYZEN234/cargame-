#include<iostream>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetstdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] ={ ' ','_+','_+',' '
                    '_+','_+','_+','_+'
                    ' ','_+','_+',' ',
                    '_+','_+','_+','_+'};

int carPos=WIN_WIDTH/2;
int score =0;

void gotoxy(int x,int y){
    CursorPosition.X=x;
    cursorPosition.Y=y;
    SetConsoleCursorposition(console,cursorPosition);
}
void setcursor(bool visible,DWORD size){
    id(size==0)
        size=20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible=visible;
    lpCursor.dwsize =size;
    SetConsoleCursorInfo(console,&lpCursor);

}
void drawBorder(){
    for(int i=0;i<SCREEN_HEIGHT;i++){
        for(int j=0;j<17;j++){
            gotoxy(0+j,i); cout<<"_+";
            gotoxy(WIN_WIDTH-j,i);
            cout<<"_+";
        }
    }
    for(int i=0;i<SCREEN_HEIGHT;i++){
        gotoxy(SCREEN_WIDTH,i);
        cout<<"_+";
    }
}
void genEnemy(ind ind){
    if(enemyFlag[ind]==true){
        gotoxy(enemyX[ind],enemyY[ind]);
            cout<<"****";
        gotoxy(enemyX[ind],enemyY[ind]+1);
        cout<<" ** "; 
        gotoxy(enemyX[ind],enemyY[ind]+2);
        cout<<"****"; 
        gotoxy(enemyX[ind],enemyY[ind]+3);
        cout<<" ** ";      
        
    }
}
void eraseEnemy(int ind){
    if( enemyFlag[ind]==true){
    gotoxy(enemyX[ind],enemyY[ind]);
        cout<<"    ";
    gotoxy(enemyX[ind],enemyY[ind]+1);
        cout<<"    "; 
    gotoxy(enemyX[ind],enemyY[ind]+2);
        cout<<"    ";
    gotoxy(enemyX[ind],enemyY[ind]+3);
        cout<<"    ";
    }                       
}
void resetEnemy(int ind){
    eraseEnemy(ind);
    enemyY[ind]=1;
    genEnemy(ind);
}
void drawCar(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            gotoxy(j+carpos,i+22);
            cout<<car[i][j];
        }
    }
}
void erasecar(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            gotoxy(j+carpos,i+22);
            cout<<" ";
        }
    }        
}
int collision(){
    if(enemyY[0]+4>=23){
        if(enemy[0]+4-carPos >=0 && enemyX[0]+4-carPos<9 ){
        return 1;
        }
    }
    return 0;
}
void game(){
    system("cls");
    cout<<endl;
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\t-------GameOver-----------"<<endl;
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\tPress any key to go back to menu.";
    getch();
}
void updateScore(){
    gotoxy(WIN_WIDTH +7,5);
    COUT<<"Score: "<<Score<<endl;
}
void instruction(){
    system("cls");
    cout<<"Instruction";
    cout<<"\n-------------------";
    cout<<"\n Avoid cars moving left or right";
    cout<<"\n\n Press 'a' to move left ";
    cout<<"\nPress 'd' to move right";
    cout<<"\n Press 'escape' to exit";
    cout<<"\n\n Press any key to go back to menu ";
    getch();
}
void play(){
    carPos = -1+WIN_WIDTH/2;
    score =0;
    enemyFlag[0]=1;
    enemyFlag[1] =1;
    enemyY[0]=enemyY[1]=1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 7,2);
    Cout<<"Car Game";
    gotoxy(WIN_WIDTH + 6,4);
    Cout<<"---------";
    gotoxy(WIN_WIDTH + 6,6);
    COUT<<"---------";
    gotoxy(WIN_WIDTH + 7,12);
    COUT<<"Control";
    gotoxy(WIN_WIDTH + 7,13);
    COUT<<"---------";
    gotoxy(WIN_WIDTH + 2,14);
    COUT<<"A key - Left";
    gotoxy(WIN_WIDTH + 2,15);
    COUT<<"D key -Right";
    gotoxy(18,5);
    cout<<"Press any key to start";
    getch();
    gotoxy(18,5);
    cout<<"                        ";

    while(1){
        if(kbhit()){
            char ch=getch();
            if(ch=='a'||ch=='A'){
                if(carPos>18)
                    carPos -=4;
            }
            if(ch=='d'|| ch=='D'){
                if(carPos<50)
                    carPos+4;
            }
            if(ch==27){
                break;
            }
        }
        deawCar();
        drawEnemy(0);
        draeEnemy(1);
        if(collision()==1){
            gameover();
            return;
        }
        Sleep(50);
        erasecar();
        eraseEnemy(0);
        eraseEnemy(1);

        if(enemyY[0]==10)
            if(enemyFlag[1]==0)
                enemyFlag[1]=1;
        if(enemyFlag[0]==1)
            enemyY[0] += 1;
        if(enemyFlag[1]==1)
            enemyY[1] += 1;
        if(enemyY[0]>SCREEN_HEIGHT-4){
            resetEnemy(0);
            score++;
            updatescore();

        }
        if(enemy[1]>SCREEN_HEIGHT-4){
            resetEnemy(1);
            score++;
            updateScore();
        }
                  
    }
    
    
}
int main{
    setcursor(0,0);
    srand( (umsigned)time(NULL));

    do{
        system("cls");
        gotoxy(10,5);
        cout<<"------------------------------";
        gotoxy(10,6);
        cout<<"|            Car Game         |";
        gotoxy(10,7;)
        cout<<"------------------------------";
        gotoxy(10,9);
        cout<<"1.  Start Game";
        gotoxy(10,10);
        cout<<"2. Instruction";
        gotoxy(10,11);
        cout<<"3.Quit";
        gotoxy(10,13);
        cout<<"select option: ";
        char op = grtche();
        if(op=='1')play();
        elseif(op =='2')instruction();
        elseif(op=='3') exit(0);
    }
    while(1);
        return 0;
    
}
