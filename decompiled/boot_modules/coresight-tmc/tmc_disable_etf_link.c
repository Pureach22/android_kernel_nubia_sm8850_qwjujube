__int64 __fastcall tmc_disable_etf_link(__int64 a1)
{
  __int64 v2; // x19
  int v3; // w8
  __int64 v4; // x22
  __int64 v5; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v2 + 104);
  if ( (*(_BYTE *)(v2 + 112) & 1) == 0 && *(_BYTE *)(v2 + 408) == 1 )
  {
    v3 = *(_DWORD *)(a1 + 976) - 1;
    *(_DWORD *)(a1 + 976) = v3;
    if ( !v3 )
    {
      v4 = *(_QWORD *)(v2 + 16);
      writel_relaxed_0(0xC5ACCE55, (unsigned int *)(*(_QWORD *)(v2 + 8) + 4016LL));
      __dsb(0xFu);
      tmc_flush_and_stop(v2);
      tmc_disable_hw(v2);
      coresight_disclaim_device_unlocked(v4);
      v5 = *(_QWORD *)(v2 + 8);
      __dsb(0xFu);
      writel_relaxed_0(0, (unsigned int *)(v5 + 4016));
      *(_QWORD *)(a1 + 968) = 0;
    }
  }
  return raw_spin_unlock_irqrestore(v2 + 104);
}
