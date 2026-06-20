__int64 __fastcall wlan_mlo_roam_abort_on_link(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x1
  int v14; // w21
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x1
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x1
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  if ( a2 )
  {
    if ( !*(_BYTE *)(a2 + 2497) )
      return 0;
    v13 = *(unsigned int *)(a2 + 2500);
    v14 = a3;
    v15 = a1;
    if ( (_DWORD)v13 != a3 )
    {
      LODWORD(a1) = cm_fw_roam_abort_req(a1, v13);
      if ( (_DWORD)a1 )
        LODWORD(a1) = qdf_trace_msg(
                        0x8Fu,
                        2u,
                        "%s: LFR3: Fail to abort roam on vdev: %u",
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        v22,
                        v23,
                        "wlan_mlo_roam_abort_on_link",
                        *(unsigned int *)(a2 + 2500));
    }
    if ( *(unsigned __int8 *)(a2 + 2497) < 2u )
      return 0;
    v24 = *(unsigned int *)(a2 + 2552);
    if ( (_DWORD)v24 != v14 )
    {
      LODWORD(a1) = cm_fw_roam_abort_req(v15, v24);
      if ( (_DWORD)a1 )
        LODWORD(a1) = qdf_trace_msg(
                        0x8Fu,
                        2u,
                        "%s: LFR3: Fail to abort roam on vdev: %u",
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        v30,
                        v31,
                        v32,
                        "wlan_mlo_roam_abort_on_link",
                        *(unsigned int *)(a2 + 2552));
    }
    if ( *(unsigned __int8 *)(a2 + 2497) < 3u )
      return 0;
    v33 = *(unsigned int *)(a2 + 2604);
    if ( (_DWORD)v33 != v14 )
    {
      LODWORD(a1) = cm_fw_roam_abort_req(v15, v33);
      if ( (_DWORD)a1 )
        LODWORD(a1) = qdf_trace_msg(
                        0x8Fu,
                        2u,
                        "%s: LFR3: Fail to abort roam on vdev: %u",
                        v34,
                        v35,
                        v36,
                        v37,
                        v38,
                        v39,
                        v40,
                        v41,
                        "wlan_mlo_roam_abort_on_link",
                        *(unsigned int *)(a2 + 2604));
    }
    if ( *(unsigned __int8 *)(a2 + 2497) > 3u )
    {
      __break(0x5512u);
      return mlo_roam_get_bssid_chan_for_link(a1, v33, a3, a4);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Roam Sync ind ptr is NULL",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_mlo_roam_abort_on_link");
    return 29;
  }
}
