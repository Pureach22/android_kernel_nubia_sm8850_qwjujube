__int64 __fastcall regulator_stub_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 regulator_init_data; // x0
  __int64 v7; // x22
  int v8; // w8
  int v9; // w11
  _BOOL4 v10; // w9
  __int64 v11; // x0
  __int64 v12; // x8
  unsigned __int64 v13; // x0
  unsigned int v14; // w20
  int v16; // w0
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v1 = a1 + 16;
  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v17[4] = 0;
  v17[5] = 0;
  if ( v2 )
  {
    v4 = devm_kmalloc(a1 + 16, 344, 3520);
    if ( !v4 )
      goto LABEL_12;
    v5 = v4;
    regulator_init_data = of_get_regulator_init_data(v1, *(_QWORD *)(a1 + 760), v4);
    if ( !regulator_init_data )
      goto LABEL_12;
    v7 = regulator_init_data;
    if ( !*(_QWORD *)(regulator_init_data + 8) )
    {
      dev_err(v1, "%s: regulator name not specified\n", "regulator_stub_probe");
      v14 = -22;
      goto LABEL_13;
    }
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,system-load", v5 + 336, 1, 0);
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,hpm-min-load", v5 + 332, 1, 0);
    v8 = *(_DWORD *)(v5 + 336) >= *(_DWORD *)(v5 + 332) ? 2 : 4;
    *(_DWORD *)(v5 + 320) = *(_DWORD *)(v7 + 16);
    *(_DWORD *)(v5 + 328) = v8;
    v9 = *(_DWORD *)(v7 + 20);
    v10 = *(_QWORD *)(v7 + 16) != 0;
    *(_DWORD *)(v7 + 64) |= 0x14u;
    *(_DWORD *)(v7 + 68) = v9;
    *(_DWORD *)(v7 + 60) = 6;
    *(_DWORD *)(v5 + 56) = 2 * v10;
    v11 = devm_kstrdup(v1, *(_QWORD *)(v7 + 8), 3264);
    *(_QWORD *)v5 = v11;
    if ( v11 )
    {
      *(_QWORD *)(v5 + 8) = "parent";
      *(_QWORD *)(v5 + 64) = &regulator_stub_ops;
      *(_QWORD *)(v5 + 80) = &_this_module;
      v12 = *(_QWORD *)(a1 + 760);
      *(_DWORD *)(v5 + 76) = 0;
      v17[0] = v1;
      v17[1] = v7;
      v17[2] = v5;
      v17[3] = v12;
      v13 = devm_regulator_register(v1, v5, v17);
      v14 = v13;
      if ( v13 < 0xFFFFFFFFFFFFF001LL )
      {
        v16 = devm_regulator_debug_register(v1, v13);
        if ( v16 )
          dev_err(v1, "failed to register debug regulator, rc=%d\n", v16);
        v14 = 0;
      }
      else if ( (_DWORD)v13 == -517 )
      {
        v14 = -517;
      }
      else
      {
        dev_err(v1, "%s: regulator_register failed\n", "regulator_stub_probe");
      }
    }
    else
    {
LABEL_12:
      v14 = -12;
    }
  }
  else
  {
    dev_err(a1 + 16, "%s: device node missing\n", "regulator_stub_probe");
    v14 = -19;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v14;
}
