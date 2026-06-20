void wlan_logging_thread()
{
  unsigned int v1; // w19
  __int64 v2; // x22
  unsigned int multiplier; // w20
  __int64 v4; // x0
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  __int64 *v24; // x22
  void **v25; // x8
  __int64 v26; // x9
  _QWORD *v27; // x10
  int v28; // w9
  int v29; // w8
  int v30; // w9
  unsigned int v31; // w19
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 **v34; // x1
  __int64 v35; // x9
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w19
  __int64 v45; // x0
  __int64 **v46; // x1
  __int64 v47; // x9
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  char v64; // w26
  __int64 v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x20
  __int64 v75; // x0
  __int64 *v76; // x22
  _QWORD *v77; // x8
  __int64 v78; // x9
  __int64 v79; // x10
  __int64 v80; // x19
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  void *v89; // x0
  void *v90; // x0
  unsigned int v91; // w8
  __int64 v92; // x4
  __int64 v93; // x5
  void *v94; // x0
  unsigned int v95; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x0
  __int64 v105; // x9
  __int64 **v106; // x1
  __int64 v107; // x3
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x0
  __int64 v117; // x1
  __int64 v118; // x19
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  unsigned __int64 v132; // x8
  unsigned __int64 v134; // x8
  unsigned __int64 v137; // x8
  unsigned __int64 v139; // x8
  unsigned __int64 v141; // x8
  unsigned __int64 v143; // x8
  unsigned __int64 v145; // x8
  unsigned __int64 v147; // x8
  unsigned __int64 v149; // x8
  unsigned __int64 v151; // x8
  unsigned __int64 v153; // x8
  __int64 v154; // [xsp+8h] [xbp-48h] BYREF
  __int64 v155; // [xsp+10h] [xbp-40h]
  unsigned __int64 v156; // [xsp+18h] [xbp-38h]
  __int64 v157; // [xsp+20h] [xbp-30h]
  __int64 v158; // [xsp+28h] [xbp-28h]
  int v159; // [xsp+34h] [xbp-1Ch] BYREF
  _DWORD v160[3]; // [xsp+38h] [xbp-18h] BYREF
  __int64 v161; // [xsp+44h] [xbp-Ch]
  __int16 v162; // [xsp+4Ch] [xbp-4h]
  __int16 v163; // [xsp+4Eh] [xbp-2h]

  __isb(0xFu);
  qword_826D40 = _ReadStatusReg(CNTVCT_EL0);
  if ( (byte_826C68 & 1) != 0 )
    goto LABEL_2;
LABEL_3:
  _X26 = (unsigned __int64 *)&qword_826C78;
LABEL_4:
  raw_spin_lock(&dword_826D00);
  if ( byte_826CF8 == 1 )
  {
    v1 = dword_826CFC;
    if ( dword_826CFC )
    {
      v2 = jiffies;
      multiplier = qdf_timer_get_multiplier();
      v4 = _msecs_to_jiffies(v1);
      mod_timer(&unk_826CC0, v2 + v4 * multiplier);
    }
  }
  v5 = raw_spin_unlock(&dword_826D00);
  if ( off_826C08 == (_UNKNOWN *)&off_826C08
    && (qword_826C78 & 2) == 0
    && (qword_826C78 & 4) == 0
    && (qword_826C78 & 8) == 0
    && (qword_826C78 & 0x10) == 0
    && (byte_826C68 & 1) == 0 )
  {
    v157 = 0;
    v158 = 0;
    v155 = 0;
    v156 = 0;
    v154 = 0;
    init_wait_entry(&v154, 0);
    while ( 1 )
    {
      v5 = prepare_to_wait_event(&unk_826C28, &v154, 1);
      if ( off_826C08 != (_UNKNOWN *)&off_826C08
        || (qword_826C78 & 2) != 0
        || (qword_826C78 & 4) != 0
        || (qword_826C78 & 8) != 0
        || (qword_826C78 & 0x10) != 0
        || (byte_826C68 & 1) != 0 )
      {
        v5 = finish_wait(&unk_826C28, &v154);
        goto LABEL_23;
      }
      if ( v5 )
        break;
      schedule();
    }
    if ( (_DWORD)v5 == -512 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: wait_event_interruptible returned -ERESTARTSYS",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_logging_thread");
      goto LABEL_2;
    }
  }
