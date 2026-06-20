__int64 __fastcall sde_hw_pp_dsc_disable(__int64 result)
{
  __int64 v1; // x19
  int v2; // w0

  if ( result )
  {
    v1 = result;
    v2 = sde_reg_read(result, 0xC8u);
    sde_reg_write(v1, 0xC8u, v2 & 0xFFFBFFFF, "PP_DCE_DATA_OUT_SWAP");
    return sde_reg_write(v1, 0xA0u, 0, "PP_DSC_MODE");
  }
  return result;
}
