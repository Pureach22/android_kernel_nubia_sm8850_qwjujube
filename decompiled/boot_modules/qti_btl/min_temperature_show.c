__int64 __fastcall min_temperature_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x11
  int *v9; // x12
  int v10; // t1
  int v11; // w3
  int *v12; // x14
  int v13; // w9
  int v14; // w12
  int v15; // w10
  int v16; // w13
  int v17; // w14
  int v18; // w12
  unsigned __int16 v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v19 = 0;
  LODWORD(result) = nvmem_device_read(*(_QWORD *)(v4 + 8), 92, 2, &v19);
  if ( (result & 0x80000000) == 0 )
  {
    v6 = *(unsigned int *)(v4 + 96);
    v7 = *(_QWORD *)(v4 + 88);
    if ( (int)v6 < 1 )
      goto LABEL_10;
    v8 = 0;
    v9 = *(int **)(v4 + 88);
    while ( 1 )
    {
      v10 = *v9;
      v9 += 2;
      if ( v10 <= v19 )
        break;
      if ( v6 == ++v8 )
      {
        LODWORD(v8) = *(_DWORD *)(v4 + 96);
        break;
      }
    }
    if ( (_DWORD)v8 )
    {
      if ( (_DWORD)v8 == (_DWORD)v6 )
      {
        v11 = *(_DWORD *)(v7 + 8LL * (int)v6 - 4);
      }
      else
      {
        v12 = (int *)(v7 + 8LL * (unsigned int)v8);
        v14 = *(v12 - 2);
        v13 = *(v12 - 1);
        v15 = v19 - v14;
        if ( v19 == v14 )
        {
          v11 = *(v12 - 1);
        }
        else
        {
          v16 = v12[1];
          v11 = *(v12 - 1);
          if ( v16 != v13 )
          {
            v17 = *v12;
            v18 = v17 - v14;
            if ( v18 )
            {
              v11 = v16;
              if ( v17 != v19 )
                v11 = (v16 - v13) * v15 / v18 + v13;
            }
            else
            {
              v11 = v16;
            }
          }
        }
      }
    }
    else
    {
LABEL_10:
      v11 = *(_DWORD *)(v7 + 4);
    }
    LODWORD(result) = scnprintf(a3, 4096, "%d\n", v11);
  }
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
