bool __fastcall dsi_display_validate_mode_seamless(__int64 a1, int *a2)
{
  int dfps_timing; // w19

  dfps_timing = dsi_display_get_dfps_timing(a1, a2, 0);
  if ( dfps_timing )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Dynamic FPS not supported for seamless\n");
  }
  else
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Mode switch is seamless Dynamic FPS\n");
    a2[39] |= 6u;
  }
  return dfps_timing != 0;
}
