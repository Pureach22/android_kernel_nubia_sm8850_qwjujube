__int64 __fastcall ieee80211_purge_tx_queue(__int64 result, __int64 a2)
{
  __int64 *v2; // x21
  __int64 v4; // x20
  __int64 v5; // x8
  _QWORD *v6; // x9

  v2 = *(__int64 **)a2;
  if ( *(_QWORD *)a2 != a2 && v2 )
  {
    v4 = result;
    do
    {
      --*(_DWORD *)(a2 + 16);
      v5 = *v2;
      v6 = (_QWORD *)v2[1];
      *v2 = 0;
      v2[1] = 0;
      *(_QWORD *)(v5 + 8) = v6;
      *v6 = v5;
      ieee80211_report_used_skb(v4, (__int64)v2, 1, 0);
      result = dev_kfree_skb_any_reason(v2, 2);
      v2 = *(__int64 **)a2;
    }
    while ( *(_QWORD *)a2 != a2 && v2 );
  }
  return result;
}
