__int64 __fastcall _gsi_config_all_ch_irq(__int64 a1)
{
  unsigned int v1; // w20
  __int64 result; // x0
  int v3; // w21
  unsigned int i; // w22

  v1 = a1;
  result = gsihal_get_bit_map_array_size(a1);
  if ( (_DWORD)result )
  {
    v3 = result;
    for ( i = 0; i != v3; ++i )
    {
      gsihal_read_reg_nk(127, v1, i);
      result = gsihal_write_reg_nk(127, v1, i);
    }
  }
  return result;
}
