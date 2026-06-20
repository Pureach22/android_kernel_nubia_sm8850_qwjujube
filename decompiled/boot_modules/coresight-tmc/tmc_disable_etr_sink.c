__int64 __fastcall tmc_disable_etr_sink(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int v4; // w19

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v2 + 104);
  v3 = *(_QWORD *)(a1 + 968);
  raw_spin_unlock_irqrestore(v2 + 104);
  if ( (_DWORD)v3 == 2 )
    return tmc_disable_etr_sink(a1, 0);
  if ( (_DWORD)v3 != 1 )
    return 4294967274LL;
  mutex_lock(v2 + 152);
  v4 = tmc_disable_etr_sink(a1, 0);
  mutex_unlock(v2 + 152);
  return v4;
}
