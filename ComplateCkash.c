    // main project //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


typedef struct {
    char name[50];
    char password[20];
    char gmail[50];
    char phone[15];
    char dob[15];
    float balance;
    char datetime[20];
} BankAccount;

BankAccount accounts[100];
int numAccounts = 0;

void fordelay(int j) {
    int i, k;
    for (i = 0; i < j; i++) {
        k = i;
    }
}

void saveAccountsToFile() {
    FILE *file = fopen("accounts.dat", "wb");
    if (file == NULL) {
        printf("Error saving accounts.\n");
        return;
    }
    fwrite(&numAccounts, sizeof(int), 1, file);
    fwrite(accounts, sizeof(BankAccount), numAccounts, file);
    fclose(file);
}

void loadAccountsFromFile() {
    FILE *file = fopen("accounts.dat", "rb");
    if (file == NULL) {
        return;
    }
    fread(&numAccounts, sizeof(int), 1, file);
    fread(accounts, sizeof(BankAccount), numAccounts, file);
    fclose(file);
}

void logTransaction(int accountIndex, const char* type, float amount) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    strftime(accounts[accountIndex].datetime, 20, "%Y-%m-%d %H:%M:%S", local);
    printf("\x1b[36mTransaction: \x1b[31m%s %.2f \x1b[36mon \x1b[31m%s\n", type, amount, accounts[accountIndex].datetime);
    saveAccountsToFile();
}

void adminLogin(){
    int adminLogin_exit;
    char adminUsername[10], adminPassword[10];
    printf("\n\n\t\t\x1B[31mEnter Admin Username: \x1B[36m");
    scanf("%s", adminUsername);
    printf("\t\t\x1B[31mEnter Admin Password: \x1B[36m");
    scanf("%s", adminPassword);

    if (strcmp(adminUsername, "admin") == 0 && strcmp(adminPassword, "6997") == 0){
        printf("\n\n\t\t\t\x1B[31mPassword Match! \x1B[36m\nLOADING");

        for (int i = 1; i <= 3; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
    }
    }
    else{
        printf("\x1B[31m");
        printf("\n\nWrong username or password!!!\a\a\a");
        printf("\x1B[36m");
        printf("\n\nEnter 1 to try again and 0 to exit: ");
        scanf("%d", &adminLogin_exit);

            if (adminLogin_exit == 1) {
            system("cls");
            adminLogin();
            } else if (adminLogin_exit == 0) {
            system("cls");
            menu();
            } else {
                system("cls");
                printf("\x1B[31m\n\n\n\n\n\n\n\t\t\t\tInvalid choice. Please try again...\n");
                Sleep(2000);
                system("cls");
                adminLogin();
            }
    }
}
void adminAcc2(){
    int adminAcc_exit;
    printf("\n\n\x1b[36mEnter \x1B[31m1 \x1B[36mto try again and \x1B[31m0 \x1B[36mto exit: \x1B[31m");
    scanf("%d", &adminAcc_exit);
    if (adminAcc_exit == 1) {
            system("cls");
            adminAcc();
        } else if (adminAcc_exit == 0) {
            system("cls");
            printf("\n\n\n\n\n\n\n");
            printf("\t\t\t\x1B[36mReturning to \x1B[31mMain menu");
            for (int i = 0; i <= 2; i++) {
                printf("\x1B[36m.");
                sleep(1);
            }
            system("cls");
            menu();
        } else {
            system("cls");
            printf("\x1B[31m\n\n\n\n\n\n\n\t\t\t\tInvalid choice. Please try again...\n");
            Sleep(2000);
            system("cls");
            adminAcc();
        }
}

void typingAnimation(const char *text) {
    while (*text) {
        printf("%c", *text++);
        fflush(stdout);
        usleep(50000);
    }
}

