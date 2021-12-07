//Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defines

#define TAM 10

#define MAXSTR 128

typedef struct vDrinks {

    int dId, dStock;
    char dName[MAXSTR], dType[TAM];
    float dPrice;

} vDrink;

//Adicionar bebidas
int createDrink(vDrink *drinksList, int *drinksNumber, int *lastDrinkId) {
    //Vars    
    vDrink drink;
    int drinksToRead = 0;

    //MainCode
    printf("\n Quantas bebidas deseja inserir: \t");
    scanf("%d", &drinksToRead);
    fflush(stdin);
    for (int i = 0; i < drinksToRead; i++) {
        printf("\n Nome da bebida: \t");
        scanf("%s", drink.dName);
        fflush(stdin);

        printf("\n Preco da bebida: \t");
        scanf("%f", &drink.dPrice);
        fflush(stdin);

        printf("\n Stock da bebida: \t");
        scanf("%d", &drink.dStock);
        fflush(stdin);

        printf("\n Tipo de bebida: (simples|alcool|refrigerante)\t");
        scanf("%s", &drink.dType);
        fflush(stdin);
        
        (*lastDrinkId)++;
        drink.dId = *lastDrinkId;
        drinksList[(*drinksNumber)++] = drink;
    }

    return drinksToRead;
}

//Listar inventario de bebidas
void listingInventory(vDrink *vDrinks, int drinksNumber) {

    //MainCode
    printf("\n Lista de bebidas: \t");
    for (int i = 0; i < drinksNumber; i++) {
        printf("\n Id: %d", vDrinks[i].dId);
        printf(" | Nome: %s", vDrinks[i].dName);
        printf(" | Preco: %.2f", vDrinks[i].dPrice);
        printf(" | Stock: %d", vDrinks[i].dStock);
        printf(" | Tipo: %s", vDrinks[i].dType);
    }

}

//Listar bebida individual
void listingIndividualDrink(vDrink *vDrinks, int drinksNumber, int *lastDrinkId) {

    //Vars
    int x = *lastDrinkId, requestedId;

    //MainCode
    printf("\n Ultimo id inserido: %d\t", x);
    printf("\n Insira o id da bebida: \t");
    scanf("%d", &requestedId);
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dId==requestedId) {
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
            break;
        }
    }
}

//Alterar preco de um certo id
void changeDrinkPrice(vDrink *vDrinks, int drinksNumber, int *lastDrinkId) {

    //Vars
    int x = *lastDrinkId, requestedId;
    float newPrice;

    //MainCode
    printf("\n Ultimo id inserido: %d\t", x);
    printf("\n Insira o id da bebida: \t");
    scanf("%d", &requestedId);
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dId==requestedId) {
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
            printf("\n Novo preco da bebida: \t");
            scanf("%f", &newPrice);
            vDrinks[i].dPrice = newPrice;
            printf("\n Novos dados da bebida: \t");
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
            break;
        }
    }
};

//Mostrar bebida com mais stock
void showMostStockedDrink(vDrink *vDrinks, int drinksNumber) {

    //Vars
    int mostStockedStock = 0, mostStockedI = 0;

    //MainCode
    printf("\n A bebida com mais stock: \t");
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dStock > mostStockedStock) {
            mostStockedStock = vDrinks[i].dStock;
            mostStockedI = i;
        }
    }
    printf("\n Id: %d", vDrinks[mostStockedI].dId);
    printf(" | Nome: %s", vDrinks[mostStockedI].dName);
    printf(" | Preco: %.2f", vDrinks[mostStockedI].dPrice);
    printf(" | Stock: %d", vDrinks[mostStockedI].dStock);
    printf(" | Tipo: %s", vDrinks[mostStockedI].dType);
}

