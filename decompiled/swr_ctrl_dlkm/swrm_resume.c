__int64 __fastcall swrm_resume(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  unsigned int v4; // w19

  v1 = *(_QWORD *)(a1 + 152);
  if ( (*(_WORD *)(a1 + 488) & 7) != 0 || (v4 = 0, !(unsigned int)_pm_runtime_suspend(a1, 0)) )
  {
    v3 = swrm_runtime_resume(a1);
    v4 = v3;
    if ( !(_DWORD)v3 )
    {
      *(_QWORD *)(a1 + 520) = ktime_get_mono_fast_ns(v3);
      _pm_runtime_suspend(a1, 9);
    }
  }
  mutex_lock(v1 + 8880);
  if ( *(_DWORD *)(v1 + 15800) == 2 )
    *(_DWORD *)(v1 + 15800) = 0;
  mutex_unlock(v1 + 8880);
  _wake_up(v1 + 15808, 3, 0, 0);
  return v4;
}
