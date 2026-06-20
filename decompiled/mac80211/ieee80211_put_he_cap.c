__int64 __fastcall ieee80211_put_he_cap(_DWORD *a1, __int64 a2, __int64 a3, __int64 *a4)
{
  int v4; // w8
  unsigned int v5; // w8
  __int64 v6; // x9
  __int64 v7; // x21
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x23
  unsigned int v11; // w8
  __int64 *v12; // x9
  __int64 v13; // x8
  unsigned int v14; // w9
  char v15; // w13
  unsigned int v16; // w25
  char v17; // w24
  int v18; // w26
  unsigned int v19; // w11
  char v20; // w27
  char v21; // w19
  char v22; // w28
  int v24; // w15
  char v25; // w14
  __int64 v26; // x12
  int v27; // w20
  unsigned int v28; // w8
  char v29; // w22
  char v30; // w27
  char v31; // w24
  char v32; // w26
  int v33; // w19
  char v34; // w0
  unsigned __int8 v35; // w8
  size_t v36; // x20
  char v37; // w28
  _DWORD *v38; // x22
  __int64 v39; // x0
  void *v40; // x0
  char v41; // w0
  size_t v42; // x20
  void *v43; // x0
  _DWORD *v44; // [xsp+0h] [xbp-30h]
  char v45; // [xsp+8h] [xbp-28h]
  int v46; // [xsp+8h] [xbp-28h]
  char v47; // [xsp+Ch] [xbp-24h]
  char v48; // [xsp+Ch] [xbp-24h]
  char v49; // [xsp+10h] [xbp-20h]
  _BYTE *v50; // [xsp+10h] [xbp-20h]
  __int64 v51; // [xsp+18h] [xbp-18h]
  int v52; // [xsp+20h] [xbp-10h]
  __int16 v53; // [xsp+24h] [xbp-Ch]

  _ReadStatusReg(SP_EL0);
  v4 = *(_DWORD *)(a2 + 4720);
  if ( *(_BYTE *)(a2 + 5848) != 1 )
    goto LABEL_6;
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      v5 = 9;
      v6 = *(unsigned __int16 *)(a3 + 92);
      if ( !*(_WORD *)(a3 + 92) )
        goto LABEL_28;
      goto LABEL_8;
    }
LABEL_6:
    v5 = (unsigned __int8)*(_DWORD *)(a2 + 4720);
    if ( v5 >= 0xC )
    {
      v11 = 0;
      __break(0x800u);
      goto LABEL_29;
    }
    v6 = *(unsigned __int16 *)(a3 + 92);
    if ( !*(_WORD *)(a3 + 92) )
      goto LABEL_28;
    goto LABEL_8;
  }
  v5 = 8;
  v6 = *(unsigned __int16 *)(a3 + 92);
  if ( !*(_WORD *)(a3 + 92) )
  {
LABEL_28:
    v11 = 0;
    goto LABEL_29;
  }