LABEL_23:
  if ( (byte_826C68 & 1) != 0 )
    goto LABEL_2;
  __asm { PRFM            #0x11, [X26] }
  do
    v132 = __ldxr(_X26);
  while ( __stlxr(v132 & 0xFFFFFFFFFFFFFFFDLL, _X26) );
  __dmb(0xBu);
  if ( (v132 & 2) != 0 )
  {
    if ( off_826C08 == (_UNKNOWN *)&off_826C08 || (byte_826C68 & 1) != 0 )
      goto LABEL_60;
    while ( 1 )
    {
      v14 = (_DWORD *)_netdev_alloc_skb(0, 2048, 2080);
      if ( !v14 )
        break;
      send_filled_buffers_to_user_rate_limit = 0;
      v23 = raw_spin_lock_irqsave((char *)&qword_826BF0 + 4);
      v24 = (__int64 *)off_826C08;
      v25 = *((void ***)off_826C08 + 1);
      v26 = v23;
      if ( *v25 == off_826C08
        && (v27 = *(_QWORD **)off_826C08, *(_UNKNOWN **)(*(_QWORD *)off_826C08 + 8LL) == off_826C08) )
      {
        v27[1] = v25;
        *v25 = v27;
      }
      else
      {
        _list_del_entry_valid_or_report(off_826C08);
      }
      *v24 = (__int64)v24;
      v24[1] = (__int64)v24;
      raw_spin_unlock_irqrestore((char *)&qword_826BF0 + 4, v26);
      v28 = v14[29];
      v29 = *((_DWORD *)v24 + 6);
      ++send_filled_buffers_to_user_nlmsg_seq;
      if ( v28 )
        v30 = 0;
      else
        v30 = v14[53] - v14[52];
      v31 = (v29 + 27) & 0xFFFFFFFC;
      if ( v30 >= (int)v31 && (v32 = _nlmsg_put(v14, 0)) != 0 )
      {
        *(_DWORD *)(v32 + 16) = *((_DWORD *)v24 + 4);
        memcpy((void *)(v32 + 20), (char *)v24 + 28, *((unsigned int *)v24 + 6) + 4LL);
        v33 = raw_spin_lock_irqsave((char *)&qword_826BF0 + 4);
        v34 = (__int64 **)qword_826C00;
        v35 = v33;
        if ( v24 == &qword_826BF8 || (__int64 *)qword_826C00 == v24 || *(__int64 **)qword_826C00 != &qword_826BF8 )
        {
          _list_add_valid_or_report(v24, qword_826C00);
        }
        else
        {
          qword_826C00 = (__int64)v24;
          *v24 = (__int64)&qword_826BF8;
          v24[1] = (__int64)v34;
          *v34 = v24;
        }
        raw_spin_unlock_irqrestore((char *)&qword_826BF0 + 4, v35);
        v5 = nl_srv_bcast(v14, 1, 28);
        if ( (v5 & 0x80000000) != 0 && (dword_826C6C & 0x3F) == 0 )
        {
          v44 = v5;
          dword_826C6C |= 1u;
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Send Failed %d drop_count = %u",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "send_filled_buffers_to_user",
            (unsigned int)v5);
          v5 = v44;
        }
        if ( off_826C08 == (_UNKNOWN *)&off_826C08 || (byte_826C68 & 1) != 0 )
        {
          if ( (_DWORD)v5 != -12 )
            goto LABEL_60;
          goto LABEL_59;
        }
      }
      else
      {
        v45 = raw_spin_lock_irqsave((char *)&qword_826BF0 + 4);
        v46 = (__int64 **)qword_826C00;
        v47 = v45;
        if ( v24 == &qword_826BF8 || (__int64 *)qword_826C00 == v24 || *(__int64 **)qword_826C00 != &qword_826BF8 )
        {
          _list_add_valid_or_report(v24, qword_826C00);
        }
        else
        {
          qword_826C00 = (__int64)v24;
          *v24 = (__int64)&qword_826BF8;
          v24[1] = (__int64)v46;
          *v46 = v24;
        }
        raw_spin_unlock_irqrestore((char *)&qword_826BF0 + 4, v47);
        ++dword_826C6C;
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: drop_count = %u",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "send_filled_buffers_to_user");
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: nlmsg_put() failed for msg size[%d]",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "send_filled_buffers_to_user",
          v31);
        v5 = consume_skb(v14);
        if ( off_826C08 == (_UNKNOWN *)&off_826C08 || (byte_826C68 & 1) != 0 )
          goto LABEL_60;
      }
    }
    if ( (send_filled_buffers_to_user_rate_limit & 1) == 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: dev_alloc_skb() failed for msg size[%d] drop count = %u",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "send_filled_buffers_to_user",
        2048,
        (unsigned int)dword_826C6C);
    send_filled_buffers_to_user_rate_limit = 1;
LABEL_59:
    v5 = msleep(200);
