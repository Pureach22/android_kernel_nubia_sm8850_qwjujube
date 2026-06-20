__int64 __fastcall dsi_display_ctl_pre_transition(__int64 *a1)
{
  sde_connector_schedule_status_work(a1[2], 0);
  *(_DWORD *)(a1[21] + 1608) = 1;
  *(_DWORD *)(a1[24] + 776) = 1;
  dsi_clk_mgr_detach_framework(a1[164], *(unsigned int *)(a1[21] + 1608));
  return 0;
}
