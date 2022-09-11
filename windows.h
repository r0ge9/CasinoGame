#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sprites.h"
#include "profiles.h"
#include "string";

using namespace sf;
using namespace std;

class Bets
{
	Font font;
	Text bet;
	int betNum;
	string type;

public:

	Bets()
	{
		this->font.loadFromFile("unispace bd.ttf");
		this->bet.setFont(font);
		this->bet.setOutlineColor(Color::Black);
		this->bet.setOutlineThickness(3);
		this->bet.setPosition(415, 50);
		this->bet.setCharacterSize(16);
		this->betNum = 1;
		this->type = "-";
		this->bet.setString(this->type);
	}

	void clear()
	{
		this->bet.setString("");
		this->type = "-";
		this->betNum = 1;
	}

	string get_type()
	{
		return this->type;
	}

	string set_type(string x)
	{
		this->type = x;
		return this->type;
	}

	void set_bet(textBox val,fieldBetBox num)
	{
		/*fieldBetBox value;*/
		/*textBox betVal;*/
		if (this->betNum == 1)
		{
			bet.setString("\t\t\t\t\tBET " + to_string(betNum) + "\nNumber:" + to_string(num.fieldValue) + "\nField: " + this->type + "\nValue:" + to_string(val.betValue));
			betNum += 1;
		}
		else
		{
			string prev_bet = bet.getString();
			bet.setString(prev_bet+"\n\n\t\t\t\t\tBET " + to_string(betNum) + "\nNumber:" + to_string(num.fieldValue) + "\nField: " + this->type + "\nValue:" + to_string(val.betValue));
			betNum += 1;
		}
	}

	bool max_bets()
	{
		if (this->betNum == 8)
		{
			return true;
		}
		else
			return false;
	}

	void draw_bets(RenderWindow& window)
	{
		window.draw(bet);
	}
};

string set_name(RenderWindow& window,bool en,Event& event,Button menuBg,Button profe,Button profr,bool& isMenu,bool& pro)
{
	string str;
	Font font;
	Text nn;
	font.loadFromFile("unispace bd.ttf");
	nn.setFont(font);
	nn.setFillColor(Color::Black);
	nn.setCharacterSize(60);
	nn.setPosition(425,310);

	Button entere("entere.png", 400, 180), enterr("enterr.png", 400, 180);

	bool entered = 0;

	while (entered==0)
	{
		window.clear();

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isMenu = false;
				pro = 1;
				entered = 1;
				window.close();
			}
		}

		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode < 128 && event.text.unicode!=8&& event.text.unicode != 13)
			{
				if (str.length() == 11)
				{

				}
				else
				{
					cout << event.text.unicode;
					str += static_cast<char>(event.text.unicode);
					nn.setString(str);
					sleep(seconds(0.1));
				}
			}
			else if (event.text.unicode == 8)
			{
				if (!str.empty())
				{
					str.pop_back();
					nn.setString(str);
					sleep(seconds(0.1));
				}
			}

			if (event.text.unicode == 13)
			{
				if (str.empty())
				{
					str = "PLAYER";
					entered = 1;
				}
				else
				{
					entered = 1;
				}
			}
		}

		if (en == 1)
		{
			window.draw(menuBg.sprite);
			window.draw(profe.sprite);
			window.draw(entere.sprite);
			window.draw(nn);
		}
		else
		{
			window.draw(menuBg.sprite);
			window.draw(profe.sprite);
			window.draw(enterr.sprite);
			window.draw(nn);
		}
		window.display();
	}
	return str;
}
void update(int arr[],string name[],int& emp1,int& emp2,int& emp3,text user[])
{
	int y = 100;
	get_profile_name(name);
	get_profile_balance(arr);
	for (int i = 0; i < 3; i++)
	{
		if (name[i].empty())
		{
			if (i == 0)
				emp1 = 1;
			if (i == 1)
				emp2 = 1;
			if (i == 2)
				emp3 = 1;
			user[i].set_text("EMPTY");
			user[i].set_pos(415, y);
		}
		else
		{
			if (i == 0)
				emp1 = 0;
			if (i == 1)
				emp2 = 0;
			if (i == 2)
				emp3 = 0;
			user[i].set_text("Username: " + name[i] + "\nBalance: " + to_string(arr[i]) + "$");
			user[i].set_pos(415, y);
		}
		y += 200;
	}
}

