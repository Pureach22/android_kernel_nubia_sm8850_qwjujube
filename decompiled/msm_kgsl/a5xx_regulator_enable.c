__int64 __fastcall a5xx_regulator_enable(_QWORD *a1)
{
  int v2; // w8
  int v3; // w8
  int v4; // w21
  __int64 v5; // x0
  int v6; // w8
  int v7; // w21
  __int64 v8; // x0
  __int64 v9; // x21
  unsigned int v10; // w22
  __int64 v11; // x21
  unsigned int v12; // w22
  unsigned __int64 v20; // x9
  unsigned __int64 v23; // x9

  if ( (a1[1780] & 0x100) != 0 )
    return 0;
  v2 = *(_DWORD *)a1[1783];
  if ( v2 != 530 && v2 != 540 )
  {
    kgsl_regmap_write(a1 + 1650, 85);
    if ( *((_BYTE *)a1 + 20434) == 1 )
    {
      v11 = a1[1783];
      if ( *(_DWORD *)(v11 + 144) )
      {
        v12 = 0;
        do
          kgsl_regmap_write(a1 + 1650, *(unsigned int *)(*(_QWORD *)(v11 + 136) + 8LL * (int)v12++ + 4));
        while ( v12 < *(_DWORD *)(v11 + 144) );
      }
      kgsl_regmap_write(a1 + 1650, 2863180288LL);
      kgsl_regmap_write(a1 + 1650, 386);
    }
    kgsl_regmap_rmw(a1 + 1650, 103, 255, 0);
    _X8 = a1 + 1780;
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 | 0x100, _X8) );
    return 0;
  }
  kgsl_regmap_write(a1 + 1650, 7831552);
  _const_udelay(12885);
  v3 = -100;
  do
  {
    v4 = v3;
    _const_udelay(4295);
    v5 = kgsl_regmap_read(a1 + 1650);
    if ( (v5 & 0x100000) != 0 )
      break;
    v3 = v4 + 1;
  }
  while ( v4 );
  if ( (v5 & 0x100000) != 0 )
  {
    kgsl_regmap_write(a1 + 1650, 7831552);
    v6 = -100;
    do
    {
      v7 = v6;
      _const_udelay(4295);
      v8 = kgsl_regmap_read(a1 + 1650);
      if ( (v8 & 0x100000) != 0 )
        break;
      v6 = v7 + 1;
    }
    while ( v7 );
    if ( (v8 & 0x100000) != 0 )
    {
      kgsl_regmap_rmw(a1 + 1650, 43136, 1, 0);
      if ( *((_BYTE *)a1 + 20434) == 1 )
      {
        v9 = a1[1783];
        if ( *(_DWORD *)(v9 + 144) )
        {
          v10 = 0;
          do
            kgsl_regmap_write(a1 + 1650, *(unsigned int *)(*(_QWORD *)(v9 + 136) + 8LL * (int)v10++ + 4));
          while ( v10 < *(_DWORD *)(v9 + 144) );
        }
        kgsl_regmap_write(a1 + 1650, 2863180288LL);
        kgsl_regmap_write(a1 + 1650, 386);
      }
      kgsl_regmap_rmw(a1 + 1650, 43136, 1, 1);
      if ( *(_DWORD *)a1[1783] == 540 )
      {
        if ( (unsigned int)kgsl_regmap_read(a1 + 1650) == -1161889074 )
        {
          a5xx_restore_isense_regs_isense_regs_0 = kgsl_regmap_read(a1 + 1650);
          a5xx_restore_isense_regs_isense_regs_1 = kgsl_regmap_read(a1 + 1650);
          a5xx_restore_isense_regs_isense_regs_2 = kgsl_regmap_read(a1 + 1650);
          a5xx_restore_isense_regs_isense_regs_3 = kgsl_regmap_read(a1 + 1650);
          a5xx_restore_isense_regs_isense_regs_4 = kgsl_regmap_read(a1 + 1650);
          a5xx_restore_isense_regs_isense_regs_5 = kgsl_regmap_read(a1 + 1650);
          kgsl_regmap_write(a1 + 1650, 0);
        }
        if ( a5xx_restore_isense_regs_isense_regs_0 != 0xFFFF )
        {
          kgsl_regmap_write(a1 + 1650, (unsigned int)a5xx_restore_isense_regs_isense_regs_0);
          kgsl_regmap_write(a1 + 1650, (unsigned int)a5xx_restore_isense_regs_isense_regs_1);
          kgsl_regmap_write(a1 + 1650, (unsigned int)a5xx_restore_isense_regs_isense_regs_2);
          kgsl_regmap_write(a1 + 1650, (unsigned int)a5xx_restore_isense_regs_isense_regs_3);
          kgsl_regmap_write(a1 + 1650, (unsigned int)a5xx_restore_isense_regs_isense_regs_4);
          kgsl_regmap_write(a1 + 1650, (unsigned int)a5xx_restore_isense_regs_isense_regs_5);
        }
      }
      _X8 = a1 + 1780;
      __asm { PRFM            #0x11, [X8] }
      do
        v20 = __ldxr(_X8);
      while ( __stxr(v20 | 0x100, _X8) );
      return 0;
    }
    dev_err(*a1, "SPTP GDSC enable failed\n");
  }
  else
  {
    dev_err(*a1, "RBCCU GDSC enable failed\n");
  }
  return 4294967186LL;
}
