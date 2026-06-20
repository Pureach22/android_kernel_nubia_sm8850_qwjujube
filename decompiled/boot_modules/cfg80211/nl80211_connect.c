unsigned __int64 __fastcall nl80211_connect(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  _QWORD *v5; // x8
  _WORD *v6; // x9
  __int64 v7; // x9
  unsigned int v8; // w9
  unsigned __int64 result; // x0
  bool v11; // w10
  __int64 v12; // x8
  int v13; // w8
  _QWORD *v14; // x8
  __int64 v15; // x9
  __int64 v16; // x9
  _QWORD *v17; // x10
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x9
  __int64 v22; // x1
  __int64 v23; // x9
  __int64 channel_khz; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  _QWORD *v27; // x8
  __int64 v28; // x9
  __int64 v29; // x9
  __int64 v30; // x9
  __int64 v31; // x11
  __int16 v32; // w12
  __int64 v33; // x13
  __int64 v34; // x9
  __int64 v35; // x9
  __int16 v36; // w10
  __int64 v37; // x11
  __int64 v38; // x12
  __int64 v39; // x9
  __int64 v40; // x9
  __int64 v41; // x11
  int v42; // w9
  __int64 v43; // x9
  int v44; // w10
  __int64 v45; // x9
  __int64 v46; // x9
  __int64 v47; // x9
  unsigned int v48; // w0
  unsigned int v49; // w21
  __int64 v50; // x8
  int v51; // w9
  _QWORD *v52; // x20
  unsigned __int64 v53; // [xsp+0h] [xbp-1A0h]
  _QWORD s[51]; // [xsp+8h] [xbp-198h] BYREF

  s[50] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 48);
  v3 = *(_QWORD *)(a2 + 56);
  memset(s, 0, 0x190u);
  v5 = *(_QWORD **)(a2 + 32);
  v6 = (_WORD *)v5[52];
  if ( !v6 || *v6 == 4 )
    goto LABEL_89;
  v7 = v5[53];
  if ( !v7 )
  {
    LODWORD(s[6]) = 8;
    goto LABEL_16;
  }
  v8 = *(_DWORD *)(v7 + 4);
  LODWORD(s[6]) = v8;
  if ( v8 > 7 )
    goto LABEL_89;
  if ( (*(_BYTE *)(v4 + 1100) & 0x20) != 0 )
  {
    if ( (~v8 & 6) != 0 )
      goto LABEL_27;
LABEL_89:
    result = 4294967274LL;
    goto LABEL_90;
  }
  result = 4294967274LL;
  v11 = (*(_BYTE *)(v4 + 1108) & 0x40) == 0 && v8 == 4;
  if ( (~v8 & 6) == 0 || v11 )
    goto LABEL_90;
LABEL_27:
  if ( v8 == 5 && (*(_BYTE *)(v4 + 1105) & 0x40) == 0 )
    goto LABEL_89;
LABEL_16:
  LOBYTE(s[9]) = v5[70] != 0;
  v12 = v5[257];
  if ( v12 && (*(_BYTE *)(v4 + 1106) & 1) == 0 )
    goto LABEL_89;
  LOBYTE(s[47]) = v12 != 0;
  result = nl80211_crypto_settings(v4, a2, &s[10], 5);
  if ( (_DWORD)result )
    goto LABEL_90;
  v13 = *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL);
  if ( v13 != 8 && v13 != 2 )
  {
LABEL_38:
    result = 4294967201LL;
    goto LABEL_90;
  }
  v14 = *(_QWORD **)(a2 + 32);
  LODWORD(s[27]) = -1;
  v15 = v14[152];
  if ( v15 && (*(_BYTE *)(v4 + 1093) & 0x20) != 0 )
    LODWORD(s[27]) = *(unsigned __int16 *)(v15 + 4);
  v16 = v14[6];
  if ( v16 )
  {
    v17 = &s[2];
  }
  else
  {
    v16 = v14[200];
    if ( !v16 )
      goto LABEL_33;
    v17 = &s[3];
  }
  *v17 = v16 + 4;
