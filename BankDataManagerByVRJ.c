/********************************************************************************************************************
 Project made by Vishvdeepsinh R Jadeja
 C program where user can save their bank transection data securly.
 User don't have to open app, need internet, bank server down or anything, just keep your every transection input
 in this file and use whenever you want.
 ********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 102   // 0 to 98 for transection history, 99 for balance, remaing for others(soon).

void saveData(int data[], int size) {
    FILE *file = fopen("bankData.txt", "w");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", data[i]);
    }
    fclose(file);
}

void loadData(int data[], int size) {
    FILE *file = fopen("bankData.txt", "r");
    if (file == NULL) {
        for (int i = 0; i < size; i++) data[i] = 0;
        return;
    }
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &data[i]) != 1) {
            data[i] = 0;
        }
    }
    fclose(file);
}

int passCheck(int ispass){
    int pin = 700182; //change to your pin here.
    int ans;
    printf("Pin please:\n");
    scanf("%d",&ans);
    if(ans==pin){
        printf("Pin is correct\n");
        return 1;
    }
    else return 0;
}

int main() {
    int data[SIZE]; 
    int answer, answer2;
    int isPass=passCheck(isPass);
    
    loadData(data, SIZE);

    int tid = data[99];   
    int *balance = &data[100]; 
    if(isPass==1)
    {
        start:
        printf("\nPlease input your answer:\n"
           "1. Balance Check\n"
           "2. Deposit\n"
           "3. Withdraw\n"
           "4. Transactions\n"
           "5. EXIT\n");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            printf("Your balance is %d rs.\n", *balance);
            goto start;

        case 2:
            if (tid >= 99) {
                printf("Transaction history is full!\nDo you want to clear history? (1.Yes / 2.No): ");
                int choice;
                scanf("%d", &choice);
                if (choice == 1) {
                    for (int i = 0; i < 99; i++) data[i] = 0;
                    tid = 0;
                    data[99] = tid;
                    saveData(data, SIZE);
                    printf("History cleared.\n");
                } else {
                    goto start;
                }
            }
            printf("How much you want to deposit: ");
            scanf("%d", &answer2);
            *balance += answer2;
            data[tid++] = answer2;
            data[99] = tid;
            saveData(data, SIZE);
            printf("\n%d rs. Deposited successfully.\n", answer2);
            goto start;

        case 3:
            if (tid >= 99) {
                printf("Transaction history is full!\nDo you want to clear history? (1.Yes / 2.No): ");
                int choice;
                scanf("%d", &choice);
                if (choice == 1) {
                    for (int i = 0; i < 99; i++) data[i] = 0;
                    tid = 0;
                    data[99] = tid;
                    saveData(data, SIZE);
                    printf("History cleared.\n");
                } else {
                    goto start;
                }
            }
            printf("How much you want to withdraw: ");
            scanf("%d", &answer2);
            if (answer2 > *balance) {
                printf("Not enough balance!\n");
            } else {
                *balance -= answer2;
                data[tid++] = -answer2; 
                data[99] = tid;
                saveData(data, SIZE);
                printf("\n%d rs. Withdrawn successfully.\n", answer2);
            }
            goto start;

        case 4:
            printf("Your Transaction History:\n");
            for (int j = 0; j < tid; j++)
                printf("%d\n", data[j]);
            printf("Current Balance = %d rs.\n", *balance);
            goto start;

        case 5:
            printf("Exiting...\nProgram by V.R.Jadeja");
            break;

        default:
            printf("Invalid input!\n");
            goto start;
        }
    }
    else printf("\nYou not have access\n");
    return 0;
}
