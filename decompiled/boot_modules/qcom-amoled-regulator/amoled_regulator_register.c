__int64 __fastcall amoled_regulator_register(__int64 *a1, int a2)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  void *v7; // x11
  __int64 v8; // x23
  __int64 v9; // x0
  __int64 *v10; // x21
  __int64 regulator_init_data; // x0
  __int64 v12; // x22
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x0
  int v16; // w8
  unsigned __int64 v17; // x21
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[4] = 0;
  v19[5] = 0;
  if ( a2 )
  {
    v4 = 90;
    if ( a2 == 1 )
    {
      v4 = 46;
      v5 = 87;
    }
    else
    {
      v5 = 131;
    }
    v6 = 98;
    if ( a2 == 1 )
      v6 = 54;
    v7 = &amoled_ibb_ops;
    if ( a2 == 1 )
      v7 = &amoled_ab_ops;
  }
  else
  {
    v7 = &amoled_oledb_ops;
    v6 = 10;
    v5 = 43;
    v4 = 2;
  }
  v8 = a1[v5];
  v9 = *a1;
  v10 = &a1[v4];
  a1[v6] = (__int64)v7;
  regulator_init_data = of_get_regulator_init_data(v9, v8, &a1[v4]);
  if ( !regulator_init_data )
  {
    printk(&unk_7AE9, "amoled_regulator_register");
    LODWORD(v17) = -12;
    goto LABEL_26;
  }
  v12 = regulator_init_data;
  if ( !*(_QWORD *)(regulator_init_data + 8) )
  {
    printk(&unk_78C2, "amoled_regulator_register");
    LODWORD(v17) = -22;
    goto LABEL_26;
  }
  *((_DWORD *)v10 + 19) = 0;
  v10[10] = (__int64)&_this_module;
  v14 = *(_QWORD *)(regulator_init_data + 8);
  v19[0] = *a1;
  v13 = v19[0];
  v19[1] = regulator_init_data;
  *v10 = v14;
  v15 = *(_QWORD *)(v13 + 744);
  v19[2] = a1;
  v19[3] = v8;
  if ( of_get_property(v15, "parent-supply", 0) )
    *(_QWORD *)v12 = "parent";
  v16 = *(_DWORD *)(v12 + 64) | 0xD;
  *(_DWORD *)(v12 + 60) |= 0xEu;
  *(_DWORD *)(v12 + 64) = v16;
  v17 = devm_regulator_register(*a1, v10, v19);
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_787B, "amoled_regulator_register");
    goto LABEL_26;
  }
  if ( !(unsigned int)devm_regulator_debug_register(*a1, v17) )
  {
    if ( a2 )
      goto LABEL_18;
LABEL_25:
    LODWORD(v17) = 0;
    *((_DWORD *)a1 + 88) = 2;
    goto LABEL_26;
  }
  printk(&unk_7AB1, "amoled_regulator_register");
  if ( !a2 )
    goto LABEL_25;
LABEL_18:
  LODWORD(v17) = 0;
  if ( a2 == 2 )
    *((_DWORD *)a1 + 264) = 2;
  else
    *((_DWORD *)a1 + 176) = 2;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v17;
}
