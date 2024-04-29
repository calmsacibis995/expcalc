/*
 * expcalc - Pokémon experience calculator.
 * Copyright (c) 2024 Stephanos Stephanidis. All rights reserved.
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

#include <stdio.h>
#include <math.h>

/*
 * Fast experience group. Introduced in Generation I.
 *
 * Max EXP: 800,000
 */
int
CalcEXP_Fast(double n)
{
	return(4 * pow(n, (double)3) / 5);
}

/*
 * Medium-fast experience group. Introduced in Generation I.
 *
 * Max EXP: 1,000,000
 */
int
CalcEXP_MediumFast(double n)
{
	return(pow(n, (double)3));
}

/*
 * Medium-slow experience group. Introduced in Generation I.
 * In R/B/Y/G/S/C, the experience underflow glitch applies to this group.
 *
 * Max EXP: 1,059,860
 */
int
CalcEXP_MediumSlow(double n)
{
	return(((6 * pow(n, (double)3)) / 5) - (15 * pow(n, (double)2)) + (100 * n) - 140);
}

/*
 * Slow experience group. Introduced in Generation I.
 *
 * Max EXP: 1,250,000
 */
int
CalcEXP_Slow(double n)
{
	return(5 * pow(n, (double)3) / 4);
}

/*
 * Erratic (Generations V, VI, VII)
 */
int
CalcEXP_Erratic(double n)
{
	if (n < 50)
		return((pow(n, (double)3) * (100 - n)) / 50);
	else if (n >= 50 && n < 68)
		return((pow(n, (double)3) * (150 - n)) / 100);
	else if (n >= 68 && n < 98)
		return((pow(n, (double)3) * ((1911 - (10 * n)) / 3)) / 500);
	else
		return((pow(n, (double)3) * (160 - n)) / 100);
}

/*
 * Fluctuating
 */
int
CalcEXP_Fluctuating(double n)
{
	if (n < 15)
		return((pow(n, (double)3) * (((n + 1) / 3) + 24)) / 50);
	else if (n >= 15 && n < 36)
		return((pow(n, (double)3) * (n + 14)) / 50);
	else
		return((pow(n, (double)3) * ((n / 2) + 32)) / 50);
}

/*
 * Glitch experience groups - Present in R/B/Y
 *
 * Notice: Groups 0x95 (Glitch Pokémon 0xCA - Yellow only) and 0xFF
 * (Glitch Pokémon 0xED - Yellow only) are not calculated, as they divide by zero.
 */

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

int
CalcEXP_Glitch_57(double n)
{
	return(((2 * pow(n, (double)3)) / 3) + (24 * pow(n, (double)2)) + (18 * n) - 33);
}

int
CalcEXP_Glitch_64(double n)
{
	return((2 * pow(n, (double)3)) + (32 * pow(n, (double)2)) + (80 * n) - 205);
}

int
CalcEXP_Glitch_88(double n)
{
	return(((3 * pow(n, (double)3)) / 5) - (122 * pow(n, (double)2)) + (38 * n) - 204);
}

int
main()
{
	double n;

	while (1) {
		printf("Enter a level: ");
		scanf("%lf", &n);
		if (n < 1 || n > 100)
			printf("Invalid level. Please try again.\n");
		else
			break;
	}

	printf("\nRegular experience groups:\n");
	printf("Erratic: %d\n", CalcEXP_Erratic(n));
	printf("Fast: %d\n", CalcEXP_Fast(n));
	printf("Medium-fast: %d\n", CalcEXP_MediumFast(n));
	printf("Medium-slow: %d\n", CalcEXP_MediumSlow(n));
	printf("Slow: %d\n", CalcEXP_Slow(n));
	printf("Fluctuating: %d\n", CalcEXP_Fluctuating(n));

	printf("\nGlitch experience groups (R/B/Y only):\n");
	printf("0xD1: %d\n", CalcEXP_Glitch_D1(n));
	printf("0x7B: %d\n", CalcEXP_Glitch_7B(n));
	printf("0x81: %d\n", CalcEXP_Glitch_81(n));
	printf("0x0D: %d\n", CalcEXP_Glitch_0D(n));
	printf("0x1A: %d\n", CalcEXP_Glitch_1A(n));
	printf("0x06: %d\n", CalcEXP_Glitch_06(n));
	printf("0x1D: %d\n", CalcEXP_Glitch_1D(n));
	printf("0x37: %d\n", CalcEXP_Glitch_37(n));
	printf("0x4B: %d\n", CalcEXP_Glitch_4B(n));
	printf("0x57: %d\n", CalcEXP_Glitch_57(n));
	printf("0x64: %d\n", CalcEXP_Glitch_64(n));
	printf("0x88: %d\n", CalcEXP_Glitch_88(n));
}
