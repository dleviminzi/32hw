#include <iostream>
#include <string>
using namespace std;

class Event 
{
    public:
        Event(string name);
        void setSport(bool spt);
        virtual ~Event();
        string name() const;
        virtual string need() const = 0;
        bool isSport() const;
    private:
        string nm;
        bool sport;
};

Event::Event(string name)
{
    nm = name; 
}

Event::~Event() {};

string Event::name() const
{
    return nm;
}

bool Event::isSport() const
{
    return sport;
}

void Event::setSport(bool spt)
{
    sport = spt;
}

class BasketballGame : public Event 
{
    public:
        BasketballGame(string name);
        virtual string need() const;
        virtual ~BasketballGame();
    private:
};

BasketballGame::BasketballGame(string name) : Event(name)
{
    setSport(true);
}

string BasketballGame::need() const { return "hoops"; }

BasketballGame::~BasketballGame()
{
    cout << "Destroying the " << name() << " basketball game" << endl;
}

class Concert : public Event
{
    public:
        Concert(string name, string genre);
        virtual string need() const;
        ~Concert();
    private:
        string gn;
};

Concert::Concert(string name, string genre)
    : Event(name)
{
    setSport(false);
    gn = genre;
}

string Concert::need() const { return "stage"; }

Concert::~Concert()
{
    cout << "Destroying the " << name() << " " << gn << " concert" << endl;
}

class HockeyGame : public Event
{
    public:
        HockeyGame(string name);
        virtual string need() const;
        ~HockeyGame();
    private:
};

HockeyGame::HockeyGame(string name) 
    : Event(name)
{
    setSport(true);
}

string HockeyGame::need() const { return "ice"; }

HockeyGame::~HockeyGame()
{
    cout << "Destorying the " << name() << " hockey game" << endl;
}

void display(const Event* e) 
{
    cout << e->name() << ": ";
    if (e->isSport())
        cout << "(sport) ";
    cout << "needs " << e->need() << endl;
}

int main() 
{
    
    Event* events[4];
    events[0] = new BasketballGame("Lakers vs. Suns");
        // Concerts have a name and a genre
    events[1] = new Concert("Banda MS", "banda");
    events[2] = new Concert("KISS", "hard rock");
    events[3] = new HockeyGame("Kings vs. Flames");

    cout << "Here are the events." << endl;
    for (int k = 0; k < 4; k++)
        display(events[k]);

        // Clean up the events before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete events[k];
       
    // new Event("Please dont work");
}
