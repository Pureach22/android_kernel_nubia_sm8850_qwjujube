__int64 __fastcall wma_post_vdev_start_setup(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x8
  __int64 v20; // x22
  int v21; // w8
  __int64 v22; // x20
  _QWORD *v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  const char *v33; // x2
  __int64 *v34; // x20
  __int64 cmpt_obj; // x0
  __int64 v36; // x21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 channel_reg_power_for_freq; // x6
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_post_vdev_start_setup", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = (__int64 *)(context[65] + 488LL * (unsigned __int8)a1);
    if ( v19 )
    {
      v20 = *v19;
      if ( *v19 )
      {
        v21 = *(_DWORD *)(v20 + 16);
        if ( v21 == 11 || v21 == 5 )
        {
          v22 = *context;
          v23 = _cds_get_context(54, (__int64)"wma_is_vdev_valid", v11, v12, v13, v14, v15, v16, v17, v18);
          if ( v23 )
          {
            if ( *((unsigned __int16 *)v23 + 81) <= (unsigned int)(unsigned __int8)a1 )
            {
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: vdev_id: %d is invalid, max_bssid: %d",
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                "wma_is_vdev_valid",
                (unsigned __int8)a1);
            }
            else if ( (*(_BYTE *)(v23[65] + 488LL * (unsigned __int8)a1 + 184) & 1) != 0 )
            {
              wmi_unified_vdev_set_param_send(v22);
LABEL_24:
              result = 0;
              goto LABEL_25;
            }
          }
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: vdev_id: %d is not active reject the req: param id %d val %d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wma_vdev_set_param",
            (unsigned __int8)a1,
            26,
            0);
          goto LABEL_24;
        }
        v34 = context;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v20, v11, v12, v13, v14, v15, v16, v17, v18);
        if ( cmpt_obj )
        {
          v36 = cmpt_obj;
          qdf_mem_copy(*(void **)(v20 + 32), *(const void **)(v20 + 40), 0x20u);
          if ( (wlan_reg_is_ext_tpc_supported(v34[3], v37, v38, v39, v40, v41, v42, v43, v44) & 1) != 0 )
            channel_reg_power_for_freq = 0;
          else
            channel_reg_power_for_freq = (unsigned int)wlan_reg_get_channel_reg_power_for_freq(
                                                         v34[4],
                                                         **(unsigned __int16 **)(v20 + 32),
                                                         v45,
                                                         v46,
                                                         v47,
                                                         v48,
                                                         v49,
                                                         v50,
                                                         v51,
                                                         v52);
          if ( (unsigned int)wma_vdev_set_bss_params(
                               v34,
                               (unsigned __int8)a1,
                               *(unsigned __int16 *)(v36 + 20),
                               *(unsigned __int8 *)(v36 + 8),
                               *(unsigned int *)(v36 + 12),
                               *(unsigned int *)(v36 + 16),
                               channel_reg_power_for_freq) )
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Failed to set wma_vdev_set_bss_params",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "wma_post_vdev_start_setup");
          wma_vdev_set_he_bss_params(v34, a1, v36 + 68);
          goto LABEL_24;
        }
        v33 = "%s: vdev component object is NULL";
      }
      else
      {
        v33 = "%s: vdev is NULL";
      }
    }
    else
    {
      v33 = "%s: Invalid interface";
    }
    qdf_trace_msg(0x36u, 2u, v33, v11, v12, v13, v14, v15, v16, v17, v18, "wma_post_vdev_start_setup");
    result = 16;
  }
  else
  {
    result = 16;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
