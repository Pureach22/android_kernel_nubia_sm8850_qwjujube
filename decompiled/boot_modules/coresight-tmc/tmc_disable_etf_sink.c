__int64 __fastcall tmc_disable_etf_sink(__int64 a1)
{
  __int64 v2; // x19
  int v3; // w8
  unsigned int v4; // w22

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v2 + 104);
  if ( *(_BYTE *)(v2 + 408) == 1 )
  {
    if ( (*(_BYTE *)(v2 + 112) & 1) != 0 || (v3 = *(_DWORD *)(a1 + 976) - 1, (*(_DWORD *)(a1 + 976) = v3) != 0) )
    {
      v4 = -16;
    }
    else
    {
      if ( !(unsigned int)*(_QWORD *)(a1 + 968) )
        __break(0x800u);
      _tmc_etb_disable_hw(v2);
      coresight_disclaim_device(*(_QWORD *)(v2 + 16));
      v4 = 0;
      *(_DWORD *)(v2 + 108) = -1;
      *(_QWORD *)(a1 + 968) = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  raw_spin_unlock_irqrestore(v2 + 104);
  return v4;
}
