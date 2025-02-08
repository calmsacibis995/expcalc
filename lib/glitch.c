/*
 * expcalc - Pokémon experience calculator.
 * Copyright (c) 2024, 2025 Stephanos Stephanidis. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

/*
 * Glitch experience groups - Present in R/B/Y
 *
 * Notice: Groups 0x95 (Glitch Pokémon 0xCA - Yellow only) and 0xFF
 * (Glitch Pokémon 0xED - Yellow only) are not calculated, as they divide by zero.
 *
 * They are included for research purposes.
 */

#include <math.h>

/*
 * Hex D1
 *
 * Glitch Pokémon that are in this group:
 * h ゥ (0xED, R/B)
 * ゥ₽'M (0xEF, R/B)
 */
int
CalcEXP_Glitch_D1(double n)
{
	return(((4 * pow(n, (double)3)) / 7) + (14 * pow(n, (double)2)) + n - 205);
}

/*
 * Hex 7B
 *
 * Glitch Pokémon that are in this group:
 * 8 (0xDE, Y)
 */
int
CalcEXP_Glitch_7B(double n)
{
	return(((3 * pow(n, (double)3)) / 2) - (55 * pow(n, (double)2)) + (79 * n) - 208);
}

/*
 * Hex 81
 *
 * Glitch Pokémon that are in this group:
 * 94 (0xF1, R/B)
 * 94 h (0xF9, R/B)
 * X ゥ- xゥ, (0xC4, Y)
 * ゥ ゥ. (0xE7, Y)
 */
int
CalcEXP_Glitch_81(double n)
{
	return(((3 * pow(n, (double)3)) / 4) + (10 * pow(n, (double)2) - 30));
}

/*
 * Hex 0D
 *
 * Glitch Pokémon that are in this group:
 * ゥ (0xF5, R/B)
 */
int
CalcEXP_Glitch_0D(double n)
{
	return(((4 * pow(n, (double)3)) / 7) - (112 * pow(n, (double)2)) + (219 * n) - 184);
}

/*
 * Hex 1A
 *
 * Glitch Pokémon that are in this group:
 * 'M (0x00, R/B)
 * MissingNo./けつばん (all variants, R/B)
 */
int
CalcEXP_Glitch_1A(double n)
{
	return((33 * pow(n, (double)2)) + (155 * n) - 80);
}

/*
 * Hex 06
 *
 * Glitch Pokémon that are in this group:
 * g g (0xC8, Y)
 * ₽ (0xF9, Y)
 * MissingNo./けつばん (all variants, Y)
 */
int
CalcEXP_Glitch_06(double n)
{
	return((pow(n, (double)3) / 10) - (75 * pow(n, (double)2)) + (95 * n) - 32);
}

/*
 * Hex 1D
 *
 * Glitch Pokémon that are in this group:
 * ゥ .4 (0xC2, R/B)
 * ゥU? (0xC8, R/B)
 * M p'u ゥ (0xD3, R/B)
 * PkMnRPkMn (0xD9, R/B)
 * A (0xEA, R/B)
 */
int
CalcEXP_Glitch_1D(double n)
{
	return((pow(n, (double)3) / 7) + (67 * pow(n, (double)2)) + (65 * n) - 32);
}

/*
 * Hex 37
 *
 * Glitch Pokémon that are in this group:
 * ▶ A (0xBF, R/B)
 * PkMn (0xC5, R/B)
 * PkMn PkMn T (0xD0, R/B)
 * 4 h (0xD6, R/B)
 * .PkMn (0xDF, R/B)
 * ゥ₽ (0xF4, R/B)
 */
int
CalcEXP_Glitch_37(double n)
{
	return(((5 * pow(n, (double)3)) / 12) + (81 * pow(n, (double)2)) + (4 * n) - 48);
}

/*
 * Hex 4B
 *
 * Glitch Pokémon that are in this group:
 * Pゥ 4₽ (0xE7, R/B)
 * ゥ₽ (0xF0, R/B)
 * ゥ (0xF2, R/B)
 */
int
CalcEXP_Glitch_4B(double n)
{
	return(((12 * pow(n, (double)3)) / 13) + (127 * pow(n, (double)2)) + (43 * n) - 250);
}

/*
 * Hex 57
 */
int
CalcEXP_Glitch_57(double n)
{
	return(((2 * pow(n, (double)3)) / 3) + (24 * pow(n, (double)2)) + (18 * n) - 33);
}

/*
 * Hex 64
 * Glitch Pokémon that are in this group:
 *
 * Glitch (0xE3, R/B)
 * - - (0xE6, R/B)
 */
int
CalcEXP_Glitch_64(double n)
{
	return((2 * pow(n, (double)3)) + (32 * pow(n, (double)2)) + (80 * n) - 205);
}

/*
 * Hex 88
 */
int
CalcEXP_Glitch_88(double n)
{
	return(((3 * pow(n, (double)3)) / 5) - (122 * pow(n, (double)2)) + (38 * n) - 204);
}

/*
 * Hex A5
 *
 * Glitch Pokémon that are in this group:
 * …… (0xE2, R/B)
 * C (0xE5, R/B)
 * X C (0xE8, R/B)
 */
int
CalcEXP_Glitch_A5(double n)
{
	return((pow(n, (double)3) / 4) + (60 * pow(n, (double)2)) + (33 * n) - 215);
}

/*
 * Hex 23
 */
int
CalcEXP_Glitch_23(double n)
{
	return((80 * pow(n, (double)2)) + (23 * n) - 236);
}

/*
 * Hex 10
 *
 * Glitch Pokémon that are in this group:
 * . 4( h 4 (0xEB, Y)
 * ₽ pゥ. 4( (0xEE, Y)
 * ゥ▶ ゥ▼ ゥ(0xF3, Y)
 * ゥ ₽ A (0xF6, Y)
 */
int
CalcEXP_Glitch_10(double n)
{
	return((pow(n, (double)3)) + (62 * pow(n, (double)2)) + (145 * n) - 34);
}
