__int64 __fastcall wlan_cfg80211_mc_cp_get_big_data_stats(
        __int64 a1,
        unsigned int *a2,
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
  __int64 *context; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  __int64 result; // x0
  _DWORD *v31; // x20
  __int64 v32; // x0
  __int64 v33; // x19
  __int64 v34; // x25
  __int64 v35; // x0
  __int64 v36; // x9
  int v37; // w10
  unsigned int *v38; // x24
  int v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w22
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  char v91[4]; // [xsp+24h] [xbp-6Ch] BYREF
  _QWORD v92[6]; // [xsp+28h] [xbp-68h] BYREF
  _QWORD v93[2]; // [xsp+58h] [xbp-38h] BYREF
  int v94; // [xsp+68h] [xbp-28h]
  int v95; // [xsp+6Ch] [xbp-24h]
  __int64 v96; // [xsp+70h] [xbp-20h]
  __int64 v97; // [xsp+78h] [xbp-18h]
  __int64 v98; // [xsp+80h] [xbp-10h]
  __int64 v99; // [xsp+88h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97 = 0;
  v98 = 0;
  v96 = 0;
  memset(v92, 0, sizeof(v92));
  v91[0] = 0;
  qdf_trace_msg(0x48u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cfg80211_mc_cp_get_big_data_stats");
  context = _cds_get_context(
              51,
              (__int64)"wlan_cfg80211_mc_cp_get_big_data_stats",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19);
  v29 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"wlan_cfg80211_mc_cp_get_big_data_stats",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28);
  result = 0;
  if ( !v29 )
  {
    result = _qdf_mem_malloc(0x20u, "wlan_cfg80211_mc_cp_get_big_data_stats", 1236);
    if ( result )
    {
      v31 = (_DWORD *)result;
      v32 = osif_request_alloc(wlan_cfg80211_mc_cp_get_big_data_stats_params);
      if ( v32 )
      {
        v33 = v32;
        v34 = osif_request_cookie(v32);
        v35 = osif_request_priv(v33);
        v36 = *(_QWORD *)(a1 + 216);
        v37 = *(unsigned __int8 *)(a1 + 168);
        v93[0] = v34;
        v93[1] = get_big_data_stats_cb;
        v38 = (unsigned int *)v35;
        v39 = *(unsigned __int8 *)(v36 + 40);
        v94 = v37;
        v95 = v39;
        v48 = ucfg_send_big_data_stats_request(a1, 6u, v93, v40, v41, v42, v43, v44, v45, v46, v47);
        if ( v48 )
        {
          v57 = v48;
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Failed to send stats request status: %d",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "wlan_cfg80211_mc_cp_get_big_data_stats",
            v48);
          *a2 = qdf_status_to_os_return(v57);
        }
        else
        {
          v58 = osif_request_wait_for_response(v33);
          *a2 = v58;
          if ( !v58 )
          {
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: vdev_id: %d tsf_out_of_sync: %d ani_level: %d tx_pwr_last_data_frm: %d target_power_dsss: %d target_po"
              "wer_ofdm: %d rix_last_data_frm: %d tx_rate_last_data_frm: %d",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "wlan_cfg80211_mc_cp_get_big_data_stats",
              *v38,
              v38[1],
              v38[2],
              v38[3],
              v38[4],
              v38[5],
              v38[6],
              v38[7]);
            *v31 = *v38;
            v31[1] = v38[1];
            v31[2] = v38[2];
            v31[3] = v38[3];
            v31[4] = v38[4];
            v31[5] = v38[5];
            v31[6] = v38[6];
            v31[7] = v38[7];
            osif_request_put(v33);
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: Exit",
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              "wlan_cfg80211_mc_cp_get_big_data_stats");
            result = (__int64)v31;
            goto LABEL_11;
          }
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: wait failed or timed out ret: %d",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "wlan_cfg80211_mc_cp_get_big_data_stats",
            v58);
          ucfg_mc_cp_stats_reset_pending_req(*context, 6u, v92, v91, v67, v68, v69, v70, v71, v72, v73, v74);
        }
        osif_request_put(v33);
        _qdf_mem_free((__int64)v31);
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: Exit",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "wlan_cfg80211_mc_cp_get_big_data_stats");
      }
      else
      {
        _qdf_mem_free((__int64)v31);
      }
      result = 0;
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
