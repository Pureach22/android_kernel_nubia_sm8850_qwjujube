__int64 __fastcall synx_util_local_map_is_empty(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  unsigned int next_bit; // w0
  __int64 v6; // x5
  unsigned int v7; // w25

  if ( !a1 )
    return 4294967284LL;
  v2 = a2;
  next_bit = find_next_bit(a1, a2, 0);
  if ( next_bit >= a2 )
    return 0;
  do
  {
    if ( (synx_debug & 0x80) != 0 )
    {
      v7 = next_bit;
      printk(&unk_2987B, &unk_25D36, "synx_util_local_map_is_empty", 511, next_bit, v6);
      next_bit = v7;
    }
    next_bit = find_next_bit(a1, v2, next_bit + 1);
  }
  while ( next_bit < a2 );
  return 4294967274LL;
}
