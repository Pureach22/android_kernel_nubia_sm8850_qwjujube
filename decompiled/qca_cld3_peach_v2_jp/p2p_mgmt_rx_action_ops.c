__int64 __fastcall p2p_mgmt_rx_action_ops(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  _QWORD v21[2]; // [xsp+8h] [xbp-28h] BYREF
  int v22; // [xsp+18h] [xbp-18h]
  int v23; // [xsp+1Ch] [xbp-14h]
  __int64 (__fastcall *v24)(); // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: psoc:%pK, is register rx:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "p2p_mgmt_rx_action_ops",
    a1,
    a2 & 1);
  v21[1] = tgt_p2p_mgmt_frame_rx_cb;
  v21[0] = 31;
  v22 = 28;
  v24 = tgt_p2p_mgmt_frame_rx_cb;
  if ( (a2 & 1) != 0 )
    result = wlan_mgmt_txrx_register_rx_cb(a1, 5u, (__int64)v21, 2u, v12, v13, v14, v15, v16, v17, v18, v19);
  else
    result = wlan_mgmt_txrx_deregister_rx_cb(a1, 5u, (__int64)v21, 2u, v12, v13, v14, v15, v16, v17, v18, v19);
  _ReadStatusReg(SP_EL0);
  return result;
}
