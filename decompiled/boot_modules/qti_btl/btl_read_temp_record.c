__int64 __fastcall btl_read_temp_record(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x11
  int *v10; // x12
  int v11; // t1
  int v12; // w10
  _DWORD *v13; // x15
  int v14; // w9
  int v15; // w13
  int v16; // w11
  int v17; // w14
  int v18; // w13
  unsigned __int16 v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 8);
  v19 = 0;
  result = nvmem_device_read(v5, a2, 2, &v19);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = *(unsigned int *)(a1 + 96);
    v8 = *(_QWORD *)(a1 + 88);
    if ( (int)v7 < 1 )
      goto LABEL_10;
    v9 = 0;
    v10 = *(int **)(a1 + 88);
    while ( 1 )
    {
      v11 = *v10;
      v10 += 2;
      if ( v11 <= v19 )
        break;
      if ( v7 == ++v9 )
      {
        LODWORD(v9) = *(_DWORD *)(a1 + 96);
        break;
      }
    }
    if ( (_DWORD)v9 )
    {
      if ( (_DWORD)v9 == (_DWORD)v7 )
      {
        v12 = *(_DWORD *)(v8 + 8LL * (int)v7 - 4);
      }
      else
      {
        v13 = (_DWORD *)(v8 + 8LL * (unsigned int)v9);
        v15 = *(v13 - 2);
        v14 = *(v13 - 1);
        v16 = v19 - v15;
        if ( v19 == v15 )
        {
          v12 = *(v13 - 1);
        }
        else
        {
          v17 = v13[1];
          v12 = *(v13 - 1);
          if ( v17 != v14 )
          {
            v18 = *v13 - v15;
            if ( v18 )
            {
              v12 = v13[1];
              if ( *v13 != v19 )
                v12 = (v17 - v14) * v16 / v18 + v14;
            }
            else
            {
              v12 = v13[1];
            }
          }
        }
      }
    }
    else
    {
LABEL_10:
      v12 = *(_DWORD *)(v8 + 4);
    }
    result = 0;
    *a3 = v12;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
