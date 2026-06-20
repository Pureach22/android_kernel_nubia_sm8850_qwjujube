__int64 __fastcall lim_update_stads_he_caps(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
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
  int v13; // w8
  unsigned __int64 *v19; // x8
  __int64 v20; // x11
  __int64 v21; // x12
  unsigned int v22; // w12
  __int64 v23; // x9
  __int64 v24; // x10
  unsigned int v25; // w11
  unsigned __int64 v26; // x9
  bool is_24ghz_ch_freq; // w0
  __int64 v28; // x8
  __int16 v29; // w8

  v13 = *(unsigned __int8 *)(a4 + 154);
  if ( (unsigned int)(v13 - 10) >= 4 && v13 != 0 )
    goto LABEL_29;
  if ( !*(_BYTE *)(a3 + 2508) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: HE cap IE is missing in assoc response",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_update_stads_he_caps");
    goto LABEL_29;
  }
  *(_BYTE *)(a2 + 38) = 1;
  if ( a5 )
  {
    v19 = (unsigned __int64 *)(a5 + 2641);
    v20 = *(_QWORD *)(a3 + 2509);
    v21 = *(_QWORD *)(a5 + 2641) & 0x4000000000000000LL | v20;
    *(_QWORD *)(a3 + 2509) = v21;
    if ( (v21 & 0x4000000000000000LL) != 0 )
    {
      v23 = v21 & 0x4000000000000000LL;
    }
    else
    {
      if ( !*(_DWORD *)(a4 + 7176) )
      {
        v22 = *(unsigned __int16 *)(a3 + 2528);
        if ( ((v22 >> (2 * *(_BYTE *)(a4 + 8635) - 2)) & 3) != 2
          && ((*(unsigned __int16 *)(a3 + 2530) >> (2 * *(_BYTE *)(a4 + 8635) - 2)) & 3) != 2 )
        {
          if ( *(_BYTE *)(a4 + 8676) != 1 )
          {
            v23 = 0;
            goto LABEL_20;
          }
          v23 = 0;
          if ( v22 >> 8 > 0xFE || !*(_BYTE *)(a3 + 2508) )
            goto LABEL_20;
        }
      }
      *(_QWORD *)(a3 + 2509) = v20 | 0x4000000000000000LL;
      v23 = 0x4000000000000000LL;
    }
LABEL_20:
    v26 = *v19 & 0xBFFFFFFFFFFFFFFFLL | v23;
    goto LABEL_21;
  }
  v19 = (unsigned __int64 *)(a3 + 2509);
  v24 = *(_QWORD *)(a3 + 2509);
  if ( (v24 & 0x4000000000000000LL) != 0 )
    goto LABEL_22;
  if ( !*(_DWORD *)(a4 + 7176) )
  {
    v25 = *(unsigned __int16 *)(a3 + 2528);
    if ( ((v25 >> (2 * *(_BYTE *)(a4 + 8635) - 2)) & 3) != 2
      && ((*(unsigned __int16 *)(a3 + 2530) >> (2 * *(_BYTE *)(a4 + 8635) - 2)) & 3) != 2
      && (*(_BYTE *)(a4 + 8676) != 1 || v25 >> 8 > 0xFE || !*(_BYTE *)(a3 + 2508)) )
    {
      goto LABEL_22;
    }
  }
  v26 = v24 | 0x4000000000000000LL;
LABEL_21:
  *v19 = v26;
LABEL_22:
  qdf_mem_copy((void *)(a2 + 864), (const void *)(a3 + 2508), 0x3Cu);
  if ( *(_BYTE *)(a3 + 2464) && *(_BYTE *)(a3 + 2484) )
    *(_WORD *)(a2 + 924) = *(_WORD *)(a3 + 2485);
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284));
  v28 = *(_QWORD *)(a1 + 8);
  if ( is_24ghz_ch_freq )
    v29 = *(_WORD *)(v28 + 1492);
  else
    v29 = *(_WORD *)(v28 + 1494);
  *(_WORD *)(a2 + 924) &= v29;
LABEL_29:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: he_mcs_12_13_map: sta_ds 0x%x, 2g_fw 0x%x, 5g_fw 0x%x",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_update_stads_he_caps",
    *(unsigned __int16 *)(a2 + 924),
    *(unsigned __int16 *)(*(_QWORD *)(a1 + 8) + 1492LL),
    *(unsigned __int16 *)(*(_QWORD *)(a1 + 8) + 1494LL));
  return lim_update_he_mcs_12_13_map(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a4 + 10), *(_WORD *)(a2 + 924));
}
