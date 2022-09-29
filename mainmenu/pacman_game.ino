/* 0 ESSEN
   1 WAND
   2 LEER
   3 PILLEN
   4 BLINKY
   5 PINKY
   6 INKY
   7 CLYDE
   8 PACMAN */
vector pacman_mappos = {0, 0};
short pacman_map[]  = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 3, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 3, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 5, 6, 7, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 3, 1,
  1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
  1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
  1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};
short backup_map[]  = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 3, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 3, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 5, 6, 7, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 2, 2, 2, 2, 2,
  1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
  1, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 3, 1,
  1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
  1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
  1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
  1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};



int pacman_pos = 0;
boolean pill_eaten = false;
int pill_timer = 0;
int remaining_food = 0;

int selected_ghost = 1;
int blinky_pos = 0;
int last_blinky_pos = 2;
int pinky_pos = 0;
int last_pinky_pos = 2;
int inky_pos = 0;
int last_inky_pos = 2;
int clyde_pos = 0;
int last_clyde_pos = 2;



//Score, einzelne Stellen
int pac_score_0 = 0;
int pac_score_00 = 0;
int pac_score_000 = 0;
int pac_score_0000 = 0;

void draw_pacmanmap() {
  //groeße array in bytes geteilt durch groeße von 1 int
  remaining_food = 0;
  for (short i  = 0; i < sizeof(pacman_map) / sizeof(short); i++) {

    //ESSEN
    if (pacman_map[i] == 0) {
      display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(25, 25, 25));
      remaining_food++;
    }
    //WAND
    else if (pacman_map[i] == 1) {
      display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(0, 0, 35));
    }
    //LEER
    else if (pacman_map[i] == 2) {
      display.drawPixel(pacman_mappos.x, pacman_mappos.y , remove_color);
    }
    //PILLEN
    else if (pacman_map[i] == 3) {
      display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(50, 255, 50));
    }
    //BLINKY
    else if (pacman_map[i] == 4) {
      if (pill_eaten == false) display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(100, 0, 0));
      else  display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(100, 0, 100));
      blinky_pos = i;
    }
    //PINKY
    else if (pacman_map[i] == 5) {
      if (pill_eaten == false) display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(255, 20, 150));
      else  display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(100, 0, 100));
      pinky_pos = i;
    }
    //INKY
    else if (pacman_map[i] == 6) {
      if (pill_eaten == false) display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(0, 191, 255));
      else  display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(100, 0, 100));
      inky_pos = i;
    }
    //CLYDE
    else if (pacman_map[i] == 7) {
      if (pill_eaten == false) display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(255, 100, 30));
      else  display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(100, 0, 100));
      clyde_pos = i;
    }
    //PACMAN
    else if (pacman_map[i] == 8) {
      display.drawPixel(pacman_mappos.x, pacman_mappos.y , display.color565(100, 100, 0));
      pacman_pos = i;
    }

    //ZEICHNEN
    pacman_mappos.x++;

    if (pacman_mappos.x == 28) {
      pacman_mappos.x = 0;
      pacman_mappos.y++;
    }
    if (pacman_mappos.y == 31) {
      pacman_mappos.y = 0;
    }
  }
}

