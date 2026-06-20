__int64 init_module()
{
  __int64 v0; // x0
  unsigned __int64 v1; // x20
  int v2; // w0
  unsigned int v3; // w21
  int v4; // w0
  unsigned __int64 v5; // x0
  int v6; // w8
  __int64 v7; // x28
  __int64 v8; // x19
  int v9; // w25
  __int64 v10; // x27
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v16; // x20

  if ( (unsigned int)(dword_104 - 17) <= 0xFFFFFFEF )
  {
    printk(&unk_7AB5);
    LODWORD(v1) = -33;
    return (unsigned int)v1;
  }
  if ( !is_mul_ok(dword_104, 0x1C8u) )
  {
    qword_108 = 0;
LABEL_35:
    LODWORD(v1) = -12;
    return (unsigned int)v1;
  }
  v0 = _kmalloc_noprof(456LL * dword_104, 3520);
LABEL_4:
  qword_108 = v0;
  if ( !v0 )
    goto LABEL_35;
  LODWORD(v1) = _platform_driver_register(&rdbg_driver, &_this_module);
  if ( (_DWORD)v1 )
    return (unsigned int)v1;
  v2 = alloc_chrdev_region(&dword_100, 0, (unsigned int)dword_104, "rdbgctl");
  if ( v2 )
  {
    LODWORD(v1) = v2;
    printk(&unk_795D);
LABEL_27:
    kfree(qword_108);
    return (unsigned int)v1;
  }
  v3 = dword_100 & 0xFFF00000;
  cdev_init(&g_rdbg_instance, &rdbg_fops);
  qword_D0 = (__int64)&_this_module;
  v4 = cdev_add(&g_rdbg_instance, v3, (unsigned int)dword_104);
  if ( v4 )
  {
    LODWORD(v1) = v4;
    printk(&unk_7B70);
LABEL_26:
    unregister_chrdev_region((unsigned int)dword_100, (unsigned int)dword_104);
    goto LABEL_27;
  }
  v5 = class_create("rdbg");
  qword_F8 = v5;
  if ( v5 > 0xFFFFFFFFFFFFF000LL )
  {
    LODWORD(v1) = v5;
    printk(&unk_764D);
LABEL_25:
    cdev_del(&g_rdbg_instance);
    goto LABEL_26;
  }
  v6 = dword_104;
  if ( dword_104 < 1 )
  {
LABEL_20:
    printk(&unk_7B9A);
    LODWORD(v1) = -22;
LABEL_21:
    class_destroy(qword_F8);
    goto LABEL_25;
  }
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = -1;
  do
  {
    if ( v10 == 15 )
    {
      __break(0x5512u);
LABEL_38:
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v16 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      if ( is_mul_ok(dword_104, 0x1C8u) )
        v0 = _kmalloc_noprof(456LL * dword_104, 3520);
      else
        v0 = 0;
      *(_QWORD *)(StatusReg + 80) = v16;
      goto LABEL_4;
    }
    if ( v8 == 384 )
      goto LABEL_38;
    if ( *(_QWORD *)((char *)&proc_info + v8) )
    {
      *(_QWORD *)(qword_108 + v7) = device_create(qword_F8, 0, v3 | ((_DWORD)v10 + 1), 0, &unk_7892);
      v1 = *(_QWORD *)(qword_108 + v7);
      if ( v1 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_7B11);
        if ( v10 != -1 )
        {
          v12 = qword_108;
          do
          {
            if ( *(_BYTE *)(v12 + 456LL * (unsigned int)v10 + 88) == 1 )
            {
              device_destroy(qword_F8, dword_100 & 0xFFF00000 | (unsigned int)v10);
              v12 = qword_108;
            }
            v13 = v10-- + 1;
          }
          while ( v13 > 1 );
        }
        goto LABEL_21;
      }
      ++v9;
      *(_BYTE *)(qword_108 + v7 + 88) = 1;
      v6 = dword_104;
    }
    v11 = v10 + 2;
    ++v10;
    v8 += 24;
    v7 += 456;
  }
  while ( v11 < v6 );
  if ( !v9 )
    goto LABEL_20;
  LODWORD(v1) = 0;
  return (unsigned int)v1;
}
