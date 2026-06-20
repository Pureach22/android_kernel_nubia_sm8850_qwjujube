__int64 __fastcall ieee80211_ibss_notify_scan_completed(__int64 result)
{
  __int64 *i; // x8

  for ( i = *(__int64 **)(result + 4616); i != (__int64 *)(result + 4616); i = (__int64 *)*i )
  {
    if ( (i[204] & 1) != 0 && *((_DWORD *)i + 1180) == 1 )
      i[291] = jiffies;
  }
  return result;
}
