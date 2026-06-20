__int64 __fastcall init_module(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19

  printk(&unk_6F26, a2);
  spidev_major = _register_chrdev(0, 0, 1, "spi", &zte_ir_fops);
  printk(&unk_6F54, (unsigned int)spidev_major);
  zte_ir_class = class_create("zte_ir_class");
  if ( (unsigned __int64)zte_ir_class < 0xFFFFFFFFFFFFF001LL )
  {
    v2 = _spi_register_driver(&_this_module, &zte_ir_spi_driver);
    if ( (v2 & 0x80000000) != 0 )
    {
      class_destroy(zte_ir_class);
      _unregister_chrdev((unsigned int)spidev_major, 0, 256, off_B0);
    }
    printk(&unk_6F78, v2);
  }
  else
  {
    _unregister_chrdev((unsigned int)spidev_major, 0, 256, off_B0);
    return (unsigned int)zte_ir_class;
  }
  return v2;
}
