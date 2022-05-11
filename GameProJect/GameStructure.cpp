#include "GameStructure.h"
#include <iostream>
#include <SDL_ttf.h>
#include "Util.cpp"

void GameBase::init() {

	//test
	/*int w, h;
	SDL_GetWindowSize(window, &w, &h);
	std::cout << mb->getWidth() << " " << mb->getHeight() << std::endl << w << " " << h << std::endl;*/


	//Initialize Environment
	SDL_Log("Initializing Game");

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return;
	}

	if (TTF_Init() == -1)
	{
		SDL_Log("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return;
	}

	if ((window = SDL_CreateWindow((TITLE + " - " + VERSION).c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_OPENGL)) == NULL) {
		SDL_Log("Unable to create Window: %s", SDL_GetError());
		return;
	}

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
		SDL_Log("Unable to create Renderer: %s", SDL_GetError());
		return;
	}

	//Load Texture
	SDL_Log("Loading Texture:");
	t->load(renderer);
	menu->load(renderer);
	mb->load(renderer);
	pb->load(renderer);
	test->load(renderer);
	test2->load(renderer);
	test3->load(renderer);
	test4->load(renderer);
	test5->load(renderer);
	test6->load(renderer);
	test7->load(renderer);
	test8->load(renderer);
	gb->load(renderer);
	load(tutor1, renderer, "TAB to change Button", "font.ttf", 12);
	load(tutor2, renderer, "SPACE to select", "font.ttf", 12);
	load(tutor3, renderer, "ESCAPE to back to Menu", "font.ttf", 12);
	

	//Setup Object
	SDL_Log("Setup Object");

	tob1.setTexture(&tutor1);
	tob1.setSize(1, 1);
	tob1.setPos(30, 600 - 50);
	tob2.setTexture(&tutor2);
	tob2.setSize(1, 1);
	tob2.setPos(30, 600 - 80);
	tob3.setTexture(&tutor3);
	tob3.setSize(1, 1);
	tob3.setPos(600 - 300, 30);

	mbo.setTexture(mb);
	mbo.setSize(1, 1);
	mbo.setPos(0, 0);

	mo.setTexture(menu);
	mo.setSize(1.5, 1.5);
	mo.setPos(30, 30);

	pbo.setTexture(pb);
	pbo.setSize(1.5, 1.5);
	pbo.setPos(30, 30 + 128 + 30 );

	mbl.addButton(&pbo, [=]() {
		changeScene(GAME);
		return;
		}, 0);

	ao.addVar("colormod", 0);

	ao.setEvent([=](SDL_Event* Event) {
		if (Event->type == SDL_KEYDOWN && Event->key.keysym.sym == SDLK_ESCAPE) {
			changeScene(MENU);
		}
		if (Event->type == SDL_KEYDOWN && Event->key.keysym.sym == SDLK_SPACE) {
			(ao2.getVar("checkinput") == 1) ? ao2.setVar("checkinput", 0) : ao2.setVar("checkinput", 1);
			std::cout << ao2.getVar("checkinput") << std::endl;
			
		}
		return;
		});

	ao.setTick([=]() {
		/*mto.setPos(45 / 2.5 + 10 * sin(newtime * M_PI / 300), 45 / 2.5 + 5 * cos(newtime * M_PI / 300));
		int a = 256 * ( 1 + sin(newtime * M_PI / 3000))/2;
		std::cout << a << std::endl;
		mto.setColorMod(a, a, a);
		ao.setVar("colormod", a);*/
		return;
		});

	gbo.setTexture(gb);
	gbo.setSize(1, 1);
	gbo.setPos(0, 0);

	mto.addTex(test); mto.addTex(test2); mto.addTex(test3); mto.addTex(test4); mto.addTex(test5); mto.addTex(test6); mto.addTex(test7); mto.addTex(test8);
	mto.setCurTexture();
	mto.setSize(2.5, 2.5);
	mto.setPos(45 / 2.5, 45 / 2.5);

	
	//Setup Scene
	SDL_Log("Setup Scene");
	s1.push_back((GameObject*)&mbo);
	s1.push_back((GameObject*)&mo);
	s1.push_back((GameObject*)&mbl);
	s1.push_back((GameObject*)&tob1);
	s1.push_back((GameObject*)&tob2);

	s2.push_back((GameObject*)&gbo);
	s2.push_back((GameObject*)&mto);
	s2.push_back((GameObject*)&ao);
	s2.push_back((GameObject*)&ao2);
	s2.push_back((GameObject*)&tob3);
	

	addScene("scene1", s1);
	addScene("scene2", s2);

	changeScene("scene1");

	SDL_Log("Complete");
}


void GameBase::render(){
	SDL_RenderClear(renderer);

	for (GameObject* a : (scene[presentedscene])) {
		a->render(renderer);
	}

	SDL_RenderPresent(renderer);
}


void GameBase::eventCheck(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		running = false;
		return;
	}

	for (GameObject* a : (scene[presentedscene])) {
		a->eventCheck(Event);
	}
}


void GameBase::tick() {
	for (GameObject* a : (scene[presentedscene])) {
		a->tick();
	}
}


void GameBase::quit() {
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;
	delete t;
	delete menu;
	delete mb;
	delete pb;
	delete test;
	delete gb;
	delete test2;
	delete test3;
	delete test4;
	delete test5;
	delete test6;
	delete test7;
	delete test8;
	std::cout << std::endl;
	//delete tutor1;
	//delete tutor2;
	gb = NULL;
	t = NULL;
	menu = NULL;
	mb = NULL;
	pb = NULL;
	test = NULL;
	test2 = NULL;
	test3 = NULL;
	test4 = NULL;
	test5 = NULL;
	test6 = NULL;
	test7 = NULL;
	test8 = NULL;

	SDL_Quit();
	IMG_Quit();
}


void GameBase::run() {

	init();

	oldtime = 0;

	while (running) {

		newtime = SDL_GetTicks64();
		delta = newtime - oldtime;

		while (SDL_PollEvent(&Event)) {
			eventCheck(&Event);
		}

		tick();

		render();

		SDL_Delay(1);

		oldtime = newtime;

	}

	quit();
	
}

void GameBase::addScene(std::string name, std::vector<GameObject*> objects) {
	scene.insert(std::pair<std::string, std::vector<GameObject*>>(name, objects));
}

void GameBase::changeScene(std::string name) {
	presentedscene = name;
}





