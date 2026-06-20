__int64 __fastcall send_plm_start_cmd_tlv(__int64 a1, unsigned __int16 *a2)
{
  int v4; // w24
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x25
  __int64 v15; // x19
  int v16; // w8
  int v17; // w9
  int v18; // w10
  int v19; // w11
  int v20; // w12
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w8
  __int64 v31; // x22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0

  v4 = 4 * *((unsigned __int8 *)a2 + 18);
  v5 = wmi_buf_alloc_fl(a1, v4 + 52, "send_plm_start_cmd_tlv", 0x2D0u);
  if ( !v5 )
    return 2;
  v14 = *(_DWORD **)(v5 + 224);
  v15 = v5;
  *v14 = 15859756;
  v14[1] = *((unsigned __int8 *)a2 + 420);
  v14[2] = a2[1];
  v14[3] = *a2;
  v14[4] = a2[2];
  v16 = 1000 * a2[3];
  v14[5] = v16;
  v17 = a2[4];
  v14[8] = v17;
  v18 = *((unsigned __int8 *)a2 + 10);
  v14[6] = v18;
  v19 = *((char *)a2 + 11);
  v14[7] = v19;
  v14[9] = *((_DWORD *)a2 + 3);
  v14[10] = a2[8];
  v20 = *((unsigned __int8 *)a2 + 18);
  v14[11] = v20;
  v21 = qdf_trace_msg(
          0x31u,
          8u,
          "%s: vdev: %d measu token: %d dialog_token: %d number_bursts: %d burst_interval: %d off_duration: %d burst_cycl"
          "e: %d tx_power: %d Number of channels: %d",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "send_plm_start_cmd_tlv",
          v16,
          v17,
          v18,
          v19,
          v20);
  v30 = v14[11];
  v14[12] = (4 * (v30 & 0x3FFF)) | 0x100000;
  if ( v30 )
  {
    v31 = 0;
    while ( v31 != 100 )
    {
      v14[v31 + 13] = *(_DWORD *)&a2[2 * v31 + 10];
      v21 = qdf_trace_msg(
              0x31u,
              8u,
              "%s: Ch[%d]: %d MHz",
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              "send_plm_start_cmd_tlv",
              (unsigned int)v31++);
      if ( v14[11] <= (unsigned int)v31 )
        goto LABEL_6;
    }
    __break(0x5512u);
    v49 = MEMORY[0xFFFFFFFFFAE7B688](v21);
    return wmi_get_host_roam_frame_tx_status(v49);
  }
  else
  {
LABEL_6:
    wmi_mtrace(0x5010u, v14[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v15,
               v4 + 52,
               0x5010u,
               "send_plm_start_cmd_tlv",
               0x2FFu,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send plm start wmi cmd",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "send_plm_start_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
  }
  return result;
}
