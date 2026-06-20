__int64 __fastcall hdd_sysfs_bmiss_show(__int64 a1, __int64 a2, __int64 a3)
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 infra_cp_stats; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x20
  int v61; // w0
  __int64 v62; // x25
  __int64 v63; // x26
  __int64 v64; // x22
  int v65; // w0
  __int64 v66; // x25
  int v67; // w0
  __int64 v68; // x20
  _DWORD *v69; // x8
  int v70; // w0
  __int64 *v71; // [xsp+30h] [xbp-20h] BYREF
  __int64 v72; // [xsp+3Ch] [xbp-14h] BYREF
  __int16 v73; // [xsp+44h] [xbp-Ch]
  __int64 v74; // [xsp+48h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, &v71, (__int64)"hdd_sysfs_bmiss_show");
  if ( !v5 )
  {
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_bmiss_show",
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13) )
      goto LABEL_4;
    v23 = *(_QWORD *)(a1 + 1336);
    v24 = _wlan_hdd_validate_context(v23, (__int64)"__hdd_sysfs_bmiss_show", v15, v16, v17, v18, v19, v20, v21, v22);
    if ( v24 )
    {
      v14 = v24;
      goto LABEL_7;
    }
    if ( !wlan_hdd_validate_modules_state(v23, v25, v26, v27, v28, v29, v30, v31, v32) )
    {
LABEL_4:
      v14 = -22;
    }
    else
    {
      v73 = 0;
      v42 = *(_QWORD *)(a1 + 54144);
      v72 = 0;
      if ( v42 == -80 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: hdd_sta_ctx received NULL",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wlan_hdd_get_bmiss");
      }
      else
      {
        qdf_mem_copy((char *)&v72 + 4, (const void *)(v42 + 308), 6u);
        infra_cp_stats = wlan_cfg80211_mc_bmiss_get_infra_cp_stats(
                           *(_QWORD *)(*(_QWORD *)(a1 + 54144) + 32LL),
                           (char *)&v72 + 4,
                           (int *)&v72,
                           v43,
                           v44,
                           v45,
                           v46,
                           v47,
                           v48,
                           v49,
                           v50);
        if ( infra_cp_stats )
        {
          v60 = infra_cp_stats;
          scnprintf(a3, 4096, "num_pre_bmiss:%u\n", *(_DWORD *)(*(_QWORD *)(infra_cp_stats + 24) + 8LL));
          v62 = v61;
          if ( v61 < 1 )
          {
            v14 = v61;
          }
          else
          {
            v63 = 0;
            v64 = 0;
            v14 = 4096;
            while ( v62 != 4096 )
            {
              scnprintf(
                a3 + v62,
                4096 - v62,
                "rssi_sample%d-rssi:%d\n",
                v64,
                *(_DWORD *)(*(_QWORD *)(v60 + 24) + v63 + 12));
              v66 = v62 + v65;
              if ( v66 == 4096 )
                break;
              scnprintf(
                a3 + v66,
                4096 - v66,
                "rssi_sample%d-sample_time:%u\n",
                v64++,
                *(_DWORD *)(*(_QWORD *)(v60 + 24) + v63 + 16));
              v62 = v66 + v67;
              v63 += 8;
              if ( v64 == 10 )
              {
                if ( v62 == 4096 )
                {
                  v14 = 4096;
                }
                else
                {
                  v69 = *(_DWORD **)(v60 + 24);
                  scnprintf(
                    a3 + v62,
                    4096 - v62,
                    "rssi_sample_curr_index:%u\n"
                    "num_first_bmiss:%u\n"
                    "num_final_bmiss:%u\n"
                    "num_null_sent_in_first_bmiss:%u\n"
                    "num_null_failed_in_first_bmiss:%u\n"
                    "num_null_sent_in_final_bmiss:%u\n"
                    "num_null_failed_in_final_bmiss:%u\n"
                    "cons_bmiss_stats.num_of_bmiss_sequences:%u\n"
                    "cons_bmiss_stats.num_bitmask_wraparound:%u\n"
                    "cons_bmiss_stats.num_bcn_hist_lost:%u\n",
                    v69[23],
                    v69[24],
                    v69[25],
                    v69[26],
                    v69[27],
                    v69[28],
                    v69[29],
                    v69[30],
                    v69[31],
                    v69[32]);
                  v14 = v62 + v70;
                  _qdf_mem_free(*(_QWORD *)(v60 + 24));
                  _qdf_mem_free(v60);
                }
                goto LABEL_7;
              }
            }
          }
          goto LABEL_7;
        }
      }
      v68 = jiffies;
      if ( _hdd_sysfs_bmiss_show___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: GET_BMISS failed",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "__hdd_sysfs_bmiss_show");
        v14 = 0;
        _hdd_sysfs_bmiss_show___last_ticks = v68;
      }
      else
      {
        v14 = 0;
      }
    }
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v71, (__int64)"hdd_sysfs_bmiss_show");
    goto LABEL_8;
  }
  v14 = v5;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v14;
}
