#include<conio.h>
#include<iomanip.h>
#include<stdio.h>             // Header Files Used In Project...
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
			      // Global Variables And Functions...
typedef int AB;
typedef char ADI;

void game_selection();
void main_display();
ADI any_key;

class Game                                           // Class
{
public:
	ADI winner[20]; AB  score;
	Game()                                    // Constructor...
	{
	strcpy(winner,"No Data"); score = 0;
	}
	void input(ADI champ[20],AB marks)
	{
	strcpy(winner,champ); score = marks;
	}
	void input(ADI champ[20])                // Polymorphism...
	{
	strcpy(winner,champ);
	}
	void output(AB gc)
	{
	cout<<winner;
	for(AB i=strlen(winner);i<=20;i++)
	cout<<" ";
	if(gc==0)
	cout<<score;
	cout<<endl;
	}

}race_obj,guess_obj,tic_obj,casino_obj;





		     //  TIC TAC TOE...


void topline_ttt();                 void winner_interface_ttt();
void draw_interface_ttt();          void user_interface_ttt();
void tic_tac_toe();                 void tic_tac_toe_play();
void tic_tac_toe_about();           void tic_tac_toe_winner();

ADI *player_ttt,player_name_ttt1[15],player_name_ttt2[15],symbol;
ADI box1='1',box2='2',box3='3',box4='4',box5='5',box6='6',box7='7',box8='8',box9='9';
AB i,chance_ttt=0,draw_checker=0,game_selector,tic_tac_toe_selector,player_choice_ttt;




void topline_ttt()        // To Print Top Line Border Of Each Page...
{
	clrscr();
	cout<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<setw(45)<<"TIC TAC TOE"<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<endl;
}
void winner_interface_ttt()     //To Print Winner Interface...
{
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(38)<<player_ttt<<" WON"<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";

	fstream file_ttt;
	file_ttt.open("Adi_TTT.dat",ios::in|ios::binary|ios::app);
	tic_obj.input(player_ttt);
	file_ttt.write((ADI*)&tic_obj,sizeof(tic_obj));
	file_ttt.close();
	draw_checker++;
}

void draw_interface_ttt()   //To Print Game Draw Interface...
{
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(43)<<"GAME DRAW"<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
}

void user_interface_ttt()    //To Print Game Interface...
{
	topline_ttt();
	cout<<"	         Player 1 = X                          Player 2 = O       "<<endl;
	cout<<endl;
	cout<<"      			         บ       บ      "<<endl;
	cout<<setw(30)<<"   "<<box1<<"  บ   "<<box2<<"   บ    "<<box3<<endl;
	cout<<"             	           ออออออบอออออออบออออออ"<<endl;
	cout<<"			         บ       บ      "<<endl;
	cout<<setw(30)<<"   "<<box4<<"  บ   "<<box5<<"   บ    "<<box6<<endl;
	cout<<"                           ออออออบอออออออบออออออ"<<endl;
	cout<<"	                         บ       บ      "<<endl;
	cout<<setw(30)<<"   "<<box7<<"  บ   "<<box8<<"   บ    "<<box9<<endl;
	cout<<"      			         บ       บ      "<<endl;

}

