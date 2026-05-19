#ifndef STORAGECOMPONENTCONTAINER_H_INCLUDED
#define STORAGECOMPONENTCONTAINER_H_INCLUDED

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

};

#endif // STORAGECOMPONENTCONTAINER_H_INCLUDED
