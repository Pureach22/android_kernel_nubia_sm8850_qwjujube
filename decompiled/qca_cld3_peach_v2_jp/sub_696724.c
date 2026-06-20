__int64 __fastcall sub_696724(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_svc_deinit(a1);
}
