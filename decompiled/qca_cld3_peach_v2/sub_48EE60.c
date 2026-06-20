__int64 __fastcall sub_48EE60(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _WORD *v10; // x20
  __int64 v11; // d8

  *v10 = HIWORD(a8);
  v10[1] = HIWORD(a9);
  v10[2] = HIWORD(a10);
  v10[3] = HIWORD(v11);
  return sme_ap_disable_intra_bss_fwd(a1, a2);
}
