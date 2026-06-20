__int64 __fastcall tgt_fwol_register_rx_ops(_QWORD *a1)
{
  *a1 = tgt_fwol_get_elna_bypass_resp;
  a1[1] = notify_thermal_throttle_handler;
  a1[2] = tgt_fwol_get_thermal_stats_resp;
  return 0;
}
