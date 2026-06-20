__int64 __fastcall kgsl_cooling_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x29
  __int64 v3; // x9
  __int64 v5; // x8
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // [xsp+38h] [xbp+8h]

  v3 = *(_QWORD *)(a1 + 944);
  if ( (unsigned int)(*(_DWORD *)(v3 + 10068) - 1) < a2 )
    return 4294967274LL;
  v5 = *(unsigned int *)(v3 + 10048);
  if ( v5 == a2 )
    return 0;
  if ( a2 >= 0x20 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      *(_QWORD *)(v2 + 24) = a2;
      v9 = v3;
      v7 = _traceiter_kgsl_thermal_constraint(0, (unsigned int)v5);
      v3 = v9;
      a2 = *(_QWORD *)(v2 + 24);
      v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v8;
      if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v7);
        v3 = v9;
        a2 = *(_QWORD *)(v2 + 24);
      }
    }
  }
  *(_DWORD *)(v3 + 10048) = a2;
  kthread_queue_work(*(_QWORD *)(v3 + 10960), v3 + 10968);
  return 0;
}
