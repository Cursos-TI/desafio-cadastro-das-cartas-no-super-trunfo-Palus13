#include <stdio.h>

// Desafio Super Trunfo - Países - NOVATO
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

/* Teste Ighor de Souza Ribeiro
A ideia será estruturar as variáveis cidade e país
Cada país terá 4 cidades
Cada cidade terá os atributos estipulados no desafio
Feitos os cálculos de densidade populacional, PIB per capita e super poder
Será incluída a possibilidade do usuário verificar os dados e editar as informações
Será incluída a possibilidade do usuário iniciar o jogo, comparando as cartas
*/

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
    float superpoder;
};

// Definição da estrutura Pais
struct pais {
    char nome[20];
    struct cidade cidades[4];
};

// Declaração de um array de 8 estruturas pais
struct pais paises[8];

// Criada função de comparação de cartas de modo a manter o código mais limpo e organizado
// criadas variáveis estruturadas cidade1 e cidade2 para comparação
// criadas variáveis para contagem de vitórias de cada cidade

void compararCartas(struct cidade cidade1, struct cidade cidade2) {
    int vitoriasCidade1 = 0;
    int vitoriasCidade2 = 0;

    printf("Comparando as cartas:\n");

    // Comparar população
    if (cidade1.populacao > cidade2.populacao) {
        printf("População: %s vence\n", cidade1.nome);
        vitoriasCidade1++;
    } else if (cidade1.populacao < cidade2.populacao) {
        printf("População: %s vence\n", cidade2.nome);
        vitoriasCidade2++;
    } else {
        printf("População: Empate\n");
    }

    // Comparar área
    if (cidade1.area > cidade2.area) {
        printf("Área: %s vence\n", cidade1.nome);
        vitoriasCidade1++;
    } else if (cidade1.area < cidade2.area) {
        printf("Área: %s vence\n", cidade2.nome);
        vitoriasCidade2++;
    } else {
        printf("Área: Empate\n");
    }

    // Comparar PIB
    if (cidade1.pib > cidade2.pib) {
        printf("PIB: %s vence\n", cidade1.nome);
        vitoriasCidade1++;
    } else if (cidade1.pib < cidade2.pib) {
        printf("PIB: %s vence\n", cidade2.nome);
        vitoriasCidade2++;
    } else {
        printf("PIB: Empate\n");
    }

    // Comparar pontos turísticos
    if (cidade1.pontosturisticos > cidade2.pontosturisticos) {
        printf("Pontos Turísticos: %s vence\n", cidade1.nome);
        vitoriasCidade1++;
    } else if (cidade1.pontosturisticos < cidade2.pontosturisticos) {
        printf("Pontos Turísticos: %s vence\n", cidade2.nome);
        vitoriasCidade2++;
    } else {
        printf("Pontos Turísticos: Empate\n");
    }

    // Comparar densidade populacional (menor ganha)
    if (cidade1.densidadepopulacional < cidade2.densidadepopulacional) {
        printf("Densidade Populacional: %s vence\n", cidade1.nome);
        vitoriasCidade1++;
    } else if (cidade1.densidadepopulacional > cidade2.densidadepopulacional) {
        printf("Densidade Populacional: %s vence\n", cidade2.nome);
        vitoriasCidade2++;
    } else {
        printf("Densidade Populacional: Empate\n");
    }

    // Comparar PIB per capita
    if (cidade1.pibpercapita > cidade2.pibpercapita) {
        printf("PIB per Capita: %s vence\n", cidade1.nome);
        vitoriasCidade1++;
    } else if (cidade1.pibpercapita < cidade2.pibpercapita) {
        printf("PIB per Capita: %s vence\n", cidade2.nome);
        vitoriasCidade2++;
    } else {
        printf("PIB per Capita: Empate\n");
    }

    // Comparar super poder
    if (cidade1.superpoder > cidade2.superpoder) {
        printf("Super Poder: %s vence\n", cidade1.nome);
        vitoriasCidade1++;
    } else if (cidade1.superpoder < cidade2.superpoder) {
        printf("Super Poder: %s vence\n", cidade2.nome);
        vitoriasCidade2++;
    } else {
        printf("Super Poder: Empate\n");
    }

    // Determinar a carta vencedora no geral
    if (vitoriasCidade1 > vitoriasCidade2) {
        printf("A carta vencedora no geral é: %s\n", cidade1.nome);
    } else if (vitoriasCidade1 < vitoriasCidade2) {
        printf("A carta vencedora no geral é: %s\n", cidade2.nome);
    } else {
        printf("Empate geral\n");
    }
}