LABEL_33:
  s[4] = v14[52] + 4LL;
  s[5] = (unsigned __int16)(*(_WORD *)v14[52] - 4);
  v18 = v14[42];
  if ( v18 )
  {
    s[7] = v18 + 4;
    s[8] = (unsigned __int16)(*(_WORD *)v14[42] - 4);
  }
  v19 = v14[66];
  if ( v19 )
  {
    HIDWORD(s[9]) = *(_DWORD *)(v19 + 4);
    if ( HIDWORD(s[9]) == 2 && (*(_BYTE *)(v4 + 1106) & 0x20) == 0 )
      goto LABEL_38;
  }
  else
  {
    HIDWORD(s[9]) = 0;
  }
  v20 = v14[79];
  if ( v20 )
    s[39] = v20 + 4;
  v21 = v14[38];
  if ( v21 )
    v22 = (unsigned int)(1000 * *(_DWORD *)(v21 + 4));
  else
    v22 = 0;
  v23 = v14[290];
  if ( v23 )
    v22 = (unsigned int)(*(_DWORD *)(v23 + 4) + v22);
  if ( (_DWORD)v22 )
  {
    channel_khz = ieee80211_get_channel_khz(v4 + 992, v22);
    if ( !channel_khz || (*(_BYTE *)(channel_khz + 12) & 1) != 0 )
      goto LABEL_89;
    s[0] = channel_khz;
  }
  else
  {
    v25 = v14[201];
    if ( v25 )
    {
      v26 = ieee80211_get_channel_khz(v4 + 992, (unsigned int)(1000 * *(_DWORD *)(v25 + 4)));
      if ( !v26 || (*(_BYTE *)(v26 + 12) & 1) != 0 )
        goto LABEL_89;
      s[1] = v26;
    }
  }
  v27 = *(_QWORD **)(a2 + 32);
  v28 = v27[280];
  if ( v28 )
  {
    BYTE4(s[47]) = *(_BYTE *)(v28 + 4);
    v29 = v27[281];
    if ( v29 )
      LODWORD(s[48]) = *(unsigned __int8 *)(v29 + 4);
  }
  if ( LOBYTE(s[9]) == 1 && v27[81] )
  {
    result = nl80211_parse_connkeys(v4, a2, 0);
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_90;
    v27 = *(_QWORD **)(a2 + 32);
  }
  else
  {
    result = 0;
  }
  if ( v27[147] )
    HIDWORD(s[26]) |= 1u;
  v30 = v27[148];
  if ( v30 )
  {
    v31 = *(_QWORD *)(v30 + 20);
    v32 = *(_WORD *)(v30 + 28);
    v33 = *(_QWORD *)(v30 + 4);
    v34 = *(_QWORD *)(v30 + 12);
    *(_QWORD *)((char *)&s[32] + 6) = v31;
    HIWORD(s[33]) = v32;
    *(_QWORD *)((char *)&s[31] + 6) = v34;
    *(_QWORD *)((char *)&s[30] + 6) = v33;
  }
  v35 = v27[31];
  if ( v35 )
  {
    if ( !v27[148] )
      goto LABEL_88;
    v36 = *(_WORD *)(v35 + 28);
    v37 = *(_QWORD *)(v35 + 20);
    v38 = *(_QWORD *)(v35 + 4);
    v39 = *(_QWORD *)(v35 + 12);
    WORD2(s[30]) = v36;
    *(_QWORD *)((char *)&s[29] + 4) = v37;
    *(_QWORD *)((char *)&s[28] + 4) = v39;
    *(_QWORD *)((char *)&s[27] + 4) = v38;
  }
  if ( v27[175] )
    HIDWORD(s[26]) |= 2u;
  if ( v27[301] )
    HIDWORD(s[26]) |= 0x10u;
  if ( v27[311] )
    HIDWORD(s[26]) |= 0x20u;
  v40 = v27[176];
  if ( v40 )
  {
    v41 = *(_QWORD *)(v40 + 4);
    v42 = *(_DWORD *)(v40 + 12);
    *(_QWORD *)((char *)&s[35] + 4) = v41;
    HIDWORD(s[36]) = v42;
  }
  v43 = v27[157];
  if ( v43 )
  {
    if ( !v27[176] )
      goto LABEL_88;
    v44 = *(_DWORD *)(v43 + 12);
    v45 = *(_QWORD *)(v43 + 4);
    LODWORD(s[35]) = v44;
    s[34] = v45;
  }
  if ( v27[208] )
  {
    if ( (~*(_DWORD *)(v4 + 1100) & 0x280000) != 0 && (*(_BYTE *)(v4 + 1104) & 2) == 0 )
      goto LABEL_88;
    HIDWORD(s[26]) |= 4u;
  }
  v46 = v27[226];
  LOBYTE(s[37]) = v46 != 0;
  if ( v46 && !*(_QWORD *)(v4 + 1336) )
  {
    kfree_sensitive(result);
    result = 4294967201LL;
    goto LABEL_90;
  }
  if ( v27[227] )
    goto LABEL_88;
  v47 = v27[249];
  if ( (*(_BYTE *)(v4 + 1105) & 0x40) == 0 )
  {
    if ( !v47 )
      goto LABEL_100;
LABEL_88:
    kfree_sensitive(result);
    goto LABEL_89;
  }
  if ( v47 )
  {
    if ( v27[250] && v27[251] && v27[252] )
    {
      s[40] = v47 + 4;
      s[41] = (unsigned __int16)(*(_WORD *)v27[249] - 4);
      s[42] = v27[250] + 4LL;
      s[43] = (unsigned __int16)(*(_WORD *)v27[250] - 4);
      LOWORD(s[44]) = *(_WORD *)(v27[251] + 4LL);
      s[45] = v27[252] + 4LL;
      s[46] = (unsigned __int16)(*(_WORD *)v27[252] - 4);
      goto LABEL_103;
    }
    goto LABEL_88;
  }
