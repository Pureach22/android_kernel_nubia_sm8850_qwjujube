__int64 __fastcall sub_7748C(__int64 a1)
{
  __int64 v1; // x19

  if ( v1 )
    JUMPOUT(0xFFFFFFFFFFFADF3CLL);
  return ieee80211_request_sched_scan_stop(a1);
}
