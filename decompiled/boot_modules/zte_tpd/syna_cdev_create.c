__int64 __fastcall syna_cdev_create(__int64 a1, __int64 a2)
{
  int v3; // w0
  __int64 v4; // x2
  unsigned __int64 v5; // x20
  void *v6; // x0
  int v7; // w0
  __int64 v8; // x1
  int v9; // w0
  __int64 v10; // x2
  unsigned __int64 v11; // x0
  __int64 v12; // x2
  unsigned __int64 v13; // x0
  __int64 v14; // x2

  g_cdev_data = a2;
  qword_31708 = 0;
  qword_31710 = 0;
  qword_316F8 = 0;
  qword_31700 = 0;
  qword_316E8 = 0;
  qword_316F0 = 0;
  qword_316D8 = 0;
  qword_316E0 = 0;
  qword_316C0 = 0;
  qword_316C8 = 0;
  qword_316B0 = 0;
  qword_316B8 = 0;
  qword_316A8 = 0;
  qword_31690 = 0;
  qword_31698 = 0;
  qword_31680 = 0;
  qword_31688 = 0;
  qword_31670 = 0;
  qword_31678 = 0;
  qword_31658 = 0;
  qword_31660 = 0;
  qword_31668 = 0;
  qword_316D0 = 0;
  qword_316A0 = 0;
  *(_QWORD *)(a1 + 904) = 0;
  *(_QWORD *)(a1 + 912) = 0;
  _mutex_init(&qword_316A0, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_0);
  _mutex_init(&qword_316D0, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_0);
  LOBYTE(qword_31698) = 0;
  qword_31658 = 0;
  qword_31660 = 0;
  _mutex_init(&qword_31668, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_0);
  if ( syna_cdev_create_cdev_major_num )
  {
    *(_DWORD *)(a1 + 896) = syna_cdev_create_cdev_major_num << 20;
    v3 = register_chrdev_region();
    if ( v3 < 0 )
    {
      LODWORD(v5) = v3;
      v6 = &unk_3A3DA;
LABEL_17:
      printk(v6, "syna_cdev_create", v4);
      return (unsigned int)v5;
    }
  }
  else
  {
    v7 = alloc_chrdev_region(a1 + 896, 0, 1, "synaptics_tcm");
    if ( v7 < 0 )
    {
      LODWORD(v5) = v7;
      v6 = &unk_3362E;
      goto LABEL_17;
    }
    syna_cdev_create_cdev_major_num = *(_DWORD *)(a1 + 896) >> 20;
  }
  cdev_init(a1 + 760, &device_fops);
  v8 = *(unsigned int *)(a1 + 896);
  *(_QWORD *)(a1 + 856) = &_this_module;
  v9 = cdev_add(a1 + 760, v8, 1);
  if ( v9 < 0 )
  {
    LODWORD(v5) = v9;
    printk(&unk_3A9AC, "syna_cdev_create", v10);
LABEL_15:
    unregister_chrdev_region(*(unsigned int *)(a1 + 896), 1);
    return (unsigned int)v5;
  }
  v11 = class_create("synaptics_tcm");
  v5 = v11;
  if ( v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_35AC9, "syna_cdev_create", v12);
LABEL_14:
    cdev_del(a1 + 760);
    goto LABEL_15;
  }
  *(_QWORD *)(v11 + 32) = syna_cdev_devnode;
  v13 = device_create(v11, 0, *(unsigned int *)(a1 + 896), 0, "tcm%d", *(_DWORD *)(a1 + 896) & 0xFFFFF);
  if ( v13 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3B816, "syna_cdev_create", v14);
    class_destroy(v5);
    LODWORD(v5) = -2;
    goto LABEL_14;
  }
  *(_QWORD *)(a1 + 912) = v13;
  HIDWORD(qword_31700) = 0;
  *(_QWORD *)(a1 + 904) = v5;
  *(_DWORD *)(a1 + 900) = 0;
  *(_QWORD *)(a1 + 1272) = a1 + 1272;
  *(_QWORD *)(a1 + 1280) = a1 + 1272;
  _init_waitqueue_head(a1 + 1288, "&tcm->wait_frame", &syna_cdev_create___key);
  LODWORD(v5) = 0;
  return (unsigned int)v5;
}