void move_pacman() {
  //RIGHT
  if (button_state_lright == LOW && pacman_map[pacman_pos + 1] != 1) {
    pacman_map[pacman_pos] = 2;
    if (pacman_map[pacman_pos + 1] == 0)pac_score_0++;
    else if (pacman_map[pacman_pos + 1] == 3)pill_eaten = true;
    pacman_map[pacman_pos + 1] = 8;
  }
  //LEFT
  else if (button_state_lleft == LOW && pacman_map[pacman_pos - 1] != 1) {
    pacman_map[pacman_pos] = 2;
    if (pacman_map[pacman_pos - 1] == 0)pac_score_0++;
    else if (pacman_map[pacman_pos - 1] == 3)pill_eaten = true;
    pacman_map[pacman_pos - 1] = 8;
  }
  //DOWN
  else if (button_state_ldown == LOW && pacman_map[pacman_pos + 28] != 1) {
    pacman_map[pacman_pos] = 2;
    if (pacman_map[pacman_pos + 28] == 0)pac_score_0++;
    else if (pacman_map[pacman_pos + 28] == 3)pill_eaten = true;
    pacman_map[pacman_pos + 28] = 8;
  }
  //UP
  else if (button_state_lup == LOW && pacman_map[pacman_pos - 28] != 1) {
    pacman_map[pacman_pos] = 2;
    if (pacman_map[pacman_pos - 28] == 0)pac_score_0++;
    else if (pacman_map[pacman_pos - 28] == 3)pill_eaten = true;
    pacman_map[pacman_pos - 28] = 8;
  }
  //Tunnel benutzen
  if (pacman_pos == 419) {
    pacman_map[419] = 2;
    pacman_map[393] = 8;
  }
  else if (pacman_pos == 392) {
    pacman_map[392] = 2;
    pacman_map[418] = 8;
  }

  //AUFGEBEN
  if (button_state_lright == LOW && button_state_lleft == LOW && button_state_ldown == LOW && button_state_lup == LOW) {
    pacman_pos = blinky_pos;
  }

  if (pill_eaten == true) {
    pill_timer++;
    if (pill_timer >= 100) {
      pill_eaten = false;
      pill_timer = 0;
    }

    if (pacman_pos == blinky_pos ) {
      pacman_map[404] = 4;
      last_blinky_pos = 2;
    }
    else if (pacman_pos == pinky_pos ) {
      pacman_map[405] = 5;
      last_pinky_pos = 2;
    }
    else if (pacman_pos == inky_pos ) {
      pacman_map[406] = 6;
      last_inky_pos = 2;
    }
    else if (pacman_pos == pinky_pos ) {
      pacman_map[407] = 7;
      last_clyde_pos = 2;
    }
  }



}

