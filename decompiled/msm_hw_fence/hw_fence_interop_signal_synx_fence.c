__int64 __fastcall hw_fence_interop_signal_synx_fence(unsigned __int64 a1, char a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x30
  __int64 v5; // x20
  unsigned int v7; // w21
  void *v8; // x8
  __int64 v9; // x1
  __int64 result; // x0
  char v12; // w26
  __int64 v13; // x30
  unsigned int v14; // w20

  v5 = v4;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && a3 && off_2B790 )
  {
    if ( a4 )
    {
      if ( a4 == 1 )
        v7 = 6;
      else
        v7 = a4;
    }
    else
    {
      v7 = 2;
    }
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    {
      v12 = a2;
      printk(&unk_252B9, "hw_fence_interop_to_synx_signal_status", 93, 1, a4);
      a2 = v12;
      if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      {
        printk(&unk_27E44, "hw_fence_interop_signal_synx_fence", 399, a3, a4);
        a2 = v12;
      }
    }
    v8 = off_2B790;
    v9 = a2 & 1;
    if ( *((_DWORD *)off_2B790 - 1) != -1328200472 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v8)(5, v9, a3, v7);
    if ( (_DWORD)result )
    {
      v13 = v5;
      v14 = result;
      printk(&unk_2243D, "hw_fence_interop_signal_synx_fence", 402, v13, a3);
      return v14;
    }
  }
  else
  {
    printk(&unk_28AAC, "hw_fence_interop_signal_synx_fence", 394, v4, a1);
    return 4294967274LL;
  }
  return result;
}
