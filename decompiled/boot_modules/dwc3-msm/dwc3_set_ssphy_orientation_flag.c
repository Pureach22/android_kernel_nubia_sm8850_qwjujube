__int64 __fastcall dwc3_set_ssphy_orientation_flag(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  int v3; // w20
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  int v7; // w3
  __int64 v8; // x0
  bool v9; // zf
  __int64 v10; // x8
  unsigned int v11; // w20
  __int64 v12; // x21
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v1 = result;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 456);
  if ( v2 )
    *(_DWORD *)(v2 + 16) &= 0xFFFFFFF3;
  v3 = *(_DWORD *)(result + 1236);
  v13 = 0;
  if ( !v3 )
  {
    if ( *(_BYTE *)(result + 2580) == 1 )
    {
      v8 = gpio_to_desc(*(unsigned int *)(result + 2576));
      v9 = (unsigned int)gpiod_get_raw_value(v8) == 0;
    }
    else
    {
      v10 = *(_QWORD *)(result + 784);
      if ( !v10 )
        goto LABEL_17;
      if ( *(_BYTE *)(result + 746) == 1 && *(_BYTE *)(result + 632) != 1 )
      {
        v11 = 1;
      }
      else
      {
        if ( *(_DWORD *)(result + 752) )
          goto LABEL_17;
        v11 = 2;
      }
      v12 = *(_QWORD *)(v10 + 80LL * *(int *)(result + 792));
      if ( !v12 )
        goto LABEL_17;
      result = extcon_get_state(*(_QWORD *)(v10 + 80LL * *(int *)(result + 792)), v11);
      if ( !(_DWORD)result )
        goto LABEL_17;
      result = extcon_get_property(v12, v11, 1, &v13);
      if ( (_DWORD)result )
        goto LABEL_17;
      v9 = v13 == 0;
    }
    if ( v9 )
      v3 = 4;
    else
      v3 = 8;
    v4 = *(_QWORD *)(v1 + 456);
    if ( v4 )
    {
LABEL_6:
      *(_DWORD *)(v4 + 16) |= v3;
      v5 = *(_QWORD *)(v1 + 456);
      v6 = *(_QWORD *)(v1 + 1256);
      if ( v5 )
      {
        v7 = *(_DWORD *)(v5 + 16);
LABEL_16:
        result = dwc3_dbg_print(v6, 0xFFu, "ss_flag", v7, (const char *)&unk_16A05);
        *(_DWORD *)(v1 + 1240) = v3;
        goto LABEL_17;
      }
LABEL_15:
      v7 = 0;
      goto LABEL_16;
    }
LABEL_14:
    v6 = *(_QWORD *)(v1 + 1256);
    goto LABEL_15;
  }
  if ( (v3 & 0x80000000) == 0 )
  {
    v4 = *(_QWORD *)(result + 456);
    if ( v4 )
      goto LABEL_6;
    goto LABEL_14;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
