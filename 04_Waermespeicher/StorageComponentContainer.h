#ifndef STORAGECOMPONENTCONTAINER_H_INCLUDED
#define STORAGECOMPONENTCONTAINER_H_INCLUDED

class StorageComponentContainer;


class StorageComponentContainerIterator
{
public:
    Boiler** ItemPointer;

    StorageComponentContainerIterator(Boiler** Item)    //Konstruktor
                :ItemPointer(Item)
                {}


    StorageComponentContainerIterator operator++(){     //Präinkrement
        ItemPointer++;
        return *this;
    }

    StorageComponentContainerIterator operator++(int x){      //Postinkrement
        StorageComponentContainerIterator Backup(*this);
        ItemPointer++;
        return Backup;
    }

    bool operator==(StorageComponentContainerIterator rhs){     //Prüfe Gleichheit
        if(this->ItemPointer == rhs.ItemPointer){
            return true;
        }
        return false;
    }

    bool operator!=(StorageComponentContainerIterator rhs){     //Prüfe Ungleichheit
        if(this->ItemPointer == rhs.ItemPointer){
            return false;
        }
        return true;
    }

    Boiler& operator*(){            //Überladen: doppelte Dereferenzierung
        return **ItemPointer;
    }

    Boiler* operator->(){           //Überladen: einfache Dereferenzierung
        return *ItemPointer;
    }
};


class StorageComponentContainer
{
public:
    Boiler** ContentList;       //Zeigt auf ein Pointer-Array
    int MaxSize;
    int CurrentSize;


    StorageComponentContainer(int MSize=10)
            :CurrentSize(0), MaxSize(MSize)
            {
                ContentList = new Boiler*[MSize];
            }

    ~StorageComponentContainer(){
        for (int i=0; i<CurrentSize; i++){
            delete ContentList[i];
        }
        delete[] ContentList;
    }

    void add(Boiler* NewOne){
        if(CurrentSize < MaxSize){
            ContentList[CurrentSize] = NewOne;
            CurrentSize++;
        }
    }

    Boiler* operator[](int Index){
        return ContentList[Index];
    }

    int getNr(){
        return CurrentSize;
    }

    StorageComponentContainerIterator begin(){
        return StorageComponentContainerIterator(ContentList);
    }

    StorageComponentContainerIterator end(){
        return StorageComponentContainerIterator(ContentList + CurrentSize);
    }
};

#endif // STORAGECOMPONENTCONTAINER_H_INCLUDED
