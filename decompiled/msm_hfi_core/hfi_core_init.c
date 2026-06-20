__int64 __fastcall hfi_core_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  unsigned int inited; // w0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  unsigned int v12; // w0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  unsigned int v17; // w0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  unsigned int v21; // w0
  unsigned int v22; // w0
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v26; // x22
  __int64 v27; // x30
  unsigned int v28; // w19
  void *v29; // x0
  __int64 v30; // x2

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_12:
    printk(&unk_1905C, "hfi_core_init", 83, v6, a5);
    return 4294967274LL;
  }
  v26 = a1;
  printk(&unk_1E83A, "hfi_core_init", 80, a4, a5);
  a1 = v26;
  if ( !v26 )
    goto LABEL_12;
LABEL_3:
  drv_data = a1;
  inited = init_smmu(a1, a2, a3, a4, a5);
  if ( inited )
  {
    v27 = v6;
    v28 = inited;
    v29 = &unk_1C0D1;
    v30 = 91;
LABEL_18:
    printk(v29, "hfi_core_init", v30, v27, v28);
    return v28;
  }
  v12 = init_swi(drv_data, v8, v9, v10, v11);
  if ( v12 )
  {
    v27 = v6;
    v28 = v12;
    v29 = &unk_1DDB1;
    v30 = 97;
    goto LABEL_18;
  }
  v17 = init_resources(drv_data, v13, v14, v15, v16);
  if ( v17 )
  {
    v27 = v6;
    v28 = v17;
    v29 = &unk_1E5A4;
    v30 = 103;
    goto LABEL_18;
  }
  v21 = init_ipc((__int64 *)drv_data, (__int64)hfi_ipc_core_cb, v18, v19, v20);
  if ( v21 )
  {
    v27 = v6;
    v28 = v21;
    v29 = &unk_1C48E;
    v30 = 109;
    goto LABEL_18;
  }
  v22 = hfi_core_dbg_debugfs_register(drv_data);
  if ( v22 )
  {
    v27 = v6;
    v28 = v22;
    v29 = &unk_19E59;
    v30 = 115;
    goto LABEL_18;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_core_init", 119, v23, v24);
  return 0;
}
