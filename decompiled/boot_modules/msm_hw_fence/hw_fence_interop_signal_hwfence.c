__int64 __fastcall hw_fence_interop_signal_hwfence(unsigned int a1, char a2, unsigned __int16 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x21
  __int64 v6; // x4
  unsigned __int64 v7; // x19
  int v8; // w20
  unsigned int v9; // w3
  __int64 result; // x0
  void *v11; // x0
  __int64 v12; // x2
  unsigned int v13; // w21
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v5 = v4;
  v6 = a1;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( a1 != 5 || (a2 & 1) == 0 )
  {
    v11 = &unk_22F22;
    v12 = 415;
LABEL_20:
    printk(v11, "hw_fence_interop_signal_hwfence", v12, v4, v6);
    result = 4294967274LL;
    goto LABEL_16;
  }
  v7 = a3;
  v8 = a4;
  if ( (unsigned int)hw_fence_get_fence_allocator(hw_fence_drv_data, a3, &v14, a4, a1) )
  {
    printk(&unk_23E16, "hw_fence_interop_signal_hwfence", 422, v5, (unsigned int)v7);
    result = 4294967274LL;
    goto LABEL_16;
  }
  v6 = v14;
  if ( v14 != -2 )
  {
    v4 = v5;
    v11 = &unk_2699D;
    v12 = 427;
    goto LABEL_20;
  }
  if ( v8 > 5 )
  {
    if ( v8 == 6 )
    {
      v9 = 1;
      goto LABEL_13;
    }
LABEL_12:
    v9 = v8;
    goto LABEL_13;
  }
  if ( v8 != 2 )
  {
    if ( !v8 )
    {
      printk(&unk_29B07, "hw_fence_interop_to_hw_fence_error", 104, v5, v14);
      v9 = 22;
      goto LABEL_13;
    }
    if ( v8 == 1 )
    {
      printk(&unk_2B14E, "hw_fence_interop_to_hw_fence_error", 108, v5, v14);
      v9 = 0;
      goto LABEL_13;
    }
    goto LABEL_12;
  }
  v9 = 0;
LABEL_13:
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
  {
    v13 = v9;
    printk(&unk_294E6, "hw_fence_interop_to_hw_fence_error", 121, (unsigned int)v8, v9);
    v9 = v13;
  }
  result = hw_fence_signal_fence(hw_fence_drv_data, 0, v7, v9, 1);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
