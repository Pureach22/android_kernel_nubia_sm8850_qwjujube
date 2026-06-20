__int64 __fastcall parse_station_flags(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  int v5; // w8
  __int64 result; // x0
  _WORD *v7; // x8
  int v10; // w9
  __int64 v11; // x10
  int v12; // w9
  __int64 v13; // [xsp+0h] [xbp-50h] BYREF
  __int64 v14; // [xsp+8h] [xbp-48h]
  __int64 v15; // [xsp+10h] [xbp-40h]
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int64 v17; // [xsp+20h] [xbp-30h]
  __int64 v18; // [xsp+28h] [xbp-28h]
  __int64 v19; // [xsp+30h] [xbp-20h]
  __int64 v20; // [xsp+38h] [xbp-18h]
  __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v13 = 0;
  v4 = *(_QWORD *)(v3 + 536);
  if ( !v4 )
  {
    v7 = *(_WORD **)(v3 + 136);
    if ( v7 )
    {
      if ( (unsigned int)_nla_parse(
                           &v13,
                           8,
                           v7 + 2,
                           (unsigned __int16)(*v7 - 4),
                           &sta_flags_policy,
                           0,
                           *(_QWORD *)(a1 + 64)) )
        goto LABEL_24;
      v10 = a2 - 2;
      if ( (unsigned int)(a2 - 2) > 7 || ((0xE7u >> v10) & 1) == 0 )
        goto LABEL_24;
      v11 = v14;
      *(_DWORD *)(a3 + 8) = dword_BF5F8[v10];
      if ( v11 )
        *(_DWORD *)(a3 + 12) |= 2u;
      if ( v15 )
        *(_DWORD *)(a3 + 12) |= 4u;
      if ( v16 )
        *(_DWORD *)(a3 + 12) |= 8u;
      if ( v17 )
        *(_DWORD *)(a3 + 12) |= 0x10u;
      if ( v18 )
        *(_DWORD *)(a3 + 12) |= 0x20u;
      if ( v19 )
        *(_DWORD *)(a3 + 12) |= 0x40u;
      if ( v20 )
      {
        v12 = *(_DWORD *)(a3 + 12) | 0x80;
LABEL_23:
        *(_DWORD *)(a3 + 12) = v12;
LABEL_24:
        result = 4294967274LL;
        goto LABEL_26;
      }
      if ( v21 )
      {
        v12 = *(_DWORD *)(a3 + 12) | 0x100;
        goto LABEL_23;
      }
    }
    result = 0;
    goto LABEL_26;
  }
  v5 = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(a3 + 8) = v5;
  *(_DWORD *)(a3 + 12) = *(_DWORD *)(v4 + 8) & v5;
  result = (v5 << 31 >> 31) & 0xFFFFFFEA;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
