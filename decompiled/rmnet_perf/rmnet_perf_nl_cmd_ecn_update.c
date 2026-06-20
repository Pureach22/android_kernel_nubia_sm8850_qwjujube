__int64 __fastcall rmnet_perf_nl_cmd_ecn_update(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x10
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x19
  int v7; // w21
  bool v9; // w23
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x20
  unsigned __int64 v12; // x21
  _QWORD *v13; // x20
  __int64 result; // x0
  unsigned __int64 v15; // x19
  _QWORD *v16; // x20

  v2 = *(_QWORD **)(a2 + 32);
  v3 = v2[6];
  if ( v3 && (v4 = v2[7]) != 0 && (v5 = v2[8]) != 0 )
  {
    v6 = *(unsigned int *)(v3 + 4);
    v7 = *(_DWORD *)(v4 + 4);
    v9 = *(_BYTE *)(v5 + 4) == 0;
    raw_spin_lock(&rmnet_perf_ecn_map);
    v10 = _xa_store(&rmnet_perf_ecn_map, v6, 0, 2080);
    v11 = v10;
    if ( v10 >= 0xFFFFFFFFFFFFC006LL && (v10 & 3) == 2 )
    {
      raw_spin_unlock(&rmnet_perf_ecn_map);
      LODWORD(v12) = v11 >> 2;
      if ( !(_DWORD)v12 )
        return 0;
      goto LABEL_22;
    }
    if ( !v10 )
    {
      v11 = _kmalloc_cache_noprof(init_net, 2336, 32);
      if ( !v11 )
      {
        raw_spin_unlock(&rmnet_perf_ecn_map);
        LODWORD(v12) = -12;
        goto LABEL_22;
      }
    }
    if ( !v7 )
    {
      call_rcu(v11, rmnet_perf_ecn_node_free);
      raw_spin_unlock(&rmnet_perf_ecn_map);
      return 0;
    }
    *(_DWORD *)(v11 + 16) = v7;
    *(_BYTE *)(v11 + 28) = v9;
    v15 = _xa_store(&rmnet_perf_ecn_map, v6, v11, 2080);
    raw_spin_unlock(&rmnet_perf_ecn_map);
    result = 0;
    if ( v15 >= 0xFFFFFFFFFFFFC006LL && (v15 & 3) == 2 )
    {
      v12 = v15 >> 2;
      if ( (unsigned int)(v15 >> 2) )
      {
        kfree(v11);
LABEL_22:
        v16 = *(_QWORD **)(a2 + 64);
        do_trace_netlink_extack("Updating probability failed");
        if ( v16 )
          *v16 = "Updating probability failed";
        return (unsigned int)v12;
      }
    }
  }
  else
  {
    v13 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Must provide ECN hash, probability, & type");
    if ( v13 )
      *v13 = "Must provide ECN hash, probability, & type";
    return 4294967274LL;
  }
  return result;
}
