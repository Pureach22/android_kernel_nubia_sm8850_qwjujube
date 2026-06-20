__int64 __fastcall msm_pcie_enable_link(__int64 a1)
{
  __int64 v2; // x20
  __int64 *v3; // x26
  __int64 v4; // x20
  int v5; // w0
  __int64 v6; // x20
  int v7; // w0
  unsigned int *v8; // x20
  __int64 v9; // x20
  int v10; // w0
  __int64 v11; // x20
  __int64 v12; // x20
  int v13; // w0
  __int64 v14; // x20
  int v15; // w21
  int v16; // w0
  __int64 v17; // x20
  int v18; // w21
  int v19; // w0
  unsigned int *v20; // x20
  __int64 v21; // x22
  unsigned int *v22; // x21
  __int64 v23; // x22
  __int64 v24; // x20
  __int64 v25; // x20
  __int64 v26; // x20
  __int64 v27; // x20
  int v28; // w0
  __int64 v29; // x20
  __int64 v30; // x21
  int v31; // w0
  __int64 v32; // x20
  int v33; // w0
  __int64 v34; // x20
  int v35; // w21
  int v36; // w0
  __int64 v37; // x20
  int v38; // w21
  int v39; // w0
  unsigned int *v40; // x20
  int i; // w21
  unsigned int v42; // w0
  __int64 v43; // x23
  __int64 v44; // x22
  unsigned int *v45; // x20
  int j; // w21
  int v47; // w24
  __int64 v48; // x23
  __int64 v49; // x22
  __int64 v50; // x0
  __int64 v51; // x25
  __int64 v52; // x1
  int v53; // w0
  __int64 v54; // x23
  __int64 k; // x20
  __int64 v56; // x0
  __int64 v57; // x1
  __int64 v58; // x0
  unsigned int v59; // w20
  __int64 v60; // x0
  unsigned int v61; // w0
  int v62; // w4
  char v63; // w20
  unsigned int v64; // w8
  __int64 v65; // x0
  int v66; // w3
  unsigned int v67; // w5
  int v68; // w20
  __int64 v69; // x21
  int v70; // w0
  __int64 v71; // x21
  int v72; // w0
  __int64 v73; // x21
  int v74; // w0
  __int64 v75; // x21
  int v76; // w0
  __int64 v77; // x20
  int v78; // w0
  unsigned int v79; // w4
  __int64 v80; // x20
  int v81; // w0
  __int64 v82; // x20
  unsigned __int8 v83; // w0
  __int64 v84; // x20
  int v85; // w0
  __int64 v86; // x20
  int v87; // w0
  __int64 v88; // x20
  int v89; // w0
  __int64 v90; // x20
  int v91; // w0
  __int64 v92; // x20
  int v93; // w0
  unsigned int v94; // w8
  int v95; // w20
  int v96; // w21
  __int64 v97; // x23
  int v98; // w0
  __int64 v99; // x23
  int v100; // w24
  int v101; // w0
  __int64 v102; // x23
  int v103; // w0
  __int64 v104; // x23
  int v105; // w24
  int v106; // w0
  unsigned int v107; // w0
  __int64 v108; // x22
  unsigned int v109; // w20
  unsigned int v110; // w21
  int v111; // w0
  unsigned int v112; // w0
  __int64 v113; // x22
  __int64 result; // x0
  int v115; // w21
  __int64 v116; // x9
  __int64 v117; // x20
  int v118; // w20
  int v119; // w20
  int v120; // w22
  unsigned int v121; // w23
  bool v122; // cf
  __int64 v123; // x23
  unsigned int v124; // w20
  __int64 v125; // x22
  unsigned int m; // w23
  __int64 v127; // x24
  __int64 v128; // x20
  int v129; // w0
  int v130; // w20
  __int64 v131; // x21
  int v132; // w0
  __int64 v133; // x20
  int v134; // w21
  int v135; // w0
  __int64 v136; // x20
  int v137; // w0
  unsigned int v138; // w27
  unsigned int v139; // w24
  unsigned int v140; // w8
  __int64 v141; // x0
  int v142; // w3
  const char *v143; // x25
  int v144; // w24
  unsigned int v145; // w0
  int v146; // w4
  int v147; // w5
  int v148; // w3
  int v149; // w2
  unsigned int v150; // w20
  unsigned int v151; // w8
  __int64 v152; // x21
  int v153; // w0
  __int64 v154; // x9
  unsigned int v155; // w3
  __int64 v156; // x22
  int v157; // w20
  unsigned int v158; // w0
  __int64 v159; // x21
  int v160; // w21
  unsigned int v161; // w22
  __int64 v162; // x22
  __int64 v163; // x22
  __int64 v164; // x23
  __int64 v165; // [xsp+8h] [xbp-68h] BYREF
  __int64 v166; // [xsp+10h] [xbp-60h]
  __int64 v167; // [xsp+18h] [xbp-58h]
  __int64 v168; // [xsp+20h] [xbp-50h]
  __int64 v169; // [xsp+28h] [xbp-48h]
  __int64 v170; // [xsp+30h] [xbp-40h]
  __int64 v171; // [xsp+38h] [xbp-38h]
  __int64 v172; // [xsp+40h] [xbp-30h]
  __int64 v173; // [xsp+48h] [xbp-28h]
  __int64 v174; // [xsp+50h] [xbp-20h]
  __int64 v175; // [xsp+58h] [xbp-18h]
  __int64 v176; // [xsp+60h] [xbp-10h]
  __int64 v177; // [xsp+68h] [xbp-8h]

  v177 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 872);
  v3 = *(__int64 **)(a1 + 408);
  v175 = 0;
  v176 = 0;
  v173 = 0;
  v174 = 0;
  v171 = 0;
  v172 = 0;
  v169 = 0;
  v170 = 0;
  v167 = 0;
  v168 = 0;
  v165 = 0;
  v166 = 0;
  writel_relaxed_0(4u, (unsigned int *)(v2 + 4096));
  readl_relaxed_0((unsigned int *)(v2 + 4096));
  if ( *(_BYTE *)(a1 + 1218) == 1 )
  {
    v4 = *(_QWORD *)(a1 + 872);
    v5 = readl_relaxed_0((unsigned int *)(v4 + 32));
    writel_relaxed_0(v5 & 0xFFFFFFDF, (unsigned int *)(v4 + 32));
    readl_relaxed_0((unsigned int *)(v4 + 32));
  }
  v6 = *(_QWORD *)(a1 + 872);
  v7 = readl_relaxed_0((unsigned int *)(v6 + 64));
  writel_relaxed_0(v7 & 0xFFFFFFFE, (unsigned int *)(v6 + 64));
  readl_relaxed_0((unsigned int *)(v6 + 64));
  v8 = *(unsigned int **)(a1 + 872);
  writel_relaxed_0(0x365Eu, v8);
  readl_relaxed_0(v8);
  v9 = *(_QWORD *)(a1 + 872);
  v10 = readl_relaxed_0((unsigned int *)(v9 + 372));
  writel_relaxed_0(v10 | 0x10, (unsigned int *)(v9 + 372));
  readl_relaxed_0((unsigned int *)(v9 + 372));
  v11 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(0, (unsigned int *)(v11 + 556));
  readl_relaxed_0((unsigned int *)(v11 + 556));
  v12 = *(_QWORD *)(a1 + 872);
  v13 = readl_relaxed_0((unsigned int *)(v12 + 556));
  writel_relaxed_0(v13 | 0x7F80D202, (unsigned int *)(v12 + 556));
  readl_relaxed_0((unsigned int *)(v12 + 556));
  if ( a1 )
  {
    v14 = *(_QWORD *)(a1 + 1704);
    v15 = *(_DWORD *)(a1 + 1348);
    v16 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 556LL));
    ipc_log_string(v14, "INFO:%s: PCIe: RC%d: PCIE20_PARF_INT_ALL_MASK: 0x%x\n", "msm_pcie_enable_link", v15, v16);
    v17 = *(_QWORD *)(a1 + 1696);
    v18 = *(_DWORD *)(a1 + 1348);
    v19 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 556LL));
    ipc_log_string(v17, "%s: PCIe: RC%d: PCIE20_PARF_INT_ALL_MASK: 0x%x\n", "msm_pcie_enable_link", v18, v19);
  }
  readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 556LL));
  printk(&unk_28125);
  v20 = *(unsigned int **)(a1 + 408);
  v21 = *(_QWORD *)(a1 + 872);
  v22 = *(unsigned int **)(a1 + 456);
  writel_relaxed_0(*v20, (unsigned int *)(v21 + 848));
  readl_relaxed_0((unsigned int *)(v21 + 848));
  v23 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v20[1], (unsigned int *)(v23 + 852));
  readl_relaxed_0((unsigned int *)(v23 + 852));
  v24 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(*v22, (unsigned int *)(v24 + 1588));
  readl_relaxed_0((unsigned int *)(v24 + 1588));
  v25 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v22[1], (unsigned int *)(v25 + 1592));
  readl_relaxed_0((unsigned int *)(v25 + 1592));
  v26 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(0, (unsigned int *)(v26 + 856));
  readl_relaxed_0((unsigned int *)(v26 + 856));
  v27 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(0x80000000, (unsigned int *)(v27 + 860));
  readl_relaxed_0((unsigned int *)(v27 + 860));
  v28 = *(_DWORD *)(a1 + 1276);
  if ( !v28 )
    v28 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 424LL));
  v29 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v28 | 0x80000000, (unsigned int *)(v29 + 424));
  readl_relaxed_0((unsigned int *)(v29 + 424));
  v30 = *(_QWORD *)(a1 + 872);
  LODWORD(v29) = *(unsigned __int8 *)(a1 + 1343);
  v31 = readl_relaxed_0((unsigned int *)(v30 + 1184));
  writel_relaxed_0(v31 | v29, (unsigned int *)(v30 + 1184));
  readl_relaxed_0((unsigned int *)(v30 + 1184));
  v32 = *(_QWORD *)(a1 + 872);
  v33 = readl_relaxed_0((unsigned int *)(v32 + 1292));
  writel_relaxed_0(v33 & 0xF9FFFFFF, (unsigned int *)(v32 + 1292));
  readl_relaxed_0((unsigned int *)(v32 + 1292));
  if ( a1 )
  {
    v34 = *(_QWORD *)(a1 + 1704);
    v35 = *(_DWORD *)(a1 + 1348);
    v36 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 1292LL));
    ipc_log_string(v34, "INFO:%s: PCIe: RC:%d PARF_INT_ALL_2_TYPE:0x%x\n", "msm_pcie_enable_link", v35, v36);
    v37 = *(_QWORD *)(a1 + 1696);
    v38 = *(_DWORD *)(a1 + 1348);
    v39 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 1292LL));
    ipc_log_string(v37, "%s: PCIe: RC:%d PARF_INT_ALL_2_TYPE:0x%x\n", "msm_pcie_enable_link", v38, v39);
  }
  readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 872) + 1292LL));
  printk(&unk_2BBDF);
  v40 = *(unsigned int **)(a1 + 1640);
  if ( v40 )
  {
    for ( i = *(_DWORD *)(a1 + 1632); i; --i )
    {
      v43 = *v40;
      v42 = v40[1];
      v40 += 2;
      v44 = *(_QWORD *)(a1 + 920);
      writel_relaxed_0(v42, (unsigned int *)(v44 + v43));
      readl_relaxed_0((unsigned int *)(v44 + v43));
    }
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: Initializing PHY\n",
      "pcie_phy_init",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: Initializing PHY\n",
      "pcie_phy_init",
      *(_DWORD *)(a1 + 1348));
  }
  v45 = *(unsigned int **)(a1 + 1624);
  if ( v45 )
  {
    for ( j = *(_DWORD *)(a1 + 1620); j; v45 += 3 )
    {
      v48 = *v45;
      v49 = *(_QWORD *)(a1 + 880);
      writel_relaxed_0(v45[1], (unsigned int *)(v49 + v48));
      readl_relaxed_0((unsigned int *)(v49 + v48));
      v50 = v45[2];
      if ( (_DWORD)v50 )
        usleep_range_state(v50, (unsigned int)(v50 + 1), 2);
      --j;
    }
  }
  usleep_range_state(995, 1005, 2);
  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_pipe_clk_init", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: entry\n", "msm_pcie_pipe_clk_init", *(_DWORD *)(a1 + 1348));
  }
  if ( !*(_DWORD *)(a1 + 840) )
    goto LABEL_39;
  v47 = 0;
  while ( 1 )
  {
    v51 = *(_QWORD *)(a1 + 848) + 24LL * v47;
    if ( *(_QWORD *)v51 )
      break;
LABEL_23:
    if ( (unsigned int)++v47 >= *(_DWORD *)(a1 + 840) )
      goto LABEL_39;
  }
  v52 = *(unsigned int *)(v51 + 16);
  if ( (_DWORD)v52 )
  {
    v53 = clk_set_rate(*(_QWORD *)v51, v52);
    if ( v53 )
    {
      v119 = v53;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "ERR:%s: PCIe: RC%d can't set rate for clk %s: %d.\n",
          "msm_pcie_pipe_clk_init",
          *(_DWORD *)(a1 + 1348),
          *(const char **)(v51 + 8),
          v53);
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: RC%d can't set rate for clk %s: %d.\n",
          "msm_pcie_pipe_clk_init",
          *(_DWORD *)(a1 + 1348),
          *(const char **)(v51 + 8),
          v119);
      }
      printk(&unk_256E2);
      if ( a1 )
        goto LABEL_37;
      goto LABEL_38;
    }
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "DBG2:%s: PCIe: RC%d set rate for clk %s: %d.\n",
        "msm_pcie_pipe_clk_init",
        *(_DWORD *)(a1 + 1348),
        *(const char **)(v51 + 8),
        0);
  }
  v54 = *(_QWORD *)v51;
  if ( (unsigned int)clk_prepare(*(_QWORD *)v51) )
    goto LABEL_34;
  if ( !(unsigned int)clk_enable(v54) )
  {
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "DBG2:%s: RC%d enabled pipe clk %s.\n",
        "msm_pcie_pipe_clk_init",
        *(_DWORD *)(a1 + 1348),
        *(const char **)(v51 + 8));
    goto LABEL_23;
  }
  clk_unprepare(v54);
