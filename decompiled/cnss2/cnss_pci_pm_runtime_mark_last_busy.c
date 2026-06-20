__int64 *__fastcall cnss_pci_pm_runtime_mark_last_busy(__int64 *result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = *result;
    result = (__int64 *)ktime_get_mono_fast_ns();
    *(_QWORD *)(v1 + 720) = result;
  }
  return result;
}
