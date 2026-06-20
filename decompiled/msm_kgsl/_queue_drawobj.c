__int64 __fastcall queue_drawobj(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x2
  unsigned __int64 StatusReg; // x20
  __int64 v9; // x8

  v3 = *(unsigned int *)(result + 1436);
  if ( (unsigned int)v3 >= 0x80 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_adreno_cmdbatch_queued(0, v2);
      v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v9;
      if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
  }
  else
  {
    v4 = result + 8 * v3;
    v5 = *(_QWORD *)(a2 + 8);
    *(_QWORD *)(v4 + 408) = a2;
    LODWORD(v4) = ((unsigned __int8)*(_DWORD *)(result + 1436) + 1) & 0x7F;
    ++*(_DWORD *)(result + 1512);
    *(_DWORD *)(result + 1436) = v4;
    v6 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 8LL);
    if ( v6 )
      v7 = *(unsigned int *)(v6 + 112);
    else
      v7 = 0;
    return msm_perf_events_update(
             0,
             1,
             v7,
             *(unsigned int *)(v5 + 4),
             *(unsigned int *)(a2 + 20),
             (*(_QWORD *)(a2 + 24) >> 8) & 1LL);
  }
  return result;
}
