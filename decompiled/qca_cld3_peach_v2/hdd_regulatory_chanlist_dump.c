__int64 __fastcall hdd_regulatory_chanlist_dump(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x24
  unsigned int v19; // w20
  unsigned int v20; // w26
  int v21; // w0
  __int64 result; // x0
  _QWORD v23[25]; // [xsp+8h] [xbp-C8h] BYREF

  v23[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v23, 0, 192);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: start (freq MHz, tx power dBm):",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_regulatory_chanlist_dump");
  v18 = 0;
  v19 = 0;
  v20 = 0;
  while ( (*(_BYTE *)(a1 + v18 + 12) & 1) != 0 )
  {
LABEL_2:
    v18 += 36;
    if ( v18 == 3672 )
      goto LABEL_7;
  }
  ++v19;
  v10 = scnprintf((char *)v23 + v20, 192LL - v20, "%d %d ", *(_DWORD *)(a1 + v18), *(_DWORD *)(a1 + v18 + 16));
  if ( v21 >= 1 )
  {
    v20 += v21;
    if ( v20 >= 0xAC )
    {
      qdf_trace_msg(0x33u, 8u, "%s: %s", v10, v11, v12, v13, v14, v15, v16, v17, "hdd_regulatory_chanlist_dump", v23);
      v20 = 0;
    }
    goto LABEL_2;
  }
LABEL_7:
  if ( (int)v20 >= 1 )
    qdf_trace_msg(0x33u, 8u, "%s: %s", v10, v11, v12, v13, v14, v15, v16, v17, "hdd_regulatory_chanlist_dump", v23);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: end total_count %d",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "hdd_regulatory_chanlist_dump",
             v19);
  _ReadStatusReg(SP_EL0);
  return result;
}
