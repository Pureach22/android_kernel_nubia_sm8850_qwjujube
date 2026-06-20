__int64 __fastcall wma_vdev_start_resp_handler(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x23
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x24
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _QWORD *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x22
  __int64 v40; // x20
  __int64 psoc_ext_obj_fl; // x0
  __int64 v42; // x26
  __int64 tgt_res_cfg; // x0
  _DWORD *v44; // x22
  __int64 v45; // x5
  unsigned int v46; // w25
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  const char *v55; // x2
  __int64 cmpt_obj; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x23
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  _BOOL4 v74; // w24
  __int64 result; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x20
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w9
  __int64 v94; // x0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  const char *v103; // x2
  int v104; // [xsp+20h] [xbp-10h] BYREF
  __int16 v105; // [xsp+24h] [xbp-Ch]
  __int64 v106; // [xsp+28h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_vdev_start_resp_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = _cds_get_context(71, (__int64)"wma_vdev_start_resp_handler", v13, v14, v15, v16, v17, v18, v19, v20);
  v30 = _cds_get_context(54, (__int64)"wma_vdev_start_resp_handler", v22, v23, v24, v25, v26, v27, v28, v29);
  if ( v30 )
  {
    v39 = v30[3];
    if ( v39 )
    {
      v40 = (__int64)v30;
      psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v30[3]);
      if ( psoc_ext_obj_fl )
      {
        if ( context )
        {
          v42 = psoc_ext_obj_fl;
          tgt_res_cfg = lmac_get_tgt_res_cfg(v39, v31, v32, v33, v34, v35, v36, v37, v38);
          if ( tgt_res_cfg )
          {
            if ( *(unsigned __int16 *)(v40 + 162) <= (unsigned int)*a2 )
            {
              v55 = "%s: Invalid vdev id received from firmware";
            }
            else
            {
              v44 = (_DWORD *)(*(_QWORD *)(v40 + 520) + 488LL * *a2);
              if ( *(_QWORD *)v44 )
              {
                if ( !*((_DWORD *)a2 + 2) )
                {
                  v45 = *((unsigned int *)a2 + 7);
                  v44[66] = v45;
                  v46 = *((_DWORD *)a2 + 6);
                  if ( *(_DWORD *)(tgt_res_cfg + 252) )
                  {
                    if ( !v46 )
                    {
                      qdf_trace_msg(
                        0x36u,
                        2u,
                        "%s: soc level id received for mac id",
                        v31,
                        v32,
                        v33,
                        v34,
                        v35,
                        v36,
                        v37,
                        v38,
                        "wma_vdev_start_resp_handler");
                      result = 4294967292LL;
                      goto LABEL_27;
                    }
                    --v46;
                  }
                  qdf_trace_msg(
                    0x36u,
                    8u,
                    "%s: vdev:%d tx ss=%d rx ss=%d chain mask=%d mac=%d",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "wma_vdev_start_resp_handler",
                    *a2,
                    v45,
                    *((unsigned int *)a2 + 8),
                    *((unsigned int *)a2 + 4),
                    v46,
                    0,
                    0,
                    0);
                  qdf_mem_copy(*(void **)(*(_QWORD *)v44 + 32LL), *(const void **)(*(_QWORD *)v44 + 40LL), 0x20u);
                  wma_set_and_update_mac_id(v40, context, a2, v21, v46);
                }
                if ( (wma_get_hidden_ssid_restart_in_progress(v44) & 1) != 0
                  && wma_is_vdev_in_ap_mode(v40, *a2, v47, v48, v49, v50, v51, v52, v53, v54) )
                {
                  wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)v44, 4u, 0, 0, v47, v48, v49, v50, v51, v52, v53, v54);
LABEL_51:
                  result = 0;
                  goto LABEL_27;
                }
                cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v44, v47, v48, v49, v50, v51, v52, v53, v54);
                if ( !cmpt_obj )
                  goto LABEL_36;
                v65 = cmpt_obj;
                *(_DWORD *)(cmpt_obj + 116) = *((_DWORD *)a2 + 9);
                *(_BYTE *)(cmpt_obj + 121) = *((_DWORD *)a2 + 10);
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: Max allowed tx power: %d, Min allowed tx power: %d",
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  "wma_vdev_start_resp_handler",
                  *((unsigned int *)a2 + 9),
                  *((unsigned int *)a2 + 10));
                v74 = v44[41] != 2
                   || (unsigned int)mlme_get_assoc_type(*(_QWORD *)(a1 + 504), v66, v67, v68, v69, v70, v71, v72, v73) < 2;
                if ( (mlme_is_chan_switch_in_progress(*(_QWORD *)v44, v66, v67, v68, v69, v70, v71, v72, v73) & 1) != 0 )
                {
LABEL_30:
                  wma_handle_channel_switch_resp(v40, a2, v76, v77, v78, v79, v80, v81, v82, v83);
LABEL_31:
                  if ( v44[41] == 1 && (wma_is_vdev_up(*a2) & 1) != 0 )
                    wma_set_sap_keepalive(v40, *a2);
                  if ( (unsigned int)(*(_DWORD *)(v42 + 6580) - 1) > 3 )
                    goto LABEL_51;
                  v84 = *(_QWORD *)v40;
                  if ( !(unsigned int)_wmi_validate_handle(
                                        v84,
                                        (__int64)"wma_vdev_start_resp_handler",
                                        v31,
                                        v32,
                                        v33,
                                        v34,
                                        v35,
                                        v36,
                                        v37,
                                        v38) )
                  {
                    if ( (unsigned int)(*(_DWORD *)(v42 + 6580) - 1) >= 4 )
                    {
                      v103 = "%s: %s: unable to map ratemask";
                    }
                    else
                    {
                      result = wmi_unified_vdev_config_ratemask_cmd_send(v84);
                      if ( !(_DWORD)result )
                        goto LABEL_27;
                      v103 = "%s: %s: failed to send ratemask";
                    }
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      v103,
                      v85,
                      v86,
                      v87,
                      v88,
                      v89,
                      v90,
                      v91,
                      v92,
                      "wma_vdev_start_resp_handler",
                      "wma_vdev_start_resp_handler");
                    goto LABEL_51;
                  }
LABEL_36:
                  result = 4;
                  goto LABEL_27;
                }
                v93 = v44[41];
                if ( v93 != 6 )
                {
                  if ( v93 != 4 && (v93 != 2 || !v74) )
                  {
                    v94 = *(_QWORD *)v44;
                    v105 = 0;
                    v104 = 0;
                    if ( (unsigned int)wlan_vdev_get_bss_peer_mac(v94, &v104, v76, v77, v78, v79, v80, v81, v82, v83) )
                    {
                      qdf_trace_msg(
                        0x36u,
                        2u,
                        "%s: Failed to get bssid",
                        v95,
                        v96,
                        v97,
                        v98,
                        v99,
                        v100,
                        v101,
                        v102,
                        "wma_vdev_start_resp_handler");
                      result = 4;
                      goto LABEL_27;
                    }
                    qdf_mem_copy((void *)(v65 + 168), &v104, 6u);
                    wma_vdev_start_rsp(v40, *(_QWORD *)(a1 + 504), a2);
                    goto LABEL_31;
                  }
                  goto LABEL_30;
                }
                *(_WORD *)(v65 + 42) = *((_WORD *)v44 + 104);
                if ( !(unsigned int)vdev_mgr_up_send(v65, v76, v77, v78, v79, v80, v81, v82, v83) )
                  goto LABEL_31;
                v55 = "%s: failed to send vdev up";
              }
              else
              {
                v55 = "%s: Invalid vdev";
              }
            }
          }
          else
          {
            v55 = "%s: Wlan resource config is NULL";
          }
        }
        else
        {
          v55 = "%s: Failed to get mac_ctx";
        }
      }
      else
      {
        v55 = "%s: Failed to get mlme_psoc";
      }
    }
    else
    {
      v55 = "%s: psoc is NULL";
    }
    qdf_trace_msg(0x36u, 2u, v55, v31, v32, v33, v34, v35, v36, v37, v38, "wma_vdev_start_resp_handler");
  }
  result = 16;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
