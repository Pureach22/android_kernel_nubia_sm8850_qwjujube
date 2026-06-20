__int64 __fastcall ieee80211_send_addba_with_timeout(__int64 result, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x20
  __int64 v6; // x23
  __int16 v7; // w25
  __int64 v8; // x24
  char v9; // w28
  __int16 v10; // w26
  __int16 v11; // w27
  __int64 v12; // x8
  __int64 v13; // x22
  __int64 v14; // x9
  __int64 v15; // x0
  __int64 v16; // x24
  int v17; // w8
  _WORD *v18; // x8
  unsigned __int64 v25; // x8

  v3 = *(_QWORD *)(result + 72);
  v2 = *(_QWORD *)(result + 80);
  v4 = *(unsigned __int8 *)(a2 + 158);
  if ( (*(_QWORD *)(a2 + 128) & 8) != 0 || (*(_QWORD *)(a2 + 128) & 0x20) != 0 )
    goto LABEL_25;
  v6 = result;
  mod_timer(a2 + 56, jiffies + 250LL);
  result = raw_spin_lock_bh(v6 + 148);
  if ( (unsigned int)v4 >= 0x10 )
  {
    __break(0x5512u);
  }
  else
  {
    *(_QWORD *)(v6 + 8 * v4 + 1160) = jiffies;
    ++*(_BYTE *)(v6 + v4 + 1288);
    raw_spin_unlock_bh(v6 + 148);
    if ( *(_BYTE *)(v6 + 2964) == 1 )
      v7 = *(_WORD *)(v3 + 138) << 6;
    else
      v7 = 4096;
    v8 = *(_QWORD *)(v2 + 1616);
    v9 = *(_BYTE *)(a2 + 146);
    v10 = *(_WORD *)(a2 + 152);
    v11 = *(_WORD *)(a2 + 144);
    result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v8 + 104) + 50), 2080);
    if ( result )
    {
      v12 = *(int *)(v8 + 104);
      v13 = result;
      v14 = *(_QWORD *)(result + 224) + v12;
      LODWORD(v12) = *(_DWORD *)(result + 208) + v12;
      *(_QWORD *)(result + 224) = v14;
      *(_DWORD *)(result + 208) = v12;
      v15 = skb_put(result, 24);
      *(_QWORD *)v15 = 0;
      *(_QWORD *)(v15 + 8) = 0;
      v16 = v15;
      *(_QWORD *)(v15 + 16) = 0;
      *(_DWORD *)(v15 + 4) = *(_DWORD *)(v6 + 2688);
      *(_WORD *)(v15 + 8) = *(_WORD *)(v6 + 2692);
      *(_DWORD *)(v15 + 10) = *(_DWORD *)(v2 + 5842);
      *(_WORD *)(v15 + 14) = *(_WORD *)(v2 + 5846);
      v17 = *(_DWORD *)(v2 + 4720);
      if ( v17 <= 2 )
      {
        if ( v17 == 1 )
        {
          *(_DWORD *)(v15 + 16) = *(_DWORD *)(v2 + 2346);
          v18 = (_WORD *)(v2 + 2350);
        }
        else
        {
          if ( v17 != 2 )
          {
LABEL_18:
            *(_WORD *)v15 = 208;
            skb_put(v13, 9);
            *(_BYTE *)(v16 + 26) = v9;
            *(_WORD *)(v16 + 29) = v11;
            *(_WORD *)(v16 + 24) = 3;
            *(_WORD *)(v16 + 27) = v7 | (4 * (v4 & 0x3F)) | 3;
            *(_WORD *)(v16 + 31) = 16 * v10;
            result = ieee80211_tx_skb_tid(v2, v13, (unsigned int)v4, 0xFFFFFFFFLL);
            goto LABEL_22;
          }
          *(_DWORD *)(v15 + 16) = *(_DWORD *)(v2 + 4802);
          v18 = (_WORD *)(v2 + 4806);
        }
      }
      else
      {
        if ( (unsigned int)(v17 - 3) >= 2 && v17 != 7 )
          goto LABEL_18;
        v18 = (_WORD *)(v2 + 5846);
        *(_DWORD *)(v15 + 16) = *(_DWORD *)(v2 + 5842);
      }
      *(_WORD *)(v15 + 20) = *v18;
      goto LABEL_18;
    }
  }
LABEL_22:
  _X9 = (unsigned __int64 *)(a2 + 128);
  __asm { PRFM            #0x11, [X9] }
  do
    v25 = __ldxr(_X9);
  while ( __stlxr(v25 | 0x100, _X9) );
  __dmb(0xBu);
  if ( (v25 & 0x100) != 0 )
LABEL_25:
    __break(0x800u);
  return result;
}
