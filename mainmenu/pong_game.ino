boolean pong_win  = false;
boolean updated_score = false;
short player_left_score = 0;
short player_right_score = 0;

vector ball_pos = {32, 16};
vector ball_speed = {1, 1};

vector leftwall_1_pos = {3, 16};
vector leftwall_2_pos = {3, 20};

vector rightwall_1_pos = {60, 16};
vector rightwall_2_pos = {60, 20};

vector ball_trail[5];
int ball_trail_color_intensity[5] = {255, 100, 60, 30, 5};
int ball_trail_size = 5;
//vector wall_player1[5] = {{3, 16}, {3, 17}, {3, 18}, {3, 19}, {3, 20}};
int wall_size = 5;



void pong() {

  ball_pos.x += ball_speed.x;
  ball_pos.y += ball_speed.y;

  //LINKER SPIELER PUNKT
  if (ball_pos.x >= 63) {
    updated_score = false;
    ball_pos.x = 32;
    ball_pos.y = random(30) + 1;
    player_left_score = player_left_score + 1;
    delay(100);
    ball_speed = { -ball_speed.x, ball_speed.y};
    //Serial.print("player_left_score: ");
    //Serial.println(player_left_score);
  }
  //RECHTER SPIELER PUNKT
  else if (ball_pos.x <= 0) {
    updated_score = false;
    ball_pos.x = 32;
    ball_pos.y = random(30) + 1;
    player_right_score = player_right_score + 1;
    delay(100);
    ball_speed = { -ball_speed.x, ball_speed.y};
    //Serial.print( "player_right_score: ");
    //Serial.println( player_right_score);
  }
  //UNTEN OBEN CHECK
  if (ball_pos.y >= 31) {
    ball_speed.y = -ball_speed.y;
  }
  else if (ball_pos.y <= 0) {
    ball_speed.y = -ball_speed.y;
  }

  //LINKE WAND
  if (ball_pos.x == leftwall_1_pos.x && ball_pos.y <= leftwall_2_pos.y && ball_pos.y >= leftwall_1_pos.y) {
    ball_speed.x = -ball_speed.x;
  }

  //RECHTE WAND
  if (ball_pos.x == rightwall_1_pos.x && ball_pos.y <= rightwall_2_pos.y && ball_pos.y >= rightwall_1_pos.y) {
    ball_speed.x = -ball_speed.x;
  }

  update_ball_trail(ball_pos.x, ball_pos.y);

}

//alle um 1 verschieben letztes loeschen
void update_ball_trail(int x, int y) {
  display.drawPixel(ball_trail[ball_trail_size - 1].x, ball_trail[ball_trail_size - 1].y, remove_color);
  for (int i = ball_trail_size - 1; i > 0; i--) {
    ball_trail[i].x =  ball_trail[i - 1].x;
    ball_trail[i].y =  ball_trail[i - 1].y;
  }
  ball_trail[0].x = x;
  ball_trail[0].y = y;
}


void draw_ball() {
  for (int i = 0; i < ball_trail_size; i++) {
    display.drawPixel(ball_trail[i].x, ball_trail[i].y, display.color565(0, 0, ball_trail_color_intensity[i] ) );
  }
}


void update_leftwall_trail(boolean up) {

  if (up == true) {
    display.drawPixel(leftwall_1_pos.x, leftwall_1_pos.y + wall_size - 1, remove_color);
  }
  else {
    display.drawPixel(leftwall_2_pos.x, leftwall_2_pos.y - wall_size + 1, remove_color);
  }
}


void update_rightwall_trail(boolean up) {
  if (up == true) {

    display.drawPixel(rightwall_1_pos.x, rightwall_1_pos.y + wall_size - 1, remove_color);
  }
  else {
    display.drawPixel(rightwall_2_pos.x, rightwall_2_pos.y - wall_size + 1, remove_color);
  }
}


//Linke Wand zeichnen
void draw_leftwall() {
  for (int i = 0; i < wall_size; i++) {
    display.drawPixel(leftwall_1_pos.x, leftwall_1_pos.y, display.color565(0, 255, 0 ) );
    display.drawPixel(leftwall_2_pos.x, leftwall_2_pos.y, display.color565(255, 0, 0 ) );
  }
}

//Rechte Wand zeichnen
void draw_rightwall() {
  for (int i = 0; i < wall_size; i++) {
    display.drawPixel(rightwall_1_pos.x, rightwall_1_pos.y, display.color565(0, 255, 0 ) );
    display.drawPixel(rightwall_2_pos.x, rightwall_2_pos.y, display.color565(255, 0, 0 ) );
  }
}

