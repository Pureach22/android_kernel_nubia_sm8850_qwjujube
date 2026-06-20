__int64 __fastcall send_vdev_start_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x23
  __int64 v15; // x19
  unsigned int v16; // w8
  int v17; // w8
  __int16 v18; // w9
  int v19; // w8
  unsigned int v20; // w9
  unsigned int v21; // w8
  unsigned int v22; // w8
  int v23; // w8
  int v24; // w9
  int v25; // w8
  size_t v26; // x2
  int v27; // w8
  int v28; // w3
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w9
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7

  if ( a2[12] )
    v4 = 172;
  else
    v4 = 176;
  v5 = wmi_buf_alloc_fl(a1, v4, "send_vdev_start_cmd_tlv", 0x5A2u);
  if ( !v5 )
    return 2;
  v14 = *(_DWORD **)(v5 + 224);
  v15 = v5;
  *v14 = 5767304;
  v14[35] = 5242904;
  v14[1] = *a2;
  v16 = v14[39] & 0xFFFFFFC0;
  v14[36] = *((_DWORD *)a2 + 21);
  v14[39] = v16;
  v17 = *((_DWORD *)a2 + 23) | v16;
  v14[39] = v17;
  v14[37] = *((_DWORD *)a2 + 24);
  v14[38] = *((_DWORD *)a2 + 25);
  v18 = *((_WORD *)a2 + 44);
  if ( (v18 & 1) != 0 )
  {
    v46 = 0x4000;
  }
  else
  {
    if ( (v18 & 2) == 0 )
    {
      if ( (v18 & 4) == 0 )
        goto LABEL_8;
      goto LABEL_36;
    }
    v46 = 0x8000;
  }
  v17 |= v46;
  v14[39] = v17;
  v18 = *((_WORD *)a2 + 44);
  if ( (v18 & 4) == 0 )
  {
LABEL_8:
    if ( (v18 & 8) == 0 )
      goto LABEL_9;
    goto LABEL_37;
  }
LABEL_36:
  v17 |= 0x400u;
  v14[39] = v17;
  v14[18] = *((_DWORD *)a2 + 4);
  v18 = *((_WORD *)a2 + 44);
  if ( (v18 & 8) == 0 )
  {
LABEL_9:
    if ( (v18 & 0x100) == 0 )
      goto LABEL_11;
    goto LABEL_10;
  }
LABEL_37:
  v17 |= 0x10000u;
  v14[39] = v17;
  if ( (*((_WORD *)a2 + 44) & 0x100) != 0 )
LABEL_10:
    v14[39] = v17 | 0x100000;
LABEL_11:
  v19 = v14[40];
  v20 = v14[41] & 0xFFFFFF00;
  v14[40] = v19 & 0xFFFFFF00;
  v21 = v19 & 0xFFFF0000 | a2[105];
  v14[40] = v21;
  v22 = v21 & 0xFF0000FF | (a2[104] << 8);
  v14[40] = v22;
  v23 = v22 | (a2[107] << 16);
  v14[40] = v23;
  v14[41] = v20;
  v24 = v20 | a2[108];
  v14[40] = v23 & 0xFFFFFF;
  v14[41] = v24;
  v14[40] = v23 & 0xFFFFFF | (a2[109] << 24);
  v14[41] = v24 & 0xFFFF00FF;
  v14[41] = v24 & 0xFFFF00FF | (a2[106] << 8);
  v14[3] = *((_DWORD *)a2 + 1);
  v14[4] = *((_DWORD *)a2 + 2);
  v25 = *((_DWORD *)a2 + 28);
  v14[15] = v25;
  if ( v25 )
    v14[5] |= 4u;
  if ( (a2[12] & 1) == 0 )
  {
    if ( a2[21] == 1 )
      v14[5] |= 2u;
    v14[25] = *((_DWORD *)a2 + 30);
    v14[26] = a2[124];
    v14[29] = a2[125];
    v14[30] = *((_DWORD *)a2 + 32);
  }
  if ( a2[22] )
  {
    if ( a2[22] >= 0x20u )
      v26 = 32;
    else
      v26 = a2[22];
    v14[6] = v26;
    qdf_mem_copy(v14 + 7, a2 + 23, v26);
  }
  v14[5] |= a2[20] | 8;
  v27 = *((_DWORD *)a2 + 14);
  v14[17] = v27;
  v14[20] = *((_DWORD *)a2 + 15);
  v14[19] = *((_DWORD *)a2 + 16);
  v14[22] = *((_DWORD *)a2 + 17);
  v14[23] = *((_DWORD *)a2 + 18);
  v14[21] = *((_DWORD *)a2 + 19);
  if ( a2[12] == 1 )
  {
    v14[31] = *((_DWORD *)a2 + 33);
    v14[32] = *((_DWORD *)a2 + 34);
  }
  v14[42] = (4 * ((5 * (_WORD)v27) & 0x3FFF)) | 0x120000;
  if ( (a2[12] & 1) == 0 )
    *(_QWORD *)&v14[5 * v14[17] + 43] = 0x12000000120000LL;
  qdf_trace_msg(
    0x31u,
    4u,
    "%s: vdev_id %d freq %d chanmode %d ch_info: 0x%x is_dfs %d beacon interval %d dtim %d center_chan %d center_freq2 %d"
    " reg_info_1: 0x%x reg_info_2: 0x%x, req->max_txpow: 0x%x Tx SS %d, Rx SS %d, ldpc_rx: %d, cac %d, regd %d, HE ops: %"
    "dreq->dis_hw_ack: %d target_tsf_us_lo %ul target_tsf_us_hi %ul",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "send_vdev_start_cmd_tlv",
    *a2,
    (unsigned int)v14[36],
    *((unsigned int *)a2 + 23),
    (unsigned int)v14[39],
    (*((unsigned __int16 *)a2 + 44) >> 2) & 1,
    *((_DWORD *)a2 + 1),
    v14[4],
    v14[37],
    v14[38],
    v14[40],
    v14[41],
    (char)a2[106],
    *((_DWORD *)a2 + 16),
    *((_DWORD *)a2 + 15),
    a2[116],
    *((_DWORD *)a2 + 17),
    *((_DWORD *)a2 + 18),
    *((_DWORD *)a2 + 19),
    *((_DWORD *)a2 + 4),
    *((_DWORD *)a2 + 33),
    *((_DWORD *)a2 + 34));
  v28 = v14[1];
  if ( a2[12] == 1 )
  {
    qdf_mtrace(49, 100, 0x284u, v28, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v15,
               v4,
               0x5004u,
               "send_vdev_start_cmd_tlv",
               0x5FEu,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36);
    if ( !(_DWORD)result )
      return result;
  }
  else
  {
    qdf_mtrace(49, 100, 0x283u, v28, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v15,
               v4,
               0x5003u,
               "send_vdev_start_cmd_tlv",
               0x602u,
               v47,
               v48,
               v49,
               v50,
               v51,
               v52,
               v53,
               v54);
    if ( !(_DWORD)result )
      return result;
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Failed to send vdev start command",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "send_vdev_start_cmd_tlv");
  wmi_buf_free();
  return 16;
}