void adminAcc(){
    system("cls");
    typingAnimation("\x1b[36mWelcome Back, ");
    printf("\x1b[1;3;4;31mAdmin\x1b[0m\n\n");
    if(numAccounts == 0){
        printf("\n\t\t\t\t\x1b[31mNo accounts are created.\n\n\n\n");
        Sleep(2000);
        system("cls");
        menu();
    } else {
        printf("\n\t\t\t\t\x1b[36mTotal Accounts: \x1b[31m%d\n", numAccounts);
        printf("\n");

        for (int i = 0; i < numAccounts; i++) {
            printf("\x1b[36mAccount \x1b[31m#%d \x1b[36m- Name: \x1b[31m%s\n", i + 1, accounts[i].name);
        }

        int selectedAccount;
        printf("\n\n\n\x1b[36mSelect account \x1b[31m(1-%d)\x1b[36m: \x1b[31m", numAccounts);
        scanf("%d", &selectedAccount);

        if (selectedAccount >= 1 && selectedAccount <= numAccounts) {
            selectedAccount -= 1;  // Adjust for zero-based indexing
            int option;
            system("cls");
            printf("\n\x1b[36mAccount \x1b[31m#%d \x1b[36m(\x1b[1;3;4;31m%s\x1b[0;36m) is now Selected:\n",
       selectedAccount + 1, accounts[selectedAccount].name);


            printf("\n\t\t\t\t\x1b[31m1. \x1b[36mShow user details\n\t\t\t\t\x1b[31m2. \x1b[36mShow transaction history\n\nSelect an option: \x1b[31m");
            scanf("%d", &option);

            if (option == 1) {
                printf("\n\x1b[36mName: \x1b[31m%s\n\x1b[36mEmail: \x1b[31m%s\n\x1b[36mPhone: \x1b[31m%s\n\x1b[36mDate Of Birth: \x1b[31m%s\n\x1b[36mBalance: \x1b[31m%.2f\n\x1b[36mPassword: \x1b[31m%s\n",
                       accounts[selectedAccount].name, accounts[selectedAccount].gmail,
                       accounts[selectedAccount].phone, accounts[selectedAccount].dob,
                       accounts[selectedAccount].balance, accounts[selectedAccount].password);
                adminAcc2();
            } else if (option == 2) {
                printf("\x1b[36mLast Transaction: \x1b[31m%s\n", accounts[selectedAccount].datetime);
                adminAcc2();
            } else {
                system("cls");
            printf("\x1B[31m\n\n\n\n\n\n\n\t\t\t\tInvalid option. Please try again...\n");
            Sleep(2000);
            system("cls");
            adminAcc();
            }
        } else {
            system("cls");
            printf("\x1B[31m\n\n\n\n\n\n\n\t\t\t\tInvalid selection. Please try again...\n");
            Sleep(2000);
            system("cls");
            adminAcc();
        }
    }
}





void adminPanel() {
    adminLogin();
    adminAcc();
    }

void createAccount() {
    if (numAccounts >= 100) {
        printf("Maximum number of accounts reached. Unable to create a new account.\n");
        return;
    }

    printf("\n\t\t\t\x1b[36mEnter your name: \x1b[31m");
    scanf("%s", accounts[numAccounts].name);
    printf("\t\t\t\x1b[36mEnter password: \x1b[31m");
    scanf("%s", accounts[numAccounts].password);
    printf("\t\t\t\x1b[36mEnter G-mail: \x1b[31m");
    scanf("%s", accounts[numAccounts].gmail);
    printf("\t\t\t\x1b[36mEnter phone number: \x1b[31m");
    scanf("%s", accounts[numAccounts].phone);
    printf("\t\t\t\x1b[36mEnter date of birth (\x1b[31mdd-mm-yyyy\x1b[36m): \x1b[31m");
    scanf("%s", accounts[numAccounts].dob);

    printf("\t\t\t\x1b[36mEnter your initial deposit: \x1b[31m");
    scanf("%f", &accounts[numAccounts].balance);
    strcpy(accounts[numAccounts].datetime, "N/A");

    printf("\n\x1b[36mAccount created for \x1b[31m%s \x1b[36mwith a balance of \x1b[31m%.2f\x1b[36m.\n", accounts[numAccounts].name, accounts[numAccounts].balance);
    numAccounts++;
    Sleep(2000);
    system("cls");
    saveAccountsToFile();
}

void signIn() {
    int signIn_exit;
    char name[50], password[20];
    printf("\n\n\t\t\x1B[31mEnter User name: \x1B[36m");
    scanf("%s", name);
    printf("\t\t\x1B[31mEnter Password: \x1B[36m");
    scanf("%s", password);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0 && strcmp(accounts[i].password, password) == 0) {
            system("cls");

            accmenu(i);
            return;
        }
    }

    // If no matching account was found
    printf("\n\n\x1B[36mWrong \x1B[31mUser name \x1B[36mor \x1B[31mPassword\x1B[36m!\a\a\a\n\n");
    printf("Enter \x1B[31m1 \x1B[36mto try again and \x1B[31m0 \x1B[36mto exit: \x1B[36m");
    scanf("%d", &signIn_exit);

    if (signIn_exit == 1) {
        system("cls");
        signIn();
    } else if (signIn_exit == 0) {
        system("cls");
        menu();
    } else {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        printf("\n\n\n\n\n\n\n\t\t\t\t\x1B[31mInvalid choice! Please try again...");
        Sleep(2000);
        system("cls");
        signIn();
    }
}

