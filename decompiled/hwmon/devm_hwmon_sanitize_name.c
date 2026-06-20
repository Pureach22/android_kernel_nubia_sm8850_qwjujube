__int64 __fastcall devm_hwmon_sanitize_name(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _BYTE *i; // x11
  unsigned int v4; // w12

  if ( !a1 )
    return -22;
  result = devm_kstrdup(a1, a2, 3264);
  if ( result )
  {
    for ( i = (_BYTE *)result; ; ++i )
    {
      v4 = (unsigned __int8)*i;
      if ( v4 <= 0x2D )
      {
        if ( ((1LL << v4) & 0x240100000600LL) != 0 )
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