void tic_tac_toe_play()    // To Input Player Name as well as Play...
{
	topline_ttt();
	cout<<endl<<setw(43)<<"PLAYERS"<<endl<<endl;
	cout<<endl<<endl<<"Enter Player1 Name : ";
	gets(player_name_ttt1);
	cout<<endl<<endl<<"Enter Player2 Name : ";
	gets(player_name_ttt2);

	do
	{
	user_interface_ttt();
	if(chance_ttt%2==0)
	{
	player_ttt=player_name_ttt1; symbol='X';
	}
	else
	{
	player_ttt=player_name_ttt2; symbol='O';
	}
	cout<<endl<<endl<<endl<<setw(20)<<player_ttt<<" enter your choice = ";
	cin>>player_choice_ttt;
	switch(player_choice_ttt)
	{
	case 1:   box1 = symbol;break;
	case 2:   box2 = symbol;break;
	case 3:   box3 = symbol;break;
	case 4:   box4 = symbol;break;
	case 5:   box5 = symbol;break;
	case 6:   box6 = symbol;break;
	case 7:   box7 = symbol;break;
	case 8:   box8 = symbol;break;
	case 9:   box9 = symbol;break;
	default:  chance_ttt-- ;break;
	}
	if(box1 == box2 && box2 == box3)  { winner_interface_ttt();break;}
	else if(box4 == box5 && box5 == box6)  { winner_interface_ttt();break;}
	else if(box7 == box8 && box8 == box9)  { winner_interface_ttt();break;}
	else if(box1 == box4 && box4 == box7)  { winner_interface_ttt();break;}
	else if(box2 == box5 && box5 == box8)  { winner_interface_ttt();break;}
	else if(box3 == box6 && box6 == box9)  { winner_interface_ttt();break;}
	else if(box1 == box5 && box5 == box9)  { winner_interface_ttt();break;}
	else if(box3 == box5 && box5 == box7)  { winner_interface_ttt();break;}
	chance_ttt++;

}       while(chance_ttt!=9);

	if(draw_checker==0)
	draw_interface_ttt();
	box1='1',box2='2',box3='3',box4='4',box5='5',box6='6',box7='7',box8='8',box9='9';
}

void tic_tac_toe_winner()    // To save Last Winners...
{
	topline_ttt();
	fstream file_ttt;
	file_ttt.open("Adi_TTT.dat",ios::in|ios::out|ios::binary);
	cout<<"The Best Players : "<<endl<<endl;
	cout<<setw(24)<<"Name"<<endl<<endl;
	AB wno_ttt=1;
	while(!file_ttt.eof())
	{
	file_ttt.read((ADI*)&tic_obj,sizeof(tic_obj));
	cout<<setw(18)<<wno_ttt++<<". ";
	tic_obj.output(1);
	}
	file_ttt.close();
}

void tic_tac_toe_about()     // To Print About The Game...
{
	topline_ttt();
	cout<<"1."<<"Tic Tac Toe is also called 'Noughts and Crosses'.";
	cout<<endl<<endl<<"2."<<"Tic Tac Toe is a game for two player,X and O.";
	cout<<endl<<endl<<"3."<<"Each take turns marking the spaces in grid.";
	cout<<endl<<endl<<"4."<<"Skills Required :  Strategy, Tactics, and Good Observation.";
	cout<<endl<<endl<<"5."<<"Player needs to mark three consecutive grid to Win!!!";
	cout<<endl<<endl<<endl<<endl<<"Press any key...";
	any_key = getch();
	tic_tac_toe();
}

void tic_tac_toe()    // To print tic tac toe screen to choose...
{
	topline_ttt();
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 1."<<"    PLAY       บ"<<"                                 บ 2."<<"   WINNER      บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 3."<<"    ABOUT      บ"<<"                                 บ 4."<<"   BACK        บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<endl<<setw(49)<<"Enter Your Choice ->  ";
	cin>>tic_tac_toe_selector;

	switch(tic_tac_toe_selector)
	{
	case 1  :tic_tac_toe_play();any_key=getch();tic_tac_toe();break;
	case 2  :tic_tac_toe_winner();any_key=getch();tic_tac_toe();break;
	case 3  :tic_tac_toe_about();tic_tac_toe();break;
	case 4  :game_selection();break;
	default :tic_tac_toe();
	}
}





			   // RACING...

void racing_game_play();                void racing_game_about();
void racing_game_winner();              void racing_game();
void topline_r();                       void car();
void move_car_down(AB);                void score();
void racing_game_winner_store();        void car_cleaner();
void full_screen_cleaner();

#define LEFT 75
#define RIGHT 77

