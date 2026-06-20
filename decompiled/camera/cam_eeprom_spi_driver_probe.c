__int64 __fastcall cam_eeprom_spi_driver_probe(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x1
  __int64 v4; // x0
  __int64 v5; // x19
  int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  int v10; // w0
  unsigned int v11; // w20
  unsigned int v12; // w0
  const char *v13; // x3
  const char *v14; // x5
  __int64 v15; // x1
  __int64 v16; // x4
  _QWORD *v17; // x0

  *(_DWORD *)(a1 + 944) = 0;
  *(_BYTE *)(a1 + 940) = 8;
  spi_setup();
  v2 = debug_priority;
  v3 = debug_mdl & 0x10000;
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v3,
      4,
      "cam_eeprom_spi_driver_probe",
      506,
      "irq[%d] cs[%x] CPHA[%x] CPOL[%x] CS_HIGH[%x]",
      *(_DWORD *)(a1 + 948),
      a1 + 924,
      *(_DWORD *)(a1 + 944) & 1,
      (*(_DWORD *)(a1 + 944) >> 1) & 1,
      (*(_DWORD *)(a1 + 944) >> 2) & 1);
    v2 = debug_priority;
    v3 = debug_mdl & 0x10000;
    if ( (debug_mdl & 0x10000) == 0 )
      goto LABEL_6;
  }
  else if ( !v3 )
  {
    goto LABEL_6;
  }
  if ( !v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v3,
      4,
      "cam_eeprom_spi_driver_probe",
      507,
      "max_speed[%u]",
      *(_DWORD *)(a1 + 920));
LABEL_6:
  if ( mem_trace_en == 1 )
    v4 = cam_mem_trace_alloc(4408, 0xCC0u, 0, "cam_eeprom_spi_setup", 0x1AAu);
  else
    v4 = _kvmalloc_node_noprof(4408, 0, 3520, 0xFFFFFFFFLL);
  v5 = v4;
  if ( !v4 )
    return (unsigned int)-12;
  v6 = (unsigned __int8)mem_trace_en;
  *(_QWORD *)(v4 + 112) = a1 + 968;
  *(_QWORD *)(v4 + 96) = a1;
  *(_QWORD *)(v4 + 4128) = &cam_eeprom_subdev_ops;
  *(_BYTE *)(v4 + 4296) = 0;
  *(_QWORD *)(v4 + 4320) = 0;
  *(_QWORD *)(v4 + 4304) = 0;
  if ( v6 == 1 )
    v7 = cam_mem_trace_alloc(56, 0xCC0u, 0, "cam_eeprom_spi_setup", 0x1B7u);
  else
    v7 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
  v8 = v7;
  if ( v7 )
  {
    if ( mem_trace_en )
    {
      v9 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_eeprom_spi_setup", 0x1BDu);
      if ( !v9 )
        goto LABEL_36;
    }
    else
    {
      v9 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
      if ( !v9 )
      {
LABEL_36:
        v11 = 0;
LABEL_37:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v8, 0);
        else
          kvfree(v8);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v5, 0);
        else
          kvfree(v5);
        return v11;
      }
    }
    *(_QWORD *)(v5 + 3384) = v9;
    *(_DWORD *)(v5 + 4288) = 2;
    *(_DWORD *)(v5 + 3664) = 3;
    *(_QWORD *)(v5 + 3688) = v8;
    *(_QWORD *)v8 = a1;
    *(_QWORD *)(v5 + 4344) = v5 + 4344;
    *(_QWORD *)(v5 + 4352) = v5 + 4344;
    *(_QWORD *)(v9 + 16) = a1;
    *(_WORD *)(v8 + 47) = 1;
    _mutex_init(v5 + 40, "&(e_ctrl->eeprom_mutex)", &cam_eeprom_spi_setup___key);
    *(_DWORD *)(v5 + 4208) = -1;
    v10 = cam_eeprom_parse_dt(v5);
    if ( v10 )
    {
      v11 = v10;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_spi_setup",
        468,
        "failed: spi soc init rc %d",
        v10);
    }
    else
    {
      v12 = cam_eeprom_spi_parse_of(v8);
      if ( v12 )
      {
        v11 = v12;
        v13 = "cam_eeprom_spi_setup";
        v14 = "Device tree parsing error";
        v15 = 0x10000;
        v16 = 474;
      }
      else
      {
        *(_QWORD *)(v5 + 4136) = &cam_eeprom_internal_ops;
        *(_DWORD *)(v5 + 4152) = 12;
        *(_QWORD *)(v5 + 4128) = &cam_eeprom_subdev_ops;
        *(_DWORD *)(v5 + 4168) = 65548;
        strcpy((char *)v5, "cam-eeprom");
        *(_QWORD *)(v5 + 4144) = v5;
        *(_QWORD *)(v5 + 4160) = v5;
        *(_DWORD *)(v5 + 4200) = 1;
        v11 = cam_register_subdev(v5 + 3736);
        if ( !v11 )
        {
          *(_QWORD *)(v5 + 4240) = 0;
          *(_QWORD *)(v5 + 4232) = 0;
          *(_QWORD *)(v5 + 4224) = 0;
          *(_QWORD *)(v5 + 3984) = v5;
          return v11;
        }
        v13 = "cam_eeprom_init_subdev";
        v14 = "Fail with cam_register_subdev";
        v15 = 32;
        v16 = 193;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v15,
        1,
        v13,
        v16,
        v14);
    }
    v17 = *(_QWORD **)(v5 + 3384);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v17, 0);
    else
      kvfree(v17);
    goto LABEL_37;
  }
  if ( mem_trace_en )
    cam_mem_trace_free((_QWORD *)v5, 0);
  else
    kvfree(v5);
  return (unsigned int)-12;
}
