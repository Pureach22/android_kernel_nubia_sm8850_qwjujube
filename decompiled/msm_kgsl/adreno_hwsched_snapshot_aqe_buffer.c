__int64 __fastcall adreno_hwsched_snapshot_aqe_buffer(_QWORD *a1, __int64 a2, unsigned __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 v4; // x8
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  unsigned __int64 v9; // x19
  __int64 v10; // x20
  unsigned __int64 v11; // x19

  v4 = 0;
  if ( a4 )
  {
    if ( a4 <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = *(_QWORD *)(a4 + 40);
      if ( v4 )
      {
        if ( v4 + 28 <= a3 )
        {
          *(_QWORD *)(a2 + 20) = v4 >> 2;
          *(_QWORD *)(a2 + 4) = *(_QWORD *)(a4 + 24);
          v6 = a1[9];
          if ( v6 )
          {
            v7 = *(_QWORD *)(v6 + 96);
            if ( v7 && (v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 48)) != nullptr )
            {
              v9 = a4;
              v10 = a2;
              if ( *((_DWORD *)v8 - 1) != 1831526433 )
                __break(0x8228u);
              v6 = v8(v6, a2);
              a2 = v10;
              a4 = v9;
            }
            else
            {
              v6 = 0;
            }
          }
          *(_QWORD *)(a2 + 12) = v6;
          *(_DWORD *)a2 = 5;
          v11 = a4;
          memcpy((void *)(a2 + 28), *(const void **)(a4 + 8), *(_QWORD *)(a4 + 40));
          return *(_QWORD *)(v11 + 40) + 28LL;
        }
        else
        {
          if ( (unsigned int)__ratelimit(&adreno_hwsched_snapshot_aqe_buffer__rs, "adreno_hwsched_snapshot_aqe_buffer") )
            dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "AQE BUFFER");
          return 0;
        }
      }
    }
  }
  return v4;
}
