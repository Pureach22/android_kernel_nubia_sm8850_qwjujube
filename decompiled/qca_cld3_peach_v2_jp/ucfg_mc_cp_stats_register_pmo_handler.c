double ucfg_mc_cp_stats_register_pmo_handler()
{
  pmo_register_suspend_handler(27, ucfg_mc_cp_stats_suspend_handler, 0);
  return pmo_register_resume_handler(27, ucfg_mc_cp_stats_resume_handler, 0);
}
