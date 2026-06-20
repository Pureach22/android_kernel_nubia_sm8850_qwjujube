__int64 init_module()
{
  __int64 result; // x0
  unsigned int v1; // w19

  result = _register_chrdev(0, 0, 256, "mhi_uci", &mhidev_fops);
  if ( (result & 0x80000000) == 0 )
  {
    dword_8708 = result;
    qword_8700 = class_create("mhi_uci");
    if ( (unsigned __int64)qword_8700 <= 0xFFFFFFFFFFFFF000LL )
    {
      _mutex_init(&unk_86D0, "&mhi_uci_drv.lock", &mhi_uci_init___key);
      mhi_uci_drv = (__int64)&mhi_uci_drv;
      qword_86C8 = (__int64)&mhi_uci_drv;
      result = _mhi_driver_register(&mhi_uci_driver, &_this_module);
      if ( (_DWORD)result )
      {
        v1 = result;
        class_destroy(qword_8700);
        return v1;
      }
    }
    else
    {
      return 4294967277LL;
    }
  }
  return result;
}
