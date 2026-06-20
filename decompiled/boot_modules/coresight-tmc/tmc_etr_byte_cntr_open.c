__int64 __fastcall tmc_etr_byte_cntr_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v5; // x19
  unsigned int v6; // w19
  __int64 rwp_offset; // x0

  v2 = *(_QWORD *)(a1 + 656);
  v5 = *(_QWORD *)(v2 + 368);
  mutex_lock(v2 + 312);
  if ( (*(_BYTE *)(v2 + 145) & 1) != 0 )
  {
    v6 = -16;
  }
  else if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(v5 + 16) + 968LL) == 1 && *(_DWORD *)(v2 + 152) )
  {
    irq_set_irq_wake(*(unsigned int *)(v2 + 156), 1);
    coresight_csr_set_byte_cntr(*(_QWORD *)(v2 + 360), *(unsigned int *)(v2 + 392), *(_DWORD *)(v2 + 152) >> 3);
    *(_QWORD *)(a2 + 32) = v2;
    nonseekable_open(a1, a2);
    *(_QWORD *)(v2 + 416) = 0;
    *(_WORD *)(v2 + 144) = 257;
    rwp_offset = tmc_get_rwp_offset(v5);
    v6 = 0;
    *(_QWORD *)(v2 + 424) = 0;
    *(_QWORD *)(v2 + 400) = rwp_offset;
  }
  else
  {
    v6 = -22;
  }
  mutex_unlock(v2 + 312);
  return v6;
}
