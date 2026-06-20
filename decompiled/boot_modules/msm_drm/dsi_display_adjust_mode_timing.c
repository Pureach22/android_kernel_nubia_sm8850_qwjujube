__int64 __fastcall dsi_display_adjust_mode_timing(__int64 result, unsigned int *a2, int a3, unsigned int a4)
{
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x8
  unsigned int v9; // w9
  __int64 v10; // x10
  unsigned int j; // w11
  __int64 v12; // x10
  __int64 v13; // x10
  __int64 v14; // x8
  unsigned int v15; // w9
  __int64 v16; // x10
  unsigned int i; // w11
  __int64 v18; // x9
  __int64 v19; // x10
  int v20; // w8
  bool v21; // zf
  unsigned __int64 v22; // x9
  unsigned int v23; // w8
  unsigned __int64 v24; // x9
  unsigned int v25; // w11
  int v26; // w8
  unsigned __int64 v27; // x14
  bool v28; // zf
  unsigned __int64 v29; // x10
  unsigned int v30; // w8
  unsigned __int64 v31; // x9
  unsigned int v32; // w8

  if ( (a2[40] & 1) != 0 )
  {
    v4 = *(_QWORD *)(result + 264);
    if ( *(_BYTE *)(v4 + 1400) == 1 )
    {
      v5 = *(_DWORD *)(v4 + 1396);
      if ( v5 > 2 )
      {
        if ( v5 == 3 )
        {
          v14 = *((_QWORD *)a2 + 23);
          v15 = *(_DWORD *)(v14 + 2424);
          if ( v15 )
          {
            v16 = *((_QWORD *)a2 + 6);
            for ( i = 0; i < v15; ++i )
            {
              if ( v16 == *(_DWORD *)(*(_QWORD *)(v14 + 2432) + 4LL * (int)i) )
              {
                a2[3] = *(_DWORD *)(*(_QWORD *)(v14 + 2448) + 4LL * (int)i);
                v15 = *(_DWORD *)(v14 + 2424);
              }
            }
          }
        }
        else if ( v5 == 4 )
        {
          v8 = *((_QWORD *)a2 + 23);
          v9 = *(_DWORD *)(v8 + 2424);
          if ( v9 )
          {
            v10 = *((_QWORD *)a2 + 6);
            for ( j = 0; j < v9; ++j )
            {
              if ( v10 == *(_DWORD *)(*(_QWORD *)(v8 + 2432) + 4LL * (int)j) )
              {
                a2[9] = *(_DWORD *)(*(_QWORD *)(v8 + 2448) + 4LL * (int)j);
                v9 = *(_DWORD *)(v8 + 2424);
              }
            }
          }
        }
      }
      else if ( v5 == 1 )
      {
        if ( *((_BYTE *)a2 + 72) == 1 && (v12 = *((_QWORD *)a2 + 10)) != 0 )
        {
          v13 = *(int *)(v12 + 160);
        }
        else if ( *((_BYTE *)a2 + 73) == 1 && (v19 = *((_QWORD *)a2 + 11)) != 0 )
        {
          v13 = *(int *)(v19 + 500);
        }
        else
        {
          v13 = *a2;
        }
        v25 = a2[3];
        v26 = *(_DWORD *)(v4 + 1276);
        v27 = *(unsigned int *)(result + 160);
        v28 = v26 == 1;
        v29 = (v13 + (unsigned __int64)(v25 + a2[1] + a2[2])) / v27;
        if ( v26 == 1 )
          v30 = 7 * (a2[7] + a2[6] + a2[8] + a2[9]) * a4 * a2[11];
        else
          v30 = (a2[7] + a2[6] + a2[8] + a2[9]) * a4 * a2[11];
        if ( v28 )
          v31 = 16 * *((_QWORD *)a2 + 6) * a3;
        else
          v31 = *((_QWORD *)a2 + 6) * a3;
        a2[3] = v25 + v27 * (v31 / v30 - v29);
      }
      else if ( v5 == 2 )
      {
        if ( *((_BYTE *)a2 + 72) == 1 && (v6 = *((_QWORD *)a2 + 10)) != 0 )
        {
          v7 = *(int *)(v6 + 160);
        }
        else if ( *((_BYTE *)a2 + 73) == 1 && (v18 = *((_QWORD *)a2 + 11)) != 0 )
        {
          v7 = *(int *)(v18 + 500);
        }
        else
        {
          v7 = *a2;
        }
        v20 = *(_DWORD *)(v4 + 1276);
        v21 = v20 == 1;
        v22 = (v7 + (unsigned __int64)(a2[3] + a2[1] + a2[2])) / *(unsigned int *)(result + 160) * a4 * a2[11];
        if ( v20 == 1 )
          v23 = 7 * v22;
        else
          v23 = v22;
        if ( v21 )
          v24 = 16 * *((_QWORD *)a2 + 6) * a3;
        else
          v24 = *((_QWORD *)a2 + 6) * a3;
        a2[9] = v24 / v23 - (a2[7] + a2[8] + a2[6]);
      }
      v32 = (unsigned int)(*((_QWORD *)a2 + 6) * a3 / (unsigned __int64)a4) / 0x3E8;
      a2[38] = v32;
      a2[38] = *(_DWORD *)(result + 160) * v32;
    }
  }
  return result;
}
