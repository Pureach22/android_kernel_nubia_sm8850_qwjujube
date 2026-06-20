__int64 __fastcall swrm_device_suspend(__int64 result)
{
  __int64 v1; // x19

  v1 = result;
  if ( (*(_WORD *)(result + 488) & 7) != 0 || *(_DWORD *)(result + 500) != 2 )
  {
    result = swrm_runtime_suspend(result);
    if ( !(_DWORD)result )
    {
      _pm_runtime_disable(v1, 1);
      _pm_runtime_set_status(v1, 2);
      return pm_runtime_enable(v1);
    }
  }
  return result;
}
