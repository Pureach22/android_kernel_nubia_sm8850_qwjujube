__int64 hdd_driver_memdump_deinit()
{
  __int64 result; // x0

  if ( proc_file_driver )
  {
    remove_proc_entry("driverdump", proc_dir_driver);
    return remove_proc_entry("debugdriver", 0);
  }
  return result;
}
