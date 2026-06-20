__int64 __fastcall of_property_read_u32_array(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int variable_u32_array; // w0

  variable_u32_array = of_property_read_variable_u32_array(a1, a2, a3, a4, 0);
  return variable_u32_array & (unsigned int)(variable_u32_array >> 31);
}
