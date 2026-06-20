__int64 __fastcall wlan_cm_update_hlp_info(__int64 a1, const void *a2, unsigned __int16 a3, unsigned int a4, char a5)
{
  unsigned __int8 v8; // w20
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v8 = a4;
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a4, 2);
  if ( !v9 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL for vdev_id %d",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "wlan_cm_update_hlp_info",
             v8);
  v18 = v9;
  cm_update_hlp_info(v9, a2, a3, a5 & 1, v10, v11, v12, v13, v14, v15, v16, v17);
  return wlan_objmgr_vdev_release_ref(v18, 2u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
}
