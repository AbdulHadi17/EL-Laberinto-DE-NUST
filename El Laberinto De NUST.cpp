#include<iostream>
#include<stdlib.h>
#include<chrono>  // for srand
#include<iomanip> // for indentation
#include<conio.h> // for input
#include<string> 
#include<thread> // for typewriting effect
#include<windows.h> // For colors

using namespace std;
void intro();
void instructions();
void ScreenClearer(string); // dislays UI
void GameCheck(); // checks the game ending state

bool level1();
bool level2();
bool level3();
bool level4();
bool level5();
bool ending();

int coins = 0;
int confidence = 15;
int choices = 0;
int counter = 0;
string name;
string message;
string inventory = "nothing";
bool game = true;
char val, val1, val2;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	intro();
	if (game == true)
		level1();
	if (game == true)
		level2();
	if (game == true)
		level3();
	if (game == true)
		level4();
	if (game == true)
		level5();
	if (game == true)
		ending();

	getchar();

}
void typewrite(string message)
{
	for (char c : message)
	{
		cout << c << flush; // Print the character without buffering
		this_thread::sleep_for(chrono::milliseconds(20)); // Adjust delay as needed
	}

	cout << endl;
}
void instructions()
{
	ScreenClearer("INSTRUCTIONS");
	cout << "\nThe game is a text-based game in which the player is given multiple choices to complete the objective.\n\nThis game consists of 5 levels. \n\nThis game is set in NUST, and each level is based upon some location of NUST. \n\nIn order to complete the game, the player must have specific items which the player attains after the completion of each level.\n\nIn order to complete the game, the player must have specific items which the player attains after the completion of each level.\n\n The player is given multiple routes via choices to reach its destination and each route has its own level of complexity.\n\nThere is a time limit in our game, and time is regarded as the number of choices made in our game.\n\nThe Least possible choices to win the game are 25.\n\nThe Most possible choices to win the game are 49.\n\nWhile keeping the complexities in mind, the games provides the player a maximum number of 35 choices to win the game.\n\nThere is a confidence meter as well, which will increase or decerase depending upon the choices made by the user.\n\nThe player is given 15 confidence bars as a default, In case the confidence meter runs out, the game ends.\n\n";
	cout << "\nPress 0 to Go Back.\n";

	switch (_getche())
	{
	case '0':
		intro();
		break;
	default:
		instructions();
		break;
	}
}


void intro()
{
	ScreenClearer("EL LABERINTO DE NUST");


	cout << endl << "\nPress 1 to Start\n\nPress 2 for Instructions\n\nPress 3 to exit\n";
	switch (_getche())
	{
	case '1':
		break;
	case '2':
		instructions();
		break;
	case '3':
		game = false;
		exit(0);
		break;
	default:
		intro();
		break;
	}
}


void ScreenClearer(string message)
{
	SetConsoleTextAttribute(h, 7);
	system("cls");

	// Box Generator

	// Calculate the width of the box based on the length of the text
	int boxWidth = message.length() + 4; // 2 for each side of the box

	// Draw the top border
	cout << endl << setw(72) << '+' << string(boxWidth, '-') << '+' << endl;

	// Draw the text with borders on each side
	cout << setw(74) << "| ";

	SetConsoleTextAttribute(h, 3);

	cout << message;

	SetConsoleTextAttribute(h, 7);

	cout << " |" << endl;

	// Draw the bottom border
	cout << setw(72) << '+' << string(boxWidth, '-') << '+' << endl;


	for (int i = 0;i <= 167;i++)
		cout << "_";

	cout << "\n\n";

	if (choices < 0)
		choices = 0;

	SetConsoleTextAttribute(h, 7);
	if (choices != 0)
	{
		SetConsoleTextAttribute(h, 7);
		cout << "\t\t\tNo of Choices Made: ";

		SetConsoleTextAttribute(h, 4);
		cout << choices;

		SetConsoleTextAttribute(h, 7);

		cout << "\t\t\t\t    coins: ";

		SetConsoleTextAttribute(h, 4);

		cout << coins << "\t\t\t\t";

		SetConsoleTextAttribute(h, 7);

		cout << "Confidence Meter : ";

		SetConsoleTextAttribute(h, 4);

		for (int i = 1;i <= confidence;i++)
			cout << '\3' << " ";

		SetConsoleTextAttribute(h, 7);

		if (inventory != "nothing")
		{

			SetConsoleTextAttribute(h, 7);

			cout << "\n\n" << "\t\t\t\t\t\t\t" << "INVENTORY: ";

			SetConsoleTextAttribute(h, 7);
			cout << "You have ";

			SetConsoleTextAttribute(h, 4);
			cout << inventory;

			SetConsoleTextAttribute(h, 7);

			cout << " in your inventory. ";
		}
		cout << endl;
		for (int i = 0;i <= 167;i++)
			cout << "_";
	}



	cout << endl;
	SetConsoleTextAttribute(h, 7);
}

void GameCheck()
{
	if (choices > 37)
	{
		game = false;

		ScreenClearer(" GAME OVER "); // Displays UI

		message = "\nYou have failed to win the game because you have breached the allowed choices limit.\n\n** GAME OVER **\n\n";
		typewrite(message);

		exit(0);
	}

	else if (confidence <= 0)
	{
		game = false;

		ScreenClearer(" GAME OVER ");

		message = "\nYou have failed to win the game because your confidence bar reached zero.\n\nPress any key to go back to main menu.\n\n";
		typewrite(message);

		system("pause");
		exit(0);
	}

}

string SADATriangle()
{
	cout << "\n\n\n";

	cout << setw(84) << ".\n";
	cout << setw(86) << ". . .\n";
	cout << setw(88) << ".   .   .\n";
	cout << setw(90) << ".     .     .\n";
	cout << setw(92) << ".       .       .\n";
	cout << setw(94) << ". . . . . . . . . . .\n";
	cout << setw(96) << ".   .   .   .   .   .   .\n";
	cout << setw(98) << ".     .     . . .     .     .\n";
	cout << setw(100) << ". . . . . . . . . . . . . . . . .\n";

	cout << "\n\n";

	return "";
}