AB  racing_game_selector,line,k,score_r=0,speed=100,first_time=0;
AB  origin=8,car_path=0,line_option=2,car_cleaner_path;
ADI ch1,ch2,player_name_r1[25];


void full_screen_cleaner()      //  To clear the screen....
{
	window(1,1,80,25); clrscr();
}

void score()       // To Print Basics Things On Screen...
{
	window(2,18,79,23);
	cout<<"Press Enter To Exit...";
	window(55,11,79,20);
	cout<<"Score ";
	window(61,11,70,23);
	cout<<score_r;
	window(2,20,79,22);
	cout<<"Enter P to Pause...";
}

void move_car_down(AB speed_argument)    // To move Car Down...
{
	while(origin!=18 && !kbhit())
	{
	window(27+(line*8),origin,29+(line*8),origin+5);
	cout<<"Þ----Ý";
	window(27+(line*8),origin+1,29+(line*8),(origin+1)+5);
	cout<<"  --  ";
	window(27+(line*8),origin+2,29+(line*8),(origin+2)+5);
	cout<<"Þ----Ý";

	origin++;
	delay(speed_argument);

	window(27+(line*8),origin-1,29+(line*8),origin+5);
	cout<<"          ";
	window(27+(line*8),origin,29+(line*8),(origin+1)+5);
	cout<<"          ";
	window(27+(line*8),origin+1,29+(line*8),(origin+2)+5);
	cout<<"          ";
	score();
	score_r++;
	}
}

void car()         // To print car on particular line...
{
	window(27+(car_path*8),21,29+(car_path*8),25);
	cout<<"Þ----Ý";
	window(27+(car_path*8),22,29+(car_path*8),25);
	cout<<" -ÝÞ- ";
	window(27+(car_path*8),23,29+(car_path*8),25);
	cout<<"Þ-ÝÞ-Ý";
}

void car_cleaner()      // To Clean the car from a particular line...
{
	window(27+(car_cleaner_path*8),21,29+(car_cleaner_path*8),25);
	cout<<"      ";
	window(27+(car_cleaner_path*8),22,29+(car_cleaner_path*8),25);
	cout<<"      ";
	window(27+(car_cleaner_path*8),23,29+(car_cleaner_path*8),25);
	cout<<"      ";
}

void racing_game_play()       // Main Gameplay Conditions...
{
	topline_r();
	while(1)
	{
	if(first_time==0)
	{
	topline_r();
	cout<<endl<<setw(43)<<"PLAYERS"<<endl<<endl;
	cout<<endl<<endl<<"Enter Player Name : ";
	gets(player_name_r1);
	full_screen_cleaner();
	topline_r();
	window(32,10,40,11);
	cout<<"Ready...";delay(1000);clrscr();
	cout<<"Steady...";delay(1000);clrscr();
	cout<<"Go...";delay(1000);clrscr();
	first_time++;
	}

	car();

	while(!kbhit())
	{
	if(speed%2==0)
	speed--;

	move_car_down(speed);

	if(origin==18)
	{
	if(line==0 && car_path==0)
	{
	window(55,15,79,20);
	cout<<"Game Over";
	any_key=getch();
	first_time=0;
	racing_game_winner_store();
	}
	else if(line==1 && car_path==1)
	{
	window(55,15,79,20);
	cout<<"Game Over";
	any_key=getch();
	first_time=0;
	racing_game_winner_store();
	}
	line=rand()%line_option; origin=8;
	}
	}
	ch1=getch();

	switch(ch1)
	{
	case 0: ch2=getch();
		if(ch2==LEFT)
		{
		car();
		car_path=0;
		car_cleaner_path=1;
		car_cleaner();
		}
		if(ch2==RIGHT)
		{ car();
		car_path=1;
		car_cleaner_path=0;
		car_cleaner();
		}
		break;

	case '\r': full_screen_cleaner();
		   first_time=0;
		   racing_game();

	case 'p' : while(!kbhit())
		   {
		   delay(1);
		   if(kbhit())break;
		   }
	}
	}
}