LABEL_8:
  v7 = *(_QWORD *)(a3 + 96);
  if ( v5 == 4 )
    LOBYTE(v5) = 3;
  v8 = v6 << 7;
  v9 = 1LL << v5;
  v10 = 0;
  while ( ((unsigned __int16)v9 & *(_WORD *)(v7 + v10)) == 0 )
  {
    v10 += 128;
    if ( v8 == v10 )
      goto LABEL_28;
  }
  if ( !(v7 + v10) )
    goto LABEL_28;
  v11 = 0;
  if ( v7 + v10 == -2 || (*(_BYTE *)(v7 + v10 + 2) & 1) == 0 )
    goto LABEL_29;
  v12 = &ieee80211_conn_settings_unlimited;
  if ( a4 )
    v12 = a4;
  v13 = v7 + v10;
  v14 = *((_DWORD *)v12 + 1);
  v15 = *(_BYTE *)(v7 + v10 + 17);
  v16 = *(unsigned __int8 *)(v7 + v10 + 9);
  v17 = *(_BYTE *)(v7 + v10 + 14);
  v18 = *(char *)(v7 + v10 + 15);
  v19 = v14 << 6;
  v52 = *(_DWORD *)(v7 + v10 + 3);
  v20 = *(_BYTE *)(v7 + v10 + 16);
  v21 = *(_BYTE *)(v7 + v10 + 18);
  if ( v14 >= 3 )
    v19 = 192;
  v53 = *(_WORD *)(v7 + v10 + 7);
  if ( v19 >= (v15 & 0xC0u) )
    v22 = v15 & 0xC0;
  else
    v22 = v19;
  if ( !v14 )
  {
    LOBYTE(v16) = v16 & 0xF9;
    v21 &= ~1u;
    goto LABEL_31;
  }
  if ( v14 <= 2 )
  {
LABEL_31:
    v17 &= 0xC7u;
    v20 &= 0x3Fu;
    v16 &= 0xE7u;
  }
  v24 = *(_DWORD *)(v13 + 10);
  v25 = *(_BYTE *)(v13 + 19);
  v26 = v7 + v10;
  if ( (v16 & 8) != 0 )
    v27 = 8;
  else
    v27 = 4;
  if ( (v18 & 0x80000000) == 0 )
  {
    v28 = 0;
    if ( !a1[29] )
      goto LABEL_39;
LABEL_40:
    v11 = -105;
    goto LABEL_29;
  }
  v29 = v20;
  v30 = *(_BYTE *)(v26 + 32);
  v44 = a1;
  v47 = *(_BYTE *)(v7 + v10 + 15);
  v49 = v17;
  v31 = *(_BYTE *)(v7 + v10 + 17);
  v45 = v21;
  v32 = *(_BYTE *)(v13 + 19);
  v33 = *(_DWORD *)(v13 + 10);
  v34 = _sw_hweight8(v30 & 0x78);
  v24 = v33;
  v25 = v32;
  v15 = v31;
  v21 = v45;
  LOBYTE(v18) = v47;
  v35 = v34 * (6 * (v30 & 7) + 6) + 7;
  v26 = v7 + v10;
  a1 = v44;
  v17 = v49;
  v20 = v29;
  v28 = ((unsigned int)v35 + 7) >> 3;
  if ( v44[29] )
    goto LABEL_40;
LABEL_39:
  v36 = v27 + ((v16 >> 2) & 4);
  if ( a1[53] - a1[52] < (int)(v36 + 20 + v28) )
    goto LABEL_40;
  v37 = v22 & 0xC0 | v15 & 0x3F;
  v38 = a1;
  v51 = v26;
  v46 = v24;
  v48 = v25;
  *(_BYTE *)skb_put(a1, 1) = -1;
  v50 = (_BYTE *)skb_put(v38, 1);
  *(_BYTE *)skb_put(v38, 1) = 35;
  v39 = skb_put(v38, 17);
  *(_BYTE *)(v39 + 6) = v16;
  *(_DWORD *)v39 = v52;
  *(_WORD *)(v39 + 4) = v53;
  *(_BYTE *)(v39 + 11) = v17;
  *(_BYTE *)(v39 + 12) = v18;
  *(_DWORD *)(v39 + 7) = v46;
  *(_BYTE *)(v39 + 13) = v20;
  *(_BYTE *)(v39 + 14) = v37;
  *(_BYTE *)(v39 + 15) = v21;
  *(_BYTE *)(v39 + 16) = v48;
  v40 = (void *)skb_put(v38, (unsigned int)v36);
  memcpy(v40, (const void *)(v7 + v10 + 20), v36);
  if ( *(char *)(v51 + 15) < 0 )
  {
    v41 = _sw_hweight8(*(_BYTE *)(v51 + 32) & 0x78);
    v42 = ((unsigned int)(unsigned __int8)(6 * (v41 + v41 * (*(_BYTE *)(v51 + 32) & 7)) + 7) + 7) >> 3;
    v43 = (void *)skb_put(v38, (unsigned int)v42);
    memcpy(v43, (const void *)(v51 + 32), v42);
  }
  v11 = 0;
  *v50 = *((_BYTE *)v38 + 216) + *((_BYTE *)v38 + 208) + ~(_BYTE)v50;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v11;
}
