__int64 __fastcall hdd_cm_connect_active_notify(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x20
  __int64 link_info_by_vdev; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _QWORD *v29; // x21
  __int64 vdev_by_user; // x0
  __int64 v31; // x22
  const char *v33; // x2

  context = _cds_get_context(51, (__int64)"hdd_cm_connect_active_notify", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: HDD context is NULL",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "hdd_cm_connect_active_notify");
  v19 = context;
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
  {
    v33 = "%s: Link info not found for vdev %d";
    return qdf_trace_msg(0x33u, 2u, v33, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_cm_connect_active_notify", a1);
  }
  v29 = (_QWORD *)link_info_by_vdev;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(link_info_by_vdev, 5, "hdd_cm_connect_active_notify");
  if ( !vdev_by_user )
  {
    v33 = "%s: Invalid VDEV id %d";
    return qdf_trace_msg(0x33u, 2u, v33, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_cm_connect_active_notify", a1);
  }
  v31 = vdev_by_user;
  if ( (hdd_adapter_restore_link_vdev_map(*v29, 1) & 1) != 0 )
    hdd_adapter_update_mlo_mgr_mac_addr(*v29);
  ucfg_dp_update_def_link(*v19, (unsigned __int8 *)(*v29 + 1617LL), v31);
  return _hdd_objmgr_put_vdev_by_user(v31, 5, "hdd_cm_connect_active_notify");
}
