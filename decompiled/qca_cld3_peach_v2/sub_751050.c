__int64 sub_751050()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_stc_print_sampling_table();
}
