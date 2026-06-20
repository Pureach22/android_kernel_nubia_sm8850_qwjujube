__int64 __fastcall sde_connector_destroy(_QWORD *a1)
{
  _DWORD *v2; // x8
  __int64 v3; // x1
  __int64 v4; // x8
  __int64 v5; // x0
  void (__fastcall *v6)(_QWORD); // x8

  if ( !a1 )
    return printk(&unk_242658, "sde_connector_destroy");
  if ( a1[413] )
    device_unregister();
  sde_connector_schedule_status_work((__int64)a1, 0);
  v2 = (_DWORD *)a1[389];
  if ( v2 )
  {
    v3 = a1[345];
    if ( *(v2 - 1) != 1212788166 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v2)(a1, v3);
  }
  if ( a1[528] )
    drm_property_blob_put();
  if ( a1[529] )
    drm_property_blob_put();
  if ( a1[531] )
    drm_property_blob_put();
  if ( a1[532] )
    drm_property_blob_put();
  if ( a1[530] )
    drm_property_blob_put();
  if ( a1[546] )
    backlight_cdev_unregister();
  if ( a1[545] )
    backlight_device_unregister();
  drm_connector_unregister(a1);
  sde_fence_deinit(a1[358]);
  drm_connector_cleanup(a1);
  msm_property_destroy(a1 + 414);
  v4 = a1[314];
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 8);
    if ( !v5 )
      goto LABEL_27;
    LODWORD(v5) = sde_crtc_get_disp_op(v5);
    if ( (unsigned int)v5 < 3 )
      goto LABEL_27;
    __break(0x5512u);
  }
  LODWORD(v5) = 0;
LABEL_27:
  v6 = (void (__fastcall *)(_QWORD))a1[(unsigned int)v5 + 646];
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != 1295139750 )
      __break(0x8228u);
    v6(a1);
  }
  return kfree(a1);
}
