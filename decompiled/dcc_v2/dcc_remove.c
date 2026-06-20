__int64 __fastcall dcc_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  device_destroy(*(_QWORD *)(v1 + 304), *(unsigned int *)(v1 + 296));
  class_destroy(*(_QWORD *)(v1 + 304));
  cdev_del(v1 + 168);
  unregister_chrdev_region(*(unsigned int *)(v1 + 296), 1);
  return dcc_config_reset(v1);
}
