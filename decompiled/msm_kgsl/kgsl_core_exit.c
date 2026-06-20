__int64 kgsl_core_exit()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x0

  kgsl_eventlog_exit();
  if ( qword_3A900 )
  {
    destroy_workqueue();
    qword_3A900 = 0;
  }
  if ( qword_3A908 )
  {
    destroy_workqueue();
    qword_3A908 = 0;
  }
  v0 = kgsl_events_exit();
  v1 = kgsl_core_debugfs_close(v0);
  kgsl_reclaim_close(v1);
  if ( qword_3A770 )
    device_unregister(&unk_3A458);
  if ( qword_3A450 )
  {
    class_destroy();
    qword_3A450 = 0;
  }
  kgsl_drawobjs_cache_exit();
  kfree(memfree);
  memfree = 0;
  qword_17D100 = 0;
  v2 = unregister_chrdev_region((unsigned int)dword_3A448, 1);
  return sysstats_unregister_kgsl_stats_cb(v2);
}
