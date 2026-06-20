__int64 __fastcall reg_fixed_voltage_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  _BYTE *match_data; // x23
  __int64 v4; // x0
  __int64 v5; // x24
  __int64 v6; // x20
  __int64 v7; // x0
  unsigned __int64 v8; // x22
  __int64 regulator_init_data; // x0
  __int16 v10; // w8
  __int64 v11; // x9
  int v12; // w9
  __int64 v13; // x0
  unsigned __int64 v14; // x0
  __int64 v15; // x0
  int required_opp_performance_state; // w0
  __int64 v17; // x1
  __int64 v18; // x0
  int v19; // w8
  __int64 v20; // x2
  unsigned __int64 optional; // x0
  unsigned __int64 v22; // x1
  const char *v23; // x2
  _QWORD *v24; // x0
  int v25; // w0
  __int64 v26; // x8
  __int64 v27; // x9
  unsigned __int64 v28; // x22
  __int64 v30; // x1
  int v31; // w0
  int v32; // w0
  __int64 v33; // x0
  unsigned int v34; // w0
  unsigned int v35; // w0
  _QWORD *v36; // [xsp+8h] [xbp-38h] BYREF
  __int64 v37; // [xsp+10h] [xbp-30h]
  __int64 v38; // [xsp+18h] [xbp-28h]
  __int64 v39; // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h]
  unsigned __int64 v41; // [xsp+30h] [xbp-10h]
  __int64 v42; // [xsp+38h] [xbp-8h]

  v1 = a1 + 2;
  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  match_data = (_BYTE *)of_device_get_match_data(a1 + 2);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = nullptr;
  v37 = 0;
  v4 = devm_kmalloc(v1, 344, 3520);
  if ( !v4 )
    goto LABEL_34;
  v5 = a1[95];
  v6 = v4;
  if ( !v5 )
  {
    v8 = a1[20];
    if ( !v8 )
      goto LABEL_34;
LABEL_13:
    v13 = devm_kstrdup(v1, *(_QWORD *)v8, 3264);
    *(_QWORD *)v6 = v13;
    if ( !v13 )
    {
      dev_err(v1, "Failed to allocate supply name\n");
      LODWORD(v8) = -12;
      goto LABEL_38;
    }
    *(_DWORD *)(v6 + 76) = 0;
    *(_QWORD *)(v6 + 80) = &_this_module;
    if ( match_data )
    {
      if ( *match_data == 1 )
      {
        *(_QWORD *)(v6 + 64) = &fixed_voltage_clkenabled_ops;
        v14 = devm_clk_get(v1, 0);
        *(_QWORD *)(v6 + 328) = v14;
        if ( v14 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(v1, "Can't get enable-clock from devicetree\n");
          LODWORD(v8) = *(_DWORD *)(v6 + 328);
          goto LABEL_38;
        }
LABEL_24:
        *(_DWORD *)(v6 + 292) = *(_DWORD *)(v8 + 20);
        *(_DWORD *)(v6 + 296) = *(_DWORD *)(v8 + 24);
        v17 = *(_QWORD *)(v8 + 8);
        if ( !v17 || (v18 = devm_kstrdup(v1, v17, 3264), (*(_QWORD *)(v6 + 8) = v18) != 0) )
        {
          v19 = *(_DWORD *)(v8 + 16);
          if ( v19 )
          {
            *(_DWORD *)(v6 + 56) = 1;
            v19 = *(_DWORD *)(v8 + 16);
          }
          *(_DWORD *)(v6 + 100) = v19;
          if ( (*(_BYTE *)(v8 + 28) & 1) != 0 )
            v20 = 23;
          else
            v20 = 19;
          optional = gpiod_get_optional(v1, 0, v20);
          v41 = optional;
          if ( optional < 0xFFFFFFFFFFFFF001LL )
          {
            v26 = *(_QWORD *)(v8 + 32);
            v27 = a1[95];
            v36 = v1;
            v37 = v26;
            v38 = v6;
            v39 = v27;
            v28 = devm_regulator_register(v1, v6, &v36);
            *(_QWORD *)(v6 + 320) = v28;
            if ( v28 >= 0xFFFFFFFFFFFFF001LL )
            {
              v25 = dev_err_probe(v1, (unsigned int)v28, "Failed to register regulator: %ld\n", v28);
              goto LABEL_37;
            }
            v30 = a1[95];
            a1[21] = v6;
            v31 = devm_regulator_proxy_consumer_register(v1, v30);
            if ( v31 )
              dev_err(v1, "failed to register proxy consumer, ret=%d\n", v31);
            v32 = devm_regulator_debug_register(v1, v28);
            if ( v32 )
              dev_err(v1, "failed to register debug regulator, ret=%d\n", v32);
            v33 = _dev_fwnode(v1);
            v34 = fwnode_irq_get(v33, 0);
            LODWORD(v8) = 0;
            if ( v34 == -22 )
              goto LABEL_38;
            v22 = v34;
            if ( (v34 & 0x80000000) != 0 )
            {
              v23 = "Failed to get IRQ\n";
            }
            else
            {
              v35 = devm_request_threaded_irq(
                      v1,
                      v34,
                      0,
                      reg_fixed_under_voltage_irq_handler,
                      0x2000,
                      "under-voltage",
                      v6);
              if ( !v35 )
              {
                LODWORD(v8) = 0;
                goto LABEL_38;
              }
              v22 = v35;
              v23 = "Failed to request IRQ\n";
            }
            v24 = v1;
          }
          else
          {
            v22 = optional;
            v23 = "can't get GPIO\n";
            v24 = v1;
          }
          v25 = dev_err_probe(v24, v22, v23);
LABEL_37:
          LODWORD(v8) = v25;
          goto LABEL_38;
        }
LABEL_34:
        LODWORD(v8) = -12;
        goto LABEL_38;
      }
      if ( match_data[1] == 1 )
      {
        v15 = a1[95];
        *(_QWORD *)(v6 + 64) = &fixed_voltage_domain_ops;
        required_opp_performance_state = of_get_required_opp_performance_state(v15, 0);
        *(_DWORD *)(v6 + 340) = required_opp_performance_state;
        if ( required_opp_performance_state < 0 )
        {
          dev_err(v1, "Can't get performance state from devicetree\n");
          LODWORD(v8) = *(_DWORD *)(v6 + 340);
          goto LABEL_38;
        }
        goto LABEL_24;
      }
    }
    *(_QWORD *)(v6 + 64) = &fixed_voltage_ops;
    goto LABEL_24;
  }
  v7 = devm_kmalloc(v1, 40, 3520);
  if ( !v7 )
  {
    LODWORD(v8) = -12;
    goto LABEL_38;
  }
  v8 = v7;
  regulator_init_data = of_get_regulator_init_data(v1, a1[95], v6);
  *(_QWORD *)(v8 + 32) = regulator_init_data;
  if ( !regulator_init_data )
  {
    LODWORD(v8) = -22;
    goto LABEL_38;
  }
  v10 = *(_WORD *)(regulator_init_data + 228);
  v11 = *(_QWORD *)(regulator_init_data + 8);
  *(_WORD *)(regulator_init_data + 228) = v10 & 0xFFFB;
  *(_QWORD *)v8 = v11;
  v12 = *(_DWORD *)(regulator_init_data + 16);
  if ( v12 != *(_DWORD *)(regulator_init_data + 20) )
  {
    dev_err(v1, "Fixed regulator specified with variable voltages\n");
    LODWORD(v8) = -22;
    goto LABEL_38;
  }
  *(_DWORD *)(v8 + 16) = v12;
  if ( (v10 & 2) != 0 )
    *(_BYTE *)(v8 + 28) |= 1u;
  of_property_read_variable_u32_array(v5, "startup-delay-us", v8 + 20, 1, 0);
  of_property_read_variable_u32_array(v5, "off-on-delay-us", v8 + 24, 1, 0);
  if ( of_find_property(v5, "vin-supply", 0) )
    *(_QWORD *)(v8 + 8) = "vin";
  if ( v8 < 0xFFFFFFFFFFFFF001LL )
    goto LABEL_13;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v8;
}
