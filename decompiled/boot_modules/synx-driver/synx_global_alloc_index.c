__int64 __fastcall synx_global_alloc_index(
        unsigned int *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 first_zero_bit; // x0
  unsigned int v8; // w19
  __int64 v9; // x5

  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_alloc_index", 270, a5, a6);
    return 4294967284LL;
  }
  if ( a1 && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    while ( 1 )
    {
      first_zero_bit = find_first_zero_bit(synx_gmem_0, 4096);
      v8 = first_zero_bit;
      if ( (unsigned int)first_zero_bit > 0xFFF )
        break;
      if ( (((unsigned int)ipclite_global_test_and_set_bit(
                             first_zero_bit & 0x1F,
                             synx_gmem_0 + 4 * ((first_zero_bit >> 5) & 0x7F)) >> (first_zero_bit & 0x1F))
          & 1) == 0 )
      {
        *a1 = v8;
        if ( (synx_debug & 0x80) != 0 )
          printk(&unk_26B07, &unk_25D36, "synx_global_alloc_index", 289, v8, v9);
        return 0;
      }
    }
    return 4294967284LL;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_260BC, &unk_29207, "synx_global_alloc_index", 275, a5, a6);
  return 4294967274LL;
}
