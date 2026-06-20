__int64 __fastcall qcom_flash_strobe_set(__int64 a1, char a2)
{
  __int64 v4; // x19
  __int64 v5; // x23
  unsigned __int64 v6; // x25
  unsigned __int8 v7; // w24
  unsigned __int8 v8; // w22
  __int64 result; // x0
  __int64 v10; // x1
  unsigned int v11; // w8
  __int64 v12; // x24
  __int64 v13; // x23
  unsigned int v14; // w9
  int v15; // w9
  unsigned int v16; // w22

  v4 = a1 - 8;
  v5 = *(_QWORD *)(a1 - 8);
  if ( *(_BYTE *)(a1 + 560) )
  {
    v6 = 0;
    v7 = 0;
    while ( 1 )
    {
      v8 = *(_BYTE *)(*(_QWORD *)(a1 + 552) + v6);
      result = regmap_fields_update_bits_base(*(_QWORD *)(v5 + 64), v8, 0xFFFFFFFFLL, 1, 0, 0, 0);
      if ( (_DWORD)result )
        break;
      ++v6;
      v7 |= 1LL << v8;
      if ( v6 >= *(unsigned __int8 *)(a1 + 560) )
      {
        v10 = v7;
        goto LABEL_7;
      }
    }
  }
  else
  {
    v10 = 0;
LABEL_7:
    result = regmap_field_update_bits_base(*(_QWORD *)(v5 + 72), v10, 0, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      *(_BYTE *)(a1 + 561) = 0;
      result = update_allowed_flash_current(v4, a1 + 540, a2 & 1);
      if ( (result & 0x80000000) == 0 )
      {
        result = set_flash_current(v4, *(unsigned int *)(a1 + 540), 0);
        if ( !(_DWORD)result )
        {
          if ( *(_BYTE *)(a1 + 560) )
          {
            v11 = *(_DWORD *)(a1 + 544);
            v12 = *(_QWORD *)(a1 - 8);
            v13 = 0;
            if ( *(_DWORD *)(a1 + 536) < v11 )
              v11 = *(_DWORD *)(a1 + 536);
            v14 = (unsigned __int8)(v11 / 0xA);
            if ( v14 >= 0x7F )
              v14 = 127;
            v15 = v14 | 0x80;
            if ( v11 )
              v16 = v15;
            else
              v16 = 0;
            while ( 1 )
            {
              result = regmap_fields_update_bits_base(
                         *(_QWORD *)(v12 + 32),
                         *(unsigned __int8 *)(*(_QWORD *)(a1 + 552) + v13),
                         0xFFFFFFFFLL,
                         v16,
                         0,
                         0,
                         0);
              if ( (_DWORD)result )
                break;
              if ( ++v13 >= (unsigned __int64)*(unsigned __int8 *)(a1 + 560) )
                goto LABEL_21;
            }
          }
          else
          {
LABEL_21:
            result = set_flash_module_en(v4, a2 & 1);
            if ( !(_DWORD)result )
              return set_flash_strobe(v4, a2 & 1);
          }
        }
      }
    }
  }
  return result;
}
