#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

struct Question {
    string questionText;
    string options[4]; //possible answers
    int correctAnswer; // 1 to 4
};

// Sports questions
vector<Question> sportsQuestions={
    {"Which country has won the most FIFA World Cups?", {"Brazil", "Germany", "Italy", "Argentina"}, 1},
    {"What is Cristiano Ronaldo's nickname?", {"CR7", "The King", "Golden Foot", "Magic"}, 1},
    {"How many players are on the field for a football team?", {"9", "10", "11", "12"}, 3},
    {"Which country hosted the 2004 Olympic Games?", {"China", "USA", "Greece", "Italy"}, 3},
    {"Who is the most famous Greek NBA player?", {"Nikos Galis", "Vassilis Spanoulis", "Thanasis Antetokounmpo", "Giannis Antetokounmpo"}, 4},
    {"What is the regular duration of a football match?", {"60 minutes", "90 minutes", "80 minutes", "100 minutes"}, 2},
    {"Which country is famous for ice hockey?", {"Canada", "Spain", "Egypt", "India"}, 1},
    {"In which sport is a racket used?", {"Basketball", "Tennis", "Football", "Rugby"}, 2},
    {"Which sport is played at Wimbledon?", {"Golf", "Tennis", "Cricket", "Snooker"}, 2},
    {"Which ball has the smallest diameter?", {"Baseball", "Tennis ball", "Cricket ball", "Table tennis ball"}, 4},
    {"Which athlete has the most Olympic medals?", {"Michael Phelps", "Usain Bolt", "Larisa Latynina", "Simone Biles"}, 1},
    {"Where were the first modern Olympics held?", {"Paris", "Athens", "London", "Rome"}, 2},
    {"Which sport uses a shuttlecock?", {"Squash", "Tennis", "Badminton", "Volleyball"}, 3},
    {"What is the name of the top baseball league in the USA?", {"NFL", "NBA", "NHL", "MLB"}, 4},
    {"Which boxer was known as 'The Greatest'?", {"Mike Tyson", "Floyd Mayweather", "Muhammad Ali", "Joe Frazier"}, 3},
    {"Which country won the Euro 2004 football championship?", {"Italy", "Portugal", "Greece", "France"}, 3},
    {"Which city hosted the 2016 Summer Olympics?", {"Rio de Janeiro", "Tokyo", "London", "Beijing"}, 1},
    {"How many rings are on the Olympic flag?", {"4", "5", "6", "7"}, 2},
    {"Which sport uses a pommel horse?", {"Equestrian", "Gymnastics", "Fencing", "Wrestling"}, 2},
    {"Who holds the men's 100m world record?", {"Tyson Gay", "Yohan Blake", "Usain Bolt", "Asafa Powell"}, 3}
};

