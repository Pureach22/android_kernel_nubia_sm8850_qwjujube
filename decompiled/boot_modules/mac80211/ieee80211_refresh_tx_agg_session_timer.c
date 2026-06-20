__int64 __fastcall ieee80211_refresh_tx_agg_session_timer(__int64 result, unsigned __int16 a2)
{
  __int64 v2; // x8

  if ( a2 >= 0x10u )
  {
    __break(0x800u);
  }
  else
  {
    v2 = *(_QWORD *)(result + 8LL * a2 - 1784);
    if ( v2 )
      *(_QWORD *)(v2 + 136) = jiffies;
  }
  return result;
}
