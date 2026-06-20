__int64 __fastcall extract_roam_scan_stats_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned __int8 a12,
        unsigned __int8 a13,
        unsigned __int8 a14)
{
  __int64 v14; // x8
  unsigned int v15; // w19
  __int64 v16; // x10
  int v17; // w9
  unsigned int v18; // w8
  int v19; // w12
  int v20; // w12
  unsigned int v21; // w6
  __int64 result; // x0
  __int64 v23; // x9
  int *v24; // x12
  int v25; // t1
  bool v26; // w14
  char v27; // w13
  unsigned __int16 v28; // w9
  int v29; // w8
  __int64 v30; // x10
  __int64 v31; // x11
  char v32; // w12
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( !a10 )
    return 16;
  v14 = *(_QWORD *)(a10 + 32);
  if ( !v14 )
    return 16;
  v15 = a12;
  if ( *(_DWORD *)(a10 + 40) <= (unsigned int)a12 )
    return 16;
  v16 = v14 + 32LL * a12;
  *(_BYTE *)a11 = 1;
  v17 = *(_DWORD *)(v16 + 4);
  *(_WORD *)(a11 + 2) = v17;
  v18 = *(unsigned __int16 *)(v16 + 12);
  *(_WORD *)(a11 + 6) = v18;
  *(_DWORD *)(a11 + 672) = *(_DWORD *)(v16 + 24);
  *(_DWORD *)(a11 + 12) = *(_DWORD *)(v16 + 8);
  *(_BYTE *)(a11 + 1) = *(_BYTE *)(v16 + 28) & 1;
  v19 = *(_DWORD *)(v16 + 20);
  if ( (unsigned __int16)v19 > 0x36u )
    LOWORD(v19) = 54;
  *(_WORD *)(a11 + 8) = v19;
  v20 = (*(_DWORD *)(v16 + 28) >> 1) & 7;
  *(_BYTE *)(a11 + 677) = (*(_DWORD *)(v16 + 28) >> 1) & 7;
  if ( v20 )
    *(_BYTE *)(a11 + 676) = 1;
  if ( !v18 || (_WORD)v17 || (v21 = *(_DWORD *)(a10 + 56)) == 0 || v21 <= a13 )
  {
LABEL_22:
    if ( !*(_DWORD *)(v16 + 16) || !*(_DWORD *)(a10 + 72) )
      return 0;
    if ( (*(_DWORD *)(v16 + 16) & 0xFFFEu) <= 9 )
      v28 = *(_DWORD *)(v16 + 16);
    else
      v28 = 9;
    *(_WORD *)(a11 + 4) = v28;
    if ( *(_DWORD *)(a10 + 72) > (unsigned int)a14 )
    {
      if ( v28 )
      {
        v29 = 0;
        v30 = a11 + 92;
        v31 = *(_QWORD *)(a10 + 64) + 76LL * a14 + 32;
        do
        {
          ++v29;
          result = 0;
          *(_WORD *)(v30 + 5) = *(_DWORD *)(v31 - 20);
          *(_BYTE *)(v30 + 7) = *(_WORD *)(v31 - 18);
          *(_BYTE *)(v30 + 8) = *(_BYTE *)(v31 - 17);
          *(_WORD *)(v30 + 9) = *(_DWORD *)(v31 - 16);
          *(_BYTE *)(v30 + 4) = *(_DWORD *)(v31 - 24);
          *(_WORD *)(v30 + 12) = *(_DWORD *)(v31 - 12);
          *(_DWORD *)(v30 + 36) = *(_DWORD *)(v31 + 12);
          *(_DWORD *)(v30 + 24) = *(_DWORD *)(v31 - 8);
          *(_DWORD *)(v30 + 28) = *(_DWORD *)v31;
          *(_DWORD *)(v30 + 16) = *(_DWORD *)(v31 - 4);
          *(_DWORD *)(v30 + 20) = *(_DWORD *)(v31 + 4);
          *(_DWORD *)(v30 + 32) = *(_DWORD *)(v31 + 8);
          *(_DWORD *)v30 = *(_DWORD *)(v31 - 28);
          *(_DWORD *)(v30 + 40) = *(_DWORD *)(v31 + 16);
          *(_DWORD *)(v30 + 44) = *(_DWORD *)(v31 + 20);
          *(_DWORD *)(v30 + 48) = *(_DWORD *)(v31 + 24);
          *(_DWORD *)(v30 + 52) = *(_DWORD *)(v31 + 28);
          v32 = *(_BYTE *)(v31 + 32);
          v31 += 76;
          *(_BYTE *)(v30 + 56) = v32 & 1;
          v30 += 60;
        }
        while ( v28 > (unsigned int)(unsigned __int8)v29 );
        return result;
      }
      return 0;
    }
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid roam scan AP tlv ap_idx:%d total_ap:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_scan_ap_stats_tlv");
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Extract candidate stats for tlv[%d] failed",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "extract_roam_scan_stats_tlv",
      v15);
    return 16;
  }
  if ( v18 >= 0x27 )
  {
    v18 = 38;
    *(_WORD *)(a11 + 6) = 38;
    v21 = *(_DWORD *)(a10 + 56);
  }
  if ( v18 + a13 <= v21 )
  {
    v23 = 0;
    v24 = (int *)(*(_QWORD *)(a10 + 48) + 12LL * a13 + 8);
    while ( v23 != 38 )
    {
      *(_WORD *)(a11 + 2 * v23 + 16) = *(v24 - 1);
      v25 = *v24;
      v24 += 3;
      v26 = v25 == 1;
      if ( v25 == 2 )
        v27 = 2;
      else
        v27 = v26;
      *(_BYTE *)(a11 + 632 + v23++) = v27;
      if ( v18 == v23 )
        goto LABEL_22;
    }
    __break(0x5512u);
    return extract_roam_result_stats_tlv();
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid TLV. num_chan %d chan_idx %d num_roam_scan_chan_info %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_scan_stats_tlv",
      v18,
      a13);
    return 0;
  }
}
