vector spaceship1_pos {5, 16};
vector spaceship2_pos {2, 16};

int placeholder = 0;
short earth_max_health = 32;

int max_invaders_size = 32;
vector invader_pos[32];
int enemies = 1;

vector rocket1_pos;
boolean rocket1_fired = false;
vector rocket2_pos;
boolean rocket2_fired = false;






//Raumschiff fuer Spieler1
void spaceship1() {
  draw_spaceship(spaceship1_pos.x, spaceship1_pos.y, display.color565(0, 25, 25));
  if (singleplayer == true) {
    if (button_state_lright == LOW && spaceship1_pos.x < 60) {
      spaceship1_pos.x++;
    }
    else if (button_state_lleft == LOW && spaceship1_pos.x > 3) {
      spaceship1_pos.x--;
    }
    if  (button_state_ldown == LOW && spaceship1_pos.y < 30) {
      spaceship1_pos.y++;
    }
    else if   (button_state_lup == LOW && spaceship1_pos.y > 1) {
      spaceship1_pos.y--;
    }

    if ((button_state_rdown == LOW && rocket1_fired == false) || (button_state_rup == LOW && rocket1_fired == false) || (button_state_rleft == LOW && rocket1_fired == false) || (button_state_rright == LOW && rocket1_fired == false)) {
      rocket1_pos.y = spaceship1_pos.y;
      rocket1_pos.x = -4;
      rocket1_fired = true;
    }
  }
  else {
    if (button_state_lleft == LOW && rocket1_fired == false) {
      rocket1_pos.y = spaceship1_pos.y;
      rocket1_pos.x = -4;
      rocket1_fired = true;
    }
    else if (button_state_lright == LOW && rocket1_fired == false) {
      rocket1_pos.y = spaceship1_pos.y;
      rocket1_pos.x = -4;
      rocket1_fired = true;
    }

    if  (button_state_ldown == LOW && spaceship1_pos.y < 30) {
      spaceship1_pos.y++;
    }
    else if   (button_state_lup == LOW && spaceship1_pos.y > 1) {
      spaceship1_pos.y--;
    }

  }
  //AUFGEBEN
  if (button_state_lright == LOW && button_state_lleft == LOW && button_state_ldown == LOW && button_state_lup == LOW) {
    earth_max_health = -1;
  }
}

//Raumschiff fuer Spieler 2 / Bot
void spaceship2() {
  draw_spaceship(spaceship2_pos.x, spaceship2_pos.y, display.color565(25, 0, 25));

  if (singleplayer == true) {
    if (invader_pos[0].y < spaceship2_pos.y) {
      spaceship2_pos.y--;
    }
    else if (invader_pos[0].y > spaceship2_pos.y) {
      spaceship2_pos.y++;
    }
    else if (rocket2_fired == false) {
      rocket2_pos.y = spaceship2_pos.y;
      rocket2_pos.x = -4;
      rocket2_fired = true;
    }
  }
  else {

    if (button_state_rleft == LOW && rocket2_fired == false) {
      rocket2_pos.y = spaceship2_pos.y;
      rocket2_pos.x = -4;
      rocket2_fired = true;
    }
    else if (button_state_rright == LOW && rocket2_fired == false) {
      rocket2_pos.y = spaceship2_pos.y;
      rocket2_pos.x = -4;
      rocket2_fired = true;
    }

    if  (button_state_rdown == LOW && spaceship2_pos.y < 30) {
      spaceship2_pos.y++;
    }
    else if   (button_state_rup == LOW && spaceship2_pos.y > 1) {
      spaceship2_pos.y--;
    }


  }
  if (button_state_rright == LOW && button_state_rleft == LOW && button_state_rdown == LOW && button_state_rup == LOW) {
    earth_max_health = -1;
  }
}

void shoot_rocket() {
  if (rocket1_fired == true) {
    draw_rocket(rocket1_pos.x, rocket1_pos.y, display.color565(50, 50, 25));
    rocket1_pos.x++;
    rocket1_pos.x++;
    if (rocket1_pos.x >= 67) {
      rocket1_fired = false;
      rocket1_pos.x = -4;
    }
  }
  if (rocket2_fired == true) {
    draw_rocket(rocket2_pos.x, rocket2_pos.y, display.color565(25, 50, 50));
    rocket2_pos.x++;
    rocket2_pos.x++;
    if (rocket2_pos.x >= 67) {
      rocket2_fired = false;
      rocket2_pos.x = -4;
    }
  }
}





