__int64 spcom_unregister_chrdev()
{
  cdev_del(spcom_dev + 1024);
  device_destroy(*(_QWORD *)(spcom_dev + 1168), *(unsigned int *)(spcom_dev + 1160));
  class_destroy(*(_QWORD *)(spcom_dev + 1168));
  mutex_lock(spcom_dev + 58296);
  unregister_chrdev_region(*(unsigned int *)(spcom_dev + 1160), *(unsigned int *)(spcom_dev + 58288));
  mutex_unlock(spcom_dev + 58296);
  return ipc_log_string(
           spcom_ipc_log_context,
           "%sspcom:%s: control spcom device removed\n",
           "spcom_unregister_chrdev",
           (const char *)&unk_F80E);
}
