void __fastcall ieee80211_hw_roc_done(__int64 a1, __int64 a2)
{
  __int64 v3; // x22
  __int64 *v4; // x20
  __int64 *v5; // x21
  __int64 v6; // x9
  __int64 *v7; // x23
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 v11; // x0

  v3 = jiffies;
  v5 = (__int64 *)(a2 - 40);
  v4 = *(__int64 **)(a2 - 40);
  if ( v4 != (__int64 *)(a2 - 40) )
  {
    do
    {
      if ( *((_BYTE *)v4 + 32) != 1 )
        break;
      v7 = (__int64 *)*v4;
      v8 = v4[5];
      v9 = _msecs_to_jiffies(*((unsigned int *)v4 + 12));
      if ( (*((_BYTE *)v4 + 33) & 1) != 0 || (*((_BYTE *)v4 + 34) & 1) != 0 || v9 + v8 - v3 <= 0 )
        ieee80211_roc_notify_destroy(v4);
      v4 = v7;
    }
    while ( v7 != v5 );
  }
  v6 = *(_QWORD *)(a2 - 40);
  if ( (__int64 *)v6 == v5 )
  {
    ieee80211_run_deferred_scan(v5 - 658);
  }
  else if ( (*(_BYTE *)(a2 - 3834) & 1) == 0 )
  {
    if ( *(_BYTE *)(v6 + 32) == 1 )
    {
      __break(0x800u);
    }
    else if ( *(_QWORD *)(*(_QWORD *)(a2 - 4840) + 472LL) )
    {
      ieee80211_start_next_roc((__int64)(v5 - 658));
    }
    else
    {
      v10 = *(_QWORD *)(a2 - 5232);
      v11 = round_jiffies_relative(125);
      wiphy_delayed_work_queue(v10, a2 - 112, v11);
    }
  }
}