bool level1()
{

	ScreenClearer("LEVEL NO 1");

	cout << "\nEnter the Name of the Player: ";
	getline(cin, name);

	ScreenClearer("LEVEL NO 1");


	string message1 = ", you are currently at Zakaria Hostel. Your Objective is to escape NUST.\n\nTo complete Level 1, you must reach SEECS and find the Permission Letter.";
	message = name + message1;
	cout << endl;
	typewrite(message);
	cout << endl;

	system("pause");

	ScreenClearer("LEVEL NO 1");

	message = "\nIts a Monday morning. You woke up and got ready. You need a permission letter.\nSomeone told you that you will get the permission letter at SEECS. So you get out of the hostel.\nWhile Leaving , The guard didnt recognize you and then asked if you are a hostellite or a day scholar:\nYou have two choices.";
	typewrite(message);
	cout << "\nChoice 1: Say you are a Hostelite.\nChoice 2: Say you are a Day Scholar.\n";
	cout << "\nPress 1 to select choice 1.\nPress 2 to select choice 2.\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	do
	{
		val = _getche();
		switch (val)
		{
		case '1':
			ScreenClearer("LEVEL NO 1");
			message = " \nYou told the guard that you are a hostelite. So he let you go.\n";
			typewrite(message);
			break;
		case '2':
			ScreenClearer("LEVEL NO 1");
			message = "\nThe guard is furious. He takes you to the manager's office. Manager tells you that Day Scholars aren't allowed in hostels. You should have atleast taken the permission.\nSo he asks you to leave. Now, you have 2 choices.";
			typewrite(message);
			cout << "\nChoice 1: Say \"I'm Sorry\" and leave.";
			cout << "\nChoice 2: Say \"I'll come here whenever I want. I don't need your permission.\"";
			cout << "\n\nPress 1 to select choice 1.\nPress 2 to select choice 2.";

			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}

			do
			{
				val = _getche();
				switch (val)
				{
				case '1':
					ScreenClearer("LEVEL NO 1");
					break;
				case'2':
					confidence -= 2;
					ScreenClearer("LEVEL NO 1");
					message = "\nYou just triggered the manager!..... The manager insulted you in the worst way possible. As a result your confidence went down by 2.";
					typewrite(message);

				}
			} while ((val != '1') && (val != '2'));
			break;
		}

	} while ((val != '1') && (val != '2'));


	cout << endl;
	system("pause");
	ScreenClearer("LEVEL NO 1");

	message = "\nYou just came out of hostel. You are at the shuttle stop. There is no shuttle there at the moment.\nYou need to reach SEECS as soon as possible. You have two choices:\n";
	typewrite(message);

	cout << "Choice 1: Wait for Shuttle\n";
	cout << "Choice 2: Walk\n";
	cout << "\nPress 1 to select choice 1.\nPress 2 to select choice 2.";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	do
	{
		val = _getche();
		switch (val)
		{
		case'1':
			ScreenClearer("LEVEL NO 1");
			message = "\nShuttle arrived after 5 minutes and dropped you to SEECS Parking area.\n";
			typewrite(message);
			break;
		case'2':
			ScreenClearer("LEVEL NO 1");
			message = "\nYou chose to start walking instead of waiting for the shuttle to arrive. You are walking across Bolan Road and saw your friend coming your way.\n He is your best friend and he asks if you are busy. You have two choices.\n ";
			typewrite(message);

			cout << "Choice 1: Respond with \"No\"\n";
			cout << "Choice 2: Respond with \"Yes\"\n";
			cout << "\nPress 1 to select choice 1.\nPress 2 to select choice 2.";
			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}


			do
			{
				val = _getche();
				switch (val)
				{
				case '1':
					ScreenClearer("LEVEL NO 1");
					message = "\nYou told your friend that you aren't busy. Your friend is bored. He asks you a riddle.\n\nThe riddle is \"Tommorow is neither Wednesday nor Thursday. Yesterday was not Friday or Saturday.\nToday is not Thursday nor Monday nor Sunday. What day is Today?\"\n";
					typewrite(message);

					cout << "\nChoice 1: Today is Monday\n";
					cout << "Choice 2: Today is Thursday\n";
					cout << "Choice 3: Today is Friday\n";
					cout << "Choice 4: Today is Sunday\n";
					cout << "\nPress 1 to select choice 1.\nPress 2 to select choice 2.\nPress 3 to select choice 3.\nPress 4 to select choice 4.";
					choices++;

					GameCheck(); // Termminates the game if true
					if (game == false) {
						return false;
					}


					do
					{
						val1 = _getche();
						switch (val1)
						{
						case '1':
						case '2':
						case '4':
							ScreenClearer("LEVEL NO 1");
							message = "\nOops! You chose the incorrect option.\nYour friend left and now you're on your way to SEECS.";
							typewrite(message);
							break;
						case '3':
							coins++;
							ScreenClearer("LEVEL NO 1");
							message = "\nCONGRATULATIONS!You got the right answer. As a reward, your friend gave you a coin.\n\n.....After a while, your friend left and now you're on your way to SEECS.";
							typewrite(message);
							break;
						}
					} while ((val1 != '1') && (val1 != '2') && (val1 != '3') && (val1 != '4'));
					break;

				case '2':
					ScreenClearer("LEVEL NO 1");
					message = "\nYour friend left. Now you walk from C-2 to SEECS Parking.\n";
					typewrite(message);
					break;
				}

			} while ((val != '1') && (val != '2'));
			break;
		}
	} while ((val != '1') && (val != '2'));

	system("pause");
	ScreenClearer("LEVEL NO 1");

	message = "\nYou reached SEECS Parking. Here you see four cars infront of you.\nYou have to guess the number beneath the car by cracking a code inorder to get a reward. Fill the blank\n\nB9\tD11\t__\tK18\n\nOptions are:\n\n";
	typewrite(message);
	cout << "Option 1: F13\n";
	cout << "Option 2: G14\n";
	cout << "Option 3: F14\n";
	cout << "Option 4: I15\n";

	bool cigarette = false;

	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}


	do
	{
		val = _getche();
		switch (val)
		{
		case '2':
		{
			message = "\nYou chose the correct option.\nYou have been given a pack of cigarettes as a reward which you can use later.";
			typewrite(message);
			cigarette = true;
			inventory = "cigarette";
			break;
		}
		case '1':
		case '3':
		case '4':
		{
			confidence--; // Drops confidence by 1 bar
			message = "\n\nYou failed to find the correct answer. Your confidence has gone down by 1 bar.\n";
			typewrite(message);
			break;
		}
		}

	} while ((val != '1') && (val != '2') && (val != '3') && (val != '4'));

	cout << endl;
	system("pause");
	ScreenClearer("LEVEL NO 1");

	message = "\nYou are at SEECS Dolphin Area, searching for the permission letter. Someone told you that only a professor can issue a permission letter.\nYou met your calculus sir and he asks you a question after that he will give you permission letter.\nYou can skip the question by using the reward(if you have it)\n";
	typewrite(message);
	if (cigarette == true)
	{
		cout << "Press 1 to use Reward\n";
		choices++;

		GameCheck(); // Termminates the game if true
		if (game == false) {
			return false;
		}

		do
		{
			val = _getch();
			switch (val)
			{
			case '1':
				inventory = "nothing";
				message = "\nYou gave the cigarette to Calculus sir. As a result, he gave you the Permission letter without solving the question\n";
				typewrite(message);
				break;
			}

		} while (val != '1');
	}
	else
	{
		choices++;

		GameCheck(); // Termminates the game if true
		if (game == false) {
			return false;
		}

		message = "\nSolve this Calculus Question to get the permission letter.\n\nQuestion: What is the Domain of the following question:\t\t (3x - 8) / (x^2 - 9x + 20)..... ?\n\n";
		typewrite(message);

		cout << "\nA) All Real Numbers excluding x = -4 and x = -5.\nB) All Real Numbers excluding x = -4 and x = 5.\nC) All real numbers excluding x = 4 and x = -5.\nD) All Real Numbers excluding x = 4 and x = 5\n";
		cout << "\nPress 1 to select A option.\nPress 2 to select B option.\nPress 3 to select C option.\nPress 4 to select D option.\n";

		do
		{
			val = _getche();

			switch (val)
			{
			case '1':
			case '2':
			case '3':
			{
				choices++;
				GameCheck(); // Termminates the game if true
				if (game == false) {
					return false;
				}

				confidence--;
				ScreenClearer("LEVEL NO 1");
				message = "\nYou gave the WRONG Answer.......As a result your confidence went down by 1 bar.....\n\nYou went to another professor to get the permission letter....He gave you the letter.\n\nYour choices have been increased by 1 due to it.\n";
				typewrite(message);

				system("pause");

				break;
			}

			case '4':
			{
				confidence++;
				ScreenClearer("LEVEL NO 1");
				message = "\nCongratulations!.......You asnwered the question correctly. Calculus Professor is impressed and he issued you the permission letter.\n\nAs a result your confidence has been increased by 1 bar.\n";
				typewrite(message);

				system("pause");
				break;
			} // end of case 2
			} // end of switch
		} while (val != '1' && val != '2' && val != '3' && val != '4'); // end of do-while

	}


	ScreenClearer("LEVEL NO 1");
	message = "\nCONGRAULATIONS! You have finished level 1 and collected the Permission Letter.";
	typewrite(message);
	cout << endl;
	system("pause");

	game = true;
	return true;
}
bool level2()
{
	ScreenClearer("LEVEL NO 2");

	message = "\nCongratulations! You have made it to level no 2.\n\nYour objective of this level is to reach NBS Ground and Find your NUSt ID Card.\n\nYou may find a coin too if you are lucky.\n\nBest of Luck :)\n\n";
	typewrite(message);
	system("pause");

	ScreenClearer("LEVEL NO 2");
	message = "You have to reach NBS Ground to find your NUST ID Card. So you started walking\n\nYou have 2 ways to reach to NBS Ground:\n\n";
	typewrite(message);
	cout << "Choice 1: Go by Road\nChoice 2: Go in between the Helipad Ground.\n";
	cout << "\nPress 1 to select Choice 1.\nPress 2 to select choice 2.\n\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}


	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{
			ScreenClearer("LEVEL NO 2");
			message = "You Chose to go by road. You are walking your way to NBS Ground and you just met a senior student\nSenior is here for your ragging. He gives you a task to sing a song.\n\n";
			typewrite(message);
			cout << "\nChoice 1: Sing a Song\nChoice 2: Don't Do it\n";
			cout << "\nPress 1 To make the first choice.\nPress 2 to make the second choice.\n\n";
			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}


			do
			{
				val1 = _getche();

				switch (val1)
				{
				case '1':
				{
					ScreenClearer("LEVEL NO 2");
					confidence++;
					message = "\nThe senior is impressed with your singing skills. He leaves the spot and gives you useful piece of advice.\nAs a Result your confidence gets increased by 1.\n\n";
					typewrite(message);

					system("pause");
					break;
				}

				case '2':
				{
					ScreenClearer("LEVEL NO 2");
					confidence--;
					message = "\nYou refused to sing ! He is not happy at all...... He talked trash to you and as result your confidence went down by 1.\n\n";
					typewrite(message);

					system("pause");
					break;
				}

				}
			} while (val1 != '1' && val1 != '2');

			break;
		}

		case '2':
		{
			ScreenClearer("LEVEL NO 2");
			message = "\nYou chose to go in between the Helipad Ground. You are walking through the Helipad ground and after few minutes you reached NBS Ground.\n\n";
			typewrite(message);

			system("pause");
			break;
		} // end of switch

		} // end of do while

	} while (val != '1' && val != '2');

	// End of 1 out of 3 choices

	ScreenClearer("LEVEL NO 2");
	message = "\nNow, you are at NBS Ground. You saw a group of people playing Basketball.\nAlthough you aren't in sports kit but you want to play. Its not allowed to play without being in proper kit.\nThe Ground Staff is looking the opposite way. A group of people playing invites you to Join. You have two choices: \n\n";
	typewrite(message);
	cout << "\nChoice 1: Refuse.... As you aren't in proper kit\nChoice 2: Join.... As you wanted to play\n";
	cout << "\nPress 1 to Refuse.\nPress 2 To Join.\n\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}


	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{
			coins++;
			ScreenClearer("LEVEL NO 2");
			message = "\nYou thanked them for their invitation and refused to play. You then left the basketball court.\n\nYou earned a coin in reward for following the ground rules.\n\n ";
			typewrite(message);

			system("pause");
			break;
		}

		case '2':
		{
			ScreenClearer("LEVEL NO 2");
			message = "\nYou accepted their invitation and started playing basketball. After a few minutes ...... The Ground Staff saw you playing.\nHe is not happy at all and politely asked you to leave\n\n";
			typewrite(message);

			cout << "\nChoice 1: Leave\nChoice 2: Argue\n";
			cout << "\nPress 1 to leave.\nPress 2 to Argue.\n";

			choices++;
			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}


			do   // For L2 - C2 - Lose case.
			{
				val1 = _getche();

				switch (val1)
				{
				case '1':
				{
					ScreenClearer("LEVEL NO 2");
					message = "\nYou apologized to the grounds staff and told him that you didnt know the dress code rule.So, You leave the BasketBall Court.\n";
					typewrite(message);

					system("pause");

					break;
				}

				case '2':
				{
					ScreenClearer("LEVEL NO 2");
					confidence -= 2;
					message = "\nYou started arguing to the ground staff. Ground Staff knows how to handle people like you.\nGround Staff is now scolding you and now you regret your decision to argue.\n\nYou lose your confidence by 2\n";
					typewrite(message);

					system("pause");

					break;
				}
				}
			} while (val1 != '1' && val1 != '2');


			break;
		} // End of case 2
		} // End of switch
	} while (val != '1' && val != '2'); // end of do-while

	// End of choice 2 out of 3

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	ScreenClearer("LEVEL NO 2");

	message = "\nYou are now near the football area. Someone told you that you will get your NUST ID Card beneath a bench.\n\nYou have 4 benches infront of you. No of choices made will increase with the no of attempts you make.\n";
	typewrite(message);

	cout << "\nPress 1 to look under Bench 1\nPress 2 to look under Bench 2\nPress 3 to look under Bench 3\nPress 4 to look under Bench 4\n\n";

	srand(time(0));
	int TargetBench = rand() % 4 + 49;

	do  // Start of Bench Rand
	{
		val = _getche();

		if (val == (char)TargetBench) {
			choices++;
			cout << " - Congratulations! You found your NUST ID Card\n";

			break;
		}
		else
		{
			if (val >= '1' && val <= '4') {
				cout << " - You Looked under the wrong bench. Pick again.\n";
			}
			else {
				// Print an error message or take any other appropriate action for invalid input
				cout << " - Invalid choice. Press ( 1 , 2 , 3 or 4 )" << endl;
			}
		}

		if (val > '9' || val < '1') {
			val = '0';
		}
		else
		{
			choices++;
			counter++;
		}

		if (counter > 3) {
			break;
		}

	} while (val != (char)TargetBench);

	if (counter == 4)
	{
		ScreenClearer("LEVEL NO 2");
		confidence--;
		message = "\nYou Failed to find your card in 4 attempts. As a result someone else finds it for you.\n\nYour confidence comes down by 1.\n\n";
		typewrite(message);
	}

	cout << endl;
	system("pause");

	// End of Level 2 - Riddle 3

	GameCheck(); // Termminates the game if true

	ScreenClearer("LEVEL NO 2");
	message = "\nYou have succesfully found your card. You have Completed LEVEL NO 2.\n";
	typewrite(message);

	system("pause");

	game = true;
	return true;
}
bool level3()
{
	ScreenClearer("LEVEL NO 3");
	message = "\nWelcome to LEVEL NO 3......\n\nYour objective of this LEVEL is to reach SADA and get a Ticket.\n\n";
	typewrite(message);

	system("pause");
	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	// Start of  Riddle 1 of 4

	ScreenClearer("LEVEL NO 3");
	message = "\nYou started walking from NBS Ground and now you have reached C1.\nYou are roaming around C1 and you are hungry. You see canteen infront of you.\nSo you either eat food or not?\n";
	typewrite(message);

	cout << "\nPress 1 to eat food\nPress 2 to not eat.\n\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{

			ScreenClearer("LEVEL NO 3");
			message = "\nYou chose to eat food. Therefore you bought C1 special Pizza. You gave money bills and got coins in return.\nYou now have to do a coin toss.... There is a 50-50 chance of you making the right call.\nMaking the right call will deccrement the no of choices made 2.\nWhile making the wrong choice will increment the choices made by 2.\n";
			typewrite(message);
			cout << "\nPress 1 to call HEADS\nPress 2 to call TAILS\n\n";
			srand(time(0));
			char temp = (char)(rand() % 2 + 49);

			do
			{
				val = _getche();

				if (val == temp)
				{
					choices -= 2;
					inventory = "Snooker Card";
					ScreenClearer("LEVEL NO 3");
					message = "\nYou made the right call....As a result your choices get decremented by 2.\nAlso the Shop owner gave you a Snooker Card as a reward.\n ";
					typewrite(message);

					system("pause");
					break;

				}
				else if (val == '1' || val == '2')
				{

					choices += 2;
					ScreenClearer("LEVEL NO 3");
					message = "\nYou made the wrong call....As a result your choices get incremented by 2.\n\n ";
					typewrite(message);

					system("pause");
					break;
				}

			} while (val != '1' && val != '2'); // end of do-while


			break;
		}

		case '2':
		{
			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}
			ScreenClearer("LEVEL NO 3");
			message = "\nYou chose not to eat food. You are focused on your goal rather than doing side quests......\n\n";
			typewrite(message);

			system("pause");

			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2'); // end of do-while



	ScreenClearer("LEVEL NO 3");

	message = "\nYou left C1 and went towards SADA.....\n\n";
	typewrite(message);

	system("pause");

	//End of Riddle 1 of 4

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}



	// Start of riddle 2 of 4

	ScreenClearer("LEVEL NO 3");
	message = "\nYou are now at the Main Gate of SADA... Only SADA Student are allowed to enter in SADA.\nYou aren't a SADA Student so you must solve this question displayed on the entry board in order to get a direct entry.\n\nYou have to find the no of triangle embedded in this illusiom:\n\n";
	typewrite(message);

	message = SADATriangle();
	typewrite(message);

	cout << "How many triangles do you see here?\n";
	cout << "\nPress 1 for [8]\nPress 2 for [14]\nPress 3 for [15]\nPress 4 for [17]\n\n ";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	do
	{
		val = _getche();

		switch (val)
		{

		case '1':
		case '2':
		case '3':
		{

			ScreenClearer("LEVEL NO 3");
			message = "\nYou made the wrong choice......As a result the system didn't allow to enter in SADA.\nYou will get the ticket in SADA. So you must find a way in.\n";
			typewrite(message);

			system("pause");

			ScreenClearer("LEVEL NO 3");
			message = "\nYou must go inside SADA. You can either rush from the main gate or can use the back door.\nBack door will however cause increase in choices. What will you do\n";
			typewrite(message);

			cout << "\nChoice 1: Rush\nChoice 2: Use the back door\n";
			cout << "\nPress 1 to select Choice 1\nPress 2 to select choice 2\n";
			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}
			do
			{
				val1 = _getche();

				switch (val1)
				{
				case '1':
				{
					confidence -= 3;
					ScreenClearer("LEVEL NO 3");
					message = "\nYou chose to rush...... As a result, you find yourself in an awkward situation.\nWhere people are looking at you strangely.\n\nAs a result, Your Confidence gets dropped by 3 bars\n";
					typewrite(message);

					system("pause");
					break;
				}

				case '2':
				{

					ScreenClearer("LEVEL NO 3");
					message = "\nYou chose to pick the alternate route.....You reached the back side of SADA and entered the department from there.\nAs you chose the long route... Your Choices made counter gets increased by 1.\n";
					typewrite(message);

					system("pause");
					break;
				} // end of case 2
				} // end of switch
			} while (val1 != '1' && val1 != '2'); // end of do-while




			break;
		}

		case '4':
		{

			ScreenClearer("LEVEL NO 3");
			message = "\nWOW !...... You guessed it correctly. The guard let you go inside SADA as you have gained his trust.\nSo you get inside SADA.\n";
			typewrite(message);

			system("pause");

			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2' && val != '3' && val != '4'); // end of do-while

	// End of riddle 2 of 4

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}



	// Start of riddle 3 of 4

	ScreenClearer("LEVEL NO 3");
	message = "\nYou Finally managed to get inside SADA.....You are walking through the corridor and saw a missing piece of project that's quite expensive.\nThis is a sharp object and can cause a serious injury if someone steps on it. It is lying on the floor and is about 10m away from its actual location.\nYou can deal with the situation in 2 ways.\n";
	typewrite(message);

	cout << "\nChoice 1: Place the piece back on the project\nChoice 2: Let the piece remain lying on the floor\n";
	cout << "\nPress 1 to make the first choice.\nPress 2 to make the second choice.\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}
	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{

			ScreenClearer("LEVEL NO 3");
			message = "\nYou decided to pick that missing piece and place it on the project......";
			typewrite(message);
			system("pause");

			confidence -= 2;
			ScreenClearer("LEVEL NO 3");
			message = "\nWhoops ! ........ YOU BROKE THE PROJECT !!!!!\n\nEveryone is starring at you...... Your confidence bar gets dropped by 2.\n\nYou quickly need to do something.\n\n";
			typewrite(message);

			cout << "\nChoice 1: Remain Standing there unfazed like a MAN\nChoice 2: Run away from the spot\n";
			cout << "\nPress 1 to make the first choice.\nPress 2 to make the second choice.\n";
			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}
			do
			{
				val1 = _getche();

				switch (val1)
				{
				case '1':
				{

					ScreenClearer("LEVEL NO 3");
					message = "\nYou fear no one ..... You remain standing there without any fear !.... But it didnt last long.\nThe guard arrived and he is now interacting with you.\n\nYou can respond in 2 ways.\n";
					typewrite(message);

					cout << "\nChoice 1: Apologize for the loss\nChoice 2: Refuse to accept your mistake - Argue\n";
					cout << "\nPress 1 to make choice 1.\nPress 2 to make choice 2.\n";
					choices++;

					GameCheck(); // Termminates the game if true
					if (game == false) {
						return false;
					}
					do
					{
						val2 = _getche();

						switch (val2)
						{
						case '1':
						{
							confidence -= 2;
							ScreenClearer("LEVEL NO 3");
							message = "\nYou accepted your mistake and apologized as you didnt do it knowingly.... You have to pay mimimal cost of the loss.\n\nSo your confidence drops by 2 bar.\n";
							typewrite(message);

							system("pause");
							break;
						}

						case '2':
						{
							confidence -= 6;
							ScreenClearer("LEVEL NO 3");
							message = "\nYou REFUSED to accept your mistake and are pretending to be innocent.....\nThe guard watches the security camera and you have been exposed !!!.\n\nThis incident embarassed you.... Now you have to pay the price. Six confidence bars have been deducted as the price of the loss.\n";
							typewrite(message);
							system("pause");

							break;
						} // end of case 2
						} // end of switch
					} while (val2 != '1' && val2 != '2'); // end of do-while

					break;
				}

				case '2':
				{

					ScreenClearer("LEVEL NO 3");
					message = "\nYou think that running away is the best option.....So, you leave the spot before the arrival of any faculty member.\n ";
					typewrite(message);

					system("pause");
					break;
				} // end of case 2
				} // end of switch
			} while (val1 != '1' && val1 != '2'); // end of do-while





			break;
		}

		case '2':
		{

			ScreenClearer("LEVEL NO 3");
			message = "\nYou let that piece remain lying the floor..... You are now walking across SADA to find the ticket.\n\n ";
			typewrite(message);
			system("pause");

			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2'); // end of do-while



	string scode;


	ScreenClearer("LEVEL NO 3");

	message = "\nYou come across a Random Number Generator machine in SADA.\nThis machine takes a 1 digit input and then generates a random 5 digit code from it.\n\n ** DONT FORGET THIS CODE **\n\n";
	typewrite(message);
	choices++;
	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}
	do
	{
		cout << "\nEnter a digit from 1 to 9: ";
		val = _getche();

		if (val >= '1' && val <= '9')
		{
			long int code = val * (rand() % 10000 + 10000);

			if (code < 10000)
				code = code * 10;

			else if (code > 99999)
				code = code / 10;

			code = tolower(code);

			scode = to_string(code);

			ScreenClearer("LEVEL NO 3");
			message = "\nYour special code is : " + scode + " \n\nDont Forget this code.\n\n";
			typewrite(message);

			system("pause");

		}

	} while (val < '1' || val > '9'); // end of do-while


	// End of riddle 3 out of 4

	GameCheck(); // Termminates the game if true

	//Start of riddle 4 out of 4

	ScreenClearer("LEVEL NO 3");
	message = "\nYou are now roaming around SADA, searching for the ticket generating machine.\nYour actions seems a bit suspicious. A faculty member approaches you and asks whether you are from SADA.\nYou have two choices.\n";
	typewrite(message);

	cout << "\nChoice 1: Yes, I am from SADA\nChoice 2: No, I am not from SADA\n";
	cout << "\nPress 1 to select Choice no 1.\nPress 2to select choice no 2.\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}
	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{

			ScreenClearer("LEVEL NO 3");
			message = "\nYou Told the faculty staff that you are from SADA....... He don't trust you. So, he asks you to display your card\nYou can respond in two ways.\n";
			typewrite(message);

			cout << "\nChoice 1: Display your card\nChoice 2: Sorry, I dont have it\n";
			cout << "\nPress 1 to make the first choice.\nPress 2 to make the second choice.\n";
			choices++;
			val1 = 1;
			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}
			do
			{
				val1 = _getche();

				switch (val1)
				{
				case '1':
				{
					confidence--;
					ScreenClearer("LEVEL NO 3");
					message = "\nYou displayed your NUST ID Card......Your card says that you are from SEECS.\nFaculty Member laughs at you.\n\nAs a result your confidence gets dropped by 1 bar\n";
					typewrite(message);

					system("pause");
					break;
				}

				case '2':
				{

					ScreenClearer("LEVEL NO 3");
					message = "\nYou told him that you don't have your NUST ID Card at the moment. You Further told him that you are here to take the ticket\nSo he let you go.\n";
					typewrite(message);

					system("pause");

					break;
				} // end of case 2
				} // end of switch
			} while (val1 != '1' && val1 != '2'); // end of do-while

			break;
		}

		case '2':
		{

			ScreenClearer("LEVEL NO 3");
			message = "\nYou told him that you aren't from SADA......\n\n";
			typewrite(message);

			system("pause");
			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2'); // end of do-while

	if (val1 != '2')
	{
		ScreenClearer("LEVEL NO 3");
		message = "\nThe Faculty Member asks your reason for being here.....You can respond in two ways.\n";
		typewrite(message);
		cout << "\nChoice 1: I am Here for Ticket\nChoice 2: None of your concern , Sir\n";
		cout << "\nPress 1 to make the first choice.\nPress 2 to make the second choice.\n";
		choices++;

		GameCheck(); // Termminates the game if true
		if (game == false) {
			return false;
		}
		do
		{
			val = _getche();

			switch (val)
			{
			case '1':
			{

				ScreenClearer("LEVEL NO 3");
				message = "\nYou told him that you are here to take the ticket\nSo he let you go.\n\n";
				typewrite(message);

				system("pause");
				break;
			}

			case '2':
			{
				choices += 3;
				ScreenClearer("LEVEL NO 3");
				message = "\nYou talked rudely to him....He is furious at you. He insulted you and as a penalty, your choices counter increses by 3.\n\n";
				typewrite(message);
				system("pause");

				break;
			} // end of case 2
			} // end of switch
		} while (val != '1' && val != '2'); // end of do-while

	} // End of if statement

	ScreenClearer("LEVEL NO 3");
	message = "\nYou have now reached near the Seminar Hall of SADA. Here you find the Ticket Generating Machine.\n\nThe Machine requires a 5-Digit code to issue a ticket. The no of choices made will increase with the no of tries taken.\n";
	typewrite(message);

	cout << "\nEnter the 5-Digit code you generated earlier: ";
	counter = 0;

	string temp;

	while (counter < 3)
	{
		cin >> temp;

		if (temp == scode)
		{
			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}
			ScreenClearer("LEVEL NO 3");
			message = "\nCongratulations! You entered the correct number... You have succesfully recieved the ticket.\n\n";
			typewrite(message);

			system("pause");

			break;
		}
		else
		{
			cout << "\nOops....You entered incorrect code.\n\nEnter the Code Again: ";
		}

		choices++;
		counter++;
	}

	if (counter >= 3)
	{
		system("pause");
		ScreenClearer("LEVEL NO 3");

		message = "\nYou have failed to generate ticket in 3 tries. Hence to get the ticket you have to redeem.\n\n";
		typewrite(message);

		cout << "\nChoice 1: Trade 4 choices\nChoice 2: Trade 4 Confidence bars\n";
		cout << "\nPress 1 to accept offer 1.\nPress 2 to accept offer 2.\n";
		choices++;
		do
		{
			val = _getche();

			switch (val)
			{
			case '1':
			{
				choices += 4;
				ScreenClearer("LEVEL NO 3");
				message = "\nYou accepted offer no 1.\n\nAs a result your choices made counter gets increased by 4.\n\n";
				typewrite(message);

				system("pause");

				break;
			}

			case '2':
			{
				confidence -= 4;
				ScreenClearer("LEVEL NO 3");
				message = "\nYou accepted offer no 2.\n\nAs a result your confidence meter drops by 4 bars.\n\n";
				typewrite(message);

				system("pause");
				break;
			} // end of case 2
			} // end of switch
		} while (val != '1' && val != '2'); // end of do-while



	}

	// End of riddle 4 out of 4

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	game = true;
	return true;
}
bool level4()
{

	ScreenClearer("LEVEL NO 4");
	message = "\nWelcome to Level No 4........Now, you have to go to the old gym. You have two options to reach there:\n";
	typewrite(message);
	cout << "\nChoice 1: Stand by the road and ask someone for a lift.";
	cout << "\nChoice 2: Walk to the old gym\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}
	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{

			ScreenClearer("LEVEL NO 4");
			message = "\nYou have successfully taken a lift  to old gym. In the old gym, you look at some people playing table tennis.\nSo you decide to join in.\n.\n.\n.\nHowever, after a while the gym staff approaches you and asks you to leave as you aren't appropriately dressed.\n";
			typewrite(message);
			cout << "\nChoice 1: Leave without saying a word";
			cout << "\nChoice 2: Argue with him";
			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}

			do
			{
				val1 = _getche();

				switch (val1)
				{
				case '1':
				{

					ScreenClearer("LEVEL NO 4");
					message = "\nYou left without saying a word....\n";
					typewrite(message);
					system("pause");
					break;
				}

				case '2':
				{
					confidence--;
					ScreenClearer("LEVEL NO 4");
					message = "\nYou argued with him but it only wasted your time. Finally, you had to leave the sports area. This has resulted in loss of confidence\n";
					typewrite(message);

					system("pause");

					break;
				} // end of case 2
				} // end of switch
			} while (val1 != '1' && val1 != '2'); // end of do-while


			break;
		}

		case '2':
		{
			choices++;
			confidence--;
			ScreenClearer("LEVEL NO 4");
			message = "\nOOPS!! While you were walking to old gym, you slipped and fell down. Your clothes got real;y dirty so you had to go change your clothes. This has resulted in a loss confidence and time, which also means a loss of choices.\n";
			typewrite(message);

			system("pause");

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}

			message = "\nAfterwards, you walk to old gym and start playing snooker there. There, you are asked to show your snooker card.\n";
			typewrite(message);
			if (inventory == "Snooker Card")
			{
				message = "\nYou have a snooker card in your inventory. Select 1 to use it.\n";
				typewrite(message);
				cout << "1. Show snooker card";
				do
				{
					val = _getche();

					switch (val)
					{
					case '1':
					{
						inventory = "nothing";
						ScreenClearer("LEVEL NO 4");
						message = "\nYou showed your snooker card and played snooker without any disturbance\n";
						typewrite(message);
						system("pause");

						break;
					}


					} // end of switch
				} while (val != '1'); // end of do-while


			}
			else
			{
				message = "\nYou don't have a snooker card in your inventory. So you have been asked to leave.\n";
				typewrite(message);
				cout << "\nChoice 1: Leave.";
				cout << "\nChoice 2: Argue.";
				choices++;

				GameCheck(); // Termminates the game if true
				if (game == false) {
					return false;
				}

				do
				{
					val = _getche();

					switch (val)
					{
					case '1':
					{

						break;
					}

					case '2':
					{

						ScreenClearer("LEVEL NO 4");
						message = "\nArguing led to you being forced to leave the snooker table. As a result, you lost confidence.\n";
						typewrite(message);
						confidence--;

						break;
					} // end of case 2
					} // end of switch
				} while (val != '1' && val != '2'); // end of do-while
			}



			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2'); // end of do-while

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	if (inventory != "Snooker Card")
	{
		ScreenClearer("LEVEL NO 4");
		message = "\nWhile leaving the old gym, you walk by the gym. You are not allowed to enter without membership. What will you do?\n";
		typewrite(message);
		cout << "\nChoice 1: Walk Through The GYM anyway\n";
		cout << "\nChoice 2: Walk through the other side\n";
		choices++;

		GameCheck(); // Termminates the game if true
		if (game == false) {
			return false;
		}

		do
		{
			val = _getche();

			switch (val)
			{
			case '1':
			{
				confidence -= 3;
				ScreenClearer("LEVEL NO 4");
				message = "\nYou were caught by the gym staff. You were insulted infront of everyone for breaking the rules and now you're really embarrased. Your confidence went down by 3 as a result.\nSHAME!\n";
				typewrite(message);
				system("pause");

				break;
			}

			case '2':
			{



				break;
			} // end of case 2
			} // end of switch
		} while (val != '1' && val != '2'); // end of do-while

		GameCheck(); // Termminates the game if true
		if (game == false) {
			return false;
		}

	}
	ScreenClearer("LEVEL NO 4");
	message = "\nYou have finally reached S3H now. Here, you start talking to a girl asking for clues to find the code.\nBut she will only guide you after you answer her question.\n\"Who is your favourite singer?\"\n";
	typewrite(message);
	cout << "\nChoice 1: Taylor Swift";
	cout << "\nChoice 2: Chahat Fateh Ali Khan";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{

			ScreenClearer("LEVEL NO 4");
			message = "\nThe girl is glad to know that you both have the same favourite singer. So she guided you to the code.";
			typewrite(message);

			system("pause");

			break;
		}

		case '2':
		{

			ScreenClearer("LEVEL NO 4");
			message = "\nWow! You surely have a great taste in music. However, the girl didn't like your answer. So she wont guide you towards the code\n";
			typewrite(message);

			system("pause");
			ScreenClearer("LEVEL NO 4");
			message = "\nNow, you are looking for someone else to guide you. Suddenly, you come across a rather unique person. That person has the physical appearance of a man but is dressed as a female.\nYou want to ask for help but you don't kow how to address that person.";
			typewrite(message);
			cout << "\nChoice 1: \"Brother, can you tell me where I can find the code?\"";
			cout << "\nChoice 2: \"Sister, can you tell me where I can find the code?\"";
			cout << "\nChoice 3: \"Hey, can you tell me where I can find the code?\"";
			choices++;

			GameCheck(); // Termminates the game if true
			if (game == false) {
				return false;
			}

			do
			{
				val = _getche();

				switch (val)
				{
				case '1':
				case '2':
				{
					choices += 2;
					ScreenClearer("LEVEL NO 4");
					message = "\nThat person got offended and won't guide you to the code.\n.\n.\n.\nYou eventually got someone to guide you but it resulted in loss of choices you can make as you have lost time\n";
					typewrite(message);
					system("pause");
					break;
				}



				case '3':
				{

					ScreenClearer("LEVEL NO 4");
					message = "\nGood choice.\nThat person guided you to the code.\n";
					typewrite(message);
					system("pause");
					break;
				} // end of case 3
				} // end of switch
			} while (val != '1' && val != '2' && val != '3'); // end of do-while





			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2'); // end of do-while

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	int chances = 1;

label: {
	ScreenClearer("LEVEL NO 4");
	message = "\nYou found out that the code can be found in S3H sheds.\nYou reach the sheds and here you find a lottery machine. Press 1 to use it.\n";
	typewrite(message);


	do
	{
		val = _getche();

		switch (val)
		{
		case '1':
		{

			ScreenClearer("LEVEL NO 4");
			srand((unsigned)time(0));
			string abc = "1";
			int efg = rand() % 2 + 1;
			int ijk = rand() % 2 + 1;

			string str1 = to_string(efg);
			string str2 = to_string(ijk);

			string str = abc + str1 + str2;
			if (str == "111")
			{
				cout << endl << str << " -  Is the number after a spin.\n";
				message = "\nCongratulations! You have successfully gotten the code from the machine.\nYou have completed level 4.\n";

				typewrite(message);
				choices++;
				system("pause");
			}
			else
			{
				cout << endl << str;
				chances++;
				choices++;

				GameCheck(); // Termminates the game if true
				if (game == false) {
					return false;
				}

				message = " - Is the number after spin - Try again";
				typewrite(message);

				system("pause");
				if (chances <= 4)
					goto label;



				break;
			}

		}
		}  // end of switch
	} while (val != '1');// end of do-while


	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}




	system("pause");
	game = true;
	return true;



	}
}
bool level5()

