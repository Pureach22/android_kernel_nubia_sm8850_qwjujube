__int64 cleanup_module()
{
  driver_unregister(&off_B0);
  class_destroy(zte_ir_class);
  return _unregister_chrdev((unsigned int)spidev_major, 0, 256, off_B0);
}
