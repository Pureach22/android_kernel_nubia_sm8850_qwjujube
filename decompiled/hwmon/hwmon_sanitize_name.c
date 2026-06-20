__int64 __fastcall hwmon_sanitize_name(__int64 a1)
{
  __int64 result; // x0
  _BYTE *i; // x11
  unsigned int v3; // w12

  result = kstrdup(a1, 3264);
  if ( result )
  {
    for ( i = (_BYTE *)result; ; ++i )
    {
      v3 = (unsigned __int8)*i;
      if ( v3 <= 0x2D )
      {
        if ( ((1LL << v3) & 0x240100000600LL) != 0 )
        {
          *i = 95;
        }
        else if ( !*i )
        {
          return result;
        }
      }
    }
  }
  return -12;
}
