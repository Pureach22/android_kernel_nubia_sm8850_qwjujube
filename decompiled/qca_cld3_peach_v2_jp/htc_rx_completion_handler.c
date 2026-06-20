__int64 __fastcall htc_rx_completion_handler(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  __int64 v5; // x24
  int v6; // w9
  unsigned int v7; // w8
  unsigned int v8; // w4
  const char *v9; // x2
  __int64 v10; // x28
  unsigned int v11; // w4
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x22
  __int64 v17; // x27
  __int64 v18; // x27
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x21
  unsigned int v22; // w26
  __int64 v23; // x5
  unsigned int v24; // w23
  __int64 v26; // x25
  unsigned int v27; // w21
  __int64 v28; // x24
  int *v29; // x23
  int v30; // w24
  unsigned int v31; // w6
  unsigned __int8 v32; // w8
  _DWORD *v33; // x23
  int v34; // t1
  __int64 v35; // x27
  int v36; // w22
  unsigned int v37; // w22
  __int64 htc_packet_container; // x0
  __int64 v39; // x24
  __int64 v40; // x8
  __int64 v41; // x8
  unsigned int v42; // w21
  unsigned int v43; // w9
  unsigned int v44; // w8
  __int64 v45; // x8
  _DWORD *v46; // x21
  int v47; // w8
  int v48; // w9
  int v49; // w10
  void (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x0
  unsigned int v52; // w21
  void (__fastcall *v53)(__int64, __int64, __int64); // x8
  __int64 v54; // x0
  __int64 v55; // x1
  __int64 v56; // x2
  int v57; // w9
  int v58; // w10
  void (__fastcall *v59)(__int64, __int64); // x8
  __int64 v60; // x0
  __int64 v61; // x0
  int v62; // w22
  size_t v63; // x2
  unsigned int v64; // [xsp+0h] [xbp-10h]
  __int64 v65; // [xsp+0h] [xbp-10h]
  __int64 v66; // [xsp+8h] [xbp-8h]

  v4 = a2 + 224;
  v5 = *(_QWORD *)(a2 + 224);
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v6 = *(unsigned __int16 *)(a2 + 66);
  else
    v6 = 0;
  v7 = *(_DWORD *)v5;
  v8 = (unsigned __int8)*(_DWORD *)v5;
  if ( v8 >= 9 )
  {
    if ( (dword_B0B4 & 1) != 0 )
      qdf_trace_msg(56, 2, "%s: HTC Rx: invalid EndpointID=%d\n", "htc_rx_completion_handler", v8);
    v9 = "BAD HTC Header";
LABEL_39:
    debug_dump_bytes(v5, 8u, v9);
    qdf_dp_trace(a2, 39, 255, v4, 8, 1);
    v24 = 16;
    goto LABEL_40;
  }
  v66 = (unsigned __int8)*(_DWORD *)v5;
  v10 = a1 + 328 * v66;
  v11 = *(_DWORD *)(a2 + 112) + v6;
  if ( *(_DWORD *)(v10 + 148) )
  {
    v12 = 0;
    v64 = *(_DWORD *)(a2 + 112) + v6;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      if ( *(unsigned __int8 *)(a1 + v12 + 145) == *(unsigned __int8 *)(v10 + 145) && *(_DWORD *)(a1 + v12 + 148) )
      {
        v16 = a1 + v12;
        v17 = *(_QWORD *)(a1 + v12 + 288);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v17 + 2992);
        }
        else
        {
          raw_spin_lock_bh(v17 + 2992);
          *(_QWORD *)(v17 + 3000) |= 1uLL;
        }
        v18 = a1 + v12;
        if ( *(_DWORD *)(a1 + v12 + 208) )
          *(_DWORD *)(v18 + 208) = 0;
        v19 = *(_QWORD *)(v16 + 288);
        v20 = *(_QWORD *)(v19 + 3000);
        if ( (v20 & 1) != 0 )
        {
          *(_QWORD *)(v19 + 3000) = v20 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v19 + 2992);
        }
        else
        {
          raw_spin_unlock(v19 + 2992);
        }
        hif_send_complete_check(**(_QWORD **)(v16 + 288), *(unsigned __int8 *)(a1 + v12 + 144), 1);
        v21 = *(_QWORD *)(v16 + 288);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v21 + 2992);
        }
        else
        {
          raw_spin_lock_bh(v21 + 2992);
          *(_QWORD *)(v21 + 3000) |= 1uLL;
        }
        if ( *(_DWORD *)(a1 + v12 + 212) && !*(_DWORD *)(v18 + 208) )
          *(_DWORD *)(v18 + 208) = 1;
        v14 = *(_QWORD *)(v16 + 288);
        v15 = *(_QWORD *)(v14 + 3000);
        if ( (v15 & 1) != 0 )
        {
          *(_QWORD *)(v14 + 3000) = v15 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v14 + 2992);
        }
        else
        {
          raw_spin_unlock(v14 + 2992);
        }
      }
      v12 += 328;
    }
    while ( v12 != 2952 );
    v7 = *(_DWORD *)v5;
    v11 = v64;
  }
  v22 = HIWORD(v7);
  v23 = HIWORD(v7) + 8;
  if ( v11 < (unsigned int)v23 )
  {
    if ( (dword_B0B4 & 1) != 0 )
      qdf_trace_msg(
        56,
        2,
        "%s: HTC Rx: insufficient length, got:%d expected =%zu\n",
        "htc_rx_completion_handler",
        v11,
        v23);
    v9 = "BAD RX packet length";
    goto LABEL_39;
  }
  if ( (v7 & 0x200) != 0 )
  {
    v26 = *(unsigned __int8 *)(v5 + 4);
    if ( (v26 & 0xFC) == 0 || (unsigned int)v26 > v22 )
    {
      if ( (dword_B0B4 & 1) != 0 )
        qdf_trace_msg(
          56,
          2,
          "%s: htc_rx_completion_handler, invalid header (payloadlength should be :%d, CB[0] is:%d)\n",
          "htc_rx_completion_handler",
          v22,
          v26);
      v24 = 4;
      goto LABEL_40;
    }
    v27 = v11;
    v28 = v5 + v22 - v26 + 8;
    if ( (dword_B0B4 & 0x200) != 0 )
    {
      qdf_trace_msg(56, 2, "%s: +htc_process_trailer (length:%d)\n", "htc_process_trailer", v26);
      if ( (dword_B0B4 & 0x200) != 0 )
        debug_dump_bytes(v28, v26, "Recv Trailer");
    }
    if ( (_DWORD)v26 )
    {
      v65 = v28;
      v29 = (int *)v28;
      v30 = v26;
      do
      {
        v31 = v30 - 4;
        if ( (unsigned int)v30 < 4 )
          goto LABEL_67;
        v34 = *v29;
        v33 = v29 + 1;
        v32 = v34;
        v35 = BYTE1(v34);
        v30 = v31 - BYTE1(v34);
        if ( v31 < BYTE1(v34) )
        {
          if ( (dword_B0B4 & 1) != 0 )
            qdf_trace_msg(
              56,
              2,
              "%s: invalid record length: %d (id:%d) buffer has: %d bytes left\n",
              "htc_process_trailer",
              v35,
              v32,
              v31);
LABEL_67:
          debug_dump_bytes(v65, v26, "BAD Recv Trailer");
          v36 = 0;
          goto LABEL_69;
        }
        if ( v32 == 1 )
        {
          if ( (unsigned int)v35 <= 3 )
            printk(
              &unk_881311,
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_recv.c",
              705,
              "htc_rec_len >= sizeof(HTC_CREDIT_REPORT)");
          htc_process_credit_rpt(a1, v33, (unsigned int)v35 >> 2, v66);
        }
        else if ( (dword_B0B4 & 1) != 0 )
        {
          qdf_trace_msg(56, 2, "%s: HTC unhandled record: id:%d length:%d\n", "htc_process_trailer", v32, v35);
        }
        v29 = (_DWORD *)((char *)v33 + v35);
      }
      while ( v30 >= 1 );
      v36 = 1;
    }
    else
    {
      v36 = 1;
    }
LABEL_69:
    if ( (dword_B0B4 & 0x200) != 0 )
      qdf_trace_msg(56, 2, "%s: -htc_process_trailer\n", "htc_process_trailer");
    v11 = v27;
    if ( v36 )
      v24 = 0;
    else
      v24 = 16;
    if ( !v36 )
    {
LABEL_40:
      if ( a2 )
        goto LABEL_41;
      return v24;
    }
  }
  else
  {
    LODWORD(v26) = 0;
    v24 = 0;
  }
  if ( v22 <= (unsigned int)v26 )
    goto LABEL_40;
  if ( (_DWORD)v66 )
  {
    v37 = v11;
    htc_packet_container = allocate_htc_packet_container(a1);
    if ( htc_packet_container )
    {
      *(_QWORD *)(htc_packet_container + 48) = (unsigned int)v66;
      v39 = htc_packet_container;
      *(_QWORD *)(htc_packet_container + 16) = a2;
      v40 = *(_QWORD *)(a2 + 224);
      *(_DWORD *)(htc_packet_container + 44) = v37 - v26 - 8;
      *(_QWORD *)(htc_packet_container + 32) = v40 + 8;
      v41 = *(_QWORD *)(a2 + 40);
      if ( v41 )
        *(_QWORD *)(a2 + 40) = v41 + 8;
      skb_pull(a2, 8);
      v42 = *(_DWORD *)(v39 + 44);
      v43 = *(_DWORD *)(a2 + 112);
      v44 = v42 - v43;
      if ( v42 < v43 )
      {
        skb_trim(a2, v42);
LABEL_115:
        v59 = *(void (__fastcall **)(__int64, __int64))(v10 + 32);
        if ( v59 )
        {
          if ( (dword_B0B4 & 0x200) != 0 )
          {
            qdf_trace_msg(
              56,
              2,
              "%s: HTC calling ep %d recv callback on packet %pK\n",
              "do_recv_completion_pkt",
              *(_DWORD *)(v10 + 8),
              (const void *)v39);
            v59 = *(void (__fastcall **)(__int64, __int64))(v10 + 32);
          }
          v60 = *(_QWORD *)(v10 + 16);
          if ( *((_DWORD *)v59 - 1) != 1226475842 )
            __break(0x8228u);
          v59(v60, v39);
        }
        else
        {
          if ( (dword_B0B4 & 1) != 0 )
            qdf_trace_msg(
              56,
              2,
              "%s: HTC ep %d has NULL recv callback on packet %pK\n",
              "do_recv_completion_pkt",
              *(_DWORD *)(v10 + 8),
              (const void *)v39);
          v61 = *(_QWORD *)(v39 + 16);
          if ( v61 )
            _qdf_nbuf_free(v61);
        }
        free_htc_packet_container(a1, (_QWORD *)v39);
        return v24;
      }
      if ( *(_DWORD *)(a2 + 116) )
      {
        v44 = v42 - v43;
        if ( v42 != v43 )
        {
          v48 = 0;
          goto LABEL_112;
        }
      }
      else
      {
        v58 = *(_DWORD *)(a2 + 208);
        v57 = *(_DWORD *)(a2 + 212);
        if ( v57 - v58 < v44 )
        {
          v48 = v58 - v57;
LABEL_112:
          if ( (unsigned int)pskb_expand_head(a2, 0, v48 + v44, 2080) )
            dev_kfree_skb_any_reason(a2, 1);
        }
      }
      skb_put(a2, v42 - *(_DWORD *)(a2 + 112));
      goto LABEL_115;
    }
    v24 = 1;
    goto LABEL_40;
  }
  v45 = *(_QWORD *)(a2 + 40);
  if ( v45 )
    *(_QWORD *)(a2 + 40) = v45 + 8;
  skb_pull(a2, 8);
  v46 = *(_DWORD **)(a2 + 224);
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v47 = *(unsigned __int16 *)(a2 + 66);
  else
    v47 = 0;
  v49 = (unsigned __int16)*v46;
  switch ( v49 )
  {
    case 6:
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))htc_credit_record)(
        2,
        *(unsigned int *)(v10 + 296),
        *(unsigned int *)(v10 + 128));
      v53 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 3040);
      v54 = *(_QWORD *)(a1 + 3056);
      v55 = 0;
      v56 = 0;
      goto LABEL_103;
    case 7:
      v52 = (unsigned __int8)BYTE2(*v46);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))htc_credit_record)(
        2,
        *(unsigned int *)(v10 + 296),
        *(unsigned int *)(v10 + 128));
      v53 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 3040);
      v54 = *(_QWORD *)(a1 + 3056);
      v55 = 1;
      v56 = v52;
