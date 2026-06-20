__int64 smcinvoke_probe()
{
  unsigned int v0; // w0
  unsigned __int64 v1; // x0
  unsigned int v2; // w0
  unsigned __int64 v3; // x0
  unsigned int qseecom_kernel_fun_ops; // w0
  unsigned int v5; // w19

  v0 = alloc_chrdev_region(&smcinvoke_device_no, 0, 1, "smcinvoke");
  if ( (v0 & 0x80000000) != 0 )
  {
    v5 = v0;
    printk(&unk_10B23, "smcinvoke_probe", v0);
    return v5;
  }
  v1 = class_create("smcinvoke");
  driver_class = v1;
  if ( v1 >= 0xFFFFFFFFFFFFF001LL )
  {
    v5 = v1;
    printk(&unk_10626, "smcinvoke_probe", (unsigned int)v1);
LABEL_14:
    unregister_chrdev_region((unsigned int)smcinvoke_device_no, 1);
    return v5;
  }
  cdev_init(&smcinvoke_cdev, &root_fops);
  qword_118E8 = (__int64)&_this_module;
  v2 = cdev_add(&smcinvoke_cdev, smcinvoke_device_no & 0xFFF00000, 1);
  if ( (v2 & 0x80000000) != 0 )
  {
    v5 = v2;
    printk(&unk_1034F, "smcinvoke_probe", v2);
LABEL_13:
    class_destroy(driver_class);
    goto LABEL_14;
  }
  v3 = device_create(driver_class, 0, (unsigned int)smcinvoke_device_no, 0, "smcinvoke");
  smci_dev = v3;
  if ( v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    v5 = v3;
    printk(&unk_10850, "smcinvoke_probe", (unsigned int)v3);
    cdev_del(&smcinvoke_cdev);
    goto LABEL_13;
  }
  qseecom_kernel_fun_ops = get_qseecom_kernel_fun_ops();
  if ( qseecom_kernel_fun_ops )
    printk(&unk_10BC4, "smcinvoke_probe", qseecom_kernel_fun_ops);
  return 0;
}
