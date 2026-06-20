_DWORD *__fastcall adreno_rpmh_build_bw_table_cmd(_DWORD *result, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  unsigned __int64 v4; // x9
  _DWORD *v5; // x10
  unsigned int v6; // w8
  unsigned __int64 v7; // x9
  _DWORD *i; // x10

  result[1] = *(_DWORD *)(a2 + 16);
  result[3] = *(_DWORD *)(a2 + 4);
  result[5] = *(_DWORD *)a2;
  v3 = *(_DWORD *)(a2 + 4);
  if ( !v3 )
    goto LABEL_46;
  result[24] = **(_DWORD **)(a2 + 8);
  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 <= 1 )
    goto LABEL_46;
  result[25] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL);
  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 < 3 )
    goto LABEL_46;
  result[26] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 8LL);
  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 < 4 )
    goto LABEL_46;
  result[27] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 12LL);
  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 < 5 )
    goto LABEL_46;
  result[28] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 16LL);
  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 < 6
    || (result[29] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 20LL), v3 = *(_DWORD *)(a2 + 4), v3 < 7)
    || (result[30] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 24LL), v3 = *(_DWORD *)(a2 + 4), v3 < 8)
    || (result[31] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 28LL), v3 = *(_DWORD *)(a2 + 4), v3 <= 8) )
  {
LABEL_46:
    if ( *(_DWORD *)(a2 + 16) )
    {
      v4 = 0;
      v5 = result + 39;
      while ( 1 )
      {
        if ( v3 )
        {
          if ( v4 > 0xF )
            break;
          *(v5 - 7) = **(_DWORD **)(*(_QWORD *)(a2 + 24) + 8 * v4);
          v3 = *(_DWORD *)(a2 + 4);
          if ( v3 >= 2 )
          {
            *(v5 - 6) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8 * v4) + 4LL);
            v3 = *(_DWORD *)(a2 + 4);
            if ( v3 >= 3 )
            {
              *(v5 - 5) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8 * v4) + 8LL);
              v3 = *(_DWORD *)(a2 + 4);
              if ( v3 >= 4 )
              {
                *(v5 - 4) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8 * v4) + 12LL);
                v3 = *(_DWORD *)(a2 + 4);
                if ( v3 >= 5 )
                {
                  *(v5 - 3) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8 * v4) + 16LL);
                  v3 = *(_DWORD *)(a2 + 4);
                  if ( v3 >= 6 )
                  {
                    *(v5 - 2) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8 * v4) + 20LL);
                    v3 = *(_DWORD *)(a2 + 4);
                    if ( v3 >= 7 )
                    {
                      *(v5 - 1) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8 * v4) + 24LL);
                      v3 = *(_DWORD *)(a2 + 4);
                      if ( v3 >= 8 )
                      {
                        *v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8 * v4) + 28LL);
                        v3 = *(_DWORD *)(a2 + 4);
                        if ( v3 > 8 )
                          break;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ++v4;
        v5 += 8;
        if ( v4 >= *(unsigned int *)(a2 + 16) )
          goto LABEL_24;
      }
    }
    else
    {
LABEL_24:
      if ( !a3 )
        return result;
      result[2] = *(_DWORD *)(a3 + 4);
      result[4] = *(_DWORD *)a3;
      v6 = *(_DWORD *)(a3 + 4);
      if ( !v6 )
        goto LABEL_32;
      result[6] = **(_DWORD **)(a3 + 8);
      v6 = *(_DWORD *)(a3 + 4);
      if ( v6 <= 1 )
        goto LABEL_32;
      result[7] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 4LL);
      v6 = *(_DWORD *)(a3 + 4);
      if ( v6 < 3 )
        goto LABEL_32;
      result[8] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 8LL);
      v6 = *(_DWORD *)(a3 + 4);
      if ( v6 < 4
        || (result[9] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 12LL), v6 = *(_DWORD *)(a3 + 4), v6 < 5)
        || (result[10] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 16LL), v6 = *(_DWORD *)(a3 + 4), v6 < 6)
        || (result[11] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 20LL), v6 = *(_DWORD *)(a3 + 4), v6 <= 6) )
      {
LABEL_32:
        if ( !*(_DWORD *)(a3 + 16) )
          return result;
        v7 = 0;
        for ( i = result + 17; ; i += 6 )
        {
          if ( v6 )
          {
            if ( v7 > 1 )
              break;
            *(i - 5) = **(_DWORD **)(*(_QWORD *)(a3 + 24) + 8 * v7);
            v6 = *(_DWORD *)(a3 + 4);
            if ( v6 >= 2 )
            {
              *(i - 4) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 24) + 8 * v7) + 4LL);
              v6 = *(_DWORD *)(a3 + 4);
              if ( v6 >= 3 )
              {
                *(i - 3) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 24) + 8 * v7) + 8LL);
                v6 = *(_DWORD *)(a3 + 4);
                if ( v6 >= 4 )
                {
                  *(i - 2) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 24) + 8 * v7) + 12LL);
                  v6 = *(_DWORD *)(a3 + 4);
                  if ( v6 >= 5 )
                  {
                    *(i - 1) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 24) + 8 * v7) + 16LL);
                    v6 = *(_DWORD *)(a3 + 4);
                    if ( v6 >= 6 )
                    {
                      *i = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 24) + 8 * v7) + 20LL);
                      v6 = *(_DWORD *)(a3 + 4);
                      if ( v6 > 6 )
                        break;
                    }
                  }
                }
              }
            }
          }
          if ( ++v7 >= *(unsigned int *)(a3 + 16) )
            return result;
        }
      }
    }
  }
  __break(0x5512u);
  return result;
}
