/* CONVERT IEEE DOUBLE PRECISION (64 bits) TO DOUBLE */
#include <stdio.h>
#include<math.h>

#define NBITS 64
//#define EXP_BITS 11
//#define MANTISSA_BITS 52
//#define bias 1023

double todecimal(const char s[NBITS])
{
  double f;
  int sign, exp = 0;
  unsigned long long  mant = 0;
  int i;

  sign = s[0] - '0';

  for (i=1; i<=11; i++)
    exp = exp * 2 + (s[i] - '0');

  if (exp > -1022)
  {
    mant = 1; 
    exp -= 1023;
  }
  else
  {
    // Subnormal numbers
    mant = 0; 
    exp = -1022;
  }
  for(i=12; i<64; i++){
    mant = mant * 2 + (s[i] - '0');
  }
  printf("s = %d\n", sign);
  printf("exp = %d\n", exp);
  printf("m = %llu\n", mant);

  f = pow(-1, sign) * pow(2, exp) * (mant/pow(2, 52));
  return f;
}

int main(void)
{
  /* Test todecimal function*/

  //0.98245
  printf("%.10f\n", todecimal("0011111111101111011100000011101011111011011111101001000100000000"));

  // 12.58393
  printf("%.10f\n", todecimal("0100000000101001001010101111100011011111011110100100111001111011"));

  // 89.34455556666
  printf("%.10f\n", todecimal("0100000001010110010101100000110100110010110010101001110101101000"));

  return 0;
}
