__int64 __usercall coresight_trace_id_put_cpu_id@<X0>(__int64 result@<X0>, __int64 a2@<X8>)
{
  unsigned __int64 v2; // x20
  __int64 v3; // x21
  unsigned __int64 v6; // x10
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x10

  if ( (unsigned int)result >= 0x20 )
  {
    __break(0x5512u);
  }
  else
  {
    v2 = *(unsigned int *)((char *)&cpu_id + _per_cpu_offset[(unsigned int)result]);
    if ( !(_DWORD)v2 )
      return result;
    v3 = (unsigned int)result;
    raw_spin_lock_irqsave(&id_map_lock);
    if ( !perf_cs_etm_session_active )
    {
      if ( (unsigned int)(v2 - 112) > 0xFFFFFF90 )
      {
        if ( ((*(_QWORD *)((char *)&id_map_default + ((v2 >> 3) & 0x1FFFFFF8)) >> v2) & 1) != 0 )
        {
          _X8 = (unsigned __int64 *)((char *)&id_map_default + 8 * (v2 >> 6));
          __asm { PRFM            #0x11, [X8] }
          do
            v16 = __ldxr(_X8);
          while ( __stxr(v16 & ~(1LL << v2), _X8) );
        }
        else
        {
          _warn_printk("Freeing unused ID %d\n", v2);
          __break(0x800u);
        }
      }
      else
      {
        _warn_printk("Invalid Trace ID %d\n", v2);
        __break(0x800u);
      }
      *(_DWORD *)((char *)&cpu_id + _per_cpu_offset[v3]) = 0;
      return raw_spin_unlock_irqrestore(&id_map_lock);
    }
    if ( (unsigned int)(v2 - 112) > 0xFFFFFF90 )
    {
      _X9 = (unsigned __int64 *)((char *)&id_map_default + 8 * (v2 >> 6) + 16);
      __asm { PRFM            #0x11, [X9] }
      do
        v13 = __ldxr(_X9);
      while ( __stxr(v13 | (1LL << v2), _X9) );
    }
    else
    {
      _warn_printk("Invalid Trace ID %d\n", v2);
      __break(0x800u);
    }
    a2 = 1LL << v3;
  }
  _X9 = &cpu_id_release_pending;
  __asm { PRFM            #0x11, [X9] }
  do
    v6 = __ldxr((unsigned __int64 *)&cpu_id_release_pending);
  while ( __stxr(v6 | a2, (unsigned __int64 *)&cpu_id_release_pending) );
  return raw_spin_unlock_irqrestore(&id_map_lock);
}
