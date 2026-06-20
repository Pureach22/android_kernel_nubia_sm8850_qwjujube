__int64 init_module()
{
  unsigned int v0; // w0
  unsigned __int64 v1; // x0
  unsigned int v2; // w19
  unsigned int v3; // w0

  v0 = alloc_chrdev_region(&mem_buf_dev_no, 0, 1, "membuf");
  if ( (v0 & 0x80000000) != 0 )
  {
    return v0;
  }
  else
  {
    v1 = class_create("membuf");
    mem_buf_class = v1;
    if ( v1 >= 0xFFFFFFFFFFFFF001LL )
    {
      v2 = v1;
LABEL_8:
      unregister_chrdev_region((unsigned int)mem_buf_dev_no, 1);
      return v2;
    }
    v3 = _platform_driver_register(mem_buf_msgq_driver, &_this_module);
    if ( (v3 & 0x80000000) != 0 )
    {
      v2 = v3;
      class_destroy(mem_buf_class);
      goto LABEL_8;
    }
    return 0;
  }
}
