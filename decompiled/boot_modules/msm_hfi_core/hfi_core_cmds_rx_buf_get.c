__int64 __fastcall hfi_core_cmds_rx_buf_get(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 result; // x0
  __int64 v8; // x3
  __int64 v9; // x4
  unsigned int v10; // w19
  unsigned int *v11; // x22
  __int64 v12; // x23

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_12:
      printk(&unk_199DA, "hfi_core_cmds_rx_buf_get", 300, v5, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v11 = a1;
    v12 = v5;
    printk(&unk_1E83A, "hfi_core_cmds_rx_buf_get", 297, a4, a5);
    a1 = v11;
    v5 = v12;
    if ( !v11 )
      goto LABEL_12;
  }
  if ( !a2 )
    goto LABEL_12;
  result = get_rx_buffer(drv_data, *a1, a2, a4, a5);
  if ( (_DWORD)result )
  {
    if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
    {
      v10 = result;
      printk(&unk_1CF1C, "hfi_core_cmds_rx_buf_get", 306, (unsigned int)result, v9);
      return v10;
    }
  }
  else
  {
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_core_cmds_rx_buf_get", 310, v8, v9);
    return 0;
  }
  return result;
}