//Mostrar todo o stock em quantidade e preco
void showAllStock(vDrink *vDrinks, int drinksNumber) {

    //Vars
    int stockCount = 0;
    float stockPriceCount = 0, calcVar;

    //MainCode
    printf("\n O stock total: \t");
    for (int i = 0; i < drinksNumber; i++) {
        stockCount = stockCount + vDrinks[i].dStock;
        calcVar = calcVar + vDrinks[i].dPrice; //Calcula preco individual
    }
    stockPriceCount = stockCount * calcVar;
    printf("\n Quantidade: %d", stockCount);
    printf("\n Preco: %.2f", stockPriceCount);
}

//Mostrar media de preco das bebidas
void averagePriceOfDrinks(vDrink *vDrinks, int drinksNumber) {

    //Vars
    float averagePrice = 0, sumPrice = 0;

    //MainCode
    printf("\n A media de preco das bebidas: \t");
    for (int i = 0; i < drinksNumber; i++) {
        sumPrice = sumPrice + vDrinks[i].dPrice;
    }
    averagePrice = sumPrice / drinksNumber;
    printf("%.2f", averagePrice);
}

//Mostrar bebida por tipo inserido
void drinksByType(vDrink *vDrinks, int drinksNumber) {
    char requestedType[MAXSTR];

    printf("\n Insira o tipo de bebida: (simples|alcool|refrigerante)\t");
    scanf("%s", requestedType);
    for (int i = 0; i < drinksNumber; i++) {
        if (strcmp(vDrinks[i].dType, requestedType) == 0) {
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
        } else {
            printf("\n Todas as bebidas de todos os tipos, pois nao escolheu nenhuma das opcoes possiveis:");
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
        }
    }
}

//Mostrar a bebida mais barata de um certo tipo
void cheapestDrinkOfCertainType(vDrink *vDrinks, int drinksNumber) {
    char requestedType[MAXSTR];
    float cheapestDrink = 999;
    int iVar = 0;

    printf("\n Insira o tipo de bebida: (simples|alcool|refrigerante)\t");
    scanf("%s", requestedType);
    for (int i = 0; i < drinksNumber; i++) {
        if (strcmp(vDrinks[i].dType, requestedType) == 0) {
            if (cheapestDrink > vDrinks[i].dPrice) {
                cheapestDrink = vDrinks[i].dPrice;
                iVar = i;
            }
        } else {
            printf("\n Nenhum dos tipos possiveis foi escolhido \t");
        }
    }
    for (int i = 0; i < drinksNumber; i++) {
        if (strcmp(vDrinks[i].dType, requestedType) == 0) {
            printf("\n Bebida mais barata desse tipo: \t");
            printf("\n Id: %d", vDrinks[iVar].dId);
            printf(" | Nome: %s", vDrinks[iVar].dName);
            printf(" | Preco: %.2f", vDrinks[iVar].dPrice);
            printf(" | Stock: %d", vDrinks[iVar].dStock);
            printf(" | Tipo: %s", vDrinks[iVar].dType);
            break;
        }
    }
}

//Mostrar bebidas com o preco acima da media
void overpricedDrinks(vDrink *vDrinks, int drinksNumber) {

    //Vars
    float averagePrice = 0, sumPrice = 0;

    //MainCode
    for (int i = 0; i < drinksNumber; i++) {
        sumPrice = sumPrice + vDrinks[i].dPrice;
    }
    averagePrice = sumPrice / drinksNumber;         //Media de preco das bebidas todas
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dPrice > averagePrice) {
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
        }  
    }
    printf("\n Media de precos: %.2f\t", averagePrice);
}

