#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular densidade populacional
float calcular_densidade(unsigned long int populacao, float area) {
    return populacao / area;
}

// Função para calcular PIB per capita
float calcular_pib_per_capita(double pib, unsigned long int populacao) {
    return pib / populacao;
}

// Função para calcular Super Poder
float calcular_super_poder(Carta c) {
    float inverso_densidade = 1.0 / c.densidade_populacional;
    return (float)c.populacao + c.area + (float)c.pib + (float)c.pontos_turisticos + c.pib_per_capita + inverso_densidade;
}

// Função para ler os dados de uma carta
void ler_carta(Carta *c) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", c->estado);
    printf("Digite o código: ");
    scanf("%d", &c->codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", c->nome);
    printf("Digite a população: ");
    scanf("%lu", &c->populacao);
    printf("Digite a área: ");
    scanf("%f", &c->area);
    printf("Digite o PIB: ");
    scanf("%lf", &c->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);

    // Cálculos
    c->densidade_populacional = calcular_densidade(c->populacao, c->area);
    c->pib_per_capita = calcular_pib_per_capita(c->pib, c->populacao);
    c->super_poder = calcular_super_poder(*c);
}

// Função para comparar dois atributos e imprimir o resultado
void comparar(char *atributo, float valor1, float valor2, int menor_vence) {
    int resultado = 0;
    if (menor_vence) {
        resultado = valor1 < valor2 ? 1 : 0;
    } else {
        resultado = valor1 > valor2 ? 1 : 0;
    }
    printf("%s: Carta %d venceu (%d)\n", atributo, resultado ? 1 : 2, resultado);
}

int main() {
    Carta c1, c2;

    printf("=== Digite os dados da Carta 1 ===\n");
    ler_carta(&c1);

    printf("\n=== Digite os dados da Carta 2 ===\n");
    ler_carta(&c2);

    printf("\n=== Comparação de Cartas ===\n");

    comparar("População", (float)c1.populacao, (float)c2.populacao, 0);
    comparar("Área", c1.area, c2.area, 0);
    comparar("PIB", (float)c1.pib, (float)c2.pib, 0);
    comparar("Pontos Turísticos", (float)c1.pontos_turisticos, (float)c2.pontos_turisticos, 0);
    comparar("Densidade Populacional", c1.densidade_populacional, c2.densidade_populacional, 1);
    comparar("PIB per Capita", c1.pib_per_capita, c2.pib_per_capita, 0);
    comparar("Super Poder", c1.super_poder, c2.super_poder, 0);

    return 0;
}