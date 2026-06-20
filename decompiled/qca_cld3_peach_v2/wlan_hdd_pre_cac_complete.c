__int64 __fastcall wlan_hdd_pre_cac_complete(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *link_info_from_vdev; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  __int64 *v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  const char *v50; // x3
  __int64 *v51; // x21
  unsigned int chan_width; // w20
  __int64 adapter; // x0
  __int64 v54; // x19
  unsigned int freq; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w1

  link_info_from_vdev = (__int64 *)wlan_hdd_get_link_info_from_vdev(a4, a5, a6, a7, a8, a9, a10, a11, a1, a2);
  if ( !link_info_from_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid vdev %d",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "wlan_hdd_pre_cac_complete",
             a2);
  v22 = *link_info_from_vdev;
  if ( a3 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v14, v15, v16, v17, v18, v19, v20, v21, "wlan_hdd_pre_cac_failure");
    v23 = *(__int64 **)(v22 + 24);
    result = _wlan_hdd_validate_context(
               (__int64)v23,
               (__int64)"wlan_hdd_pre_cac_failure",
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31);
    if ( (_DWORD)result )
      return result;
    wlan_hdd_stop_sap(*(_QWORD *)(v22 + 52832), v33, v34, v35, v36, v37, v38, v39, v40);
    hdd_stop_adapter(v23, v22);
    v49 = "%s: exit";
    v50 = "wlan_hdd_pre_cac_failure";
    goto LABEL_11;
  }
  qdf_trace_msg(0x33u, 8u, "%s: enter", v14, v15, v16, v17, v18, v19, v20, v21, "wlan_hdd_pre_cac_success");
  v51 = *(__int64 **)(v22 + 24);
  if ( !v51 )
  {
    v49 = "%s: HDD context is null";
LABEL_14:
    v50 = "wlan_hdd_pre_cac_success";
    v64 = 2;
    return qdf_trace_msg(0x33u, v64, v49, v41, v42, v43, v44, v45, v46, v47, v48, v50);
  }
  chan_width = wlansap_get_chan_width(
                 *(_QWORD *)(*(_QWORD *)(v22 + 52832) + 272LL),
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48);
  hdd_stop_adapter(v51, v22);
  adapter = hdd_get_adapter((__int64)v51, 1);
  if ( !adapter )
  {
    v49 = "%s: failed to get SAP adapter, no restart on pre CAC channel";
    goto LABEL_14;
  }
  v54 = adapter;
  ucfg_pre_cac_complete_set(*(_QWORD *)(*(_QWORD *)(adapter + 52832) + 32LL), 1, v41, v42, v43, v44, v45, v46, v47, v48);
  wlan_hdd_set_sap_csa_reason(*v51, *(_BYTE *)(*(_QWORD *)(v54 + 52832) + 8LL), 4u);
  freq = ucfg_pre_cac_get_freq(*(_QWORD *)(*(_QWORD *)(v54 + 52832) + 32LL));
  if ( (unsigned int)hdd_softap_set_channel_change(*(__int64 **)(v54 + 52832), freq, 0, chan_width, 0, 0, 0) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to change channel",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "wlan_hdd_pre_cac_success");
    ucfg_pre_cac_complete_set(*(_QWORD *)(*(_QWORD *)(v54 + 52832) + 32LL), 0, v56, v57, v58, v59, v60, v61, v62, v63);
  }
  v49 = "%s: exit";
  v50 = "wlan_hdd_pre_cac_success";
LABEL_11:
  v64 = 8;
  return qdf_trace_msg(0x33u, v64, v49, v41, v42, v43, v44, v45, v46, v47, v48, v50);
}
