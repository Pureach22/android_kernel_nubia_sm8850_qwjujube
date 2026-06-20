__int64 __fastcall rmnet_perf_nl_cmd_get_stats(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x21
  __int16 *v7; // x22
  __int64 v8; // x8
  __int64 v9; // x1
  unsigned int v10; // w23
  __int16 v11; // w8
  int v12; // w0
  void *v14; // x0
  void *v15; // x0
  _BYTE v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  v3 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
  if ( !v3 )
  {
    printk(&unk_F0B0, "rmnet_perf_nl_cmd_get_stats");
    v10 = -12;
    goto LABEL_10;
  }
  v4 = v3;
  ++rmnet_perf_netlink_seq;
  v5 = genlmsg_put(v3, 0);
  if ( !v5 )
  {
    v14 = &unk_F0D9;
LABEL_20:
    printk(v14, "rmnet_perf_nl_cmd_get_stats");
    v10 = -12;
    goto LABEL_21;
  }
  v6 = v5;
  v7 = (__int16 *)_kmalloc_cache_noprof(synchronize_rcu, 2336, 1200);
  if ( !v7 )
  {
    v14 = &unk_F45F;
    goto LABEL_20;
  }
  v8 = *(_QWORD *)(a2 + 32);
  v16[0] = 0;
  v9 = *(_QWORD *)(v8 + 8);
  if ( !v9 )
  {
    v15 = &unk_F3B2;
LABEL_16:
    printk(v15, "rmnet_perf_nl_cmd_get_stats");
    goto LABEL_18;
  }
  if ( (int)nla_memcpy(v16, v9, 1) <= 0 )
  {
    v15 = &unk_F1CB;
    goto LABEL_16;
  }
  if ( v16[0] < 0x11u )
  {
    memcpy(v7 + 4, (char *)&stats_store + 1192 * v16[0], 0x4A8u);
    v10 = 0;
    v11 = 0;
    goto LABEL_8;
  }
  printk(&unk_F062, "rmnet_perf_nl_cmd_get_stats");
LABEL_18:
  v11 = 22;
  v10 = -22;
LABEL_8:
  *v7 = v11;
  if ( (unsigned int)nla_put(v4, 2, 1200, v7) )
  {
    printk(&unk_F32D, "rmnet_perf_nl_cmd_get_stats");
    kfree(v7);
LABEL_21:
    sk_skb_reason_drop(0, v4, 2);
    goto LABEL_10;
  }
  kfree(v7);
  *(_DWORD *)(v6 - 20) = *(_DWORD *)(v4 + 216) + *(_DWORD *)(v4 + 208) - (v6 - 20);
  v12 = netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v4, *(unsigned int *)(a2 + 4), 64);
  v10 = v12 & (v12 >> 31);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v10;
}
