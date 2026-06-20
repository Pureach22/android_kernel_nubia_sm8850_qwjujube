__int64 __fastcall wlan_mgmt_rx_srng_htt_setup_send(
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
  _QWORD *context; // x0
  __int64 v11; // x19
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  unsigned int v22; // w19
  const char *v23; // x2

  context = _cds_get_context(71, (__int64)"wlan_mgmt_rx_srng_htt_setup_send", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v11 = (__int64)context;
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x35u);
  if ( comp_private_obj )
  {
    result = dp_send_htt_mgmt_rx_buf_refil_srng_setup(v11, *(_QWORD *)(comp_private_obj + 72));
    if ( !(_DWORD)result )
      return result;
    v22 = result;
    v23 = "%s: mgmt srng htt setup failed";
  }
  else
  {
    v22 = 4;
    v23 = "%s: pdev priv is NULL";
  }
  qdf_trace_msg(0xA5u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_mgmt_rx_srng_htt_setup_send");
  return v22;
}
