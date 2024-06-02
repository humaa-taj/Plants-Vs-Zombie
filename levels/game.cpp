
#include"game.h"
game::game() : b(false), isPaused(false)
{
    window.create(VideoMode(1400, 600), "Plants Vs Zombies");
    icon.loadFromFile("Images/icon.png");
    window.setIcon(32, 32, icon.getPixelsPtr());
    l = new level * [9];
    l[0] = new level1(window, 1);
    l[1] = new level2(window, 2);
    l[2] = new level3(window, 3);
    l[3] = new level1(window, 1);
    l[4] = new level2(window, 2);
    l[5] = new level3(window, 3);
    l[6] = new level1(window, 1);
    l[7] = new level2(window, 2);
    l[8] = new level3(window, 3);
    l1 =true; l2 = false; l3 = false; lifeoflevel1 = 3; lifeoflevel2 = 3; lifeoflevel3 = 3;
    highscore = 0;
    gamewon = false;
    reading = "score.txt";
    for (int i = 0; i < 3; i++)
    {
        top[i] = "";
        topscore[i] = 0;
    }

}
void game::createBack(RenderWindow& window)
{
    if (l1 && !l2 && !l3)

    {
        map_image.loadFromFile("Images/level1.jpg");
    }
    else if (l3 && !l1 && !l2)
    {
        map_image.loadFromFile("Images/limitedarea.jpg");
    }
    else if (l2 && !l1 && !l3)
    {
        map_image.loadFromFile("Images/night.jpg");
    }
    else if (!l1 && !l2 && !l3 && !gamewon)
    {
        map_image.loadFromFile("Images/end.jpg");
    }
    else if (!l1 && !l2 && !l3 && gamewon)
    {
        {
            map_image.loadFromFile("Images/winn.jpg");
        }
    }

    map.loadFromImage(map_image);
    s_map.setTexture(map);
    s_map.setPosition(0, 0);
    window.draw(s_map);


}


bool game::creategame()

