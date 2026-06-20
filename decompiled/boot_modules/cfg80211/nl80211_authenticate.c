__int64 __fastcall nl80211_authenticate(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 result; // x0
  int v7; // w8
  _QWORD *v8; // x8
  __int64 v9; // x1
  __int64 v10; // x9
  __int64 v11; // x22
  __int64 channel_khz; // x0
  _QWORD *v13; // x9
  __int16 *v14; // x3
  _WORD *v15; // x10
  _WORD *v16; // x3
  __int16 v17; // w8
  __int16 v18; // t1
  _BYTE *v19; // x10
  unsigned int v20; // w10
  _WORD *v21; // x11
  __int64 v22; // x9
  int *v23; // x10
  int v24; // t1
  __int64 v25; // x10
  int v26; // w10
  __int64 v27; // x9
  int v28; // w10
  unsigned int v29; // w20
  __int64 bss; // [xsp+8h] [xbp-98h] BYREF
  _WORD *v31; // [xsp+10h] [xbp-90h]
  __int64 v32; // [xsp+18h] [xbp-88h]
  _BYTE *v33; // [xsp+20h] [xbp-80h]
  __int64 v34; // [xsp+28h] [xbp-78h]
  __int64 v35; // [xsp+30h] [xbp-70h]
  __int64 v36; // [xsp+38h] [xbp-68h]
  _WORD *v37; // [xsp+40h] [xbp-60h]
  __int64 v38; // [xsp+48h] [xbp-58h]
  __int64 v39; // [xsp+50h] [xbp-50h]
  __int64 v40; // [xsp+58h] [xbp-48h]
  _QWORD v41[2]; // [xsp+60h] [xbp-40h] BYREF
  __int64 v42; // [xsp+70h] [xbp-30h]
  __int64 v43; // [xsp+78h] [xbp-28h]
  __int64 v44; // [xsp+80h] [xbp-20h]
  __int64 v45; // [xsp+88h] [xbp-18h]
  __int64 v46; // [xsp+90h] [xbp-10h]
  __int64 v47; // [xsp+98h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)a2[4];
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v3 = a2[6];
  v4 = a2[7];
  v41[1] = 0;
  v42 = 0;
  v41[0] = 0;
  v39 = 0;
  v40 = 0;
  v37 = nullptr;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = nullptr;
  v34 = 0;
  v31 = nullptr;
  v32 = 0;
  bss = 0;
  if ( !v2[6] || !v2[53] || !v2[52] || !v2[38] )
    goto LABEL_8;
  result = nl80211_parse_key(a2, v41);
  if ( (_DWORD)result )
    goto LABEL_9;
  if ( (v45 & 0x80000000) != 0 )
  {
    LODWORD(v42) = 0;
    v41[0] = 0;
LABEL_11:
    if ( !*(_QWORD *)(*(_QWORD *)v3 + 336LL) || (v7 = *(_DWORD *)(*(_QWORD *)(v4 + 992) + 8LL), v7 != 8) && v7 != 2 )
    {
      result = 4294967201LL;
      goto LABEL_9;
    }
    v8 = (_QWORD *)a2[4];
    v9 = (unsigned int)(1000 * *(_DWORD *)(v8[38] + 4LL));
    v10 = v8[290];
    if ( v10 )
      v9 = (unsigned int)(*(_DWORD *)(v10 + 4) + v9);
    v11 = v8[6];
    channel_khz = ieee80211_get_channel_khz(v3 + 992, v9);
    if ( !channel_khz || (*(_BYTE *)(channel_khz + 12) & 1) != 0 )
      goto LABEL_8;
    v13 = (_QWORD *)a2[4];
    v14 = (__int16 *)v13[52];
    v15 = (_WORD *)v13[42];
    v18 = *v14;
    v16 = v14 + 2;
    v17 = v18;
    if ( v15 )
    {
      v31 = v15 + 2;
      v32 = (unsigned __int16)(*v15 - 4);
    }
    v19 = (_BYTE *)v13[334];
    if ( v19 )
    {
      v33 = v19 + 4;
      LOBYTE(v34) = *v19 - 4;
    }
    v20 = *(_DWORD *)(v13[53] + 4LL);
    if ( v20 > 7 || v20 == 4 && (*(_DWORD *)(v3 + 1100) & 0x20) == 0 )
      goto LABEL_8;
    if ( (*(_BYTE *)(v3 + 1105) & 2) == 0 && (v20 | 0xFFFFFFF8) > 0xFFFFFFFC )
      goto LABEL_8;
    v21 = (_WORD *)v13[156];
    if ( v20 >= 4 )
    {
      if ( !v21 )
        goto LABEL_8;
      v37 = v21 + 2;
      v38 = (unsigned __int16)(*v21 - 4);
    }
    else if ( v21 )
    {
      goto LABEL_8;
    }
    if ( v13[95] )
    {
      result = 0;
      goto LABEL_9;
    }
    HIDWORD(v34) = v20;
    v35 = v41[0];
    LOBYTE(v36) = v42;
    BYTE1(v36) = v45;
    v25 = v13[313];
    if ( v25 )
    {
      v26 = *(char *)(v25 + 4);
      LOBYTE(v39) = v26;
      if ( (v26 & 0x80000000) == 0 )
      {
        if ( (*(_BYTE *)(v3 + 1092) & 2) == 0 )
          goto LABEL_8;
        v27 = v13[314];
        if ( !v27 )
          goto LABEL_8;
        v40 = v27 + 4;
        v28 = *(_DWORD *)(v27 + 4);
        if ( (v28 & 1) != 0 || !(v28 | *(unsigned __int16 *)(v27 + 8)) )
          goto LABEL_8;
      }
    }
    else
    {
      LOBYTE(v39) = -1;
    }
    bss = _cfg80211_get_bss(v3 + 992, channel_khz, v11 + 4, v16, (unsigned __int16)(v17 - 4), 0, 2, 1);
    if ( bss )
    {
      v29 = cfg80211_mlme_auth((__int64 *)v3, v4, &bss);
      cfg80211_put_bss(v3 + 992, bss);
      result = v29;
    }
    else
    {
      result = 4294967294LL;
    }
    goto LABEL_9;
  }
  if ( (unsigned int)(HIDWORD(v45) - 1) < 0xFFFFFFFE )
  {
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  result = 4294967274LL;
  if ( v41[0] && (_DWORD)v42 )
  {
    if ( HIDWORD(v43) == 1027073 && (_DWORD)v42 == 5 )
    {
      if ( (unsigned int)v45 > 3 )
        goto LABEL_9;
    }
    else if ( (unsigned int)v45 > 3 || HIDWORD(v43) != 1027077 || (_DWORD)v42 != 13 )
    {
      goto LABEL_9;
    }
    v22 = *(unsigned int *)(v3 + 1148);
    if ( (int)v22 < 1 )
      goto LABEL_9;
    v23 = *(int **)(v3 + 1152);
    do
    {
      v24 = *v23++;
      if ( HIDWORD(v43) == v24 )
        goto LABEL_11;
    }
    while ( --v22 );
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
