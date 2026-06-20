__int64 __fastcall sta_info_insert_rcu(__int64 unlock, __int64 a2)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x19
  int v4; // w8
  int v5; // w9
  unsigned __int64 lock; // x0
  __int64 v7; // x8
  unsigned int v8; // w23
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x22
  __int64 v14; // x21
  __int64 v15; // x1
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x21
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x21
  int v21; // w9
  __int64 v22; // x0
  unsigned int v23; // w0
  __int64 v24; // x2
  unsigned __int64 *v25; // x1
  int v26; // w8
  int v27; // w24
  unsigned int v28; // w0
  int v29; // w25
  _QWORD *v30; // x8
  __int64 v31; // x9
  __int64 v32; // x0
  __int64 v33; // x1
  unsigned __int64 v41; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v47; // x10

  v2 = *(_QWORD *)(unlock + 80);
  v3 = unlock;
  if ( (*(_QWORD *)(v2 + 1632) & 1) == 0 )
  {
    v8 = -100;
    goto LABEL_11;
  }
  v4 = *(_DWORD *)(unlock + 2688);
  v5 = *(unsigned __int16 *)(unlock + 2692);
  if ( !(v4 | v5) || (v4 & 1) != 0 || !(*(_DWORD *)(v2 + 5842) ^ v4 | (unsigned __int16)(*(_WORD *)(v2 + 5846) ^ v5)) )
  {
    __break(0x800u);
    v8 = -22;
    goto LABEL_11;
  }
  lock = _rcu_read_lock(unlock, a2);
  v7 = *(_QWORD *)(v2 + 1616);
  if ( (*(_QWORD *)(v7 + 96) & 0x100000000LL) != 0 )
  {
    lock = rhltable_lookup((__int64 *)(v7 + 1632), (const void *)(v3 + 64), (__int64)&sta_rht_params);
    if ( lock )
    {
      if ( lock != -2640 && (*(_BYTE *)(lock + 156) & 1) != 0 )
      {
        unlock = _rcu_read_unlock(lock);
        v8 = -76;
LABEL_11:
        v9 = sta_info_free(unlock, v3);
        goto LABEL_60;
      }
    }
  }
  v11 = _rcu_read_unlock(lock);
  v12 = *(_QWORD *)(v3 + 72);
  v13 = *(_QWORD *)(v3 + 80);
  v14 = *(_QWORD *)(v13 + 1616);
  _rcu_read_lock(v11, v15);
  v16 = rhltable_lookup((__int64 *)(v14 + 1632), (const void *)(v3 + 2688), (__int64)&sta_rht_params);
  if ( v16 )
  {
    v17 = v16;
    while ( 1 )
    {
      v18 = *(_QWORD *)(v17 + 32);
      if ( v18 == v13 )
        break;
      v19 = *(_QWORD *)(v18 + 2032);
      if ( v19 )
      {
        if ( v19 == *(_QWORD *)(v13 + 2032) )
          break;
      }
      v17 = *(_QWORD *)(v17 + 8);
      if ( !v17 )
        goto LABEL_20;
    }
    _rcu_read_unlock(v16);
    if ( v17 != 48 )
    {
      v20 = 0;
      v8 = -17;
      goto LABEL_59;
    }
  }
  else
  {
LABEL_20:
    _rcu_read_unlock(v16);
  }
  v20 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 264);
  if ( !v20 )
  {
    v8 = -12;
    goto LABEL_59;
  }
  v21 = *(_DWORD *)(v12 + 1992) + 1;
  ++*(_QWORD *)(v12 + 1608);
  *(_DWORD *)(v12 + 1992) = v21;
  __dmb(0xBu);
  _X8 = (unsigned __int64 *)(v3 + 216);
  __asm { PRFM            #0x11, [X8] }
  do
    v41 = __ldxr(_X8);
  while ( __stxr(v41 | 0x100, _X8) );
  v22 = rhltable_insert(v12 + 1632, v3 + 48, &sta_rht_params);
  v8 = v22;
  if ( (_DWORD)v22 )
    goto LABEL_24;
  if ( *(_WORD *)(v3 + 2872) )
  {
    v23 = rhltable_insert(v12 + 1792, v3 + 1656, &link_sta_rht_params);
    if ( v23 )
    {
      v8 = v23;
      v22 = rhltable_remove(v12 + 1632, v3 + 48, &sta_rht_params);
      goto LABEL_24;
    }
  }
  v24 = v12 + 1616;
  v25 = *(unsigned __int64 **)(v12 + 1624);
  if ( v12 + 1616 == v3 || v25 == (unsigned __int64 *)v3 || *v25 != v24 )
  {
    _list_add_valid_or_report(v3, v25);
  }
  else
  {
    *(_QWORD *)v3 = v24;
    *(_QWORD *)(v3 + 8) = v25;
    atomic_store(v3, v25);
    *(_QWORD *)(v12 + 1624) = v3;
  }
  if ( *(_DWORD *)(v3 + 208) >= 3u )
  {
    ieee80211_recalc_min_chandef(*(_QWORD *)(v3 + 80), 0xFFFFFFFFLL);
    if ( (*(_BYTE *)(v3 + 2728) & 1) == 0 )
      ieee80211_recalc_p2p_go_ps_allowed(*(_QWORD *)(v3 + 80));
  }
  v26 = -1;
  do
  {
    v27 = v26 + 1;
    if ( (unsigned int)(v26 + 1) >= *(_DWORD *)(v3 + 208) )
    {
      if ( !*(_QWORD *)(*(_QWORD *)(v12 + 464) + 264LL) )
        *(_BYTE *)(v3 + 204) = 1;
LABEL_65:
      _X8 = (unsigned __int64 *)(v3 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v44 = __ldxr(_X8);
      while ( __stxr(v44 | 0x100000, _X8) );
      _X8 = (unsigned __int64 *)(v3 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v47 = __ldxr(_X8);
      while ( __stxr(v47 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
      *(_DWORD *)(v20 + 116) = *(_DWORD *)(v12 + 1992);
      cfg80211_new_sta(*(_QWORD *)(v13 + 1608), v3 + 2688, v20, 3264);
      v32 = kfree(v20);
      _rcu_read_lock(v32, v33);
      ieee80211_check_fast_xmit(v3);
      return 0;
    }
    v28 = drv_sta_state(v12, v13, v3, v27, v26 + 2);
    v26 = v27;
  }
  while ( !v28 );
  v8 = v28;
  if ( *(_DWORD *)(v13 + 4720) == 1 )
  {
    printk(&unk_BB6E1, v13 + 1640, v3 + 2688, (unsigned int)(v27 + 1));
    v8 = 0;
    if ( v27 )
    {
      do
      {
LABEL_40:
        while ( 1 )
        {
          v29 = v27 - 1;
          if ( (unsigned int)drv_sta_state(v12, v13, v3, v27, v27 - 1) )
            break;
          --v27;
          if ( !v29 )
            goto LABEL_48;
        }
        __break(0x800u);
        --v27;
      }
      while ( v29 );
    }
  }
  else if ( v27 )
  {
    goto LABEL_40;
  }
LABEL_48:
  if ( !v8 )
    goto LABEL_65;
  if ( *(_WORD *)(v3 + 2872) )
    rhltable_remove(v12 + 1792, v3 + 1656, &link_sta_rht_params);
  v22 = rhltable_remove(v12 + 1632, v3 + 48, &sta_rht_params);
  v30 = *(_QWORD **)(v3 + 8);
  if ( *v30 == v3 && (v31 = *(_QWORD *)v3, *(_QWORD *)(*(_QWORD *)v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v31 + 8) = v30;
    *v30 = v31;
  }
  else
  {
    v22 = _list_del_entry_valid_or_report(v3);
  }
  *(_QWORD *)(v3 + 8) = 0xDEAD000000000122LL;
LABEL_24:
  --*(_QWORD *)(v12 + 1608);
  synchronize_net(v22);
LABEL_59:
  cleanup_single_sta(v3);
  v9 = kfree(v20);
LABEL_60:
  _rcu_read_lock(v9, v10);
  return v8;
}
