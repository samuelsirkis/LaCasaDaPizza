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
void logar_cliente();


struct cliente {
	char nome[100];
	char telefone[9];
	char endereco[200];
	char bairro[50];
	char cidade[50];
	char cep[9];
	char sugestao[200];
	char senha[10];
	int codigo_cliente;
}clientes[1000], cad_clientes[1000];

struct bebida {
	char bebida[20];
	int quantidade_bebida;
	int codigo_bebiba;
	float preco_bebida;

}bebidas[200], cadastro_bebida[200];

struct ingrediente {
	char ingrediente[50];
	int quantidade_ingredientes;
	int codigo_ingrediente;
	float preco_ingrediented;
};

struct pizza {
	char sabor[30];
	char ingredientes[50];
	int tamanho_sabor;
	int quantidade_sabor;
	int codigo_sabor;
	float preco_sabor;
}pizzas[50];

struct cadastro {
	char user[20];
	char pass[20];
	int codigo;
}usuario[1000], admin[50], cadastro_user[1000], cad_admin[50]; 

struct pedido {
	struct cliente cliente_pedido;
	struct bebida cliente_bebida;
	struct pizza cliente_pizza;
	int codigo_pedido;
	float valor_pedido;

}pedido[1000], cadastro_pedido[1000];

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

	if (strcmp(cad_clientes[a].telefone, clientes[c].telefone) == 0)
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
	clientes[a].codigo_cliente = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", clientes[a].codigo_cliente);
	puts("\t=================================");
	puts("\n\n\tDigite o Telefone do Cliente: ");
	printf("\t");
	scanf(" %s", cad_clientes[a].telefone);
	for (c = 0; c < 1000; c++)
	{
		b = validar_cliente(a, c);
		if (b == 1) break;
	}
	if (b == 0)
	{
		memcpy(clientes[a].telefone, cad_clientes[a].telefone, 9);
		puts("\tInforme o nome do cliente: ");
		printf("\t");
		scanf(" %[^\n]s", cad_clientes[a].nome);
		printf("\n\tEndere�o Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", cad_clientes[a].endereco);
		printf("\n\tBairro do Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", cad_clientes[a].bairro);
		printf("\n\tCidade do Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", cad_clientes[a].cidade);
		printf("\n\tCEP do Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", cad_clientes[a].cep);
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
	/*int i, j;
	system("cls");
pedido_existente:
	pedido[a].codigo_pedido = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro de pedido n.�: %d\n", pedido[a].codigo_pedido);
	puts("\t=================================");
	puts("\n\n\tDigite o n�mero de telefone do cliente: ");
	printf("\t");
	scanf(" %s", cadastro_pedido[a].cliente_pedido.telefone);
	for (j = 0; j < 1000; j++)
	{
		i = validar_cliente(a, j);
		if (i == 0) break;
	}
	if (i == 0)
	{
		memcpy(pedido[a].cliente_pedido.telefone, cadastro_pedido[a].cliente_pedido.telefone, 9);*/
		//tentar imprimir o cadastro do cliente na tela
		//criar menu com op��es de pedido
		//solicitar informa��es do pedido
		//concluir pedido e informar valor total
		

	/*	puts("\tInforme a quantidade de sabores: ");
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
	}*/
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
		printf("\n\tQual o pre�o de venda da bebida: ");
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

void cadastro_pizzas() {

}

void cadastro_sugestao(int a){
	int i, j;
	system("cls");
sugestao_existe:
	clientes[a].codigo_cliente = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", clientes[a].codigo_cliente);
	puts("\t=================================");
	puts("\n\n\tDigite seu telefone: ");
	printf("\t");
	scanf(" %s", cad_clientes[a].telefone);
	for (j = 0; j < 1000; j++)
	{
		i = validar_cliente(a, j);
		if (i == 1) break;
	}
	if (i == 1)
	{
		memcpy(clientes[a].telefone, cad_clientes[a].telefone, 9);
		printf("\n\tCliente cadastrado!\n\tDigite o seu elogio/reclama��o/sugest�o: \n");
		printf("\n\t_");
		scanf(" %[^\n]s", clientes[a].sugestao);
		printf("Sugest�o salva com sucesso!!");
		getchar();
		
	}
	else if (i == 0)
	{
		system("cls");
		printf("\nCliente n�o cadastrado!\n");
		logar_cliente();
	}
}

void cadastro_comandas(){

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
	int i = 0, user_cad = 0, x, y, nc;

tela_inicial_user:
	system("cls");
	head();
	puts("\t=================================");
	printf("\n\t1- Mesas\n");
	puts("\t=================================");
	printf("\n\t2- Pedidos\n");
	puts("\t=================================");
	printf("\n\t3- Promo��es\n");
	puts("\t=================================");
	printf("\n\t9- Voltar a tela inicial de login\n");
	puts("\t=================================");
	printf("\t");
	scanf("%d", &op_user);

	if (op_user == 1)
	{
		system("cls");
		head();
		puts("\t=================================");
		printf("\n\tQuantos comandas deseja fechar? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (i == 0)
		{
			for (i = 0; i < nc; i++)
			{
				cadastro_comandas(i);
			}
			goto tela_inicial_user;
		}
		else if (i != 0)
		{
			x = i;
			y = i + nc - 1;
			printf("\n%d\n", i);
			for (i = x; i <= y; i++)
			{
				cadastro_comandas(i);
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
		if (i == 0)
		{
			for (i = 0; i < nc; i++)
			{
				cadastro_pedidos(i);
			}
			goto tela_inicial_user;
		}
		else if (i != 0)
		{
			x = i;
			y = i + nc - 1;
			printf("\n%d\n", i);
			for (i = x; i <= y; i++)
			{
				cadastro_pedidos(i);
			}
			goto tela_inicial_user;
		}
	}
	else if (op_user == 3) {}
	else if (op_user == 4) {}
	else if (op_user == 9) { system("cls"); menu_login_inicial(); }
	else if (op_user == 0) exit(0);
	else { system("cls"); printf("\n\tOpcao Invalida\n"); goto tela_inicial_user; }
}

void logar_cliente()
{
	int op_cliente;
	int i = 0, cliente_cad = 0, x, y, nc;

tela_inicial_cliente:
	system("cls");
	head();
	puts("\t=================================");
	printf("\n\t1- Cadastrar\n");
	puts("\t=================================");
	printf("\n\t2- Elogios/Relcama��es\n");
	puts("\t=================================");
	printf("\n\t9- Voltar a tela inicial de login\n");
	puts("\t=================================");
	printf("\n\t0- Fechar\n");
	puts("\t=================================");
	printf("\t");
	scanf("%d", &op_cliente);

	if (op_cliente == 1)
	{
		system("cls");
		head();
		puts("\t=================================");
		printf("\n\tQuantos cadastros deseja fazer? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (i == 0)
		{
			for (i = 0; i < nc; i++)
			{
				cadastro_clientes(i);
			}
			goto tela_inicial_cliente;
		}
		else if (i != 0)
		{
			x = i;
			y = i + nc - 1;
			printf("\n%d\n", i);
			for (i = x; i <= y; i++)
			{
				cadastro_clientes(i);
			}
			goto tela_inicial_cliente;
		}
	}
	else if (op_cliente == 2) {
		system("cls");
		head();
		puts("\t=================================");
		printf("\n\tQuantas elogios/reclama��es deseja fazer? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (i == 0)
		{
			for (i = 0; i < nc; i++)
			{
				cadastro_sugestao(i);
			}
			goto tela_inicial_cliente;
		}
		else if (i != 0)
		{
			x = i;
			y = i + nc - 1;
			printf("\n%d\n", i);
			for (i = x; i <= y; i++)
			{
				cadastro_sugestao(i);
			}
			goto tela_inicial_cliente;
		}
	}

	else if (op_cliente == 9) { system("cls"); menu_login_inicial(); }
	else if (op_cliente == 0) exit(0);
	else { system("cls"); printf("\n\tOpcao Invalida\n"); goto tela_inicial_cliente; }
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
	puts("\t=================================\t=================================");
	printf("\n\t1- Cadastro de usuarios\t\t\t5- Alterar Cadastros\n");
	puts("\t=================================\t=================================");
	printf("\n\t2- Cadastro de administradores\t\t6- Promo��es\n");
	puts("\t=================================\t=================================");
	printf("\n\t3- Cadastro de pizzaiolos\t\t7- Relat�rios\n");
	puts("\t=================================\t=================================");
	printf("\n\t4- Controle de estoque\t\t\t9- Voltar a tela de login\n");
	puts("\t=================================\t=================================");
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
	else if (op_adm == 3)
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
	else if (op_adm == 4) {
		head();
		puts("\t=================================");
		printf("\n\tControle de estoque \n");
		puts("\t=================================");
		printf("\n\t1- ");
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
	else if (op_adm == 5) {}
	else if (op_adm == 6) {}
	else if (op_adm == 7) {}
	else if (op_adm == 8) {}
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
	printf("3- Login de CLIENTE\n");
	puts("=================================");
	printf("0- FECHAR\n");
	puts("=================================");
	scanf(" %d", &op_login);
	if (op_login == 1) logar_adm();
	else if (op_login == 2) logar_usuario();
	else if (op_login == 3) logar_cliente();
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
	printf("%d/", data_hora_atual->tm_mon + 1); //m�s
	printf("%d  | ", data_hora_atual->tm_year + 1900);
	printf("Hora: %d:", data_hora_atual->tm_hour);
	printf("%d:", data_hora_atual->tm_min);
	printf("%d\n", data_hora_atual->tm_sec);

}