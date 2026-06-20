unsigned __int8 *__fastcall rmnet_get_endpoint(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x9
  unsigned __int8 *v3; // x8
  bool v4; // zf
  unsigned __int8 *result; // x0
  __int64 v6; // x8

  v2 = *(_QWORD *)(a1 + 8LL * a2 + 16);
  v3 = (unsigned __int8 *)(v2 - 16);
  if ( v2 )
    v4 = v2 == 16;
  else
    v4 = 1;
  if ( v4 )
    return nullptr;
  while ( *v3 != a2 )
  {
    v6 = *((_QWORD *)v3 + 2);
    result = nullptr;
    if ( v6 )
    {
      v3 = (unsigned __int8 *)(v6 - 16);
      if ( v3 )
        continue;
    }
    return result;
  }
  return v3;
}
