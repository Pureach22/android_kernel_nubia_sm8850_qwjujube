__int64 __fastcall sub_CD34(__int64 a1)
{
  __asm { SUBG            X24, X29, #0x3B0, #7 }
  return to_mhi_pm_state_str(a1);
}
