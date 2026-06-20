__int64 __fastcall gdsc_enable(__int64 a1)
{
  __int64 drvdata; // x0
  __int64 result; // x0
  char v4; // w8
  __int64 v5; // x19
  __int64 v6; // x21
  __int64 v7; // x21
  int v8; // w0
  int v9; // w8
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  int v23; // w0
  __int64 v24; // x8
  unsigned int v25; // w19
  __int64 v26; // x20
  __int64 v27; // x20
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w19
  unsigned int v33; // [xsp+0h] [xbp-80h] BYREF
  int v34; // [xsp+4h] [xbp-7Ch] BYREF
  _QWORD v35[2]; // [xsp+8h] [xbp-78h] BYREF
  _DWORD v36[8]; // [xsp+18h] [xbp-68h] BYREF
  __int64 v37; // [xsp+38h] [xbp-48h]
  __int64 v38; // [xsp+40h] [xbp-40h]
  __int64 v39; // [xsp+48h] [xbp-38h]
  __int64 v40; // [xsp+50h] [xbp-30h]
  __int64 v41; // [xsp+58h] [xbp-28h]
  __int64 v42; // [xsp+60h] [xbp-20h]
  __int64 v43; // [xsp+68h] [xbp-18h]
  __int64 v44; // [xsp+70h] [xbp-10h]
  __int64 v45; // [xsp+78h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = rdev_get_drvdata(a1);
  if ( (*(_BYTE *)(drvdata + 512) & 1) != 0 )
  {
    result = 0;
    goto LABEL_42;
  }
  v4 = *(_BYTE *)(drvdata + 475);
  v5 = drvdata;
  v33 = 0;
  if ( (v4 & 1) != 0 || *(_BYTE *)(drvdata + 476) == 1 )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(drvdata + 384) + 8LL * *(int *)(drvdata + 492));
    if ( !(unsigned int)clk_prepare(v6) && (unsigned int)clk_enable(v6) )
      clk_unprepare(v6);
    *(_BYTE *)(v5 + 480) = 1;
  }
  regmap_read(*(_QWORD *)(v5 + 336), 0, &v33);
  if ( (v33 & 2) != 0 )
  {
    dev_warn(a1 + 232, "Invalid enable while %s is under HW control\n", *(const char **)(v5 + 8));
    result = 4294967280LL;
    goto LABEL_42;
  }
  if ( (*(_BYTE *)(v5 + 472) & 1) == 0 )
  {
    if ( *(int *)(v5 + 488) >= 1 )
    {
      v26 = 0;
      do
        reset_control_deassert(*(_QWORD *)(*(_QWORD *)(v5 + 456) + 8 * v26++));
      while ( v26 < *(int *)(v5 + 488) );
    }
    *(_BYTE *)(v5 + 474) = 0;
LABEL_35:
    _const_udelay(4295);
    _const_udelay(4295);
    if ( *(_BYTE *)(v5 + 476) == 1 )
    {
      v27 = *(_QWORD *)(*(_QWORD *)(v5 + 384) + 8LL * *(int *)(v5 + 492));
      clk_disable(v27);
      clk_unprepare(v27);
      *(_BYTE *)(v5 + 480) = 0;
    }
    result = 0;
    *(_BYTE *)(v5 + 478) = 1;
    goto LABEL_42;
  }
  if ( *(int *)(v5 + 500) < 1 )
  {
LABEL_15:
    v9 = *(_DWORD *)(v5 + 496);
    if ( v9 )
    {
      if ( v9 >= 1 )
      {
        v10 = 0;
        do
          regmap_update_bits_base(*(_QWORD *)(*(_QWORD *)(v5 + 360) + 8 * v10++), 0, 1, 1, 0, 0, 0);
        while ( v10 < *(int *)(v5 + 496) );
      }
      v11 = *(_QWORD *)(v5 + 336);
      v36[0] = 0;
      regmap_read(v11, 0, v36);
      _const_udelay(4295);
      if ( *(int *)(v5 + 496) >= 1 )
      {
        v12 = 0;
        do
          regmap_update_bits_base(*(_QWORD *)(*(_QWORD *)(v5 + 360) + 8 * v12++), 0, 1, 0, 0, 0, 0);
        while ( v12 < *(int *)(v5 + 496) );
      }
      v13 = *(_QWORD *)(v5 + 336);
      v36[0] = 0;
      regmap_read(v13, 0, v36);
    }
    v14 = *(_QWORD *)(v5 + 344);
    if ( v14 )
    {
      if ( *(_BYTE *)(v5 + 481) == 1 )
      {
        regmap_read(v14, 0, &v33);
        v15 = *(_QWORD *)(v5 + 344);
        v33 |= 0x10u;
        regmap_write(v15, 0, v33);
        v16 = *(_QWORD *)(v5 + 336);
        v36[0] = 0;
        regmap_read(v16, 0, v36);
        _const_udelay(4295);
        v17 = *(_QWORD *)(v5 + 344);
        v33 &= ~0x10u;
        regmap_write(v17, 0, v33);
        v18 = *(_QWORD *)(v5 + 336);
        v36[0] = 0;
        regmap_read(v18, 0, v36);
        v14 = *(_QWORD *)(v5 + 344);
      }
      regmap_read(v14, 0, &v33);
      v19 = *(_QWORD *)(v5 + 344);
      v33 &= ~1u;
      regmap_write(v19, 0, v33);
      v20 = *(_QWORD *)(v5 + 336);
      v36[0] = 0;
      regmap_read(v20, 0, v36);
    }
    if ( *(_QWORD *)(v5 + 448) )
    {
      v21 = *(_QWORD *)(v5 + 336);
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      strcpy((char *)v36, "{class: clock, res: gpu_noc_wa}");
      v39 = 0;
      v40 = 0;
      v37 = 0;
      v38 = 0;
      v35[0] = 96;
      v34 = 0;
      regmap_read(v21, 0, &v34);
      if ( (v34 & 1) != 0 )
      {
        v22 = *(_QWORD *)(v5 + 448);
        v35[1] = v36;
        v23 = mbox_send_message(v22, v35);
        if ( v23 < 0 )
        {
          v24 = *(_QWORD *)v5;
          v25 = v23;
          dev_err(v24 + 232, "qmp message send failed, ret=%d\n", v23);
          result = v25;
          goto LABEL_42;
        }
      }
    }
    else
    {
      v28 = *(_QWORD *)(v5 + 368);
      if ( v28 )
      {
        regmap_update_bits_base(
          v28,
          0,
          1LL << *(_DWORD *)(v5 + 376),
          (unsigned int)~(1 << *(_DWORD *)(v5 + 376)),
          0,
          0,
          0);
      }
      else
      {
        regmap_read(*(_QWORD *)(v5 + 336), 0, &v33);
        v29 = *(_QWORD *)(v5 + 336);
        v33 &= ~1u;
        regmap_write(v29, 0, v33);
      }
    }
    v30 = *(_QWORD *)(v5 + 336);
    v36[0] = 0;
    regmap_read(v30, 0, v36);
    _const_udelay(4295);
    result = check_gdsc_status(v5, a1 + 232, 1u);
    if ( (_DWORD)result )
      goto LABEL_42;
    if ( *(_BYTE *)(v5 + 473) == 1 && (v33 & 0x800) == 0 )
    {
      v31 = *(_QWORD *)(v5 + 336);
      v33 |= 0x800u;
      regmap_write(v31, 0, v33);
    }
    goto LABEL_35;
  }
  v7 = 0;
  while ( 1 )
  {
    v8 = icc_set_bw(*(_QWORD *)(*(_QWORD *)(v5 + 464) + 8 * v7), 1, 1);
    if ( v8 )
      break;
    if ( ++v7 >= *(int *)(v5 + 500) )
      goto LABEL_15;
  }
  v32 = v8;
  dev_err(a1 + 232, "Failed to vote BW for %d, ret=%d\n", v7, v8);
  result = v32;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
