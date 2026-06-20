__int64 __fastcall ieee80211_sta_reset_conn_monitor(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( (*(_BYTE *)(result + 2477) & 8) != 0 )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 2472) )
      *(_DWORD *)(result + 2472) = 0;
    if ( (*(_QWORD *)(*(_QWORD *)(result + 1616) + 96LL) & 0x20000) == 0 )
    {
      v2 = round_jiffies_up(jiffies + 7500LL);
      return mod_timer(v1 + 2304, v2);
    }
  }
  return result;
}
