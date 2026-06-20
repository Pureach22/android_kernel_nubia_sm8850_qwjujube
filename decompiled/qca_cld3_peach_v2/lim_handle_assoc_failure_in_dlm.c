__int64 __fastcall lim_handle_assoc_failure_in_dlm(unsigned __int16 a1)
{
  unsigned int v1; // w8
  __int64 result; // x0
  unsigned int v3; // w8

  v1 = a1;
  result = 1;
  if ( v1 > 0x12 || ((1 << v1) & 0x61000) == 0 )
  {
    v3 = v1 - 130;
    if ( v3 > 9 || ((1 << v3) & 0x221) == 0 )
      return 0;
  }
  return result;
}
