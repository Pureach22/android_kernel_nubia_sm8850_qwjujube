__int64 __fastcall nb7vpq904m_release_usb_lanes(__int64 a1, _BOOL4 a2, int a3)
{
  int v4; // w8
  __int64 v5; // x0
  _BOOL4 v6; // w20
  int v7; // w8
  int v8; // w9
  _BOOL4 v9; // w8
  unsigned __int8 v10; // w8
  char v11; // w9
  __int64 v12; // x0
  __int64 v13; // x2

  if ( a3 == 4 )
  {
    v4 = 2;
    goto LABEL_5;
  }
  if ( a3 == 2 )
  {
    v4 = 3;
LABEL_5:
    *(_DWORD *)(a1 + 124) = v4;
  }
  v5 = *(_QWORD *)(a1 + 112);
  if ( v5 && (*(_BYTE *)(a1 + 166) & 1) == 0 )
  {
    v6 = a2;
    *(_BYTE *)(a1 + 166) = 1;
    regulator_set_load(v5, 260000);
    regulator_set_voltage(*(_QWORD *)(a1 + 112), 1710000, 1890000);
    regulator_enable(*(_QWORD *)(a1 + 112));
    a2 = v6;
  }
  v7 = *(unsigned __int8 *)(a1 + 165);
  v8 = *(_DWORD *)(a1 + 124);
  *(_DWORD *)(a1 + 120) = a2;
  if ( v7 )
    v9 = !a2;
  else
    v9 = a2;
  if ( v8 > 2 )
  {
    if ( v8 != 3 )
    {
      if ( v8 == 4 )
      {
        v10 = -5;
        goto LABEL_29;
      }
      goto LABEL_19;
    }
    if ( v9 )
      v10 = -15;
    else
      v10 = -13;
  }
  else
  {
    if ( v8 != 1 )
    {
      if ( v8 == 2 )
      {
        v10 = -11;
        goto LABEL_29;
      }
LABEL_19:
      v10 = 0;
      goto LABEL_29;
    }
    if ( v9 )
      v11 = 59;
    else
      v11 = 11;
    if ( v9 )
      v10 = v11;
    else
      v10 = -53;
  }
LABEL_29:
  v12 = *(_QWORD *)(a1 + 96);
  *(_BYTE *)(a1 + 164) = v10;
  if ( (regmap_write(v12, 0, v10) & 0x80000000) != 0 )
    dev_err(*(_QWORD *)(a1 + 88), "writing reg 0x%02x failure\n", 0);
  if ( *(_BYTE *)(a1 + 167) == 1 )
  {
    if ( (*(_DWORD *)(a1 + 124) & 0xFFFFFFFE) == 2 )
      v13 = *(_DWORD *)(a1 + 120) != 0;
    else
      v13 = 2;
    if ( (regmap_write(*(_QWORD *)(a1 + 96), 9, v13) & 0x80000000) != 0 )
      dev_err(*(_QWORD *)(a1 + 88), "writing reg 0x%02x failure\n", 9);
  }
  nb7vpq904m_channel_update(a1);
  return 0;
}
