__int64 __fastcall sme_ext_change_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  unsigned int v31; // w19

  qdf_trace_msg(0x34u, 2u, "%s: Set Channel freq: %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_ext_change_freq", a2);
  if ( (unsigned __int8)wlan_reg_get_channel_state_for_pwrmode(
                          *(_QWORD *)(a1 + 21632),
                          a2,
                          0,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21) )
  {
    result = qdf_mutex_acquire(a1 + 12848);
    if ( !(_DWORD)result )
    {
      v31 = csr_send_ext_change_freq(a1, a2, a3);
      qdf_mutex_release(a1 + 12848);
      return v31;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid channel freq: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sme_ext_change_freq",
      a2);
    return 4;
  }
  return result;
}
