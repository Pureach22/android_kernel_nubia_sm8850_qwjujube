__int64 __fastcall cfg80211_sched_scan_stop_wk(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x20
  _QWORD *v3; // x8
  __int64 v4; // x19
  _QWORD *v5; // x21
  __int64 result; // x0

  v2 = (_QWORD *)(a2 - 448);
  v3 = *(_QWORD **)(a2 - 448);
  if ( v3 != (_QWORD *)(a2 - 448) )
  {
    v4 = a2 - 696;
    do
    {
      v5 = (_QWORD *)*v3;
      if ( *((_BYTE *)v3 - 4) == 1 )
        result = cfg80211_stop_sched_scan_req(v4, v3 - 21, 0);
      v3 = v5;
    }
    while ( v5 != v2 );
  }
  return result;
}
