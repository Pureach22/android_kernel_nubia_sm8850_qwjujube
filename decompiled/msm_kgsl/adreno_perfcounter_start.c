__int64 __fastcall adreno_perfcounter_start(__int64 result)
{
  __int64 v1; // x21
  unsigned __int64 v2; // x9
  __int64 v3; // x19
  unsigned __int64 i; // x22
  __int64 v5; // x24
  unsigned __int64 v6; // x8
  __int64 v7; // x25
  unsigned __int64 j; // x20
  __int64 v9; // x9
  __int64 v10; // x1
  __int64 (__fastcall *v11)(_QWORD); // x8

  v1 = *(_QWORD *)(*(_QWORD *)(result + 14264) + 48LL);
  if ( v1 )
  {
    v2 = *(unsigned int *)(v1 + 8);
    if ( (_DWORD)v2 )
    {
      v3 = result;
      for ( i = 0; i < v2; ++i )
      {
        v5 = *(_QWORD *)v1 + 56 * i;
        v6 = *(unsigned int *)(v5 + 8);
        if ( (_DWORD)v6 )
        {
          v7 = 0;
          for ( j = 0; j < v6; ++j )
          {
            if ( *(_DWORD *)(*(_QWORD *)v5 + v7) <= 0xFFFFFFFD )
            {
              v9 = *(_QWORD *)(*(_QWORD *)(v3 + 14264) + 48LL);
              if ( v9 )
              {
                if ( i < *(unsigned int *)(v9 + 8) )
                {
                  v10 = *(_QWORD *)v9 + 56 * i;
                  if ( j < *(unsigned int *)(v10 + 8) )
                  {
                    v11 = *(__int64 (__fastcall **)(_QWORD))(v10 + 32);
                    if ( *((_DWORD *)v11 - 1) != 339051004 )
                      __break(0x8228u);
                    result = v11(v3);
                    v6 = *(unsigned int *)(v5 + 8);
                  }
                }
              }
            }
            v7 += 48;
          }
          v2 = *(unsigned int *)(v1 + 8);
        }
      }
    }
  }
  return result;
}
