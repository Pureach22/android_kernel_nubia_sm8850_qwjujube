__int64 __fastcall msm_config_group_set(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 drvdata; // x0
  _QWORD *v7; // x19
  int v8; // w26
  __int64 v9; // x27
  unsigned int *v10; // x24
  __int64 result; // x0
  __int64 v12; // x25
  unsigned int v13; // w8
  unsigned int v14; // w21
  __int64 v15; // x28
  unsigned int v16; // w22
  unsigned int v17; // w10
  int v18; // w9
  int v19; // w8
  __int64 v20; // x23
  int v21; // w0
  unsigned __int64 v22; // x8
  int v23; // w9
  int v24; // w10
  int v25; // w9
  unsigned int v26; // w0
  __int64 v27; // x23
  int v28; // w0
  __int64 v29; // x20
  int v30; // w0
  __int64 v31; // [xsp+0h] [xbp-10h]

  drvdata = pinctrl_dev_get_drvdata();
  if ( a4 )
  {
    v7 = (_QWORD *)drvdata;
    v8 = 0;
    v9 = drvdata + 976;
    v31 = 0;
    v10 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(drvdata + 968) + 32LL) + 112LL * a2);
    while ( 1 )
    {
      result = 4294966772LL;
      v12 = *(_QWORD *)(a3 + 8LL * v8);
      v13 = (unsigned int)v12 >> 8;
      if ( (unsigned __int8)v12 > 0xBu )
        break;
      if ( (unsigned __int8)*(_QWORD *)(a3 + 8LL * v8) <= 4u )
      {
        if ( (unsigned __int8)v12 >= 2u && (unsigned __int8)v12 != 3 )
          return result;
LABEL_20:
        v17 = v10[21];
        v18 = (v17 >> 22) & 0x1F;
        LODWORD(v15) = (v17 >> 12) & 0x1F;
        if ( v18 )
          v14 = ((unsigned int)(1 << v18) >> v15) | 3;
        else
          v14 = 3;
LABEL_25:
        v16 = 0;
        if ( (unsigned __int8)v12 > 0xBu )
        {
          if ( (unsigned __int8)v12 > 0x12u )
          {
            if ( (unsigned __int8)v12 == 19 )
            {
              v16 = (unsigned int)v12 > 0xFF;
              if ( (v16 & ~v14) != 0 )
                goto LABEL_63;
            }
            else
            {
              if ( (unsigned __int8)v12 == 128 )
              {
                LODWORD(v31) = 1;
              }
              else
              {
                if ( (unsigned __int8)v12 != 129 )
                  goto LABEL_70;
                LODWORD(v31) = 0;
              }
              HIDWORD(v31) = 1;
              v16 = (unsigned int)v12 >> 8;
              if ( (v13 & ~v14) != 0 )
              {
LABEL_63:
                dev_err(*v7, "config %x: %x is invalid\n", (unsigned __int8)v12, v16);
                return 4294967274LL;
              }
            }
            goto LABEL_60;
          }
          if ( (unsigned __int8)v12 != 12 )
          {
            if ( (unsigned __int8)v12 != 18 )
            {
LABEL_70:
              dev_err(*v7, "Unsupported config parameter: %x\n", (unsigned __int8)v12);
              return 4294967274LL;
            }
            v20 = raw_spin_lock_irqsave((char *)v7 + 764);
            v21 = readl((unsigned int *)(*(_QWORD *)(v9 + 8 * ((*(_QWORD *)(v10 + 21) >> 5) & 3LL)) + v10[16]));
            v22 = *(_QWORD *)(v10 + 21);
            v16 = 1;
            v23 = 1 << (v22 >> 52);
            v24 = v21 | v23;
            v25 = v21 & ~v23;
            if ( (unsigned int)v12 >= 0x100 )
              v26 = v24;
            else
              v26 = v25;
            writel(v26, (unsigned int *)(*(_QWORD *)(v9 + 8 * ((v22 >> 5) & 3)) + v10[16]));
            raw_spin_unlock_irqrestore((char *)v7 + 764, v20);
            if ( (v14 & 1) == 0 )
              goto LABEL_63;
            goto LABEL_60;
          }
          goto LABEL_59;
        }
        if ( (unsigned __int8)v12 <= 2u )
        {
          if ( (_BYTE)v12 )
          {
            if ( (unsigned __int8)v12 != 1 )
              goto LABEL_70;
          }
          else
          {
            if ( (*(_BYTE *)(v7[121] + 48LL) & 1) != 0 )
              return result;
LABEL_58:
            v16 = 2;
          }
LABEL_59:
          if ( (v16 & ~v14) != 0 )
            goto LABEL_63;
          goto LABEL_60;
        }
        if ( (unsigned __int8)v12 == 3 )
          goto LABEL_52;
        if ( (unsigned __int8)v12 != 5 )
          goto LABEL_70;
        if ( (*(_BYTE *)(v7[121] + 48LL) & 1) != 0 )
          goto LABEL_58;
        v16 = 3;
        if ( v13 != 2200 )
          goto LABEL_59;
        v19 = (v10[21] >> 22) & 0x1F;
        if ( !v19 )
          goto LABEL_59;
        v16 = (1 << v19) | 3;
        if ( (v16 & ~v14) != 0 )
          goto LABEL_63;
        goto LABEL_60;
      }
      if ( (unsigned __int8)v12 == 5 )
        goto LABEL_20;
      if ( (unsigned __int8)v12 == 6 )
      {
        v14 = 1;
        LODWORD(v15) = v10[21] >> 27;
        goto LABEL_52;
      }
      if ( (unsigned __int8)v12 != 9 )
        return result;
      v16 = -1;
      v14 = 7;
      LODWORD(v15) = (v10[21] >> 17) & 0x1F;
      if ( (v12 & 0x100) != 0 || v13 - 2 >= 0xF )
        goto LABEL_59;
      v16 = ((unsigned int)v12 >> 9) - 1;
      if ( (v16 & 0xFFFFFFF8) != 0 )
        goto LABEL_63;
LABEL_60:
      if ( (v12 & 0xFE) != 0x80 )
      {
        v27 = raw_spin_lock_irqsave((char *)v7 + 764);
        v28 = readl((unsigned int *)(*(_QWORD *)(v9 + 8 * ((*(_QWORD *)(v10 + 21) >> 5) & 3LL)) + v10[15]));
        writel(
          v28 & ~(v14 << v15) | (v16 << v15),
          (unsigned int *)(*(_QWORD *)(v9 + 8 * ((*(_QWORD *)(v10 + 21) >> 5) & 3LL)) + v10[15]));
        raw_spin_unlock_irqrestore((char *)v7 + 764, v27);
      }
      if ( a4 == ++v8 )
      {
        if ( HIDWORD(v31) )
        {
          v29 = raw_spin_lock_irqsave((char *)v7 + 764);
          v30 = readl((unsigned int *)(v7[((*(_QWORD *)(v10 + 21) >> 5) & 3LL) + 122] + v10[15]));
          if ( (v30 & 0x800) != 0 )
            writel(
              v30 & 0xFFFFEFFF | ((_DWORD)v31 << 12),
              (unsigned int *)(v7[((*(_QWORD *)(v10 + 21) >> 5) & 3LL) + 122] + v10[15]));
          raw_spin_unlock_irqrestore((char *)v7 + 764, v29);
        }
        return 0;
      }
    }
    if ( (unsigned __int8)*(_QWORD *)(a3 + 8LL * v8) > 0x7Fu )
    {
      v14 = 1;
      if ( (unsigned int)(unsigned __int8)v12 - 128 >= 2 )
      {
        if ( (unsigned __int8)v12 != 130 )
          return result;
        LOBYTE(v15) = 13;
LABEL_52:
        v16 = 1;
        if ( (v14 & 1) == 0 )
          goto LABEL_63;
        goto LABEL_60;
      }
      LOBYTE(v15) = 12;
    }
    else
    {
      if ( (unsigned int)(unsigned __int8)v12 - 18 >= 2 && (unsigned __int8)v12 != 12 )
        return result;
      v14 = 1;
      v15 = (*(_QWORD *)(v10 + 21) >> 42) & 0x1FLL;
    }
    goto LABEL_25;
  }
  return 0;
}