//Feinde
void enemy_spaceship() {

  for (int i = 0; i < enemies; i++) {

    //Bewegen
    display.drawPixel(invader_pos[i].x, invader_pos[i].y, display.color565(50, 0, 0));
    if (random(4) + 1 >= 2) {
      invader_pos[i].x--;
    }
    //Rakete 1 beruehren
    if (invader_pos[i].x <= rocket1_pos.x + 1 && invader_pos[i].y <= rocket1_pos.y + 1) {
      if (invader_pos[i].x >= rocket1_pos.x - 1 && invader_pos[i].y >= rocket1_pos.y - 1) {
        invader_pos[i].y = random(30) + 1;
        invader_pos[i].x = 110;
      }
    }
    //Rakete 2 beruehren
    if (invader_pos[i].x <= rocket2_pos.x + 1 && invader_pos[i].y <= rocket2_pos.y + 1) {
      if (invader_pos[i].x >= rocket2_pos.x - 1 && invader_pos[i].y >= rocket2_pos.y - 1) {
        invader_pos[i].y = random(30) + 1;
        invader_pos[i].x = 110;
      }
    }
    //Ende beruehren
    if (invader_pos[i].x < 2) {
      earth_max_health--;
      invader_pos[i].x = 80;
      invader_pos[i].y = random(30) + 1;
    }
    //Raumschiff 1 beruehren
    else if (invader_pos[i].x == spaceship1_pos.x + 1 && invader_pos[i].y == spaceship1_pos.y) {
      invader_pos[i].y = random(30) + 1;
      invader_pos[i].x = 100;
    }
    //Raumschiff 2 beruehren
    else if (invader_pos[i].x == spaceship2_pos.x + 1 && invader_pos[i].y == spaceship2_pos.y) {
      invader_pos[i].y = random(30) + 1;
      invader_pos[i].x = 100;

    }
  }
}

//langsam, zufaellig mehr Gegner erschaffen
void calc_enemies() {
  if (random(200 ) == placeholder) {
    enemies++;
    invader_pos[enemies - 1].x = 70;
  }
  if (enemies >= 32)enemies = 32;
}

//Feinde erschaffen
void spawn_invaders() {
  for (int i = 0; i < max_invaders_size; i++) {
    vector spaceshipenemy_pos {70 + i, random(14) + 1};
    invader_pos[i] =  spaceshipenemy_pos ;
  }
}

//Restliches Leben anzeigen
void draw_remaining_health() {

  for (int health = 0; health < earth_max_health; health++) {
    display.drawPixel(1, health, display.color565(0, 55, 0));
  }
}

//Verlieren
void invader_lose() {
  if (earth_max_health < 0) {
    write_y(10, 10, menu_color);
    write_o(14, 10, menu_color);
    write_u(18, 10, menu_color);

    write_l(24, 10, menu_color);
    write_o(28, 10, menu_color);
    write_s(32, 10, menu_color);
    write_t(36, 10, menu_color);
    delay(2000);
    earth_max_health = 32;
    enemies = 1;
    rocket1_fired = false;
    rocket2_fired = false;
    rocket1_pos.x = -4;
    rocket2_pos.x = -4;

    display.clearDisplay();
    gameNumber = 0;

  }

}

//SPIELER RAUMSCHIFF
void draw_spaceship(int x, int y, uint16_t color) {
  display.drawPixel(x, y , color);
  display.drawPixel(x + 1, y , display.color565(25, 25, 100));
  display.drawPixel(x, y + 1 , color);
  display.drawPixel(x, y - 1 , color);
}

//SCHNELLE RAKETE
void draw_rocket(int x, int y, uint16_t color) {
  display.drawPixel(x, y , color);
  display.drawPixel(x + 1, y , color);
  display.drawPixel(x + 2, y , color);
  display.drawPixel(x - 1, y , display.color565(100, 25, 0));
  display.drawPixel(x, y + 1 , color);
  display.drawPixel(x, y - 1 , color);
}
