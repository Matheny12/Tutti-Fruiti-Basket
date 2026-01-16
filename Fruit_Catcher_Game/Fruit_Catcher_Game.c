#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Texture* background_texture;
    SDL_Texture* MNM;
    SDL_Texture* Skittles;
    SDL_Texture* Kitkat;
    SDL_Texture* Milkyway;
    SDL_Texture* Twix;
    SDL_Texture* Poprocks;
    SDL_Texture* Candycane;
    SDL_Texture* Lollipop;
    SDL_Texture* Chocolate;
    SDL_Texture* Pear;
    SDL_Texture* Pineapple;
    SDL_Texture* Orange;
    SDL_Texture* Blueberry;
    SDL_Texture* Strawberry;
    SDL_Texture* Raspberry;
    SDL_Texture* Grape;
    SDL_Texture* Banana;
    SDL_Texture* Apple;
    SDL_Texture* VictoryBasket;
    TTF_Font* font;
    
    SDL_FRect Bucket_rect;
    float Bucket_vy;
    
    SDL_FRect MNM_rect;
    float MNM_vy;
    
    SDL_FRect Skittles_rect;
    float Skittles_vy;
    
    SDL_FRect Kitkat_rect;
    float Kitkat_vy;
    
    SDL_FRect Milkyway_rect;
    float Milkyway_vy;
    
    SDL_FRect Twix_rect;
    float Twix_vy;
    
    SDL_FRect Lollipop_rect;
    float Lollipop_vy;
    
    SDL_FRect Candycane_rect;
    float Candycane_vy;
    
    SDL_FRect Poprocks_rect;
    float Poprocks_vy;
    
    SDL_FRect Chocolate_rect;
    float Chocolate_vy;
    
    SDL_FRect Pear_rect;
    float Pear_vy;
    
    SDL_FRect Pineapple_rect;
    float Pineapple_vy;
    
    SDL_FRect Orange_rect;
    float Orange_vy;
    
    SDL_FRect Blueberry_rect;
    float Blueberry_vy;
    
    SDL_FRect Strawberry_rect;
    float Strawberry_vy;
    
    SDL_FRect Raspberry_rect;
    float Raspberry_vy;
    
    SDL_FRect Grape_rect;
    float Grape_vy;
    
    SDL_FRect Banana_rect;
    float Banana_vy;
    
    SDL_FRect Apple_rect;
    float Apple_vy;
    
    int health;
    int score;
    int win;
    int lose;
    int quit;
    int screenWidth;
    int screenHeight;
    int gameStarted;
} GameState;

void reset_game(GameState* state) {
    state->health = 100;
    state->score = 0;
    state->win = 0;
    state->lose = 0;

    state->Bucket_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Bucket_rect.y = (float)(rand() % (state->screenHeight - 100));
    
    state->MNM_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->MNM_rect.y = -((float)(rand() % 1600));

    state->Skittles_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Skittles_rect.y = -((float)(rand() % 1600));

    state->Kitkat_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Kitkat_rect.y = -((float)(rand() % 1600));

    state->Milkyway_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Milkyway_rect.y = -((float)(rand() % 1600));

    state->Twix_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Twix_rect.y = -((float)(rand() % 1600));

    state->Lollipop_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Lollipop_rect.y = -((float)(rand() % 1600));

    state->Candycane_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Candycane_rect.y = -((float)(rand() % 1600));

    state->Poprocks_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Poprocks_rect.y = -((float)(rand() % 1600));

    state->Chocolate_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Chocolate_rect.y = -((float)(rand() % 1600));

    state->Pear_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Pear_rect.y = -((float)(rand() % 1600));

    state->Pineapple_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Pineapple_rect.y = -((float)(rand() % 1600));
        
    state->Orange_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Orange_rect.y = -((float)(rand() % 1600));

    state->Blueberry_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Blueberry_rect.y = -((float)(rand() % 1600));

    state->Strawberry_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Strawberry_rect.y = -((float)(rand() % 1600));

    state->Raspberry_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Raspberry_rect.y = -((float)(rand() % 1600));

    state->Grape_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Grape_rect.y = -((float)(rand() % 1600));

    state->Banana_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Banana_rect.y = -((float)(rand() % 1600));

    state->Apple_rect.x = (float)(rand() % (state->screenWidth - 100));
    state->Apple_rect.y = -((float)(rand() % 1600));

    SDL_Log("Game Reset!");
}

