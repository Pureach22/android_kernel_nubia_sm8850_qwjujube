unsigned __int8 *__fastcall ieee80211_beacon_free_ema_list(unsigned __int8 *result)
{
  unsigned __int8 *v1; // x19
  unsigned __int64 v2; // x20
  __int64 v3; // x21

  if ( result )
  {
    v1 = result;
    if ( *result )
    {
      v2 = 0;
      v3 = 8;
      do
      {
        sk_skb_reason_drop(0);
        ++v2;
        v3 += 24;
      }
      while ( v2 < *v1 );
    }
    return (unsigned __int8 *)kfree(v1);
  }
  return result;
}
