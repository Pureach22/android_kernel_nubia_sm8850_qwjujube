__int64 __fastcall adreno_gpu_clock_set(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w19
  _QWORD *v7; // x20
  unsigned int v8; // w21
  __int64 (*v9)(void); // x8
  __int64 result; // x0
  int v11; // w0
  unsigned int v12; // w19
  unsigned __int64 StatusReg; // x23
  __int64 v14; // x0
  __int64 v15; // x8

  if ( a2 >= 0x21 )
    goto LABEL_12;
  v8 = *(_DWORD *)(a1 + 10044);
  v6 = a2;
  v7 = (_QWORD *)a1;
  v9 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 160LL) + 48LL);
  if ( !v9 )
  {
    v11 = clk_set_rate(*(_QWORD *)(a1 + 8840), *(unsigned int *)(a1 + 9144 + 28LL * a2));
    if ( v11 )
    {
      v12 = v11;
      dev_err(*v7, "GPU clk freq set failure: %d\n", v11);
      return v12;
    }
LABEL_8:
    if ( v8 <= 0x1F )
      return 0;
LABEL_12:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v14 = _traceiter_kgsl_pwrlevel(0, v7, v6, a4, v8, a6, 0);
      v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v15;
      if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v14);
    }
    return 0;
  }
  if ( *((_DWORD *)v9 - 1) != -1269352808 )
    __break(0x8228u);
  result = v9();
  if ( !(_DWORD)result )
    goto LABEL_8;
  return result;
}
