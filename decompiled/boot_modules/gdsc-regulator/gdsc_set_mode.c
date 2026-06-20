__int64 __fastcall gdsc_set_mode(__int64 a1, int a2)
{
  __int64 drvdata; // x20
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x8
  unsigned int v10; // w21
  __int64 v11; // x0
  unsigned int v12; // w21
  __int64 v13; // x0
  unsigned int v14; // w19
  unsigned int v15; // [xsp+0h] [xbp-10h] BYREF
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = rdev_get_drvdata(a1);
  if ( *(_BYTE *)(drvdata + 513) == 1 )
  {
    if ( a2 == 2 )
    {
      result = 0;
      *(_BYTE *)(drvdata + 514) = 0;
    }
    else if ( a2 == 4 )
    {
      result = 0;
      *(_BYTE *)(drvdata + 514) = 1;
    }
    else
    {
      result = 4294967274LL;
    }
    goto LABEL_24;
  }
  v6 = *(_QWORD *)(a1 + 1152);
  v15 = 0;
  if ( v6 )
  {
    v7 = *(_QWORD *)(v6 + 120);
    ww_mutex_lock(v7 + 152, 0);
    if ( !*(_DWORD *)(v7 + 12) )
    {
      dev_err(
        a1 + 232,
        "%s cannot change GDSC HW/SW control mode while parent is disabled\n",
        *(const char **)(drvdata + 8));
      result = 4294967291LL;
      goto LABEL_22;
    }
  }
  else
  {
    v7 = 0;
  }
  result = regmap_read(*(_QWORD *)(drvdata + 336), 0, &v15);
  if ( (result & 0x80000000) == 0 )
  {
    if ( a2 != 2 )
    {
      if ( a2 == 1 )
      {
        v8 = *(_QWORD *)(drvdata + 336);
        v15 |= 2u;
        result = regmap_write(v8, 0, v15);
        if ( (result & 0x80000000) == 0 )
        {
          v9 = *(_QWORD *)(drvdata + 336);
          v10 = result;
          v16 = 0;
          regmap_read(v9, 0, &v16);
          _const_udelay(4295);
          result = v10;
          *(_BYTE *)(drvdata + 479) = 1;
        }
      }
      else
      {
        result = 4294967274LL;
      }
      goto LABEL_22;
    }
    v11 = *(_QWORD *)(drvdata + 336);
    v15 &= ~2u;
    result = regmap_write(v11, 0, v15);
    if ( (result & 0x80000000) == 0 )
    {
      v12 = result;
      v13 = *(_QWORD *)(drvdata + 336);
      v16 = 0;
      regmap_read(v13, 0, &v16);
      _const_udelay(4295);
      if ( *(_BYTE *)(drvdata + 478) == 1 )
      {
        result = check_gdsc_status(drvdata, a1 + 232, 1u);
        if ( (_DWORD)result )
          goto LABEL_22;
        v12 = 0;
      }
      result = v12;
      *(_BYTE *)(drvdata + 479) = 0;
    }
  }
LABEL_22:
  if ( *(_QWORD *)(a1 + 1152) )
  {
    v14 = result;
    ww_mutex_unlock(v7 + 152);
    result = v14;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
