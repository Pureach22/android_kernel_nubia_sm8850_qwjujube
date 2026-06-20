__int64 __fastcall power_init(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x22
  __int64 v9; // x4
  __int64 v10; // x19
  _QWORD *v11; // x25
  __int64 v12; // x0
  __int64 v13; // x4
  __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x21
  __int64 v19; // x3
  __int64 v20; // x4
  int v21; // w2
  unsigned int v22; // w0
  __int64 v23; // x4
  unsigned int v24; // w0
  __int64 v25; // x2
  __int64 v26; // x3
  unsigned int v27; // w0
  unsigned int v28; // w0
  unsigned int v29; // w0
  __int64 v30; // x2
  __int64 v31; // x3
  int v32; // w8
  unsigned int v33; // w0
  __int64 v34; // x3
  unsigned int v35; // w0
  __int64 v37; // x30
  unsigned int v38; // w23
  void *v39; // x0
  __int64 v40; // x2
  __int64 v41; // x22
  __int64 v42; // x2
  __int64 v43; // x30
  void *v44; // x0
  __int64 v45; // x2
  __int64 v46; // x30
  void *v47; // x0
  __int64 v48; // x2
  unsigned __int64 StatusReg; // x20
  __int64 v50; // x21
  __int64 (__fastcall *v51)(_QWORD); // x0

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a2 )
      goto LABEL_3;
LABEL_31:
    printk(&unk_1905C, "power_init", 888, v6, a5);
    return 4294967274LL;
  }
  printk(&unk_1E83A, "power_init", 885, a4, a5);
  if ( !a2 )
    goto LABEL_31;
LABEL_3:
  v10 = _kmalloc_cache_noprof(mbox_free_channel, 3520, 4);
  if ( !v10 )
  {
LABEL_51:
    printk(&unk_1D3F8, "power_init", 894, v6, v9);
    return 4294967284LL;
  }
  while ( a1 >= 4 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v50 = *(_QWORD *)(StatusReg + 80);
    v51 = mbox_free_channel;
    *(_QWORD *)(StatusReg + 80) = &power_init__alloc_tag;
    v10 = _kmalloc_cache_noprof(v51, 3520, 4);
    *(_QWORD *)(StatusReg + 80) = v50;
    if ( !v10 )
      goto LABEL_51;
  }
  v11 = (_QWORD *)(a2 + 176LL * a1);
  v11[21] = v10;
  v12 = _kmalloc_cache_noprof(mbox_free_channel, 3520, 4);
  v14 = v12;
  if ( !v12 )
  {
    printk(&unk_1A31C, "power_init", 901, v6, v13);
    v38 = -12;
    goto LABEL_49;
  }
  v11[22] = v12;
  v15 = _kmalloc_cache_noprof(irq_set_irq_wake, 3520, 24);
  v18 = v15;
  if ( !v15 )
  {
    printk(&unk_19D4E, "power_init", 909, v6, v17);
    v38 = -12;
    goto LABEL_48;
  }
  v11[23] = v15;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "hfi_core_enable_dcp_clock", 787, v16, v17);
  _init_waitqueue_head(v18, "queue", &hfi_core_enable_dcp_clock___key);
  if ( hfi_core_loop_back_mode_enable )
    v21 = 1;
  else
    v21 = 2;
  v22 = trigger_ipc(a1, a2, v21, v19, v20);
  if ( v22 )
  {
    v37 = v6;
    v38 = v22;
    v39 = &unk_1DD69;
    v40 = 802;
LABEL_34:
    v41 = v37;
    printk(v39, "hfi_core_enable_dcp_clock", v40, v37, v23);
    v42 = 917;
LABEL_47:
    printk(&unk_1A118, "power_init", v42, v41, v38);
    kfree(v18);
    v11[23] = 0;
LABEL_48:
    kfree(v14);
    v11[22] = 0;
LABEL_49:
    kfree(v10);
    v11[21] = 0;
    return v38;
  }
  v24 = hfi_core_wait_event(v11 + 2, v11[21]);
  if ( v24 )
  {
    v37 = v6;
    v38 = v24;
    v39 = &unk_1ABC9;
    v40 = 808;
    goto LABEL_34;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0
    || (printk(&unk_1C28B, "hfi_core_enable_dcp_clock", 812, v26, v23), (~msm_hfi_core_debug_level & 0x10001) != 0) )
  {
    if ( (hfi_core_loop_back_mode_enable & 1) != 0 )
      goto LABEL_17;
  }
  else
  {
    printk(&unk_1E83A, "hfi_core_setup_swi_registers", 822, v26, v23);
    if ( (hfi_core_loop_back_mode_enable & 1) != 0 )
      goto LABEL_17;
  }
  v27 = swi_setup_resources(a1, a2, v25, v26, v23);
  if ( v27 )
  {
    v43 = v6;
    v38 = v27;
    v44 = &unk_1A176;
    v45 = 828;
    goto LABEL_43;
  }
LABEL_17:
  v28 = trigger_ipc(a1, a2, 1, v26, v23);
  if ( v28 )
  {
    v43 = v6;
    v38 = v28;
    v44 = &unk_19DD5;
    v45 = 842;
LABEL_43:
    v41 = v43;
    printk(v44, "hfi_core_setup_swi_registers", v45, v43, v23);
    v42 = 923;
    goto LABEL_47;
  }
  v29 = hfi_core_wait_event(v11 + 2, v11[22]);
  if ( v29 )
  {
    v43 = v6;
    v38 = v29;
    v44 = &unk_1ABC9;
    v45 = 848;
    goto LABEL_43;
  }
  v32 = msm_hfi_core_debug_level;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( (hfi_core_loop_back_mode_enable & 1) == 0 )
    {
LABEL_21:
      if ( (~v32 & 0x10001) == 0 )
        printk(&unk_1E83A, "hfi_core_disable_dcp_clock", 861, v31, v23);
      v33 = swi_reg_power_off(a1, a2, v30, v31, v23);
      if ( v33 )
      {
        v46 = v6;
        v38 = v33;
        v47 = &unk_19E1A;
        v48 = 865;
      }
      else
      {
        v35 = trigger_ipc(a1, a2, 2, v34, v23);
        if ( !v35 )
        {
          v32 = msm_hfi_core_debug_level;
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          {
            printk(&unk_1C28B, "hfi_core_disable_dcp_clock", 875, v31, v23);
            v32 = msm_hfi_core_debug_level;
          }
          goto LABEL_27;
        }
        v46 = v6;
        v38 = v35;
        v47 = &unk_18F3C;
        v48 = 871;
      }
      v41 = v46;
      printk(v47, "hfi_core_disable_dcp_clock", v48, v46, v23);
      v42 = 931;
      goto LABEL_47;
    }
  }
  else
  {
    printk(&unk_1C28B, "hfi_core_setup_swi_registers", 852, v31, v23);
    v32 = msm_hfi_core_debug_level;
    if ( (hfi_core_loop_back_mode_enable & 1) == 0 )
      goto LABEL_21;
  }
LABEL_27:
  if ( (~v32 & 0x10001) == 0 )
    printk(&unk_1C28B, "power_init", 943, v31, v23);
  return 0;
}
