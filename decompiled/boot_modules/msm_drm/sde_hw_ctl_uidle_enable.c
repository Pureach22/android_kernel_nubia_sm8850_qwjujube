__int64 __fastcall sde_hw_ctl_uidle_enable(__int64 result, char a2)
{
  __int64 v3; // x20
  int v4; // w0

  if ( result )
  {
    v3 = result;
    v4 = sde_reg_read(result, 312);
    return sde_reg_write(v3, 312, v4 & 0xFFFFFFFE | a2 & 1, "CTL_UIDLE_ACTIVE");
  }
  return result;
}
