__int64 __fastcall tmc_etr_byte_cntr_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19

  v2 = *(_QWORD *)(a2 + 32);
  mutex_lock(v2 + 312);
  *(_BYTE *)(v2 + 145) = 0;
  *(_DWORD *)(v2 + 160) = 0;
  if ( *(_BYTE *)(v2 + 144) == 1 )
    coresight_csr_set_byte_cntr(*(_QWORD *)(v2 + 360), *(unsigned int *)(v2 + 392), 0);
  irq_set_irq_wake(*(unsigned int *)(v2 + 156), 0);
  mutex_unlock(v2 + 312);
  return 0;
}
