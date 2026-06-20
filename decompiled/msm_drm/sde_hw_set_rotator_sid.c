__int64 __fastcall sde_hw_set_rotator_sid(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    sde_reg_write(result, 0x20u, 0x1Cu, "MDP_SID_ROT_RD");
    return sde_reg_write(v1, 0x24u, 0x1Cu, "MDP_SID_ROT_WR");
  }
  return result;
}
