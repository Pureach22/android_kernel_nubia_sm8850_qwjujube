__int64 __fastcall lim_get_tpe_ie_length(__int64 a1, _BYTE *a2, unsigned __int16 a3)
{
  __int64 result; // x0
  __int64 v4; // x8
  unsigned int v5; // w11

  if ( !a3 )
    return 0;
  result = 0;
  v4 = a3;
  do
  {
    if ( *a2 )
    {
      v5 = ((unsigned __int8)a2[1] >> 3) & 7;
      result = (unsigned int)result + (unsigned __int8)a2[2] + 3;
      if ( v5 <= 5 )
      {
        if ( ((1 << v5) & 0x15) != 0 )
        {
          if ( a2[11] )
            result = (unsigned int)(result + 1);
          else
            result = (unsigned int)result;
        }
        else if ( (a2[11] & 0xF) != 0 )
        {
          result = (unsigned int)result + (a2[11] & 0xF) + 1;
        }
        else
        {
          result = (unsigned int)result;
        }
      }
    }
    --v4;
    a2 += 27;
  }
  while ( v4 );
  return result;
}
