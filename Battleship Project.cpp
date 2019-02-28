#include<iostream>
using namespace std;
void Greeting(char a[10][10]){
	cout<<"**** Welcome to Battle Ships Game ****\n\n";
	cout<<"Right now, the sea is empty.\n\n";
	cout<<"   "<<"0123456789"<<endl;
	for (int i = 0; i < 10; i++) {
            cout<<i<<" |";
            for (int j = 0; j < 9; j++) {

                cout<<a[i][j];
            }
            cout<<" |"<<i;
            cout<<endl;
        }
        cout<<"   "<<"0123456789"<<endl;
}
void PDeploy(char a[10][10]){
	int cnt=0;
	cout<<"\nDeploy your ships: \n\n";
	int i=0;
	int j=0;
	while(cnt<5){
		cout<<"Enter X coordinate for your "<<cnt+1<<" ship: ";
		cin>>i;
		cout<<"Enter Y coordinate for your "<<cnt+1<<" ship: ";
		cin>>j;
		if(i<10 && j<10 && a[i][j]!='1'){
			a[i][j]='1';
			cnt++;
		}
		else{
			cout<<"Wrong Choice. Enter valid choices..\n";
		}
	}
	cout<<"   "<<"0123456789"<<endl;
	for (int i = 0; i < 10; i++) {
            cout<<i<<" |";
            for (int j = 0; j < 10; j++) {

                if(a[i][j]=='1'){
                	cout<<"@";
				}
				else{
					cout<<a[i][j];
				}
            }
            cout<<"|"<<i;
            cout<<endl;
        }
        cout<<"   "<<"0123456789\n\n"<<endl;
}
void CDeploy(char a[10][10]){
	int cnt=0;
	cout<<"Computer is Deploying Ships: \n";
	while(cnt<5){
		int i=0;
		int j=0;
		i=rand()%10;
		j=rand()%10;
		if(a[i][j]!='1' && a[i][j]!='2'){
			a[i][j]='2';
			cout<<++cnt<<". ship DEPLOYED\n";
			continue;
		}
	}
	
	cout<<"--------------------------";
}
int Toss(){
	int c;
	int num=0;
	cout<<"Choose Heads(1) or Tails(0) (1,0): ";
	cin>>c;
	num=rand() % 2;
	if(num==c){
		cout<<"\nYou Won The Toss";
		cout<<"\nYou Play First";
		return 1;
	}
	else{
		cout<<"\nComputer Won the Toss";
		cout<<"\nComputer Plays First";
		return 0;
	}
}
void End(char a[10][10],int cnt1, int cnt2){
	cout<<"   "<<"0123456789"<<endl;
	for (int i = 0; i < 10; i++) {
            cout<<i<<" |";
            for (int j = 0; j < 10; j++) {
            	if(a[i][j]=='1'){
		                	cout<<"@";
						}
						else if(a[i][j]=='2'){
							cout<<" ";
						}
						else if(a[i][j]=='*'){
							cout<<" ";
						}
						else{
							cout<<a[i][j];
						}
            }
            cout<<" |"<<i;
            cout<<endl;
        }
        cout<<"   "<<"0123456789\n\n";
        cout<<"Your Ships: "<<cnt1<<" | Computer ships: "<<cnt2;
        if(cnt1==0){
        	cout<<"\nGame Over. Better Luck Next Time :)";
        }
        else if(cnt2==0){
        	cout<<"\nHooray! You win the battle :)";
        }
}