LABEL_34:
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "ERR:%s: PCIe: RC%d failed to enable clk %s.\n",
      "msm_pcie_pipe_clk_init",
      *(_DWORD *)(a1 + 1348),
      *(const char **)(v51 + 8));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d failed to enable clk %s.\n",
      "msm_pcie_pipe_clk_init",
      *(_DWORD *)(a1 + 1348),
      *(const char **)(v51 + 8));
  }
  printk(&unk_25076);
  if ( a1 )
  {
LABEL_37:
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: RC%d disable pipe clocks for error handling.\n",
      "msm_pcie_pipe_clk_init",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: RC%d disable pipe clocks for error handling.\n",
      "msm_pcie_pipe_clk_init",
      *(_DWORD *)(a1 + 1348));
  }
LABEL_38:
  if ( v47 )
  {
    v115 = v47 - 1;
    do
    {
      v116 = *(_QWORD *)(a1 + 848);
      v117 = *(_QWORD *)(v116 + 24LL * v115);
      if ( v117 )
      {
        clk_disable(*(_QWORD *)(v116 + 24LL * v115));
        clk_unprepare(v117);
      }
      --v115;
    }
    while ( v115 != -1 );
  }
LABEL_39:
  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_pipe_clk_init", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: exit\n", "msm_pcie_pipe_clk_init", *(_DWORD *)(a1 + 1348));
    __dsb(0xEu);
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_pipe_reset", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: entry\n", "msm_pcie_pipe_reset", *(_DWORD *)(a1 + 1348));
    if ( *(_QWORD *)(a1 + 768) )
      goto LABEL_44;
