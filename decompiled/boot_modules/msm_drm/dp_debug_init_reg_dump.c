__int64 __fastcall dp_debug_init_reg_dump(__int64 a1, __int64 a2)
{
  unsigned __int64 file; // x0
  unsigned __int64 v5; // x0
  unsigned int v6; // w20
  __int64 v8; // x0
  __int64 ipc_log_context; // x0

  file = debugfs_create_file("exe_mode", 420, a2, a1, &exe_mode_fops);
  if ( file && file < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = debugfs_create_file("dump", 420, a2, a1, &dump_fops);
    if ( v5 && v5 < 0xFFFFFFFFFFFFF001LL )
    {
      return 0;
    }
    else
    {
      v6 = v5;
      ipc_log_context = get_ipc_log_context(v5);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d][%s] debugfs dump failed, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(const char **)(a1 + 96),
        v6);
      printk(&unk_245334, "dp_debug_init_reg_dump");
    }
  }
  else
  {
    v6 = file;
    v8 = get_ipc_log_context(file);
    ipc_log_string(
      v8,
      "[e][%-4d][%s] debugfs register failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(a1 + 96),
      v6);
    printk(&unk_259C0C, "dp_debug_init_reg_dump");
  }
  return v6;
}
