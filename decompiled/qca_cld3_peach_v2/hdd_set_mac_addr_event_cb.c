__int64 __fastcall hdd_set_mac_addr_event_cb(
        unsigned __int8 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *context; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 link_info_by_vdev; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  __int64 v39; // x21
  _DWORD *v40; // x0
  const char *v42; // x2
  __int64 v43; // x4
  unsigned int v44; // w0
  unsigned int v51; // w8
  unsigned int v52; // w8

  qdf_trace_msg(0x48u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_mac_addr_event_cb");
  context = _cds_get_context(51, (__int64)"hdd_set_mac_addr_event_cb", v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !context )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid HDD context",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "hdd_set_mac_addr_event_cb");
  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, a1);
  if ( !link_info_by_vdev )
  {
    v42 = "%s: No adapter found for VDEV ID:%d";
    v43 = a1;
    v44 = 51;
    return qdf_trace_msg(v44, 2u, v42, v30, v31, v32, v33, v34, v35, v36, v37, "hdd_set_mac_addr_event_cb", v43);
  }
  v38 = osif_request_get(*(_QWORD *)(*(_QWORD *)link_info_by_vdev + 52808LL));
  if ( !v38 )
  {
    v42 = "%s: Obsolete request for VDEV ID:%d";
    v43 = a1;
    v44 = 72;
    return qdf_trace_msg(v44, 2u, v42, v30, v31, v32, v33, v34, v35, v36, v37, "hdd_set_mac_addr_event_cb", v43);
  }
  v39 = v38;
  v40 = (_DWORD *)osif_request_priv(v38);
  _X9 = v40 + 1;
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v51 = __ldxr(_X9);
    v52 = v51 - 1;
  }
  while ( __stlxr(v52, _X9) );
  __dmb(0xBu);
  if ( !v52 )
  {
    *v40 = a2;
    osif_request_complete(v39);
  }
  return osif_request_put(v39);
}
