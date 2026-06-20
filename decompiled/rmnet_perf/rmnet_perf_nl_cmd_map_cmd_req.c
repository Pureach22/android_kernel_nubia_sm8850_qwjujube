__int64 __fastcall rmnet_perf_nl_cmd_map_cmd_req(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  _BYTE *v8; // x22
  __int64 v9; // x1
  unsigned int v10; // w2
  int v11; // w23
  int v12; // w8
  int v13; // w0
  void *v15; // x0
  void *v16; // x0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v3 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
  if ( !v3 )
  {
    printk(&unk_F0B0, "rmnet_perf_nl_cmd_map_cmd_req");
    v11 = -12;
    goto LABEL_16;
  }
  v4 = v3;
  ++rmnet_perf_netlink_seq;
  v5 = genlmsg_put(v3, 0);
  if ( !v5 )
  {
    v11 = -12;
    v15 = &unk_F0D9;
LABEL_20:
    printk(v15, "rmnet_perf_nl_cmd_map_cmd_req");
    sk_skb_reason_drop(0, v4, 2);
    goto LABEL_16;
  }
  v6 = v5;
  v17 = 0;
  v7 = _kmalloc_large_noprof(16388, 2336);
  v8 = (_BYTE *)v7;
  if ( v7 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 24LL);
    if ( v9 )
    {
      if ( (int)nla_memcpy(v7, v9, 16388) <= 0 )
      {
        v16 = &unk_F1CB;
      }
      else
      {
        v10 = (unsigned __int8)v8[2];
        if ( v10 <= 0x2C && ((1LL << v10) & 0x150180000000LL) != 0 )
        {
          if ( *(unsigned __int16 *)v8 < 0x3E81u )
          {
            LOBYTE(v17) = v8[2];
            v11 = rmnet_perf_cmd_xmit(v8);
LABEL_10:
            kfree(v8);
            goto LABEL_11;
          }
          v16 = &unk_F091;
        }
        else
        {
          v16 = &unk_F42B;
        }
      }
    }
    else
    {
      v16 = &unk_F3B2;
    }
    printk(v16, "rmnet_perf_nl_cmd_map_cmd_req");
    v11 = -22;
    goto LABEL_10;
  }
  printk(&unk_F248, "rmnet_perf_nl_cmd_map_cmd_req");
  v11 = -12;
LABEL_11:
  if ( v11 >= 0 )
    LOWORD(v12) = v11;
  else
    v12 = -v11;
  HIWORD(v17) = v12;
  if ( (unsigned int)nla_put(v4, 4, 4, &v17) )
  {
    v15 = &unk_F32D;
    goto LABEL_20;
  }
  *(_DWORD *)(v6 - 20) = *(_DWORD *)(v4 + 216) + *(_DWORD *)(v4 + 208) - (v6 - 20);
  v13 = netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v4, *(unsigned int *)(a2 + 4), 64);
  v11 = v13 & (v13 >> 31);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v11;
}
