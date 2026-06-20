__int64 __fastcall qcom_hwspinlock_probe(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x0
  unsigned __int64 inited; // x20
  __int64 match_data; // x0
  int v6; // w9
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x21
  __int64 v10; // x22
  __int64 v11; // x23
  unsigned __int64 v12; // x0
  const char *v14; // x1
  __int64 v15; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v16[11]; // [xsp+8h] [xbp-58h] BYREF

  v16[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v15 = 0;
  memset(v16, 0, 80);
  if ( !(unsigned int)_of_parse_phandle_with_args(v2, "syscon", 0, 0, 0, v16) && v16[0] )
  {
    v3 = syscon_node_to_regmap();
    inited = v3;
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( (of_property_read_u32_index(*(_QWORD *)(a1 + 760), "syscon", 1, &v15) & 0x80000000) != 0 )
      {
        v14 = "no offset in syscon\n";
      }
      else
      {
        if ( (of_property_read_u32_index(*(_QWORD *)(a1 + 760), "syscon", 2, (char *)&v15 + 4) & 0x80000000) == 0 )
          goto LABEL_10;
        v14 = "no stride syscon\n";
      }
      dev_err(a1 + 16, v14);
      LODWORD(inited) = -22;
      goto LABEL_19;
    }
    if ( v3 != -19 )
      goto LABEL_10;
  }
  match_data = of_device_get_match_data(a1 + 16);
  if ( !*(_QWORD *)(match_data + 8) )
  {
    LODWORD(inited) = -22;
    goto LABEL_19;
  }
  v6 = *(_DWORD *)(match_data + 4);
  v7 = match_data;
  LODWORD(v15) = *(_DWORD *)match_data;
  HIDWORD(v15) = v6;
  inited = devm_platform_ioremap_resource(a1, 0);
  if ( inited <= 0xFFFFFFFFFFFFF000LL )
    inited = _devm_regmap_init_mmio_clk(a1 + 16, 0, inited, *(_QWORD *)(v7 + 8), 0, 0);
LABEL_10:
  if ( inited < 0xFFFFFFFFFFFFF001LL )
  {
    v8 = devm_kmalloc(a1 + 16, 792, 3520);
    if ( v8 )
    {
      v9 = v8;
      v10 = 0;
      *(_QWORD *)(a1 + 168) = v8;
      v11 = 40;
      while ( 1 )
      {
        *(_OWORD *)((char *)v16 + 4) = 0x1F00000000uLL;
        LODWORD(v16[0]) = v15 + HIDWORD(v15) * v10;
        v12 = devm_regmap_field_alloc(a1 + 16, inited, v16);
        *(_QWORD *)(v9 + v11) = v12;
        if ( v12 >= 0xFFFFFFFFFFFFF001LL )
          break;
        ++v10;
        v11 += 24;
        if ( v10 == 32 )
        {
          LODWORD(inited) = devm_hwspin_lock_register(a1 + 16, v9, qcom_hwspinlock_ops, 0, 32);
          goto LABEL_19;
        }
      }
      LODWORD(inited) = v12;
    }
    else
    {
      LODWORD(inited) = -12;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)inited;
}
