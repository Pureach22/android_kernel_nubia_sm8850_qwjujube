__int64 __fastcall wlan_global_lmac_if_rx_ops_register(__int64 a1)
{
  if ( a1 )
  {
    wlan_lmac_if_umac_rx_ops_register();
    wlan_lmac_if_sptrl_register_rx_ops(a1);
    return 0;
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: lmac if rx ops pointer is NULL", "wlan_global_lmac_if_rx_ops_register");
    return 4;
  }
}
