__int64 __fastcall sub_2662B4(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        float a8)
{
  short float v8; // h23
  short float v9; // h24

  *(short float *)&a8 = v8 - (short float)(v8 * v9);
  return policy_mgr_handle_conc_multiport(a1, a2, a3, a4, a5, a6, a7, a8);
}
