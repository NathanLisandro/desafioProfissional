#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "C:\sqlite\lib\sqlite3.h"

int main() {
    char modelo[25];
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *stmt;
int idadeDoVeiculo;
    int rc = sqlite3_open("bancodedados.db", &db);
    if (rc) {
        fprintf(stderr, "Erro ao abrir o banco de dados: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
/*

    CÓDIGO CRIAÇÃO DA TABELA

    char *sql = "CREATE TABLE Veiculo ( id_veiculo INT PRIMARY KEY, modelo VARCHAR(50) NOT NULL, ano_fabricacao INT NOT NULL, placa VARCHAR(10) NOT NULL, quilometragem_rodada FLOAT, idade_veiculo INT ); CREATE TABLE Motorista ( id_motorista INT PRIMARY KEY, nome VARCHAR(50) NOT NULL, cpf VARCHAR(14) NOT NULL, num_habilitacao VARCHAR(10) NOT NULL, categoria_habilitacao VARCHAR(2) NOT NULL, validade_habilitacao DATE NOT NULL ); CREATE TABLE Viagem ( id_viagem INT PRIMARY KEY, data_viagem DATE NOT NULL, id_veiculo INT NOT NULL, id_motorista INT NOT NULL, destino VARCHAR(100) NOT NULL, quilometragem_percorrida FLOAT NOT NULL, FOREIGN KEY (id_veiculo) REFERENCES Veiculo(id_veiculo), FOREIGN KEY (id_motorista) REFERENCES Motorista(id_motorista) ); CREATE TABLE RelatorioVeiculo ( id_relatorio INT PRIMARY KEY, id_veiculo INT NOT NULL, idade_veiculo INT NOT NULL, quilometragem_rodada FLOAT NOT NULL, FOREIGN KEY (id_veiculo) REFERENCES Veiculo(id_veiculo) ); CREATE TABLE RelatorioMotorista ( id_relatorio INT PRIMARY KEY, id_motorista INT NOT NULL, nome VARCHAR(50) NOT NULL, cpf VARCHAR(14) NOT NULL, num_habilitacao VARCHAR(10) NOT NULL, categoria_habilitacao VARCHAR(2) NOT NULL, validade_habilitacao DATE NOT NULL, FOREIGN KEY (id_motorista) REFERENCES Motorista(id_motorista) ); CREATE TABLE DiarioBordo ( id_diario INT PRIMARY KEY, id_veiculo INT NOT NULL, data_viagem DATE NOT NULL, quilometragem_percorrida FLOAT NOT NULL, FOREIGN KEY (id_veiculo) REFERENCES Veiculo(id_veiculo) );";
    rc = sqlite3_exec(db, sql, NULL, NULL, &err_msg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "Erro ao criar a tabela: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
*/
    sqlite3_close(db);
    return 0;



    time_t dataDeHoje = time(NULL);
    setlocale(0, "Portuguese");
    int escolhaNumero = 0;
    int contador,idVeiculo, dataViagem, anodeFabricacao, anoValidade, mesValidade, diaValidade,
    tamanhocpf;
    float kmRodado, quilometragemP;
    int diaAtual = 11;
    int mesAtual = 04;
    int anoAtual = 2023;
    char nome[50];
    char placaDoVeiculo[10];
    char cpfMotorista[12];
    char num_habilitacao[11];
    char categoriacnh[2];
    char motorizacao[20];
    char combustivel[20];
    char desejaContinuar[2];
    contador = 0;
    cpfMotorista[12] = '\0';
    char email[50] = "agente01@empresa.com";
    char senha[20] = "agente01";
    char login[50];
    char *errMsg;
    char *sql;
do {
    do {
        printf("Escolha uma das opções abaixo: \n");
        printf("1 - Cadastro de novo usuário\n");
        printf("2 - Cadastro de veículos\n"); 
        printf("3 - Fazer login\n");
        printf("4 - Cadastrar novo diário de bordo\n");

        scanf("%d", &escolhaNumero);
        fflush(stdin);
        system("cls");
    } while (escolhaNumero < 1 || escolhaNumero > 4);

    switch(escolhaNumero){
        // cadastro motorista
        case 1:
            printf("Digite o nome do motorista: ");
            scanf("%s", nome); 
             printf("\nCPF do motorista: ");
    do{
        fgets(cpfMotorista, sizeof(cpfMotorista), stdin);
        tamanhocpf = strlen(cpfMotorista) - 1; // subtrair 1 para desconsiderar o caractere de quebra de linha (\n)
    } while (tamanhocpf != 11);
            printf("\nNúmero da CNH:");
            scanf("%s", num_habilitacao); 
            printf("Categoria da CNH:");
            scanf("%s", categoriacnh); 
            // DATA
            printf("\nAno de validade:");
            scanf("%d", &anoValidade);
            do {
            printf("\nMês de validade");
            scanf("%d", &mesValidade);        

  char *sql = "INSERT INTO Motorista (nome, cpf, num_habilitacao, categoria_hablitacao, validade_habilitacao) VALUES (?, ?, ?, ?, ?)";
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
        sqlite3_bind_text(stmt, 1, nome, -1, SQLITE_TRANSIENT);   
        sqlite3_bind_text(stmt, 2, cpfMotorista, -1, SQLITE_TRANSIENT);    
        sqlite3_bind_text(stmt, 3, num_habilitacao, -1, SQLITE_TRANSIENT); 
        sqlite3_bind_text(stmt, 4, categoriacnh, -1, SQLITE_TRANSIENT); 
        sqlite3_bind_text(stmt, 5, anoValidade, -1, SQLITE_TRANSIENT); 

            } while(mesValidade < 1 || mesValidade >12);
            do {
            printf("Digite o dia de validade: ");
            scanf("%d", &diaValidade);
            }while(diaValidade > 31 || diaValidade < 1);
            if(diaValidade < diaAtual && mesValidade < mesAtual && anoValidade < anoAtual || mesValidade < mesAtual && anoValidade < anoAtual){
                printf("Motorista não cadastrado! A habilitação está vencida!");

            } else {
                printf("motorista cadastrado do sucesso!");
            }
          
            break; // Adicionar um break statement para finalizar o case 1
// cadastro veiculos
        case 2:
            printf("*CADASTRO DE VEÍCULOS *\n");
            printf("Modelo do veículo: ");
            scanf("%d", modelo);
            do{
            printf("\nKM rodados: ");
            scanf("%f", &kmRodado); 
            }while(kmRodado < 0.0);
            printf("\nDigite o ano de fabricação: ");
            scanf("%d", &anodeFabricacao);
            printf("\nDigite a placa do veículo");
            scanf("%s", &placaDoVeiculo); 
            printf("\nIdade do veiculo: ");
            scanf("%s", idadeDoVeiculo);

            char *sql = "INSERT INTO Veiculo (modelo, ano_fabricacao, placa, quilometragem_rodada, idade_veiculo) VALUES (?, ?, ?, ?, ?)";
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
        sqlite3_bind_text(stmt, 1, modelo, -1, SQLITE_TRANSIENT);   
        sqlite3_bind_int(stmt, 2, anodeFabricacao);    
        sqlite3_bind_text(stmt, 3, placaDoVeiculo, -1, SQLITE_TRANSIENT); 
        sqlite3_bind_double(stmt, 4, kmRodado); 
        sqlite3_bind_int(stmt, 5, idadeDoVeiculo); 
            break; 

// sistema de login
        case 3:
                do{
                printf("Digite seu login: ");
                scanf("%s", login);
                printf("Digite sua senha: ");
                scanf("%s", senha);
                }while (strcmp(login, "agente01@empresa.com") != 0 || strcmp(senha, "agente01") != 0);
            break;
// diario de bordo
        case 4:
          printf("*DIÁRIO DE BORDO*");
          printf("Digite o ID do veículo: ");
          scanf("%d", idVeiculo);
          printf("Data da viagem:");
          scanf("%d", dataViagem);
          do {
          printf("Quilometragem Percorrida: ");
          scanf("%f", quilometragemP);
    }while(quilometragemP < 0.0);
        printf("Diário de bordo cadastrado e veículo atualizado!");

        char *sql1 = "INSERT INTO Veiculo (idVeiculo, data_viagem, quilometragem_percorrida) VALUES (?, ?, ?, ?)";
  rc = sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
        sqlite3_bind_int(stmt, 1, idVeiculo);   
        sqlite3_bind_int(stmt, 2, dataViagem);    
        sqlite3_bind_float(stmt, 3, quilometragemP, -1, SQLITE_TRANSIENT); 
      break;
    
    }
    printf("Deseja continuar ? (S/N)");
    scanf("%c", desejaContinuar);
} while (desejaContinuar[0] == 'S');
    return 0;
}
