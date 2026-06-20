__int64 __fastcall cser_free_inst(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1

  v2 = *(_QWORD *)(a1 + 176);
  if ( v2 )
  {
    cdev_device_del(v2, v2 + 136);
    mutex_lock(&chardev_ida_lock);
    ida_free(&chardev_ida, *(unsigned int *)(*(_QWORD *)(a1 + 176) + 1064LL));
    mutex_unlock(&chardev_ida_lock);
    debugfs_remove(*(_QWORD *)(*(_QWORD *)(a1 + 176) + 1600LL));
    put_device(*(_QWORD *)(a1 + 176) + 136LL);
  }
  if ( !qword_158 )
  {
    if ( major )
    {
      if ( minors )
        v3 = 4;
      else
        v3 = 0;
      unregister_chrdev_region((unsigned int)(major << 20), v3);
      minors = 0;
      major = 0;
    }
    if ( fcdev_classp && (unsigned __int64)fcdev_classp <= 0xFFFFFFFFFFFFF000LL )
      class_destroy();
  }
  kfree(*(_QWORD *)(a1 + 184));
  return kfree(a1);
}
