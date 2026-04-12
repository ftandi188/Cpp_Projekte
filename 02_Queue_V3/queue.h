class QueueElement;     //Kurzdeklaration

class Queue{
public:

    QueueElement* FirstElement;
    QueueElement* LastElement;

    Queue();
    Queue(QueueElement* InitialElement);
    ~Queue();               //Destruktor

    QueueElement* getFirstElement();
    QueueElement* getLastElement();
    void push(QueueElement* NewItem);
    void pop();
    void insert(QueueElement* NewItem, unsigned Position);
    bool isEmpty();
    void clear();
    unsigned size();        //Kurzschreibweise für unsigned int size();
    void print();

    //insert, clear und size sind keine reservierten Schlüsselwörter
};

