__int64 __fastcall _cfg80211_stop_sched_scan(__int64 a1, __int64 a2, char a3)
{
  _QWORD *v3; // x9

  v3 = (_QWORD *)(a1 + 248);
  while ( 1 )
  {
    v3 = (_QWORD *)*v3;
    if ( v3 == (_QWORD *)(a1 + 248) )
      break;
    if ( *(v3 - 21) == a2 )
    {
      if ( v3 != &_ksymtab_cfg80211_cac_event )
        return cfg80211_stop_sched_scan_req(a1, v3 - 21, a3 & 1);
      return 4294967294LL;
    }
  }
  return 4294967294LL;
}
