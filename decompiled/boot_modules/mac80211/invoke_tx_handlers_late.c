__int64 __fastcall invoke_tx_handlers_late(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  int v4; // w0
  __int64 v5; // x22
  int *v6; // x23
  int v7; // w24
  unsigned __int16 *v8; // x21
  int v9; // w20
  unsigned int v10; // w0
  int v11; // w8
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v17; // x8
  __int64 v18; // x20
  _QWORD *v19; // x27
  __int64 *v20; // x10
  unsigned __int16 *v21; // x8
  unsigned int v22; // w22
  int v23; // w9
  __int64 v24; // x21
  unsigned int v25; // w0
  int v26; // w8
  int v27; // w23
  unsigned int v28; // w10
  signed int v29; // w22
  __int64 v30; // x0
  __int64 *v31; // x8
  __int64 v32; // x26
  __int64 v33; // x9
  size_t v34; // x24
  __int64 v35; // x8
  __int64 v36; // x8
  int v37; // w10
  __int64 v38; // x11
  __int64 v39; // x12
  unsigned int v40; // w8
  const void *v41; // x25
  void *v42; // x0
  const void *v43; // x25
  void *v44; // x0
  _QWORD *v45; // x8
  int v46; // w9
  __int16 v47; // w13
  _WORD *v48; // x11
  int v49; // w12
  _QWORD *v50; // x8
  unsigned __int64 v51; // x9
  _QWORD *v52; // x8
  _QWORD *v53; // x10
  unsigned int v54; // [xsp+4h] [xbp-1Ch]
  int v55; // [xsp+14h] [xbp-Ch]
  unsigned int v56; // [xsp+18h] [xbp-8h]
  unsigned int v57; // [xsp+1Ch] [xbp-4h]

  v1 = *(_QWORD *)a1;
  if ( (*(_QWORD *)(*(_QWORD *)(a1 + 32) + 96LL) & 1) == 0 && (unsigned int)ieee80211_tx_h_rate_ctrl((__int64 *)a1) )
    goto LABEL_3;
  if ( (*(_BYTE *)(v1 + 42) & 8) != 0 )
  {
    v52 = *(_QWORD **)a1;
    v53 = *(_QWORD **)(a1 + 16);
    *v52 = a1 + 8;
    v52[1] = v53;
    *(_QWORD *)(a1 + 16) = v52;
    *v53 = v52;
    ++*(_DWORD *)(a1 + 24);
    *(_QWORD *)a1 = 0;
    return 0;
  }
  v4 = ieee80211_tx_h_michael_mic_add(a1);
  if ( v4 )
    goto LABEL_50;
  v5 = *(_QWORD *)a1;
  v6 = *(int **)(*(_QWORD *)a1 + 64LL);
  v7 = *v6;
  if ( *v6 != 6 )
  {
    v8 = *(unsigned __int16 **)(v5 + 224);
    v9 = *v8;
    if ( (v9 & 0xC) != 4 )
    {
      v10 = ieee80211_hdrlen(*v8);
      if ( (v9 & 0xFC) != 0xC8 && v10 >= 0x18 )
      {
        v11 = *(_DWORD *)(v5 + 80);
        if ( (v11 & 0x80) == 0 )
        {
          if ( (v8[2] & 1) != 0 )
          {
            if ( v7 == 3 && *((_WORD *)v6 + 540) )
            {
              if ( (v11 & 0x200) != 0 )
                *(_WORD *)(*(_QWORD *)(a1 + 40) + 1938LL) += 16;
              v8[11] = *(_WORD *)(*(_QWORD *)(a1 + 40) + 1938LL);
              goto LABEL_24;
            }
          }
          else if ( (v9 & 0x8C) == 0x88 )
          {
            v12 = *(_QWORD *)(a1 + 48);
            if ( v12 )
            {
              v13 = 12;
              if ( (~v9 & 0x300) == 0 )
                v13 = 15;
              v14 = v8[v13] & 0xF;
              ++*(_QWORD *)(v12 + 8 * v14 + 2416);
              v15 = *(_QWORD *)(a1 + 48) + 2 * v14;
              LOWORD(v14) = *(_WORD *)(v15 + 490);
              *(_WORD *)(v15 + 490) = (v14 & 0xFFF0) + 16;
              v8[11] = v14;
            }
            goto LABEL_24;
          }
          *(_DWORD *)(v5 + 40) |= 2u;
          v8[11] = *(_WORD *)(*(_QWORD *)(a1 + 40) + 1936LL);
          *(_WORD *)(*(_QWORD *)(a1 + 40) + 1936LL) += 16;
          v17 = *(_QWORD *)(a1 + 48);
          if ( v17 )
            ++*(_QWORD *)(v17 + 2544);
        }
      }
    }
  }
LABEL_24:
  v18 = *(_QWORD *)a1;
  v19 = (_QWORD *)(a1 + 8);
  v20 = *(__int64 **)(a1 + 16);
  v21 = *(unsigned __int16 **)(*(_QWORD *)a1 + 224LL);
  v22 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 72LL) + 200LL);
  *(_QWORD *)v18 = a1 + 8;
  *(_QWORD *)(v18 + 8) = v20;
  *(_QWORD *)(a1 + 16) = v18;
  *v20 = v18;
  ++*(_DWORD *)(a1 + 24);
  *(_QWORD *)a1 = 0;
  v23 = *(_DWORD *)(v18 + 40);
  if ( (v23 & 0x40000000) == 0 )
  {
    v24 = *(_QWORD *)(a1 + 32);
    if ( (*(_QWORD *)(v24 + 96) & 0x4000000000LL) == 0 )
    {
      if ( (v23 & 0x40) != 0
        || (v25 = ieee80211_hdrlen(*v21), v26 = *(_DWORD *)(v18 + 112), v57 = v25, v26 + 4 <= v22)
        || (v27 = v26 - (v22 - 4), v54 = v22 - 4, v27 < 0) )
      {
        __break(0x800u);
        goto LABEL_3;
      }
      if ( v27 )
      {
        v55 = v54 - v25;
        v28 = v22 + 26;
        v29 = v22 - 4;
        v56 = v28;
        do
        {
          v30 = _netdev_alloc_skb(0, v56 + *(_DWORD *)(v24 + 1508), 2080);
          if ( !v30 )
            goto LABEL_3;
          v31 = *(__int64 **)(a1 + 16);
          *(_QWORD *)v30 = v19;
          v32 = v30;
          *(_QWORD *)(v30 + 8) = v31;
          *(_QWORD *)(a1 + 16) = v30;
          *v31 = v30;
          ++*(_DWORD *)(a1 + 24);
          LODWORD(v31) = *(_DWORD *)(v24 + 1508) + 8;
          v33 = *(_QWORD *)(v30 + 224) + (int)v31;
          *(_DWORD *)(v30 + 208) += (_DWORD)v31;
          if ( v55 >= v27 )
            v34 = (unsigned int)v27;
          else
            v34 = (unsigned int)v55;
          *(_QWORD *)(v30 + 224) = v33;
          v27 -= v34;
          v35 = *(_QWORD *)(v18 + 48);
          *(_QWORD *)(v30 + 40) = *(_QWORD *)(v18 + 40);
          *(_QWORD *)(v30 + 48) = v35;
          v36 = *(_QWORD *)(v18 + 80);
          v37 = *(_DWORD *)(v30 + 40);
          v38 = *(_QWORD *)(v18 + 56);
          v39 = *(_QWORD *)(v18 + 64);
          *(_QWORD *)(v30 + 72) = *(_QWORD *)(v18 + 72);
          *(_QWORD *)(v30 + 80) = v36;
          v40 = v37 & 0xFFFFFFE7;
          *(_QWORD *)(v30 + 56) = v38;
          *(_QWORD *)(v30 + 64) = v39;
          if ( v27 )
            v40 = v37 & 0xFFFBFFE7 | 0x40000;
          *(_DWORD *)(v30 + 40) = v40;
          *(_WORD *)(v30 + 124) = *(_WORD *)(v18 + 124);
          *(_DWORD *)(v30 + 144) = *(_DWORD *)(v18 + 144);
          *(_QWORD *)(v30 + 16) = *(_QWORD *)(v18 + 16);
          v41 = *(const void **)(v18 + 224);
          v42 = (void *)skb_put(v30, v57);
          memcpy(v42, v41, v57);
          v43 = (const void *)(*(_QWORD *)(v18 + 224) + v29);
          v44 = (void *)skb_put(v32, (unsigned int)v34);
          memcpy(v44, v43, v34);
          v29 += v34;
        }
        while ( v27 );
      }
      skb_trim(v18, v54);
      v45 = (_QWORD *)*v19;
      if ( (_QWORD *)*v19 != v19 )
      {
        v46 = 0;
        do
        {
          v48 = (_WORD *)v45[28];
          if ( (_QWORD *)*v45 == v19 )
          {
            *v48 &= ~0x400u;
          }
          else
          {
            *v48 |= 0x400u;
            v49 = *((_DWORD *)v45 + 10);
            *((_BYTE *)v45 + 51) = -1;
            *((_BYTE *)v45 + 54) = -1;
            *((_BYTE *)v45 + 57) = -1;
            *((_DWORD *)v45 + 10) = v49 & 0xFFFFEFFF;
          }
          v47 = v46++ & 0xF;
          v48[11] |= v47;
          v45 = (_QWORD *)*v45;
        }
        while ( v45 != v19 );
      }
    }
  }
  if ( *(_QWORD *)(a1 + 48) )
  {
    v50 = (_QWORD *)*v19;
    if ( (_QWORD *)*v19 != v19 )
    {
      do
      {
        v51 = *((unsigned __int16 *)v50 + 62);
        if ( v51 >= 4 )
        {
          __break(0x5512u);
          JUMPOUT(0xA5904);
        }
        *(_QWORD *)(*(_QWORD *)(a1 + 48) + 8 * v51 + 2360) += *((unsigned int *)v50 + 28);
        v50 = (_QWORD *)*v50;
      }
      while ( v50 != v19 );
      ++*(_QWORD *)(*(_QWORD *)(a1 + 48) + 8 * v51 + 2328);
    }
  }
  v4 = ieee80211_tx_h_encrypt(a1);
  if ( !v4 )
  {
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 32) + 96LL) & 1) == 0 )
      ieee80211_tx_h_calculate_duration(a1);
    return 0;
  }
LABEL_50:
  if ( v4 == 2 )
    return 0xFFFFFFFFLL;
  if ( v4 == 1 )
  {
LABEL_3:
    v3 = *(_QWORD *)(a1 + 32);
    if ( *(_QWORD *)a1 )
      ieee80211_free_txskb(v3, *(_QWORD *)a1);
    else
      ieee80211_purge_tx_queue(v3, a1 + 8);
    return 0xFFFFFFFFLL;
  }
  return 0;
}
