__int64 __fastcall msm_dss_enable_vreg(_QWORD *a1, int a2, int a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  __int64 v6; // x21
  __int64 v7; // x25
  _QWORD *v8; // x24
  __int64 v9; // x20
  int v10; // w0
  int is_enabled; // w0
  int v12; // w8
  int v13; // w22
  int v14; // w0
  int v15; // w0
  int v16; // w8
  __int64 v17; // x8
  __int64 v18; // x21
  _QWORD *v19; // x19
  bool v20; // cc
  int mode; // w0
  int v22; // w8
  int v23; // w8
  __int64 v25; // x8
  _QWORD *v26; // x19
  __int64 v27; // x21
  int v28; // w8
  int v29; // w8
  __int64 v30; // [xsp+8h] [xbp-48h]
  __int64 v31; // [xsp+8h] [xbp-48h]

  _ReadStatusReg(SP_EL0);
  if ( !a3 )
  {
    v17 = (unsigned int)(a2 - 1);
    if ( a2 - 1 >= 0 )
    {
      v18 = v17 + 1;
      v19 = &a1[9 * (unsigned int)v17];
      do
      {
        v31 = v19[1];
        mode = regulator_get_mode(*v19);
        if ( (unsigned int)v31 ^ 0x63736467 | BYTE4(v31) || mode != 1 )
        {
          v22 = *((_DWORD *)v19 + 16);
          if ( v22 )
            usleep_range_state(1000 * v22, 1000 * v22 + 10, 2);
          regulator_disable(*v19);
          v23 = *((_DWORD *)v19 + 17);
          if ( v23 )
            usleep_range_state(1000 * v23, 1000 * v23 + 10, 2);
          regulator_set_load(*v19, *((unsigned int *)v19 + 13));
          if ( (int)regulator_count_voltages(*v19) >= 1 )
            regulator_set_voltage(*v19, 0, *((unsigned int *)v19 + 11));
        }
        v20 = v18-- <= 1;
        v19 -= 9;
      }
      while ( !v20 );
    }
    goto LABEL_32;
  }
  if ( a2 < 1 )
  {
LABEL_32:
    LODWORD(v9) = 0;
    goto LABEL_33;
  }
  v5 = 0;
  v6 = v3;
  v7 = -(__int64)(unsigned int)a2;
  v8 = a1;
  while ( 1 )
  {
    v9 = *v8;
    if ( *v8 >= 0xFFFFFFFFFFFFF001LL && (_DWORD)v9 )
    {
      printk(&unk_235A77, v6);
      goto LABEL_36;
    }
    v30 = v8[1];
    v10 = regulator_get_mode(*v8);
    if ( !((unsigned int)v30 ^ 0x63736467 | BYTE4(v30)) && v10 == 1 )
    {
      LODWORD(v9) = 0;
      goto LABEL_5;
    }
    is_enabled = regulator_is_enabled(*v8);
    v12 = *((_DWORD *)v8 + 14);
    v13 = is_enabled;
    if ( v12 && !is_enabled )
      usleep_range_state(1000 * v12, 1000 * v12 + 10, 2);
    v14 = regulator_set_load(*v8, *((unsigned int *)v8 + 12));
    if ( v14 < 0 )
      break;
    if ( (int)regulator_count_voltages(*v8) >= 1 )
      regulator_set_voltage(*v8, *((unsigned int *)v8 + 10), *((unsigned int *)v8 + 11));
    v15 = regulator_enable(*v8);
    v16 = *((_DWORD *)v8 + 15);
    LODWORD(v9) = v15;
    if ( v16 && !v13 )
      usleep_range_state(1000 * v16, 1000 * v16 + 10, 2);
    if ( (v9 & 0x80000000) != 0 )
    {
      printk(&unk_22ECE5, v6);
      regulator_set_load(*v8, *((unsigned int *)v8 + 13));
      goto LABEL_36;
    }
LABEL_5:
    --v5;
    v8 += 9;
    if ( v7 == v5 )
      goto LABEL_33;
  }
  LODWORD(v9) = v14;
  printk(&unk_25086E, v6);
LABEL_36:
  if ( v5 )
  {
    v25 = (unsigned int)~(_DWORD)v5;
    v26 = &a1[9 * (unsigned int)v25];
    v27 = v25 + 1;
    do
    {
      v28 = *((_DWORD *)v26 + 16);
      if ( v28 )
        usleep_range_state(1000 * v28, 1000 * v28 + 10, 2);
      regulator_disable(*v26);
      v29 = *((_DWORD *)v26 + 17);
      if ( v29 )
        usleep_range_state(1000 * v29, 1000 * v29 + 10, 2);
      regulator_set_load(*v26, *((unsigned int *)v26 + 13));
      v20 = v27-- <= 1;
      v26 -= 9;
    }
    while ( !v20 );
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v9;
}
