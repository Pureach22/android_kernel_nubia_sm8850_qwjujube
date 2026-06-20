__int64 __fastcall ll_sap_vdev_obj_created_notification(__int64 a1)
{
  __int64 v1; // x29
  __int64 v2; // x30
  __int64 v4; // x0
  __int64 v5; // x19
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  __int64 result; // x0
  __int64 v17; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)(a1 + 16) != 1 )
    return 0;
  v17 = v2;
  v4 = _qdf_mem_malloc(0x28u, "ll_sap_vdev_obj_created_notification", 131);
  if ( !v4 )
    return 2;
  v5 = v4;
  v6 = wlan_objmgr_vdev_component_obj_attach(a1, 0x34u, v4, 0);
  if ( v6 )
  {
    v15 = v6;
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d obj attach failed",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ll_sap_vdev_obj_created_notification",
      *(unsigned __int8 *)(a1 + 168),
      v1,
      v17);
  }
  else
  {
    result = ll_lt_sap_init(a1, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( !(_DWORD)result )
      return result;
    v15 = result;
    wlan_objmgr_vdev_component_obj_detach(a1, 0x34u, v5);
  }
  _qdf_mem_free(v5);
  return v15;
}
