__int64 __fastcall msm_rng_remove(__int64 a1)
{
  _QWORD *v2; // x19
  __int64 result; // x0

  v2 = *(_QWORD **)(a1 + 168);
  cdev_del(&msm_rng_cdev);
  device_destroy(msm_rng_class, 0x10000000);
  class_destroy(msm_rng_class);
  _unregister_chrdev(256, 0, 256, "msm_rng");
  hwrng_unregister(&msm_rng);
  if ( v2[2] )
    clk_put();
  iounmap(v2[1]);
  *(_QWORD *)(a1 + 168) = 0;
  if ( v2[9] )
    icc_put();
  result = kfree_sensitive(v2);
  msm_rng_dev_cached = 0;
  return result;
}
