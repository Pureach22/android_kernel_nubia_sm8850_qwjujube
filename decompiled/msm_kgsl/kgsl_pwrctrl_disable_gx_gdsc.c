__int64 __fastcall kgsl_pwrctrl_disable_gx_gdsc(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x21
  int v6; // w2

  result = a1[1126];
  if ( result )
  {
    result = kgsl_regulator_disable_wait(result, 0xC8u);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_13;
  }
  v3 = a1[1129];
  if ( v3 )
  {
    v4 = ktime_get(0);
    LODWORD(result) = _pm_runtime_idle(v3, 4);
    if ( (result & 0x80000000) != 0 )
    {
LABEL_13:
      v6 = result;
      return dev_err(*a1, "vdd is stuck on, error %d\n", v6);
    }
    result = kgsl_genpd_is_enabled(v3);
    if ( (result & 1) != 0 )
    {
      v5 = v4 + 200000000;
      while ( ktime_get(result) <= v5 )
      {
        usleep_range_state(26, 100, 2);
        result = kgsl_genpd_is_enabled(v3);
        if ( (result & 1) == 0 )
          return result;
      }
      result = kgsl_genpd_is_enabled(v3);
      if ( (result & 1) != 0 )
      {
        v6 = -110;
        return dev_err(*a1, "vdd is stuck on, error %d\n", v6);
      }
    }
  }
  return result;
}
