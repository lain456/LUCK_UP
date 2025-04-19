//
// Created by lain on 4/18/25.
//











int fat_ass_audio_test()
{




    Mix_Chunk *sfx = Mix_LoadWAV(HOVER_SFX_PATH);


    if (!sfx) {
        printf("Mix_LoadWAV Error: %s\n", Mix_GetError());
    } else {
        printf("WAV loaded successfully!\n");
    }


                // Play sound when mouse enters the circle
                if (isHovering && !wasHovering && sfx) {
                    Mix_PlayChannel(-1, sfx, 0);
                }

                wasHovering = isHovering;

                // Update volume if dragging
                if (dragging) {
                    volume = ((mouse_x - centerX) * MIX_MAX_VOLUME) / barWidth;
                    if (volume < 0) volume = 0;
                    if (volume > MIX_MAX_VOLUME) volume = MIX_MAX_VOLUME;
                    Mix_VolumeMusic(volume);
                }
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouse_x = event.button.x;
                int mouse_y = event.button.y;
                if (mouse_x >= circle_x && mouse_x <= circle_x + circle_w &&
                    mouse_y >= circle_y && mouse_y <= circle_y + circle_h) {
                    dragging = 1;
                }
            } else if (event.type == SDL_MOUSEBUTTONUP) {
                dragging = 0;
            }

            // Call existing handleEvents for other interactions
            handleEvents(&quit, &fullscreen, &volume, &dragging, &screen, bar, scaledCircle);
        }

        SDL_BlitSurface(image, NULL, screen, NULL);
        renderVolumeSlider(screen, bar, barFill, scaledCircle, volume);
        SDL_Flip(screen);
    }

    Mix_FreeChunk(sfx);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_FreeSurface(image);
    SDL_FreeSurface(bar);
    SDL_FreeSurface(barFill);
    SDL_FreeSurface(circle);
    SDL_FreeSurface(scaledCircle);
    SDL_Quit();

    return 0;
}