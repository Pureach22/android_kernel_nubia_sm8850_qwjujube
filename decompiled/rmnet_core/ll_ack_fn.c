__int64 __fastcall ll_ack_fn(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0

  v2 = _alloc_skb(36, 3264, 0, 0xFFFFFFFFLL);
  if ( v2 )
  {
    v3 = v2;
    v4 = _nlmsg_put(v2, *(unsigned int *)(a1 + 32), *(unsigned int *)(a1 + 36), 2, 20, 256);
    *(_QWORD *)(v4 + 16) = 0x1000000000LL;
    *(_WORD *)(v4 + 24) = *(unsigned __int8 *)(a1 + 40);
    *(_WORD *)(v4 + 26) = *(unsigned __int8 *)(a1 + 41);
    *(_DWORD *)(v4 + 28) = *(unsigned __int8 *)(a1 + 42);
    *(_DWORD *)(v4 + 32) = *(_DWORD *)(a1 + 32);
    *(_DWORD *)v4 = *(_DWORD *)(v3 + 216) + *(_DWORD *)(v3 + 208) - v4;
    rtnl_unicast(v3, &init_net, *(unsigned int *)(a1 + 32));
  }
  return kfree(a1);
}
