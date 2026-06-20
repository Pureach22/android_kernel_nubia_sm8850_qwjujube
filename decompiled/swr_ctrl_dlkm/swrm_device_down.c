__int64 __fastcall swrm_device_down(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 15360);
  *(_DWORD *)(v1 + 15336) = 4;
  result = mutex_unlock(v1 + 15360);
  if ( (*(_WORD *)(a1 + 488) & 7) != 0 || *(_DWORD *)(a1 + 500) != 2 )
  {
    result = swrm_runtime_suspend(a1);
    if ( !(_DWORD)result )
    {
      _pm_runtime_disable(a1, 1);
      _pm_runtime_set_status(a1, 2);
      return pm_runtime_enable(a1);
    }
  }
  return result;
}
