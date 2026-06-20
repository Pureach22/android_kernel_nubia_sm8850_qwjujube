__int64 __fastcall set_flash_current(__int64 *a1, int a2, int a3)
{
  __int64 v3; // x22
  unsigned int v4; // w23
  unsigned __int64 v7; // x25
  unsigned __int8 v8; // w24
  unsigned __int8 v9; // w26
  unsigned int v10; // w27
  __int64 v11; // x8
  int v12; // w9
  char v13; // w21
  unsigned __int8 v14; // w8
  __int64 result; // x0
  int v16; // w2
  char v17; // w9
  __int64 v18; // x1
  __int64 v19; // x2

  v3 = *a1;
  if ( a3 )
    v4 = 5000;
  else
    v4 = 12500;
  if ( *((_BYTE *)a1 + 568) )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 1000 * a2 / (unsigned int)*((unsigned __int8 *)a1 + 568) + 1;
    while ( 1 )
    {
      v13 = *(_BYTE *)(a1[70] + v7);
      v14 = v10 > v4 ? v10 / v4 - 1 : 0;
      result = regmap_fields_update_bits_base(
                 *(_QWORD *)(v3 + 40),
                 *(unsigned __int8 *)(a1[70] + v7),
                 0xFFFFFFFFLL,
                 v14,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      v16 = *(_DWORD *)(v3 + 132);
      if ( v16 == 1 )
      {
        v11 = 1LL << v13;
        v12 = 1 << v13;
      }
      else
      {
        if ( v16 )
        {
          dev_err(a1[11], "HW type %d is not supported\n", v16);
          return 4294967201LL;
        }
        v17 = 2 * (v13 & 0x7F);
        v11 = 3LL << v17;
        v12 = 3 << v17;
      }
      ++v7;
      if ( !a3 )
        LOBYTE(v12) = 0;
      v9 |= v11;
      v8 |= v12;
      if ( v7 >= *((unsigned __int8 *)a1 + 568) )
      {
        v18 = v9;
        v19 = v8;
        return regmap_field_update_bits_base(*(_QWORD *)(v3 + 56), v18, v19, 0, 0, 0);
      }
    }
  }
  else
  {
    v18 = 0;
    v19 = 0;
    return regmap_field_update_bits_base(*(_QWORD *)(v3 + 56), v18, v19, 0, 0, 0);
  }
  return result;
}
