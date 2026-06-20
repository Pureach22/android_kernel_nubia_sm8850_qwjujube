__int64 __fastcall extract_dfs_radar_detection_event_tlv(
        __int64 a1,
        unsigned int **a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned int v24; // w8
  int v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int *v35; // x8

  if ( !a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid radar detection event buf",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_dfs_radar_detection_event_tlv");
    return 16;
  }
  v14 = *a2;
  qdf_mem_set(a3, 0x30u, 0);
  v23 = v14[1];
  if ( (unsigned int)(v23 - 1) > 2 )
  {
    if ( !(_DWORD)v23 )
    {
      v26 = 255;
      goto LABEL_12;
    }
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid pdev_id",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "convert_target_pdev_id_to_host_pdev_id");
    *a3 = -1;
    return 16;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 760) + 7844LL) & 1) == 0 )
  {
    v26 = v23 - 1;
LABEL_12:
    *a3 = v26;
    goto LABEL_13;
  }
  v24 = *(_DWORD *)(*(_QWORD *)(a1 + 864) + 4 * v23 - 4);
  *a3 = v24;
  if ( v24 == -1 )
    return 16;
LABEL_13:
  a3[1] = v14[2];
  a3[8] = v14[3];
  a3[3] = v14[4];
  a3[4] = v14[5];
  a3[5] = v14[6];
  a3[6] = v14[7];
  a3[7] = v14[8];
  a3[2] = v14[9];
  a3[10] = v14[10];
  if ( (is_service_enabled_tlv(a1, 0x186u, v15, v16, v17, v18, v19, v20, v21, v22) & 1) != 0 )
  {
    v35 = a2[2];
    if ( v35 )
    {
      *((_BYTE *)a3 + 44) = v35[1] & 1;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Is full bw nol %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "extract_dfs_radar_detection_event_tlv");
    }
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: processed radar found event pdev %d,Radar Event Info:pdev_id %d,timestamp %d,chan_freq  (dur) %d,chan_width (RSS"
    "I) %d,detector_id (false_radar) %d,freq_offset (radar_check) %d,segment_id %d,sidx %d,is_chirp %d,detection mode %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "extract_dfs_radar_detection_event_tlv",
    v14[1],
    *a3,
    v14[7],
    v14[3],
    v14[4],
    v14[5],
    v14[9],
    v14[6],
    v14[10],
    v14[8],
    v14[2]);
  return 0;
}
