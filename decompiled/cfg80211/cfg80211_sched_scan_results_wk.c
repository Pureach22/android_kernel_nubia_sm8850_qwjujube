__int64 __fastcall cfg80211_sched_scan_results_wk(__int64 a1)
{
  _QWORD *v2; // x24
  _QWORD *v3; // x23
  _QWORD *v4; // x27
  char v5; // w8
  _QWORD *v6; // x1
  __int64 v7; // x28
  int v8; // w26
  _QWORD *v9; // x25

  mutex_lock(a1 + 272);
  v2 = *(_QWORD **)(a1 - 472);
  if ( v2 != (_QWORD *)(a1 - 472) )
  {
    v3 = (_QWORD *)(a1 - 528);
    do
    {
      v4 = (_QWORD *)*v2;
      if ( *((_BYTE *)v2 - 32) == 1 )
      {
        v5 = *((_BYTE *)v2 - 128);
        *((_BYTE *)v2 - 32) = 0;
        if ( (v5 & 2) != 0 )
        {
          raw_spin_lock_bh(a1 - 536);
          v6 = (_QWORD *)*v3;
          if ( (_QWORD *)*v3 != v3 )
          {
            v7 = *(v2 - 5);
            v8 = 0;
            do
            {
              v9 = (_QWORD *)*v6;
              if ( !*((_DWORD *)v6 + 20) && v6[8] - v7 < 0 )
                v8 |= _cfg80211_unlink_bss(a1 - 720);
              v6 = v9;
            }
            while ( v9 != v3 );
            if ( (v8 & 1) != 0 )
              ++*(_DWORD *)(a1 - 504);
          }
          raw_spin_unlock_bh(a1 - 536);
          *(v2 - 5) = jiffies;
        }
        nl80211_send_sched_scan(v2 - 21, 0x4Du);
      }
      v2 = v4;
    }
    while ( v4 != (_QWORD *)(a1 - 472) );
  }
  return mutex_unlock(a1 + 272);
}
