#include <iostream>
#include <random>
#include <algorithm>
#include <array>

//Exercice simuler jeu de carte 

namespace  Random
{
    std::mt19937 generateRandomNumber {std::random_device{}()};

    int randomNumberGenerator (int min, int max)
    {
        std::uniform_int_distribution distribute {min, max};

        return distribute(generateRandomNumber); 
    }
    
}

enum Rank 
{
    rank_2, 
    rank_3, 
    rank_4, 
    rank_5, 
    rank_6, 
    rank_7, 
    rank_8, 
    rank_9, 
    rank_10, 
    rank_valet, 
    rank_reine, 
    rank_roi, 
    rank_as

};

enum Suit 
{
    trèfles, 
    carreau, 
    coeur, 
    pique
 
};

struct Card
{
    Rank Rank{};
    Suit Suit{};
};

void printCard(const Card& card)
{
    switch (card.Rank)
    {
    case Rank::rank_2:      std::cout << '2';   break;
    case Rank::rank_3:      std::cout << '3';   break;
    case Rank::rank_4:      std::cout << '4';   break;
    case Rank::rank_5:      std::cout << '5';   break;
    case Rank::rank_6:      std::cout << '6';   break;
    case Rank::rank_7:      std::cout << '7';   break;
    case Rank::rank_8:      std::cout << '8';   break;
    case Rank::rank_9:      std::cout << '9';   break;
    case Rank::rank_10:     std::cout << 'D';   break;
    case Rank::rank_valet:   std::cout << 'V';   break;
    case Rank::rank_reine:  std::cout << 'R';   break;
    case Rank::rank_roi:   std::cout << 'K';   break;
    case Rank::rank_as:    std::cout << 'A';   break;
    default:
        std::cout << '?';
        break;
    };

    switch (card.Suit)
    {
    case Suit::trèfles:      std::cout << 'T' <<' ';   break;
    case Suit::carreau:    std::cout << 'C' <<' ';   break;
    case Suit::coeur:      std::cout << 'H' <<' ';   break;
    case Suit::pique:      std::cout << 'P'<<' ';   break;
    default:
        std::cout << '?';
        break;
    } 

}

std::array<Card,52> createDeck()
{
    std::array<Card,52> deck {} ;
    int arrayIndex{};
        for (int suitIndex{}; suitIndex<4; ++suitIndex)
        {
            for (int rankIndex{}; rankIndex<13; ++rankIndex)
            {
                deck[arrayIndex].Suit = static_cast<Suit>(suitIndex);
                deck[arrayIndex].Rank = static_cast<Rank>(rankIndex);
                ++arrayIndex;
            }
        }

return deck;
}

void printDeck( const std::array<Card,52>& deck)
{
    for (auto card : deck)
    {
        printCard( card );
    }
}

std::array<Card,52> shuffleDeck(std::array<Card,52> deck)
{
    std::shuffle(deck.begin(), deck.end(), Random::generateRandomNumber ); 

return deck;
}

Card pickRandomCard (const std::array<Card,52>& deck)
{
    return deck[Random::randomNumberGenerator(0,51)] ;
}


int main() 
{
printDeck ( shuffleDeck ( createDeck() ) );
std::cout<< '\n';
printCard ( pickRandomCard (createDeck() ) ); 


return 0 ;

}

