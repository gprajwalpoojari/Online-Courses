 #include <iostream>
 #include <string>
 #include <vector>
 
 class Player {
 public:
    //attributes
    std::string name {"Hello"};
    int health {100};
    int xp;
    
    //methods
    std::string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
     void talk (std::string text_to_say) { std::cout << name << " says " << text_to_say << std::endl;}
     bool is_dead();
     
     //constructor
     Player (std::string name_val = "None", int health_val = 0, int xp_val = 0) ;
      //copy constructor
      Player(const Player &source);
      //destructor

 };
 
 class Account {
 private:
     //attributes
     std::string name;
     double balance;
     int *temp;
 public:
     //methods
     void deposit(double bal) { balance += bal; std::cout << "In deposit" <<std::endl;}
     void withdraw(double bal) {balance -= bal; std::cout << "In withdraw" << std::endl;}
     Account(std::string string_val  = "None", double balance_val = 0, int temp_val = 0);
     Account(const Account &source);
 };
 
 Account::Account(std::string string_val, double balance_val, int temp_val)
        : name {string_val}, balance {balance_val} {
              temp = new int;
            *temp = temp_val;
}

Account::Account(const Account &source)
        : Account(source.name, source.balance, *source.temp) {}
 
Player::Player(std::string name_val , int health_val , int xp_val )
        : name {name_val}, health {health_val}, xp {xp_val} {}
        
Player::Player(const Player &source)
        : Player(source.name, source.health, source.xp) {}
        
void display_player(Player p) {
    std::cout << p.get_name() << std::endl;
    std::cout << p.get_health() << std::endl;
    std::cout << p.get_xp() << std::endl;
    
}

 int main() {
     Player Jim;
     Player Tom {"Tom"};
     Player frank("Hi there", 40, 10);
     display_player(frank);
     frank.name = "Frank";
     frank.health = 100;
     frank.xp = 12;
     frank.talk("Hi there!");
     Player hero;
     
     Player *enemy = new Player;
     enemy -> name = "Enemy";
     enemy ->health = 100;
     enemy -> xp = 15;
     enemy -> talk ("I will destroy you.");
     delete enemy;
     
     Account frank_account;
    // frank_account.name = "Frank";
     //frank_account.balance = 5000;
     frank_account.deposit(1000);
     frank_account.withdraw (500);
     return 0;
 }