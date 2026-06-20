__int64 __fastcall mlme_vdev_sm_create(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w3
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x2
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _QWORD v40[9]; // [xsp+8h] [xbp-48h] BYREF

  v40[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 520);
  v3 = *(unsigned __int8 *)(v2 + 168);
  memset(v40, 0, 64);
  v4 = scnprintf(v40, 64, "VM-%d", v3);
  v12 = wlan_sm_create(
          (__int64)v40,
          a1,
          0,
          (__int64)&sm_info,
          0x15u,
          (__int64)vdev_sm_event_names,
          33,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11);
  if ( v12 )
  {
    *(_QWORD *)(a1 + 504) = v12;
    v21 = *(_QWORD *)(v2 + 216);
    if ( v21 )
      v22 = *(_QWORD *)(v21 + 80);
    else
      v22 = 0;
    wlan_minidump_log(v13, v14, v15, v16, v17, v18, v19, v20, v12, 112, v22);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: VDEV SM lock is disabled!!!",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "mlme_vdev_sm_spinlock_create");
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: VDEV CMD lock is disabled!!!",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "mlme_vdev_cmd_mutex_create");
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV MLME SM allocation failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlme_vdev_sm_create");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
