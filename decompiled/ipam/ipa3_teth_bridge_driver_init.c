__int64 ipa3_teth_bridge_driver_init()
{
  __int64 result; // x0
  __int64 v1; // x0
  __int64 v2; // x8
  unsigned __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x0

  if ( ipa3_teth_ctx )
    return 0;
  ipa3_teth_ctx = _kmalloc_cache_noprof(_kmalloc_noprof, 3520, 168);
  if ( !ipa3_teth_ctx )
    return 4294967284LL;
  v1 = class_create("ipa_tethering_bridge");
  v2 = ipa3_teth_ctx;
  *(_QWORD *)ipa3_teth_ctx = v1;
  if ( (unsigned int)alloc_chrdev_region(v2 + 8, 0, 1, "ipa_tethering_bridge") )
  {
    printk(&unk_3E7BA3, "ipa3_teth_bridge_driver_init");
  }
  else
  {
    v3 = device_create(
           *(_QWORD *)ipa3_teth_ctx,
           0,
           *(unsigned int *)(ipa3_teth_ctx + 8),
           ipa3_teth_ctx,
           "ipa_tethering_bridge");
    v4 = ipa3_teth_ctx;
    *(_QWORD *)(ipa3_teth_ctx + 16) = v3;
    if ( v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_3F96DB, "ipa3_teth_bridge_driver_init");
    }
    else
    {
      cdev_init(v4 + 24, &ipa3_teth_bridge_drv_fops);
      v5 = ipa3_teth_ctx;
      v6 = *(unsigned int *)(ipa3_teth_ctx + 8);
      v7 = ipa3_teth_ctx + 24;
      *(_QWORD *)(ipa3_teth_ctx + 120) = &_this_module;
      *(_QWORD *)(v5 + 128) = &ipa3_teth_bridge_drv_fops;
      result = cdev_add(v7, v6, 1);
      if ( !(_DWORD)result )
      {
        *(_QWORD *)(ipa3_teth_ctx + 160) = -1;
        return result;
      }
      printk(&unk_3D0F2E, "ipa3_teth_bridge_driver_init");
      device_destroy(*(_QWORD *)ipa3_teth_ctx, *(unsigned int *)(ipa3_teth_ctx + 8));
    }
    unregister_chrdev_region(*(unsigned int *)(ipa3_teth_ctx + 8), 1);
  }
  kfree(ipa3_teth_ctx);
  ipa3_teth_ctx = 0;
  return 4294967277LL;
}
