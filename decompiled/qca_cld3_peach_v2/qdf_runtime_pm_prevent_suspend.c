__int64 __fastcall qdf_runtime_pm_prevent_suspend(__int64 *a1)
{
  return hif_pm_runtime_prevent_suspend(*a1);
}
