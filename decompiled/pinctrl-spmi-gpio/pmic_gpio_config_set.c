__int64 __fastcall pmic_gpio_config_set(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 *drvdata; // x19
  unsigned __int16 *v9; // x20
  int v10; // w8
  __int64 v11; // x16
  __int64 result; // x0
  unsigned int v13; // w15
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  int v17; // w8
  int v18; // w8
  __int64 v19; // x2
  unsigned int v20; // w0
  __int64 v21; // x2
  unsigned int v22; // w0
  unsigned int v23; // w0
  unsigned int v24; // w20
  int v25; // w2

  drvdata = (__int64 *)pinctrl_dev_get_drvdata();
  v9 = *(unsigned __int16 **)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) + 24LL * a2 + 16);
  v9[1] = 257;
  if ( a4 )
  {
    v10 = 0;
    do
    {
      v11 = *(_QWORD *)(a3 + 8LL * v10);
      result = 4294967274LL;
      v13 = (unsigned int)v11 >> 8;
      switch ( (char)v11 )
      {
        case 1:
          goto LABEL_3;
        case 2:
          *((_BYTE *)v9 + 2) = 0;
          break;
        case 3:
          if ( (unsigned int)v11 < 0x100 )
LABEL_3:
            *((_DWORD *)v9 + 6) = 5;
          else
            *((_DWORD *)v9 + 6) = 4;
          break;
        case 5:
          *((_DWORD *)v9 + 6) = 0;
          break;
        case 6:
          if ( *((_BYTE *)v9 + 5) != 1 )
            return result;
          *((_DWORD *)v9 + 5) = 1;
          break;
        case 7:
          if ( *((_BYTE *)v9 + 5) != 1 )
            return result;
          *((_DWORD *)v9 + 5) = 2;
          break;
        case 8:
          *((_DWORD *)v9 + 5) = 0;
          break;
        case 12:
          *((_BYTE *)v9 + 7) = (unsigned int)v11 > 0xFF;
          break;
        case 18:
          *((_BYTE *)v9 + 6) = 1;
          *((_BYTE *)v9 + 4) = (unsigned int)v11 > 0xFF;
          break;
        case 19:
          *((_BYTE *)v9 + 6) = (unsigned int)v11 > 0xFF;
          break;
        case 22:
          if ( v13 >= *((_DWORD *)v9 + 3) )
            return result;
          *((_DWORD *)v9 + 4) = v13;
          break;
        case -128:
          if ( (unsigned int)v11 > 0x3FF )
            return result;
          *((_DWORD *)v9 + 6) = v13;
          break;
        case -127:
          if ( (unsigned int)v11 > 0x3FF )
            return result;
          if ( v13 == 3 )
          {
            *((_DWORD *)v9 + 7) = 1;
          }
          else if ( v13 == 1 )
          {
            *((_DWORD *)v9 + 7) = 3;
          }
          else
          {
            *((_DWORD *)v9 + 7) = v13;
          }
          break;
        case -126:
          if ( (unsigned int)v11 > 0x4FF || (*((_BYTE *)v9 + 9) & 1) == 0 )
            return result;
          *((_DWORD *)v9 + 9) = v13;
          break;
        case -125:
          if ( *((_BYTE *)v9 + 9) != 1 )
            return result;
          *((_BYTE *)v9 + 8) = 1;
          break;
        case -124:
          if ( (unsigned int)v11 > 0x4FF )
            return result;
          *((_DWORD *)v9 + 10) = v13;
          break;
        default:
          return result;
      }
      ++v10;
    }
    while ( a4 != v10 );
  }
  v14 = regmap_write(drvdata[1], (unsigned int)*v9 + 65, *((unsigned int *)v9 + 4));
  if ( (v14 & 0x80000000) != 0 )
  {
    v24 = v14;
    v25 = 65;
LABEL_63:
    dev_err(*drvdata, "write 0x%x failed\n", v25);
    return v24;
  }
  v15 = regmap_write(drvdata[1], (unsigned int)*v9 + 66, *((unsigned int *)v9 + 6));
  if ( (v15 & 0x80000000) != 0 )
  {
    v24 = v15;
    v25 = 66;
    goto LABEL_63;
  }
  v16 = regmap_write(drvdata[1], (unsigned int)*v9 + 69, *((_DWORD *)v9 + 7) | (unsigned int)(16 * *((_DWORD *)v9 + 5)));
  if ( (v16 & 0x80000000) != 0 )
  {
    v24 = v16;
    v25 = 69;
    goto LABEL_63;
  }
  v17 = *((_DWORD *)v9 + 10);
  if ( v17 )
  {
    v18 = v17 - 1;
    if ( *((_BYTE *)v9 + 9) == 1 )
      v19 = v18 | 0x80u;
    else
      v19 = 1LL << v18;
  }
  else
  {
    v19 = 0;
  }
  v20 = regmap_write(drvdata[1], (unsigned int)*v9 + 67, v19);
  if ( (v20 & 0x80000000) != 0 )
  {
    v24 = v20;
    v25 = 67;
    goto LABEL_63;
  }
  if ( (v9[4] & 1) != 0 )
  {
    v21 = 3;
  }
  else
  {
    v21 = *((unsigned __int8 *)v9 + 6);
    if ( (_DWORD)v21 == 1 && (*((_BYTE *)v9 + 7) & 1) != 0 )
      v21 = 2;
  }
  if ( *((_BYTE *)v9 + 9) != 1 )
  {
    v22 = regmap_write(
            drvdata[1],
            (unsigned int)*v9 + 64,
            (2 * *((_DWORD *)v9 + 8)) | (16 * (_DWORD)v21) | (unsigned int)*((unsigned __int8 *)v9 + 4));
    if ( (v22 & 0x80000000) == 0 )
      goto LABEL_55;
    goto LABEL_61;
  }
  v22 = regmap_write(drvdata[1], (unsigned int)*v9 + 64, v21);
  if ( (v22 & 0x80000000) != 0 )
  {
LABEL_61:
    v24 = v22;
    v25 = 64;
    goto LABEL_63;
  }
  v23 = regmap_write(drvdata[1], (unsigned int)*v9 + 74, (unsigned int)(*((_DWORD *)v9 + 9) - 1));
  if ( (v23 & 0x80000000) != 0 )
  {
    v24 = v23;
    v25 = 74;
    goto LABEL_63;
  }
  result = pmic_gpio_write(drvdata, v9, 68, *((_DWORD *)v9 + 8) & 0xF | (*((unsigned __int8 *)v9 + 4) << 7));
  if ( (result & 0x80000000) == 0 )
  {
LABEL_55:
    result = regmap_write(drvdata[1], (unsigned int)*v9 + 70, *((unsigned __int8 *)v9 + 2) << 7);
    if ( (result & 0x80000000) == 0 )
      return result;
    v24 = result;
    v25 = 70;
    goto LABEL_63;
  }
  return result;
}
