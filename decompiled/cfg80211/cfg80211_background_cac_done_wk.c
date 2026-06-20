__int64 __fastcall cfg80211_background_cac_done_wk(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21

  v2 = a1 - 512;
  v3 = a1 - 32;
  mutex_lock(a1 + 480);
  _cfg80211_background_cac_event(v2, *(_QWORD *)(a1 - 40), v3, 1);
  return mutex_unlock(a1 + 480);
}
