__int64 __fastcall ipa_fw_nl_broadcast(const void *a1, unsigned int a2)
{
  signed int v4; // w22
  _DWORD *v5; // x0
  __int64 v6; // x21
  _WORD *v7; // x0

  v4 = (a2 + 23) & 0xFFFFFFFC;
  v5 = (_DWORD *)_netdev_alloc_skb(0, (unsigned int)v4, 2080);
  if ( !v5 )
    return 16;
  v6 = (__int64)v5;
  if ( v5[29] )
  {
    if ( v4 > 0 )
      goto LABEL_8;
LABEL_6:
    v7 = (_WORD *)_nlmsg_put(v5, 0);
    if ( v7 )
    {
      v7[8] = 1;
      v7[9] = a2;
      qdf_mem_copy(v7 + 10, a1, a2);
      nl_srv_bcast(v6, 7u, 30);
      ++dword_864E8C;
      return 0;
    }
    goto LABEL_8;
  }
  if ( v5[53] - v5[52] >= v4 )
    goto LABEL_6;
LABEL_8:
  consume_skb(v6);
  return 16;
}
