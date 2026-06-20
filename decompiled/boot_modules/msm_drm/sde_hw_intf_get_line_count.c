__int64 __fastcall sde_hw_intf_get_line_count(__int64 result)
{
  if ( result )
    return (unsigned __int16)sde_reg_read(result, 176);
  return result;
}
