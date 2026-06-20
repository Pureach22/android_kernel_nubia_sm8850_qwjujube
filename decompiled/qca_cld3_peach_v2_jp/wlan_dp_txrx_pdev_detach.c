__int64 __fastcall wlan_dp_txrx_pdev_detach(__int64 **a1, unsigned int a2, unsigned int a3)
{
  __int64 v5; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  _DWORD *v16; // x8

  v5 = gp_dp_ctx;
  wlan_dp_stc_detach(gp_dp_ctx);
  dp_rx_fst_detach(v5);
  if ( !a1 || !*a1 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v7, v8, v9, v10, v11, v12, v13, v14, "cdp_pdev_detach");
    return 16;
  }
  v15 = **a1;
  if ( !v15 )
    return 16;
  v16 = *(_DWORD **)(v15 + 56);
  if ( !v16 )
    return 16;
  if ( *(v16 - 1) != 226555140 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64 **, _QWORD, _QWORD))v16)(a1, a2, a3);
}
