#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	//Variáveis
	string marca[10];
	string modelo[10];
	string placa[10];
	int anoNumero[10];
	int anoNumeroCadastro = 0;
	int anoConsulta = 0;
	int quantidade = 0;
	int menuNumero = 0;
	string marcaCadastro = "";
	string modeloCadastro = "";
	string placaCadastro = "XXX-YYYY";
	string modeloConsulta = "";
	string menu = "";
	string comando = "";
	bool anoConsultaEncontrado = false;
	bool anoCertoConsulta = false;
	bool menuCerto = false;
	bool anoCerto = false;
	bool placaCerta = false;
	bool comandoCerto = false;
	bool programaLigado = true;
	bool modeloEncontrado = false;
	bool cadastrou = false;

	//While que mantem o programa ligado
	while (programaLigado == true)
	{
		//While para o usuário escolher uma das opções do menu
		while (menuCerto == false)
		{
			cout << " ------------- \n";
			cout << "| Carros Menu | \n";
			cout << " ------------- \n";
			cout << "";

			cout << "Escolha uma opção do Menu: \n";
			cout << "\n";

			cout << "(1) Inserir um novo veículo \n";
			cout << "(2) Listar veículos cadastrados \n";
			cout << "(3) Listar veículos filtrando pelo ano de fabricação \n";
			cout << "(4) Informar um ano para listar veículos acima do ano de fabricação informado \n";
			cout << "(5) Listar veículos pelo modelo \n";

			cin >> menu;

			//Confere se o caracter digitado corrsponde a uma das opções de menu
			if ((menu != "1") && (menu != "2") && (menu != "3") && (menu != "4") && (menu != "5"))
			{
				system("cls");
				menuCerto = false;
			}
			else
			{
				if (quantidade == 10 && menu == "1")
				{
					cout << "Número máximo de cadastro atingido! \n";
					cout << "\n";
					menuCerto = false;
				}
				else
				{
					menuCerto = true;
					menuNumero = stoi(menu);
					system("cls");
				}
			}
		}

		//Switch para executar o que foi escolhido pelo usuário
		switch (menuNumero)
		{
			case 1:
				cout << " ------------------------- \n";
				cout << "| Inserir um novo veículo | \n";
				cout << " ------------------------- \n";
				cout << "\n";

				cout << "Digite a marca do veículo: \n";
				cin >> marcaCadastro;
				cout << "\n";

				cout << "Digite o modelo do veículo: \n";
				cin >> modeloCadastro;
				cout << "\n";

				//While para verificar se o ano está certo
				while (anoCerto == false)
				{
					cout << "Digite o ano de fabricação do veículo: \n";

					try
					{
						cin >> anoNumeroCadastro;
						cout << "\n";

						if (anoNumeroCadastro > 1900 && anoNumeroCadastro < 2100)
						{
							anoCerto = true;
						}
						else
						{
							cout << "O ano deve estar no formato AAAA \n";
							cout << "\n";
							anoCerto = false;
						}
					}
					catch(exception)
					{
						cout << "Ano digitado inválido! \n";
						cout << "\n";
						anoCerto = false;
					}
				}

				//While para verificar se a placa esta certa
				while (placaCerta == false)
				{
					cout << "Digite a placa do veículo: \n";
					cin >> placaCadastro;
					cout << "\n";

					if (placaCadastro[3] == '-')
					{
						placaCerta = true;
					}
					else
					{
						cout << "A placa deve estar no seguinte formato : XXX-YYYY \n";
						cout << "\n";
						placaCerta = false;
					}
				}

				//Se for a primeira inserção de veículo, o programa insere na primeira posição
				if (quantidade == 0)
				{
					marca[quantidade] = marcaCadastro;
					modelo[quantidade] = modeloCadastro;
					anoNumero[quantidade] = anoNumeroCadastro;
					placa[quantidade] = placaCadastro;

					cadastrou = true;
				}

				//Caso não seja a primeira inserção, o programa entra nesse if para colocar o veículo em ordem crescente (ano)
				if (quantidade != 0)
				{
					int decremento = quantidade;

					for (int i = 0; i < quantidade; i++)
					{
						if (anoNumeroCadastro < anoNumero[i])
						{
							for (int j = quantidade - 1; j >= i; j--)
							{
								marca[decremento] = marca[j];
								modelo[decremento] = modelo[j];
								anoNumero[decremento] = anoNumero[j];
								placa[decremento] = placa[j];

								decremento = decremento - 1;
							}
							marca[i] = marcaCadastro;
							modelo[i] = modeloCadastro;
							anoNumero[i] = anoNumeroCadastro;
							placa[i] = placaCadastro;

							i = quantidade;
							cadastrou = true;
						}
					}
				}

				//Se nenhum veículo da lista era maior que o veículo a ser inserido, o if abaixo insere o veículo na ultima posição
				if (cadastrou == false)
				{
					marca[quantidade] = marcaCadastro;
					modelo[quantidade] = modeloCadastro;
					anoNumero[quantidade] = anoNumeroCadastro;
					placa[quantidade] = placaCadastro;
				}

				//Mostra na tela que o veículo foi inserido com sucesso
				cout << "Novo veículo inserido com sucesso! \n";
				cout << "\n";
				cout << "Marca: " << marcaCadastro << "\n";
				cout << "Modelo: " << modeloCadastro << "\n";
				cout << "Ano de Fabricação: " << anoNumeroCadastro;
				cout << "\nPlaca: " << placaCadastro << "\n";
				cout << "\n";
				quantidade++;
				break;

			case 2:
				cout << " ------------------- \n";
				cout << "| Lista de veículos | \n";
				cout << " ------------------- \n";
				cout << "\n";

				//For para listar todos os veículos cadastrados
				for (int i = 0; i < quantidade; i++)
				{
					cout << "[Veículo " << (i + 1) << ']';
					cout << "\nMarca:  " << marca[i] << "\n";
					cout << "Modelo: " << modelo[i] << "\n";
					cout << "Ano:    " << anoNumero[i];
					cout << "\nPlaca:  " << placa[i] << "\n";
					cout << "--------------------------- \n";
				}
				break;

			case 3:
				cout << " ------------------------------------------ \n";
				cout << "| Lista de veículos pelo ano de fabricação | \n";
				cout << " ------------------------------------------ \n";
				cout << "\n";

				//While para verificar se o ano está certo
				while (anoCertoConsulta == false)
				{
					cout << "Digite o ano de fabricação desejado: \n";
					try
					{
						cin >> anoConsulta;
						anoCertoConsulta = true;
						cout << "\n";
					}
					catch (exception)
					{
						cout << "Ano inválido: \n";
						cout << "\n";
						anoCertoConsulta = false;
					}
				}

				//For para listar veículos cadastrados conforme ano digitado
				for (int i = 0; i < quantidade; i++)
				{
					if (anoConsulta == anoNumero[i])
					{
						cout << "[Veículo " << (i + 1) << ']';
						cout << "\nMarca:  " << marca[i] << "\n";
						cout << "Modelo: " << modelo[i] << "\n";
						cout << "Ano:    " << anoNumero[i];
						cout << "\nPlaca:  " << placa[i] << "\n";
						cout << "--------------------------- \n";
						anoConsultaEncontrado = true;
					}
				}

				//If para se não houver veículo com o ano digitado
				if (anoConsultaEncontrado == false)
				{
					cout << "\nNenhum veículo encontrado com o ano: " << anoConsulta;
					cout << "\n";
				}
				break;

			case 4:
				cout << " ---------------------------------------------- \n";
				cout << "| Lista de veículos acima do ano de fabricação | \n";
				cout << " ---------------------------------------------- \n";
				cout << "\n";

				//While para verificar se o ano está certo
				while (anoCertoConsulta == false)
				{
					cout << "Digite o ano de fabricação desejado: \n";
					try
					{
						cin >> anoConsulta;
						cout << "\n";
						anoCertoConsulta = true;
					}
					catch (exception)
					{
						cout << "Ano inválido: \n";
						cout << "\n";
						anoCertoConsulta = false;
					}
				}

				//For para listar os veículos cadastrados conforme ano digitado
				for (int i = 0; i < quantidade; i++)
				{
					if (anoNumero[i] >= anoConsulta)
					{
						cout << "[Veículo " << (i + 1) << ']';
						cout << "\nMarca:  " << marca[i] << "\n";
						cout << "Modelo: " << modelo[i] << "\n";
						cout << "Ano:    " << anoNumero[i];
						cout << "\nPlaca:  " << placa[i] << "\n";
						cout << "--------------------------- \n";
						anoConsultaEncontrado = true;
					}
				}

				//If para se caso não houver veículo acima do ano digitado
				if (anoConsultaEncontrado == false)
				{
					cout << "\nNenhum veículo encontrado acima do ano: " << anoConsulta;
					cout << "\n";
				}
				break;

			case 5:
				cout << " ------------------------------ \n";
				cout << "| Lista de veículos por modelo | \n";
				cout << " ------------------------------ \n";
				cout << "";

				cout << "Digite o modelo desejado: \n";
				cin >> modeloConsulta;
				cout << "\n";

				//For para listar veículos do modelo digitado
				for (int i = 0; i < quantidade; i++)
				{
					if (modelo[i] == modeloConsulta)
					{
						cout << "[Veículo " << (i + 1) << ']';
						cout << "\nMarca:  " << marca[i] << "\n";
						cout << "Modelo: " << modelo[i] << "\n";
						cout << "Ano:    " << anoNumero[i];
						cout << "\nPlaca:  " << placa[i] << "\n";
						cout << "--------------------------- \n";
						modeloEncontrado = true;
					}
				}

				//If para se caso não houver veículo com o modelo digitado
				if (modeloEncontrado == false)
				{
					cout << "Nenhum veículo encontrado com o modelo: " << modeloConsulta << "\n";
				}
				break;
		}

		//While para verificar se o usuário deseja fazer mais alguma coisa
		while (comandoCerto == false)
		{
			cout << "\n";
			cout << "Deseja fazer mais alguma coisa? \n";
			cout << "\n";
			cout << "(S) Sim \n";
			cout << "(N) Não \n";
			cin >> comando;
			cout << "\n";

			if ((comando == "s") || (comando == "S") || (comando == "n") || (comando == "N"))
			{
				comandoCerto = true;
			}
			else
			{
				comandoCerto = false;
			}
		}

		//Caso o usuário deseje fazer mais alguma coisa, as variáveis abaixo são configuradas para mais uma execução
		if ((comando == "s") || (comando == "S"))
		{
			system("cls");
			programaLigado = true;
			menu = "";
			menuCerto = false;
			anoCerto = false;
			placaCerta = false;
			comandoCerto = false;
			anoConsultaEncontrado = false;
			anoCertoConsulta = false;
			modeloEncontrado = false;
			cadastrou = false;
		}
		else
		{
			//Caso o usuário não deseja fazer mais nada no sistema, o mesmo agradece e sai do While que mantem o programa ligado
			system("cls");
			programaLigado = false;
			cout << " ------------- \n";
			cout << "| Carros Sair | \n";
			cout << " ------------- \n";
			cout << "\n";
			cout << "Obrigado por usar nosso programa. Digite qualquer tecla para sair. \n";
		}
	}
	getchar();
}
