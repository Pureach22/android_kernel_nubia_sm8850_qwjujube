__int64 __fastcall dsi_display_handle_poms_te(__int64 a1)
{
  __int64 v1; // x20
  int v2; // w19
  __int64 result; // x0

  if ( a1 == 1480 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  v1 = *(_QWORD *)(a1 - 1216);
  if ( !v1 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  mutex_lock(v1 + 1040);
  if ( *(_BYTE *)(v1 + 1973) == 1 )
  {
    v2 = mipi_dsi_dcs_set_tear_off(v1 + 24);
    result = mutex_unlock(v1 + 1040);
    if ( (v2 & 0x80000000) == 0 )
      return result;
  }
  else
  {
    mutex_unlock(v1 + 1040);
  }
  return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set tear off\n");
}
