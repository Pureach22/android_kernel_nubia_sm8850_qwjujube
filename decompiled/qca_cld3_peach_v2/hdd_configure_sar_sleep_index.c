__int64 __fastcall hdd_configure_sar_sleep_index(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v9 = *(_QWORD *)(result + 104);
  if ( (*(_BYTE *)(v9 + 172) & 1) != 0 )
  {
    v10 = result;
    if ( *(_BYTE *)(v9 + 173) == 1 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "Configure SAR sleep index %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        *(unsigned int *)(v9 + 168));
      return hdd_configure_sar_index(
               v10,
               *(_DWORD *)(*(_QWORD *)(v10 + 104) + 168LL),
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18);
    }
    else
    {
      qdf_trace_msg(0x33u, 8u, "Disable SAR", a2, a3, a4, a5, a6, a7, a8, a9);
      return hdd_disable_sar(v10, v19, v20, v21, v22, v23, v24, v25, v26);
    }
  }
  return result;
}
