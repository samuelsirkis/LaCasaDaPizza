#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#define conta_adm "root"
#define senha_adm "root"

void head(); void login_adm(); void menu_login_inicial(); void menu_estoque(); void menu_mesa(a);
void menu_pedido(a); void login_usuario(); void dataHora(); void logar_cliente();
void gotoxy(coluna, linha); void logar_adm(); void alterar_cadastro(a);
void cadastro_pizzas(); void cadastro_bebidas(); void estoque_bebida();
void estoque_ingrediente(); void login_usuario();

struct cliente {
	char nome[100];
	char telefone[10];
	char endereco[200];
	char bairro[50];
	char cidade[50];
	char cep[10];
	char sugestao[200];
	char senha[10];
	int codigo_cliente;
}clientes[1000], cad_clientes[1000];
//ok
struct bebida {
	char bebida[20];
	int quantidade_bebida;
	int codigo_bebiba;
	double preco_bebida;
}bebidas[19], cadastro_bebida[19];
//ok
struct ingrediente {
	char ingrediente[50];
	int quantidade_ingredientes;
	int codigo_ingrediente;
}ingredientes[20];

struct pizza {
	struct ingrediente pizza_ingreditente;
	int qdt_ing;
	char sabor[30];
	int codigo_pizza;
	double preco_pizza;
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
	double valor_pedido;
}pedido[1000], cadastro_pedido[1000];

struct mesa {
	int numero;
	struct pizza mesa_pizza;
	struct bebida mesa_bebida;
	int codigo_mesa;
	double valor_mesa;
}mesas[30], cad_mesa[30];

