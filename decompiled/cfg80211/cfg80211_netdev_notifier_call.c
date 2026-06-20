__int64 __fastcall cfg80211_netdev_notifier_call(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 v7; // x20
  __int64 result; // x0
  __int64 v9; // x9
  __int64 v10; // x10
  unsigned int v11; // w9
  int v12; // w9
  int v13; // w8
  unsigned int (__fastcall *v14)(__int64, __int64, __int64, __int64); // x8
  int v15; // w9
  __int64 v16; // x9
  __int64 v17; // x9
  _QWORD *v18; // x8
  _QWORD *v19; // x23
  unsigned __int64 StatusReg; // x23
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x8
  unsigned int v24; // [xsp+18h] [xbp+18h]
  unsigned int v25; // [xsp+1Ch] [xbp+1Ch]

  v5 = *(_QWORD *)a3;
  v6 = *(_QWORD *)(*(_QWORD *)a3 + 992LL);
  if ( !v6 )
    return 0;
  v7 = *(_QWORD *)v6;
  if ( !*(_QWORD *)v6 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v24 = a4;
      v25 = a3;
      v21 = _traceiter_rdev_set_power_mgmt(0, 0, v5, (unsigned int)a3, (unsigned int)a4);
      a4 = v24;
      a3 = v25;
      v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v23;
      if ( !v23 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v21, v22, v25);
        a4 = v24;
        a3 = v25;
      }
    }
    goto LABEL_29;
  }
  v4 = v7 - 992;
  if ( !*(_DWORD *)(v6 + 8) )
    __break(0x800u);
  result = 0;
  if ( a2 <= 5 )
  {
    if ( a2 != 1 )
    {
      if ( a2 == 2 )
      {
        mutex_lock(v7);
        v15 = *(_DWORD *)(v6 + 8);
        --*(_DWORD *)(v7 - 828);
        if ( v15 == 6 )
          --*(_DWORD *)(v7 - 824);
        v16 = *(_QWORD *)(v7 - 768);
        if ( v16 && *(_QWORD *)(v16 + 64) == v6 )
        {
          if ( (*(_BYTE *)(v16 + 128) & 1) == 0 )
          {
            v17 = *(_QWORD *)(v7 - 760);
            if ( !v17 || (*(_BYTE *)(v17 + 128) & 1) == 0 )
            {
              __break(0x800u);
              *(_BYTE *)(*(_QWORD *)(v7 - 768) + 126LL) = 1;
            }
          }
          __cfg80211_scan_done(v7 - 992, 0);
        }
        v18 = *(_QWORD **)(v7 - 744);
        if ( v18 != (_QWORD *)(v7 - 744) )
        {
          do
          {
            v19 = (_QWORD *)*v18;
            if ( *(v18 - 6) == *(_QWORD *)(v6 + 32) )
            {
              __break(0x800u);
              cfg80211_stop_sched_scan_req(v7 - 992, v18 - 21, 0);
            }
            v18 = v19;
          }
          while ( v19 != (_QWORD *)(v7 - 744) );
        }
        --*(_DWORD *)(v7 - 880);
        mutex_unlock(v7);
        result = _wake_up(v7 - 872, 3, 1, 0);
        goto LABEL_56;
      }
      if ( a2 != 5 )
        return result;
      if ( (*(_BYTE *)(v6 + 67) & 1) != 0 )
        goto LABEL_56;
      mutex_lock(v7);
      cfg80211_register_wdev(v7 - 992, v6);
      goto LABEL_36;
    }
    mutex_lock(v7);
    v12 = *(_DWORD *)(v6 + 8);
    ++*(_DWORD *)(v7 - 828);
    if ( v12 == 6 )
      ++*(_DWORD *)(v7 - 824);
    ++*(_DWORD *)(v7 - 880);
    v13 = *(_DWORD *)(v6 + 8);
    if ( v13 != 8 && v13 != 2 || !*(_QWORD *)(*(_QWORD *)v4 + 536LL) )
    {
LABEL_36:
      result = mutex_unlock(v7);
      goto LABEL_56;
    }
    a3 = *(unsigned __int8 *)(v6 + 165);
    a4 = *(unsigned int *)(v6 + 168);
LABEL_29:
    v14 = *(unsigned int (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)v4 + 536LL);
    if ( *((_DWORD *)v14 - 1) != -1867233320 )
      __break(0x8228u);
    if ( v14(v7, v5, a3, a4) )
      *(_BYTE *)(v6 + 165) = 0;
    goto LABEL_36;
  }
  if ( a2 > 13 )
  {
    if ( a2 == 14 )
    {
      if ( (cfg80211_iftype_allowed(*(_QWORD *)v6, *(unsigned int *)(v6 + 8), *(unsigned __int8 *)(v6 + 65), 0) & 1) == 0 )
        return 32864;
      result = rfkill_blocked(*(_QWORD *)(v7 + 1480));
      if ( (result & 1) != 0 )
        return 32901;
    }
    else
    {
      if ( a2 != 17 )
        return result;
      *(_QWORD *)(v5 + 1496) = &wiphy_type;
      *(_QWORD *)(v6 + 32) = v5;
      *(_BYTE *)(v5 + 2418) |= 4u;
      *(_QWORD *)(v6 + 144) = v6 + 144;
      *(_QWORD *)(v6 + 152) = v6 + 144;
      *(_DWORD *)(v6 + 160) = 0;
      *(_QWORD *)(v6 + 48) = v6 + 48;
      *(_QWORD *)(v6 + 56) = v6 + 48;
      *(_QWORD *)(v6 + 216) = v6 + 216;
      *(_QWORD *)(v6 + 224) = v6 + 216;
      *(_DWORD *)(v6 + 232) = 0;
      *(_QWORD *)(v6 + 240) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v6 + 248) = v6 + 248;
      *(_QWORD *)(v6 + 256) = v6 + 248;
      *(_QWORD *)(v6 + 264) = cfg80211_pmsr_free_wk;
      *(_QWORD *)(v6 + 184) = v6 + 184;
      *(_QWORD *)(v6 + 192) = v6 + 184;
      v9 = *(_QWORD *)v6;
      *(_QWORD *)(v6 + 200) = cfg80211_cqm_rssi_notify_work;
      *(_BYTE *)(v6 + 165) = (*(_BYTE *)(v9 + 100) & 0x10) != 0;
      *(_DWORD *)(v6 + 168) = -1;
      v10 = -1LL << *(_DWORD *)(v9 + 1496);
      v11 = *(_DWORD *)(v6 + 8);
      *(_DWORD *)(v6 + 1476) = ~(_DWORD)v10;
      if ( v11 <= 8 && ((1 << v11) & 0x106) != 0 && (*(_BYTE *)(v6 + 65) & 1) == 0 )
        **(_QWORD **)(v6 + 32) |= 0x40uLL;
      *(_QWORD *)(v6 + 104) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v6 + 112) = v6 + 112;
      *(_QWORD *)(v6 + 120) = v6 + 112;
      *(_QWORD *)(v6 + 128) = cfg80211_autodisconnect_wk;
    }
  }
  else
  {
    if ( a2 != 6 )
    {
      if ( a2 != 10 )
        return result;
      mutex_lock(v7);
      cfg80211_leave(v7 - 992, v6);
      cfg80211_remove_links(v6);
      mutex_unlock(v7);
      cancel_work_sync(v6 + 104);
      result = cancel_work_sync(v6 + 240);
      goto LABEL_56;
    }
    if ( *(_BYTE *)(v6 + 67) == 1 && (*(_BYTE *)(v6 + 68) & 1) == 0 )
    {
      mutex_lock(v7);
      cfg80211_unregister_wdev(v6, 0);
      goto LABEL_36;
    }
  }
LABEL_56:
  wireless_nlevent_flush(result);
  return 1;
}