LABEL_103:
      if ( *((_DWORD *)v53 - 1) != -2021387240 )
        __break(0x8228u);
      v53(v54, v55, v56);
      goto LABEL_40;
    case 8:
      if ( (_WORD)dword_B0B4 )
        qdf_trace_msg(56, 2, "%s: Received initial wake up", "htc_rx_completion_handler");
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))htc_credit_record)(
        4,
        *(unsigned int *)(v10 + 296),
        *(unsigned int *)(v10 + 128));
      v50 = *(void (__fastcall **)(_QWORD))(a1 + 3048);
      if ( v50 )
      {
        v51 = *(_QWORD *)(a1 + 3056);
        if ( *((_DWORD *)v50 - 1) != 251140989 )
          __break(0x8228u);
        v50(v51);
        if ( a2 )
          goto LABEL_41;
        return v24;
      }
      if ( (_WORD)dword_B0B4 )
      {
        qdf_trace_msg(56, 2, "%s: No initial wake up cb", "htc_rx_completion_handler");
        if ( !a2 )
          return v24;
        goto LABEL_41;
      }
      goto LABEL_40;
  }
  if ( *(_BYTE *)(a1 + 3408) == 1 )
  {
    if ( (dword_B0B4 & 1) != 0 )
    {
      qdf_trace_msg(56, 2, "%s: HTC Rx Ctrl still processing\n", "htc_rx_completion_handler");
      v24 = 16;
      if ( !a2 )
        return v24;
    }
    else
    {
      v24 = 16;
      if ( !a2 )
        return v24;
    }
    goto LABEL_41;
  }
  v62 = *(_DWORD *)(a2 + 112) + v47;
  qdf_spin_lock_bh_1(a1 + 2976);
  if ( v62 >= 256 )
    v63 = 256;
  else
    v63 = (unsigned int)v62;
  *(_DWORD *)(a1 + 3360) = v63;
  qdf_mem_copy(a1 + 3104, (int)v46, v63);
  *(_BYTE *)(a1 + 3408) = 1;
  qdf_spin_unlock_bh_0(a1 + 2976);
  qdf_event_set(a1 + 3368);
  if ( a2 )
LABEL_41:
    _qdf_nbuf_free(a2);
  return v24;
}
