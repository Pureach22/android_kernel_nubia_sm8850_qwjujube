__int64 __fastcall update_ndi_state(__int64 a1)
{
  __int64 vdev_by_user; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned int *v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x52u, (__int64)"update_ndi_state");
  if ( !vdev_by_user )
    return qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "update_ndi_state");
  v10 = vdev_by_user;
  _ucfg_nan_set_ndi_state(vdev_by_user, 0, (__int64)"os_if_nan_set_ndi_state", v2, v3, v4, v5, v6, v7, v8, v9);
  return _hdd_objmgr_put_vdev_by_user(
           v10,
           0x52u,
           (__int64)"update_ndi_state",
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19);
}
