__int64 __fastcall wma_vdev_pre_start(
        unsigned int a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  __int64 v31; // x9
  const char *v32; // x2
  __int64 v33; // x27
  __int64 v34; // x22
  _QWORD *v35; // x26
  __int64 cmpt_obj; // x0
  __int64 v37; // x21
  unsigned __int16 *v38; // x28
  __int64 ini_vdev_config; // x0
  __int64 v40; // x25
  int v41; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w9
  unsigned int v51; // w8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _QWORD *v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x22
  unsigned int v86; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int max_amsdu_num; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x4
  const char *v105; // x2
  unsigned int v106; // w0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // [xsp+0h] [xbp-10h] BYREF
  __int64 v116; // [xsp+8h] [xbp-8h]

  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_vdev_pre_start", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = _cds_get_context(53, (__int64)"wma_vdev_pre_start", v13, v14, v15, v16, v17, v18, v19, v20);
  result = 16;
  if ( context && v21 )
  {
    v31 = context[65];
    HIDWORD(v115) = 0;
    LOBYTE(v115) = 0;
    if ( v31 )
    {
      if ( (unsigned __int8)a1 >= 6u )
      {
        qdf_trace_msg(0x36u, 2u, "%s: Invalid vdev id", v22, v23, v24, v25, v26, v27, v28, v29, "wma_vdev_pre_start");
        result = 4;
        goto LABEL_50;
      }
      v33 = v31 + 488LL * (unsigned __int8)a1;
      v34 = *(_QWORD *)v33;
      if ( *(_QWORD *)v33 )
      {
        v35 = v21;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v33, v22, v23, v24, v25, v26, v27, v28, v29);
        if ( cmpt_obj )
        {
          v37 = cmpt_obj;
          v38 = *(unsigned __int16 **)(v34 + 40);
          ini_vdev_config = mlme_get_ini_vdev_config(v34, v22, v23, v24, v25, v26, v27, v28, v29);
          if ( ini_vdev_config )
          {
            v40 = ini_vdev_config;
            *(_QWORD *)(v33 + 112) = 0x8020000008080LL;
            v41 = *(_DWORD *)(v35[1] + 3508LL);
            *(_QWORD *)(v33 + 124) = 0x200000003LL;
            *(_QWORD *)(v33 + 132) = 1;
            *(_DWORD *)(v33 + 120) = v41;
            *(_DWORD *)(v33 + 140) = 15;
            *(_DWORD *)(v33 + 180) = *((_DWORD *)v38 + 6);
            *(_DWORD *)(v33 + 436) = *v38;
            if ( (unsigned int)cds_get_conparam() != 4
              && (wlan_reg_is_dfs_for_freq(context[4], *v38, v42, v43, v44, v45, v46, v47, v48, v49) & 1) != 0 )
            {
              *(_BYTE *)(v37 + 183) = 1;
            }
            if ( *(_DWORD *)(v37 + 320) )
            {
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: beacon tx rate [%u * 100 Kbps]",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "wma_vdev_pre_start");
              v50 = *(unsigned __int16 *)(v37 + 320);
              v51 = 131;
              if ( v50 <= 0x77 )
              {
                if ( *(unsigned __int16 *)(v37 + 320) <= 0x3Bu )
                {
                  if ( v50 == 20 )
                  {
                    v51 = 130;
                  }
                  else if ( v50 == 55 )
                  {
                    v51 = 129;
                  }
                }
                else
                {
                  switch ( v50 )
                  {
                    case '<':
                      v51 = 3;
                      break;
                    case 'Z':
                      v51 = 7;
                      break;
                    case 'n':
                      v51 = 128;
                      break;
                  }
                }
              }
              else if ( *(unsigned __int16 *)(v37 + 320) > 0x167u )
              {
                switch ( v50 )
                {
                  case 0x168u:
                    v51 = 5;
                    break;
                  case 0x1E0u:
                    v51 = 0;
                    break;
                  case 0x21Cu:
                    v51 = 4;
                    break;
                }
              }
              else
              {
                switch ( v50 )
                {
                  case 0x78u:
                    v51 = 2;
                    break;
                  case 0xB4u:
                    v51 = 6;
                    break;
                  case 0xF0u:
                    v51 = 1;
                    break;
                }
              }
              *(_DWORD *)(v37 + 320) = v51;
              *(_DWORD *)(v37 + 324) = wlan_mlme_assemble_rate_code(v51 >> 7, 0, v51 & 7);
            }
            if ( (a2 & 1) == 0 )
            {
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: vdev_id: %d, unpausing tx_ll_queue at VDEV_START",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "wma_vdev_pre_start",
                (unsigned __int8)a1);
              v60 = _cds_get_context(71, (__int64)"wma_vdev_pre_start", v52, v53, v54, v55, v56, v57, v58, v59);
              cdp_fc_vdev_unpause((__int64)v60, v61, v62, v63, v64, v65, v66, v67, v68);
              wma_vdev_update_pause_bitmap(a1, v69, v70, v71, v72, v73, v74, v75, v76);
              if ( *((_BYTE *)context + 3950) == 1 )
                wma_vdev_nss_chain_params_send(a1, v40);
            }
            if ( (unsigned int)ucfg_coex_psoc_get_btc_chain_mode(context[3], (char *)&v115 + 4) )
            {
              v32 = "%s: Failed to get btc chain mode";
              goto LABEL_48;
            }
            if ( HIDWORD(v115) != 255 && (unsigned int)ucfg_coex_send_btc_chain_mode(v34) )
            {
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Failed to send btc chain mode %d",
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                "wma_vdev_pre_start",
                HIDWORD(v115));
              goto LABEL_49;
            }
            v85 = v35[1];
            v86 = wma_set_tx_rx_aggr_size(a1, *(unsigned int *)(v85 + 2892));
            if ( v86 )
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: failed to set aggregation sizes(status = %d)",
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                v94,
                "wma_vdev_pre_start",
                v86);
            if ( *((_BYTE *)v35 + 21696) == 1 )
            {
              max_amsdu_num = wlan_mlme_get_max_amsdu_num(context[3], &v115);
              if ( max_amsdu_num )
              {
                v104 = max_amsdu_num;
                v105 = "%s: failed to get amsdu aggr.size(status = %d)";
              }
              else
              {
                v106 = wma_set_tx_rx_aggr_size(a1, (unsigned __int8)v115);
                if ( !v106 )
                  goto LABEL_62;
                v104 = v106;
                v105 = "%s: failed to set amsdu aggr.size(status = %d)";
              }
              qdf_trace_msg(
                0x36u,
                2u,
                v105,
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                "wma_vdev_pre_start",
                v104,
                v115,
                v116);
            }
LABEL_62:
            if ( *(_BYTE *)(v37 + 179) == 2 )
            {
              result = wma_set_tx_rx_aggr_size_per_ac(context, a1, v85 + 2892, 0);
              if ( !(_DWORD)result )
                goto LABEL_50;
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: failed to set aggr size per ac(status = %d)",
                v107,
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                "wma_vdev_pre_start",
                (unsigned int)result);
            }
            result = 0;
            goto LABEL_50;
          }
          v32 = "%s: nss chain ini config NULL";
        }
        else
        {
          v32 = "%s: vdev component object is NULL";
        }
      }
      else
      {
        v32 = "%s: Invalid vdev";
      }
    }
    else
    {
      v32 = "%s: Invalid interface";
    }
LABEL_48:
    qdf_trace_msg(0x36u, 2u, v32, v22, v23, v24, v25, v26, v27, v28, v29, "wma_vdev_pre_start", v115, v116);
LABEL_49:
    result = 16;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