int main() {
    printf("********** Desafio Super Trunfo - Países **********\n\n");

    // Início do cadastro das cartas
    // Foi utilizada a função "for" com as variaveis inteiras i e j para realizar o looping do cadastro
    // Além disso, elas servirão de apoio para a incrição dos códigos das cartas
    // Inicialmente, será cadastrado o país e, em seguida, as cidades desse país, com todas suas informações
    for (int i = 0; i < 8; i++) {
        printf("Cadastro do país %d:\n", i + 1);
        printf("Digite o nome do país %d:\n", i + 1);
        scanf("%19s", paises[i].nome);

        for (int j = 0; j < 4; j++) {
            // A instrução a seguir irá determinar o código da cidade
            snprintf(paises[i].cidades[j].codigo, sizeof(paises[i].cidades[j].codigo), "%c%02d", 'A' + i, j + 1);

            // Copiar o nome do país para a cidade
            snprintf(paises[i].cidades[j].pais, sizeof(paises[i].cidades[j].pais), "%s", paises[i].nome);

            // Informa qual cidade será cadastrada
            printf("Cadastro da cidade %d do país %s:\n", j + 1, paises[i].nome);

            // Informa o código da cidade
            printf("Código da cidade: %s\n", paises[i].cidades[j].codigo);

            // Solicita as informações da cidade - foram utilizadas essas ordens de grandeza para ser algo mais palpável no calculo do super poder
            printf("Digite o nome da cidade: \n");
            scanf("%19s", paises[i].cidades[j].nome);
            printf("Digite a população da cidade em milhoes de habitantes: \n");
            scanf("%f", &paises[i].cidades[j].populacao);
            printf("Digite a área da cidade em milhares de km2: \n");
            scanf("%f", &paises[i].cidades[j].area);
            printf("Digite o PIB da cidade em bilhoes de dolares: \n");
            scanf("%f", &paises[i].cidades[j].pib);
            printf("Digite o número de pontos turísticos da cidade: \n");
            scanf("%d", &paises[i].cidades[j].pontosturisticos);
            printf("\n");

            // Cálculo a densidade populacional da cidade - habitantes por km2
            paises[i].cidades[j].densidadepopulacional = paises[i].cidades[j].populacao / paises[i].cidades[j].area / 1000;

            // Cálculo do PIB per capita da cidade - PIB em dólares por habitante
            paises[i].cidades[j].pibpercapita = paises[i].cidades[j].pib / paises[i].cidades[j].populacao * 1000;

            /*
            Será realizado o cálculo do super poder da cidade
            O superpoder consiste na soma de todos os atributos da cidade menos a densidade populacional
            Foi utilizado esse raciocínio, pois a densidade populacional é um fator negativo para a cidade, como na comparação
            */
            paises[i].cidades[j].superpoder = paises[i].cidades[j].populacao + paises[i].cidades[j].area + paises[i].cidades[j].pib + paises[i].cidades[j].pontosturisticos - paises[i].cidades[j].densidadepopulacional;
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
            printf("Super Poder: %.2f\n", paises[i].cidades[j].superpoder);
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
            scanf("%d", &paisIndex);
            printf("Digite o número da cidade (1-4): \n");
            scanf("%d", &cidadeIndex);

            paisIndex--; // Ajuste do índice do array
            cidadeIndex--; // Ajustar do índice do array

            // Solicita as informações da cidade novamente
            printf("Digite o nome da cidade: \n");
            scanf("%19s", paises[paisIndex].cidades[cidadeIndex].nome);
            printf("Digite a população da cidade em milhoes de habitantes: \n");
            scanf("%f", &paises[paisIndex].cidades[cidadeIndex].populacao);
            printf("Digite a área da cidade em milhoes de km2: \n");
            scanf("%f", &paises[paisIndex].cidades[cidadeIndex].area);
            printf("Digite o PIB da cidade em milhoes de dolares: \n");
            scanf("%f", &paises[paisIndex].cidades[cidadeIndex].pib);
            printf("Digite o número de pontos turísticos da cidade: \n");
            scanf("%d", &paises[paisIndex].cidades[cidadeIndex].pontosturisticos);
            printf("\n");
        }
    } while (opcao == 's' || opcao == 'S');

    // Comparação de cartas

    // Após a coleta de dados, será incluída a possibilidade do usuário comparar as cartas e iniciar o jogo
    char opcaoComparar;
    do {
        printf("Vamos iniciar o jogo? Digite 's' ou 'n': ");
        scanf(" %c", &opcaoComparar);

        if (opcaoComparar == 's' || opcaoComparar == 'S') {
            // Serão criadas as variáveis "Index" para ajuste do índice do array das cidades
            int paisIndex1, cidadeIndex1, paisIndex2, cidadeIndex2;

            printf("Digite o número do primeiro país (1-8): \n");
            scanf("%d", &paisIndex1);
            printf("Digite o número da primeira cidade (1-4): \n");
            scanf("%d", &cidadeIndex1);

            printf("Digite o número do segundo país (1-8): \n");
            scanf("%d", &paisIndex2);
            printf("Digite o número da segunda cidade (1-4): \n");
            scanf("%d", &cidadeIndex2);

            paisIndex1--; // Ajuste do índice do array
            cidadeIndex1--; // Ajuste do índice do array
            paisIndex2--; // Ajuste do índice do array
            cidadeIndex2--; // Ajuste do índice do array

            // Realizada a chamada de funções com os índices informados
            compararCartas(paises[paisIndex1].cidades[cidadeIndex1], paises[paisIndex2].cidades[cidadeIndex2]);
        }
    } while (opcaoComparar == 's' || opcaoComparar == 'S');

    printf("Obrigado por jogar o Super Trunfo de Países!\n");

    return 0;
}
