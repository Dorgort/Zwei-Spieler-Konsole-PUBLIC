#include <PxMatrix.h>


#ifdef ESP32

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 2
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
#endif

//Knoepfe
const int button_pin_lup = 16;
int button_state_lup = 0;
const int button_pin_ldown = 17;
int button_state_ldown = 0;
const int button_pin_lright = 21;
int button_state_lright = 0;
const int button_pin_lleft = 27;
int button_state_lleft = 0;
const int button_pin_rup = 32;
int button_state_rup = 0;
const int button_pin_rdown = 26;
int button_state_rdown = 0;
const int button_pin_rright = 25;
int button_state_rright = 0;
const int button_pin_rleft = 33;
int button_state_rleft = 0;

//Wurde ein Knopf gedrueckt?
boolean button_press_lup = false;
boolean button_press_ldown = false;
boolean button_press_lright = false;
boolean button_press_lleft = false;
boolean button_press_rup = false;
boolean button_press_rdown = false;
boolean button_press_rright = false;
boolean button_press_rleft = false;

//spielt eine Person oder zwei?
boolean singleplayer = true;

//Welches Spiel wird gespielt
int gameNumber = 0;
//Welches Spiel ist im Hauptmenue ausgewaehlt
int selectedNumber = 1;


//Vektor mit x und y
typedef struct {
  int x;
  int y;
} vector;


//PxMATRIX display(32,16,P_LAT, P_OE,P_A,P_B,P_C);
PxMATRIX display(64, 32, P_LAT, P_OE, P_A, P_B, P_C, P_D);
//PxMATRIX display(64, 32, P_LAT, P_OE, P_A, P_B, P_C, P_D, P_E);


#ifdef ESP32
void IRAM_ATTR display_updater() {
  // Increment the counter and set the time of ISR
  portENTER_CRITICAL_ISR(&timerMux);
  display.display(70);

  portEXIT_CRITICAL_ISR(&timerMux);
}
#endif


uint16_t score_color = display.color565(25, 50, 50);
uint16_t remove_color = display.color565(0, 0, 0);
uint16_t menu_color = display.color565(25, 25, 0);
uint16_t selected_color = display.color565(25, 51, 51);
uint16_t green = display.color565(0, 150, 0);
uint16_t purple = display.color565(100, 0, 100);



void setup() {
  pinMode(button_pin_lup, INPUT_PULLUP);
  pinMode(button_pin_ldown, INPUT_PULLUP);
  pinMode(button_pin_lright, INPUT_PULLUP);
  pinMode(button_pin_lleft, INPUT_PULLUP);
  pinMode(button_pin_rup, INPUT_PULLUP);
  pinMode(button_pin_rdown, INPUT_PULLUP);
  pinMode(button_pin_rright, INPUT_PULLUP);
  pinMode(button_pin_rleft, INPUT_PULLUP);

  Serial.begin(9600);
  display.begin(16);
  display.flushDisplay();
  display.setScanPattern(LINE);
  display.setMuxPattern(BINARY);
  display.setTextWrap(false);


#ifdef ESP32
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &display_updater, true);
  timerAlarmWrite(timer, 2000, true);
  timerAlarmEnable(timer);
#endif

  spawn_invaders();


  delay(500);
}

