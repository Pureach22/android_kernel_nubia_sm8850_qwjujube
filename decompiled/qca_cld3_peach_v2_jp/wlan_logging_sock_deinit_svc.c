__int64 __fastcall wlan_logging_sock_deinit_svc(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  _QWORD *v3; // x9
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned __int64 v28; // x10
  unsigned __int64 v31; // x10
  unsigned __int64 v34; // x10
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x10
  unsigned __int64 v43; // x10

  if ( qword_76E1C8 )
  {
    qdf_event_destroy((__int64)dword_76E268, a2);
    __isb(0xFu);
    qword_76E2A0 = _ReadStatusReg(CNTVCT_EL0);
    dword_76E1A0 = 0;
    __dsb(0xEu);
    byte_76E1C0 = 1;
    __dsb(0xEu);
    __isb(0xFu);
    qword_76E2A8 = _ReadStatusReg(CNTVCT_EL0);
    LOBYTE(word_76E1D8) = 0;
    cds_set_multicast_logging(0);
    *(__int16 *)((char *)&word_76E1D8 + 1) = 0;
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v28 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v28 & 0xFFFFFFFFFFFFFFFDLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v31 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v31 & 0xFFFFFFFFFFFFFFFBLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v34 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v34 & 0xFFFFFFFFFFFFFFF7LL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v37 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v37 & 0xFFFFFFFFFFFFFFEFLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v40 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v40 & 0xFFFFFFFFFFFFFFDFLL, (unsigned __int64 *)&qword_76E1D0) );
    _X9 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X9] }
    do
      v43 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v43 & 0xFFFFFFFFFFFFFFBFLL, (unsigned __int64 *)&qword_76E1D0) );
    _wake_up(&unk_76E180, 1, 1, 0);
    wait_for_completion(&dword_76E1A0);
    v2 = raw_spin_lock_irqsave(&dword_76E20C);
    qword_76E200 = 0;
    v3 = (_QWORD *)gpkt_stats_buffers;
    dword_76E210 = 0;
    dword_76E208 = 0;
    v4 = v2;
    if ( *(_QWORD *)(gpkt_stats_buffers + 16) )
    {
      consume_skb(*(_QWORD *)(gpkt_stats_buffers + 16));
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v5 = v3[5];
    if ( v5 )
    {
      consume_skb(v5);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v6 = v3[8];
    if ( v6 )
    {
      consume_skb(v6);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v7 = v3[11];
    if ( v7 )
    {
      consume_skb(v7);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v8 = v3[14];
    if ( v8 )
    {
      consume_skb(v8);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v9 = v3[17];
    if ( v9 )
    {
      consume_skb(v9);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v10 = v3[20];
    if ( v10 )
    {
      consume_skb(v10);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v11 = v3[23];
    if ( v11 )
    {
      consume_skb(v11);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v12 = v3[26];
    if ( v12 )
    {
      consume_skb(v12);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v13 = v3[29];
    if ( v13 )
    {
      consume_skb(v13);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v14 = v3[32];
    if ( v14 )
    {
      consume_skb(v14);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v15 = v3[35];
    if ( v15 )
    {
      consume_skb(v15);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v16 = v3[38];
    if ( v16 )
    {
      consume_skb(v16);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v17 = v3[41];
    if ( v17 )
    {
      consume_skb(v17);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v18 = v3[44];
    if ( v18 )
    {
      consume_skb(v18);
      v3 = (_QWORD *)gpkt_stats_buffers;
    }
    v19 = v3[47];
    if ( v19 )
      consume_skb(v19);
    raw_spin_unlock_irqrestore(&dword_76E20C, v4);
    _qdf_mem_vfree(gpkt_stats_buffers);
    gpkt_stats_buffers = 0;
    byte_76E250 = 0;
    raw_spin_lock(&dword_76E258);
    timer_delete(&unk_76E218);
    timer_delete_sync(&unk_76E218);
    raw_spin_unlock(&dword_76E258);
    v20 = raw_spin_lock_irqsave((char *)&qword_76E148 + 4);
    qword_76E1C8 = 0;
    raw_spin_unlock_irqrestore((char *)&qword_76E148 + 4, v20);
    qdf_ssr_driver_dump_unregister_region("wlan_logs");
    qdf_ssr_driver_dump_unregister_region("gwlan_logging");
    _qdf_minidump_remove((__int64)&gplog_msg, 532480, "wlan_logs");
    _qdf_minidump_remove((__int64)&gwlan_logging, 376, "gwlan_logging");
  }
  return 0;
}
