__int64 __fastcall ucfg_pmo_tgt_psoc_get_runtime_pm_in_progress(__int64 a1)
{
  return pmo_tgt_psoc_get_runtime_pm_inprogress(a1) & 1;
}
