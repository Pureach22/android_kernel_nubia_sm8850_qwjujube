void coresight_trace_id_perf_stop()
{
  int next_bit; // w0
  __int64 v1; // x9
  __int64 v2; // x8
  unsigned __int64 v5; // x11
  unsigned __int64 v8; // x10
  char v9; // w14
  unsigned __int64 v11; // x14
  unsigned __int64 v12; // x14
  unsigned __int64 v14; // x16
  unsigned int v21; // w8
  unsigned int v22; // w8

  _X10 = &perf_cs_etm_session_active;
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v21 = __ldxr((unsigned int *)&perf_cs_etm_session_active);
    v22 = v21 - 1;
  }
  while ( __stlxr(v22, (unsigned int *)&perf_cs_etm_session_active) );
  __dmb(0xBu);
  if ( !v22 )
  {
    raw_spin_lock_irqsave(&id_map_lock);
    next_bit = find_next_bit(&unk_11AC8, 112, 0);
    if ( next_bit <= 111 )
    {
      do
      {
        v1 = (unsigned int)next_bit >> 6;
        v2 = 1LL << next_bit;
        _X10 = (unsigned __int64 *)((char *)&id_map_default + 8 * v1);
        __asm { PRFM            #0x11, [X10] }
        do
          v5 = __ldxr(_X10);
        while ( __stxr(v5 & ~v2, _X10) );
        _X9 = (unsigned __int64 *)((char *)&id_map_default + 8 * v1 + 16);
        __asm { PRFM            #0x11, [X9] }
        do
          v8 = __ldxr(_X9);
        while ( __stxr(v8 & ~v2, _X9) );
        next_bit = find_next_bit(&unk_11AC8, 112, next_bit + 1);
      }
      while ( next_bit < 112 );
    }
    v9 = 0;
    _X13 = &cpu_id_release_pending;
    do
    {
      v11 = (unsigned int)(-1LL << v9) & (unsigned int)cpu_id_release_pending;
      if ( !(_DWORD)v11 )
        break;
      v12 = __clz(__rbit64(v11));
      *(_DWORD *)((char *)&cpu_id + _per_cpu_offset[v12]) = 0;
      __asm { PRFM            #0x11, [X13] }
      do
        v14 = __ldxr((unsigned __int64 *)&cpu_id_release_pending);
      while ( __stxr(v14 & ~(1LL << v12), (unsigned __int64 *)&cpu_id_release_pending) );
      _CF = v12 >= 0x1F;
      v9 = v12 + 1;
    }
    while ( !_CF );
    raw_spin_unlock_irqrestore(&id_map_lock);
  }
}
