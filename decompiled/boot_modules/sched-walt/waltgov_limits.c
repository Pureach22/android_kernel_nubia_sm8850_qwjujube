__int64 __fastcall waltgov_limits(__int64 a1)
{
  __int64 v1; // x23
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x20
  unsigned int v6; // w22
  unsigned __int64 v7; // x21
  int v8; // w0
  unsigned __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x1
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned int v16; // w8
  __int64 v17; // x0

  v1 = *(_QWORD *)(a1 + 88);
  if ( (*(_BYTE *)(a1 + 609) & 1) == 0 )
  {
    mutex_lock(v1 + 280);
    v11 = raw_spin_lock_irqsave(v1 + 152);
    v12 = *(unsigned int *)(*(_QWORD *)v1 + 60LL);
    v14 = walt_sched_clock(v11, v13);
    v15 = *(_QWORD *)(v1 + 8) + (unsigned int)sched_ravg_window;
    if ( v15 >= v14 )
      v15 = v14;
    *(_QWORD *)(v1 + 16) += (v15 - *(_QWORD *)(v1 + 24)) * v12 / 0xF4240;
    *(_QWORD *)(v1 + 24) = v15;
    raw_spin_unlock_irqrestore(v1 + 152, v11);
    v16 = *(_DWORD *)(a1 + 60);
    if ( *(_DWORD *)(a1 + 56) >= v16 )
    {
      if ( *(_DWORD *)(a1 + 52) <= v16 )
      {
LABEL_15:
        result = mutex_unlock(v1 + 280);
        goto LABEL_16;
      }
      v17 = a1;
    }
    else
    {
      v17 = a1;
    }
    _cpufreq_driver_target(v17);
    goto LABEL_15;
  }
  v3 = raw_spin_lock_irqsave(v1 + 152);
  v5 = v3;
  if ( (*(_BYTE *)(v1 + 394) & 1) == 0 )
  {
    v6 = *(_DWORD *)(a1 + 60);
    v7 = walt_sched_clock(v3, v4);
    v8 = cpufreq_driver_resolve_freq(a1, v6);
    if ( *(_DWORD *)(v1 + 192) != v8 )
    {
      *(_QWORD *)(v1 + 160) = v7;
      *(_DWORD *)(v1 + 192) = v8;
      *(_DWORD *)(v1 + 196) = v8;
      v9 = *(_QWORD *)(v1 + 8) + (unsigned int)sched_ravg_window;
      if ( v9 >= v7 )
        v9 = v7;
      *(_QWORD *)(v1 + 16) += (v9 - *(_QWORD *)(v1 + 24)) * *(unsigned int *)(*(_QWORD *)v1 + 60LL) / 0xF4240;
      *(_QWORD *)(v1 + 24) = v9;
      cpufreq_driver_fast_switch();
    }
  }
  result = raw_spin_unlock_irqrestore(v1 + 152, v5);
LABEL_16:
  *(_BYTE *)(v1 + 392) = 1;
  return result;
}
