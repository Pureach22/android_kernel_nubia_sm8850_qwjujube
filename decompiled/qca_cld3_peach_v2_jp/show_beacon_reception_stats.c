__int64 __fastcall show_beacon_reception_stats(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  _QWORD *context; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x20
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _DWORD *v62; // x22
  double v63; // d0
  int v64; // w0
  int v65; // w23
  int v66; // w0
  int v67; // w23
  int v68; // w0
  int v69; // w23
  int v70; // w0
  int v71; // w23
  int v72; // w0
  int v73; // w23
  int v74; // w0
  int v75; // w23
  int v76; // w0
  int v77; // w23
  int v78; // w0
  int v79; // w23
  int v80; // w0
  int v81; // w23
  double v82; // d0
  int v83; // w0
  int v84; // w22
  int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 *v94[2]; // [xsp+0h] [xbp-10h] BYREF

  v94[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v94[0] = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, v94, (__int64)"show_beacon_reception_stats");
  if ( !v5 )
  {
    context = _cds_get_context(51, (__int64)"__show_beacon_reception_stats", v6, v7, v8, v9, v10, v11, v12, v13);
    v24 = _wlan_hdd_validate_context(
            (__int64)context,
            (__int64)"__show_beacon_reception_stats",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
    if ( v24 )
    {
      v14 = v24;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 1312) == 1885692259 )
      {
        if ( (*(_QWORD *)(a1 + 2936) & 4) != 0 )
        {
          if ( (*(_DWORD *)(a1 + 1352) | 2) != 2 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Beacon Reception Stats only supported in STA or P2P CLI modes!",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "__show_beacon_reception_stats");
            v14 = -524;
            goto LABEL_10;
          }
          if ( hdd_cm_is_vdev_associated(*(_DWORD **)(a1 + 54136)) )
          {
            v35 = osif_request_alloc(_show_beacon_reception_stats_params);
            if ( v35 )
            {
              v44 = v35;
              v45 = osif_request_cookie(v35);
              if ( (unsigned int)sme_beacon_debug_stats_req(
                                   context[2],
                                   *(unsigned __int8 *)(*(_QWORD *)(a1 + 54136) + 8LL),
                                   (__int64)hdd_beacon_debugstats_cb,
                                   v45) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: chip power stats request failed",
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  "__show_beacon_reception_stats");
                v14 = -22;
              }
              else if ( (unsigned int)osif_request_wait_for_response(v44) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Target response timed out Power stats",
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  "__show_beacon_reception_stats");
                v14 = -110;
              }
              else
              {
                v62 = (_DWORD *)osif_request_priv(v44);
                v14 = 4096;
                v63 = scnprintf(
                        a3,
                        4096,
                        "BEACON RECEPTION STATS\n"
                        "=================\n"
                        "vdev id: %u\n"
                        "Total Beacon Count: %u\n"
                        "Total Beacon Miss Count: %u\n",
                        *v62,
                        v62[1],
                        v62[2]);
                v65 = v64;
                scnprintf(a3 + v64, 4096LL - v64, "Beacon Miss Bit map ", v63);
                v67 = v66 + v65;
                if ( v67 != 4096 )
                {
                  v14 = 4096;
                  scnprintf(a3 + v67, 4096LL - v67, "[0x%x] ", v62[3]);
                  v69 = v68 + v67;
                  if ( v69 != 4096 )
                  {
                    v14 = 4096;
                    scnprintf(a3 + v69, 4096LL - v69, "[0x%x] ", v62[4]);
                    v71 = v70 + v69;
                    if ( v71 != 4096 )
                    {
                      v14 = 4096;
                      scnprintf(a3 + v71, 4096LL - v71, "[0x%x] ", v62[5]);
                      v73 = v72 + v71;
                      if ( v73 != 4096 )
                      {
                        v14 = 4096;
                        scnprintf(a3 + v73, 4096LL - v73, "[0x%x] ", v62[6]);
                        v75 = v74 + v73;
                        if ( v75 != 4096 )
                        {
                          v14 = 4096;
                          scnprintf(a3 + v75, 4096LL - v75, "[0x%x] ", v62[7]);
                          v77 = v76 + v75;
                          if ( v77 != 4096 )
                          {
                            v14 = 4096;
                            scnprintf(a3 + v77, 4096LL - v77, "[0x%x] ", v62[8]);
                            v79 = v78 + v77;
                            if ( v79 != 4096 )
                            {
                              v14 = 4096;
                              scnprintf(a3 + v79, 4096LL - v79, "[0x%x] ", v62[9]);
                              v81 = v80 + v79;
                              if ( v81 != 4096 )
                              {
                                v14 = 4096;
                                v82 = scnprintf(a3 + v81, 4096LL - v81, "[0x%x] ", v62[10]);
                                v84 = v83 + v81;
                                if ( v83 + v81 != 4096 )
                                {
                                  scnprintf(a3 + v84, 4096LL - v84, "\n", v82);
                                  v14 = v85 + v84;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              osif_request_put(v44);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: exit",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "__show_beacon_reception_stats");
            }
            else
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Request allocation failure",
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                "__show_beacon_reception_stats");
              v14 = -12;
            }
            goto LABEL_10;
          }
          v33 = "%s: Adapter is not in connected state";
        }
        else
        {
          v33 = "%s: Interface is not enabled";
        }
      }
      else
      {
        v33 = "%s: Invalid adapter or adapter has invalid magic";
      }
      qdf_trace_msg(0x33u, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "__show_beacon_reception_stats");
      v14 = -22;
    }
LABEL_10:
    _osif_vdev_sync_op_stop((__int64)v94[0], (__int64)"show_beacon_reception_stats");
    goto LABEL_11;
  }
  v14 = v5;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v14;
}
