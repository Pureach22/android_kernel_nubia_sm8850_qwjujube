__int64 __fastcall hdd_stop_enh_cfr(
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int *v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  result = ucfg_cfr_get_rcc_enabled(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (result & 1) != 0 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: cleanup rcc mode", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_stop_enh_cfr");
    wlan_objmgr_vdev_try_get_ref(a1, 0x30u, v19, v20, v21, v22, v23, v24, v25, v26);
    ucfg_cfr_set_rcc_mode(a1, 6, 0, v27, v28, v29, v30, v31, v32, v33, v34);
    ucfg_cfr_subscribe_ppdu_desc(*(_QWORD *)(a1 + 152), v35, v36, v37, v38, v39, v40, v41, v42);
    ucfg_cfr_committed_rcc_config(a1, v43, v44, v45, v46, v47, v48, v49, v50);
    ucfg_cfr_stop_indication(a1, v51, v52, v53, v54, v55, v56, v57, v58);
    ucfg_cfr_suspend(*(_QWORD *)(a1 + 152));
    qdf_trace_msg(0x33u, 8u, "%s: stop indication done", v59, v60, v61, v62, v63, v64, v65, v66, "hdd_stop_enh_cfr");
    return wlan_objmgr_vdev_release_ref(a1, 0x30u, v67, v68, v69, v70, v71, v72, v73, v74, v75);
  }
  return result;
}
