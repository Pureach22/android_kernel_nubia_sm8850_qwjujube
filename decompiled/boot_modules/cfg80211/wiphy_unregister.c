__int64 __fastcall wiphy_unregister(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  int v3; // w21
  int v4; // w23
  __int64 v5; // x0
  __int64 v6; // x0
  _QWORD *v7; // x9
  __int64 *v8; // x0
  _QWORD *v9; // x8
  __int64 v10; // x10
  _DWORD *v11; // x8
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x20
  __int64 v15; // x21
  _QWORD *v16; // x0
  _QWORD *v17; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x8
  _QWORD v24[6]; // [xsp+0h] [xbp-30h] BYREF

  v24[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v20 = _traceiter_rdev_set_wakeup(0, v1, 0);
      v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v23;
      if ( !v23 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v20, v21, v22);
    }
    goto LABEL_16;
  }
  v1 = a1;
  v2 = a1 - 992;
  mutex_lock(a1);
  v3 = *(_DWORD *)(v1 - 880);
  mutex_unlock(v1);
  if ( v3 )
  {
    memset(v24, 0, 40);
    init_wait_entry(v24, 0);
    while ( 1 )
    {
      prepare_to_wait_event(v1 - 872, v24, 2);
      mutex_lock(v1);
      v4 = *(_DWORD *)(v1 - 880);
      v5 = mutex_unlock(v1);
      if ( !v4 )
        break;
      schedule(v5);
    }
    finish_wait(v1 - 872, v24);
  }
  v6 = *(_QWORD *)(v1 + 1480);
  if ( v6 )
    v6 = rfkill_unregister();
  rtnl_lock(v6);
  mutex_lock(v1);
  nl80211_notify_wiphy(v2, 4);
  *(_BYTE *)(v1 + 1304) = 0;
  if ( *(_QWORD *)(v1 + 1336) != v1 + 1336 )
    __break(0x800u);
  debugfs_remove(*(_QWORD *)(v1 + 1312));
  v7 = (_QWORD *)(v1 - 976);
  v8 = (__int64 *)(v1 - 984);
  v9 = *(_QWORD **)(v1 - 976);
  if ( *v9 == v1 - 984 && (v10 = *v8, *(__int64 **)(*v8 + 8) == v8) )
  {
    *(_QWORD *)(v10 + 8) = v9;
    *v9 = v10;
  }
  else
  {
    _list_del_entry_valid_or_report(v8);
  }
  *v7 = 0xDEAD000000000122LL;
  synchronize_rcu();
  wiphy_regulatory_deregister(v1);
  ++cfg80211_rdev_list_generation;
  device_del(v1 + 392);
  if ( *(_QWORD *)(v1 + 256) && *(_QWORD *)(*(_QWORD *)v2 + 16LL) )
  {
LABEL_16:
    v11 = *(_DWORD **)(*(_QWORD *)v2 + 16LL);
    if ( *(v11 - 1) != -1552247882 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v11)(v1, 0);
  }
  cfg80211_process_wiphy_works(v2, 0);
  v12 = mutex_unlock(v1);
  rtnl_unlock(v12);
  cancel_work_sync(v1 - 72);
  cancel_work_sync(v1 - 688);
  flush_work(v1 - 656);
  cancel_delayed_work_sync(v1 - 624);
  cancel_delayed_work_sync(v1 - 480);
  flush_work(v1 - 328);
  flush_work(v1 - 208);
  flush_work(v1 - 144);
  flush_work(v1 - 112);
  flush_work(v1 - 376);
  v13 = *(_QWORD *)(v1 + 256);
  if ( v13 )
  {
    if ( *(int *)(v13 + 24) >= 1 )
    {
      v14 = 0;
      v15 = 0;
      do
      {
        kfree(*(_QWORD *)(*(_QWORD *)(v13 + 8) + v14));
        v13 = *(_QWORD *)(v1 + 256);
        ++v15;
        v14 += 24;
      }
      while ( v15 < *(int *)(v13 + 24) );
    }
    kfree(*(_QWORD *)(v13 + 8));
    v16 = *(_QWORD **)(*(_QWORD *)(v1 + 256) + 16LL);
    if ( v16 && *v16 )
    {
      sock_release(*v16);
      v16 = *(_QWORD **)(*(_QWORD *)(v1 + 256) + 16LL);
    }
    kfree(v16);
    kfree(*(_QWORD *)(*(_QWORD *)(v1 + 256) + 32LL));
    kfree(*(_QWORD *)(v1 + 256));
  }
  v17 = (_QWORD *)(v1 - 336);
  result = cfg80211_free_coalesce(*v17);
  *v17 = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
