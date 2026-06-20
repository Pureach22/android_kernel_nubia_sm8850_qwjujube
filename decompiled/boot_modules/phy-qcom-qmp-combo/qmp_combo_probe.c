__int64 __fastcall qmp_combo_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  unsigned __int64 *v4; // x21
  __int64 match_data; // x0
  unsigned __int64 v6; // x22
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x25
  unsigned __int64 v10; // x24
  unsigned __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  int v16; // w0
  __int64 v17; // x26
  __int64 v18; // x27
  int v19; // w0
  __int64 child_by_name; // x0
  __int64 v21; // x22
  __int64 v22; // x23
  __int64 v23; // x0
  __int64 v24; // x24
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x24
  unsigned __int64 v27; // x25
  unsigned __int64 v28; // x0
  __int64 v29; // x8
  unsigned __int64 v30; // x25
  unsigned __int64 v31; // x0
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x0
  unsigned __int16 *v34; // x24
  unsigned __int64 v35; // x23
  unsigned __int64 v36; // x0
  __int64 v37; // x8
  __int64 (__fastcall *v38)(); // x3
  unsigned __int64 v39; // x20
  unsigned __int16 *v40; // x8
  unsigned int v41; // w9
  int v42; // w23
  const char *v43; // x1
  __int64 v44; // x8
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x0
  _QWORD *v47; // x0
  unsigned __int64 v48; // x0
  unsigned __int64 v50; // x0
  unsigned __int64 v51; // x0
  unsigned __int64 v52; // x0
  unsigned __int64 v53; // x0
  unsigned __int64 v54; // x8
  unsigned __int64 clk_from_child; // x0

  v1 = a1 + 16;
  v3 = devm_kmalloc(a1 + 16, 464, 3520);
  if ( !v3 )
    goto LABEL_64;
  v4 = (unsigned __int64 *)v3;
  *(_QWORD *)v3 = v1;
  *(_DWORD *)(v3 + 456) = 1;
  match_data = of_device_get_match_data(v1);
  v4[1] = match_data;
  if ( !match_data )
  {
LABEL_49:
    LODWORD(v26) = -22;
    return (unsigned int)v26;
  }
  _mutex_init(v4 + 26, "&qmp->phy_mutex", &qmp_combo_probe___key);
  v6 = *v4;
  v7 = _devm_reset_control_get(*v4, "phy", 0, 0, 0, 1);
  v4[23] = v7;
  if ( v7 > 0xFFFFFFFFFFFFF000LL )
  {
    v42 = v7;
    v43 = "failed to get phy_reset\n";
LABEL_56:
    dev_err(v6, v43);
    LODWORD(v26) = v42;
    return (unsigned int)v26;
  }
  v8 = _devm_reset_control_get(v6, "common", 0, 0, 0, 1);
  v4[24] = v8;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    v42 = v8;
    v43 = "failed to get global_phy_reset\n";
    goto LABEL_56;
  }
  v9 = v4[1];
  v10 = *(int *)(v9 + 272);
  if ( !is_mul_ok(v10, 0x18u) )
  {
    v4[25] = 0;
    LODWORD(v26) = -12;
    return (unsigned int)v26;
  }
  v11 = *v4;
  v12 = devm_kmalloc(*v4, 24 * v10, 3520);
  v4[25] = v12;
  if ( !v12 )
    goto LABEL_64;
  if ( (int)v10 >= 1 )
  {
    v13 = 0;
    v14 = 0;
    do
    {
      v15 = *(_QWORD *)(*(_QWORD *)(v9 + 264) + v14);
      v14 += 16;
      *(_QWORD *)(v4[25] + v13) = v15;
      v13 += 24;
    }
    while ( 16 * v10 != v14 );
    v16 = devm_regulator_bulk_get(v11, (unsigned int)v10, v4[25]);
    if ( !v16 )
    {
      v17 = 0;
      v18 = 8;
      while ( 1 )
      {
        v19 = regulator_set_load(*(_QWORD *)(v4[25] + v17 + 8), *(unsigned int *)(*(_QWORD *)(v9 + 264) + v18));
        if ( v19 )
          break;
        v17 += 24;
        v18 += 16;
        if ( 24 * v10 == v17 )
          goto LABEL_16;
      }
      LODWORD(v26) = v19;
      dev_err(v11, "failed to set load at %s\n", *(const char **)(v4[25] + v17));
      return (unsigned int)v26;
    }
LABEL_57:
    LODWORD(v26) = v16;
    dev_err(v11, "failed at devm_regulator_bulk_get\n");
    return (unsigned int)v26;
  }
  v16 = devm_regulator_bulk_get(v11, (unsigned int)v10, v12);
  if ( v16 )
    goto LABEL_57;
