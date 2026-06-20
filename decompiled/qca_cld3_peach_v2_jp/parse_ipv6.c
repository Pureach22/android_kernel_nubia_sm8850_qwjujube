__int64 __fastcall parse_ipv6(
        _BYTE *a1,
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
  __int64 v12; // x21
  char *v13; // x9
  __int16 v14; // w23
  _BYTE *v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  _WORD v41[2]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-18h] BYREF
  __int64 v43; // [xsp+10h] [xbp-10h]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v12 = 0;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v41[0] = 0;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  do
  {
    v14 = 0;
    if ( *a1 == 58 )
      ++a1;
    if ( *a1 && *a1 != 58 )
    {
      kstrtou16(a1, 16, v41);
      v14 = v41[0];
      v15 = a1 + 1;
      if ( !a1[1]
        || a1[1] == 58
        || (kstrtou16(v15, 16, v41), v15 = a1 + 2, v14 = v41[0] | (16 * v14), !a1[2])
        || a1[2] == 58
        || (kstrtou16(v15, 16, v41), v15 = a1 + 3, v14 = v41[0] | (16 * v14), !a1[3])
        || a1[3] == 58 )
      {
        a1 = v15;
      }
      else
      {
        kstrtou16(v15, 16, v41);
        a1 += 4;
        v14 = v41[0] | (16 * v14);
      }
    }
    v13 = (char *)&v42 + v12;
    *((_BYTE *)&v42 + v12) = HIBYTE(v14);
    v12 += 2;
    v13[1] = v14;
  }
  while ( (_DWORD)v12 != 16 );
  *(_DWORD *)a2 = bswap32(v42);
  qdf_trace_msg(0x61u, 8u, "%s: opt_dp_ctrl, ipv6_array[%d] %d", a3, a4, a5, a6, a7, a8, a9, a10, "parse_ipv6", 0);
  *(_DWORD *)(a2 + 4) = bswap32(HIDWORD(v42));
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl, ipv6_array[%d] %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "parse_ipv6",
    1);
  *(_DWORD *)(a2 + 8) = bswap32(v43);
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl, ipv6_array[%d] %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "parse_ipv6",
    2);
  *(_DWORD *)(a2 + 12) = bswap32(HIDWORD(v43));
  result = qdf_trace_msg(
             0x61u,
             8u,
             "%s: opt_dp_ctrl, ipv6_array[%d] %d",
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             "parse_ipv6",
             3);
  _ReadStatusReg(SP_EL0);
  return result;
}
