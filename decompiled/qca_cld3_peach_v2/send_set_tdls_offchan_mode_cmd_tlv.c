__int64 __fastcall send_set_tdls_offchan_mode_cmd_tlv(__int64 a1, __int64 a2)
{
  unsigned __int16 v3; // w22
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x26
  __int64 v15; // x19
  int v16; // w8
  unsigned int v17; // w4
  int v18; // w8
  __int64 v19; // x4
  __int64 v20; // x5
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  unsigned __int64 v30; // x22
  unsigned int *v31; // x27
  _BYTE *v32; // x28
  unsigned int v33; // w8
  unsigned int v34; // w9
  __int64 v35; // x5
  unsigned int v36; // w8
  __int64 v37; // x6
  unsigned int v38; // t1
  unsigned int v39; // w0
  unsigned int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 result; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int16 v66; // [xsp+1Ch] [xbp-4h]

  v3 = 28 * *(_WORD *)(a2 + 20) + 44;
  v5 = wmi_buf_alloc_fl(a1, v3 & 0xFFFC, "send_set_tdls_offchan_mode_cmd_tlv", 0x266u);
  if ( !v5 )
    return 16;
  v14 = *(_DWORD **)(v5 + 224);
  v15 = v5;
  *v14 = 23003172;
  v14[3] = *(_DWORD *)(a2 + 4);
  v14[4] = *(unsigned __int16 *)(a2 + 8);
  v14[1] = *(_DWORD *)a2;
  if ( (unsigned int)*(unsigned __int8 *)(a2 + 12) - 1 >= 3 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: unknown tdls_sw_mode: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "tdls_get_wmi_offchannel_mode");
    v16 = 1;
  }
  else
  {
    v16 = (unsigned __int8)(*(_BYTE *)(a2 + 12) - 1);
  }
  v14[2] = v16;
  v66 = v3;
  v14[5] = *(unsigned __int8 *)(a2 + 14);
  v14[9] = *(_DWORD *)(a2 + 16);
  v14[6] = *(unsigned __int8 *)(a2 + 11);
  v17 = *(unsigned __int8 *)(a2 + 10);
  if ( v17 < 6 && ((0x3Bu >> v17) & 1) != 0 )
  {
    v18 = dword_B34388[*(unsigned __int8 *)(a2 + 10)];
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: unknown tdls offchannel bw offset: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "tdls_get_wmi_offchannel_bw");
    v18 = 1;
  }
  v14[7] = v18;
  v19 = (unsigned int)v14[3];
  v20 = (unsigned int)v14[4];
  v14[8] = *(unsigned __int8 *)(a2 + 13);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Peer MAC Addr mac_addr31to0: 0x%x, mac_addr47to32: 0x%x",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "send_set_tdls_offchan_mode_cmd_tlv",
    v19,
    v20);
  v29 = qdf_trace_msg(
          0x31u,
          8u,
          "%s: vdev_id: %d, off channel mode: %d, off channel Num: %d, off channel frequency: %u off channel offset: 0x%x"
          ", is_peer_responder: %d, operating class: %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "send_set_tdls_offchan_mode_cmd_tlv",
          (unsigned int)v14[1],
          (unsigned int)v14[2],
          (unsigned int)v14[6],
          (unsigned int)v14[9],
          v14[7],
          v14[5],
          v14[8]);
  v14[10] = (unsigned __int16)(28 * *(_WORD *)(a2 + 20)) | 0x120000;
  if ( !*(_WORD *)(a2 + 20) )
  {
LABEL_15:
    wmi_mtrace(0x20003u, v14[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v15,
               v66 & 0xFFFC,
               0x20003u,
               "send_set_tdls_offchan_mode_cmd_tlv",
               0x2B1u,
               v49,
               v50,
               v51,
               v52,
               v53,
               v54,
               v55,
               v56);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: failed to send tdls off chan command",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "send_set_tdls_offchan_mode_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  v30 = 0;
  v31 = v14 + 15;
  v32 = (_BYTE *)(a2 + 29);
  while ( 1 )
  {
    *(v31 - 4) = 5242904;
    if ( v30 == 129 )
      break;
    v39 = *(_DWORD *)(v32 - 5);
    *((_QWORD *)v31 - 1) = v39;
    *(v31 - 3) = v39;
    v40 = *v31 & 0xFFFFFFC0 | wlan_reg_is_24ghz_ch_freq(v39);
    *v31 = v40;
    if ( *v32 == 1 )
      *v31 = v40 | 0x80;
    v34 = v31[1];
    v33 = v31[2];
    v35 = *(v31 - 3);
    v31[2] = v33 & 0xFFFF00FF;
    v36 = v33 & 0xFFFF00FF | ((unsigned __int8)*(v32 - 1) << 8);
    v31[1] = v34 & 0xFF00FFFF;
    v31[2] = v36;
    v31[1] = v34 & 0xFF00FFFF | ((unsigned __int8)*(v32 - 1) << 16);
    v37 = (unsigned __int8)*(v32 - 1);
    v38 = (unsigned __int8)*v32;
    v32 += 8;
    v29 = qdf_trace_msg(
            0x31u,
            8u,
            "%s: chan[%d] = %u TX power:%d DFS[%d]",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "send_set_tdls_offchan_mode_cmd_tlv",
            (unsigned int)v30++,
            v35,
            v37,
            v38);
    v31 += 7;
    if ( v30 >= *(unsigned __int16 *)(a2 + 20) )
      goto LABEL_15;
  }
  __break(0x5512u);
  atomic_load_explicit((atomic_ullong *volatile)((char *)&loc_4FFF78 + 3), memory_order_acquire);
  return send_update_fw_tdls_state_cmd_tlv(v29);
}