int profiles(RenderWindow& window, bool& en, bool& isMenu, Button menuBg,int& balance,int& prof,Event& event)
{
	Button profe("profe.png", 400, 0), profr("profr.png", 400, 0),dele1("dele.png",630,200), dele2("dele.png", 630, 400), dele3("dele.png", 630, 650),
		delr1("delr.png", 630, 200), delr2("delr.png", 630, 400), delr3("delr.png", 630, 650),newe1("newe.png",430,200), newe2("newe.png", 430, 400),
		newe3("newe.png", 430, 650), newr1("newr.png", 430, 200), newr2("newr.png", 430, 400),
		newr3("newr.png", 430, 650), sele1("sele.png", 430, 200), sele2("sele.png", 430, 400), sele3("sele.png", 430, 650),
		selr1("selr.png", 430, 200), selr2("selr.png", 430, 400), selr3("selr.png", 430, 650);

	text user[3]; 

	const int n = 3;
	 int arr[n],emp1=1,emp2=1,emp3=1;
	string name[n];
	int purch[3];
	update(arr, name, emp1, emp2, emp3, user);
	
	int menu = 0;
	bool pro = 0;
	sleep(seconds(0.2));
	
	while (pro==0)
	{
		window.clear();
		if (IntRect(430, 200, 610, 260).contains(Mouse::getPosition(window))) { menu = 1; }
		if (IntRect(430, 400, 610, 460).contains(Mouse::getPosition(window))) { menu = 2; }
		if (IntRect(430, 650, 610, 710).contains(Mouse::getPosition(window))) { menu = 3; }
		if (IntRect(630, 200, 810, 260).contains(Mouse::getPosition(window))) { menu = 4; }
		if (IntRect(630, 400, 810, 460).contains(Mouse::getPosition(window))) { menu = 5; }
		if (IntRect(630, 650, 810, 710).contains(Mouse::getPosition(window))) { menu = 6; }

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isMenu = false;
				pro = 1;
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			pro = 1;
			sleep(seconds(0.5));
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menu == 1)
			{
				if (emp1 == 1)
				{
					name[0]=set_name(window,en,event,menuBg,profe,profr,isMenu,pro);
					/*name[0] = "PLAYER 1";*/
					arr[0] = 1000;
					balance = 1000;
					set_profiles_name(name);
					set_profiles_balance(arr);
					prof = 0;
					isMenu = 0;
					pro = 1;
					//update(arr, name, emp1, emp2, emp3, user);
				}

				if (emp1 == 0)
				{
					balance = arr[0];
					prof = 0;
					isMenu = 0;
					pro = 1;
				}

			}

			if (menu == 2)
			{
				if (emp2 == 1)
				{
					/*set_name(window,en);*/
					name[1] = set_name(window, en, event, menuBg, profe, profr,isMenu,pro);
					arr[1] = 1000;
					balance = 1000;
					set_profiles_name(name);
					set_profiles_balance(arr);
					prof = 1;
					isMenu = 0;
					pro = 1;
					//update(arr, name, emp1, emp2, emp3, user);
				}

				if (emp2 == 0)
				{
					balance = arr[1];
					prof = 1;
					isMenu = 0;
					pro = 1;
				}
			}

			if (menu == 3)
			{
				if (emp3 == 1)
				{
					/*set_name(window,en);*/
					name[2] = set_name(window, en, event, menuBg, profe, profr,isMenu,pro);
					arr[2] = 1000;
					balance = 1000;
					set_profiles_name(name);
					set_profiles_balance(arr);
					prof = 2;
					isMenu = 0;
					pro = 1;
					//update(arr, name, emp1, emp2, emp3, user);
				}

				if (emp3 == 0)
				{
					balance = arr[2];
					prof = 2;
					isMenu = 0;
					pro = 1;
				}
			}

			if (menu == 4)
			{
				name[0] = "";
				arr[0] = 0;
				set_profiles_name(name);
				set_profiles_balance(arr);
				/*user[0].set_text("EMPTY");
				user[0].set_pos(415, 100);*/
				update(arr, name, emp1, emp2, emp3, user);
			}

			if (menu == 5)
			{
				name[1] = "";
				arr[1] = 0;
				set_profiles_name(name);
				set_profiles_balance(arr);
				/*user[1].set_text("EMPTY");
				user[1].set_pos(415, 300);*/
				update(arr, name, emp1, emp2, emp3, user);
				//update(arr, name, emp1, emp2, emp3, user);
			}

			if (menu == 6)
			{
				name[2] = "";
				arr[2] = 0;
				set_profiles_name(name);
				set_profiles_balance(arr);
				/*user[2].set_text("EMPTY");
				user[2].set_pos(415, 500);*/
				update(arr, name, emp1, emp2, emp3, user);
				//update(arr, name, emp1, emp2, emp3, user);
			}
		}
		if (en == 1)
		{
			window.draw(menuBg.sprite);
			window.draw(profe.sprite);
			for (size_t i = 0; i < 3; i++)
			{
				if (emp1 == 1 && i == 0)
					window.draw(newe1.sprite);
				else if (emp1 == 0 && i == 0)
				{
					window.draw(sele1.sprite);
					window.draw(dele1.sprite);
				}
				if (emp2 == 1 && i == 1)
					window.draw(newe2.sprite);
				else if (emp2 == 0 && i == 1)
				{
					window.draw(sele2.sprite);
					window.draw(dele2.sprite);
				}
				if (emp3 == 1 && i == 2)
					window.draw(newe3.sprite);
				else if (emp3 == 0 && i == 2)
				{
					window.draw(sele3.sprite);
					window.draw(dele3.sprite);
				}
				user[i].draw_user(window);

				
			}
		}
		else
		{
			window.draw(menuBg.sprite);
			window.draw(profr.sprite);
			for (size_t i = 0; i < 3; i++)
			{
				if (emp1 == 1 && i == 0)
					window.draw(newr1.sprite);
				else if (emp1 == 0 && i == 0)
				{
					window.draw(selr1.sprite);
					window.draw(delr1.sprite);
				}
				if (emp2 == 1 && i == 1)
					window.draw(newr2.sprite);
				else if (emp2 == 0 && i == 1)
				{
					window.draw(selr2.sprite);
					window.draw(delr2.sprite);
				}
				if (emp3 == 1 && i == 2)
					window.draw(newr3.sprite);
				else if (emp3 == 0 && i == 2)
				{
					window.draw(selr3.sprite);
					window.draw(delr3.sprite);
				}
				user[i].draw_user(window);
				
			}
		}
		window.display();
	}
	return 1;
}

