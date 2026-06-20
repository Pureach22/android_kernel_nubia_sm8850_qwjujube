__int64 __fastcall bwmon_intr_handler2(__int64 a1, __int64 a2)
{
  unsigned __int8 v3; // w0
  __int64 v4; // x21
  int v5; // w19

  v3 = readl_relaxed(*(_QWORD *)a2 + 256LL);
  *(_DWORD *)(a2 + 308) = v3 >> 4;
  if ( !(v3 >> 4) )
    return 0;
  v4 = raw_spin_lock_irqsave(&sample_irq_lock);
  v5 = _bw_hwmon_sample_end(a2 + 40);
  raw_spin_unlock_irqrestore(&sample_irq_lock, v4);
  if ( v5 )
    return 2;
  else
    return 1;
}
