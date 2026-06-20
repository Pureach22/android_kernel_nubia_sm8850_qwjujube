__int64 cleanup_module()
{
  __int64 v0; // x8
  _QWORD *v1; // x9
  _QWORD *v2; // x8
  _QWORD *v3; // x21

  _flush_workqueue(*(_QWORD *)(synx_dev + 160));
  _flush_workqueue(*(_QWORD *)(synx_dev + 168));
  device_destroy(*(_QWORD *)(synx_dev + 144), *(unsigned int *)(synx_dev + 136));
  class_destroy(*(_QWORD *)(synx_dev + 144));
  cdev_del(synx_dev);
  unregister_chrdev_region(*(unsigned int *)(synx_dev + 136), 1);
  synx_remove_debugfs_dir(synx_dev);
  v0 = synx_dev;
  v1 = *(_QWORD **)(synx_dev + 336);
  if ( v1 != (_QWORD *)(synx_dev + 336) )
  {
    do
    {
      v3 = (_QWORD *)*v1;
      v2 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v2 == v1 && (_QWORD *)v3[1] == v1 )
      {
        v3[1] = v2;
        *v2 = v3;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      kfree(v1 - 7);
      v0 = synx_dev;
      v1 = v3;
    }
    while ( v3 != (_QWORD *)(synx_dev + 336) );
  }
  vfree(*(_QWORD *)(v0 + 152));
  return kfree(synx_dev);
}
