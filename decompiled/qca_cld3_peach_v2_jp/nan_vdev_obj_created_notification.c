__int64 __fastcall nan_vdev_obj_created_notification(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x0
  int v20; // w8
  __int64 v21; // x0
  __int64 v22; // x20
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19

  qdf_trace_msg(
    0x53u,
    8u,
    "%s: nan_vdev_create_notif called",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "nan_vdev_obj_created_notification");
  if ( (ucfg_is_nan_vdev(a1) & 1) != 0 )
  {
    v18 = *(_QWORD *)(a1 + 152);
    if ( !v18 || (v19 = *(_QWORD *)(v18 + 80)) == 0 )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: psoc is NULL",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "nan_vdev_obj_created_notification");
      return 4;
    }
    target_if_nan_set_vdev_feature_config(v19, *(unsigned __int8 *)(a1 + 104));
  }
  v20 = *(_DWORD *)(a1 + 16);
  if ( v20 == 11 || v20 == 16 )
  {
    v21 = _qdf_mem_malloc(0x90u, "nan_vdev_obj_created_notification", 128);
    if ( v21 )
    {
      v22 = v21;
      *(_DWORD *)v21 = 0;
      *(_QWORD *)(v21 + 8) = 0;
      result = wlan_objmgr_vdev_component_obj_attach(a1, 0xFu, v21, 0);
      if ( (_DWORD)result )
      {
        v32 = result;
        qdf_trace_msg(
          0x53u,
          1u,
          "%s: obj attach with vdev failed",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "nan_vdev_obj_created_notification");
        _qdf_mem_free(v22);
        return v32;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: not a ndi vdev. do nothing",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "nan_vdev_obj_created_notification");
    return 0;
  }
  return result;
}
