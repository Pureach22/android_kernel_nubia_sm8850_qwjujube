__int64 __fastcall dsi_display_drm_bridge_deinit(__int64 a1)
{
  if ( a1 )
  {
    mutex_lock(a1 + 72);
    dsi_drm_bridge_cleanup(*(_QWORD *)(a1 + 1296));
    *(_QWORD *)(a1 + 1296) = 0;
    mutex_unlock(a1 + 72);
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
}
