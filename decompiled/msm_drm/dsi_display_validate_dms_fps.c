void __fastcall dsi_display_validate_dms_fps(_DWORD *a1, _DWORD *a2)
{
  if ( *a1 == *a2 && a1[6] == a2[6] && a1[11] != a2[11] )
  {
    a2[39] |= 0x40u;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DMS Modeset with FPS change\n");
  }
  else
  {
    a2[39] &= ~0x40u;
  }
}
