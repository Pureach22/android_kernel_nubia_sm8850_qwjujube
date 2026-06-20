__int64 __fastcall secure_etr_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  _pm_runtime_disable(a1 + 16, 1);
  device_destroy(*(_QWORD *)(v1 + 160), *(unsigned int *)(v1 + 152));
  class_destroy(*(_QWORD *)(v1 + 160));
  cdev_del(v1 + 24);
  unregister_chrdev_region(*(unsigned int *)(v1 + 152), 1);
  return coresight_unregister(*(_QWORD *)(v1 + 8));
}
