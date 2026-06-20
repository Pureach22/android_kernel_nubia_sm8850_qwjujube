__int64 __fastcall sde_hw_mdp_events(__int64 result, char a2)
{
  if ( result )
    return sde_reg_write(result, 0x37Cu, a2 & 1, "HW_EVENTS_CTL");
  return result;
}