void purchase(int num,RenderWindow& window,int& balance,int& field_on,int& prof)
{
	text no_money;
	no_money.set_text("NOT ENOUGH MONEY!");
	no_money.set_pos(490, 260);

	text purch;
	purch.set_text("ALREADY PURCHASED!");
	purch.set_pos(490, 260);

	int bought[3],money[3];

	int price[3] = { 1500,3000,5000 };

	get_profile_goods(bought);
	get_profile_balance(money);
	
	if (num == 1)
	{
		if (balance >= 1500 && bought[0] != 1)
		{
			bought[0] = 1;
			balance -= 1500;
			money[prof] = balance;
			set_profiles_balance(money);
			set_profiles_goods(bought);
			field_on = 1;
		}
		else if (balance < 1500)
		{
			no_money.draw_user(window);
			window.display();
			sleep(seconds(0.5));
		}

		else if(bought[0]==1)
		{
			purch.draw_user(window);
			field_on = 1;
			window.display();
			sleep(seconds(0.5));
		}

	}

	else if (num == 2)
	{
		if (balance >= 3000 && bought[1] != 1)
		{
			bought[1] = 1;
			balance -= 3000;
			money[prof] = balance;
			set_profiles_balance(money);
			set_profiles_goods(bought);
			field_on = 2;
		}

		else if (balance < 3000)
		{
			no_money.draw_user(window);
			window.display();
			sleep(seconds(0.5));
		}

		else if(bought[1]==1)
		{
			purch.draw_user(window);
			field_on = 2;
			window.display();
			sleep(seconds(0.5));
		}

	}

	else
	{
		if (balance >= 5000 && bought[2] != 1)
		{
			bought[2] = 1;
			balance -= 5000;
			money[prof] = balance;
			set_profiles_balance(money);
			set_profiles_goods(bought);
			field_on = 3;
			
		}
		else if (balance < 5000)
		{
			no_money.draw_user(window);
			window.display();
			sleep(seconds(0.5));
		}

		else if(bought[2]==1)
		{
			purch.draw_user(window);
			field_on = 3;
			window.display();
			sleep(seconds(0.5));
		}

	}
	window.display();
}


