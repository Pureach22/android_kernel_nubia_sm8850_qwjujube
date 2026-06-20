size_t __fastcall hfi_core_dbg_put_tx_buf(__int64 a1, __int64 a2, size_t a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x21
  __int64 v7; // x20
  __int64 v8; // x22
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  unsigned int debugfs_input_client; // w20
  __int64 v13; // x30
  void *v14; // x0
  __int64 v15; // x2
  __int64 *client_node; // x0
  unsigned __int64 v18; // x8
  __int64 *v19; // x22
  _QWORD *v20; // x8
  _QWORD *v21; // x22
  __int64 *v22; // x25
  __int64 v23; // x3
  __int64 v24; // x4
  int v25; // w22
  __int64 v26; // x3
  __int64 v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v5 = v4;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v7 = a1;
    v8 = a2;
    printk(&unk_1E83A, "hfi_core_dbg_put_tx_buf", 1847, a4);
    a1 = v7;
    a2 = v8;
  }
  v27[0] = 0;
  debugfs_input_client = get_debugfs_input_client(a1, a2, a3, v27);
  if ( (debugfs_input_client & 0x80000000) != 0
    || !v27[0]
    || !*(__int64 (__fastcall **)())((char *)get_param_func + v27[0]) )
  {
    v13 = v5;
    v14 = &unk_1F01E;
    v15 = 1854;
LABEL_7:
    printk(v14, "hfi_core_dbg_put_tx_buf", v15, v13);
    a3 = -22;
    goto LABEL_8;
  }
  client_node = get_client_node(v27[0], debugfs_input_client, v9, v10, v11);
  if ( !client_node || (v18 = client_node[2]) == 0 || v18 >= 0xFFFFFFFFFFFFF001LL )
  {
    v13 = v5;
    v14 = &unk_1CA45;
    v15 = 1860;
    goto LABEL_7;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v19 = client_node;
    printk(&unk_1931E, "hfi_core_dbg_put_tx_buf", 1865, debugfs_input_client);
    client_node = v19;
  }
  v21 = client_node + 6;
  v20 = (_QWORD *)client_node[6];
  if ( v20 )
  {
    v22 = client_node;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1F203, "hfi_core_dbg_put_tx_buf", 1873, *v20);
    printk(&unk_1DE77, "hfi_core_dbg_put_tx_buf", 1882, v5);
    v25 = hfi_core_release_tx_buffer((unsigned int *)v22[2], v21, 1u, v23, v24);
    if ( v25 )
    {
      printk(&unk_1D7AC, "hfi_core_dbg_put_tx_buf", 1889, v5);
      a3 = v25;
    }
    else
    {
      kfree(v22[6]);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "hfi_core_dbg_put_tx_buf", 1894, v26);
    }
  }
  else
  {
    printk(&unk_1974A, "hfi_core_dbg_put_tx_buf", 1875, v5);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a3;
}
