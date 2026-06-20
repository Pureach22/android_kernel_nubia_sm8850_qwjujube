__int64 __fastcall sde_hw_ctl_get_flush_sync_mode(__int64 result)
{
  __int64 v1; // x19
  char v2; // w20

  if ( result )
  {
    v1 = result;
    v2 = sde_reg_read(result, 2564);
    return (unsigned int)sde_reg_read(v1, 2560) & ((v2 & 1) == 0);
  }
  return result;
}
