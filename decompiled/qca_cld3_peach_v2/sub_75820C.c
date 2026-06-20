__int64 __fastcall sub_75820C(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_spm_flow_table_detach(a1);
}
