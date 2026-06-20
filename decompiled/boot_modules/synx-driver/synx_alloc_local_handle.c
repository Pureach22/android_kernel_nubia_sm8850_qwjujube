__int64 __fastcall synx_alloc_local_handle(_DWORD *a1)
{
  __int64 v2; // x20
  __int64 first_zero_bit; // x0
  __int64 v4; // x8
  unsigned __int64 v11; // x9

  v2 = *(_QWORD *)(synx_dev + 152) + 22568LL;
  do
  {
    first_zero_bit = find_first_zero_bit(v2, 4096);
    if ( first_zero_bit > 4095 )
      break;
    v4 = 1LL << first_zero_bit;
    _X10 = (unsigned __int64 *)(v2 + 8LL * ((unsigned int)first_zero_bit >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v11 = __ldxr(_X10);
    while ( __stlxr(v11 | v4, _X10) );
    __dmb(0xBu);
  }
  while ( (v11 & v4) != 0 );
  if ( (unsigned int)first_zero_bit > 0xFFF )
    return 4294967284LL;
  *a1 = first_zero_bit;
  if ( (synx_debug & 8) != 0 )
    printk(&unk_2A400, &unk_2A972, "synx_alloc_local_handle", 581, first_zero_bit, (unsigned int)first_zero_bit);
  return 0;
}
