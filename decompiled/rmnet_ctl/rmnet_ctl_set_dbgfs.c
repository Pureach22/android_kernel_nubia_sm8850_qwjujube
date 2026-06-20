__int64 __fastcall rmnet_ctl_set_dbgfs(__int64 result)
{
  unsigned __int64 v1; // x2

  v1 = qword_6B10;
  if ( (result & 1) != 0 )
  {
    if ( !qword_6B10 || (unsigned __int64)qword_6B10 >= 0xFFFFFFFFFFFFF001LL )
    {
      result = debugfs_create_dir("rmnet_ctl", 0, qword_6B10);
      v1 = result;
      qword_6B10 = result;
    }
    if ( v1 && v1 <= 0xFFFFFFFFFFFFF000LL )
      result = debugfs_create_u8("ipc_log_lvl", 420);
    if ( !qword_6B20 )
    {
      result = ipc_log_context_create(10, "rmnet_ctl", 0);
      qword_6B20 = result;
    }
  }
  else
  {
    debugfs_remove(qword_6B10);
    result = ipc_log_context_destroy(qword_6B20);
    qword_6B10 = 0;
    qword_6B18 = 0;
    qword_6B20 = 0;
  }
  return result;
}
