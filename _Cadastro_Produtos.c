#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct do produto
struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    int opcao = 0;
    int quantidadeProdutos = 0;
    int totalProdutos = 0;
    struct Produto *produtos = NULL;
    int i;
	int j;

    while (opcao != 4) {
    	// menu do programa, depois de executar uma ação ele voltara para esse medo para que possa ser realizada outra ação
        printf("\n=============================\n");
        printf(" SISTEMA DE PRODUTOS\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Mostrar resumo\n");
        printf("3 - Buscar por codigo\n");
        printf("4 - Sair\n");
        printf("=============================\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
        	// case 1 é a parte de cadastro de produtos
            case 1:
                do {
                    printf("\nQuantos produtos deseja cadastrar (1 a 10)? ");
                    scanf("%d", &quantidadeProdutos);
                    if (quantidadeProdutos < 1 || quantidadeProdutos > 10) {
                        printf("Quantidade invalida!\n");
                    }
                } while (quantidadeProdutos < 1 || quantidadeProdutos > 10);
                struct Produto *temp = realloc(produtos,(totalProdutos + quantidadeProdutos) * sizeof(struct Produto));
				if (temp == NULL) {
				    printf("Erro ao alocar memoria!\n");
				    break;
				}
				produtos = temp;
                printf("\n===== CADASTRO DOS PRODUTOS =====\n");
				int resultado;
                for (i = totalProdutos; i < totalProdutos + quantidadeProdutos; i++) {

                    printf("\nPRODUTO %d\n", i + 1);
                    // Pede para ser inserido o codigo do produto, se o codigo não for numerico ele apresenta um erro e pede o codigo novamente
                    do{
					    printf("Codigo: ");
					    resultado = scanf("%d", &produtos[i].codigo);
					    if(resultado != 1){
					        printf("Digite apenas numeros!\n");
					        while(getchar() != '\n');
					    }
					} while(resultado != 1);
                    
                    // pede o nome do produto, usei a biblioteca string.h para possibilitar a entrada de nomes com espaço com "placa de video"
                    getchar();
                    printf("Nome: ");
					fgets(produtos[i].nome, 50, stdin);
					produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
					
					// Pede para ser inserido o preço do produto, se o preço não for numerico ele apresenta um erro e pede o preço novamente
					do{
	                    printf("Preco: ");
					    resultado = scanf("%f", &produtos[i].preco);
					    if(resultado != 1){
					        printf("Digite um valor valido!\n");
					        while(getchar() != '\n');
					    }
					} while(resultado != 1);
					
					// Pede para ser inserido o quantidade do produto, se o quantidade não for numerico ou negativo ele apresenta um erro e pede o quantidade novamente
					do{
	                    printf("Quantidade: ");
					    resultado = scanf("%d", &produtos[i].quantidade);
					    if(resultado != 1){
					        printf("Digite apenas numeros!\n");
					        while(getchar() != '\n');
					    } else if(produtos[i].quantidade < 0){
					        printf("A quantidade nao pode ser negativa!\n");
					        resultado = 0;
					    }
					} while(resultado != 1);
                }
                totalProdutos += quantidadeProdutos;
                printf("\nProdutos cadastrados com sucesso!\n");
                break;

			// case 2 apresenta o resumo dos produtos, contendo o total do estoque e o produto mais caro
            case 2:

                if (produtos == NULL) {
                    printf("\nNenhum produto cadastrado!\n");
                    break;
                }

                float valorTotalEstoque = 0;
                int indiceMaisCaro = 0;

                printf("\n=====================================\n");
                printf(" PRODUTOS CADASTRADOS\n");
                // faz a busca do produto mais caro no estoque
                for(i = 0; i < totalProdutos; i++) {
                    float valorEstoque = produtos[i].preco * produtos[i].quantidade;
                    printf("\nCodigo: %d\n", produtos[i].codigo);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Preco: R$ %.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("Valor em estoque: R$ %.2f\n", valorEstoque);
                    valorTotalEstoque += valorEstoque;
					// verifica se o produto da vez é mais caro que o anterior, se for ele aloca o produto novo no indiceMaisCaro para ser apresentado no resumo
                    if (produtos[i].preco > produtos[indiceMaisCaro].preco) {
                        indiceMaisCaro = i;
                    }
                }

                printf("\n=====================================\n");
                printf(" RESUMO\n");
                printf("Valor total do estoque: R$ %.2f\n", valorTotalEstoque);
                printf("\nProduto mais caro: %s\n", produtos[indiceMaisCaro].nome);
                printf("Preco: R$ %.2f\n", produtos[indiceMaisCaro].preco);
				printf("=====================================\n");
                break;
            
            // case 3 faz a busca de um produto por codigo inserido pelo usuario
			case 3:
				//se nenhum produto foi cadastrado ele apresenta esse texto
				if(produtos == NULL){
			        printf("\nNenhum produto cadastrado!\n");
			        break;
			    }
			    int codigoBusca;
			    int encontrado = 0;
			
			    printf("\nDigite o codigo do produto: ");
			    scanf("%d", &codigoBusca);
				//faz a busca do produto que existe com o mesmo codigo
			    for(i = 0; i < totalProdutos; i++) {
			        if(produtos[i].codigo == codigoBusca){
			            printf("\n===== PRODUTO ENCONTRADO =====\n");
			            printf("Codigo: %d\n", produtos[i].codigo);
			            printf("Nome: %s\n", produtos[i].nome);
			            printf("Preco: R$ %.2f\n", produtos[i].preco);
			            printf("Quantidade: %d\n", produtos[i].quantidade);
			            encontrado = 1;
			            break;
			        }
			    }
			    if(encontrado == 0){
			        printf("\nProduto nao encontrado!\n");
			    }
			    break;
			
			// case 4 encerra o programa limpando a memoria
            case 4:
                if (produtos != NULL) {
                    free(produtos);
                    produtos = NULL;
                }

                printf("\nMemoria liberada com sucesso.\n");
                printf("Programa encerrado.\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}