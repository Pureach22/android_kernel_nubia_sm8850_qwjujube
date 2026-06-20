__int64 __fastcall sub_74A080(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_resource_mgr_attach(a1);
}