LABEL_41:
    if ( !a1 )
      goto LABEL_56;
    goto LABEL_57;
  }
  __dsb(0xEu);
  if ( !unk_300 )
    goto LABEL_41;
LABEL_44:
  if ( (unsigned int)reset_control_assert() )
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "ERR:%s: PCIe: RC%d failed to assert pipe reset for %s.\n",
        "msm_pcie_pipe_reset",
        *(_DWORD *)(a1 + 1348),
        *(const char **)(a1 + 776));
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d failed to assert pipe reset for %s.\n",
        "msm_pcie_pipe_reset",
        *(_DWORD *)(a1 + 1348),
        *(const char **)(a1 + 776));
    }
    printk(&unk_2A022);
  }
  else if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "DBG2:%s: PCIe: RC%d successfully asserted pipe reset for %s.\n",
      "msm_pcie_pipe_reset",
      *(_DWORD *)(a1 + 1348),
      *(const char **)(a1 + 776));
  }
  usleep_range_state(1000, 1005, 2);
  if ( (unsigned int)reset_control_deassert(*(_QWORD *)(a1 + 768)) )
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "ERR:%s: PCIe: RC%d failed to deassert pipe reset for %s.\n",
        "msm_pcie_pipe_reset",
        *(_DWORD *)(a1 + 1348),
        *(const char **)(a1 + 776));
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d failed to deassert pipe reset for %s.\n",
        "msm_pcie_pipe_reset",
        *(_DWORD *)(a1 + 1348),
        *(const char **)(a1 + 776));
    }
    printk(&unk_2903A);
    if ( !a1 )
      goto LABEL_56;
