__int64 __fastcall dsi_display_ctl_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v4; // w19

  if ( (unsigned int)dsi_display_hfi_setup_hfi(a1, *(_QWORD *)(a2 + 8)) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: hfi client could not be created for dsi\n");
    return 4294967277LL;
  }
  else
  {
    result = dsi_hfi_panel_init(a1, *(_QWORD *)(a1 + 264));
    if ( (_DWORD)result )
    {
      v4 = result;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to send panel init to DCP: %d", result);
      return v4;
    }
  }
  return result;
}
