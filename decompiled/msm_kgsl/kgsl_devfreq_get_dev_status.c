__int64 __fastcall kgsl_devfreq_get_dev_status(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  __int64 v4; // x0
  _QWORD *v5; // x21
  __int64 updated; // x0
  __int64 v7; // x2
  unsigned int v8; // w8
  __int64 v9; // x1
  __int64 v10; // x9
  __int64 v11; // x11
  __int64 v12; // x9
  int v13; // w10
  unsigned int v14; // w9
  unsigned __int64 StatusReg; // x20
  __int64 v17; // x0
  __int64 v18; // x8

  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
    return 4294967277LL;
  if ( !a2 )
    return 4294967274LL;
  if ( *(_BYTE *)(v2 + 12960) == 1 )
  {
    v4 = rt_mutex_lock(v2 + 11088);
    v5 = (_QWORD *)ktime_get(v4);
    updated = kgsl_pwrscale_update_stats(v2);
    *a2 = (ktime_get(updated) - *(_QWORD *)(v2 + 11888)) / 1000;
    v7 = *(_QWORD *)(v2 + 11856);
    *(_QWORD *)(v2 + 11888) = v5;
    a2[1] = v7;
    v8 = *(_DWORD *)(v2 + 10040);
    if ( v8 < 0x20 )
    {
      v9 = *a2;
      v10 = *(unsigned int *)(v2 + 9144 + 28LL * v8);
      a2[2] = v10;
      a2[3] = v2 + 12984;
      if ( *(_BYTE *)(v2 + 10368) != 1 )
      {
LABEL_8:
        v5 = (_QWORD *)(v2 + 11856);
        kgsl_pwrctrl_busy_time(v2, v9, v7);
LABEL_9:
        v5[1] = 0;
        v5[2] = 0;
        *v5 = 0;
        rt_mutex_unlock(v2 + 11088);
        return 0;
      }
      v11 = *(_QWORD *)(v2 + 11864);
      last_status_2 = v10;
      v12 = *(_QWORD *)(v2 + 11872);
      v13 = *(_DWORD *)(v2 + 10936);
      last_xstats = v11;
      qword_17D170 = v12;
      v14 = *(_DWORD *)(v2 + 10060);
      LODWORD(qword_17D178) = v13;
      last_status_0 = v9;
      last_status_1 = v7;
      if ( v14 < 0x21 )
      {
        qword_17D180 = *(unsigned int *)(v2 + 9144 + 28LL * v14);
        goto LABEL_8;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v17 = _traceiter_kgsl_pwrstats(0, v2, v7, v5);
      v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v18;
      if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v17);
    }
    goto LABEL_9;
  }
  return 4294967225LL;
}
