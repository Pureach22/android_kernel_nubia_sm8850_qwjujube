__int64 __fastcall lim_process_normal_hdd_msg(__int64 a1, unsigned __int16 *a2, char a3)
{
  unsigned int v4; // w8
  bool v5; // cc
  int v6; // w8
  bool v7; // zf
  __int64 v9; // x23
  unsigned int v10; // w21
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0

  if ( (*(_DWORD *)(a1 + 4060) > 1u
     || ((v4 = *a2 - 5139, v5 = v4 > 5, v6 = (1 << v4) & 0x31, !v5) ? (v7 = v6 == 0) : (v7 = 1), v7))
    && *(_BYTE *)(a1 + 8876) )
  {
    if ( (unsigned __int8)((__int64 (*)(void))lim_write_deferred_msg_q)() )
    {
      v9 = jiffies;
      if ( lim_defer_msg___last_ticks - jiffies + 125 < 0 )
      {
        v10 = *a2;
        v11 = lim_msg_str(*a2);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Dropped lim message (0x%X) Message %s",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "lim_defer_msg",
          v10,
          v11);
        lim_defer_msg___last_ticks = v9;
      }
      mac_trace_msg_rx(a1, 255, *a2 | 0x80000000);
      lim_log_session_states(a1, v20, v21, v22, v23, v24, v25, v26, v27);
      goto LABEL_15;
    }
    return mac_trace_msg_rx(a1, 255, *a2 | 0x40000000u);
  }
  else
  {
    if ( a3 )
      *(_BYTE *)(a1 + 4012) = 1;
    result = lim_process_sme_req_messages(a1, a2);
    if ( (result & 1) != 0 )
    {
LABEL_15:
      result = _qdf_mem_free(*((_QWORD *)a2 + 1));
      *((_QWORD *)a2 + 1) = 0;
    }
  }
  return result;
}
