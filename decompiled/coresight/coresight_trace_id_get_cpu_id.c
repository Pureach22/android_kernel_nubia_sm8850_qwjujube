__int64 __fastcall coresight_trace_id_get_cpu_id(unsigned int a1)
{
  unsigned int v1; // w20
  __int64 v3; // x8
  int next_zero_bit; // w0
  unsigned __int64 v8; // x10
  unsigned __int64 v11; // x10
  unsigned __int64 v18; // x10

  raw_spin_lock_irqsave(&id_map_lock);
  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
  }
  else
  {
    v1 = *(_DWORD *)((char *)&cpu_id + _per_cpu_offset[a1]);
    if ( !v1 )
    {
      next_zero_bit = 2 * a1 + 16;
      if ( ((*(_QWORD *)((char *)&id_map_default + (((unsigned __int64)(unsigned int)next_zero_bit >> 3) & 0xFFFFFF8)) >> ((2 * a1 + 16) & 0x3E))
          & 1) != 0 )
      {
        next_zero_bit = find_next_zero_bit(&id_map_default, 112, 1);
        if ( next_zero_bit > 111 )
        {
          v1 = -22;
          goto LABEL_4;
        }
      }
      _X9 = (unsigned __int64 *)((char *)&id_map_default + 8 * ((unsigned int)next_zero_bit >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v18 = __ldxr(_X9);
      while ( __stxr(v18 | (1LL << next_zero_bit), _X9) );
      if ( (unsigned int)(next_zero_bit - 1) > 0x6E )
      {
        v1 = next_zero_bit;
        goto LABEL_4;
      }
      v1 = next_zero_bit;
      *(_DWORD *)((char *)&cpu_id + _per_cpu_offset[a1]) = next_zero_bit;
    }
    v3 = 1LL << a1;
  }
  _X9 = &cpu_id_release_pending;
  __asm { PRFM            #0x11, [X9] }
  do
    v8 = __ldxr((unsigned __int64 *)&cpu_id_release_pending);
  while ( __stxr(v8 & ~v3, (unsigned __int64 *)&cpu_id_release_pending) );
  _X9 = (unsigned __int64 *)((char *)&id_map_default + 8 * (v1 >> 6) + 16);
  __asm { PRFM            #0x11, [X9] }
  do
    v11 = __ldxr(_X9);
  while ( __stxr(v11 & ~(1LL << v1), _X9) );
LABEL_4:
  raw_spin_unlock_irqrestore(&id_map_lock);
  return v1;
}
