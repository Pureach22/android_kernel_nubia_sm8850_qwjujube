__int64 __fastcall hdd_ndp_session_end_handler(__int64 a1)
{
  __int64 vdev_by_user; // x0
  __int64 v2; // x1
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  unsigned int *v13; // x8
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x52u, (__int64)"hdd_ndp_session_end_handler");
  if ( !vdev_by_user )
    return qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "hdd_ndp_session_end_handler");
  v11 = vdev_by_user;
  v12 = os_if_nan_ndi_session_end(vdev_by_user, v2);
  return _hdd_objmgr_put_vdev_by_user(
           v11,
           0x52u,
           (__int64)"hdd_ndp_session_end_handler",
           v13,
           v12,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20);
}
