__int64 __fastcall rmnet_ll_ipa_tx(_QWORD *a1)
{
  _QWORD *stats; // x0
  __int64 result; // x0
  _QWORD *v4; // x21
  _QWORD *v5; // x9
  _QWORD *v6; // x8

  stats = rmnet_ll_get_stats();
  if ( !rmnet_ll_ipa_ep )
    return 4294967277LL;
  if ( (__int64 *)tx_pending_list != &tx_pending_list )
    goto LABEL_3;
  v4 = stats;
  result = ipa_rmnet_ll_xmit(a1);
  if ( (result & 0x80000000) == 0 )
    return 0;
  if ( (_DWORD)result == -11 )
  {
    stats = v4;
    ++v4[11];
LABEL_3:
    if ( (unsigned int)dword_2FE20 < 0x3E8 )
    {
      v5 = (_QWORD *)qword_2FE18;
      *a1 = &tx_pending_list;
      v6 = stats;
      result = 0;
      a1[1] = v5;
      qword_2FE18 = (__int64)a1;
      *v5 = a1;
      ++dword_2FE20;
      ++v6[13];
    }
    else
    {
      sk_skb_reason_drop(0, a1, 2);
      return 4294967284LL;
    }
  }
  return result;
}
