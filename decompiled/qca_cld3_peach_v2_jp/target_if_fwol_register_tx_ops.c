__int64 __fastcall target_if_fwol_register_tx_ops(_QWORD *a1)
{
  *a1 = target_if_fwol_set_elna_bypass;
  a1[1] = target_if_fwol_get_elna_bypass;
  a1[4] = target_if_fwol_set_mdns_config;
  a1[5] = target_if_fwol_get_thermal_stats;
  a1[2] = target_if_fwol_register_event_handler;
  a1[3] = target_if_fwol_unregister_event_handler;
  return 0;
}