void racing_game_about()           //Displays About Game...
{
	topline_r();
	cout<<"1."<<"This Is A Single Player Racing Game.";
	cout<<endl<<endl<<"2."<<"Player Has To Just Tackle Barriers.";
	cout<<endl<<endl<<"3."<<"Player Has To Get As Max. Score To Achieve High Score.";
	cout<<endl<<endl<<"4."<<"Scores Are Dependent On The Time You Survive.";
	cout<<endl<<endl<<"5."<<"Player Has To Move Left or Right To Survive.";
	cout<<endl<<endl<<endl<<endl<<"Press any key...";
	any_key = getch();
	racing_game();
}

void racing_game_winner_store()     //To Store Winners...
{
	full_screen_cleaner();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(k=0;k<80;k++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(44)<<"Your Score : "<<score_r<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(k=0;k<80;k++) cout<<"อ";

	fstream file_r;
	file_r.open("Adi_Racing.dat",ios::in|ios::binary|ios::app);
	race_obj.input(player_name_r1,score_r);
	file_r.write((ADI*)&race_obj,sizeof(race_obj));
	file_r.close();

	score_r=0;

	if(car_path==0)
	car_path=1;
	else
	car_path=0;

	any_key=getch();
	racing_game();
}

void racing_game_winner()            //Displays Winner History...
{
	topline_r();
	fstream file_r;
	file_r.open("Adi_Racing.dat",ios::in|ios::out|ios::binary);
	cout<<"Best Racers : "<<endl<<endl;
	cout<<setw(24)<<"Name"<<setw(25)<<"Scores   "<<endl<<endl;
	AB wno_r=1;
	while(!file_r.eof())
	{
	file_r.read((ADI*)&race_obj,sizeof(race_obj));
	cout<<setw(18)<<wno_r++<<". ";
	race_obj.output(0);
	}
	file_r.close();
}

void racing_game()       // To print game screen to choose...
{
	topline_r();
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 1."<<"    PLAY       บ"<<"                                 บ 2."<<" High Score    บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 3."<<"    ABOUT      บ"<<"                                 บ 4."<<"   BACK        บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<endl<<setw(49)<<"Enter Your Choice ->  ";
	cin>>racing_game_selector;

	switch(racing_game_selector)
	{
	case 1  :racing_game_play();any_key=getch();racing_game();break;
	case 2  :racing_game_winner();any_key=getch();racing_game();break;
	case 3  :racing_game_about();any_key=getch();racing_game();break;
	case 4  :game_selection();break;
	default :racing_game();
	}
}

void topline_r()        //To Print Game Top Line Border Of Each Page...
{
	clrscr();
	cout<<endl<<endl;
	for(k=0;k<80;k++) cout<<"อ";
	cout<<endl<<setw(45)<<"Racing Game"<<endl<<endl;
	for(k=0;k<80;k++) cout<<"อ";
	cout<<endl<<endl;
}





			    //  GUESS...

void guess_game();                         void guess_game_play();
void guess_game_winner();                  void guess_game_about();
void topline_g();                          void  guess_letter_interface();
void word_input_g();                       void stopper();
void guess_game_winner_display();

AB j,guess_game_selector,word_length,return_value;
ADI *player_g,hint[40],player_name_g1[15],player_name_g2[15];
ADI user_input,word,secret_word[15],word_store[15];


void guess_game_winner_display()     //To Print Winner Interface...
{
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(38)<<player_name_g2<<" WON"<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";

	fstream file_g;
	file_g.open("Adi_Guess.dat",ios::in|ios::binary|ios::app);
	guess_obj.input(player_name_g2);
	file_g.write((ADI*)&guess_obj,sizeof(guess_obj));
	file_g.close();
}

void stopper(AB try_display)	// To Stop For A While...
{
	cout<<"You Have "<<try_display<<" chances left..."<<endl;
	cout<<endl<<endl<<"Next...";
	any_key = getch();
}

void word_input_g()            //To Input Secret Word...
{
	topline_g();
	cout<<endl<<endl<<endl;
	cout<<setw(27)<<player_name_g1<<" enter your word (without spaces) "<<endl<<endl<<setw(30)<<" ";

	for(j=0;;)  //Infinite Loop
	{
	word=getch();
	if(word=='\r')
	{
	break;
	}
	word_store[j] = word;
	++j;
	cout<<" * ";
	}
	word_length = strlen(word_store);

	for(j=0; j!=word_length;j++)
	secret_word[j]='*';

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"Enter Hint(Without Spaces) : ";
	cin>>hint;
}

void guess_letter_interface()       //To input Guess Letter...
{
	topline_g();
	cout<<endl<<endl<<endl<<setw(36)<<" "<<secret_word<<" ";
	cout<<endl<<endl<<setw(31)<<"Hint : "<<hint;
	cout<<endl<<endl<<setw(34)<<player_name_g2<<" guess the word : ";
	cin>>user_input;
}

void guess_game_play()           //Inner Functionality Of Game...
{
	topline_g();
	cout<<endl<<setw(43)<<"PLAYERS"<<endl<<endl;
	cout<<endl<<endl<<"Enter Player1 Name : ";
	gets(player_name_g1);
	cout<<endl<<endl<<"Enter Player2 Name : ";
	gets(player_name_g2);

	AB tries=5;
	word_input_g();

	do
	{
	guess_letter_interface();
	AB correct_checker = 0;

	for(j=0;j<=word_length;j++)
	{
	if(user_input==word_store[j])
	{
	secret_word[j]=word_store[j];
	correct_checker++;
	}
	}

	if(correct_checker!=0)
	{
	cout<<endl<<endl<<"You got it correct...!!!";
	stopper(tries);
	}
	else if(correct_checker==0)
	{
	cout<<endl<<endl<<"Oops! You got it Wrong...!!!";
	--tries;
	stopper(tries);
	if(tries==0)
	{
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(34)<<" "<<player_name_g2<<" Lose"<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";
	}
	}

	if(strcmp(secret_word,word_store)==0)
	{
	cout<<endl<<endl<<"Congrats...You Got That Word Right...!!!";
	any_key = getch();
	guess_game_winner_display();
	break;
	}
	}while(tries>0);
}

void guess_game_about()           //Displays About Game...
{
	topline_g();
	cout<<"1."<<"This Is A Multiplayer Guess Game.";
	cout<<endl<<endl<<"2."<<"One Player Gets Chance To Guess The Word.";
	cout<<endl<<endl<<"3."<<"Other Player Defines The Word And Hint.";
	cout<<endl<<endl<<"4."<<"This Game Is All About Mind And Guesses.";
	cout<<endl<<endl<<"5."<<"The Player Who Get The Word Right Will Be Declared Winner.";
	cout<<endl<<endl<<endl<<endl<<"Press any key...";
	any_key = getch();
	guess_game();
}

void guess_game_winner()            //Displays Winner History...
{
	topline_g();
	fstream file_g;
	file_g.open("Adi_Guess.dat",ios::in|ios::out|ios::binary);
	cout<<"Top Minded Winner : "<<endl<<endl;
	cout<<setw(24)<<"Name"<<endl<<endl;

	AB wno_g=1;

	while(!file_g.eof())
	{
	file_g.read((ADI*)&guess_obj,sizeof(guess_obj));
	cout<<setw(18)<<wno_g++<<". ";
	guess_obj.output(1);
	}
	file_g.close();
}

void guess_game()    // To print guess game screen to choose...
{
	topline_g();
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 1."<<"    PLAY       บ"<<"                                 บ 2."<<"   WINNER      บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 3."<<"    ABOUT      บ"<<"                                 บ 4."<<"   BACK        บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<endl<<setw(49)<<"Enter Your Choice ->  ";

	cin>>guess_game_selector;

	switch(guess_game_selector)
	{
	case 1  :guess_game_play();any_key=getch();guess_game();break;
	case 2  :guess_game_winner();any_key=getch();guess_game();break;
	case 3  :guess_game_about();any_key=getch();guess_game();break;
	case 4  :game_selection();break;
	default :guess_game();
	}
}

void topline_g()           //To Print Game Top Line Border Of Each Page...
{
	clrscr();
	cout<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";
	cout<<endl<<setw(45)<<"Guess Game"<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";
	cout<<endl<<endl;
}





			   // Casino...

void casino_game_play();                void casino_game_about();
void casino_game_winner();              void casino_game();
void topline_c();

AB casino_game_selector,betting_amount,total_amount,guess_number,random_num;
ADI again[5],player_name_c1[25],num[6]={'0','1','2','3','4','5'};


void casino_game_play()            //Core function Of Game...
{
	topline_c();
	cout<<endl<<setw(43)<<"PLAYERS"<<endl<<endl;
	cout<<endl<<endl<<"Enter Player Name : ";
	gets(player_name_c1);
	cout<<endl<<endl<<"Enter Amount To Be Deposit For Further Play : $ ";
	cin>>total_amount;

	do
	{
	invalid:
	topline_c();
	cout<<"Your Current Balance is : $ "<<total_amount<<endl<<endl;
	cout<<player_name_c1<<" enter amount to bet on a number : $ ";
	cin>>betting_amount;

	if(betting_amount > total_amount)
	goto invalid;

	cout<<endl<<"Guess To Bet On Number(0-5) : ";
	cin>>guess_number;
	cout<<endl<<endl<<endl;

	if(guess_number<0 || guess_number>5)
	goto invalid;

	random_num = rand()%5;
	if(random_num == guess_number)
	{
	cout <<endl<<endl<<"Good Luck! You won Rs." << betting_amount * 10<<endl;
	total_amount+=(betting_amount * 10);

	fstream file_c;
	file_c.open("Adi_Casino.dat",ios::in|ios::binary|ios::app);
	casino_obj.input(player_name_c1,total_amount);
	file_c.write((ADI*)&casino_obj,sizeof(casino_obj));
	file_c.close();
	}
	else
	{
	cout << "Bad Luck!! You lost $ "<< betting_amount <<endl<<endl;
	total_amount-=betting_amount;
	}

	cout <<player_name_c1<<" You have $ " <<total_amount<<endl;
	cout <<"The winning number was : " <<random_num<<endl<<endl;

	if(total_amount == 0)
	{
	cout <<endl<<"You have no money to play further...";
	any_key=getch();
	break;
	}

	cout<<endl<<endl<<"If You Want To Play Again(Y/N) : ";
	gets(again);

	}while(strcmpi(again,"y")==0);

	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(k=0;k<80;k++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(45)<<"GAME OVER"<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(k=0;k<80;k++) cout<<"อ";
	any_key=getch();
	casino_game();
}

void casino_game_about()           //Displays About Game...
{
	topline_c();
	cout<<"1."<<"This Is A Single player Guess Game.";
	cout<<endl<<endl<<"2."<<"One Player Gets Chance To Bet On Number.";
	cout<<endl<<endl<<"3."<<"Player Defines A Betting Amount.";
	cout<<endl<<endl<<"4."<<"This Game Is All About Luck And Guesses.";
	cout<<endl<<endl<<"5."<<"The Player Who Get The Number Right Will Be Awarded.";
	cout<<endl<<endl<<endl<<endl<<"Press any key...";
	any_key = getch();
	casino_game();
}

void casino_game_winner()            //Displays Winner History...
{
	topline_c();
	fstream file_c;
	file_c.open("Adi_Casino.dat",ios::in|ios::out|ios::binary);
	cout<<"Top Luckiest Winner : "<<endl<<endl;
	cout<<setw(24)<<"Name"<<setw(25)<<"Amount($)"<<endl<<endl;

	AB wno_c=1;

	while(!file_c.eof())
	{
	file_c.read((ADI*)&casino_obj,sizeof(casino_obj));
	cout<<setw(18)<<wno_c++<<". ";
	casino_obj.output(0);
	}
	file_c.close();
}

void casino_game()    // To print casino game screen to choose...
{
	topline_c();
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 1."<<"    PLAY       บ"<<"                                 บ 2."<<"   WINNER      บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 3."<<"    ABOUT      บ"<<"                                 บ 4."<<"   BACK        บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<endl<<setw(49)<<"Enter Your Choice ->  ";

	cin>>casino_game_selector;

	switch(casino_game_selector)
	{
	case 1  :casino_game_play();any_key=getch();casino_game();break;
	case 2  :casino_game_winner();any_key=getch();casino_game();break;
	case 3  :casino_game_about();any_key=getch();casino_game();break;
	case 4  :game_selection();break;
	default :casino_game();
	}
}

void topline_c()           //To Print Game Top Line Border Of Each Page...
{
	clrscr();
	cout<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";
	cout<<endl<<setw(45)<<"Casino Game"<<endl<<endl;
	for(j=0;j<80;j++) cout<<"อ";
	cout<<endl<<endl;
}


			   // Main...

void main()
{
	clrscr();
	main_display();
	getch();
}

void game_selection()   //For choosing games to play...
{
	clrscr();
	cout<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<setw(45)<<" SELECT THE GAME"<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";

	cout<<endl<<endl;
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 1."<<"Tic Tac Toe    บ"<<"                                 บ 2."<<"   Racing      บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<" ษออออออออออออออออออป"<<"                                 ษออออออออออออออออออป"<<endl;
	cout<<" บ 3."<<" Any Guesses   บ"<<"                                 บ 4."<<"   Casino      บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<"                                 ศออออออออออออออออออผ"<<endl<<endl;
	cout<<" ษออออออออออออออออออป"<<endl;
	cout<<" บ 5."<<"    Exit       บ"<<endl;
	cout<<" ศออออออออออออออออออผ"<<endl<<endl;
	cout<<endl<<setw(49)<<"Enter Your Choice ->  ";

	cin>>game_selector;

	switch(game_selector)
	{
	case 1  :tic_tac_toe();break;
	case 2  :racing_game();break;
	case 3  :guess_game();break;
	case 4  :casino_game();break;
	case 5  :clrscr();

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(50)<<"(90's Collection) By -"<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";

	delay(1500);
	clrscr();

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(47)<<"Aditya Bhardwaj"<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";

	delay(2500);
	clrscr();

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<endl<<endl<<endl<<endl<<setw(48)<<"   Thank You   "<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"อ";
	cout<<endl<<endl<<endl;

	window(6,23,80,25);
	cout<<" Good Bye!!!";
	window(6,24,55,25);
	for(i=0;i<70;i++)
	{
	delay(50);
	cout<<"Û";
	}
	exit(0);

	default :game_selection();
	}
}
void main_display()           // To Print 1st main screen...
{
	cout<<endl<<endl;
	for(i=0;i<80;i++) cout<<"ฒ";
	cout<<endl<<setw(50)<<"90s GAME COLLECTION"<<endl<<endl;
	cout<<endl<<setw(42)<<"BY -"<<endl<<endl<<endl;
	for(i=0;i<80;i++) cout<<"Ü";

	cout<<endl<<endl<<setw(51)<<"Name : Aditya Bhardwaj"<<endl;
	cout<<setw(44)<<"Class : XII - A"<<endl;
	cout<<setw(42)<<"Roll no. : 02"<<endl<<endl;
	for(i=0;i<80;i++) cout<<"Ü";

	cout<<endl<<setw(51)<<"COLUMBUS PUBLIC SCHOOL";
	cout<<endl<<endl<<setw(78)<<"To - Skimpy Mam"<<endl;
	for(i=0;i<80;i++) cout<<"ฒ";

	cout<<"Press any key...";
	any_key = getch();
	game_selection();
}
