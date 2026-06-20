__int64 __fastcall ucfg_nan_is_vdev_creation_allowed(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w9
  __int16 v29; // w8
  const char *v31; // x4
  const char *v32; // x5

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_8:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc_nan_obj is null",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ucfg_nan_is_vdev_creation_allowed");
    return 0;
  }
  v19 = comp_private_obj;
  if ( (nan_is_allowed(a1, v11, v12, v13, v14, v15, v16, v17, v18) & 1) != 0 )
  {
    v28 = *(_DWORD *)(v19 + 208);
    v29 = *(_WORD *)(v19 + 232);
    if ( (v28 & 8) != 0 && (v29 & 0x20) != 0 )
      return 1;
    if ( (v28 & 8) != 0 )
      v31 = (const char *)&unk_98C763;
    else
      v31 = " not";
    if ( (v29 & 0x20) != 0 )
      v32 = (const char *)&unk_98C763;
    else
      v32 = " not";
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: NAN separate vdev%s supported by host,%s supported by firmware",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "ucfg_nan_is_vdev_creation_allowed",
      v31,
      v32);
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: NAN is not enabled",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "ucfg_nan_is_vdev_creation_allowed");
  }
  return 0;
}
