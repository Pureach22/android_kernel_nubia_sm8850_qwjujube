__int64 __fastcall sub_37A468(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // d22

  *(double *)(a2 + 504) = a11;
  *(_QWORD *)(a2 + 512) = v11;
  return lim_decide_ap_protection_on_delete(a1, a2 + 504, a3, a4);
}
