__int64 cleanup_module()
{
  crypto_unregister_rngs(rng_algs, 1);
  return platform_driver_unregister(rng_driver);
}
