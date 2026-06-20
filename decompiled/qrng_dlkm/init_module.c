__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19
  void *v3; // x0

  msm_rng_dev_cached = 0;
  v0 = _platform_driver_register(rng_driver, &_this_module);
  if ( v0 )
  {
    v1 = v0;
    v3 = &unk_6F14;
LABEL_6:
    printk(v3);
    return v1;
  }
  v1 = crypto_register_rngs(rng_algs, 1);
  if ( v1 )
  {
    v3 = &unk_6C30;
    goto LABEL_6;
  }
  return v1;
}
