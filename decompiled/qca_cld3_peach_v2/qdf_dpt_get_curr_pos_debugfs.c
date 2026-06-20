__int64 __fastcall qdf_dpt_get_curr_pos_debugfs(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v11; // x2

  if ( (byte_7F7658 & 1) == 0 )
  {
    v11 = "%s: Tracing Disabled";
LABEL_7:
    qdf_trace_msg(0x38u, 8u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "qdf_dpt_get_curr_pos_debugfs");
    return 13;
  }
  if ( !dword_7F7648 )
  {
    v11 = "%s: no packets";
    goto LABEL_7;
  }
  if ( a2 == 2 )
    return (unsigned int)dword_7F765C;
  qdf_debugfs_printf(
    a1,
    "DPT: config - bitmap 0x%x verb %u #rec %u rec_requested %u live_config %u thresh %u time_limit %u\n",
    dword_7F764C,
    (unsigned __int8)byte_7F7656,
    (unsigned __int8)byte_7F7650,
    (unsigned __int16)dword_7F7652,
    (unsigned __int8)byte_7F7659,
    (unsigned __int8)byte_7F7667,
    (unsigned __int16)word_7F7668);
  qdf_debugfs_printf(
    a1,
    "STATS |DPT: icmp(%u %u) arp(%u %u) icmpv6(%u %u %u %u %u %u) dhcp(%u %u %u %u %u %u) eapol(%u %u %u %u %u)\n",
    (unsigned __int16)word_7F768E,
    (unsigned __int16)word_7F7690,
    (unsigned __int16)word_7F7674,
    (unsigned __int16)word_7F7676,
    (unsigned __int16)word_7F7692,
    (unsigned __int16)word_7F7694,
    (unsigned __int16)word_7F7696,
    (unsigned __int16)word_7F7698,
    (unsigned __int16)word_7F769C,
    (unsigned __int16)word_7F769E,
    (unsigned __int16)word_7F7678,
    (unsigned __int16)word_7F767C,
    (unsigned __int16)word_7F767A,
    (unsigned __int16)word_7F767E,
    (unsigned __int16)word_7F7680,
    (unsigned __int16)word_7F7682,
    (unsigned __int16)word_7F7684,
    (unsigned __int16)word_7F7686,
    (unsigned __int16)word_7F7688,
    (unsigned __int16)word_7F768A,
    (unsigned __int16)word_7F768C);
  qdf_debugfs_printf(
    a1,
    "DPT: Total Records: %d, Head: %d, Tail: %d\n",
    dword_7F7648,
    g_qdf_dp_trace_data,
    HIDWORD(g_qdf_dp_trace_data));
  raw_spin_lock_bh(&l_dp_trace_lock);
  if ( (_DWORD)g_qdf_dp_trace_data != -1 )
  {
    dword_7F765C = 0;
    dword_7F7660 = HIDWORD(g_qdf_dp_trace_data);
  }
  raw_spin_unlock_bh(&l_dp_trace_lock);
  return (unsigned int)dword_7F7660;
}
