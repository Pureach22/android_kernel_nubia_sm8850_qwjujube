__int64 __fastcall sde_hw_pp_get_line_count(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  unsigned int v3; // w8

  if ( result )
  {
    v1 = result;
    v2 = (unsigned __int16)sde_reg_read(result, 0x10u);
    if ( v2 <= (unsigned __int16)sde_reg_read(v1, 8u) )
    {
      v3 = (unsigned __int16)sde_reg_read(v1, 0x14u);
      result = v3 - v2;
      if ( v3 < v2 )
        return v3 + (v2 ^ 0xFFFF);
    }
    else
    {
      return 0xFFFF;
    }
  }
  return result;
}
