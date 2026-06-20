__int64 __fastcall wlan_ll_sap_oob_connect_response(__int64 a1, unsigned __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 comp_private_obj; // x0
  __int64 v14; // x20
  __int64 osif_cbk; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x8
  unsigned __int64 v25; // x21
  unsigned int v26; // w22
  __int64 v27; // x24
  _DWORD *v28; // x8
  const char *v30; // x2
  __int64 v31; // x4

  v3 = ((__int64 (__fastcall *)(__int64, unsigned __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 105);
  if ( !v3 )
  {
    v30 = "%s: Invalid vdev %d for oob connect response";
    v31 = (unsigned __int8)a2;
LABEL_19:
    qdf_trace_msg(0xA1u, 2u, v30, v4, v5, v6, v7, v8, v9, v10, v11, "wlan_ll_sap_oob_connect_response", v31);
    return 4;
  }
  v12 = v3;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v3, 0x34u);
  if ( !comp_private_obj )
  {
    v31 = *(unsigned __int8 *)(v12 + 168);
    v30 = "%s: vdev %d ll_sap obj null";
    goto LABEL_19;
  }
  v14 = comp_private_obj;
  osif_cbk = ll_sap_get_osif_cbk();
  if ( !osif_cbk || (v24 = *(_DWORD **)(osif_cbk + 8)) == nullptr )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: invalid high ap availability ops",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_ll_sap_oob_connect_response");
    return 4;
  }
  v25 = HIDWORD(a2);
  v26 = v25 - 3;
  if ( *(unsigned __int16 *)(v14 + 8) != 0xFFFF )
  {
    v27 = osif_cbk;
    if ( *(v24 - 1) != 2120861206 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v24)(v12, (unsigned int)v25);
    osif_cbk = v27;
    if ( v26 <= 1 )
    {
      *(_WORD *)(v14 + 8) = -1;
      ll_lt_sap_high_ap_availability_ser_cmd_remove(v12, 32);
      osif_cbk = v27;
    }
  }
  if ( *(unsigned __int16 *)(v14 + 10) != 0xFFFF )
  {
    v28 = *(_DWORD **)(osif_cbk + 8);
    if ( *(v28 - 1) != 2120861206 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v28)(v12, (unsigned int)v25);
    if ( v26 <= 1 )
    {
      *(_WORD *)(v14 + 10) = -1;
      v16 = ll_lt_sap_high_ap_availability_ser_cmd_remove(v12, 32);
    }
  }
  wlan_objmgr_vdev_release_ref(v12, 0x69u, v24, v16, v17, v18, v19, v20, v21, v22, v23);
  return 0;
}
