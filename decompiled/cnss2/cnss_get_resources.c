__int64 __fastcall cnss_get_resources(__int64 *a1)
{
  unsigned int v2; // w19
  unsigned int vreg_type; // w0
  __int64 v4; // x7
  unsigned int clk; // w0
  __int64 v6; // x7
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  unsigned __int64 v9; // x8
  const char *v10; // x1
  unsigned int pinctrl; // w0
  __int64 v12; // x7
  unsigned __int64 v13; // x8
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  __int16 v17; // w9
  const char *v18; // x8
  __int64 v19; // x19
  unsigned __int64 v20; // x0
  __int64 v21; // x7
  unsigned __int64 v22; // x6
  unsigned __int64 v23; // x8
  __int64 v24; // x0
  const char *v25; // x1
  __int16 v26; // w9
  const char *v27; // x8
  __int64 optional; // x0
  unsigned __int64 v30; // x8
  int v31; // w9
  const char *v32; // x1
  __int16 v33; // w9
  const char *v34; // x8
  const char *v35; // x5
  __int16 v36; // w9
  const char *v37; // x8
  __int16 v38; // w9
  const char *v39; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( *((_BYTE *)a1 + 7880) == 1 )
    return (unsigned int)cnss_fw_managed_domain_attach(a1);
  vreg_type = cnss_get_vreg_type(a1, 0);
  if ( (vreg_type & 0x80000000) == 0 )
  {
    clk = cnss_get_clk(a1);
    if ( clk )
    {
      v2 = clk;
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v8 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v8 = "soft_irq";
        else
          v8 = v16;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v8,
        "cnss_get_resources",
        3u,
        3u,
        "Failed to get clocks, err = %d\n",
        clk,
        v6,
        vars0);
LABEL_27:
      cnss_put_vreg_type(a1, 0);
      return v2;
    }
    pinctrl = cnss_get_pinctrl(a1);
    if ( pinctrl )
    {
      v2 = pinctrl;
      v13 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v26 = *(_DWORD *)(v13 + 16);
        v27 = (const char *)(v13 + 2320);
        if ( (v26 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v27;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "cnss_get_resources",
        3u,
        3u,
        "Failed to get pinctrl, err = %d\n",
        pinctrl,
        v12,
        vars0);
      cnss_put_clk(a1);
      goto LABEL_27;
    }
    v19 = *a1;
    v20 = devm_nvmem_cell_get(*a1 + 16, "xo_calib_reg");
    a1[991] = v20;
    if ( v20 < 0xFFFFFFFFFFFFF001LL )
    {
      optional = devm_regulator_get_optional(v19 + 16, "wcal-pbs");
      a1[992] = optional;
      v22 = optional;
      v30 = _ReadStatusReg(SP_EL0);
      v24 = cnss_ipc_log_context;
      v31 = *(_DWORD *)(v30 + 16) & 0xF0000;
      if ( v22 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( v31 )
        {
          v32 = "irq";
        }
        else
        {
          v38 = *(_DWORD *)(v30 + 16);
          v39 = (const char *)(v30 + 2320);
          if ( (v38 & 0xFF00) != 0 )
            v32 = "soft_irq";
          else
            v32 = v39;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v32,
          "cnss_xo_trim_init",
          7u,
          7u,
          "XO trim initialized\n",
          v22,
          v21,
          vars0);
        return 0;
      }
      if ( v31 )
      {
        v25 = "irq";
      }
      else
      {
        v36 = *(_DWORD *)(v30 + 16);
        v37 = (const char *)(v30 + 2320);
        if ( (v36 & 0xFF00) != 0 )
          v25 = "soft_irq";
        else
          v25 = v37;
      }
      v35 = "Invalid wcal_pbs: %ld\n";
    }
    else
    {
      v22 = v20;
      v23 = _ReadStatusReg(SP_EL0);
      v24 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v23 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else
      {
        v33 = *(_DWORD *)(v23 + 16);
        v34 = (const char *)(v23 + 2320);
        if ( (v33 & 0xFF00) != 0 )
          v25 = "soft_irq";
        else
          v25 = v34;
      }
      v35 = "Invalid xo_calib_reg: %ld\n";
    }
    cnss_debug_ipc_log_print(v24, v25, "cnss_xo_trim_init", 7u, 7u, v35, v22, v21, vars0);
    return 0;
  }
  v2 = vreg_type;
  v9 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v17 = *(_DWORD *)(v9 + 16);
    v18 = (const char *)(v9 + 2320);
    if ( (v17 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v18;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_get_resources",
    3u,
    3u,
    "Failed to get vreg, err = %d\n",
    vreg_type,
    v4,
    vars0);
  return v2;
}
