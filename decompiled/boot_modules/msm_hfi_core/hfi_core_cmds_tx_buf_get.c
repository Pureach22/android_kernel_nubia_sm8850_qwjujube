__int64 __fastcall hfi_core_cmds_tx_buf_get(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  unsigned int tx_buffer; // w0
  __int64 v9; // x3
  __int64 v10; // x4
  unsigned int *v12; // x23
  __int64 v13; // x30
  unsigned int v14; // w19

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_9:
      printk(&unk_199DA, "hfi_core_cmds_tx_buf_get", 277, v6, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v12 = a1;
    printk(&unk_1E83A, "hfi_core_cmds_tx_buf_get", 274, a4, a5);
    a1 = v12;
    if ( !v12 )
      goto LABEL_9;
  }
  if ( !a2 )
    goto LABEL_9;
  tx_buffer = get_tx_buffer(drv_data, *a1, a2, a4, a5);
  if ( tx_buffer )
  {
    v13 = v6;
    v14 = tx_buffer;
    printk(&unk_1CEDF, "hfi_core_cmds_tx_buf_get", 283, v13, v10);
    return v14;
  }
  else
  {
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_core_cmds_tx_buf_get", 287, v9, v10);
    return 0;
  }
}
