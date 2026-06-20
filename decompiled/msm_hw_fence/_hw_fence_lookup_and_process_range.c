unsigned __int64 __fastcall hw_fence_lookup_and_process_range(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 *a5,
        unsigned int a6,
        unsigned int a7,
        __int64 (__fastcall *a8)(_QWORD))
{
  __int64 v8; // x30
  unsigned int v16; // w0
  unsigned int v17; // w25
  int v18; // w24
  unsigned __int64 result; // x0
  unsigned __int64 v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  if ( a1 && a5 && a8 )
  {
    v16 = hw_fence_iterator_init(a1, v20, a5, a3, a4, a6, a7);
    if ( v16 < a7 )
    {
      v17 = v16;
      while ( *(_QWORD *)(v20[0] + 8) != a3
           || *(_QWORD *)(v20[0] + 16) != a4
           || *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8 * *a5) != a2 )
      {
        v17 = hw_fence_iterator_next(a1, v20, a5, v17, a7, 0);
        if ( v17 >= a7 )
          goto LABEL_15;
      }
      if ( *((_DWORD *)a8 - 1) != -1459772718 )
        __break(0x8238u);
      v18 = a8(a1);
      if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
        printk(&unk_24995, "_hw_fence_lookup_and_process_range", 1436, a3, a4);
      hw_fence_iterator_next(a1, v20, a5, v17, a7, 1);
      if ( !v18 )
      {
        result = v20[0];
        goto LABEL_18;
      }
    }
LABEL_15:
    if ( (~msm_hw_fence_debug_level & 0x10020) == 0 )
      printk(&unk_230D2, "_hw_fence_lookup_and_process_range", 1444, a3, a4);
  }
  else
  {
    printk(&unk_2307B, "_hw_fence_lookup_and_process_range", 1426, v8, a1);
  }
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
