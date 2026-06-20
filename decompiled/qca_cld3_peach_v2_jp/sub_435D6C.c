__int64 __fastcall sub_435D6C(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        long double a10)
{
  __int64 v10; // x19
  __int128 v11; // q26

  *(long double *)(v10 + 336) = a10;
  *(_OWORD *)(v10 + 352) = v11;
  return sme_add_set_thermal_level_callback(a1, a2);
}
