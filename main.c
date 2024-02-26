#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct Computer{
    int identifier;
    char *name;
}Computer;

char *rpsComSelector(char *item, Computer *items[]);
int hierarchy(char *player, char *computer);
void initializeComputer(Computer *rock, Computer *paper, Computer *scissors);
int main(int argc, char *argv[]){
    puts("Let's play rock-paper-scissors!");
    int pScore, comScore;
    pScore = comScore = 0;
    Computer *rock = malloc(sizeof(Computer));
    Computer *paper = malloc(sizeof(Computer));
    Computer *scissors = malloc(sizeof(Computer));
    initializeComputer(rock, paper, scissors);
    Computer *allItems[3] = {rock, paper, scissors};
    int playAgain = 1;
    while(playAgain){
        char player[10];
        printf("Enter your selection: ");
        scanf("%9s", player);
        if(strcmp(player, "rock") != 0 && strcmp(player, "paper") != 0 && strcmp(player, "scissors") != 0){
            puts("That item is not allowed in rock-paper-scissors");
            exit(EXIT_FAILURE);
        }
        char *comp = rpsComSelector(player, allItems);
        printf("ROCK!\n");
        fflush(stdout);
        sleep(1);
        printf("PAPER!\n");
        fflush(stdout);
        sleep(1);
        printf("SCISSORS!\n");
        fflush(stdout);
        sleep(1);
        printf("SHOOOOOOOOT!!!!\n");
        fflush(stdout);
        sleep(1);
        printf("\nPlayer selected: %s\n", player);
        printf("Computer selected: %s\n", comp);

        if(hierarchy(player, comp)){
            pScore++;
        }
        else if(strcmp(player, comp) != 0){
            comScore++;
        }
        printf("%c", '\n');
        printf("Player score: %d\n", pScore);
        printf("Computer score: %d\n", comScore);
        printf("%c", '\n');
        printf("Continue? (Type 0 to terminate, 1 to continue): ");
        scanf("%d", &playAgain);
        printf("\n--------------------------------------------------\n");
    }
    puts("\nThanks for playing!");
    return 0;
}

void initializeComputer(Computer *rock, Computer *paper, Computer *scissors){
    rock->identifier = 0;
    rock->name = "rock";
    paper->identifier = 1;
    paper->name = "paper";
    scissors->identifier = 2;
    scissors->name = "scissors";
}

char *rpsComSelector(char *item, Computer *items[]){
    srand(time(NULL));
    int index = rand() % 3;
    Computer *selection = items[index];
    char *ret = selection->name;
    return ret;
}


int hierarchy(char *player, char *computer){
    if(strcmp(player, "rock") == 0){
        if(strcmp(computer, "scissors") == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(strcmp(player, "paper") == 0){
        if(strcmp(computer, "rock") == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(strcmp(computer, "paper") == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}
