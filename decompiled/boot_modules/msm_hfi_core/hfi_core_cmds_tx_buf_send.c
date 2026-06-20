__int64 __fastcall hfi_core_cmds_tx_buf_send(unsigned int *a1, _QWORD *a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  char v7; // w20
  unsigned int v11; // w0
  __int64 v12; // x3
  __int64 v13; // x4
  unsigned int v14; // w0
  __int64 v16; // x30
  unsigned int v17; // w19
  void *v18; // x0
  __int64 v19; // x2

  v6 = v5;
  v7 = a4;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_13:
      printk(&unk_1905C, "hfi_core_cmds_tx_buf_send", 324, v6, a5);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1E83A, "hfi_core_cmds_tx_buf_send", 321, a4, a5);
    if ( !a1 )
      goto LABEL_13;
  }
  if ( !a2 )
    goto LABEL_13;
  v11 = set_tx_buffer(drv_data, *a1, a2, a3, a5);
  if ( v11 )
  {
    v16 = v6;
    v17 = v11;
    v18 = &unk_191BC;
    v19 = 332;
LABEL_16:
    printk(v18, "hfi_core_cmds_tx_buf_send", v19, v16, v13);
    return v17;
  }
  __dsb(0xEu);
  if ( (v7 & 1) == 0 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
      printk(&unk_1D9D6, "hfi_core_cmds_tx_buf_send", 348, v12, v13);
    goto LABEL_9;
  }
  v14 = trigger_ipc(*a1, drv_data, 1, v12, v13);
  if ( v14 )
  {
    v16 = v6;
    v17 = v14;
    v18 = &unk_1B522;
    v19 = 344;
    goto LABEL_16;
  }
LABEL_9:
  __dsb(0xEu);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_core_cmds_tx_buf_send", 355, v12, v13);
  return 0;
}
