__int64 __fastcall sme_rrm_process_beacon_report_req_ind(_QWORD *a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  unsigned __int8 *v5; // x24
  unsigned __int16 *v6; // x23
  unsigned int session_id_from_bssid; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w9
  unsigned __int8 v35; // w1
  unsigned int v36; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  unsigned int v47; // w8
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _DWORD *v57; // x21
  unsigned int v58; // w22
  unsigned int v59; // w25
  __int64 v60; // x0
  unsigned int v61; // w8
  __int64 v62; // x0
  unsigned __int8 v63; // w22
  __int64 v64; // x25
  __int64 v65; // x21
  unsigned int v66; // w26
  int *v67; // x27
  unsigned int v68; // w8
  unsigned int v69; // w22
  unsigned int v70; // w22
  unsigned int v71; // w22
  unsigned int v72; // w22
  unsigned int v73; // w22
  unsigned int v74; // w22
  unsigned int v75; // w22
  unsigned int v76; // w22
  __int64 v77; // x27
  unsigned __int64 v78; // x26
  unsigned int v79; // w25
  int v80; // w22
  __int64 v81; // x9
  __int64 v82; // x10
  int *v83; // x11
  int v84; // t1
  unsigned __int8 v85; // w8
  unsigned int v86; // w8
  unsigned int v87; // w9
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned __int64 v96; // x10
  __int64 v97; // x4
  const char *v98; // x10
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // x25
  __int64 v108; // [xsp+0h] [xbp-30h]
  __int64 v109; // [xsp+1Ch] [xbp-14h] BYREF
  __int16 v110; // [xsp+24h] [xbp-Ch] BYREF
  unsigned __int8 v111; // [xsp+26h] [xbp-Ah]
  __int64 v112; // [xsp+28h] [xbp-8h]

  v112 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a2 + 4);
  v109 = 0;
  v111 = 0;
  v110 = 0;
  if ( v2 >= 6 )
    goto LABEL_92;
  v5 = (unsigned __int8 *)a1 + 17410;
  v6 = (unsigned __int16 *)&a1[68 * (unsigned int)v2 + 2177];
  session_id_from_bssid = csr_roam_get_session_id_from_bssid((__int64)a1, (int *)(a2 + 5), &v109);
  if ( session_id_from_bssid )
  {
    v16 = session_id_from_bssid;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: sme session ID not found for bssid",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "sme_rrm_process_beacon_report_req_ind");
    goto LABEL_9;
  }
  if ( (unsigned int)v109 > 5 || !(a1[2153] + 96LL * (unsigned int)v109) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid session id %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "sme_rrm_process_beacon_report_req_ind");
    v16 = 16;
    goto LABEL_9;
  }
  rrm_get_country_code_from_connected_profile((__int64)a1, v109, (unsigned __int8 *)&v110);
  if ( wlan_reg_is_6ghz_op_class(a1[2695], *(_BYTE *)(a2 + 32)) )
  {
    v25 = 4;
    v111 = 4;
  }
  else
  {
    v25 = v111;
  }
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: RRM_SCN: Index:%d Request Reg class %d, AP's country code %c%c 0x%x, channel = %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "sme_rrm_process_beacon_report_req_ind",
    *(unsigned __int8 *)(a2 + 4),
    *(unsigned __int8 *)(a2 + 32),
    (unsigned __int8)v110,
    HIBYTE(v110),
    v25,
    *(unsigned __int8 *)(a2 + 33));
  if ( *(unsigned __int8 *)(a2 + 92) >= 9u )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Beacon report request numChannels:%u exceeds max num channels",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "sme_rrm_process_beacon_report_req_ind");
    v16 = 4;
    goto LABEL_9;
  }
  if ( *(_BYTE *)(a2 + 33) && (*(unsigned __int8 *)(a2 + 33) != 255 || *(_BYTE *)(a2 + 92)) )
  {
    *((_BYTE *)v6 + 56) = 0;
    v46 = *((_QWORD *)v6 + 8);
    if ( *(unsigned __int8 *)(a2 + 33) == 255 )
      v47 = *(unsigned __int8 *)(a2 + 92);
    else
      v47 = *(unsigned __int8 *)(a2 + 92) + 1;
    HIDWORD(v109) = v47;
    if ( v46 )
    {
      _qdf_mem_free(v46);
      v47 = HIDWORD(v109);
      *((_QWORD *)v6 + 8) = 0;
    }
    v48 = _qdf_mem_malloc(4LL * v47, "sme_rrm_process_beacon_report_req_ind", 1564);
    *((_QWORD *)v6 + 8) = v48;
    if ( v48 )
    {
      v57 = (_DWORD *)v48;
      if ( *(unsigned __int8 *)(a2 + 33) != 255 )
      {
        v58 = *(_DWORD *)(a2 + 36);
        if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v58) & 1) != 0 )
        {
          *v57 = v58;
          v59 = 1;
LABEL_44:
          if ( !*(_BYTE *)(a2 + 92) )
            goto LABEL_69;
          v69 = *(_DWORD *)(a2 + 96);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v69) & 1) != 0 )
            v57[v59++] = v69;
          if ( *(unsigned __int8 *)(a2 + 92) < 2u )
            goto LABEL_69;
          v70 = *(_DWORD *)(a2 + 100);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v70) & 1) != 0 )
            v57[v59++] = v70;
          if ( *(unsigned __int8 *)(a2 + 92) < 3u )
            goto LABEL_69;
          v71 = *(_DWORD *)(a2 + 104);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v71) & 1) != 0 )
            v57[v59++] = v71;
          if ( *(unsigned __int8 *)(a2 + 92) < 4u )
            goto LABEL_69;
          v72 = *(_DWORD *)(a2 + 108);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v72) & 1) != 0 )
            v57[v59++] = v72;
          if ( *(unsigned __int8 *)(a2 + 92) < 5u )
            goto LABEL_69;
          v73 = *(_DWORD *)(a2 + 112);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v73) & 1) != 0 )
            v57[v59++] = v73;
          if ( *(unsigned __int8 *)(a2 + 92) < 6u )
            goto LABEL_69;
          v74 = *(_DWORD *)(a2 + 116);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v74) & 1) != 0 )
            v57[v59++] = v74;
          if ( *(unsigned __int8 *)(a2 + 92) < 7u )
            goto LABEL_69;
          v75 = *(_DWORD *)(a2 + 120);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v75) & 1) != 0 )
            v57[v59++] = v75;
          if ( *(unsigned __int8 *)(a2 + 92) < 8u )
            goto LABEL_69;
          v76 = *(_DWORD *)(a2 + 124);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(a1[1] + 5756LL, v76) & 1) != 0 )
          {
            v57[v59] = v76;
            LOBYTE(v59) = v59 + 1;
          }
          if ( *(unsigned __int8 *)(a2 + 92) <= 8u )
          {
LABEL_69:
            v68 = (unsigned __int8)v59;
            *((_BYTE *)v6 + 56) = v59;
            goto LABEL_70;
          }
