__int64 __fastcall hfi_core_deinit(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
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
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x4
  unsigned int v22; // w0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  unsigned int v27; // w0
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v31; // x30
  unsigned int v32; // w19
  void *v33; // x0
  __int64 v34; // x2

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_11:
    printk(&unk_1905C, "hfi_core_deinit", 131, v6, a5);
    return 4294967274LL;
  }
  printk(&unk_1E83A, "hfi_core_deinit", 128, a4, a5);
  if ( !a1 )
    goto LABEL_11;
LABEL_3:
  hfi_core_dbg_debugfs_unregister(a1);
  v12 = deinit_ipc(a1, v8, v9, v10, v11);
  if ( v12 )
  {
    v31 = v6;
    v32 = v12;
    v33 = &unk_1A8B2;
    v34 = 140;
LABEL_16:
    printk(v33, "hfi_core_deinit", v34, v31, v32);
    return v32;
  }
  v17 = deinit_resources((__int64)a1, v13, v14, v15, v16);
  if ( v17 )
  {
    v31 = v6;
    v32 = v17;
    v33 = &unk_1917A;
    v34 = 146;
    goto LABEL_16;
  }
  v22 = deinit_swi((__int64)a1, v18, v19, v20, v21);
  if ( v22 )
  {
    v31 = v6;
    v32 = v22;
    v33 = &unk_1E122;
    v34 = 152;
    goto LABEL_16;
  }
  v27 = deinit_smmu((__int64)a1, v23, v24, v25, v26);
  if ( v27 )
  {
    v31 = v6;
    v32 = v27;
    v33 = &unk_18F6E;
    v34 = 158;
    goto LABEL_16;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_core_deinit", 162, v28, v29);
  return 0;
}