int validar_login_usuario(int a, int c) {
	int r;
	if (strcmp(cadastro_user[a].user, usuario[c].user) == 0) {
		r = 1; //usuario ja existe
	}
	else r = 0; //usuario nao existe
	return (r);
}
//ok
int validar_login_adm(int a, int c) {
	int r;
	if (strcmp(cad_admin[a].user, usuario[c].user) == 0) {
		r = 1; //usuario ja existe
	}
	else r = 0; //usuario nao existe
	return (r);
}
//ok
int validar_cliente(int a, int c) {
	int r;
	if (strcmp(cad_clientes[a].telefone, clientes[c].telefone) == 0) {
		r = 1; //cliente ja existe
	}
	else r = 0; //cliente nao existe
	return (r);
}
//ok
void cadastro_users(int a) {
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
	for (c = 0; c < 1000; c++) {
		b = validar_login_usuario(a, c);
		if (b == 1) break;
	}
	if (b == 0) {
		memcpy(usuario[a].user, cadastro_user[a].user, 50);
		puts("\tDigite a senha: ");
		printf("\t");
		scanf(" %s", usuario[a].pass);
	}
	else if (b == 1) { system("cls"); printf("\nLogin ja existente!\n"); goto usuario_existente; }
}
//ok
void cadastro_clientes(int a) {
	int b, c;

cliente_existente:
	clientes[a].codigo_cliente = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", clientes[a].codigo_cliente);
	puts("\t=================================");
	puts("\n\n\tDigite o Telefone do Cliente: ");
	printf("\t");
	scanf(" %s", cad_clientes[a].telefone);
	for (c = 0; c < 1000; c++) {
		b = validar_cliente(a, c);
		if (b == 1) break;
	}
	if (b == 0) {
		memcpy(clientes[a].telefone, cad_clientes[a].telefone, 9);
		puts("\tInforme o nome do cliente: ");
		printf("\t");
		scanf(" %[^\n]s", clientes[a].nome);
		printf("\n\tEndereço Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", clientes[a].endereco);
		printf("\n\tBairro do Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", clientes[a].bairro);
		printf("\n\tCidade do Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", clientes[a].cidade);
		printf("\n\tCEP do Cliente: ");
		printf("\t");
		scanf(" %[^\n]s", clientes[a].cep);
	}
	else if (b == 1) { system("cls"); printf("\nLogin ja existente!\n"); goto cliente_existente; }
}
//ok
void cadastro_administrador(int a) {
	int b, c;
	system("cls");
admin_existente:
	usuario[a].codigo = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", usuario[a].codigo);
	puts("\t=================================");
	puts("\n\n\tDigite o login: ");
	printf("\t");
	scanf(" %s", cad_admin[a].user);
	for (c = 0; c < 50; c++) {
		b = validar_login_adm(a, c);
		if (b == 1) break;
	} if (b == 0) {
		memcpy(usuario[a].user, cad_admin[a].user, 50);
		puts("\tDigite a senha: ");
		printf("\t");
		scanf(" %s", usuario[a].pass);
		/*puts("\tDigite o código: ");
		printf("\t");
		scanf(" %d", admin[a].codigo);*/
	}
	else if (b == 1) { system("cls"); printf("\nLogin ja existente!\n"); goto admin_existente; }
}
//ok
void altera_adm(int a) {
	int i, op_cad, cont = 0;
tela_adm:
	system("cls");
	head();
	printf("\tControle de adminstradores\n");
	if (a == 0) {
		printf("\tSem adm cadastrados!");
		Sleep(3000);
		login_adm();
	}
	else {
		gotoxy(8, 11); puts("|-------------------------------|");
		gotoxy(8, 12); puts("|índice\t|Nome\t\t|Código\t|\n");
		gotoxy(8, 13); puts("|-------|---------------|-------|");
		int j = 14;
		for (i = 0; i < a; i++, j++) {
			if (usuario[i].user != 0) {
				usuario[i].codigo = i + 1;
				gotoxy(8, j); printf("|(%d)", i + 1);
				gotoxy(16, j); printf("|%s", usuario[i].user);
				gotoxy(32, j); printf("|%d\t|", usuario[i].codigo);
				cont++;
			}
		}
		puts("\n\t|-------|---------------|-------|");
		puts("\t|-------------------------------|");
	}
	printf("\n\tDigite 1 para alterar ou 2 para adicionar: ");
	scanf("%d", &op_cad);
	if (op_cad == 1) {
		int b;
	repetir:
		printf("\tDigite o número do indice a ser alterado: ");
		scanf("%d", &b);
		if (b <= cont) {
			printf("\tDigite o novo nome: ");
			scanf(" %[^\n]s", &usuario[b - 1].user);
			printf("\tDigite o novo código: ");
			scanf("%d", &usuario[b - 1].codigo);
			printf("\tDigite a nova password: ");
			scanf("%s", &usuario[b - 1].pass);
			goto tela_adm;
		}
		else { printf("\tÍndice inválido!\n"); goto  repetir; }
	}
	else if (op_cad == 2) { login_adm(); }
	else if (op_cad == 9) login_adm();
	else if (op_cad == 0)  exit(0);
	else { printf("Opcao invalida!\n"); goto tela_adm; }
}
//ok
void altera_user(int a) {
	int i, op_cad, cont = 0;
tela_user:
	system("cls");
	head();
	printf("\tCONTROLE DE USUÁRIOS\n");
	if (a == 0) {
		printf("\tSem users cadastrados!");
		Sleep(3000);
		login_adm();
	}
	else {
		gotoxy(8, 11); puts("|-------------------------------|");
		gotoxy(8, 12); puts("|índice\t|Nome\t\t|Código\t|\n");
		gotoxy(8, 13); puts("|-------|---------------|-------|");
		int j = 14;
		for (i = 0; i < a; i++) {
			if (usuario[i].user != 0) {
				usuario[i].codigo = i + 1;
				gotoxy(8, j); printf("|(%d)", i + 1);
				gotoxy(16, j); printf("|%s", usuario[i].user);
				gotoxy(32, j); printf("|%d\t|", usuario[i].codigo);
				cont++;
				j++;
			}
		}
		puts("\n\t|-------|---------------|-------|");
		puts("\t|-------------------------------|");
	}
	printf("\n\tDigite 1 para alterar ou 2 para adicionar: ");
	scanf("%d", &op_cad);
	if (op_cad == 1) {
		int b;
	repetir:
		printf("\tDigite o número do indice a ser alterado: ");
		scanf("%d", &b);
		if (b <= cont) {
			printf("\tDigite o novo nome: ");
			scanf(" %[^\n]s", &usuario[b - 1].user);
			printf("\tDigite o novo código: ");
			scanf("%d", &usuario[b - 1].codigo);
			printf("\tDigite a nova password: ");
			scanf("%s", &usuario[b - 1].pass);
			goto tela_user;
		}
		else { printf("\tÍndice inválido!\n"); goto  repetir; }
	}
	else if (op_cad == 2) { login_adm(); }
	else if (op_cad == 9) login_adm();
	else if (op_cad == 0)  exit(0);
	else { printf("Opcao invalida!\n"); goto tela_user; }
}
//ok
void altera_cliente() {
	int i, op_cad, cont = 0, tam = sizeof(clientes->codigo_cliente);
tela_cliente:
	system("cls");
	head();
	printf("\t\t\tCONTROLE DE CLIENTES\n");
	if (clientes->codigo_cliente == 0) {
		printf("\tSem clientes cadastrados!");
		Sleep(3000);
		login_adm();
	}
	else {
		gotoxy(4, 11); puts("|------------------------------------------------------------------------------------------------------------|");
		gotoxy(4, 12); puts("|Índice|Nome");
		gotoxy(36, 12); puts("| Cód. | Telefone| Endereço");
		gotoxy(76, 12); puts("| Bairro");
		gotoxy(92, 12); puts("| Cidade");
		gotoxy(103, 12); puts("| CEP\t |");
		gotoxy(4, 13); puts("|------|------------------------|------|---------|----------------------|---------------|----------|---------|");
		int j = 14;
		for (i = 0; i < tam; i++, j++) {
			if (clientes[i].nome != 0) {
				clientes[i].codigo_cliente = i + 1;
				gotoxy(4, j); printf("|(%d)", i + 1);
				gotoxy(11, j); printf("|%s", clientes[i].nome);
				gotoxy(36, j); printf("|%d", clientes[i].codigo_cliente);
				gotoxy(43, j); printf("|%s", clientes[i].telefone);
				gotoxy(53, j); printf("|%s", clientes[i].endereco);
				gotoxy(76, j); printf("|%s", clientes[i].bairro);
				gotoxy(92, j); printf("|%s", clientes[i].cidade);
				gotoxy(103, j); printf("|%s", clientes[i].cep);
				gotoxy(113, j); printf("|");
				cont++;
			}
		}
		gotoxy(4, j - 1); puts("|------|------------------------|------|---------|----------------------|---------------|----------|---------|");
	}
	printf("\n\tDigite 1 para alterar ou 2 para adicionar: ");
	scanf("%d", &op_cad);
	if (op_cad == 1) {
		int b;
	repetir:
		printf("\tDigite o número do indice a ser alterado: ");
		scanf("%d", &b);
		if (b <= cont) {
			printf("\tDigite o novo nome: ");
			scanf(" %[^\n]s", &clientes[b - 1].nome);
			printf("\tDigite o novo código: ");
			scanf("%d", &clientes[b - 1].codigo_cliente);
			printf("\tDigite a nova password: ");
			scanf("%s", &clientes[b - 1].senha);
			printf("\tDigite o novo telefone: ");
			scanf("%s", &clientes[b - 1].telefone);
			printf("\tDigite a nova cidade: ");
			scanf("%s", &clientes[b - 1].cidade);
			printf("\tDigite o novo CEP: ");
			scanf("%s", &clientes[b - 1].cep);
			goto tela_cliente;
		}
		else { printf("\tÍndice inválido!\n"); goto  repetir; }
	}
	else if (op_cad == 2) { login_adm(); }
	else if (op_cad == 9) login_adm();
	else if (op_cad == 0)  exit(0);
	else { printf("Opcao invalida!\n"); goto tela_cliente; }
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
	strcpy(bebidas[0].bebida, "Água"), bebidas[0].preco_bebida = 1.00, bebidas[0].quantidade_bebida = 100, bebidas[0].codigo_bebiba = 20;
	strcpy(bebidas[1].bebida, "Coca-Cola"), bebidas[1].preco_bebida = 5.00, bebidas[1].quantidade_bebida = 100, bebidas[1].codigo_bebiba = 21;
	strcpy(bebidas[2].bebida, "Fanta"), bebidas[2].preco_bebida = 4.00, bebidas[2].quantidade_bebida = 100, bebidas[2].codigo_bebiba = 22;
	strcpy(bebidas[3].bebida, "Guarana"), bebidas[3].preco_bebida = 4.00, bebidas[3].quantidade_bebida = 100, bebidas[3].codigo_bebiba = 23;
	strcpy(bebidas[4].bebida, "Cerveja"), bebidas[4].preco_bebida = 3.00, bebidas[4].quantidade_bebida = 100, bebidas[4].codigo_bebiba = 24;
	strcpy(bebidas[5].bebida, "Suco"), bebidas[5].preco_bebida = 3.00, bebidas[5].quantidade_bebida = 100, bebidas[5].codigo_bebiba = 25;
	strcpy(bebidas[6].bebida, "Sprit"), bebidas[6].preco_bebida = 2.00, bebidas[6].quantidade_bebida = 100, bebidas[6].codigo_bebiba = 26;
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
	strcpy(pizzas[0].sabor, "mussarela"), pizzas[0].preco_pizza = 11, 99, strcpy(pizzas[0].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[0].codigo_pizza = 1, pizzas[0].qdt_ing = 5; 
	strcpy(pizzas[1].sabor, "calabresa"), pizzas[1].preco_pizza = 12.99, strcpy(pizzas[1].pizza_ingreditente.ingrediente, "Queijo"), 
		pizzas[1].codigo_pizza = 2, pizzas[1].qdt_ing = 5,
	strcpy(pizzas[2].sabor, "portuguesa"), pizzas[2].preco_pizza = 12.99, strcpy(pizzas[2].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[2].codigo_pizza = 3, pizzas[2].qdt_ing = 5;
	strcpy(pizzas[3].sabor, "quatro queijos"), pizzas[3].preco_pizza = 15.99, strcpy(pizzas[3].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[3].codigo_pizza = 4, pizzas[3].qdt_ing = 5;
	strcpy(pizzas[4].sabor, "peperone"), pizzas[4].preco_pizza = 15.99, strcpy(pizzas[4].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[4].codigo_pizza = 5, pizzas[4].qdt_ing = 5;
	strcpy(pizzas[5].sabor, "marguerita"), pizzas[5].preco_pizza = 12.99, strcpy(pizzas[5].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[5].codigo_pizza = 6, pizzas[5].qdt_ing = 5;
	strcpy(pizzas[6].sabor, "aspargus"), pizzas[6].preco_pizza = 11.99, strcpy(pizzas[6].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[6].codigo_pizza = 7, pizzas[6].qdt_ing = 5;
	strcpy(pizzas[7].sabor, "bacon"), pizzas[7].preco_pizza = 12.99, strcpy(pizzas[7].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[7].codigo_pizza = 8, pizzas[7].qdt_ing = 5;
	strcpy(pizzas[8].sabor, "cogumelo"), pizzas[8].preco_pizza = 13.99, strcpy(pizzas[8].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[8].codigo_pizza = 9, pizzas[8].qdt_ing = 5;
	strcpy(pizzas[9].sabor, "banana"), pizzas[9].preco_pizza = 12.99, strcpy(pizzas[9].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[9].codigo_pizza = 10, pizzas[9].qdt_ing = 5;
	strcpy(pizzas[10].sabor, "chocolate"), pizzas[10].preco_pizza = 13.99, strcpy(pizzas[0].pizza_ingreditente.ingrediente, "Queijo"),
		pizzas[10].codigo_pizza = 11, pizzas[10].qdt_ing = 5;
}
//ok
void cadastro_sugestao(int a) {
	int i, j;
	system("cls");
	clientes[a].codigo_cliente = a + 1;
	head();
	puts("\t=================================");
	printf("\n\tCadastro %d\n", clientes[a].codigo_cliente);
	puts("\t=================================");
	puts("\n\n\tDigite seu telefone: ");
	printf("\t");
	scanf("%s", cad_clientes[a].telefone);
	for (j = 0; j < 1000; j++) {
		i = validar_cliente(a, j);
		if (i == 1) break;
	}
	if (i == 1) {
		memcpy(clientes[a].telefone, cad_clientes[a].telefone, 9);
		printf("\n\tCliente cadastrado!\n\tDigite o seu elogio/reclamação/sugestão: \n");
		printf("\n\t_");
		scanf(" %[^\n]s", clientes[a].sugestao);
		printf("Sugestão salva com sucesso!!");
		Sleep(5000);
	}
	else if (i == 0) {
		system("cls");
		printf("\nCliente não cadastrado!\n");
		Sleep(5000);
		logar_cliente();
	}
}
//ok
void alterar_cadastro(int a, int b) {
	int op_cad, cont = 0;
tela_cadastro:
	system("cls");
	head();
	puts("\t=================================");
	printf("\t  Menu alterar cadastros\n");
	puts("\t=================================");
	printf("\t1- Administradores\n");
	puts("\t=================================");
	printf("\t2- Usuários\n");
	puts("\t=================================");
	printf("\t3- Clientes\n");
	puts("\t=================================");
	printf("\t");
	scanf("%d", &op_cad);
	system("cls");
	if (op_cad == 1) altera_adm(b);
	else if (op_cad == 2) altera_user(a);
	else if (op_cad == 3) altera_cliente();
	else if (op_cad == 9) login_adm();
	else if (op_cad == 0)  exit(0);
	else { system("cls"); printf("Opcao invalida!\n"); goto tela_cadastro; }
}
//ok
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
	else {
		for (c = 0; c < 1000; c++) {
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
	if (logado == 1) {
		system("cls");
		printf("\nLogin e/ou senha incorreto(s)\n");
		printf("\nTente Novamente!\n");
		goto erro_login;
	}
	else if (logado == 2) {
		system("cls");
		printf("\nLogado com sucesso!\n\nBem-vindo(a) %s\n", login[0]);
		//printf("Codigo do usuario: %d\n\n", usuario[c].codigo);
		//Sleep(1000);
		login_usuario();
	}
}
//ok
void login_usuario()
{
	int op_user, i = 0, nc=0, user_cad = 0, nm, np=1,r=0;

tela_inicial_user:
	system("cls");
	head();
	puts("\t=================================");
	printf("\t1- Mesas\n");
	puts("\t=================================");
	printf("\t2- Pedidos\n");
	puts("\t=================================");
	printf("\t3- Promoções\n");
	puts("\t=================================");
	printf("\t4- Clientes\n");
	puts("\t=================================");
	printf("\t9- Voltar a tela inicial de login\n");
	puts("\t=================================");
	printf("\t");
	scanf("%d", &op_user);
	system("cls");
	if (op_user == 1)
	{
		head();
		puts("\t=================================");
		printf("\n\tDigite o numero da mesa? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nm);
		menu_mesa(nm);
	}
	else if (op_user == 2) {
		head();
		printf("\t PEDIDO Nº %d\n", np);
		puts("\t=================================");
		printf("\n\tDigite o numero do telefone? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%s", &cadastro_pedido[nc].cliente_pedido.telefone);
		for (i = 0; i < sizeof(clientes->codigo_cliente); i++) {
			if (strcmp(cadastro_pedido[nc].cliente_pedido.telefone, clientes[i].telefone) == 0) {
				r = 1; //cliente cadastrado
			}
		}
		if (r == 1) {
			system("cls");
			menu_pedido(np, nc);
		}
		else {
			puts("\tcliente não cadastrado! favor cadastrar.");
			Sleep(1000);
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

	if (op_cliente == 1) {
		system("cls");
		head();
		puts("\t=================================");
		printf("\n\tQuantos cadastros deseja fazer? \n");
		puts("\t=================================");
		printf("\t");
		scanf("%d", &nc);
		if (i == 0) {
			for (i = 0; i < nc; i++) {
				cadastro_clientes(i);
			}
			goto tela_inicial_cliente;
		}
		else if (i != 0) {
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
		if (i == 0) {
			for (i = 0; i < nc; i++)
			{
				cadastro_sugestao(i);
			}
			goto tela_inicial_cliente;
		}
		else if (i != 0) {
			x = i;
			y = i + nc - 1;
			printf("\n%d\n", i);
			for (i = x; i <= y; i++) {
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
	else {
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
	if (logado == 1) {
		system("cls");
		head();
		printf("\nLogin e/ou senha incorreto(s)\n");
		printf("\nTente Novamente!\n");
		Sleep(3000);
		goto erro_login;
	}
	else if (logado == 2) {
		system("cls");
		printf("\n\tLogado com sucesso!\n\n\tBem-vindo(a) [ADM]%s\n", login[0]);
		// printf("Codigo do ADMIN: %d\n\n",admin[c].codigo);
		//Sleep(1000);
		login_adm();
	}
}
//ok
void login_adm() {
	int op_adm;
	int  a = 0, adm_cad = 0, b, c, nc;

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
	if (op_adm == 1) {
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
		else if (a != 0) {
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
	else if (op_adm == 3) {
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
		menu_estoque();
	}
	else if (op_adm == 5) {
		alterar_cadastro(a, adm_cad);
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
	else { system("cls"); printf("\n\tOpcao Invalida\n"); goto tela_inicial_adm; }
}

void menu_login_inicial()
{
	int op_login;
	system("cls");
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
void menu_estoque() {
	int op_estoque;
menu_de_estoque:
	head();
	puts("\t=================================");
	printf("\n\t1- Estoque de Bebidas\n");
	puts("\t=================================");
	printf("\n\t2- Estoque de Igredientes\n");
	puts("\t=================================");
	printf("\n\t9- Voltar a tela de login\n");
	puts("\t=================================");
	printf("\t");
	scanf(" %d", &op_estoque);
	if (op_estoque == 1) estoque_bebida();
	else if (op_estoque == 2) estoque_ingrediente();
	else if (op_estoque == 9) login_adm();
	else if (op_estoque == 0) exit(0);
	else
	{
		system("cls");
		printf("Opcao invalida!\n");
		Sleep(3000);
		goto menu_de_estoque;
	}
}
//ok
void estoque_bebida() {
	int i, cont = 0, op_bebida = 0, tam = sizeof(bebidas->bebida);;
	fflush(stdin);
cad_bebida:
	system("cls");
	head();
	printf("\t\tCONTROLE DE ESTOQUE BEBIDAS\n");
	gotoxy(8, 12); puts("|-------------------------------------------------------|");
	gotoxy(8, 13); puts("|item\t|Código\t|Produto\t|Tipo\t|Qtde\t|Preço\t|\n");
	gotoxy(8, 14); puts("|-------|-------|---------------|-------|-------|-------|");
	int j = 15;
	for (i = 0; i <= tam; i++, j++) {
		if (bebidas[i].codigo_bebiba != 0) {
			gotoxy(8, j); printf("|(%d)", i + 1);
			gotoxy(16, j); printf("|%d", bebidas[i].codigo_bebiba);
			gotoxy(24, j); printf("|%s", bebidas[i].bebida);
			gotoxy(40, j); printf("|%s", "Bebida");
			gotoxy(48, j); printf("|%d", bebidas[i].quantidade_bebida);
			gotoxy(56, j); printf("|R$%.2f", bebidas[i].preco_bebida);
			gotoxy(64, j); printf("|");
			cont++;
		}
	}
	puts("\n\t|-------|-------|---------------|-------|-------|-------|");
	puts("\t|-------------------------------------------------------|");
	printf("\n\tDigite 1 para alterar ou 2 para adicionar: ");
	scanf("%d", &op_bebida);

	if (op_bebida == 1) {
		int a;
	repetir:
		printf("\tDigite o número do item a ser alterado: ");
		scanf("%d", &a);
		if (a <= cont) {
			printf("\tDigite o novo nome da bebida: ");
			scanf(" %[^\n]s", &bebidas[a - 1].bebida);
			printf("\tDigite o novo código da bebida: ");
			scanf("%d", &bebidas[a - 1].codigo_bebiba);
			printf("\tDigite nova quantidade: ");
			scanf("%d", &bebidas[a - 1].quantidade_bebida);
			printf("\tDigite o novo valor: ");
			scanf("%lf", &bebidas[a - 1].preco_bebida);
			goto cad_bebida;
		}
		else { printf("\tÍndice inválido!\n"); goto  repetir; }
	}
	else if (op_bebida == 2) {
		printf("\tDigite a nova bebida: ");
		scanf(" %[^\n]s", &bebidas[cont - 1].bebida);
		printf("\tDigite o código da bebida: ");
		scanf("%d", &bebidas[cont - 1].codigo_bebiba);
		printf("\tDigite quantidade: ");
		scanf("%d", &bebidas[cont - 1].quantidade_bebida);
		printf("\tDigite o valor: ");
		scanf("%lf", &bebidas[cont - 1].preco_bebida);
		goto cad_bebida;
	}
	else if (op_bebida == 9) { login_adm(); }
	else if (op_bebida == 0) { exit(0); }
	else { system("cls"); printf("Opcao invalida!\n"); goto cad_bebida; }
}

void estoque_ingrediente() {
	int i, cont = 0, op_ing = 0, tam = sizeof(ingredientes->ingrediente);;
	fflush(stdin);
cad_ingredientes:
	system("cls");
	head();
	printf("\tCONTROLE DE INGREDIENTES\n");
	gotoxy(8, 12); puts("|-------------------------------------------------------|");
	gotoxy(8, 13); puts("|item\t|Código\t|Produto\t|Tipo\t\t|Qtde\t|\n");
	gotoxy(8, 14); puts("|-------|-------|---------------|---------------|-------|");
	int j = 15;
	for (i = 0; i <= tam; i++, j++) {
		if (ingredientes[i].codigo_ingrediente != 0) {
			gotoxy(8, j); printf("|(%d)", i + 1);
			gotoxy(16, j); printf("|%d", ingredientes[i].codigo_ingrediente);
			gotoxy(24, j); printf("|%s", ingredientes[i].ingrediente);
			gotoxy(40, j); printf("|%s", "Suprimentos");
			gotoxy(56, j); printf("|%d", ingredientes[i].quantidade_ingredientes);
			gotoxy(64, j);  printf("|");
			cont++;
		}
	}
	puts("\n\t|-------|-------|---------------|---------------|-------|");
	puts("\t|-------------------------------------------------------|");
	printf("\n\tDigite 1 para alterar ou 2 para adicionar: ");
	scanf("%d", &op_ing);
	if (op_ing == 1) {
		int a;
	repetir:
		printf("\tDigite o número do item a ser alterado: ");
		scanf("%d", &a);
		if (a <= cont) {
			printf("\tDigite o novo nome: ");
			scanf(" %[^\n]s", &ingredientes[a - 1].ingrediente);
			printf("\tDigite o novo código: ");
			scanf("%3d", &ingredientes[a - 1].codigo_ingrediente);
			printf("\tDigite nova quantidade: ");
			scanf("%d", &ingredientes[a - 1].quantidade_ingredientes);
			goto cad_ingredientes;
		}
		else { printf("\tÍndice inválido!\n"); goto  repetir; }
	}
	else if (op_ing == 2) {

		printf("\tDigite o novo ingrediente: ");
		scanf(" %[^\n]s", &ingredientes[cont - 1].ingrediente);
		printf("\tDigite o código: ");
		scanf("%d", &ingredientes[cont - 1].codigo_ingrediente);
		printf("\tDigite quantidade: ");
		scanf("%d", &ingredientes[cont - 1].quantidade_ingredientes);
		goto cad_ingredientes;

	}
	else if (op_ing == 9) login_adm();
	else if (op_ing == 0) exit(0);
	else { system("cls"); printf("Opcao invalida!\n"); goto cad_ingredientes; }
}
//ok
void menu_mesa(int nm) {
	int i, j, a, tamP = sizeof(pizzas->sabor), tamB = sizeof(bebidas->bebida), codProduto[20];
	double valor = 0.00;
	char op;
	system("cls");
tela:
	head();
	gotoxy(6, 10); printf("\tCAIXA REGISTRO DE MESA Nº %d \t| Selecione 'E' entrar 'S' sair 'V' valor 'N' nova mesa -> ", nm);
	gotoxy(6, 11); puts("|-----------------------------------------------------------------------------------------------------------|");
	gotoxy(6, 12); puts("|\tPizzas\t\t\t\t| Bebidas\t\t\t| CAIXA\t\t\t\t\t  |");
	gotoxy(6, 13); puts("|---------------------------------|-------------------------------|-----------------------------------------|");
	gotoxy(6, 14); puts("| Cod.| Descrição\t\t| Preço | Cod.| Descrição\t| Preço | ITEM | CÓDIGO | DESCRIÇÃO    \t| VALOR   |    ");
	gotoxy(6, 15); puts("|-----|-------------------|-------|-----|-----------------|-------|------|--------|---------------|---------|");
	for (i = 16, j = 0; i < 29; i++, j++) {
		gotoxy(6, i); printf("|");
		gotoxy(12, i); printf("|");
		gotoxy(32, i); printf("|");
		gotoxy(40, i); printf("|");
		gotoxy(46, i); printf("|");
		gotoxy(64, i); printf("|");
		gotoxy(72, i); printf("|");
		gotoxy(114, i); printf("|");
	}
	for (i = 16, j = 0; i < 27; i++, j++) {
		gotoxy(74, i); printf("(%d)", j + 1);
		gotoxy(79, i); printf("|");
		gotoxy(88, i); printf("|");
		gotoxy(104, i); printf("|");
	}
	gotoxy(73, 27); puts("-----------------------------------------");
	gotoxy(74, 28); puts(" Valor total -> ");
	gotoxy(6, 29); puts("|-----|-------------------|-------|-----|-----------------|-------|-----------------------------------------|");
	//apresentando as pizzas no menu
	for (i = 0, j = 16; i < tamP; i++, j++) {
		if (pizzas[i].codigo_pizza != 0) {
			gotoxy(7, j); printf(" %2d", pizzas[i].codigo_pizza);
			gotoxy(13, j); printf("-> %s", pizzas[i].sabor);
			gotoxy(33, j); printf("R$%.2f", pizzas[i].preco_pizza);
		}
	}
	//apresentando as bebidas no menu
	for (i = 0, j = 16; i < tamB; i++, j++) {
		if (bebidas[i].codigo_bebiba != 0) {
			gotoxy(41, j); printf(" %2d", bebidas[i].codigo_bebiba);
			gotoxy(47, j); printf("-> %s", bebidas[i].bebida);
			gotoxy(65, j); printf("R$%.2f", bebidas[i].preco_bebida);
		}
	}
opcao:
	gotoxy(106, 10); scanf(" %c", &op);
	if (op == 'E' || op == 'e') {
		goto mesa;
	}
	else if (op == 'P' || op == 'p') {
		;
	}
	else if (op == 'F' || op == 'f') {
		goto fechar_mesa;
	}
	else if (op == '9') { system("cls"); login_usuario(); }
	else if (op == '0') exit(0);
	else { system("cls"); printf("\n\tOpcao Invalida\n"); goto tela; }
mesa:
	for (i = 0, j = 16; codProduto[i] != 0; i++, j++) {
		gotoxy(83, j); scanf("%d", &codProduto[i]);
		for (a = 0; a < tamP; a++) {
			if (codProduto[i] == pizzas[a].codigo_pizza) {
				gotoxy(89, j); printf(" %s", pizzas[a].sabor);
				gotoxy(105, j); printf("R$%.2f", pizzas[a].preco_pizza);
				valor = valor + pizzas[a].preco_pizza;
			}
			else if (codProduto[i] == bebidas[a].codigo_bebiba) {
				gotoxy(89, j); printf(" %s", bebidas[a].bebida);
				gotoxy(105, j); printf("R$%.2f", bebidas[a].preco_bebida);
				valor = valor + bebidas[i].preco_bebida;
			}
			else if (codProduto[i] == 99) {
				goto fechar_mesa;
			}
		}
	}
fechar_mesa:
	gotoxy(89, 28); printf("R$ %.2f", valor);
	goto opcao;
}

void menu_pedido(int np, int nc) {
	int i=0,j, a, codPedido[10], tamC = sizeof(clientes->nome), tamP = sizeof(pizzas->sabor),tamB = sizeof(bebidas->bebida);
	char op;
	float valor_pedido=0;
	fflush(stdin);
pedido:
	head();
	gotoxy(6, 9); printf("|\tREGISTRO DE PEDIDO %d", np);
	gotoxy(6, 10); puts("|-----------------------------------------------------------------------------------------------------------|");
	gotoxy(6, 11); puts("|\tDados cliente\t\t| Dados pedidos\t| Selecione 'E' entrar 'S' sair 'V' valor 'N' nova mesa -> \t\t");
	gotoxy(114, 11); puts("|");
	gotoxy(6, 12); puts("|-----------------------------------------------------------------------------------------------------------|");
	gotoxy(6, 13); puts("| Cod.| Nome do cliente\t| Telefone | Endereço\t\t\t| Bairro\t| Cidade\t| CEP");
	gotoxy(114, 13); puts("|");
	gotoxy(6, 14); puts("|-----|-------------------|----------|----------------------------|---------------|---------------|---------|");
	for (i = 0; i < tamC; i++) {
		if (strcmp(cadastro_pedido[nc].cliente_pedido.telefone, clientes[i].telefone) == 0) {
			gotoxy(6, 15); printf("| (%d)", clientes[i].codigo_cliente);
			gotoxy(12, 15); printf("|%s", clientes[i].nome);
			gotoxy(32, 15); printf("|%s", clientes[i].telefone);
			gotoxy(43, 15); printf("|%s", clientes[i].endereco);
			gotoxy(72, 15); printf("|%s", clientes[i].bairro);
			gotoxy(88, 15); printf("|%s", clientes[i].cidade);
			gotoxy(104, 15); printf("|%s", clientes[i].cep);
			gotoxy(114, 15); printf("|");
		}
	}	
	gotoxy(6, 16); puts("|-----|-------------------|----------|----------------------------|---------------|---------------|---------|");
	gotoxy(6, 17); puts("|-----------------------------------------------------------------------------------------------------------|");
	gotoxy(6, 18); puts("| PIZZAS PEDIDO");
	gotoxy(69, 18); puts("| BEBIDAS PEDIDO");
	gotoxy(99, 18); puts("| CAIXA");
	gotoxy(114, 18); printf("|");
	gotoxy(6, 19); puts("|-----------------------------------------------------------------------------------------------------------|");
	for (i = 20, j = 0; i < 31; i++, j++) {
		gotoxy(6, i); printf("|");
		gotoxy(12, i); printf("|");
		gotoxy(32, i); printf("|");
		gotoxy(40, i); printf("|");
		gotoxy(46, i); printf("|");
		gotoxy(64, i); printf("|");
		gotoxy(72, i); printf("|");
		gotoxy(114, i); printf("|");
	}
	for (i = 20, j = 0; i < 29; i++, j++) {
		gotoxy(74, i); printf("(%d)", j + 1);
		gotoxy(79, i); printf("|");
		gotoxy(88, i); printf("|");
		gotoxy(104, i); printf("|");
	}
	gotoxy(73, 29); puts("-----------------------------------------");
	gotoxy(74, 30); puts(" Valor total -> ");
	gotoxy(6, 31); puts("|-----|-------------------|-------|-----|-----------------|-------|-----------------------------------------|");
	//apresentando as pizzas no menu
	for (i = 0, j = 20; i < tamP; i++, j++) {
		if (pizzas[i].codigo_pizza != 0) {
			gotoxy(7, j); printf(" %2d", pizzas[i].codigo_pizza);
			gotoxy(13, j); printf("-> %s", pizzas[i].sabor);
			gotoxy(33, j); printf("R$%.2f", pizzas[i].preco_pizza);
		}
	}
	//apresentando as bebidas no menu
	for (i = 0, j = 20; i < tamB; i++, j++) {
		if (bebidas[i].codigo_bebiba != 0) {
			gotoxy(41, j); printf(" %2d", bebidas[i].codigo_bebiba);
			gotoxy(47, j); printf("-> %s", bebidas[i].bebida);
			gotoxy(65, j); printf("R$%.2f", bebidas[i].preco_bebida);
		}
	}
opcao:
	gotoxy(108, 11); scanf(" %c", &op);
	if (op == 'E' || op == 'e') {
		goto pedido_entra;
	}
	else if (op == 'F' || op == 'f') {
		goto fechar_pedido;
	}
	else if (op == '9') { system("cls"); login_usuario(); }
	else if (op == '0') exit(0);
	else { system("cls"); printf("\n\tOpcao Invalida\n"); goto pedido; }
pedido_entra:
	for (i = 0, j = 20; codPedido[i] != 0; i++, j++) {
		gotoxy(83, j); scanf("%d", &codPedido[i]);
		for (a = 0; a < tamP; a++) {
			if (codPedido[i] == pizzas[a].codigo_pizza) {
				gotoxy(89, j); printf(" %s", pizzas[a].sabor);
				gotoxy(105, j); printf("R$%.2f", pizzas[a].preco_pizza);
				valor_pedido = valor_pedido + pizzas[a].preco_pizza;
			}
			else if (codPedido[i] == bebidas[a].codigo_bebiba) {
				gotoxy(89, j); printf(" %s", bebidas[a].bebida);
				gotoxy(105, j); printf("R$%.2f", bebidas[a].preco_bebida);
				valor_pedido = valor_pedido + bebidas[i].preco_bebida;
			}
			else if (codPedido[i] == 99) {
				goto fechar_pedido;
			}
		}
	}
fechar_pedido:
	gotoxy(89, 30); printf("R$ %.2f", valor_pedido);
	goto opcao;
	scanf("%d", &op);
	if (op == 1){ }
	else if (op == '9') { system("cls"); login_usuario(); }
	else if (op == '0') { exit(0); }
	else { system("cls"); printf("\n\tOpcao Invalida\n"); goto pedido; }
}

void stcli() {
	strcpy(clientes[0].nome, "Joaozinho da silva"), strcpy(clientes[0].telefone, "9999-9999"), strcpy(clientes[0].endereco, "Sul 10, bloco A"),
		strcpy(clientes[0].bairro, "Aguas Claras"), strcpy(clientes[0].cidade, "Brasilia"), strcpy(clientes[0].cep, "70000-000"), clientes[0].codigo_cliente = 1;
	strcpy(clientes[1].nome, "pedrinho da silva"), strcpy(clientes[1].telefone, "8888-9999"), strcpy(clientes[1].endereco, "Sul 10, bloco A"),
		strcpy(clientes[1].bairro, "Aguas Claras"), strcpy(clientes[1].cidade, "Brasilia"), strcpy(clientes[1].cep, "70000-000"), clientes[1].codigo_cliente = 2;
	strcpy(clientes[2].nome, "mariazinha da silva"), strcpy(clientes[2].telefone, "7777-9999"), strcpy(clientes[2].endereco, "Sul 10, bloco A"),
		strcpy(clientes[2].bairro, "Aguas Claras"), strcpy(clientes[2].cidade, "Brasilia"), strcpy(clientes[2].cep, "70000-000"), clientes[2].codigo_cliente = 3;
}
//ok
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	stcli();
	cadastro_pizzas();
	cadastro_bebidas();
	cadastro_ingredientes();
	system("cls");
	menu_login_inicial();
	return 0;
}
//ok
void head() {
	dataHora();
	printf("\t.____             _________                             .___        __________.__                        \n");
	printf("\t|    |   _____    \\_   ___ \\_____    ___________      __| _/____    \\______   \\__|____________________   \n");
	printf("\t|    |   \\__  \\   /    \\  \\/\\__  \\  /  ___/\\__  \\    / __ |\\__  \\    |     ___/  \\___   /\\___   /\\__  \\  \n");
	printf("\t|    |___ / __ \\_ \\     \\____/ __ \\_\\___ \\  / __ \\_ / /_/ | / __ \\_  |    |   |  |/    /  /    /  / __ \\_\n");
	printf("\t|_______ (____  /  \\______  (____  /____  >(____  / \\____ |(____  /  |____|   |__/_____ \\/_____ \\(____  /\n");
	printf("\t        \\/    \\/          \\/     \\/     \\/      \\/       \\/     \\/                     \\/      \\/     \\/ \n\n\n");
}
//ok
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
//ok
void gotoxy(int coluna, int linha) {
	COORD point;
	point.X = coluna;
	point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
//ok