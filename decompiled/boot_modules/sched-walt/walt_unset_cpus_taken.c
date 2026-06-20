__int64 __fastcall walt_unset_cpus_taken(_DWORD *a1)
{
  __int64 v2; // x1
  char v3; // w13
  unsigned __int64 v10; // x15
  unsigned __int64 v12; // x13
  unsigned __int64 v13; // x13
  __int64 v14; // x15
  int v15; // w14
  int v16; // w16
  __int64 v17; // x14

  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  v2 = raw_spin_lock_irqsave(&cpus_taken_lock);
  v3 = 0;
  _X12 = &walt_cpus_taken_mask;
  do
  {
    v12 = (unsigned int)(-1LL << v3) & *a1;
    if ( !(_DWORD)v12 )
      break;
    v13 = __clz(__rbit64(v12));
    v14 = *((_QWORD *)&_per_cpu_offset + v13);
    v15 = *(_DWORD *)((char *)&cpus_taken_refcount + v14);
    v16 = v15 - 1;
    if ( v15 >= 1 )
    {
      v17 = *((_QWORD *)&_per_cpu_offset + v13);
      *(_DWORD *)((char *)&cpus_taken_refcount + v14) = v16;
      v15 = *(_DWORD *)((char *)&cpus_taken_refcount + v17);
    }
    if ( !v15 )
    {
      __asm { PRFM            #0x11, [X12] }
      do
        v10 = __ldxr((unsigned __int64 *)&walt_cpus_taken_mask);
      while ( __stxr(v10 & ~(1LL << v13), (unsigned __int64 *)&walt_cpus_taken_mask) );
    }
    _CF = v13 >= 0x1F;
    v3 = v13 + 1;
  }
  while ( !_CF );
  raw_spin_unlock_irqrestore(&cpus_taken_lock, v2);
  return 0;
}