void main_loop(void* arg) {
    GameState* state = (GameState*)arg;
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_EVENT_QUIT:
                SDL_Log("SDL3 event quit");
                state->quit = 1;
        #ifdef __EMSCRIPTEN__
                emscripten_cancel_main_loop();
        #endif
                break;
            case SDL_EVENT_KEY_DOWN:
                if (event.key.key == SDLK_ESCAPE) {
                    SDL_Log("SDL3 ESC key quit");
                    state->quit = 1;
        #ifdef __EMSCRIPTEN__
                    emscripten_cancel_main_loop();
        #endif
                }
                if (event.key.key == SDLK_SPACE && !state->gameStarted) {
                    state->gameStarted = 1;
                    reset_game(state);
                }
                if (event.key.key == SDLK_R) {
                    state->gameStarted = 0;
                }
                break;
        }
    }

    if (state->score >= 100) {
        state->win = 1;
    }
    if (state->health <= 0) {
        state->lose = 1;
    }
    
    if (state->gameStarted && !state->win && !state->lose) {
        state->MNM_rect.y += state->MNM_vy;
        if (state->MNM_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->MNM_rect, &state->Bucket_rect)) {
                if (SDL_HasRectIntersectionFloat(&state->MNM_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->MNM_rect.y = -((float)(rand() % 1600));
            state->MNM_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Skittles_rect.y += state->Skittles_vy;
        if (state->Skittles_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Skittles_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Skittles_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Skittles_rect.y = -((float)(rand() % 1600));
            state->Skittles_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Kitkat_rect.y += state->Kitkat_vy;
        if (state->Kitkat_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Kitkat_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Kitkat_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Kitkat_rect.y = -((float)(rand() % 1600));
            state->Kitkat_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Milkyway_rect.y += state->Milkyway_vy;
        if (state->Milkyway_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Milkyway_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Milkyway_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Milkyway_rect.y = -((float)(rand() % 1600));
            state->Milkyway_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Twix_rect.y += state->Twix_vy;
        if (state->Twix_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Twix_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Twix_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Twix_rect.y = -((float)(rand() % 1600));
            state->Twix_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Lollipop_rect.y += state->Lollipop_vy;
        if (state->Lollipop_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Lollipop_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Lollipop_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Lollipop_rect.y = -((float)(rand() % 1600));
            state->Lollipop_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Candycane_rect.y += state->Candycane_vy;
        if (state->Candycane_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Candycane_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Candycane_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Candycane_rect.y = -((float)(rand() % 1600));
            state->Candycane_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Poprocks_rect.y += state->Poprocks_vy;
        if (state->Poprocks_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Poprocks_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Poprocks_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Poprocks_rect.y = -((float)(rand() % 1600));
            state->Poprocks_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Chocolate_rect.y += state->Chocolate_vy;
        if (state->Chocolate_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Chocolate_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Chocolate_rect, &state->Bucket_rect)) {
                state->health -= 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Chocolate_rect.y = -((float)(rand() % 1600));
            state->Chocolate_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Pear_rect.y += state->Pear_vy;
        if (state->Pear_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Pear_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Pear_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Pear_rect.y = -((float)(rand() % 1600));
            state->Pear_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Pineapple_rect.y += state->Pineapple_vy;
        if (state->Pineapple_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Pineapple_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Pineapple_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Pineapple_rect.y = -((float)(rand() % 1600));
            state->Pineapple_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Orange_rect.y += state->Orange_vy;
        if (state->Orange_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Orange_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Orange_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Orange_rect.y = -((float)(rand() % 1600));
            state->Orange_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Blueberry_rect.y += state->Blueberry_vy;
        if (state->Blueberry_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Blueberry_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Blueberry_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Blueberry_rect.y = -((float)(rand() % 1600));
            state->Blueberry_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Strawberry_rect.y += state->Strawberry_vy;
        if (state->Strawberry_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Strawberry_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Strawberry_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Strawberry_rect.y = -((float)(rand() % 1600));
            state->Strawberry_rect.x = (float)(rand() % (currentWidth - 100));
        }
        
        state->Raspberry_rect.y += state->Raspberry_vy;
        if (state->Raspberry_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Raspberry_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Raspberry_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Raspberry_rect.y = -((float)(rand() % 1600));
            state->Raspberry_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Grape_rect.y += state->Grape_vy;
        if (state->Grape_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Grape_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Grape_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Grape_rect.y = -((float)(rand() % 1600));
            state->Grape_rect.x = (float)(rand() % (currentWidth - 100));
        }

        state->Banana_rect.y += state->Banana_vy;
        if (state->Banana_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Banana_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Banana_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Banana_rect.y = -((float)(rand() % 1600));
            state->Banana_rect.x = (float)(rand() % (currentWidth - 100));
        }
        
        state->Apple_rect.y += state->Apple_vy;
        if (state->Apple_rect.y > state->screenHeight || SDL_HasRectIntersectionFloat(&state->Apple_rect, &state->Bucket_rect)) {
            if (SDL_HasRectIntersectionFloat(&state->Apple_rect, &state->Bucket_rect)) {
                state->score += 5;
            }
            int currentWidth, currentHeight;
            SDL_GetWindowSize(state->window, &currentWidth, &currentHeight);
            state->Apple_rect.y = -((float)(rand() % 1600));
            state->Apple_rect.x = (float)(rand() % (currentWidth - 100));
        }
    }

    const bool* keys = SDL_GetKeyboardState(NULL);
    if (!state->win && !state->lose) {
        if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A]) {
            state->Bucket_rect.x -= state->Bucket_vy;
        }
        if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D]) {
            state->Bucket_rect.x += state->Bucket_vy;
        }
        if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_W]) {
            state->Bucket_rect.y -= state->Bucket_vy;
        }
        if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_S]) {
            state->Bucket_rect.y += state->Bucket_vy;
        }
    }

    SDL_GetWindowSize(state->window, &state->screenWidth, &state->screenHeight);

    if (state->Bucket_rect.x < 0) state->Bucket_rect.x = 0;
    if (state->Bucket_rect.y < 0) state->Bucket_rect.y = 0;
    if (state->Bucket_rect.x + state->Bucket_rect.w > state->screenWidth) 
        state->Bucket_rect.x = state->screenWidth - state->Bucket_rect.w;
    if (state->Bucket_rect.y + state->Bucket_rect.h > state->screenHeight) 
        state->Bucket_rect.y = state->screenHeight - state->Bucket_rect.h;

    SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 0);
    SDL_RenderClear(state->renderer);
    SDL_RenderTexture(state->renderer, state->background_texture, NULL, NULL);
    if(!state->gameStarted) {
        SDL_Color white = {255, 255, 255, 255};
        SDL_Surface* startSurf = TTF_RenderText_Solid(state->font, "Press Space to Start. Use W,A,S,D or Arrow Keys to Move the Bucket.", 0, white);
        if (startSurf) {
            SDL_Texture* startTex = SDL_CreateTextureFromSurface(state->renderer, startSurf);
            SDL_FRect startRect = {(state->screenWidth - startSurf->w) / 2.0f, (state->screenHeight - startSurf->h) / 2.0f, (float)startSurf->w, (float)startSurf->h};
            SDL_RenderTexture(state->renderer, startTex, NULL, &startRect);
            SDL_DestroyTexture(startTex);
            SDL_DestroySurface(startSurf);
        }
    }
    else {
        SDL_RenderTexture(state->renderer, state->Poprocks, NULL, &state->Poprocks_rect);
        SDL_RenderTexture(state->renderer, state->Skittles, NULL, &state->Skittles_rect);
        SDL_RenderTexture(state->renderer, state->Kitkat, NULL, &state->Kitkat_rect);
        SDL_RenderTexture(state->renderer, state->Milkyway, NULL, &state->Milkyway_rect);
        SDL_RenderTexture(state->renderer, state->Twix, NULL, &state->Twix_rect);
        SDL_RenderTexture(state->renderer, state->Lollipop, NULL, &state->Lollipop_rect);
        SDL_RenderTexture(state->renderer, state->MNM, NULL, &state->MNM_rect);
        SDL_RenderTexture(state->renderer, state->Candycane, NULL, &state->Candycane_rect);
        SDL_RenderTexture(state->renderer, state->Chocolate, NULL, &state->Chocolate_rect);
        SDL_RenderTexture(state->renderer, state->Pear, NULL, &state->Pear_rect);
        SDL_RenderTexture(state->renderer, state->Pineapple, NULL, &state->Pineapple_rect);
        SDL_RenderTexture(state->renderer, state->Orange, NULL, &state->Orange_rect);
        SDL_RenderTexture(state->renderer, state->Blueberry, NULL, &state->Blueberry_rect);
        SDL_RenderTexture(state->renderer, state->Strawberry, NULL, &state->Strawberry_rect);
        SDL_RenderTexture(state->renderer, state->Raspberry, NULL, &state->Raspberry_rect);
        SDL_RenderTexture(state->renderer, state->Grape, NULL, &state->Grape_rect);
        SDL_RenderTexture(state->renderer, state->Banana, NULL, &state->Banana_rect);
        SDL_RenderTexture(state->renderer, state->Apple, NULL, &state->Apple_rect);
        SDL_RenderTexture(state->renderer, state->texture, NULL, &state->Bucket_rect);

        if (state->font != NULL) {
            SDL_Color green = {0, 255, 0, 255};
            SDL_Color red = {255, 0, 0, 255};
            SDL_Color white = {255, 255, 255, 255};

            char scoreText[50];
            snprintf(scoreText, sizeof(scoreText), "Score: %d", state->score);
            SDL_Surface* textSurface = TTF_RenderText_Solid(state->font, scoreText, 0, green);
            if (textSurface != NULL) {
                SDL_Texture* textTexture = SDL_CreateTextureFromSurface(state->renderer, textSurface);
                SDL_FRect textRect = {10.0f, 10.0f, (float)textSurface->w, (float)textSurface->h};
                SDL_RenderTexture(state->renderer, textTexture, NULL, &textRect);
                SDL_DestroyTexture(textTexture);
                SDL_DestroySurface(textSurface);
            }

            char healthText[50];
            snprintf(healthText, sizeof(healthText), "Health: %d", state->health);
            SDL_Surface* textSurface1 = TTF_RenderText_Solid(state->font, healthText, 0, red);
            if (textSurface1 != NULL) {
                SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(state->renderer, textSurface1);
                SDL_FRect textRect1 = {10.0f, 50.0f, (float)textSurface1->w, (float)textSurface1->h};
                SDL_RenderTexture(state->renderer, textTexture1, NULL, &textRect1);
                SDL_DestroyTexture(textTexture1);
                SDL_DestroySurface(textSurface1);
            }

            if (state->win) {
                SDL_FRect victoryRect = {(state->screenWidth - 400) / 2.0f, (state->screenHeight - 400) / 2.0f, 400.0f, 400.0f};
                SDL_RenderTexture(state->renderer, state->VictoryBasket, NULL, &victoryRect);
                
                SDL_Surface* winSurface = TTF_RenderText_Solid(state->font, "You Win!! Press 'Esc' to Exit or Press R to Restart.", 0, green);
                if (winSurface != NULL) {
                    SDL_Texture* winTexture = SDL_CreateTextureFromSurface(state->renderer, winSurface);
                    SDL_FRect winRect = {(state->screenWidth - winSurface->w) / 2.0f, (state->screenHeight - winSurface->h) / 5.0f, (float)winSurface->w, (float)winSurface->h};
                    SDL_RenderTexture(state->renderer, winTexture, NULL, &winRect);
                    SDL_DestroyTexture(winTexture);
                    SDL_DestroySurface(winSurface);
                }
            }

            if (state->lose) {
                SDL_Surface* loseSurface = TTF_RenderText_Solid(state->font, "You Lose!! Press 'Esc' to Exit or Press R to Restart.", 0, red);
                if (loseSurface != NULL) {
                    SDL_Texture* loseTexture = SDL_CreateTextureFromSurface(state->renderer, loseSurface);
                    SDL_FRect loseRect = {(state->screenWidth - loseSurface->w) / 2.0f, (state->screenHeight - loseSurface->h) / 5.0f, (float)loseSurface->w, (float)loseSurface->h};
                    SDL_RenderTexture(state->renderer, loseTexture, NULL, &loseRect);
                    SDL_DestroyTexture(loseTexture);
                    SDL_DestroySurface(loseSurface);
                }
            }
        }

        SDL_RenderPresent(state->renderer);
    }
}

int main(int argc, char* argv[]) {
    GameState state = {0};
    
    srand(time(NULL));

    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    if (result < 0) {
        SDL_Log("SDL_Init error: %s", SDL_GetError());
        return -1;
    }

    if (TTF_Init() < 0) {
        SDL_Log("TTF_Init error: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    state.window = SDL_CreateWindow("Game", 800, 600, SDL_WINDOW_FULLSCREEN);
    if (state.window == NULL) {
        SDL_Log("SDL_CreateWindow: %s", SDL_GetError());
        SDL_Quit();
        return -2;
    }

    state.renderer = SDL_CreateRenderer(state.window, NULL);
    if (state.renderer == NULL) {
        SDL_Log("SDL_CreateRenderer: %s", SDL_GetError());
        SDL_DestroyWindow(state.window);
        SDL_Quit();
        return -2;
    }

    state.font = TTF_OpenFont("/data/DejaVuSans.ttf", 36);
    if (state.font == NULL) {
        SDL_Log("TTF_OpenFont error: %s", SDL_GetError());
    }

    state.texture = IMG_LoadTexture(state.renderer, "/data/Bucket.png");
    if (state.texture == NULL) {
        SDL_Log("IMG_LoadTexture error: %s", SDL_GetError());
        return -3;
    }

    state.background_texture = IMG_LoadTexture(state.renderer, "/data/Sky.jpg");
    state.MNM = IMG_LoadTexture(state.renderer, "/data/MNM.png");
    state.Skittles = IMG_LoadTexture(state.renderer, "/data/Skittles.png");
    state.Kitkat = IMG_LoadTexture(state.renderer, "/data/Kitkat.png");
    state.Milkyway = IMG_LoadTexture(state.renderer, "/data/Milkyway.png");
    state.Twix = IMG_LoadTexture(state.renderer, "/data/Twix.png");
    state.Poprocks = IMG_LoadTexture(state.renderer, "/data/Poprocks.png");
    state.Candycane = IMG_LoadTexture(state.renderer, "/data/Candycane.png");
    state.Lollipop = IMG_LoadTexture(state.renderer, "/data/Lollipop.png");
    state.Chocolate = IMG_LoadTexture(state.renderer, "/data/Chocolate.png");
    state.Pear = IMG_LoadTexture(state.renderer, "/data/Pear.png");
    state.Pineapple = IMG_LoadTexture(state.renderer, "/data/Pineapple.png");
    state.Orange = IMG_LoadTexture(state.renderer, "/data/Orange.png");
    state.Blueberry = IMG_LoadTexture(state.renderer, "/data/Blueberry.png");
    state.Strawberry = IMG_LoadTexture(state.renderer, "/data/Strawberry.png");
    state.Raspberry = IMG_LoadTexture(state.renderer, "/data/Raspberry.png");
    state.Grape = IMG_LoadTexture(state.renderer, "/data/Grape.png");
    state.Banana = IMG_LoadTexture(state.renderer, "/data/Banana.png");
    state.Apple = IMG_LoadTexture(state.renderer, "/data/Apple.png");
    state.VictoryBasket = IMG_LoadTexture(state.renderer, "/data/FruitBasket.png");

    SDL_Log("SDL3 initialized");

    SDL_GetWindowSize(state.window, &state.screenWidth, &state.screenHeight);

    state.Bucket_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                     (float)(rand() % (state.screenHeight - 100)), 200.0f, 200.0f};
    state.Bucket_vy = 2.0f;

    state.MNM_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                  -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.MNM_vy = 2.25f;

    state.Skittles_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                       -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Skittles_vy = 2.25f;

    state.Kitkat_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                     -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Kitkat_vy = 2.25f;

    state.Milkyway_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                       -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Milkyway_vy = 2.25f;

    state.Twix_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                   -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Twix_vy = 2.25f;

    state.Lollipop_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                       -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Lollipop_vy = 2.25f;

    state.Candycane_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                        -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Candycane_vy = 2.25f;

    state.Poprocks_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                       -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Poprocks_vy = 2.25f;

    state.Chocolate_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                        -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Chocolate_vy = 2.25f;

    state.Pear_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                   -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Pear_vy = 2.25f;

    state.Pineapple_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                        -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Pineapple_vy = 2.25f;

    state.Orange_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                     -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Orange_vy = 2.25f;

    state.Blueberry_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                        -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Blueberry_vy = 2.25f;

    state.Strawberry_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                         -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Strawberry_vy = 2.25f;

    state.Raspberry_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                        -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Raspberry_vy = 2.25f;

    state.Grape_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                    -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Grape_vy = 2.25f;

    state.Banana_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                     -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Banana_vy = 2.25f;

    state.Apple_rect = (SDL_FRect){(float)(rand() % (state.screenWidth - 100)), 
                                    -((float)(rand() % 1600)), 200.0f, 200.0f};
    state.Apple_vy = 2.25f;

    state.health = 100;
    state.score = 0;
    state.win = 0;
    state.lose = 0;
    state.quit = 0;

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(main_loop, &state, 0, 1);
#else
    while (!state.quit) {
        main_loop(&state);
        SDL_Delay(1);
    }
#endif

    SDL_Log("SDL3 shutdown");
    if (state.font != NULL) {
        TTF_CloseFont(state.font);
    }
    SDL_DestroyTexture(state.texture);
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
