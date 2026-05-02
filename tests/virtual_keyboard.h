    if ((held_1 & 0x1000) != 0) {
      /* Pressed Up: move cursor */
      cursor_delta_y_1 = -2;
    }
    if ((held_1 & 0x2000) != 0) {
      /* Pressed Down: move cursor */
      cursor_delta_y_1 = 2;
    }
    if ((held_1 & 0x4000) != 0) {
      /* Pressed Left: move cursor */
      cursor_delta_x_1 = -2;
    }
    if ((held_1 & 0x8000) != 0) {
      /* Pressed Right: move cursor */
      cursor_delta_x_1 = 2;
    }
    if (((held_1 & 8) != 0) && (*(short *)(game_state_1_[2] + 8) < 0x2c)) {
      /* Pressed L: scroll left */
      *(short *)(game_state_1_[2] + 8) = *(short *)(game_state_1_[2] + 8) + 2;
    }
    if (((held_1 & 0x80) != 0) && (-0x1aa < *(short *)(game_state_1_[2] + 8))) {
      /* Pressed R: scroll right */
      *(short *)(game_state_1_[2] + 8) = *(short *)(game_state_1_[2] + 8) + -2;
    }
    if ((pressed_1 & 0x400) != 0) {
      /* Pressed A: play the voice clip */
      pressed_a_060133a8();
    }
