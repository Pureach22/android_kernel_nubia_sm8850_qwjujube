__int64 __fastcall hdd_ndp_event_handler(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 vdev_by_user; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  __int64 v18; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _BOOL4 v28; // w21
  const char *v29; // x5
  const char *v30; // x2
  __int64 v31; // x4
  _BOOL4 v32; // w21
  const char *v33; // x5

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x52u, (__int64)"hdd_ndp_event_handler");
  if ( !vdev_by_user )
    return qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v9, v10, v11, v12, v13, v14, v15, v16, "hdd_ndp_event_handler");
  v17 = *(_QWORD *)(vdev_by_user + 152);
  if ( v17 )
    v18 = *(_QWORD *)(v17 + 80);
  else
    v18 = 0;
  _hdd_objmgr_put_vdev_by_user(
    vdev_by_user,
    0x52u,
    (__int64)"hdd_ndp_event_handler",
    (unsigned int *)v17,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16);
  if ( a3 != 43 )
  {
    v30 = "%s: in correct roam_status: %d";
    v31 = a3;
    return qdf_trace_msg(0x33u, 2u, v30, v20, v21, v22, v23, v24, v25, v26, v27, "hdd_ndp_event_handler", v31);
  }
  if ( a4 != 21 )
  {
    if ( a4 == 20 )
    {
      v28 = *(_DWORD *)(a2 + 184) == 0;
      if ( *(_DWORD *)(a2 + 184) )
        v29 = "Failure";
      else
        v29 = "Success";
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: posting ndi create status: %d (%s) to umac",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_ndp_event_handler",
        *(_DWORD *)(a2 + 184) == 0,
        v29);
      return os_if_nan_post_ndi_create_rsp(v18, *(unsigned __int8 *)(a1 + 8), v28);
    }
    v30 = "%s: in correct roam_result: %d";
    v31 = a4;
    return qdf_trace_msg(0x33u, 2u, v30, v20, v21, v22, v23, v24, v25, v26, v27, "hdd_ndp_event_handler", v31);
  }
  v32 = *(_DWORD *)(a2 + 184) == 0;
  if ( *(_DWORD *)(a2 + 184) )
    v33 = "Failure";
  else
    v33 = "Success";
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: posting ndi delete status: %d (%s) to umac",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "hdd_ndp_event_handler",
    *(_DWORD *)(a2 + 184) == 0,
    v33);
  return os_if_nan_post_ndi_delete_rsp(v18, *(unsigned __int8 *)(a1 + 8), v32);
}
