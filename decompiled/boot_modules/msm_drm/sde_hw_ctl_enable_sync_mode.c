__int64 __fastcall sde_hw_ctl_enable_sync_mode(__int64 result, char a2)
{
  __int64 v3; // x20
  int v4; // w0

  if ( result )
  {
    v3 = result;
    v4 = sde_reg_read(result, 2564);
    return sde_reg_write(v3, 2564, v4 & 0xFFFFFFFE | a2 & 1, "CTL_FLUSH_SYNC_MODE");
  }
  return result;
}
