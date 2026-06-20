__int64 __fastcall lim_update_mlo_mgr_info(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
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
  __int64 v12; // x24
  int v15; // w23
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
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
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 result; // x0
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  __int64 v50; // x0
  __int64 v51; // x0

  _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)(a1 + 21632);
  if ( !v12 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: pdev is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "lim_update_mlo_mgr_info");
    result = 29;
    goto LABEL_19;
  }
  v15 = a2;
  v17 = wlan_scan_entry_by_bssid_and_security(*(_QWORD *)(a1 + 21632), a3, *(_BYTE *)(a2 + 168));
  if ( !v17 )
  {
LABEL_18:
    result = 16;
    goto LABEL_19;
  }
  v26 = v17;
  wlan_reg_freq_to_chan(v12, (unsigned __int16)*(_DWORD *)(v17 + 1192), v18, v19, v20, v21, v22, v23, v24, v25);
  wlan_mlme_get_ch_width_from_phymode(*(_DWORD *)(v26 + 52), v27, v28, v29, v30, v31, v32, v33, v34);
  mlo_mgr_update_ap_link_info(v15, a4, (int)a3);
  if ( (wlan_cm_is_eht_allowed_for_current_security(*(_QWORD *)(*(_QWORD *)(a1 + 21632) + 80LL), v26, 1) & 1) == 0 )
  {
    if ( a3 )
    {
      v46 = *a3;
      v47 = a3[1];
      v48 = a3[2];
      v49 = a3[5];
    }
    else
    {
      v48 = 0;
      v46 = 0;
      v47 = 0;
      v49 = 0;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: current security is not valid for partner link link_addr:%02x:%02x:%02x:**:**:%02x",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "lim_update_mlo_mgr_info",
      v46,
      v47,
      v48,
      v49);
    v50 = *(_QWORD *)(v26 + 1320);
    if ( v50 )
      _qdf_mem_free(v50);
    v51 = *(_QWORD *)(v26 + 1896);
    if ( v51 )
      _qdf_mem_free(v51);
    _qdf_mem_free(v26);
    goto LABEL_18;
  }
  v43 = *(_QWORD *)(v26 + 1320);
  if ( v43 )
    _qdf_mem_free(v43);
  v44 = *(_QWORD *)(v26 + 1896);
  if ( v44 )
    _qdf_mem_free(v44);
  _qdf_mem_free(v26);
  result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
