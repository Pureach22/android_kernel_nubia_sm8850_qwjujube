__int64 __fastcall wma_set_ap_vdev_up(
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
  __int64 v12; // x21
  __int64 cmpt_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * (unsigned __int8)a2);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v12, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj )
  {
    v22 = cmpt_obj;
    *(_WORD *)(cmpt_obj + 42) = 0;
    v23 = vdev_mgr_up_send(cmpt_obj, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( v23 )
    {
      v32 = v23;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: failed to send vdev up",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wma_set_ap_vdev_up");
      return v32;
    }
    else
    {
      wma_set_sap_keepalive(a1, a2, v24, v25, v26, v27, v28, v29, v30, v31);
      wma_set_vdev_mgmt_rate(v34, v35, v36, v37, v38, v39, v40, v41);
      wma_vdev_set_he_bss_params(a1, a2, v22 + 68);
      mlme_sr_update(v12, 1, v42, v43, v44, v45, v46, v47, v48, v49);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: failed to get mlme_obj", v14, v15, v16, v17, v18, v19, v20, v21, "wma_set_ap_vdev_up");
    return 4;
  }
}
