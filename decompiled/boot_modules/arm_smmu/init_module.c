__int64 __fastcall init_module(__int64 a1)
{
  unsigned int v1; // w20
  __int64 v2; // x0

  ktime_get(a1);
  v1 = _platform_driver_register(&qsmmuv500_tbu_driver, &_this_module);
  if ( !v1 )
  {
    v2 = _platform_driver_register(arm_smmu_driver, &_this_module);
    if ( (_DWORD)v2 )
    {
      v1 = v2;
      platform_driver_unregister(&qsmmuv500_tbu_driver);
    }
    else
    {
      ktime_get(v2);
      return 0;
    }
  }
  return v1;
}
