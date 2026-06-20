__int64 __fastcall wmi_extract_pdev_hw_mode_trans_ind(
        _DWORD *a1,
        _DWORD *a2,
        unsigned int a3,
        _DWORD *a4,
        _DWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  unsigned int v28; // w4
  const char *v29; // x2
  int v30; // w8
  unsigned int v31; // w4
  int v32; // w8
  unsigned int v33; // w4
  int v34; // w8
  unsigned int v35; // w4
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w1

  if ( a1[4] >= 5u )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: Number of Vdev mac entries %d exceeded max vdev supported %d",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "wmi_extract_pdev_hw_mode_trans_ind");
  *a5 = a1[2];
  a5[1] = a1[3];
  a5[2] = a1[4];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: old_hw_mode_index:%d new_hw_mode_index:%d entries=%d num_mac_freq %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "wmi_extract_pdev_hw_mode_trans_ind",
    (unsigned int)a1[2],
    (unsigned int)a1[3]);
  if ( !a2 )
  {
    v29 = "%s: Invalid vdev_mac_entry";
LABEL_31:
    v61 = 2;
    return qdf_trace_msg(0x31u, v61, v29, v19, v20, v21, v22, v23, v24, v25, v26, "wmi_extract_pdev_hw_mode_trans_ind");
  }
  if ( !a1[4] )
    goto LABEL_22;
  v27 = a2[1];
  if ( !v27 )
    goto LABEL_30;
  v28 = a2[2];
  if ( v28 >= 6 )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: vdev_id: %d is invalid, max_bssid: %d",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "wmi_extract_pdev_hw_mode_trans_ind");
  a5[3] = v28;
  a5[4] = v27 - 1;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id:%d mac_id:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wmi_extract_pdev_hw_mode_trans_ind");
  if ( a1[4] <= 1u )
    goto LABEL_22;
  v30 = a2[4];
  if ( !v30 )
    goto LABEL_30;
  v31 = a2[5];
  if ( v31 > 5 )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: vdev_id: %d is invalid, max_bssid: %d",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "wmi_extract_pdev_hw_mode_trans_ind");
  a5[5] = v31;
  a5[6] = v30 - 1;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id:%d mac_id:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wmi_extract_pdev_hw_mode_trans_ind");
  if ( a1[4] < 3u )
    goto LABEL_22;
  v32 = a2[7];
  if ( !v32 )
    goto LABEL_30;
  v33 = a2[8];
  if ( v33 > 5 )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: vdev_id: %d is invalid, max_bssid: %d",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "wmi_extract_pdev_hw_mode_trans_ind");
  a5[7] = v33;
  a5[8] = v32 - 1;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id:%d mac_id:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wmi_extract_pdev_hw_mode_trans_ind");
  if ( a1[4] < 4u )
    goto LABEL_22;
  v34 = a2[10];
  if ( !v34 )
  {
LABEL_30:
    v29 = "%s: soc level id received for mac id";
    goto LABEL_31;
  }
  v35 = a2[11];
  if ( v35 > 5 )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: vdev_id: %d is invalid, max_bssid: %d",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "wmi_extract_pdev_hw_mode_trans_ind");
  a5[9] = v35;
  a5[10] = v34 - 1;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id:%d mac_id:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wmi_extract_pdev_hw_mode_trans_ind");
  if ( a1[4] >= 5u )
  {
    if ( a2[13] )
    {
      if ( a2[14] > 5u )
        return qdf_trace_msg(
                 0x31u,
                 2u,
                 "%s: vdev_id: %d is invalid, max_bssid: %d",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "wmi_extract_pdev_hw_mode_trans_ind");
      __break(0x5512u);
      goto LABEL_22;
    }
    goto LABEL_30;
  }
LABEL_22:
  if ( !a4 )
  {
    v29 = "%s: mac_freq Null";
    v61 = 8;
    return qdf_trace_msg(0x31u, v61, v29, v19, v20, v21, v22, v23, v24, v25, v26, "wmi_extract_pdev_hw_mode_trans_ind");
  }
  result = qdf_trace_msg(
             0x31u,
             8u,
             "%s: num mac freq %d",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "wmi_extract_pdev_hw_mode_trans_ind",
             a3);
  if ( a3 >= 3 )
    v44 = 3;
  else
    v44 = a3;
  a5[11] = v44;
  if ( a3 )
  {
    a5[12] = a4[1] - 1;
    a5[13] = a4[2];
    a5[14] = a4[3];
    result = qdf_trace_msg(
               0x31u,
               8u,
               "%s: mac id %d freq %d %d",
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               "wmi_extract_pdev_hw_mode_trans_ind");
    if ( a3 != 1 )
    {
      a5[15] = a4[5] - 1;
      a5[16] = a4[6];
      a5[17] = a4[7];
      result = qdf_trace_msg(
                 0x31u,
                 8u,
                 "%s: mac id %d freq %d %d",
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 v52,
                 "wmi_extract_pdev_hw_mode_trans_ind");
      if ( a3 != 2 )
      {
        a5[18] = a4[9] - 1;
        a5[19] = a4[10];
        a5[20] = a4[11];
        return qdf_trace_msg(
                 0x31u,
                 8u,
                 "%s: mac id %d freq %d %d",
                 v53,
                 v54,
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 "wmi_extract_pdev_hw_mode_trans_ind");
      }
    }
  }
  return result;
}
