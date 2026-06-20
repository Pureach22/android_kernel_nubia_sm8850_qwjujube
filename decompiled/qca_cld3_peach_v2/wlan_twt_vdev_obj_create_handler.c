__int64 __fastcall wlan_twt_vdev_obj_create_handler(__int64 a1)
{
  _BYTE *v2; // x0
  __int64 v3; // x20
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  __int64 result; // x0

  v2 = (_BYTE *)_qdf_mem_malloc(0x14u, "wlan_twt_vdev_obj_create_handler", 89);
  if ( !v2 )
    return 2;
  v3 = (__int64)v2;
  *v2 = 0;
  v4 = wlan_objmgr_vdev_component_obj_attach(a1, 0x2Cu, (__int64)v2, 0);
  if ( v4 )
  {
    v13 = v4;
    _qdf_mem_free(v3);
    v22 = "%s: Failed to attach twt vdev priv object";
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: twt vdev priv obj attach successful",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_twt_vdev_obj_create_handler");
    result = mlme_twt_vdev_create_notification();
    if ( !(_DWORD)result )
      return result;
    v13 = result;
    v22 = "%s: vdev create notification failed";
  }
  qdf_trace_msg(0x96u, 2u, v22, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_twt_vdev_obj_create_handler");
  return v13;
}
