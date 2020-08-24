/* Copyright 2019 Biacco42
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes{
  M_GIT_CO = SAFE_RANGE,
  M_COPY_ID,
  M_ANSIBLE,
  M_GIT_BRANCHING,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed){
    switch(keycode){
      case M_GIT_CO:
        SEND_STRING("git checkout master; git pull; git fetch\n");
        return false; break;
      case M_COPY_ID:
        SEND_STRING("ssh-copy-id -i ~/.ssh/qa_hotwire.key ");
        return false; break;
      case M_ANSIBLE:
        SEND_STRING("ansible-playbook ");
        return false; break;
      case M_GIT_BRANCHING:
        SEND_STRING("git checkout -b ${NEW_BRANCH}");
        return false; break;
    }
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    LCTL(M_GIT_CO),  LCTL(M_COPY_ID),  LCTL(M_ANSIBLE), LCTL(M_GIT_BRANCHING) \
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

