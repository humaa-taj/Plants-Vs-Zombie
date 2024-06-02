#include"sunflower.h"
#include"iostream"
using namespace std;
sunflower::sunflower(int px, int py, int l, int p, bool a, int c, bool e) :su(0, px + 10, py + 20)
{
    setpx(px);
    setpy(py);
    t.loadFromFile("Images/img2.png");
    //+++++++++++
    setcherry(false);
    setnut(false);
    s.setTexture(t);
    s.setPosition(px, py);
    b = NULL;
}
void sunflower::draw(RenderWindow& window, Event event)
{


}
void sunflower::draw(RenderWindow& window)
{



    if (getlife() > 0)//////////
    {
        window.draw(s);

        // Check if it's time to spawn a sun
        if (!su.getalive() && su.despawnClock.getElapsedTime().asSeconds() >= 10)
        {

            // Set the sun's position relative to the sunflower
            su.set(getpx() + 10, getpy() + 20, true);
            su.setalive(true);
            su.despawnClock.restart();
        }
        if (su.handleinput(window))////////////////
        {

            setprice(su.getcollected());
        }
        // Display the sun
        su.draw(window);

    }
    else if (getlife() <= 0)
    {
        setalive(false);
        su.setalive(false);
    }



}