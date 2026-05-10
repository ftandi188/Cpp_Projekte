#include <iostream>
#include <sstream>
#include "WinAdapt.h"
#include "Stages.h"
#if STAGE >= CREATE_COMPONENTS
#include "Boiler.h"
#include "Burner.h"
#endif
#if STAGE >= CREATE_PIPELINES
#include "Pipeline.h"
#endif
#if STAGE == CREATE_CONTAINER || STAGE == CREATE_TEMPLATE
#include "StorageComponentContainer.h"
#endif

using namespace std;

#if STAGE == CREATE_COMPONENTS || STAGE == INTEGRATE_COMPONENTS || STAGE == CREATE_PIPELINES
Boiler B1 ( "Kessel 1", Point(120  ,30) , Point(130 ,100) ,10 ,30);
Boiler B2 ( "Kessel 2", Point(400 ,200) , Point(100 ,130));
#endif

#if STAGE == CREATE_COMPONENTS
Burner Bu0 (nullptr, "Brenner 0", Point(70,230));
#endif

#if STAGE == CREATE_CONTAINER || STAGE == CREATE_TEMPLATE
#define NUM_BOILERS 4
Point BoilerPositions[NUM_BOILERS]={Point(20,20), Point(400,20),
                                        Point (400,260), Point(20,260)};
string BoilerNames[NUM_BOILERS]={"Agnetha", "Benny", "Bjoern", "Frida"};
#endif
#if STAGE == CREATE_CONTAINER
StorageComponentContainer BoilerList;
#endif

#if STAGE == CREATE_PIPELINES
Pipeline P1 (&B1, &B2);
#endif

#if STAGE == CREATE_TEMPLATE
StorageComponentContainer<Boiler> BoilerList;
StorageComponentContainer<Pipeline> PipelineList;
#endif

double AmountRequested = 0.0;
double TemperatureRequested = 0.0;

void VtlZyk(void)
{

}

void VtlMouse(int X, int Y)
{
#if STAGE == CREATE_CONTAINER || STAGE == CREATE_TEMPLATE
#if ERROR_HANDLING
    try
    {
#endif
    for (auto& Item : BoilerList)
    {
        if (Item.contains(Point(X, Y)))
        {
            Item.activateHeating(0.01);
        }
    }
#if ERROR_HANDLING
    }
    catch (ExceptionBoilerOverheating& a)
    {
        std::cout << a.what() << std::endl;
    }
#endif
#endif
#if STAGE == CREATE_TEMPLATE
    for (auto& Item : PipelineList)
    {
        if (Item.contains(Point(X, Y)))
        {
            Item.transferMedium(1);
        }
    }
#endif
#if STAGE == INTEGRATE_COMPONENTS
    if (B1.contains(Point(X,Y)))
    {
       B1.activateHeating(0.01);
    }
    if (B2.contains(Point(X,Y)))
    {
       B2.activateHeating(0.01);
    }
#endif
#if STAGE == CREATE_PIPELINES
    if (P1.contains(Point(X,Y)))
    {
       P1.transferMedium(1);
    }
#endif
}


void VtlKeyHit(int key)
{
// ADD your "BASIC KEY OPERATIONS" here, see manual
// important: ensure *not* to modify the value of "key"

    if((key > 48)&&(key < 58)){         //Prüfe, ob Zahl zwischen 1 und 9
        AmountRequested = (key - 48)*10;
    }

    if((key > 64)&&(key < 91)){         //Prüfe, ob Großbuchstabe
        TemperatureRequested = (key - 64)*5;
    }



// Do not change the following code lines
#if STAGE == CREATE_CONTAINER || STAGE == CREATE_TEMPLATE
    if (key >='a' && key <= 'd')
    {
        BoilerList[key-'a']->addContent(TemperatureRequested, AmountRequested);
    }
    if (key >='\001' && key <= '\004')
    {
#if ERROR_HANDLING
        try
        {
#endif // ERROR_HANDLING
            BoilerList[key-'\001']->activateHeating(0.01);
#if ERROR_HANDLING
        }
        catch (const ExceptionBoilerOverheating& a)
        {
            std::cout << a.what() << std::endl;
        }
#endif // ERROR_HANDLING
    }
#endif
#if STAGE == CREATE_COMPONENTS || STAGE == INTEGRATE_COMPONENTS
    if (key ==',')
    {
        B1.addHeat(100.0);
    }
    if (key =='.')
    {
        B2.addHeat(100.0);
    }
    if (key ==';')
    {
        B1.addContent(TemperatureRequested, AmountRequested);
    }
    if (key ==':')
    {
        B2.addContent(TemperatureRequested, AmountRequested);
    }
    #endif
    #if STAGE == CREATE_COMPONENTS
    if (key ==' ')
    {
        Bu0.feedFuel(0.01);
    }
#endif
#if STAGE == INTEGRATE_COMPONENTS
    if (key =='*')
    {
        B1.activateHeating(.01);
    }
    if (key =='#')
    {
        B2.activateHeating(.01);
    }
#endif
}

void VtlInit(void)
{
    setWindowTitle("Waermespeicheranlage");
#if STAGE == CREATE_CONTAINER || STAGE == CREATE_TEMPLATE
    for (int i=0; i<4; i++)
    {
        BoilerList.add(new Boiler(BoilerNames[i], BoilerPositions[i]));
    }
#endif
#if STAGE == CREATE_TEMPLATE
    for (int i=0; i<4; i++)
    {
        PipelineList.add(new Pipeline(BoilerList[i],
                                      BoilerList[(i+1)%4]));
    }
#endif
}

void VtlPaint(int xl, int yo, int xr, int yu)
{
#if STAGE == CREATE_TEMPLATE
    for (auto& Item : PipelineList)
    {
        Item.show();
    }
#endif
#if STAGE == CREATE_PIPELINES
    P1.show();
#endif

#if STAGE == CREATE_COMPONENTS || STAGE == INTEGRATE_COMPONENTS || STAGE == CREATE_PIPELINES
    B1.show();
    B2.show();
#endif
#if STAGE == CREATE_COMPONENTS
    Bu0.show();
#endif
#if STAGE == CREATE_CONTAINER || STAGE == CREATE_TEMPLATE
    for (auto& Item : BoilerList)
    {
        Item.show();
    }
#endif
    stringstream Textbuffer;
    Textbuffer << "Volumen: " << AmountRequested << " Liter";
    Text(xl+20, yu-30, Textbuffer.str().c_str());
    Textbuffer.str("");
    Textbuffer << "Temperatur: " << TemperatureRequested << " Grad C";
    Text(xl+250, yu-30, Textbuffer.str().c_str());
}

