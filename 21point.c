/*
 ============================================================================
 Name        : FinalProject_ID.c (use your ID as the file name)
 Author      : Yi-Ju Tseng (put your name here), ID (put your ID here)
 Description :
 This is the final project for C Programming! 
 Your work is to implement your strategy for asking cards in a BlackJack game.
 The strategy need to be implemented in the askCard_B0000000 funciton.
 Please don't edit the codes not in the askCard_B0000000 funciton.
 # comments * 10pt
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shuffle(short[][2]);
void printCardAndPoint(short[][2], short n_card);
int calculatePoint(short[][2], short n_card);
void comparePointWithBanker(int, int, char *, int *, int, int);
int askCard_Banker(short[][2], short*, int, int);
/*TODO: Please implement your strategy for asking cards */
int askCard_B0000000(char *yourName, short cards[][2], short *n_card, short banker_cards_open[][2], short used_card[][2], short n_used) /* Please replace B0000000 with your name */
{
	int ask_card = 0;					/*return 0 if you don't want to have one more card (hit), return 1 if you want to have one more card */
  char *myName = "Student 1";			/* Please replace Student 1 with your name */
  strcpy(yourName, myName);
	printf("%s's cards:\n", yourName); /* Please don't edit this line */
	printCardAndPoint(cards, *n_card);	/* Please don't edit this line */
	/*Please finish the strategy below */
	if (calculatePoint(cards, *n_card) == 21)
	{
		printf("BlackJack!\n");
		ask_card = 0;
	}
	else if (calculatePoint(cards, *n_card) > 21)
	{
		printf("Bust!\n");
		ask_card = 0;
	}
	else if (calculatePoint(cards, *n_card) < 15)
	{
		ask_card = 1;
	}
	return ask_card;
}
/*TODO end*/

