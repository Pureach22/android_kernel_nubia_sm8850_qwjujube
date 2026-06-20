__int64 __fastcall lim_is_in_mcc(__int64 a1)
{
  int v1; // w11
  unsigned __int8 i; // w9
  __int64 v3; // x13
  int v4; // w13

  if ( *(_WORD *)(a1 + 3992) )
  {
    v1 = 0;
    for ( i = 0; *(unsigned __int16 *)(a1 + 3992) > (unsigned int)i; ++i )
    {
      v3 = *(_QWORD *)(a1 + 12264) + 14000LL * i;
      if ( *(_BYTE *)(v3 + 70) )
      {
        v4 = *(_DWORD *)(v3 + 284);
        if ( v4 )
        {
          if ( v1 )
          {
            if ( v1 != v4 )
              return 1;
          }
          else
          {
            v1 = v4;
          }
        }
      }
    }
  }
  return 0;
}
