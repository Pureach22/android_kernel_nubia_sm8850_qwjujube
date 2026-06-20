__int64 __fastcall smmu_proxy_create_dev(__int64 a1)
{
  unsigned int v2; // w0
  unsigned __int64 v3; // x0
  unsigned int v4; // w19
  unsigned int v5; // w0
  unsigned __int64 v6; // x0

  v2 = alloc_chrdev_region(&smmu_proxy_dev_no, 0, 1, "qti-smmu-proxy");
  if ( (v2 & 0x80000000) != 0 )
  {
    return v2;
  }
  else
  {
    v3 = class_create("qti-smmu-proxy");
    smmu_proxy_class = v3;
    if ( v3 < 0xFFFFFFFFFFFFF001LL )
    {
      cdev_init(&smmu_proxy_char_dev, a1);
      v5 = cdev_add(&smmu_proxy_char_dev, (unsigned int)smmu_proxy_dev_no, 1);
      if ( (v5 & 0x80000000) != 0 )
      {
        v4 = v5;
      }
      else
      {
        v6 = device_create(smmu_proxy_class, 0, (unsigned int)smmu_proxy_dev_no, 0, "qti-smmu-proxy");
        if ( v6 < 0xFFFFFFFFFFFFF001LL )
          return 0;
        v4 = v6;
        cdev_del(&smmu_proxy_char_dev);
      }
      class_destroy(smmu_proxy_class);
    }
    else
    {
      v4 = v3;
    }
    unregister_chrdev_region((unsigned int)smmu_proxy_dev_no, 1);
  }
  return v4;
}
