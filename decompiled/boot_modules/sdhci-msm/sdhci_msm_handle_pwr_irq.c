__int64 __fastcall sdhci_msm_handle_pwr_irq(__int64 a1, int a2)
{
  unsigned int *v4; // x27
  _QWORD *v5; // x22
  __int64 (*v6)(void); // x9
  char v7; // w23
  unsigned int v8; // w21
  __int64 v9; // x2
  _DWORD *v10; // x8
  __int64 v11; // x1
  unsigned int (__fastcall *v12)(__int64, __int64); // x8
  __int64 v13; // x2
  __int64 v14; // x3
  int v15; // w24
  __int64 v17; // x2
  _DWORD *v18; // x8
  __int64 v19; // x1
  unsigned int (__fastcall *v20)(__int64, __int64); // x8
  unsigned int (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x2
  __int64 (__fastcall *v23)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x1
  __int64 v27; // x8
  unsigned int *v28; // x26
  __int64 v29; // x24
  __int64 v30; // x1
  void (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x1
  void (__fastcall *v33)(__int64, __int64); // x8
  __int64 v34; // x1
  void (__fastcall *v35)(__int64, __int64); // x8
  int v36; // w0
  int v37; // w26
  char v38; // w28
  int v39; // w25
  unsigned int v40; // w24
  char v41; // w23
  int v42; // w24
  unsigned int v43; // w28
  int v44; // w8
  unsigned __int64 v45; // x1
  int v46; // w8
  unsigned __int64 v47; // x0
  __int64 v48; // x8
  unsigned int v49; // w0
  unsigned int v50; // w0
  unsigned int v51; // w0
  __int64 v52; // x0
  int v53; // w0
  char v54; // w8
  int v55; // w0
  __int64 v56; // x2
  _DWORD *v57; // x8
  unsigned int *v58; // x27
  unsigned int v59; // t1
  int v60; // w0
  int v61; // w8
  int v62; // w9
  unsigned int v63; // w0
  __int64 v64; // x22
  __int64 v65; // x27
  __int64 (__fastcall *v66)(_QWORD); // x8
  __int64 v67; // x0
  _BOOL4 v68; // w26
  const char *v69; // x2
  unsigned int v70; // t1
  __int64 v71; // x8
  _BOOL4 v72; // w8
  _BOOL4 v73; // w9
  __int64 v74; // x2
  const char *v75; // x3
  __int64 v76; // x2
  __int64 v77; // x2
  _QWORD v78[2]; // [xsp+0h] [xbp-20h] BYREF
  int v79; // [xsp+10h] [xbp-10h]
  __int64 v80; // [xsp+18h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int **)(a1 + 1624);
  v5 = *(_QWORD **)(a1 + 72);
  v6 = **(__int64 (***)(void))(a1 + 1616);
  if ( *((_DWORD *)v6 - 1) != -1793813973 )
    __break(0x8229u);
  v7 = v6();
  v8 = v7 & 0xF;
  if ( *(_QWORD *)(a1 + 2160) && *(_BYTE *)(a1 + 2168) == 1 )
    ipc_log_string(
      *(_QWORD *)(a1 + 2160),
      "%s: Received IRQ(%d), irq_status=0x%x\n",
      "sdhci_msm_handle_pwr_irq",
      a2,
      v8);
  v9 = v4[12];
  v10 = *(_DWORD **)(*(_QWORD *)(a1 + 1616) + 8LL);
  if ( *(v10 - 1) != 1443578770 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64, __int64))v10)(v7 & 0xF, a1, v9);
  v11 = v4[10];
  v12 = **(unsigned int (__fastcall ***)(__int64, __int64))(a1 + 1616);
  if ( *((_DWORD *)v12 - 1) != -1793813973 )
    __break(0x8228u);
  if ( (v12(a1, v11) & v8) != 0 )
  {
    v15 = -11;
    while ( !__CFADD__(v15++, 1) )
    {
      v17 = v4[12];
      v18 = *(_DWORD **)(*(_QWORD *)(a1 + 1616) + 8LL);
      if ( *(v18 - 1) != 1443578770 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, __int64, __int64))v18)(v7 & 0xF, a1, v17);
      _const_udelay(42950);
      v19 = v4[10];
      v20 = **(unsigned int (__fastcall ***)(__int64, __int64))(a1 + 1616);
      if ( *((_DWORD *)v20 - 1) != -1793813973 )
        __break(0x8228u);
      if ( (v20(a1, v19) & v8) == 0 )
        goto LABEL_18;
    }
    v25 = *(_QWORD *)(a1 + 72);
    v26 = *(_QWORD *)(v25 + 120);
    if ( !v26 )
      v26 = *(_QWORD *)(v25 + 8);
    printk(&unk_105AA, v26);
    v27 = *(_QWORD *)(a1 + 72);
    v28 = *(unsigned int **)(a1 + 1624);
    v29 = *(_QWORD *)(v27 + 120);
    if ( !v29 )
      v29 = *(_QWORD *)(v27 + 8);
    v30 = v28[10];
    v31 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
    if ( *((_DWORD *)v31 - 1) != -1793813973 )
      __break(0x8228u);
    v31(a1, v30);
    v32 = v28[11];
    v33 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
    if ( *((_DWORD *)v33 - 1) != -1793813973 )
      __break(0x8228u);
    v33(a1, v32);
    v34 = v28[13];
    v35 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
    if ( *((_DWORD *)v35 - 1) != -1793813973 )
      __break(0x8228u);
    v35(a1, v34);
    printk(&unk_FB5C, v29);
    __break(0x800u);
    if ( !v5[142] )
      goto LABEL_38;
  }
  else
  {
LABEL_18:
    if ( !v5[142] )
      goto LABEL_38;
  }
  v21 = *(unsigned int (__fastcall **)(_QWORD))(v5[116] + 48LL);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != -679167751 )
      __break(0x8228u);
    if ( !v21(v5) && (v7 & 2) != 0 )
    {
      v22 = v4[13];
      v23 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 1616) + 8LL);
      if ( *((_DWORD *)v23 - 1) != 1443578770 )
        __break(0x8228u);
      result = v23(2, a1, v22);
      goto LABEL_117;
    }
  }
