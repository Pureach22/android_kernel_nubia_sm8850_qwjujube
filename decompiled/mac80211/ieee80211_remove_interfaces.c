__int64 __fastcall ieee80211_remove_interfaces(__int64 a1)
{
  int v2; // w2
  __int64 v3; // x9
  __int64 v4; // x10
  _QWORD *v5; // x11
  _QWORD *v6; // x20
  int v7; // w8
  _QWORD *v8; // x23
  __int64 v9; // x24
  _QWORD *v10; // x8
  _QWORD *v11; // x9
  __int64 result; // x0
  __int64 v13; // x8
  const char *v14; // x1
  _QWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = v15;
  v15[1] = v15;
  if ( !(unsigned int)rtnl_is_locked() && (ieee80211_remove_interfaces___already_done & 1) == 0 )
  {
    ieee80211_remove_interfaces___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 2260);
    __break(0x800u);
  }
  cfg80211_shutdown_all_interfaces(*(_QWORD *)(a1 + 72));
  mutex_lock(*(_QWORD *)(a1 + 72));
  v2 = *(_DWORD *)(a1 + 1316);
  if ( v2 )
  {
    v13 = *(_QWORD *)(a1 + 72);
    v14 = *(const char **)(v13 + 504);
    if ( !v14 )
      v14 = *(const char **)(v13 + 392);
    _warn_printk("%s: open count remains %d\n", v14, v2);
    __break(0x800u);
  }
  mutex_lock(a1 + 4648);
  v3 = *(_QWORD *)(a1 + 4616);
  if ( v3 != a1 + 4616 )
  {
    v4 = v15[0];
    v5 = *(_QWORD **)(a1 + 4624);
    v15[0] = *(_QWORD *)(a1 + 4616);
    *(_QWORD *)(v3 + 8) = v15;
    *v5 = v4;
    *(_QWORD *)(v4 + 8) = v5;
    *(_QWORD *)(a1 + 4616) = a1 + 4616;
    *(_QWORD *)(a1 + 4624) = a1 + 4616;
  }
  mutex_unlock(a1 + 4648);
  v6 = (_QWORD *)v15[0];
  if ( (_QWORD *)v15[0] != v15 )
  {
    do
    {
      v7 = *((_DWORD *)v6 + 1180);
      v8 = (_QWORD *)*v6;
      v9 = v6[201];
      *((_DWORD *)v6 + 1189) = 0;
      if ( v7 == 2 && (*((_BYTE *)v6 + 2477) & 8) != 0 )
        ieee80211_vif_cfg_change_notify(v6, 4096);
      v10 = (_QWORD *)v6[1];
      if ( (_QWORD *)*v10 == v6 && (v11 = (_QWORD *)*v6, *(_QWORD **)(*v6 + 8LL) == v6) )
      {
        v11[1] = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      cfg80211_unregister_wdev(v6 + 2);
      if ( !v9 )
        kfree(v6);
      v6 = v8;
    }
    while ( v8 != v15 );
  }
  result = mutex_unlock(*(_QWORD *)(a1 + 72));
  _ReadStatusReg(SP_EL0);
  return result;
}
