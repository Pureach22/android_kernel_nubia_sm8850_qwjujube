__int64 __fastcall hdd_sta_info_init(
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

  if ( a1 )
  {
    *(_DWORD *)(a1 + 24) = 0;
    *(_QWORD *)(a1 + 32) = 0;
    *(_QWORD *)a1 = a1;
    *(_QWORD *)(a1 + 8) = a1;
    *(_QWORD *)(a1 + 16) = 0x2000000000LL;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Parameter null", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sta_info_init", v9, v10);
    return 4;
  }
}
