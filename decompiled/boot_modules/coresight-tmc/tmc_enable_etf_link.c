__int64 __fastcall tmc_enable_etf_link(__int64 a1)
{
  __int64 v2; // x19
  unsigned int v3; // w22
  int v4; // w8
  unsigned int v6; // w0
  __int64 v7; // x8
  __int64 v8; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v2 + 104);
  if ( *(_BYTE *)(v2 + 408) == 1 )
  {
    if ( (*(_BYTE *)(v2 + 112) & 1) != 0 )
    {
      v3 = -16;
    }
    else
    {
      v4 = *(_DWORD *)(a1 + 976);
      if ( !v4 )
      {
        v3 = coresight_claim_device(*(_QWORD *)(v2 + 16));
        if ( v3 )
          goto LABEL_8;
        writel_relaxed_0(0xC5ACCE55, (unsigned int *)(*(_QWORD *)(v2 + 8) + 4016LL));
        __dsb(0xFu);
        v6 = tmc_wait_for_tmcready(v2);
        if ( v6 )
        {
          v3 = v6;
          dev_err(*(_QWORD *)(v2 + 16) + 56LL, "Failed to enable : TMC is not ready\n");
          v8 = *(_QWORD *)(v2 + 8);
          __dsb(0xFu);
          writel_relaxed_0(0, (unsigned int *)(v8 + 4016));
          coresight_disclaim_device(*(_QWORD *)(v2 + 16));
          goto LABEL_8;
        }
        writel_relaxed_0(2u, (unsigned int *)(*(_QWORD *)(v2 + 8) + 40LL));
        writel_relaxed_0(3u, (unsigned int *)(*(_QWORD *)(v2 + 8) + 772LL));
        writel_relaxed_0(0, (unsigned int *)(*(_QWORD *)(v2 + 8) + 52LL));
        tmc_enable_hw(v2);
        v7 = *(_QWORD *)(v2 + 8);
        __dsb(0xFu);
        writel_relaxed_0(0, (unsigned int *)(v7 + 4016));
        if ( (*(_QWORD *)(a1 + 968) & 0xFFFFFFFELL) != 0 )
        {
          _warn_printk("Device already in use\n");
          __break(0x800u);
        }
        *(_QWORD *)(a1 + 968) = 1;
        v4 = *(_DWORD *)(a1 + 976);
      }
      v3 = 0;
      *(_DWORD *)(a1 + 976) = v4 + 1;
    }
  }
  else
  {
    v3 = -22;
  }
LABEL_8:
  raw_spin_unlock_irqrestore(v2 + 104);
  return v3;
}
