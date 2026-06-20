__int64 __fastcall sde_backlight_cooling_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21

  v3 = *(_QWORD *)(a3 + 320);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "bl: thermal max brightness cap:%lu\n", a2);
  *(_QWORD *)(v3 + 4400) = a2;
  sde_backlight_device_update_status(a3);
  return 0;
}
