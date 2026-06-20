__int64 __fastcall rmnet_mem_genl_send_int_to_userspace_no_info(int a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x22
  __int64 result; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
  if ( v4 )
  {
    v5 = v4;
    v6 = genlmsg_put(v4, 0, 0, &rmnet_mem_nl_family, 0, 1);
    if ( v6 && (v7 = v6, v9 = a1, !(unsigned int)nla_put(v5, 3, 4, &v9)) )
    {
      *(_DWORD *)(v7 - 20) = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (v7 - 20);
      if ( (netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v5, *(unsigned int *)(a2 + 4), 64) & 0x80000000) == 0 )
      {
        result = 0;
        goto LABEL_6;
      }
    }
    else
    {
      kfree(v5);
    }
  }
  result = 0xFFFFFFFFLL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
