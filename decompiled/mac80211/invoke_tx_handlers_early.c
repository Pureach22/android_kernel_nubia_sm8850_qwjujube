__int64 __fastcall invoke_tx_handlers_early(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v2; // x8
  __int64 v4; // x20
  int v5; // w23
  __int16 *v6; // x8
  __int64 v7; // x9
  int v8; // w10
  int v9; // w11
  __int64 v10; // x12
  __int64 v11; // x12
  int v12; // w9
  __int64 v13; // x9
  __int64 v14; // x21
  __int16 v15; // w8
  __int64 v16; // x20
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 v19; // x22
  unsigned int v20; // w24
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 result; // x0
  __int64 v25; // x21
  __int64 v26; // x21
  __int64 v27; // x0
  int v28; // w9
  __int64 v29; // x0
  __int64 v30; // x23
  __int64 v31; // x0
  __int64 v32; // x10
  int v33; // w9
  int v34; // w11
  __int64 v35; // x8
  __int64 v36; // x0

  v1 = a1[4];
  v2 = *a1;
  if ( (*(_QWORD *)(v1 + 96) & 0x100) != 0
    && (*(_QWORD *)(v1 + 96) & 0x400) == 0
    && *(int *)(v1 + 8) >= 1
    && !*(_QWORD *)(v1 + 4696) )
  {
    if ( *(_QWORD *)(v1 + 5008) )
    {
      if ( (*(_BYTE *)(v1 + 1468) & 1) == 0 )
      {
        v25 = a1[5];
        if ( *(_DWORD *)(v25 + 4720) == 2
          && (*(_BYTE *)(v2 + 41) & 0x20) == 0
          && ((*(_BYTE *)(v25 + 2500) & 0x80) == 0 || (*(_BYTE *)(v25 + 2516) & 1) == 0 || *(_WORD *)(v2 + 124)) )
        {
          if ( (*(_BYTE *)v1 & 2) != 0 )
          {
            ieee80211_stop_queues_by_reason(a1[4], 0xFFFF, 1, 0);
            *(_DWORD *)(v25 + 2500) &= ~0x100u;
            wiphy_work_queue(*(_QWORD *)(v1 + 72), v1 + 5040);
          }
          if ( (*(_BYTE *)(v25 + 2477) & 8) != 0 )
          {
            v26 = jiffies;
            v27 = _msecs_to_jiffies(*(unsigned int *)(v1 + 8));
            mod_timer(v1 + 5064, v27 + v26);
          }
        }
      }
    }
  }
  v4 = *a1;
  v5 = *(_DWORD *)(*a1 + 40);
  v6 = *(__int16 **)(*a1 + 224);
  if ( (v5 & 0x80) != 0 )
    goto LABEL_15;
  if ( (*(_QWORD *)(a1[4] + 4696) & 1) != 0
    && (*(_QWORD *)(a1[5] + 1632) & 2) != 0
    && (*v6 & 0xFC) != 0x40
    && (*v6 & 0x7C) != 0x48 )
  {
    goto LABEL_70;
  }
  v7 = a1[5];
  v8 = *(_DWORD *)(v7 + 4720);
  if ( v8 == 11 )
    goto LABEL_15;
  v9 = *((_DWORD *)a1 + 17);
  if ( (v9 & 4) != 0 )
    goto LABEL_15;
  v10 = a1[6];
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 216);
    if ( (v9 & 2) != 0 )
    {
      if ( (v11 & 2) != 0 )
        goto LABEL_15;
LABEL_14:
      if ( (*v6 & 0xC) == 8 )
        goto LABEL_70;
      goto LABEL_15;
    }
  }
  else if ( (v9 & 2) != 0 )
  {
    goto LABEL_14;
  }
  if ( (*v6 & 0xC) == 8 )
  {
    if ( v8 == 3 )
    {
      v32 = 2576;
    }
    else
    {
      if ( v8 != 4 || *(_QWORD *)(v7 + 2280) )
        goto LABEL_15;
      v32 = 2288;
    }
    if ( !*(_DWORD *)(v7 + v32) )
      goto LABEL_70;
  }