// Arts questions
vector<Question> artsQuestions={
    {"Who directed the film '2001: A Space Odyssey'?", {"Ridley Scott", "Francis Ford Coppola", "Stanley Kubrick", "Steven Spielberg"}, 3},
    {"Which architect designed the Sagrada Familia?", {"Frank Lloyd Wright", "Antoni Gaudi", "Le Corbusier", "Norman Foster"}, 2},
    {"Who composed the '9th Symphony'?", {"Mozart", "Bach", "Beethoven", "Tchaikovsky"}, 3},
    {"Which sculpture was created by Michelangelo?", {"Venus de Milo", "The Thinker", "David", "Winged Victory"}, 3},
    {"Who wrote 'The Little Prince'?", {"Antoine de Saint-Exupery", "Lewis Carroll", "Franz Kafka", "Oscar Wilde"}, 1},
    {"Who painted 'The Birth of Venus'?", {"Raphael", "Caravaggio", "Botticelli", "Leonardo da Vinci"}, 3},
    {"To which art movement did Picasso belong?", {"Impressionism", "Cubism", "Romanticism", "Realism"}, 2},
    {"Who is the author of 'The Old Man and the Sea'?", {"John Steinbeck", "Ernest Hemingway", "Mark Twain", "William Faulkner"}, 2},
    {"Famous ceiling in Sistine Chapel?", {"Last Supper", "Creation of Adam", "Crucifixion", "Resurrection"}, 2},
    {"Who composed 'The Magic Flute'?", {"Verdi", "Wagner", "Mozart", "Handel"}, 3},
    {"Which artist cut off his own ear?", {"Van Gogh", "Monet", "Dali", "Picasso"}, 1},
    {"Which artist is famous for melting clocks?", {"Matisse", "Dali", "Pollock", "Kandinsky"}, 2},
    {"What nationality was Frida Kahlo?", {"Mexican", "Spanish", "Argentinian", "Chilean"}, 1},
    {"Who painted 'Guernica'?", {"Miró", "Dali", "Picasso", "Goya"}, 3},
    {"Who wrote 'Romeo and Juliet'?", {"Shakespeare", "Chaucer", "Marlowe", "Byron"}, 1},
    {"Who is known for the 'Blue Period'?", {"Picasso", "Van Gogh", "Renoir", "Monet"}, 1},
    {"Which museum is the Mona Lisa in?", {"British Museum", "Louvre", "Uffizi", "MET"}, 2},
    {"Which composer went deaf?", {"Bach", "Mozart", "Beethoven", "Schubert"}, 3},
    {"What art movement is Monet associated with?", {"Cubism", "Realism", "Impressionism", "Expressionism"}, 3},
    {"Which film won Best Picture in 1994?", {"Forrest Gump", "Pulp Fiction", "Shawshank Redemption", "Four Weddings"}, 1}
};

// History questions
vector<Question> historyQuestions={
    {"Who was the first President of the US?", {"George Washington", "Thomas Jefferson", "Abraham Lincoln", "John Adams"}, 1},
    {"When did WWII end?", {"1945", "1939", "1941", "1950"}, 1},
    {"Who discovered America in 1492?", {"Columbus", "Marco Polo", "Magellan", "Vasco da Gama"}, 1},
    {"Which civ built the pyramids?", {"Romans", "Greeks", "Egyptians", "Persians"}, 3},
    {"WWII UK Prime Minister?", {"Churchill", "Chamberlain", "Thatcher", "Blair"}, 1},
    {"When did Berlin Wall fall?", {"1985", "1989", "1991", "1980"}, 2},
    {"'Maid of Orleans'?", {"Elizabeth I", "Joan of Arc", "Marie Antoinette", "Cleopatra"}, 2},
    {"Empire of Julius Caesar?", {"Persian", "Ottoman", "Roman", "Mongol"}, 3},
    {"Sank in 1912?", {"Britannic", "Titanic", "Lusitania", "Queen Mary"}, 2},
    {"1st man on Moon?", {"Buzz Aldrin", "Yuri Gagarin", "Neil Armstrong", "Michael Collins"}, 3},
    {"Country gifted Statue of Liberty?", {"England", "Germany", "France", "Italy"}, 3},
    {"1st Emperor of China?", {"Qin Shi Huang", "Sun Tzu", "Confucius", "Genghis Khan"}, 1},
    {"'Liberty, Equality, Fraternity'?", {"American", "French", "Russian", "Industrial"}, 2},
    {"Longest reigning monarch (until 2022)?", {"Elizabeth I", "Victoria", "Elizabeth II", "George III"}, 3},
    {"Sistine Chapel ceiling?", {"Da Vinci", "Raphael", "Michelangelo", "Donatello"}, 3},
    {"American Civil War began?", {"1861", "1776", "1812", "1865"}, 1},
    {"Who invented the wheel?", {"Romans", "Sumerians", "Egyptians", "Greeks"}, 2},
    {"Pilgrims' ship?", {"Santa Maria", "Endeavour", "Mayflower", "Beagle"}, 3},
    {"India's independence leader?", {"Nehru", "Gandhi", "Indira Gandhi", "Bose"}, 2},
    {"North vs South US war?", {"WWI", "Revolution", "Civil War", "Vietnam"}, 3}
};

