__int64 __fastcall sub_413D84(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        long double _Q5)
{
  __asm { UDOT            V3.4S, V5.16B, V10.16B }
  return lim_update_obss_scanparams(a1, a2);
}
