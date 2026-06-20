__int64 __fastcall tmc_shutdown(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  int v3; // w8

  v1 = *(_QWORD *)(a1 + 152);
  raw_spin_lock_irqsave(v1 + 104);
  v2 = *(_QWORD *)(v1 + 16);
  if ( v2 )
  {
    if ( (unsigned int)*(_QWORD *)(v2 + 968) )
    {
      if ( *(_DWORD *)(v1 + 140) == 1 )
      {
        v3 = *(_DWORD *)(v1 + 332);
        if ( v3 == 1 || v3 == 2 && *(_DWORD *)(*(_QWORD *)(v1 + 336) + 8LL) == 1 )
          tmc_etr_disable_hw(v1);
      }
    }
  }
  return raw_spin_unlock_irqrestore(v1 + 104);
}
