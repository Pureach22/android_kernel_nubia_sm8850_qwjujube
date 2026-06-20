void __fastcall hdd_pcl_info_dump(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w24
  __int64 v13; // x21
  _DWORD *v14; // x22
  int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD v24[25]; // [xsp+8h] [xbp-C8h] BYREF

  v24[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 192);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: PCL freqs: %d (freq MHz[weight]:flag):",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_pcl_info_dump",
    a2);
  if ( a2 )
  {
    v12 = 0;
    v13 = a2;
    v14 = (_DWORD *)(a1 + 8);
    do
    {
      v16 = scnprintf((char *)v24 + v12, 192LL - v12, "%d[%d]:0x%x ", *(v14 - 2), *(v14 - 1), *v14);
      if ( v15 < 1 )
        break;
      v12 += v15;
      if ( v12 >= 0xAC )
      {
        qdf_trace_msg(0x33u, 8u, "%s", v16, v17, v18, v19, v20, v21, v22, v23, v24);
        v12 = 0;
      }
      --v13;
      v14 += 3;
    }
    while ( v13 );
    if ( v12 )
      qdf_trace_msg(0x33u, 8u, "%s", v16, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  _ReadStatusReg(SP_EL0);
}
