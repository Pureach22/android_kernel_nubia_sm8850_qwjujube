__int64 __fastcall ieee80211_do_stop(__int64 a1, char a2)
{
  __int64 v4; // x19
  __int64 v5; // x23
  int v6; // w8
  _QWORD *v7; // x8
  __int64 v8; // x0
  __int64 v9; // x9
  int *v10; // x24
  int v11; // w0
  __int64 v12; // x8
  unsigned __int64 StatusReg; // x9
  int v14; // w8
  __int64 v15; // x22
  unsigned int vif_queues; // w0
  __int64 v17; // x9
  int v18; // w11
  __int64 v19; // x10
  __int64 v20; // x8
  __int64 v21; // x25
  __int64 v22; // x0
  _QWORD *v23; // x1
  __int64 v24; // x22
  int v25; // w8
  int v26; // w8
  unsigned int v27; // w22
  _QWORD *v28; // x27
  _QWORD *v29; // x8
  _QWORD *v30; // x9
  __int64 next; // x0
  __int64 v32; // x22
  _QWORD *v33; // x8
  __int64 v34; // x0
  __int64 v35; // x9
  __int64 v36; // x1
  unsigned __int64 v37; // x9
  __int64 v38; // x11
  _QWORD *v39; // x12
  _QWORD *v40; // x13
  _QWORD *v41; // x14
  _QWORD *v42; // x15
  _QWORD *v43; // x14
  __int64 result; // x0
  _QWORD *v45; // x1
  _QWORD *v46; // x26
  _QWORD *v47; // x8
  _QWORD *v48; // x9
  _BOOL4 v49; // w8
  _BOOL4 v50; // w9
  unsigned int v51; // w8
  int v52; // w9
  _DWORD *v53; // x8
  int v54; // w11
  unsigned __int64 v61; // x10
  unsigned int v64; // w10
  __int64 v65; // [xsp+8h] [xbp-48h] BYREF
  __int64 v66; // [xsp+10h] [xbp-40h]
  __int64 v67; // [xsp+18h] [xbp-38h]
  __int64 v68; // [xsp+20h] [xbp-30h]
  int v69; // [xsp+2Ch] [xbp-24h] BYREF
  _QWORD *v70; // [xsp+30h] [xbp-20h] BYREF
  _QWORD **v71; // [xsp+38h] [xbp-18h]
  __int64 v72; // [xsp+40h] [xbp-10h]
  __int64 v73; // [xsp+48h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 1616);
  v71 = nullptr;
  v72 = 0;
  v70 = nullptr;
  v69 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  _X8 = (unsigned __int64 *)(a1 + 1632);
  __asm { PRFM            #0x11, [X8] }
  do
    v61 = __ldxr(_X8);
  while ( __stxr(v61 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  synchronize_rcu(a1);
  v5 = *(_QWORD *)(v4 + 4968);
  if ( v5 == a1 )
    ieee80211_scan_cancel(v4);
  ieee80211_roc_purge(v4, a1);
  v6 = *(_DWORD *)(a1 + 4720);
  switch ( v6 )
  {
    case 1:
      ieee80211_ibss_stop(a1);
      break;
    case 6:
      if ( (*(_BYTE *)(a1 + 2264) & 0x20) == 0 )
      {
        v7 = *(_QWORD **)(a1 + 2288);
        v8 = a1 + 2280;
        if ( *v7 == a1 + 2280 && (v9 = *(_QWORD *)v8, *(_QWORD *)(*(_QWORD *)v8 + 8LL) == v8) )
        {
          *(_QWORD *)(v9 + 8) = v7;
          *v7 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
        }
        *(_QWORD *)(a1 + 2288) = 0xDEAD000000000122LL;
      }
      break;
    case 2:
      ieee80211_mgd_stop(a1);
      break;
  }
  v10 = (int *)(a1 + 4720);
  v11 = _sta_info_flush(a1, 0, 0xFFFFFFFFLL);
  if ( *(_DWORD *)(a1 + 4720) == 4 || v11 < 1 )
  {
    if ( (*(_BYTE *)(a1 + 1624) & 1) == 0 )
      goto LABEL_18;
  }
  else
  {
    __break(0x800u);
    if ( (*(_BYTE *)(a1 + 1624) & 1) == 0 )
      goto LABEL_18;
  }
  _X8 = (unsigned int *)(v4 + 2528);
  __asm { PRFM            #0x11, [X8] }
  do
    v64 = __ldxr(_X8);
  while ( __stxr(v64 - 1, _X8) );
LABEL_18:
  if ( *v10 != 1 )
  {
    if ( *v10 != 3 )
      goto LABEL_22;
    --*(_DWORD *)(v4 + 1344);
  }
  --*(_DWORD *)(v4 + 1348);
LABEL_22:
  v12 = *(_QWORD *)(a1 + 1608);
  if ( v12 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)(StatusReg + 16) += 512;
    raw_spin_lock(v12 + 844);
    raw_spin_lock_bh(v4 + 1404);
    _hw_addr_unsync(v4 + 1432, *(_QWORD *)(a1 + 1608) + 880LL, *(unsigned __int8 *)(*(_QWORD *)(a1 + 1608) + 824LL));
    raw_spin_unlock_bh(v4 + 1404);
    raw_spin_unlock_bh(*(_QWORD *)(a1 + 1608) + 844LL);
  }
  timer_delete_sync(v4 + 5064);
  wiphy_work_cancel(*(_QWORD *)(v4 + 72), v4 + 5016);
  if ( *(_WORD *)(a1 + 5800) )
  {
    _warn_printk("destroying interface with valid links 0x%04x\n", *(unsigned __int16 *)(a1 + 5800));
    __break(0x800u);
  }
  v14 = *(_DWORD *)(a1 + 4720);
  *(_BYTE *)(a1 + 5638) = 0;
  if ( v14 == 2 )
    *(_BYTE *)(a1 + 4400) = 0;
  v15 = *(_QWORD *)(a1 + 1616);
  vif_queues = ieee80211_get_vif_queues(v15, a1);
  ieee80211_wake_queues_by_reason(v15, vif_queues, 2, 0);
  wiphy_work_cancel(*(_QWORD *)(v4 + 72), a1 + 3760);
  wiphy_work_cancel(*(_QWORD *)(v4 + 72), a1 + 3848);
  wiphy_delayed_work_cancel(*(_QWORD *)(v4 + 72), a1 + 4080);
  if ( *(_BYTE *)(a1 + 456) == 1 )
  {
    v17 = *(_QWORD *)(a1 + 4952);
    v18 = *(unsigned __int8 *)(v4 + 1465);
    v19 = *(_QWORD *)(a1 + 4960);
    v65 = *(_QWORD *)(a1 + 4944);
    v66 = v17;
    v20 = *(_QWORD *)(a1 + 4968);
    v67 = v19;
    v68 = v20;
    if ( v18 == 1 )
      __break(0x800u);
    ieee80211_link_release_channel((__int64 *)(a1 + 3616));
    cfg80211_cac_event(*(_QWORD *)(a1 + 1608), &v65, 2, 3264, 0);
  }
  if ( *v10 == 4 )
  {
    v21 = *(_QWORD *)(a1 + 2032);
    v22 = raw_spin_lock_irqsave(v21 + 292);
    v23 = *(_QWORD **)(v21 + 272);
    v24 = v22;
    if ( v23 != (_QWORD *)(v21 + 272) )
    {
      do
      {
        v28 = (_QWORD *)*v23;
        if ( v23[2] == *(_QWORD *)(a1 + 1608) )
        {
          --*(_DWORD *)(v21 + 288);
          v29 = (_QWORD *)*v23;
          v30 = (_QWORD *)v23[1];
          *v23 = 0;
          v23[1] = 0;
          v29[1] = v30;
          *v30 = v29;
          --*(_DWORD *)(v4 + 5000);
          ieee80211_free_txskb(v4);
        }
        v23 = v28;
      }
      while ( v28 != (_QWORD *)(v21 + 272) );
    }
    raw_spin_unlock_irqrestore(v21 + 292, v24);
  }
  else if ( *v10 == 3 && *(_QWORD *)(a1 + 2264) != a1 + 2264 )
  {
    __break(0x800u);
  }
  if ( (a2 & 1) != 0 )
    --*(_DWORD *)(v4 + 1316);
  v25 = *v10;
  if ( *v10 > 9 )
  {
    if ( v25 == 10 )
    {
      *(_QWORD *)(v4 + 5376) = 0;
    }
    else if ( v25 == 12 )
    {
      raw_spin_lock_bh(a1 + 2268);
      v69 = 0;
      next = idr_get_next(a1 + 2272, &v69);
      if ( next )
      {
        v32 = next;
        do
        {
          idr_remove(a1 + 2272, v69);
          cfg80211_free_nan_func(v32);
          ++v69;
          v32 = idr_get_next(a1 + 2272, &v69);
        }
        while ( v32 );
      }
      idr_destroy(a1 + 2272);
      raw_spin_unlock_bh(a1 + 2268);
      goto LABEL_61;
    }
    goto LABEL_60;
  }
  if ( v25 == 4 )
  {
    v33 = *(_QWORD **)(a1 + 2272);
    v34 = a1 + 2264;
    if ( *v33 == a1 + 2264 && (v35 = *(_QWORD *)v34, *(_QWORD *)(*(_QWORD *)v34 + 8LL) == v34) )
    {
      *(_QWORD *)(v35 + 8) = v33;
      *v33 = v35;
    }
    else
    {
      _list_del_entry_valid_or_report(v34);
    }
    *(_QWORD *)(a1 + 2272) = 0xDEAD000000000122LL;
    *(_QWORD *)(a1 + 2264) = 0xDEAD000000000100LL;
    *(_QWORD *)(a1 + 5640) = 0;
    ieee80211_free_keys(a1, 1);
    goto LABEL_61;
  }
  if ( v25 != 6 )
  {
LABEL_60:
    wiphy_work_cancel(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 1960);
    ieee80211_free_keys(a1, 1);
    skb_queue_purge_reason(a1 + 1984, 85);
    skb_queue_purge_reason(a1 + 2008, 85);
LABEL_61:
    v27 = 0;
    goto LABEL_62;
  }
  if ( (*(_BYTE *)(a1 + 2264) & 0x20) != 0 )
  {
    v27 = 0;
    --*(_DWORD *)(v4 + 1324);
    goto LABEL_62;
  }
  v26 = *(_DWORD *)(v4 + 1320) - 1;
  *(_DWORD *)(v4 + 1320) = v26;
  if ( v26 )
  {
    v27 = 0;
  }
  else
  {
    v27 = 8;
    *(_DWORD *)v4 &= ~1u;
  }
  v52 = *(_DWORD *)(a1 + 2264);
  v53 = *(_DWORD **)(a1 + 1616);
  if ( (v52 & 2) != 0 )
  {
    --v53[332];
    if ( (v52 & 4) == 0 )
    {
LABEL_110:
      if ( (v52 & 8) == 0 )
        goto LABEL_111;
      goto LABEL_115;
    }
  }
  else if ( (v52 & 4) == 0 )
  {
    goto LABEL_110;
  }
  --v53[333];
  if ( (v52 & 8) == 0 )
  {
LABEL_111:
    if ( (v52 & 0x10) != 0 )
      goto LABEL_116;
    goto LABEL_62;
  }
LABEL_115:
  v54 = v53[336] - 1;
  --v53[334];
  v53[336] = v54;
  if ( (v52 & 0x10) != 0 )
LABEL_116:
    --v53[335];
LABEL_62:
  LODWORD(v72) = 0;
  v70 = &v70;
  v71 = &v70;
  v36 = raw_spin_lock_irqsave(v4 + 1312);
  v37 = 0;
  do
  {
    v38 = v4 + 2000 + 24 * v37;
    v39 = *(_QWORD **)v38;
    if ( *(_QWORD *)v38 != v38 )
    {
      do
      {
        v40 = (_QWORD *)*v39;
        if ( (int *)v39[8] == v10 )
        {
          --*(_DWORD *)(v38 + 16);
          v41 = (_QWORD *)*v39;
          v42 = (_QWORD *)v39[1];
          *v39 = 0;
          v39[1] = 0;
          v41[1] = v42;
          *v42 = v41;
          v43 = v71;
          *v39 = &v70;
          v39[1] = v43;
          v71 = (_QWORD **)v39;
          *v43 = v39;
          LODWORD(v72) = v72 + 1;
        }
        v39 = v40;
      }
      while ( v40 != (_QWORD *)v38 );
    }
    _CF = v37++ >= 0xF;
    v69 = v37;
  }
  while ( !_CF );
  result = raw_spin_unlock_irqrestore(v4 + 1312, v36);
  v45 = v70;
  if ( v70 != &v70 )
  {
    do
    {
      v46 = (_QWORD *)*v45;
      LODWORD(v72) = v72 - 1;
      v47 = (_QWORD *)*v45;
      v48 = (_QWORD *)v45[1];
      *v45 = 0;
      v45[1] = 0;
      v47[1] = v48;
      *v48 = v47;
      result = ieee80211_free_txskb(v4);
      v45 = v46;
    }
    while ( v46 != &v70 );
  }
  if ( *v10 == 4 )
    result = ieee80211_txq_remove_vlan(v4, a1);
  *(_QWORD *)(a1 + 2032) = 0;
  if ( !*(_DWORD *)(v4 + 1316) )
    result = ieee80211_clear_tx_pending(v4);
  *(_WORD *)(a1 + 4858) = 0;
  if ( *(_BYTE *)(v4 + 1465) != 1 )
  {
    if ( *v10 == 4 )
      goto LABEL_100;
    if ( *v10 != 6 )
    {
LABEL_98:
      if ( (a2 & 1) != 0 )
      {
        drv_remove_interface(v4, a1);
        memset((void *)(a1 + 5904), 0, *(int *)(v4 + 112));
      }
LABEL_100:
      ieee80211_recalc_ps(v4);
      if ( v5 == a1 )
      {
        wiphy_delayed_work_flush(*(_QWORD *)(v4 + 72), v4 + 4896);
        if ( *(_DWORD *)(v4 + 1316) )
        {
LABEL_102:
          ieee80211_configure_filter(v4);
          result = ieee80211_hw_config(v4, v27);
          if ( *(_DWORD *)(v4 + 1320) == *(_DWORD *)(v4 + 1316) )
            result = ieee80211_add_virtual_monitor(v4);
          goto LABEL_106;
        }
      }
      else if ( *(_DWORD *)(v4 + 1316) )
      {
        goto LABEL_102;
      }
      result = ieee80211_stop_device(v4, 0);
      goto LABEL_106;
    }
    if ( !*(_DWORD *)(v4 + 1320) )
      ieee80211_del_virtual_monitor(v4);
    v49 = *(_QWORD *)(v4 + 4984) != v4 + 4984 || *(_DWORD *)(v4 + 1320) != 0;
    if ( *(_QWORD *)(*(_QWORD *)(v4 + 464) + 472LL) )
    {
      v50 = 0;
      if ( (*(_QWORD *)(v4 + 4696) & 1) != 0 )
        goto LABEL_92;
    }
    else
    {
      v50 = *(_QWORD *)(v4 + 5264) != v4 + 5264;
      if ( (*(_QWORD *)(v4 + 4696) & 1) != 0 )
        goto LABEL_92;
    }
    if ( ((v50 || v49) | (*(_QWORD *)(v4 + 4696) >> 2) & 1) != 1 )
    {
      if ( (*(_BYTE *)v4 & 4) != 0 )
        goto LABEL_97;
      ieee80211_flush_queues(v4, 0, 0);
      v51 = *(_DWORD *)v4 | 4;
LABEL_96:
      *(_DWORD *)v4 = v51;
      ieee80211_hw_config(v4, 256);
LABEL_97:
      ieee80211_recalc_offload(v4);
      if ( (*(_BYTE *)(a1 + 2264) & 0x40) == 0 )
        goto LABEL_100;
      goto LABEL_98;
    }
LABEL_92:
    if ( (*(_DWORD *)v4 & 4) == 0 )
      goto LABEL_97;
    v51 = *(_DWORD *)v4 & 0xFFFFFFFB;
    goto LABEL_96;
  }
  if ( *(_BYTE *)(v4 + 1472) == 1 )
  {
    __break(0x800u);
    if ( !*(_QWORD *)(v4 + 5384) )
      goto LABEL_106;
    goto LABEL_78;
  }
  if ( *(_QWORD *)(v4 + 5384) )
LABEL_78:
    __break(0x800u);
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return result;
}
