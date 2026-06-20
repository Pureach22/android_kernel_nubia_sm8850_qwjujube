__int64 __fastcall tmc_read_prepare_etb(__int64 a1)
{
  unsigned int v2; // w21
  __int64 v3; // x8

  if ( (*(_DWORD *)(a1 + 140) & 0xFFFFFFFD) != 0 )
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  raw_spin_lock_irqsave(a1 + 104);
  if ( (*(_BYTE *)(a1 + 112) & 1) == 0 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    if ( (unsigned int)*(_QWORD *)(v3 + 968) == 2 || !*(_QWORD *)(a1 + 120) )
      goto LABEL_9;
    if ( (unsigned int)*(_QWORD *)(v3 + 968) == 1 )
    {
      if ( *(_BYTE *)(a1 + 408) != 1 || (unsigned int)readl_relaxed_0(*(_QWORD *)(a1 + 8) + 40LL) )
      {
LABEL_9:
        v2 = -22;
        goto LABEL_10;
      }
      _tmc_etb_disable_hw(a1);
    }
    v2 = 0;
    *(_BYTE *)(a1 + 112) = 1;
    goto LABEL_10;
  }
  v2 = -16;
LABEL_10:
  raw_spin_unlock_irqrestore(a1 + 104);
  return v2;
}
