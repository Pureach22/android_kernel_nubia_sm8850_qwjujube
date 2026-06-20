size_t __fastcall hfi_core_dbg_send_buf(__int64 a1, __int64 a2, size_t a3, __int64 a4)
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
  __int64 v18; // x4
  unsigned __int64 v19; // x8
  __int64 *v20; // x22
  _QWORD *v21; // x8
  _QWORD *v22; // x22
  __int64 *v23; // x25
  int v24; // w0
  __int64 v25; // x3
  int v26; // w22
  __int64 v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v5 = v4;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v7 = a1;
    v8 = a2;
    printk(&unk_1E83A, "hfi_core_dbg_send_buf", 1521, a4);
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
    v15 = 1528;
LABEL_7:
    printk(v14, "hfi_core_dbg_send_buf", v15, v13);
LABEL_8:
    a3 = -22;
    goto LABEL_9;
  }
  client_node = get_client_node(v27[0], debugfs_input_client, v9, v10, v11);
  if ( !client_node || (v19 = client_node[2]) == 0 || v19 >= 0xFFFFFFFFFFFFF001LL )
  {
    v13 = v5;
    v14 = &unk_1CA45;
    v15 = 1534;
    goto LABEL_7;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v20 = client_node;
    printk(&unk_1931E, "hfi_core_dbg_send_buf", 1539, debugfs_input_client);
    client_node = v20;
  }
  v22 = client_node + 6;
  v21 = (_QWORD *)client_node[6];
  if ( !v21 )
  {
    printk(&unk_1974A, "hfi_core_dbg_send_buf", 1551, v5);
    goto LABEL_8;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v23 = client_node;
    printk(&unk_1B5A2, "hfi_core_dbg_send_buf", 1549, *v21);
    client_node = v23;
  }
  v24 = hfi_core_cmds_tx_buf_send((unsigned int *)client_node[2], v22, 1u, 1, v18);
  if ( v24 )
  {
    v26 = v24;
    printk(&unk_1D7AC, "hfi_core_dbg_send_buf", 1560, v5);
    a3 = v26;
  }
  else
  {
    printk(&unk_1ED72, "hfi_core_dbg_send_buf", 1566, v5);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_core_dbg_send_buf", 1568, v25);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return a3;
}