LABEL_38:
  if ( (v7 & 2) != 0 )
  {
    v36 = sdhci_msm_setup_vreg(a1 + 1408, 1);
    if ( !v36 )
      v36 = sdhci_msm_set_vdd_io_vol(a1 + 1408, 1);
    if ( v36 )
      v37 = 2;
    else
      v37 = 1;
    if ( (v7 & 1) == 0 )
    {
      v42 = 0;
      v43 = 2;
      v39 = 8;
      goto LABEL_60;
    }
  }
  else
  {
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    v40 = 0;
    if ( (v7 & 1) == 0 )
    {
      if ( (v7 & 4) == 0 )
        goto LABEL_41;
      goto LABEL_87;
    }
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 997LL) & 1) == 0 || *(_BYTE *)(a1 + 2024) == 1 )
    v36 = sdhci_msm_setup_vreg(a1 + 1408, 0);
  if ( !v36 )
    v36 = sdhci_msm_set_vdd_io_vol(a1 + 1408, 0);
  v42 = 1;
  v39 = 4;
  if ( v36 )
    v44 = 2;
  else
    v44 = 1;
  v43 = 1;
  v37 |= v44;
LABEL_60:
  v45 = v5[176];
  if ( v45 <= 0xFFFFFFFFFFFFF000LL && (unsigned int)mmc_regulator_set_ocr(v5) )
  {
    v46 = 2;
    goto LABEL_86;
  }
  v47 = v5[177];
  if ( v47 > 0xFFFFFFFFFFFFF000LL || *((_BYTE *)v5 + 1054) == 3 )
    goto LABEL_80;
  if ( (*((_BYTE *)v5 + 997) & 1) != 0 )
  {
    v48 = v5[142];
    if ( v48 )
    {
      if ( !*(_DWORD *)(v48 + 928) )
      {
        v51 = regulator_set_load();
        if ( !v51 )
          goto LABEL_80;
        v77 = v5[15];
        if ( !v77 )
          v77 = v5[1];
        dev_err(*v5, "%s: vqmmc set load failed: %d\n", v77, v51);
        goto LABEL_157;
      }
    }
  }
  if ( *(unsigned __int8 *)(a1 + 2158) == v43 >> 1 )
  {
LABEL_80:
    v52 = *(_QWORD *)(a1 + 1408) + 16LL;
    if ( (v42 & 1) != 0 )
      v53 = pinctrl_pm_select_sleep_state(v52);
    else
      v53 = pinctrl_pm_select_default_state(v52);
    if ( v53 )
      v46 = 2;
    else
      v46 = 1;
    goto LABEL_86;
  }
  v79 = 0;
  v78[0] = 0;
  v78[1] = 0;
  if ( (v42 & 1) != 0 )
  {
    v49 = regulator_disable(v47, v45, v13, v14);
    goto LABEL_77;
  }
  if ( (*(_DWORD *)(a1 + 1604) & 0x6000000) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 1604) & 0x6000000) == 0x4000000 )
      BYTE1(v79) = 1;
    v50 = mmc_regulator_set_vqmmc(v5, v78);
    if ( (v50 & 0x80000000) == 0 )
    {
      v47 = v5[177];
      goto LABEL_76;
    }
    v76 = v5[15];
    if ( !v76 )
      v76 = v5[1];
    dev_err(*v5, "%s: vqmmc set volgate failed: %d\n", v76, v50);
LABEL_157:
    v46 = 2;
    goto LABEL_86;
  }
LABEL_76:
  v49 = regulator_enable(v47);
LABEL_77:
  if ( !v49 )
  {
    *(_BYTE *)(a1 + 2158) = v43 >> 1;
    goto LABEL_80;
  }
  v74 = v5[15];
  if ( !v74 )
    v74 = v5[1];
  if ( v42 )
    v75 = "dis";
  else
    v75 = "en";
  dev_err(*v5, "%s: vqmm %sable failed: %d\n", v74, v75, v49);
  v46 = 2;
