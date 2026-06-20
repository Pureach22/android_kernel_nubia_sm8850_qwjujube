__int64 __fastcall msm_hw_fence_update_txq(
        unsigned __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x23
  __int64 result; // x0

  v7 = v5;
  result = hw_fence_check_valid_client(hw_fence_drv_data, a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( *(unsigned int *)(hw_fence_drv_data + 80) <= a2 )
    {
      printk(&unk_2AD72, "msm_hw_fence_update_txq", 579, v7, a2);
      return 4294967274LL;
    }
    else
    {
      ((void (__fastcall *)(__int64))hw_fence_update_queue)(hw_fence_drv_data);
      return 0;
    }
  }
  return result;
}
