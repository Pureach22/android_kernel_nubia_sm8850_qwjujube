__int64 __fastcall a6xx_snapshot_vbif_debugbus_block(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  _DWORD *v6; // x23
  unsigned int v7; // w20
  char v8; // w26
  char v9; // w25
  char v10; // w24
  unsigned int i; // w21
  unsigned int j; // w21
  unsigned int k; // w21
  unsigned int m; // w21
  unsigned int n; // w21
  int ii; // w21

  if ( a3 > 0x2AF )
  {
    v6 = a2 + 2;
    *a2 = *a4;
    a2[1] = 170;
    v7 = kgsl_regmap_read(a1 + 1650);
    kgsl_regmap_write(a1 + 1650, v7 | 2);
    kgsl_regmap_write(a1 + 1650, 0);
    v8 = 1;
    kgsl_regmap_write(a1 + 1650, 1);
    v9 = 0;
    do
    {
      v10 = v8;
      kgsl_regmap_write(a1 + 1650, (unsigned int)(0x10000 << v9));
      kgsl_regmap_write(a1 + 1650, 0);
      *v6 = kgsl_regmap_read(a1 + 1650);
      v9 = 1;
      kgsl_regmap_write(a1 + 1650, 1);
      v6[1] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 2);
      v6[2] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 3);
      v6[3] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 4);
      v6[4] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 5);
      v6[5] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 6);
      v6[6] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 7);
      v6[7] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 8);
      v6[8] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 9);
      v6[9] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 10);
      v6[10] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 11);
      v6[11] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 12);
      v6[12] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 13);
      v6[13] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 14);
      v6[14] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 15);
      v8 = 0;
      v6[15] = kgsl_regmap_read(a1 + 1650);
      v6 += 16;
    }
    while ( (v10 & 1) != 0 );
    kgsl_regmap_write(a1 + 1650, 1);
    for ( i = 0; i != 18; ++i )
    {
      kgsl_regmap_write(a1 + 1650, i);
      *v6++ = kgsl_regmap_read(a1 + 1650);
    }
    kgsl_regmap_write(a1 + 1650, 2);
    for ( j = 0; j != 18; ++j )
    {
      kgsl_regmap_write(a1 + 1650, j);
      *v6++ = kgsl_regmap_read(a1 + 1650);
    }
    kgsl_regmap_write(a1 + 1650, 4);
    for ( k = 0; k != 18; ++k )
    {
      kgsl_regmap_write(a1 + 1650, k);
      *v6++ = kgsl_regmap_read(a1 + 1650);
    }
    kgsl_regmap_write(a1 + 1650, 8);
    for ( m = 0; m != 18; ++m )
    {
      kgsl_regmap_write(a1 + 1650, m);
      *v6++ = kgsl_regmap_read(a1 + 1650);
    }
    kgsl_regmap_write(a1 + 1650, 16);
    for ( n = 0; n != 18; ++n )
    {
      kgsl_regmap_write(a1 + 1650, n);
      *v6++ = kgsl_regmap_read(a1 + 1650);
    }
    kgsl_regmap_write(a1 + 1650, 0);
    for ( ii = 0; ii != 4; ++ii )
    {
      kgsl_regmap_write(a1 + 1650, (unsigned int)(1 << ii));
      kgsl_regmap_write(a1 + 1650, 0);
      *v6 = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 1);
      v6[1] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 2);
      v6[2] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 3);
      v6[3] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 4);
      v6[4] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 5);
      v6[5] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 6);
      v6[6] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 7);
      v6[7] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 8);
      v6[8] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 9);
      v6[9] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 10);
      v6[10] = kgsl_regmap_read(a1 + 1650);
      kgsl_regmap_write(a1 + 1650, 11);
      v6[11] = kgsl_regmap_read(a1 + 1650);
      v6 += 12;
    }
    kgsl_regmap_write(a1 + 1650, v7);
    return 688;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a6xx_snapshot_vbif_debugbus_block__rs, "a6xx_snapshot_vbif_debugbus_block") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "DEBUGBUS");
    return 0;
  }
}
