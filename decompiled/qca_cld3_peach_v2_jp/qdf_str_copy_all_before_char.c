__int64 __fastcall qdf_str_copy_all_before_char(
        __int64 result,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int8 a5)
{
  __int64 v5; // x8
  unsigned int v6; // w11
  __int64 v7; // x9
  int v8; // w12

  if ( result )
  {
    v5 = result;
    result = a2 >= a4 ? a4 : a2;
    if ( (_DWORD)result )
    {
      v6 = a4;
      v7 = 0;
      if ( a4 >= (unsigned __int64)a2 )
        v6 = a2;
      while ( 1 )
      {
        v8 = *(unsigned __int8 *)(v5 + v7);
        if ( !*(_BYTE *)(v5 + v7) || v8 == a5 )
          break;
        *(_BYTE *)(a3 + v7++) = v8;
        if ( v6 == (_DWORD)v7 )
          return result;
      }
      return (unsigned int)v7;
    }
  }
  return result;
}
