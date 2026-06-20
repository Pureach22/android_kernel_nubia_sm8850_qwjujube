__int64 __fastcall sdhci_msm_setup_vreg(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  char v5; // w19
  const char *v6; // x3
  __int64 v7; // x20
  __int64 **v8; // x8
  __int64 *v9; // x27
  __int64 *v10; // x28
  __int64 v11; // x8
  int v12; // w0
  char v13; // w8
  char v14; // w23
  int v15; // w26
  unsigned int v16; // w25
  __int64 v17; // x0
  unsigned int v18; // w0
  unsigned int v19; // w25
  __int64 v20; // x0
  unsigned int v21; // w0
  __int64 v22; // x8
  unsigned int v23; // w0
  unsigned int v24; // w24
  __int64 v25; // x0
  unsigned int v26; // w0
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x0
  unsigned int v30; // w0
  unsigned int v31; // w24
  __int64 v32; // x0
  unsigned int v33; // w0
  int v34; // w0
  void *v36; // x8
  const char *v37; // x1
  unsigned int v38; // w19
  const char *v39; // x1
  unsigned int v40; // w19
  void *v41; // x0

  v4 = *(_QWORD *)(a1 + 128);
  v5 = a2;
  if ( *(_QWORD *)(a1 + 752) && *(_BYTE *)(a1 + 760) == 1 )
  {
    if ( (a2 & 1) != 0 )
      v6 = "Enabling";
    else
      v6 = "Disabling";
    v7 = a1;
    ipc_log_string(*(_QWORD *)(a1 + 752), "%s: %s regulators\n", "sdhci_msm_setup_vreg", v6);
    a1 = v7;
  }
  v8 = *(__int64 ***)(a1 + 120);
  if ( !v8 )
    return 0;
  v9 = *v8;
  v10 = v8[1];
  if ( (v5 & 1) != 0 || *((_BYTE *)v10 + 81) != 1 || *(_QWORD *)(v4 + 1136) )
  {
    v11 = *(_QWORD *)(v4 + 1136);
    if ( v11 )
    {
LABEL_12:
      if ( !*(_BYTE *)(v11 + 1196) && (*(_BYTE *)(v4 + 997) & 1) != 0 )
        return 0;
    }
  }
  else
  {
    *((_BYTE *)v10 + 81) = 0;
    v11 = *(_QWORD *)(v4 + 1136);
    if ( v11 )
      goto LABEL_12;
  }
  if ( (v5 & 1) == 0 && (*(_BYTE *)(v4 + 997) & 1) == 0 )
  {
    v12 = msm_spare_read(2);
    msm_spare_write(2, v12 & 0xFFFF7FFF);
  }
  v13 = 1;
  while ( 1 )
  {
    while ( 1 )
    {
      v14 = v13;
      if ( v9 )
        break;
LABEL_20:
      v13 = 0;
      v9 = v10;
      if ( (v14 & 1) == 0 )
      {
        if ( (v5 & 1) == 0 )
          return 0;
LABEL_67:
        if ( (*(_BYTE *)(v4 + 997) & 1) == 0 )
        {
          v34 = msm_spare_read(2);
          msm_spare_write(2, v34 | 0x8000u);
        }
        return 0;
      }
    }
    v15 = *((unsigned __int8 *)v9 + 85);
    if ( (v5 & 1) == 0 )
      break;
    v16 = *((_DWORD *)v9 + 19);
    v17 = *(_QWORD *)(*v9 + 752);
    if ( v17 && *(_BYTE *)(*v9 + 760) == 1 )
      ipc_log_string(v17, "%s: reg=%s uA_load=%d\n", "sdhci_msm_vreg_set_optimum_mode", (const char *)v9[3], v16);
    if ( *((_BYTE *)v9 + 83) == 1 )
    {
      v18 = regulator_set_load(v9[1], v16);
      if ( (v18 & 0x80000000) != 0 )
      {
        v39 = "sdhci_msm_vreg_set_optimum_mode";
        v40 = v18;
        v41 = &unk_10163;
        goto LABEL_75;
      }
    }
    if ( (v9[10] & 1) == 0 )
    {
      v19 = *((_DWORD *)v9 + 17);
      v20 = *(_QWORD *)(*v9 + 752);
      if ( v20 && *(_BYTE *)(*v9 + 760) == 1 )
        ipc_log_string(
          v20,
          "%s: reg=%s min_uV=%d max_uV=%d\n",
          "sdhci_msm_vreg_set_voltage",
          (const char *)v9[3],
          v19,
          v19);
      if ( *((_BYTE *)v9 + 83) == 1 && *((_BYTE *)v9 + 84) == 1 )
      {
        v21 = regulator_set_voltage(v9[1], v19, v19);
        if ( v21 )
        {
          v39 = "sdhci_msm_vreg_set_voltage";
          v40 = v21;
          v41 = &unk_10CA2;
          goto LABEL_75;
        }
      }
    }
    if ( v15 )
      v22 = 2;
    else
      v22 = 1;
    v23 = regulator_enable(v9[v22]);
    if ( v23 )
    {
      v36 = &unk_10E01;
      v37 = "sdhci_msm_vreg_enable";
LABEL_73:
      v38 = v23;
      printk(v36, v37);
      return v38;
    }
    v13 = 0;
    *((_BYTE *)v9 + 80) = 1;
    v9 = v10;
    if ( (v14 & 1) == 0 )
      goto LABEL_67;
  }
  if ( *((_BYTE *)v9 + 80) != 1 )
    goto LABEL_20;
  if ( (*((_BYTE *)v9 + 81) & 1) != 0 )
  {
    if ( *((_BYTE *)v9 + 82) == 1 )
    {
      v24 = *((_DWORD *)v9 + 18);
      v25 = *(_QWORD *)(*v9 + 752);
      if ( v25 && *(_BYTE *)(*v9 + 760) == 1 )
        ipc_log_string(v25, "%s: reg=%s uA_load=%d\n", "sdhci_msm_vreg_set_optimum_mode", (const char *)v9[3], v24);
      if ( *((_BYTE *)v9 + 83) == 1 )
      {
        v26 = regulator_set_load(v9[1], v24);
        if ( (v26 & 0x80000000) != 0 )
        {
          v39 = "sdhci_msm_vreg_set_optimum_mode";
          v40 = v26;
          v41 = &unk_10163;
          goto LABEL_75;
        }
      }
    }
    goto LABEL_20;
  }
  if ( *((_BYTE *)v9 + 85) )
    v27 = 2;
  else
    v27 = 1;
  v23 = regulator_disable(v9[v27], a2, a3, a4);
  if ( v23 )
  {
    v36 = &unk_104FB;
    v37 = "sdhci_msm_vreg_disable";
    goto LABEL_73;
  }
  v28 = *v9;
  *((_BYTE *)v9 + 80) = 0;
  v29 = *(_QWORD *)(v28 + 752);
  if ( v29 && *(_BYTE *)(v28 + 760) == 1 )
    ipc_log_string(v29, "%s: reg=%s uA_load=%d\n", "sdhci_msm_vreg_set_optimum_mode", (const char *)v9[3], 0);
  if ( *((_BYTE *)v9 + 83) != 1 || (v30 = regulator_set_load(v9[1], 0), (v30 & 0x80000000) == 0) )
  {
    v31 = *((_DWORD *)v9 + 17);
    v32 = *(_QWORD *)(*v9 + 752);
    if ( v32 && *(_BYTE *)(*v9 + 760) == 1 )
      ipc_log_string(v32, "%s: reg=%s min_uV=%d max_uV=%d\n", "sdhci_msm_vreg_set_voltage", (const char *)v9[3], 0, v31);
    if ( *((_BYTE *)v9 + 83) == 1 && *((_BYTE *)v9 + 84) == 1 )
    {
      v33 = regulator_set_voltage(v9[1], 0, v31);
      if ( v33 )
      {
        v39 = "sdhci_msm_vreg_set_voltage";
        v40 = v33;
        v41 = &unk_10CA2;
        goto LABEL_75;
      }
    }
    goto LABEL_20;
  }
  v39 = "sdhci_msm_vreg_set_optimum_mode";
  v40 = v30;
  v41 = &unk_10163;
LABEL_75:
  printk(v41, v39);
  return v40;
}
