__int64 __fastcall lim_partner_link_info_change(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int8 v19; // w1
  __int64 v20; // x19
  __int64 session_by_vdev_id; // x0
  __int64 v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2

  context = _cds_get_context(53, (__int64)"lim_partner_link_info_change", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v31 = "%s: mac ctx is null";
LABEL_10:
    qdf_trace_msg(0x35u, 2u, v31, v11, v12, v13, v14, v15, v16, v17, v18, "lim_partner_link_info_change");
    return 4;
  }
  if ( !a1 )
  {
    v31 = "%s: vdev is null";
    goto LABEL_10;
  }
  v19 = *(_BYTE *)(a1 + 168);
  v20 = (__int64)context;
  session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, v19, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !session_by_vdev_id )
  {
    v31 = "%s: session is NULL";
    goto LABEL_10;
  }
  v22 = session_by_vdev_id;
  if ( *(_BYTE *)(session_by_vdev_id + 10178) == 1 )
  {
    if ( (unsigned int)sch_set_fixed_beacon_fields(v20, session_by_vdev_id) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Unable to update mlo IE in beacon",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "lim_send_mlo_ie_update");
    else
      lim_send_beacon_ind(v20, v22, 6u, v23, v24, v25, v26, v27, v28, v29, v30);
  }
  return 0;
}
