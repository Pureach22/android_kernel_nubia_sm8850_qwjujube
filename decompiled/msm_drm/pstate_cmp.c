unsigned __int64 __fastcall pstate_cmp(unsigned __int64 result, __int64 *a2)
{
  __int64 *v2; // x8
  __int64 v3; // x9
  __int64 v4; // x10
  int v5; // w11
  int v6; // w12
  int v7; // w9
  int v8; // w10

  if ( result )
  {
    v2 = (__int64 *)result;
    result = 0;
    if ( a2 )
    {
      v3 = *v2;
      if ( *v2 )
      {
        v4 = *a2;
        if ( *a2 )
        {
          v5 = *(_DWORD *)(v3 + 752);
          v6 = *(_DWORD *)(v4 + 752);
          result = (unsigned int)(v5 - v6);
          if ( v5 == v6 )
          {
            v7 = *(_DWORD *)(v3 + 1796);
            v8 = *(_DWORD *)(v4 + 1796);
            result = (unsigned int)(v7 - v8);
            if ( v7 == v8 )
              return (unsigned int)(*(_DWORD *)(v2[1] + 32) - *(_DWORD *)(a2[1] + 32));
          }
        }
        else
        {
          return 0;
        }
      }
    }
  }
  return result;
}
