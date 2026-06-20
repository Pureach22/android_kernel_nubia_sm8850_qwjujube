__int64 __fastcall nb7vpq904m_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  unsigned __int64 inited; // x0
  __int64 v7; // x21
  unsigned int variable_u8_array; // w0
  unsigned __int64 optional; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned __int8 v12; // w8
  __int64 v13; // x0
  __int64 dir; // x0
  __int64 v15; // x8
  unsigned int v16; // w22
  int v17; // w8
  int v18; // w9

  v1 = a1 + 32;
  v3 = devm_kmalloc(a1 + 32, 256, 3520);
  if ( !v3 )
    return (unsigned int)-12;
  v4 = v3;
  v5 = alloc_workqueue("%s:pullup", byte_12);
  *(_QWORD *)(v4 + 168) = v5;
  if ( !v5 )
  {
    dev_err(v1, "Failed to create pullup workqueue\n");
    return (unsigned int)-12;
  }
  inited = _devm_regmap_init_i2c(a1, &redriver_regmap, 0, 0);
  *(_QWORD *)(v4 + 96) = inited;
  if ( inited >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = inited;
    dev_err(v1, "Failed to allocate register map: %d\n", (unsigned int)inited);
    return v16;
  }
  v7 = *(_QWORD *)(a1 + 776);
  *(_QWORD *)(v4 + 88) = v1;
  *(_QWORD *)(a1 + 184) = v4;
  if ( of_find_property(v7, "eq", 0)
    && (variable_u8_array = of_property_read_variable_u8_array(v7, "eq", v4 + 132, 8, 0),
        (variable_u8_array & 0x80000000) != 0)
    || of_find_property(v7, "flat-gain", 0)
    && (variable_u8_array = of_property_read_variable_u8_array(v7, "flat-gain", v4 + 156, 8, 0),
        (variable_u8_array & 0x80000000) != 0)
    || of_find_property(v7, "output-comp", 0)
    && (variable_u8_array = of_property_read_variable_u8_array(v7, "output-comp", v4 + 140, 8, 0),
        (variable_u8_array & 0x80000000) != 0)
    || of_find_property(v7, "loss-match", 0)
    && (variable_u8_array = of_property_read_variable_u8_array(v7, "loss-match", v4 + 148, 8, 0),
        (variable_u8_array & 0x80000000) != 0) )
  {
    v16 = variable_u8_array;
    dev_err(*(_QWORD *)(v4 + 88), "%s: error read parameters.\n", "nb7vpq904m_read_configuration");
    dev_err(v1, "Failed to read default configuration: %d\n", v16);
    return v16;
  }
  *(_BYTE *)(v4 + 167) = of_find_property(v7, "set-aux", 0) != 0;
  optional = devm_regulator_get_optional(v1, "vdd");
  *(_QWORD *)(v4 + 112) = optional;
  if ( optional >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v4 + 112) = 0;
    if ( (_DWORD)optional != -19 )
      dev_err(v1, "Failed to get vdd regulator %d\n", optional);
  }
  *(_QWORD *)(v4 + 176) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 184) = v4 + 184;
  *(_QWORD *)(v4 + 192) = v4 + 184;
  *(_QWORD *)(v4 + 216) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 200) = nb7vpq904m_gadget_pullup_work;
  *(_QWORD *)(v4 + 224) = v4 + 224;
  *(_QWORD *)(v4 + 232) = v4 + 224;
  v10 = *(_QWORD *)(v4 + 88);
  *(_QWORD *)(v4 + 240) = nb7vpq904m_host_work;
  *(_BYTE *)(v4 + 165) = of_find_property(*(_QWORD *)(v10 + 744), "lane-channel-swap", 0) != 0;
  v11 = *(_QWORD *)(v4 + 112);
  *(_DWORD *)(v4 + 124) = 0;
  if ( !v11 || (*(_BYTE *)(v4 + 166) & 1) != 0 )
    goto LABEL_17;
  *(_BYTE *)(v4 + 166) = 1;
  ((void (*)(void))regulator_set_load)();
  regulator_set_voltage(*(_QWORD *)(v4 + 112), 1710000, 1890000);
  regulator_enable(*(_QWORD *)(v4 + 112));
  v18 = *(_DWORD *)(v4 + 120);
  v17 = *(_DWORD *)(v4 + 124);
  if ( (*(_BYTE *)(v4 + 165) & 1) != 0 )
    v18 = v18 == 0;
  if ( v17 > 2 )
  {
    if ( v17 == 3 )
    {
      if ( v18 )
        v12 = -15;
      else
        v12 = -13;
    }
    else
    {
      if ( v17 != 4 )
        goto LABEL_17;
      v12 = -5;
    }
  }
  else
  {
    if ( v17 != 1 )
    {
      if ( v17 == 2 )
      {
        v12 = -11;
        goto LABEL_18;
      }
LABEL_17:
      v12 = 0;
      goto LABEL_18;
    }
    if ( v18 == 1 )
      v12 = 59;
    else
      v12 = 11;
    if ( !v18 )
      v12 = -53;
  }
LABEL_18:
  v13 = *(_QWORD *)(v4 + 96);
  *(_BYTE *)(v4 + 164) = v12;
  if ( (regmap_write(v13, 0, v12) & 0x80000000) != 0 )
  {
    dev_err(*(_QWORD *)(v4 + 88), "writing reg 0x%02x failure\n", 0);
    if ( *(_QWORD *)(v4 + 112) )
    {
LABEL_20:
      if ( *(_BYTE *)(v4 + 166) == 1 )
      {
        *(_BYTE *)(v4 + 166) = 0;
        regulator_disable();
        regulator_set_voltage(*(_QWORD *)(v4 + 112), 0, 1890000);
        regulator_set_load(*(_QWORD *)(v4 + 112), 0);
      }
    }
  }
  else if ( *(_QWORD *)(v4 + 112) )
  {
    goto LABEL_20;
  }
  dir = debugfs_create_dir("nb7vpq904m_redriver", 0);
  *(_QWORD *)(v4 + 248) = dir;
  if ( dir )
  {
    debugfs_create_file("eq", 384, dir, v4, &eq_ops);
    debugfs_create_file("flat_gain", 384, *(_QWORD *)(v4 + 248), v4, &flat_gain_ops);
    debugfs_create_file("output_comp", 384, *(_QWORD *)(v4 + 248), v4, &output_comp_ops);
    debugfs_create_file("loss_match", 384, *(_QWORD *)(v4 + 248), v4, &loss_match_ops);
    debugfs_create_bool("lane-channel-swap", 420, *(_QWORD *)(v4 + 248), v4 + 165);
  }
  else
  {
    dev_warn(*(_QWORD *)(v4 + 88), "Couldn't create debug dir\n");
  }
  v15 = *(_QWORD *)(*(_QWORD *)(v4 + 88) + 744LL);
  *(_QWORD *)(v4 + 32) = nb7vpq904m_notify_connect;
  *(_QWORD *)(v4 + 40) = nb7vpq904m_notify_disconnect;
  *(_QWORD *)(v4 + 16) = v15;
  *(_QWORD *)(v4 + 24) = nb7vpq904m_release_usb_lanes;
  *(_QWORD *)(v4 + 48) = nb7vpq904m_gadget_pullup_enter;
  *(_QWORD *)(v4 + 56) = nb7vpq904m_gadget_pullup_exit;
  *(_QWORD *)(v4 + 64) = nb7vpq904m_host_powercycle;
  usb_add_redriver(v4);
  return 0;
}
