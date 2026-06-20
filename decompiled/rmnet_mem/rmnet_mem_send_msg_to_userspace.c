__int64 __fastcall rmnet_mem_send_msg_to_userspace(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x22

  v4 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
  if ( v4 )
  {
    v5 = v4;
    v6 = genlmsg_put(v4, 0, 0, &rmnet_mem_nl_family, 0, 1);
    if ( v6 && (v7 = v6, !(unsigned int)nla_put(v5, 4, 1002, a2)) )
    {
      *(_DWORD *)(v7 - 20) = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (v7 - 20);
      if ( (netlink_unicast(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 288LL), v5, *(unsigned int *)(a1 + 4), 64) & 0x80000000) == 0 )
        return 0;
    }
    else
    {
      kfree(v5);
    }
  }
  return 0xFFFFFFFFLL;
}
