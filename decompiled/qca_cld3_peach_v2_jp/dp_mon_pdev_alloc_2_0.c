__int64 __fastcall dp_mon_pdev_alloc_2_0(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( *(_QWORD *)(a1 + 95560) )
    return 0;
  qdf_trace_msg(0x92u, 2u, "%s: DP MON PDEV is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_pdev_alloc_2_0", v9, v10);
  return 16;
}
