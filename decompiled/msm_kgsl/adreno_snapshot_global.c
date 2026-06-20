__int64 __fastcall adreno_snapshot_global(_QWORD *a1, __int64 a2, unsigned __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  unsigned __int64 v8; // x19
  __int64 v9; // x20
  unsigned __int64 v10; // x19

  v4 = 0;
  if ( a4 )
  {
    if ( a4 <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = *(_QWORD *)(a4 + 40);
      if ( v4 )
      {
        if ( v4 + 28 > a3 )
        {
          dev_err(*a1, "snapshot: Not enough memory for the memdesc\n");
          return 0;
        }
        else if ( *(_QWORD *)(a4 + 8) )
        {
          *(_QWORD *)(a2 + 20) = v4 >> 2;
          *(_QWORD *)(a2 + 4) = *(_QWORD *)(a4 + 24);
          v5 = a1[9];
          if ( v5 )
          {
            v6 = *(_QWORD *)(v5 + 96);
            if ( v6 && (v7 = *(__int64 (__fastcall **)(__int64, __int64))(v6 + 48)) != nullptr )
            {
              v8 = a4;
              v9 = a2;
              if ( *((_DWORD *)v7 - 1) != 1831526433 )
                __break(0x8228u);
              v5 = v7(v5, a2);
              a2 = v9;
              a4 = v8;
            }
            else
            {
              v5 = 0;
            }
          }
          *(_QWORD *)(a2 + 12) = v5;
          *(_DWORD *)a2 = 5;
          v10 = a4;
          memcpy((void *)(a2 + 28), *(const void **)(a4 + 8), *(_QWORD *)(a4 + 40));
          return *(_QWORD *)(v10 + 40) + 28LL;
        }
        else
        {
          dev_err(*a1, "snapshot: no kernel mapping for global object 0x%016llX\n", *(_QWORD *)(a4 + 24));
          return 0;
        }
      }
    }
  }
  return v4;
}
