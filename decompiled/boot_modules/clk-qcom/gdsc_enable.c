__int64 __fastcall gdsc_enable(__int64 a1)
{
  unsigned int v2; // w20
  void (*v3)(void); // x8
  __int64 result; // x0
  unsigned int v5; // w20
  void (*v6)(void); // x8
  unsigned int v7; // w20
  void (*v8)(void); // x8
  __int16 v9; // w8
  unsigned int v10; // w20
  unsigned int v11; // w21
  __int16 v12; // w8

  if ( *(_BYTE *)(a1 + 1600) == 4 )
  {
    if ( *(_DWORD *)(a1 + 1624) )
    {
      v2 = 0;
      do
      {
        v3 = *(void (**)(void))(**(_QWORD **)(a1 + 1608) + 16LL);
        if ( *((_DWORD *)v3 - 1) != -626910737 )
          __break(0x8228u);
        v3();
        ++v2;
      }
      while ( v2 < *(_DWORD *)(a1 + 1624) );
    }
    return 0;
  }
  if ( (*(_WORD *)(a1 + 1602) & 8) != 0 )
  {
    if ( *(_DWORD *)(a1 + 1624) )
    {
      v5 = 0;
      do
      {
        v6 = *(void (**)(void))(**(_QWORD **)(a1 + 1608) + 8LL);
        if ( *((_DWORD *)v6 - 1) != -626910737 )
          __break(0x8228u);
        v6();
        ++v5;
      }
      while ( v5 < *(_DWORD *)(a1 + 1624) );
    }
    _const_udelay(4295);
    if ( *(_DWORD *)(a1 + 1624) )
    {
      v7 = 0;
      do
      {
        v8 = *(void (**)(void))(**(_QWORD **)(a1 + 1608) + 16LL);
        if ( *((_DWORD *)v8 - 1) != -626910737 )
          __break(0x8228u);
        v8();
        ++v7;
      }
      while ( v7 < *(_DWORD *)(a1 + 1624) );
    }
  }
  v9 = *(_WORD *)(a1 + 1602);
  if ( (v9 & 2) != 0 )
  {
    if ( (v9 & 0x10) != 0 )
    {
      regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1568), 16, 1, 0, 0, 0);
      _const_udelay(4295);
      regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1568), 16, 0, 0, 0, 0);
    }
    regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1568), 1, 0, 0, 0, 0);
  }
  result = gdsc_toggle_logic(a1, 1, 0);
  if ( !(_DWORD)result )
  {
    if ( (*(_BYTE *)(a1 + 1600) & 1) != 0 )
    {
      v10 = (*(_WORD *)(a1 + 1602) & 0x100) != 0 ? 0x4000 : 24576;
      if ( *(_DWORD *)(a1 + 1584) )
      {
        v11 = 0;
        do
          regmap_update_bits_base(
            *(_QWORD *)(a1 + 1544),
            *(unsigned int *)(*(_QWORD *)(a1 + 1576) + 4LL * (int)v11++),
            v10,
            v10,
            0,
            0,
            0);
        while ( v11 < *(_DWORD *)(a1 + 1584) );
      }
    }
    _const_udelay(4295);
    v12 = *(_WORD *)(a1 + 1602);
    if ( (v12 & 4) != 0 )
    {
      result = regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1552), 2, 2, 0, 0, 0);
      if ( (_DWORD)result )
        return result;
      _const_udelay(4295);
      v12 = *(_WORD *)(a1 + 1602);
    }
    if ( (v12 & 0x80) != 0 )
      regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1552), 2048, 2048, 0, 0, 0);
    return 0;
  }
  return result;
}
