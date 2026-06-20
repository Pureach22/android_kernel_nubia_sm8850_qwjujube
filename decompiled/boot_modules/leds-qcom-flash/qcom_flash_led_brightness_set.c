__int64 __fastcall qcom_flash_led_brightness_set(__int64 a1, int a2)
{
  __int64 *v4; // x21
  bool v5; // w23
  char v6; // w9
  __int64 result; // x0
  __int64 v8; // x22
  __int64 v9; // x24
  __int64 v10; // x24
  unsigned __int64 v11; // x26
  unsigned __int8 v12; // w25
  unsigned __int8 v13; // w22
  __int64 v14; // x1
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v4 = (__int64 *)(a1 - 8);
  v5 = a2 != 0;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_BYTE *)(a1 + 562);
  v15 = *(_DWORD *)(a1 + 532) * a2 / 0xFFu;
  if ( (v6 & 1) != 0 )
  {
LABEL_2:
    result = update_allowed_flash_current(v4, &v15, a2 != 0);
    if ( (result & 0x80000000) == 0 )
    {
      result = set_flash_current(v4, v15, 1);
      if ( !(_DWORD)result )
      {
        if ( *(_BYTE *)(a1 + 560) )
        {
          v8 = *v4;
          v9 = 0;
          while ( 1 )
          {
            result = regmap_fields_update_bits_base(
                       *(_QWORD *)(v8 + 32),
                       *(unsigned __int8 *)(*(_QWORD *)(a1 + 552) + v9),
                       0xFFFFFFFFLL,
                       0,
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            if ( ++v9 >= (unsigned __int64)*(unsigned __int8 *)(a1 + 560) )
              goto LABEL_8;
          }
        }
        else
        {
LABEL_8:
          result = set_flash_module_en(v4, a2 != 0);
          if ( !(_DWORD)result )
          {
            result = set_flash_strobe(v4, a2 != 0);
            if ( !(_DWORD)result )
              *(_BYTE *)(a1 + 562) = v5;
          }
        }
      }
    }
    goto LABEL_19;
  }
  v10 = *(_QWORD *)(a1 - 8);
  if ( *(_BYTE *)(a1 + 560) )
  {
    v11 = 0;
    v12 = 0;
    while ( 1 )
    {
      v13 = *(_BYTE *)(*(_QWORD *)(a1 + 552) + v11);
      result = regmap_fields_update_bits_base(*(_QWORD *)(v10 + 64), v13, 0xFFFFFFFFLL, 1, 0, 0, 0);
      if ( (_DWORD)result )
        break;
      ++v11;
      v12 |= 1LL << v13;
      if ( v11 >= *(unsigned __int8 *)(a1 + 560) )
      {
        v14 = v12;
        goto LABEL_17;
      }
    }
  }
  else
  {
    v14 = 0;
LABEL_17:
    result = regmap_field_update_bits_base(*(_QWORD *)(v10 + 72), v14, 0, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      *(_BYTE *)(a1 + 561) = 0;
      result = set_flash_module_en(v4, 0);
      if ( !(_DWORD)result )
        goto LABEL_2;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
