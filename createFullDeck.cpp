#include <iostream>
//#include "header.h"

using namespace std;

struct node
{
    string suit;
    string value;
    node*next;
    int cardNum;
};

bool isEmpty(node *head){
    if (head==NULL){
        return true;
    }
    else
        return false;
}

node* createDeck(node *fullDeck){
    node *last = NULL;
    int cardNum = 1;
    for (int j=0; j<4; j++){
        for (int i=1; i<=13; i++){
            if (isEmpty(fullDeck)){
                node *temp = new node;
                if (j==0){
                    temp -> suit = "Heart";
                }
                else if (j==1){
                    temp -> suit = "Diamonds";
                }
                else if (j==2){
                    temp -> suit = "Spades";
                }
                else if (j==3){
                    temp -> suit = "Clubs";
                }
                if (i ==1){
                    temp -> value = "Ace";
                }
                else if (i==11){
                    temp -> value = "Jack";
                }
                else if (i==12){
                    temp -> value = "Queen";
                }
                else if (i==13){
                    temp -> value = "King";
                }
                else {
                    //cout<<i;
                    temp-> value = to_string(i);
                }
                temp->cardNum = cardNum;
                cardNum++;
                temp -> next = NULL;
                fullDeck = temp;
                last = temp;
            }
            else {
                
                node *fullDeck = new node;
                if (j==0){
                    fullDeck -> suit = "Heart";
                }
                else if (j==1){
                    fullDeck -> suit = "Diamonds";
                }
                else if (j==2){
                    fullDeck -> suit = "Spades";
                }
                else if (j==3){
                    fullDeck -> suit = "Clubs";
                }
                if (i ==1){
                    fullDeck -> value = "Ace";
                }
                else if (i==11){
                    fullDeck -> value = "Jack";
                }
                else if (i==12){
                    fullDeck -> value = "Queen";
                }
                else if (i==13){
                    fullDeck -> value = "King";
                }
                else {
                    //cout<<i;
                    fullDeck-> value = to_string(i);
                }
                fullDeck->cardNum = cardNum;
                cardNum++;
                fullDeck -> next = NULL;
                last ->next = fullDeck;
                last = fullDeck;
            }
        }
    }
    return fullDeck;
}
void showList(node *fullDeck){//displays the linked list with the proper formating
    while (fullDeck){
        cout<<fullDeck->value<<" of "<<fullDeck->suit<<" card num: "<<fullDeck->cardNum<<"\n";
        fullDeck = fullDeck->next;
    }
    
}

node* createHand(node *fullDeck, int num[52], int rangeMin, int rangeMax){
    node *last = NULL;
    node *hand=NULL;
    node *begining = fullDeck;

    for (int i=rangeMin; i<rangeMax; i++){ //puts the first 16 cards in the random array into the first hand
        while (fullDeck){
            if (num[i]==fullDeck->cardNum){
                if (isEmpty(hand)){
                    node *temp = new node;
                    temp->value=fullDeck->value;
                    temp->suit=fullDeck->suit;
                    temp->cardNum=fullDeck->cardNum;
                    temp -> next = NULL;
                    hand = temp;
                    last = temp;
                }
                else {
                    node *hand = new node;
                    hand->value=fullDeck->value;
                    hand->suit=fullDeck->suit;
                    hand->cardNum=fullDeck->cardNum;
                    hand -> next = NULL;
                    last ->next = hand;
                    last = hand;
                }
            }
            fullDeck=fullDeck->next;
        }
        fullDeck=begining; //resets the fulldeck from the begining
    }
    return hand;
}

int main(int argc, const char * argv[]) {
    node *fullDeck = NULL;
    node *hand1 = NULL;
    node *hand2 = NULL;
    node *hand3 = NULL;
    node *hand4 = NULL;
   
 fullDeck = createDeck(fullDeck);
   
    int num[52];
    for (int k=1; k<53;k++){
        num[k]=k;
    }
   random_shuffle(&num[0], &num[51]); //creates a list of numbers 1-52 in a random order THIS DOESNT REALLY WORK!
   for (int k=1; k<53; k++){
        //cout<<num[k]<<"\n";
    }
    
    cout<<"\n\n\nShuffled: \n";
    hand1=createHand(fullDeck, num, 0, 14);
    hand2 = createHand(fullDeck, num, 14, 27);
    hand3 = createHand(fullDeck, num, 27, 40);
    hand4 = createHand(fullDeck, num, 40, 53);
    cout<<"hand 1: \n";
        showList(hand1);
    cout<<"\nhand 2: \n";
        showList(hand2);
    cout<<"\nhand 3: \n";
        showList(hand3);
    cout<<"\nhand 4: \n";
        showList(hand4);
    return 0;
}
