#include "text.h"
#include<iostream>
#include "Game.h"
text::text(SDL_Renderer *renderer,
     const std::string &font_path, 
     int font_size, 
     const std::string &message_text, 
     const SDL_Color &color)
{
   text_texture = loadFont(renderer,font_path, font_size,message_text,color);
   SDL_QueryTexture(text_texture,nullptr,nullptr,&text_rect.w,&text_rect.h);
}

void text::display(int x,int y,SDL_Renderer *renderer) const{
    text_rect.x = x;
    text_rect.y = y;
    SDL_RenderCopy(renderer,text_texture,nullptr,&text_rect);

  
}

    SDL_Texture *text::loadFont(SDL_Renderer *renderer,const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color){
    TTF_Font *font = TTF_OpenFont(font_path.c_str(),font_size);
    if(!font){
        std::cerr << "failed to load font\n";
    }
    auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(),color);
    if(!text_surface)
    {
       std::cerr<<"failed to create text surface\n";
    }
    auto text_texture = SDL_CreateTextureFromSurface(renderer,text_surface);
    if(!text_texture){
        std::cerr << "failed to create text texture\n";
    }
    SDL_FreeSurface(text_surface);
    return text_texture;

     
}