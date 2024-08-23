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

#include "libexp.h"

int
main(void)
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
	printf("Slightly Fast: %d\n", CalcEXP_SlightlyFast(n));
	printf("Slightly Slow: %d\n", CalcEXP_SlightlySlow(n));

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
	printf("0xA5: %d\n", CalcEXP_Glitch_A5(n));
	printf("0x23: %d\n", CalcEXP_Glitch_23(n));
}
