__int64 __fastcall sde_hw_intf_enable_wide_bus(__int64 result, char a2)
{
  __int64 v3; // x20
  int v4; // w0

  if ( result )
  {
    v3 = result;
    v4 = sde_reg_read(result, 96);
    return sde_reg_write(v3, 96, v4 & 0xFFFFFFFE | a2 & 1, "INTF_CONFIG2");
  }
  return result;
}
