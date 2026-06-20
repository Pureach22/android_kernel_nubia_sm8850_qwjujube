__int64 __fastcall pm8916_pon_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x0
  _QWORD *v4; // x21
  __int64 v5; // x0
  __int64 regmap; // x0
  __int64 result; // x0
  __int64 match_data; // x0
  unsigned int v9; // w0
  unsigned int v10; // w20

  v1 = a1 + 2;
  v3 = devm_kmalloc(a1 + 2, 88, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = (_QWORD *)v3;
  v5 = a1[14];
  *v4 = v1;
  regmap = dev_get_regmap(v5, 0);
  v4[1] = regmap;
  if ( regmap )
  {
    result = of_property_read_variable_u32_array(a1[95], &unk_6880, v4 + 2, 1, 0);
    if ( (result & 0x80000000) == 0 )
    {
      match_data = of_device_get_match_data(v1);
      if ( match_data
        && (v4[3] = v1, v4[10] = match_data, v4[6] = pm8916_reboot_mode_write, (v9 = devm_reboot_mode_register(v1)) != 0) )
      {
        v10 = v9;
        dev_err(v1, "can't register reboot mode\n");
        return v10;
      }
      else
      {
        a1[21] = v4;
        return devm_of_platform_populate(v1);
      }
    }
  }
  else
  {
    dev_err(v1, "failed to locate regmap\n");
    return 4294967277LL;
  }
  return result;
}
