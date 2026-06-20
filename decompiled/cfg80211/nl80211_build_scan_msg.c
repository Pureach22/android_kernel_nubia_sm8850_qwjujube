__int64 nl80211_build_scan_msg()
{
  __int64 result; // x0
  __int64 v1; // x21

  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v1 = result;
    if ( (((__int64 (*)(void))nl80211_prep_scan_msg)() & 0x80000000) != 0 )
    {
      sk_skb_reason_drop(0, v1, 2);
      return 0;
    }
    else
    {
      return v1;
    }
  }
  return result;
}