//Mittellinie zeichnen
void draw_centreline() {

  for (int m = 1; m < 32; m = m + 4) {
    display.drawPixel(32, m, display.color565(55, 55, 55));

  }
}

void move_leftwall() {
  //LINKS HOCH
  if (button_state_lup == LOW && leftwall_1_pos.y >= 0 ) {
    update_leftwall_trail(true);
    leftwall_1_pos.y = leftwall_1_pos.y - 1;
    leftwall_2_pos.y = leftwall_2_pos.y - 1;
  }
  //LINKS RUNTER
  else if (button_state_ldown == LOW && leftwall_2_pos.y <= 31 ) {
    update_leftwall_trail(false);
    leftwall_1_pos.y = leftwall_1_pos.y + 1;
    leftwall_2_pos.y = leftwall_2_pos.y + 1;
  }
}

void move_rightwall() {
  //BOT
  if (singleplayer) {
    //RECHTS HOCH
    if (ball_pos.y <= rightwall_1_pos.y && ball_pos.x >= 42) {
      update_rightwall_trail(true);
      rightwall_1_pos.y = rightwall_1_pos.y - 1;
      rightwall_2_pos.y = rightwall_2_pos.y - 1;
    }
    //RECHTS RUNTER
    else if (ball_pos.y >= rightwall_2_pos.y && ball_pos.x >= 42) {
      update_rightwall_trail(false);
      rightwall_1_pos.y = rightwall_1_pos.y + 1;
      rightwall_2_pos.y = rightwall_2_pos.y + 1;
    }
  }
  //SPIELER ZWEI
  else {
    //RECHTS RUNTER
    if (button_state_rup == LOW && rightwall_1_pos.y >= 0 ) {
      update_rightwall_trail(true);
      rightwall_1_pos.y = rightwall_1_pos.y - 1;
      rightwall_2_pos.y = rightwall_2_pos.y - 1;
    }
    //RECHTS RUNTER
    else if (button_state_rdown == LOW && rightwall_2_pos.y <= 31 ) {
      update_rightwall_trail(false);
      rightwall_1_pos.y = rightwall_1_pos.y + 1;
      rightwall_2_pos.y = rightwall_2_pos.y + 1;
    }

  }
}



void draw_score() {
  //AUFGEBEN
  if (button_state_rright == LOW && button_state_rleft == LOW && button_state_rdown == LOW && button_state_rup == LOW) {
    player_left_score = 8;
  }
  else if (button_state_lright == LOW && button_state_lleft == LOW && button_state_ldown == LOW && button_state_lup == LOW) {
    player_right_score = 8;
  }



  if (updated_score == false) {
    updated_score = true;
    write_empty(28, 7);
    write_empty(34, 7);
  }

  if (player_left_score == 0 && player_right_score != 8) {
    write_0(28, 7, menu_color);
  }
  else if (player_left_score == 1) {
    write_1(28, 7, menu_color);
  }
  else if (player_left_score == 2) {
    write_2(28, 7, menu_color);
  }
  else if (player_left_score == 3) {
    write_3(28, 7, menu_color);
  }
  else if (player_left_score == 4) {
    write_4(28, 7, menu_color);
  }
  else if (player_left_score == 5) {
    write_5(28, 7, menu_color);
  }
  else if (player_left_score == 6) {
    write_6(28, 7, menu_color);
  }
  else if (player_left_score == 7) {
    write_7(28, 7, menu_color);
  }
  else if (player_left_score == 8) {
    write_8(28, 7, menu_color);
    delay(1400);
    pong_win  = true;
  }


  if (player_right_score == 0 && player_left_score != 8) {
    write_0(34, 7, menu_color);
  }
  else if (player_right_score == 1) {
    write_1(34, 7, menu_color);
  }
  else if (player_right_score == 2) {
    write_2(34, 7, menu_color);
  }
  else if (player_right_score == 3) {
    write_3(34, 7, menu_color);
  }
  else if (player_right_score == 4) {
    write_4(34, 7, menu_color);
  }
  else if (player_right_score == 5) {
    write_5(34, 7, menu_color);
  }
  else if (player_right_score == 6) {
    write_6(34, 7, menu_color);
  }
  else if (player_right_score == 7) {
    write_7(34, 7, menu_color);
  }
  else if (player_right_score == 8) {
    write_8(34, 7, menu_color);
    delay(1400);
    pong_win  = true;
  }

  if (pong_win == true) {
    player_left_score = 0;
    player_right_score = 0;
    updated_score = false;
    vector leftwall_1_pos = {3, 16};
    vector leftwall_2_pos = {3, 20};
    vector rightwall_1_pos = {60, 16};
    vector rightwall_2_pos = {60, 20};
    display.clearDisplay();
    pong_win  = false;
    gameNumber = 0;

  }

}
