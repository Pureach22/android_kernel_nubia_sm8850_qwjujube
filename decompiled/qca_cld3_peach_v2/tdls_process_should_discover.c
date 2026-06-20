__int64 __fastcall tdls_process_should_discover(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x21
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w23
  const char *v33; // x4
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x4
  const char *v43; // x6
  __int64 peer; // x0
  const char *v46; // x2
  unsigned int v47; // w1
  int v48; // w8
  const char *v49; // x4
  __int64 v50; // x7
  __int64 v51; // x19

  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 216);
    if ( v11 && (v13 = *(_QWORD *)(v11 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
      comp_private_obj = 0;
    }
    v15 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: NULL vdev", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
    qdf_trace_msg(0, 2u, "%s: NULL vdev", v24, v25, v26, v27, v28, v29, v30, v31, "wlan_vdev_get_tdls_vdev_obj");
    comp_private_obj = 0;
    v15 = 0;
  }
  v32 = *(unsigned __int16 *)(a2 + 8);
  if ( v32 > 3 )
    v33 = "INVALID_TYPE";
  else
    v33 = off_B2DD70[*(unsigned __int16 *)(a2 + 8)];
  qdf_trace_msg(
    0,
    8u,
    "%s: TDLS %s: %02x:%02x:%02x:**:**:%02xreason %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "tdls_process_should_discover",
    v33,
    *(unsigned __int8 *)(a2 + 1),
    *(unsigned __int8 *)(a2 + 2),
    *(unsigned __int8 *)(a2 + 3),
    *(unsigned __int8 *)(a2 + 6),
    *(_DWORD *)(a2 + 12));
  if ( comp_private_obj && v15 )
  {
    if ( *(_BYTE *)(comp_private_obj + 214) == 1 )
    {
      if ( v32 > 3 )
        v42 = "INVALID_TYPE";
      else
        v42 = off_B2DD70[v32];
      v46 = "%s: TDLS antenna switching, ignore %s";
      v47 = 2;
    }
    else
    {
      peer = tdls_get_peer(v15, a2 + 1);
      if ( !peer )
      {
        qdf_trace_msg(
          0,
          4u,
          "%s: curr_peer is null",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "tdls_process_should_discover");
        return 29;
      }
      if ( *(_DWORD *)(peer + 36) == 4 )
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: TDLS link status is connected, ignore",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "tdls_process_should_discover");
        return 0;
      }
      v48 = *(_DWORD *)(comp_private_obj + 156);
      if ( (v48 & 0x80) == 0 || (*(_BYTE *)(peer + 489) & 1) != 0 )
      {
        if ( v32 > 3 )
          v49 = "INVALID_TYPE";
        else
          v49 = off_B2DD70[v32];
        v50 = *(unsigned int *)(a2 + 12);
        v51 = peer;
        qdf_trace_msg(
          0,
          8u,
          "%s: initiate TDLS setup on %s, ext: %d, force: %d, reason: %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "tdls_process_should_discover",
          v49,
          v48 & 0x80,
          *(unsigned __int8 *)(peer + 489),
          v50);
        *(_QWORD *)(v15 + 776) = v51;
        tdls_implicit_send_discovery_request(v15);
        return 0;
      }
      if ( v32 > 3 )
        v42 = "INVALID_TYPE";
      else
        v42 = off_B2DD70[v32];
      v46 = "%s: curr_peer is not forced, ignore %s";
      v47 = 8;
    }
    qdf_trace_msg(0, v47, v46, v34, v35, v36, v37, v38, v39, v40, v41, "tdls_process_should_discover", v42);
    return 0;
  }
  if ( v32 > 3 )
    v43 = "INVALID_TYPE";
  else
    v43 = off_B2DD70[v32];
  qdf_trace_msg(
    0,
    2u,
    "%s: soc_obj: %pK, vdev_obj: %pK, ignore %s",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "tdls_process_should_discover",
    comp_private_obj,
    v15,
    v43);
  return 29;
}
