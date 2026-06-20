__int64 init_module()
{
  __int64 v0; // x0
  __int64 v1; // x19
  unsigned __int64 v2; // x9
  __int64 v3; // x8
  unsigned int v4; // w0
  __int64 v5; // x21
  unsigned __int64 v6; // x0
  __int64 v7; // x19
  unsigned int v8; // w20
  __int64 v10; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11[1] = 0;
  v11[2] = 0;
  v0 = _kmalloc_large_noprof(0x80000, 3520);
  v1 = v0;
  if ( v0 )
  {
    v2 = (v0 << 8 >> 8) + 0x8000000000LL;
    strcpy((char *)v11, "KBOOT_LOG");
    v3 = memstart_addr + v2;
    v11[5] = 0x80000;
    if ( v2 >> 38 )
      v3 = (v0 << 8 >> 8) - kimage_voffset;
    v11[3] = v0;
    v11[4] = v3;
    v4 = msm_minidump_add_region(v11);
    if ( (v4 & 0x80000000) != 0 )
    {
      v8 = v4;
      printk(&unk_641B);
      kfree(v1);
    }
    else
    {
      boot_log_buf = v1;
      boot_log_pos = v1;
      boot_log_buf_left = 0x80000;
      __dmb(0xBu);
      kmsg_dump_rewind(&iter);
      v5 = qword_63C0;
      kmsg_dump_get_buffer(&iter, 1, boot_log_buf, 0x80000, &v10);
      boot_log_pos += v10;
      boot_log_buf_left -= v10;
      iter = v5;
      v6 = kthread_create_on_node(dump_thread_func, 0, 0xFFFFFFFFLL, "dump_thread");
      v7 = v6;
      if ( v6 <= 0xFFFFFFFFFFFFF000LL )
        wake_up_process(v6);
      v8 = 0;
      dump_thread = v7;
    }
  }
  else
  {
    v8 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
