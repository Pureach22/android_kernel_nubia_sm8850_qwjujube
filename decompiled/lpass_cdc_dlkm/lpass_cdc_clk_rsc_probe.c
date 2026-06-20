__int64 __fastcall lpass_cdc_clk_rsc_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x1
  unsigned __int64 v6; // x22
  __int64 v7; // x0
  unsigned int variable_u32_array; // w0
  unsigned int string_helper; // w0
  unsigned int v10; // w22
  __int64 v11; // x0
  const char **v12; // x23
  const char *v13; // x24
  __int64 i; // x25
  unsigned __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v19; // w22
  unsigned int v20; // w20
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 + 2;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v3 = devm_kmalloc(a1 + 2, 288, 3520);
  if ( !v3 )
    goto LABEL_43;
  v4 = v3;
  if ( !of_find_property(a1[95], "qcom,fs-gen-sequence", (char *)v22 + 4) )
  {
    dev_err(v1, "%s: unable to find qcom,fs-gen-sequence property\n", "lpass_cdc_clk_rsc_probe");
    v20 = -22;
    goto LABEL_44;
  }
  v5 = SHIDWORD(v22[0]);
  v6 = SHIDWORD(v22[0]) / 0xCuLL;
  *(_DWORD *)(v4 + 212) = v6;
  v7 = devm_kmalloc(v1, v5, 3520);
  *(_QWORD *)(v4 + 216) = v7;
  if ( !v7 )
    goto LABEL_43;
  variable_u32_array = of_property_read_variable_u32_array(
                         a1[95],
                         "qcom,fs-gen-sequence",
                         v7,
                         (unsigned int)(3 * v6),
                         0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v20 = variable_u32_array;
    dev_err(v1, "%s: unable to parse fs-gen-sequence, ret = %d\n", "lpass_cdc_clk_rsc_probe", variable_u32_array);
    goto LABEL_44;
  }
  string_helper = of_property_read_string_helper(a1[95], "clock-names", 0, 0, 0);
  v10 = string_helper;
  if ( string_helper - 9 <= 0xFFFFFFF7 )
  {
    dev_err(v1, "%s: Invalid number of clocks %d", "lpass_cdc_clk_rsc_probe", string_helper);
    v20 = -22;
    goto LABEL_44;
  }
  v11 = devm_kmalloc(v1, 8LL * string_helper, 3520);
  if ( !v11 )
  {
LABEL_43:
    v20 = -12;
    goto LABEL_44;
  }
  v12 = (const char **)v11;
  of_property_read_string_helper(a1[95], "clock-names", v11, v10, 0);
  v13 = clk_src_name;
  for ( i = 104; i != 168; i += 8 )
  {
    *(_QWORD *)(v4 + i) = 0;
    if ( !v10 )
      __break(1u);
    if ( !strcmp(v13, *v12)
      || v10 != 1
      && (!strcmp(v13, v12[1])
       || v10 != 2
       && (!strcmp(v13, v12[2])
        || v10 != 3
        && (!strcmp(v13, v12[3])
         || v10 != 4
         && (!strcmp(v13, v12[4])
          || v10 != 5
          && (!strcmp(v13, v12[5]) || v10 != 6 && (!strcmp(v13, v12[6]) || v10 != 7 && !strcmp(v13, v12[7]))))))) )
    {
      v15 = devm_clk_get(v1, v13);
      if ( v15 >= 0xFFFFFFFFFFFFF001LL )
      {
        v20 = v15;
        dev_err(v1, "%s: clk get failed for %s with ret %d\n", "lpass_cdc_clk_rsc_probe", v13, v15);
        goto LABEL_44;
      }
      *(_QWORD *)(v4 + i) = v15;
    }
    v13 += 30;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,rx_mclk_mode_muxsel", v22, 1, 0) & 0x80000000) == 0 )
  {
    v16 = devm_ioremap(v1, LODWORD(v22[0]), 4);
    *(_QWORD *)(v4 + 264) = v16;
    if ( !v16 )
    {
      dev_err(v1, "%s: ioremap failed for rx muxsel\n", "lpass_cdc_clk_rsc_probe");
      goto LABEL_43;
    }
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,wsa_mclk_mode_muxsel", v22, 1, 0) & 0x80000000) == 0 )
  {
    v17 = devm_ioremap(v1, LODWORD(v22[0]), 4);
    *(_QWORD *)(v4 + 272) = v17;
    if ( !v17 )
    {
      dev_err(v1, "%s: ioremap failed for wsa muxsel\n", "lpass_cdc_clk_rsc_probe");
      goto LABEL_43;
    }
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,va_mclk_mode_muxsel", v22, 1, 0) & 0x80000000) == 0 )
  {
    v18 = devm_ioremap(v1, LODWORD(v22[0]), 4);
    *(_QWORD *)(v4 + 280) = v18;
    if ( !v18 )
    {
      dev_err(v1, "%s: ioremap failed for va muxsel\n", "lpass_cdc_clk_rsc_probe");
      goto LABEL_43;
    }
  }
  v19 = lpass_cdc_register_res_clk(v1, (__int64)lpass_cdc_clk_rsc_cb);
  if ( (v19 & 0x80000000) != 0 )
  {
    v20 = v19;
    dev_err(v1, "%s: Failed to register cb %d", "lpass_cdc_clk_rsc_probe", v19);
  }
  else
  {
    *(_QWORD *)v4 = v1;
    *(_WORD *)(v4 + 208) = 257;
    _mutex_init(v4 + 8, "&priv->rsc_clk_lock", &lpass_cdc_clk_rsc_probe___key);
    _mutex_init(v4 + 56, "&priv->fs_gen_lock", &lpass_cdc_clk_rsc_probe___key_30);
    a1[21] = v4;
    v20 = v19;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v20;
}
