__int64 __fastcall adreno_perfcounter_save(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  unsigned __int64 v3; // x8
  unsigned __int64 i; // x22
  __int64 v5; // x24
  unsigned __int64 v6; // x9
  __int64 v7; // x25
  unsigned __int64 j; // x20
  __int64 v9; // x8
  __int64 v10; // x26
  __int64 v11; // x9
  __int64 v12; // x1
  __int64 (__fastcall *v13)(_QWORD); // x8

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
          v6 = *(unsigned int *)(v5 + 8);
          if ( (_DWORD)v6 )
          {
            v7 = 0;
            for ( j = 0; j < v6; ++j )
            {
              v9 = *(_QWORD *)v5;
              if ( *(_DWORD *)(*(_QWORD *)v5 + v7) <= 0xFFFFFFFD )
              {
                if ( (*(_DWORD *)(v9 + v7 + 20) & 0x80000000) == 0 )
                {
                  *(_QWORD *)(v9 + v7 + 32) = 0;
                  v9 = *(_QWORD *)v5;
                }
                v10 = *(_QWORD *)(v9 + v7 + 32);
                v11 = *(_QWORD *)(*(_QWORD *)(v2 + 14264) + 48LL);
                if ( v11
                  && i < *(unsigned int *)(v11 + 8)
                  && (v12 = *(_QWORD *)v11 + 56 * i, j < *(unsigned int *)(v12 + 8)) )
                {
                  v13 = *(__int64 (__fastcall **)(_QWORD))(v12 + 40);
                  if ( *((_DWORD *)v13 - 1) != -1490883378 )
                    __break(0x8228u);
                  result = v13(v2);
                  v9 = *(_QWORD *)v5;
                }
                else
                {
                  result = 0;
                }
                *(_QWORD *)(v9 + v7 + 32) = result + v10;
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
  return result;
}
