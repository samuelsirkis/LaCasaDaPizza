#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define conta_adm "root"
#define senha_adm "root"

void head();
void login_adm();
void menu_login_inicial();
void login_usuario();
void dataHora();


struct cliente {
	char nome[100];
	char telefone[9];
	char endereco[200];
	int codigo_cliente;
}cliente[1000], cadastro_cliente[1000];

struct pedido {
	struct cliente cliente_pedido;
	struct bebidas cliente_bebida;
	struct sabor cliente_sabor;
	int codigo_pedido;
	float valor_pedido;

}pedido[1000],cadastro_pedido[1000];

struct bebidas {
	char bebida[20];
	int quantidade_bebida;
	int codigo_bebiba;
	float preco_bebida;

}bebidas[200], cadastro_bebida[200];

struct ingredientes {
	char ingrediente[50];
	int quantidade_ingredientes;
	int codigo_ingrediente;
	float preco_ingrediented;
};

struct sabor {
	char sabor[30];
	char ingredientes[50];
	int tamanho_sabor;
	int quantidade_sabor;
	int codigo_sabor;
	float preco_sabor;
}sabores[50];

struct cadastro {
	char user[20];
	char pass[20];
	int codigo;
}usuario[1000], admin[50], cadastro_user[1000], cad_admin[50];

int validar_login_usuario(int a, int c)
{
	int r;

	if (strcmp(cadastro_user[a].user, usuario[c].user) == 0)
	{
		r = 1; //usuario ja existe
	}
	else r = 0; //usuario nao existe
	return (r);
}

int validar_login_adm(int a, int c)
{
	int r;

	if (strcmp(cad_admin[a].user, admin[c].user) == 0)
	{
		r = 1; //usuario ja existe
	}
	else r = 0; //usuario nao existe
	return (r);
}

int validar_cliente(int a, int c)
{
	int r;

	if (strcmp(cadastro_cliente[a].telefone, cliente[c].telefone) == 0)
	{
		r = 1; //cliente ja existe
	}
	else r = 0; //cliente nao existe
	return (r);
}

int validar_bebida(int a, int c)
{
	int r;

	if (strcmp(cadastro_bebida[a].bebida, bebidas[c].bebida) == 0)
	{
		r = 1; //cliente ja existe
	}
	else r = 0; //cliente nao existe
	return (r);
}

void cadastro_users(int a)
{
	int b, c;
	system("cls");
usuario_existente:
	usuario[a].codigo = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", usuario[a].codigo);
	puts("\t=================================");
	puts("\n\n\tDigite o login: ");
	printf("\t");
	scanf(" %s", cadastro_user[a].user);
	for (c = 0; c < 1000; c++)
	{
		b = validar_login_usuario(a, c);
		if (b == 1) break;
	}
	if (b == 0)
	{
		memcpy(usuario[a].user, cadastro_user[a].user, 50);
		puts("\tDigite a senha: ");
		printf("\t");
		scanf(" %s", usuario[a].pass);
	}
	else if (b == 1)
	{
		system("cls");
		printf("\nLogin ja existente!\n");
		goto usuario_existente;
	}
}

void cadastro_clientes(int a)
{
	int b, c;
	system("cls");
cliente_existente:
	cliente[a].codigo_cliente = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", cliente[a].codigo_cliente);
	puts("\t=================================");
	puts("\n\n\tDigite o Telefone do Cliente: ");
	printf("\t");
	scanf(" %s", cadastro_cliente[a].telefone);
	for (c = 0; c < 1000; c++)
	{
		b = validar_cliente(a, c);
		if (b == 1) break;
	}
	if (b == 0)
	{
		memcpy(cliente[a].telefone, cadastro_cliente[a].telefone, 9);
		puts("\tInforme o nome do cliente: ");
		printf("\t");
		scanf(" %[^\n]s", cadastro_cliente[a].nome);
		printf("\n\tEndereço Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", cadastro_cliente[a].endereco);
	}

	else if (b == 1)
	{
		system("cls");
		printf("\nLogin ja existente!\n");
		goto cliente_existente;
	}
}

