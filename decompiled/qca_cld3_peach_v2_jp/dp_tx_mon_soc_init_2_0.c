__int64 __fastcall dp_tx_mon_soc_init_2_0(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  __int64 v11; // x20
  int dp_soc_tx_mon_buf_ring_size; // w0
  __int64 result; // x0

  if ( (unsigned int)dp_srng_init(a1) )
  {
    v10 = "%s: %pK: SRNG setup failed fortx_mon_buf_ring";
  }
  else
  {
    v11 = *(_QWORD *)(a1 + 20056);
    dp_soc_tx_mon_buf_ring_size = wlan_cfg_get_dp_soc_tx_mon_buf_ring_size(*(_QWORD *)(a1 + 40));
    result = dp_mon_desc_pool_init((unsigned int *)(v11 + 696), dp_soc_tx_mon_buf_ring_size);
    if ( !(_DWORD)result )
      return result;
    v10 = "%s: %pK: SRNG setup failed fortx mon desc pool init";
  }
  qdf_trace_msg(0x92u, 2u, v10, v2, v3, v4, v5, v6, v7, v8, v9, "dp_tx_mon_soc_init_2_0", a1);
  return 16;
}
