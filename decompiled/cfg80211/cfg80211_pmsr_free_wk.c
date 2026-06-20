__int64 __fastcall cfg80211_pmsr_free_wk(__int64 a1)
{
  _QWORD *v1; // x19

  v1 = (_QWORD *)(a1 - 240);
  mutex_lock(*(_QWORD *)(a1 - 240));
  ((void (__fastcall *)(_QWORD *))cfg80211_pmsr_process_abort)(v1);
  return mutex_unlock(*v1);
}
