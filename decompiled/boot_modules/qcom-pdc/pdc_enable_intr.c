__int64 __fastcall pdc_enable_intr(__int64 a1, char a2)
{
  char v4; // w9
  __int64 v5; // x21
  __int64 v6; // x8
  char v7; // w24
  __int64 v8; // x23
  int v9; // w0
  unsigned int v10; // w0
  __int64 v11; // x8
  int v12; // w9
  int v13; // w8

  v5 = raw_spin_lock_irqsave(&pdc_lock);
  v6 = *(_QWORD *)(a1 + 8);
  if ( (unsigned int)pdc_version >> 9 > 0x180 )
  {
    v8 = 4LL * (unsigned int)*(_QWORD *)(a1 + 8);
    v12 = readl_relaxed((unsigned int *)(pdc_base + v8 + 272)) & 0xFFFFFFF7;
    if ( (a2 & 1) != 0 )
      v13 = 8;
    else
      v13 = 0;
    v10 = v12 | v13;
    v11 = 272;
  }
  else
  {
    v7 = v6 - (v4 & 0xE0);
    v8 = 4LL * (unsigned int)((int)v6 / 32);
    v9 = readl_relaxed((unsigned int *)(pdc_base + v8 + 16));
    if ( (a2 & 1) != 0 )
      v10 = (1LL << v7) | v9;
    else
      v10 = v9 & ~(unsigned int)(1LL << v7);
    v11 = 16;
  }
  writel_relaxed(v10, (unsigned int *)(pdc_base + v11 + v8));
  raw_spin_unlock_irqrestore(&pdc_lock, v5);
  return ipc_log_string(pdc_ipc_log, "PIN=%lu enable=%d", *(_QWORD *)(a1 + 8), a2 & 1);
}
