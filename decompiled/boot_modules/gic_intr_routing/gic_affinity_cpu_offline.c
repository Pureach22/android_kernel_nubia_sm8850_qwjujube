__int64 __fastcall gic_affinity_cpu_offline(unsigned int a1)
{
  unsigned __int64 v2; // x21
  unsigned int *v3; // x20
  int v4; // w0
  unsigned __int64 v11; // x10
  unsigned int v14; // w8
  __int64 v15; // x20

  if ( (byte_7B4C & 1) != 0 || !dword_7B68 )
  {
    v2 = a1;
  }
  else
  {
    v2 = a1;
    v3 = (unsigned int *)(qword_7B58 + qword_7B60 * a1);
    v4 = readl_relaxed(v3);
    writel_relaxed(v4 | 0x2000000, v3);
  }
  if ( ((*(unsigned __int64 *)((char *)&gic_routing_data[1] + ((v2 >> 3) & 0x1FFFFFF8)) >> v2) & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)&gic_routing_data[(a1 >> 6) + 3];
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 & ~(1LL << a1), _X8) );
    if ( !dword_7B40 )
    {
      _X9 = &dword_7B54;
      __asm { PRFM            #0x11, [X9] }
      do
        v14 = __ldxr((unsigned int *)&dword_7B54);
      while ( __stlxr(v14, (unsigned int *)&dword_7B54) );
      __dmb(0xBu);
      if ( v14 )
      {
        dword_7B50 = 1;
        __dmb(0xBu);
        cancel_delayed_work_sync(&affinity_initialize_work);
        __dmb(0xBu);
        dword_7B50 = 0;
      }
      else
      {
        flush_delayed_work(&affinity_initialize_work);
        __dmb(0xBu);
      }
      v15 = raw_spin_lock_irqsave(&gic_class_lock);
      _bitmap_andnot(&gic_saved_class0, &active_gic_class0, &active_gic_class1, 1020);
      raw_spin_unlock_irqrestore(&gic_class_lock, v15);
    }
  }
  return 0;
}
