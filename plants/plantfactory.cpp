#include"plantfactory.h"
#include<iostream>
using namespace std;

plantfactory::plantfactory()
{

    t.loadFromFile("Images/options.png");
    s.setTexture(t);
    s.setPosition(0, 0);

    pst.loadFromFile("Images/peacard.png");
    pss.setTexture(pst);
    pss.setPosition(66, -5);

    sft.loadFromFile("Images/sunflowercard.png");
    sfs.setTexture(sft);
    sfs.setPosition(66 * 2, -5);

    ct.loadFromFile("Images/cherrycard.png");
    cs.setTexture(ct);
    cs.setPosition(66 * 3, -5);

    wt.loadFromFile("Images/card_wallnut.png");
    ws.setTexture(wt);
    ws.setPosition(66 * 4, -5);

    rt.loadFromFile("Images/repeatercard.png");
    rs.setTexture(rt);
    rs.setPosition(66 * 5, -5);

    spt.loadFromFile("Images/snowcard.png");
    sps.setTexture(spt);
    sps.setPosition(66 * 6, -5);

    pea = false;
    placed = false;
    sunf = false;
    ch = false;
    wa = false;
    r = false;
    sp = false;
    currency = 50;

    p = new plant * [45];
    for (int i = 0; i < 45; i++)
    {
        p[i] = NULL;
    }
    size = 0;
}

int plantfactory::handleinput(Event event, RenderWindow& window, int level, float gr[5][9][5], int& total, int y)//////////
{


    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {

        if (event.mouseButton.x >= 66 && event.mouseButton.x <= 66 * 2 && event.mouseButton.y >= 0 && event.mouseButton.y <= 90 && level >= 1 && level <= 3 && (total + y) >= 100)
        {
            placed = false;
            pea = true;
            offset = pss.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
        }

        else if (event.mouseButton.x >= 66 * 2 && event.mouseButton.x < 66 * 3 && event.mouseButton.y >= 0 && event.mouseButton.y <= 90 && level >= 1 && level <= 3 && (total + y) >= 50)
        {
            placed = false;
            sunf = true;
            offset = sfs.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
        }
        else if (event.mouseButton.x >= 66 * 3 && event.mouseButton.x < 66 * 4 && event.mouseButton.y >= 0 && event.mouseButton.y <= 90 && level >= 2 && level <= 3 && (total + y) >= 150)
        {
            placed = false;
            ch = true;
            offset = cs.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
        }
        else if (event.mouseButton.x >= 66 * 4 && event.mouseButton.x < 66 * 5 && event.mouseButton.y >= 0 && event.mouseButton.y <= 90 && level >= 2 && level <= 3 && (total + y) >= 50)
        {
            placed = false;
            wa = true;
            offset = ws.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
        }
        else if (event.mouseButton.x >= 66 * 5 && event.mouseButton.x <= 66 * 6 && event.mouseButton.y >= 0 && event.mouseButton.y <= 90 && level == 3 && (total + y) >= 200)
        {
            placed = false;
            r = true;
            offset = rs.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
        }
        else if (event.mouseButton.x >= 66 * 6 && event.mouseButton.x < 66 * 7 && event.mouseButton.y >= 0 && event.mouseButton.y <= 90 && level == 3 && (total + y) >= 175)
        {
            placed = false;
            sp = true;
            offset = sps.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
        }

    }

    else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
    {
        bool rel = true;
        if (event.mouseButton.x >= 220 && event.mouseButton.x <= 940 && event.mouseButton.y >= 65 && event.mouseButton.y <= 555 && level >= 1 && level <= 2)//////////////////
        {
            rel = false;
        }
        if (event.mouseButton.x >= 220 && event.mouseButton.x <= 440 && event.mouseButton.y >= 65 && event.mouseButton.y <= 555 && level ==3)
        {
            rel = false;
        }

        if(!rel)
        {
            int count = 0;

            int boxWidth = 80; // Width of each box in the grass grid
            int boxHeight = 98; // Height of each box in the grass grid

            int mouseX = event.mouseButton.x;
            int mouseY = event.mouseButton.y;

            mouseX -= 220;
            while (mouseX >= 80)
            {
                mouseX -= 80;
                count++;
            }
            mouseX = 220 + count * 80;
            mouseY -= 65;
            count = 0;
            while (mouseY >= 98)
            {
                mouseY -= 98;
                count++;
            }
            mouseY = 65 + count * 98;
            if (gr[(mouseY - 65) / 98][(mouseX - 220) / 80][3] == false)
            {
                /////////////////////

                  
                if (pea) {
                    placed = true;

                    p[size] = new peashooter(window, mouseX, mouseY);
                    gr[(mouseY - 65) / 98][(mouseX - 220) / 80][3] = true;
                    p[size]->setpx(mouseX);
                    p[size]->setpy(mouseY);
                    size++;
                    pea = false;
                  
                   
                    total -= 100;
               
                    return total ;
                }

                else if (sunf)
                {

                    placed = true;
                    p[size] = new sunflower(mouseX, mouseY);
                    gr[(mouseY - 65) / 98][(mouseX - 220) / 80][3] = true;
                    p[size]->setpx(mouseX);
                    p[size]->setpy(mouseY);
                    size++;
                    sunf = false;
                    total -= 50;
                    return total;
                }
                else if (ch)
                {

                    placed = true;
                    p[size] = new cherry(mouseX, mouseY);
                    p[size]->setpx(mouseX);
                    p[size]->setpy(mouseY);
                    size++;
                    ch = false;
                    total -= 150;
                    return total;
                }
                else if (wa)
                {

                    placed = true;
                    p[size] = new wallnut(mouseX, mouseY);
                    p[size]->setpx(mouseX);
                    p[size]->setpy(mouseY);

                    size++;
                    wa = false;
                    total -= 50;
                    return total ;
                }
                else if (r)
                {

                    placed = true;
                    p[size] = new repeater(window, mouseX, mouseY);
                    gr[(mouseY - 65) / 98][(mouseX - 220) / 80][3] = true;
                    p[size]->setpx(mouseX);
                    p[size]->setpy(mouseY);
                    size++;
                    r = false;
                    total -= 200;
                    return total ;
                }
                else if (sp)
                {

                    placed = true;
                    p[size] = new snowpea(window, mouseX, mouseY);
                    gr[(mouseY - 65) / 98][(mouseX - 220) / 80][3] = true;
                    p[size]->setpx(mouseX);
                    p[size]->setpy(mouseY);
                    size++;
                    sp = false;
                    total -= 175;
                    return total ;
                }
            }
        }


    }


    if (pea)
    {
        pss.setPosition(static_cast<float>(Mouse::getPosition(window).x) + offset.x, static_cast<float>(Mouse::getPosition(window).y) + offset.y);
    }

    else if (sunf)
    {
        sfs.setPosition(static_cast<float>(Mouse::getPosition(window).x) + offset.x, static_cast<float>(Mouse::getPosition(window).y) + offset.y);
    }
    else if (ch)
    {
        cs.setPosition(static_cast<float>(Mouse::getPosition(window).x) + offset.x, static_cast<float>(Mouse::getPosition(window).y) + offset.y);
    }
    else if (wa)
    {
        ws.setPosition(static_cast<float>(Mouse::getPosition(window).x) + offset.x, static_cast<float>(Mouse::getPosition(window).y) + offset.y);
    }
    else if (r)
    {
        rs.setPosition(static_cast<float>(Mouse::getPosition(window).x) + offset.x, static_cast<float>(Mouse::getPosition(window).y) + offset.y);
    }
    else if (sp)
    {
        sps.setPosition(static_cast<float>(Mouse::getPosition(window).x) + offset.x, static_cast<float>(Mouse::getPosition(window).y) + offset.y);
    }

}

