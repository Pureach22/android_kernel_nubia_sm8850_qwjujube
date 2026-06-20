__int64 __fastcall sde_hw_dsc_disable(__int64 a1)
{
  return sde_reg_write(a1, 0, 0, "DSC_COMMON_MODE");
}
