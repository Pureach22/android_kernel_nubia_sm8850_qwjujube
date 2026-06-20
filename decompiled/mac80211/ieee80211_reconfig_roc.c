__int64 __fastcall ieee80211_reconfig_roc(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x0

  if ( *(_QWORD *)(*(_QWORD *)(result + 464) + 472LL) )
  {
    v1 = result;
    wiphy_work_flush(*(_QWORD *)(result + 72), result + 5280);
    wiphy_work_flush(*(_QWORD *)(v1 + 72), v1 + 5304);
    result = *(_QWORD *)(v1 + 5264);
    v2 = v1 + 5264;
    if ( result != v1 + 5264 )
    {
      do
      {
        if ( *(_BYTE *)(result + 32) != 1 )
          break;
        v3 = *(_QWORD *)result;
        if ( (*(_BYTE *)(result + 34) & 1) != 0 )
          ieee80211_roc_notify_destroy();
        else
          *(_BYTE *)(result + 32) = 0;
        result = v3;
      }
      while ( v3 != v2 );
    }
    if ( *(_QWORD *)v2 == v2 )
    {
      return ieee80211_run_deferred_scan(v1);
    }
    else if ( (*(_BYTE *)(v1 + 1470) & 1) == 0 )
    {
      if ( *(_BYTE *)(*(_QWORD *)v2 + 32LL) == 1 )
      {
        __break(0x800u);
      }
      else if ( *(_QWORD *)(*(_QWORD *)(v1 + 464) + 472LL) )
      {
        return ieee80211_start_next_roc(v1);
      }
      else
      {
        v4 = *(_QWORD *)(v1 + 72);
        v5 = round_jiffies_relative(125);
        return wiphy_delayed_work_queue(v4, v1 + 5192, v5);
      }
    }
  }
  return result;
}
