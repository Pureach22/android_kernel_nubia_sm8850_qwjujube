__int64 __fastcall kgsl_pwrctrl_clk(__int64 a1, char a2, unsigned int a3)
{
  unsigned __int64 v3; // x20
  __int64 result; // x0
  __int64 v7; // x1
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x8
  __int64 v10; // x1
  unsigned int v11; // w0
  __int64 v12; // x8
  int v13; // w20
  const char *v14; // x21
  int v15; // w0
  const char **v16; // x24
  __int64 v17; // x25
  void (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // x1
  int v20; // w23
  unsigned __int64 v21; // x8
  __int64 v22; // x22
  const char *v23; // x21
  int v24; // w0
  int v25; // w0
  __int64 v26; // x8
  __int64 (__fastcall *v27)(_QWORD); // x8
  unsigned __int64 v34; // x8
  unsigned __int64 v37; // x8
  __int64 (__fastcall *v38)(__int64, __int64); // x8
  __int64 v39; // x1
  __int64 v40; // x8
  __int64 v41; // x1
  unsigned int v42; // w0
  __int64 v43; // x8
  int v44; // w20
  const char *v45; // x21
  __int64 v46; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v48; // x0
  __int64 v49; // x8

  v3 = a3;
  result = gmu_core_gpmu_isenabled(a1);
  if ( (result & 1) != 0 || (*(_QWORD *)(a1 + 9136) & 2) != 0 )
    return result;
  if ( (a2 & 1) != 0 )
  {
    _X9 = (unsigned __int64 *)(a1 + 9128);
    __asm { PRFM            #0x11, [X9] }
    do
      v34 = __ldxr(_X9);
    while ( __stlxr(v34 | 2, _X9) );
    __dmb(0xBu);
    if ( (v34 & 2) != 0 )
      return result;
    if ( *(_DWORD *)(a1 + 10040) >= 0x20u )
      goto LABEL_65;
    v3 = a1 + 9144;
    while ( 1 )
    {
      if ( !*(_DWORD *)v3 )
        goto LABEL_18;
      v7 = *(unsigned int *)(a1 + 10040);
      v8 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8752) + 248LL);
      if ( *((_DWORD *)v8 - 1) != -1642886764 )
        __break(0x8228u);
      v8(a1, v7);
      v9 = *(unsigned int *)(a1 + 9120);
      if ( !(_DWORD)v9 )
        goto LABEL_18;
      if ( (unsigned int)v9 < 0x13 )
      {
        v10 = *(_DWORD *)(a1 + 9124) >= *(_DWORD *)(a1 + 10040) ? 200000000LL : 19200000LL;
        v11 = clk_round_rate(*(_QWORD *)(a1 + 8840 + 8 * v9), v10);
        v12 = *(unsigned int *)(a1 + 9120);
        if ( (unsigned int)v12 <= 0x12 )
          break;
      }
LABEL_65:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v48 = _traceiter_kgsl_clk(0, a1, 1);
        v49 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v49;
        if ( !v49 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v48);
      }
    }
    v13 = v11;
    v14 = clocks[v12];
    v15 = clk_set_rate(*(_QWORD *)(a1 + 8840 + 8 * v12), v11);
    if ( v15 )
    {
      _warn_printk("%s set freq %d failed:%d\n", v14, v13, v15);
      __break(0x800u);
    }
LABEL_18:
    v16 = (const char **)off_1725C0;
    v17 = 1123;
    while ( 1 )
    {
      v22 = *(_QWORD *)(a1 + 8 * v17);
      v23 = *v16;
      v24 = clk_prepare(v22);
      if ( v24 )
      {
        v20 = v24;
      }
      else
      {
        v25 = clk_enable(v22);
        if ( !v25 )
          goto LABEL_27;
        v20 = v25;
        clk_unprepare(v22);
      }
      dev_err(*(_QWORD *)a1, "GPU Clock %s enable error:%d\n", v23, v20);
LABEL_27:
      v21 = v17 - 1105;
      --v17;
      --v16;
      if ( v21 <= 1 )
      {
        result = *(_QWORD *)(a1 + 8992);
        if ( result && !*(_DWORD *)(a1 + 10040) && (*(_BYTE *)(a1 + 10448) & 1) == 0 )
        {
          kgsl_pwrctrl_clk_set_rate(result, *(_DWORD *)(a1 + 10444), "bimc_gpu_clk");
          result = bimc_clk_prepare_enable((_QWORD *)a1, *(_QWORD *)(a1 + 8992));
          *(_BYTE *)(a1 + 10448) = 1;
        }
        v26 = *(_QWORD *)(a1 + 88);
        if ( !v26 )
          return result;
        v27 = *(__int64 (__fastcall **)(_QWORD))(v26 + 48);
        if ( !v27 )
          return result;
LABEL_59:
        if ( *((_DWORD *)v27 - 1) != -919125270 )
          __break(0x8228u);
        return v27(a1 + 56);
      }
    }
  }
  _X9 = (unsigned __int64 *)(a1 + 9128);
  __asm { PRFM            #0x11, [X9] }
  do
    v37 = __ldxr(_X9);
  while ( __stlxr(v37 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
  __dmb(0xBu);
  if ( (v37 & 2) != 0 )
  {
    if ( *(_DWORD *)(a1 + 10040) < 0x20u )
    {
      v3 = *(_QWORD *)(a1 + 8992);
      if ( v3 && *(_BYTE *)(a1 + 10448) == 1 )
      {
        clk_disable(*(_QWORD *)(a1 + 8992));
        clk_unprepare(v3);
        *(_BYTE *)(a1 + 10448) = 0;
      }
      clk_disable(*(_QWORD *)(a1 + 8984));
      clk_disable(*(_QWORD *)(a1 + 8976));
      clk_disable(*(_QWORD *)(a1 + 8968));
      clk_disable(*(_QWORD *)(a1 + 8960));
      clk_disable(*(_QWORD *)(a1 + 8952));
      clk_disable(*(_QWORD *)(a1 + 8944));
      clk_disable(*(_QWORD *)(a1 + 8936));
      clk_disable(*(_QWORD *)(a1 + 8928));
      clk_disable(*(_QWORD *)(a1 + 8920));
      clk_disable(*(_QWORD *)(a1 + 8912));
      clk_disable(*(_QWORD *)(a1 + 8904));
      clk_disable(*(_QWORD *)(a1 + 8896));
      clk_disable(*(_QWORD *)(a1 + 8888));
      clk_disable(*(_QWORD *)(a1 + 8880));
      clk_disable(*(_QWORD *)(a1 + 8872));
      clk_disable(*(_QWORD *)(a1 + 8864));
      clk_disable(*(_QWORD *)(a1 + 8856));
      result = clk_disable(*(_QWORD *)(a1 + 8848));
      if ( !*(_DWORD *)(a1 + 9144) )
        goto LABEL_57;
      clk_unprepare(*(_QWORD *)(a1 + 8984));
      clk_unprepare(*(_QWORD *)(a1 + 8976));
      clk_unprepare(*(_QWORD *)(a1 + 8968));
      clk_unprepare(*(_QWORD *)(a1 + 8960));
      clk_unprepare(*(_QWORD *)(a1 + 8952));
      clk_unprepare(*(_QWORD *)(a1 + 8944));
      clk_unprepare(*(_QWORD *)(a1 + 8936));
      clk_unprepare(*(_QWORD *)(a1 + 8928));
      clk_unprepare(*(_QWORD *)(a1 + 8920));
      clk_unprepare(*(_QWORD *)(a1 + 8912));
      clk_unprepare(*(_QWORD *)(a1 + 8904));
      clk_unprepare(*(_QWORD *)(a1 + 8896));
      clk_unprepare(*(_QWORD *)(a1 + 8888));
      clk_unprepare(*(_QWORD *)(a1 + 8880));
      clk_unprepare(*(_QWORD *)(a1 + 8872));
      clk_unprepare(*(_QWORD *)(a1 + 8864));
      clk_unprepare(*(_QWORD *)(a1 + 8856));
      clk_unprepare(*(_QWORD *)(a1 + 8848));
      v38 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8752) + 248LL);
      v39 = (unsigned int)(*(_DWORD *)(a1 + 10068) - 1);
      if ( *((_DWORD *)v38 - 1) != -1642886764 )
        __break(0x8228u);
      result = v38(a1, v39);
      v40 = *(unsigned int *)(a1 + 9120);
      if ( !(_DWORD)v40 )
        goto LABEL_57;
      if ( (unsigned int)v40 >= 0x13 )
        goto LABEL_65;
      v41 = *(_DWORD *)(a1 + 9124) >= *(_DWORD *)(a1 + 10068) - 1 ? 200000000LL : 19200000LL;
      v42 = clk_round_rate(*(_QWORD *)(a1 + 8840 + 8 * v40), v41);
      v43 = *(unsigned int *)(a1 + 9120);
      if ( (unsigned int)v43 > 0x12 )
        goto LABEL_65;
      v44 = v42;
      v45 = clocks[v43];
      result = clk_set_rate(*(_QWORD *)(a1 + 8840 + 8 * v43), v42);
      if ( (_DWORD)result )
      {
        result = _warn_printk("%s set freq %d failed:%d\n", v45, v44, result);
        __break(0x800u);
        v46 = *(_QWORD *)(a1 + 88);
        if ( !v46 )
          return result;
      }
      else
      {
LABEL_57:
        v46 = *(_QWORD *)(a1 + 88);
        if ( !v46 )
          return result;
      }
      v27 = *(__int64 (__fastcall **)(_QWORD))(v46 + 56);
      if ( !v27 )
        return result;
      goto LABEL_59;
    }
    goto LABEL_65;
  }
  if ( (_DWORD)v3 == 128 )
  {
    clk_unprepare(*(_QWORD *)(a1 + 8984));
    clk_unprepare(*(_QWORD *)(a1 + 8976));
    clk_unprepare(*(_QWORD *)(a1 + 8968));
    clk_unprepare(*(_QWORD *)(a1 + 8960));
    clk_unprepare(*(_QWORD *)(a1 + 8952));
    clk_unprepare(*(_QWORD *)(a1 + 8944));
    clk_unprepare(*(_QWORD *)(a1 + 8936));
    clk_unprepare(*(_QWORD *)(a1 + 8928));
    clk_unprepare(*(_QWORD *)(a1 + 8920));
    clk_unprepare(*(_QWORD *)(a1 + 8912));
    clk_unprepare(*(_QWORD *)(a1 + 8904));
    clk_unprepare(*(_QWORD *)(a1 + 8896));
    clk_unprepare(*(_QWORD *)(a1 + 8888));
    clk_unprepare(*(_QWORD *)(a1 + 8880));
    clk_unprepare(*(_QWORD *)(a1 + 8872));
    clk_unprepare(*(_QWORD *)(a1 + 8864));
    clk_unprepare(*(_QWORD *)(a1 + 8856));
    result = clk_unprepare(*(_QWORD *)(a1 + 8848));
    if ( *(_DWORD *)(a1 + 9144) )
    {
      v18 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8752) + 248LL);
      v19 = (unsigned int)(*(_DWORD *)(a1 + 10068) - 1);
      if ( *((_DWORD *)v18 - 1) != -1642886764 )
        __break(0x8228u);
      v18(a1, v19);
      return isense_clk_set_rate(a1 + 8832, *(_DWORD *)(a1 + 10068) - 1);
    }
  }
  return result;
}
