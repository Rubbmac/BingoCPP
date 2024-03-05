#include <iostream>
#include <math.h>
#include <time.h>
#include <string>

using namespace std;


void printMatriz(int** m,int l, int c) {
	cout << "================================================================================="<<endl;
	for (int i = 0; i < l; i++)
	{
		cout << "|";
		for (int e = 0; e < c; e++)
		{
			cout << "\t" << m[i][e] << "\t|";
		}
		cout << endl << "=================================================================================" << endl;
	}
	cout << endl;
}
bool verificaNumRepetido(int** m, int lin, int col) {
	for (int i = 0; i < lin; i++)
	{
		for (int e = 0; e < col; e++)
		{
			for (int k = 0; k < lin; k++)
			{
				for (int u = 0; u < col; u++)
				{
					if (i == k && e == u)
					{
						// mesma posicao da matriz, não compara
					}
					else
					{
						if (m[i][e] == m[k][u])
						{
							return false;
						}
					}

				}

			}
		}
	}
	return true;
}
int** preencheMatriz(int** m, int lin, int col) {
	do
	{
		for (int i = 0; i < lin; i++)
		{
			for (int e = 0; e < col; e++)
			{
				m[i][e] = rand() % 60 + 1;
			}
		}
	} while (!verificaNumRepetido(m, lin, col));
	/*printMatriz(m);*/
	return m;
}

void criaMatriz(int** m, int l, int c) {
	for (int i = 0; i < l; i++)
	{
		m[i] = new int [c];
	}
}
int verificaPremioUm(int** car, int cLin, int cCol, int** bol, int bLin, int bCol) {
	int count=0; //count aumentará a cada valor no cartao correspondente a uma bola lançada desde que seja na posição do premio
	for (int i = 0; i < cCol; i++) //vai verificar toda a primeira linha do cartao
	{
		for (int k = 0; k < bLin; k++)
		{
			for (int u = 0; u < bCol; u++)
			{
				if (car[0][i]==bol[k][u])
				{
					count++;
				}
			}
		}
	}
	for (int e = 1; e < cCol-1; e++) //verifica a segunda linha com exceçao do primeiro e ultimo index
	{
		for (int q = 0; q < bLin; q++)
		{
			for (int w = 0; w < bCol; w++)
			{
				if (car[1][e] == bol[q][w])
				{
					count++;
				}
			}
		}
	}
	for (int a = 0; a < bLin; a++) //verifica apenas o index 2 da última linha
	{
		for (int s = 0; s < bCol; s++)
		{
			if (car[2][2] == bol[a][s])
			{
				count++;
			}
		}
	}
	return count;
}
int verificaPremioUmV2(int** car, int cLin, int cCol, int* v,int c) {
	int count = 0; //count aumentará a cada valor no cartao correspondente a uma bola lançada desde que seja na posição do premio
	for (int i = 0; i < cCol; i++) //vai verificar toda a primeira linha do cartao
	{
		for (int e = 0; e < c+1; e++)
		{
			if (car[0][i]==v[e])
			{
				count++;
			}

		}
	}
	for (int q = 1; q < cCol - 1; q++) //verifica a segunda linha com exceçao do primeiro e ultimo index
	{
		for (int w = 0; w < c+1; w++)
		{
			if (car[1][q] == v[w])
			{
				count++;
			}			
		}
	}
	for (int a = 0; a < c+1; a++) //verifica apenas o index 2 da última linha
	{
		if (car[2][2] == v[a])
		{
			count++;
		}
	}
	return count;
}
int verificaPremioDois(int** car, int cLin, int cCol, int** bol, int bLin, int bCol) {
	int count = 0; //count aumentará a cada valor no cartao correspondente a uma bola lançada desde que seja na posição do premio
	for (int i = 0; i < cCol; i++) //vai verificar toda a primeira linha do cartao
	{
		for (int k = 0; k < bLin; k++)
		{
			for (int u = 0; u < bCol; u++)
			{
				if (car[0][i] == bol[k][u])
				{
					count++;
				}
			}
		}
	}	
	for (int e = 0; e < cCol; e++) //vai verificar toda a ultima linha do cartao
	{
		for (int q = 0; q < bLin; q++)
		{
			for (int w = 0; w < bCol; w++)
			{
				if (car[2][e] == bol[q][w])
				{
					count++;
				}
			}
		}
	}
	for (int a = 0; a < bLin; a++) //verifica apenas o index 2 da segunda linha
	{
		for (int s = 0; s < bCol; s++)
		{
			if (car[1][2] == bol[a][s])
			{
				count++;
			}
		}
	}
	return count;
}
int verificaPremioDoisV2(int** car, int cLin, int cCol, int* v, int c) {
	int count = 0; //count aumentará a cada valor no cartao correspondente a uma bola lançada desde que seja na posição do premio
	for (int i = 0; i < cCol; i++) //vai verificar toda a primeira linha do cartao
	{
		for (int k = 0; k < c+1; k++)
		{
			if (car[0][i] == v[k])
			{
				count++;
			}
		}
	}
	for (int e = 0; e < cCol; e++) //vai verificar toda a ultima linha do cartao
	{
		for (int q = 0; q < c+1; q++)
		{
			if (car[2][e] == v[q])
			{
				count++;
			}
		}
	}
	for (int a = 0; a < c+1; a++) //verifica apenas o index 2 da segunda linha
	{
		if (car[1][2] == v[a])
		{
			count++;
		}
	}
	return count;

}
void matrizAscendente(int** m, int lin, int col) {	
	int aux;
	for (int i = 0; i < lin; i++)
	{
		for (int e = 0; e < col; e++)
		{
			for (int k = 0; k < lin; k++)
			{
				for (int u = 0; u < col; u++)
				{
					if (m[k][u] > m[i][e])
					{
						aux = m[i][e];
						m[i][e] = m[k][u];
						m[k][u] = aux;
					}

				}
			}
		}
	}
}
int ganhaPremioUm(int num,int c) {
	if (num == 9)
	{
		c += 10;
		cout << "\nParabens! Ganhou 10 creditos!\nPossui agora " << c << " creditos!\n";
	}
	else
	{
		cout << "Acertou " << num << " bolas do primeiro premio. Faltaram " << 9 - num << " para ganhar o primeiro premio.\n";
	}
	return c;
}
int ganhaPremioDois(int num, int c) {
	if (num == 11)
	{
		c += 50;
		cout << "\nParabens! Ganhou 50 creditos!!!\nPossui agora " << 9 - num << " creditos!\n";
	}
	else
	{
		cout << "Acertou " << num << " bolas do segundo premio. Faltaram " << 11 - num << " para ganhar o segundo premio.\n";
	}
	return c;
}

