__int64 __fastcall mem_buf_vm_put_class_device_cb(__int64 a1)
{
  cdev_device_del(a1 - 136, a1);
  return 0;
}
