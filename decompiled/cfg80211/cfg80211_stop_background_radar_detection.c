__int64 __fastcall cfg80211_stop_background_radar_detection(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v3; // x20
  _DWORD *v4; // x8
  __int64 v5; // x3
  unsigned __int64 StatusReg; // x21
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x8

  v3 = *(_QWORD *)result;
  if ( *(_QWORD *)result )
  {
    v2 = v3 - 520;
    if ( *(_QWORD *)(v3 - 520) != result )
      return result;
    v1 = v3 - 992;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v7 = _traceiter_rdev_set_radar_background(0, 0, 0);
      v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v10;
      if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v7, v8, v9);
    }
  }
  v4 = *(_DWORD **)(*(_QWORD *)v1 + 952LL);
  if ( v4 )
  {
    if ( *(v4 - 1) != 699476211 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v4)(v3, 0);
  }
  *(_QWORD *)v2 = 0;
  result = cfg80211_chandef_valid((__int64 *)(v3 - 512));
  if ( (result & 1) != 0 )
  {
    if ( *(_QWORD *)v2 )
    {
      result = cancel_delayed_work(v3 - 480);
      if ( (result & 1) != 0 )
      {
        if ( *(_QWORD *)v2 )
          v5 = *(_QWORD *)(*(_QWORD *)v2 + 32LL);
        else
          v5 = 0;
        return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64))nl80211_radar_notify)(
                 v1,
                 v3 - 512,
                 2,
                 v5,
                 3264);
      }
    }
  }
  return result;
}
