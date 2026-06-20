__int64 __fastcall ucfg_dlm_psoc_open(__int64 a1)
{
  pmo_register_suspend_handler(32, ucfg_dlm_suspend_handler, 0);
  pmo_register_resume_handler(32, ucfg_dlm_resume_handler, 0);
  return dlm_cfg_psoc_open(a1);
}
