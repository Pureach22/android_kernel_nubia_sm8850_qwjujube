__int64 __fastcall adreno_perfcounter_restore(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned __int64 v3; // x8
  unsigned __int64 i; // x21
  __int64 v5; // x23
  unsigned __int64 v6; // x9
  __int64 v7; // x24
  unsigned __int64 j; // x25
  __int64 v9; // x8
  __int64 (__fastcall *v10)(__int64, __int64); // x9

  v1 = *(_QWORD *)(*(_QWORD *)(result + 14264) + 48LL);
  if ( v1 )
  {
    v2 = result;
    if ( *(_BYTE *)(result + 23968) == 1 )
    {
      v3 = *(unsigned int *)(v1 + 8);
      if ( (_DWORD)v3 )
      {
        for ( i = 0; i < v3; ++i )
        {
          v5 = *(_QWORD *)v1 + 56 * i;
          if ( *(_QWORD *)(v5 + 48) )
          {
            v6 = *(unsigned int *)(v5 + 8);
            if ( (_DWORD)v6 )
            {
              v7 = 0;
              for ( j = 0; j < v6; ++j )
              {
                v9 = *(_QWORD *)v5;
                if ( *(_DWORD *)(*(_QWORD *)v5 + v7) <= 0xFFFFFFFD )
                {
                  v10 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 48);
                  if ( *((_DWORD *)v10 - 1) != -488708463 )
                    __break(0x8229u);
                  result = v10(v2, v9 + v7);
                  v6 = *(unsigned int *)(v5 + 8);
                }
                v7 += 48;
              }
              v3 = *(unsigned int *)(v1 + 8);
            }
          }
        }
      }
    }
  }
  return result;
}
