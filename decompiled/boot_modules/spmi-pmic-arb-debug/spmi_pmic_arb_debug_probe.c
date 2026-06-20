unsigned __int64 __fastcall spmi_pmic_arb_debug_probe(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w20
  _QWORD *resource_byname; // x0
  const char *v5; // x2
  __int64 v6; // x2
  __int64 v7; // x0
  bool v8; // nf
  __int64 v9; // x20
  int v10; // w22
  unsigned int v11; // w21
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // x20
  __int64 v15; // x0
  unsigned __int64 result; // x0
  unsigned __int64 v17; // x0
  __int64 match_data; // x0
  __int64 v19; // x21
  _QWORD *v20; // x0
  __int64 v21; // x8
  const char *v22; // x1
  unsigned __int64 v23; // x22
  char v24; // w24
  _QWORD *v25; // x0
  __int64 v26; // x8
  unsigned __int64 v27; // x20
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v28 = 0;
  v3 = of_property_read_variable_u32_array(v2, "qcom,fuse-disable-bit", &v28, 1, 0);
  if ( (v3 & 0x80000000) == 0
    || (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,fuse-enable-bit", &v28, 1, 0) & 0x80000000) == 0 )
  {
    if ( v28 >= 0x20 )
    {
      v22 = "qcom,fuse-%s-bit supports values 0 to 31, but %u specified\n";
      if ( v3 < 0 )
        v5 = "enable";
      else
        v5 = "disable";
      goto LABEL_39;
    }
    resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "fuse");
    if ( !resource_byname )
    {
      v22 = "fuse address not specified\n";
LABEL_39:
      dev_err(a1 + 16, v22, v5);
      goto LABEL_40;
    }
    if ( arm64_use_ng_mappings )
      v6 = 0x68000000000F13LL;
    else
      v6 = 0x68000000000713LL;
    v7 = ioremap_prot(*resource_byname, resource_byname[1] - *resource_byname + 1LL, v6);
    if ( !v7 )
    {
LABEL_40:
      result = 4294967274LL;
      goto LABEL_41;
    }
    v8 = v3 < 0;
    v9 = v7;
    v10 = !v8;
    v11 = readl_relaxed();
    iounmap(v9);
    if ( v10 != ((((unsigned __int64)v11 >> v28) & 1) == 0) )
    {
      dev_err(a1 + 16, "SPMI PMIC arbiter debug bus disabled by fuse\n", v12);
      result = 4294967277LL;
      goto LABEL_41;
    }
  }
  v13 = devm_kmalloc(a1 + 16, 32, 3520);
  if ( !v13 )
    goto LABEL_36;
  v14 = v13;
  v15 = platform_get_resource_byname(a1, 512, "core");
  if ( !v15 )
  {
    v22 = "core address not specified\n";
    goto LABEL_39;
  }
  result = devm_ioremap_resource(a1 + 16, v15);
  *(_QWORD *)v14 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_41;
  if ( of_find_property(*(_QWORD *)(a1 + 760), "clock-names", 0) )
  {
    v17 = devm_clk_get(a1 + 16, "core_clk");
    *(_QWORD *)(v14 + 16) = v17;
    if ( v17 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v17 == -517 )
      {
        result = 4294966779LL;
      }
      else
      {
        v27 = v17;
        dev_err(a1 + 16, "unable to request core clock, rc=%d\n", v17);
        result = v27;
      }
      goto LABEL_41;
    }
  }
  *(_DWORD *)(v14 + 8) = 0;
  match_data = device_get_match_data(a1 + 16);
  v19 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v14 + 24) = match_data;
  v29[0] = 0;
  if ( (unsigned int)of_device_is_compatible(v19, "qcom,spmi-pmic-arb-debug") )
  {
    v20 = (_QWORD *)devm_spmi_controller_alloc(a1 + 16, 16);
    if ( v20 )
    {
      v21 = v20[19];
      *(_QWORD *)v21 = v14;
      *(_BYTE *)(v21 + 8) = 0;
      v20[115] = pmic_arb_debug_cmd;
      v20[116] = pmic_arb_debug_read_cmd;
      v20[93] = v19;
      v20[117] = pmic_arb_debug_write_cmd;
      result = devm_spmi_controller_add(a1 + 16, v20);
      goto LABEL_41;
    }
LABEL_36:
    result = 4294967284LL;
    goto LABEL_41;
  }
  result = of_get_next_available_child(v19, 0);
  if ( result )
  {
    v23 = result;
    do
    {
      if ( (of_node_name_eq(v23, "spmi") & 1) != 0 )
      {
        if ( (of_property_read_reg(v23, 0, v29, 0) & 0x80000000) != 0 )
        {
          v22 = "no reg property specified\n";
          goto LABEL_39;
        }
        v24 = v29[0];
        if ( v29[0] >= (unsigned __int64)*(unsigned __int8 *)(*(_QWORD *)(v14 + 24) + 1LL) )
        {
          dev_err(a1 + 16, "Unsupported bus index %llu\n", v29[0]);
          goto LABEL_40;
        }
        v25 = (_QWORD *)devm_spmi_controller_alloc(a1 + 16, 16);
        if ( !v25 )
          goto LABEL_36;
        v26 = v25[19];
        *(_QWORD *)v26 = v14;
        *(_BYTE *)(v26 + 8) = v24;
        v25[93] = v23;
        v25[115] = pmic_arb_debug_cmd;
        v25[116] = pmic_arb_debug_read_cmd;
        v25[117] = pmic_arb_debug_write_cmd;
        result = devm_spmi_controller_add(a1 + 16, v25);
        if ( (_DWORD)result )
          break;
      }
      result = of_get_next_available_child(v19, v23);
      v23 = result;
    }
    while ( result );
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