LABEL_92:
          __break(0x5512u);
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Invalid channel: %d",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "sme_rrm_process_beacon_report_req_ind",
          *(unsigned __int8 *)(a2 + 33));
      }
      v59 = 0;
      goto LABEL_44;
    }
LABEL_38:
    *((_BYTE *)v6 + 56) = 0;
    v16 = 2;
    goto LABEL_9;
  }
  v60 = *((_QWORD *)v6 + 8);
  v61 = *(_DWORD *)(a1[1] + 6176LL);
  HIDWORD(v109) = v61;
  if ( v60 )
  {
    _qdf_mem_free(v60);
    v61 = HIDWORD(v109);
    *((_QWORD *)v6 + 8) = 0;
  }
  v62 = _qdf_mem_malloc(4LL * v61, "sme_rrm_process_beacon_report_req_ind", 1526);
  *((_QWORD *)v6 + 8) = v62;
  if ( !v62 )
    goto LABEL_38;
  csr_get_cfg_valid_channels((__int64)a1, v62, (_DWORD *)&v109 + 1);
  v63 = *(_BYTE *)(a2 + 32);
  v64 = HIDWORD(v109);
  if ( !v63 )
  {
    v68 = BYTE4(v109);
    *((_BYTE *)v6 + 56) = BYTE4(v109);
    goto LABEL_70;
  }
  v65 = *((_QWORD *)v6 + 8);
  if ( !HIDWORD(v109) )
  {
    *((_BYTE *)v6 + 56) = 0;
LABEL_89:
    _qdf_mem_free(v65);
    *((_QWORD *)v6 + 8) = 0;
    v107 = jiffies;
    if ( sme_rrm_fill_scan_channels___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: No channels populated with requested operation class and current country, Hence abort the rrm operation",
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        "sme_rrm_fill_scan_channels");
      v16 = 0;
      sme_rrm_fill_scan_channels___last_ticks = v107;
LABEL_9:
      if ( *(_DWORD *)(a2 + 128) == 2 )
      {
        qdf_mem_copy(v6 + 1, (const void *)(a2 + 5), 6u);
        qdf_mem_copy(v6 + 53, (const void *)(a2 + 40), 6u);
        v34 = *v5;
        v35 = *((_BYTE *)v6 + 9);
        *v6 = *(_WORD *)(a2 + 88);
        *((_BYTE *)v6 + 8) = *(_BYTE *)(a2 + 32);
        v36 = *(unsigned __int16 *)(a2 + 28);
        if ( v36 <= v34 )
          LOWORD(v36) = v34;
        v6[56] = v36;
        sme_rrm_send_beacon_report_xmit_ind((__int64)a1, v35, nullptr, 1, 0, v26, v27, v28, v29, v30, v31, v32, v33);
      }
      goto LABEL_13;
    }
