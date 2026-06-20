__int64 __fastcall qpnp_tm_set_temp_lite_thresh(__int64 *a1, unsigned int a2, unsigned int a3)
{
  int v6; // w22
  __int64 *v7; // x9
  __int64 v8; // x10
  __int64 v9; // x8
  _BOOL4 v10; // w9
  int v11; // w21
  __int64 v12; // x24
  __int64 result; // x0
  int v14; // w8
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x8
  const char *v18; // x1
  unsigned int v19; // w19
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (mutex_is_locked(a1 + 8) & 1) != 0 )
  {
    if ( a2 < 3 )
      goto LABEL_3;
LABEL_26:
    dev_err(a1[1], "invalid TEMP_LITE trip = %d\n", a2);
    goto LABEL_27;
  }
  __break(0x800u);
  if ( a2 >= 3 )
    goto LABEL_26;
LABEL_3:
  if ( a2 )
  {
    if ( a2 == 1 )
      goto LABEL_17;
    v6 = 81;
    v7 = temp_map_lite_shutdown;
  }
  else
  {
    v6 = 80;
    v7 = temp_map_lite_warning;
  }
  v8 = *v7;
  if ( *v7 > (int)a3 || (v9 = v7[3], v9 < (int)a3) )
  {
    dev_err(a1[1], "invalid TEMP_LITE temp = %d\n", a3);
LABEL_27:
    result = 4294967274LL;
    goto LABEL_28;
  }
  if ( v9 <= (int)a3 )
  {
    v11 = 12;
  }
  else
  {
    v9 = v7[2];
    if ( v9 <= (int)a3 )
    {
      v11 = 8;
    }
    else
    {
      v9 = v7[1];
      v10 = v9 <= (int)a3;
      if ( v9 > (int)a3 )
        LODWORD(v9) = v8;
      v11 = 4 * v10;
    }
  }
  v12 = (int)v9;
  if ( (int)v9 != a1[a2 + 18] )
  {
    v14 = *((_DWORD *)a1 + 12);
    v15 = *a1;
    v20 = 0;
    v16 = regmap_read(v15, (unsigned int)(v14 + v6), &v20);
    if ( (v16 & 0x80000000) != 0 )
    {
      v17 = a1[1];
      v18 = "LITE_TEMP_CFG read failed, ret=%d\n";
    }
    else
    {
      v16 = regmap_write(*a1, (unsigned int)(*((_DWORD *)a1 + 12) + v6), v20 & 0xF3 | (unsigned int)v11);
      if ( (v16 & 0x80000000) == 0 )
      {
        result = 0;
        a1[a2 + 18] = v12;
        goto LABEL_28;
      }
      v17 = a1[1];
      v18 = "LITE_TEMP_CFG write failed, ret=%d\n";
    }
    v19 = v16;
    dev_err(v17, v18, v16);
    result = v19;
    goto LABEL_28;
  }
LABEL_17:
  result = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
