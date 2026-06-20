__int64 __fastcall ieee80211_put_eht_cap(_DWORD *a1, __int64 a2, __int64 a3, __int64 *a4)
{
  int v4; // w8
  int v6; // w10
  unsigned int v7; // w12
  __int64 v8; // x11
  _BYTE *v9; // x9
  char v10; // w9
  __int64 v11; // x12
  int v12; // w10
  __int64 v13; // x11
  char v14; // w12
  __int64 v15; // x10
  __int64 v16; // x12
  __int64 v17; // x10
  int v18; // t1
  __int64 v19; // x20
  __int64 result; // x0
  int v21; // w9
  __int64 *v22; // x10
  int v23; // w11
  _BOOL4 v24; // w11
  unsigned int v25; // w10
  char v26; // w11
  char v27; // w11
  char v28; // w0
  __int16 v29; // w26
  __int16 v30; // w16
  __int16 v31; // w28
  char v32; // w10
  char v33; // w19
  char v34; // w22
  char v35; // w27
  unsigned __int8 v36; // w24
  int v37; // w9
  char v38; // w8
  __int16 v39; // w22
  unsigned int v40; // w23
  unsigned __int8 v41; // w23
  __int64 v42; // x0
  _BOOL4 v43; // w8
  char v44; // w21
  char v45; // w21
  char v46; // w21
  char v47; // w21
  void *v48; // x0
  void *v49; // x0
  char v50; // [xsp+0h] [xbp-10h]
  char v51; // [xsp+4h] [xbp-Ch]
  char v52; // [xsp+8h] [xbp-8h]
  _BOOL4 v53; // [xsp+Ch] [xbp-4h]

  v4 = *(_DWORD *)(a2 + 4720);
  v6 = *(unsigned __int8 *)(a2 + 5848);
  if ( v6 == 1 )
  {
    if ( v4 == 2 )
    {
      v7 = 8;
      v8 = *(unsigned __int16 *)(a3 + 92);
      if ( !*(_WORD *)(a3 + 92) )
        goto LABEL_5;
      goto LABEL_8;
    }
    if ( v4 == 3 )
    {
      v7 = 9;
      v8 = *(unsigned __int16 *)(a3 + 92);
      if ( !*(_WORD *)(a3 + 92) )
      {
LABEL_5:
        v9 = nullptr;
LABEL_17:
        if ( !*(_BYTE *)(a2 + 5848) )
          goto LABEL_29;
        goto LABEL_24;
      }
      goto LABEL_8;
    }
  }
  v7 = (unsigned __int8)*(_DWORD *)(a2 + 4720);
  if ( v7 >= 0xC )
  {
    __break(0x800u);
    v4 = *(_DWORD *)(a2 + 4720);
    v9 = nullptr;
    if ( (*(_BYTE *)(a2 + 5848) & 1) == 0 )
      goto LABEL_29;
    goto LABEL_24;
  }
  v8 = *(unsigned __int16 *)(a3 + 92);
  if ( !*(_WORD *)(a3 + 92) )
    goto LABEL_5;
LABEL_8:
  if ( v7 == 4 )
    v10 = 3;
  else
    v10 = v7;
  v11 = 1LL << v10;
  v9 = (_BYTE *)(*(_QWORD *)(a3 + 96) + 2LL);
  while ( ((unsigned __int16)v11 & *((_WORD *)v9 - 1)) == 0 )
  {
    --v8;
    v9 += 128;
    if ( !v8 )
      goto LABEL_19;
  }
  if ( v9 != byte_2 )
  {
    if ( (*v9 & 1) != 0 )
      goto LABEL_17;
LABEL_19:
    v9 = nullptr;
    if ( (v6 & 1) != 0 )
      goto LABEL_24;
    goto LABEL_29;
  }
  v9 = nullptr;
  if ( !*(_BYTE *)(a2 + 5848) )
    goto LABEL_29;
LABEL_24:
  if ( v4 == 2 )
  {
    v12 = 8;
    goto LABEL_30;
  }
  if ( v4 == 3 )
  {
    v12 = 9;
    goto LABEL_30;
  }
LABEL_29:
  v12 = (unsigned __int8)v4;
  if ( (unsigned __int8)v4 >= 0xCu )
  {
    __break(0x800u);
    v4 = *(_DWORD *)(a2 + 4720);
    goto LABEL_45;
  }
LABEL_30:
  v13 = *(unsigned __int16 *)(a3 + 92);
  if ( !*(_WORD *)(a3 + 92) )
    goto LABEL_45;
  v14 = v12 == 4 ? 3 : v12;
  v15 = *(_QWORD *)(a3 + 96);
  v16 = 1LL << v14;
  while ( ((unsigned __int16)v16 & *(_WORD *)v15) == 0 )
  {
    --v13;
    v15 += 128;
    if ( !v13 )
      goto LABEL_45;
  }
  if ( !v15 )
  {
LABEL_45:
    v19 = 0;
    result = 0;
    if ( !v9 )
      return result;
LABEL_46:
    if ( !v19 )
      return result;
    v21 = (unsigned __int8)v9[7];
    v22 = &ieee80211_conn_settings_unlimited;
    if ( a4 )
      v22 = a4;
    if ( (v21 & 2) != 0 )
    {
      v24 = 1;
    }
    else
    {
      v23 = (v21 << 29 >> 31) & 3;
      if ( (v21 & 8) != 0 )
        v23 += 3;
      if ( (*(_BYTE *)(v19 + 3) & 2) != 0 )
        v23 += 3;
      if ( v23 )
        v24 = v23 != 4;
      else
        v24 = v4 == 3;
    }
    v25 = *((_DWORD *)v22 + 1);
    v53 = v24;
    if ( v25 )
    {
      if ( v25 == 2 )
      {
        v27 = *(_BYTE *)(v19 + 9);
        v21 &= 0xFFFFFFE7;
LABEL_65:
        v28 = *(_BYTE *)(v19 + 8);
        v29 = *(_WORD *)(v19 + 10);
        v30 = *(_WORD *)(v19 + 6);
        v31 = *(_WORD *)(v19 + 1);
        v52 = *(_BYTE *)(v19 + 4) & 3;
        if ( v25 )
          v32 = -3;
        else
          v32 = -7;
        v33 = *(_BYTE *)(v19 + 5) & 7;
        v34 = v27 & 0x8F;
        v35 = *(_BYTE *)(v19 + 3) & v32;
LABEL_69:
        v36 = 3;
        if ( (v21 & 2) == 0 )
        {
          if ( (v21 & 8) != 0 )
            v37 = ((v21 << 29 >> 31) & 3) + 3;
          else
            v37 = (v21 << 29 >> 31) & 3;
          if ( (v35 & 2) != 0 )
            v37 += 3;
          if ( v4 == 3 )
            v38 = 3;
          else
            v38 = 4;
          if ( v37 )
            v36 = v37;
          else
            v36 = v38;
        }
        v50 = v34;
        v51 = v28;
        v39 = v30;
        if ( (v28 & 8) != 0 )
        {
          v41 = *(_BYTE *)(v19 + 21);
          v40 = ((unsigned int)_sw_hweight16(v41 & 0xF0) * (6 * (v41 & 0xF) + 6) + 16) >> 3;
        }
        else
        {
          LOBYTE(v40) = 0;
        }
        if ( a1[29] )
        {
          if ( v36 + (_BYTE)v40 != 0xF2 )
            return 4294967191LL;
        }
        else if ( a1[53] - a1[52] < (unsigned __int8)(v36 + v40 + 14) )
        {
          return 4294967191LL;
        }
        *(_BYTE *)skb_put(a1, 1) = -1;
        *(_BYTE *)skb_put(a1, 1) = v36 + v40 + 12;
        *(_BYTE *)skb_put(a1, 1) = 108;
        v42 = skb_put(a1, 11);
        *(_WORD *)v42 = v31;
        *(_BYTE *)(v42 + 2) = v35;
        *(_BYTE *)(v42 + 7) = v51;
        v43 = v53;
        *(_BYTE *)(v42 + 3) = v52;
        if ( v36 != 4 )
          v43 = 0;
        *(_BYTE *)(v42 + 4) = v33;
        *(_WORD *)(v42 + 5) = v39;
        *(_BYTE *)(v42 + 8) = v50;
        *(_WORD *)(v42 + 9) = v29;
        if ( v43 )
        {
          v44 = *(_BYTE *)(v19 + 12);
          *(_BYTE *)skb_put(a1, 1) = v44;
          v45 = *(_BYTE *)(v19 + 12);
          *(_BYTE *)skb_put(a1, 1) = v45;
          v46 = *(_BYTE *)(v19 + 13);
          *(_BYTE *)skb_put(a1, 1) = v46;
          v47 = *(_BYTE *)(v19 + 14);
          *(_BYTE *)skb_put(a1, 1) = v47;
          if ( !(_BYTE)v40 )
            return 0;
        }
        else
        {
          v48 = (void *)skb_put(a1, v36);
          memcpy(v48, (const void *)(v19 + 12), v36);
          if ( !(_BYTE)v40 )
            return 0;
        }
        v49 = (void *)skb_put(a1, (unsigned __int8)v40);
        memcpy(v49, (const void *)(v19 + 21), (unsigned __int8)v40);
        return 0;
      }
      if ( v25 != 1 )
      {
        v31 = *(_WORD *)(v19 + 1);
        v35 = *(_BYTE *)(v19 + 3);
        v33 = *(_BYTE *)(v19 + 5);
        v30 = *(_WORD *)(v19 + 6);
        v28 = *(_BYTE *)(v19 + 8);
        v34 = *(_BYTE *)(v19 + 9);
        v29 = *(_WORD *)(v19 + 10);
        if ( v25 > 3 )
        {
          v52 = *(_BYTE *)(v19 + 4);
        }
        else
        {
          v35 &= ~2u;
          v33 &= 0x3Fu;
          v52 = *(_BYTE *)(v19 + 4) & 0x1F;
          v34 &= ~0x40u;
        }
        goto LABEL_69;
      }
      v26 = *(_BYTE *)(v19 + 9);
      v21 &= 0xFFFFFFE7;
    }
    else
    {
      v26 = *(_BYTE *)(v19 + 9);
      v21 = 0;
    }
    v27 = v26 & 0xF7;
    goto LABEL_65;
  }
  v18 = *(unsigned __int8 *)(v15 + 59);
  v17 = v15 + 59;
  if ( v18 )
    v19 = v17;
  else
    v19 = 0;
  result = 0;
  if ( v9 )
    goto LABEL_46;
  return result;
}
