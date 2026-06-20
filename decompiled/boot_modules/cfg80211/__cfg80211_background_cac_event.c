__int64 __fastcall _cfg80211_background_cac_event(_QWORD *a1, __int64 a2, __int64 *a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x1
  __int64 v13; // x3

  result = cfg80211_chandef_valid(a3);
  if ( (result & 1) != 0 && a1[59] )
  {
    if ( a4 != 5 )
    {
      if ( a4 == 2 )
      {
        result = cancel_delayed_work(a1 + 64);
        if ( (result & 1) == 0 )
          return result;
      }
      else
      {
        if ( a4 != 1 )
          return result;
        cfg80211_set_dfs_state((__int64)(a1 + 124), (__int64)a3, 2);
        v9 = a3[2];
        v10 = *a3;
        v11 = a3[1];
        v12 = cfg80211_wq;
        a1[105] = a3[3];
        a1[104] = v9;
        a1[103] = v11;
        a1[102] = v10;
        queue_work_on(32, v12, a1 + 106);
        cancel_delayed_work(a1 + 46);
        queue_delayed_work_on(32, cfg80211_wq, a1 + 46, 0);
      }
      a2 = a1[59];
    }
    if ( a2 )
      v13 = *(_QWORD *)(a2 + 32);
    else
      v13 = 0;
    return ((__int64 (__fastcall *)(_QWORD *, __int64 *, _QWORD, __int64, __int64))nl80211_radar_notify)(
             a1,
             a3,
             a4,
             v13,
             3264);
  }
  return result;
}
