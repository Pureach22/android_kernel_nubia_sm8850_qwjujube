__int64 __fastcall cfg80211_release_pmsr(__int64 a1, int a2)
{
  _QWORD *i; // x22

  raw_spin_lock_bh(a1 + 232);
  for ( i = *(_QWORD **)(a1 + 216); i != (_QWORD *)(a1 + 216); i = (_QWORD *)*i )
  {
    if ( *((_DWORD *)i - 5) == a2 )
    {
      *((_DWORD *)i - 5) = 0;
      queue_work_on(32, system_wq, a1 + 240);
    }
  }
  return raw_spin_unlock_bh(a1 + 232);
}