//Contabilizar, para cada tipo de bebida, a media da quantidade de garrafas em stock
void averageNumberOfBottlesInStockPerType(vDrink *vDrinks, int drinksNumber) {
    char simple[MAXSTR] = "simples", alcohol[MAXSTR] = "alcool", soda[MAXSTR] = "refrigerante";
    int stockCount = 0, stockTypeS = 0, stockTypeA = 0, stockTypeR = 0;
    float averageTypeS = 0, averageTypeA = 0, averageTypeR = 0;

    for (int i = 0; i < drinksNumber; i++) {
        stockCount = stockCount + vDrinks[i].dStock;
    }

    for (int i = 0; i < drinksNumber; i++) {
        if (strcmp(vDrinks[i].dType, simple) == 0) {
            stockTypeS = stockTypeS + vDrinks[i].dStock;
        }
    }

    for (int i = 0; i < drinksNumber; i++) {
        if (strcmp(vDrinks[i].dType, alcohol) == 0) {
            stockTypeA = stockTypeA + vDrinks[i].dStock;
        }
    }

    for (int i = 0; i < drinksNumber; i++) {
        if (strcmp(vDrinks[i].dType, soda) == 0) {
            stockTypeR = stockTypeR + vDrinks[i].dStock;
        }
    }

    averageTypeS = stockTypeS * 100;
    averageTypeS = averageTypeS / stockCount;
    averageTypeA = stockTypeA * 100;
    averageTypeA = averageTypeA / stockCount;
    averageTypeR = stockTypeR * 100;
    averageTypeR = averageTypeR / stockCount;

    printf("\n Media de bebidas: Simples - %.2f%%\t", averageTypeS);
    printf("\n Media de bebidas: Alcool - %.2f%%\t", averageTypeA);
    printf("\n Media de bebidas: Refrigerante - %.2f%%\t", averageTypeR);
}

//Vender uma bebida por id
void sellDrinksById(vDrink *vDrinks, int drinksNumber, int *lastDrinkId) {
    int x = *lastDrinkId, requestedId, stock = 0, quantityToBuy = 0;

    printf("\n Ultimo id inserido: %d\t", x);
    printf("\n Insira o id da bebida: \t");
    scanf("%d", &requestedId);
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dId==requestedId) {
            stock = vDrinks[i].dStock;
            printf("\n Quantas deseja comprar?: \t");
            scanf("%d", &quantityToBuy);
            if (quantityToBuy <= stock) {
                vDrinks[i].dStock = stock - quantityToBuy;
                printf("\n Id: %d", vDrinks[i].dId);
                printf(" | Nome: %s", vDrinks[i].dName);
                printf(" | Preco: %.2f", vDrinks[i].dPrice);
                printf(" | Stock: %d", vDrinks[i].dStock);
                printf(" | Tipo: %s", vDrinks[i].dType);
            } else {
                printf("\n O stock nao e suficiente \t");
            } 
        }
    }
}

//Mostrar valor do iva de todo o stock de alccol
void calculateIvaAlcool(vDrink *vDrinks, int drinksNumber) {
    char alcohol[MAXSTR] = "alcool";
    float priceAndIva = 0, ivaAlcool = 0, justPrice = 0;

    for (int i = 0; i < drinksNumber; i++) {
        if (strcmp(vDrinks[i].dType, alcohol) == 0) {
            priceAndIva = priceAndIva + vDrinks[i].dPrice;
        }
    }
    justPrice = priceAndIva / 1.13;
    ivaAlcool = priceAndIva - justPrice;
    printf("\n priceAndIva: %.2f \t", priceAndIva);
    printf("\n justPrice: %.2f \t", justPrice);
    printf("\n O preco do iva do alcool em stock: %.2f \t", ivaAlcool);
}

