__int64 __fastcall hdd_configure_sar_resume_index(
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

  v9 = *(_QWORD *)(result + 104);
  if ( (*(_BYTE *)(v9 + 172) & 1) != 0 )
  {
    v10 = result;
    qdf_trace_msg(
      0x33u,
      8u,
      "Configure SAR safety index %d on wlan resume",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      *(unsigned int *)(v9 + 164));
    return hdd_configure_sar_index(
             v10,
             *(_DWORD *)(*(_QWORD *)(v10 + 104) + 164LL),
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18);
  }
  return result;
}
