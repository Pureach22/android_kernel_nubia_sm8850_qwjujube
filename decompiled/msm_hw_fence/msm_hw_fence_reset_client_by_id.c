__int64 __fastcall msm_hw_fence_reset_client_by_id(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x21
  char v8; // w20
  __int64 result; // x0
  unsigned int client_id_priv; // w0
  __int64 v11; // x2
  __int64 v12; // x3

  v7 = v5;
  v8 = a2;
  result = hw_fence_check_hw_fence_driver(hw_fence_drv_data, a2, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( a1 >= 0x681 )
    {
      printk(&unk_28DBD, "msm_hw_fence_reset_client_by_id", 552, v7, a1);
      return 4294967274LL;
    }
    else
    {
      client_id_priv = hw_fence_utils_get_client_id_priv(hw_fence_drv_data, a1);
      if ( client_id_priv >= 0x681 )
      {
        printk(&unk_2063D, "msm_hw_fence_reset_client_by_id", 559, v7, client_id_priv);
        return 4294967274LL;
      }
      else
      {
        return msm_hw_fence_reset_client(
                 *(unsigned int **)(*(_QWORD *)(hw_fence_drv_data + 728) + 8LL * client_id_priv),
                 v8,
                 v11,
                 v12,
                 client_id_priv);
      }
    }
  }
  return result;
}
