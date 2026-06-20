__int64 __fastcall qbt_remove(__int64 a1)
{
  _QWORD *v2; // x20

  printk(&unk_9DD2, "qbt_remove");
  v2 = *(_QWORD **)(a1 + 168);
  device_destroy(*v2, *((unsigned int *)v2 + 34));
  device_destroy(*v2, *((unsigned int *)v2 + 68));
  class_destroy(*v2);
  cdev_del(v2 + 1);
  cdev_del(v2 + 18);
  unregister_chrdev_region(*((unsigned int *)v2 + 34), 1);
  unregister_chrdev_region(*((unsigned int *)v2 + 68), 1);
  device_wakeup_disable(a1 + 16);
  device_set_wakeup_capable(a1 + 16, 0);
  return input_unregister_handler(&qbt_touch_handler);
}
