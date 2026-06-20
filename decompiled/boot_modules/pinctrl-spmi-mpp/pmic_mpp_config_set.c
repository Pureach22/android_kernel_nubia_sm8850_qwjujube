__int64 __fastcall pmic_mpp_config_set(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  _QWORD *drvdata; // x19
  unsigned __int16 *v9; // x22
  int v10; // w9
  __int64 result; // x0
  __int64 v12; // x15
  unsigned int v13; // w14
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w0
  int v18; // w8
  int v19; // w8
  int v20; // w9
  int v21; // w9
  unsigned int v22; // w0
  unsigned int v23; // w0
  unsigned int v24; // w20
  int v25; // w2

  drvdata = (_QWORD *)pinctrl_dev_get_drvdata();
  v9 = *(unsigned __int16 **)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) + 24LL * a2 + 16);
  *((_BYTE *)v9 + 2) = 1;
  if ( a4 )
  {
    v10 = 0;
    result = 4294967274LL;
    do
    {
      v12 = *(_QWORD *)(a3 + 8LL * v10);
      v13 = (unsigned int)v12 >> 8;
      if ( (unsigned __int8)v12 <= 0x11u )
      {
        if ( (unsigned __int8)*(_QWORD *)(a3 + 8LL * v10) <= 4u )
        {
          if ( (unsigned __int8)v12 == 1 )
          {
            *((_DWORD *)v9 + 6) = 3;
          }
          else
          {
            if ( (unsigned __int8)v12 != 2 )
              return result;
            *((_BYTE *)v9 + 2) = 0;
          }
        }
        else
        {
          switch ( (unsigned __int8)v12 )
          {
            case 5u:
              switch ( v13 )
              {
                case 0x7530u:
                  *((_DWORD *)v9 + 6) = 2;
                  break;
                case 0x2710u:
                  *((_DWORD *)v9 + 6) = 1;
                  break;
                case 0x258u:
                  *((_DWORD *)v9 + 6) = 0;
                  break;
                default:
                  return 4294967274LL;
              }
              break;
            case 9u:
              *((_DWORD *)v9 + 8) = v13;
              break;
            case 0xCu:
              *((_BYTE *)v9 + 5) = (unsigned int)v12 > 0xFF;
              break;
            default:
              return result;
          }
        }
      }
      else if ( (unsigned __int8)*(_QWORD *)(a3 + 8LL * v10) > 0x80u )
      {
        switch ( (unsigned __int8)v12 )
        {
          case 0x81u:
            *((_DWORD *)v9 + 5) = v13;
            break;
          case 0x82u:
            *((_DWORD *)v9 + 9) = v13;
            break;
          case 0x83u:
            *((_BYTE *)v9 + 6) = (unsigned int)v12 > 0xFF;
            break;
          default:
            return result;
        }
      }
      else
      {
        switch ( (unsigned __int8)v12 )
        {
          case 0x12u:
            *((_BYTE *)v9 + 4) = 1;
            *((_BYTE *)v9 + 3) = (unsigned int)v12 > 0xFF;
            break;
          case 0x16u:
            if ( v13 >= *((_DWORD *)v9 + 2) )
              return 4294967274LL;
            *((_DWORD *)v9 + 3) = v13;
            break;
          case 0x80u:
            if ( (unsigned int)v12 > 0x6FF )
              return 4294967274LL;
            *((_DWORD *)v9 + 4) = v13;
            break;
          default:
            return result;
        }
      }
      ++v10;
    }
    while ( a4 != v10 );
  }
  v14 = regmap_write(drvdata[1], (unsigned int)*v9 + 65, *((unsigned int *)v9 + 3));
  if ( (v14 & 0x80000000) != 0 )
  {
    v24 = v14;
    v25 = 65;
  }
  else if ( *((_BYTE *)v9 + 7) == 1
         && (v15 = regmap_write(drvdata[1], (unsigned int)*v9 + 66, *((unsigned int *)v9 + 6)), (v15 & 0x80000000) != 0) )
  {
    v24 = v15;
    v25 = 66;
  }
  else
  {
    v16 = regmap_write(drvdata[1], (unsigned int)*v9 + 74, *((_DWORD *)v9 + 4) & 7);
    if ( (v16 & 0x80000000) != 0 )
    {
      v24 = v16;
      v25 = 74;
    }
    else
    {
      v17 = regmap_write(drvdata[1], (unsigned int)*v9 + 72, *((unsigned int *)v9 + 5));
      if ( (v17 & 0x80000000) == 0 )
      {
        v18 = *((_DWORD *)v9 + 7);
        if ( v18 )
        {
          if ( v18 == 1 )
          {
            if ( *((_BYTE *)v9 + 5) == 1 )
            {
              if ( *((_BYTE *)v9 + 4) )
                v19 = 48;
              else
                v19 = 64;
              v20 = *((_DWORD *)v9 + 9);
              if ( !v20 )
                goto LABEL_48;
LABEL_58:
              v21 = 2 * v20 + 6;
              goto LABEL_59;
            }
            v19 = 80;
            v20 = *((_DWORD *)v9 + 9);
            if ( v20 )
              goto LABEL_58;
          }
          else
          {
            v19 = 96;
            v20 = *((_DWORD *)v9 + 9);
            if ( v20 )
              goto LABEL_58;
          }
        }
        else
        {
          if ( *((_BYTE *)v9 + 5) == 1 )
          {
            if ( *((_BYTE *)v9 + 4) )
              v19 = 32;
            else
              v19 = 0;
            v20 = *((_DWORD *)v9 + 9);
            if ( !v20 )
              goto LABEL_48;
            goto LABEL_58;
          }
          v19 = 16;
          v20 = *((_DWORD *)v9 + 9);
          if ( v20 )
            goto LABEL_58;
        }
LABEL_48:
        if ( *((_BYTE *)v9 + 6) )
          v21 = 2;
        else
          v21 = 0;
LABEL_59:
        v22 = regmap_write(drvdata[1], (unsigned int)*v9 + 64, v21 | v19 | (unsigned int)*((unsigned __int8 *)v9 + 3));
        if ( (v22 & 0x80000000) != 0 )
        {
          v24 = v22;
          v25 = 64;
        }
        else
        {
          v23 = regmap_write(drvdata[1], (unsigned int)*v9 + 76, *((unsigned int *)v9 + 8));
          if ( (v23 & 0x80000000) != 0 )
          {
            v24 = v23;
            v25 = 76;
          }
          else
          {
            result = regmap_write(drvdata[1], (unsigned int)*v9 + 70, *((unsigned __int8 *)v9 + 2) << 7);
            if ( (result & 0x80000000) == 0 )
              return result;
            v24 = result;
            v25 = 70;
          }
        }
        goto LABEL_74;
      }
      v24 = v17;
      v25 = 72;
    }
  }
LABEL_74:
  dev_err(*drvdata, "write 0x%x failed\n", v25);
  return v24;
}
