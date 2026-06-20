__int64 __fastcall sde_crtc_destroy(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  unsigned int v5; // w8
  void *v6; // x0
  const char *v7; // x1
  void (__fastcall *v8)(_QWORD); // x8

  v1 = (_QWORD *)result;
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "\n");
  if ( v1 )
  {
    if ( v1[562] )
      kernfs_put();
    if ( v1[563] )
      kernfs_put();
    if ( v1[561] )
      device_unregister();
    if ( v1[403] )
      drm_property_blob_put();
    msm_property_destroy(v1 + 325);
    sde_cp_crtc_destroy_properties(v1);
    sde_fence_deinit(v1[404]);
    if ( *v1 )
    {
      v2 = *(_QWORD *)(*v1 + 56LL);
      if ( v2 )
      {
        v3 = *(_QWORD *)(v2 + 8);
        if ( !v3 )
        {
          v6 = &unk_234896;
          v7 = "_sde_crtc_get_kms";
          goto LABEL_21;
        }
        v4 = *(_QWORD *)(v3 + 152);
        if ( !v4 || (*(_QWORD *)(v4 + 22008) & 0x8000000000000LL) == 0 )
          goto LABEL_22;
        v5 = *(_DWORD *)(v2 + 5912);
        if ( v5 < 3 )
        {
LABEL_23:
          v8 = (void (__fastcall *)(_QWORD))v1[v5 + 1008];
          if ( v8 )
          {
            if ( *((_DWORD *)v8 - 1) != -1451078546 )
              __break(0x8228u);
            v8(v1);
          }
          drm_crtc_cleanup(v1);
          return kfree(v1);
        }
        __break(0x5512u);
      }
    }
    v6 = &unk_25E167;
    v7 = "sde_crtc_get_disp_op";
LABEL_21:
    printk(v6, v7);
LABEL_22:
    v5 = 0;
    goto LABEL_23;
  }
  return result;
}