LABEL_60:
    if ( (unsigned int)cds_get_log_indicator(v5) == 4 )
      ((void (*)(void))send_flush_completion_to_user)();
  }
  __asm { PRFM            #0x11, [X26] }
  do
    v134 = __ldxr(_X26);
  while ( __stlxr(v134 & 0xFFFFFFFFFFFFFFFBLL, _X26) );
  __dmb(0xBu);
  _X21 = _X26;
  if ( (v134 & 4) == 0 || (__int64 *)qword_826C98 == &qword_826C98 || (byte_826C68 & 1) != 0 )
    goto LABEL_122;
  v64 = 0;
  while ( 1 )
  {
    v65 = _netdev_alloc_skb(0, 4096, 2080);
    if ( !v65 )
    {
      if ( (pktlog_send_per_pkt_stats_to_user_rate_limit & 1) == 0 )
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: dev_alloc_skb() failed for msg size[%d] drop count = %u",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "pktlog_send_per_pkt_stats_to_user",
          4096,
          (unsigned int)dword_826C6C);
      pktlog_send_per_pkt_stats_to_user_rate_limit = 1;
      msleep(200);
LABEL_122:
      __asm { PRFM            #0x11, [X21] }
      do
        v137 = __ldxr(_X21);
      while ( __stlxr(v137 & 0xFFFFFFFFFFFFFFDFLL, _X21) );
      __dmb(0xBu);
      _X26 = _X21;
      if ( (v137 & 0x20) != 0
        && HIBYTE(word_826C80) == 1
        && (unsigned int)ucfg_cp_stats_cstats_send_buffer_to_user(0) == -12 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: No memory to flush stats",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "wlan_logging_thread");
        msleep(200);
      }
      __asm { PRFM            #0x11, [X26] }
      do
        v139 = __ldxr(_X21);
      while ( __stlxr(v139 & 0xFFFFFFFFFFFFFFBFLL, _X21) );
      __dmb(0xBu);
      if ( (v139 & 0x40) != 0
        && HIBYTE(word_826C80) == 1
        && (unsigned int)ucfg_cp_stats_cstats_send_buffer_to_user(1) == -12 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: No memory to flush stats",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "wlan_logging_thread");
        msleep(200);
      }
      __asm { PRFM            #0x11, [X26] }
      do
        v141 = __ldxr(_X21);
      while ( __stlxr(v141 & 0xFFFFFFFFFFFFFFF7LL, _X21) );
      __dmb(0xBu);
      if ( (v141 & 8) != 0 )
      {
        if ( HIBYTE(word_826C80) == 1 )
        {
          v116 = qdf_trace_msg(
                   0x38u,
                   8u,
                   "%s: reset is_flush_complete",
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   "wlan_logging_thread");
          HIBYTE(word_826C80) = 0;
          send_flush_completion_to_user(v116);
          qdf_event_set((__int64)dword_826D10, v117);
        }
        else
        {
          qdf_trace_msg(
            0x38u,
            8u,
            "%s: set is_flush_complete",
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            "wlan_logging_thread");
          HIBYTE(word_826C80) = 1;
          v118 = raw_spin_lock_irqsave((char *)&qword_826BF0 + 4);
          wlan_queue_logmsg_for_app();
          raw_spin_unlock_irqrestore((char *)&qword_826BF0 + 4, v118);
          __asm { PRFM            #0x11, [X26] }
          do
            v145 = __ldxr(_X21);
          while ( __stxr(v145 | 2, _X21) );
          __asm { PRFM            #0x11, [X26] }
          do
            v147 = __ldxr(_X21);
          while ( __stxr(v147 | 4, _X21) );
          __asm { PRFM            #0x11, [X26] }
          do
            v149 = __ldxr(_X21);
          while ( __stxr(v149 | 8, _X21) );
          if ( byte_826C82 == 1 )
          {
            qdf_trace_msg(
              0x38u,
              8u,
              "%s: setting chipset stats event flags",
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              "wlan_logging_thread");
            byte_826C82 = 0;
            __asm { PRFM            #0x11, [X26] }
            do
              v151 = __ldxr(_X21);
            while ( __stxr(v151 | 0x20, _X21) );
            __asm { PRFM            #0x11, [X26] }
            do
              v153 = __ldxr(_X21);
            while ( __stxr(v153 | 0x40, _X21) );
          }
          _wake_up(&unk_826C28, 1, 1, 0);
        }
      }
      __asm { PRFM            #0x11, [X26] }
      do
        v143 = __ldxr(_X21);
      while ( __stxr(v143 & 0xFFFFFFFFFFFFFFEFLL, _X21) );
      if ( byte_826C68 == 1 )
      {
LABEL_2:
        __isb(0xFu);
        qword_826D58 = _ReadStatusReg(CNTVCT_EL0);
        kthread_complete_and_exit();
        goto LABEL_3;
      }
      goto LABEL_4;
    }
    v74 = v65;
    v75 = raw_spin_lock_irqsave(&dword_826CB4);
    v76 = (__int64 *)qword_826C98;
    v77 = *(_QWORD **)(qword_826C98 + 8);
    v78 = v75;
    if ( *v77 == qword_826C98
      && (v79 = *(_QWORD *)qword_826C98, *(_QWORD *)(*(_QWORD *)qword_826C98 + 8LL) == qword_826C98) )
    {
      *(_QWORD *)(v79 + 8) = v77;
      *v77 = v79;
    }
    else
    {
      _list_del_entry_valid_or_report(qword_826C98);
    }
    *v76 = (__int64)v76;
    v76[1] = (__int64)v76;
    raw_spin_unlock_irqrestore(&dword_826CB4, v78);
    v80 = v76[2];
    v155 = 0;
    v156 = 0;
    v154 = 0;
    qdf_mem_set(&v154, 0x18u, 0);
    v156 = __PAIR64__(*(_DWORD *)(v80 + 112), dword_826CB8++);
    HIDWORD(v155) = 1;
    host_diag_log_set_code(&v154, 6368);
    host_diag_log_set_length(&v154, (unsigned int)*(unsigned __int16 *)(v80 + 112) + 24);
    if ( (unsigned int)*(_QWORD *)(v80 + 224) - (unsigned int)*(_QWORD *)(v80 + 216) <= 0x17 )
      break;
    v89 = (void *)skb_push(v80, 24);
    qdf_mem_copy(v89, &v154, 0x18u);
    if ( (((unsigned int)*(_QWORD *)(v80 + 224) - (unsigned int)*(_QWORD *)(v80 + 216)) & 0xFFFFFFFC) == 0 )
    {
      v107 = 556;
      goto LABEL_90;
    }
    v159 = 1;
    v90 = (void *)skb_push(v80, 4);
    qdf_mem_copy(v90, &v159, 4u);
    v91 = *(_DWORD *)(v80 + 112);
    v92 = *(_QWORD *)(v80 + 216);
    v93 = *(_QWORD *)(v80 + 224);
    v160[0] = v91 + 24;
    v160[1] = 65553;
    v160[2] = pkt_stats_fill_headers_nlmsg_seq++;
    v161 = 0;
    v162 = 20560;
    v163 = bswap32(v91) >> 16;
    if ( (unsigned int)(v93 - v92) <= 0x17 )
    {
      v107 = 579;
      goto LABEL_90;
    }
    v94 = (void *)skb_push(v80, 24);
    qdf_mem_copy(v94, v160, 0x18u);
    v95 = nl_srv_bcast(v76[2], 4, 17);
    if ( (v95 & 0x80000000) != 0 )
    {
      ++dword_826CB0;
      qdf_trace_msg(
        0x38u,
        4u,
        "%s: Send Failed %d drop_count = %u",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "pktlog_send_per_pkt_stats_to_user",
        v95);
      if ( (v64 & 1) != 0 )
        goto LABEL_77;
    }
    else if ( (v64 & 1) != 0 )
    {
      goto LABEL_77;
    }
    v64 = 0;
LABEL_79:
    v104 = raw_spin_lock_irqsave(&dword_826CB4);
    v76[2] = v74;
    v105 = v104;
    v106 = (__int64 **)qword_826C90;
    if ( v76 == &qword_826C88 || (__int64 *)qword_826C90 == v76 || *(__int64 **)qword_826C90 != &qword_826C88 )
    {
      _list_add_valid_or_report(v76, qword_826C90);
    }
    else
    {
      qword_826C90 = (__int64)v76;
      *v76 = (__int64)&qword_826C88;
      v76[1] = (__int64)v106;
      *v106 = v76;
    }
    raw_spin_unlock_irqrestore(&dword_826CB4, v105);
    if ( (__int64 *)qword_826C98 == &qword_826C98 || (byte_826C68 & 1) != 0 )
      goto LABEL_122;
  }
  v107 = 546;
LABEL_90:
  qdf_trace_msg(
    0x38u,
    2u,
    "VPKT [%d]: Insufficient headroom, head[%pK], data[%pK], req[%zu]",
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v107);
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: Failed to fill headers %d",
    v108,
    v109,
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    "pktlog_send_per_pkt_stats_to_user",
    4294967291LL);
LABEL_77:
  consume_skb(v76[2]);
  v64 = 1;
  goto LABEL_79;
}
