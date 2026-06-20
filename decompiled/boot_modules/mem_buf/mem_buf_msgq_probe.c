__int64 __fastcall mem_buf_msgq_probe(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w0
  unsigned __int64 v4; // x0

  if ( mem_buf_dev )
  {
    v2 = mem_buf_msgq_alloc(a1 + 16);
    if ( !v2 )
    {
      cdev_init(&mem_buf_char_dev, &mem_buf_dev_fops);
      v3 = cdev_add(&mem_buf_char_dev, (unsigned int)mem_buf_dev_no, 1);
      if ( (v3 & 0x80000000) != 0 )
      {
        v2 = v3;
      }
      else
      {
        v4 = device_create(mem_buf_class, 0, (unsigned int)mem_buf_dev_no, 0, "membuf");
        if ( v4 < 0xFFFFFFFFFFFFF001LL )
        {
          v2 = gunyah_qtvm_register_notifier(&vm_nb);
          if ( !v2 )
          {
            debugfs_create_file("xmem_total_size", 256, mem_buf_debugfs_root, 0, &mem_buf_debug_xmem_total_size_fops);
            return v2;
          }
          gunyah_qtvm_unregister_notifier(&vm_nb);
        }
        else
        {
          v2 = v4;
        }
        cdev_del(&mem_buf_char_dev);
      }
      mem_buf_msgq_free(a1 + 16);
    }
  }
  else
  {
    return (unsigned int)-517;
  }
  return v2;
}
