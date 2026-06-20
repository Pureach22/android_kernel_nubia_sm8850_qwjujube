__int64 sub_69F6F8()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_spm_flow_table_attach();
}