void loop() {
  button_state_lup = digitalRead(button_pin_lup);
  button_state_ldown = digitalRead(button_pin_ldown);
  button_state_lright = digitalRead(button_pin_lright);
  button_state_lleft = digitalRead(button_pin_lleft);
  button_state_rup = digitalRead(button_pin_rup);
  button_state_rdown = digitalRead(button_pin_rdown);
  button_state_rright = digitalRead(button_pin_rright);
  button_state_rleft = digitalRead(button_pin_rleft);

  if (gameNumber == 0) {
    check_selected();
    write_p(5, 5, menu_color);
    write_o(9, 5, menu_color);
    write_n(13, 5, menu_color);
    write_g(17, 5, menu_color);

    write_s(5, 13, menu_color);
    write_n(9, 13, menu_color);
    write_a(13, 13, menu_color);
    write_k(17, 13, menu_color);
    write_e(21, 13, menu_color);

    write_p(5, 21, menu_color);
    write_a(9, 21, menu_color);
    write_c(13, 21, menu_color);
    write_m(17, 21, menu_color);
    write_a(21, 21, menu_color);
    write_n(25, 21, menu_color);

    write_i(5, 29, menu_color);
    write_n(9, 29, menu_color);
    write_v(13, 29, menu_color);
    write_a(17, 29, menu_color);
    write_d(21, 29, menu_color);
    write_e(25, 29, menu_color);
    write_r(29, 29, menu_color);

    if (singleplayer == true) {
      write_1(32, 5, display.color565(50, 0, 0));
      write_p(36, 5, menu_color);
      write_l(40, 5, menu_color);
      write_a(44, 5, menu_color);
      write_y(48, 5, menu_color);
      write_e(52, 5, menu_color);
      write_r(56, 5, menu_color);
    }
    else {
      write_2(32, 5, display.color565(50, 0, 0));
      write_p(36, 5, menu_color);
      write_l(40, 5, menu_color);
      write_a(44, 5, menu_color);
      write_y(48, 5, menu_color);
      write_e(52, 5, menu_color);
      write_r(56, 5, menu_color);
    }



    if (button_state_ldown == LOW || button_state_rdown == LOW) {
      selectedNumber++;
    }
    else if (button_state_lup == LOW || button_state_rup == LOW) {
      selectedNumber--;
    }
    if (button_state_lright == LOW || button_state_lleft == LOW || button_state_rright == LOW || button_state_rleft == LOW) {
      display.clearDisplay();
      gameNumber = selectedNumber;
    }
  }


  // PONG
  else if (gameNumber == 1) {
    pong();
    move_leftwall();
    draw_leftwall();
    move_rightwall();
    draw_rightwall();
    draw_centreline();
    draw_ball();
    draw_score();
  }
  //SNAKE
  else if (gameNumber == 2) {
    create_objects();
    draw_snake();
    check_snake();
    snake_button();
    calc_snake_score();
    if (singleplayer == false) {
      draw_viper();
      check_viper();
      viper_button();
    }
    check_snake_lose();
    delay(3);
  }
  //PACMAN
  else if (gameNumber == 3) {
    draw_pacmanmap();
    move_pacman();
    move_ghosts();
    calc_pacman_score();
    pacman_gameover();
  }

  //INVADER
  else if (gameNumber == 4) {
    display.clearDisplay();
    spaceship1();
    spaceship2();
    draw_remaining_health();
    enemy_spaceship();
    calc_enemies();
    shoot_rocket();
    invader_lose();
  }

  else if (gameNumber == 5) {
    display.clearDisplay();
    gameNumber = 0;
    if (singleplayer == true) {
      singleplayer = false;
    }
    else  if (singleplayer == false) {
      singleplayer = true;
    }
  }

  display.showBuffer();
  delay(42);
}