void plantfactory::draw(RenderWindow& window, int level)
{

    window.draw(s);
    if (!placed)
    {
        window.draw(pss);
        window.draw(sfs);
        window.draw(cs);
        window.draw(ws);
        window.draw(rs);
        window.draw(sps);
    }
    else if (placed)
    {
        pss.setPosition(66, -5);
        window.draw(pss);
        sfs.setPosition(66 * 2, -5);
        window.draw(sfs);
        cs.setPosition(66 * 3, -5);
        window.draw(cs);
        ws.setPosition(66 * 4, -5);
        window.draw(ws);
        rs.setPosition(66 * 5, -5);
        window.draw(rs);
        sps.setPosition(66 * 6, -5);
        window.draw(sps);

    }





    for (int i = 0; i < size; i++)
    {

        p[i]->draw(window);
        if (p[i]->b != NULL && p[i]->getlife() > 0)///////////
        {
            p[i]->b->movebullet();
            p[i]->b->draw(window);

        }
        p[i]->updatecherry(window);
        if (p[i]->getmove())
        {
            p[i]->moveup(window);
        }
        else
        {
            p[i]->diagnal_up(window);
        }

    }

}
plantfactory:: ~plantfactory()
{
    for (int i = 0; i < size; i++)
    {

        delete p[i];
    }
    delete[] p;
}
void plantfactory::setcurrency(sun* s)
{
    /*
     for (int i = 0; i < size; i++)
     {
         currency+=p[i]->getprice();
     }*/


}
int plantfactory::getcurrency()
{
    return currency;
}
