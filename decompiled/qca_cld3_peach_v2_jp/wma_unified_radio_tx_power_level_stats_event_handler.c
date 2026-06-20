__int64 __fastcall wma_unified_radio_tx_power_level_stats_event_handler(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x22
  _DWORD *v22; // x20
  unsigned int v23; // w4
  unsigned int v24; // w4
  __int64 v25; // x8
  const char *v26; // x2
  unsigned int v27; // w1
  unsigned int v28; // w20
  const void *v30; // x1
  _DWORD *v31; // x23
  unsigned int v32; // w5
  unsigned int v33; // w4
  unsigned int v34; // w6
  _QWORD *v35; // x21
  __int64 v36; // x0
  const void *v37; // x24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x5
  __int64 v47; // x6
  int v48; // w9
  int v49; // w8
  int v50; // w8
  int v51; // w8
  _DWORD *v52; // x9
  __int64 v53; // x3
  __int64 v54; // x0

  qdf_mutex_acquire(a1 + 3816);
  context = _cds_get_context(
              53,
              (__int64)"__wma_unified_radio_tx_power_level_stats_event_handler",
              v4,
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11);
  if ( !context )
  {
    v26 = "%s: NULL mac ptr. Exiting";
LABEL_13:
    v27 = 8;
LABEL_18:
    qdf_trace_msg(
      0x36u,
      v27,
      v26,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "__wma_unified_radio_tx_power_level_stats_event_handler");
    goto LABEL_19;
  }
  if ( !context[1619] )
  {
    v26 = "%s: HDD callback is null";
    goto LABEL_13;
  }
  if ( !a2 )
  {
    v26 = "%s: Invalid tx power level stats event";
LABEL_17:
    v27 = 2;
    goto LABEL_18;
  }
  v21 = *(unsigned int **)a2;
  if ( !*(_QWORD *)a2 )
  {
    v26 = "%s: Invalid param_tlvs for Radio tx_power level Stats";
    goto LABEL_17;
  }
  v22 = *(_DWORD **)(a1 + 3808);
  if ( !v22 )
  {
    v26 = "%s: link_stats_results is NULL";
    goto LABEL_17;
  }
  v23 = v21[2];
  if ( v23 > 0x17A || v23 > *(_DWORD *)(a2 + 24) )
  {
    v26 = "%s: excess tx_power buffers:%d, num_tx_time_per_power_level:%d";
    v27 = 2;
    goto LABEL_18;
  }
  v24 = v21[4];
  if ( v24 >= v22[5] )
  {
    v26 = "%s: Invalid radio_id %d num_radio %d";
    v27 = 2;
    goto LABEL_18;
  }
  v25 = v21[1];
  if ( (unsigned int)v25 < 0x401 )
  {
    v30 = *(const void **)(a2 + 16);
    v31 = &v22[20 * v24];
    v32 = v31[19];
    if ( v32 && (unsigned int)v25 > v32 )
    {
      v26 = "%s: excess tx_power buffers:%d, total_num_tx_power_levels:%d";
      v27 = 2;
      goto LABEL_18;
    }
    v31[19] = v25;
    if ( !(_DWORD)v25 )
    {
      v50 = v22[4] + 1;
      v22[4] = v50;
      goto LABEL_41;
    }
    v34 = v21[2];
    v33 = v21[3];
    if ( (unsigned int)v25 < v33 || v34 > (unsigned int)v25 - v33 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Invalid offset %d total_num %d num %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "__wma_unified_radio_tx_power_level_stats_event_handler");
      goto LABEL_19;
    }
    v35 = context;
    v36 = *(_QWORD *)(v31 + 21);
    if ( !v36 )
    {
      v37 = v30;
      v36 = _qdf_mem_malloc(4 * v25, "__wma_unified_radio_tx_power_level_stats_event_handler", 2232);
      *(_QWORD *)(v31 + 21) = v36;
      if ( !v36 )
      {
        v51 = v22[4];
        v31[19] = 0;
        v50 = v51 + 1;
        v22[4] = v50;
LABEL_40:
        context = v35;
LABEL_41:
        if ( v22[5] == v50 )
        {
          v52 = (_DWORD *)context[1619];
          v53 = context[1618];
          v54 = context[1595];
          if ( *(v52 - 1) != -2006529613 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v52)(v54, 4338, v22, v53);
        }
        goto LABEL_45;
      }
      v34 = v21[2];
      v33 = v21[3];
      v30 = v37;
    }
    qdf_mem_copy((void *)(v36 + 4LL * v33), v30, 4 * v34);
    v46 = v21[2];
    v47 = v21[3];
    if ( v31[19] == (_DWORD)v47 + (_DWORD)v46 )
    {
      v48 = 0;
      v49 = v22[4] + 1;
      v22[3] = 0;
      v22[4] = v49;
      v46 = v21[2];
      v47 = v21[3];
    }
    else
    {
      v48 = v22[3];
      v49 = v22[4];
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: num tx pwr lvls %u num tx pwr lvls %u pwr lvl offset %u radio_id %u moretofollow: %u nr_received: %u",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "__wma_unified_radio_tx_power_level_stats_event_handler",
      v21[1],
      v46,
      v47,
      v21[4],
      v48,
      v49);
    if ( v22[3] )
    {
LABEL_45:
      v28 = 0;
      goto LABEL_20;
    }
    v50 = v22[4];
    goto LABEL_40;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Invalid total_num_tx_power_levels %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "__wma_unified_radio_tx_power_level_stats_event_handler",
    (unsigned int)v25);
LABEL_19:
  v28 = -22;
LABEL_20:
  qdf_mutex_release(a1 + 3816);
  return v28;
}
