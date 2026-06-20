__int64 __fastcall hdd_cm_disconnect_complete_post_user_update(
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
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x20
  __int64 *link_info_by_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x23
  unsigned int v33; // w24
  __int64 *v34; // x26
  __int64 ext_hdl; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x25
  unsigned __int16 *v45; // x27
  int v46; // w25
  __int64 channel_bonding_5ghz; // x0
  int vht_ch_width; // w0
  unsigned int v49; // w25
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 result; // x0
  int v59; // w2
  __int64 *v60; // x24
  const char *v61; // x2
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 *v70; // x8
  const char *v71; // x2
  unsigned __int8 client_id_bitmap; // w24
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned int v89; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int8 v99[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v100[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v101[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v102; // [xsp+18h] [xbp-8h]

  v102 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(
              51,
              (__int64)"hdd_cm_disconnect_complete_post_user_update",
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10);
  if ( context )
  {
    v21 = context;
    link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(context);
    if ( link_info_by_vdev )
    {
      v31 = *link_info_by_vdev;
      v32 = (__int64)link_info_by_vdev;
      v33 = *(unsigned __int8 *)(a1 + 104);
      v98 = 0;
      v34 = *(__int64 **)(v31 + 24);
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( ext_hdl )
      {
        v44 = ext_hdl;
        wlan_mlme_update_ch_width_from_ap(ext_hdl, 0);
        v45 = *(unsigned __int16 **)(a1 + 40);
        if ( v45 )
        {
          v46 = *(_DWORD *)(v44 + 24248);
          if ( (ucfg_mlme_is_chwidth_with_notify_supported(*v34) & 1) != 0 && v46 != 8 )
          {
            cm_update_associated_ch_info(a1, 0, v36, v37, v38, v39, v40, v41, v42, v43);
            channel_bonding_5ghz = wlan_mlme_get_channel_bonding_5ghz(*v34, (int *)&v98);
            if ( v98 || (channel_bonding_5ghz = wlan_reg_is_24ghz_ch_freq(*v45), (channel_bonding_5ghz & 1) != 0) )
            {
              vht_ch_width = wma_get_vht_ch_width(channel_bonding_5ghz);
              if ( (unsigned int)(vht_ch_width - 1) < 3 )
                v49 = vht_ch_width + 1;
              else
                v49 = 1;
            }
            else
            {
              v49 = v98;
            }
            if ( (unsigned int)hdd_set_mac_chan_width(v32, v49, 0xFFu, 1u) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: vdev %d : fail to set max ch width",
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                "hdd_cm_restore_ch_width",
                v33);
            else
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: vdev %d : updated ch width to: %d on disconnection",
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                "hdd_cm_restore_ch_width",
                v33,
                v49);
          }
        }
      }
      if ( *(_DWORD *)(a2 + 8) == 18 )
      {
        v59 = 18;
        goto LABEL_25;
      }
      v60 = *(__int64 **)(v31 + 24);
      v100[0] = 0;
      v99[0] = 0;
      if ( v60 )
      {
        if ( !(unsigned int)mlme_get_cfg_wlm_reset(*v60, v100) )
        {
          if ( v100[0] == 1 )
          {
            if ( (unsigned int)mlme_get_cfg_wlm_level(*v60, v99) )
              v99[0] = 1;
            if ( (hdd_get_multi_client_ll_support(v31) & 1) != 0 )
            {
              client_id_bitmap = wlan_hdd_get_client_id_bitmap(v31);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: client_id_bitmap: 0x%x",
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                "hdd_cm_set_default_wlm_mode",
                client_id_bitmap);
              wlan_hdd_set_wlm_latency_level(v31, v99[0], client_id_bitmap, 1, v81, v82, v83, v84, v85, v86, v87, v88);
              wlan_hdd_deinit_multi_client_info_table(v31);
            }
            else
            {
              v89 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))sme_set_wlm_latency_level)(
                      v60[2],
                      *(unsigned __int8 *)(*(_QWORD *)(v31 + 52824) + 8LL),
                      v99[0],
                      0,
                      0);
              if ( v89 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: reset wlm mode failed: %d",
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  v97,
                  "hdd_cm_set_default_wlm_mode",
                  v89);
              }
              else
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: reset wlm mode %x on disconnection",
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  v97,
                  "hdd_cm_set_default_wlm_mode",
                  v99[0]);
                *(_WORD *)(v31 + 52098) = v99[0];
              }
            }
            *(_WORD *)(v31 + 52100) = 0;
          }
          goto LABEL_24;
        }
        v61 = "%s: could not get wlm reset flag";
      }
      else
      {
        v61 = "%s: hdd_ctx is NULL";
      }
      qdf_trace_msg(0x33u, 2u, v61, v36, v37, v38, v39, v40, v41, v42, v43, "hdd_cm_set_default_wlm_mode");
LABEL_24:
      v59 = *(_DWORD *)(a2 + 8);
LABEL_25:
      _hdd_cm_disconnect_handler_post_user_update(v32, a1, v59, v36, v37, v38, v39, v40, v41, v42, v43);
      wlan_twt_concurrency_update(v21);
      v70 = *(__int64 **)(v31 + 24);
      v101[0] = 0;
      if ( v70 )
      {
        if ( !(unsigned int)mlme_get_cfg_wlm_reset(*v70, v101) )
        {
          if ( v101[0] == 1 )
          {
            *(_BYTE *)(v31 + 42083) = 1;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: UDP packets qos upgrade to: %d",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "hdd_cm_reset_udp_qos_upgrade_config",
              1);
          }
          goto LABEL_30;
        }
        v71 = "%s: could not get the wlm reset flag";
      }
      else
      {
        v71 = "%s: hdd_ctx is NULL";
      }
      qdf_trace_msg(0x33u, 2u, v71, v62, v63, v64, v65, v66, v67, v68, v69, "hdd_cm_reset_udp_qos_upgrade_config");
LABEL_30:
      ucfg_mlme_set_ml_link_control_mode();
      result = 0;
      goto LABEL_31;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: adapter is NULL for vdev %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_cm_disconnect_complete_post_user_update",
      *(unsigned __int8 *)(a1 + 104));
    result = 4;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_ctx is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_cm_disconnect_complete_post_user_update");
    result = 4;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