vector<Question> geographyQuestions={
    {"What is the longest river in the world?", {"Amazon", "Yangtze", "Nile", "Mississippi"}, 3},
    {"Which country has the largest population?", {"India", "China", "United States", "Indonesia"}, 2},
    {"What is the capital of Canada?", {"Toronto", "Vancouver", "Montreal", "Ottawa"}, 4},
    {"Mount Everest is located in which mountain range?", {"Alps", "Andes", "Rockies", "Himalayas"}, 4},
    {"Which ocean is the largest by area?", {"Atlantic", "Indian", "Southern", "Pacific"}, 4},
    {"Which country has the most natural lakes?", {"Canada", "Russia", "USA", "Brazil"}, 1},
    {"Which desert is the largest in the world?", {"Sahara", "Gobi", "Antarctic", "Kalahari"}, 3},
    {"Which country has the most time zones?", {"Russia", "USA", "France", "China"}, 3},
    {"What is the smallest country in the world?", {"Vatican City", "Monaco", "San Marino", "Liechtenstein"}, 1},
    {"Which continent has the most countries?", {"Africa", "Asia", "Europe", "South America"}, 1},
    {"Which country is both in Europe and Asia?", {"Turkey", "Egypt", "India", "Greece"}, 1},
    {"What is the capital of Australia?", {"Sydney", "Melbourne", "Canberra", "Perth"}, 3},
    {"Which river flows through Paris?", {"Danube", "Rhine", "Seine", "Thames"}, 3},
    {"Which mountain is the highest in Africa?", {"Kilimanjaro", "Atlas", "Drakensberg", "Simien"}, 1},
    {"Where is the Great Barrier Reef?", {"Indonesia", "Australia", "Philippines", "Thailand"}, 2},
    {"Which sea is shrinking due to irrigation?", {"Dead Sea", "Aral Sea", "Baltic Sea", "Red Sea"}, 2},
    {"Which US state has the most islands?", {"Hawaii", "California", "Florida", "Alaska"}, 4},
    {"What is the capital of Japan?", {"Osaka", "Kyoto", "Tokyo", "Hiroshima"}, 3},
    {"Which line divides Earth into North and South?", {"Equator", "Prime Meridian", "Tropic of Cancer", "Tropic of Capricorn"}, 1},
    {"What is the flattest continent?", {"Europe", "Asia", "Africa", "Australia"}, 4}
};

vector<Question> getCategoryQuestions(int category) {
    switch (category) {
        case 1: return sportsQuestions;
        case 2: return artsQuestions;
        case 3: return historyQuestions;
        case 4: return geographyQuestions;
        default: return {}; //empty vector
    }
}

int askQuestionWithFiftyFifty(const Question& q, int& score) {
    vector<int> wrongIndices;
    for(int i=0;i<4;++i)
        if(i+1!=q.correctAnswer)
            wrongIndices.push_back(i);

    random_shuffle(wrongIndices.begin(), wrongIndices.end()); //removes two wrong answers
    set<int> toHide={wrongIndices[0], wrongIndices[1]}; //hides two wrong answers

    cout<<"[50/50 Lifeline Used]\n";
    cout<<q.questionText<<endl;
    for(int i=0;i<4;++i) { //print only the answers not hidden
        if(toHide.count(i)) continue; //skip hidden answers
        cout<<(i+1)<<". "<<q.options[i]<<endl;
    }

    int answer;
    cout<<"Your answer (1-4): ";
    cin>>answer;

    if(answer==q.correctAnswer) {
        cout<<"Correct! +10 points\n"; //less points due to use of fifty fifty
        score+=10;
        return 1;
    } else {
        cout<<"Wrong! Correct: "<<q.correctAnswer<<". "<<q.options[q.correctAnswer-1]<<endl;
        return 0;
    }
}

