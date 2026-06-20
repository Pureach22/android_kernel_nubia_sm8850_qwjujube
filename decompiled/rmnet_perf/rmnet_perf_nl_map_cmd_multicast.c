__int64 __fastcall rmnet_perf_nl_map_cmd_multicast(__int64 a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x19
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x22
  unsigned int v7; // w8
  __int64 v8; // x9
  unsigned __int16 v9; // w8
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 result; // x0
  void *v13; // x0
  void *v14; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v16; // x24

  v2 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
  if ( !v2 )
    return printk(&unk_F387, "rmnet_perf_nl_map_cmd_multicast");
  v3 = (_DWORD *)v2;
  ++rmnet_perf_netlink_seq;
  v4 = genlmsg_put(v2, 0);
  if ( v4 )
  {
    v5 = v4;
    v6 = _kmalloc_cache_noprof(netlink_unicast, 2336, 4100);
    if ( v6 )
    {
      while ( 1 )
      {
        v7 = *(_DWORD *)(a1 + 112);
        if ( v7 < 0xD )
          break;
        v8 = *(_QWORD *)(a1 + 224);
        v9 = v7 - 12;
        *(_WORD *)v6 = v9;
        *(_BYTE *)(v6 + 2) = *(_BYTE *)(v8 + 4);
        *(_BYTE *)(v6 + 3) = *(_BYTE *)(v8 + 5) & 3;
        if ( v9 <= 0x1000u )
        {
          memcpy((void *)(v6 + 4), (const void *)(*(_QWORD *)(a1 + 224) + 12LL), v9);
          if ( !(unsigned int)nla_put(v3, 5, 4100, v6) )
          {
            *(_DWORD *)(v5 - 20) = v3[54] + v3[52] - (v5 - 20);
            kfree(v6);
            if ( byte_F590 )
            {
              v10 = (unsigned int)dword_F604;
              v11 = raw_spin_unlock_irqrestore;
              v3[14] = dword_F604;
              result = netlink_broadcast_filtered(v11, v3, 0, v10, 2080, 0, 0);
              if ( (_DWORD)result != -22 )
                return result;
            }
            else
            {
              __break(0x800u);
            }
            v13 = &unk_F01F;
            goto LABEL_18;
          }
          v14 = &unk_F0FF;
LABEL_14:
          printk(v14, "rmnet_perf_nl_map_cmd_multicast");
          kfree(v6);
          return sk_skb_reason_drop(0, v3, 2);
        }
        _fortify_panic(17, 4096, v9);
        StatusReg = _ReadStatusReg(SP_EL0);
        v16 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &rmnet_perf_nl_map_cmd_multicast__alloc_tag;
        v6 = _kmalloc_cache_noprof(netlink_unicast, 2336, 4100);
        *(_QWORD *)(StatusReg + 80) = v16;
        if ( !v6 )
          goto LABEL_17;
      }
      v14 = &unk_F1F9;
      goto LABEL_14;
    }
LABEL_17:
    v13 = &unk_F3F0;
  }
  else
  {
    v13 = &unk_F0D9;
  }
LABEL_18:
  printk(v13, "rmnet_perf_nl_map_cmd_multicast");
  return sk_skb_reason_drop(0, v3, 2);
}
