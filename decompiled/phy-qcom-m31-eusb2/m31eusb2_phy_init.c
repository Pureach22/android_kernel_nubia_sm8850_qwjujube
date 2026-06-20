__int64 __fastcall m31eusb2_phy_init(__int64 a1)
{
  __int64 v1; // x19
  unsigned int **v3; // x22
  int v4; // w0
  int v5; // w0
  int v6; // w0
  __int64 v7; // x0
  int v8; // w23
  unsigned int *v9; // x24
  unsigned __int64 v10; // x25
  __int64 v11; // x20
  __int64 v12; // x26
  unsigned int v13; // w21
  int v14; // w0
  __int64 v15; // x23
  unsigned int v16; // w20
  int v17; // w0
  int v18; // w23
  unsigned int *v19; // x24
  unsigned __int64 v20; // x25
  __int64 v21; // x20
  __int64 v22; // x26
  unsigned int v23; // w21
  int v24; // w0
  int v25; // w23
  unsigned int *i; // x22
  unsigned __int64 v27; // x24
  __int64 v28; // x20
  __int64 v29; // x25
  unsigned int v30; // w21
  int v31; // w0
  unsigned int v33; // w19
  int v34; // w0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(unsigned int ***)(v1 + 32);
  if ( (*(_BYTE *)(v1 + 97) & 1) != 0 )
  {
    if ( (*(_BYTE *)(v1 + 98) & 1) != 0 )
      goto LABEL_8;
  }
  else
  {
    v4 = regulator_bulk_enable(3, *(_QWORD *)(v1 + 48));
    if ( v4 )
    {
      v33 = v4;
      dev_err(a1, "failed to enable regulator, %d\n", v4);
      return v33;
    }
    writel_relaxed(1, *(_QWORD *)(v1 + 24));
    *(_BYTE *)(v1 + 97) = 1;
    if ( (*(_BYTE *)(v1 + 98) & 1) != 0 )
      goto LABEL_8;
  }
  v5 = phy_init(*(_QWORD *)(v1 + 88));
  if ( !v5 )
  {
    *(_BYTE *)(v1 + 98) = 1;
LABEL_8:
    v6 = m31eusb2_phy_clocks(v1, 1);
    if ( !v6 )
    {
      v7 = *(_QWORD *)(v1 + 16);
      if ( !v7 || (readl_relaxed(v7) & 1) == 0 )
      {
        reset_control_assert(*(_QWORD *)(v1 + 64));
        _const_udelay(21475);
        reset_control_deassert(*(_QWORD *)(v1 + 64));
        v8 = *((_DWORD *)v3 + 2);
        if ( v8 >= 1 )
        {
          v9 = *v3;
          while ( 1 )
          {
            v10 = v9[1];
            v11 = *v9;
            v12 = *(_QWORD *)(v1 + 8);
            v13 = v9[2] << __clz(__rbit64(v10));
            v14 = readl_relaxed(v12 + v11);
            writel_relaxed(v13 | v14 & ~(_DWORD)v10, v12 + v11);
            if ( ((unsigned int)readl_relaxed(v12 + v11) & (unsigned int)v10) != v13 )
              break;
            --v8;
            v9 += 3;
            if ( !v8 )
              goto LABEL_15;
          }
          printk(&unk_6FB3, v13, (unsigned int)v11);
        }
LABEL_15:
        v15 = *(_QWORD *)(v1 + 8);
        v16 = 16 * (*((_DWORD *)v3 + 11) & 7);
        v17 = readl_relaxed(v15 + 84);
        writel_relaxed(v17 & 0xFFFFFF8F | v16, v15 + 84);
        if ( (readl_relaxed(v15 + 84) & 0x70) != v16 )
          printk(&unk_6FB3, v16, 84);
        v18 = *((_DWORD *)v3 + 6);
        if ( v18 >= 1 )
        {
          v19 = v3[2];
          while ( 1 )
          {
            v20 = v19[1];
            v21 = *v19;
            v22 = *(_QWORD *)(v1 + 8);
            v23 = v19[2] << __clz(__rbit64(v20));
            v24 = readl_relaxed(v22 + v21);
            writel_relaxed(v23 | v24 & ~(_DWORD)v20, v22 + v21);
            if ( ((unsigned int)readl_relaxed(v22 + v21) & (unsigned int)v20) != v23 )
              break;
            --v18;
            v19 += 3;
            if ( !v18 )
              goto LABEL_21;
          }
          printk(&unk_6FB3, v23, (unsigned int)v21);
        }
LABEL_21:
        v25 = *((_DWORD *)v3 + 10);
        if ( v25 >= 1 )
        {
          for ( i = v3[4]; ; i += 3 )
          {
            v27 = i[1];
            v28 = *i;
            v29 = *(_QWORD *)(v1 + 8);
            v30 = i[2] << __clz(__rbit64(v27));
            v31 = readl_relaxed(v29 + v28);
            writel_relaxed(v30 | v31 & ~(_DWORD)v27, v29 + v28);
            if ( ((unsigned int)readl_relaxed(v29 + v28) & (unsigned int)v27) != v30 )
              break;
            if ( !--v25 )
              return 0;
          }
          printk(&unk_6FB3, v30, (unsigned int)v28);
        }
      }
      return 0;
    }
    dev_err(a1, "failed to enable phy clock, %d\n", v6);
    if ( *(_BYTE *)(v1 + 98) )
    {
      phy_exit(*(_QWORD *)(v1 + 88));
      *(_BYTE *)(v1 + 98) = 0;
    }
    if ( !*(_BYTE *)(v1 + 97) )
      return 0;
    goto LABEL_35;
  }
  dev_err(a1, "repeater init failed. %d\n", v5);
  if ( !*(_BYTE *)(v1 + 97) )
    return 0;
LABEL_35:
  v34 = readl_relaxed(*(_QWORD *)(v1 + 24));
  writel_relaxed(v34 & 0xFFFFFFFE, *(_QWORD *)(v1 + 24));
  __dsb(0xFu);
  regulator_bulk_disable(3, *(_QWORD *)(v1 + 48));
  *(_BYTE *)(v1 + 97) = 0;
  return 0;
}
