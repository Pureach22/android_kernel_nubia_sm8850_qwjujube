__int64 __fastcall dot11f_unpack_ie_wmmts_delay(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, _BYTE *a4)
{
  const void *v5; // x1
  int v6; // t1

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    v6 = *a2;
    v5 = a2 + 1;
    a4[1] = v6;
    if ( v6 != 1 )
    {
      *a4 = 0;
      return 64;
    }
    if ( a3 > 4u )
    {
      qdf_mem_copy(a4 + 4, v5, 4u);
      return 0;
    }
  }
  *a4 = 0;
  return 4;
}
