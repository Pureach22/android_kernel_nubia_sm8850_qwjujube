__int64 sub_6984C8()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_stc_print_classified_table();
}
