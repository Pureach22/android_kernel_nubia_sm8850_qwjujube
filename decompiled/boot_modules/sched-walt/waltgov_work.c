__int64 __fastcall waltgov_work(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x22
  __int64 v4; // x23
  __int64 v5; // x1
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x8

  v1 = a1 - 88;
  v3 = raw_spin_lock_irqsave(a1 - 88);
  v4 = *(unsigned int *)(*(_QWORD *)(a1 - 240) + 60LL);
  v6 = walt_sched_clock(v3, v5);
  v7 = *(_QWORD *)(a1 - 232) + (unsigned int)sched_ravg_window;
  if ( v7 >= v6 )
    v7 = v6;
  *(_QWORD *)(a1 - 224) += (v7 - *(_QWORD *)(a1 - 216)) * v4 / 0xF4240;
  *(_QWORD *)(a1 - 216) = v7;
  raw_spin_unlock_irqrestore(v1, v3);
  mutex_lock(a1 + 40);
  _cpufreq_driver_target(*(_QWORD *)(a1 - 240));
  return mutex_unlock(a1 + 40);
}
