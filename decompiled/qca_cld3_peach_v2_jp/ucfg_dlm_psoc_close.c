__int64 ucfg_dlm_psoc_close()
{
  pmo_unregister_suspend_handler(32, ucfg_dlm_suspend_handler);
  pmo_unregister_resume_handler(32, ucfg_dlm_resume_handler);
  return 0;
}
