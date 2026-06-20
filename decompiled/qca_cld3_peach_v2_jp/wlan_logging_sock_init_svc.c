__int64 wlan_logging_sock_init_svc()
{
  const char *v0; // x22
  __int64 v1; // x0
  __int64 *v2; // x10
  __int64 v3; // x9
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x10
  __int64 *v6; // x11
  unsigned __int64 v7; // x12
  unsigned int *v8; // x13
  __int64 *v9; // x2
  __int64 *v10; // x0
  __int64 **v11; // x8
  __int64 v12; // x11
  void *v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // x24
  __int64 v24; // x23
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  __int64 v35; // x2
  __int64 v36; // x9
  __int64 *v37; // x0
  __int64 *v38; // x8
  __int64 v39; // x20
  __int64 v40; // x0
  _QWORD *v41; // x9
  _QWORD *v42; // x8
  __int64 v43; // x10
  __int64 v44; // x11
  unsigned __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  __int64 result; // x0
  _QWORD *v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  unsigned __int64 v81; // x10
  unsigned __int64 v84; // x10
  unsigned __int64 v87; // x10
  unsigned __int64 v90; // x10
  unsigned __int64 v93; // x10
  unsigned __int64 v96; // x10

  dword_76E20C = 0;
  gwlan_logging = 0x10000000000LL;
  qword_76E148 = 2048;
  _qdf_minidump_log((__int64)&gwlan_logging, 376, (__int64)"gwlan_logging");
  v0 = "wlan_logs";
  _qdf_minidump_log((__int64)&gplog_msg, 532480, (__int64)"wlan_logs");
  ((void (__fastcall *)(const char *, __int64 *, __int64))qdf_ssr_driver_dump_register_region)(
    "gwlan_logging",
    &gwlan_logging,
    376);
  ((void (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
    "wlan_logs",
    &gplog_msg,
    532480);
  v1 = raw_spin_lock_irqsave((char *)&qword_76E148 + 4);
  v2 = &qword_76E150;
  v3 = v1;
  qword_76E150 = (__int64)&qword_76E150;
  qword_76E158 = (__int64)&qword_76E150;
  off_76E160 = &off_76E160;
  qword_76E168 = (__int64)&off_76E160;
  qword_76E170 = (__int64)&qword_76E170;
  qword_76E178 = (__int64)&qword_76E170;
  v4 = HIDWORD(gwlan_logging);
  if ( HIDWORD(gwlan_logging) )
  {
    v5 = 0;
    v6 = &qword_76E150;
    v7 = 20;
    v8 = (unsigned int *)&gwlan_logging + 1;
    while ( v7 != 532500 )
    {
      v9 = (__int64 *)*v6;
      v10 = (__int64 *)((char *)&gplog_msg + v7 - 20);
      if ( *(__int64 **)(*v6 + 8) != v6 || v10 == v6 || v10 == v9 )
      {
        _list_add_valid_or_report(v10, v8 + 3);
        v4 = *v8;
        if ( v7 > 0x82000 )
          goto LABEL_12;
      }
      else
      {
        v9[1] = (__int64)v10;
        *v10 = (__int64)v9;
        if ( v7 - 12 > 0x82000 || (*(_QWORD *)((char *)&gplog_msg + v7 - 12) = v6, *v6 = (__int64)v10, v7 > 0x82000) )
        {
LABEL_12:
          __break(1u);
LABEL_13:
          v2 = (__int64 *)qword_76E150;
          goto LABEL_14;
        }
      }
      *(_DWORD *)((char *)&gplog_msg + v7) = v5++;
      v7 += 2080LL;
      if ( v5 >= v4 )
        goto LABEL_13;
    }
    __break(0x5512u);
LABEL_78:
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v81 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v81 & 0xFFFFFFFFFFFFFFFDLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v84 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v84 & 0xFFFFFFFFFFFFFFFBLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v87 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v87 & 0xFFFFFFFFFFFFFFF7LL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v90 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v90 & 0xFFFFFFFFFFFFFFEFLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v93 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v93 & 0xFFFFFFFFFFFFFFDFLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v96 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v96 & 0xFFFFFFFFFFFFFFBFLL, (unsigned __int64 *)&qword_76E1D0) );
    dword_76E1A0 = 0;
    _init_swait_queue_head(&unk_76E1A8, "&x->wait", &init_completion___key_0);
    v45 = kthread_create_on_node(wlan_logging_thread, 0, 0xFFFFFFFFLL, "wlan_logging_thread");
    qword_76E198 = v45;
    if ( v45 <= 0xFFFFFFFFFFFFF000LL )
    {
      wake_up_process(v45);
      __isb(0xFu);
      qword_76E290 = _ReadStatusReg(CNTVCT_EL0);
      word_76E1D8 = 1;
      byte_76E1DA = 0;
      result = qdf_event_create(dword_76E268);
      if ( !(_DWORD)result )
        return result;
      v54 = "%s: Flush log completion event init failed";
    }
    else
    {
      v54 = "%s: Could not Create LogMsg Thread Controller";
    }
    qdf_trace_msg(0x38u, 2u, v54, v46, v47, v48, v49, v50, v51, v52, v53, "wlan_logging_sock_init_svc");
    v56 = *((_QWORD **)v0 + 87);
    v57 = v56[2];
    if ( v57 )
    {
      consume_skb(v57);
      v56 = *((_QWORD **)v0 + 87);
    }
    v58 = v56[5];
    if ( v58 )
    {
      consume_skb(v58);
      v56 = *((_QWORD **)v0 + 87);
    }
    v59 = v56[8];
    if ( v59 )
    {
      consume_skb(v59);
      v56 = *((_QWORD **)v0 + 87);
    }
    v60 = v56[11];
    if ( v60 )
    {
      consume_skb(v60);
      v56 = *((_QWORD **)v0 + 87);
    }
    v61 = v56[14];
    if ( v61 )
    {
      consume_skb(v61);
      v56 = *((_QWORD **)v0 + 87);
    }
    v62 = v56[17];
    if ( v62 )
    {
      consume_skb(v62);
      v56 = *((_QWORD **)v0 + 87);
    }
    v63 = v56[20];
    if ( v63 )
    {
      consume_skb(v63);
      v56 = *((_QWORD **)v0 + 87);
    }
    v64 = v56[23];
    if ( v64 )
    {
      consume_skb(v64);
      v56 = *((_QWORD **)v0 + 87);
    }
    v65 = v56[26];
    if ( v65 )
    {
      consume_skb(v65);
      v56 = *((_QWORD **)v0 + 87);
    }
    v66 = v56[29];
    if ( v66 )
    {
      consume_skb(v66);
      v56 = *((_QWORD **)v0 + 87);
    }
    v67 = v56[32];
    if ( v67 )
    {
      consume_skb(v67);
      v56 = *((_QWORD **)v0 + 87);
    }
    v68 = v56[35];
    if ( v68 )
    {
      consume_skb(v68);
      v56 = *((_QWORD **)v0 + 87);
    }
    v69 = v56[38];
    if ( v69 )
    {
      consume_skb(v69);
      v56 = *((_QWORD **)v0 + 87);
    }
    v70 = v56[41];
    if ( v70 )
    {
      consume_skb(v70);
      v56 = *((_QWORD **)v0 + 87);
    }
    v71 = v56[44];
    if ( v71 )
    {
      consume_skb(v71);
      v56 = *((_QWORD **)v0 + 87);
    }
    v72 = v56[47];
    if ( v72 )
      consume_skb(v72);
    goto LABEL_72;
  }
LABEL_14:
  qword_76E1C8 = (__int64)v2;
  v11 = (__int64 **)v2[1];
  if ( *v11 == v2 && (v12 = *v2, *(__int64 **)(*v2 + 8) == v2) )
  {
    *(_QWORD *)(v12 + 8) = v11;
    *v11 = (__int64 *)v12;
  }
  else
  {
    _list_del_entry_valid_or_report(v2);
  }
  *v2 = (__int64)v2;
  v2[1] = (__int64)v2;
  raw_spin_unlock_irqrestore((char *)&qword_76E148 + 4, v3);
  qword_76E260 = 0;
  dword_76E258 = 0;
  qword_76E240 = (__int64)flush_log_buffers_timer;
  qword_76E248 = 0;
  init_timer_key(&unk_76E218, _os_timer_shim_5, 0x80000, 0, 0);
  byte_76E250 = 1;
  dword_76E254 = 0;
  v13 = (void *)_qdf_mem_valloc(384, "wlan_logging_sock_init_svc", 1254);
  v0 = (const char *)&unk_7F0000;
  gpkt_stats_buffers = (__int64)v13;
  if ( v13 )
  {
    qdf_mem_set(v13, 0x180u, 0);
    v22 = raw_spin_lock_irqsave(&dword_76E20C);
    dword_76E210 = 0;
    qword_76E1E0 = (__int64)&qword_76E1E0;
    qword_76E1E8 = (__int64)&qword_76E1E0;
    qword_76E1F0 = (__int64)&qword_76E1F0;
    qword_76E1F8 = (__int64)&qword_76E1F0;
    raw_spin_unlock_irqrestore(&dword_76E20C, v22);
    v23 = 0;
    v24 = 0;
    while ( 1 )
    {
      v25 = _netdev_alloc_skb(0, 2112, 2080);
      *(_QWORD *)(gpkt_stats_buffers + v23 + 16) = v25;
      if ( !v25 )
        break;
      v34 = raw_spin_lock_irqsave(&dword_76E20C);
      v35 = qword_76E1E0;
      v36 = v34;
      v37 = (__int64 *)(gpkt_stats_buffers + v23);
      if ( *(__int64 **)(qword_76E1E0 + 8) != &qword_76E1E0 || v37 == &qword_76E1E0 || v37 == (__int64 *)qword_76E1E0 )
      {
        _list_add_valid_or_report(v37, &qword_76E1E0);
      }
      else
      {
        v38 = (__int64 *)(gpkt_stats_buffers + v23);
        *(_QWORD *)(qword_76E1E0 + 8) = v37;
        *v38 = v35;
        v38[1] = (__int64)&qword_76E1E0;
        qword_76E1E0 = (__int64)v37;
      }
      raw_spin_unlock_irqrestore(&dword_76E20C, v36);
      ++v24;
      v23 += 24;
      if ( v24 == 16 )
      {
        v40 = raw_spin_lock_irqsave(&dword_76E20C);
        v41 = (_QWORD *)qword_76E1E0;
        qword_76E200 = qword_76E1E0;
        v42 = *(_QWORD **)(qword_76E1E0 + 8);
        v43 = v40;
        if ( *v42 == qword_76E1E0
          && (v44 = *(_QWORD *)qword_76E1E0, *(_QWORD *)(*(_QWORD *)qword_76E1E0 + 8LL) == qword_76E1E0) )
        {
          *(_QWORD *)(v44 + 8) = v42;
          *v42 = v44;
        }
        else
        {
          _list_del_entry_valid_or_report(qword_76E1E0);
        }
        *v41 = v41;
        v41[1] = v41;
        raw_spin_unlock_irqrestore(&dword_76E20C, v43);
        _init_waitqueue_head(&unk_76E180, "&gwlan_logging.wait_queue", &wlan_logging_sock_init_svc___key);
        byte_76E1C0 = 0;
        goto LABEL_78;
      }
    }
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Memory alloc failed for skb",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_logging_sock_init_svc");
    if ( v24 )
    {
      v39 = 16;
      do
      {
        consume_skb(*(_QWORD *)(gpkt_stats_buffers + v39));
        --v24;
        v39 += 24;
      }
      while ( v24 );
    }
LABEL_72:
    v73 = raw_spin_lock_irqsave(&dword_76E20C);
    qword_76E200 = 0;
    raw_spin_unlock_irqrestore(&dword_76E20C, v73);
    _qdf_mem_vfree(*((_QWORD *)v0 + 87));
    *((_QWORD *)v0 + 87) = 0;
    goto LABEL_73;
  }
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: Could not allocate memory for Pkt stats",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_logging_sock_init_svc");
LABEL_73:
  byte_76E250 = 0;
  raw_spin_lock(&dword_76E258);
  timer_delete(&unk_76E218);
  timer_delete_sync(&unk_76E218);
  raw_spin_unlock(&dword_76E258);
  v74 = raw_spin_lock_irqsave((char *)&qword_76E148 + 4);
  qword_76E1C8 = 0;
  raw_spin_unlock_irqrestore((char *)&qword_76E148 + 4, v74);
  qdf_ssr_driver_dump_unregister_region("wlan_logs");
  qdf_ssr_driver_dump_unregister_region("gwlan_logging");
  _qdf_minidump_remove((__int64)&gplog_msg, 532480, "wlan_logs");
  _qdf_minidump_remove((__int64)&gwlan_logging, 376, "gwlan_logging");
  return 4294967284LL;
}
