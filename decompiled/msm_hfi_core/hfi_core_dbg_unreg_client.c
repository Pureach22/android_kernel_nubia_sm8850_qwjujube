size_t __fastcall hfi_core_dbg_unreg_client(__int64 a1, __int64 a2, size_t a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x21
  __int64 v7; // x20
  __int64 v8; // x22
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  unsigned int debugfs_input_client; // w20
  __int64 v13; // x22
  __int64 v14; // x30
  void *v15; // x0
  __int64 v16; // x2
  __int64 *client_node; // x0
  __int64 *v19; // x8
  unsigned __int64 v20; // x0
  __int64 *v21; // x26
  __int64 v22; // x25
  int v23; // w0
  __int64 v24; // x3
  int v25; // w22
  __int64 v26[2]; // [xsp+0h] [xbp-10h] BYREF

  v5 = v4;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v7 = a1;
    v8 = a2;
    printk(&unk_1E83A, "hfi_core_dbg_unreg_client", 1907, a4);
    a1 = v7;
    a2 = v8;
  }
  v26[0] = 0;
  debugfs_input_client = get_debugfs_input_client(a1, a2, a3, v26);
  if ( (debugfs_input_client & 0x80000000) != 0
    || (v13 = v26[0]) == 0
    || !*(__int64 (__fastcall **)())((char *)get_param_func + v26[0]) )
  {
    v14 = v5;
    v15 = &unk_1F01E;
    v16 = 1914;
LABEL_7:
    printk(v15, "hfi_core_dbg_unreg_client", v16, v14);
    a3 = -22;
    goto LABEL_8;
  }
  client_node = get_client_node(v26[0], debugfs_input_client, v9, v10, v11);
  if ( !client_node || (v19 = client_node, (v20 = client_node[2]) == 0) || v20 >= 0xFFFFFFFFFFFFF001LL )
  {
    v14 = v5;
    v15 = &unk_1CA45;
    v16 = 1920;
    goto LABEL_7;
  }
  v21 = v19;
  v22 = *(__int64 *)((char *)get_param_func + v13);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1931E, "hfi_core_dbg_unreg_client", 1926, debugfs_input_client);
    v20 = v21[2];
  }
  v23 = ((__int64 (__fastcall *)(unsigned __int64))hfi_core_close_session)(v20);
  if ( v23 )
  {
    v25 = v23;
    printk(&unk_1E30A, "hfi_core_dbg_unreg_client", 1935, v5);
    a3 = v25;
  }
  else
  {
    mutex_lock(v22 + 32);
    _list_del_entry(v21);
    *v21 = (__int64)v21;
    v21[1] = (__int64)v21;
    mutex_unlock(v22 + 32);
    kfree(v21);
    if ( debugfs_input_client == 3 && *(_QWORD *)((char *)&unk_110 + v22) )
    {
      kthread_flush_worker(v22 + 136);
      kthread_stop(*(_QWORD *)((char *)&unk_110 + v22));
      byte_1FA28 = 0;
      dword_1FA48 = 0;
      byte_1FA4C = 0;
      qword_1FA2C = 0;
      qword_1FA34 = 0;
      qword_1FA3C = 0;
      byte_1FA50 = 0;
      dword_1FA70 = 0;
      byte_1FA74 = 0;
      qword_1FA54 = 0;
      qword_1FA5C = 0;
      qword_1FA64 = 0;
      byte_1FA78 = 0;
      dword_1FA98 = 0;
      byte_1FA9C = 0;
      qword_1FA7C = 0;
      qword_1FA84 = 0;
      qword_1FA8C = 0;
      byte_1FAA0 = 0;
      dword_1FAC0 = 0;
      byte_1FAC4 = 0;
      qword_1FAB4 = 0;
      qword_1FAAC = 0;
      qword_1FAA4 = 0;
      byte_1FAC8 = 0;
      dword_1FAE8 = 0;
      byte_1FAEC = 0;
      qword_1FADC = 0;
      qword_1FAD4 = 0;
      qword_1FACC = 0;
      byte_1FAF0 = 0;
      dword_1FB10 = 0;
      byte_1FB14 = 0;
      qword_1FB04 = 0;
      qword_1FAFC = 0;
      qword_1FAF4 = 0;
    }
    printk(&unk_1CFD4, "hfi_core_dbg_unreg_client", 1954, v5);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_core_dbg_unreg_client", 1956, v24);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a3;
}
