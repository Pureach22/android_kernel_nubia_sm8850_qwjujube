__int64 __fastcall bwmon_intr_handler3(__int64 a1, __int64 a2)
{
  char v3; // w0
  __int64 v4; // x21
  int v5; // w19

  v3 = readl_relaxed(*(_QWORD *)a2);
  *(_DWORD *)(a2 + 308) = v3 & 0xF;
  if ( (v3 & 0xF) == 0 )
    return 0;
  v4 = raw_spin_lock_irqsave(&sample_irq_lock);
  v5 = _bw_hwmon_sample_end(a2 + 40);
  raw_spin_unlock_irqrestore(&sample_irq_lock, v4);
  if ( v5 )
    return 2;
  else
    return 1;
}