LABEL_86:
  v40 = v46 | v37;
  *(_DWORD *)(a1 + 1568) = v43;
  v38 = 1;
  if ( (v7 & 4) == 0 )
  {
LABEL_41:
    if ( v8 < 8 )
      goto LABEL_42;
LABEL_91:
    if ( (unsigned int)sdhci_msm_set_vdd_io_vol(a1 + 1408, 1) )
      v40 |= 8u;
    else
      v40 |= 4u;
    v39 = 8;
    goto LABEL_95;
  }
LABEL_87:
  if ( (unsigned int)sdhci_msm_set_vdd_io_vol(a1 + 1408, 0) )
    v40 |= 8u;
  else
    v40 |= 4u;
  v39 = 4;
  if ( v8 >= 8 )
    goto LABEL_91;
LABEL_42:
  if ( !v39 )
  {
    v41 = 1;
    goto LABEL_101;
  }
LABEL_95:
  if ( v5[177] > 0xFFFFFFFFFFFFF000LL )
    v54 = 1;
  else
    v54 = v38;
  if ( (v54 & 1) == 0 && (v55 = mmc_regulator_set_vqmmc(v5, v5 + 130), v55 < 0) )
  {
    v69 = (const char *)v5[15];
    if ( !v69 )
      v69 = (const char *)v5[1];
    dev_err(
      *v5,
      "%s: IO_level setting failed(%d). signal_voltage: %d, vdd: %d irq_status: 0x%08x\n",
      v69,
      v55,
      *((unsigned __int8 *)v5 + 1057),
      *((unsigned __int16 *)v5 + 522),
      v8);
    v41 = 0;
    v40 |= 8u;
  }
  else
  {
    v41 = 0;
  }
LABEL_101:
  v56 = v4[13];
  v57 = *(_DWORD **)(*(_QWORD *)(a1 + 1616) + 8LL);
  if ( *(v57 - 1) != 1443578770 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64, __int64))v57)(v40, a1, v56);
  if ( (*(_BYTE *)(a1 + 1607) & 6) == 0 )
    goto LABEL_112;
  v59 = v4[17];
  v58 = v4 + 17;
  v60 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v59));
  v61 = v60;
  if ( (v39 & 8) != 0 )
  {
    v62 = *(_DWORD *)(a1 + 1604);
    if ( (v62 & 0x2000000) == 0 || (*(_BYTE *)(a1 + 2025) & 1) != 0 )
    {
LABEL_109:
      if ( (v62 & 0x4000000) == 0 )
        goto LABEL_112;
      goto LABEL_110;
    }
    if ( *(_BYTE *)(a1 + 2010) != 1 )
    {
      v63 = v60 & 0xFFFEFFFF;
      if ( v61 == (v61 & 0xFFFEFFFF) )
        goto LABEL_112;
      goto LABEL_111;
    }
    v64 = *(_QWORD *)(a1 + 72);
    v65 = *(_QWORD *)(a1 + 1624);
    v66 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v64 + 928) + 48LL);
    if ( v66 )
    {
      v67 = *(_QWORD *)(a1 + 72);
      if ( *((_DWORD *)v66 - 1) != -679167751 )
        __break(0x8228u);
      v68 = v66(v67) != 0;
    }
    else
    {
      v68 = 0;
    }
    v70 = *(_DWORD *)(v65 + 68);
    v58 = (unsigned int *)(v65 + 68);
    v63 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v70));
    v71 = *(_QWORD *)(v64 + 1136);
    if ( v71 || !v68 )
    {
      if ( v71 )
        v73 = v68;
      else
        v73 = 0;
      v72 = v71 != 0;
      if ( !v73 )
      {
LABEL_140:
        if ( !v72 && !v68 && !*(_BYTE *)(v64 + 1054) )
          v63 |= 0x10000u;
        goto LABEL_111;
      }
      if ( *(_BYTE *)(v64 + 1054) != 1 )
      {
        if ( !*(_BYTE *)(v64 + 1054) )
          v63 |= 0x10000u;
        goto LABEL_111;
      }
    }
    else if ( *(_BYTE *)(v64 + 1054) != 1 )
    {
      v72 = 0;
      goto LABEL_140;
    }
    v63 &= ~0x10000u;
    goto LABEL_111;
  }
  if ( (v39 & 4) == 0 )
  {
    v62 = *(_DWORD *)(a1 + 1604);
    goto LABEL_109;
  }
LABEL_110:
  v63 = v60 | 0x10000;
  if ( v61 != (v61 | 0x10000) )
LABEL_111:
    writel_relaxed(v63, (unsigned int *)(*(_QWORD *)(a1 + 24) + *v58));
LABEL_112:
  if ( (v41 & 1) == 0 )
    *(_DWORD *)(a1 + 1572) = v39;
  result = *(_QWORD *)(a1 + 2160);
  if ( result && *(_BYTE *)(a1 + 2168) == 1 )
    result = ipc_log_string(
               result,
               "%s: Handled IRQ(%d), irq_status=0x%x, ack=0x%x\n",
               "sdhci_msm_handle_pwr_irq",
               a2,
               v8,
               v40);
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return result;
}