/* This is an example function, Please don't edit any codes below */
int askCard_YJT(char *yourName, short cards[][2], short *n_card, short banker_cards_open[][2], short used_card[][2], short n_used)
{
	int ask_card = 0;
  char *myName = "YJT";
  strcpy(yourName, myName);
	printf("%s's cards:\n", yourName);
	printCardAndPoint(cards, *n_card);

	if (calculatePoint(cards, *n_card) == 21)
	{
		printf("BlackJack!\n");
		ask_card = 0;
	}
	else if (calculatePoint(cards, *n_card) > 21)
	{
		printf("Bust!\n");
		ask_card = 0;
	}
	else if (calculatePoint(cards, *n_card) < 15)
	{
		ask_card = 1;
	}
	return ask_card;
}
/*Please don't edit the main function*/
int main(void)
{
	srand(time(NULL)); /*set random seed*/
  printf("Game start!\n");
	int user1_money = 1000; /*the initial money user 1 has*/
	int user2_money = 1000; /*the initial money user 2 has*/
	int user1_bet = 100;	/* user 1 bet $ */
	int user2_bet = 100;	/* user 2 bet $ */
	short cards[156][2];
	short used_cards[156][2];
	char *user1_name, *user2_name;

	/* Generate cards */
	for (int i = 0; i < 52; i++)
	{
		cards[i][0] = (i / 13) + 1; /*suit*/
		cards[i][1] = (i % 13) + 1; /*rank*/
	}
	for (int i = 0; i < 52; i++)
	{
		cards[i + 52][0] = (i / 13) + 1; /*suit*/
		cards[i + 52][1] = (i % 13) + 1; /*rank*/
	}
	for (int i = 0; i < 52; i++)
	{
		cards[i + 104][0] = (i / 13) + 1; /*suit*/
		cards[i + 104][1] = (i % 13) + 1; /*rank*/
	}
	shuffle(cards);
	int card_sequence = 0;
	int used_sequence=0;
	/* 	10 rounds */
	for (int i = 1; i <= 10; i++)
	{
		short banker_card_close[1][2], banker_cards_open[10][2];
		short user1_cards[10][2];
		short user2_cards[10][2];

		banker_card_close[0][0] = cards[card_sequence][0];
		banker_card_close[0][1] = cards[card_sequence][1];
		card_sequence++;
		banker_cards_open[0][0] = cards[card_sequence][0];
		banker_cards_open[0][1] = cards[card_sequence][1];
		used_cards[used_sequence][0] = cards[card_sequence][0];
		used_cards[used_sequence][1] = cards[card_sequence][1];
		used_sequence++;
		card_sequence++;

		user1_cards[0][0] = cards[card_sequence][0];
		user1_cards[0][1] = cards[card_sequence][1];
		used_cards[used_sequence][0] = cards[card_sequence][0];
		used_cards[used_sequence][1] = cards[card_sequence][1];
		used_sequence++;
		card_sequence++;
		user1_cards[1][0] = cards[card_sequence][0];
		user1_cards[1][1] = cards[card_sequence][1];
		used_cards[used_sequence][0] = cards[card_sequence][0];
		used_cards[used_sequence][1] = cards[card_sequence][1];
		used_sequence++;
		card_sequence++;

		user2_cards[0][0] = cards[card_sequence][0];
		user2_cards[0][1] = cards[card_sequence][1];
		used_cards[used_sequence][0] = cards[card_sequence][0];
		used_cards[used_sequence][1] = cards[card_sequence][1];
		used_sequence++;
		card_sequence++;
		user2_cards[1][0] = cards[card_sequence][0];
		user2_cards[1][1] = cards[card_sequence][1];
		used_cards[used_sequence][0] = cards[card_sequence][0];
		used_cards[used_sequence][1] = cards[card_sequence][1];
		used_sequence++;
		card_sequence++;

		/* let you know banker's open card */
		printf("Banker's open card:\n");
		printCardAndPoint(banker_cards_open, 1);
		short user1_cards_seq = 2;
		short user2_cards_seq = 2;
		short banker_cards_seq = 2;

		int user1_hit, user2_hit, banker_hit;

		/* Hit process */
		do
		{
			user1_hit = askCard_YJT(user1_name, user1_cards, &user1_cards_seq, banker_cards_open, used_cards,used_sequence);
			if (user1_hit)
			{
				printf("%s: one more card (Hit!)\n", user1_name);
				user1_cards[user1_cards_seq][0] = cards[card_sequence][0];
				user1_cards[user1_cards_seq][1] = cards[card_sequence][1];
				used_cards[used_sequence][0] = cards[card_sequence][0];
				used_cards[used_sequence][1] = cards[card_sequence][1];
				user1_cards_seq++;
				used_sequence++;
				card_sequence++;
			}
		} while (user1_hit);
		do
		{
			user2_hit = askCard_B0000000(user2_name, user2_cards, &user2_cards_seq, banker_cards_open, used_cards,used_sequence);
			if (user2_hit)
			{
				printf("%s: one more card (Hit!)\n", user2_name);
				user2_cards[user2_cards_seq][0] = cards[card_sequence][0];
				user2_cards[user2_cards_seq][1] = cards[card_sequence][1];
				used_cards[used_sequence][0] = cards[card_sequence][0];
				used_cards[used_sequence][1] = cards[card_sequence][1];
				user2_cards_seq++;
				used_sequence++;
				card_sequence++;
			}
		} while (user2_hit);

		printf("User 1's name: %s, total money %d, bet %d dollors\n", user1_name, user1_money, user1_bet);
		printf("User 2's name: %s, total money %d, bet %d dollors\n", user2_name, user2_money, user2_bet);
		used_cards[used_sequence][0] = banker_card_close[0][0];
		used_cards[used_sequence][1] = banker_card_close[0][1];
		used_sequence++;
		short banker_all_card[2][2] = {{banker_card_close[0][0], banker_card_close[0][1]}, {banker_cards_open[0][0], banker_cards_open[0][1]}};
		int user1_final_sum = calculatePoint(user1_cards, user1_cards_seq); /*User 1's total points*/
		int user2_final_sum = calculatePoint(user2_cards, user2_cards_seq); /*User 2's total points*/
		do{
			banker_hit=askCard_Banker(banker_all_card,&banker_cards_seq,user1_final_sum,user2_final_sum);
			if (banker_hit)
			{
				banker_all_card[banker_cards_seq][0] = cards[card_sequence][0];
				banker_all_card[banker_cards_seq][1] = cards[card_sequence][1];
				used_cards[used_sequence][0] = cards[card_sequence][0];
				used_cards[used_sequence][1] = cards[card_sequence][1];
				banker_cards_seq++;
				used_sequence++;
				card_sequence++;
			}
		}while(banker_hit);
		printf("Banker's all card:\n");
		printCardAndPoint(banker_all_card, banker_cards_seq);

		int banker_final_sum = calculatePoint(banker_all_card, banker_cards_seq);			/*Banker's total points*/
		

		printf("Round %d, %s's total points: %d\n", i, user1_name, user1_final_sum);
		printf("Round %d, %s's total points: %d\n", i, user2_name, user2_final_sum);
		printf("Round %d, Banker's total points: %d\n", i, banker_final_sum);
		comparePointWithBanker(banker_final_sum, user1_final_sum, user1_name, &user1_money, user1_bet, i);
		comparePointWithBanker(banker_final_sum, user2_final_sum, user2_name, &user2_money, user2_bet, i);
	}
	/* cards distribution */

	if (user1_money > user2_money)
	{
		printf("Final results: %s Win!\n", user1_name);
	}
	else if (user1_money < user2_money)
	{
		printf("Final results: %s Win!\n", user2_name);
	}
	else
	{
		printf("Final results: Tie, compete again!\n");
	}
	return 0;
}

