/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:15:31 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/15 09:53:28 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

/* keyboard */
enum {
	KEY_ESC = 65307,
	KEY_F1 = 65470,
	KEY_F2 = 65471,
	KEY_F3 = 65472,
	KEY_F4 = 65473,
	KEY_F5 = 65474,
	KEY_F6 = 65475,
	KEY_F7 = 65476,
	KEY_F8 = 65477,
	KEY_F9 = 65478,
	KEY_F10 = 65479,
	KEY_F11 = 65480,
	KEY_F12 = 65481,
	KEY_0 = 48,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
	KEY_PLUS = 61,
	KEY_MINUS = 45,
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	KEY_SPACE = 32,
	LEFT = 65361,
	UP = 65362,
	RIGHT = 65363,
	DOWN = 65364,
	NUMPAD_0 = 65438,
	NUMPAD_1 = 65436,
	NUMPAD_2 = 65433,
	NUMPAD_3 = 65435,
	NUMPAD_4 = 65430,
	NUMPAD_5 = 65437,
	NUMPAD_6 = 65432,
	NUMPAD_7 = 65429,
	NUMPAD_8 = 65431,
	NUMPAD_9 = 65434,
	NUMPAD_PLUS = 65451,
	NUMPAD_MINUS = 65453
};

/* mouse */
enum {
	MOUSE_LEFT_CLICK = 1,
	MOUSE_WHEEL_CLICK = 2,
	MOUSE_RIGHT_CLICK = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5
};

/* events */
enum {
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	BUTTON_RELEASE = 5,
	MOTION_NOTIFY = 6,
	DESTROY_NOTIFY = 17	
};

/* event masks */
enum {
	KEY_PRESS_MASK = (1L << 0),
	KEY_RELEASE_MASK = (1L << 1),
	BUTTON_PRESS_MASK = (1L << 2),
	BUTTON_RELEASE_MASK = (1L << 3),
	POINTER_MOTION_MASK = (1L << 6),
};

#endif