void move_ghosts() {
  if ((button_state_rup == LOW && button_state_rdown == LOW) && button_press_rup == false) {
    selected_ghost++;
    if (selected_ghost == 5) selected_ghost = 1;
    button_press_rup = true;
  }
  else if ((button_state_rup == HIGH || button_state_rdown == HIGH ) && button_press_rup == true) {
    button_press_rup = false;
  }
  else if ((button_state_rright == LOW && button_state_rleft == LOW) && button_press_rright == false) {
    selected_ghost--;
    if (selected_ghost == 0) selected_ghost = 4;
    button_press_rright = true;
  }
  else if ((button_state_rright == HIGH || button_state_rleft == HIGH ) && button_press_rright == true) {
    button_press_rright = false;
  }
  //AUFGEBEN
  if (button_state_rright == LOW && button_state_rleft == LOW && button_state_rdown == LOW && button_state_rup == LOW) {
    pacman_pos = blinky_pos;

  }



  if (selected_ghost == 1) {
    if (button_state_rright == LOW && pacman_map[blinky_pos + 1] != 1) {
      pacman_map[blinky_pos] = last_blinky_pos;
      last_blinky_pos = pacman_map[blinky_pos + 1];
      pacman_map[blinky_pos + 1] = 4;
    }
    else if (button_state_rleft == LOW && pacman_map[blinky_pos - 1] != 1) {
      pacman_map[blinky_pos] = last_blinky_pos;
      last_blinky_pos = pacman_map[blinky_pos - 1];
      pacman_map[blinky_pos - 1] = 4;
    }
    else if (button_state_rdown == LOW && pacman_map[blinky_pos + 28] != 1) {
      pacman_map[blinky_pos] = last_blinky_pos;
      last_blinky_pos = pacman_map[blinky_pos + 28];
      pacman_map[blinky_pos + 28] = 4;
    }
    else if (button_state_rup == LOW && pacman_map[blinky_pos - 28] != 1) {
      pacman_map[blinky_pos] = last_blinky_pos;
      last_blinky_pos = pacman_map[blinky_pos - 28];
      pacman_map[blinky_pos - 28] = 4;
    }
    //Tunnel benutzen
    if (blinky_pos == 419) {
      pacman_map[419] = last_blinky_pos;
      pacman_map[393] = 4;
    }
    else if (blinky_pos == 392) {
      pacman_map[392] = last_blinky_pos;
      pacman_map[418] = 4;
    }
  }
  else if (selected_ghost == 2) {
    if (button_state_rright == LOW && pacman_map[pinky_pos + 1] != 1) {
      pacman_map[pinky_pos] = last_pinky_pos;
      last_pinky_pos = pacman_map[pinky_pos + 1];
      pacman_map[pinky_pos + 1] = 5;
    }
    else if (button_state_rleft == LOW && pacman_map[pinky_pos - 1] != 1) {
      pacman_map[pinky_pos] = last_pinky_pos;
      last_pinky_pos = pacman_map[pinky_pos - 1];
      pacman_map[pinky_pos - 1] = 5;
    }
    else if (button_state_rdown == LOW && pacman_map[pinky_pos + 28] != 1) {
      pacman_map[pinky_pos] = last_pinky_pos;
      last_pinky_pos = pacman_map[pinky_pos + 28];
      pacman_map[pinky_pos + 28] = 5;
    }
    else if (button_state_rup == LOW && pacman_map[pinky_pos - 28] != 1) {
      pacman_map[pinky_pos] = last_pinky_pos;
      last_pinky_pos = pacman_map[pinky_pos - 28];
      pacman_map[pinky_pos - 28] = 5;
    }
    //Tunnel benutzen
    if (pinky_pos == 419) {
      pacman_map[419] = last_pinky_pos;
      pacman_map[393] = 5;
    }
    else if (pinky_pos == 392) {
      pacman_map[392] = last_pinky_pos;
      pacman_map[418] = 5;
    }
  }
  else if (selected_ghost == 3) {
    if (button_state_rright == LOW && pacman_map[inky_pos + 1] != 1) {
      pacman_map[inky_pos] = last_inky_pos;
      last_inky_pos = pacman_map[inky_pos + 1];
      pacman_map[inky_pos + 1] = 6;
    }
    else if (button_state_rleft == LOW && pacman_map[inky_pos - 1] != 1) {
      pacman_map[inky_pos] = last_inky_pos;
      last_inky_pos = pacman_map[inky_pos - 1];
      pacman_map[inky_pos - 1] = 6;
    }
    else if (button_state_rdown == LOW && pacman_map[inky_pos + 28] != 1) {
      pacman_map[inky_pos] = last_inky_pos;
      last_inky_pos = pacman_map[inky_pos + 28];
      pacman_map[inky_pos + 28] = 6;
    }
    else if (button_state_rup == LOW && pacman_map[inky_pos - 28] != 1) {
      pacman_map[inky_pos] = last_inky_pos;
      last_inky_pos = pacman_map[inky_pos - 28];
      pacman_map[inky_pos - 28] = 6;
    }
    //Tunnel benutzen
    if (inky_pos == 419) {
      pacman_map[419] = last_inky_pos;
      pacman_map[393] = 6;
    }
    else if (inky_pos == 392) {
      pacman_map[392] = last_inky_pos;
      pacman_map[418] = 6;
    }
  }
  else if (selected_ghost == 4) {
    if (button_state_rright == LOW && pacman_map[clyde_pos + 1] != 1) {
      pacman_map[clyde_pos] = last_clyde_pos;
      last_clyde_pos = pacman_map[clyde_pos + 1];
      pacman_map[clyde_pos + 1] = 7;
    }
    else if (button_state_rleft == LOW && pacman_map[clyde_pos - 1] != 1) {
      pacman_map[clyde_pos] = last_clyde_pos;
      last_clyde_pos = pacman_map[clyde_pos - 1];
      pacman_map[clyde_pos - 1] = 7;
    }
    else if (button_state_rdown == LOW && pacman_map[clyde_pos + 28] != 1) {
      pacman_map[clyde_pos] = last_clyde_pos;
      last_clyde_pos = pacman_map[clyde_pos + 28];
      pacman_map[clyde_pos + 28] = 7;
    }
    else if (button_state_rup == LOW && pacman_map[clyde_pos - 28] != 1) {
      pacman_map[clyde_pos] = last_clyde_pos;
      last_clyde_pos = pacman_map[clyde_pos - 28];
      pacman_map[clyde_pos - 28] = 7;
    }
    //Tunnel benutzen
    if (clyde_pos == 419) {
      pacman_map[419] = last_clyde_pos;
      pacman_map[393] = 7;
    }
    else if (clyde_pos == 392) {
      pacman_map[392] = last_clyde_pos;
      pacman_map[418] = 7;
    }
  }
}

