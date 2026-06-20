__int64 __fastcall ieee80211_if_change_type(__int64 a1, int a2)
{
  _BYTE *v4; // x24
  int v5; // w8
  __int64 result; // x0
  __int64 v7; // x21
  int v8; // w8
  unsigned int v9; // w23
  unsigned int vif_queues; // w0
  unsigned int v11; // w0
  unsigned int v12; // w1
  unsigned int v13; // w10
  __int64 v14; // x9
  unsigned int v15; // w8
  unsigned int v16; // w10
  unsigned int v17; // w10
  unsigned int v18; // w10
  unsigned int v19; // w9
  unsigned int v20; // w22
  __int64 v21; // x8
  __int64 v22; // x8
  int v23; // w8
  void *v24; // x9
  int v25; // w0
  unsigned int v26; // w0

  v4 = (_BYTE *)(a1 + 4096);
  if ( !(unsigned int)rtnl_is_locked() && (ieee80211_if_change_type___already_done & 1) == 0 )
  {
    ieee80211_if_change_type___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 1905);
    __break(0x800u);
  }
  v5 = *(_DWORD *)(a1 + 4720);
  if ( v4[1752] != 1 )
  {
LABEL_8:
    if ( v5 != a2 )
      goto LABEL_9;
    return 0;
  }
  if ( v5 != 2 )
  {
    if ( v5 == 3 )
      v5 = 9;
    goto LABEL_8;
  }
  if ( a2 == 8 )
    return 0;
LABEL_9:
  if ( (*(_QWORD *)(a1 + 1632) & 1) == 0 )
  {
    ieee80211_free_keys(a1, 0);
    ieee80211_destroy_frag_cache(a1 + 1656);
    ieee80211_vif_set_links(a1, 0, 0);
    ((void (__fastcall *)(__int64))ieee80211_link_stop)(a1 + 3616);
    ieee80211_setup_sdata(a1);
    goto LABEL_11;
  }
  v7 = *(_QWORD *)(a1 + 1616);
  if ( !(unsigned int)rtnl_is_locked() && (ieee80211_runtime_change_iftype___already_done & 1) == 0 )
  {
    ieee80211_runtime_change_iftype___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 1816);
    __break(0x800u);
  }
  if ( !*(_QWORD *)(*(_QWORD *)(v7 + 464) + 56LL) )
    return 4294967280LL;
  if ( *(_WORD *)(a1 + 5800) )
    return 4294967280LL;
  v8 = *(_DWORD *)(a1 + 4720);
  if ( (unsigned int)(v8 - 1) >= 2 && v8 != 11 && (v8 != 3 || *(_QWORD *)(a1 + 2264) != a1 + 2264) )
    return 4294967280LL;
  result = 4294967280LL;
  if ( a2 > 7 )
  {
    v9 = a2;
    if ( a2 != 11 )
    {
      if ( a2 == 9 )
      {
        v9 = 3;
      }
      else
      {
        if ( a2 != 8 )
          return result;
        v9 = 2;
      }
    }
  }
  else
  {
    v9 = a2;
    if ( (unsigned int)(a2 - 1) >= 3 )
      return result;
  }
  result = ieee80211_check_concurrent_iface(a1, v9);
  if ( (_DWORD)result )
    return result;
  vif_queues = ieee80211_get_vif_queues(v7, a1);
  ieee80211_stop_queues_by_reason(v7, vif_queues, 10, 1);
  ieee80211_do_stop(a1, 0);
  ieee80211_free_keys(a1, 0);
  ieee80211_destroy_frag_cache(a1 + 1656);
  ieee80211_vif_set_links(a1, 0, 0);
  ((void (__fastcall *)(__int64))ieee80211_link_stop)(a1 + 3616);
  ieee80211_set_sdata_offload_flags(a1);
  v11 = drv_change_interface(v7, a1);
  v12 = a2;
  if ( v11 )
  {
    v12 = *(_DWORD *)(a1 + 4720);
    if ( v4[1752] == 1 )
    {
      if ( v12 == 2 )
      {
        v12 = 8;
        goto LABEL_44;
      }
      if ( v12 == 3 )
      {
        v12 = 9;
        goto LABEL_44;
      }
    }
  }
  if ( v12 == 10 )
  {
LABEL_55:
    v4[1753] = -1;
    goto LABEL_59;
  }
  if ( v12 == 12 )
    goto LABEL_59;
LABEL_44:
  v13 = (unsigned __int8)v4[1754];
  if ( v13 == 255 )
    goto LABEL_58;
  v14 = *(_QWORD *)(a1 + 1616);
  v15 = *(unsigned __int16 *)(v14 + 128);
  if ( v15 <= v13 )
    goto LABEL_58;
  v16 = (unsigned __int8)v4[1755];
  if ( v16 == 255 )
    goto LABEL_58;
  if ( v15 <= v16 )
    goto LABEL_58;
  v17 = (unsigned __int8)v4[1756];
  if ( v17 == 255 )
    goto LABEL_58;
  if ( v15 <= v17 )
    goto LABEL_58;
  v18 = (unsigned __int8)v4[1757];
  if ( v18 == 255 || v15 <= v18 )
    goto LABEL_58;
  if ( v12 > 9 || ((1 << v12) & 0x288) == 0 || (*(_QWORD *)(v14 + 96) & 0x40000) == 0 )
    goto LABEL_55;
  v19 = (unsigned __int8)v4[1753];
  if ( v19 == 255 || v15 <= v19 )
LABEL_58:
    __break(0x800u);
LABEL_59:
  v20 = v11;
  ieee80211_setup_sdata(a1);
  v21 = a1;
  if ( *(_DWORD *)(a1 + 4720) == 4 )
  {
    v22 = *(_QWORD *)(a1 + 2032);
    if ( !v22 )
      goto LABEL_69;
    v21 = v22 - 2264;
  }
  if ( (*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 96LL) & 0x1000000000000LL) != 0
    && (*(_DWORD *)(v21 + 4720) & 0xFFFFFFFE) == 2 )
  {
    v23 = *(_DWORD *)(v21 + 5876);
    if ( *(_BYTE *)(a1 + 81) == 1 )
      v23 &= (unsigned __int8)(v23 & 2) >> 1;
    v24 = &ieee80211_dataif_ops;
    if ( (v23 & 1) != 0 )
      v24 = &ieee80211_dataif_8023_ops;
    *(_QWORD *)(*(_QWORD *)(a1 + 1608) + 8LL) = v24;
  }
LABEL_69:
  v25 = ieee80211_do_open(a1 + 16, 0);
  if ( v25 )
  {
    _warn_printk("type change: do_open returned %d", v25);
    __break(0x800u);
  }
  v26 = ieee80211_get_vif_queues(v7, a1);
  ieee80211_wake_queues_by_reason(v7, v26, 10, 1);
  result = v20;
  if ( !v20 )
  {
LABEL_11:
    if ( a2 == 2 )
    {
      *(_BYTE *)(a1 + 2524) = 0;
      return 0;
    }
    return 0;
  }
  return result;
}
