#ifndef _LIBEXP_H_
#define _LIBEXP_H_

/*
 * Regular experience groups.
 * See lib/regular.c
 */

extern int CalcEXP_Fast(double n);
extern int CalcEXP_MediumFast(double n);
extern int CalcEXP_MediumSlow(double n);
extern int CalcEXP_Slow(double n);
extern int CalcEXP_Erratic(double n);
extern int CalcEXP_Fluctuating(double n);
extern int CalcEXP_SlightlyFast(double n);
extern int CalcEXP_SlightlySlow(double n);

/*
 * Gen 1 glitch experience groups.
 * See lib/glitch.c
 */

extern int CalcEXP_Glitch_D1(double n);
extern int CalcEXP_Glitch_7B(double n);
extern int CalcEXP_Glitch_81(double n);
extern int CalcEXP_Glitch_0D(double n);
extern int CalcEXP_Glitch_1A(double n);
extern int CalcEXP_Glitch_06(double n);
extern int CalcEXP_Glitch_1D(double n);
extern int CalcEXP_Glitch_37(double n);
extern int CalcEXP_Glitch_4B(double n);
extern int CalcEXP_Glitch_57(double n);
extern int CalcEXP_Glitch_64(double n);
extern int CalcEXP_Glitch_88(double n);
extern int CalcEXP_Glitch_A5(double n);
extern int CalcEXP_Glitch_23(double n);
extern int CalcEXP_Glitch_10(double n);

#endif /* _LIBEXP_H_ */
