__int64 __fastcall qcom_flash_fault_get(__int64 a1, int *a2)
{
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x8
  char *v7; // x10
  int v8; // w22
  unsigned __int8 v9; // w9
  char v10; // t1
  int v11; // w23
  int v12; // w8
  int v13; // w9
  int v14; // w10
  int v15; // w10
  int v16; // w9
  int v17; // w22
  int v18; // w8
  __int64 v19; // x8
  char *v20; // x9
  char v21; // t1
  unsigned int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  v22 = 0;
  result = regmap_field_read(*(_QWORD *)(v4 + 8), &v22);
  if ( !(_DWORD)result )
  {
    v6 = *(unsigned __int8 *)(a1 + 560);
    if ( *(_BYTE *)(a1 + 560) )
    {
      v7 = *(char **)(a1 + 552);
      v8 = 0;
      v9 = 0;
      do
      {
        v10 = *v7++;
        v9 |= 1LL << v10;
        if ( (((unsigned __int64)v22 >> (2 * (v10 & 0x7Fu))) & 1) != 0 )
          v8 |= 8u;
        --v6;
      }
      while ( v6 );
      v11 = v9;
    }
    else
    {
      v11 = 0;
      v8 = 0;
    }
    result = regmap_field_read(*(_QWORD *)(v4 + 16), &v22);
    if ( !(_DWORD)result )
    {
      v12 = *(_DWORD *)(v4 + 132);
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          v13 = 14;
          v14 = 112;
        }
        else
        {
          v14 = 0;
          v13 = 0;
          v12 = 0;
        }
      }
      else
      {
        v12 = 16;
        v13 = 224;
        v14 = 15;
      }
      v15 = (v22 & v14) != 0 ? v8 | 4 : v8;
      v16 = (v22 & v13) != 0 ? v15 | 0x10 : v15;
      v17 = (v22 & v12) != 0 ? v16 | 0x80 : v16;
      result = regmap_field_read(*(_QWORD *)(v4 + 24), &v22);
      if ( !(_DWORD)result )
      {
        v18 = *(_DWORD *)(v4 + 132);
        if ( v18 )
        {
          if ( v18 == 1 )
          {
            v19 = *(unsigned __int8 *)(a1 + 560);
            if ( *(_BYTE *)(a1 + 560) )
            {
              v20 = *(char **)(a1 + 552);
              do
              {
                v21 = *v20++;
                if ( (((unsigned __int64)v22 >> (2 * (v21 & 0x7Fu))) & 1) != 0 )
                  v17 |= 2u;
                --v19;
              }
              while ( v19 );
            }
          }
        }
        else if ( (v22 & v11) != 0 )
        {
          v17 |= 2u;
        }
        result = 0;
        *a2 = v17;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