void Battle(char a[10][10]){
	cout<<"\nTime to Toss a Coin\n";
	int t=Toss();
	int cnt1=0;
	int cnt2=0;
	if(t==1){
		while(cnt1<5 && cnt2<5){
			int i=0;
			int j=0;
			cout<<"\n   "<<"0123456789"<<endl;
			for (int i = 0; i < 10; i++) {
		            cout<<i<<" |";
		            for (int j = 0; j < 10; j++) {
		
		                if(a[i][j]=='1'){
		                	cout<<"@";
						}
						else if(a[i][j]=='2'){
							cout<<" ";
						}
						else if(a[i][j]=='*'){
							cout<<" ";
						}
						else{
							cout<<a[i][j];
						}
		            }
		            cout<<"|"<<i;
		            cout<<endl;
		        }
        cout<<"   "<<"0123456789\n\n"<<endl;
			cout<<"\n\nYOUR TURN\n";
			cout<<"Enter X coordinate: ";
			cin>>i;
			cout<<"Enter Y coordinate: ";
			cin>>j;
			while(i<0 && j<0 && i>9 && j>9 && a[i][j]!='-'){
				cout<<"Enter X coordinate: ";
				cin>>i;
				cout<<"Enter Y coordinate: ";
				cin>>j;
			}
			if(a[i][j]=='2'){
				cout<<"\nBoom! You sunk the ship!";
				cnt2++;
				a[i][j]='!';
			}
			else if(a[i][j]=='1'){
				cout<<"\nOh no, you sunk your own ship :(";
				cnt1++;
				a[i][j]='x';
			}
			else{
				cout<<"\nSorry, you missed";
				a[i][j]='-';

			}
			i=0;
			j=0;
			cout<<"\n\nCOMPUTER'S TURN\n";
			i=rand()%10;
			j=rand()%10;
			while(i<0 && j<0 && i>9 && j>9 && a[i][j]!='*'){
				i=rand()%10;
				j=rand()%10;
			}
			if(a[i][j]=='1'){
				cout<<"The Computer sunk one of your ships!";
				cnt1++;
				a[i][j]='x';
			}
			else if(a[i][j]=='2'){
				cout<<"The Computer sunk one of its own ships";
				cnt2++;
				a[i][j]='!';
			}
			else{
				cout<<"Computer missed";
				a[i][j]='*';
			}
			cout<<"\n\n";
			cout<<"Your Ships: "<<5-cnt1<<" | Computer ships: "<<5-cnt2;
		}
	}
	else if(t==0){
		while(cnt1<5 && cnt2<5){
			int i=0;
			int j=0;
			cout<<"\n   "<<"0123456789"<<endl;
			for (int i = 0; i < 10; i++) {
		            cout<<i<<" |";
		            for (int j = 0; j < 10; j++) {
		
		                if(a[i][j]=='1'){
		                	cout<<"@";
						}
						else if(a[i][j]=='2'){
							cout<<" ";
						}
						else if(a[i][j]=='*'){
							cout<<" ";
						}
						else{
							cout<<a[i][j];
						}
		            }
		            cout<<"|"<<i;
		            cout<<endl;
		        }
        cout<<"   "<<"0123456789\n\n"<<endl;
			cout<<"\n\nCOMPUTER'S TURN\n";
			i=rand()%10;
			j=rand()%10;
			while(i<0 && j<0 && i>9 && j>9 && a[i][j]!='*'){
				i=rand()%10;
				j=rand()%10;
			}
			if(a[i][j]=='1'){
				cout<<"The Computer sunk one of your ships!";
				cnt1++;
				a[i][j]='x';
			}
			else if(a[i][j]=='2'){
				cout<<"The Computer sunk one of its own ships";
				cnt2++;
				a[i][j]='!';
			}
			else{
				cout<<"Computer missed";
				a[i][j]='*';
			}
			i=0;
			j=0;
			cout<<"\n\nYOUR TURN\n";
			cout<<"Enter X coordinate: ";
			cin>>i;
			cout<<"Enter Y coordinate: ";
			cin>>j;
			while(i<0 && j<0 && i>9 && j>9 && a[i][j]!='-'){
				cout<<"Enter X coordinate: ";
				cin>>i;
				cout<<"Enter Y coordinate: ";
				cin>>j;
			}
			if(a[i][j]=='2'){
				cout<<"\nBoom! You sunk the ship!";
				cnt2++;
				a[i][j]='!';
			}
			else if(a[i][j]=='1'){
				cout<<"\nOh no, you sunk your own ship :(";
				cnt1++;
				a[i][j]='x';
			}
			else{
				cout<<"\nSorry, you missed";
				a[i][j]='-';
			}
			cout<<"\n\n";
			cout<<"Your Ships: "<<5-cnt1<<" | Computer ships: "<<5-cnt2;
		}
	}
	End(a,5-cnt1,5-cnt2);
}

int main(){
	char ocean[10][10]={};
	Greeting(ocean);
	PDeploy(ocean);
	CDeploy(ocean);
	Battle(ocean);
}