void check_selected() {
  if (selectedNumber > 5) {
    selectedNumber = 1;
  }
  else if (selectedNumber < 1) {
    selectedNumber = 4;
  }
  if (selectedNumber == 1) {
    write_p(5, 5, selected_color);
    write_o(9, 5, selected_color);
    write_n(13, 5, selected_color);
    write_g(17, 5, selected_color);
    delay(20);
  }
  else if (selectedNumber == 2) {
    write_s(5, 13, selected_color);
    write_n(9, 13, selected_color);
    write_a(13, 13, selected_color);
    write_k(17, 13, selected_color);
    write_e(21, 13, selected_color);

    delay(20);

  }
  else if (selectedNumber == 3) {
    write_p(5, 21, selected_color);
    write_a(9, 21, selected_color);
    write_c(13, 21, selected_color);
    write_m(17, 21, selected_color);
    write_a(21, 21, selected_color);
    write_n(25, 21, selected_color);
    delay(20);
  }
  else if (selectedNumber == 4) {
    write_i(5, 29, selected_color);
    write_n(9, 29, selected_color);
    write_v(13, 29, selected_color);
    write_a(17, 29, selected_color);
    write_d(21, 29, selected_color);
    write_e(25, 29, selected_color);
    write_r(29, 29, selected_color);
    delay(20);
  }

  else if (selectedNumber == 5) {
    if (singleplayer == true) {
      write_1(32, 5, selected_color);
      write_p(36, 5, selected_color);
      write_l(40, 5, selected_color);
      write_a(44, 5, selected_color);
      write_y(48, 5, selected_color);
      write_e(52, 5, selected_color);
      write_r(56, 5, selected_color);
    }
    else {
      write_2(32, 5, selected_color);
      write_p(36, 5, selected_color);
      write_l(40, 5, selected_color);
      write_a(44, 5, selected_color);
      write_y(48, 5, selected_color);
      write_e(52, 5, selected_color);
      write_r(56, 5, selected_color);
    }
  }
}











void write_a(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
    display.drawPixel(x + 2, y - i, color);
  }
  display.drawPixel(x + 1, y - 2, color);
  display.drawPixel(x + 1, y - 4, color);
}

void write_b(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x , y - i, color);
  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x + 1 + i, y, color);
    display.drawPixel(x + 1 + i, y - 4, color);
  }
  display.drawPixel(x + 1, y - 2, color);
  display.drawPixel(x + 2, y - 4, color);
  display.drawPixel(x + 2, y, color);
}

void write_c(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x , y - i, color);
  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x + 1 + i, y, color);
    display.drawPixel(x + 1 + i, y - 4, color);
  }
}

void write_d(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + 2, y - 1 - i, color);
  }
  display.drawPixel(x + 1, y - 4, color);
  display.drawPixel(x + 1, y, color);
}

void write_e(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x , y - i, color);
  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x + 1 + i, y, color);
    display.drawPixel(x + 1 + i, y - 2, color);
    display.drawPixel(x + 1 + i, y - 4, color);
  }
}

void write_f(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x , y - i, color);
  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x + 1 + i, y - 2, color);
    display.drawPixel(x + 1 + i, y - 4, color);
  }
}

void write_g(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + 2, y - i, color);
  }
  display.drawPixel(x + 1, y , color);
  display.drawPixel(x + 1, y - 4 , color);
  display.drawPixel(x + 2, y - 4 , color);

}

void write_i(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 1, y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + i, y - 4, color);
    display.drawPixel(x + i, y, color);
  }
}

void write_k(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);

  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x + 2, y - i, color);
    display.drawPixel(x + 2, y - 3 - i, color);
  }
  display.drawPixel(x + 1, y - 2, color);
}

void write_l(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x , y - i, color);
  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x + 1 + i, y, color);
  }
}

void write_m(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
    display.drawPixel(x + 2, y - i, color);
  }
  display.drawPixel(x + 1, y - 3, color);
}

void write_n(int x, int y, uint16_t color) {
  for (int i = 0; i < 4; i++) {
    display.drawPixel(x, y - i, color);
  }
  for (int i = 0; i < 4; i++) {
    display.drawPixel(x + 2, y - 1 - i, color);
  }
  display.drawPixel(x + 1, y - 2 , color);

}

void write_o(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
    display.drawPixel(x + 2, y - i, color);
  }
  display.drawPixel(x + 1, y , color);
  display.drawPixel(x + 1, y - 4, color);
}

void write_p(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + 2, y - 2 - i, color);
  }
  display.drawPixel(x + 1, y - 4, color);
  display.drawPixel(x + 1, y - 2, color);
}

