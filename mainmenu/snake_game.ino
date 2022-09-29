//Schlange
vector snake_tail [2048];
short snake_tail_size = 3;

//Viper (Spieler2)
vector viper_tail [2048];
short viper_tail_size = 3;

//Ist eine Schlange da?
boolean snake = false;
//Ist eine Viper da?
boolean viper = false;

vector snake_pos = {0, 0};
vector snake_movement = {1, 0};
vector viper_pos = {0, 0};
vector viper_movement = {1, 0};

//Verlieren (Spieler1)
boolean lose_snake = false;
//Verlieren (Spieler2)
boolean lose_viper = false;

//Ist Essen da?
boolean food = false;
vector food_pos = {0, 0};


//Score Schlange, einzelne Stellen
short snake_score_0 = 0;
short snake_score_00 = 0;
short snake_score_000 = 0;
short snake_score_0000 = 0;
//Score Viper, einzelne Stellen
short viper_score_0 = 0;
short viper_score_00 = 0;
short viper_score_000 = 0;
short viper_score_0000 = 0;

void create_objects() {
  //Wenn kein Essen, erschaffe neues
  if (!food) {
    food_pos.x = random(60) + 2;
    food_pos.y = random(30) + 1;
    for (short i = snake_tail_size - 1; i > 0; i--) {
      if ((snake_tail[i].x == food_pos.x && snake_tail[i].y == food_pos.y)  ) {
        food_pos.x = random(60) + 2;
        food_pos.y = random(30) + 1;
      }
    }
    for (short i = viper_tail_size - 1; i > 0; i--) {
      if ((viper_tail[i].x == food_pos.x && viper_tail[i].y == food_pos.y)  ) {
        food_pos.x = random(60) + 2;
        food_pos.y = random(30) + 1;
      }
    }
    display.drawPixel(food_pos.x, food_pos.y, display.color565(255, 0, 0 ) );
    food = true;
  }
  //Wenn keine Schlange, erschaffe neue
  if (!snake) {
    snake_pos.x = random(60) + 2;
    snake_pos.y = random(30) + 1;

    snake = true;

  }
  if (singleplayer == false && !viper) {
    viper_pos.x = random(60) + 2;
    viper_pos.y = random(30) + 1;
    viper = true;
  }
}

//Schlange ueberpruefen
void check_snake() {
  //Bewegen
  snake_pos.x += snake_movement.x;
  snake_pos.y += snake_movement.y;

  //Essen beruehrt
  if (snake_pos.x == food_pos.x && snake_pos.y == food_pos.y) {
    snake_tail_size++;
    snake_score_0++;
    food = false;
  }

  //Ränder checken
  if (snake_pos.x > 63) snake_pos.x = 0;
  else if (snake_pos.x < 0) snake_pos.x = 63;
  if (snake_pos.y > 31) snake_pos.y = 0;
  else if (snake_pos.y < 0) snake_pos.y = 31;

  //Verlieren checken (1 Spieler)
  if (singleplayer == true) {
    for (short i = snake_tail_size - 1; i > 0; i--) {
      if (snake_tail[i].x == snake_pos.x && snake_tail[i].y == snake_pos.y) {
        lose_snake = true;
      }
    }
  }
  //Verlieren checken (2 Spieler)
  else {
    for (short j = viper_tail_size - 1; j > 0; j--) {

      if (viper_tail[j].x == snake_pos.x && viper_tail[j].y == snake_pos.y) {
        lose_snake = true;
      }
    }
  }
  update_snake_tail(snake_pos.x, snake_pos.y);

}

//Viper ueberpruefen
void check_viper() {
  //Bewegen
  viper_pos.x += viper_movement.x;
  viper_pos.y += viper_movement.y;

  //Essen beruehrt
  if (viper_pos.x == food_pos.x && viper_pos.y == food_pos.y) {
    viper_tail_size++;
    viper_score_0++;
    food = false;
  }

  //Ränder checken
  if (viper_pos.x > 63) viper_pos.x = 0;
  else if (viper_pos.x < 0) viper_pos.x = 63;
  if (viper_pos.y > 31) viper_pos.y = 0;
  else if (viper_pos.y < 0) viper_pos.y = 31;

  //Verlieren checken
  for (short i = snake_tail_size - 1; i > 0; i--) {
    if (snake_tail[i].x == viper_pos.x && snake_tail[i].y == viper_pos.y) {
      lose_viper = true;
    }
  }
  update_viper_tail(viper_pos.x, viper_pos.y);
}



