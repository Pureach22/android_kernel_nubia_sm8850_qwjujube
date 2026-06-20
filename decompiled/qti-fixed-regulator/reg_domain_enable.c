__int64 __fastcall reg_domain_enable(__int64 a1)
{
  __int64 drvdata; // x19
  __int64 result; // x0

  drvdata = rdev_get_drvdata();
  result = dev_pm_genpd_set_performance_state(*(_QWORD *)(a1 + 328), *(unsigned int *)(drvdata + 340));
  if ( !(_DWORD)result )
    ++*(_DWORD *)(drvdata + 336);
  return result;
}
