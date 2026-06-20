__int64 __fastcall _ieee80211_suspend(__int64 a1, _BYTE *a2)
{
  _QWORD *i; // x21
  unsigned __int64 v11; // x9
  _BOOL4 v12; // w23
  __int64 v13; // x0
  __int64 v14; // x21
  __int64 v15; // x22
  _DWORD *v16; // x8
  unsigned int v17; // w0
  unsigned int v18; // w20
  int v20; // w8
  _QWORD *j; // x8
  unsigned __int64 v24; // x12

  if ( !*(_DWORD *)(a1 + 1316) )
    goto LABEL_35;
  *(_BYTE *)(a1 + 1466) = 1;
  __dsb(0xFu);
  ieee80211_scan_cancel((_QWORD *)a1);
  ieee80211_dfs_cac_cancel(a1, 0);
  ieee80211_roc_purge(a1, 0);
  ieee80211_del_virtual_monitor(a1);
  if ( (*(_QWORD *)(a1 + 96) & 0x80) != 0 )
  {
    if ( a2 && (*a2 & 1) != 0 )
      goto LABEL_13;
    for ( i = *(_QWORD **)(a1 + 1616); i != (_QWORD *)(a1 + 1616); i = (_QWORD *)*i )
    {
      _X8 = i + 27;
      __asm { PRFM            #0x11, [X8] }
      do
        v11 = __ldxr(_X8);
      while ( __stxr(v11 | 0x100, _X8) );
      ieee80211_sta_tear_down_BA_sessions(i, 1u);
    }
  }
  v12 = a2 != nullptr;
  if ( a2 && (*a2 & 1) != 0 )
  {
LABEL_13:
    v12 = 1;
    goto LABEL_16;
  }
  if ( !(unsigned int)ieee80211_request_sched_scan_stop((_QWORD *)a1) )
    cfg80211_sched_scan_stopped_locked(*(_QWORD *)(a1 + 72), 0);
LABEL_16:
  v13 = ieee80211_stop_queues_by_reason(a1, 0xFFFF, 4u, 0);
  synchronize_net(v13);
  ieee80211_flush_queues(a1, nullptr, 1);
  *(_BYTE *)(a1 + 1468) = 1;
  __dsb(0xFu);
  _flush_workqueue(*(_QWORD *)(a1 + 472));
  timer_delete_sync(a1 + 1952);
  wiphy_work_cancel(*(_QWORD *)(a1 + 72), a1 + 5016);
  timer_delete_sync(a1 + 5064);
  v14 = *(_QWORD *)(a1 + 4616);
  *(_BYTE *)(a1 + 1472) = v12;
  v15 = a1 + 4616;
  if ( !v12 )
  {
    if ( v14 != a1 + 4616 )
    {
      do
      {
        if ( (*(_QWORD *)(v14 + 1632) & 1) != 0 )
        {
          v20 = *(_DWORD *)(v14 + 4720);
          if ( v20 != 6 && v20 != 4 )
          {
            if ( v20 == 2 )
              ieee80211_mgd_quiesce(v14);
            wiphy_delayed_work_flush(*(_QWORD *)(a1 + 72), v14 + 1536);
            drv_remove_interface(a1, v14);
          }
        }
        v14 = *(_QWORD *)v14;
      }
      while ( v14 != v15 );
    }
    if ( *(_QWORD *)(a1 + 4984) != a1 + 4984 )
      __break(0x800u);
    ieee80211_stop_device(a1);
    goto LABEL_35;
  }
  if ( v14 != a1 + 4616 )
  {
    do
    {
      if ( (*(_QWORD *)(v14 + 1632) & 1) != 0 && *(_DWORD *)(v14 + 4720) == 2 )
      {
        ieee80211_mgd_quiesce(v14);
        if ( (*(_BYTE *)(v14 + 2477) & 8) != 0 && *(_BYTE *)(v14 + 2496) == 1 && (*(_DWORD *)a1 & 2) == 0 )
        {
          *(_DWORD *)a1 |= 2u;
          ieee80211_hw_config(a1, 16);
        }
      }
      v14 = *(_QWORD *)v14;
    }
    while ( v14 != v15 );
  }
  v16 = *(_DWORD **)(*(_QWORD *)(a1 + 464) + 24LL);
  if ( *(v16 - 1) != 21130211 )
    __break(0x8228u);
  v17 = ((__int64 (__fastcall *)(__int64, _BYTE *))v16)(a1, a2);
  if ( (v17 & 0x80000000) != 0 )
  {
    *(_BYTE *)(a1 + 1468) = 0;
    v18 = v17;
    *(_BYTE *)(a1 + 1472) = 0;
    if ( (*(_QWORD *)(a1 + 96) & 0x80) != 0 )
    {
      for ( j = *(_QWORD **)(a1 + 1616); j != (_QWORD *)(a1 + 1616); j = (_QWORD *)*j )
      {
        _X11 = j + 27;
        __asm { PRFM            #0x11, [X11] }
        do
          v24 = __ldxr(_X11);
        while ( __stxr(v24 & 0xFFFFFFFFFFFFFEFFLL, _X11) );
      }
    }
    goto LABEL_50;
  }
  if ( !v17 )
  {
LABEL_35:
    *(_BYTE *)(a1 + 1465) = 1;
    *(_BYTE *)(a1 + 1468) = 0;
    *(_BYTE *)(a1 + 1466) = 0;
    return 0;
  }
  v18 = v17;
  if ( v17 != 1 )
    __break(0x800u);
LABEL_50:
  ieee80211_wake_queues_by_reason(a1, 0xFFFF, 4u, 0);
  return v18;
}
