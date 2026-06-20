__int64 __fastcall cfg80211_background_cac_abort_wk(__int64 a1)
{
  __int64 *v2; // x20
  __int64 v3; // x8
  __int64 v4; // x3

  v2 = (__int64 *)(a1 - 136);
  mutex_lock(a1 + 376);
  if ( (cfg80211_chandef_valid(v2) & 1) != 0 && *(_QWORD *)(a1 - 144) && (cancel_delayed_work(a1 - 104) & 1) != 0 )
  {
    v3 = *(_QWORD *)(a1 - 144);
    if ( v3 )
      v4 = *(_QWORD *)(v3 + 32);
    else
      v4 = 0;
    ((void (__fastcall *)(__int64, __int64 *, __int64, __int64, __int64))nl80211_radar_notify)(
      a1 - 616,
      v2,
      2,
      v4,
      3264);
  }
  return mutex_unlock(a1 + 376);
}
