__int64 __fastcall msm_hw_fence_dump_fence(unsigned int *a1, __int64 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x21
  __int64 result; // x0
  unsigned __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  unsigned __int64 v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v8 = v5;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( (a2[6] & 0x80000000) != 0 )
    {
      v10 = msm_hw_fence_find(hw_fence_drv_data, a1, (__int64)a2, a2[4], a2[5], v14);
      if ( v10 )
      {
        hw_fence_debug_dump_fence(0x10000, v10, v14[0], 0);
        msm_hw_fence_destroy_with_handle(a1, v14[0], v11, v12, v13);
        result = 0;
      }
      else
      {
        printk(&unk_29A18, "msm_hw_fence_dump_fence", 762, v8, *a1);
        result = 4294967274LL;
      }
    }
    else
    {
      printk(&unk_2899F, "msm_hw_fence_dump_fence", 753, v8, a2[4]);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
