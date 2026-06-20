__int64 __fastcall sub_91D8(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { STZ2G           X21, [X2,#-0xD00]! }
  return msm_cdc_init_wcd_supply(a1, a2, a3);
}
