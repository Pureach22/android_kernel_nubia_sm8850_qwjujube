__int64 __fastcall msm_hw_fence_deregister(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x19
  __int64 result; // x0
  __int64 v9; // x3
  __int64 v10; // x4
  unsigned int v11; // w21
  int v18; // w8

  v7 = v5;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    v10 = *a1;
    if ( (unsigned int)v10 >= *(_DWORD *)(hw_fence_drv_data + 60) )
    {
      printk(&unk_2513C, "msm_hw_fence_deregister", 226, v7, v10);
      return 4294967274LL;
    }
    else
    {
      v11 = a1[1];
      if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
        printk(&unk_2B058, "msm_hw_fence_deregister", 230, v9, v10);
      _X0 = a1 + 49;
      __asm { PRFM            #0x11, [X0] }
      do
        v18 = __ldxr(_X0);
      while ( __stlxr(v18 - 1, _X0) );
      if ( v18 == 1 )
      {
        __dmb(9u);
        hw_fence_cleanup_client(hw_fence_drv_data, a1);
        if ( *(_BYTE *)(hw_fence_drv_data + 33520) == 1
          && (v11 - 129 < 0x40 || v11 - 577 <= 0xFF)
          && (unsigned int)hw_fence_utils_set_power_vote(hw_fence_drv_data, v11, 0) )
        {
          printk(&unk_22E07, "msm_hw_fence_deregister", 239, v7, a1[1]);
        }
      }
      else if ( v18 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
        printk(&unk_2388F, "msm_hw_fence_deregister", 241, v9, v10);
      return 0;
    }
  }
  return result;
}
