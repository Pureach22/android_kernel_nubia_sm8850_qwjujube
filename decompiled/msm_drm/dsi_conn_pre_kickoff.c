__int64 __fastcall dsi_conn_pre_kickoff(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 && a2 && a3 )
    return dsi_display_pre_kickoff();
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  return 4294967274LL;
}
