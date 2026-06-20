__int64 __fastcall ieee80211_set_antenna(__int64 result, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x21
  __int64 v5; // x29
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x0
  unsigned int v8; // w20
  char v9; // w8
  unsigned __int64 StatusReg; // x20
  __int64 v11; // x8

  if ( result )
  {
    if ( (*(_BYTE *)(result + 3005) & 1) != 0 )
      return 4294967201LL;
    v6 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(result + 2000) + 456LL);
    if ( v6 )
    {
      v4 = result;
      v7 = result + 1536;
      v8 = a3;
      if ( *((_DWORD *)v6 - 1) != 2126203277 )
        __break(0x8228u);
      result = v6(v7);
      a3 = v8;
    }
    else
    {
      v4 = result;
      result = 4294967201LL;
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
      *(_DWORD *)(v5 + 24) = a3;
      *(_DWORD *)(v5 + 28) = 0;
      _traceiter_drv_set_antenna(0, v4 + 1536, v3, *(unsigned int *)(v5 + 24), *(unsigned int *)(v5 + 28));
      a3 = *(_DWORD *)(v5 + 24);
      result = *(unsigned int *)(v5 + 28);
      v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v11;
      if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(result);
        a3 = *(_DWORD *)(v5 + 24);
        result = *(unsigned int *)(v5 + 28);
      }
    }
  }
  if ( !(_DWORD)result )
  {
    v9 = _sw_hweight8(a3);
    result = 0;
    *(_BYTE *)(v4 + 3040) = v9;
  }
  return result;
}
