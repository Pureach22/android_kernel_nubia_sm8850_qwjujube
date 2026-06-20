__int64 __fastcall nb7vpq904m_notify_connect(__int64 a1, _BOOL4 a2)
{
  __int64 v3; // x0
  _BOOL4 v4; // w20
  int v5; // w9
  _DWORD *v6; // x20
  _BOOL4 v7; // w8
  unsigned __int8 v8; // w8
  int v9; // w8
  char v10; // w9
  __int64 v11; // x0
  __int64 v12; // x2

  v3 = *(_QWORD *)(a1 + 112);
  if ( v3 && (*(_BYTE *)(a1 + 166) & 1) == 0 )
  {
    v4 = a2;
    *(_BYTE *)(a1 + 166) = 1;
    regulator_set_load(v3, 260000);
    regulator_set_voltage(*(_QWORD *)(a1 + 112), 1710000, 1890000);
    regulator_enable(*(_QWORD *)(a1 + 112));
    a2 = v4;
  }
  v5 = *(_DWORD *)(a1 + 124);
  if ( !v5 )
  {
    *(_DWORD *)(a1 + 120) = a2;
    v6 = (_DWORD *)(a1 + 120);
    v9 = *(unsigned __int8 *)(a1 + 165);
    *(_DWORD *)(a1 + 124) = 1;
    if ( v9 )
      v7 = !a2;
    else
      v7 = a2;
LABEL_15:
    if ( v7 )
      v10 = 59;
    else
      v10 = 11;
    if ( v7 )
      v8 = v10;
    else
      v8 = -53;
    goto LABEL_21;
  }
  *(_DWORD *)(a1 + 120) = a2;
  v6 = (_DWORD *)(a1 + 120);
  if ( *(_BYTE *)(a1 + 165) )
    v7 = !a2;
  else
    v7 = a2;
  if ( v5 <= 2 )
  {
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
      {
        v8 = -11;
        goto LABEL_21;
      }
LABEL_33:
      v8 = 0;
      goto LABEL_21;
    }
    goto LABEL_15;
  }
  if ( v5 != 3 )
  {
    if ( v5 == 4 )
    {
      v8 = -5;
      goto LABEL_21;
    }
    goto LABEL_33;
  }
  if ( v7 )
    v8 = -15;
  else
    v8 = -13;
LABEL_21:
  v11 = *(_QWORD *)(a1 + 96);
  *(_BYTE *)(a1 + 164) = v8;
  if ( (regmap_write(v11, 0, v8) & 0x80000000) != 0 )
    dev_err(*(_QWORD *)(a1 + 88), "writing reg 0x%02x failure\n", 0);
  if ( *(_BYTE *)(a1 + 167) == 1 )
  {
    if ( (*(_DWORD *)(a1 + 124) & 0xFFFFFFFE) == 2 )
      v12 = *v6 != 0;
    else
      v12 = 2;
    if ( (regmap_write(*(_QWORD *)(a1 + 96), 9, v12) & 0x80000000) != 0 )
      dev_err(*(_QWORD *)(a1 + 88), "writing reg 0x%02x failure\n", 9);
  }
  nb7vpq904m_channel_update(a1);
  return 0;
}
