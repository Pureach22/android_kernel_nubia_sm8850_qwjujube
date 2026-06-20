__int64 __fastcall send_update_tdls_peer_state_cmd_tlv(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v5; // w20
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  __int64 v17; // x19
  int v18; // w8
  int v19; // w9
  int v20; // w10
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  char v29; // w8
  int v30; // w9
  int v31; // w8
  int v32; // w14
  int v33; // w9
  __int64 v34; // x4
  __int64 v35; // x5
  int v36; // w10
  __int64 v37; // x6
  __int64 v38; // x7
  int v39; // w12
  int v40; // w13
  int v41; // w11
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned __int64 v58; // x24
  unsigned __int8 *v59; // x21
  unsigned int *v60; // x19
  unsigned int v61; // w8
  unsigned int v62; // w10
  unsigned int v63; // w9
  unsigned int v64; // w8
  unsigned int v65; // w5
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 result; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // [xsp+0h] [xbp-50h]
  __int64 v92; // [xsp+8h] [xbp-48h]
  __int64 v93; // [xsp+10h] [xbp-40h]
  __int64 v94; // [xsp+18h] [xbp-38h]
  __int64 v95; // [xsp+38h] [xbp-18h]
  unsigned int v96; // [xsp+44h] [xbp-Ch]
  __int64 v97; // [xsp+48h] [xbp-8h]

  v5 = 28 * *(unsigned __int8 *)(a2 + 23) + 116;
  v7 = wmi_buf_alloc_fl(a1, v5, "send_update_tdls_peer_state_cmd_tlv", 0x332u);
  if ( !v7 )
    return 16;
  v96 = v5;
  v16 = *(_QWORD *)(v7 + 224);
  v17 = v7;
  *(_DWORD *)v16 = 13172764;
  *(_DWORD *)(v16 + 4) = *(_DWORD *)a2;
  v18 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v16 + 8) = v18;
  v19 = *(unsigned __int16 *)(a2 + 8);
  *(_DWORD *)(v16 + 12) = v19;
  v20 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v16 + 16) = v20;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id: %d, peermac: %02x:%02x:%02x:**:**:%02x, peer_macaddr.mac_addr31to0: 0x%x, peer_macaddr.mac_addr47to32: "
    "0x%x, peer_state: %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "send_update_tdls_peer_state_cmd_tlv",
    *(unsigned __int8 *)(a2 + 9),
    v18,
    v19,
    v20);
  *(_DWORD *)(v16 + 32) = 13303884;
  v29 = *(_BYTE *)(a2 + 17);
  if ( (v29 & 8) != 0 )
  {
    *(_DWORD *)(v16 + 36) |= 1u;
    v29 = *(_BYTE *)(a2 + 17);
  }
  if ( (v29 & 4) != 0 )
  {
    *(_DWORD *)(v16 + 36) |= 2u;
    v29 = *(_BYTE *)(a2 + 17);
  }
  v95 = a1;
  v97 = v17;
  if ( (v29 & 2) != 0 )
  {
    *(_DWORD *)(v16 + 36) |= 4u;
    v29 = *(_BYTE *)(a2 + 17);
  }
  v30 = *(_DWORD *)(v16 + 36);
  if ( (v29 & 1) != 0 )
  {
    v30 |= 8u;
    *(_DWORD *)(v16 + 36) = v30;
  }
  *(_DWORD *)(v16 + 36) = v30 | (32 * (*(_BYTE *)(a2 + 18) & 3));
  *(_DWORD *)(v16 + 40) = *(unsigned __int8 *)(a2 + 19);
  *(_DWORD *)(v16 + 44) = *(unsigned __int8 *)(a2 + 20);
  *(_DWORD *)(v16 + 48) = *(unsigned __int8 *)(a2 + 21);
  *(_DWORD *)(v16 + 52) = *(unsigned __int8 *)(a2 + 1083);
  *(_DWORD *)(v16 + 56) = *(unsigned __int8 *)(a2 + 23);
  *(_DWORD *)(v16 + 60) = *(unsigned __int8 *)(a2 + 1048);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: peer_operclass_len: %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "send_update_tdls_peer_state_cmd_tlv");
  *(_BYTE *)(v16 + 64) = *(_BYTE *)(a2 + 1049);
  *(_BYTE *)(v16 + 65) = *(_BYTE *)(a2 + 1050);
  *(_BYTE *)(v16 + 66) = *(_BYTE *)(a2 + 1051);
  *(_BYTE *)(v16 + 67) = *(_BYTE *)(a2 + 1052);
  *(_BYTE *)(v16 + 68) = *(_BYTE *)(a2 + 1053);
  *(_BYTE *)(v16 + 69) = *(_BYTE *)(a2 + 1054);
  *(_BYTE *)(v16 + 70) = *(_BYTE *)(a2 + 1055);
  *(_BYTE *)(v16 + 71) = *(_BYTE *)(a2 + 1056);
  *(_BYTE *)(v16 + 72) = *(_BYTE *)(a2 + 1057);
  *(_BYTE *)(v16 + 73) = *(_BYTE *)(a2 + 1058);
  *(_BYTE *)(v16 + 74) = *(_BYTE *)(a2 + 1059);
  *(_BYTE *)(v16 + 75) = *(_BYTE *)(a2 + 1060);
  *(_BYTE *)(v16 + 76) = *(_BYTE *)(a2 + 1061);
  *(_BYTE *)(v16 + 77) = *(_BYTE *)(a2 + 1062);
  *(_BYTE *)(v16 + 78) = *(_BYTE *)(a2 + 1063);
  *(_BYTE *)(v16 + 79) = *(_BYTE *)(a2 + 1064);
  *(_BYTE *)(v16 + 80) = *(_BYTE *)(a2 + 1065);
  *(_BYTE *)(v16 + 81) = *(_BYTE *)(a2 + 1066);
  *(_BYTE *)(v16 + 82) = *(_BYTE *)(a2 + 1067);
  *(_BYTE *)(v16 + 83) = *(_BYTE *)(a2 + 1068);
  *(_BYTE *)(v16 + 84) = *(_BYTE *)(a2 + 1069);
  *(_BYTE *)(v16 + 85) = *(_BYTE *)(a2 + 1070);
  *(_BYTE *)(v16 + 86) = *(_BYTE *)(a2 + 1071);
  *(_BYTE *)(v16 + 87) = *(_BYTE *)(a2 + 1072);
  *(_BYTE *)(v16 + 88) = *(_BYTE *)(a2 + 1073);
  *(_BYTE *)(v16 + 89) = *(_BYTE *)(a2 + 1074);
  *(_BYTE *)(v16 + 90) = *(_BYTE *)(a2 + 1075);
  *(_BYTE *)(v16 + 91) = *(_BYTE *)(a2 + 1076);
  *(_BYTE *)(v16 + 92) = *(_BYTE *)(a2 + 1077);
  *(_BYTE *)(v16 + 93) = *(_BYTE *)(a2 + 1078);
  *(_BYTE *)(v16 + 94) = *(_BYTE *)(a2 + 1079);
  *(_BYTE *)(v16 + 95) = *(_BYTE *)(a2 + 1080);
  ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(49, 8, v16 + 64, 32);
  v31 = *(unsigned __int8 *)(a2 + 16);
  v32 = *(_DWORD *)(v16 + 60);
  *(_DWORD *)(v16 + 96) = v31;
  v33 = *(_DWORD *)(a2 + 1084);
  v34 = *(unsigned int *)(v16 + 36);
  v35 = *(unsigned int *)(v16 + 40);
  *(_DWORD *)(v16 + 108) = v33;
  v36 = *(unsigned __int8 *)(a2 + 1081);
  v37 = *(unsigned int *)(v16 + 44);
  v38 = *(unsigned int *)(v16 + 48);
  *(_DWORD *)(v16 + 100) = v36;
  v39 = *(_DWORD *)(v16 + 52);
  v40 = *(_DWORD *)(v16 + 56);
  v41 = *(unsigned __int8 *)(a2 + 1082);
  *(_DWORD *)(v16 + 104) = v41;
  LODWORD(v94) = v31;
  LODWORD(v93) = v32;
  LODWORD(v92) = v40;
  LODWORD(v91) = v39;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: peer_qos: 0x%x, buff_sta_support: %d, off_chan_support: %d, peer_curr_operclass: %d, self_curr_operclass: %d, pe"
    "er_chan_len: %d, peer_operclass_len: %d, is_peer_responder: %d, pref_offchan_num: %d, pref_offchan_bw: %d, pref_offchan_freq: %u",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "send_update_tdls_peer_state_cmd_tlv",
    v34,
    v35,
    v37,
    v38,
    v91,
    v92,
    v93,
    v94,
    v36,
    v41,
    v33);
  *(_DWORD *)(v16 + 112) = (28 * *(unsigned __int8 *)(a2 + 23)) | 0x120000;
  if ( *(_BYTE *)(a2 + 23) )
  {
    v58 = 0;
    v59 = (unsigned __int8 *)(a2 + 29);
    v60 = (unsigned int *)(v16 + 132);
    do
    {
      *(v60 - 4) = 5242904;
      v65 = *(_DWORD *)(a3 + 4 * v58);
      *((_QWORD *)v60 - 1) = v65;
      *(v60 - 3) = v65;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: chan[%d] = %u",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "send_update_tdls_peer_state_cmd_tlv",
        (unsigned int)v58);
      if ( *v59 == 1 )
      {
        *v60 |= 0x80u;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: chan_freq[%d] DFS[%d]",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "send_update_tdls_peer_state_cmd_tlv",
          *(unsigned int *)(v59 - 5),
          *v59);
      }
      v62 = v60[1];
      v61 = v60[2];
      v63 = *v60 & 0xFFFFFFC0;
      if ( *(v60 - 3) < 0xBB8 )
        ++v63;
      *v60 = v63;
      v60[2] = v61 & 0xFFFF00FF;
      v64 = v61 & 0xFFFF00FF | (*(v59 - 1) << 8);
      v60[1] = v62 & 0xFF00FFFF;
      v60[2] = v64;
      v60[1] = v62 & 0xFF00FFFF | (*(v59 - 1) << 16);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Channel TX power[%d] = %u: %d",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "send_update_tdls_peer_state_cmd_tlv",
        (unsigned int)v58++);
      v59 += 8;
      v60 += 7;
    }
    while ( v58 < *(unsigned __int8 *)(a2 + 23) );
  }
  wmi_mtrace(0x20002u, *(_DWORD *)(v16 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             v95,
             v97,
             v96,
             0x20002u,
             "send_update_tdls_peer_state_cmd_tlv",
             0x3ADu,
             v74,
             v75,
             v76,
             v77,
             v78,
             v79,
             v80,
             v81);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send tdls peer update state command",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "send_update_tdls_peer_state_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
