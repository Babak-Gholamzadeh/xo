#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void display(void);
int dooz(int, int);
char a[10][10];
int n;
void gotoxy(int x,int y)
{
    COORD pos;
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );

    if (INVALID_HANDLE_VALUE != hConsole)
    {
        pos.X = x;
        pos.Y = y;

        SetConsoleCursorPosition( hConsole, pos );
    }
}
int main(){
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\tWelcome To Game" << "\n\n\t\t      Please Press Any Key To Continue . . ."
	<< "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Programmer: Babak Gholamzadeh";
	gotoxy(61,13);
	getch();
newgame:
	// clrscr();
    system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t  Enter The Number For Table:" << "\n\n\t\t\t\t3<=\t  >=10";
	gotoxy(39,13);
	cin >> n;
	if ((n<3)||(n>10))
		goto newgame;

	int x,y,c=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			a[i][j]=' ';

	display();

	while(c<=n*n){
	loop1:
		cout << "Player 1 Select (1 1)X:";
		cin >> x >> y;
		if (a[x][y]==' '){
			a[x][y]='X';
			c++;
			display();
		}
		else{
			cout << "Not Valid (Again)\n";
			goto loop1;
		}
		if (dooz(x,y)==1){
			cout << " Player 1 (X)";
			break;
		}

		if (c>n*n)
			break;

	loop2:
		cout << "Player 2 Select (1 1)O:";
		cin >> x >> y;
		if (a[x][y]==' '){
			a[x][y]='O';
			c++;
			display();
		}
		else{
			cout << "Not Valid (Again)\n";
			goto loop2;
		}
		if (dooz(x,y)==1){
			cout << " Player 2 (O)";
			break;
		}
	}

	cout << "\n\nStart New Game(Y/N):";
	if (getch()=='y')
		goto newgame;

	return 0;
}
void display(void){
	int i,j;
	// clrscr();
    system("cls");
	cout << " ";

	for (i=0;i<n;i++)
		cout << "     " << i;

	cout << "\n    ";

	for (i=0;i<n;i++)
		cout << "_____ ";

	for (i=0;i<n;i++){
		cout << endl << i << "  |";
		for (j=0;j<n;j++)
			cout << "  " << a[i][j] << "  |";
		cout << "\n   |";
		for (j=0;j<n;j++)
			cout << "_____|";
	}
	cout << endl << endl;
}
int dooz(int x,int y){
	char f;
	int i,j;
	if(a[0][0]!=' '){
		f='1';
		for (i=1;i<n;i++)
			if (a[i][i]!=a[0][0]){
				f='0';
				break;
				}
		if (f=='1')
				goto win;
	}



	if (a[0][n-1]!=' '){
		j=n-1;
		f='1';
		for (i=1;i<n;i++){
			--j;
			if (a[i][j]!=a[0][n-1]){
				f='0';
				break;
			}
		}
		if (f=='1')
			goto win;
	}

	if (a[x][0]!=' '){
		f='1';
		for (j=1;j<n;j++)
			if (a[x][j]!=a[x][0]){
				f='0';
				break;
			}
		if (f=='1')
			goto win;
	}

	if (a[0][y]!=' '){
		f='1';
		for (i=1;i<n;i++)
			if (a[i][y]!=a[0][y]){
				f='0';
				break;
			}
		if (f=='1')
			goto win;
	}



	if (f=='1'){
win:
		cout << "YOU WIN";
		return 1;
	}
}
