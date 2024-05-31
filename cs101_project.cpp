#include<iostream>
using namespace std;
const int SIZE = 7;// Size of options,declared as gloabl
void printOptions(string options[])// Function to print options in array
{
	for(int i=0; i<SIZE; i++)
	{
		cout<<i+1 <<": " <<options[i] <<endl;
	}
	cout<<endl;
}
int checkAnswer(int correct[], int userAnswer[]){// Function to check whether user sequence and correct sequence or same or not
	int points = 0;
	for(int i=0; i<SIZE; i++)
	{
		if(correct[i] == userAnswer[i]){
			points++;
		}
		if (points==7)
		{
			points=10;
		}
	}
	return points;
}
void printCorrectAnswer(int answer[], string options[]){// Function to print correct anser sequence
	cout<<"\n\n >> Correct Sequence: " <<endl <<endl;
	for(int i=0; i<SIZE; i++)
	{
		cout<<" " <<answer[i] <<". " <<options[answer[i]-1] <<endl;
	}
}
bool isAlreadyEntered(int arr[], int n, int s)
{
	for(int i=0; i<s; i++){
		if(arr[i] == n)
			return true;
	}
	return false;
}
int main()// Main driver code
{
	string questions[10] = {"Arrange the following Presidents in order of their Term.",// Sting array having 10 question statements
							   "Arrange the Presidents in ascending order of their time of death.",
							   "Arrange the Presidents in the number of Electoral Votes they got.",
							   "Arrange Presidents in accordance to the age of death.",
							   "Arrange the Presidents in ascending order of their time of birth.",
							   "Arrange the Presidents according to the Net worth.",
							   "Arrange the Presidents in the number of bills the vetoed.",
							   "Arrange the Presidents according to their Party(Democrats then Republicans).",
							   "Arrange the Presidents in the number of terms they served.",
							   "Arrange the Presidents by the percentage of Votes they got."};								
	string options[SIZE] = {"Richard Nixon", // Sting array having 7 options
							"Ronald Reagan", 
							"George W. Bush", 
							"Bill Clinton", 
							"Lyndon Johnson", 
							"John F. Kennedy", 
							"Jimmy Carter"};
	int answers[10][SIZE] = {{6, 5, 1, 7, 2, 4, 3},// 2D array having correct sequence for 10 questions,10 x 7 Matrix ( 10 questions having 7 options each )
							 {6, 5, 1, 2, 3, 4, 7},
	 						 {2, 5, 4, 6, 1, 7, 3},
							 {7, 4, 3, 2, 1, 5, 6},
							 {5, 2, 1, 6, 7, 4, 3},
							 {5, 4, 3, 2, 1, 6, 7},
							 {2, 1, 4, 5, 7, 6, 3},
							 {6, 5, 7, 4, 1, 2, 3},
							 {2, 4, 3, 6, 5, 1, 7},
						     {5, 7, 2, 6, 3, 1, 4}};
	int userAnswer[SIZE];// Array to store user sequence
	cout<<"\n\n\t\t\t\t ----------------------------";// Screen header messae
	cout<<"\n\t\t\t\t | AMERICAN PRESIDENTS GAME | ";
	cout<<"\n\t\t\t\t -----------------------------";
	cout<<"\n\n\t\t <<<<< Arrange the Presidents of United States in Correct Order >>>>> " <<endl <<endl;
	cout<<"\tWelcome to the US Presidents Game!."; 
	cout<<" \n\tYou will be given 10 Questions and you will have to answer them the max you can get is 10 points per Question.";
	cout<<" \n\tIf you get an arrangement all correct you will receive 10 Points but even if you get a single arrangement ";	
	cout<<" \n\tincorrect you will 1 point on every correct arrangement.";
	cout<<" \n\tAfter answering each question, you will be told the correct answer and also told if your answer is ";
	cout<<" \n\tcorrect or incorrect and the number of points you gained from the question.";
	cout<<" \n\tAt the end of the game your points will be totaled. The game is based on the following presidents:";
	cout<<"\n\n\t  > Richard Nixon";
	cout<<"\n\t  > Ronald Reagan";
	cout<<"\n\t  > George W. Bush";
	cout<<"\n\t  > Bill Clinton";
	cout<<"\n\t  > Lyndon Johnson"; 
	cout<<"\n\t  > John F. Kennedy";
	cout<<"\n\t  > Jimmy Carter" <<endl <<endl;
	char ch = 'Y';
	while(ch == 'y' || ch == 'Y')
	{
		int totalPoints = 0; // To store total points
		int n = 1; // Loop control variable
		while(n <= 10)// In this loop, we displayed 10 questions and get answers
		{
			cout<<"\nQ" <<n <<": " <<questions[n-1] <<endl <<endl;
			printOptions(options);
			cout<<" >> Enter Your 7 Digit Sequence: " <<endl <<endl;
			for(int i=0; i<SIZE; i++){
				cout<<"   > ";
				cin >> userAnswer[i];
				while(true==isAlreadyEntered(userAnswer, userAnswer[i], i)){
					cout<<"   >> Invalid. Already Entered ";
					cout<<"\n   > "; cin >> userAnswer[i];
				}
				while(userAnswer[i] < 1 || userAnswer[i] > 7){
					cout<<"   >> Invalid. It must be [1-7] ";
					cout<<"\n   > "; cin >> userAnswer[i];
				}
			}
			int points = checkAnswer(answers[n-1], userAnswer);
			if(points == 10)
			{
				cout<<"\n >> Nice. Your Sequence is Correct ...";
			}
			else
			{
				cout<<"\n >> Oops. Your Sequence is Incorrect ...";
				printCorrectAnswer(answers[n-1], options);
			}
			
			totalPoints += points;
			cout<<"\n >> Points: [ " <<points <<" ]" <<endl;
			cout<<" >> Total Points: [ " <<totalPoints <<" ]" <<endl;
			n++;
		}
		cout<<"\n >> Your Points: " <<totalPoints <<endl;
		cout<<" >> Thank you for playing the game ... ";
		cout<<"\n\n >> If you like to play again press [ Y ] of [ y ] or any other key to exit: ";
		cin>>ch;
	}
	return 0;
}

