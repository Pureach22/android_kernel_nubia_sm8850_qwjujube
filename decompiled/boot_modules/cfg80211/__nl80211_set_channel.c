__int64 __fastcall _nl80211_set_channel(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  unsigned int v4; // w21
  __int64 v7; // x22
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 *v15; // x22
  __int64 v16; // x9
  __int64 v17; // x10
  unsigned int v18; // w8
  __int64 v19; // x8
  __int64 v20; // x10
  __int64 v21; // x11
  __int64 v22; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  unsigned int v26[2]; // [xsp+2Ch] [xbp-14h] BYREF
  char v27; // [xsp+34h] [xbp-Ch]
  __int16 v28; // [xsp+35h] [xbp-Bh]
  char v29; // [xsp+37h] [xbp-9h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v4 = a4;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  if ( a2 && (v7 = *(_QWORD *)(a2 + 992)) != 0 )
  {
    v8 = *(_DWORD *)(v7 + 8);
    result = 4294967201LL;
    if ( (unsigned int)v8 > 9 || ((1 << v8) & 0x2C8) == 0 )
      goto LABEL_34;
    if ( a4 < 0 )
    {
      if ( *(_WORD *)(v7 + 1472) )
        goto LABEL_33;
      v4 = 0;
    }
  }
  else
  {
    v7 = 0;
    v4 = a4 & ~(a4 >> 31);
    v8 = 6;
  }
  result = nl80211_parse_chandef(a1, a3, v8 == 6, (__int64)&v22);
  if ( (_DWORD)result )
    goto LABEL_34;
  result = 4294967274LL;
  if ( v8 <= 6 )
  {
    if ( v8 != 3 )
    {
      if ( v8 == 6 )
        result = cfg80211_set_monitor_channel((_DWORD *)a1);
      goto LABEL_34;
    }
    goto LABEL_16;
  }
  if ( v8 == 7 )
  {
    result = cfg80211_set_mesh_channel((__int64 *)a1, v7, &v22);
    goto LABEL_34;
  }
  if ( v8 != 9 )
  {
LABEL_34:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_16:
  v26[0] = v8;
  v26[1] = 0;
  v27 = 1;
  v28 = 0;
  v29 = 0;
  v10 = cfg80211_reg_check_beaconing(a1 + 992, (__int64)&v22, v26);
  if ( (v10 & 1) == 0 )
    goto LABEL_33;
  if ( v4 < 0xF )
  {
    v13 = v7 + 72LL * v4;
    if ( !*(_DWORD *)(v13 + 400) )
    {
      v16 = v23;
      result = 0;
      *(_QWORD *)(v7 + 280) = v22;
      *(_QWORD *)(v7 + 288) = v16;
      v17 = v25;
      *(_QWORD *)(v7 + 296) = v24;
      *(_QWORD *)(v7 + 304) = v17;
      goto LABEL_34;
    }
    if ( !a2
      || !*(_QWORD *)(*(_QWORD *)a1 + 744LL)
      || (*(_BYTE *)(a1 + 1102) & 4) == 0
      || (v14 = v13 + 400, v15 = (__int64 *)(v14 + 8), v22 != *(_QWORD *)(v14 + 8)) )
    {
      result = 4294967280LL;
      goto LABEL_34;
    }
    v18 = *(_DWORD *)(v14 + 16);
    if ( (v18 < 6 || v18 == 13) && ((unsigned int)v23 < 6 || (_DWORD)v23 == 13) )
    {
      result = rdev_set_ap_chanwidth(a1, a2, v4, &v22);
      if ( !(_DWORD)result )
      {
        v19 = v25;
        v20 = v22;
        v21 = v23;
        v15[2] = v24;
        v15[3] = v19;
        *v15 = v20;
        v15[1] = v21;
      }
      goto LABEL_34;
    }
LABEL_33:
    result = 4294967274LL;
    goto LABEL_34;
  }
  __break(0x5512u);
  return rdev_set_antenna(v10, v11, v12);
}