/* Please don't edit any codes below */
void shuffle(short cards[][2])
{
	for (int i = 0; i < 156; i++)
	{
		short temp_suit, temp_rank, rand_place;
		temp_suit = cards[i][0];
		temp_rank = cards[i][1];
		rand_place = rand() % 156;
		cards[i][0] = cards[rand_place][0];
		cards[i][1] = cards[rand_place][1];
		cards[rand_place][0] = temp_suit;
		cards[rand_place][1] = temp_rank;
	}
}
void printCardAndPoint(short cards[][2], short n_card)
{
	for (int i = 0; i < n_card; i++)
	{
		printf("Suit=%d, Rank=%d ; ", cards[i][0], cards[i][1]);
	}
	printf("\nTotal points=%d \n", calculatePoint(cards, n_card));
}

int calculatePoint(short cards[][2], short n_card)
{
	int totalPoint = 0;
	int isAce = 0;
	for (int i = 0; i < n_card; i++)
	{
		if (cards[i][1] > 10)
		{
			totalPoint += 10;
		}
		else if (cards[i][1] == 1)
		{
			isAce = 1;
			totalPoint += cards[i][1];
		}
		else
		{
			totalPoint += cards[i][1];
		}
	}
	if (isAce == 1 & totalPoint <= 11)
	{
		totalPoint += 10;
	}
	return totalPoint;
}

void comparePointWithBanker(int banker_final_sum, int user_final_sum, char *user_name, int *user_money, int user_bet, int round)
{
	printf("Round %d, %s's results: ", round, user_name);
	if (banker_final_sum == user_final_sum)
	{
		printf("Tie! ");
	}
	else if ((banker_final_sum > user_final_sum&banker_final_sum<=21) || user_final_sum > 21)
	{
		*user_money -= user_bet;
		printf("You Lose! ");
	}
	else
	{
		*user_money += user_bet;
		printf("You Win! ");
	}

	printf("%s's money now is: %d\n", user_name, *user_money);
}

int askCard_Banker(short cards[][2], short *n_card, int user1_point, int user2_point)
{
	int banker_point=calculatePoint(cards,*n_card);
	int win=0;
	if (banker_point>user1_point||user1_point>21){
		win++;
	}else if (banker_point<user1_point||banker_point>21){
		win--;
	}
	if (banker_point>user2_point||user2_point>21){
		win++;
	}else if (banker_point<user2_point||banker_point>21){
		win--;
	}
	if(win>0){
		return 0;
	}else if(win<0 && banker_point<21){
		return 1;
	}else{
		return 0;
	}
}
