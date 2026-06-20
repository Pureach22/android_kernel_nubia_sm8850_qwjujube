__int64 __fastcall atoi(__int64 result)
{
  unsigned __int8 *v1; // x0
  int v2; // w8
  int v3; // w9
  int v4; // t1
  unsigned int v5; // w11
  unsigned __int8 *v6; // x10
  int v7; // w11
  int v8; // t1

  if ( result )
  {
    v1 = (unsigned __int8 *)strim();
    v2 = *v1;
    if ( v2 == 45 || v2 == 43 )
    {
      v4 = *++v1;
      v3 = v4;
    }
    else
    {
      v3 = *v1;
    }
    if ( (unsigned int)(v3 - 48) > 9 )
    {
      v5 = 0;
    }
    else
    {
      v5 = 0;
      v6 = v1 + 1;
      do
      {
        v7 = v3 + 10 * v5;
        v8 = *v6++;
        v3 = v8;
        v5 = v7 - 48;
      }
      while ( (unsigned int)(v8 - 48) < 0xA );
    }
    if ( v2 == 45 )
      return -v5;
    else
      return v5;
  }
  return result;
}
