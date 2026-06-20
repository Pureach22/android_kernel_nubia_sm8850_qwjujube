__int64 __fastcall cfg80211_pmsr_wdev_down(__int64 a1)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x20
  __int64 result; // x0

  raw_spin_lock_bh(a1 + 232);
  v3 = (_QWORD *)(a1 + 216);
  v2 = *(_QWORD **)(a1 + 216);
  if ( v2 == (_QWORD *)(a1 + 216) )
  {
    result = raw_spin_unlock_bh(a1 + 232);
  }
  else
  {
    do
    {
      *((_DWORD *)v2 - 5) = 0;
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != v3 );
    raw_spin_unlock_bh(a1 + 232);
    result = ((__int64 (__fastcall *)(__int64))cfg80211_pmsr_process_abort)(a1);
  }
  if ( (_QWORD *)*v3 != v3 )
    __break(0x800u);
  return result;
}
