__int64 __fastcall ieee80211_start_tx_ba_session(_BYTE *a1, unsigned __int16 a2, __int16 a3)
{
  __int64 v4; // x22
  _QWORD *v5; // x21
  int v6; // w10
  _QWORD *v7; // x10
  _BYTE *v9; // x20
  __int64 v12; // x22
  unsigned int v13; // w9
  unsigned int v14; // w19
  bool v15; // cf
  _BYTE *v16; // x9
  __int64 v17; // x0
  __int64 v18; // x9
  __int64 v19; // x19
  char v20; // w9

  v4 = *((_QWORD *)a1 - 326);
  v5 = *(_QWORD **)(v4 + 1616);
  if ( (unsigned __int8)*(a1 - 1356) == a2 )
  {
    _warn_printk("Requested to start BA session on reserved tid=%d", a2);
    __break(0x800u);
    return 4294967274LL;
  }
  if ( (a1[238] & 1) == 0 && (a1[260] & 1) == 0 && (a1[276] & 1) == 0 && a1[333] != 1 )
    return 4294967274LL;
  if ( !*(_QWORD *)(v5[58] + 384LL) )
  {
LABEL_31:
    __break(0x800u);
    return 4294967274LL;
  }
  if ( a2 > 0xFu || (v5[12] & 0x80) == 0 || (v5[12] & 0x200000) != 0 )
    return 4294967274LL;
  if ( a2 >= 8u )
    goto LABEL_31;
  v6 = *(_DWORD *)(v4 + 4720);
  if ( (unsigned int)(v6 - 1) >= 4 && v6 != 7 )
    return 4294967274LL;
  v7 = a1 - 2472;
  if ( (*((_QWORD *)a1 - 309) & 0x100) != 0 || (*v7 & 0x80) != 0 && (*v7 & 8) == 0 )
    return 4294967274LL;
  if ( *(_DWORD *)(*((_QWORD *)a1 - 326) + 4720LL) == 1 && !a1[238] )
    return 4294967274LL;
  v9 = a1 - 2540;
  raw_spin_lock_bh(a1 - 2540);
  v12 = a2;
  v13 = (unsigned __int8)a1[a2 - 1400];
  if ( v13 > 0xF || (v15 = v13 >= 4, v16 = &a1[8 * a2], v15) && jiffies - *((_QWORD *)v16 - 191) - 3750LL < 0 )
  {
    v14 = -16;
  }
  else if ( *((_QWORD *)v16 - 223) || *(_QWORD *)&a1[8 * a2 - 1656] )
  {
    v14 = -11;
  }
  else
  {
    v17 = _kmalloc_cache_noprof(init_timer_key, 2336, 160);
    if ( v17 )
    {
      v18 = *(_QWORD *)(v17 + 128);
      *(_WORD *)(v17 + 144) = a3;
      *(_QWORD *)(v17 + 96) = v17 + 96;
      *(_QWORD *)(v17 + 104) = v17 + 96;
      *(_QWORD *)(v17 + 112) = 0;
      *(_QWORD *)(v17 + 120) = a1 - 2688;
      *(_QWORD *)(v17 + 128) = v18 | 0x10;
      *(_BYTE *)(v17 + 158) = a2;
      v19 = v17;
      init_timer_key(v17 + 56, sta_addba_resp_timer_expired, 0, 0, 0);
      init_timer_key(v19 + 16, sta_tx_agg_session_timer_expired, 0x80000, 0, 0);
      v20 = *(a1 - 1384) + 1;
      *(a1 - 1384) = v20;
      *(_BYTE *)(v19 + 146) = v20;
      *(_QWORD *)&a1[8 * v12 - 1656] = v19;
      wiphy_work_queue(v5[9], a1 - 1808);
      v14 = 0;
    }
    else
    {
      v14 = -12;
    }
  }
  raw_spin_unlock_bh(v9);
  return v14;
}
