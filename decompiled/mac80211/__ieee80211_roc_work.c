__int64 __fastcall _ieee80211_roc_work(__int64 result)
{
  __int64 *v1; // x21
  __int64 v2; // x19
  __int64 v3; // x22
  char v4; // w23
  __int64 v5; // x20
  __int64 v6; // x24
  __int64 *v7; // x25
  __int64 v8; // x26
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x2
  __int64 v14; // x1
  __int64 v15; // x0

  if ( *(_QWORD *)(*(_QWORD *)(result + 464) + 472LL) )
  {
LABEL_30:
    __break(0x800u);
    return result;
  }
  v1 = *(__int64 **)(result + 5264);
  v2 = result;
  v3 = result + 5264;
  if ( v1 != (__int64 *)(result + 5264) && v1 )
  {
    if ( (v1[4] & 1) == 0 )
    {
      if ( (*(_BYTE *)(result + 1400) & 1) == 0 )
        __break(0x800u);
      return ieee80211_start_next_roc(v2);
    }
    v4 = *((_BYTE *)v1 + 36);
    v5 = 0x7FFFFFFFFFFFFFFFLL;
    v6 = jiffies;
    do
    {
      if ( *((_BYTE *)v1 + 32) != 1 )
        break;
      v7 = (__int64 *)*v1;
      v8 = v1[5];
      v9 = _msecs_to_jiffies(*((unsigned int *)v1 + 12));
      if ( (*((_BYTE *)v1 + 33) & 1) != 0 || (*((_BYTE *)v1 + 34) & 1) != 0 || (v10 = v9 + v8 - v6, v10 <= 0) )
      {
        ieee80211_roc_notify_destroy(v1);
      }
      else if ( v5 >= v10 )
      {
        v5 = v9 + v8 - v6;
      }
      v1 = v7;
    }
    while ( v7 != (__int64 *)v3 );
    if ( v5 != 0x7FFFFFFFFFFFFFFFLL )
    {
      v15 = *(_QWORD *)(v2 + 72);
      v13 = v5;
      v14 = v2 + 5192;
      return wiphy_delayed_work_queue(v15, v14, v13);
    }
    if ( (v4 & 1) == 0 )
    {
      ieee80211_flush_queues(v2, 0, 0);
      *(_QWORD *)(v2 + 4976) = 0;
      ieee80211_hw_conf_chan(v2);
      ieee80211_offchannel_return(v2);
    }
    result = ieee80211_recalc_idle(v2);
    v11 = *(_QWORD *)(v2 + 5264);
    if ( v11 == v3 )
    {
      return ieee80211_run_deferred_scan(v2);
    }
    else if ( (*(_BYTE *)(v2 + 1470) & 1) == 0 )
    {
      if ( *(_BYTE *)(v11 + 32) != 1 )
      {
        if ( !*(_QWORD *)(*(_QWORD *)(v2 + 464) + 472LL) )
        {
          v12 = *(_QWORD *)(v2 + 72);
          v13 = round_jiffies_relative(125);
          v14 = v2 + 5192;
          v15 = v12;
          return wiphy_delayed_work_queue(v15, v14, v13);
        }
        return ieee80211_start_next_roc(v2);
      }
      goto LABEL_30;
    }
  }
  return result;
}
