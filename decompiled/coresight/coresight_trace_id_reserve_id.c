__int64 __fastcall coresight_trace_id_reserve_id(unsigned int a1)
{
  unsigned int v2; // w19
  unsigned __int64 v10; // x10

  raw_spin_lock_irqsave(&id_map_lock);
  if ( a1 - 1 > 0x6E
    || ((*(_QWORD *)((char *)&id_map_default + (((unsigned __int64)a1 >> 3) & 0x1FFFFFF8)) >> a1) & 1) != 0 )
  {
    v2 = -16;
  }
  else
  {
    _X8 = (unsigned __int64 *)((char *)&id_map_default + 8 * (a1 >> 6));
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 | (1LL << a1), _X8) );
    v2 = 0;
  }
  raw_spin_unlock_irqrestore(&id_map_lock);
  return v2;
}