void draw_snake() {
  for (short i = 0; i < snake_tail_size; i++) {
    display.drawPixel(snake_tail[i].x, snake_tail[i].y, green );
  }
}
void draw_viper() {
  for (short i = 0; i < viper_tail_size; i++) {
    display.drawPixel(viper_tail[i].x, viper_tail[i].y, purple );
  }
}

void update_snake_tail(int x, int y) {
  display.drawPixel(snake_tail[snake_tail_size - 1].x, snake_tail[snake_tail_size - 1].y, remove_color);
  for (short i = snake_tail_size - 1; i > 0; i--) {
    snake_tail[i].x =  snake_tail[i - 1].x;
    snake_tail[i].y =  snake_tail[i - 1].y;
  }
  snake_tail[0].x = x;
  snake_tail[0].y = y;

}
void update_viper_tail(int x, int y) {
  display.drawPixel(viper_tail[viper_tail_size - 1].x, viper_tail[viper_tail_size - 1].y, remove_color);
  for (short i = viper_tail_size - 1; i > 0; i--) {
    viper_tail[i].x =  viper_tail[i - 1].x;
    viper_tail[i].y =  viper_tail[i - 1].y;
  }
  viper_tail[0].x = x;
  viper_tail[0].y = y;

}

//Bewegung Schlange
void snake_button() {

  if (button_state_lup == LOW && snake_movement.y != 1) {
    snake_movement = {0, -1};
  }

  else if (button_state_ldown == LOW && snake_movement.y != -1 ) {
    snake_movement = {0, 1};
  }

  else if (button_state_lleft == LOW && snake_movement.x != 1) {
    snake_movement = { -1, 0};
  }

  else if (button_state_lright == LOW && snake_movement.x != -1) {
    snake_movement = {1, 0};
  }
  //AUFGEBEN
  if (button_state_lright == LOW && button_state_lleft == LOW && button_state_ldown == LOW && button_state_lup == LOW) {
    lose_snake = true;
  }

}
//Bewegung Viper
void viper_button() {

  if (button_state_rup == LOW && viper_movement.y != 1) {
    viper_movement = {0, -1};
  }

  else if (button_state_rdown == LOW && viper_movement.y != -1 ) {
    viper_movement = {0, 1};
  }

  else if (button_state_rleft == LOW && viper_movement.x != 1) {
    viper_movement = { -1, 0};
  }

  else if (button_state_rright == LOW && viper_movement.x != -1) {
    viper_movement = {1, 0};
  }
  //AUFGEBEN
  if (button_state_rright == LOW && button_state_rleft == LOW && button_state_rdown == LOW && button_state_rup == LOW) {
    lose_viper = true;
  }



}





//Methode damit ich Score korrekt anzeigen lassen kann
void calc_snake_score() {
  if (snake_score_0 == 10) {
    snake_score_00++;
    snake_score_0 = 0;
    if (snake_score_00 == 100) {
      snake_score_000++;
      snake_score_00 = 0;
      if (snake_score_000 == 1000) {
        snake_score_0000++;
        snake_score_000 = 0;
      }
    }
  }
  else if (viper_score_0 == 10) {
    viper_score_00++;
    viper_score_0 = 0;
    if (viper_score_00 == 100) {
      viper_score_000++;
      viper_score_00 = 0;
      if (viper_score_000 == 1000) {
        viper_score_0000++;
        viper_score_000 = 0;
      }
    }
  }
}