LABEL_90:
    v16 = 0;
    goto LABEL_9;
  }
  v66 = 0;
  v67 = *((int **)v6 + 8);
  do
  {
    if ( (wlan_reg_is_freq_in_country_opclass(
            a1[2695],
            (unsigned __int8 *)&v110,
            v63,
            *v67,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56)
        & 1) != 0 )
      *(_DWORD *)(v65 + 4LL * v66++) = *v67;
    --v64;
    ++v67;
  }
  while ( v64 );
  v68 = (unsigned __int8)v66;
  *((_BYTE *)v6 + 56) = v66;
  if ( !(_BYTE)v66 )
  {
    v65 = *((_QWORD *)v6 + 8);
    goto LABEL_89;
  }
LABEL_70:
  if ( !v68 )
    goto LABEL_90;
  v77 = *((_QWORD *)v6 + 8);
  v78 = 0;
  v79 = 0;
  do
  {
    v80 = *(_DWORD *)(v77 + 4 * v78);
    v81 = v5[3810];
    if ( !*(_BYTE *)(a2 + 4) )
    {
LABEL_78:
      if ( (_DWORD)v81 == 255 )
        goto LABEL_92;
LABEL_79:
      *(_DWORD *)&v5[4 * v81 + 2790] = v80;
      v85 = v5[3810] + 1;
      v5[3810] = v85;
      if ( v85 == 0xFF )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Reset beacon_rpt_chan_num : %d",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "sme_rrm_process_beacon_report_req_ind",
          255);
        v5[3810] = 0;
      }
      *(_DWORD *)(v77 + 4LL * v79++) = v80;
      v68 = *((unsigned __int8 *)v6 + 56);
      goto LABEL_73;
    }
    v82 = v5[3810];
    v83 = (int *)(v5 + 2790);
    if ( !v5[3810] )
      goto LABEL_79;
    while ( 1 )
    {
      v84 = *v83++;
      if ( v84 == v80 )
        break;
      if ( !--v82 )
        goto LABEL_78;
    }
LABEL_73:
    ++v78;
  }
  while ( v78 < v68 );
  if ( !v79 )
    goto LABEL_90;
  *((_BYTE *)v6 + 56) = v79;
  qdf_mem_copy(v6 + 1, (const void *)(a2 + 5), 6u);
  qdf_mem_copy(v6 + 53, (const void *)(a2 + 40), 6u);
  qdf_mem_copy((char *)v6 + 73, (const void *)(a2 + 54), 0x21u);
  *v6 = *(_WORD *)(a2 + 88);
  *((_BYTE *)v6 + 8) = *(_BYTE *)(a2 + 32);
  v86 = *v5;
  v87 = *(unsigned __int16 *)(a2 + 28);
  *((_BYTE *)v6 + 72) = 0;
  if ( v87 > v86 )
    LOWORD(v86) = v87;
  v6[56] = v86;
  *((_DWORD *)v6 + 134) = *(_DWORD *)(a2 + 128);
  qdf_mem_copy(v6 + 65, (const void *)(a2 + 46), 8u);
  qdf_mem_copy(v6 + 57, (const void *)(a2 + 12), 8u);
  v96 = *((unsigned __int8 *)v6 + 130);
  v97 = *v6;
  *((_DWORD *)v6 + 3) = 1;
  if ( v96 > 2 )
    v98 = "UNKNOWN";
  else
    v98 = off_A178C0[v96];
  LODWORD(v108) = v6[57];
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: token: %d randnIntvl: %d msgSource: %d measurementduration %d, rrm_ctx duration %d Meas_mode: %s, type: %d",
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    "sme_rrm_process_beacon_report_req_ind",
    v97,
    v6[56],
    *((unsigned int *)v6 + 134),
    *(unsigned __int16 *)(a2 + 12),
    v108,
    v98,
    1);
  v16 = sme_rrm_issue_scan_req((__int64)a1, *(unsigned __int8 *)(a2 + 4));
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v16;
}
