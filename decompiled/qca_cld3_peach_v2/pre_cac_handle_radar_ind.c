__int64 __fastcall pre_cac_handle_radar_ind(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x21
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  __int64 v14; // x20
  _DWORD *v15; // x8
  char v16; // w8
  __int64 v17; // x1
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v1 = *(_QWORD *)(a1 + 216);
  if ( v1 )
    v3 = *(_QWORD *)(v1 + 80);
  else
    v3 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v3, 0x2Du);
  if ( comp_private_obj )
  {
    v13 = *(unsigned __int8 *)(a1 + 168);
    v14 = comp_private_obj;
    if ( glbl_pre_cac_ops )
    {
      v15 = *(_DWORD **)glbl_pre_cac_ops;
      if ( *(_QWORD *)glbl_pre_cac_ops )
      {
        if ( *(v15 - 1) != -1125204353 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD))v15)(v3, (unsigned int)v13, 0);
        v13 = *(unsigned __int8 *)(a1 + 168);
      }
    }
    qdf_trace_msg(
      0x98u,
      8u,
      "%s: schedue pre_cac_work vdev %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "pre_cac_handle_radar_ind",
      v13);
    v16 = *(_BYTE *)(a1 + 168);
    *(_QWORD *)(v14 + 32) = pre_cac_handle_failure;
    *(_QWORD *)(v14 + 40) = v3;
    *(_BYTE *)(v14 + 48) = v16;
    *(_QWORD *)v14 = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v14 + 8) = v14 + 8;
    *(_QWORD *)(v14 + 16) = v14 + 8;
    v17 = system_wq;
    *(_QWORD *)(v14 + 24) = _qdf_defer_func;
    return queue_work_on(32, v17, v14);
  }
  else
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s:%u: psoc_priv is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "pre_cac_handle_radar_ind",
      227);
    return qdf_trace_msg(
             0x98u,
             2u,
             "%s: invalid psoc",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "pre_cac_handle_radar_ind");
  }
}
