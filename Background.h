class Background{
	public:
	
	//variables	
	float x;
	float y;
	BITMAP* sprite;
	string background;
	
	//Fuciones
	Background(string background);
	void action();
};

Background::Background(string background){
	sprite = load_bitmap(background.c_str(),NULL);
	this->background = background;
	this->x = 0;
	this->y = 0;
}

void Background::action(){
		draw_sprite(lienzo,sprite,x,sprite->h*-1 + y);
		draw_sprite(lienzo,sprite,x,sprite->h*-2 + y);
		draw_sprite(lienzo,sprite,x,y);
		draw_sprite(lienzo,sprite,x,sprite->h + y);
		draw_sprite(lienzo,sprite,x,sprite->h*2 + y);
		y+=0.2;
		
		if(y <= sprite->h*-1 or y >= sprite->h)		
		{	y = 0;	}
	
}
