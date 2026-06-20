__int64 __fastcall cfg80211_unregister_wdev(__int64 a1, __int64 a2)
{
  __int64 v2; // d15
  __int64 v3; // d19
  __int64 v4; // x22
  char v6; // w21
  __int64 v7; // x8
  _QWORD *v8; // x8
  __int64 v9; // x0
  __int64 v10; // x9
  int v11; // w8
  __int64 v12; // x0
  __int64 result; // x0
  int v14; // w8
  __int64 i; // x21
  __int64 v16; // x20
  __int64 v17; // x0

  v4 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 )
  {
    v6 = a2;
    if ( !(unsigned int)rtnl_is_locked(a1) && (cfg80211_unregister_wdev___already_done & 1) == 0 )
    {
      cfg80211_unregister_wdev___already_done = 1;
      _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 1252);
      __break(0x800u);
    }
    nl80211_notify_iface(v4 - 992, a1, 8);
    v7 = *(_QWORD *)(a1 + 32);
    *(_BYTE *)(a1 + 67) = 0;
    if ( v7 )
    {
      sysfs_remove_link(v7 + 1376, "phy80211");
      if ( (v6 & 1) != 0 )
        unregister_netdevice_queue(*(_QWORD *)(a1 + 32), 0);
    }
    v8 = *(_QWORD **)(a1 + 24);
    v9 = a1 + 16;
    if ( *v8 == a1 + 16 && (v10 = *(_QWORD *)v9, *(_QWORD *)(*(_QWORD *)v9 + 8LL) == v9) )
    {
      *(_QWORD *)(v10 + 8) = v8;
      *v8 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(v9);
    }
    *(_QWORD *)(a1 + 24) = 0xDEAD000000000122LL;
    synchronize_net();
    ++*(_DWORD *)(v4 - 888);
    ((void (__fastcall *)(__int64))cfg80211_mlme_purge_registrations)(a1);
    v11 = *(_DWORD *)(a1 + 8);
    if ( v11 == 12 )
    {
      cfg80211_stop_nan(v4 - 992, a1);
    }
    else if ( v11 == 10 )
    {
      cfg80211_stop_p2p_device(v4 - 992, a1);
    }
    wiphy_work_cancel(*(_QWORD *)a1, a1 + 184);
    v12 = *(_QWORD *)(a1 + 208);
    if ( v12 )
      kvfree_call_rcu(v12, *(_QWORD *)(a1 + 208));
    *(_QWORD *)(a1 + 208) = 0;
    result = ((__int64 (__fastcall *)(__int64))cfg80211_process_wdev_events)(a1);
    v14 = *(_DWORD *)(a1 + 8);
    if ( v14 == 8 || v14 == 2 )
    {
      for ( i = 400; i != 1480; i += 72 )
      {
        v16 = *(_QWORD *)(a1 + i);
        if ( v16 )
        {
          v17 = *(_QWORD *)(a1 + i);
          __break(0x800u);
          cfg80211_unhold_bss(v17);
          result = cfg80211_put_bss(*(_QWORD *)a1, v16 + 112);
          *(_QWORD *)(a1 + i) = 0;
        }
      }
    }
    *(_BYTE *)(a1 + 164) &= ~1u;
  }
  else
  {
    __break(0x800u);
    *(_QWORD *)(a2 + 280) = v2;
    *(_QWORD *)(a2 + 288) = v3;
    return cfg80211_update_iface_num();
  }
  return result;
}
