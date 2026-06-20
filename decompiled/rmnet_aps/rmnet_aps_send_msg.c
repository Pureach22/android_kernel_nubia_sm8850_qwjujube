__int64 __fastcall rmnet_aps_send_msg(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x24

  if ( !a1 )
    return 4294967274LL;
  v11 = _alloc_skb((unsigned __int8)(((((a4 + 7) & 0x7C) + 7) & 0x7C) + 19) & 0xFC, a6, 0, 0xFFFFFFFFLL);
  if ( v11 )
  {
    v12 = v11;
    v13 = genlmsg_put(v11, 0, (unsigned int)(*(_DWORD *)a1 + 1), &rmnet_aps_genl_family, 0, a2);
    if ( v13 && (v14 = v13, !(unsigned int)nla_put(v12, a3, a4, a5)) )
    {
      *(_DWORD *)(v14 - 20) = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (v14 - 20);
      if ( (netlink_unicast(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 288LL), v12, *(unsigned int *)(a1 + 4), 64) & 0x80000000) == 0 )
        return 0;
    }
    else
    {
      sk_skb_reason_drop(0, v12, 2);
    }
  }
  return 4294967282LL;
}
