__int64 __fastcall sde_hw_ctl_get_flush_register(__int64 result)
{
  __int64 v1; // x19
  char v2; // w20

  if ( result )
  {
    v1 = result;
    v2 = sde_reg_read(result, 192);
    LODWORD(result) = sde_reg_read(v1, 24);
    if ( (v2 & 3) != 0 )
      return (unsigned int)result;
    else
      return (unsigned int)result & 0xF7FFFFFF;
  }
  return result;
}
