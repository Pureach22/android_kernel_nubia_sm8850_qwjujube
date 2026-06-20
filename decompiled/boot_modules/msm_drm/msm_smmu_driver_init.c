__int64 msm_smmu_driver_init()
{
  __int64 v0; // x1
  unsigned int v1; // w19

  v1 = _platform_driver_register(msm_smmu_driver, &_this_module);
  if ( v1 )
    printk(&unk_229656, v0);
  return v1;
}
