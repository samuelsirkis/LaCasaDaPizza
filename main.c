#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#define conta_adm "root"
#define senha_adm "root"

void head();
void login_adm();
void menu_login_inicial();
void login_usuario();
void dataHora();
void logar_cliente();
void menu_alterar_cadastro();


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
//ok
struct bebida {
	char bebida[20];
	int quantidade_bebida;
	int codigo_bebiba;
	float preco_bebida;

}bebidas[20], cadastro_bebida[20];

struct ingrediente {
	char ingrediente[50];
	int quantidade_ingredientes;
	int codigo_ingrediente;
}ingredientes[20];

struct pizza {
	struct ingrediente pizza_ingreditente;
	char sabor[30];
	int codigo_pizza;
	float preco_pizza;
}pizzas[50];

struct cadastro {
	char user[20];
	char pass[20];
	int codigo;
}usuario[1000], admin[50], cadastro_user[1000], cad_admin[50];
//ok
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
//ok
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
//ok
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
//ok
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
//ok
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
		printf("\n\tEndereço Cliente: ");
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
//ok
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
//ok
void cadastro_pedidos(int a) {
	/*int i, j;
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
		memcpy(pedido[a].cliente_pedido.telefone, cadastro_pedido[a].cliente_pedido.telefone, 9);*/
		//tentar imprimir o cadastro do cliente na tela
		//criar menu com opções de pedido
		//solicitar informações do pedido
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

void cadastro_bebidas() {
	strcpy(bebidas[0].bebida, "Água\t"), bebidas[0].preco_bebida = 1.00, bebidas[0].quantidade_bebida = 100, bebidas[0].codigo_bebiba = 20;
	strcpy(bebidas[1].bebida, "Coca-Cola"), bebidas[1].preco_bebida = 5.00, bebidas[1].quantidade_bebida = 100, bebidas[1].codigo_bebiba = 21;
	strcpy(bebidas[2].bebida, "Fanta\t"), bebidas[2].preco_bebida = 4, 00, bebidas[2].quantidade_bebida = 100, bebidas[2].codigo_bebiba = 22;
	strcpy(bebidas[3].bebida, "Guarana"), bebidas[3].preco_bebida = 4.00, bebidas[3].quantidade_bebida = 100, bebidas[3].codigo_bebiba = 23;
	strcpy(bebidas[4].bebida, "Cerveja"), bebidas[4].preco_bebida = 3.00, bebidas[4].quantidade_bebida = 100, bebidas[4].codigo_bebiba = 24;
	strcpy(bebidas[5].bebida, "Suco\t"), bebidas[5].preco_bebida = 3.00, bebidas[5].quantidade_bebida = 100, bebidas[5].codigo_bebiba = 25;
	strcpy(bebidas[6].bebida, "Água com gás"), bebidas[6].preco_bebida = 2.00, bebidas[6].quantidade_bebida = 100, bebidas[6].codigo_bebiba = 26;
	puts("\t=================================");
	printf("\tControle de estoque Bebidas\n");
	puts("\t=================================");
	printf("\t|item\t|Código\t|Produto\t|Tipo\t|Qtde\t|Preço\t|\n");
	int i;

	for (i = 0; i < 7; i++) {
		printf("\t|(%d)\t|%d\t|%s\t|%s\t|%d\t|%.2f\t|\n", i + 1, bebidas[i].codigo_bebiba, bebidas[i].bebida, "Bebida", bebidas[i].quantidade_bebida, bebidas[i].preco_bebida);
	}
}
//ok
void cadastro_ingredientes() {
	strcpy(ingredientes[0].ingrediente, "peperone"), ingredientes[0].quantidade_ingredientes = 100, ingredientes[0].codigo_ingrediente = 30;
	strcpy(ingredientes[1].ingrediente, "queijo"), ingredientes[1].quantidade_ingredientes = 100, ingredientes[1].codigo_ingrediente = 31;
	strcpy(ingredientes[2].ingrediente, "ovo"), ingredientes[2].quantidade_ingredientes = 100, ingredientes[2].codigo_ingrediente = 32;
	strcpy(ingredientes[3].ingrediente, "bacon"), ingredientes[3].quantidade_ingredientes = 100, ingredientes[3].codigo_ingrediente = 33;
	strcpy(ingredientes[4].ingrediente, "cogumelo"), ingredientes[4].quantidade_ingredientes = 100, ingredientes[4].codigo_ingrediente = 34;
	strcpy(ingredientes[5].ingrediente, "chocolate"), ingredientes[5].quantidade_ingredientes = 100, ingredientes[5].codigo_ingrediente = 35;
	strcpy(ingredientes[6].ingrediente, "banana"), ingredientes[6].quantidade_ingredientes = 100, ingredientes[6].codigo_ingrediente = 36;
}
//ok
void cadastro_pizzas() {

	strcpy(pizzas[0].sabor, "mussarela"), pizzas[0].preco_pizza = 10, 00;
	strcpy(pizzas[1].sabor, "calabresa"), pizzas[1].preco_pizza = 10, 00;
	strcpy(pizzas[2].sabor, "portuguesa"), pizzas[2].preco_pizza = 10, 00;
	strcpy(pizzas[3].sabor, "quatro queijos"), pizzas[3].preco_pizza = 10, 00;
	strcpy(pizzas[4].sabor, "peperone"), pizzas[4].preco_pizza = 10, 00;
	strcpy(pizzas[5].sabor, "marguerita"), pizzas[5].preco_pizza = 10, 00;
	strcpy(pizzas[6].sabor, "peperone"), pizzas[6].preco_pizza = 10, 00;
	strcpy(pizzas[7].sabor, "bacon"), pizzas[7].preco_pizza = 10, 00;
	strcpy(pizzas[8].sabor, "cogumelo"), pizzas[8].preco_pizza = 10, 00;
	strcpy(pizzas[9].sabor, "banana"), pizzas[9].preco_pizza = 10, 00;
	strcpy(pizzas[10].sabor, "chocolate"), pizzas[10].preco_pizza = 10, 00;

	strcpy(pizzas[0].codigo_pizza, 1);
	strcpy(pizzas[1].codigo_pizza, 2);
	strcpy(pizzas[2].codigo_pizza, 3);
	strcpy(pizzas[3].codigo_pizza, 4);
	strcpy(pizzas[4].codigo_pizza, 5);
	strcpy(pizzas[5].codigo_pizza, 6);
	strcpy(pizzas[6].codigo_pizza, 7);
	strcpy(pizzas[7].codigo_pizza, 8);
	strcpy(pizzas[8].codigo_pizza, 9);
	strcpy(pizzas[9].codigo_pizza, 10);
	strcpy(pizzas[10].codigo_pizza, 11);
}
//ok

void cadastro_sugestao(int a) {
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
	scanf("%s", cad_clientes[a].telefone);
	for (j = 0; j < 1000; j++)
	{
		i = validar_cliente(a, j);
		if (i == 1) break;
	}
	if (i == 1)
	{
		memcpy(clientes[a].telefone, cad_clientes[a].telefone, 9);
		printf("\n\tCliente cadastrado!\n\tDigite o seu elogio/reclamação/sugestão: \n");
		printf("\n\t_");
		scanf(" %[^\n]s", clientes[a].sugestao);
		printf("Sugestão salva com sucesso!!");
		Sleep(5000);

	}
	else if (i == 0)
	{
		system("cls");
		printf("\nCliente não cadastrado!\n");
		Sleep(5000);
		logar_cliente();
	}
}
//ok
void cadastro_mesas(int a) {
	int i;
	system("cls");
	head();
	printf("");
}

void alterar_cadastro() {
	
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
//ok
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
	printf("\n\t3- Promoções\n");
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
				//cadastro_comandas(i);
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
				//cadastro_comandas(i);
			}
			goto tela_inicial_user;
		}
	}
	else if (op_user == 2) {
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
	printf("\n\t2- Elogios/Relcamações\n");
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
		printf("\n\tQuantas elogios/reclamações deseja fazer? \n");
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
//ok
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
//ok
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
	printf("\n\t2- Cadastro de administradores\t\t6- Promoções\n");
	puts("\t=================================\t=================================");
	printf("\n\t3- Cadastro de pizzaiolos\t\t7- Relatórios\n");
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
		cadastro_bebidas();
		
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
	else if (op_adm == 5) {
		head();
		//menu_alterar_cadastros();
		Sleep(5000);
		goto tela_inicial_adm;

	}
	else if (op_adm == 6) {
		head();
		Sleep(5000);
		goto tela_inicial_adm;
	}
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
//ok
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

//void menu_alterar_cadastros() {
//	puts("\t=================================\t=================================");
//	printf("\n\t1- Alterar cadastro de usuarios\n");
//	puts("\t=================================\t=================================");
//	printf("\n\t2- Alterar cadastro de administradores\n");
//	puts("\t=================================\t=================================");
//	printf("\n\t3- Cadastro de pizzaiolos\n");
//	puts("\t=================================\t=================================");
//	printf("\n\t9- Voltar a tela de login\n");
//	puts("\t=================================\t=================================");
//}

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