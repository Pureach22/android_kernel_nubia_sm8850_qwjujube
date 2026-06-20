__int64 __fastcall lim_process_ft_aggr_qos_req(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 session_by_bssid; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int8 *v15; // x22
  __int64 v16; // x0
  __int64 v17; // x24
  char v18; // w27
  __int64 v19; // x26
  __int64 v20; // x21
  unsigned int v21; // w8
  int v22; // w9
  unsigned int v23; // w8
  int v24; // w8
  unsigned __int8 v25; // w9
  __int64 *v26; // x25
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x12
  __int64 v39; // x9
  __int64 v40; // x12
  __int64 v41; // x11
  unsigned int v42; // w20
  __int64 v43; // x4
  const char *v44; // x2
  const char *v45; // x3
  const char *v46; // x2
  int v48; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // w8
  __int64 v74; // [xsp+0h] [xbp-80h]
  _BYTE v75[4]; // [xsp+8h] [xbp-78h] BYREF
  __int16 v76; // [xsp+Ch] [xbp-74h] BYREF
  __int64 v77; // [xsp+10h] [xbp-70h] BYREF
  __int64 v78; // [xsp+18h] [xbp-68h] BYREF
  __int64 v79; // [xsp+20h] [xbp-60h]
  __int64 v80; // [xsp+28h] [xbp-58h]
  __int64 v81; // [xsp+30h] [xbp-50h]
  __int64 v82; // [xsp+38h] [xbp-48h]
  __int64 v83; // [xsp+40h] [xbp-40h]
  __int64 v84; // [xsp+48h] [xbp-38h] BYREF
  __int64 v85; // [xsp+50h] [xbp-30h]
  __int64 v86; // [xsp+58h] [xbp-28h]
  __int64 v87; // [xsp+60h] [xbp-20h]
  __int64 v88; // [xsp+68h] [xbp-18h]
  __int64 v89; // [xsp+70h] [xbp-10h]
  __int64 v90; // [xsp+78h] [xbp-8h]

  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v77 = 0;
  v76 = 0;
  v75[0] = 0;
  v4 = _qdf_mem_malloc(0x100u, "lim_process_ft_aggr_qos_req", 970);
  if ( !v4 )
  {
    v42 = 2;
    goto LABEL_28;
  }
  v5 = v4;
  session_by_bssid = pe_find_session_by_bssid(a1, a2 + 5, v75);
  if ( !session_by_bssid )
  {
    v43 = *(unsigned __int8 *)(a2 + 4);
    v44 = "%s: psession Entry Null for sessionId: %d";
    v45 = "lim_process_ft_aggr_qos_req";
LABEL_19:
    qdf_trace_msg(0x35u, 2u, v44, v7, v8, v9, v10, v11, v12, v13, v14, v45, v43);
    goto LABEL_26;
  }
  v15 = (unsigned __int8 *)session_by_bssid;
  if ( *(_DWORD *)(session_by_bssid + 88) != 2 )
  {
    v46 = "%s: pe_session is not in STA mode";
    goto LABEL_25;
  }
  v16 = dph_lookup_hash_entry(
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          a1,
          (unsigned __int8 *)(a2 + 5),
          &v76,
          session_by_bssid + 360);
  if ( !v16 )
  {
    v46 = "%s: Station context not found - ignoring AddTsRsp";
LABEL_25:
    qdf_trace_msg(0x35u, 2u, v46, v7, v8, v9, v10, v11, v12, v13, v14, "lim_process_ft_aggr_qos_req");
LABEL_26:
    v42 = 16;
LABEL_27:
    _qdf_mem_free(v5);
    goto LABEL_28;
  }
  v17 = v16;
  v18 = 0;
  v19 = -652;
  *(_BYTE *)(v5 + 252) = v75[0];
  v20 = 2;
  v74 = a1 + 0x2000;
  *(_WORD *)v5 = *(_WORD *)(a2 + 18);
  *(_BYTE *)(v5 + 253) = v15[10];
  do
  {
    if ( ((*(unsigned __int16 *)(a2 + 18) >> v18) & 1) == 0 )
      goto LABEL_6;
    lim_set_tspec_uapsd_mask_per_session(a1, v15, a2 + v19 + 675, (*(unsigned __int16 *)(a2 + v19 + 676) >> 10) & 1);
    v21 = *(unsigned __int16 *)(a2 + v19 + 676);
    v22 = (v21 >> 5) & 3;
    v23 = 0x33220110u >> ((v21 >> 9) & 0x1C);
    if ( v22 == 3 )
    {
      v24 = 1 << (v23 & 3);
      v25 = v15[7277] | v24;
      LOBYTE(v24) = v15[7278] | v24;
      v15[7277] = v25;
    }
    else
    {
      if ( v22 != 1 )
      {
        if ( !v22 )
          v15[7277] |= 1 << (v23 & 3);
        goto LABEL_15;
      }
      v24 = v15[7278] | (1 << (v23 & 3));
    }
    v15[7278] = v24;
LABEL_15:
    v26 = (__int64 *)(a2 + v19 + 673);
    lim_set_active_edca_params(a1, v15 + 7096, v15);
    v27 = lim_send_edca_params(a1, v15 + 7136, v15[10], 0);
    if ( (unsigned int)lim_tspec_add(
                         a1,
                         (const void *)(v17 + 338),
                         *(_WORD *)(v17 + 336),
                         v26,
                         v27,
                         v28,
                         v29,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         0,
                         &v77) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Adding entry in lim Tspec Table failed",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "lim_process_ft_aggr_qos_req");
      v42 = 16;
      *(_BYTE *)(v74 + 684) = 0;
      goto LABEL_27;
    }
    v35 = *(_QWORD *)(a2 + v19 + 697);
    v36 = v5 + v20;
    v37 = *v26;
    v38 = *(_QWORD *)(a2 + v19 + 681);
    *(_QWORD *)(v36 + 16) = *(_QWORD *)(a2 + v19 + 689);
    *(_QWORD *)(v36 + 24) = v35;
    *(_QWORD *)v36 = v37;
    *(_QWORD *)(v36 + 8) = v38;
    v40 = *(_QWORD *)(a2 + v19 + 713);
    v39 = *(_QWORD *)(a2 + v19 + 721);
    v41 = *(_QWORD *)(a2 + v19 + 705);
    *(_WORD *)(v36 + 56) = *(_WORD *)(a2 + v19 + 729);
    *(_QWORD *)(v36 + 40) = v40;
    *(_QWORD *)(v36 + 48) = v39;
    *(_QWORD *)(v36 + 32) = v41;
LABEL_6:
    v19 += 163;
    ++v18;
    v20 += 58;
  }
  while ( v19 );
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1510LL) == 1 && (v15[7041] & 1) != 0 )
  {
    lim_ft_send_aggr_qos_rsp(a1, (__int16 *)v5, v15[10]);
    v42 = 0;
    goto LABEL_27;
  }
  v79 = v5;
  LOWORD(v78) = 4237;
  HIDWORD(v78) = 0;
  *(_BYTE *)(a1 + 8885) = 0;
  *(_QWORD *)(a1 + 8888) = "lim_process_ft_aggr_qos_req";
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Defer LIM msg %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "lim_process_ft_aggr_qos_req",
    0,
    v74);
  v48 = *(unsigned __int8 *)(a1 + 8885);
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  if ( v48 )
  {
    if ( *(_WORD *)(a1 + 8688) )
    {
      LOWORD(v84) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v84) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "lim_post_msg_to_process_deferred_queue",
          (unsigned __int16)v84);
    }
  }
  mac_trace_msg_tx(a1, v15[8], 4237);
  if ( (unsigned int)wma_post_ctrl_msg(a1, &v78) )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: wma_post_ctrl_msg() failed",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "lim_process_ft_aggr_qos_req");
    *(_BYTE *)(a1 + 8885) = 1;
    *(_QWORD *)(a1 + 8888) = "lim_process_ft_aggr_qos_req";
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Defer LIM msg %d",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "lim_process_ft_aggr_qos_req",
      1);
    v73 = *(unsigned __int8 *)(a1 + 8885);
    v88 = 0;
    v89 = 0;
    v86 = 0;
    v87 = 0;
    v84 = 0;
    v85 = 0;
    if ( v73 )
    {
      if ( *(_WORD *)(a1 + 8688) )
      {
        LOWORD(v84) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v84) )
        {
          v43 = (unsigned __int16)v84;
          v44 = "%s: Failed to post lim msg:0x%x";
          v45 = "lim_post_msg_to_process_deferred_queue";
          goto LABEL_19;
        }
      }
    }
    goto LABEL_26;
  }
  v42 = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v42;
}
