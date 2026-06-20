__int64 synx_global_memory_is_empty()
{
  unsigned int next_bit; // w0
  __int64 v1; // x5
  unsigned int i; // w20

  if ( !synx_gmem_2 )
    return 4294967284LL;
  next_bit = find_next_bit(synx_gmem_0, 4096, 1);
  if ( next_bit > 0xFFF )
    return 0;
  for ( i = next_bit; i < 0x1000; i = find_next_bit(synx_gmem_0, 4096, i + 1) )
  {
    if ( (synx_debug & 0x80) != 0 )
      printk(&unk_2751B, &unk_25D36, "synx_global_memory_is_empty", 253, i, v1);
    synx_global_print_data((_WORD *)(synx_gmem_2 + glcoredata_size * i), (__int64)"synx_global_memory_is_empty");
  }
  return 4294967274LL;
}
