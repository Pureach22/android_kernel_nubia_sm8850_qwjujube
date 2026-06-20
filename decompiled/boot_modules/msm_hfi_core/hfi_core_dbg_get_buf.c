size_t __fastcall hfi_core_dbg_get_buf(__int64 a1, __int64 a2, size_t a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x21
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  unsigned int debugfs_input_client; // w20
  __int64 *client_node; // x0
  unsigned __int64 v12; // x8
  __int64 *v13; // x22
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  _QWORD *v18; // x23
  int v19; // w8
  __int64 v20; // x30
  void *v21; // x0
  __int64 v22; // x2
  __int64 v23; // x20
  __int64 v24; // x22
  __int64 v25; // x3
  __int64 v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v5 = v4;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v23 = a1;
    v24 = a2;
    printk(&unk_1E83A, "hfi_core_dbg_get_buf", 1468, a4);
    a1 = v23;
    a2 = v24;
  }
  v27[0] = 0;
  debugfs_input_client = get_debugfs_input_client(a1, a2, a3, v27);
  if ( (debugfs_input_client & 0x80000000) != 0
    || !v27[0]
    || !*(__int64 (__fastcall **)())((char *)get_param_func + v27[0]) )
  {
    v20 = v5;
    v21 = &unk_1F01E;
    v22 = 1475;
LABEL_21:
    printk(v21, "hfi_core_dbg_get_buf", v22, v20);
    goto LABEL_22;
  }
  client_node = get_client_node(v27[0], debugfs_input_client, v7, v8, v9);
  if ( !client_node || (v12 = client_node[2], v13 = client_node, !v12) || v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v20 = v5;
    v21 = &unk_1CA45;
    v22 = 1481;
    goto LABEL_21;
  }
  v14 = _kmalloc_cache_noprof(devm_free_irq, 3520, 40);
  v18 = (_QWORD *)v14;
  if ( !v14 )
  {
    v20 = v5;
    v21 = &unk_19B17;
    v22 = 1490;
    goto LABEL_21;
  }
  *(_DWORD *)(v14 + 24) = 1;
  if ( (unsigned int)hfi_core_cmds_tx_buf_get((unsigned int *)v13[2], v14, v15, v16, v17) || !*v18 || !v18[2] )
  {
    printk(&unk_1D215, "hfi_core_dbg_get_buf", 1499, v5);
LABEL_22:
    a3 = -22;
    goto LABEL_23;
  }
  v19 = msm_hfi_core_debug_level;
  v13[6] = (__int64)v18;
  if ( (~v19 & 0x10001) == 0 )
  {
    printk(&unk_1DA26, "hfi_core_dbg_get_buf", 1507, debugfs_input_client);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_core_dbg_get_buf", 1509, v25);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return a3;
}