LABEL_57:
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_pipe_reset", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: exit\n", "msm_pcie_pipe_reset", *(_DWORD *)(a1 + 1348));
    __dsb(0xEu);
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe RC%d: waiting for phy ready...\n",
      "pcie_phy_init",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe RC%d: waiting for phy ready...\n",
      "pcie_phy_init",
      *(_DWORD *)(a1 + 1348));
    goto LABEL_58;
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "DBG2:%s: PCIe: RC%d successfully deasserted pipe reset for %s.\n",
      "msm_pcie_pipe_reset",
      *(_DWORD *)(a1 + 1348),
      *(const char **)(a1 + 776));
    goto LABEL_57;
  }
LABEL_56:
  __dsb(0xEu);
LABEL_58:
  for ( k = 0; k != 10; ++k )
  {
    if ( *(_QWORD *)(a1 + 928) )
      break;
    if ( (((unsigned __int64)(unsigned int)readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 880)
                                                                          + *(unsigned int *)(a1 + 1280))) >> *(_DWORD *)(a1 + 1284))
        & 1) == 0 )
      break;
    usleep_range_state(1000, 1005, 2);
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: number of PHY retries: %ld.\n",
      "pcie_phy_init",
      *(_DWORD *)(a1 + 1348),
      k);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: number of PHY retries: %ld.\n",
      "pcie_phy_init",
      *(_DWORD *)(a1 + 1348),
      k);
  }
  if ( !*(_QWORD *)(a1 + 928)
    && (((unsigned __int64)(unsigned int)readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 880)
                                                                        + *(unsigned int *)(a1 + 1280))) >> *(_DWORD *)(a1 + 1284))
      & 1) != 0 )
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "ERR:%s: PCIe PHY RC%d failed to come up!\n",
        "pcie_phy_init",
        *(_DWORD *)(a1 + 1348));
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe PHY RC%d failed to come up!\n",
        "pcie_phy_init",
        *(_DWORD *)(a1 + 1348));
    }
    printk(&unk_27105);
    pcie_phy_dump(a1);
    result = 4294967277LL;
  }
  else
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "INFO:%s: PCIe RC%d PHY is ready!\n",
        "pcie_phy_init",
        *(_DWORD *)(a1 + 1348));
      ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: PCIe RC%d PHY is ready!\n", "pcie_phy_init", *(_DWORD *)(a1 + 1348));
    }
    printk(&unk_27870);
    v56 = *(_QWORD *)(a1 + 1032);
    if ( v56 )
    {
      v57 = *(_QWORD *)(a1 + 1040);
      if ( v57 )
        clk_set_parent(v56, v57);
    }
    usleep_range_state((unsigned int)(1000 * *(_DWORD *)(a1 + 1268)), (unsigned int)(1000 * *(_DWORD *)(a1 + 1268)), 2);
    v58 = *(unsigned int *)(a1 + 328);
    if ( (_DWORD)v58 )
    {
      v59 = *(_DWORD *)(a1 + 336);
      v60 = gpio_to_desc(v58);
      gpiod_set_raw_value(v60, v59);
    }
    v61 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 124LL));
    v62 = (v61 >> 4) & 0x3F;
    v63 = v61;
    *(_DWORD *)(a1 + 996) = v62;
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "DBG1:%s: PCIe: RC%d: Maximum supported link width is %d\n",
        "msm_pcie_enable_link",
        *(_DWORD *)(a1 + 1348),
        v62);
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: Maximum supported link width is %d\n",
        "msm_pcie_enable_link",
        *(_DWORD *)(a1 + 1348),
        *(_DWORD *)(a1 + 996));
      v65 = *(_QWORD *)(a1 + 1704);
      v66 = *(_DWORD *)(a1 + 1348);
      *(_DWORD *)(a1 + 1000) = v63 & 0xF;
      ipc_log_string(
        v65,
        "DBG1:%s: PCIe: RC%d: Maximum supported link speed is %d\n",
        "msm_pcie_enable_link",
        v66,
        v63 & 0xF);
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: Maximum supported link speed is %d\n",
        "msm_pcie_enable_link",
        *(_DWORD *)(a1 + 1348),
        *(_DWORD *)(a1 + 1000));
      v64 = *(_DWORD *)(a1 + 1256);
      if ( !v64 )
        goto LABEL_83;
    }
    else
    {
      dword_3E8 = v61 & 0xF;
      v64 = dword_4E8;
      if ( !dword_4E8 )
        goto LABEL_83;
    }
    v67 = *(_DWORD *)(a1 + 996);
    if ( v64 > v67 )
      goto LABEL_95;
    v68 = v64 & 0xFFF;
    if ( v68 == 1 )
      goto LABEL_81;
    if ( v68 == 2 )
    {
      v68 = 3;
LABEL_81:
      v69 = *(_QWORD *)(a1 + 904);
      v70 = readl_relaxed_0((unsigned int *)(v69 + 1808));
      writel_relaxed_0(v70 & 0xFFC0FFFF | (v68 << 16), (unsigned int *)(v69 + 1808));
      readl_relaxed_0((unsigned int *)(v69 + 1808));
      v71 = *(_QWORD *)(a1 + 904);
      v72 = readl_relaxed_0((unsigned int *)(v71 + 2060));
      writel_relaxed_0(v72 & 0xFFFFE0FF | (v68 << 8), (unsigned int *)(v71 + 2060));
      readl_relaxed_0((unsigned int *)(v71 + 2060));
      v73 = *(_QWORD *)(a1 + 904);
      v74 = readl_relaxed_0((unsigned int *)(v73 + 2236));
      writel_relaxed_0(v74 | 1, (unsigned int *)(v73 + 2236));
      readl_relaxed_0((unsigned int *)(v73 + 2236));
      v75 = *(_QWORD *)(a1 + 904);
      v76 = readl_relaxed_0((unsigned int *)(v75 + 124));
      writel_relaxed_0(v76 & 0xFFFFFC0F | (16 * v68), (unsigned int *)(v75 + 124));
      readl_relaxed_0((unsigned int *)(v75 + 124));
      v77 = *(_QWORD *)(a1 + 904);
      v78 = readl_relaxed_0((unsigned int *)(v77 + 2236));
      writel_relaxed_0(v78 & 0xFFFFFFFE, (unsigned int *)(v77 + 2236));
      readl_relaxed_0((unsigned int *)(v77 + 2236));
      v79 = ((unsigned int)readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 124LL)) >> 4) & 0x3F;
      *(_DWORD *)(a1 + 996) = v79;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "DBG1:%s: PCIe: RC%d: updated maximum link width supported to: %d\n",
          "msm_pcie_set_link_width",
          *(_DWORD *)(a1 + 1348),
          v79);
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: RC%d: updated maximum link width supported to: %d\n",
          "msm_pcie_set_link_width",
          *(_DWORD *)(a1 + 1348),
          *(_DWORD *)(a1 + 996));
      }
