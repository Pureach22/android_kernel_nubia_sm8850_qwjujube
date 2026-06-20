__int64 __fastcall update_cpu_capacity_helper(__int64 result)
{
  __int64 v1; // x10
  char *v2; // x8
  unsigned __int64 v3; // x2
  __int64 v4; // x9
  unsigned __int64 v5; // x10
  __int64 v6; // x12
  unsigned __int64 v7; // x11
  unsigned int v8; // w15
  unsigned __int64 v9; // x11
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x8

  if ( (unsigned int)result >= 0x20 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_update_cpu_capacity(0);
      v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v11;
      if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
  }
  else if ( (walt_disabled & 1) == 0 )
  {
    v1 = *((_QWORD *)&_per_cpu_offset + (unsigned int)result);
    v2 = (char *)&walt_rq + v1;
    v3 = *(_QWORD *)((char *)&cpu_scale + v1);
    v4 = *(_QWORD *)((char *)&walt_rq + v1 + 8);
    v5 = v3 - *(_QWORD *)((char *)&hw_pressure + v1);
    LODWORD(v6) = *(_DWORD *)(v4 + 48);
    v7 = *(unsigned int *)(v4 + 40);
    if ( (_DWORD)v6 != (_DWORD)v7 )
    {
      v8 = *(_DWORD *)(v4 + 44);
      if ( (unsigned int)v6 >= v8 )
        v6 = v8;
      else
        v6 = (unsigned int)v6;
      v3 = v3 % v7 * v6 / v7 + v3 / v7 * v6;
    }
    if ( v3 >= v5 )
      v9 = v5;
    else
      v9 = v3;
    *((_QWORD *)v2 + 79) = v9;
    *(_QWORD *)(v4 + 56) = v5;
  }
  return result;
}