void cadastro_administrador(int a)
{
	int b, c;
	system("cls");
admin_existente:
	admin[a].codigo = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", admin[a].codigo);
	puts("\t=================================");
	puts("\n\n\tDigite o login: ");
	printf("\t");
	scanf(" %s", cad_admin[a].user);
	for (c = 0; c < 50; c++)
	{
		b = validar_login_adm(a, c);
		if (b == 1) break;
	}
	if (b == 0)
	{
		memcpy(admin[a].user, cad_admin[a].user, 50);
		puts("\tDigite a senha: ");
		printf("\t");
		scanf(" %s", admin[a].pass);
	}
	else if (b == 1)
	{
		system("cls");
		printf("\nLogin ja existente!\n");
		goto admin_existente;
	}
}

void cadastro_pedidos(int a) {
	int i, j;
	system("cls");
pedido_existente:
	pedido[a].codigo_pedido = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro de pedido n.º: %d\n", pedido[a].codigo_pedido);
	puts("\t=================================");
	puts("\n\n\tDigite o número de telefone do cliente: ");
	printf("\t");
	scanf(" %s", cadastro_pedido[a].cliente_pedido.telefone);
	for (j = 0; j < 1000; j++)
	{
		i = validar_cliente(a, j);
		if (i == 0) break;
	}
	if (i == 0)
	{
		memcpy(pedido[a].cliente_pedido.telefone, cadastro_pedido[a].cliente_pedido.telefone, 9);
		//tentar imprimir o cadastro do cliente na tela
		//solicitar informações do pedido
		//concluir pedido e informar valor total
		//criar menu com opções de pedido

		puts("\tInforme a quantidade de sabores: ");
		printf("\t");
		scanf(" %d", cadastro_pedido[a].cliente_sabor.sabor);
		printf("\n\tQuais sabores: ");
		printf("\t");
		scanf(" %d", cadastro_pedido[a].cliente_bebida.bebida);
	}

	else if (i == 1)
	{
		system("cls");
		printf("\nBebida ja existente!\n");
		goto pedido_existente;
	}
}

void cadastro_bebidas(int a) {
	int i, j;
	system("cls");
bebida_existente:
	bebidas[a].codigo_bebiba = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", bebidas[a].codigo_bebiba);
	puts("\t=================================");
	puts("\n\n\tDigite a bebida que deseja cadastrar: ");
	printf("\t");
	scanf(" %s", cadastro_bebida[a].bebida);
	for (j = 0; j < 1000; j++)
	{
		i = validar_bebida(a, j);
		if (i == 1) break;
	}
	if (i == 0)
	{
		memcpy(bebidas[a].bebida, cadastro_bebida[a].bebida, 20);
		puts("\tInforme a quantidade de bebidas: ");
		printf("\t");
		scanf(" %d", cadastro_bebida[a].quantidade_bebida);
		printf("\n\tQual o preço de venda da bebida: ");
		printf("\t");
		scanf(" %f", cadastro_bebida[a].preco_bebida);
	}

	else if (i == 1)
	{
		system("cls");
		printf("\nBebida ja existente!\n");
		goto bebida_existente;
	}
}

void cadastro_sabores() {

}

void cadastro_pizzaiolos() {

}

void logar_usuario()
{
	int c;
	int logado;
	char login[1][20], senha[1][20];
	char fechar_login[] = { "EXIT" }, fechar_senha[] = { "EXIT" };

erro_login:

	printf("\n\tPara fechar digite o usuario e a senha EXIT em maiusculo\n");
	printf("\n\tLogon\n");
	printf("\n\tLogin: ");
	scanf(" %s", login[0]);
	printf("\n\tSenha: ");
	scanf(" %s", senha[0]);

	if ((strcmp(login[0], conta_adm) == 0) && (strcmp(login[0], senha_adm) == 0)) logado = 2;
	else if ((strcmp(login[0], fechar_login) == 0) && (strcmp(senha[0], fechar_senha) == 0)) exit(0);
	else
	{
		for (c = 0; c < 1000; c++)
		{
			if ((strcmp(login[0], usuario[c].user) != 0) || (strcmp(senha[0], usuario[c].pass) != 0))
			{
				logado = 1; //login e/ou senha incorretos
			}
			else if ((strcmp(login[0], usuario[c].user) == 0) && (strcmp(senha[0], usuario[c].pass) == 0))
			{
				logado = 2; //logado com sucesso
				break;
			}

		}
	}
		if (logado == 1)
		{
			system("cls");
			printf("\nLogin e/ou senha incorreto(s)\n");
			printf("\nTente Novamente!\n");
			goto erro_login;
		}
		else if (logado == 2)
		{
			system("cls");
			printf("\nLogado com sucesso!\n\nBem-vindo(a) %s\n", login[0]);
			//printf("Codigo do usuario: %d\n\n", usuario[c].codigo);
			login_usuario();
		}
	
}

