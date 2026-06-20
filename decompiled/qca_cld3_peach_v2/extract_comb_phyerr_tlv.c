__int64 __fastcall extract_comb_phyerr_tlv(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        _WORD *a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int *v13; // x19
  const char *v14; // x2
  __int64 (*v19)(void); // x9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x9
  unsigned int v29; // w4

  if ( !a2 )
  {
    v14 = "%s: Received null data from FW";
LABEL_7:
    qdf_trace_msg(0x31u, 8u, v14, a6, a7, a8, a9, a10, a11, a12, a13, "extract_comb_phyerr_tlv");
    return 16;
  }
  v13 = *(unsigned int **)a2;
  if ( !*(_QWORD *)a2 )
  {
    v14 = "%s: Received Data PE Header is NULL";
    goto LABEL_7;
  }
  if ( a3 > 0x23u )
  {
    v19 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3688LL);
    if ( *((_DWORD *)v19 - 1) != -2112860426 )
      __break(0x8229u);
    *(_DWORD *)(a5 + 68) = v19();
    v28 = v13[2];
    *(_QWORD *)(a5 + 32) = v28;
    *(_QWORD *)(a5 + 32) = v28 | ((unsigned __int64)v13[3] << 32);
    *(_QWORD *)(a5 + 48) = *(_QWORD *)(a2 + 16);
    v29 = v13[4];
    if ( v29 <= *(_DWORD *)(a2 + 24) )
    {
      *(_DWORD *)(a5 + 56) = v29;
      *(_DWORD *)(a5 + 60) = v13[6];
      *(_DWORD *)(a5 + 64) = v13[7];
      *a4 = 40;
      return 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Invalid buf_len %d, num_bufp %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "extract_comb_phyerr_tlv");
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Expected minimum size %zu, received %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "extract_comb_phyerr_tlv",
      36);
  }
  return 16;
}
