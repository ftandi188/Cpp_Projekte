#ifndef STORAGECOMPONENTCONTAINER_H_INCLUDED
#define STORAGECOMPONENTCONTAINER_H_INCLUDED


template <typename Elementtype>
class StorageComponentContainer;

template <typename Elementtype>
class StorageComponentContainerIterator
{
public:
    Elementtype** ItemPointer;

    StorageComponentContainerIterator<Elementtype>(Elementtype** Item)    //Konstruktor
                :ItemPointer(Item)
                {}


    StorageComponentContainerIterator<Elementtype> operator++(){     //Präinkrement
        ItemPointer++;
        return *this;
    }

    StorageComponentContainerIterator<Elementtype> operator++(int x){      //Postinkrement
        StorageComponentContainerIterator<Elementtype> Backup(*this);
        ItemPointer++;
        return Backup;
    }

    bool operator==(StorageComponentContainerIterator<Elementtype> rhs){     //Prüfe Gleichheit
        if(this->ItemPointer == rhs.ItemPointer){
            return true;
        }
        return false;
    }

    bool operator!=(StorageComponentContainerIterator<Elementtype> rhs){     //Prüfe Ungleichheit
        if(this->ItemPointer == rhs.ItemPointer){
            return false;
        }
        return true;
    }

    Elementtype& operator*(){            //Überladen: doppelte Dereferenzierung
        return **ItemPointer;
    }

    Elementtype* operator->(){           //Überladen: einfache Dereferenzierung
        return *ItemPointer;
    }
};

template <typename Elementtype>
class StorageComponentContainer
{
public:
    Elementtype** ContentList;       //Zeigt auf ein Pointer-Array
    int MaxSize;
    int CurrentSize;


    StorageComponentContainer<Elementtype>(int MSize=10)
            :CurrentSize(0), MaxSize(MSize)
            {
                ContentList = new Elementtype*[MSize];
            }

    ~StorageComponentContainer<Elementtype>(){
        for (int i=0; i<CurrentSize; i++){
            delete ContentList[i];
        }
        delete[] ContentList;
    }

    void add(Elementtype* NewOne){
        if(CurrentSize < MaxSize){
            ContentList[CurrentSize] = NewOne;
            CurrentSize++;
        }
    }

    Elementtype* operator[](int Index){
        return ContentList[Index];
    }

    int getNr(){
        return CurrentSize;
    }

    StorageComponentContainerIterator<Elementtype> begin(){
        return StorageComponentContainerIterator<Elementtype>(ContentList);
    }

    StorageComponentContainerIterator<Elementtype> end(){
        return StorageComponentContainerIterator<Elementtype>(ContentList + CurrentSize);
    }
};

#endif // STORAGECOMPONENTCONTAINER_H_INCLUDED
