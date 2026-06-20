__int64 __fastcall dsi_panel_bl_unregister(__int64 a1)
{
  unsigned int v2; // w3

  if ( (*(_BYTE *)(a1 + 1274) & 1) != 0 )
    return 0;
  v2 = *(_DWORD *)(a1 + 1472);
  if ( v2 < 5 )
    return 0;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Backlight type(%d) not supported\n", v2);
  return 4294966772LL;
}
