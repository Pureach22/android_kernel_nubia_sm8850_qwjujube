__int64 __fastcall cfg80211_register_wdev(__int64 a1, __int64 a2)
{
  int v4; // w8
  __int64 v5; // x2
  unsigned __int64 *v6; // x1
  unsigned __int64 v7; // x0
  __int64 v8; // x8

  if ( !(unsigned int)rtnl_is_locked(a1) && (cfg80211_register_wdev___already_done & 1) == 0 )
  {
    cfg80211_register_wdev___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 1454);
    __break(0x800u);
    if ( *(_DWORD *)(a2 + 40) )
      goto LABEL_5;
    goto LABEL_4;
  }
  if ( !*(_DWORD *)(a2 + 40) )
  {
LABEL_4:
    v4 = *(_DWORD *)(a1 + 108) + 1;
    *(_DWORD *)(a1 + 108) = v4;
    *(_DWORD *)(a2 + 40) = v4;
  }
LABEL_5:
  v5 = *(_QWORD *)(a1 + 2328);
  v6 = (unsigned __int64 *)(a1 + 2328);
  v7 = a2 + 16;
  if ( *(_QWORD *)(v5 + 8) != a1 + 2328 || (unsigned __int64 *)v7 == v6 || v5 == v7 )
  {
    _list_add_valid_or_report(v7, v6);
  }
  else
  {
    *(_QWORD *)(a2 + 16) = v5;
    *(_QWORD *)(a2 + 24) = v6;
    atomic_store(v7, v6);
    *(_QWORD *)(v5 + 8) = v7;
  }
  ++*(_DWORD *)(a1 + 104);
  v8 = *(_QWORD *)(a2 + 32);
  *(_BYTE *)(a2 + 67) = 1;
  if ( v8 && (unsigned int)sysfs_create_link(v8 + 1376, a1 + 1384, "phy80211") )
    printk(&unk_B6B29);
  return nl80211_notify_iface(a1, a2, 7);
}
