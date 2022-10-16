#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	//Declaracao das variaveis utilizadas
	int escolhaInicio, dificuldade = 2, leDificuldade, tentativas, numerosCertos = 0, numerosPosicaoCerta = 0, resposta, n1, n2, n3, n4, n5, i;
	bool case2 = false, naoVenceu = true;

	//Laco de repeticao que roda ate o usuario pedir pra sair
	while (true)
	{
		cout << "<----- Boas Vindas ----->" << endl;
		cout << "\n[1] - Jogar" << endl;
		cout << "[2] - Dificuldade" << endl;
		cout << "[3] - Sobre" << endl;
		cout << "[4] - Sair" << endl;
		cin >> escolhaInicio; //Le a escolha do usuario

		switch (escolhaInicio) { //Executa de acordo com a escolha do usario
		case 1://Escolha jogar
			switch (dificuldade)//define as tentativas de acordo com a dificuldade
			{
			case 1:
				tentativas = 8;
				break;
			case 2:
				tentativas = 10;
				break;
			case 3:
				tentativas = 12;
				break;
			}

			system("cls");
			srand(time(NULL));
			n4 = 0, n5 = 0;
			for (i = 0; i < dificuldade + 2; i++) {//Repete para gerar o 5 numeros nao repetidos
				switch (i)//Gera os numeros de acordo com a quantidade de repeticoes
				{
				case 0://Apenas gera o primeiro numero
					n1 = rand() % 6 + 1;
					break;
				case 1://Gera o numero 2
					n2 = rand() % 6 + 1;
					while (n2 == n1)//Gera denovo ate ser diferente do primeiro
					{
						n2 = rand() % 6 + 1;
					}
					break;
				case 2://gera o 3 numero
					n3 = rand() % 6 + 1;
					while (n3 == n1 || n3 == n2)//Gera dnovo ate ser diferente do n1 e n2
					{
						n3 = rand() % 6 + 1;
					}
					break;
				case 3://gera o 4 numero
					n4 = rand() % 6 + 1;
					while (n4 == n1 || n4 == n2 || n4 == n3)//gera dnovo ate ser diferente do n1, n2 e n3
					{
						n4 = rand() % 6 + 1;
					}
					break;
				case 4://gera o 5 numero
					n5 = rand() % 6 + 1;
					while (n5 == n1 || n5 == n2 || n5 == n3 || n5 == n4)//gera dnovo ate ser diferente do n1, n2 ,n3 e n4
					{
						n5 = rand() % 6 + 1;
					}
					break;
				default:
					break;
				}
			}
			naoVenceu = true; //Sempre que ele jogar define que ele nao venceu
			while (tentativas > 0 && naoVenceu) {//roda ate acabar as tentativas ou vencer o jogo
				//zera as variaveis
				numerosCertos = 0;
				numerosPosicaoCerta = 0;
				for (i = 0; i < dificuldade + 3; i++)//Roda uma vez a mais de acordo com a dificuldade para poder atualizar os numeros certos
				{
					system("cls");
					cout << "Tentativas Restantes: " << tentativas;
					cout << "\nNumeros certos: " << numerosCertos;
					cout << "\nNumeros certos nas posicoes certas: " << numerosPosicaoCerta << endl;
					if (i < dificuldade + 2)//Apenas le a tentativa quando o numero da repeticao for menor que o numero de numeros do jogo
					{
						cout << "\nSua tentativa " << i + 1 << "/" << dificuldade + 2 << ": ";
						cin >> resposta;
					}
					if (resposta > 0 && resposta < 7) {//soh verifica se ele digitar um numero valido
						switch (i)//Utilizado para verificar se tem numero certo e se esta na posicao certa
						{
						case 0://verifica o primeiro numero
							if (resposta == n1)//se for igual o numero da posicao 1 soma os dois
							{
								numerosCertos++;
								numerosPosicaoCerta++;
							}
							else if (resposta == n2 || resposta == n3 || resposta == n4 || resposta == n5)//Se for igual aos outros apenas soma o numero certo
							{
								numerosCertos++;
							}
							break;
						case 1://faz o mesmo procedimento para o segundo
							if (resposta == n2)
							{
								numerosCertos++;
								numerosPosicaoCerta++;
							}
							else if (resposta == n1 || resposta == n3 || resposta == n4 || resposta == n5)
							{
								numerosCertos++;
							}
							break;
						case 2://faz o mesmo procedimento para o terceiro
							if (resposta == n3)
							{
								numerosCertos++;
								numerosPosicaoCerta++;
							}
							else if (resposta == n1 || resposta == n2 || resposta == n4 || resposta == n5)
							{
								numerosCertos++;
							}
							break;
						case 3://faz o mesmo procedimento para o quarto
							if (resposta == n4)
							{
								numerosCertos++;
								numerosPosicaoCerta++;
							}
							else if (resposta == n1 || resposta == n2 || resposta == n3 || resposta == n5)
							{
								numerosCertos++;
							}
							break;
						case 4://faz o mesmo procedimento para o quinto
							if (resposta == n5)
							{
								numerosCertos++;
								numerosPosicaoCerta++;
							}
							else if (resposta == n1 || resposta == n2 || resposta == n3 || resposta == n4)
							{
								numerosCertos++;
							}
							break;
						}
					}
					else {//caso n seja valido, volta a repeticao
						i--;
					}

					if (numerosPosicaoCerta == dificuldade + 2)//verifica se o quantidade de acertos de posicao eh igual ao numero de digitos para adivinhar 
					{
						naoVenceu = false;//se verdadeiro, define que ganhou para sair do jogo
					}
				}
				tentativas--;//diminui o numero de tentativas restantes
				system("pause");
			}

			system("cls");
			if (naoVenceu)//verifica se venceu ou perdeu e avisa
			{
				cout << "<----- Que pena, nao foi dessa vez! ;-; ----->" << endl;
			}
			else
			{
				cout << "<----- Parabens voce venceu! ----->" << endl;
			}
			cout << "O numero era: " << n1 << n2 << n3;//escreve apenas os numeros de acordo com a dificuldade
			if (dificuldade == 2)
			{
				cout << n4 << endl;
			}
			else if (dificuldade == 3)
			{
				cout << n4 << n5 << endl;
			}
			cout << "\n";

			/*cout << "O numero era: " << n1 << n2 << n3;
			n4 == 0 ? cout << "" : cout << n4;                 <--- eu faria assim
			n5 == 0 ? cout << "" : cout << n5;*/

			system("pause");
			system("cls");
			break;

		case 2://tela de dificuldade
			case2 = true;//define sempre que entrar como verdadeiro
			while (case2) {//enquanto a pessoa nao sair deixa na tela
				system("cls");
				cout << "<----- Escolha sua Dificuldade ----->" << endl;
				cout << "\nAtualmente a dificuldade esta em: " << dificuldade << endl;//escreve qual a dificuldade atual
				cout << "\n[1] - Facil" << endl;
				cout << "[2] - Medio" << endl;
				cout << "[3] - Dificil" << endl;
				cout << "\[9] - Voltar" << endl;
				cin >> leDificuldade;

				switch (leDificuldade)//define a dificuldade apenas nas opcoes validas
				{
				case 1:
					dificuldade = 1;
					break;
				case 2:
					dificuldade = 2;
					break;
				case 3:
					dificuldade = 3;
					break;
				case 9:
					case2 = false;
					break;
				}
			}
			system("cls");
			break;

		case 3://tela sobre
			system("cls");
			cout << "Equipe de Deselvolvimento:" << endl;
			cout << "Gabriel de Jesus" << endl;
			cout << "Gregori Maciel" << endl;
			cout << "Kaio Saldanha" << endl;
			cout << "Vinicius Grisa\n" << endl;
			cout << "Data: Outubro/2022\n" << endl;
			cout << "Professora: Cristina Ono Horita\n" << endl;
			system("pause");//pausa pessoa ler
			system("cls");
			break;

		case 4://sai do programa e agradece
			system("cls");
			cout << "<----- Obrigado por Jogar ----->" << endl;
			return 0;
		}
	}
}