//Schauen ob Spieler verloren hat + Score anzeigen
void check_snake_lose() {

  if (lose_snake) {
    if (singleplayer) {
      delay(200);
      display.clearDisplay();
      write_s(10, 10, menu_color);
      write_n(14, 10, menu_color);
      write_a(18, 10, menu_color);
      write_k(22, 10, menu_color);
      write_e(26, 10, menu_color);

      write_l(32, 10, menu_color);
      write_o(36, 10, menu_color);
      write_s(40, 10, menu_color);
      write_t(44, 10, menu_color);

      write_s(10, 17, menu_color);
      write_c(14, 17, menu_color);
      write_o(18, 17, menu_color);
      write_r(22, 17, menu_color);
      write_e(26, 17, menu_color);

      if (snake_score_0000 == 1) write_1(31, 17, green);
      else if (snake_score_0000 == 2) write_2(31, 17, green);
      else  write_0(31, 17, green);

      if (snake_score_000 == 1) write_1(35, 17, green);
      else if (snake_score_000 == 2) write_2(35, 17, green);
      else if (snake_score_000 == 3) write_3(35, 17, green);
      else if (snake_score_000 == 4) write_4(35, 17, green);
      else if (snake_score_000 == 5) write_5(35, 17, green);
      else if (snake_score_000 == 6) write_6(35, 17, green);
      else if (snake_score_000 == 7) write_7(35, 17, green);
      else if (snake_score_000 == 8) write_8(35, 17, green);
      else if (snake_score_000 == 9) write_9(35, 17, green);
      else  write_0(35, 17, green);

      if (snake_score_00 == 1) write_1(39, 17, green);
      else if (snake_score_00 == 2) write_2(39, 17, green);
      else if (snake_score_00 == 3) write_3(39, 17, green);
      else if (snake_score_00 == 4) write_4(39, 17, green);
      else if (snake_score_00 == 5) write_5(39, 17, green);
      else if (snake_score_00 == 6) write_6(39, 17, green);
      else if (snake_score_00 == 7) write_7(39, 17, green);
      else if (snake_score_00 == 8) write_8(39, 17, green);
      else if (snake_score_00 == 9) write_9(39, 17, green);
      else  write_0(39, 17, green);

      if (snake_score_0 == 1) write_1(43, 17, green);
      else if (snake_score_0 == 2) write_2(43, 17, green);
      else if (snake_score_0 == 3) write_3(43, 17, green);
      else if (snake_score_0 == 4) write_4(43, 17, green);
      else if (snake_score_0 == 5) write_5(43, 17, green);
      else if (snake_score_0 == 6) write_6(43, 17, green);
      else if (snake_score_0 == 7) write_7(43, 17, green);
      else if (snake_score_0 == 8) write_8(43, 17, green);
      else if (snake_score_0 == 9) write_9(43, 17, green);
      else  write_0(43, 17, green);


      delay(2000);
      display.clearDisplay();
      snake_score_0 = 0;
      snake_score_00 = 0;
      snake_score_000 = 0;
      snake_score_0000 = 0;
      snake = false;
      food = false;
      lose_snake = false;
      gameNumber = 0;
    }
    else {
      delay(200);
      display.clearDisplay();
      write_s(10, 10, menu_color);
      write_n(14, 10, menu_color);
      write_a(18, 10, menu_color);
      write_k(22, 10, menu_color);
      write_e(26, 10, menu_color);

      write_l(32, 10, menu_color);
      write_o(36, 10, menu_color);
      write_s(40, 10, menu_color);
      write_t(44, 10, menu_color);

      write_s(10, 17, menu_color);
      write_c(14, 17, menu_color);
      write_o(18, 17, menu_color);
      write_r(22, 17, menu_color);
      write_e(26, 17, menu_color);

      if (snake_score_0000 == 1) write_1(31, 17, green);
      else if (snake_score_0000 == 2) write_2(31, 17, green);
      else  write_0(31, 17, green);

      if (snake_score_000 == 1) write_1(35, 17, green);
      else if (snake_score_000 == 2) write_2(35, 17, green);
      else if (snake_score_000 == 3) write_3(35, 17, green);
      else if (snake_score_000 == 4) write_4(35, 17, green);
      else if (snake_score_000 == 5) write_5(35, 17, green);
      else if (snake_score_000 == 6) write_6(35, 17, green);
      else if (snake_score_000 == 7) write_7(35, 17, green);
      else if (snake_score_000 == 8) write_8(35, 17, green);
      else if (snake_score_000 == 9) write_9(35, 17, green);
      else  write_0(35, 17, green);

      if (snake_score_00 == 1) write_1(39, 17, green);
      else if (snake_score_00 == 2) write_2(39, 17, green);
      else if (snake_score_00 == 3) write_3(39, 17, green);
      else if (snake_score_00 == 4) write_4(39, 17, green);
      else if (snake_score_00 == 5) write_5(39, 17, green);
      else if (snake_score_00 == 6) write_6(39, 17, green);
      else if (snake_score_00 == 7) write_7(39, 17, green);
      else if (snake_score_00 == 8) write_8(39, 17, green);
      else if (snake_score_00 == 9) write_9(39, 17, green);
      else  write_0(39, 17, green);

      if (snake_score_0 == 1) write_1(43, 17, green);
      else if (snake_score_0 == 2) write_2(43, 17, green);
      else if (snake_score_0 == 3) write_3(43, 17, green);
      else if (snake_score_0 == 4) write_4(43, 17, green);
      else if (snake_score_0 == 5) write_5(43, 17, green);
      else if (snake_score_0 == 6) write_6(43, 17, green);
      else if (snake_score_0 == 7) write_7(43, 17, green);
      else if (snake_score_0 == 8) write_8(43, 17, green);
      else if (snake_score_0 == 9) write_9(43, 17, green);
      else  write_0(43, 17, green);




      if (viper_score_0000 == 1) write_1(31, 24, purple);
      else if (viper_score_0000 == 2) write_2(31, 24, purple);
      else  write_0(31, 24, purple);

      if (viper_score_000 == 1) write_1(35, 24, purple);
      else if (viper_score_000 == 2) write_2(35, 24, purple);
      else if (viper_score_000 == 3) write_3(35, 24, purple);
      else if (viper_score_000 == 4) write_4(35, 24, purple);
      else if (viper_score_000 == 5) write_5(35, 24, purple);
      else if (viper_score_000 == 6) write_6(35, 24, purple);
      else if (viper_score_000 == 7) write_7(35, 24, purple);
      else if (viper_score_000 == 8) write_8(35, 24, purple);
      else if (viper_score_000 == 9) write_9(35, 24, purple);
      else  write_0(35, 24, purple);

      if (viper_score_00 == 1) write_1(39, 24, purple);
      else if (viper_score_00 == 2) write_2(39, 24, purple);
      else if (viper_score_00 == 3) write_3(39, 24, purple);
      else if (viper_score_00 == 4) write_4(39, 24, purple);
      else if (viper_score_00 == 5) write_5(39, 24, purple);
      else if (viper_score_00 == 6) write_6(39, 24, purple);
      else if (viper_score_00 == 7) write_7(39, 24, purple);
      else if (viper_score_00 == 8) write_8(39, 24, purple);
      else if (viper_score_00 == 9) write_9(39, 24, purple);
      else  write_0(39, 24, purple);

      if (viper_score_0 == 1) write_1(43, 24, purple);
      else if (viper_score_0 == 2) write_2(43, 24, purple);
      else if (viper_score_0 == 3) write_3(43, 24, purple);
      else if (viper_score_0 == 4) write_4(43, 24, purple);
      else if (viper_score_0 == 5) write_5(43, 24, purple);
      else if (viper_score_0 == 6) write_6(43, 24, purple);
      else if (viper_score_0 == 7) write_7(43, 24, purple);
      else if (viper_score_0 == 8) write_8(43, 24, purple);
      else if (viper_score_0 == 9) write_9(43, 24, purple);
      else  write_0(43, 24, purple);

      delay(2000);
      display.clearDisplay();
      snake_score_0 = 0;
      snake_score_00 = 0;
      snake_score_000 = 0;
      snake_score_0000 = 0;
      viper_score_0 = 0;
      viper_score_00 = 0;
      viper_score_000 = 0;
      viper_score_0000 = 0;
      snake = false;
      viper = false;
      food = false;
      lose_snake = false;
      lose_viper = false;
      gameNumber = 0;
    }
  }
  if (lose_viper) {
    delay(200);
    display.clearDisplay();
    write_v(10, 10, menu_color);
    write_i(14, 10, menu_color);
    write_p(18, 10, menu_color);
    write_e(22, 10, menu_color);
    write_r(26, 10, menu_color);

    write_l(32, 10, menu_color);
    write_o(36, 10, menu_color);
    write_s(40, 10, menu_color);
    write_t(44, 10, menu_color);

    write_s(10, 17, menu_color);
    write_c(14, 17, menu_color);
    write_o(18, 17, menu_color);
    write_r(22, 17, menu_color);
    write_e(26, 17, menu_color);

    if (viper_score_0000 == 1) write_1(31, 17, purple);
    else if (viper_score_0000 == 2) write_2(31, 17, purple);
    else  write_0(31, 17, purple);

    if (viper_score_000 == 1) write_1(35, 17, purple);
    else if (viper_score_000 == 2) write_2(35, 17, purple);
    else if (viper_score_000 == 3) write_3(35, 17, purple);
    else if (viper_score_000 == 4) write_4(35, 17, purple);
    else if (viper_score_000 == 5) write_5(35, 17, purple);
    else if (viper_score_000 == 6) write_6(35, 17, purple);
    else if (viper_score_000 == 7) write_7(35, 17, purple);
    else if (viper_score_000 == 8) write_8(35, 17, purple);
    else if (viper_score_000 == 9) write_9(35, 17, purple);
    else  write_0(35, 17, purple);

    if (viper_score_00 == 1) write_1(39, 17, purple);
    else if (viper_score_00 == 2) write_2(39, 17, purple);
    else if (viper_score_00 == 3) write_3(39, 17, purple);
    else if (viper_score_00 == 4) write_4(39, 17, purple);
    else if (viper_score_00 == 5) write_5(39, 17, purple);
    else if (viper_score_00 == 6) write_6(39, 17, purple);
    else if (viper_score_00 == 7) write_7(39, 17, purple);
    else if (viper_score_00 == 8) write_8(39, 17, purple);
    else if (viper_score_00 == 9) write_9(39, 17, purple);
    else  write_0(39, 17, purple);

    if (viper_score_0 == 1) write_1(43, 17, purple);
    else if (viper_score_0 == 2) write_2(43, 17, purple);
    else if (viper_score_0 == 3) write_3(43, 17, purple);
    else if (viper_score_0 == 4) write_4(43, 17, purple);
    else if (viper_score_0 == 5) write_5(43, 17, purple);
    else if (viper_score_0 == 6) write_6(43, 17, purple);
    else if (viper_score_0 == 7) write_7(43, 17, purple);
    else if (viper_score_0 == 8) write_8(43, 17, purple);
    else if (viper_score_0 == 9) write_9(43, 17, purple);
    else  write_0(43, 17, purple);


    if (snake_score_0000 == 1) write_1(31, 24, green);
    else if (snake_score_0000 == 2) write_2(31, 24, green);
    else  write_0(31, 24, green);

    if (snake_score_000 == 1) write_1(35, 24, green);
    else if (snake_score_000 == 2) write_2(35, 24, green);
    else if (snake_score_000 == 3) write_3(35, 24, green);
    else if (snake_score_000 == 4) write_4(35, 24, green);
    else if (snake_score_000 == 5) write_5(35, 24, green);
    else if (snake_score_000 == 6) write_6(35, 24, green);
    else if (snake_score_000 == 7) write_7(35, 24, green);
    else if (snake_score_000 == 8) write_8(35, 24, green);
    else if (snake_score_000 == 9) write_9(35, 24, green);
    else  write_0(35, 24, green);

    if (snake_score_00 == 1) write_1(39, 24, green);
    else if (snake_score_00 == 2) write_2(39, 24, green);
    else if (snake_score_00 == 3) write_3(39, 24, green);
    else if (snake_score_00 == 4) write_4(39, 24, green);
    else if (snake_score_00 == 5) write_5(39, 24, green);
    else if (snake_score_00 == 6) write_6(39, 24, green);
    else if (snake_score_00 == 7) write_7(39, 24, green);
    else if (snake_score_00 == 8) write_8(39, 24, green);
    else if (snake_score_00 == 9) write_9(39, 24, green);
    else  write_0(39, 24, green);

    if (snake_score_0 == 1) write_1(43, 24, green);
    else if (snake_score_0 == 2) write_2(43, 24, green);
    else if (snake_score_0 == 3) write_3(43, 24, green);
    else if (snake_score_0 == 4) write_4(43, 24, green);
    else if (snake_score_0 == 5) write_5(43, 24, green);
    else if (snake_score_0 == 6) write_6(43, 24, green);
    else if (snake_score_0 == 7) write_7(43, 24, green);
    else if (snake_score_0 == 8) write_8(43, 24, green);
    else if (snake_score_0 == 9) write_9(43, 24, green);
    else  write_0(43, 24, green);



    delay(2000);
    snake_score_0 = 0;
    snake_score_00 = 0;
    snake_score_000 = 0;
    snake_score_0000 = 0;
    viper_score_0 = 0;
    viper_score_00 = 0;
    viper_score_000 = 0;
    viper_score_0000 = 0;
    snake = false;
    viper = false;
    food = false;
    lose_snake = false;
    lose_viper = false;
    display.clearDisplay();
    gameNumber = 0;
  }



}
