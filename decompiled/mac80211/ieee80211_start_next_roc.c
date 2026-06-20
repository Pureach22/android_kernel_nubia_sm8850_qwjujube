__int64 __fastcall ieee80211_start_next_roc(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x0

  v1 = *(_QWORD *)(result + 5264);
  if ( v1 == result + 5264 )
    return ieee80211_run_deferred_scan(result);
  if ( (*(_BYTE *)(result + 1470) & 1) == 0 )
  {
    if ( *(_BYTE *)(v1 + 32) == 1 )
    {
      __break(0x800u);
    }
    else if ( *(_QWORD *)(*(_QWORD *)(result + 464) + 472LL) )
    {
      return ieee80211_start_next_roc();
    }
    else
    {
      v2 = *(_QWORD *)(result + 72);
      v3 = result;
      v4 = round_jiffies_relative(125);
      return wiphy_delayed_work_queue(v2, v3 + 5192, v4);
    }
  }
  return result;
}
