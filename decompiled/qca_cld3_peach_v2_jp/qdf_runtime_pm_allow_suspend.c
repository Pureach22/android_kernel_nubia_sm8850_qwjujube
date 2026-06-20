__int64 __fastcall qdf_runtime_pm_allow_suspend(__int64 *a1)
{
  return hif_pm_runtime_allow_suspend(*a1);
}
