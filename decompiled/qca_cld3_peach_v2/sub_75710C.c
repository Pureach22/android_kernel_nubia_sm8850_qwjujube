__int64 sub_75710C()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_spm_dump_tx_aft();
}