LABEL_83:
      v80 = *(_QWORD *)(a1 + 904);
      v81 = readl_relaxed_0((unsigned int *)(v80 + 2236));
      writel_relaxed_0(v81 | 1, (unsigned int *)(v80 + 2236));
      readl_relaxed_0((unsigned int *)(v80 + 2236));
      v82 = *(_QWORD *)(a1 + 904);
      v83 = readl_relaxed_0((unsigned int *)(v82 + 8));
      writel_relaxed_0(v83 | 0x6040000, (unsigned int *)(v82 + 8));
      readl_relaxed_0((unsigned int *)(v82 + 8));
      v84 = *(_QWORD *)(a1 + 904);
      v85 = readl_relaxed_0((unsigned int *)(v84 + 2236));
      writel_relaxed_0(v85 & 0xFFFFFFFE, (unsigned int *)(v84 + 2236));
      readl_relaxed_0((unsigned int *)(v84 + 2236));
      v86 = *(_QWORD *)(a1 + 872);
      v87 = readl_relaxed_0((unsigned int *)(v86 + 708));
      writel_relaxed_0(v87 & 0xFFFFFFFE, (unsigned int *)(v86 + 708));
      readl_relaxed_0((unsigned int *)(v86 + 708));
      v88 = *(_QWORD *)(a1 + 872);
      v89 = readl_relaxed_0((unsigned int *)(v88 + 708));
      writel_relaxed_0(v89 | 0x100, (unsigned int *)(v88 + 708));
      readl_relaxed_0((unsigned int *)(v88 + 708));
      v90 = *(_QWORD *)(a1 + 904);
      v91 = readl_relaxed_0((unsigned int *)(v90 + 1812));
      writel_relaxed_0(v91 | 0x20, (unsigned int *)(v90 + 1812));
      readl_relaxed_0((unsigned int *)(v90 + 1812));
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "INFO:%s: PCIe: Release the reset of endpoint of RC%d.\n",
          "msm_pcie_enable_link",
          *(_DWORD *)(a1 + 1348));
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: Release the reset of endpoint of RC%d.\n",
          "msm_pcie_enable_link",
          *(_DWORD *)(a1 + 1348));
      }
      printk(&unk_3071A);
      msm_pcie_config_perst(a1, 0);
      usleep_range_state(*(unsigned int *)(a1 + 1312), *(unsigned int *)(a1 + 1316), 2);
      v92 = *(_QWORD *)(a1 + 904);
      v93 = readl_relaxed_0((unsigned int *)(v92 + 2060));
      writel_relaxed_0(v93 & 0xFFFFE0FF | 0x100, (unsigned int *)(v92 + 2060));
      readl_relaxed_0((unsigned int *)(v92 + 2060));
      v94 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 124LL)) & 0xF;
      if ( v94 >= 3 )
      {
        v95 = 0;
        v96 = (v94 << 24) - 0x2000000;
        do
        {
          v97 = *(_QWORD *)(a1 + 904);
          v98 = readl_relaxed_0((unsigned int *)(v97 + 2192));
          writel_relaxed_0(v98 & 0xFCFFFFFF | v95, (unsigned int *)(v97 + 2192));
          readl_relaxed_0((unsigned int *)(v97 + 2192));
          v99 = *(_QWORD *)(a1 + 904);
          v100 = *(_DWORD *)(a1 + 1292);
          v101 = readl_relaxed_0((unsigned int *)(v99 + 2216));
          writel_relaxed_0(v101 & 0xFF0000FF | (v100 << 8), (unsigned int *)(v99 + 2216));
          readl_relaxed_0((unsigned int *)(v99 + 2216));
          v102 = *(_QWORD *)(a1 + 904);
          v103 = readl_relaxed_0((unsigned int *)(v102 + 2192));
          writel_relaxed_0(v103 & 0xFFFFFFFE, (unsigned int *)(v102 + 2192));
          readl_relaxed_0((unsigned int *)(v102 + 2192));
          v104 = *(_QWORD *)(a1 + 904);
          v105 = *(_DWORD *)(a1 + 1300);
          v106 = readl_relaxed_0((unsigned int *)(v104 + 2220));
          writel_relaxed_0(v106 & 0xFFFFFFE0 | v105, (unsigned int *)(v104 + 2220));
          readl_relaxed_0((unsigned int *)(v104 + 2220));
          v95 += 0x1000000;
        }
        while ( v96 != v95 );
      }
      v107 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 124LL));
      v108 = *(_QWORD *)(a1 + 904);
      v109 = v107;
      v110 = v107 & 0xF;
      v111 = readl_relaxed_0((unsigned int *)(v108 + 2236));
      writel_relaxed_0(v111 | 1, (unsigned int *)(v108 + 2236));
      readl_relaxed_0((unsigned int *)(v108 + 2236));
      if ( v110 < 3 )
      {
LABEL_116:
        v128 = *(_QWORD *)(a1 + 904);
        v129 = readl_relaxed_0((unsigned int *)(v128 + 2236));
        writel_relaxed_0(v129 & 0xFFFFFFFE, (unsigned int *)(v128 + 2236));
        readl_relaxed_0((unsigned int *)(v128 + 2236));
      }
      else
      {
        v112 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 256LL));
        if ( v112 )
        {
          if ( (unsigned __int16)v112 == 25 )
          {
            v113 = 268;
LABEL_112:
            v123 = *(_QWORD *)(a1 + 904);
            v124 = (v109 >> 4) & 0x3F;
            writel_relaxed_0(*(_DWORD *)(a1 + 1296), (unsigned int *)(v123 + v113));
            readl_relaxed_0((unsigned int *)(v123 + v113));
            if ( v124 >= 3 )
            {
              v125 = v113 + 4;
              for ( m = 2; m < v124; m += 2 )
              {
                v127 = *(_QWORD *)(a1 + 904);
                writel_relaxed_0(*(_DWORD *)(a1 + 1296), (unsigned int *)(v127 + v125));
                readl_relaxed_0((unsigned int *)(v127 + v125));
                v125 += 4;
              }
            }
            if ( v110 == 3 )
              goto LABEL_116;
            v158 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 256LL));
            if ( v158 )
            {
              if ( (unsigned __int16)v158 == 38 )
              {
                v159 = 288;
LABEL_174:
                v162 = *(_QWORD *)(a1 + 904);
                writel_relaxed_0(*(_DWORD *)(a1 + 1296), (unsigned int *)(v162 + v159));
                readl_relaxed_0((unsigned int *)(v162 + v159));
                if ( v124 >= 5 )
                {
                  v163 = 4;
                  do
                  {
                    v164 = *(_QWORD *)(a1 + 904);
                    writel_relaxed_0(*(_DWORD *)(a1 + 1296), (unsigned int *)(v164 + v159 + v163));
                    readl_relaxed_0((unsigned int *)(v164 + v159 + v163));
                    v163 += 4;
                  }
                  while ( (unsigned int)v163 < v124 );
                }
                goto LABEL_116;
              }
              v160 = -480;
              while ( 1 )
              {
                v161 = (v158 >> 20) & 0xFFC;
                if ( v161 < 0x100 )
                  break;
                v158 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + v161));
                v122 = __CFADD__(v160++, 1);
                if ( v122 )
                  break;
                if ( (unsigned __int16)v158 == 38 )
                {
                  v159 = v161 + 32;
                  goto LABEL_174;
                }
              }
            }
          }
          else
          {
            v120 = -480;
            while ( 1 )
            {
              v121 = (v112 >> 20) & 0xFFC;
              if ( v121 < 0x100 )
                break;
              v112 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + v121));
              v122 = __CFADD__(v120++, 1);
              if ( v122 )
                break;
              if ( (unsigned __int16)v112 == 25 )
              {
                v113 = v121 + 12;
                goto LABEL_112;
              }
            }
          }
        }
      }
      v130 = *(_DWORD *)(a1 + 1244);
      if ( v130 )
      {
        v131 = *(_QWORD *)(a1 + 904);
        v132 = readl_relaxed_0((unsigned int *)(v131 + 160));
        writel_relaxed_0(v132 & 0xFFFFFFF0 | v130, (unsigned int *)(v131 + 160));
        readl_relaxed_0((unsigned int *)(v131 + 160));
      }
      v133 = *(_QWORD *)(a1 + 904);
      v134 = *(_DWORD *)(a1 + 1320);
      v135 = readl_relaxed_0((unsigned int *)(v133 + 120));
      writel_relaxed_0(v135 & 0xFFFF8FFF | (v134 << 12), (unsigned int *)(v133 + 120));
      readl_relaxed_0((unsigned int *)(v133 + 120));
      v136 = *(_QWORD *)(a1 + 872);
      v137 = readl_relaxed_0((unsigned int *)(v136 + 432));
      writel_relaxed_0(v137 | 0x100, (unsigned int *)(v136 + 432));
      readl_relaxed_0((unsigned int *)(v136 + 432));
      if ( a1 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: %s", "msm_pcie_link_train", "check if link is up\n");
        ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: %s", "msm_pcie_link_train", "check if link is up\n");
      }
      v138 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          usleep_range_state(5000, 5101, 2);
          v139 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 888) + 8LL));
          if ( a1 )
          {
            v140 = (v139 >> 12) & 0x3F;
            v141 = *(_QWORD *)(a1 + 1704);
            v142 = *(_DWORD *)(a1 + 1348);
            if ( v140 < 0x24 )
            {
              v143 = msm_pcie_ltssm_str[v140];
              ipc_log_string(v141, "DBG1:%s: PCIe RC%d: LTSSM_STATE: %s\n", "msm_pcie_link_train", v142, v143);
            }
            else
            {
              ipc_log_string(
                v141,
                "DBG1:%s: PCIe RC%d: LTSSM_STATE: %s\n",
                "msm_pcie_link_train",
                v142,
                "LTSSM_INVALID");
              v143 = "LTSSM_INVALID";
            }
            ipc_log_string(
              *(_QWORD *)(a1 + 1696),
              "%s: PCIe RC%d: LTSSM_STATE: %s\n",
              "msm_pcie_link_train",
              *(_DWORD *)(a1 + 1348),
              v143);
          }
          if ( (v139 & 0x400) != 0 )
            break;
          v122 = v138++ >= *(_DWORD *)(a1 + 1240);
          if ( v122 )
            goto LABEL_135;
        }
        if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 128LL)) & 0x20000000) != 0 )
          break;
        v144 = v138 + 1;
        v122 = v138++ >= *(_DWORD *)(a1 + 1240);
        if ( v122 )
          goto LABEL_134;
      }
      v144 = v138;
