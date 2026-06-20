__int64 __fastcall ieee80211_tx_h_michael_mic_add(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int v3; // w21
  unsigned __int16 *v4; // x20
  unsigned int v6; // w0
  bool v7; // cf
  unsigned __int64 v8; // x21
  int v10; // w9
  _QWORD *v11; // x8
  int v12; // w4
  int v13; // w3
  char *v14; // x1
  unsigned int v15; // w23
  _QWORD *v16; // x22
  _DWORD *v17; // x0
  __int64 v18; // x8
  _BYTE *v19; // x22

  v1 = a1[7];
  if ( !v1 )
    return 0;
  if ( *(_DWORD *)(v1 + 544) != 1027074 )
    return 0;
  v2 = *a1;
  v3 = *(_DWORD *)(*a1 + 112LL);
  if ( v3 < 0x18 )
    return 0;
  v4 = *(unsigned __int16 **)(v2 + 224);
  if ( (*v4 & 0x4C) != 8 )
    return 0;
  v6 = ieee80211_hdrlen(*v4);
  v7 = v3 >= v6;
  v8 = v3 - v6;
  if ( !v7 )
    return 1;
  v10 = *(_DWORD *)(v2 + 40);
  if ( (v10 & 0x4000000) != 0 )
  {
    *(_QWORD *)(v2 + 72) = 0;
    v12 = 12;
    v11 = a1;
    if ( !*(_DWORD *)(v2 + 116) )
      goto LABEL_19;
    goto LABEL_16;
  }
  v11 = a1;
  if ( !*(_QWORD *)(v2 + 72) )
  {
    v12 = 12;
    if ( !*(_DWORD *)(v2 + 116) )
      goto LABEL_19;
LABEL_16:
    v13 = 0;
    v14 = (char *)v4 - *(_QWORD *)(v2 + 216);
LABEL_17:
    _warn_printk("mmic: not enough head/tail (%d/%d,%d/%d)\n", (_DWORD)v14, 8, v13, v12);
    __break(0x800u);
    return 1;
  }
  if ( ((v10 & 0x40000000) != 0 || (*(_QWORD *)(a1[4] + 96LL) & 0x4000000000LL) != 0)
    && (*(_WORD *)(a1[7] + 552LL) & 0x104) == 0 )
  {
    return 0;
  }
  v12 = 8;
  if ( *(_DWORD *)(v2 + 116) )
    goto LABEL_16;
LABEL_19:
  v13 = *(_DWORD *)(v2 + 212) - *(_DWORD *)(v2 + 208);
  v14 = (char *)v4 - *(_QWORD *)(v2 + 216);
  if ( v13 < v12 || ((unsigned int)v14 & 0xFFFFFFF8) == 0 )
    goto LABEL_17;
  v15 = v6;
  v16 = v11;
  v17 = (_DWORD *)skb_put(v2, 8);
  v18 = v16[7];
  v19 = v17;
  if ( (*(_WORD *)(v18 + 552) & 0x100) != 0 )
  {
    *(_QWORD *)v17 = 0;
    return 0;
  }
  michael_mic((_DWORD *)(v18 + 572), v4, (int *)((char *)v4 + v15), v8, v17);
  if ( (*(_BYTE *)(v2 + 43) & 4) != 0 )
  {
    ++*v19;
    return 0;
  }
  return 0;
}
