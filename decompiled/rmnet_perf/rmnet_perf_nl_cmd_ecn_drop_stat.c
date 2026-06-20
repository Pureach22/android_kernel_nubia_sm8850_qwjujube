__int64 __fastcall rmnet_perf_nl_cmd_ecn_drop_stat(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x0
  int v6; // w22
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 result; // x0
  _QWORD *v12; // x20
  _QWORD *v13; // x20
  _QWORD *v14; // x20
  _QWORD *v15; // x21
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 48LL);
  if ( !v3 )
  {
    v12 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Must provide hash value");
    if ( v12 )
      *v12 = "Must provide hash value";
    goto LABEL_17;
  }
  v4 = *(unsigned int *)(v3 + 4);
  _rcu_read_lock();
  v5 = xa_load(&rmnet_perf_ecn_map, v4);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 24);
    _rcu_read_unlock();
    v7 = _alloc_skb(36, 3264, 0, 0xFFFFFFFFLL);
    if ( v7 )
    {
      v8 = v7;
      v9 = genlmsg_put(v7, *(unsigned int *)(a2 + 4));
      if ( v9 )
      {
        v10 = v9;
        v16 = v6;
        nla_put(v8, 9, 4, &v16);
        *(_DWORD *)(v10 - 20) = *(_DWORD *)(v8 + 216) + *(_DWORD *)(v8 + 208) - (v10 - 20);
        netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v8, *(unsigned int *)(a2 + 4), 64);
        result = 0;
        goto LABEL_18;
      }
      v15 = *(_QWORD **)(a2 + 64);
      do_trace_netlink_extack("Building response failed");
      if ( v15 )
        *v15 = "Building response failed";
      sk_skb_reason_drop(0, v8, 2);
LABEL_17:
      result = 4294967274LL;
      goto LABEL_18;
    }
    v14 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Allocating response failed");
    if ( v14 )
      *v14 = "Allocating response failed";
    result = 4294967284LL;
  }
  else
  {
    _rcu_read_unlock();
    v13 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Fetching drop count failed");
    if ( v13 )
      *v13 = "Fetching drop count failed";
    result = 4294967293LL;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
