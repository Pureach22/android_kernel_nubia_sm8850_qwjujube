__int64 __fastcall pe_register_mgmt_rx_frm_callback(
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
  __int64 v9; // x0
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  _QWORD v20[3]; // [xsp+8h] [xbp-18h] BYREF

  v20[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 21624);
  v20[1] = pe_handle_mgmt_frame;
  v20[0] = 122;
  v10 = wlan_mgmt_txrx_register_rx_cb(v9, 0, (__int64)v20, 1u, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)v10 )
    v10 = qdf_trace_msg(
            0x35u,
            2u,
            "%s: Registering the PE Handle with MGMT TXRX layer has failed",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "pe_register_mgmt_rx_frm_callback");
  result = wma_register_mgmt_frm_client(v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
