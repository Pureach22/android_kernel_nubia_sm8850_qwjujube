__int64 __fastcall hdd_cm_disconnect_complete_pre_user_update(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  char *link_info_by_vdev; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x22
  char *v31; // x21
  int v32; // w23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8

  context = _cds_get_context(51, (__int64)"hdd_cm_disconnect_complete_pre_user_update", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_ctx is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_cm_disconnect_complete_pre_user_update");
    return 4;
  }
  link_info_by_vdev = (char *)hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: adapter is NULL for vdev %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hdd_cm_disconnect_complete_pre_user_update",
      *(unsigned __int8 *)(a1 + 104));
    return 4;
  }
  v30 = *(_QWORD *)link_info_by_vdev;
  v31 = link_info_by_vdev;
  hdd_conn_set_authenticated((__int64)link_info_by_vdev, 0, v22, v23, v24, v25, v26, v27, v28, v29);
  hdd_disable_and_flush_mc_addr_list(v30, 8);
  _hdd_cm_disconnect_handler_pre_user_update(v31);
  v32 = a2[2];
  hdd_handle_disassociation_event((int *)v31, (__int64)(a2 + 4), v33, v34, v35, v36, v37, v38, v39, v40);
  wlan_rec_debug_log((char *)&off_0 + 1, v31[8], 0x17u, 0, a2 + 4, 0, *a2, a2[2] | (a2[3] << 16));
  *(_DWORD *)(v30 + 52400) = osif_cm_mac_to_qca_reason(a2[3]);
  hdd_set_disconnect_link_info_cb((unsigned __int8)v31[8], 0);
  v41 = *(_QWORD *)(v30 + 57440);
  if ( v41 )
  {
    if ( *(unsigned __int8 *)(v41 + 8) == (unsigned __int8)v31[8] )
      wlan_connectivity_disconnect_event(
        a1,
        a2 + 4,
        (unsigned int)a2[3],
        *((unsigned int *)v31 + 605),
        (v32 & 0xFFFFFFFE) != 6);
  }
  return 0;
}
