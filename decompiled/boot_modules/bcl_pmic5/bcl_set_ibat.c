__int64 __fastcall bcl_set_ibat(__int64 a1, __int64 a2, int a3)
{
  int *v3; // x21
  unsigned int v5; // w20
  __int64 v6; // x8
  int v7; // w11
  unsigned int v8; // w12
  __int64 v9; // x10
  __int64 v10; // x11
  int v11; // w23
  unsigned __int16 v12; // w12
  int v13; // w10
  unsigned __int16 v14; // w24
  int v16; // w0

  v3 = *(int **)(a1 + 1048);
  mutex_lock(v3 + 6);
  if ( *((_QWORD *)v3 + 1) == a3 )
  {
LABEL_2:
    v5 = 0;
    goto LABEL_42;
  }
  if ( *v3 && *((_BYTE *)v3 + 72) == 1 )
  {
    disable_irq_nosync();
    *((_BYTE *)v3 + 72) = 0;
  }
  if ( a3 == 0x7FFFFFFF )
  {
    v5 = 0;
    *((_QWORD *)v3 + 1) = 0x7FFFFFFF;
    goto LABEL_42;
  }
  v6 = *((_QWORD *)v3 + 22);
  if ( *(_BYTE *)(v6 + 36) == 1 )
  {
    v7 = 15625 * *(_DWORD *)(v6 + 40);
    if ( *(_BYTE *)(v6 + 38) )
      goto LABEL_23;
  }
  else if ( *(_BYTE *)(v6 + 37) == 1 )
  {
    v7 = 39062 * *(_DWORD *)(v6 + 40);
    if ( *(_BYTE *)(v6 + 38) )
      goto LABEL_23;
  }
  else
  {
    v8 = *(unsigned __int8 *)(v6 + 18);
    if ( v8 < 5 )
    {
      if ( v8 == 4 )
        v12 = 28217;
      else
        v12 = 12591;
      v7 = *(_DWORD *)(v6 + 40) * (v12 | 0x10000);
      if ( *(_BYTE *)(v6 + 38) )
        goto LABEL_23;
    }
    else
    {
      v7 = 156255 * *(_DWORD *)(v6 + 40);
      if ( *(_BYTE *)(v6 + 38) )
      {
LABEL_23:
        v11 = 4000 * a3 / v7;
        goto LABEL_24;
      }
    }
  }
  v9 = (unsigned int)(20000 * a3) / (__int64)v7;
  v10 = (unsigned int)(10000 * a3) / (__int64)v7;
  if ( *(_BYTE *)(v6 + 39) == 1 )
    LOBYTE(v11) = v10;
  else
    LOBYTE(v11) = v9;
LABEL_24:
  v13 = v3[19];
  v5 = 0;
  v14 = 75;
  if ( v13 > 7 )
  {
    if ( v13 == 8 )
      goto LABEL_39;
    if ( v13 != 9 )
      goto LABEL_42;
  }
  else
  {
    if ( !v13 )
      goto LABEL_39;
    if ( v13 != 1 )
      goto LABEL_42;
  }
  v14 = 76;
  if ( *(unsigned __int8 *)(v6 + 18) >= 4u )
  {
    if ( (*(_BYTE *)(v6 + 20) & 4) != 0 )
      v14 = 77;
    else
      v14 = 76;
  }
  if ( *(_BYTE *)(v6 + 36) )
  {
    v11 = (a3 - 800) / 100;
    if ( v11 << 24 >= 234881025 )
    {
      printk(&unk_8668, "bcl_pmic5", "convert_ibat_to_ccm_val");
      v6 = *((_QWORD *)v3 + 22);
      LOBYTE(v11) = 14;
    }
  }
  if ( *(_BYTE *)(v6 + 37) != 1 || (v11 = (a3 - 900) / 150, v11 << 24 < 268435457) )
  {
LABEL_39:
    if ( v6 )
      goto LABEL_40;
LABEL_48:
    printk(&unk_8411, "bcl_pmic5", "bcl_write_register");
    v5 = -22;
    goto LABEL_42;
  }
  printk(&unk_8668, "bcl_pmic5", "convert_ibat_to_ccm_val");
  v6 = *((_QWORD *)v3 + 22);
  LOBYTE(v11) = 16;
  if ( !v6 )
    goto LABEL_48;
LABEL_40:
  v5 = regmap_write(*(_QWORD *)(v6 + 8), *(unsigned __int16 *)(v6 + 16) + (unsigned int)v14, (unsigned __int8)v11);
  if ( (v5 & 0x80000000) != 0 )
  {
    printk(&unk_86BF, "bcl_pmic5", "bcl_write_register");
    goto LABEL_42;
  }
  if ( !v5 )
  {
    v16 = *v3;
    *((_QWORD *)v3 + 1) = a3;
    if ( v16 && (v3[18] & 1) == 0 )
    {
      enable_irq();
      v5 = 0;
      *((_BYTE *)v3 + 72) = 1;
      goto LABEL_42;
    }
    goto LABEL_2;
  }
LABEL_42:
  mutex_unlock(v3 + 6);
  return v5;
}
