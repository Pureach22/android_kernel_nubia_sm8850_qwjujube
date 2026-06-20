__int64 __fastcall deinit_ipc(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x21
  unsigned int *v8; // x24
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  _QWORD *v14; // x19
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v20; // x20
  __int64 v21; // x20

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_32:
    printk(&unk_1D5BD, "deinit_ipc", 514, v5, a5);
    return 4294967274LL;
  }
  v20 = v5;
  printk(&unk_1E83A, "deinit_ipc", 511, a4, a5);
  v5 = v20;
  if ( !a1 )
    goto LABEL_32;
LABEL_3:
  if ( *((_DWORD *)a1 + 58) == 1 )
  {
    v7 = *a1;
    if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
    {
      if ( v7 )
      {
LABEL_6:
        v8 = (unsigned int *)a1[30];
        v9 = v5;
        v10 = v8[20];
        if ( (_DWORD)v10 )
        {
          irq_set_irq_wake(v10, 0);
          devm_free_irq(v7, v8[20], a1);
        }
        v11 = v8[29];
        if ( (_DWORD)v11 )
        {
          irq_set_irq_wake(v11, 0);
          devm_free_irq(v7, v8[29], a1);
        }
        v12 = v8[42];
        if ( (_DWORD)v12 )
        {
          irq_set_irq_wake(v12, 0);
          devm_free_irq(v7, v8[42], a1);
        }
        v13 = v8[51];
        if ( (_DWORD)v13 )
        {
          irq_set_irq_wake(v13, 0);
          devm_free_irq(v7, v8[51], a1);
        }
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1C28B, "mbox_irq_deinit", 451, a4, a5);
        goto LABEL_16;
      }
    }
    else
    {
      v21 = v5;
      printk(&unk_1E83A, "mbox_irq_deinit", 420, a4, a5);
      v5 = v21;
      if ( v7 )
        goto LABEL_6;
    }
    v9 = v5;
    printk(&unk_1D5BD, "mbox_irq_deinit", 423, v5, a5);
LABEL_16:
    v14 = (_QWORD *)a1[30];
    if ( v14 )
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1E83A, "mbox_deinit", 203, a4, a5);
      v15 = v14[8];
      if ( v15 )
        mbox_free_channel(v15);
      v16 = v14[9];
      if ( v16 )
        mbox_free_channel(v16);
      v17 = v14[19];
      if ( v17 )
        mbox_free_channel(v17);
      v18 = v14[20];
      if ( v18 )
        mbox_free_channel(v18);
      v14[8] = 0;
      v14[9] = 0;
      v14[19] = 0;
      v14[20] = 0;
      kfree(v14);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      {
        printk(&unk_1E48C, "mbox_deinit", 227, "mbox_deinit", a5);
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1C28B, "mbox_deinit", 228, a4, a5);
      }
    }
    else
    {
      printk(&unk_1E404, "deinit_ipc", 532, v9, a5);
    }
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "deinit_ipc", 535, a4, a5);
  return 0;
}