int main() {

	//vars
    int menu = 0,
        drinksNumber = 0,
        drinksAdded = 0,
        lastDrinkAddedId = 0;
    vDrink drinks[TAM];

	//main code
	puts("\n Gestao de bebidas:");              
	puts("\n 01|Adicionar bebidas");                                                                    
    puts("\n 02|Listar inventario de bebidas");                                                         
    puts("\n 03|Listar bebida individual");                                                            
    puts("\n 04|Alterar preco de uma bebida por id");                                                   
    puts("\n 05|Mostrar bebida com mais stock");                                                        
    puts("\n 06|Mostrar todo o stock (quantidade e preco)");                                            
    puts("\n 07|Media de preco das bebidas");                                                           
    puts("\n 08|Listar todas as bebidas por tipo (simples|alcool|refrigerante|outros)");               
    puts("\n 09|Mostrar a bebida mais barata de um certo tipo");                                        
    puts("\n 10|Listar bebidas que o preco esta acima da media");                                       
    puts("\n 11|Contabilizar, para cada tipo de bebida, a media da quantidade de garrafas em stock");   
    puts("\n 12|Vender bebidas por id");                                                                
    puts("\n 13|Calcular o IVA de todo o stock de alcool");                                            
    puts("\n 00|Sair");                                                                                

    printf("\n Escolha a opcao que deseja: \t");
    scanf("%d", &menu);
    fflush(stdin);

    while (menu > 0)
    {
        switch (menu)
        {
        case 1: //Adicionar bebidas
            drinksAdded = createDrink(drinks, &drinksNumber, &lastDrinkAddedId);
            break;

        case 2: //Listar inventario de bebidas
            listingInventory(drinks, drinksNumber);
            break;

        case 3: //Listar info sobre bebida individual
            listingIndividualDrink(drinks, drinksNumber, &lastDrinkAddedId);
            break;

        case 4: //Alterar preco da bebida
            changeDrinkPrice(drinks, drinksNumber, &lastDrinkAddedId);
            break;

        case 5: //Mostrar bebida com mais stock
            showMostStockedDrink(drinks, drinksNumber);
            break;

        case 6: //Mostrar total de stock (quantidade e preco)
            showAllStock(drinks, drinksNumber);
            break;

        case 7: //Media de preco das bebidas
            averagePriceOfDrinks(drinks, drinksNumber);
            break;

        case 8: //Listar bebida por tipo inserido
            drinksByType(drinks, drinksNumber);
            break;

        case 9: //Mostrar a bebida mais barata de um certo tipo
            cheapestDrinkOfCertainType(drinks, drinksNumber);
            break;

        case 10: //Mostrar bebidas com preco acima da media
            overpricedDrinks(drinks, drinksNumber);
            break;

        case 11: //Contabilizar, para cada tipo de bebida, a media da quantidade de garrafas em stock
            averageNumberOfBottlesInStockPerType(drinks, drinksNumber);
            break;

        case 12: //Vender bebidas por id
            sellDrinksById(drinks, drinksNumber, &lastDrinkAddedId);
            break;

        case 13: //Calcular iva do alcool em stock
            calculateIvaAlcool(drinks, drinksNumber);
            break;

        case 0:
            menu = 0;
            break;
        }

        if (menu == 0) {
            break;
        }

	    //main code
	    puts("\n Gestao de bebidas:");              
	    puts("\n 01|Adicionar bebidas");                                                                    
        puts("\n 02|Listar inventario de bebidas");                                                         
        puts("\n 03|Listar bebida individual");                                                            
        puts("\n 04|Alterar preco de uma bebida por id");                                                   
        puts("\n 05|Mostrar bebida com mais stock");                                                        
        puts("\n 06|Mostrar todo o stock (quantidade e preco)");                                            
        puts("\n 07|Media de preco das bebidas");                                                           
        puts("\n 08|Listar todas as bebidas por tipo (simples|alcool|refrigerante|outros)");               
        puts("\n 09|Mostrar a bebida mais barata de um certo tipo");                                        
        puts("\n 10|Listar bebidas que o preco esta acima da media");                                       
        puts("\n 11|Contabilizar, para cada tipo de bebida, a media da quantidade de garrafas em stock");   
        puts("\n 12|Vender bebidas por id");                                                                
        puts("\n 13|Calcular o IVA de todo o stock de alcool");                                            
        puts("\n 00|Sair");  

        printf("\n Escolha a opcao que deseja: \t");
        scanf("%d", &menu);
        fflush(stdin);
    }

    return 0;

}
