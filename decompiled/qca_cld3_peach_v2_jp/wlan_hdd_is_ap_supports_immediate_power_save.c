__int64 __fastcall wlan_hdd_is_ap_supports_immediate_power_save(
        unsigned __int8 *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  const char *v11; // x2

  if ( a2 >= 2 )
  {
    if ( a1 )
    {
      if ( !wlan_get_vendor_ie_ptr_from_oui(&unk_A303A4, 3u, a1, a2) )
        return 1;
      v10 = 0;
      v11 = "%s: AP can't support immediate powersave. defer it";
    }
    else
    {
      v10 = 1;
      v11 = "%s: invalid IE pointer";
    }
  }
  else
  {
    v10 = 1;
    v11 = "%s: bss size is less than expected";
  }
  qdf_trace_msg(0x33u, 8u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_is_ap_supports_immediate_power_save");
  return v10;
}
