__int64 __fastcall amoled_ab_ibb_regulator_set_mode(__int64 a1, unsigned int a2)
{
  __int64 drvdata; // x0
  __int64 v5; // x20
  unsigned int v6; // w8
  int v7; // w8
  unsigned int v8; // w21
  __int16 v9; // w8
  __int64 v10; // x20
  unsigned int v11; // w8
  int v12; // w8
  __int64 v13; // x2
  __int16 v14; // w8
  unsigned int updated; // w20
  __int64 v16; // x23
  __int64 v17; // x22

  drvdata = rdev_get_drvdata();
  if ( a2 > 8 || ((1 << a2) & 0x114) == 0 )
  {
    printk(&unk_7E42, "amoled_ab_ibb_regulator_set_mode");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(drvdata + 704) == a2 || *(_DWORD *)(drvdata + 1056) == a2 )
    return 0;
  if ( a2 != 8 )
  {
    if ( a2 == 4 )
    {
      if ( *(_BYTE *)(drvdata + 1067) == 1
        && (v10 = drvdata,
            v11 = regmap_update_bits_base(
                    *(_QWORD *)(drvdata + 8),
                    (unsigned __int16)(*(_DWORD *)(drvdata + 1128) + 71),
                    128,
                    0,
                    0,
                    0,
                    0),
            drvdata = v10,
            (v11 & 0x80000000) != 0) )
      {
        updated = v11;
      }
      else
      {
        if ( *(_BYTE *)(drvdata + 714) != 1 )
          goto LABEL_21;
        v12 = *(unsigned __int8 *)(drvdata + 712);
        if ( v12 == 6 )
        {
          v13 = 128;
          v14 = 120;
        }
        else
        {
          if ( v12 != 7 )
            goto LABEL_33;
          v13 = 3;
          v14 = 71;
        }
        v17 = drvdata;
        updated = regmap_update_bits_base(
                    *(_QWORD *)(drvdata + 8),
                    (unsigned __int16)(*(_DWORD *)(drvdata + 1124) + v14),
                    v13,
                    0,
                    0,
                    0,
                    0);
        if ( (updated & 0x80000000) == 0 )
        {
          drvdata = v17;
          goto LABEL_29;
        }
      }
LABEL_35:
      printk(&unk_7BA4, "amoled_masked_write");
      goto LABEL_36;
    }
    if ( a2 != 2 )
      goto LABEL_21;
  }
  if ( *(_BYTE *)(drvdata + 1067) == 1 )
  {
    v5 = drvdata;
    v6 = regmap_update_bits_base(
           *(_QWORD *)(drvdata + 8),
           (unsigned __int16)(*(_DWORD *)(drvdata + 1128) + 71),
           128,
           128,
           0,
           0,
           0);
    drvdata = v5;
    if ( (v6 & 0x80000000) != 0 )
    {
      updated = v6;
      goto LABEL_35;
    }
  }
  if ( *(_BYTE *)(drvdata + 714) == 1 )
  {
    v7 = *(unsigned __int8 *)(drvdata + 712);
    if ( v7 == 6 )
    {
      v8 = 128;
      v9 = 120;
LABEL_23:
      v16 = drvdata;
      updated = regmap_update_bits_base(
                  *(_QWORD *)(drvdata + 8),
                  (unsigned __int16)(*(_DWORD *)(drvdata + 1124) + v9),
                  v8,
                  v8,
                  0,
                  0,
                  0);
      if ( (updated & 0x80000000) == 0 )
      {
        drvdata = v16;
        goto LABEL_29;
      }
      goto LABEL_35;
    }
    if ( v7 == 7 )
    {
      v8 = 3;
      v9 = 71;
      goto LABEL_23;
    }
LABEL_33:
    updated = -22;
LABEL_36:
    printk(&unk_7C80, "amoled_ab_ibb_regulator_set_mode");
    return updated;
  }
LABEL_21:
  updated = 0;
LABEL_29:
  *(_DWORD *)(drvdata + 1056) = a2;
  *(_DWORD *)(drvdata + 704) = a2;
  return updated;
}
