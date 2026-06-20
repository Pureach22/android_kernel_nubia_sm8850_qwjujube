__int64 init_module()
{
  void *v0; // x0
  unsigned int v1; // w0
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  __int64 v6; // x5
  unsigned int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  unsigned __int64 dir; // x0
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  unsigned int v17; // w8
  unsigned int v19; // w19
  unsigned int v20; // w19
  unsigned __int64 v21; // x19

  g_frpc[0] = 0;
  _mutex_init(&unk_26CA8, "&g_frpc.gmut", &fastrpc_init___key);
  _mutex_init(&unk_26CD8, "&g_frpc.hmut", &fastrpc_init___key_517);
  qword_27520 = 0;
  qword_27518 = 0x1000000400000000LL;
  qword_27528 = 0;
  v0 = memset(&unk_26D08, 0, 0x800u);
  fastrpc_sysfs_register_kset(v0);
  qword_27508 = -1;
  qword_27510 = -1;
  v1 = _platform_driver_register(fastrpc_cb_driver, &_this_module);
  if ( (v1 & 0x80000000) != 0 )
  {
    v19 = v1;
    printk(&unk_259A3, v2, v3, v4, v5, v6);
    return v19;
  }
  else
  {
    v7 = fastrpc_transport_init();
    if ( (v7 & 0x80000000) != 0 )
    {
      v20 = v7;
      printk(&unk_23DE2, v8, v9, v10, v11, v12);
      platform_driver_unregister(fastrpc_cb_driver);
      return v20;
    }
    else
    {
      byte_27530 = 0;
      dir = debugfs_create_dir("fastrpc", 0);
      if ( !dir || dir >= 0xFFFFFFFFFFFFF001LL )
      {
        v21 = dir;
        printk(&unk_233DA, _ReadStatusReg(SP_EL0) + 2320, "fastrpc_init", v14, v15, v16);
        debugfs_remove(v21);
        dir = 0;
      }
      v17 = 0;
      qword_27538 = dir;
    }
  }
  return v17;
}