LABEL_16:
  child_by_name = of_get_child_by_name(*(_QWORD *)(a1 + 760), "usb3-phy");
  v21 = *(_QWORD *)(a1 + 760);
  if ( !child_by_name )
  {
    v34 = *(unsigned __int16 **)v4[1];
    if ( !v34 )
      goto LABEL_49;
    v35 = *v4;
    v25 = devm_platform_ioremap_resource(*v4 - 16, 0);
    if ( v25 >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_37:
      LODWORD(v26) = v25;
      return (unsigned int)v26;
    }
    v4[2] = v25 + *v34;
    v4[4] = v25 + v34[1];
    v4[5] = v25 + v34[2];
    v40 = v34 + 3;
    v4[7] = v25 + v34[3];
    v4[8] = v25 + v34[4];
    v4[3] = v25 + v34[5];
    v4[9] = v25 + v34[6];
    v4[6] = v25 + v34[7];
    if ( v34[8] )
      v4[10] = v25 + v34[8];
    v4[11] = v25 + v34[9];
    v4[12] = v25 + v34[10];
    v41 = v34[11];
    if ( v34[11] )
      v40 = v34 + 12;
    else
      v41 = v34[1];
    v4[13] = v25 + v41;
    v4[14] = v25 + *v40;
    v44 = v34[13];
    v26 = *v4;
    v45 = v25 + v44;
    v46 = *v4;
    v4[15] = v45;
    v47 = (_QWORD *)devm_kmalloc(v46, 80, 3520);
    v4[20] = (unsigned __int64)v47;
    if ( v47 )
    {
      *v47 = "aux";
      v47[2] = "cfg_ahb";
      v47[4] = "ref";
      v47[6] = "ref_en";
      v47[8] = "com_aux";
      *((_DWORD *)v4 + 42) = 5;
      LODWORD(v26) = devm_clk_bulk_get_optional(v26, 5, v47);
      if ( (_DWORD)v26 )
        return (unsigned int)v26;
      v48 = devm_clk_get(v35, "usb3_pipe");
      v4[16] = v48;
      if ( v48 < 0xFFFFFFFFFFFFF001LL )
      {
        v50 = devm_clk_get(v35, "pipe_clk_mux");
        v4[17] = v50;
        if ( v50 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(v35, "failed to get usb3_pipe_src clock\n");
          v4[17] = 0;
        }
        v51 = devm_clk_get(v35, "pipe_clk_ext_src");
        v4[18] = v51;
        if ( v51 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(v35, "failed to get pipe_clk_ext_src clock\n");
          v4[18] = 0;
        }
        v52 = devm_clk_get(v35, "ref");
        v4[19] = v52;
        if ( v52 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(v35, "failed to get ref_clk_src clock\n");
          v4[19] = 0;
        }
        v22 = v21;
      }
      else
      {
        LODWORD(v26) = dev_err_probe(v35, v48, "failed to get usb3_pipe clock\n");
        v22 = v21;
        if ( (_DWORD)v26 )
          return (unsigned int)v26;
      }
      goto LABEL_38;
    }
LABEL_64:
    LODWORD(v26) = -12;
    return (unsigned int)v26;
  }
  v22 = child_by_name;
  v23 = of_get_child_by_name(*(_QWORD *)(a1 + 760), "dp-phy");
  if ( !v23 )
    goto LABEL_49;
  v21 = v23;
  v24 = *v4 - 16;
  v25 = devm_platform_ioremap_resource(v24, 0);
  v4[3] = v25;
  if ( v25 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_37;
  v25 = devm_platform_ioremap_resource(v24, 1);
  v4[2] = v25;
  if ( v25 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_37;
  v25 = devm_platform_ioremap_resource(v24, 2);
  v4[12] = v25;
  if ( v25 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_37;
  v26 = *v4;
  v27 = v4[1];
  v28 = devm_of_iomap(*v4, v22, 0, 0);
  v4[4] = v28;
  if ( v28 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_28;
  v28 = devm_of_iomap(v26, v22, 1, 0);
  v4[5] = v28;
  if ( v28 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_28;
  v28 = devm_of_iomap(v26, v22, 2, 0);
  v4[6] = v28;
  if ( v28 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_28;
  v29 = *(unsigned int *)(v27 + 292);
  if ( (_DWORD)v29 )
    v4[11] = v28 + v29;
  v28 = devm_of_iomap(v26, v22, 3, 0);
  v4[7] = v28;
  if ( v28 >= 0xFFFFFFFFFFFFF001LL || (v28 = devm_of_iomap(v26, v22, 4, 0), v4[8] = v28, v28 >= 0xFFFFFFFFFFFFF001LL) )
  {
LABEL_28:
    LODWORD(v26) = v28;
    return (unsigned int)v26;
  }
  v53 = devm_of_iomap(v26, v22, 5, 0);
  if ( v53 <= 0xFFFFFFFFFFFFF000LL )
    v54 = v53;
  else
    v54 = 0;
  v4[9] = v54;
  clk_from_child = devm_get_clk_from_child(v26, v22, 0);
  v4[16] = clk_from_child;
  if ( clk_from_child < 0xFFFFFFFFFFFFF001LL
    || (LODWORD(v26) = dev_err_probe(v26, clk_from_child, "failed to get pipe clock\n"), !(_DWORD)v26) )
  {
    v30 = *v4;
    v31 = devm_of_iomap(*v4, v21, 0, 0);
    LODWORD(v26) = v31;
    v4[13] = v31;
    if ( v31 <= 0xFFFFFFFFFFFFF000LL )
    {
      v32 = devm_of_iomap(v30, v21, 2, 0);
      LODWORD(v26) = v32;
      v4[15] = v32;
      if ( v32 <= 0xFFFFFFFFFFFFF000LL )
      {
        v33 = devm_of_iomap(v30, v21, 3, 0);
        LODWORD(v26) = v33;
        v4[14] = v33;
        if ( v33 < 0xFFFFFFFFFFFFF001LL )
          goto LABEL_33;
      }
    }
    if ( !(_DWORD)v26 )
    {
LABEL_33:
      LODWORD(v26) = devm_clk_bulk_get_all(*v4, v4 + 20);
      if ( (v26 & 0x80000000) == 0 )
      {
        *((_DWORD *)v4 + 42) = v26;
LABEL_38:
        LODWORD(v26) = qmp_combo_typec_switch_register(v4);
        if ( !(_DWORD)v26 )
        {
          _pm_runtime_set_status(v1, 0);
          LODWORD(v26) = devm_pm_runtime_enable(v1);
          if ( !(_DWORD)v26 )
          {
            pm_runtime_forbid(v1);
            LODWORD(v26) = qmp_combo_register_clocks(v4, v22, v21);
            if ( !(_DWORD)v26 )
            {
              v26 = devm_phy_create(v1, v22, qmp_combo_usb_phy_ops);
              v4[33] = v26;
              if ( v26 >= 0xFFFFFFFFFFFFF001LL )
              {
                dev_err(v1, "failed to create USB PHY: %d\n", (unsigned int)v26);
              }
              else
              {
                *(_QWORD *)(v26 + 152) = v4;
                v36 = devm_phy_create(v1, v21, qmp_combo_dp_phy_ops);
                LODWORD(v26) = v36;
                v4[36] = v36;
                if ( v36 >= 0xFFFFFFFFFFFFF001LL )
                {
                  dev_err(v1, "failed to create DP PHY: %d\n", (unsigned int)v36);
                }
                else
                {
                  *(_QWORD *)(v36 + 152) = v4;
                  v37 = *(_QWORD *)(a1 + 760);
                  *(_QWORD *)(a1 + 168) = v4;
                  if ( v22 == v37 )
                    v38 = qmp_combo_phy_xlate;
                  else
                    v38 = (__int64 (__fastcall *)())&of_phy_simple_xlate;
                  v39 = _devm_of_phy_provider_register(v1, 0, &_this_module, v38);
                  pm_runtime_allow(v1);
                  if ( v39 <= 0xFFFFFFFFFFFFF000LL )
                    LODWORD(v26) = 0;
                  else
                    LODWORD(v26) = v39;
                }
              }
            }
          }
        }
      }
    }
  }
  return (unsigned int)v26;
}
