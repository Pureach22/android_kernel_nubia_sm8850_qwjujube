__int64 __fastcall reg_domain_disable(__int64 a1)
{
  __int64 drvdata; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 result; // x0

  drvdata = rdev_get_drvdata();
  v3 = *(_QWORD *)(a1 + 328);
  v4 = drvdata;
  result = dev_pm_genpd_set_performance_state(v3, 0);
  if ( !(_DWORD)result )
    --*(_DWORD *)(v4 + 336);
  return result;
}
