__int64 __fastcall adreno_hwsched_add_profile_events(__int64 result, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 v4; // x22
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x23
  __int64 (__fastcall *v14)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x2

  _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(a2 + 8);
  if ( a3 )
  {
    v7 = *(_QWORD *)(*(_QWORD *)(result + 14264) + 40LL);
    StatusReg = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v7 + 152);
    if ( *((_DWORD *)v14 - 1) != -944375624 )
      __break(0x8228u);
    v15 = v14(result, a2, a3, a4);
    *a3 = v15;
    a3[1] = sched_clock(v15, *(unsigned int *)(v4 + 4), *(unsigned int *)(v4 + 8), *(unsigned int *)(a2 + 20));
    ktime_get_real_ts64(a3 + 2);
    _WriteStatusReg(DAIF, StatusReg);
    *(_QWORD *)(a2 + 152) = *a3;
    v16 = *(_QWORD *)(*(_QWORD *)(v4 + 24) + 8LL);
    if ( v16 )
      v17 = *(unsigned int *)(v16 + 112);
    else
      v17 = 0;
    msm_perf_events_update(
      0,
      2,
      v17,
      *(unsigned int *)(v4 + 4),
      *(unsigned int *)(a2 + 20),
      (*(_QWORD *)(a2 + 24) >> 8) & 1LL);
    result = log_kgsl_cmdbatch_submitted_event(
               *(unsigned int *)(v4 + 4),
               *(unsigned int *)(a2 + 20),
               *(unsigned int *)(v4 + 8),
               *(_QWORD *)(a2 + 24));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
