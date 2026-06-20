__int64 __fastcall msm_rng_probe(__int64 a1)
{
  _QWORD *v2; // x19
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  unsigned __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x21
  int v11; // w0
  int v12; // w0
  __int64 v13; // x21
  __int64 v14; // x0
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned __int64 v17; // x0
  unsigned int v18; // w21
  unsigned __int64 v19; // x0

  if ( !platform_get_resource(a1, 512, 0) )
  {
    dev_err(a1 + 16, "invalid address\n");
    return (unsigned int)-14;
  }
  v2 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( !v2 )
    return (unsigned int)-12;
  v3 = ioremap_prot();
  if ( !v3 )
  {
    dev_err(a1 + 16, "ioremap failed\n");
    v18 = -12;
LABEL_49:
    kfree_sensitive(v2);
    return v18;
  }
  v4 = v3;
  v5 = *(_QWORD *)(a1 + 760);
  v2[1] = v4;
  if ( v5 )
  {
    if ( of_find_property(v5, "qcom,no-clock-support", 0) )
    {
      v2[2] = 0;
      goto LABEL_8;
    }
    v19 = clk_get(a1 + 16, "km_clk_src");
    v2[2] = v19;
    if ( v19 >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_30:
      dev_err(a1 + 16, "failed to register clock source\n");
      v18 = -19;
LABEL_48:
      iounmap(v2[1]);
      goto LABEL_49;
    }
  }
  else if ( v2[2] >= 0xFFFFFFFFFFFFF001LL )
  {
    goto LABEL_30;
  }
LABEL_8:
  v6 = *(_QWORD *)(a1 + 760);
  *v2 = a1;
  *(_QWORD *)(a1 + 168) = v2;
  if ( v6 )
  {
    v7 = of_icc_get(a1 + 16, "data_path");
    v2[9] = v7;
    msm_rng_device_info_0 = v7;
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      v18 = v7;
      dev_err(a1 + 16, "get icc path err %d\n", v7);
      goto LABEL_46;
    }
    v8 = *(_QWORD *)(a1 + 760);
    if ( v8 && of_find_property(v8, "qcom,no-qrng-config", 0) )
      goto LABEL_24;
  }
  v9 = v2[9];
  if ( v9 && (unsigned int)icc_set_bw(v9, 0, 30000) )
  {
    printk(&unk_6F82);
    v10 = v2[2];
    if ( !v10 )
      goto LABEL_17;
    goto LABEL_15;
  }
  v10 = v2[2];
  if ( v10 )
  {
LABEL_15:
    if ( !(unsigned int)clk_prepare(v10) )
    {
      if ( !(unsigned int)clk_enable(v10) )
        goto LABEL_17;
      clk_unprepare(v10);
    }
    dev_err(*v2 + 16LL, "failed to enable clock in probe\n");
    v18 = -1;
LABEL_46:
    if ( v2[2] )
      clk_put();
    goto LABEL_48;
  }
LABEL_17:
  if ( (readl_relaxed(v2[1] + 260LL) & 2) == 0 )
  {
    v11 = readl_relaxed(v2[1] + 256LL);
    writel_relaxed(v11 & 0xFFFF0000 | 0xDDDD, v2[1] + 256LL);
    __dsb(0xFu);
    v12 = readl_relaxed(v2[1] + 260LL);
    writel_relaxed(v12 | 2u, v2[1] + 260LL);
    __dsb(0xFu);
  }
  v13 = v2[2];
  if ( v13 )
  {
    clk_disable(v2[2]);
    clk_unprepare(v13);
  }
  v14 = v2[9];
  if ( v14 && (unsigned int)icc_set_bw(v14, 0, 0) )
    printk(&unk_6F82);
LABEL_24:
  _mutex_init(v2 + 3, "&msm_rng_dev->rng_lock", &msm_rng_probe___key);
  _mutex_init(&cached_rng_lock, "&cached_rng_lock", &msm_rng_probe___key_16);
  qword_140 = (__int64)v2;
  v15 = hwrng_register();
  if ( v15 )
  {
    v18 = v15;
    dev_err(a1 + 16, "failed to register hwrng\n");
    goto LABEL_39;
  }
  v16 = _register_chrdev(256, 0, 256, "msm_rng", &msm_rng_fops);
  if ( v16 )
  {
    v18 = v16;
    dev_err(a1 + 16, "failed to register chrdev\n");
LABEL_38:
    hwrng_unregister(&msm_rng);
LABEL_39:
    if ( v2[9] )
      icc_put();
    goto LABEL_46;
  }
  msm_rng_class = class_create("msm-rng");
  if ( (unsigned __int64)msm_rng_class >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_6E49);
    v18 = msm_rng_class;
LABEL_37:
    _unregister_chrdev(256, 0, 256, "msm_rng");
    goto LABEL_38;
  }
  v17 = device_create();
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    v18 = v17;
    printk(&unk_6D3F);
    class_destroy(msm_rng_class);
    goto LABEL_37;
  }
  cdev_init(&msm_rng_cdev, &msm_rng_fops);
  v18 = 0;
  msm_rng_dev_cached = (__int64)v2;
  return v18;
}
