__int64 __fastcall init_ipc(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  int v9; // w8
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x3
  __int64 v13; // x4
  _QWORD *v14; // x23
  unsigned __int64 v15; // x0
  unsigned int v16; // w22
  unsigned __int64 v17; // x0
  __int64 v18; // x3
  __int64 v19; // x4
  unsigned __int64 v20; // x0
  __int64 v21; // x19
  unsigned __int64 v22; // x0
  __int64 v23; // x23
  __int64 v24; // x1
  unsigned int v25; // w0
  unsigned int v26; // w0
  unsigned int v27; // w0
  unsigned int v28; // w0
  __int64 v30; // x4
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x30
  void *v34; // x0
  __int64 v35; // x2

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_19:
      printk(&unk_1905C, "init_ipc", 461, v6, a5);
      return (unsigned int)-22;
    }
  }
  else
  {
    printk(&unk_1E83A, "init_ipc", 458, a4, a5);
    if ( !a1 )
      goto LABEL_19;
  }
  if ( !a2 )
    goto LABEL_19;
  v9 = msm_hfi_core_debug_level;
  if ( *((_DWORD *)a1 + 58) != 1 )
    goto LABEL_49;
  v10 = *a1;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( v10 )
      goto LABEL_7;
LABEL_24:
    v21 = v6;
    printk(&unk_1F41E, "mbox_init", 61, v6, 1);
    v16 = -22;
LABEL_56:
    printk(&unk_1BAFC, "init_ipc", 485, v21, v13);
    goto LABEL_65;
  }
  printk(&unk_1E83A, "mbox_init", 57, a4, a5);
  if ( !v10 )
    goto LABEL_24;
LABEL_7:
  v11 = _kmalloc_cache_noprof(mbox_client_txdone, 3520, 248);
  v14 = (_QWORD *)v11;
  if ( !v11 )
  {
    v16 = -12;
    goto LABEL_38;
  }
  *(_QWORD *)(v11 + 8) = v10;
  *(_BYTE *)(v11 + 32) = 1;
  v15 = mbox_request_channel(v11 + 8, 0);
  v14[8] = v15;
  if ( v15 >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = v15;
    if ( (_DWORD)v15 == -517 )
      v16 = -517;
    else
      printk(&unk_1CC4F, "mbox_init", 81, v6, (unsigned int)v15);
    goto LABEL_31;
  }
  v17 = mbox_request_channel(v14 + 1, 1);
  v14[9] = v17;
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)v17 == -517 )
    {
      v16 = -517;
    }
    else
    {
      v16 = v17;
      printk(&unk_1D2E8, "mbox_init", 90, v6, (unsigned int)v17);
    }
    goto LABEL_30;
  }
  if ( hfi_core_loop_back_mode_enable == 1 )
  {
    v20 = mbox_request_channel(v14 + 1, 2);
    v14[19] = v20;
    if ( v20 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v20 == -517 )
      {
        v16 = -517;
      }
      else
      {
        v16 = v20;
        printk(&unk_1F45D, "mbox_init", 103, v6, (unsigned int)v20);
      }
LABEL_29:
      mbox_free_channel(v14[9]);
LABEL_30:
      mbox_free_channel(v14[8]);
LABEL_31:
      kfree(v14);
LABEL_38:
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "mbox_init", 140, v12, v13);
      v21 = v6;
      goto LABEL_56;
    }
    v22 = mbox_request_channel(v14 + 1, 3);
    v14[20] = v22;
    if ( v22 >= 0xFFFFFFFFFFFFF001LL )
    {
      v16 = v22;
      if ( (_DWORD)v22 != -517 )
        printk(&unk_1E439, "mbox_init", 114, v6, (unsigned int)v22);
      mbox_free_channel(v14[19]);
      goto LABEL_29;
    }
  }
  else
  {
    v14[19] = 0;
    v14[20] = 0;
  }
  a1[30] = (__int64)v14;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1D899, "mbox_init", 124, v18, v19);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "mbox_init", 125, v18, v19);
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !*a1 )
    {
LABEL_53:
      printk(&unk_1A5F9, "mbox_irq_init", 361, v6, v19);
      v16 = -22;
      goto LABEL_64;
    }
  }
  else
  {
    printk(&unk_1E83A, "mbox_irq_init", 352, v18, v19);
    if ( !*a1 )
      goto LABEL_53;
  }
  v23 = a1[30];
  if ( !v23 )
    goto LABEL_53;
  v24 = a1[30];
  *(_DWORD *)v23 = 1;
  *(_QWORD *)(v23 + 240) = a2;
  v25 = setup_irq(a1, v24, 0);
  if ( v25 )
  {
    v33 = v6;
    v16 = v25;
    v34 = &unk_1B6DB;
    v35 = 378;
  }
  else
  {
    v26 = setup_irq(a1, v23, 1);
    if ( v26 )
    {
      v33 = v6;
      v16 = v26;
      v34 = &unk_1A633;
      v35 = 385;
    }
    else
    {
      if ( hfi_core_loop_back_mode_enable != 1 )
        goto LABEL_48;
      v27 = setup_irq(a1, v23, 2);
      if ( v27 )
      {
        v33 = v6;
        v16 = v27;
        v34 = &unk_1DB87;
        v35 = 396;
      }
      else
      {
        v28 = setup_irq(a1, v23, 3);
        if ( !v28 )
        {
LABEL_48:
          v9 = msm_hfi_core_debug_level;
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          {
            printk(&unk_1C28B, "mbox_irq_init", 410, a4, a5);
            if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
              return 0;
            goto LABEL_60;
          }
LABEL_49:
          if ( (~v9 & 0x10001) != 0 )
            return 0;
LABEL_60:
          printk(&unk_1C28B, "init_ipc", 496, a4, a5);
          return 0;
        }
        v33 = v6;
        v16 = v28;
        v34 = &unk_18D79;
        v35 = 404;
      }
    }
  }
  v6 = v33;
  printk(v34, "mbox_irq_init", v35, v33, v16);
LABEL_64:
  printk(&unk_1EF07, "init_ipc", 491, v6, v30);
  deinit_ipc(a1);
LABEL_65:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "init_ipc", 502, v31, v32);
  return v16;
}
