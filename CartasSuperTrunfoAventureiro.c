#include <stdio.h>

// Desafio Super Trunfo - Países - NOVATO
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

/* Teste Ighor de Souza Ribeiro
A ideia será estruturar as variáveis cidade e país
Cada país terá 4 cidades
Cada cidade terá os atributos estipulados no desafio
*/

int main() {

// Definição da estrutura cidade
struct cidade {
    char pais[20];
    char codigo[4];
    char nome[20];
    float populacao;
    float area;
    float pib;
    int pontosturisticos;
    float densidadepopulacional;
    float pibpercapita;
};

// Definição da estrutura Pais
struct pais {
    char nome[20];
    struct cidade cidades[4];
};

// Declaração de um array de 8 estruturas pais
struct pais paises[8];

printf("********** Desafio Super Trunfo - Países **********\n\n");
/* Início do cadastro das cartas
Foi utilizada a função "for" com as variaveis inteiras i e j para realizar o looping do cadastro
Além disso, elas servirão de apoio para a incrição dos códigos das cartas
Inicialmente, será cadastrado o país e, em seguida, as cidades desse país, com todas suas informações
*/
for (int i = 0; i < 8; i++) {
    printf("Cadastro do país %d:\n", i + 1);
    printf("Digite o nome do país %d:\n", i + 1);
    scanf("%s", paises[i].nome);

    for (int j = 0; j < 4; j++) {
        // A formula a seguir irá determinar o código da cidade e escrevê-lo
        snprintf(paises[i].cidades[j].codigo, sizeof(paises[i].cidades[j].codigo), "%c%02d", 'A' + i, j + 1);

        // Copiar o nome do país para a cidade
        snprintf(paises[i].cidades[j].pais, sizeof(paises[i].cidades[j].pais), "%s", paises[i].nome);

        // Informa qual cidade será cadastrada
        printf("Cadastro da cidade %d do país %s:\n", j + 1, paises[i].nome);

        // Informa o código da cidade
        printf("Código da cidade: %s\n", paises[i].cidades[j].codigo);

        // Solicita as informações da cidade - foram utilizadas essas ordens de grandeza para ser algo mais palpável no calculo do super poder
        printf("Digite o nome da cidade: ");
        scanf(" %s", paises[i].cidades[j].nome);
        printf("Digite a população da cidade em milhoes de habitantes: ");
        scanf(" %f", &paises[i].cidades[j].populacao);
        printf("Digite a área da cidade em milhares de km2: ");
        scanf(" %f", &paises[i].cidades[j].area);
        printf("Digite o PIB da cidade em bilhoes de dolares: ");
        scanf(" %f", &paises[i].cidades[j].pib);
        printf("Digite o número de pontos turísticos da cidade: ");
        scanf(" %d", &paises[i].cidades[j].pontosturisticos);
        printf("\n");

        // Cálculo a densidade populacional da cidade - habitantes por km2
        paises[i].cidades[j].densidadepopulacional = paises[i].cidades[j].populacao / paises[i].cidades[j].area / 1000;

        // Cálculo do PIB per capita da cidade - PIB em dólares por habitante
        paises[i].cidades[j].pibpercapita = paises[i].cidades[j].pib / paises[i].cidades[j].populacao * 1000;
    }
}

// Após toda a coleta de dados, será exibido o resultado, também utilizando a função "for"
for (int i = 0; i < 8; i++) {
    printf("Dados do País %d:\n", i + 1);
    printf("Nome do País: %s\n", paises[i].nome);

    for (int j = 0; j < 4; j++) {
        printf("Dados da Cidade %d do País %s:\n", j + 1, paises[i].nome);
        printf("Código: %s\n", paises[i].cidades[j].codigo);
        printf("Nome: %s\n", paises[i].cidades[j].nome);
        printf("População: %f milhoes de habitantes\n", paises[i].cidades[j].populacao);
        printf("Área: %.2f milhares de km2\n", paises[i].cidades[j].area);
        printf("PIB: %.2f bilhoes de dolares\n", paises[i].cidades[j].pib);
        printf("Pontos Turísticos: %d\n", paises[i].cidades[j].pontosturisticos);
        printf("Densidade Populacional: %.2f habitantes por km2\n", paises[i].cidades[j].densidadepopulacional);
        printf("PIB per Capita: %.2f dolares por habitante\n", paises[i].cidades[j].pibpercapita);
        printf("\n");
    }
}

// Será incluída a possibilidade do usuário verificar os dados e editar as informações

  
// criada uma variável opcao para indicar se deseja ou nao editar os dados
char opcao;

// utilizada a função "do while" para repetir a pergunta até responder "s"
do {
    printf("Deseja editar os dados de alguma cidade? Digite 's' ou 'n': ");
    scanf(" %c", &opcao);

    // será dada a possibilidade de responder em caixa alta ou baixa
    if (opcao == 's' || opcao == 'S') {

        // criadas as variaveis "Index" para ajuste do índice do array
        int paisIndex, cidadeIndex;
        printf("Digite o número do país (1-8): \n");
        scanf(" %d", &paisIndex);
        printf("Digite o número da cidade (1-4): \n");
        scanf(" %d", &cidadeIndex);

        paisIndex--; // Ajuste do índice do array
        cidadeIndex--; // Ajustar do índice do array

        // Solicita as informações da cidade novamente
        printf("Digite o nome da cidade: \n");
        scanf(" %s", paises[paisIndex].cidades[cidadeIndex].nome);
        printf("Digite a população da cidade em milhoes de habitantes: \n");
        scanf(" %f", &paises[paisIndex].cidades[cidadeIndex].populacao);
        printf("Digite a área da cidade em milhoes de km2: \n");
        scanf(" %f", &paises[paisIndex].cidades[cidadeIndex].area);
        printf("Digite o PIB da cidade em milhoes de dolares: \n");
        scanf(" %f", &paises[paisIndex].cidades[cidadeIndex].pib);
        printf("Digite o número de pontos turísticos da cidade: \n");
        scanf(" %d", &paises[paisIndex].cidades[cidadeIndex].pontosturisticos);
        printf("\n");
    }
} while (opcao == 's' || opcao == 'S');

return 0;
}
