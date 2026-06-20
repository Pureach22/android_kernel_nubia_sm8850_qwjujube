__int64 __fastcall pe_find_partner_session_by_link_id(
        __int64 a1,
        unsigned int a2,
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
  __int64 v21; // x20
  __int64 vdev_by_link_id; // x0
  __int64 v23; // x19
  __int64 result; // x0
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2

  context = _cds_get_context(53, (__int64)"pe_find_partner_session_by_link_id", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v34 = "%s: mac ctx is null";
LABEL_9:
    qdf_trace_msg(0x35u, 2u, v34, v13, v14, v15, v16, v17, v18, v19, v20, "pe_find_partner_session_by_link_id");
    return 0;
  }
  if ( !a1 )
  {
    v34 = "%s: session is null";
    goto LABEL_9;
  }
  v21 = (__int64)context;
  vdev_by_link_id = mlo_get_vdev_by_link_id(*(_QWORD *)(a1 + 16), a2, 90);
  if ( !vdev_by_link_id )
  {
    v34 = "%s: vdev is null";
    goto LABEL_9;
  }
  v23 = vdev_by_link_id;
  result = pe_find_session_by_vdev_id(v21, *(_BYTE *)(vdev_by_link_id + 168), v13, v14, v15, v16, v17, v18, v19, v20);
  if ( result )
    return result;
  wlan_objmgr_vdev_release_ref(v23, 0x5Au, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  return 0;
}
