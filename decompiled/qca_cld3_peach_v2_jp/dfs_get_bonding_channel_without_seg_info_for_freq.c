__int64 __fastcall dfs_get_bonding_channel_without_seg_info_for_freq(
        __int64 a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x9
  __int16 v13; // w8
  __int16 v15; // w8
  __int16 v16; // w10
  __int16 v17; // w9
  __int16 v18; // w8
  __int16 v19; // w8

  v12 = *(_QWORD *)(a1 + 8);
  v13 = *(_WORD *)(a1 + 22);
  if ( (v12 & 0x1000000000LL) != 0
    || (*(_QWORD *)(a1 + 8) & 0x10000100LL) == 0x10000100
    || (v12 & 0x100100) == 0x100100
    || (*(_QWORD *)(a1 + 8) & 0x140LL) == 0x140
    || (v12 & 0x10100) == 0x10100 )
  {
    *a2 = v13;
    return 1;
  }
  if ( (~v12 & 0x4000000100LL) == 0
    || (v12 & 0x2000000100LL) == 0x2000000100LL
    || (*(_QWORD *)(a1 + 8) & 0x40000100LL) == 0x40000100
    || (*(_QWORD *)(a1 + 8) & 0x20000100LL) == 0x20000100
    || (v12 & 0x40100) == 0x40100
    || (v12 & 0x20100) == 0x20100
    || (v12 & 0x200100) == 0x200100
    || (v12 & 0x400100) == 0x400100 )
  {
    *a2 = v13 - 10;
    a2[1] = v13 + 10;
    return 2;
  }
  if ( (~v12 & 0x8000000100LL) == 0 || (v12 & 0x800100) == 0x800100 || (v12 & 0x200000100LL) == 0x200000100LL )
  {
    *a2 = v13 - 30;
    a2[1] = v13 - 10;
    a2[2] = v13 + 10;
    a2[3] = v13 + 30;
    return 4;
  }
  if ( (~(_DWORD)v12 & 0x8000100) == 0 || (v12 & 0x800000100LL) == 0x800000100LL )
  {
    *a2 = v13 - 30;
    a2[1] = v13 - 10;
    a2[2] = v13 + 10;
    a2[3] = v13 + 30;
    v15 = *(_WORD *)(a1 + 24);
    v16 = v15 - 10;
    a2[4] = v15 - 30;
    v17 = v15 + 10;
    v18 = v15 + 30;
    a2[5] = v16;
LABEL_30:
    a2[6] = v17;
    a2[7] = v18;
    return 8;
  }
  if ( (~v12 & 0x10000000100LL) == 0
    || (*(_QWORD *)(a1 + 8) & 0x4000100LL) == 0x4000100
    || (v12 & 0x400000100LL) == 0x400000100LL )
  {
    v19 = *(_WORD *)(a1 + 24);
    *a2 = v19 - 70;
    a2[1] = v19 - 50;
    a2[2] = v19 - 30;
    a2[3] = v19 - 10;
    a2[4] = v19 + 10;
    a2[5] = v19 + 30;
    v17 = v19 + 50;
    v18 = v19 + 70;
    goto LABEL_30;
  }
  if ( (~v12 & 0x20000000100LL) == 0 )
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: 320MHz chan width for non 11be",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dfs_get_320mhz_bonding_channels",
      v10,
      v11);
  return 0;
}
