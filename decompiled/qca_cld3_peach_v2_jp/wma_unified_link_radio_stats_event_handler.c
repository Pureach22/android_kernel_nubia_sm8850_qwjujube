__int64 __fastcall wma_unified_link_radio_stats_event_handler(__int64 *a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 ini_handle; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x27
  unsigned int v31; // w22
  int v32; // w26
  _DWORD *v33; // x28
  unsigned int v34; // w4
  __int64 v35; // x23
  const char *v36; // x2
  unsigned int v37; // w23
  unsigned int v38; // w1
  __int64 v40; // x0
  __int64 v41; // x21
  __int64 v42; // x22
  char v43; // w8
  unsigned int v44; // w8
  int v45; // w8
  int v46; // w9
  void (__fastcall *v47)(__int64, __int64, __int64, __int64); // x8
  __int64 v48; // x0
  __int64 v49; // x3
  unsigned int v50; // w8
  __int64 v51; // x5
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w8
  __int64 v61; // x9
  __int64 v62; // x0
  __int64 v63; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x25
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  char *v83; // x24
  int v84; // w22
  _DWORD *v85; // x25
  int v86; // w8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // w8
  unsigned int v96; // w9
  bool v97; // cf
  unsigned int v98; // w8
  int v99; // w0
  __int64 v100; // x24
  int v101; // w0
  unsigned int v102; // w0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // [xsp+8h] [xbp-38h]
  __int64 v112; // [xsp+10h] [xbp-30h]
  __int64 v113; // [xsp+18h] [xbp-28h]
  __int64 v114; // [xsp+20h] [xbp-20h]
  unsigned int v115; // [xsp+28h] [xbp-18h]
  char *v116; // [xsp+30h] [xbp-10h]
  int v117; // [xsp+38h] [xbp-8h]
  unsigned int v118; // [xsp+3Ch] [xbp-4h]

  qdf_mutex_acquire((__int64)(a1 + 477));
  context = _cds_get_context(
              53,
              (__int64)"__wma_unified_link_radio_stats_event_handler",
              v4,
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11);
  ini_handle = wma_get_ini_handle((__int64)a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !context )
  {
    v36 = "%s: NULL mac ptr. Exiting";
    goto LABEL_16;
  }
  if ( ini_handle )
  {
    if ( context[1619] )
    {
      if ( !a2 )
      {
        v36 = "%s: Invalid stats event";
        goto LABEL_18;
      }
      v30 = *(unsigned int **)a2;
      if ( !*(_QWORD *)a2 )
      {
LABEL_11:
        v36 = "%s: Invalid param_tlvs for Radio Stats";
LABEL_18:
        v38 = 2;
        goto LABEL_19;
      }
      v31 = v30[2];
      v32 = *(unsigned __int8 *)(ini_handle + 1);
      if ( v31 || v30[3] )
      {
        v33 = *(_DWORD **)(a2 + 16);
        if ( !v33 )
          goto LABEL_11;
        v34 = v33[11];
        v35 = *(_QWORD *)(a2 + 32);
        if ( v34 )
        {
          if ( !v35 )
            goto LABEL_11;
        }
        if ( v34 > 0x66 || v34 > *(_DWORD *)(a2 + 40) )
        {
          v36 = "%s: Too many channels %d";
          v38 = 2;
          goto LABEL_19;
        }
        if ( v31 >= 0x3333333 )
        {
          v36 = "%s: excess num_radio %d is leading to int overflow";
          v38 = 2;
          goto LABEL_19;
        }
        if ( v33[1] >= v31 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: invalid radio id:%d, num radio:%d",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "__wma_unified_link_radio_stats_event_handler");
          goto LABEL_20;
        }
        v41 = a1[476];
        if ( v41 && (*(_DWORD *)(v41 + 20) || (_wma_unified_radio_tx_mem_free((__int64)a1), (v41 = a1[476]) != 0))
          || (v41 = _qdf_mem_malloc(80LL * v31 + 28, "__wma_unified_link_radio_stats_event_handler", 2481),
              (a1[476] = v41) != 0) )
        {
          v50 = *(_DWORD *)(v41 + 20);
          v51 = v30[2];
          if ( v50 )
          {
            if ( v50 < (unsigned int)v51 )
            {
              v36 = "%s: Invalid following WMI_RADIO_LINK_STATS_EVENTID. Discarding this set";
              goto LABEL_18;
            }
          }
          else
          {
            *(_DWORD *)(v41 + 20) = v51;
          }
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Radio stats Fixed Param: req_id: %u num_radio: %u more_radio_events: %u more_channels %u",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "__wma_unified_link_radio_stats_event_handler",
            v30[1],
            v51,
            v30[3],
            v30[4]);
          v60 = v33[1];
          v61 = v41 + 80LL * v60;
          v42 = v61 + 28;
          if ( !*(_DWORD *)(v61 + 92) )
          {
            *(_DWORD *)v42 = v60;
            v62 = *(_QWORD *)(v61 + 100);
            *(_DWORD *)(v61 + 32) = v33[2];
            *(_DWORD *)(v61 + 36) = v33[3];
            *(_DWORD *)(v61 + 40) = v33[4];
            *(_DWORD *)(v61 + 44) = v33[5];
            *(_DWORD *)(v61 + 48) = v33[6];
            *(_DWORD *)(v61 + 52) = v33[7];
            *(_DWORD *)(v61 + 56) = v33[8];
            *(_DWORD *)(v61 + 60) = v33[9];
            *(_DWORD *)(v61 + 64) = v33[10];
            *(_DWORD *)(v61 + 68) = v33[76];
            *(_DWORD *)(v61 + 72) = v33[77];
            if ( v62 )
            {
              _qdf_mem_free(v62);
              *(_QWORD *)(v42 + 72) = 0;
            }
          }
          v63 = *(_QWORD *)(v42 + 56);
          *(_DWORD *)(v42 + 48) = 0;
          if ( v63 )
          {
            _qdf_mem_free(v63);
            *(_QWORD *)(v42 + 56) = 0;
          }
          if ( (wmi_service_enabled(*a1, 0xD8u, v52, v53, v54, v55, v56, v57, v58, v59) & 1) == 0 )
            qdf_trace_msg(
              0x36u,
              8u,
              "LL Stats per channel tx time and rx time are not supported.",
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71);
          *(_DWORD *)(v42 + 64) = v30[4];
          v72 = (unsigned int)v33[11];
          if ( !(_DWORD)v72 )
            goto LABEL_28;
          v73 = _qdf_mem_malloc(32 * v72, "__wma_unified_link_radio_stats_event_handler", 2550);
          if ( v73 )
          {
            v112 = v42;
            v113 = v73;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Channel Stats Info, radio id %d, total channels %d",
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              "__wma_unified_link_radio_stats_event_handler",
              (unsigned int)v33[1],
              (unsigned int)v33[11]);
            v82 = _qdf_mem_malloc(0x15Eu, "__wma_unified_link_radio_stats_event_handler", 2560);
            if ( !v82 )
            {
              _qdf_mem_free(v113);
              v37 = -12;
              goto LABEL_21;
            }
            v114 = v82;
            v111 = v72;
            if ( v33[11] )
            {
              v83 = (char *)v113;
              v84 = 0;
              v85 = (_DWORD *)(v35 + 32);
              v86 = 4;
              v118 = 0;
              do
              {
                v115 = v86;
                v116 = v83;
                v117 = v84;
                if ( v32 )
                {
                  v95 = *(v85 - 2);
                  v96 = *(v85 - 1);
                  v97 = v95 >= v96;
                  v98 = v95 - v96;
                  if ( v97 )
                    *(v85 - 2) = v98;
                }
                v87 = scnprintf(
                        v114 + v118,
                        350 - v118,
                        " %d[%d][%d][%d]",
                        *(v85 - 6),
                        *(v85 - 7),
                        *(v85 - 5),
                        *(v85 - 4));
                if ( v99 < 1 )
                  break;
                v100 = v99 + v118;
                v87 = scnprintf(
                        v114 + v100,
                        (unsigned int)(350 - v100),
                        "[%d][%d][%d][%d]",
                        *(v85 - 3),
                        *(v85 - 2),
                        *(v85 - 1),
                        *v85);
                if ( v101 < 1 )
                  goto LABEL_72;
                v118 = v101 + v100;
                if ( (unsigned int)(v101 + v100) >= 0x116 )
                {
                  qdf_trace_msg(
                    0x31u,
                    8u,
                    "freq[width][freq0][freq1][awake time][cca busy time][tx time][rx time] :%s",
                    v87,
                    v88,
                    v89,
                    v90,
                    v91,
                    v92,
                    v93,
                    v94,
                    v114);
                  v118 = 0;
                }
                qdf_mem_copy(v116, (const void *)(v35 + v115), 0x20u);
                ++v84;
                v83 = v116 + 32;
                v85 += 9;
                v86 = v115 + 36;
              }
              while ( (unsigned int)(v117 + 1) < v33[11] );
              if ( !v118 )
                goto LABEL_73;
LABEL_72:
              qdf_trace_msg(
                0x31u,
                8u,
                "freq[width][freq0][freq1][awake time][cca busy time][tx time][rx time] :%s",
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                v94,
                v114);
            }
LABEL_73:
            _qdf_mem_free(v114);
            v42 = v112;
            v102 = wma_copy_chan_stats(v111, v113, v112);
            if ( v102 )
            {
              v37 = v102;
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Failed to copy channel stats",
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                v109,
                v110,
                "__wma_unified_link_radio_stats_event_handler");
              goto LABEL_21;
            }
            goto LABEL_28;
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: FW indicates dummy link radio stats",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "__wma_unified_link_radio_stats_event_handler");
        v40 = a1[476];
        if ( v40
          || (v40 = _qdf_mem_malloc(0x1Cu, "__wma_unified_link_radio_stats_event_handler", 2427), (a1[476] = v40) != 0) )
        {
          wma_unified_link_stats_results_mem_free(v40);
          v41 = a1[476];
          v42 = 0;
          *(_DWORD *)(v41 + 20) = v30[2];
LABEL_28:
          *(_DWORD *)v41 = 1;
          *(_DWORD *)(v41 + 8) = v30[1];
          v43 = v30[5];
          *(_DWORD *)(v41 + 24) = 0;
          *(_BYTE *)(v41 + 4) = v43;
          v44 = v30[3];
          *(_DWORD *)(v41 + 12) = v44;
          if ( v42 )
            v44 |= *(_DWORD *)(v42 + 64);
          if ( !v44 )
          {
            v45 = *(_DWORD *)(v41 + 20);
            if ( !v45 || (v46 = *(_DWORD *)(v41 + 16) + 1, *(_DWORD *)(v41 + 16) = v46, v45 == v46) )
            {
              v47 = (void (__fastcall *)(__int64, __int64, __int64, __int64))context[1619];
              v48 = context[1595];
              v49 = context[1618];
              if ( *((_DWORD *)v47 - 1) != -2006529613 )
                __break(0x8228u);
              v47(v48, 4338, v41, v49);
            }
          }
          goto LABEL_14;
        }
      }
      v37 = -12;
      goto LABEL_21;
    }
    v36 = "%s: HDD callback is null";
LABEL_16:
    v38 = 8;
LABEL_19:
    qdf_trace_msg(
      0x36u,
      v38,
      v36,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "__wma_unified_link_radio_stats_event_handler");
LABEL_20:
    v37 = -22;
    goto LABEL_21;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: NULL WMA ini handle",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "__wma_unified_link_radio_stats_event_handler");
LABEL_14:
  v37 = 0;
LABEL_21:
  qdf_mutex_release((__int64)(a1 + 477));
  return v37;
}
