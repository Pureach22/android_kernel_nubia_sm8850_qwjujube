__int64 __fastcall populate_bound_rows(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v5; // x19
  __int64 v6; // x21
  __int64 v7; // x21
  __int64 v8; // x21
  __int64 v9; // x21
  __int64 v10; // x21
  __int64 v11; // x21

  if ( *(_DWORD *)(result + 132) )
  {
    v5 = result;
    result = scnprintf(a2, a3 - a2, "\n\tID: %llu", *(_QWORD *)(result + 136));
    if ( *(_DWORD *)(v5 + 132) > 1u )
    {
      v6 = a2 + (int)result;
      result = scnprintf(v6, a3 - v6, "\n\tID: %llu", *(_QWORD *)(v5 + 160));
      if ( *(_DWORD *)(v5 + 132) >= 3u )
      {
        v7 = v6 + (int)result;
        result = scnprintf(v7, a3 - v7, "\n\tID: %llu", *(_QWORD *)(v5 + 184));
        if ( *(_DWORD *)(v5 + 132) >= 4u )
        {
          v8 = v7 + (int)result;
          result = scnprintf(v8, a3 - v8, "\n\tID: %llu", *(_QWORD *)(v5 + 208));
          if ( *(_DWORD *)(v5 + 132) >= 5u )
          {
            v9 = v8 + (int)result;
            result = scnprintf(v9, a3 - v9, "\n\tID: %llu", *(_QWORD *)(v5 + 232));
            if ( *(_DWORD *)(v5 + 132) >= 6u )
            {
              v10 = v9 + (int)result;
              result = scnprintf(v10, a3 - v10, "\n\tID: %llu", *(_QWORD *)(v5 + 256));
              if ( *(_DWORD *)(v5 + 132) >= 7u )
              {
                v11 = v10 + (int)result;
                result = scnprintf(v11, a3 - v11, "\n\tID: %llu", *(_QWORD *)(v5 + 280));
                if ( *(_DWORD *)(v5 + 132) >= 8u )
                {
                  result = scnprintf(v11 + (int)result, a3 - (v11 + (int)result), "\n\tID: %llu", *(_QWORD *)(v5 + 304));
                  if ( *(_DWORD *)(v5 + 132) > 8u )
                  {
                    __break(0x5512u);
                    __asm { STGP            X14, X5, [X30,#-0x58]! }
                    return synx_init_debugfs_dir(result);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
