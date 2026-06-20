__int64 __fastcall qcom_stats_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  device_destroy(*(_QWORD *)(v1 + 40), *(unsigned int *)(v1 + 32));
  class_destroy(*(_QWORD *)(v1 + 40));
  cdev_del(v1 + 56);
  unregister_chrdev_region(*(unsigned int *)(v1 + 32), 1);
  return debugfs_remove(*(_QWORD *)(v1 + 24));
}
