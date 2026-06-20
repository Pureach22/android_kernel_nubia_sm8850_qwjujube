__int64 __fastcall of_property_read_string_index_0(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  int string_helper; // w0

  string_helper = of_property_read_string_helper(a1, a2, a4, 1, a3);
  return string_helper & (unsigned int)(string_helper >> 31);
}
