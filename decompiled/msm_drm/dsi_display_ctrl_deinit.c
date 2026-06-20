__int64 __fastcall dsi_display_ctrl_deinit(__int64 result)
{
  __int64 v1; // x19

  if ( *(_DWORD *)(result + 160) )
  {
    v1 = result;
    result = dsi_ctrl_host_deinit(*(_QWORD *)(result + 168));
    if ( (_DWORD)result )
      result = drm_dev_printk(
                 0,
                 &unk_248D72,
                 "*ERROR* [msm-dsi-error]: [%s] failed to deinit host_%d, rc=%d\n",
                 *(const char **)(v1 + 32),
                 0,
                 result);
    if ( *(_DWORD *)(v1 + 160) >= 2u )
    {
      result = dsi_ctrl_host_deinit(*(_QWORD *)(v1 + 216));
      if ( (_DWORD)result )
        return drm_dev_printk(
                 0,
                 &unk_248D72,
                 "*ERROR* [msm-dsi-error]: [%s] failed to deinit host_%d, rc=%d\n",
                 *(const char **)(v1 + 32),
                 1,
                 result);
    }
  }
  return result;
}
