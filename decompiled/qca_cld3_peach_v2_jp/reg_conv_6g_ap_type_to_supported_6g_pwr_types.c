__int64 __fastcall reg_conv_6g_ap_type_to_supported_6g_pwr_types(unsigned int a1)
{
  if ( a1 > 3 )
    return 13;
  if ( a1 == 3 )
    return 10;
  return reg_conv_6g_ap_type_to_supported_6g_pwr_types_reg_enum_conv[a1];
}