void accmenu(int accountIndex) {
    int choice;
    float depositAmount, withdrawAmount;

    displayInfo(accountIndex);  // Display user information once

    printf("\x1B[36m");
    printf("\n\n\t\t\t   =====================================================\n");
    printf("\t\t\t   ||                                                 ||\n");
    printf("\t\t\t   ||          ");
    printf("\x1B[31m");
    printf("\t  Bank Management System");
    printf("\x1B[36m");
    printf("              ||\n");
    printf("\t\t\t   ||                                                 ||\n");
    printf("\t\t\t   =====================================================\n");
    printf("\t\t           ||         \t  ::Account Menu::                    ||\n");
    printf("\t\t           ||                                                 ||\n");
    printf("\t\t           ||    Select An Option:                            ||\n");
    printf("\t\t           ||                                                 ||\n");
    printf("\t\t           ||     \x1b[31m1\x1b[36m.... \x1b[36mDeposit                               ||\n");
    printf("\t\t           ||     \x1b[31m2\x1b[36m.... \x1b[36mWithdraw                              ||\n");
    printf("\t\t           ||     \x1b[31m3\x1b[36m.... \x1b[36mCheck Balance                         ||\n");
    printf("\t\t           ||     \x1b[31m4\x1b[36m.... \x1b[36mExit                                  ||\n");
    printf("\t\t           ||                                                 ||\n");
    printf("\t\t           =====================================================\n");
    printf("\n\x1B[36mEnter your choice \x1b[31m(1-4)\x1b[36m: \x1B[31m");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            system("cls");
            printf("\x1b[36mEnter the amount to deposit: \x1b[31m");
            scanf("%f", &depositAmount);
            accounts[accountIndex].balance += depositAmount;
            logTransaction(accountIndex, "Deposit", depositAmount);  // Log transaction
            printf("\x1b[36mDeposited \x1b[31m%.2f \x1b[36minto \x1b[31m%s\x1b[36m's account.\nNew balance: \x1b[31m%.2f.\n", depositAmount, accounts[accountIndex].name, accounts[accountIndex].balance);
            saveAccountsToFile();
            Sleep(2000);
            system("cls");
            accmenu(accountIndex);
            break;

        case 2:
            system("cls");
            printf("\x1b[36mEnter the amount to withdraw: \x1b[31m");
            scanf("%f", &withdrawAmount);
            if (accounts[accountIndex].balance >= withdrawAmount) {
                accounts[accountIndex].balance -= withdrawAmount;
                logTransaction(accountIndex, "\x1b[36mWithdraw \x1b[31m", withdrawAmount);  // Log transaction
                printf("\x1b[36mWithdrew \x1b[31m%.2f \x1b[36mfrom \x1b[31m%s\x1b[36m's account.\n\x1b[36mNew balance: \x1b[31m%.2f\x1b[36m.\n", withdrawAmount, accounts[accountIndex].name, accounts[accountIndex].balance);
                saveAccountsToFile();  // Save changes
            } else {
                system("cls");
                printf("\n\n\n\n\n\n\n");
                printf("\t\t\t\x1b[36mInsufficient funds in \x1b[31m%s\x1b[36m's account.\n", accounts[accountIndex].name);
            }
            Sleep(2000);
            system("cls");
            accmenu(accountIndex);
            break;

        case 3:
            system("cls");
            printf("\x1b[31m%s\x1b[36m's account balance: \x1b[31m%.2f\x1b[36m.\n", accounts[accountIndex].name, accounts[accountIndex].balance);
            Sleep(2000);
            system("cls");
            accmenu(accountIndex);
            break;

        case 4:
            system("cls");
            printf("\n\n\n\n\n\n\n");
            printf("\t\t\t\x1B[36mReturning to \x1B[31mMain menu");
            for (int i = 0; i <= 2; i++) {
                printf("\x1B[36m.");
                sleep(1);
            }
            system("cls");
            menu();
            break;

        default:
            system("cls");
            printf("\n\n\n\n\n\n\n");
            printf("\t\t\t\x1B[31mInvalid choice. Please try again.\n");
            sleep(2);
            system("cls");
            accmenu(accountIndex);
            break;
    }
}

