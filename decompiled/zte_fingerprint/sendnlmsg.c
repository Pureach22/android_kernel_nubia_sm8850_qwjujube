__int64 __fastcall sendnlmsg(_BYTE *a1)
{
  __int64 result; // x0
  _BYTE *v3; // x22
  _DWORD *v4; // x0
  _DWORD *v5; // x19
  __int64 v6; // x0
  int v7; // w19

  result = 4294967277LL;
  if ( a1 && nl_sk && pid )
  {
    v3 = a1;
    v4 = (_DWORD *)_alloc_skb(48, 2080, 0, 0xFFFFFFFFLL);
    if ( v4 )
    {
      v5 = v4;
      if ( !v4[29] && v4[53] - v4[52] >= 48 && (v6 = _nlmsg_put(v4, 0, 0, 0, 32, 0)) != 0 )
      {
        *(_QWORD *)(v5 + 13) = 0;
        *(_BYTE *)(v6 + 16) = *v3;
        printk(&unk_960F);
        v7 = netlink_unicast(nl_sk, v5, (unsigned int)pid, 64);
        printk(&unk_9635);
        return v7 & (unsigned int)(v7 >> 31);
      }
      else
      {
        sk_skb_reason_drop(0, v5, 2);
        return 4294967206LL;
      }
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
