__int64 __fastcall init_hw_fences_events(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x4
  __int64 result; // x0
  __int64 v5; // x3
  int v6; // w8
  __int64 v7; // x4
  unsigned int v8; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10[0] = 0;
  v8 = 0;
  v2 = hw_fence_utils_reserve_mem(a1, 4, v10, &v9, &v8, 0);
  if ( v2 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10004) == 0 )
      printk(&unk_2121F, "init_hw_fences_events", 741, v2, v3);
    result = 4294967284LL;
  }
  else
  {
    v5 = v9;
    v6 = msm_hw_fence_debug_level;
    v7 = v8 >> 6;
    *(_QWORD *)(a1 + 88) = v9;
    *(_DWORD *)(a1 + 96) = v7;
    if ( (~v6 & 0x10008) == 0 )
      printk(&unk_20B45, "init_hw_fences_events", 747, v5, v7);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
