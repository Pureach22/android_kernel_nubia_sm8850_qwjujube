__int64 __fastcall hw_fence_cb(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  unsigned int v3; // w20
  __int64 v5; // x21
  unsigned int v6; // w0
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  unsigned int v10; // w21
  __int64 v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0x1FFFFFFFFLL;
  if ( a2 )
  {
    v3 = result;
    v5 = v2;
    v6 = gh_dbl_read_and_clean(*(_QWORD *)(a2 + 472), v11, 0);
    if ( v6 )
    {
      result = printk(&unk_28D0D, "_hw_fence_cb", 541, v5, v6);
    }
    else
    {
      if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
      {
        v10 = *(_DWORD *)(a2 + 468);
        hw_fence_get_qtime();
        printk(&unk_22053, "_hw_fence_cb", 546, v10, v3);
      }
      result = hw_fence_utils_process_signaled_clients_mask(a2, v11[0], v7, v8, v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
