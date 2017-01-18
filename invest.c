#include <stdio.h>
#include <math.h>

/*Lab 2*/
/*This code has not been tested yet!*/

double stockPrice, balance;
double changeRate0, changeRate1, changeRate2; /*changeRateN means the change rate of N days before today.*/
int stockOwned;
int dayCount;/*Irrelevant in the program.*/
int pass = 1;/*Input param. When equal to 0, finish the program.*/
int r, b;/*Init var for rand and buy.*/

main(){
	
	onInit();
	
	do{
	  scanf("%d", &pass);
	  if(pass != 0){
		Day();
	  }
	}while(pass != 0);
	
	onFinish();

}

Day(){
	++ dayCount;/*Good morning!*/
	changeRate2 = changeRate1;
	changeRate1 = changeRate0;
	changeRate0 = 1;
	
	/*In the morning, buy or sell stocks.*/
	if(changeRate2 == 1.1 && changeRate1 == 1.1){
		Sell(stockOwned);
	}else if(changeRate2 >= 1.05 && changeRate1 >= 1.05){
		b = (balance/stockPrice)/2;
		Buy(b);
	}else if(changeRate2 < 1 && changeRate1 < 1){
		b = (balance/stockPrice);
		Buy(b);
	}
	
	/*In the night, stock price changes by random. Stock price only change 10% maximum per day.*/
	r = rand() %30;
	changeRate0 = 0.01 * r + 0.86;
	
	if(changeRate0 < 0.9){
		changeRate0 = 0.9;
	}else if(changeRate0 > 1.1){
		changeRate0 = 1.1;
	}
	
	stockPrice = stockPrice * changeRate0;
	printf("the price now is %.2f.\n", stockPrice);
}

onInit(){
	changeRate0 = changeRate1 = changeRate2 = 1;
	stockPrice = 10.0;
	balance = 10000.0;
	stockOwned = 0;
	dayCount = 0; /*Program starts at the night time.*/
}

onFinish(){
	balance = balance + stockOwned * stockPrice;
	stockOwned = 0;
	double settlement = balance - 10000.0;
	printf("$""%.2f\n", settlement);
}

Buy(int s){
	if(s * stockPrice > balance){
		b = stockPrice/balance;
		Buy(b);
	}else{
		balance = balance - s * stockPrice;
		stockOwned = stockOwned + s;
		printf("%d stock purchased at price $ %.2f. The balance now is %.2f.\n", s, stockPrice, balance);
	}
}

Sell(int s){
	if(s > stockOwned){
		Sell(stockOwned);
	}else{
		stockOwned = stockOwned - s;
		balance = balance + s * stockPrice;
		printf("%d stock sold at price $ %.2f. The balance now is %.2f.\n", s, stockPrice, balance);
	}
}