void pacman_gameover() {
  //GHOSTS WIN
  if ((pacman_pos == blinky_pos || pacman_pos == pinky_pos || pacman_pos == inky_pos || pacman_pos == clyde_pos) && pill_eaten == false ) {
    delay(2000);
    display.clearDisplay();
    pac_score_0 = 0;
    pac_score_00 = 0;
    pac_score_000 = 0;
    remaining_food = 0;
    for (short i  = 0; i < sizeof(pacman_map) / sizeof(short); i++) {
      pacman_map[i] = backup_map[i];
    }
    gameNumber = 0;
  }
  //PACMAN WIN
  if (remaining_food <= 4) {
    delay(2000);
    display.clearDisplay();
    pac_score_0 = 0;
    pac_score_00 = 0;
    pac_score_000 = 0;
    remaining_food = 0;
    for (short i  = 0; i < sizeof(pacman_map) / sizeof(short); i++) {
      pacman_map[i] = backup_map[i];
    }
    gameNumber = 0;


  }


}

void calc_pacman_score() {
  if (pac_score_0 == 10) {
    pac_score_00++;
    pac_score_0 = 0;
    if (pac_score_00 == 100) {
      pac_score_000++;
      pac_score_00 = 0;
      if (pac_score_000 == 1000) {
        pac_score_0000++;
        pac_score_000 = 0;
      }
    }
  }

  write_s(35, 5, menu_color);
  write_c(39, 5, menu_color);
  write_o(43, 5, menu_color);
  write_r(47, 5, menu_color);
  write_e(51, 5, menu_color);

  write_empty(35, 13);
  if (pac_score_000 == 0)write_0(35, 13, score_color);
  else if (pac_score_000 == 1) write_1(35, 13, score_color);
  else if (pac_score_000 == 2) write_2(35, 13, score_color);
  else if (pac_score_000 == 3) write_3(35, 13, score_color);
  else if (pac_score_000 == 4) write_4(35, 13, score_color);
  else if (pac_score_000 == 5) write_5(35, 13, score_color);
  else if (pac_score_000 == 6) write_6(35, 13, score_color);
  else if (pac_score_000 == 7) write_7(35, 13, score_color);
  else if (pac_score_000 == 8) write_8(35, 13, score_color);
  else  write_9(35, 13, score_color);

  write_empty(39, 13);
  if (pac_score_00 == 0)write_0(39, 13, score_color);
  else if (pac_score_00 == 1) write_1(39, 13, score_color);
  else if (pac_score_00 == 2) write_2(39, 13, score_color);
  else if (pac_score_00 == 3) write_3(39, 13, score_color);
  else if (pac_score_00 == 4) write_4(39, 13, score_color);
  else if (pac_score_00 == 5) write_5(39, 13, score_color);
  else if (pac_score_00 == 6) write_6(39, 13, score_color);
  else if (pac_score_00 == 7) write_7(39, 13, score_color);
  else if (pac_score_00 == 8) write_8(39, 13, score_color);
  else   write_9(39, 13, score_color);

  write_empty(43, 13);
  if (pac_score_0 == 0)write_0(43, 13, score_color);
  else  if (pac_score_0 == 1) write_1(43, 13, score_color);
  else if (pac_score_0 == 2) write_2(43, 13, score_color);
  else if (pac_score_0 == 3) write_3(43, 13, score_color);
  else if (pac_score_0 == 4) write_4(43, 13, score_color);
  else if (pac_score_0 == 5) write_5(43, 13, score_color);
  else if (pac_score_0 == 6) write_6(43, 13, score_color);
  else if (pac_score_0 == 7) write_7(43, 13, score_color);
  else if (pac_score_0 == 8) write_8(43, 13, score_color);
  else   write_9(43, 13, score_color);


}