{
	ScreenClearer("LEVEL NO 5");

	message = "\nWelcome to LEVEL NO 5.\n\nHere you will play 5 mini games. You have to collect a minimum of 10 coins to finish the game.\n\nIf you fail to get minimum 10 coins at the end of the game your confidence meter will call to zero and eventually the game will end\n\n";
	typewrite(message);

	system("pause");

	ScreenClearer("LEVEL NO 5");
	message = "\nThis is a rock-paper scissors game. Win this game to win 3 coins.\n\nChoice 1: Pick Rock\nChoice 2: Pick Paper\nChoice 3: Pick Scissors\n";
	typewrite(message);

	cout << "\nPress 1 to pick rock.\nPress 2 to pick paper.\nPress 3 to pick scissors.\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	srand((unsigned)time(0));
	char random = (char)(rand() % 3 + 49); // 1 for rock 2 for paper 3 for scissors


	do {
		val = _getche(); // Gets the user input

		// Determine the winner
		if (random == val) {
			coins++;
			cout << "\nIt's a tie! You both picked ";
			if (val == '1') {
				cout << "rock.\n";
			}
			else if (val == '2') {
				cout << "paper.\n";
			}
			else if (val == '3') {
				cout << "scissors.\n";
			}
		}
		else if ((val == '1' && random == '3') || (val == '2' && random == '1') || (val == '3' && random == '2')) {
			coins += 3;
			cout << "\nYou win! You picked ";
			if (val == '1') {
				cout << "rock.\n";
			}
			else if (val == '2') {
				cout << "paper.\n";
			}
			else if (val == '3') {
				cout << "scissors.\n";
			}
		}
		else {

			if (val == '1' || val == '2' || val == '3')
			{
				cout << "\nComputer wins! You picked ";
				if (val == '1') {
					cout << "rock.\n";
				}
				else if (val == '2') {
					cout << "paper.\n";
				}
				else if (val == '3') {
					cout << "scissors.\n";
				}
			}
		}

	} while (val != '1' && val != '2' && val != '3');

	cout << "\n";
	system("pause");


	ScreenClearer("LEVEL NO 5");
	message = "\nIn this mini game you have to find the mess bill:\n\nThe mess bill for whole month is 13,175. You have had 7 days off from mess. What would be your grand total?\n\n ";
	typewrite(message);

	cout << "\nPress 1 to select 10,095.\nPress 2 to select 10,625.\nPress 3 to Select 10,200.\nPress 4 to select 9775.\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	do
	{
		val = _getche(); // Gets the user input

		switch (val)
		{
		case '1':
		case '2':
		case '4':
		{

			ScreenClearer("LEVEL NO 5"); // Displays UI
			message = "\n You guessed it wrong.\n\nAs a result you got no coins.\n";
			typewrite(message);

			system("pause");

			break;
		}

		case '3':
		{
			coins += 3;
			ScreenClearer("LEVEL NO 5");
			message = "\nYou guessed it right.\n\nAs a result your coins gets increased by 3.\n";
			typewrite(message);

			system("pause");

			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2' && val != '3' && val != '4'); // end of do-while

	// end of R2

	ScreenClearer("LEVEL NO 5");
	message = "\nThis is Riddle no 3.\n\nIn this riddle You have to guess the country with Hints.\n\nRabat is the capital of which country?\n\n";
	typewrite(message);

	cout << "\nPress 1 to pick Lebanon\nPress 2 to pick Morocoo\nPress 3 to pick Libya\nPress 4 to pick Algeria\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}
	do
	{
		val = _getche(); // Gets the user input

		switch (val)
		{
		case '1':
		case '3':
		case '4':
		{

			ScreenClearer("LEVEL NO 5"); // Displays UI
			message = "\n You guessed it wrong.\n\nAs a result you got no coins.\n";
			typewrite(message);

			system("pause");

			break;
		}

		case '2':
		{
			coins += 3;
			ScreenClearer("LEVEL NO 5");
			message = "\nYou guessed it right. Rabat is indeed Capital of Morocco.\n\nAs a result your coins gets increased by 3.\n";
			typewrite(message);

			system("pause");

			break;
		} // end of case 2
		} // end of switch
	} while (val != '1' && val != '2' && val != '3' && val != '4'); // end of do-while

	//End of riddle no 3

	ScreenClearer("LEVEL NO 5");
	message = "\nThis is mini game no 4.\nHere are 4 buttons infront of you. One button gives 3 coins. One gives 2 coins. One gives 1 and the other gives zero.\n ";
	typewrite(message);

	cout << "\nPress 1 to click Button1.\nPress 2 to click Button 2.\nPress 3 to click button 3.\nPress 4 to click button 4.\n";
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	srand((unsigned)time(0));
	char temp = (char)rand() % 4 + 1;
	int temp1;

	do
	{
		val = _getche(); // Gets the user input

		if (temp == val)
		{
			coins += 3;
			message = "\nYou got 3 coins....\n\n";
			system("pause");
		}
		else if (val == '1' || val == '2' || val == '3' || val == '4')
		{
			srand((unsigned)time(0));
			temp1 = (rand() % 3);
			coins = coins + temp1;
			cout << "\nYou got " << temp1 << "coins....\n\n";
			system("pause");
		}
	} while (val != '1' && val != '2' && val != '3' && val != '4'); // end of do-while

	ScreenClearer("LEVEL NO 5");
	message = "\nWelcome to Mini-Game no 5. Here is a word puzzle.\n Find 3 words from it. One will give you 3 coins , other will give 2 , while the last will give 1.\n\n";
	typewrite(message);
	choices++;

	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}

	cout << "\n\nT E G U A V A F W\nH A J K L M G D U\nR W C U P E A R I\nA P O S V X U S P\nM X E Q G J W I A\nN Z V B E K F Y Z\nS O U O Q M P N O\nQ W Y L E J Y X A\nV K U G G M I X X\nY S U P Z G F M R\n";

	string word;
	cout << "\nEnter the word to get coins.(only write in lowercase without spaces) \n";
	cin >> word;

	if (word == "mango")
	{

		coins += 3;
		ScreenClearer("LEVEL NO 5");
		message = "\n You guessed 3 coins word......\n\n";
		typewrite(message);

		system("pause");
	}
	else if (word == "guava")
	{
		coins += 1;
		ScreenClearer("LEVEL NO 5");
		message = "\n You guessed 1 coins word......\n\n";
		typewrite(message);

		system("pause");
	}
	else if (word == "pear")
	{
		coins += 2;
		ScreenClearer("LEVEL NO 5");
		message = "\n You guessed 2 coins word......\n\n";
		typewrite(message);

		system("pause");
	}
	else
	{
		message = "\n You guessed it wrong . you get 0 coins......\n\n";
		typewrite(message);

		system("pause");
	}
	GameCheck(); // Termminates the game if true
	if (game == false) {
		return false;
	}


	game = true;
	if (coins < 10)
	{
		GameCheck(); // Termminates the game if true
		if (game == false) {
			return false;
		}
		game = false;
		ScreenClearer("GAME OVER");
		message = "\nYou failed to collect 10 coins.....\n\nAs a result You failed the game.\n\n";
		typewrite(message);
		exit(0);

	}
	else
		return true;
}

bool ending()
{
	ScreenClearer("ENDING");

	message = "\nCongratulations!! You have all the items required to finish the game. Your player has succesfully exited NUST.\n\n";
	typewrite(message);

	exit(0);
	game = true;
	return false;

}

