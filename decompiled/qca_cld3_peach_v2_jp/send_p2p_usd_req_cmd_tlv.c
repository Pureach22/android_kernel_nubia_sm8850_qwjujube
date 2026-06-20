__int64 __fastcall send_p2p_usd_req_cmd_tlv(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w25
  unsigned int v12; // w21
  unsigned int v13; // w24
  unsigned int v14; // w28
  unsigned int v15; // w26
  unsigned int v16; // w23
  _BOOL4 v17; // w27
  unsigned int v18; // w20
  __int64 result; // x0
  __int64 v20; // x0
  unsigned int v21; // w26
  _DWORD *v22; // x28
  __int64 v23; // x22
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
  unsigned int v40; // w4
  unsigned int v41; // w27
  int v42; // w8
  int v43; // w8
  unsigned int *v44; // x25
  int *v45; // x0
  void *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w19
  __int64 v56; // [xsp+0h] [xbp-20h]
  __int16 v57; // [xsp+10h] [xbp-10h]
  unsigned int v58; // [xsp+14h] [xbp-Ch]

  if ( !a2 )
  {
    qdf_trace_msg(0x31u, 2u, "%s: lo start param is null", a3, a4, a5, a6, a7, a8, a9, a10, "send_p2p_usd_req_cmd_tlv");
    return 4;
  }
  v10 = a2[1];
  if ( v10 > 5 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid OP type %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wmi_p2p_op_type_convert_p2p_enum_to_wmi_enum",
      v10);
    return 4;
  }
  if ( ((1 << v10) & 0x31) != 0 )
  {
    v12 = 0;
    v13 = 0;
    v14 = 0;
    LOWORD(v15) = 0;
    v58 = 0;
    v16 = 0;
    v17 = v10 - 1 < 2;
    v18 = 52;
  }
  else if ( ((1 << v10) & 6) != 0 )
  {
    v16 = a2[16];
    v14 = a2[10];
    v17 = 1;
    v13 = (v16 + 3) & 0xFFFFFFFC;
    v15 = (v14 + 3) & 0xFFFFFFFC;
    v12 = (a2[20] + 3) & 0xFFFFFFFC;
    v58 = a2[20];
    v18 = v13 + v15 + v12 + 64;
  }
  else
  {
    v14 = a2[10];
    v17 = 0;
    v12 = 0;
    v13 = 0;
    v16 = 0;
    v58 = 0;
    v15 = (v14 + 3) & 0xFFFFFFFC;
    v18 = v15 + 56;
  }
  v20 = wmi_buf_alloc_fl(a1, v18, "send_p2p_usd_req_cmd_tlv", 0x286u);
  if ( !v20 )
    return 2;
  v57 = v15;
  v21 = v14;
  v22 = *(_DWORD **)(v20 + 224);
  v23 = v20;
  qdf_mem_set(v22, 0x34u, 0);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev: %d len %d, num_chan_len %d, num_channel_aligned %d sdf_len_aligned %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "send_p2p_usd_req_cmd_tlv",
    *a2,
    v18,
    v16,
    v13,
    v12);
  *v22 = 82116656;
  v22[1] = *a2;
  v22[2] = v10;
  v22[6] = *((unsigned __int8 *)a2 + 14);
  if ( v17 )
  {
    v40 = a2[6];
    if ( v40 - 1 < 3 )
    {
      v22[10] = v40;
      v41 = v21;
      v42 = *((unsigned __int16 *)a2 + 44);
      v22[3] = v58;
      v22[8] = v21;
      v22[9] = v42;
      v22[7] = a2[12];
      v22[11] = a2[2];
      v22[12] = *((unsigned __int16 *)a2 + 6);
      v22[4] = **((_DWORD **)a2 + 2);
      v43 = *(unsigned __int16 *)(*((_QWORD *)a2 + 2) + 4LL);
      v22[13] = v12 & 0xFFFC | 0x110000;
      v22[5] = v43;
      qdf_mem_copy(v22 + 14, *((const void **)a2 + 9), v58);
      v44 = (_DWORD *)((char *)v22 + v12 + 56);
      *v44++ = v13 & 0xFFFC | 0x100000;
      qdf_mem_copy(v44, *((const void **)a2 + 7), v16);
      v45 = (int *)((char *)v44 + v13);
      *v45 = v57 & 0xFFFC | 0x110000;
      v46 = v45 + 1;
      goto LABEL_17;
    }
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid service protocol type %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wmi_p2p_service_protocol_type_convert_p2p_enum_to_wmi_enum");
    wmi_buf_free();
    return 4;
  }
  if ( v10 != 3 )
    goto LABEL_18;
  v46 = v22 + 14;
  v41 = v21;
  v22[13] = v57 & 0xFFFC | 0x110000;
LABEL_17:
  qdf_mem_copy(v46, *((const void **)a2 + 4), v41);
LABEL_18:
  LODWORD(v56) = v22[3];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Sending USD req: vdev %d, usd_mode %d, ttl %d, freq %d sdf_len %d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "send_p2p_usd_req_cmd_tlv",
    (unsigned int)v22[1],
    (unsigned int)v22[2],
    (unsigned int)v22[9],
    (unsigned int)v22[7],
    v56);
  v47 = wmi_mtrace(118824, (unsigned int)v22[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v23,
             v18,
             0x1D028u,
             "send_p2p_usd_req_cmd_tlv",
             0x2D1u,
             v47,
             v48,
             v49,
             v50,
             v51,
             v52,
             v53,
             v54);
  if ( (_DWORD)result )
  {
    v55 = result;
    wmi_buf_free();
    return v55;
  }
  return result;
}