LABEL_15:
  v12 = *((_DWORD *)a1 + 17);
  if ( (v12 & 4) != 0 )
    goto LABEL_44;
  if ( (v12 & 2) == 0 )
  {
    v13 = a1[5];
    if ( (unsigned int)(*(_DWORD *)(v13 + 4720) - 3) <= 1 )
    {
      v14 = *(_QWORD *)(v13 + 2032);
      if ( v14 )
      {
        v15 = *v6;
        if ( (v15 & 0x8000) == 0 && (v15 & 0xFC) != 0x40 )
        {
          if ( (*(_QWORD *)(a1[4] + 96) & 0x40000) != 0 )
            *(_DWORD *)(v4 + 44) = *(_DWORD *)(v4 + 44) & 0xFFE1FFFF | ((*(_BYTE *)(v13 + 5849) & 0xF) << 17);
          if ( *(_DWORD *)(v14 + 296) || *(_QWORD *)(v14 + 272) != v14 + 272 )
          {
            *(_DWORD *)(v4 + 40) = v5 | 0x20;
            v16 = a1[4];
            if ( (*(_QWORD *)(v16 + 96) & 4) != 0 )
            {
              if ( *(int *)(v16 + 5000) >= 512 )
              {
                purge_old_ps_buffers(a1[4]);
                v16 = a1[4];
              }
              if ( *(_DWORD *)(v14 + 288) < 0x80u )
              {
                ++*(_DWORD *)(v16 + 5000);
              }
              else
              {
                v17 = skb_dequeue(v14 + 272);
                ieee80211_free_txskb(v16, v17);
              }
              skb_queue_tail(v14 + 272);
              return 0xFFFFFFFFLL;
            }
          }
        }
      }
    }
    goto LABEL_44;
  }
  v18 = a1[6];
  if ( !v18 )
  {
LABEL_44:
    v22 = *a1;
    v23 = a1[5];
    if ( *(unsigned __int16 *)(v23 + 1940) == *(unsigned __int16 *)(*a1 + 180) )
    {
      if ( *(_BYTE *)(v23 + 1942) )
        v28 = *(_DWORD *)(v22 + 40) | 0x10000;
      else
        v28 = *(_DWORD *)(v22 + 40);
      *(_DWORD *)(v22 + 80) |= 1u;
      *(_DWORD *)(v22 + 40) = v28 | 0x20000000;
    }
    result = ieee80211_tx_h_select_key(a1);
    if ( !(_DWORD)result )
      return result;
    v4 = *a1;
LABEL_70:
    v29 = a1[4];
    if ( v4 )
      ieee80211_free_txskb(v29, v4);
    else
      ieee80211_purge_tx_queue(v29, (__int64)(a1 + 1));
    return 0xFFFFFFFFLL;
  }
  v19 = a1[4];
  if ( (*(_QWORD *)(v18 + 216) & 4) != 0 || (*(_QWORD *)(v18 + 216) & 0x200) != 0 )
  {
    if ( (v5 & 0x20000) != 0 )
      goto LABEL_44;
  }
  else if ( (v5 & 0x20000) != 0 || (*(_QWORD *)(v18 + 216) & 0x2000000) == 0 )
  {
    goto LABEL_44;
  }
  v20 = *(unsigned __int16 *)(v4 + 124);
  if ( (*v6 & 0xC) == 0 && (ieee80211_is_bufferable_mmpdu(*a1) & 1) == 0 )
  {
    *(_DWORD *)(v4 + 40) = v5 | 0x20000;
    goto LABEL_44;
  }
  if ( *(int *)(v19 + 5000) >= 512 )
    purge_old_ps_buffers(v19);
  v21 = raw_spin_lock(v18 + 224);
  if ( (*(_QWORD *)(v18 + 216) & 4) == 0
    && (*(_QWORD *)(v18 + 216) & 0x200) == 0
    && (*(_QWORD *)(v18 + 216) & 0x2000000) == 0 )
  {
    raw_spin_unlock(v18 + 224);
    goto LABEL_44;
  }
  if ( v20 < 5 )
  {
    v30 = v18 + 24LL * v20;
    if ( *(_DWORD *)(v30 + 248) < 0x40u )
    {
      ++*(_DWORD *)(a1[4] + 5000);
    }
    else
    {
      v31 = skb_dequeue(v30 + 232);
      ieee80211_free_txskb(v19, v31);
    }
    v33 = *(_DWORD *)(v4 + 80);
    v34 = *(_DWORD *)(v4 + 40);
    *(_QWORD *)(v4 + 48) = jiffies;
    v35 = a1[5];
    *(_DWORD *)(v4 + 80) = v33 | 0x40;
    *(_QWORD *)(v4 + 64) = v35 + 4720;
    *(_DWORD *)(v4 + 40) = v34 & 0xEE39E083;
    skb_queue_tail(v30 + 232);
    raw_spin_unlock(v18 + 224);
    if ( !*(_QWORD *)(v19 + 1960) )
    {
      v36 = round_jiffies(jiffies + 2500LL);
      mod_timer(v19 + 1952, v36);
    }
    sta_info_recalc_tim(v18);
    return 0xFFFFFFFFLL;
  }
  __break(0x5512u);
  return ieee80211_is_bufferable_mmpdu(v21);
}
