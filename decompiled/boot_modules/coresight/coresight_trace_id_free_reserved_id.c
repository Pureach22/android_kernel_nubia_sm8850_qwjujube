__int64 __fastcall coresight_trace_id_free_reserved_id(unsigned int a1)
{
  unsigned __int64 v9; // x10

  raw_spin_lock_irqsave(&id_map_lock);
  if ( a1 - 112 <= 0xFFFFFF90 )
  {
    _warn_printk("Invalid Trace ID %d\n", a1);
    __break(0x800u);
  }
  else if ( ((*(_QWORD *)((char *)&id_map_default + (((unsigned __int64)a1 >> 3) & 0x1FFFFFF8)) >> a1) & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)((char *)&id_map_default + 8 * (a1 >> 6));
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 & ~(1LL << a1), _X8) );
  }
  else
  {
    _warn_printk("Freeing unused ID %d\n", a1);
    __break(0x800u);
  }
  return raw_spin_unlock_irqrestore(&id_map_lock);
}
