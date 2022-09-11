#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "betText.h"
#include "fieldBet.h"
#include "Roulette.h"
#include "windows.h"
#include <ctime>
#include "Sprites.h"

using namespace sf;
using namespace std;

bool betPlaced = false, betBarEnable = false, first = true, fieldBarEnable = false,launch=false,fieldPicked=false,en=true;

int fieldType = 0;

int field_on = 0;

int balance = 1000, pickedField = NULL;

int x = 549;
int posX = 295;

int i = 0;

int nums[16] = { 24,16,33,1,20,9,18,28,35,0,32,19,22,17,7,30 };





void main()
{
	RenderWindow window(VideoMode(1280, 720), "Roulette", Style::Titlebar | Style::Close);


	SoundBuffer rotBuf,kekBuf,vjBuf,kazBuf;
	rotBuf.loadFromFile("sounds/rot.wav");
	kekBuf.loadFromFile("sounds/kek.wav");
	vjBuf.loadFromFile("sounds/vj.wav");
	kazBuf.loadFromFile("sounds/kazeniy.wav");
	Sound vj(vjBuf);
	Sound rot(rotBuf);
	Sound kek(kekBuf);
	Sound kaz(kazBuf);
	rot.setVolume(50);
	kek.setVolume(50);
	vj.setVolume(10);
	kaz.setVolume(30);

	Music music;
	music.openFromFile("sounds/casino.wav");
	music.setVolume(20);
	
	music.setLoop(true);

	Sound soundsLose[3] = { rot,kek,vj };
	Sound soundsWin[1] = { kaz };

	Font font;
	font.loadFromFile("unispace bd.ttf");
	Text fieldStatus("Field: ",font,30);
	fieldStatus.setOutlineColor(Color::Black);
	fieldStatus.setOutlineThickness(2);
	fieldStatus.setPosition(0, 510);
	Text txt("Balance:", font, 30);
	txt.setOutlineColor(Color::Black);
	txt.setOutlineThickness(2);
	txt.setPosition(0, 0);
	string type="-";

	Text status;
	font.loadFromFile("unispace bd.ttf");
	status.setFont(font);
	status.setOutlineColor(Color::Black);
	status.setOutlineThickness(5);
	status.setPosition(500, 260);
	status.setCharacterSize(100);

	txt.setString("Balance:" + to_string(balance));

	textBox bet;

	fieldBetBox fieldBet;

	Roulette roulette;

	CircleShape circle(7.f);
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(2);
	circle.setPosition(981,515);

	Image anim;
	anim.loadFromFile("images/anim.png");

	Texture animTex;

	Button rouletteT("roll3.png", 700, 50), field("field1.png", 0, 0), f1("1.png", 0, 670), f10("10.png", 70, 670), f100("100.png", 140, 670),
		f1000("1000.png", 210, 670), max("max.png", 280, 670), start_e("butStart.png", 1030, 640), del_e("clear.png", 780, 640), place_e("butPlace.png", 530, 640), bets_e("bets.png", 400, 0),
		start_r("rollr.png", 1030, 640), del_r("clearr.png", 780, 640), place_r("placer.png", 530, 640), bets_r("betsr.png", 400, 0),
		play("play.png", 525, 219), exit("exit.png", 525, 419), about("about.png", 525, 319), menuBg("background.png", 0, 0), aboutBg("about1.png", 0, 0),
		rus("rus.png", 1130, 0), eng("eng2.png", 1130, 0), play_r("playr.png", 525, 219), exit_r("exitr.png", 525, 419), about_r("aboutrpsd.png", 525, 319),
		aboutBg_r("aboutr.png", 0, 0), fieldb("fieldb.png", 0, 0), fieldm("fieldm.png", 0, 0), fielde("fielde.png", 0, 0),shope("shope.png",10,70), 
		shopr("shopr.png", 10, 70),shopbge("shopbge.png",340,60), shopbgr("shopbgr.png", 340, 60);

	bool isMenu = 1;
	int menuNum = 0;

	animTex.loadFromImage(anim);


	Sprite animSprite;

	animSprite.setTexture(animTex);
	animSprite.setPosition(700, 50);

	Clock clock;

	Bets list;

	int prof = 0;

	int users[3];

	/*menu(window, en,balance,prof);*/

	music.play();

	while (window.isOpen())
	{
		
		window.setFramerateLimit(60);

		float fps = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		fps = fps / 800;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		

		while (isMenu)
		{
			menuNum = 0;
			window.clear();

			if (IntRect(525, 219, 180, 60).contains(Mouse::getPosition(window))) { menuNum = 1; }
			if (IntRect(525, 319, 180, 60).contains(Mouse::getPosition(window))) { menuNum = 2; }
			if (IntRect(525, 419, 180, 60).contains(Mouse::getPosition(window))) { menuNum = 3; }
			if (IntRect(1130, 0, 1280, 120).contains(Mouse::getPosition(window))) { menuNum = 4; }

			while (window.pollEvent(e))
			{
				if (e.type == Event::Closed)
				{
					isMenu = 0;
					window.close();
				}
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) profiles(window, en, isMenu, menuBg, balance, prof,e);//isMenu = false;
				if (menuNum == 2)
				{
					if (en == true)
					{
						window.draw(about.sprite); window.display();
						while (!Keyboard::isKeyPressed(Keyboard::Escape))
						{
							window.draw(aboutBg.sprite); window.display();
						}
					}
					else
					{
						window.draw(about_r.sprite); window.display();
						while (!Keyboard::isKeyPressed(Keyboard::Escape))
						{
							window.draw(aboutBg_r.sprite); window.display();
						}
					}
				}
				if (menuNum == 3) { window.close(); isMenu = false; }
				if (menuNum == 4)
				{
					if (en == true)
					{
						en = false;
						sleep(seconds(0.1));
					}
					else
					{
						en = true;
						sleep(seconds(0.1));
					}
				}

			}
			

			window.clear();
			if (en == true)
			{
				window.draw(menuBg.sprite);
				window.draw(about.sprite);
				window.draw(play.sprite);
				window.draw(exit.sprite);
			}
			else
			{
				window.draw(menuBg.sprite);
				window.draw(about_r.sprite);
				window.draw(play_r.sprite);
				window.draw(exit_r.sprite);
			}
			if (en == true)
				window.draw(eng.sprite);
			else
				window.draw(rus.sprite);

			window.display();
		}

		if (e.type == Event::TextEntered)
		{
			bet.input(e, betBarEnable);
		}

		if (e.type == Event::TextEntered)
		{
			fieldBet.inputField(e, fieldBarEnable);
		}

		//exit in menu
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			isMenu = 1;
		}

		//info
		if (Keyboard::isKeyPressed(Keyboard::Tab))  //Keyboard::isKeyPressed(Keyboard::Tab)
		{
			if (en == true)
				window.draw(bets_e.sprite);
			else
				window.draw(bets_r.sprite);
			list.draw_bets(window);
			window.display();
		}

		//tracker
		if (e.type == Event::MouseButtonPressed)
		{
			if (e.key.code == Mouse::Left)
			{
				float x = Mouse::getPosition(window).x;
				float y = Mouse::getPosition(window).y;
				// place //
				if (x >= 530 && y >= 640 && x <= 710 && y <= 700 && bet.betValue > 0 && bet.betValue <= balance && fieldBet.fieldValue >= 0&& fieldBet.fieldValue <= 36&& list.max_bets()==false)
				{
					betPlaced = true;
					balance -= bet.betValue;
					pickedField = fieldBet.fieldValue;
					list.set_bet(bet,fieldBet);
					sleep(seconds(0.1));
				}
				else if (x >= 530 && y >= 640 && x <= 710 && y <= 700 && bet.betValue > 0 && bet.betValue <= balance && fieldPicked == true&& list.max_bets() == false)
				{
					betPlaced = true;
					balance -= bet.betValue;
					list.set_bet(bet,fieldBet);
					sleep(seconds(0.1));
				}
				//clear//
				if (x >= 780 && y >= 640 && x <= 960 && y <= 700)
				{
					bet.betValue = 0;
					fieldBet.fieldValue = NULL;
					fieldType = 0;
					type = "-";
				}
				//start//
				if (x >= 1030 && y >= 640 && x <= 1210 && y <= 700&& betPlaced==true)
				{
					betBarEnable = false;
					fieldBarEnable = false;
					launch = true;
					first = false;
					roulette.timer();
				}
				//shop//
				if (x >= 10 && y >= 70 && x <= 190 && y <= 130)
				{
					bool shop = 1;
					int num = 0;
					while (shop == 1)
					{
						while (window.pollEvent(e))
						{
							if (e.type == Event::Closed)
							{
								shop = 0;
								window.close();
							}
						}

						if (Keyboard::isKeyPressed(Keyboard::Escape))
						{
							shop = 0;
							sleep(seconds(0.3));
						}

						if (e.type == Event::MouseButtonPressed)
						{
							if (e.key.code == Mouse::Left)
							{
								float x = Mouse::getPosition(window).x;
								float y = Mouse::getPosition(window).y;

								if (x >= 380 && y >= 130 && x <= 574 && y <= 241)
								{
									num = 1;
									purchase(num, window,balance,field_on,prof);
									shop = 0;
								}

								if (x >= 713 && y >= 130 && x <= 907 && y <= 241)
								{
									num = 2;
									purchase(num, window, balance, field_on,prof);
									shop = 0;
								}

								if (x >= 544 && y >= 329 && x <= 738 && y <= 437)
								{
									num = 3;
									purchase(num, window, balance, field_on,prof);
									shop = 0;
								}
							}
						}

						if (en == 1)
						{
							window.draw(shopbge.sprite);
						}
						else
						{
							window.draw(shopbgr.sprite);
						}
						window.display();
					}
				}
				//field picker//
				if (x >= 0 && y >= 550 && x <= 200 && y <= 585)
				{
					fieldBarEnable = true;
					betBarEnable = false;
				}
				//bet picker//
				if (x >= 0 && y >= 600 && x <= 200 && y <= 635)
				{
					fieldBarEnable = false;
					betBarEnable = true;
				}
				//1//
				if (x >= 0 && y >= 670 && x <= 50 && y <= 720)

				{
					bet.betValue += 1;
					sleep(seconds(0.1));
				}
				//10//
				if (x >= 70 && y >= 670 && x <= 120 && y <= 720)
				{
					bet.betValue += 10;
					sleep(seconds(0.1));
				}
				//100//
				if (x >= 140 && y >= 670 && x <= 190 && y <= 720)
				{
					bet.betValue += 100;
					sleep(seconds(0.1));
				}
				//1k//
				if (x >= 210 && y >= 670 && x <= 260 && y <= 720)
				{
					bet.betValue += 1000;
					sleep(seconds(0.1));
				}
				//max//
				if (x >= 280 && y >= 670 && x <= 330 && y <= 720)
				{
					bet.betValue = balance;
					sleep(seconds(0.1));
				}
				//red//
				if (x >= 273 && y >= 461 && x <= 338 && y <= 507 )
				{
					type = "Red";
					fieldType = 1;
					fieldPicked = true;
					list.set_type("Red");
				}
				//black//
				if (x >= 341 && y >= 461 && x <= 407 && y <= 507) 
				{ 
					type = "Black";
					fieldType = 2;
					fieldPicked = true;
					list.set_type("Black");
				}
				//1 col//
				if (x >= 133 && y >= 417 && x <= 270 && y <= 458 ) 
				{
					type = "1st 12";
					fieldType = 3;
					fieldPicked = true;
					list.set_type("1st 12");
				}
				//2 col//
				if (x >= 273 && y >= 417 && x <= 407 && y <= 458 )
				{
					type = "2nd 12";
					fieldPicked = true;
					fieldType = 4;
					list.set_type("2nd 12");
				}
				//3 col//
				if (x >= 410 && y >= 417 && x <= 547 && y <= 458 )
				{
					type = "3rd 12";
					fieldPicked = true;
					fieldType = 5;
					list.set_type("3rd 12");
				}
				//1 half//
				if (x >= 133 && y >= 461 && x <= 199 && y <= 507 )
				{
					type = "1-18";
					fieldPicked = true;
					fieldType = 6;
					list.set_type("1-18");
				}
				//2 half//
				if (x >= 482 && y >= 461 && x <= 549 && y <= 509 )
				{
					type = "19-36";
					fieldType = 7;
					fieldPicked = true;
					list.set_type("19-36");
				}
				//even//
				if (x >= 202 && y >= 461 && x <= 270 && y <= 507 )
				{
					type = "Even";
					fieldPicked = true;
					fieldType = 8;
					list.set_type("Even");
				}
				//odd//
				if (x >= 410 && y >= 461 && x <= 479 && y <= 507)
				{
					type = "Odd";
					fieldType = 9;
					fieldPicked = true;
					list.set_type("Odd");
				}
				//1 row//
				if (x >= 550 && y >= 179 && x <= 582 && y <= 258)
				{
					type = "First 2 to 1";
					fieldPicked = true;
					fieldType = 10;
					list.set_type("First 2 to 1");
				}
				//2 row//
				if (x >= 550 && y >= 261 && x <= 582 && y <= 334)
				{
					type = "Second 2 to 1";
					fieldPicked = true;
					fieldType = 11;
					list.set_type("Second 2 to 1");
				}
				//3 row//
				if (x >= 550 && y >= 337 && x <= 582 && y <= 414 )
				{
					type = "Third 2 to 1";
					fieldPicked = true;
					fieldType = 12;
					list.set_type("Third 2 to 1");
				}
				fieldStatus.setString("Field: "+type);
			}
		}

			//roll
			while (launch==true)	
			{				
				if (roulette.stop_rol() == true)
				{
					i++;
					cout << nums[i];
					bool checkWin = false;

					if (nums[i] == fieldBet.fieldValue)
					{
						checkWin = true;
						balance += (5 * bet.betValue);
					}
					
					if (fieldPicked == true)
					{
						if (fieldType==1)
						{
							if (roulette.check_red(nums, i) == true)
							{
								checkWin = true;
								balance += bet.betValue;
							}
						}

						if (fieldType==2)
						{
							if (roulette.check_black(nums, i) == true)
							{
								checkWin = true;
								balance += bet.betValue;
							}
						}

						if (fieldType==3)
						{
							if (roulette.check_firstC(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if (fieldType==4)
						{
							if (roulette.check_secondC(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if (fieldType==5)
						{
							if (roulette.check_thirdC(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if (fieldType == 6)
						{
							if (roulette.check_firstR(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if (fieldType == 7)
						{
							if (roulette.check_secondR(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if (fieldType == 8)
						{
							if (roulette.check_thirdR(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if (fieldType == 9)
						{
							if (roulette.check_firstH(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if(fieldType == 10)
							if (roulette.check_secondH(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}

						if (fieldType == 11)
						{
							if (roulette.check_even(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}

						if (fieldType == 12)
						{
							if (roulette.check_odd(nums, i) == true)
							{
								checkWin = true;
								balance += 2 * bet.betValue;
							}
						}
					}

					if (checkWin == true)
					{
						window.clear(Color::Color(7, 112, 7));
						status.setString("WIN");
						window.draw(status);
						window.display();
						music.pause();
						srand(time(0));
						soundsWin[0 + rand() % 1].play();
						sleep(seconds(3));
						music.play();
					}
					else
					{
						window.clear(Color::Color(7, 112, 7));
						status.setString("LOSE");
						window.draw(status);
						window.display();
						music.pause();
						srand(time(0));
						soundsLose[rand() % 3].play();
						sleep(seconds(3));
						music.play();
					}

					x = x;
					posX = posX;
					launch = false;
					fieldPicked = false;
					fieldType = 0;
					betBarEnable = true;
					fieldBarEnable = true;
					betPlaced = false;
					checkWin = false;
					fieldBet.fieldValue = NULL;
					bet.betValue = 0;
					list.clear();
					get_profile_balance(users);
					users[prof] = balance;
					set_profiles_balance(users);

				}

				i++;
				x += x;
				posX += 605;
				animSprite.setTextureRect(IntRect(posX, 0, x, 560));
				

				window.clear();
				if (field_on == 0)
					window.draw(field.sprite);
				else if (field_on == 1)
					window.draw(fieldb.sprite);
				else if (field_on == 2)
					window.draw(fieldm.sprite);
				else if(field_on==3)
					window.draw(fielde.sprite);
				window.draw(f1.sprite);
				window.draw(f10.sprite);
				window.draw(f100.sprite);
				window.draw(f1000.sprite);
				window.draw(max.sprite);
				if (en == true)
				{
					window.draw(start_e.sprite);
					window.draw(del_e.sprite);
					window.draw(place_e.sprite);
					window.draw(shope.sprite);
				}
				else
				{
					window.draw(start_r.sprite);
					window.draw(del_r.sprite);
					window.draw(place_r.sprite);
					window.draw(shopr.sprite);
				}
				window.draw(animSprite);
				window.draw(txt);
				bet.drawBetBar(window);
				fieldBet.drawFieldBar(window);
				txt.setString("Balance:" + to_string(balance) + "$");
				window.draw(fieldStatus);
				window.display();

				if (posX >= 9075)
				{
					i = 0;
					x = 549;
					posX = 295;
				}
			}

			window.clear();
			if (field_on == 0)
				window.draw(field.sprite);
			else if (field_on == 1)
				window.draw(fieldb.sprite);
			else if (field_on == 2)
				window.draw(fieldm.sprite);
			else if(field_on==3)
				window.draw(fielde.sprite);
			if (first == true)
				window.draw(rouletteT.sprite);
			else
				window.draw(animSprite);
			window.draw(f1.sprite);
			window.draw(f10.sprite);
			window.draw(f100.sprite);
			window.draw(f1000.sprite);
			window.draw(max.sprite);
			if (en == true)
			{
				window.draw(start_e.sprite);
				window.draw(del_e.sprite);
				window.draw(place_e.sprite);
				window.draw(shope.sprite);
			}
			else
			{
				window.draw(start_r.sprite);
				window.draw(del_r.sprite);
				window.draw(place_r.sprite);
				window.draw(shopr.sprite);
			}
			window.draw(txt);
			bet.drawBetBar(window);
			fieldBet.drawFieldBar(window);
			txt.setString("Balance:" + to_string(balance) + "$");
			window.draw(fieldStatus);
			window.draw(circle);
			window.display();

		}
	}
	