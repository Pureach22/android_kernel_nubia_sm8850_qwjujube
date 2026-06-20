__int64 __fastcall sub_15498(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        float a7)
{
  short float v7; // h10
  short float v8; // h27

  *(short float *)&a7 = -(short float)(v8 + (short float)(*(short float *)&a3 * v7));
  return hw_fence_ssr_cleanup_lock(a1, a2, a3, a4, a5, a6, a7);
}
