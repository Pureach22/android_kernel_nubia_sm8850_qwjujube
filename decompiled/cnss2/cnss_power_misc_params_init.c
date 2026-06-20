__int64 __fastcall cnss_power_misc_params_init(__int64 *a1)
{
  __int64 v1; // x20
  int string_helper; // w0
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x8
  __int64 v7; // x2
  unsigned __int64 v8; // x8
  __int64 v9; // x0
  const char *v10; // x1
  unsigned __int64 StatusReg; // x8
  __int16 v12; // w9
  const char *v13; // x8
  const char *v14; // x5
  unsigned int v15; // w3
  unsigned int v16; // w4
  __int16 v17; // w9
  const char *v18; // x8
  unsigned __int64 v19; // x8
  __int16 v20; // w9
  const char *v21; // x8
  int v22; // w0
  __int64 v23; // x6
  __int64 v24; // x7
  __int64 v25; // x8
  __int64 v26; // x2
  unsigned __int64 v27; // x8
  __int64 v28; // x0
  const char *v29; // x1
  unsigned __int64 v30; // x8
  __int16 v31; // w9
  const char *v32; // x8
  const char *v33; // x5
  unsigned int v34; // w3
  unsigned int v35; // w4
  __int16 v36; // w9
  const char *v37; // x8
  unsigned __int64 v38; // x8
  __int16 v39; // w9
  const char *v40; // x8
  int v41; // w0
  __int64 v42; // x6
  __int64 v43; // x7
  __int64 v44; // x8
  __int64 v45; // x2
  unsigned __int64 v46; // x8
  __int64 v47; // x0
  const char *v48; // x1
  unsigned __int64 v49; // x8
  __int16 v50; // w9
  const char *v51; // x8
  const char *v52; // x5
  unsigned int v53; // w3
  unsigned int v54; // w4
  __int16 v55; // w9
  const char *v56; // x8
  unsigned __int64 v57; // x8
  __int16 v58; // w9
  const char *v59; // x8
  __int64 v60; // x6
  __int64 v61; // x7
  unsigned __int64 v62; // x8
  const char *v63; // x1
  __int16 v64; // w9
  const char *v65; // x8
  __int64 v66; // x6
  __int64 v67; // x7
  unsigned __int64 v68; // x8
  const char *v69; // x1
  __int16 v70; // w9
  const char *v71; // x8
  int v72; // w0
  __int64 v73; // x6
  __int64 v74; // x7
  unsigned int v75; // w20
  __int64 v76; // x0
  __int64 v77; // x21
  __int64 result; // x0
  unsigned __int64 v79; // x8
  __int64 v80; // x0
  const char *v81; // x1
  __int16 v82; // w9
  const char *v83; // x8
  const char *v84; // x5
  unsigned int v85; // w3
  unsigned int v86; // w4
  unsigned __int64 v87; // x8
  __int16 v88; // w9
  const char *v89; // x8
  char v90; // [xsp+0h] [xbp+0h]

  v1 = *a1;
  string_helper = of_property_read_string_helper(*(_QWORD *)(*a1 + 760), "qcom,pdc_init_table", 0, 0, 0);
  *((_DWORD *)a1 + 1924) = string_helper;
  if ( string_helper < 1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(StatusReg + 16);
      v13 = (const char *)(StatusReg + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v13;
    }
    v14 = "PDC Init Table not configured\n";
    v15 = 7;
    v16 = 7;
    goto LABEL_25;
  }
  v6 = *((unsigned int *)a1 + 1924);
  if ( (v6 & 0x80000000) != 0 )
  {
    a1[959] = 0;
  }
  else
  {
    v7 = _kmalloc_noprof(8 * v6, 3520);
    a1[959] = v7;
    if ( v7 )
    {
      if ( (of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,pdc_init_table", v7, *((int *)a1 + 1924), 0)
          & 0x80000000) == 0 )
        goto LABEL_26;
      v8 = _ReadStatusReg(SP_EL0);
      v9 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
      {
        v10 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(v8 + 16);
        v18 = (const char *)(v8 + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v10 = "soft_irq";
        else
          v10 = v18;
      }
      v14 = "Failed to get PDC Init Table\n";
      goto LABEL_24;
    }
  }
  v19 = _ReadStatusReg(SP_EL0);
  v9 = cnss_ipc_log_context;
  if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v20 = *(_DWORD *)(v19 + 16);
    v21 = (const char *)(v19 + 2320);
    if ( (v20 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v21;
  }
  v14 = "Failed to alloc PDC Init Table mem\n";
LABEL_24:
  v15 = 3;
  v16 = 3;
LABEL_25:
  cnss_debug_ipc_log_print(v9, v10, "cnss_power_misc_params_init", v15, v16, v14, v4, v5, v90);
LABEL_26:
  v22 = of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,vreg_pdc_map", 0, 0, 0);
  *((_DWORD *)a1 + 1925) = v22;
  if ( v22 < 1 )
  {
    v30 = _ReadStatusReg(SP_EL0);
    v28 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v30 + 16) & 0xF0000) != 0 )
    {
      v29 = "irq";
    }
    else
    {
      v31 = *(_DWORD *)(v30 + 16);
      v32 = (const char *)(v30 + 2320);
      if ( (v31 & 0xFF00) != 0 )
        v29 = "soft_irq";
      else
        v29 = v32;
    }
    v33 = "VReg PDC Mapping not configured\n";
    v34 = 7;
    v35 = 7;
    goto LABEL_50;
  }
  v25 = *((unsigned int *)a1 + 1925);
  if ( (v25 & 0x80000000) != 0 )
  {
    a1[960] = 0;
  }
  else
  {
    v26 = _kmalloc_noprof(8 * v25, 3520);
    a1[960] = v26;
    if ( v26 )
    {
      if ( (of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,vreg_pdc_map", v26, *((int *)a1 + 1925), 0)
          & 0x80000000) == 0 )
        goto LABEL_51;
      v27 = _ReadStatusReg(SP_EL0);
      v28 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
      {
        v29 = "irq";
      }
      else
      {
        v36 = *(_DWORD *)(v27 + 16);
        v37 = (const char *)(v27 + 2320);
        if ( (v36 & 0xFF00) != 0 )
          v29 = "soft_irq";
        else
          v29 = v37;
      }
      v33 = "Failed to get VReg PDC Mapping\n";
      goto LABEL_49;
    }
  }
  v38 = _ReadStatusReg(SP_EL0);
  v28 = cnss_ipc_log_context;
  if ( (*(_DWORD *)(v38 + 16) & 0xF0000) != 0 )
  {
    v29 = "irq";
  }
  else
  {
    v39 = *(_DWORD *)(v38 + 16);
    v40 = (const char *)(v38 + 2320);
    if ( (v39 & 0xFF00) != 0 )
      v29 = "soft_irq";
    else
      v29 = v40;
  }
  v33 = "Failed to alloc VReg PDC mem\n";
