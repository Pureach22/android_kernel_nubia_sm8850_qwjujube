__int64 cleanup_module()
{
  driver_unregister(&off_170);
  class_destroy(st54spi_class);
  return _unregister_chrdev((unsigned int)spidev_major, 0, 256, off_170);
}
