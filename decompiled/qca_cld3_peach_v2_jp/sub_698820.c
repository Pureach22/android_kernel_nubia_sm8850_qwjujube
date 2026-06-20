__int64 sub_698820()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_stc_print_active_traffic_map();
}
