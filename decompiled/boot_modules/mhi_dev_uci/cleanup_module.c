__int64 cleanup_module()
{
  if ( dword_8708 )
  {
    unregister_chrdev_region((unsigned int)(dword_8708 << 20));
    dword_8708 = 0;
  }
  class_destroy(qword_8700);
  return mhi_driver_unregister(&mhi_uci_driver);
}