void displayInfo(int accountIndex) {
    printf("\x1B[36mWelcome back, [\x1B[1;3;4;31m%s\x1b[0;31m!\x1b[36m]\n", accounts[accountIndex].name);
}


void menu() {
    int choice;
    printf("\x1B[36m");
    printf("\n\n\t\t\t   =====================================================\n");
    printf("\t\t\t   ||                                                 ||\n");
    printf("\t\t\t   ||          ");
    printf("\x1B[31m");
    printf("\t  Bank Management System");
    printf("\x1B[36m");
    printf("              ||\n");
    printf("\t\t\t   ||                                                 ||\n");
    printf("\t\t\t   =====================================================\n");
    printf("\t\t           ||         \t  ::Main Menu::                       ||\n");
    printf("\t\t           ||                                                 ||\n");
    printf("\t\t           ||    Select An Option:                            ||\n");
    printf("\t\t           ||                                                 ||\n");
    printf("\t\t           ||     \x1b[31m1\x1b[36m.... CREATE A BANK ACCOUNT                 ||\n");
    printf("\t\t           ||     \x1b[31m2\x1b[36m.... ALREADY A USER? SIGN IN               ||\n");
    printf("\t\t           ||     \x1b[31m3\x1b[36m.... ADMIN LOGIN                           ||\n");
    printf("\t\t           ||     \x1b[31m4\x1b[36m.... EXIT                                  ||\n");
    printf("\t\t           ||                                                 ||\n");
    printf("\t\t           =====================================================\n");
    printf("\x1B[36m");

    printf("\n\n\nSelect Your Option \x1b[31m(1-4)\x1b[36m: \x1b[31m");
    scanf("%d", &choice);
    printf("\x1B[0m");

    switch (choice) {
        case 1:
            system("cls");
            createAccount();
            menu();
            break;
        case 2:
            system("cls");
            signIn();
            break;
        case 3:
            system("cls");
            adminPanel();
            break;
        case 4:
            printf("\x1B[31m");
            system("cls");
            printf("\n\n\n\n\n\n\n");
            printf("\t\t\t\tExiting \x1b[36mBank Management System");
            for (int i = 0; i <= 2; i++) {
            printf("\x1b[31m.");
            sleep(1);
        }
            typingAnimation("\n\n\n\nThis C Mini Project is developed by \x1B[36m1597(Sakib) \x1B[31m& \x1B[36m1569(Abir)\x1B[31m!");
            printf("\n\x1B[0m\n");
            return 0;
        default:
            system("cls");
            printf("\x1B[31m");
            printf("\n\n\n\n\n\n\n\t\t\t\tInvalid Option. Please try again...\n");
            Sleep(2000);
            system("cls");
            menu();
    }
}

int main(void) {
    loadAccountsFromFile();
    char pass[10], password[] = "ckash";
    int main_exit;


    printf("\n\n\t\t\xB2\xB2\xB2Prove that you're the developer.\xB2\xB2\xB2");

    printf("\n\n\tEnter the password to login: ");
    scanf("%s", pass);

    if (strcmp(pass, password) == 0) {
        printf("\n\n\t\t\t\x1B[31mPassword Match!");
        printf("\x1B[36m\nLOADING");

        for (int i = 0; i <= 2; i++) {
            printf(".");
            sleep(1);
        }

        printf("\n");
        system("cls");
        menu();
    } else {
        printf("\n\nWrong password!!\a\a\a");


        printf("\n\nEnter 1 to try again and 0 to exit: ");
        scanf("%d", &main_exit);

        if (main_exit == 1) {
            system("cls");
            main();
        } else if (main_exit == 0) {
            system("cls");
            printf("\x1B[31m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
            typingAnimation("This C Mini Project is developed by \x1B[36m1597(Sakib) \x1B[31m& \x1B[36m1569(Abir)\x1B[31m!");
            printf("\x1B[0m\n");
            return 0;
        } else {
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\tInvalid choice. Please try again...\n");
            Sleep(2000);
            system("cls");
            main();
        }
    }
    return 0;
}
