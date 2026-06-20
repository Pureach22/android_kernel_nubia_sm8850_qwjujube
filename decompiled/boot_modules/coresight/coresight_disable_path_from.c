__int64 __fastcall coresight_disable_path_from(__int64 result, __int64 a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x22
  __int64 *v4; // x21
  int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x8
  __int64 v10; // x24
  _QWORD *v11; // x8
  __int64 v12; // x23
  __int64 v13; // x9
  __int64 *v14; // x10
  __int64 v15; // x1
  const char *v16; // x2
  const char *v17; // x3
  __int64 v18; // x8
  __int64 *v19; // x9
  __int64 v20; // x2
  const char *v21; // x2
  const char *v22; // x3
  __int64 v23; // x24
  __int64 (__fastcall *v24)(__int64 *, __int64, __int64); // x8
  __int64 v25; // x8
  __int64 v26; // x23
  __int64 (*v27)(void); // x9

  v2 = (_QWORD *)result;
  if ( !a2 )
    a2 = *(_QWORD *)result - 8LL;
  v3 = *(_QWORD **)(a2 + 8);
  if ( v3 != (_QWORD *)result )
  {
    do
    {
      v4 = (__int64 *)*(v3 - 1);
      v5 = *((_DWORD *)v4 + 2);
      if ( v5 == 2 )
      {
        if ( !v2 || (v6 = *(_QWORD *)(v2[1] - 8LL), (*(_DWORD *)(v6 + 8) | 2) != 2) )
          v6 = 0;
        v5 = v4 != (__int64 *)v6;
      }
      switch ( v5 )
      {
        case 3:
          __break(0x800u);
          break;
        case 1:
          if ( v2 && (v9 = *(_QWORD *)(*v2 - 8LL)) != 0 )
          {
            if ( *(_DWORD *)(v9 + 8) == 3 )
              v10 = *(_QWORD *)(*v2 - 8LL);
            else
              v10 = 0;
          }
          else
          {
            v10 = 0;
          }
          v11 = *(_QWORD **)(v3[1] - 8LL);
          if ( v11 )
          {
            v12 = *(_QWORD *)(*v3 - 8LL);
            if ( v12 )
            {
              v13 = *(unsigned int *)(*v11 + 4LL);
              if ( (int)v13 < 1 )
              {
LABEL_33:
                v16 = (const char *)v11[21];
                if ( !v16 )
                  v16 = (const char *)v11[7];
                v17 = (const char *)v4[21];
                if ( !v17 )
                  v17 = (const char *)v4[7];
                dev_err(v11 + 7, "couldn't find output connection, csdev: %s, out_dev: %s\n", v16, v17);
                v15 = -19;
              }
              else
              {
                v14 = *(__int64 **)(*v11 + 8LL);
                while ( 1 )
                {
                  v15 = *v14;
                  if ( (!*(_QWORD *)(*v14 + 40) || *(_QWORD *)(v15 + 48) == v10) && *(__int64 **)(v15 + 16) == v4 )
                    break;
                  --v13;
                  ++v14;
                  if ( !v13 )
                    goto LABEL_33;
                }
              }
              v18 = *(unsigned int *)(*v4 + 4);
              if ( (int)v18 < 1 )
              {
LABEL_45:
                v21 = (const char *)v4[21];
                if ( !v21 )
                  v21 = (const char *)v4[7];
                v22 = *(const char **)(v12 + 168);
                v23 = v15;
                if ( !v22 )
                  v22 = *(const char **)(v12 + 56);
                dev_err(v4 + 7, "couldn't find output connection, csdev: %s, out_dev: %s\n", v21, v22);
                v20 = -19;
                v15 = v23;
              }
              else
              {
                v19 = *(__int64 **)(*v4 + 8);
                while ( 1 )
                {
                  v20 = *v19;
                  if ( (!*(_QWORD *)(*v19 + 40) || *(_QWORD *)(v20 + 48) == v10) && *(_QWORD *)(v20 + 16) == v12 )
                    break;
                  --v18;
                  ++v19;
                  if ( !v18 )
                    goto LABEL_45;
                }
              }
              v24 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(*(_QWORD *)(v4[3] + 8) + 8LL);
              if ( *((_DWORD *)v24 - 1) != -727984260 )
                __break(0x8228u);
              result = v24(v4, v15, v20);
            }
          }
          break;
        case 0:
          v7 = *(v3 - 1);
          v8 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v4[3] + 8LL);
          if ( *((_DWORD *)v8 - 1) != 335626315 )
            __break(0x8228u);
          result = v8(v7);
          break;
      }
      v25 = *v4;
      if ( *(int *)(*v4 + 4) >= 1 )
      {
        v26 = 0;
        do
        {
          result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v25 + 8) + 8 * v26) + 16LL);
          if ( result )
          {
            if ( *(_DWORD *)(result + 8) == 4 )
            {
              v27 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(result + 24) + 24LL) + 8LL);
              if ( v27 )
              {
                if ( *((_DWORD *)v27 - 1) != -1331650805 )
                  __break(0x8229u);
                result = v27();
                v25 = *v4;
              }
            }
          }
          ++v26;
        }
        while ( v26 < *(int *)(v25 + 4) );
      }
      v3 = (_QWORD *)*v3;
    }
    while ( v3 != v2 );
  }
  return result;
}
