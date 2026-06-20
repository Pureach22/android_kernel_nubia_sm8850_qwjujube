__int64 __fastcall hfi_core_cmds_tx_device_buf_send(
        unsigned int *a1,
        _QWORD *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  char v7; // w20
  unsigned int v11; // w0
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v15; // x30
  unsigned int v16; // w19

  v6 = v5;
  v7 = a4;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_11:
      printk(&unk_1B028, "hfi_core_cmds_tx_device_buf_send", 396, v6, "hfi_core_cmds_tx_device_buf_send");
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1E83A, "hfi_core_cmds_tx_device_buf_send", 393, a4, a5);
    if ( !a1 )
      goto LABEL_11;
  }
  if ( !a2 )
    goto LABEL_11;
  v11 = set_device_tx_buffer(drv_data, *a1, a2, a3, a5);
  if ( v11 )
  {
    v15 = v6;
    v16 = v11;
    printk(&unk_19A1C, "hfi_core_cmds_tx_device_buf_send", 405, v15, "hfi_core_cmds_tx_device_buf_send");
    return v16;
  }
  else
  {
    if ( (v7 & 1) != 0 )
      trigger_ipc(*a1, drv_data, 1, v12, v13);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_core_cmds_tx_device_buf_send", 414, v12, v13);
    return 0;
  }
}
