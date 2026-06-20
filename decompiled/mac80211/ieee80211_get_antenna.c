__int64 __fastcall ieee80211_get_antenna(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v8; // x8

  if ( result )
  {
    v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(result + 2000) + 464LL);
    if ( v5 )
    {
      v6 = result + 1536;
      if ( *((_DWORD *)v5 - 1) != 1196181766 )
        __break(0x8228u);
      return v5(v6);
    }
    else
    {
      return 4294967201LL;
    }
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
      result = _traceiter_drv_get_antenna(0, v4 + 1536, a3, a4, 0);
      v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v8;
      if ( !v8 || (result = 0, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(result);
        return 0;
      }
    }
  }
  return result;
}
