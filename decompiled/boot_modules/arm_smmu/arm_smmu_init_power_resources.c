__int64 __fastcall arm_smmu_init_power_resources(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x19
  __int64 v4; // x20
  int string_helper; // w0
  __int64 v6; // x0
  __int64 property; // x21
  __int64 string; // x0
  const char *v9; // x22
  int v10; // w24
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x23
  __int64 v13; // x0
  __int64 v14; // x20
  int v15; // w0
  __int64 v16; // x0
  __int64 v17; // x21
  __int64 v18; // x0
  __int64 v19; // x1
  int v20; // w8
  int v21; // w23
  int v22; // w0
  __int64 v23; // x20
  unsigned __int64 v24; // x0
  __int64 v25; // x8

  v2 = (_QWORD *)devm_kmalloc(a1, 120, 3520);
  if ( !v2 )
    return -12;
  v3 = v2;
  *v2 = a1;
  _mutex_init(v2 + 6, "&pwr->power_lock", &arm_smmu_init_power_resources___key);
  v4 = *v3;
  string_helper = of_property_read_string_helper(*(_QWORD *)(*v3 + 744LL), "clock-names", 0, 0, 0);
  *((_DWORD *)v3 + 4) = string_helper;
  if ( string_helper <= 0 )
  {
    *((_DWORD *)v3 + 4) = 0;
  }
  else
  {
    v6 = devm_kmalloc(v4, 8LL * (unsigned int)string_helper, 3520);
    v3[1] = v6;
    if ( !v6 )
      return -12;
    property = of_find_property(*(_QWORD *)(v4 + 744), "clock-names", 0);
    string = of_prop_next_string(property, 0);
    if ( string )
    {
      v9 = (const char *)string;
      v10 = 0;
      while ( 1 )
      {
        v11 = devm_clk_get(v4, v9);
        v12 = v11;
        if ( v11 > 0xFFFFFFFFFFFFF000LL )
          break;
        if ( !clk_get_rate(v11) )
        {
          v13 = clk_round_rate(v12, 1000);
          clk_set_rate(v12, v13);
        }
        *(_QWORD *)(v3[1] + 8LL * v10++) = v12;
        v9 = (const char *)of_prop_next_string(property, v9);
        if ( !v9 )
          goto LABEL_12;
      }
      dev_err(v4, "Couldn't get clock: %s\n", v9);
      if ( (_DWORD)v12 )
        return (int)v12;
    }
  }
LABEL_12:
  v14 = *v3;
  v15 = of_property_read_string_helper(*(_QWORD *)(*v3 + 744LL), "qcom,regulator-names", 0, 0, 0);
  *((_DWORD *)v3 + 8) = v15;
  if ( v15 <= 0 )
  {
    *((_DWORD *)v3 + 8) = 0;
  }
  else
  {
    v16 = devm_kmalloc(v14, 24LL * (unsigned int)v15, 3520);
    v3[3] = v16;
    if ( !v16 )
      return -12;
    v17 = of_find_property(*(_QWORD *)(v14 + 744), "qcom,regulator-names", 0);
    v18 = of_prop_next_string(v17, 0);
    if ( v18 )
    {
      v19 = v18;
      v20 = 0;
      do
      {
        v21 = v20 + 1;
        *(_QWORD *)(v3[3] + 24LL * v20) = v19;
        v19 = of_prop_next_string(v17, v19);
        v20 = v21;
      }
      while ( v19 );
    }
    v22 = devm_regulator_bulk_get(v14, *((unsigned int *)v3 + 8), v3[3]);
    if ( v22 )
      return v22;
  }
  v23 = *v3;
  if ( !of_find_property(*(_QWORD *)(*v3 + 744LL), "interconnects", 0) )
    return (__int64)v3;
  v24 = devm_of_icc_get(v23, 0);
  v3[5] = v24;
  if ( !v24 || v24 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( v24 == -517 )
    {
      LODWORD(v25) = -517;
    }
    else
    {
      dev_err(v23, "Unable to read interconnect path from devicetree rc: %ld\n", v24);
      v25 = v3[5];
      if ( !v25 )
      {
        LODWORD(v25) = -22;
        return (int)v25;
      }
    }
    if ( !(_DWORD)v25 )
      return (__int64)v3;
    return (int)v25;
  }
  if ( of_find_property(*(_QWORD *)(v23 + 744), "qcom,active-only", 0) )
    icc_set_tag(v3[5], 3);
  return (__int64)v3;
}
