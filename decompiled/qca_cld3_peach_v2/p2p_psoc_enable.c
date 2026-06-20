__int64 __fastcall p2p_psoc_enable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  _QWORD v10[9]; // [xsp+8h] [xbp-48h] BYREF

  v10[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v10[0] = wlan_p2p_rx_callback;
    v10[1] = a1;
    v10[2] = wlan_p2p_event_callback;
    v10[3] = a1;
    v10[4] = wlan_p2p_action_tx_cnf_callback;
    v10[5] = a1;
    v10[6] = wlan_p2p_lo_event_callback;
    v10[7] = a1;
    result = ucfg_p2p_psoc_start(a1, v10, a2, a3, a4, a5, a6, a7, a8, a9);
  }
  else
  {
    qdf_trace_msg(0x48u, 2u, "%s: psoc null", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_psoc_enable");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
