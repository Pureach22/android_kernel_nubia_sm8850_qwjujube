__int64 __fastcall cfg80211_remove_link(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  unsigned int v3; // w20
  __int64 v4; // x22
  __int64 v5; // x21
  int v6; // w8
  _DWORD *v7; // x8
  __int64 v8; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x8

  v5 = *(_QWORD *)result;
  if ( !*(_QWORD *)result )
    goto LABEL_12;
  v6 = *(_DWORD *)(result + 8);
  v2 = result;
  v3 = a2;
  v4 = v5 - 992;
  if ( v6 == 9 || v6 == 3 )
    result = cfg80211_stop_ap(v5 - 992, *(_QWORD *)(result + 32), a2, 1);
  while ( 1 )
  {
    v7 = *(_DWORD **)(*(_QWORD *)v4 + 56LL);
    if ( v7 )
    {
      if ( *(v7 - 1) != -234350869 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v7)(v5, v2, v3);
    }
    *(_WORD *)(v2 + 1472) &= ~(unsigned __int16)(1LL << v3);
    if ( v3 < 0xF )
      break;
    __break(0x5512u);
LABEL_12:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_rdev_del_intf_link(0, v5, v2, v3);
      v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v12;
      if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
        result = preempt_schedule_notrace(result, v10, v11);
    }
  }
  v8 = v2 + 72LL * v3;
  *(_WORD *)(v8 + 396) = 0;
  *(_DWORD *)(v8 + 392) = 0;
  return result;
}
