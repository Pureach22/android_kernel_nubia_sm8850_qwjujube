__int64 __fastcall gdsc_disable(__int64 a1)
{
  unsigned int v2; // w20
  void (*v3)(void); // x8
  __int16 v4; // w8
  int v5; // w8
  unsigned int v6; // w20
  unsigned int v7; // w21
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 v11; // x1
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x1
  __int64 v16; // x0
  int v17; // w8
  unsigned int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 1600) == 4 )
  {
    if ( *(_DWORD *)(a1 + 1624) )
    {
      v2 = 0;
      do
      {
        v3 = *(void (**)(void))(**(_QWORD **)(a1 + 1608) + 8LL);
        if ( *((_DWORD *)v3 - 1) != -626910737 )
          __break(0x8228u);
        v3();
        ++v2;
      }
      while ( v2 < *(_DWORD *)(a1 + 1624) );
    }
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  v4 = *(_WORD *)(a1 + 1602);
  if ( (v4 & 0x400) == 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      result = regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1552), 2, 0, 0, 0, 0);
      if ( (result & 0x80000000) != 0 )
        goto LABEL_20;
      v9 = _const_udelay(4295);
      v10 = ktime_get(v9);
      while ( 1 )
      {
        if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
        {
          v11 = (unsigned int)(*(_DWORD *)(a1 + 1552) + 4);
        }
        else
        {
          v11 = *(unsigned int *)(a1 + 1564);
          if ( !(_DWORD)v11 )
            v11 = *(unsigned int *)(a1 + 1552);
        }
        v12 = *(_QWORD *)(a1 + 1544);
        v18 = 0;
        v13 = regmap_read(v12, v11, &v18);
        if ( (_DWORD)v13 )
          break;
        v14 = HIWORD(v18) & 1;
        if ( (*(_WORD *)(a1 + 1602) & 0x20) == 0 )
          v14 = v18 >> 31;
        if ( v14 )
          break;
        if ( ktime_get(v13) - v10 >= 2000000 )
        {
          if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
          {
            v15 = (unsigned int)(*(_DWORD *)(a1 + 1552) + 4);
          }
          else
          {
            v15 = *(unsigned int *)(a1 + 1564);
            if ( !(_DWORD)v15 )
              v15 = *(unsigned int *)(a1 + 1552);
          }
          v16 = *(_QWORD *)(a1 + 1544);
          v18 = 0;
          if ( !(unsigned int)regmap_read(v16, v15, &v18) )
          {
            v17 = HIWORD(v18) & 1;
            if ( (*(_WORD *)(a1 + 1602) & 0x20) == 0 )
              v17 = v18 >> 31;
            if ( !v17 )
            {
              result = 4294967186LL;
              goto LABEL_20;
            }
          }
          break;
        }
      }
    }
    v5 = *(unsigned __int8 *)(a1 + 1600);
    if ( (v5 & 1) != 0 )
    {
      v6 = (*(_WORD *)(a1 + 1602) & 0x100) != 0 ? 0x4000 : 24576;
      if ( *(_DWORD *)(a1 + 1584) )
      {
        v7 = 0;
        do
          regmap_update_bits_base(
            *(_QWORD *)(a1 + 1544),
            *(unsigned int *)(*(_QWORD *)(a1 + 1576) + 4LL * (int)v7++),
            v6,
            0,
            0,
            0,
            0);
        while ( v7 < *(_DWORD *)(a1 + 1584) );
        v5 = *(unsigned __int8 *)(a1 + 1600);
      }
    }
    if ( v5 != 6 )
    {
      result = gdsc_toggle_logic(a1, 0, *(_BYTE *)(a1 + 1336));
      if ( (_DWORD)result )
        goto LABEL_20;
      if ( (*(_WORD *)(a1 + 1602) & 2) != 0 )
        regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1568), 1, 1, 0, 0, 0);
    }
    goto LABEL_19;
  }
  result = *(_QWORD *)(a1 + 1640);
  if ( result )
    result = regulator_disable(result);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
