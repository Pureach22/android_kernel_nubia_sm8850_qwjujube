__int64 __fastcall cfg80211_process_rdev_events(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD *i; // x20

  v1 = *(_QWORD **)(result + 2328);
  for ( i = (_QWORD *)(result + 2328); v1 != i; v1 = (_QWORD *)*v1 )
    result = ((__int64 (__fastcall *)(_QWORD *))cfg80211_process_wdev_events)(v1 - 2);
  return result;
}
