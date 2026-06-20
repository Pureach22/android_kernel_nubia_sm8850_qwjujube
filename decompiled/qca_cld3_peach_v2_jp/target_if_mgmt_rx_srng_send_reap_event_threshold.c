__int64 __fastcall target_if_mgmt_rx_srng_send_reap_event_threshold(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 wmi_unified_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  _ReadStatusReg(SP_EL0);
  wmi_unified_hdl = lmac_get_wmi_unified_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( wmi_unified_hdl )
  {
    v21 = wmi_unified_hdl;
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: psoc:%pK, mgmt_rx_reap_thres:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_mgmt_rx_srng_send_reap_event_threshold",
      a1,
      a2);
    result = wmi_unified_pdev_param_send(v21);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0xA5u,
        2u,
        "%s: Fail to send mgmt srng reap event thres",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "target_if_mgmt_rx_srng_send_reap_event_threshold");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid wmi handle",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_mgmt_rx_srng_send_reap_event_threshold");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
