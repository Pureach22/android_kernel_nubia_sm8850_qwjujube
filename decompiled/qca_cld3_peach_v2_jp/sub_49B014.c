__int64 __fastcall sub_49B014(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        unsigned int a9)
{
  __int64 v9; // x2

  v9 = __ldaxr(&a9);
  return osif_dp_get_nud_stats(a1, a2, v9);
}
