__int64 __fastcall sde_hw_pp_dsc_enable(__int64 result)
{
  if ( result )
    return sde_reg_write(result, 0xA0u, 1u, "PP_DSC_MODE");
  return result;
}
