__int64 sub_750EF8()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_stc_print_classified_table();
}