int askQuestion(const Question& q, int& score, bool& usedFiftyFifty) {
    cout<<q.questionText<<endl;
    for(int i=0;i<4;++i) //display options
        cout<<(i+1)<<". "<<q.options[i]<<endl;

    cout<<"Your answer (1-4), or type 0 to use 50/50 lifeline";
    if(usedFiftyFifty)cout<<" (already used)";
    cout<<": ";

    int answer;
    cin>>answer;
	//check if fifty fifty has been used
    if(answer==0) {
    	if(!usedFiftyFifty){
		
        	usedFiftyFifty=true;
        	return askQuestionWithFiftyFifty(q, score);
    	}else{
    		cout<<"50/50 lifeline already used. Please choose an answer (1-4):\n";
			}
    }
    while(answer < 1 || answer > 4){
    cout << "Invalid input. Please choose between 1 and 4: ";
    cin >> answer;
}

	//score update
    if(answer==q.correctAnswer) {
        cout<<"Correct! +20 points\n";
        score+=20;
        return 1;
    } else {
        cout<<"Wrong! Correct: "<< q.correctAnswer<< ". "<<q.options[q.correctAnswer-1]<<endl;
        return 0;
    }
}





int main() {
    srand(time(0));
    char playAgain;

    cout << "Enter name for Player 1: ";
    string name1;
    getline(cin, name1);

    cout << "Enter name for Player 2: ";
    string name2;
    getline(cin, name2);

    do {
        vector<int> selectedCategories;

        // Category selection loop to force valid input
        do {
            selectedCategories.clear();
            cout<<"\nChoose categories (e.g., 1 or 1 2 3 4):\n";
            cout<<"1. Sports\n2. Arts\n3. History\n4. Geography\n> ";

            string line;
            getline(cin, line);
            istringstream iss(line);
            int c;
            while(iss>>c) {
                if(c>=1&&c<=4)
                    selectedCategories.push_back(c);
            }
            if(selectedCategories.empty()) {
                cout<<"At least one category required. Please try again.\n";
            }
        } while(selectedCategories.empty());

        int score1=0, score2=0;
        int turn=0, qCount1=0, qCount2=0;
        set<int>used;
        bool usedFiftyFifty1=false, usedFiftyFifty2=false;

        vector<Question> totalQuestions;
        for(int cat:selectedCategories) {
            vector<Question>q=getCategoryQuestions(cat);
            totalQuestions.insert(totalQuestions.end(), q.begin(), q.end());
        }

        random_device rd;
        mt19937 g(rd());
        shuffle(totalQuestions.begin(), totalQuestions.end(), g);

        while(qCount1<10&&qCount2<10&&score1<100&&score2<100) {
            cout<<"\n----- "<<(turn%2==0?name1:name2)<< "'s Turn -----\n";

            bool questionAsked=false;
            for(int i=0;i<(int)totalQuestions.size();++i) {
                if(!used.count(i)) {
                    used.insert(i);
                    if(turn%2==0) {
                        askQuestion(totalQuestions[i], score1, usedFiftyFifty1);
                        cout<<"Score "<<name1<<": "<<score1<<"\n";
                        qCount1++;
                    }
                    else {
                        askQuestion(totalQuestions[i], score2, usedFiftyFifty2);
                        cout<<"Score "<<name2<<": "<<score2<<"\n";
                        qCount2++;
                    }
                    turn++; // switch turns
                    questionAsked = true;
                    break;
                }
            }
            // In case all questions used before reaching limits, break loop
            if(!questionAsked) break;
        }

        cout<<"\nFinal Scores:\n"<<name1<< ": "<<score1<<"\n"<<name2<<": "<<score2<<"\n";
        if(score1>score2)cout<<name1<<" wins!\n";
        else if(score2>score1)cout<<name2<<" wins!\n";
        else cout<<"It's a tie!\n";

        cout<<"\nDo you want to play again? (y/n): ";
        cin>>playAgain;
        cin.ignore();

    } while(playAgain=='y'||playAgain=='Y');

    return 0;
}

