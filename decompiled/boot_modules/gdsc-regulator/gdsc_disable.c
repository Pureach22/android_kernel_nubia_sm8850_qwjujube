__int64 __fastcall gdsc_disable(__int64 a1)
{
  __int64 drvdata; // x0
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x22
  _BOOL4 v6; // w23
  __int64 result; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x21
  int v16; // w0
  __int64 v17; // x21
  unsigned int v18; // w19
  unsigned int v19; // w20
  unsigned int v20; // [xsp+0h] [xbp-10h] BYREF
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = rdev_get_drvdata(a1);
  v3 = *(_QWORD *)(a1 + 1152);
  v4 = drvdata;
  v20 = 0;
  if ( v3 )
  {
    v5 = *(_QWORD *)(v3 + 120);
    v6 = ww_mutex_trylock(v5 + 152, 0) != 0;
    if ( !*(_DWORD *)(v5 + 12) )
    {
      dev_err(a1 + 232, "%s cannot disable GDSC while parent is disabled\n", *(const char **)(v4 + 8));
      result = 4294967291LL;
      if ( !*(_QWORD *)(a1 + 1152) )
        goto LABEL_39;
      goto LABEL_37;
    }
  }
  else
  {
    v5 = 0;
    v6 = 0;
  }
  regmap_read(*(_QWORD *)(v4 + 336), 0, &v20);
  if ( (v20 & 2) != 0 )
  {
    dev_warn(a1 + 232, "Invalid Disable while %s is under HW control\n", *(const char **)(v4 + 8));
    result = 4294967280LL;
    goto LABEL_39;
  }
  if ( *(_BYTE *)(v4 + 476) == 1 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(v4 + 384) + 8LL * *(int *)(v4 + 492));
    if ( !(unsigned int)clk_prepare(v8) && (unsigned int)clk_enable(v8) )
      clk_unprepare(v8);
    *(_BYTE *)(v4 + 480) = 1;
  }
  _const_udelay(4295);
  if ( *(_BYTE *)(v4 + 513) == 1 && *(_BYTE *)(v4 + 514) != 1 )
    goto LABEL_31;
  if ( *(_BYTE *)(v4 + 472) != 1 )
  {
    if ( *(_DWORD *)(v4 + 488) - 1 >= 0 )
    {
      v10 = 8LL * (unsigned int)(*(_DWORD *)(v4 + 488) - 1);
      do
      {
        reset_control_assert(*(_QWORD *)(*(_QWORD *)(v4 + 456) + v10));
        v10 -= 8;
      }
      while ( v10 != -8 );
    }
    *(_BYTE *)(v4 + 474) = 1;
    goto LABEL_31;
  }
  v9 = *(_QWORD *)(v4 + 368);
  if ( v9 )
  {
    regmap_update_bits_base(v9, 0, 1LL << *(_DWORD *)(v4 + 376), (unsigned int)(1LL << *(_DWORD *)(v4 + 376)), 0, 0, 0);
  }
  else
  {
    regmap_read(*(_QWORD *)(v4 + 336), 0, &v20);
    v11 = *(_QWORD *)(v4 + 336);
    v20 |= 1u;
    regmap_write(v11, 0, v20);
  }
  v12 = *(_QWORD *)(v4 + 336);
  v21 = 0;
  regmap_read(v12, 0, &v21);
  _const_udelay(4295);
  if ( *(_BYTE *)(v4 + 477) == 1 )
  {
    _const_udelay(429500);
  }
  else
  {
    result = check_gdsc_status(v4, a1 + 232, 0);
    if ( (_DWORD)result )
      goto LABEL_36;
  }
  v13 = *(_QWORD *)(v4 + 344);
  if ( v13 )
  {
    regmap_read(v13, 0, &v20);
    v14 = *(_QWORD *)(v4 + 344);
    v20 |= 1u;
    regmap_write(v14, 0, v20);
  }
  if ( *(int *)(v4 + 500) < 1 )
  {
LABEL_31:
    if ( *(_BYTE *)(v4 + 480) == 1 && (*(_BYTE *)(v4 + 475) & 1) != 0 || *(_BYTE *)(v4 + 476) == 1 )
    {
      v17 = *(_QWORD *)(*(_QWORD *)(v4 + 384) + 8LL * *(int *)(v4 + 492));
      clk_disable(v17);
      clk_unprepare(v17);
      *(_BYTE *)(v4 + 480) = 0;
    }
    result = 0;
    *(_BYTE *)(v4 + 478) = 0;
LABEL_36:
    if ( !*(_QWORD *)(a1 + 1152) )
      goto LABEL_39;
    goto LABEL_37;
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = icc_set_bw(*(_QWORD *)(*(_QWORD *)(v4 + 464) + 8 * v15), 0, 0);
    if ( v16 )
      break;
    if ( ++v15 >= *(int *)(v4 + 500) )
      goto LABEL_31;
  }
  v19 = v16;
  dev_err(a1 + 232, "Failed to unvote BW for %d: %d\n", v15, v16);
  result = v19;
  if ( *(_QWORD *)(a1 + 1152) )
  {
LABEL_37:
    if ( v6 )
    {
      v18 = result;
      ww_mutex_unlock(v5 + 152);
      result = v18;
    }
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