void write_r(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
  }
  display.drawPixel(x + 2, y - 3, color);
  display.drawPixel(x + 1, y - 4, color);
  display.drawPixel(x + 1, y - 2, color);
  display.drawPixel(x + 2, y - 1, color);
  display.drawPixel(x + 2, y, color);
}

void write_s(int x, int y, uint16_t color) {
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + i, y , color);
    display.drawPixel(x + i, y - 2 , color);
    display.drawPixel(x + i, y - 4 , color);
  }
  display.drawPixel(x + 2, y - 1, color);
  display.drawPixel(x, y - 3, color);
}


void write_t(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 1, y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + i, y - 4, color);
  }
}

void write_u(int x, int y, uint16_t color) {
  display.drawPixel(x + 1 , y, color);
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
    display.drawPixel(x + 2 , y - i, color);
  }
}

void write_v(int x, int y, uint16_t color) {
  for (int i = 0; i < 4; i++) {
    display.drawPixel(x, y - 1 - i, color);
    display.drawPixel(x + 2, y - 1 - i, color);
  }

  display.drawPixel(x + 1, y, color);
}

void write_y(int x, int y, uint16_t color) {
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + 1 , y - i, color);
  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x, y - 3 - i, color);
    display.drawPixel(x + 2 , y - 3 - i, color);
  }
}


void write_0(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
    display.drawPixel(x + 2, y - i, color);
  }
  display.drawPixel(x + 1, y , color);
  display.drawPixel(x + 1, y - 4, color);
}

void write_1(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 2, y - i, color);
  }
}

void write_2(int x, int y, uint16_t color) {
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + i, y , color);
    display.drawPixel(x + i, y - 2 , color);
    display.drawPixel(x + i, y - 4 , color);
  }
  display.drawPixel(x , y - 1, color);
  display.drawPixel(x + 2, y - 3, color);
}

void write_3(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 2 , y - i, color);
  }
  for (int i = 0; i < 2; i++) {
    display.drawPixel(x  + i, y, color);
    display.drawPixel(x  + i, y - 2, color);
    display.drawPixel(x  + i, y - 4, color);
  }
}

void write_4(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 2 , y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x , y - 2 - i , color);
  }
  display.drawPixel(x  + 1, y - 2, color);
}

void write_5(int x, int y, uint16_t color) {
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + i, y , color);
    display.drawPixel(x + i, y - 2 , color);
    display.drawPixel(x + i, y - 4 , color);
  }
  display.drawPixel(x + 2, y - 1, color);
  display.drawPixel(x, y - 3, color);
}

void write_6(int x, int y, uint16_t color) {
  for (int i = 0; i < 4; i++) {
    display.drawPixel(x, y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x + 2, y - i, color);
    display.drawPixel(x + i, y - 4, color);
  }
  display.drawPixel(x + 1, y, color);
  display.drawPixel(x + 1, y - 2, color);
}


void write_7(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 2, y - i, color);
  }
  display.drawPixel(x , y - 4, color);
  display.drawPixel(x + 1 , y - 4, color);
}

void write_8(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x, y - i, color);
    display.drawPixel(x + 2, y - i, color);
  }
  display.drawPixel(x + 1, y , color);
  display.drawPixel(x + 1, y - 4, color);
  display.drawPixel(x + 1, y - 2, color);
}

void write_9(int x, int y, uint16_t color) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 2, y - i, color);
  }
  for (int i = 0; i < 3; i++) {
    display.drawPixel(x , y - 2 - i, color);
    display.drawPixel(x + 1, y - 2 * i , color);
  }
  display.drawPixel(x, y , color);
}

void write_empty(int x, int y) {
  for (int i = 0; i < 5; i++) {
    display.drawPixel(x + 2, y - i, remove_color);
    display.drawPixel(x + 1, y - i, remove_color);
    display.drawPixel(x, y - i, remove_color);
  }

}
