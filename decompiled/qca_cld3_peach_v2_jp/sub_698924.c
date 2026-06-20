__int64 sub_698924()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_stc_dump_periodic_stats();
}
