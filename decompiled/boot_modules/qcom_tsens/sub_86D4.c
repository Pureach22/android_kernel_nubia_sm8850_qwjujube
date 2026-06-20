__int64 __fastcall sub_86D4(long double _Q0, double a2, double a3, double a4, double a5, long double _Q5)
{
  __asm { XAR             V30.2D, V5.2D, V0.2D, #0x12 }
  return tsens_get_temp();
}