LABEL_100:
  if ( v27[250] || v27[251] || v27[252] )
    goto LABEL_88;
LABEL_103:
  v53 = result;
  if ( v27[261] )
  {
    if ( !v27[204] )
    {
      kfree_sensitive(result);
      v52 = *(_QWORD **)(a2 + 64);
      do_trace_netlink_extack("external auth requires connection ownership");
      if ( v52 )
        *v52 = "external auth requires connection ownership";
      goto LABEL_89;
    }
    HIDWORD(s[26]) |= 8u;
  }
  if ( v27[315] )
    HIDWORD(s[26]) |= 0x40u;
  v48 = cfg80211_connect(v4, v3, s, result, s[39]);
  if ( v48 )
  {
    v49 = v48;
    kfree_sensitive(v53);
    result = v49;
  }
  else if ( *(_QWORD *)(*(_QWORD *)(a2 + 32) + 1632LL) )
  {
    result = 0;
    *(_DWORD *)(*(_QWORD *)(v3 + 992) + 100LL) = *(_DWORD *)(a2 + 4);
    v50 = *(_QWORD *)(v3 + 992);
    if ( s[2] )
    {
      v51 = *(_DWORD *)s[2];
      *(_WORD *)(v50 + 140) = *(_WORD *)(s[2] + 4LL);
      *(_DWORD *)(v50 + 136) = v51;
    }
    else
    {
      *(_WORD *)(v50 + 140) = 0;
      *(_DWORD *)(v50 + 136) = 0;
    }
  }
  else
  {
    result = 0;
  }
LABEL_90:
  _ReadStatusReg(SP_EL0);
  return result;
}