LABEL_49:
  v34 = 3;
  v35 = 3;
LABEL_50:
  cnss_debug_ipc_log_print(v28, v29, "cnss_power_misc_params_init", v34, v35, v33, v23, v24, v90);
LABEL_51:
  v41 = of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,pmu_vreg_map", 0, 0, 0);
  *((_DWORD *)a1 + 1926) = v41;
  if ( v41 < 1 )
  {
    v49 = _ReadStatusReg(SP_EL0);
    v47 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v49 + 16) & 0xF0000) != 0 )
    {
      v48 = "irq";
    }
    else
    {
      v50 = *(_DWORD *)(v49 + 16);
      v51 = (const char *)(v49 + 2320);
      if ( (v50 & 0xFF00) != 0 )
        v48 = "soft_irq";
      else
        v48 = v51;
    }
    v52 = "PMU VReg Mapping not configured\n";
    v53 = 7;
    v54 = 7;
    goto LABEL_75;
  }
  v44 = *((unsigned int *)a1 + 1926);
  if ( (v44 & 0x80000000) != 0 )
  {
    a1[961] = 0;
  }
  else
  {
    v45 = _kmalloc_noprof(8 * v44, 3520);
    a1[961] = v45;
    if ( v45 )
    {
      if ( (of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,pmu_vreg_map", v45, *((int *)a1 + 1926), 0)
          & 0x80000000) == 0 )
        goto LABEL_76;
      v46 = _ReadStatusReg(SP_EL0);
      v47 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v46 + 16) & 0xF0000) != 0 )
      {
        v48 = "irq";
      }
      else
      {
        v55 = *(_DWORD *)(v46 + 16);
        v56 = (const char *)(v46 + 2320);
        if ( (v55 & 0xFF00) != 0 )
          v48 = "soft_irq";
        else
          v48 = v56;
      }
      v52 = "Fail to get PMU VReg Mapping\n";
      goto LABEL_74;
    }
  }
  v57 = _ReadStatusReg(SP_EL0);
  v47 = cnss_ipc_log_context;
  if ( (*(_DWORD *)(v57 + 16) & 0xF0000) != 0 )
  {
    v48 = "irq";
  }
  else
  {
    v58 = *(_DWORD *)(v57 + 16);
    v59 = (const char *)(v57 + 2320);
    if ( (v58 & 0xFF00) != 0 )
      v48 = "soft_irq";
    else
      v48 = v59;
  }
  v52 = "Failed to alloc PMU VReg mem\n";