//CHALLENGE 4
bool verificaNumRepetido2(int* v, int c, int** m) {
	for (int i = 0; i < 6; i++)
	{
		for (int e = 0; e < 5; e++)
		{
			if (v[c] == m[i][e])
			{
				return false;
			}
		}
	}
	for (int k = 0; k < c+1; k++)
	{
		if (k != c) //msm posicao do vetor das bolas extra
		{
			if (v[k]==v[c])
			{
				return false;
			}
		}
	}
	return true;
}
void adicionaBola(int* v, int c,int**m){
	do
	{
		v[c] = rand() % 60 + 1;
	} while (!verificaNumRepetido2(v,c,m));
}
void printBolasExtra(int* v, int c) {
	cout << "=================================================================================" << endl << "|";
	for (int i = 0; i < c+1; i++)
	{
	cout << "\t" << v[i] << "\t|";
	}
	cout << endl << "=================================================================================" << endl;

}

int main()
{
	int creditos = 100;
	srand(time(0));

	int cLin = 3, cCol = 5;		// "c" significa cartao, logo linhas e colunas da matriz cartao
	int bLin = 6, bCol = 5;		// "b" para bolas, logo linhas e colunas da matriz bolas

	int** cartao = new int* [cLin];
	int** bolas = new int* [bLin];
	criaMatriz(cartao, cLin, cCol);
	criaMatriz(bolas, bLin, bCol);
	string asd;
	cout << "Gerando novo cartao\nPressione qualquer tecla para comecar.";
	getline(cin, asd);
	do
	{		
		creditos--;
		preencheMatriz(cartao, 3, 5);
		preencheMatriz(bolas, 6, 5);
		matrizAscendente(bolas, 6, 5);// organizar a matriz irá ajudar a verificar as bolas que sairam e comparar com o cartao

		cout << "\n\t\t\t\t      CARTAO\n";
		printMatriz(cartao, 3, 5);
		cout << "\n\t\t\t\t       BOLAS\n";
		printMatriz(bolas, 6, 5);

		int premioUm = verificaPremioUm(cartao, 3, 5, bolas, 6, 5);
		creditos = ganhaPremioUm(premioUm, creditos);

		int premioDois = verificaPremioDois(cartao, 3, 5, bolas, 6, 5);
		creditos = ganhaPremioDois(premioDois, creditos);	
		cout << "\n\nTem agora " << creditos << " creditos.";

		// CHALLENGE 4

		int count = 0;
		int* bolExtra = new int[5];
		string continuar = "s";
		do
		{
			int premioUmV2 = premioUm;
			int premioDoisV2 = premioDois;
			cout << "\nPressione 's' para comprar bolas adicionais.";
			getline(cin, continuar);
			if (continuar == "s" && creditos > 0)
			{
				creditos--;
				adicionaBola(bolExtra, count, bolas);
				cout << "\n\t\t\t\t      CARTAO\n";
				printMatriz(cartao, 3, 5);
				cout << "\n\t\t\t\t       BOLAS\n";
				printBolasExtra(bolExtra, count);
				printMatriz(bolas, 6, 5);
				premioUmV2 += verificaPremioUmV2(cartao, 3, 5, bolExtra, count);
				creditos = ganhaPremioUm(premioUmV2, creditos);
				premioDoisV2 += verificaPremioDoisV2(cartao, 3, 5, bolExtra, count);
				creditos = ganhaPremioDois(premioDoisV2, creditos);
				cout << "\n\nTem agora " << creditos << " creditos.";
				count++;
			}
			if (creditos==0)
			{
				cout << "\nCreditos insuficientes.";
				continuar = "n";
			}
			if (count==5)
			{
				continuar = "n";
			}
		} while (continuar == "s");

		string aux;		
		cout << "\nGerando novo cartao\nPressione qualquer tecla para continuar.";
		getline(cin, aux);
	} while (creditos > 0);
	
	cout << "\nFicou sem creditos, melhor sorte para a proxima!\n\n";
}

