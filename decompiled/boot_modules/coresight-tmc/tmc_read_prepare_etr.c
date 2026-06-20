__int64 __fastcall tmc_read_prepare_etr(__int64 a1)
{
  unsigned int v2; // w21
  __int64 v3; // x8

  if ( *(_DWORD *)(a1 + 140) == 1 )
  {
    mutex_lock(a1 + 152);
    raw_spin_lock_irqsave(a1 + 104);
    if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
    {
      v2 = -16;
    }
    else if ( !*(_QWORD *)(a1 + 288) || (v3 = *(_QWORD *)(a1 + 304)) != 0 && (*(_BYTE *)(v3 + 144) & 1) != 0 )
    {
      v2 = -22;
    }
    else
    {
      if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(a1 + 16) + 968LL) == 1 )
        _tmc_etr_disable_hw((_QWORD *)a1);
      v2 = 0;
      *(_BYTE *)(a1 + 112) = 1;
    }
    raw_spin_unlock_irqrestore(a1 + 104);
    mutex_unlock(a1 + 152);
  }
  else
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  return v2;
}
