__int64 __fastcall synx_util_clear_cb_entry(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned int v6; // w8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x9
  __int64 v9; // x8
  unsigned __int64 v17; // x10

  v6 = -22;
  if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v7 = *(unsigned int *)(a2 + 4);
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    *(_QWORD *)(a2 + 32) = 0;
    *(_QWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 48) = 0;
    *(_QWORD *)(a2 + 56) = 0;
    *(_QWORD *)a2 = 0;
    *(_QWORD *)(a2 + 8) = 0;
    if ( (unsigned int)(v7 - 1) > 0xFFE )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_28BDA, &unk_29207, "synx_util_clear_cb_entry", 1348, a5, a6);
      return (unsigned int)-22;
    }
    else
    {
      v8 = v7 >> 6;
      v9 = 1LL << v7;
      _X9 = (unsigned __int64 *)(a1 + 216 + 8 * v8);
      __asm { PRFM            #0x11, [X9] }
      do
        v17 = __ldxr(_X9);
      while ( __stxr(v17 & ~v9, _X9) );
      return 0;
    }
  }
  return v6;
}
