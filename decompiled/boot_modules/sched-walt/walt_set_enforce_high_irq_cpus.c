__int64 __fastcall walt_set_enforce_high_irq_cpus(__int64 *a1)
{
  __int64 v2; // x1
  char v3; // w12
  __int64 v4; // x11
  unsigned __int64 v5; // x12
  unsigned __int64 v6; // x11

  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  v2 = raw_spin_lock_irqsave(&enforce_high_irq_cpu_lock);
  v3 = 0;
  while ( 1 )
  {
    v4 = *a1;
    v5 = (unsigned int)(-1LL << v3) & (unsigned int)*a1;
    if ( !(_DWORD)v5 )
      break;
    v6 = __clz(__rbit64(v5));
    ++*(_DWORD *)((char *)&enforce_high_irq_cpus_refcount + *((_QWORD *)&_per_cpu_offset + v6));
    v3 = v6 + 1;
    if ( v6 >= 0x1F )
    {
      v4 = *a1;
      break;
    }
  }
  walt_enforce_high_irq_cpu_mask |= v4;
  raw_spin_unlock_irqrestore(&enforce_high_irq_cpu_lock, v2);
  return 0;
}
