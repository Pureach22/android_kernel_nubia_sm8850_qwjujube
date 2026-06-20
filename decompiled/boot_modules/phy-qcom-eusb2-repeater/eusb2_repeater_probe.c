__int64 __fastcall eusb2_repeater_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x21
  _QWORD *v4; // x0
  _QWORD *v5; // x20
  __int64 match_data; // x0
  __int64 regmap; // x0
  unsigned int v8; // w0
  __int64 v9; // x9
  unsigned __int64 v10; // x22
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x2
  unsigned int v17; // w22
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x0
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v1 = a1 + 2;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[95];
  v21 = 0;
  v4 = (_QWORD *)devm_kmalloc(a1 + 2, 48, 3520);
  if ( !v4 )
  {
    v17 = -12;
    goto LABEL_20;
  }
  v5 = v4;
  *v4 = v1;
  a1[21] = v4;
  match_data = of_device_get_match_data(v1);
  v5[4] = match_data;
  if ( !match_data )
  {
    v17 = -22;
    goto LABEL_20;
  }
  regmap = dev_get_regmap(a1[14], 0);
  v5[1] = regmap;
  if ( !regmap )
  {
    v17 = -19;
    goto LABEL_20;
  }
  v8 = of_property_read_variable_u32_array(v3, &unk_6AF8, &v21, 1, 0);
  if ( (v8 & 0x80000000) != 0 )
  {
    v17 = v8;
    goto LABEL_20;
  }
  v9 = v5[4];
  *((_DWORD *)v5 + 10) = v21;
  v10 = *(int *)(v9 + 24);
  if ( !is_mul_ok(v10, 0x18u) )
  {
    v5[3] = 0;
    goto LABEL_24;
  }
  v11 = *v5;
  v12 = devm_kmalloc(*v5, 24 * v10, 3520);
  v5[3] = v12;
  if ( !v12 )
  {
LABEL_24:
    v17 = -12;
LABEL_25:
    dev_err(v1, "unable to get supplies\n");
    goto LABEL_20;
  }
  if ( (int)v10 < 1 )
  {
    v16 = v12;
  }
  else
  {
    v13 = 0;
    v14 = 0;
    do
    {
      v15 = *(_QWORD *)(*(_QWORD *)(v5[4] + 16LL) + v14);
      v14 += 8;
      *(_QWORD *)(v5[3] + v13) = v15;
      v13 += 24;
    }
    while ( 8 * v10 != v14 );
    v16 = v5[3];
  }
  v17 = devm_regulator_bulk_get(v11, (unsigned int)v10, v16);
  if ( (v17 & 0x80000000) != 0 )
    goto LABEL_25;
  v18 = devm_phy_create(v1, v3, eusb2_repeater_ops);
  v5[2] = v18;
  if ( v18 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v1, "failed to create PHY: %d\n", v17);
    v17 = *((_DWORD *)v5 + 4);
  }
  else
  {
    *(_QWORD *)(v18 + 152) = v5;
    v19 = _devm_of_phy_provider_register(v1, 0, &_this_module, &of_phy_simple_xlate);
    if ( v19 < 0xFFFFFFFFFFFFF001LL )
    {
      dev_info(v1, "Registered Qcom-eUSB2 repeater\n");
      v17 = 0;
    }
    else
    {
      v17 = v19;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v17;
}
