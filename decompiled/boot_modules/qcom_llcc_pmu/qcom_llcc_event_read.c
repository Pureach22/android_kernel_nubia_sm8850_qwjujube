__int64 __fastcall qcom_llcc_event_read(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x22
  __int64 i; // x26
  int v7; // w8
  int v8; // w9
  int v9; // w9
  __int64 v10; // x8

  v2 = *(unsigned int *)(a1 + 668);
  v3 = raw_spin_lock_irqsave(&counter_lock);
  if ( *(_DWORD *)(llccpmu + 1456) != 1 )
  {
    v4 = mon_disable((unsigned int)v2);
    if ( (unsigned int)v2 >= 0x20 )
      goto LABEL_23;
    v9 = *(_DWORD *)(llccpmu + 1456);
    if ( (unsigned int)(v9 - 1) >= 3 )
    {
      if ( v9 )
      {
        v10 = 0;
      }
      else
      {
        printk(&unk_6F54);
        v10 = 134217552;
      }
    }
    else
    {
      v10 = 8 * (readl_relaxed(*(_QWORD *)(llccpmu + 328) + 4 * phys_cpu[v2] + 544LL) & 0xFFFFFF);
    }
    llcc_stats[v2] += v10;
    goto LABEL_17;
  }
  v4 = ktime_get();
  if ( v4 - last_read >= 2000000 )
  {
    v5 = v4;
    mon_disable((unsigned int)v2);
    for ( i = 0; i != 32; ++i )
    {
      v8 = *(_DWORD *)(llccpmu + 1456);
      if ( (unsigned int)(v8 - 1) < 3 )
      {
        v7 = readl_relaxed(*(_QWORD *)(llccpmu + 328) + 4 * phys_cpu[i] + 544LL);
      }
      else if ( v8 )
      {
        v7 = 0;
      }
      else
      {
        printk(&unk_6F54);
        v7 = -22;
      }
      llcc_stats[i] += 8 * (*(_QWORD *)&v7 & 0xFFFFFFLL);
    }
    last_read = v5;
LABEL_17:
    mon_clear((unsigned int)v2);
    v4 = mon_enable((unsigned int)v2);
  }
  if ( (*(_BYTE *)(a1 + 480) & 1) != 0 )
    return raw_spin_unlock_irqrestore(&counter_lock, v3);
  if ( (unsigned int)v2 <= 0x1F )
  {
    *(_QWORD *)(a1 + 176) = llcc_stats[v2];
    return raw_spin_unlock_irqrestore(&counter_lock, v3);
  }
LABEL_23:
  __break(0x5512u);
  return mon_enable(v4);
}
