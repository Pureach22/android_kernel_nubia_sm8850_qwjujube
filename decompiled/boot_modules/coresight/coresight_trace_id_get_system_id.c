__int64 coresight_trace_id_get_system_id()
{
  int v0; // w21
  int next_zero_bit; // w0
  _BOOL4 v3; // w8
  unsigned int v4; // w21
  unsigned __int64 v12; // x10

  raw_spin_lock_irqsave(&id_map_lock);
  v0 = 1;
  do
  {
    next_zero_bit = find_next_zero_bit(&id_map_default, 112, v0);
    v3 = (next_zero_bit & 1) == 0 || next_zero_bit > 111;
    if ( v3 )
      v0 = next_zero_bit + 1;
  }
  while ( v3 && v0 < 112 );
  if ( v3 && (next_zero_bit = find_next_zero_bit(&id_map_default, 112, 1), next_zero_bit > 111) )
  {
    v4 = -22;
  }
  else
  {
    v4 = next_zero_bit;
    _X9 = (unsigned __int64 *)((char *)&id_map_default + 8 * ((unsigned int)next_zero_bit >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v12 = __ldxr(_X9);
    while ( __stxr(v12 | (1LL << next_zero_bit), _X9) );
  }
  raw_spin_unlock_irqrestore(&id_map_lock);
  return v4;
}
