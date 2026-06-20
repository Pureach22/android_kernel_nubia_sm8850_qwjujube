__int64 __fastcall tdls_process_should_teardown(
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
  unsigned int v10; // w24
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 comp_private_obj; // x22
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x5
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 peer; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w22
  __int64 v52; // x4
  __int64 v53; // x21
  const char *v54; // x5
  const char *v55; // x6
  const char *v57; // x4
  __int64 v58; // x2
  __int64 v59; // [xsp+0h] [xbp-20h]
  __int64 v60; // [xsp+8h] [xbp-18h]
  __int64 v61; // [xsp+10h] [xbp-10h]

  v10 = *(unsigned __int16 *)(a2 + 8);
  if ( a1 )
  {
    v13 = *(_QWORD *)(a1 + 152);
    if ( v13 && (v14 = *(_QWORD *)(v13 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v14, 0xAu);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
      comp_private_obj = 0;
    }
    v16 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: NULL vdev", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
    qdf_trace_msg(0, 2u, "%s: NULL vdev", v25, v26, v27, v28, v29, v30, v31, v32, "wlan_vdev_get_tdls_vdev_obj");
    comp_private_obj = 0;
    v16 = 0;
  }
  if ( v10 > 3 )
    v33 = "INVALID_TYPE";
  else
    v33 = off_A2B9E8[v10];
  qdf_trace_msg(
    0,
    8u,
    "%s: vdev %d TDLS %s: %02x:%02x:%02x:**:**:%02xreason %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "tdls_process_should_teardown",
    *(unsigned __int8 *)(a1 + 104),
    v33,
    *(unsigned __int8 *)(a2 + 1),
    *(unsigned __int8 *)(a2 + 2),
    *(unsigned __int8 *)(a2 + 3),
    *(unsigned __int8 *)(a2 + 6),
    *(_DWORD *)(a2 + 12));
  if ( comp_private_obj && v16 )
  {
    peer = tdls_find_peer(v16, a2 + 1);
    if ( peer )
    {
      if ( *(_DWORD *)(peer + 36) == 4 )
      {
        v51 = *(_DWORD *)(a2 + 12);
        v52 = *(unsigned __int8 *)(a1 + 104);
        v53 = peer;
        if ( v10 > 3 )
          v54 = "INVALID_TYPE";
        else
          v54 = off_A2B9E8[v10];
        LODWORD(v61) = *(unsigned __int8 *)(a2 + 3);
        LODWORD(v60) = *(unsigned __int8 *)(a2 + 2);
        LODWORD(v59) = *(unsigned __int8 *)(a2 + 1);
        qdf_trace_msg(
          0,
          2u,
          "%s: vdev %d %s reason: %d link_state %d for%02x:%02x:%02x:**:**:%02x",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "tdls_process_should_teardown",
          v52,
          v54,
          v51,
          4,
          v59,
          v60,
          v61,
          *(unsigned __int8 *)(a2 + 6));
        if ( v51 - 1 > 5 )
          v58 = 26;
        else
          v58 = word_A2B9D8[v51 - 1];
        tdls_indicate_teardown(v16, v53, v58);
      }
      else
      {
        if ( v10 > 3 )
          v57 = "INVALID_TYPE";
        else
          v57 = off_A2B9E8[v10];
        qdf_trace_msg(
          0,
          2u,
          "%s: TDLS link is not connected, ignore %s",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "tdls_process_should_teardown",
          v57);
      }
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0,
        4u,
        "%s: curr_peer is null",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "tdls_process_should_teardown");
      return 29;
    }
  }
  else
  {
    if ( v10 > 3 )
      v55 = "INVALID_TYPE";
    else
      v55 = off_A2B9E8[v10];
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
      "tdls_process_should_teardown",
      comp_private_obj,
      v16,
      v55);
    return 29;
  }
}