LABEL_74:
  v53 = 3;
  v54 = 3;
LABEL_75:
  cnss_debug_ipc_log_print(v47, v48, "cnss_power_misc_params_init", v53, v54, v52, v42, v43, v90);
LABEL_76:
  if ( (a1[66] | 2) == 0x1103 )
  {
    if ( (unsigned int)of_property_read_string(*(_QWORD *)(v1 + 760), "qcom,vreg_ol_cpr", a1 + 957) )
    {
      v62 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v62 + 16) & 0xF0000) != 0 )
      {
        v63 = "irq";
      }
      else
      {
        v64 = *(_DWORD *)(v62 + 16);
        v65 = (const char *)(v62 + 2320);
        if ( (v64 & 0xFF00) != 0 )
          v63 = "soft_irq";
        else
          v63 = v65;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v63,
        "cnss_power_misc_params_init",
        7u,
        7u,
        "VReg for QCA6490 OL CPR not configured\n",
        v60,
        v61,
        v90);
    }
    if ( (unsigned int)of_property_read_string(*(_QWORD *)(v1 + 760), "qcom,vreg_ipa", a1 + 958) )
    {
      v68 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v68 + 16) & 0xF0000) != 0 )
      {
        v69 = "irq";
      }
      else
      {
        v70 = *(_DWORD *)(v68 + 16);
        v71 = (const char *)(v68 + 2320);
        if ( (v70 & 0xFF00) != 0 )
          v69 = "soft_irq";
        else
          v69 = v71;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v69,
        "cnss_power_misc_params_init",
        7u,
        7u,
        "VReg for QCA6490 Int Power Amp not configured\n",
        v66,
        v67,
        v90);
    }
  }
  v72 = of_property_count_elems_of_size(*(_QWORD *)(*a1 + 760), "qcom,on-chip-pmic-support", 4);
  if ( v72 < 1 )
  {
    v79 = _ReadStatusReg(SP_EL0);
    v80 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v79 + 16) & 0xF0000) != 0 )
    {
      v81 = "irq";
    }
    else
    {
      v82 = *(_DWORD *)(v79 + 16);
      v83 = (const char *)(v79 + 2320);
      if ( (v82 & 0xFF00) != 0 )
        v81 = "soft_irq";
      else
        v81 = v83;
    }
    v84 = "On chip PMIC device ids not configured\n";
    v85 = 7;
    v86 = 7;
    return cnss_debug_ipc_log_print(v80, v81, "cnss_power_misc_params_init", v85, v86, v84, v73, v74, v90);
  }
  v75 = v72;
  v76 = _kmalloc_noprof(4LL * (unsigned int)v72, 3520);
  v77 = v76;
  if ( !v76 )
  {
    v87 = _ReadStatusReg(SP_EL0);
    v80 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v87 + 16) & 0xF0000) != 0 )
    {
      v81 = "irq";
    }
    else
    {
      v88 = *(_DWORD *)(v87 + 16);
      v89 = (const char *)(v87 + 2320);
      if ( (v88 & 0xFF00) != 0 )
        v81 = "soft_irq";
      else
        v81 = v89;
    }
    v84 = "Failed to alloc cfg table mem\n";
    v85 = 3;
    v86 = 3;
    return cnss_debug_ipc_log_print(v80, v81, "cnss_power_misc_params_init", v85, v86, v84, v73, v74, v90);
  }
  result = of_property_read_variable_u32_array(*(_QWORD *)(*a1 + 760), "qcom,on-chip-pmic-support", v76, v75, 0);
  if ( (result & 0x80000000) == 0 )
  {
    *((_DWORD *)a1 + 1956) = v75;
    a1[979] = v77;
  }
  return result;
}
