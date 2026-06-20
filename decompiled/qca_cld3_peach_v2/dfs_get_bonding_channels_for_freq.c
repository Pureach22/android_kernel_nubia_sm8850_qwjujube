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
  __int16 v16; // w9
  __int64 result; // x0
  int v18; // w8
  __int16 v19; // w10
  __int16 v20; // w8
  __int16 v21; // w9
  __int64 v22; // x8
  unsigned int v23; // w8
  __int16 v24; // w8
  __int16 v25; // w8
  __int16 v26; // w8

  if ( a4 != 3 )
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
      v16 = *(_WORD *)(a2 + 24);
      if ( (v15 & 0x1000000000LL) == 0 )
        goto LABEL_13;
    }
    else
    {
      v16 = *(_WORD *)(a2 + 22);
      if ( (v15 & 0x1000000000LL) == 0 )
        goto LABEL_13;
    }
LABEL_35:
    *a5 = v16;
    return 1;
  }
  v15 = *(_QWORD *)(a2 + 8);
  v16 = *(_WORD *)(a1 + 14952);
  if ( (v15 & 0x1000000000LL) != 0 )
    goto LABEL_35;
LABEL_13:
  if ( (v15 & 0x10000100) == 0x10000100
    || (v15 & 0x100100) == 0x100100
    || (v15 & 0x140) == 0x140
    || (v15 & 0x10100) == 0x10100 )
  {
    goto LABEL_35;
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
    *a5 = v16 - 10;
    a5[1] = v16 + 10;
    return 2;
  }
  if ( (~v15 & 0x8000000100LL) == 0 || (v15 & 0x800100) == 0x800100 || (v15 & 0x200000100LL) == 0x200000100LL )
    goto LABEL_48;
  if ( (~v15 & 0x10000000100LL) != 0 && (v15 & 0x4000100) != 0x4000100 && (v15 & 0x400000100LL) != 0x400000100LL )
  {
    if ( (~v15 & 0x20000000100LL) == 0 )
    {
      *a5 = v16 - 150;
      a5[1] = v16 - 130;
      a5[2] = v16 - 110;
      a5[3] = v16 - 90;
      a5[4] = v16 - 70;
      a5[5] = v16 - 50;
      a5[6] = v16 - 30;
      a5[7] = v16 - 10;
      a5[8] = v16 + 10;
      a5[9] = v16 + 30;
      a5[10] = v16 + 50;
      a5[11] = v16 + 70;
      a5[12] = v16 + 90;
      a5[13] = v16 + 110;
      a5[14] = v16 + 130;
      a5[15] = v16 + 150;
      return 12;
    }
    if ( (~(_DWORD)v15 & 0x8000100) != 0 && (v15 & 0x800000100LL) != 0x800000100LL )
      return 0;
    if ( a4 == 3 )
    {
      v23 = *(_DWORD *)(a1 + 14880);
      if ( v23 != 2 )
      {
        if ( v23 == 3 )
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
          v23,
          v13,
          v14);
        return 0;
      }
    }
LABEL_48:
    *a5 = v16 - 30;
    a5[2] = v16 + 10;
    a5[1] = v16 - 10;
    a5[3] = v16 + 30;
    return 4;
  }
  if ( a4 != 3 )
  {
LABEL_47:
    *a5 = v16 - 70;
    a5[1] = v16 - 50;
    a5[2] = v16 - 30;
    a5[3] = v16 - 10;
    a5[4] = v16 + 10;
    a5[5] = v16 + 30;
    a5[6] = v16 + 50;
    a5[7] = v16 + 70;
    return 8;
  }
  v18 = *(_DWORD *)(a1 + 14880);
  if ( v18 != 4 )
  {
    if ( v18 == 3 )
    {
      v19 = v16 - 50;
      result = 8;
      *a5 = v16 - 70;
      a5[2] = v16 - 30;
      a5[3] = v16 - 10;
      a5[4] = v16 + 10;
      a5[5] = v16 + 30;
      v24 = v16 + 50;
      v21 = v16 + 70;
      a5[6] = v24;
      v22 = 7;
    }
    else
    {
      if ( v18 != 2 )
        return 8;
      v19 = v16 - 10;
      result = 4;
      *a5 = v16 - 30;
      v20 = v16 + 10;
      v21 = v16 + 30;
      a5[2] = v20;
      v22 = 3;
    }
    a5[1] = v19;
    a5[v22] = v21;
    return result;
  }
  if ( a3 )
    v25 = 45;
  else
    v25 = -40;
  v26 = v16 + v25;
  *a5 = v26 - 30;
  a5[1] = v26 - 10;
  a5[2] = v26 + 10;
  a5[3] = v26 + 30;
  return 4;
}
