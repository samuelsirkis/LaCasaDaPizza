#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>



void head();

int main() {
	system("color 4b");
inicio:
	system("cls");

	head();









	system("pause");
	return 0;
}

void head() {
	printf("\t.____             _________                             .___        __________.__                        \n");
	printf("\t|    |   _____    \\_   ___ \\_____    ___________      __| _/____    \\______   \\__|____________________   \n");
	printf("\t|    |   \\__  \\   /    \\  \\/\\__  \\  /  ___/\\__  \\    / __ |\\__  \\    |     ___/  \\___   /\\___   /\\__  \\  \n");
	printf("\t|    |___ / __ \\_ \\     \\____/ __ \\_\\___ \\  / __ \\_ / /_/ | / __ \\_  |    |   |  |/    /  /    /  / __ \\_\n");
	printf("\t|_______ (____  /  \\______  (____  /____  >(____  / \\____ |(____  /  |____|   |__/_____ \\/_____ \\(____  /\n");
	printf("\t        \\/    \\/          \\/     \\/     \\/      \\/       \\/     \\/                     \\/      \\/     \\/ \n");
}

void menu() {
	puts("\n=====================================================================================================");
	puts("\n\t\t\t* SELECIONE A OPÇÃO DESEJADA *");
	puts("\n=====================================================================================================");
	puts("\n\t\t\t | 1 - CADASTRO DE USUÁRIO *");
	puts("\n=====================================================================================================");
	puts("\n\t\t\t | 2 - CADASTRO DE CLIENTE ");
}

void gotxy(int coluna, int linha) {
	COORD point;
	point.X = coluna;
	point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
