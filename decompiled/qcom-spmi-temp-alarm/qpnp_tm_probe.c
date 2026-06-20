unsigned __int64 __fastcall qpnp_tm_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  _QWORD *v3; // x21
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 regmap; // x0
  unsigned __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x1
  unsigned int v10; // w0
  int v11; // w8
  __int64 v12; // x0
  int v13; // w23
  unsigned int v14; // w0
  int v15; // w8
  __int64 v16; // x0
  int v17; // w22
  unsigned int v18; // w0
  __int64 v19; // x0
  __int64 v20; // x1
  unsigned __int8 v21; // w24
  unsigned int v22; // w0
  unsigned __int64 v23; // x1
  const char *v24; // x2
  _QWORD *v25; // x0
  void *v26; // x8
  void *v27; // x3
  unsigned __int64 v28; // x0
  unsigned int v29; // w0
  unsigned int v30; // w20
  int v31; // [xsp+0h] [xbp-10h] BYREF
  int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v1 = a1 + 2;
  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)a1[95];
  v31 = 0;
  v4 = devm_kmalloc(a1 + 2, 168, 3520);
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_24;
  }
  v5 = v4;
  a1[21] = v4;
  *(_QWORD *)(v4 + 8) = v1;
  _mutex_init(v4 + 64, "&chip->lock", &qpnp_tm_probe___key);
  regmap = dev_get_regmap(a1[14], 0);
  *(_QWORD *)v5 = regmap;
  if ( !regmap )
  {
    result = 4294967290LL;
    goto LABEL_24;
  }
  result = of_property_read_variable_u32_array(v3, "reg", &v31, 1, 0);
  if ( (result & 0x80000000) == 0 )
  {
    result = platform_get_irq(a1, 0);
    *(_DWORD *)(v5 + 56) = result;
    if ( (result & 0x80000000) == 0 )
    {
      result = devm_iio_channel_get(v1, "thermal");
      *(_QWORD *)(v5 + 120) = result;
      if ( result < 0xFFFFFFFFFFFFF001LL || (*(_QWORD *)(v5 + 120) = 0, (_DWORD)result != -517) )
      {
        v8 = *(_QWORD *)v5;
        v32 = 0;
        v9 = (unsigned int)(v31 + 4);
        *(_DWORD *)(v5 + 48) = v31;
        v10 = regmap_read(v8, v9, &v32);
        if ( (v10 & 0x80000000) != 0 )
        {
          v23 = v10;
          v24 = "could not read type\n";
          goto LABEL_22;
        }
        v11 = *(_DWORD *)(v5 + 48);
        v12 = *(_QWORD *)v5;
        v13 = (unsigned __int8)v32;
        v32 = 0;
        v14 = regmap_read(v12, (unsigned int)(v11 + 5), &v32);
        if ( (v14 & 0x80000000) != 0 )
        {
          v23 = v14;
          v24 = "could not read subtype\n";
          goto LABEL_22;
        }
        v15 = *(_DWORD *)(v5 + 48);
        v16 = *(_QWORD *)v5;
        v17 = (unsigned __int8)v32;
        v32 = 0;
        v18 = regmap_read(v16, (unsigned int)(v15 + 1), &v32);
        if ( (v18 & 0x80000000) != 0 )
        {
          v23 = v18;
          v24 = "could not read dig_major\n";
          goto LABEL_22;
        }
        v19 = *(_QWORD *)v5;
        v20 = *(unsigned int *)(v5 + 48);
        v21 = v32;
        v32 = 0;
        v22 = regmap_read(v19, v20, &v32);
        if ( (v22 & 0x80000000) != 0 )
        {
          v30 = v22;
          dev_err(v1, "could not read dig_minor\n");
          result = v30;
          goto LABEL_24;
        }
        *(_DWORD *)(v5 + 28) = (unsigned __int8)v32 | (v21 << 8);
        if ( v13 != 9 || (unsigned int)(v17 - 8) >= 2 && v17 != 192 )
        {
          dev_err(v1, "invalid type 0x%02x or subtype 0x%02x\n", v13, v17);
          result = 4294967277LL;
          goto LABEL_24;
        }
        *(_DWORD *)(v5 + 24) = v17;
        if ( v17 == 9 && v21 >= 2u )
        {
          *(_BYTE *)(v5 + 136) = 1;
LABEL_31:
          if ( *(_BYTE *)(v5 + 136) == 1 )
          {
            result = qpnp_tm_temp_dac_init(v5);
            if ( (result & 0x80000000) != 0 )
              goto LABEL_24;
            v17 = *(_DWORD *)(v5 + 24);
            v27 = &qpnp_tm_sensor_temp_dac_ops;
          }
          else
          {
            v27 = &qpnp_tm_sensor_ops;
          }
          if ( v17 == 192 )
          {
            result = qpnp_tm_temp_lite_init(v5);
            if ( (result & 0x80000000) != 0 )
              goto LABEL_24;
            v27 = &qpnp_tm_sensor_temp_lite_ops;
          }
          v28 = devm_thermal_of_zone_register(v1, 0, v5, v27);
          *(_QWORD *)(v5 + 16) = v28;
          if ( v28 >= 0xFFFFFFFFFFFFF001LL )
          {
            v23 = v28;
            v24 = "failed to register sensor\n";
            v25 = v1;
            goto LABEL_23;
          }
          v29 = qpnp_tm_init(v5);
          if ( (v29 & 0x80000000) == 0 )
          {
            result = devm_request_threaded_irq(v1, *(unsigned int *)(v5 + 56), 0, qpnp_tm_isr, 0x2000, *v3, v5);
            if ( (result & 0x80000000) == 0 )
            {
              thermal_zone_device_update(*(_QWORD *)(v5 + 16), 0);
              result = 0;
            }
            goto LABEL_24;
          }
          v23 = v29;
          v24 = "init failed\n";
LABEL_22:
          v25 = v1;
LABEL_23:
          result = dev_err_probe(v25, v23, v24);
          goto LABEL_24;
        }
        if ( v17 == 9 && v21 )
        {
          v26 = &temp_map_gen2_v1;
        }
        else
        {
          if ( v17 != 8 )
            goto LABEL_31;
          v26 = &temp_map_gen1;
        }
        *(_QWORD *)(v5 + 128) = v26;
        goto LABEL_31;
      }
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
