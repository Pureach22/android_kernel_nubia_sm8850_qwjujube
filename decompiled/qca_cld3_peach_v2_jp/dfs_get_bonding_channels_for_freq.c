__int64 __fastcall dfs_get_bonding_channels_for_freq(
        __int64 a1,
        __int64 a2,
        int a3,
        char a4,
        _WORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x29
  __int64 v14; // x30
  __int64 v15; // x8
  __int16 *v16; // x9
  __int16 v17; // w9
  __int64 result; // x0
  int v19; // w8
  __int16 v20; // w10
  __int16 v21; // w8
  __int16 v22; // w9
  __int64 v23; // x8
  unsigned int v24; // w8
  __int16 v25; // w8
  __int16 v26; // w8
  __int16 v27; // w8

  if ( a4 == 3 )
  {
    v15 = *(_QWORD *)(a2 + 8);
    v16 = (__int16 *)(a1 + 14952);
  }
  else
  {
    v15 = *(_QWORD *)(a2 + 8);
    if ( (~v15 & 0x21000000000LL) == 0
      || (v15 & 0x20000000100LL) == 0x20000000100LL
      || (v15 & 0x11000000000LL) == 0x11000000000LL
      || (v15 & 0x10000000100LL) == 0x10000000100LL
      || (v15 & 0x1400000000LL) == 0x1400000000LL
      || (*(_QWORD *)(a2 + 8) & 0x4000100LL) == 0x4000100
      || (v15 & 0x400000100LL) == 0x400000100LL
      || a3 )
    {
      v16 = (__int16 *)(a2 + 24);
    }
    else
    {
      v16 = (__int16 *)(a2 + 22);
    }
  }
  v17 = *v16;
  if ( (v15 & 0x1000000000LL) != 0
    || (v15 & 0x10000100) == 0x10000100
    || (v15 & 0x100100) == 0x100100
    || (v15 & 0x140) == 0x140
    || (v15 & 0x10100) == 0x10100 )
  {
    *a5 = v17;
    return 1;
  }
  if ( (~v15 & 0x4000000100LL) == 0
    || (v15 & 0x2000000100LL) == 0x2000000100LL
    || (v15 & 0x40000100) == 0x40000100
    || (v15 & 0x20000100) == 0x20000100
    || (v15 & 0x40100) == 0x40100
    || (v15 & 0x20100) == 0x20100
    || (v15 & 0x200100) == 0x200100
    || (v15 & 0x400100) == 0x400100 )
  {
    *a5 = v17 - 10;
    a5[1] = v17 + 10;
    return 2;
  }
  if ( (~v15 & 0x8000000100LL) == 0 || (v15 & 0x800100) == 0x800100 || (v15 & 0x200000100LL) == 0x200000100LL )
    goto LABEL_48;
  if ( (~v15 & 0x10000000100LL) != 0 && (v15 & 0x4000100) != 0x4000100 && (v15 & 0x400000100LL) != 0x400000100LL )
  {
    if ( (~v15 & 0x20000000100LL) == 0 )
    {
      qdf_trace_msg(
        0x27u,
        8u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: 320MHz chan width for non 11be",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "dfs_get_320mhz_bonding_channels",
        v13,
        v14);
      return 0;
    }
    if ( (~(_DWORD)v15 & 0x8000100) != 0 && (v15 & 0x800000100LL) != 0x800000100LL )
      return 0;
    if ( a4 == 3 )
    {
      v24 = *(_DWORD *)(a1 + 14880);
      if ( v24 != 2 )
      {
        if ( v24 == 3 )
          goto LABEL_47;
        qdf_trace_msg(
          0x27u,
          2u,
          "WLAN_DEBUG_DFS_ALWAYS : %s: Incorrect precac width %u",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "dfs_get_bonding_channels_for_freq",
          v24,
          v13,
          v14);
        return 0;
      }
    }
LABEL_48:
    *a5 = v17 - 30;
    a5[2] = v17 + 10;
    a5[1] = v17 - 10;
    a5[3] = v17 + 30;
    return 4;
  }
  if ( a4 != 3 )
  {
LABEL_47:
    *a5 = v17 - 70;
    a5[1] = v17 - 50;
    a5[2] = v17 - 30;
    a5[3] = v17 - 10;
    a5[4] = v17 + 10;
    a5[5] = v17 + 30;
    a5[6] = v17 + 50;
    a5[7] = v17 + 70;
    return 8;
  }
  v19 = *(_DWORD *)(a1 + 14880);
  if ( v19 != 4 )
  {
    if ( v19 == 3 )
    {
      v20 = v17 - 50;
      result = 8;
      *a5 = v17 - 70;
      a5[2] = v17 - 30;
      a5[3] = v17 - 10;
      a5[4] = v17 + 10;
      a5[5] = v17 + 30;
      v25 = v17 + 50;
      v22 = v17 + 70;
      a5[6] = v25;
      v23 = 7;
    }
    else
    {
      if ( v19 != 2 )
        return 8;
      v20 = v17 - 10;
      result = 4;
      *a5 = v17 - 30;
      v21 = v17 + 10;
      v22 = v17 + 30;
      a5[2] = v21;
      v23 = 3;
    }
    a5[1] = v20;
    a5[v23] = v22;
    return result;
  }
  if ( a3 )
    v26 = 45;
  else
    v26 = -40;
  v27 = v17 + v26;
  *a5 = v27 - 30;
  a5[1] = v27 - 10;
  a5[2] = v27 + 10;
  a5[3] = v27 + 30;
  return 4;
}
