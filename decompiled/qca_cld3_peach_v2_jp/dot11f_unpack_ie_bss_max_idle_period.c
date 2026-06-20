__int64 __fastcall dot11f_unpack_ie_bss_max_idle_period(__int64 a1, _BYTE *a2, unsigned __int8 a3, _BYTE *a4)
{
  __int64 result; // x0
  int v5; // w20

  if ( *a4 )
    return 32;
  v5 = a3;
  *a4 = 1;
  if ( a3 <= 1u )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 2, a2, 2u);
    if ( v5 == 2 )
    {
      *a4 = 0;
      return 4;
    }
    else
    {
      result = 0;
      a4[4] = a2[2];
    }
  }
  return result;
}
