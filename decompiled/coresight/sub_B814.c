__int64 __fastcall sub_B814(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8)
{
  _BYTE v8[12]; // q18

  WORD2(a8) = *(_WORD *)&v8[10];
  return coresight_init_driver(a1, a2, a3, a4, a5, a6, a7, a8);
}
