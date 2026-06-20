__int64 __fastcall adreno_get_submit_time(__int64 result, __int64 a2, __int64 *a3)
{
  unsigned int *v3; // x21
  __int64 v5; // x8
  unsigned __int64 StatusReg; // x20
  __int64 (*v12)(void); // x8
  __int64 v13; // x0

  if ( a3 )
  {
    v3 = *(unsigned int **)(a2 + 176);
    v5 = *(_QWORD *)(*(_QWORD *)(result + 14264) + 40LL);
    StatusReg = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v12 = *(__int64 (**)(void))(v5 + 152);
    if ( *((_DWORD *)v12 - 1) != -944375624 )
      __break(0x8228u);
    v13 = v12();
    *a3 = v13;
    a3[1] = sched_clock(v13, v3[1], v3[2], v3[98]);
    result = ktime_get_real_ts64(a3 + 2);
    _WriteStatusReg(DAIF, StatusReg);
  }
  return result;
}
