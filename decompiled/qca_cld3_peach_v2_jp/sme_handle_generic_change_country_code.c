__int64 __fastcall sme_handle_generic_change_country_code(__int64 a1)
{
  unsigned int channel_and_power_list; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  channel_and_power_list = csr_get_channel_and_power_list();
  if ( channel_and_power_list )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: fail to get Channels",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "sme_handle_generic_change_country_code");
  }
  else
  {
    csr_apply_channel_power_info_wrapper(a1);
    csr_update_beacon(a1);
    csr_scan_filter_results(a1);
  }
  return channel_and_power_list;
}
