unsigned __int64 __fastcall usb_cser_debugfs_init(__int64 a1)
{
  unsigned __int64 result; // x0

  result = debugfs_create_dir(a1 + 1052, 0);
  *(_QWORD *)(a1 + 1600) = result;
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return debugfs_create_file("remote_wakeup", 384, result, a1, &cser_rem_wakeup_fops);
  return result;
}