//void menu(RenderWindow& window,bool& en,int& balance,int& user) 
//{
//	Button play("play.png", 525, 219), exit("exit.png", 525, 419), about("about.png", 525, 319), menuBg("background.png", 0, 0), aboutBg("about1.png", 0, 0),
//		rus("rus.png",1130,0),eng("eng2.png",1130,0),play_r("playr.png",525,219), exit_r("exitr.png", 525, 419), about_r("aboutrpsd.png", 525, 319), aboutBg_r("aboutr.png", 0, 0);
//	bool isMenu = 1;
//	int menuNum = 0;
//
//	while (isMenu)
//	{
//		menuNum = 0;
//		window.clear();
//
//		if (IntRect(525, 219, 180, 60).contains(Mouse::getPosition(window))) {  menuNum = 1; }
//		if (IntRect(525, 319, 180, 60).contains(Mouse::getPosition(window))) { menuNum = 2; }
//		if (IntRect(525, 419, 180, 60).contains(Mouse::getPosition(window))) { menuNum = 3; }
//		if (IntRect(1130, 0, 1280, 120).contains(Mouse::getPosition(window))) { menuNum = 4; }
//
//		if (Mouse::isButtonPressed(Mouse::Left))
//		{
//			if (menuNum == 1) profiles(window,en,isMenu,menuBg,balance,user);//isMenu = false;
//			if (menuNum == 2)
//			{
//				if (en == true)
//				{
//					window.draw(about.sprite); window.display();
//					while (!Keyboard::isKeyPressed(Keyboard::Escape))
//					{
//						window.draw(aboutBg.sprite); window.display();
//					}
//				}
//				else
//				{
//					window.draw(about_r.sprite); window.display();
//					while (!Keyboard::isKeyPressed(Keyboard::Escape))
//					{
//						window.draw(aboutBg_r.sprite); window.display();
//					}
//				}
//			}
//			if (menuNum == 3) { window.close(); isMenu = false; }
//			if (menuNum == 4) 
//			{
//				if (en == true)
//				{
//					en = false;
//					sleep(seconds(0.1));
//				}
//				else
//				{
//					en = true;
//					sleep(seconds(0.1));
//				}
//			}
//
//		}
//
//		window.clear();
//		if (en == true)
//		{
//			window.draw(menuBg.sprite);
//			window.draw(about.sprite);
//			window.draw(play.sprite);
//			window.draw(exit.sprite);
//		}
//		else
//		{
//			window.draw(menuBg.sprite);
//			window.draw(about_r.sprite);
//			window.draw(play_r.sprite);
//			window.draw(exit_r.sprite);
//		}
//		if (en == true)
//			window.draw(eng.sprite);
//		else
//			window.draw(rus.sprite);
//
//		window.display();
//	}
//}


