unsigned __int64 __fastcall m31eusb2_phy_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned __int64 match_data; // x0
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x1
  const char *v10; // x2
  unsigned __int64 optional; // x0
  unsigned __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x21

  v2 = devm_kmalloc(a1 + 16, 104, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = v2;
  match_data = device_get_match_data(a1 + 16);
  if ( match_data > 0xFFFFFFFFFFFFF000LL )
    return 4294967274LL;
  *(_QWORD *)(v3 + 32) = match_data;
  result = devm_platform_ioremap_resource(a1, 0);
  *(_QWORD *)(v3 + 8) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = devm_platform_ioremap_resource_byname(a1, "eud_enable_reg");
    *(_QWORD *)(v3 + 16) = v6;
    if ( v6 >= 0xFFFFFFFFFFFFF001LL )
      dev_info(a1 + 16, "missing eud_enable register address\n");
    v7 = devm_platform_ioremap_resource_byname(a1, "eud_detect_reg");
    *(_QWORD *)(v3 + 24) = v7;
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
      dev_info(a1 + 16, "missing eud_detect register address\n");
    result = _devm_reset_control_get(a1 + 16, 0, 0, 0, 0, 1);
    *(_QWORD *)(v3 + 64) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v8 = devm_clk_get(a1 + 16, "ref_clk_src");
      *(_QWORD *)(v3 + 72) = v8;
      if ( v8 >= 0xFFFFFFFFFFFFF001LL )
      {
        v9 = v8;
        v10 = "failed to get ref clk src\n";
LABEL_17:
        v13 = a1 + 16;
        return dev_err_probe(v13, v9, v10);
      }
      optional = devm_clk_get_optional(a1 + 16, "ref_clk");
      *(_QWORD *)(v3 + 80) = optional;
      if ( optional >= 0xFFFFFFFFFFFFF001LL )
      {
        v9 = optional;
        v10 = "failed to get ref clk\n";
        goto LABEL_17;
      }
      *(_QWORD *)(a1 + 168) = v3;
      _pm_runtime_set_status(a1 + 16, 0);
      pm_runtime_enable(a1 + 16);
      v12 = devm_phy_create(a1 + 16, 0, m31eusb2_phy_gen_ops);
      *(_QWORD *)v3 = v12;
      if ( v12 >= 0xFFFFFFFFFFFFF001LL )
      {
        v9 = v12;
        v10 = "failed to create phy\n";
        goto LABEL_17;
      }
      v14 = devm_regulator_bulk_get_const(a1 + 16, 3, &m31_eusb_phy_vregs, v3 + 48);
      if ( v14 )
      {
        v9 = v14;
        v10 = "failed to get regulator supplies\n";
        v13 = a1 + 16;
        return dev_err_probe(v13, v9, v10);
      }
      *(_QWORD *)(*(_QWORD *)v3 + 152LL) = v3;
      v15 = devm_of_phy_get_by_index(a1 + 16, *(_QWORD *)(a1 + 760), 0);
      *(_QWORD *)(v3 + 88) = v15;
      if ( v15 >= 0xFFFFFFFFFFFFF001LL )
      {
        v9 = v15;
        v10 = "failed to get repeater\n";
        goto LABEL_17;
      }
      v16 = _devm_of_phy_provider_register(a1 + 16, 0, &_this_module, &of_phy_simple_xlate);
      if ( v16 <= 0xFFFFFFFFFFFFF000LL )
      {
        dev_info(a1 + 16, "Registered M31 USB phy\n");
        if ( *(_QWORD *)(v3 + 16) )
        {
LABEL_26:
          if ( (readl_relaxed() & 1) != 0 )
          {
            m31eusb2_phy_power(v3, 1);
            if ( (*(_BYTE *)(v3 + 98) & 1) == 0 && !(unsigned int)phy_init(*(_QWORD *)(v3 + 88)) )
              *(_BYTE *)(v3 + 98) = 1;
            m31eusb2_phy_clocks(v3, 1);
          }
        }
      }
      else if ( *(_QWORD *)(v3 + 16) )
      {
        goto LABEL_26;
      }
      if ( v16 <= 0xFFFFFFFFFFFFF000LL )
        return 0;
      else
        return (unsigned int)v16;
    }
  }
  return result;
}