void login_usuario()
{
	int op_user;
	int a = 0, cliente_cad = 0, b, c, nc;

tela_inicial_user:
	system("cls");
	head();
	puts("\t=================================\t=================================\t");
	printf("\n\t1- Clientes\t\t\t\t5- Pizzaiolos\n");
	puts("\t=================================\t=================================\t");
	printf("\n\t2- Pedidos\t\t\t\t6- Promoções\n");
	puts("\t=================================\t=================================\t");
	printf("\n\t3- Sabores\t\t\t\t7- Estoque\n");
	puts("\t=================================\t=================================\t");
	printf("\n\t4- Bedidas\t\t\t\t8- Elogios/Reclamações\n");
	puts("\t=================================\t=================================\t");
	printf("\n\t0- Fechar\t\t\t\t9- Voltar a tela inicial de login\n");
	puts("\t=================================\t=================================\t");
	printf("\t");
	scanf("%d", &op_user);

	if (op_user == 1)
	{
		system("cls");
		head();
		puts("\t=================================");
		printf("\n\tQuantos cadastros deseja fazer? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (a == 0)
		{
			for (a = 0; a < nc; a++)
			{
				cadastro_clientes(a);
			}
			goto tela_inicial_user;
		}
		else if (a != 0)
		{
			b = a;
			c = a + nc - 1;
			printf("\n%d\n", a);
			for (a = b; a <= c; a++)
			{
				cadastro_clientes(a);
			}
			goto tela_inicial_user;
		}
	}
	else if(op_user ==2){
		system("cls");
		head();
		puts("\t=================================");
		printf("\n\tQuantos pedidos deseja fazer? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (a == 0)
		{
			for (a = 0; a < nc; a++)
			{
				cadastro_pedidos(a);
			}
			goto tela_inicial_user;
		}
		else if (a != 0)
		{
			b = a;
			c = a + nc - 1;
			printf("\n%d\n", a);
			for (a = b; a <= c; a++)
			{
				cadastro_pedidos(a);
			}
			goto tela_inicial_user;
		}
	}
	else if (op_user == 3) {}
	else if (op_user == 4) {}
	else if (op_user == 5) {}
	else if (op_user == 6) {}
	else if (op_user == 7) {}
	else if (op_user == 8) {}
	else if (op_user == 9) { system("cls"); menu_login_inicial(); }
	else if (op_user == 0) exit(0);
	else { system("cls"); printf("\n\tOpcao Invalida\n"); goto tela_inicial_user; }
}

void logar_adm()
{
	int c;
	int logado;
	char login[1][20], senha[1][20];
	char fechar_login[] = { "EXIT" }, fechar_senha[] = { "EXIT" };

erro_login:

	printf("\n\tPara fechar digite o usuario e a senha EXIT em maiusculo\n");
	printf("\n\tLogon\n");
	printf("\n\tLogin: ");
	scanf(" %s", login[0]);
	printf("\n\tSenha: ");
	scanf(" %s", senha[0]);

	if ((strcmp(login[0], conta_adm) == 0) && (strcmp(login[0], senha_adm) == 0)) logado = 2;
	else if ((strcmp(login[0], fechar_login) == 0) && (strcmp(senha[0], fechar_senha) == 0)) exit(0);
	else
	{
		for (c = 0; c < 1000; c++)
		{
			if ((strcmp(login[0], admin[c].user) != 0) || (strcmp(senha[0], admin[c].pass) != 0))
			{
				logado = 1; //login e/ou senha incorretos
			}
			else if ((strcmp(login[0], admin[c].user) == 0) && (strcmp(senha[0], admin[c].pass) == 0))
			{
				logado = 2; //logado com sucesso
				break;
			}

		}
	}

	if (logado == 1)
	{
		system("cls");
		head();
		printf("\nLogin e/ou senha incorreto(s)\n");
		printf("\nTente Novamente!\n");
		goto erro_login;
	}
	else if (logado == 2)
	{
		system("cls");
		printf("\n\tLogado com sucesso!\n\n\tBem-vindo(a) [ADM]%s\n", login[0]);
		// printf("Codigo do ADMIN: %d\n\n",admin[c].codigo);
		login_adm();
	}
}

void login_adm()
{
	int op_adm;
	int a = 0, adm_cad = 0, b, c, nc;

tela_inicial_adm:
	system("cls");
	head();
	puts("\t=================================");
	printf("\n\t1- Cadastro de usuarios\n");
	puts("\t=================================");
	printf("\n\t2- Cadastro de administradores\n");
	puts("\t=================================");
	printf("\n\t9- Voltar a tela de login\n");
	puts("\t=================================");
	printf("\n\t0- Fechar\n");
	puts("\t=================================");
	printf("\t");
	scanf("%d", &op_adm);
	system("cls");
	if (op_adm == 1)
	{
		head();
		puts("\t=================================");
		printf("\n\tQuantos cadastros deseja fazer? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (a == 0)
		{
			for (a = 0; a < nc; a++)
			{
				cadastro_users(a);
			}
			goto tela_inicial_adm;
		}
		else if (a != 0)
		{
			b = a;
			c = a + nc - 1;
			printf("\n%d\n", a);
			for (a = b; a <= c; a++)
			{
				cadastro_users(a);
			}
			goto tela_inicial_adm;
		}
	}
	else if (op_adm == 2)
	{
		head();
		puts("\t=================================");
		printf("\n\tQuantos cadastros deseja fazer? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (adm_cad == 0)
		{
			for (adm_cad = 0; adm_cad < nc; adm_cad++)
			{
				cadastro_administrador(adm_cad);
			}
			goto tela_inicial_adm;
		}
		else if (adm_cad != 0)
		{
			b = adm_cad;
			c = adm_cad + nc - 1;
			printf("\n%d\n", a);
			for (adm_cad = b; adm_cad <= c; adm_cad++)
			{
				cadastro_administrador(adm_cad);
			}
			goto tela_inicial_adm;
		}
	}
	else if (op_adm == 0) exit(0);
	else if (op_adm == 9) menu_login_inicial();
}

void menu_login_inicial()
{
	int op_login;

menu_de_login:
	head();
	puts("=================================");
	printf("1- Login de ADMINISTRADOR\n");
	puts("=================================");
	printf("2- Login de USUARIO\n");
	puts("=================================");
	printf("0- FECHAR\n");
	puts("=================================");
	scanf(" %d", &op_login);
	if (op_login == 1) logar_adm();
	else if (op_login == 2) logar_usuario();
	else if (op_login == 0) exit(0);
	else
	{
		system("cls");
		printf("Opcao invalida!\n");
		goto menu_de_login;
	}
}

void menu_cadastro_pedido() {
	int op_pedido;

menu_cadastro_pedido:
	head();
	puts("=================================");
	printf("1- Login de ADMINISTRADOR\n");
	puts("=================================");
	printf("2- Login de USUARIO\n");
	puts("=================================");
	printf("0- FECHAR\n");
	puts("=================================");
	scanf(" %d", &op_pedido);
	if (op_pedido == 1) logar_adm();
	else if (op_pedido == 2) logar_usuario();
	else if (op_pedido == 0) exit(0);
	else
	{
		system("cls");
		printf("Opcao invalida!\n");
		goto menu_cadastro_pedido;
	}
}

int main(void)
{
	setlocale(LC_ALL, "");
	menu_login_inicial();
	return 0;
}

void head() {
	dataHora();
	printf("\t.____             _________                             .___        __________.__                        \n");
	printf("\t|    |   _____    \\_   ___ \\_____    ___________      __| _/____    \\______   \\__|____________________   \n");
	printf("\t|    |   \\__  \\   /    \\  \\/\\__  \\  /  ___/\\__  \\    / __ |\\__  \\    |     ___/  \\___   /\\___   /\\__  \\  \n");
	printf("\t|    |___ / __ \\_ \\     \\____/ __ \\_\\___ \\  / __ \\_ / /_/ | / __ \\_  |    |   |  |/    /  /    /  / __ \\_\n");
	printf("\t|_______ (____  /  \\______  (____  /____  >(____  / \\____ |(____  /  |____|   |__/_____ \\/_____ \\(____  /\n");
	printf("\t        \\/    \\/          \\/     \\/     \\/      \\/       \\/     \\/                     \\/      \\/     \\/ \n\n\n");
}

void dataHora() {
	struct tm* data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);
	printf("\nData: %d/", data_hora_atual->tm_mday);
	printf("%d/", data_hora_atual->tm_mon + 1); //mês
	printf("%d  | ", data_hora_atual->tm_year + 1900);
	printf("Hora: %d:", data_hora_atual->tm_hour);
	printf("%d:", data_hora_atual->tm_min);
	printf("%d\n", data_hora_atual->tm_sec);

}

//void gotoxy(int coluna, int linha) {
//	COORD point;
//	point.X = coluna;
//	point.Y = linha;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
//}


//struct user {
//	char nome[100];
//	int pass[6];
//	int idUser;
//	int cpf[11];
//	int dataNasci[10];
//	int tel[9];
//}user[100];
//
//struct pedido {
//	char namePed[100];
//	char CPF[11];
//	char numPed[6];
//	char qtdPed[200];
//	float valorPed;
//	int cod;
//}pedido[200];
//
//struct client {
//	char CPF[11];
//	char telefone[9];
//	char nome[100];
//	char endereco[200];
//	char data[10];
//	int vazio, cod;
//	struct pedido clientePed;
//}cliente[200];
//
//
//
//int main() {
//	
//	//int i = 0, op = 0, opcaoCliente = 0, posicao = 0, retorno = 0, codaux = 0;
//	system("color");
//	system("cls");
//	strcpy(user[0].nome, "admin");
//	strcpy(user[0].pass, "12345");
//	//do {
//	dataHora();
//	head();
//
//	char c;
//	char login[20];
//	char senha[20];
//	int a = 10;
//	int i = 0;
//	int verifica_senha = 0;
//	while (verifica_senha == 0) {
//		printf("\nDIGITE USUÁRIO: ");
//		fflush(stdin);  //Limpando o buffer do teclado
//		gets(user[0].nome);
//		printf("\nSENHA: ");
//		while ((c = getch()) != 13) { //13 é o valor de ENTER na tabela ASCII
//			user[0].pass[i] = c;
//			i++;
//			printf("*");      //imprime o * Anterisco
//		}
//		user[0].pass[i] = '\0';
//		i = 0;
//		system("cls");
//		a = strcmp(senha, "nunes"); //
//		if (a == 0) { printf("SENHA CORRETA"); system("color 0a"); verifica_senha = 1; Beep(1500, 2000); }
//		else { printf("%s SENHA ERRADA\n", senha); system("color 0c"); Beep(1200, 200); }
//		printf("\n");
//
//	}
//	scanf
//		//menu();
//		/*printf("\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>...");
//		scanf_s("%d", &op);
//		if (op == 1)
//		{
//			printf("\t\t VOCÊ SELECIONOU A OPÇÃO 1 - CADASTRAR USUÁRIO\n");
//			posicao = verifica_pos();
//
//			if (posicao != -1)
//			{
//
//				printf("\nentre com um codigo de 1 a 200 para seu cadastro: \n");
//				scanf("%d", &codaux); fflush(stdin);
//
//				retorno = verifica_cod(codaux);
//
//				if (retorno == 1)
//					cadastrop(codaux, posicao);
//				else {
//					printf("\ncodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
//					getchar();
//					system("cls");
//					main();
//				}
//
//			}
//			else
//				printf("\nnao e possivel realizar mais cadastros!\n");
//
//			break;
//
//		}
//		else if (opcao == 2)
//		{
//			system("cls");
//			do {
//				printf("voce selecionou a opcao 2 - clientes\n\n");
//				printf("1 - pesquisar cliente por codigo\n");
//				printf("2 - listar todos os clientes\n");
//				printf("3 - voltar ao menu principal\n");
//				printf("selecione uma opcao por favor: ");
//				scanf("%d", &opcaocliente);
//				getchar();
//				if (opcaocliente == 1) {
//					consultacod();
//				}
//				else if (opcaocliente == 2) {
//					list();
//				}
//				else if (opcaocliente == 3) {
//					printf("voce selecionou voltar ao menu principal, pressione enter para continuar");
//					getchar();
//					system("cls");
//				}
//				else
//					printf("opcao invalida\n\n");
//
//
//			} while (opcaocliente = !3 || opcaocliente > 3 || opcaocliente < 0 || opcaocliente == 0);
//		}
//		else if (opcao == 3)
//		{
//			printf("voce selecionou a opcao 3 - alterar cliente\n");
//		}
//		else if (opcao == 4)
//		{
//			printf("voce selecionou a opcao 4 - excluir cliente\n");
//			excluircliente();
//		}
//		else if (opcao == 5)
//		{
//			printf("voce selecionou a opcao 5 - cadastrar pedido\n");
//			cadastropedido();
//		}
//		else if (opcao == 6)
//		{
//			printf("voce selecionou a opcao 6 - alterar pedido\n");
//		}
//		else if (opcao == 7)
//		{
//			printf("voce selecionou a opcao 7 - excluir pedido\n");
//		}
//		else if (opcao == 8)
//		{
//			printf("voce selecionou a opcao 8 - sair\n");
//		}
//		else {
//			printf("opcao invalida, favor pressione enter para voltar ao menu principal");
//			getchar();
//			system("cls");
//		}
//	} while (opcao != 8 || opcao < 8);
//	*/
//
//	//system("pause");
//		return 0;
//} //FIM DO MAIN
//
//
//}
//int verifica_cod(int cod) // VERIFICADOR DE CÓDIGO
//{
//	int cont = 0;
//
//	while (cont <= 200)
//	{
//		if (client[cont].cod == cod)
//			return(0);
//
//		cont++;
//	}
//
//	return(1);
//
//} // FIM DO VERIFICADOR
//int verifica_pos(void) //VERIFICADOR DA POSIÇÃO
//{
//	int cont = 0;
//
//	while (cont <= 200)
//	{
//
//		if (client[cont].vazio == 0)
//			return(cont);
//
//		cont++;
//
//	}
//
//	return(-1);
//
//} // FIM DO VERIFICADOR
//
//void dataHora() {
//	struct tm* data_hora_atual;
//	time_t segundos;
//	time(&segundos);
//	data_hora_atual = localtime(&segundos);
//	printf("\nData: %d/", data_hora_atual->tm_mday);
//	printf("%d/", data_hora_atual->tm_mon + 1); //mês
//	printf("%d  | ", data_hora_atual->tm_year + 1900);
//	printf("Hora: %d:", data_hora_atual->tm_hour);
//	printf("%d:", data_hora_atual->tm_min);
//	printf("%d\n", data_hora_atual->tm_sec);
//
//}
//char sabor(char sabor[10]) {
//	sabor[1] = "Calabresa";
//	sabor[2] = "";
//	sabor[3] = "";
//	sabor[4] = "";
//	sabor[5] = "";
//	sabor[6] = "";
//	sabor[7] = "";
//	sabor[8] = "";
//	sabor[9] = "";
//	sabor[10] = "";
//}
//void cadastroPedido() { //Cadastro dos pedidos
//	system("cls");
//	int i, option, opcaoPedido;
//	char nomeCad[100];
//	printf("\nDigite seu nome como esta no cadastro: ");
//	gets(nomeCad);
//	for (i = 0; i < 100; i++) {
//		if (strcmp(cliente[i].nome, nomeCad) == 0) {
//			do {
//				printf("\nEscolha o seu pedido: "); 
//				printf("\n1- Sanduba esperto");
//				printf("\n2- Ceasar Salad");
//				printf("\n3- Raviolli\n:");
//				scanf("%d", &OpcaoPedido);
//				if (opcaoPedido == 1) {
//					strcpy(log[i].clientePed.namePed, "Sanduba esperto");
//					printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
//					printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
//					scanf("%d", &option);
//					i++;
//				}
//				else if (opcaoPedido == 2) {
//					strcpy(log[i].clientePed.namePed, "Ceasar Salad");
//					printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
//					printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
//					scanf("%d", &Option);
//					i++;
//				}
//				else if (opcaoPedido == 3) {
//					strcpy(cliente[i].clientePed.namePed, "Raviolli");
//					printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", cliente[i].clientePed.namePed);
//					printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
//					scanf("%d", &Option);
//					i++;
//				}
//			} while (Option == 1);
//			system("cls");
//
//
//		}
//	}
//} // FIM DO CADASTRO DE PEDIDOS.
//
//
//
//void head(); void menu(); void dataHora();
//
//
//
//struct user {
//	char nome[100];
//	int pass[6];
//	int idUser;
//	int cpf[11];
//	int dataNasci[10];
//	int tel[9];
//}user[100];
//
//struct pedido {
//	char namePed[100];
//	char CPF[11];
//	char numPed[6];
//	char qtdPed[200];
//	float valorPed;
//	int cod;
//}pedido[200];
//
//struct client {
//	char CPF[11];
//	char telefone[9];
//	char nome[100];
//	char endereco[200];
//	char data[10];
//	int vazio, cod;
//	struct pedido clientePed;
//}cliente[200];
//
//
//
//int main() {
//	setlocale(LC_ALL, "");
//	//int i = 0, op = 0, opcaoCliente = 0, posicao = 0, retorno = 0, codaux = 0;
//	system("color");
//	system("cls");
//	strcpy(user[0].nome, "admin");
//	strcpy(user[0].pass, "12345");
//	//do {
//	dataHora();
//	head();
//	
//	char c;
//	char login[20];
//	char senha[20];
//	int a = 10;
//	int i = 0;
//	int verifica_senha = 0;
//	while (verifica_senha == 0) {
//		printf("\nDIGITE USUÁRIO: ");
//		fflush(stdin);  //Limpando o buffer do teclado
//		gets(user[0].nome);
//		printf("\nSENHA: ");
//		while ((c = getch()) != 13) { //13 é o valor de ENTER na tabela ASCII
//			user[0].pass[i] = c;
//			i++;
//			printf("*");      //imprime o * Anterisco
//		}
//		user[0].pass[i] = '\0';
//		i = 0;
//		system("cls");
//		a = strcmp(senha, "nunes"); //
//		if (a == 0) { printf("SENHA CORRETA"); system("color 0a"); verifica_senha = 1; Beep(1500, 2000); }
//		else { printf("%s SENHA ERRADA\n", senha); system("color 0c"); Beep(1200, 200); }
//		printf("\n");
//
//	}
//	scanf
//	//menu();
//	/*printf("\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>...");
//	scanf_s("%d", &op);
//	if (op == 1)
//	{
//		printf("\t\t VOCÊ SELECIONOU A OPÇÃO 1 - CADASTRAR USUÁRIO\n");
//		posicao = verifica_pos();
//
//		if (posicao != -1)
//		{
//
//			printf("\nentre com um codigo de 1 a 200 para seu cadastro: \n");
//			scanf("%d", &codaux); fflush(stdin);
//
//			retorno = verifica_cod(codaux);
//
//			if (retorno == 1)
//				cadastrop(codaux, posicao);
//			else {
//				printf("\ncodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
//				getchar();
//				system("cls");
//				main();
//			}
//
//		}
//		else
//			printf("\nnao e possivel realizar mais cadastros!\n");
//
//		break;
//
//	}
//	else if (opcao == 2)
//	{
//		system("cls");
//		do {
//			printf("voce selecionou a opcao 2 - clientes\n\n");
//			printf("1 - pesquisar cliente por codigo\n");
//			printf("2 - listar todos os clientes\n");
//			printf("3 - voltar ao menu principal\n");
//			printf("selecione uma opcao por favor: ");
//			scanf("%d", &opcaocliente);
//			getchar();
//			if (opcaocliente == 1) {
//				consultacod();
//			}
//			else if (opcaocliente == 2) {
//				list();
//			}
//			else if (opcaocliente == 3) {
//				printf("voce selecionou voltar ao menu principal, pressione enter para continuar");
//				getchar();
//				system("cls");
//			}
//			else
//				printf("opcao invalida\n\n");
//
//
//		} while (opcaocliente = !3 || opcaocliente > 3 || opcaocliente < 0 || opcaocliente == 0);
//	}
//	else if (opcao == 3)
//	{
//		printf("voce selecionou a opcao 3 - alterar cliente\n");
//	}
//	else if (opcao == 4)
//	{
//		printf("voce selecionou a opcao 4 - excluir cliente\n");
//		excluircliente();
//	}
//	else if (opcao == 5)
//	{
//		printf("voce selecionou a opcao 5 - cadastrar pedido\n");
//		cadastropedido();
//	}
//	else if (opcao == 6)
//	{
//		printf("voce selecionou a opcao 6 - alterar pedido\n");
//	}
//	else if (opcao == 7)
//	{
//		printf("voce selecionou a opcao 7 - excluir pedido\n");
//	}
//	else if (opcao == 8)
//	{
//		printf("voce selecionou a opcao 8 - sair\n");
//	}
//	else {
//		printf("opcao invalida, favor pressione enter para voltar ao menu principal");
//		getchar();
//		system("cls");
//	}
//} while (opcao != 8 || opcao < 8);
//*/
//
////system("pause");
//return 0;
//} //FIM DO MAIN
//
//
//void menu() {
//	puts("\t\t\t\t\t==========================================================");
//	puts("\t\t\t\t\t||\t\t* SELECIONE A OPÇÃO DESEJADA *\t\t||");
//	puts("\t\t\t\t\t==========================================================");
//	puts("\t\t\t\t\t||\t\t | 1 - CADASTRO DE USUÁRIO |\t\t||");
//	puts("\t\t\t\t\t==========================================================");
//	puts("\t\t\t\t\t||\t\t | 2 - CADASTRO DE CLIENTE |\t\t||");
//	puts("\t\t\t\t\t==========================================================");
//	puts("\t\t\t\t\t||\t\t | 3 - CADASTRAR PEDIDO    |\t\t||");
//	puts("\t\t\t\t\t==========================================================");
//	puts("\t\t\t\t\t||\t\t | 4 - ALTERAR PEDIDO	   |\t\t||");
//	puts("\t\t\t\t\t==========================================================");
//	puts("\t\t\t\t\t||\t\t | 5 - EXCLUIR PEDIDO	   |\t\t||");
//	puts("\t\t\t\t\t==========================================================");
//	puts("\t\t\t\t\t||\t\t | 6 - SAIR		   |\t\t||");
//	puts("\t\t\t\t\t==========================================================");
//
//}
//int verifica_cod(int cod) // verificador de código
//{
//	int cont = 0;
//
//	while (cont <= 200)
//	{
//		if (client[cont].cod == cod)
//			return(0);
//
//		cont++;
//	}
//
//	return(1);
//
//} // fim do verificador
//int verifica_pos(void) //verificador da posição
//{
//	int cont = 0;
//
//	while (cont <= 200)
//	{
//
//		if (client[cont].vazio == 0)
//			return(cont);
//
//		cont++;
//
//	}
//
//	return(-1);
//
//} // fim do verificador
//
//char sabor(char sabor[10]) {
//	sabor[1] = "Calabresa";
//	sabor[2] = "";
//	sabor[3] = "";
//	sabor[4] = "";
//	sabor[5] = "";
//	sabor[6] = "";
//	sabor[7] = "";
//	sabor[8] = "";
//	sabor[9] = "";
//	sabor[10] = "";
//}
//void cadastroPedido() { //Cadastro dos pedidos
//	system("cls");
//	int i, option, opcaoPedido;
//	char nomeCad[100];
//	printf("\nDigite seu nome como esta no cadastro: ");
//	gets(nomeCad);
//	for (i = 0; i < 100; i++) {
//		if (strcmp(cliente[i].nome, nomeCad) == 0) {
//			do {
//				printf("\nEscolha o seu pedido: "); 
//				printf("\n1- Sanduba esperto");
//				printf("\n2- Ceasar Salad");
//				printf("\n3- Raviolli\n:");
//				scanf("%d", &OpcaoPedido);
//				if (opcaoPedido == 1) {
//					strcpy(log[i].clientePed.namePed, "Sanduba esperto");
//					printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
//					printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
//					scanf("%d", &option);
//					i++;
//				}
//				else if (opcaoPedido == 2) {
//					strcpy(log[i].clientePed.namePed, "Ceasar Salad");
//					printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
//					printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
//					scanf("%d", &Option);
//					i++;
//				}
//				else if (opcaoPedido == 3) {
//					strcpy(cliente[i].clientePed.namePed, "Raviolli");
//					printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", cliente[i].clientePed.namePed);
//					printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
//					scanf("%d", &Option);
//					i++;
//				}
//			} while (Option == 1);
//			system("cls");
//
//
//		}
//	}
//} // FIM DO CADASTRO DE PEDIDOS.