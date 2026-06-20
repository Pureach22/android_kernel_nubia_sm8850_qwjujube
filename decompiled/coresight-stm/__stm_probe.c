unsigned __int64 __fastcall _stm_probe(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x0
  const char *v5; // x21
  __int64 v6; // x0
  __int64 v7; // x20
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x23
  unsigned __int64 result; // x0
  __int64 v12; // x0
  unsigned __int64 v13; // x19
  unsigned __int64 v14; // x23
  int v15; // w24
  int v16; // w0
  unsigned __int64 v17; // x8
  __int64 v18; // x22
  unsigned int v19; // w23
  __int64 v20; // x8
  int v21; // w1
  int v22; // w8
  __int64 v23; // x0
  int v24; // w8
  unsigned __int64 platform_data; // x0
  __int64 system_id; // x21
  __int64 v27; // x19
  const char *v28; // x0
  _QWORD v29[2]; // [xsp+8h] [xbp-C8h] BYREF
  void *v30; // [xsp+18h] [xbp-B8h]
  unsigned __int64 v31; // [xsp+20h] [xbp-B0h]
  _QWORD *v32; // [xsp+28h] [xbp-A8h]
  _UNKNOWN **v33; // [xsp+30h] [xbp-A0h]
  __int64 v34; // [xsp+38h] [xbp-98h]
  char v35; // [xsp+40h] [xbp-90h]
  _BYTE v36[7]; // [xsp+41h] [xbp-8Fh] BYREF
  unsigned __int64 v37; // [xsp+48h] [xbp-88h]
  __int64 v38; // [xsp+50h] [xbp-80h]
  _QWORD v39[12]; // [xsp+58h] [xbp-78h] BYREF
  int v40; // [xsp+BCh] [xbp-14h] BYREF
  const char *v41[2]; // [xsp+C0h] [xbp-10h] BYREF

  v41[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  memset(v39, 0, sizeof(v39));
  v32 = nullptr;
  v33 = nullptr;
  v30 = nullptr;
  v31 = 0;
  v29[0] = 0;
  v29[1] = 0;
  v4 = coresight_alloc_device_name(&stm_devs, a1);
  v34 = v4;
  if ( !v4 )
    goto LABEL_39;
  v5 = (const char *)v4;
  v6 = devm_kmalloc(a1, 184, 3520);
  if ( !v6 )
    goto LABEL_39;
  v7 = v6;
  v8 = devm_clk_get(a1, "atclk");
  *(_QWORD *)(v7 + 8) = v8;
  if ( v8 <= 0xFFFFFFFFFFFFF000LL )
  {
    v10 = v8;
    result = clk_prepare(v8);
    if ( (_DWORD)result )
      goto LABEL_40;
    v12 = clk_enable(v10);
    if ( (_DWORD)v12 )
    {
      v13 = v12;
      clk_unprepare(v10);
      result = v13;
      goto LABEL_40;
    }
  }
  v9 = clk_get(a1, "apb_pclk");
  if ( v9 < 0xFFFFFFFFFFFFF001LL )
  {
    v14 = v9;
    v15 = clk_prepare(v9);
    if ( !v15 )
    {
      v16 = clk_enable(v14);
      if ( !v16 )
        goto LABEL_13;
      v15 = v16;
      clk_unprepare(v14);
    }
    clk_put(v14);
    v14 = v15;
LABEL_13:
    *(_QWORD *)(v7 + 16) = v14;
    if ( v14 > 0xFFFFFFFFFFFFF000LL )
    {
      result = 4294967277LL;
      goto LABEL_40;
    }
    goto LABEL_15;
  }
  *(_QWORD *)(v7 + 16) = 0;
LABEL_15:
  a1[19] = v7;
  result = devm_ioremap_resource(a1, a2);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)v7 = result;
    v37 = result;
    v38 = 0;
    v35 = 1;
    memset(v36, 0, sizeof(v36));
    v17 = _dev_fwnode(a1);
    result = 4294967294LL;
    if ( v17 )
    {
      if ( v17 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( *(_UNKNOWN **)(v17 + 8) != &of_fwnode_ops )
        {
          result = 4294967294LL;
          goto LABEL_40;
        }
        v18 = a1[93];
        v41[0] = nullptr;
        if ( (of_property_read_string_helper(v18, "reg-names", v41, 1, 0) & 0x80000000) != 0 )
        {
LABEL_24:
          result = 4294967274LL;
          goto LABEL_40;
        }
        v19 = 0;
        while ( strcmp("stm-stimulus-base", v41[0]) )
        {
          if ( (of_property_read_string_helper(v18, "reg-names", v41, 1, ++v19) & 0x80000000) != 0 )
            goto LABEL_24;
        }
        result = of_address_to_resource(v18, v19, v39);
        if ( !(_DWORD)result )
        {
          *(_QWORD *)(v7 + 48) = v39[0];
          result = devm_ioremap_resource(a1, v39);
          if ( result < 0xFFFFFFFFFFFFF001LL )
          {
            v20 = *(_QWORD *)v7;
            *(_QWORD *)(v7 + 40) = result;
            v21 = boot_nr_channel;
            if ( (*(_DWORD *)(v20 + 3748) & 0xF000) != 0 )
              v22 = 8;
            else
              v22 = 4;
            *(_DWORD *)(v7 + 148) = v22;
            if ( !v21 )
            {
              if ( (*(_DWORD *)(*(_QWORD *)v7 + 4040LL) & 0x1FFFF) != 0 )
                v21 = *(_DWORD *)(*(_QWORD *)v7 + 4040LL) & 0x1FFFF;
              else
                v21 = 32;
            }
            *(_DWORD *)(v7 + 160) = v21;
            v23 = devm_bitmap_zalloc(a1);
            *(_QWORD *)(v7 + 56) = v23;
            if ( v23 )
            {
              *(_DWORD *)(v7 + 32) = 0;
              stm_init_default_data(v7);
              *(_QWORD *)(v7 + 64) = v5;
              *(_QWORD *)(v7 + 80) = 0x100000001LL;
              v24 = *(_DWORD *)(v7 + 160);
              *(_QWORD *)(v7 + 92) = 0x100000100LL;
              *(_DWORD *)(v7 + 88) = v24;
              *(_QWORD *)(v7 + 104) = stm_generic_packet;
              *(_QWORD *)(v7 + 112) = stm_mmio_addr;
              *(_QWORD *)(v7 + 120) = stm_generic_link;
              *(_QWORD *)(v7 + 128) = stm_generic_unlink;
              *(_QWORD *)(v7 + 136) = stm_generic_set_options;
              if ( (unsigned int)stm_register_device(a1, v7 + 64, &_this_module) )
              {
                dev_info(a1, "%s : stm_register_device failed, probing deferred\n", v5);
                _pm_runtime_idle(a1, 5);
                result = 4294966779LL;
                goto LABEL_40;
              }
              platform_data = coresight_get_platform_data(a1);
              if ( platform_data >= 0xFFFFFFFFFFFFF001LL )
                goto LABEL_38;
              a1[18] = platform_data;
              v29[0] = 0x200000003LL;
              v30 = &stm_cs_ops;
              v31 = platform_data;
              v32 = a1;
              v33 = &coresight_stm_groups;
              platform_data = coresight_register(v29);
              *(_QWORD *)(v7 + 24) = platform_data;
              if ( platform_data >= 0xFFFFFFFFFFFFF001LL )
              {
LABEL_38:
                system_id = (unsigned int)platform_data;
LABEL_44:
                stm_unregister_device(v7 + 64);
                result = system_id;
                goto LABEL_40;
              }
              if ( (of_property_read_variable_u32_array(a1[93], "atid", &v40, 1, 0) & 0x80000000) != 0 )
              {
                system_id = coresight_trace_id_get_system_id();
                v40 = system_id;
                if ( (system_id & 0x80000000) != 0 )
                {
                  coresight_unregister(*(_QWORD *)(v7 + 24));
                  goto LABEL_44;
                }
              }
              else
              {
                LOBYTE(system_id) = v40;
                *(_BYTE *)(v7 + 176) = 1;
              }
              v27 = *(_QWORD *)(v7 + 24);
              *(_BYTE *)(v7 + 144) = system_id;
              v28 = (const char *)stm_csdev_name(v27);
              dev_info(v27 + 56, "%s initialized\n", v28);
              result = 0;
              goto LABEL_40;
            }
LABEL_39:
            result = 4294967284LL;
          }
        }
      }
    }
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
