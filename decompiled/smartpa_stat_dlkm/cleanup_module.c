__int64 cleanup_module()
{
  return remove_proc_entry("driver/smarttest", 0);
}
