__int64 __fastcall wlan_hdd_pld_notify_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  result = cds_get_conparam();
  if ( (_DWORD)result != 8 )
  {
    result = hdd_wlan_notify_modem_power_state(a3);
    if ( (result & 0x80000000) != 0 )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: Fail to send notify",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "wlan_hdd_notify_handler");
  }
  return result;
}
