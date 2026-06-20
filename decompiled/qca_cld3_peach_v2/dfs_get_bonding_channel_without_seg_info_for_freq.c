__int64 __fastcall dfs_get_bonding_channel_without_seg_info_for_freq(__int64 a1, _WORD *a2)
{
  __int64 v2; // x9
  __int16 v3; // w8
  __int64 result; // x0
  __int16 v5; // w8
  __int16 v6; // w10
  __int16 v7; // w9
  __int16 v8; // w8
  __int16 v9; // w8
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(_WORD *)(a1 + 22);
  v10[0] = 0;
  if ( (v2 & 0x1000000000LL) != 0
    || (v2 & 0x10000100) == 0x10000100
    || (v2 & 0x100100) == 0x100100
    || (v2 & 0x140) == 0x140
    || (v2 & 0x10100) == 0x10100 )
  {
    *a2 = v3;
    result = 1;
    goto LABEL_30;
  }
  if ( (~v2 & 0x4000000100LL) == 0
    || (v2 & 0x2000000100LL) == 0x2000000100LL
    || (v2 & 0x40000100) == 0x40000100
    || (v2 & 0x20000100) == 0x20000100
    || (v2 & 0x40100) == 0x40100
    || (v2 & 0x20100) == 0x20100
    || (v2 & 0x200100) == 0x200100
    || (v2 & 0x400100) == 0x400100 )
  {
    result = 2;
    *a2 = v3 - 10;
    a2[1] = v3 + 10;
    goto LABEL_30;
  }
  if ( (~v2 & 0x8000000100LL) == 0 || (v2 & 0x800100) == 0x800100 || (v2 & 0x200000100LL) == 0x200000100LL )
  {
    result = 4;
    *a2 = v3 - 30;
    a2[1] = v3 - 10;
    a2[2] = v3 + 10;
    a2[3] = v3 + 30;
    goto LABEL_30;
  }
  if ( (~(_DWORD)v2 & 0x8000100) == 0 || (v2 & 0x800000100LL) == 0x800000100LL )
  {
    *a2 = v3 - 30;
    a2[1] = v3 - 10;
    a2[2] = v3 + 10;
    a2[3] = v3 + 30;
    v5 = *(_WORD *)(a1 + 24);
    v6 = v5 - 10;
    a2[4] = v5 - 30;
    v7 = v5 + 10;
    v8 = v5 + 30;
    a2[5] = v6;
LABEL_29:
    a2[6] = v7;
    result = 8;
    a2[7] = v8;
    goto LABEL_30;
  }
  if ( (~v2 & 0x10000000100LL) == 0 || (v2 & 0x4000100) == 0x4000100 || (v2 & 0x400000100LL) == 0x400000100LL )
  {
    v9 = *(_WORD *)(a1 + 24);
    *a2 = v9 - 70;
    a2[1] = v9 - 50;
    a2[2] = v9 - 30;
    a2[3] = v9 - 10;
    a2[4] = v9 + 10;
    a2[5] = v9 + 30;
    v7 = v9 + 50;
    v8 = v9 + 70;
    goto LABEL_29;
  }
  if ( (~v2 & 0x20000000100LL) != 0 )
  {
    result = 0;
  }
  else
  {
    dfs_get_320mhz_bonding_channels(*(unsigned __int16 *)(a1 + 24), a2, v10);
    result = v10[0];
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
