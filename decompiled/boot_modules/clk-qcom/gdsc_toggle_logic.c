__int64 __fastcall gdsc_toggle_logic(__int64 a1, int a2, char a3)
{
  unsigned int v6; // w21
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w8
  __int64 v10; // x9
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 updated; // x0
  __int64 v14; // x21
  __int64 v15; // x1
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w8
  int v19; // w8
  __int64 v20; // x1
  __int64 v21; // x0
  unsigned int v22; // w8
  int v23; // w8
  __int64 v24; // x0
  __int64 v25; // x0
  const char *v27; // x2
  int v28; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v6 = 0;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  if ( a2 != 1 )
    goto LABEL_8;
  v7 = *(_QWORD *)(a1 + 1640);
  if ( !v7 )
  {
    v6 = 0;
    v8 = *(_QWORD *)(a1 + 1656);
    if ( !v8 )
      goto LABEL_8;
    goto LABEL_7;
  }
  v6 = regulator_enable(v7);
  if ( (v6 & 0x80000000) != 0 )
    goto LABEL_61;
  v8 = *(_QWORD *)(a1 + 1656);
  if ( v8 )
  {
LABEL_7:
    v6 = icc_set_bw(v8, 0, 1);
    if ( (v6 & 0x80000000) != 0 )
    {
      regulator_disable(*(_QWORD *)(a1 + 1640));
      goto LABEL_61;
    }
  }
LABEL_8:
  regmap_read(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + 1552), &v28);
  if ( (v28 & 2) != 0 )
  {
LABEL_54:
    if ( v6 | a2 )
      goto LABEL_61;
    goto LABEL_55;
  }
  v9 = *(_DWORD *)(a1 + 1560);
  v10 = 1556;
  if ( !v9 )
    v10 = 1552;
  if ( v9 <= 1 )
    v11 = 1;
  else
    v11 = v9;
  if ( a2 )
    v12 = 0;
  else
    v12 = (unsigned int)v11;
  updated = regmap_update_bits_base(*(_QWORD *)(a1 + 1544), *(unsigned int *)(a1 + v10), v11, v12, 0, 0, 0);
  if ( !a2 && (*(_WORD *)(a1 + 1602) & 1) != 0 && (a3 & 1) == 0 )
  {
    v6 = updated;
    _const_udelay(2147500);
    if ( v6 )
      goto LABEL_61;
LABEL_55:
    v24 = *(_QWORD *)(a1 + 1656);
    if ( v24 )
    {
      v6 = icc_set_bw(v24, 0, 0);
      if ( (v6 & 0x80000000) != 0 )
        goto LABEL_61;
      v25 = *(_QWORD *)(a1 + 1640);
      if ( !v25 )
        goto LABEL_61;
    }
    else
    {
      v6 = 0;
      v25 = *(_QWORD *)(a1 + 1640);
      if ( !v25 )
        goto LABEL_61;
    }
    v6 = regulator_disable(v25);
    goto LABEL_61;
  }
  if ( *(_DWORD *)(a1 + 1564) )
    updated = _const_udelay(4295);
  v14 = ktime_get(updated);
  do
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
    v29 = 0;
    v17 = regmap_read(v16, v15, &v29);
    if ( !(_DWORD)v17 )
    {
      v18 = v29;
      if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
      {
        v19 = a2 == 1 ? HIWORD(v29) & 1 : (v29 >> 15) & 1;
      }
      else
      {
        if ( a2 != 1 )
          v18 = ~v29;
        v19 = v18 >> 31;
      }
      if ( !v19 )
        continue;
    }
    goto LABEL_53;
  }
  while ( ktime_get(v17) - v14 < 2000000 );
  if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
  {
    v20 = (unsigned int)(*(_DWORD *)(a1 + 1552) + 4);
  }
  else
  {
    v20 = *(unsigned int *)(a1 + 1564);
    if ( !(_DWORD)v20 )
      v20 = *(unsigned int *)(a1 + 1552);
  }
  v21 = *(_QWORD *)(a1 + 1544);
  v29 = 0;
  if ( (unsigned int)regmap_read(v21, v20, &v29) )
    goto LABEL_53;
  v22 = v29;
  if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
  {
    v23 = a2 == 1 ? HIWORD(v29) & 1 : (v29 >> 15) & 1;
  }
  else
  {
    if ( a2 != 1 )
      v22 = ~v29;
    v23 = v22 >> 31;
  }
  if ( v23 )
  {
LABEL_53:
    v6 = 0;
    goto LABEL_54;
  }
  if ( a2 )
    v27 = "ff";
  else
    v27 = (const char *)&unk_282F4;
  _warn_printk("%s status stuck at 'o%s'", *(const char **)(a1 + 1288), v27);
  v6 = -110;
  __break(0x800u);
  if ( !(a2 | 0xFFFFFF92) )
    goto LABEL_55;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return v6;
}
