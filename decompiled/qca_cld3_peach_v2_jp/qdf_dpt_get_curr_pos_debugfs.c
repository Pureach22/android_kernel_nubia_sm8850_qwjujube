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

  if ( (byte_73EC28 & 1) == 0 )
  {
    v11 = "%s: Tracing Disabled";
LABEL_7:
    qdf_trace_msg(0x38u, 8u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "qdf_dpt_get_curr_pos_debugfs");
    return 13;
  }
  if ( !dword_73EC18 )
  {
    v11 = "%s: no packets";
    goto LABEL_7;
  }
  if ( a2 == 2 )
    return (unsigned int)dword_73EC2C;
  qdf_debugfs_printf(
    a1,
    "DPT: config - bitmap 0x%x verb %u #rec %u rec_requested %u live_config %u thresh %u time_limit %u\n",
    dword_73EC1C,
    (unsigned __int8)byte_73EC26,
    (unsigned __int8)byte_73EC20,
    (unsigned __int16)dword_73EC22,
    (unsigned __int8)byte_73EC29,
    (unsigned __int8)byte_73EC37,
    (unsigned __int16)word_73EC38);
  qdf_debugfs_printf(
    a1,
    "STATS |DPT: icmp(%u %u) arp(%u %u) icmpv6(%u %u %u %u %u %u) dhcp(%u %u %u %u %u %u) eapol(%u %u %u %u %u)\n",
    (unsigned __int16)word_73EC5E,
    (unsigned __int16)word_73EC60,
    (unsigned __int16)word_73EC44,
    (unsigned __int16)word_73EC46,
    (unsigned __int16)word_73EC62,
    (unsigned __int16)word_73EC64,
    (unsigned __int16)word_73EC66,
    (unsigned __int16)word_73EC68,
    (unsigned __int16)word_73EC6C,
    (unsigned __int16)word_73EC6E,
    (unsigned __int16)word_73EC48,
    (unsigned __int16)word_73EC4C,
    (unsigned __int16)word_73EC4A,
    (unsigned __int16)word_73EC4E,
    (unsigned __int16)word_73EC50,
    (unsigned __int16)word_73EC52,
    (unsigned __int16)word_73EC54,
    (unsigned __int16)word_73EC56,
    (unsigned __int16)word_73EC58,
    (unsigned __int16)word_73EC5A,
    (unsigned __int16)word_73EC5C);
  qdf_debugfs_printf(
    a1,
    "DPT: Total Records: %d, Head: %d, Tail: %d\n",
    dword_73EC18,
    g_qdf_dp_trace_data,
    HIDWORD(g_qdf_dp_trace_data));
  raw_spin_lock_bh(&l_dp_trace_lock);
  if ( (_DWORD)g_qdf_dp_trace_data != -1 )
  {
    dword_73EC2C = 0;
    dword_73EC30 = HIDWORD(g_qdf_dp_trace_data);
  }
  raw_spin_unlock_bh(&l_dp_trace_lock);
  return (unsigned int)dword_73EC30;
}
