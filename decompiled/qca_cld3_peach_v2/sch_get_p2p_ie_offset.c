__int64 __fastcall sch_get_p2p_ie_offset(unsigned __int8 *a1, unsigned int a2, _WORD *a3)
{
  unsigned int v4; // w21
  __int16 v6; // w23
  __int64 v7; // x24
  unsigned int v8; // w8
  __int64 result; // x0

  *a3 = 0;
  if ( a2 < 3 )
    return 16;
  v4 = a2;
  v6 = 0;
  do
  {
    v7 = a1[1];
    v8 = v4 - 2;
    v4 = v4 - 2 - v7;
    if ( v8 < (unsigned int)v7 )
      break;
    if ( (unsigned int)v7 >= 4 && *a1 == 221 )
    {
      result = qdf_mem_cmp(a1 + 2, &p2p_oui, 4u);
      if ( !(_DWORD)result )
      {
        *a3 = v6;
        return result;
      }
    }
    a1 += v7 + 2;
    v6 += v7 + 2;
  }
  while ( v4 > 2 );
  return 16;
}
