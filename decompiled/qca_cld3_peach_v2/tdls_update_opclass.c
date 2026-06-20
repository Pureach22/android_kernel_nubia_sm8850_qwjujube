__int64 __fastcall tdls_update_opclass(__int64 a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  int v5; // w8
  __int64 v6; // x2

  result = tdls_find_opclass(a1, a2[11], a2[10]);
  a2[13] = result;
  if ( !(_BYTE)result )
  {
    v5 = a2[10];
    if ( v5 == 3 )
    {
      v6 = 1;
    }
    else
    {
      if ( v5 != 1 )
        return result;
      v6 = 3;
    }
    result = tdls_find_opclass(a1, a2[11], v6);
    a2[13] = result;
  }
  return result;
}
