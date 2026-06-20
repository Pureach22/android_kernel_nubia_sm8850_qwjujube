__int64 __fastcall send_tx_power_per_mcs_cmd_tlv(__int64 a1, _DWORD *a2)
{
  int v4; // w23
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
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int64 v65; // x8
  __int64 v66; // x9
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 result; // x0
  unsigned int v76; // w19

  v4 = a2[11] + 3;
  v5 = wmi_buf_alloc_fl(a1, (v4 & 0xFFFFFFFC) + 64, "send_tx_power_per_mcs_cmd_tlv", 0x554u);
  if ( !v5 )
    return 2;
  v14 = *(_DWORD **)(v5 + 224);
  v15 = v5;
  *v14 = 81068088;
  v14[1] = *a2;
  v14[2] = a2[1];
  qdf_trace_msg(0x31u, 8u, "2G_band[chain%d]: %d", v6, v7, v8, v9, v10, v11, v12, v13, 0);
  v14[3] = a2[2];
  qdf_trace_msg(0x31u, 8u, "2G_band[chain%d]: %d", v16, v17, v18, v19, v20, v21, v22, v23, 1);
  v14[6] = a2[3];
  v14[10] = a2[7];
  qdf_trace_msg(0x31u, 8u, "5G_band[chain%d]: %d 6G_band[chain%d]: %d", v24, v25, v26, v27, v28, v29, v30, v31, 0);
  v14[7] = a2[4];
  v14[11] = a2[8];
  qdf_trace_msg(0x31u, 8u, "5G_band[chain%d]: %d 6G_band[chain%d]: %d", v32, v33, v34, v35, v36, v37, v38, v39, 1);
  v14[8] = a2[5];
  v14[12] = a2[9];
  qdf_trace_msg(0x31u, 8u, "5G_band[chain%d]: %d 6G_band[chain%d]: %d", v40, v41, v42, v43, v44, v45, v46, v47, 2);
  v14[9] = a2[6];
  v14[13] = a2[10];
  v56 = qdf_trace_msg(0x31u, 8u, "5G_band[chain%d]: %d 6G_band[chain%d]: %d", v48, v49, v50, v51, v52, v53, v54, v55, 3);
  v65 = (unsigned int)a2[11];
  v14[14] = v65;
  v14[15] = v4 & 0xFFFC | 0x110000;
  if ( (_DWORD)v65 )
  {
    v66 = 0;
    while ( v66 != 244 )
    {
      *((_BYTE *)v14 + v66 + 64) = *((_BYTE *)a2 + v66 + 48);
      if ( ++v66 >= v65 )
        goto LABEL_6;
    }
    __break(0x5512u);
    return send_sar_limit_cmd_tlv(v56);
  }
  else
  {
LABEL_6:
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: txpower array:",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "send_tx_power_per_mcs_cmd_tlv");
    ((void (__fastcall *)(__int64, __int64, _DWORD *, _QWORD))qdf_trace_hex_dump)(49, 8, v14 + 16, (unsigned int)a2[11]);
    wmi_mtrace(0x4055u, 0xFFu, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v15,
               (v4 & 0xFFFFFFFC) + 64,
               0x4055u,
               "send_tx_power_per_mcs_cmd_tlv",
               0x582u,
               v67,
               v68,
               v69,
               v70,
               v71,
               v72,
               v73,
               v74);
    if ( (_DWORD)result )
    {
      v76 = result;
      wmi_buf_free();
      return v76;
    }
  }
  return result;
}
