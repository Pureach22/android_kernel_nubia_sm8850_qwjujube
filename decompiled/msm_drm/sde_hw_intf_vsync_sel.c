__int64 __fastcall sde_hw_intf_vsync_sel(__int64 result, char a2)
{
  if ( result )
    return sde_reg_write(result, 640, a2 & 0xF, "INTF_TEAR_MDP_VSYNC_SEL");
  return result;
}