{

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            {
                window.close();

                return false;
              
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
            {

                isPaused = !isPaused;
            }
        }


        window.clear();

        if (!isPaused)
        {

            if (b == false)
            {
                m.display(window, event);
                b = m.handleInput(window, event);
            }
            else if (b)
            {
                createBack(window);
                // window.draw(zs);
                if (l1 == true && lifeoflevel1 == 3)////////////
                {
                    l[0]->startgame(window, event);
                    setter(l[0]->changelevel(), 1);
                }
                else if (l2 == true && lifeoflevel2 == 3)
                {
                    l[1]->startgame(window, event);
                    setter(l[1]->changelevel(), 2);
                }
                else if (l3 == true && lifeoflevel3 == 3)
                {
                    l[2]->startgame(window, event);
                    setter(l[2]->changelevel(), 3);
                }

                else if (l1 == true && lifeoflevel1 == 2)
                {
                    l[3]->startgame(window, event);
                    setter(l[3]->changelevel(), 1);
                }
                else if (l2 == true && lifeoflevel2 == 2)
                {
                    l[4]->startgame(window, event);
                    setter(l[4]->changelevel(), 2);
                }
                else if (l3 == true && lifeoflevel3 == 2)
                {
                    l[5]->startgame(window, event);
                    setter(l[5]->changelevel(), 3);
                }


                else if (l1 == true && lifeoflevel1 == 1)
                {
                    l[6]->startgame(window, event);
                    setter(l[6]->changelevel(), 1);
                }
                else if (l2 == true && lifeoflevel2 == 1)
                {
                    l[7]->startgame(window, event);
                    setter(l[7]->changelevel(), 2);
                }
                else if (l3 == true && lifeoflevel3 == 1)
                {
                    l[8]->startgame(window, event);
                    setter(l[8]->changelevel(), 3);
                }
            }
        }
        else
        {
            /* Texture pau;
             pau.loadFromFile("Images/paus.png");
             Sprite paus;
             paus.setTexture(pau);
             paus.setPosition(450, 100);
             paus.setScale(3, 3);
             window.draw(paus);
             window.display();*/
            window.clear();
            createBack(window);
            Font fontt;
            fontt.loadFromFile("font.ttf");
            /* Text tex("Game Paused", fontt, 65);
             tex.setFillColor(Color::White);
             tex.setPosition(430, 160);
             window.draw(tex);*/
            writing.open(reading, ios::app);

            if (writing)
            {
                writing << m.iS << " " << highscore << endl;
                writing.close();
            }
            writing.close();
            const int m = 100;
            hs high[m];
            int c = 0;

            f.open(reading);
            if (f.is_open())
            {
                while (c < m && f >> high[c].na >> high[c].sc)
                {
                    c++;
                }
                for (int i = 0; i < c - 1; i++)
                {
                    for (int j = 0; j < c - i - 1; j++)
                    {
                        if (high[j].sc < high[j + 1].sc)
                        {
                            swap(high[j], high[j + 1]);
                        }
                    }
                }
                f.close();

                Text head;
                head.setFont(fontt);
                head.setString("Highscores:");
                head.setCharacterSize(40);
                head.setFillColor(Color::Black);
                head.setPosition(300, 100);
                window.draw(head);

                Sprite S1;
                Texture S1t;
                S1t.loadFromFile("Images/1m.jpg");
                S1.setTexture(S1t);
                S1.setPosition(200, 200);
                window.draw(S1);
                Sprite S2;
                Texture S2t;
                S2t.loadFromFile("Images/2m.jpg");
                S2.setTexture(S2t);
                S2.setPosition(200, 300);
                window.draw(S2);
                Sprite S3;
                Texture S3t;
                S3t.loadFromFile("Images/3m.jpg");
                S3.setTexture(S3t);
                S3.setPosition(200, 400);
                window.draw(S3);

                int posY = 200;
                for (int i = 0; i < 3; i++)
                {
                    Text nt;
                    nt.setFont(fontt);
                    nt.setString(high[i].na + ": " + to_string(high[i].sc));
                    nt.setCharacterSize(35);
                    nt.setFillColor(Color::White);
                    nt.setPosition(300, posY);
                    window.draw(nt);
                    posY += 100;
                }
            }
         
            window.display();
            while (isPaused)
            {

                Event resumeEvent;
                while (window.pollEvent(resumeEvent))
                {
                    if (resumeEvent.type == Event::KeyPressed && resumeEvent.key.code == Keyboard::Space)
                    {
                        isPaused = false;
                    }
                    if (resumeEvent.type == Event::Closed || resumeEvent.type == Event::KeyPressed && resumeEvent.key.code == Keyboard::Escape)
                    {
                        window.close();
                        return false;
                    }
                }
            }
        }


        window.display();
    }


}

void game::setter(int lev, int num)////////////
{
    if (lev == 1)
    {
        if (lifeoflevel1 == 3)
        {
            lifeoflevel1--;

        }
        else if (lifeoflevel1 == 2)
        {
            lifeoflevel1--;
        }
        else if (lifeoflevel1 == 1)
        {
            lifeoflevel1--;
            // l2 = true;
            l1 = false;
        }
    }
    else if (lev == 2)

    {
        if (lifeoflevel2 == 3)
        {
            lifeoflevel2--;

        }
        else if (lifeoflevel2 == 2)
        {
            lifeoflevel2--;
        }
        else if (lifeoflevel2 == 1)
        {
            lifeoflevel2--;
            //  l3 = true;
            l2 = false;
            l1 = false;

        }

    }
    else if (lev == 3)

    {
        if (lifeoflevel3 == 3)
        {
            lifeoflevel3--;

        }
        else if (lifeoflevel3 == 2)
        {
            lifeoflevel3--;
        }
        else if (lifeoflevel3 == 1)
        {
            lifeoflevel3--;
            l3 = false;
            l2 = false;
            l1 = false;
            cout << "game end" << endl;
        }
    }
    else if (lev == 20)
    {
        if (num == 1)
        {
            l1 = false;
            l2 = true;
            l3 = false;
            highscore += 100;
        }
        else if (num == 2)
        {
            l1 = false;
            l2 = false;
            l3 = true;
            highscore += 200;
        }
        else if (num == 3)
        {

            l1 = false;
            l2 = false;
            l3 = false;
            gamewon = true;
            highscore += 300;
           
        }
    }

}

game::~game()
{

    for (int i = 0; i < 9; i++)//////////
    {

        delete l[i];
    }
    delete[] l;
}