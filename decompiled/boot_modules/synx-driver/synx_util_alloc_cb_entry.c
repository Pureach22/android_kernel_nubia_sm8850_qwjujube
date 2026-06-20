__int64 __fastcall synx_util_alloc_cb_entry(unsigned __int64 a1, __int64 *a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 first_zero_bit; // x0
  __int64 v8; // x1
  __int64 v9; // x5
  __int64 v10; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x8
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x12

  result = 4294967274LL;
  if ( a1
    && a1 <= 0xFFFFFFFFFFFFF000LL
    && a2
    && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL
    && a3
    && (unsigned __int64)a3 <= 0xFFFFFFFFFFFFF000LL )
  {
    while ( 1 )
    {
      first_zero_bit = find_first_zero_bit(a1 + 216, 4096);
      if ( first_zero_bit > 4095 )
        break;
      v10 = 1LL << first_zero_bit;
      _X10 = (unsigned __int64 *)(a1 + 216 + 8LL * ((unsigned int)first_zero_bit >> 6));
      __asm { PRFM            #0x11, [X10] }
      do
        v17 = __ldxr(_X10);
      while ( __stlxr(v17 | v10, _X10) );
      __dmb(0xBu);
      if ( (v17 & v10) == 0 )
      {
        if ( (unsigned __int64)first_zero_bit > 0x1000 )
        {
          __break(0x5512u);
          return synx_util_clear_cb_entry(first_zero_bit, v8);
        }
        else
        {
          v18 = a1 + (first_zero_bit << 6);
          *(_QWORD *)(v18 + 728) = 0;
          *(_QWORD *)(v18 + 784) = 0;
          *(_QWORD *)(v18 + 776) = 0;
          *(_QWORD *)(v18 + 768) = 0;
          *(_QWORD *)(v18 + 760) = 0;
          *(_QWORD *)(v18 + 752) = 0;
          *(_QWORD *)(v18 + 744) = 0;
          *(_BYTE *)(v18 + 728) = 1;
          *(_QWORD *)(v18 + 736) = a1;
          *(_DWORD *)(v18 + 732) = first_zero_bit;
          v19 = a2[2];
          v20 = *a2;
          v21 = a2[1];
          *(_QWORD *)(v18 + 768) = a2[3];
          *(_QWORD *)(v18 + 760) = v19;
          *(_QWORD *)(v18 + 752) = v21;
          *(_QWORD *)(v18 + 744) = v20;
          *a3 = first_zero_bit;
          if ( (synx_debug & 0x10) != 0 )
            printk(&unk_27C45, "verb", "synx_util_alloc_cb_entry", 1330, *(_QWORD *)(a1 + 104), first_zero_bit);
          return 0;
        }
      }
    }
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2800D, &unk_29207, "synx_util_alloc_cb_entry", 1316, *(_QWORD *)(a1 + 104), v9);
    return 4294967284LL;
  }
  return result;
}
