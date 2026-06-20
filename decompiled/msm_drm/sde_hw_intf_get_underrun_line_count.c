__int64 __fastcall sde_hw_intf_get_underrun_line_count(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w0

  if ( result )
  {
    v1 = result;
    v2 = sde_reg_read(result, 8);
    if ( v2 >= 0x10000 )
      return (unsigned int)sde_reg_read(v1, 616) / HIWORD(v2);
    else
      return 3954043821LL;
  }
  return result;
}
