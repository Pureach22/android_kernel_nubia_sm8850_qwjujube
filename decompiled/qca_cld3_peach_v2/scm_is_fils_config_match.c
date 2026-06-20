bool __fastcall scm_is_fils_config_match(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int16 v3; // w8
  unsigned __int64 v4; // x10
  int v5; // w11
  int v6; // w8
  unsigned __int64 v7; // x21
  unsigned __int64 v10; // x19
  _BOOL8 result; // x0
  int v13; // w8
  int v14; // w8
  int v15; // w8
  int v16; // w8
  int v17; // w8
  int v18; // w8

  if ( *(_BYTE *)(a1 + 60) != 1 )
    return 1;
  v2 = *(_QWORD *)(a2 + 1728);
  if ( !v2 )
    return 0;
  v3 = *(_WORD *)(v2 + 2);
  if ( (v3 & 0x38) == 0 )
    return 1;
  v4 = v2 + 6;
  v5 = v3 & 0x80;
  v6 = v3 & 0x100;
  v7 = v2 + *(unsigned __int8 *)(v2 + 1);
  if ( v2 + 6 > v7 + 2 || v5 == 0 )
    v4 = v2 + 4;
  if ( v4 + 6 > v7 + 2 || v6 == 0 )
    v10 = v4;
  else
    v10 = v4 + 6;
  if ( v10 > v7 )
    return 0;
  v13 = qdf_mem_cmp((const void *)(a1 + 61), (const void *)v10, 2u);
  result = v13 == 0;
  if ( v13 )
  {
    if ( ((*(unsigned __int16 *)(v2 + 2) >> 3) & 7u) > 1 && v10 + 2 <= v7 )
    {
      v14 = qdf_mem_cmp((const void *)(a1 + 61), (const void *)(v10 + 2), 2u);
      result = v14 == 0;
      if ( v14 )
      {
        if ( ((*(unsigned __int16 *)(v2 + 2) >> 3) & 7u) > 2 && v10 + 4 <= v7 )
        {
          v15 = qdf_mem_cmp((const void *)(a1 + 61), (const void *)(v10 + 4), 2u);
          result = v15 == 0;
          if ( v15 )
          {
            if ( ((*(unsigned __int16 *)(v2 + 2) >> 3) & 7u) >= 4 && v10 + 6 <= v7 )
            {
              v16 = qdf_mem_cmp((const void *)(a1 + 61), (const void *)(v10 + 6), 2u);
              result = v16 == 0;
              if ( v16 )
              {
                if ( ((*(unsigned __int16 *)(v2 + 2) >> 3) & 7u) > 4 && v10 + 8 <= v7 )
                {
                  v17 = qdf_mem_cmp((const void *)(a1 + 61), (const void *)(v10 + 8), 2u);
                  result = v17 == 0;
                  if ( v17 )
                  {
                    if ( ((*(unsigned __int16 *)(v2 + 2) >> 3) & 7u) >= 6 && v10 + 10 <= v7 )
                    {
                      v18 = qdf_mem_cmp((const void *)(a1 + 61), (const void *)(v10 + 10), 2u);
                      result = v18 == 0;
                      if ( v18 )
                      {
                        if ( ((*(unsigned __int16 *)(v2 + 2) >> 3) & 7) == 7 && v10 + 12 <= v7 )
                          return (unsigned int)qdf_mem_cmp((const void *)(a1 + 61), (const void *)(v10 + 12), 2u) == 0;
                      }
                    }
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
