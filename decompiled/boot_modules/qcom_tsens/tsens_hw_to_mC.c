__int64 __fastcall tsens_hw_to_mC(__int64 *a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v3; // x24
  int v6; // w21
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w9
  int v10; // w23
  int v11; // w8
  int v12; // w9
  int v13; // w9
  int v14; // w8
  int v15; // w10
  int v16; // w9
  int v17; // w25
  int v18; // w10
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v19 = 0;
  if ( a2 >= 0x137 )
    __break(0x5512u);
  v3 = v2 + 48;
  v6 = *(_DWORD *)(*(_QWORD *)(v2 + 2544) + 32LL);
  result = regmap_field_read(*(_QWORD *)(v2 + 48 + 8LL * a2), &v19);
  if ( !(_DWORD)result )
  {
    v8 = *(_QWORD *)(v2 + 2544);
    v9 = v19;
    if ( *(_DWORD *)v8 )
    {
      v10 = *(_DWORD *)(v8 + 28) & v19;
      if ( (*(_DWORD *)(v8 + 24) & v19) == 0 )
      {
        result = regmap_field_read(*(_QWORD *)(v3 + 8LL * a2), &v19);
        if ( (_DWORD)result )
          goto LABEL_24;
        v8 = *(_QWORD *)(v2 + 2544);
        v17 = *(_DWORD *)(v8 + 28) & v19;
        if ( (*(_DWORD *)(v8 + 24) & v19) != 0 )
        {
          v9 = *(_DWORD *)(v8 + 28) & v19;
          goto LABEL_6;
        }
        result = regmap_field_read(*(_QWORD *)(v3 + 8LL * a2), &v19);
        if ( (_DWORD)result )
          goto LABEL_24;
        v8 = *(_QWORD *)(v2 + 2544);
        v9 = *(_DWORD *)(v8 + 28) & v19;
        if ( (*(_DWORD *)(v8 + 24) & v19) != 0 )
          goto LABEL_6;
        if ( v10 != v17 )
        {
          if ( v17 != v9 )
            v9 = 0;
          goto LABEL_6;
        }
      }
      v9 = v10;
    }
LABEL_6:
    if ( (*(_BYTE *)(v8 + 4) & 4) != 0 )
    {
      v13 = 1000 * v9 - *((_DWORD *)a1 + 16);
      v14 = *((_DWORD *)a1 + 18);
      if ( v13 < 1 )
      {
        if ( v13 < 0 )
        {
          if ( v14 >= 0 )
            v18 = *((_DWORD *)a1 + 18);
          else
            v18 = v14 + 1;
          v16 = v13 - (v18 >> 1);
        }
        else
        {
          v16 = 0;
        }
      }
      else
      {
        if ( v14 >= 0 )
          v15 = *((_DWORD *)a1 + 18);
        else
          v15 = v14 + 1;
        v16 = v13 + (v15 >> 1);
      }
      v11 = v16 / v14;
      v12 = 1000;
    }
    else
    {
      v11 = v9 << (31 - v6) >> (31 - v6);
      v12 = 100;
    }
    result = (unsigned int)(v11 * v12);
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
