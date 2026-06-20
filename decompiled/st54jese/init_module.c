__int64 __fastcall init_module(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19

  printk(&unk_8DA8, a2);
  spidev_major = _register_chrdev(0, 0, 1, "spi", &st54spi_fops);
  printk(&unk_9043, (unsigned int)spidev_major);
  st54spi_class = class_create("st54spi");
  if ( (unsigned __int64)st54spi_class < 0xFFFFFFFFFFFFF001LL )
  {
    v2 = _spi_register_driver(&_this_module, &st54spi_spi_driver);
    if ( (v2 & 0x80000000) != 0 )
    {
      class_destroy(st54spi_class);
      _unregister_chrdev((unsigned int)spidev_major, 0, 256, off_170);
    }
    printk(&unk_9005, v2);
  }
  else
  {
    _unregister_chrdev((unsigned int)spidev_major, 0, 256, off_170);
    return (unsigned int)st54spi_class;
  }
  return v2;
}