LABEL_134:
      if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 128LL)) & 0x20000000) == 0 )
      {
LABEL_135:
        if ( a1 )
        {
          ipc_log_string(
            *(_QWORD *)(a1 + 1704),
            "INFO:%s: PCIe: Assert the reset of endpoint of RC%d.\n",
            "msm_pcie_link_train",
            *(_DWORD *)(a1 + 1348));
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "%s: PCIe: Assert the reset of endpoint of RC%d.\n",
            "msm_pcie_link_train",
            *(_DWORD *)(a1 + 1348));
          printk(&unk_23B65);
          msm_pcie_config_perst(a1, 1);
          ipc_log_string(
            *(_QWORD *)(a1 + 1704),
            "ERR:%s: PCIe RC%d link initialization failed\n",
            "msm_pcie_link_train",
            *(_DWORD *)(a1 + 1348));
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "%s: PCIe RC%d link initialization failed\n",
            "msm_pcie_link_train",
            *(_DWORD *)(a1 + 1348));
        }
        else
        {
          printk(&unk_23B65);
          msm_pcie_config_perst(0, 1);
        }
        printk(&unk_2D877);
        result = 0xFFFFFFFFLL;
        goto LABEL_165;
      }
      if ( a1 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: Link is up after %d checkings\n", "msm_pcie_link_train", v144);
        ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: Link is up after %d checkings\n", "msm_pcie_link_train", v144);
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "INFO:%s: PCIe RC%d link initialized\n",
          "msm_pcie_link_train",
          *(_DWORD *)(a1 + 1348));
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe RC%d link initialized\n",
          "msm_pcie_link_train",
          *(_DWORD *)(a1 + 1348));
      }
      printk(&unk_2AEC2);
      v145 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 128LL));
      v146 = HIWORD(v145) & 0xF;
      v147 = (v145 >> 20) & 0x3F;
      *(_DWORD *)(a1 + 1252) = v146;
      *(_DWORD *)(a1 + 1260) = v147;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "DBG1:%s: PCIe: RC%d: Link is up at Gen%dX%d\n",
          "msm_pcie_link_train",
          *(_DWORD *)(a1 + 1348),
          v146,
          v147);
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: RC%d: Link is up at Gen%dX%d\n",
          "msm_pcie_link_train",
          *(_DWORD *)(a1 + 1348),
          *(_DWORD *)(a1 + 1252),
          *(_DWORD *)(a1 + 1260));
      }
      if ( (*(_BYTE *)(a1 + 1357) & 1) == 0 && *(_BYTE *)(a1 + 1993) == 1 )
      {
        v148 = *(_DWORD *)(a1 + 1244);
        if ( v148 )
        {
          v149 = *(_DWORD *)(a1 + 1252);
          if ( v148 != v149 )
            panic("PCIe: RC%d: Gen-speed mismatch:%d, expected:%d\n", *(_DWORD *)(a1 + 1348), v149, v148);
        }
      }
      if ( *(_QWORD *)(a1 + 984) )
      {
        v150 = *(_DWORD *)(a1 + 1252);
        v151 = *(_DWORD *)(a1 + 992);
        if ( v150 < v151 )
        {
          if ( v150 - 1 >= v151 )
          {
            if ( a1 )
            {
              ipc_log_string(
                *(_QWORD *)(a1 + 1704),
                "ERR:%s: PCIe: RC%d: unsupported gen speed: %d\n",
                "msm_pcie_link_train",
                *(_DWORD *)(a1 + 1348),
                v150);
              ipc_log_string(
                *(_QWORD *)(a1 + 1696),
                "%s: PCIe: RC%d: unsupported gen speed: %d\n",
                "msm_pcie_link_train",
                *(_DWORD *)(a1 + 1348),
                *(_DWORD *)(a1 + 1252));
            }
            printk(&unk_27151);
          }
          else
          {
            v152 = *(_QWORD *)(a1 + 904);
            v153 = readl_relaxed_0((unsigned int *)(v152 + 160));
            writel_relaxed_0(v153 & 0xFFFFFFF0 | v150, (unsigned int *)(v152 + 160));
            readl_relaxed_0((unsigned int *)(v152 + 160));
            msm_pcie_scale_link_bandwidth(a1, *(_DWORD *)(a1 + 1252));
          }
        }
      }
      v154 = *(_QWORD *)(a1 + 1544);
      v155 = *(_DWORD *)(a1 + 1272);
      *(_DWORD *)(a1 + 1176) = 1;
      *(_BYTE *)(a1 + 1692) = 1;
      *(_BYTE *)(a1 + 1568) = 0;
      *(_QWORD *)(a1 + 1544) = v154 + 1;
      if ( v155 )
      {
        if ( a1 )
        {
          ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: switch_latency: %dms\n", "msm_pcie_enable_link", v155);
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "%s: switch_latency: %dms\n",
            "msm_pcie_enable_link",
            *(_DWORD *)(a1 + 1272));
          v155 = *(_DWORD *)(a1 + 1272);
        }
        if ( v155 > 0x14 )
          msleep(v155);
        else
          usleep_range_state(1000 * v155, 1000 * v155, 2);
      }
      msm_pcie_config_sid(a1);
      msm_pcie_config_controller(a1);
      v156 = *v3;
      if ( (unsigned int)of_pci_parse_bus_range(*(_QWORD *)(*(_QWORD *)a1 + 760LL), &v165) )
        v157 = 256;
      else
        v157 = v166 - v165 + 1;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "DBG1:%s: RC%d: configure ECAM for bus range:%d\n",
          "msm_pcie_enable_link",
          *(_DWORD *)(a1 + 1348),
          v157);
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: RC%d: configure ECAM for bus range:%d\n",
          "msm_pcie_enable_link",
          *(_DWORD *)(a1 + 1348),
          v157);
      }
      msm_pcie_iatu_config_shift(a1, 0, 4, v156 + 0x100000, (unsigned int)(v156 + 0x1FFFFF));
      if ( v157 >= 3 )
        msm_pcie_iatu_config_shift(a1, 1, 5, v156 + 0x200000, (unsigned int)(v156 + (v157 << 20) - 1));
      msm_pcie_iatu_setup_ecam_blocker(a1);
      result = 0;
    }
    else
    {
LABEL_95:
      if ( a1 )
      {
        v118 = v64 & 0xFFF;
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "ERR:%s: PCIe: RC%d: unsupported link width request: %d, Max: %d\n",
          "msm_pcie_set_link_width",
          *(_DWORD *)(a1 + 1348),
          v118,
          v67);
        ipc_log_string(
          *(_QWORD *)(a1 + 1696),
          "%s: PCIe: RC%d: unsupported link width request: %d, Max: %d\n",
          "msm_pcie_set_link_width",
          *(_DWORD *)(a1 + 1348),
          v118,
          *(_DWORD *)(a1 + 996));
      }
      printk(&unk_25E86);
      result = 4294967274LL;
    }
  }
LABEL_165:
  _ReadStatusReg(SP_EL0);
  return result;
}
