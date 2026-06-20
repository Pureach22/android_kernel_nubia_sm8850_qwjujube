__int64 __fastcall set_flash_strobe(__int64 *a1, char a2)
{
  __int64 v2; // x22
  unsigned __int64 v5; // x24
  unsigned __int8 v6; // w23
  unsigned __int8 v7; // w21
  __int64 result; // x0
  __int64 v9; // x1
  __int64 v10; // x2

  v2 = *a1;
  if ( *((_BYTE *)a1 + 568) )
  {
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      v7 = *(_BYTE *)(a1[70] + v5);
      result = regmap_fields_update_bits_base(*(_QWORD *)(v2 + 64), v7, 0xFFFFFFFFLL, 1, 0, 0, 0);
      if ( (_DWORD)result )
        break;
      ++v5;
      v6 |= 1LL << v7;
      if ( v5 >= *((unsigned __int8 *)a1 + 568) )
      {
        v9 = v6;
        goto LABEL_7;
      }
    }
  }
  else
  {
    v9 = 0;
LABEL_7:
    if ( (a2 & 1) != 0 )
      v10 = (unsigned int)v9;
    else
      v10 = 0;
    result = regmap_field_update_bits_base(*(_QWORD *)(v2 + 72), v9, v10, 0, 0, 0);
    if ( !(_DWORD)result )
      *((_BYTE *)a1 + 569) = a2 & 1;
  }
  return result;
}
