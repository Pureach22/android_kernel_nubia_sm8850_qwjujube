__int64 __fastcall tmc_read_unprepare_etb(__int64 a1)
{
  unsigned int v2; // w21
  __int64 v3; // x22

  if ( (*(_DWORD *)(a1 + 140) & 0xFFFFFFFD) != 0 )
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  raw_spin_lock_irqsave(a1 + 104);
  if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(a1 + 16) + 968LL) != 1 )
  {
    v3 = *(_QWORD *)(a1 + 120);
    v2 = 0;
    *(_QWORD *)(a1 + 120) = 0;
LABEL_9:
    *(_BYTE *)(a1 + 112) = 0;
    raw_spin_unlock_irqrestore(a1 + 104);
    kfree(v3);
    return v2;
  }
  if ( *(_BYTE *)(a1 + 408) != 1 )
  {
    v3 = 0;
    v2 = -22;
    goto LABEL_9;
  }
  if ( !(unsigned int)readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + 40LL)) )
  {
    memset(*(void **)(a1 + 120), 0, *(unsigned int *)(a1 + 132));
    _tmc_etb_enable_hw(a1);
    v2 = 0;
    v3 = 0;
    goto LABEL_9;
  }
  raw_spin_unlock_irqrestore(a1 + 104);
  return (unsigned int)-22;
}
