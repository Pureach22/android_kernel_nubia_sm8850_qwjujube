__int64 __fastcall sub_7D260(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( (a5 & 0x1000000000000LL) == 0 )
    JUMPOUT(0x7953C);
  return _cfg80211_stop_sched_scan(a1, a2, a3);
}
