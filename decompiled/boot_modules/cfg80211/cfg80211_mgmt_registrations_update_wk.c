__int64 __fastcall cfg80211_mgmt_registrations_update_wk(__int64 a1)
{
  _QWORD *i; // x20

  mutex_lock(a1 + 112);
  for ( i = *(_QWORD **)(a1 + 1448); i != (_QWORD *)(a1 + 1448); i = (_QWORD *)*i )
    cfg80211_mgmt_registrations_update(i - 2);
  return mutex_unlock(a1 + 112);
}
