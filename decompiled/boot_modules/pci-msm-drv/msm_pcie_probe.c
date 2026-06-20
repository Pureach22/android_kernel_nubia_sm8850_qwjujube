__int64 __fastcall msm_pcie_probe(unsigned __int64 a1)
{
  const char *v1; // x22
  unsigned __int64 v2; // x28
  __int64 v4; // x27
  unsigned int v5; // w0
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x20
  _QWORD *v9; // x8
  __int64 v10; // x19
  __int64 v11; // x24
  __int64 property; // x0
  const char *v13; // x3
  const char *v14; // x3
  __int64 v15; // x0
  const char *v16; // x3
  const char *v17; // x3
  __int64 v18; // x0
  const char *v19; // x3
  const char *v20; // x3
  __int64 v21; // x0
  const char *v22; // x3
  const char *v23; // x3
  char v24; // w8
  __int64 v25; // x0
  const char *v26; // x3
  const char *v27; // x3
  __int64 v28; // x0
  const char *v29; // x3
  const char *v30; // x3
  __int64 v31; // x0
  const char *v32; // x3
  void *v33; // x3
  _DWORD *v34; // x20
  int variable_u32_array; // w8
  __int64 v36; // x0
  int v37; // w3
  __int64 v38; // x0
  const char *v39; // x3
  const char *v40; // x3
  int v41; // w8
  __int64 v42; // x0
  int v43; // w3
  __int64 v44; // x8
  __int64 v45; // x0
  int v46; // w3
  __int64 v47; // x0
  const char *v48; // x0
  __int64 v49; // x0
  int v50; // w9
  __int64 v51; // x20
  unsigned int v52; // w13
  const char *v53; // x4
  const char *v54; // x4
  unsigned int v55; // w8
  _QWORD *v56; // x9
  _QWORD *v57; // x10
  _QWORD *v58; // x8
  __int64 v59; // x8
  __int64 v60; // x22
  __int64 i; // x28
  __int64 v62; // x23
  const void *resource_byname; // x0
  const void *v64; // x27
  __int64 v65; // x0
  __int64 v66; // x23
  __int64 v67; // x9
  __int64 v68; // x8
  __int64 v69; // x9
  __int64 v70; // x8
  __int64 v71; // x9
  __int64 v72; // x8
  __int64 v73; // x9
  __int64 v74; // x8
  unsigned __int64 v75; // x0
  __int64 j; // x27
  int irq_byname; // w26
  __int64 v78; // x0
  __int64 v79; // x0
  unsigned __int64 v80; // x3
  __int64 v81; // x21
  unsigned int all; // w24
  int v83; // w0
  __int64 v84; // x0
  int v85; // w0
  int v86; // w0
  __int64 v87; // x0
  int v88; // w0
  unsigned __int64 v89; // x20
  __int64 v90; // x0
  unsigned __int64 v91; // x10
  __int64 v92; // x11
  __int64 v93; // x26
  __int64 v94; // x8
  __int64 v95; // x12
  unsigned __int64 v96; // x27
  unsigned int v97; // w21
  const char *v98; // x4
  int v99; // w5
  int v100; // w9
  __int64 v101; // x20
  __int64 v102; // x21
  unsigned int v103; // w22
  int v104; // w8
  unsigned __int64 v105; // x0
  unsigned __int64 v106; // x0
  unsigned __int64 v107; // x0
  unsigned __int64 v108; // x0
  unsigned __int64 v109; // x8
  unsigned __int64 v110; // x0
  unsigned __int64 v111; // x8
  unsigned __int64 v112; // x0
  __int64 v113; // x27
  __int64 v114; // x26
  __int64 v115; // x24
  unsigned __int64 optional; // x0
  _QWORD *v117; // x22
  unsigned int *v118; // x0
  _DWORD *v119; // x9
  const char *v120; // x21
  const char *v121; // x21
  __int64 v122; // x22
  const char *v123; // x21
  __int64 v124; // x9
  __int64 v125; // x8
  unsigned int v126; // w20
  int v127; // w20
  int v128; // w23
  __int64 v129; // x23
  __int64 v130; // x24
  unsigned __int64 *v131; // x23
  const char *v132; // x20
  _QWORD *v133; // x22
  __int64 v134; // x8
  unsigned __int64 v135; // x0
  unsigned __int64 *v136; // x9
  unsigned __int64 v137; // x4
  unsigned __int64 v138; // x0
  __int64 v139; // x20
  __int64 v140; // x0
  __int64 v141; // x20
  __int64 v142; // x0
  unsigned __int64 v143; // x3
  unsigned __int64 v144; // x20
  __int64 v145; // x21
  __int64 v146; // x1
  __int64 v147; // x0
  unsigned int v148; // w8
  unsigned __int64 v149; // x11
  unsigned __int64 v150; // x9
  unsigned __int64 v151; // x11
  bool v152; // cf
  unsigned __int64 v153; // x11
  const char *v154; // x8
  int named_gpio; // w0
  int v156; // w8
  int v157; // w8
  int v158; // w8
  __int64 v159; // x0
  __int64 v160; // x0
  const char *v161; // x21
  __int64 v162; // x2
  unsigned __int64 v163; // x3
  const char *v164; // x21
  __int64 v165; // x2
  unsigned __int64 v166; // x3
  const char *v167; // x21
  __int64 v168; // x2
  unsigned __int64 v169; // x3
  int v170; // w20
  void *v171; // x0
  int v172; // w20
  int v173; // w20
  int v174; // w20
  const char **v175; // x8
  int v176; // w21
  unsigned __int64 StatusReg; // x23
  __int64 v178; // x24
  int v179; // w0
  const char *v180; // x20
  __int64 v181; // x0
  __int64 v182; // x1
  __int64 v183; // x21
  int v184; // w22
  __int64 v185; // x0
  __int64 v186; // x1
  __int64 v187; // x0
  __int64 v188; // x1
  __int64 v189; // x0
  _QWORD *v190; // x19
  __int64 v191; // x0
  __int64 v192; // x9
  int v193; // w8
  int v194; // w9
  int v195; // w10
  __int64 v196; // x23
  __int64 v197; // x22
  __int64 v198; // x22
  __int64 v199; // x20
  __int64 v200; // x24
  __int64 v201; // x25
  __int64 v202; // x26
  int v203; // w24
  __int64 v204; // x25
  __int64 v205; // x26
  __int64 v206; // x27
  __int64 v207; // x20
  __int64 v208; // x21
  int v209; // w0
  unsigned __int64 device; // x0
  int v211; // w8
  int v212; // w0
  unsigned __int64 v213; // x0
  unsigned __int64 v214; // x0
  unsigned __int64 v215; // x0
  unsigned __int64 v216; // x8
  _QWORD *v217; // x23
  __int64 v218; // x24
  unsigned __int64 k; // x21
  unsigned int v220; // w20
  __int64 v221; // x0
  int v222; // w20
  __int64 v223; // x20
  __int64 v224; // x0
  int v225; // w0
  __int64 v226; // x0
  __int64 v227; // x0
  const char *v228; // x21
  __int64 v229; // x1
  __int64 v230; // x0
  __int64 v231; // x1
  int v232; // w0
  __int64 v233; // x1
  int v234; // w0
  __int64 v235; // x0
  int v236; // w0
  __int64 v237; // x0
  char v238; // w8
  int v240; // w21
  int v241; // w22
  const char *v242; // x20
  int v243; // w0
  void *v244; // x20
  void *v245; // x0
  __int64 v246; // x0
  bool v247; // zf
  const char *v248; // x21
  __int64 v249; // x0
  __int64 v250; // x3
  const char *v251; // x3
  const char *v252; // x3
  __int64 v253; // x0
  int v254; // w20
  __int64 v255; // [xsp+10h] [xbp-80h]
  const char **v256; // [xsp+18h] [xbp-78h]
  __int64 v257; // [xsp+20h] [xbp-70h]
  __int64 v258; // [xsp+38h] [xbp-58h]
  unsigned __int64 v259; // [xsp+40h] [xbp-50h]
  __int64 v260; // [xsp+48h] [xbp-48h]
  __int64 v261; // [xsp+50h] [xbp-40h]
  unsigned int v262; // [xsp+60h] [xbp-30h] BYREF
  int v263; // [xsp+64h] [xbp-2Ch] BYREF
  __int128 v264; // [xsp+68h] [xbp-28h] BYREF
  __int64 v265; // [xsp+78h] [xbp-18h]
  __int64 v266; // [xsp+80h] [xbp-10h]
  __int64 v267; // [xsp+88h] [xbp-8h]

  v267 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v262 = -1;
  dev_info(a1 + 16, "PCIe: %s\n", "msm_pcie_probe");
  mutex_lock(&unk_30CD8);
  v4 = *(_QWORD *)(a1 + 760);
  v5 = of_property_read_variable_u32_array(v4, "cell-index", &v262, 1, 0);
  if ( (v5 & 0x80000000) != 0 )
  {
    v126 = v5;
    dev_err(a1 + 16, "PCIe: %s: Did not find RC index\n", "msm_pcie_probe");
    goto LABEL_414;
  }
  if ( (int)v262 > 4 )
  {
    v126 = 0;
    goto LABEL_415;
  }
  v6 = devm_pci_alloc_host_bridge(a1 + 16, 3160);
  v7 = v262;
  if ( !v6 )
  {
    v126 = -12;
    printk(&unk_2FEF3);
    goto LABEL_414;
  }
  if ( v262 >= 5 )
    goto LABEL_501;
  v8 = v6;
  msm_pcie_dev[v262] = v6 + 1088;
  *(_QWORD *)((char *)&v264 + 7) = 0;
  *(_QWORD *)&v264 = 0;
  scnprintf(&v264, 15, "pcie%d-short", v7);
  *(_QWORD *)(msm_pcie_dev[v7] + 1696) = ipc_log_context_create(50, &v264, 0);
  scnprintf(&v264, 15, "pcie%d-long", v7);
  *(_QWORD *)(msm_pcie_dev[v7] + 1704) = ipc_log_context_create(50, &v264, 0);
  scnprintf(&v264, 15, "pcie%d-dump", v7);
  *(_QWORD *)(msm_pcie_dev[v7] + 1712) = ipc_log_context_create(50, &v264, 0);
  v9 = (_QWORD *)msm_pcie_dev[v7];
  if ( !v9[212] || !v9[213] || !v9[214] )
    printk(&unk_2BD22);
  ++pcie_drv[0];
  if ( v262 > 4 )
    goto LABEL_501;
  v10 = msm_pcie_dev[v262];
  *(_DWORD *)(v10 + 1348) = v262;
  *(_QWORD *)v10 = a1;
  *(_DWORD *)(v10 + 1176) = 0;
  *(_QWORD *)(v10 + 16) = v8;
  *(_DWORD *)(v10 + 1060) = 0;
  *(_DWORD *)(v10 + 1688) = 0;
  *(_BYTE *)(v10 + 1056) = 1;
  _mutex_init(v10 + 1072, "&pcie_dev->enumerate_lock", &msm_pcie_lock_init___key);
  _mutex_init(v10 + 1120, "&pcie_dev->setup_lock", &msm_pcie_lock_init___key_901);
  _mutex_init(v10 + 1424, "&pcie_dev->recovery_lock", &msm_pcie_lock_init___key_903);
  _mutex_init(v10 + 1480, "&pcie_dev->aspm_lock", &msm_pcie_lock_init___key_905);
  _mutex_init(v10 + 1904, "&pcie_dev->drv_pc_lock", &msm_pcie_lock_init___key_907);
  *(_DWORD *)(v10 + 1472) = 0;
  *(_BYTE *)(v10 + 1356) = 0;
  *(_QWORD *)(v10 + 1560) = 100000;
  *(_QWORD *)(v10 + 1832) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 1840) = v10 + 1840;
  *(_QWORD *)(v10 + 1848) = v10 + 1840;
  *(_QWORD *)(v10 + 1856) = msm_pcie_drv_disable_pc;
  *(_QWORD *)(v10 + 1800) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 1808) = v10 + 1808;
  *(_QWORD *)(v10 + 1816) = v10 + 1808;
  *(_QWORD *)(v10 + 1864) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 1824) = msm_pcie_drv_enable_pc;
  *(_QWORD *)(v10 + 1872) = v10 + 1872;
  *(_QWORD *)(v10 + 1880) = v10 + 1872;
  *(_QWORD *)(v10 + 1888) = msm_pcie_drv_connect_worker;
  *(_QWORD *)(v10 + 1584) = v10 + 1584;
  *(_QWORD *)(v10 + 1592) = v10 + 1584;
  *(_QWORD *)(v10 + 1600) = v10 + 1600;
  *(_QWORD *)(v10 + 1608) = v10 + 1600;
  *(_QWORD *)(v10 + 1672) = v10 + 1672;
  *(_QWORD *)(v10 + 1680) = v10 + 1672;
  if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC index is %d.\n",
      "msm_pcie_probe",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: PCIe: RC index is %d.\n", "msm_pcie_probe", *(_DWORD *)(v10 + 1348));
  }
  v11 = v262;
  property = of_find_property(v4, "qcom,no-l0s-supported", 0);
  *(_BYTE *)(v10 + 1217) = property == 0;
  if ( v10 )
  {
    if ( property )
      v13 = "not";
    else
      v13 = (const char *)&unk_24FCB;
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: L0s is %s supported.\n", "msm_pcie_read_dt", v13);
    if ( *(_BYTE *)(v10 + 1217) )
      v14 = (const char *)&unk_24FCB;
    else
      v14 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: L0s is %s supported.\n", "msm_pcie_read_dt", v14);
  }
  v15 = of_find_property(v4, "qcom,no-l1-supported", 0);
  *(_BYTE *)(v10 + 1218) = v15 == 0;
  if ( v10 )
  {
    if ( v15 )
      v16 = "not";
    else
      v16 = (const char *)&unk_24FCB;
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: L1 is %s supported.\n", "msm_pcie_read_dt", v16);
    if ( *(_BYTE *)(v10 + 1218) )
      v17 = (const char *)&unk_24FCB;
    else
      v17 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: L1 is %s supported.\n", "msm_pcie_read_dt", v17);
  }
  v18 = of_find_property(v4, "qcom,no-l1ss-supported", 0);
  *(_BYTE *)(v10 + 1219) = v18 == 0;
  if ( v10 )
  {
    if ( v18 )
      v19 = "not";
    else
      v19 = (const char *)&unk_24FCB;
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: L1ss is %s supported.\n", "msm_pcie_read_dt", v19);
    if ( *(_BYTE *)(v10 + 1219) )
      v20 = (const char *)&unk_24FCB;
    else
      v20 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: L1ss is %s supported.\n", "msm_pcie_read_dt", v20);
  }
  v21 = of_find_property(v4, "qcom,bdf-change-halt-en", 0);
  *(_BYTE *)(v10 + 1343) = v21 != 0;
  if ( v10 )
  {
    if ( v21 )
      v22 = (const char *)&unk_24FCB;
    else
      v22 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: bdf_change_halt_en is %s supported.\n", "msm_pcie_read_dt", v22);
    if ( *(_BYTE *)(v10 + 1343) )
      v23 = (const char *)&unk_24FCB;
    else
      v23 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: bdf_change_halt_en is %s supported.\n", "msm_pcie_read_dt", v23);
  }
  v24 = *(_BYTE *)(v10 + 1219);
  *(_BYTE *)(v10 + 1222) = v24;
  *(_BYTE *)(v10 + 1223) = v24;
  *(_BYTE *)(v10 + 1220) = v24;
  *(_BYTE *)(v10 + 1221) = v24;
  of_property_read_variable_u32_array(v4, "qcom,l1-2-th-scale", v10 + 1224, 1, 0);
  of_property_read_variable_u32_array(v4, "qcom,l1-2-th-value", v10 + 1228, 1, 0);
  if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: L1.2 threshold scale: %d value: %d.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1224),
      *(_DWORD *)(v10 + 1228));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: L1.2 threshold scale: %d value: %d.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1224),
      *(_DWORD *)(v10 + 1228));
  }
  v25 = of_find_property(v4, "qcom,common-clk-en", 0);
  *(_BYTE *)(v10 + 1232) = v25 != 0;
  if ( v10 )
  {
    if ( v25 )
      v26 = (const char *)&unk_24FCB;
    else
      v26 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: Common clock is %s enabled.\n", "msm_pcie_read_dt", v26);
    if ( *(_BYTE *)(v10 + 1232) )
      v27 = (const char *)&unk_24FCB;
    else
      v27 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: Common clock is %s enabled.\n", "msm_pcie_read_dt", v27);
  }
  v28 = of_find_property(v4, "qcom,clk-power-manage-en", 0);
  *(_BYTE *)(v10 + 1233) = v28 != 0;
  if ( v10 )
  {
    if ( v28 )
      v29 = (const char *)&unk_24FCB;
    else
      v29 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: Clock power management is %s enabled.\n", "msm_pcie_read_dt", v29);
    if ( *(_BYTE *)(v10 + 1233) )
      v30 = (const char *)&unk_24FCB;
    else
      v30 = "not";
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: Clock power management is %s enabled.\n", "msm_pcie_read_dt", v30);
  }
  v31 = of_find_property(v4, "qcom,no-aux-clk-sync", 0);
  *(_BYTE *)(v10 + 1234) = v31 == 0;
  if ( v10 )
  {
    v1 = "msm_pcie_read_dt";
    v32 = v31 ? "not" : (const char *)&unk_24FCB;
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: AUX clock is %s synchronous to Core clock.\n",
      "msm_pcie_read_dt",
      v32);
    v33 = *(_BYTE *)(v10 + 1234) ? &unk_24FCB : "not";
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: AUX clock is %s synchronous to Core clock.\n", "msm_pcie_read_dt", v33);
    of_property_read_variable_u32_array(v4, "qcom,smmu-sid-base", v10 + 1236, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: qcom,smmu-sid-base: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1236));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: qcom,smmu-sid-base: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1236));
    of_property_read_variable_u32_array(v4, "qcom,boot-option", v10 + 1332, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d boot option is 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1332));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d boot option is 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1332));
    of_property_read_variable_u32_array(v4, "qcom,pcie-phy-ver", v10 + 1352, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: pcie-phy-ver: %d.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1352));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: pcie-phy-ver: %d.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1352));
    *(_DWORD *)(v10 + 1240) = 20;
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,link-check-max-count", v10 + 1240, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: link-check-max-count: %u.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1240));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: link-check-max-count: %u.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1240));
    v34 = (_DWORD *)(v10 + 1248);
    of_property_read_variable_u32_array(v4, "qcom,target-link-speed", v10 + 1248, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: target-link-speed: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1248));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: target-link-speed: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1248));
  }
  else
  {
    of_property_read_variable_u32_array(v4, "qcom,smmu-sid-base", 1236, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,boot-option", 1332, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,pcie-phy-ver", 1352, 1, 0);
    LODWORD(off_4D8) = 20;
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,link-check-max-count", 1240, 1, 0);
    v34 = (_DWORD *)&off_4E0;
    of_property_read_variable_u32_array(v4, "qcom,target-link-speed", 1248, 1, 0);
  }
  *(_DWORD *)(v10 + 1244) = *v34;
  if ( (unsigned int)v11 >= 5 )
    goto LABEL_501;
  *(_DWORD *)(msm_pcie_dev[v11] + 1256) = 0;
  of_property_read_variable_u32_array(v4, "qcom,target-link-width", v10 + 1256, 1, 0);
  if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: target-link-width: %d.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1256));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: target-link-width: %d.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1256));
    of_property_read_variable_u32_array(v4, "qcom,n-fts", v10 + 1264, 1, 0);
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: n-fts: 0x%x.\n", "msm_pcie_read_dt", *(_DWORD *)(v10 + 1264));
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: n-fts: 0x%x.\n", "msm_pcie_read_dt", *(_DWORD *)(v10 + 1264));
    of_property_read_variable_u32_array(v4, "qcom,ep-latency", v10 + 1268, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: ep-latency: %ums.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1268));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: ep-latency: %ums.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1268));
    of_property_read_variable_u32_array(v4, "qcom,switch-latency", v10 + 1272, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: switch-latency: %ums.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1272));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: switch-latency: %ums.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1272));
    variable_u32_array = of_property_read_variable_u32_array(v4, "qcom,wr-halt-size", v10 + 1276, 1, 0);
    v36 = *(_QWORD *)(v10 + 1704);
    v37 = *(_DWORD *)(v10 + 1348);
    if ( variable_u32_array < 0 )
    {
      ipc_log_string(
        v36,
        "DBG1:%s: RC%d: wr-halt-size not specified in dt. Use default value.\n",
        "msm_pcie_read_dt",
        v37);
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: RC%d: wr-halt-size not specified in dt. Use default value.\n",
        "msm_pcie_read_dt",
        *(_DWORD *)(v10 + 1348));
    }
    else
    {
      ipc_log_string(v36, "DBG1:%s: RC%d: wr-halt-size: 0x%x.\n", "msm_pcie_read_dt", v37, *(_DWORD *)(v10 + 1276));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: RC%d: wr-halt-size: 0x%x.\n",
        "msm_pcie_read_dt",
        *(_DWORD *)(v10 + 1348),
        *(_DWORD *)(v10 + 1276));
    }
  }
  else
  {
    of_property_read_variable_u32_array(v4, "qcom,n-fts", 1264, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,ep-latency", 1268, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,switch-latency", 1272, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,wr-halt-size", 1276, 1, 0);
  }
  v38 = of_find_property(v4, "qcom,gdsc-clk-drv-ss-nonvotable", 0);
  *(_BYTE *)(v10 + 1342) = v38 != 0;
  if ( v10 )
  {
    v1 = "msm_pcie_read_dt";
    if ( v38 )
      v39 = "not";
    else
      v39 = (const char *)&unk_24FCB;
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: Gdsc clk is %s votable during drv hand over.\n",
      "msm_pcie_read_dt",
      v39);
    if ( *(_BYTE *)(v10 + 1342) )
      v40 = "not";
    else
      v40 = (const char *)&unk_24FCB;
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: Gdsc clk is %s votable during drv hand over.\n",
      "msm_pcie_read_dt",
      v40);
    of_property_read_variable_u32_array(v4, "qcom,num-parf-testbus-sel", v10 + 1616, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: num-parf-testbus-sel: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1616));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: num-parf-testbus-sel: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1616));
    of_property_read_variable_u32_array(v4, "qcom,phy-status-offset", v10 + 1280, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: phy-status-offset: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1280));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: phy-status-offset: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1280));
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,phy-status-bit", v10 + 1284, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: phy-status-bit: %u.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1284));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: phy-status-bit: %u.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1284));
    of_property_read_variable_u32_array(v4, "qcom,phy-power-down-offset", v10 + 1288, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: phy-power-down-offset: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1288));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: phy-power-down-offset: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1288));
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,eq-pset-req-vec", v10 + 1292, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: eq-pset-req-vec: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1292));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: eq-pset-req-vec: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1292));
    *(_DWORD *)(v10 + 1296) = 1431655765;
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,core-preset", v10 + 1296, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: core-preset: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1296));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: core-preset: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1296));
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,eq-fmdc-t-min-phase23", v10 + 1300, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: qcom,eq-fmdc-t-min-phase23: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1300));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: qcom,eq-fmdc-t-min-phase23: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1300));
    of_property_read_variable_u32_array(v4, "qcom,cpl-timeout", v10 + 1304, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: cpl-timeout: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1304));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: cpl-timeout: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1304));
  }
  else
  {
    of_property_read_variable_u32_array(v4, "qcom,num-parf-testbus-sel", 1616, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,phy-status-offset", 1280, 1, 0);
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,phy-status-bit", 1284, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,phy-power-down-offset", 1288, 1, 0);
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,eq-pset-req-vec", 1292, 1, 0);
    dword_510 = 1431655765;
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,core-preset", 1296, 1, 0);
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,eq-fmdc-t-min-phase23", 1300, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,cpl-timeout", 1304, 1, 0);
  }
  *(_QWORD *)(v10 + 1312) = 0x3ED000003E8LL;
  of_property_read_variable_u32_array(v4, "qcom,perst-delay-us-min", v10 + 1312, 1, 0);
  of_property_read_variable_u32_array(v4, "qcom,perst-delay-us-max", v10 + 1316, 1, 0);
  if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: perst-delay-us-min: %dus. perst-delay-us-max: %dus.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1312),
      *(_DWORD *)(v10 + 1316));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: perst-delay-us-min: %dus. perst-delay-us-max: %dus.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1312),
      *(_DWORD *)(v10 + 1316));
    *(_DWORD *)(v10 + 1320) = 5;
    of_property_read_variable_u32_array(v4, "qcom,tlp-rd-size", v10 + 1320, 1, 0);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: tlp-rd-size: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1320));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: tlp-rd-size: 0x%x.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 1320));
    v41 = of_property_read_variable_u32_array(v4, "qcom,aux-clk-freq", v10 + 1324, 1, 0);
    v42 = *(_QWORD *)(v10 + 1704);
    v43 = *(_DWORD *)(v10 + 1348);
    if ( v41 < 0 )
    {
      ipc_log_string(v42, "DBG1:%s: RC%d: using default aux clock frequency.\n", "msm_pcie_read_dt", v43);
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: RC%d: using default aux clock frequency.\n",
        "msm_pcie_read_dt",
        *(_DWORD *)(v10 + 1348));
    }
    else
    {
      ipc_log_string(v42, "DBG1:%s: RC%d: aux clock frequency: %d.\n", "msm_pcie_read_dt", v43, *(_DWORD *)(v10 + 1324));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: RC%d: aux clock frequency: %d.\n",
        "msm_pcie_read_dt",
        *(_DWORD *)(v10 + 1348),
        *(_DWORD *)(v10 + 1324));
    }
    *(_BYTE *)(v10 + 1235) = 1;
    v44 = of_find_property(v4, "msi-map", 0);
    v45 = *(_QWORD *)(v10 + 1704);
    v46 = *(_DWORD *)(v10 + 1348);
    if ( v44 )
    {
      ipc_log_string(v45, "DBG1:%s: RC%d: LPI supported.\n", "msm_pcie_read_dt", v46);
      ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: RC%d: LPI supported.\n", "msm_pcie_read_dt", *(_DWORD *)(v10 + 1348));
      goto LABEL_93;
    }
    ipc_log_string(v45, "DBG1:%s: RC%d: LPI not supported.\n", "msm_pcie_read_dt", v46);
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: LPI not supported.\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348));
  }
  else
  {
    dword_528 = 5;
    of_property_read_variable_u32_array(v4, "qcom,tlp-rd-size", 1320, 1, 0);
    of_property_read_variable_u32_array(v4, "qcom,aux-clk-freq", 1324, 1, 0);
    BYTE3(msm_pci_driver) = 1;
    if ( of_find_property(v4, "msi-map", 0) )
LABEL_93:
      *(_BYTE *)(v10 + 1340) = 1;
  }
  if ( (of_property_read_variable_u32_array(v4, "qcom,pcie-clkreq-offset", v10 + 1344, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v10 + 1344) = 0;
  v47 = of_find_property(v4, "qcom,config-recovery", 0);
  *(_BYTE *)(v10 + 1752) = v47 != 0;
  if ( v47 )
  {
    if ( v10 )
      ipc_log_string(
        *(_QWORD *)(v10 + 1712),
        "DUMP:%s: RC%d config space recovery enabled\n",
        "msm_pcie_read_dt",
        *(_DWORD *)(v10 + 1348));
    *(_QWORD *)(v10 + 1760) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v10 + 1768) = v10 + 1768;
    *(_QWORD *)(v10 + 1776) = v10 + 1768;
    *(_QWORD *)(v10 + 1784) = handle_link_recover;
  }
  of_property_read_variable_u32_array(v4, "qcom,l1ss-sleep-disable", v10 + 3148, 1, 0);
  if ( (of_property_read_variable_u32_array(v4, "qcom,drv-l1ss-timeout-us", v10 + 3144, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v10 + 3144) = 100000;
  if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: DRV L1ss timeout: %dus\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 3144));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: DRV L1ss timeout: %dus\n",
      "msm_pcie_read_dt",
      *(_DWORD *)(v10 + 1348),
      *(_DWORD *)(v10 + 3144));
  }
  if ( !(unsigned int)of_property_read_string(v4, "qcom,drv-name", v10 + 1984) )
  {
    v48 = *(const char **)(v10 + 1984);
    *(_BYTE *)(v10 + 1992) = 1;
    if ( strcmp(v48, "cesta") )
    {
      v49 = devm_kmalloc(*(_QWORD *)v10 + 16LL, 288, 3520);
      if ( v49 )
      {
        v50 = *(_DWORD *)(v10 + 1348);
        *(_DWORD *)(v49 + 25) = -1073741824;
        *(_DWORD *)(v49 + 65) = -1073741823;
        *(_DWORD *)(v49 + 1) = 1;
        *(_WORD *)(v49 + 5) = 12;
        v51 = v49;
        *(_DWORD *)(v49 + 244) = v50;
        *(_WORD *)(v49 + 11) = 16;
        *(_DWORD *)(v49 + 13) = v50;
        *(_DWORD *)(v49 + 29) = v50;
        *(_DWORD *)(v49 + 41) = 1;
        *(_WORD *)(v49 + 45) = 12;
        *(_WORD *)(v49 + 51) = 16;
        *(_DWORD *)(v49 + 53) = v50;
        *(_DWORD *)(v49 + 69) = v50;
        *(_DWORD *)(v49 + 81) = 1;
        *(_WORD *)(v49 + 85) = 12;
        *(_WORD *)(v49 + 91) = 16;
        *(_DWORD *)(v49 + 93) = v50;
        *(_DWORD *)(v49 + 105) = -1073741819;
        *(_DWORD *)(v49 + 109) = v50;
        v52 = *(_DWORD *)(v10 + 3144);
        *(_DWORD *)(v49 + 121) = 1;
        *(_DWORD *)(v49 + 161) = 1;
        *(_DWORD *)(v49 + 201) = 1;
        *(_WORD *)(v49 + 125) = 12;
        *(_WORD *)(v49 + 131) = 16;
        *(_DWORD *)(v49 + 133) = v50;
        *(_DWORD *)(v49 + 149) = v50;
        *(_DWORD *)(v49 + 113) = v52 / 0x3E8;
        *(_DWORD *)(v49 + 145) = -1073741818;
        *(_WORD *)(v49 + 165) = 12;
        *(_WORD *)(v49 + 171) = 16;
        *(_DWORD *)(v49 + 173) = v50;
        *(_DWORD *)(v49 + 185) = -1073741816;
        *(_DWORD *)(v49 + 189) = v50;
        *(_WORD *)(v49 + 205) = 12;
        *(_WORD *)(v49 + 211) = 16;
        *(_DWORD *)(v49 + 213) = v50;
        *(_DWORD *)(v49 + 225) = -1073741817;
        *(_DWORD *)(v49 + 229) = v50;
        *(_DWORD *)(v49 + 256) = 0;
        _init_swait_queue_head(v49 + 264, "&x->wait", &init_completion___key);
        *(_DWORD *)(v51 + 252) = 250;
        *(_QWORD *)(v10 + 1792) = v51;
      }
      else
      {
        *(_BYTE *)(v10 + 1992) = 0;
        if ( v10 )
        {
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "ERR:%s: PCIe: RC%d: setup sw drv failed\n",
            "msm_pcie_setup_sw_drv",
            *(_DWORD *)(v10 + 1348));
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: PCIe: RC%d: setup sw drv failed\n",
            "msm_pcie_setup_sw_drv",
            *(_DWORD *)(v10 + 1348));
        }
        printk(&unk_2EAFC);
      }
    }
  }
  if ( v10 )
  {
    if ( *(_QWORD *)(v10 + 1984) )
      v53 = *(const char **)(v10 + 1984);
    else
      v53 = "no";
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: %s-DRV supported\n",
      "msm_pcie_read_dt",
      *(unsigned int *)(v10 + 1348),
      v53);
    if ( *(_QWORD *)(v10 + 1984) )
      v54 = *(const char **)(v10 + 1984);
    else
      v54 = "no";
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: %s-DRV supported\n",
      "msm_pcie_read_dt",
      *(unsigned int *)(v10 + 1348),
      v54);
  }
  *(_BYTE *)(v10 + 1993) = of_find_property(v4, "qcom,panic-genspeed-mismatch", 0) != 0;
  memcpy((void *)(v10 + 64), &msm_pcie_vreg_info, 0xC0u);
  *(_QWORD *)(v10 + 320) = "qcom,ep-gpio";
  *(_QWORD *)(v10 + 328) = 0x100000000LL;
  *(_QWORD *)(v10 + 336) = 1;
  *(_QWORD *)(v10 + 344) = 0;
  *(_QWORD *)(v10 + 288) = "wake-gpio";
  *(_QWORD *)(v10 + 296) = 0;
  *(_QWORD *)(v10 + 304) = 0;
  *(_QWORD *)(v10 + 312) = 0;
  *(_QWORD *)(v10 + 256) = "perst-gpio";
  *(_QWORD *)(v10 + 264) = 0x100000000LL;
  *(_QWORD *)(v10 + 272) = 0;
  *(_QWORD *)(v10 + 280) = 1;
  memcpy((void *)(v10 + 352), &msm_pcie_res_info, 0xD8u);
  *(_QWORD *)(v10 + 616) = "int_d";
  *(_QWORD *)(v10 + 624) = 0;
  *(_QWORD *)(v10 + 632) = "int_global_int";
  *(_QWORD *)(v10 + 640) = 0;
  *(_QWORD *)(v10 + 584) = "int_b";
  *(_QWORD *)(v10 + 592) = 0;
  *(_QWORD *)(v10 + 600) = "int_c";
  v55 = v262;
  *(_QWORD *)(v10 + 608) = 0;
  *(_QWORD *)(v10 + 568) = "int_a";
  *(_QWORD *)(v10 + 576) = 0;
  if ( v55 > 5 )
    goto LABEL_501;
  if ( v55 == 5 )
    goto LABEL_383;
  v56 = (_QWORD *)((char *)&msm_pcie_reset_info + 120 * v55);
  v258 = v4;
  v257 = v10 + 1872;
  *(_QWORD *)(v10 + 736) = v56[11];
  *(_QWORD *)(v10 + 744) = v56[12];
  *(_QWORD *)(v10 + 752) = v56[13];
  *(_QWORD *)(v10 + 760) = v56[14];
  *(_QWORD *)(v10 + 704) = v56[7];
  *(_QWORD *)(v10 + 712) = v56[8];
  *(_QWORD *)(v10 + 720) = v56[9];
  *(_QWORD *)(v10 + 728) = v56[10];
  *(_QWORD *)(v10 + 672) = v56[3];
  *(_QWORD *)(v10 + 680) = v56[4];
  *(_QWORD *)(v10 + 688) = v56[5];
  *(_QWORD *)(v10 + 696) = v56[6];
  *(_QWORD *)(v10 + 648) = *v56;
  *(_QWORD *)(v10 + 656) = v56[1];
  v57 = (_QWORD *)((char *)&msm_pcie_pipe_reset_info + 24 * v55);
  *(_QWORD *)(v10 + 664) = v56[2];
  v58 = (_QWORD *)((char *)&msm_pcie_linkdown_reset_info + 48 * v55);
  *(_QWORD *)(v10 + 768) = *v57;
  *(_QWORD *)(v10 + 776) = v57[1];
  *(_QWORD *)(v10 + 784) = v57[2];
  *(_QWORD *)(v10 + 808) = v58[2];
  *(_QWORD *)(v10 + 816) = v58[3];
  *(_QWORD *)(v10 + 824) = v58[4];
  *(_QWORD *)(v10 + 832) = v58[5];
  *(_QWORD *)(v10 + 792) = *v58;
  v59 = v58[1];
  *(_DWORD *)(v10 + 1952) = 0;
  *(_QWORD *)(v10 + 800) = v59;
  v256 = (const char **)(v10 + 256);
  _init_swait_queue_head(v10 + 1960, "&x->wait", &init_completion___key);
  *(_QWORD *)(a1 + 168) = v10;
  v60 = *(_QWORD *)v10;
  v259 = a1;
  if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: entry\n",
      "msm_pcie_get_resources",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: entry\n",
      "msm_pcie_get_resources",
      *(_DWORD *)(v10 + 1348));
  }
  for ( i = 0; i != 216; i += 24 )
  {
    v62 = v10 + i;
    resource_byname = (const void *)platform_get_resource_byname(*(_QWORD *)v10, 512, *(_QWORD *)(v10 + i + 352));
    if ( resource_byname )
    {
      v64 = resource_byname;
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: start addr for %s is %pa.\n",
          "msm_pcie_get_reg",
          *(const char **)(v62 + 352),
          resource_byname);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: start addr for %s is %pa.\n",
          "msm_pcie_get_reg",
          *(const char **)(v62 + 352),
          v64);
      }
      v65 = devm_ioremap(*(_QWORD *)v10 + 16LL);
      v66 = v10 + i;
      *(_QWORD *)(v10 + i + 368) = v65;
      if ( !v65 )
      {
        if ( v10 )
        {
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "ERR:%s: PCIe: RC%d: can't remap %s.\n",
            "msm_pcie_get_reg",
            *(_DWORD *)(v10 + 1348),
            *(const char **)(v66 + 352));
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: PCIe: RC%d: can't remap %s.\n",
            "msm_pcie_get_reg",
            *(_DWORD *)(v10 + 1348),
            *(const char **)(v66 + 352));
        }
        printk(&unk_252D3);
        goto LABEL_405;
      }
      *(_QWORD *)(v66 + 360) = v64;
    }
    else
    {
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "ERR:%s: PCIe: RC%d: no %s resource found.\n",
          "msm_pcie_get_reg",
          *(_DWORD *)(v10 + 1348),
          *(const char **)(v62 + 352));
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: PCIe: RC%d: no %s resource found.\n",
          "msm_pcie_get_reg",
          *(_DWORD *)(v10 + 1348),
          *(const char **)(v62 + 352));
      }
      printk(&unk_26083);
    }
  }
  v67 = *(_QWORD *)(v10 + 392);
  *(_QWORD *)(v10 + 872) = *(_QWORD *)(v10 + 368);
  v68 = *(_QWORD *)(v10 + 440);
  *(_QWORD *)(v10 + 880) = v67;
  v69 = *(_QWORD *)(v10 + 464);
  *(_QWORD *)(v10 + 888) = v68;
  v70 = *(_QWORD *)(v10 + 416);
  *(_QWORD *)(v10 + 896) = v69;
  v71 = *(_QWORD *)(v10 + 488);
  *(_QWORD *)(v10 + 904) = v70;
  v72 = *(_QWORD *)(v10 + 512);
  *(_QWORD *)(v10 + 3128) = v71;
  v73 = *(_QWORD *)(v10 + 536);
  *(_QWORD *)(v10 + 912) = v72;
  v74 = *(_QWORD *)(v10 + 560);
  *(_QWORD *)(v10 + 920) = v73;
  *(_QWORD *)(v10 + 928) = v74;
  v75 = of_icc_get(v60 + 16, "icc_path");
  *(_QWORD *)(v10 + 1208) = v75;
  if ( v75 >= 0xFFFFFFFFFFFFF001LL )
  {
    v128 = v75;
    if ( v10 )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "ERR:%s: PCIe: RC%d: failed to get ICC path: %d\n",
        "msm_pcie_get_resources",
        *(_DWORD *)(v10 + 1348),
        v75);
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: PCIe: RC%d: failed to get ICC path: %d\n",
        "msm_pcie_get_resources",
        *(_DWORD *)(v10 + 1348),
        v128);
    }
    printk(&unk_2B691);
    LODWORD(optional) = v128;
    if ( !*(_QWORD *)(v10 + 928) )
      goto LABEL_406;
  }
  for ( j = 0; j != 80; j += 16 )
  {
    v2 = v10 + j;
    irq_byname = platform_get_irq_byname(v60, *(_QWORD *)(v10 + j + 568));
    if ( irq_byname < 0 )
    {
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: PCIe: RC%d: can't find IRQ # for %s. ret %d\n",
          "msm_pcie_get_resources",
          *(_DWORD *)(v10 + 1348),
          *(const char **)(v2 + 568),
          irq_byname);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: PCIe: RC%d: can't find IRQ # for %s. ret %d\n",
          "msm_pcie_get_resources",
          *(_DWORD *)(v10 + 1348),
          *(const char **)(v2 + 568),
          irq_byname);
      }
    }
    else
    {
      *(_DWORD *)(v2 + 576) = irq_byname;
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: IRQ # for %s is %d.\n",
          "msm_pcie_get_resources",
          *(const char **)(v2 + 568),
          irq_byname);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: IRQ # for %s is %d.\n",
          "msm_pcie_get_resources",
          *(const char **)(v2 + 568),
          *(_DWORD *)(v2 + 576));
      }
    }
  }
  v78 = *(_QWORD *)(v60 + 760);
  LODWORD(v264) = 0;
  of_get_property(v78, "qcom,tcsr", &v264);
  if ( (_DWORD)v264 )
  {
    v79 = devm_kmalloc(v60 + 16, (int)v264, 3520);
    *(_QWORD *)(v10 + 1640) = v79;
    if ( !v79 )
      goto LABEL_405;
    v80 = (unsigned __int64)(int)v264 >> 2;
    *(_DWORD *)(v10 + 1632) = (int)v264 >> 3;
    of_property_read_variable_u32_array(*(_QWORD *)(v60 + 760), "qcom,tcsr", v79, v80, 0);
  }
  else if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: tcsr is not present in DT\n",
      "msm_pcie_get_tcsr_values",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: tcsr is not present in DT\n",
      "msm_pcie_get_tcsr_values",
      *(_DWORD *)(v10 + 1348));
  }
  v81 = *(_QWORD *)v10;
  *(_QWORD *)&v264 = 0;
  all = devm_clk_bulk_get_all(v81 + 16, &v264);
  if ( (int)all > 0 )
  {
    v83 = of_property_count_elems_of_size(*(_QWORD *)(v81 + 760), "qcom,pcie-clock-frequency", 4);
    if ( v83 == all )
    {
      v84 = devm_kmalloc(v81 + 16, 4LL * all, 3520);
      if ( !v84 )
        goto LABEL_405;
      v261 = v84;
      v85 = of_property_read_variable_u32_array(*(_QWORD *)(v81 + 760), "qcom,pcie-clock-frequency", v84, all, 0);
      if ( v85 < 0 )
      {
        v172 = v85 & (v85 >> 31);
        if ( v10 )
        {
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "ERR:%s: PCIe: RC%d: failed to get clock frequencies: ret: %d\n",
            "msm_pcie_get_clk",
            *(_DWORD *)(v10 + 1348),
            v172);
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: PCIe: RC%d: failed to get clock frequencies: ret: %d\n",
            "msm_pcie_get_clk",
            *(_DWORD *)(v10 + 1348),
            v172);
        }
        v171 = &unk_291F4;
      }
      else
      {
        v86 = of_property_count_elems_of_size(*(_QWORD *)(v81 + 760), "clock-suppressible", 4);
        if ( v86 == all )
        {
          v87 = devm_kmalloc(v81 + 16, 4LL * all, 3520);
          if ( !v87 )
            goto LABEL_405;
          v260 = v87;
          v88 = of_property_read_variable_u32_array(*(_QWORD *)(v81 + 760), "clock-suppressible", v87, all, 0);
          if ( (v88 & 0x80000000) == 0 )
          {
            v89 = 24LL * all;
            v90 = devm_kmalloc(v81 + 16, v89, 3520);
            if ( !v90 )
              goto LABEL_405;
            v92 = v261;
            v91 = 4LL * all;
            v93 = v90;
            v94 = v264;
            v95 = v260;
            v1 = nullptr;
            v255 = v81;
            v96 = 20;
            v97 = all;
            *(_QWORD *)(v10 + 864) = v90;
            *(_QWORD *)(v10 + 848) = v90;
            do
            {
              if ( v89 <= v96 - 12 )
                goto LABEL_382;
              v98 = *(const char **)v94;
              v2 = v93 + v96;
              *(_QWORD *)(v93 + v96 - 12) = *(_QWORD *)v94;
              if ( v89 <= v96 - 20 )
                goto LABEL_382;
              *(_QWORD *)(v2 - 20) = *(_QWORD *)(v94 + 8);
              if ( v91 <= (unsigned __int64)v1 )
                goto LABEL_382;
              if ( v89 <= v96 - 4 )
                goto LABEL_382;
              v99 = *(_DWORD *)&v1[v92];
              *(_DWORD *)(v93 + v96 - 4) = v99;
              if ( v91 <= (unsigned __int64)v1 || v89 < v96 )
                goto LABEL_382;
              v100 = *(_DWORD *)&v1[v95];
              *(_BYTE *)(v93 + v96) = v100 != 0;
              if ( v10 )
              {
                ipc_log_string(
                  *(_QWORD *)(v10 + 1704),
                  "DBG1:%s: PCIe: RC%d: %s: frequency: %d: suppressible: %d\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348),
                  v98,
                  v99,
                  v100 != 0);
                if ( v89 <= v96 - 12 || v89 <= v96 - 4 || v89 < v96 )
                  goto LABEL_382;
                ipc_log_string(
                  *(_QWORD *)(v10 + 1696),
                  "%s: PCIe: RC%d: %s: frequency: %d: suppressible: %d\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348),
                  *(const char **)(v2 - 12),
                  *(_DWORD *)(v93 + v96 - 4),
                  *(unsigned __int8 *)(v93 + v96));
                v92 = v261;
                v91 = 4LL * all;
                v94 = v264;
                v95 = v260;
              }
              v94 += 16;
              --v97;
              v96 += 24LL;
              v1 += 4;
              *(_QWORD *)&v264 = v94;
            }
            while ( v97 );
            v101 = *(_QWORD *)(v10 + 864);
            if ( !strcmp(*(const char **)(v101 + 8), "pcie_pipe_clk") )
            {
              v103 = all;
              v102 = v255;
              v104 = *(_DWORD *)(v10 + 840) + 1;
              *(_QWORD *)(v10 + 864) = v101 + 24;
              *(_DWORD *)(v10 + 840) = v104;
            }
            else
            {
              v103 = all;
              if ( v10 )
              {
                ipc_log_string(
                  *(_QWORD *)(v10 + 1704),
                  "ERR:%s: PCIe: RC%d: could not find entry for pcie_pipe_clk\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v10 + 1696),
                  "%s: PCIe: RC%d: could not find entry for pcie_pipe_clk\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
              }
              printk(&unk_2BDFD);
              v102 = v255;
              if ( !*(_QWORD *)(v10 + 3128) )
                goto LABEL_475;
              v104 = *(_DWORD *)(v10 + 840);
            }
            *(_DWORD *)(v10 + 856) = v103 - v104;
            v105 = clk_get(v102 + 16, "pcie_rate_change_clk");
            *(_QWORD *)(v10 + 1008) = v105;
            if ( v105 >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( v10 )
              {
                ipc_log_string(
                  *(_QWORD *)(v10 + 1704),
                  "DBG1:%s: PCIe: RC%d: pcie_rate_change_clk is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v10 + 1696),
                  "%s: PCIe: RC%d: pcie_rate_change_clk is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
              }
              *(_QWORD *)(v10 + 1008) = 0;
            }
            v106 = clk_get(v102 + 16, "pcie_pipe_clk_mux");
            *(_QWORD *)(v10 + 1016) = v106;
            if ( v106 >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( v10 )
              {
                ipc_log_string(
                  *(_QWORD *)(v10 + 1704),
                  "DBG1:%s: PCIe: RC%d: pcie_pipe_clk_mux is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v10 + 1696),
                  "%s: PCIe: RC%d: pcie_pipe_clk_mux is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
              }
              *(_QWORD *)(v10 + 1016) = 0;
            }
            v107 = clk_get(v102 + 16, "pcie_pipe_clk_ext_src");
            *(_QWORD *)(v10 + 1024) = v107;
            if ( v107 >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( v10 )
              {
                ipc_log_string(
                  *(_QWORD *)(v10 + 1704),
                  "DBG1:%s: PCIe: RC%d: pcie_pipe_clk_ext_src is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v10 + 1696),
                  "%s: PCIe: RC%d: pcie_pipe_clk_ext_src is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
              }
              *(_QWORD *)(v10 + 1024) = 0;
            }
            v108 = clk_get(v102 + 16, "pcie_phy_aux_clk_mux");
            if ( v108 <= 0xFFFFFFFFFFFFF000LL )
              v109 = v108;
            else
              v109 = 0;
            *(_QWORD *)(v10 + 1032) = v109;
            v110 = clk_get(v102 + 16, "pcie_phy_aux_clk_ext_src");
            if ( v110 <= 0xFFFFFFFFFFFFF000LL )
              v111 = v110;
            else
              v111 = 0;
            *(_QWORD *)(v10 + 1040) = v111;
            v112 = clk_get(v102 + 16, "pcie_ref_clk_src");
            *(_QWORD *)(v10 + 1048) = v112;
            if ( v112 >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( v10 )
              {
                ipc_log_string(
                  *(_QWORD *)(v10 + 1704),
                  "DBG1:%s: PCIe: RC%d: pcie_ref_clk_src is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v10 + 1696),
                  "%s: PCIe: RC%d: pcie_ref_clk_src is not present\n",
                  "msm_pcie_get_clk",
                  *(_DWORD *)(v10 + 1348));
              }
              *(_QWORD *)(v10 + 1048) = 0;
            }
            goto LABEL_191;
          }
          v174 = v88 & (v88 >> 31);
          if ( v10 )
          {
            ipc_log_string(
              *(_QWORD *)(v10 + 1704),
              "ERR:%s: PCIe: RC%d: failed to get clock suppressible info: ret: %d\n",
              "msm_pcie_get_clk",
              *(_DWORD *)(v10 + 1348),
              v174);
            ipc_log_string(
              *(_QWORD *)(v10 + 1696),
              "%s: PCIe: RC%d: failed to get clock suppressible info: ret: %d\n",
              "msm_pcie_get_clk",
              *(_DWORD *)(v10 + 1348),
              v174);
          }
          v171 = &unk_29274;
        }
        else
        {
          v173 = v86;
          if ( v10 )
          {
            ipc_log_string(
              *(_QWORD *)(v10 + 1704),
              "ERR:%s: PCIe: RC%d: mismatch between number of clock and suppressible entries: %d != %d\n",
              "msm_pcie_get_clk",
              *(_DWORD *)(v10 + 1348),
              all,
              v86);
            ipc_log_string(
              *(_QWORD *)(v10 + 1696),
              "%s: PCIe: RC%d: mismatch between number of clock and suppressible entries: %d != %d\n",
              "msm_pcie_get_clk",
              *(_DWORD *)(v10 + 1348),
              all,
              v173);
          }
          v171 = &unk_2C405;
        }
      }
    }
    else
    {
      v170 = v83;
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "ERR:%s: PCIe: RC%d: mismatch between number of clock and frequency entries: %d != %d\n",
          "msm_pcie_get_clk",
          *(_DWORD *)(v10 + 1348),
          all,
          v83);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: PCIe: RC%d: mismatch between number of clock and frequency entries: %d != %d\n",
          "msm_pcie_get_clk",
          *(_DWORD *)(v10 + 1348),
          all,
          v170);
      }
      v171 = &unk_2FFF0;
    }
LABEL_358:
    printk(v171);
    LODWORD(optional) = -5;
    goto LABEL_406;
  }
  if ( !*(_QWORD *)(v10 + 3128) )
  {
    if ( v10 )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "ERR:%s: PCIe: RC%d: failed to get clocks: ret: %d\n",
        "msm_pcie_get_clk",
        *(_DWORD *)(v10 + 1348),
        all);
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: PCIe: RC%d: failed to get clocks: ret: %d\n",
        "msm_pcie_get_clk",
        *(_DWORD *)(v10 + 1348),
        all);
    }
    v171 = &unk_2A2B3;
    goto LABEL_358;
  }
LABEL_191:
  v113 = *(_QWORD *)v10;
  v114 = 0;
  v263 = 0;
  v265 = 0;
  v266 = 0;
  v264 = 0u;
  do
  {
    v115 = v10 + v114;
    optional = devm_regulator_get_optional(v113 + 16, *(_QWORD *)(v10 + v114 + 72));
    *(_QWORD *)(v10 + v114 + 64) = optional;
    v117 = (_QWORD *)(v10 + v114 + 64);
    if ( optional == -517 )
    {
      if ( !v10 )
      {
        LODWORD(optional) = -517;
        goto LABEL_406;
      }
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: EPROBE_DEFER for VReg:%s\n",
        "msm_pcie_get_vreg",
        *(const char **)(v115 + 72));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: EPROBE_DEFER for VReg:%s\n",
        "msm_pcie_get_vreg",
        *(const char **)(v115 + 72));
      LODWORD(optional) = *(_DWORD *)(v115 + 64);
      v2 = a1;
      if ( !(_DWORD)optional )
        goto LABEL_245;
LABEL_406:
      v126 = optional;
      --pcie_drv[0];
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "ERR:%s: PCIe: RC%d: Driver probe failed. ret: %d\n",
          "msm_pcie_probe",
          *(_DWORD *)(v10 + 1348),
          optional);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: PCIe: RC%d: Driver probe failed. ret: %d\n",
          "msm_pcie_probe",
          *(_DWORD *)(v10 + 1348),
          v126);
      }
      printk(&unk_2E1DC);
      if ( v262 <= 4 )
      {
        v190 = (_QWORD *)msm_pcie_dev[v262];
        v191 = v190[5];
        v192 = v190[6];
        if ( v191 )
        {
          if ( v192 )
          {
            dev_pm_domain_detach(v191, 0);
            dev_pm_domain_detach(v190[6], 0);
            goto LABEL_414;
          }
        }
        else if ( !v192 )
        {
          goto LABEL_414;
        }
        _pm_runtime_disable(*v190 + 16LL, 1);
LABEL_414:
        if ( v262 < 5 )
          goto LABEL_464;
LABEL_415:
        printk(&unk_24C80);
        goto LABEL_464;
      }
LABEL_501:
      __break(0x5512u);
    }
    if ( optional < 0xFFFFFFFFFFFFF001LL )
    {
      ++*(_DWORD *)(v10 + 948);
      scnprintf(&v264, 32, "qcom,%s-voltage-level", *(const char **)(v115 + 72));
      v118 = (unsigned int *)of_get_property(*(_QWORD *)(v113 + 760), &v264, &v263);
      if ( v118 && v263 == 12 )
      {
        v119 = (_DWORD *)(v10 + v114);
        v119[20] = bswap32(*v118);
        v119[21] = bswap32(v118[1]);
        v119[22] = bswap32(v118[2]);
      }
      else if ( v10 )
      {
        if ( v118 )
          v120 = "invalid format";
        else
          v120 = "no";
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: %s %s property\n",
          "msm_pcie_get_vreg",
          v120,
          (const char *)&v264);
        ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: %s %s property\n", "msm_pcie_get_vreg", v120, (const char *)&v264);
      }
      v121 = *(const char **)(v115 + 72);
      if ( !strcmp(v121, "vreg-cx") )
      {
        *(_QWORD *)(v10 + 968) = v117;
        v121 = *(const char **)(v115 + 72);
      }
      if ( !strcmp(v121, "vreg-mx") )
        *(_QWORD *)(v10 + 976) = v117;
    }
    else
    {
      if ( *(_BYTE *)(v10 + v114 + 92) == 1 && !*(_QWORD *)(v10 + 3128) )
      {
        if ( v10 )
        {
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "DBG1:%s: Vreg %s doesn't exist\n",
            "msm_pcie_get_vreg",
            *(const char **)(v10 + v114 + 72));
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: Vreg %s doesn't exist\n",
            "msm_pcie_get_vreg",
            *(const char **)(v10 + v114 + 72));
          optional = *(_QWORD *)(v10 + v114 + 64);
        }
        v2 = a1;
        if ( (_DWORD)optional )
          goto LABEL_406;
        goto LABEL_245;
      }
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: Optional Vreg %s doesn't exist\n",
          "msm_pcie_get_vreg",
          *(const char **)(v115 + 72));
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: Optional Vreg %s doesn't exist\n",
          "msm_pcie_get_vreg",
          *(const char **)(v115 + 72));
      }
      *v117 = 0;
    }
    v114 += 32;
  }
  while ( v114 != 192 );
  v2 = a1;
  if ( of_find_property(*(_QWORD *)(v113 + 760), "power-domains", 0) )
  {
    v122 = *(_QWORD *)v10;
    *(_QWORD *)(v10 + 24) = 0;
    *(_QWORD *)(v10 + 32) = 0;
    if ( *(_QWORD *)(v122 + 608) )
    {
      if ( (unsigned int)of_property_read_string(*(_QWORD *)(v122 + 760), "power-domain-names", v10 + 56) )
        goto LABEL_286;
      v123 = *(const char **)(v10 + 56);
      if ( !strcmp(v123, "gdsc-core-vdd") )
      {
        v125 = 0;
        v124 = v122 + 16;
      }
      else
      {
        if ( strcmp(v123, "gdsc-phy-vdd") )
          goto LABEL_286;
        v124 = 0;
        v125 = v122 + 16;
      }
      *(_QWORD *)(v10 + 40) = v124;
      *(_QWORD *)(v10 + 48) = v125;
      *(_WORD *)(v122 + 504) |= 0x100u;
      pm_runtime_enable(v122 + 16);
    }
    else
    {
      LODWORD(optional) = msm_pcie_genpd_get_dev(v10, "gdsc-core-vdd", v10 + 40);
      if ( (_DWORD)optional )
        goto LABEL_406;
      LODWORD(optional) = msm_pcie_genpd_get_dev(v10, "gdsc-phy-vdd", v10 + 48);
      if ( (_DWORD)optional )
      {
        if ( *(_QWORD *)(v10 + 40) )
        {
          v127 = optional;
          dev_pm_domain_detach(*(_QWORD *)(v10 + 40), 0);
          LODWORD(optional) = v127;
        }
        goto LABEL_406;
      }
    }
  }
  else
  {
    *(_QWORD *)(v10 + 40) = 0;
    *(_QWORD *)(v10 + 48) = 0;
    LODWORD(optional) = msm_pcie_gdsc_vreg_get(v10, "gdsc-core-vdd", v10 + 24);
    if ( (_DWORD)optional )
      goto LABEL_406;
    LODWORD(optional) = msm_pcie_gdsc_vreg_get(v10, "gdsc-phy-vdd", v10 + 32);
    if ( (_DWORD)optional )
      goto LABEL_406;
  }
LABEL_245:
  v129 = 0;
  while ( 2 )
  {
    v130 = v10 + v129;
    optional = _devm_reset_control_get(*(_QWORD *)v10 + 16LL, *(_QWORD *)(v10 + v129 + 656), 0, 0, 0, 1);
    *(_QWORD *)(v10 + v129 + 648) = optional;
    if ( optional < 0xFFFFFFFFFFFFF001LL )
    {
LABEL_247:
      v129 += 24;
      if ( v129 != 120 )
        continue;
      optional = _devm_reset_control_get(*(_QWORD *)v10 + 16LL, *(_QWORD *)(v10 + 776), 0, 0, 0, 1);
      *(_QWORD *)(v10 + 768) = optional;
      if ( optional >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( *(_BYTE *)(v10 + 784) == 1 )
        {
          v131 = (unsigned __int64 *)(v10 + 768);
          if ( v10 )
          {
            v132 = "%s: Pipe Reset %s isn't available:%ld\n";
            v133 = (_QWORD *)(v10 + 776);
            ipc_log_string(
              *(_QWORD *)(v10 + 1704),
              "DBG1:%s: Pipe Reset %s isn't available:%ld\n",
              "msm_pcie_get_reset",
              *(_QWORD *)(v10 + 776),
              optional);
            goto LABEL_265;
          }
          goto LABEL_266;
        }
        if ( v10 )
        {
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "DBG1:%s: Ignoring Pipe Reset %s\n",
            "msm_pcie_get_reset",
            *(const char **)(v10 + 776));
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: Ignoring Pipe Reset %s\n",
            "msm_pcie_get_reset",
            *(const char **)(v10 + 776));
        }
        *(_QWORD *)(v10 + 768) = 0;
      }
      v135 = _devm_reset_control_get(*(_QWORD *)v10 + 16LL, *(_QWORD *)(v10 + 800), 0, 0, 0, 1);
      *(_QWORD *)(v10 + 792) = v135;
      if ( v135 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( *(_BYTE *)(v10 + 808) == 1 )
        {
          v136 = (unsigned __int64 *)(v10 + 792);
          v137 = v135;
          v133 = (_QWORD *)(v10 + 800);
          if ( v10 )
            goto LABEL_264;
          goto LABEL_274;
        }
        if ( v10 )
        {
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "DBG1:%s: Ignoring Linkdown Reset %s\n",
            "msm_pcie_get_reset",
            *(const char **)(v10 + 800));
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: Ignoring Linkdown Reset %s\n",
            "msm_pcie_get_reset",
            *(const char **)(v10 + 800));
        }
        *(_QWORD *)(v10 + 792) = 0;
      }
      v138 = _devm_reset_control_get(*(_QWORD *)v10 + 16LL, *(_QWORD *)(v10 + 824), 0, 0, 0, 1);
      *(_QWORD *)(v10 + 816) = v138;
      if ( v138 < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_278;
      v136 = (unsigned __int64 *)(v10 + 816);
      if ( (*(_BYTE *)(v10 + 832) & 1) == 0 )
      {
        if ( v10 )
        {
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "DBG1:%s: Ignoring Linkdown Reset %s\n",
            "msm_pcie_get_reset",
            *(const char **)(v10 + 824));
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: Ignoring Linkdown Reset %s\n",
            "msm_pcie_get_reset",
            *(const char **)(v10 + 824));
          v136 = (unsigned __int64 *)(v10 + 816);
        }
        *v136 = 0;
        goto LABEL_278;
      }
      v137 = v138;
      v133 = (_QWORD *)(v10 + 824);
      if ( v10 )
      {
LABEL_264:
        v132 = "%s: Linkdown Reset %s isn't available:%ld\n";
        v131 = v136;
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: Linkdown Reset %s isn't available:%ld\n",
          "msm_pcie_get_reset",
          *v133,
          v137);
LABEL_265:
        ipc_log_string(*(_QWORD *)(v10 + 1696), v132, "msm_pcie_get_reset", *v133, *v131);
        optional = *v131;
        goto LABEL_266;
      }
LABEL_274:
      LODWORD(optional) = v137;
      goto LABEL_406;
    }
    break;
  }
  if ( *(_BYTE *)(v130 + 664) != 1 )
  {
    if ( v10 )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: Ignoring Reset %s\n",
        "msm_pcie_get_reset",
        *(const char **)(v130 + 656));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: Ignoring Reset %s\n",
        "msm_pcie_get_reset",
        *(const char **)(v130 + 656));
    }
    *(_QWORD *)(v130 + 648) = 0;
    goto LABEL_247;
  }
  if ( v10 )
  {
    v134 = v10 + v129;
    v132 = "%s: Reset %s isn't available:%ld\n";
    v131 = (unsigned __int64 *)(v10 + v129 + 648);
    v133 = (_QWORD *)(v134 + 656);
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: Reset %s isn't available:%ld\n",
      "msm_pcie_get_reset",
      *(_QWORD *)(v134 + 656),
      optional);
    goto LABEL_265;
  }
LABEL_266:
  if ( (_DWORD)optional )
    goto LABEL_406;
LABEL_278:
  LODWORD(v264) = 0;
  v139 = *(_QWORD *)v10;
  of_get_property(*(_QWORD *)(*(_QWORD *)v10 + 760LL), "qcom,bw-scale", &v264);
  if ( (_DWORD)v264 )
  {
    v140 = devm_kmalloc(v139 + 16, (int)v264, 3520);
    *(_QWORD *)(v10 + 984) = v140;
    if ( v140 )
    {
      of_property_read_variable_u32_array(
        *(_QWORD *)(v139 + 760),
        "qcom,bw-scale",
        v140,
        (unsigned __int64)(int)v264 >> 2,
        0);
      *(_DWORD *)(v10 + 992) = (int)v264 / 0xCuLL;
      goto LABEL_283;
    }
LABEL_405:
    LODWORD(optional) = -12;
    goto LABEL_406;
  }
  if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: RC%d: bandwidth scaling is not supported\n",
      "msm_pcie_get_bw_scale",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: RC%d: bandwidth scaling is not supported\n",
      "msm_pcie_get_bw_scale",
      *(_DWORD *)(v10 + 1348));
  }
LABEL_283:
  LODWORD(v264) = 0;
  v141 = *(_QWORD *)v10;
  of_get_property(*(_QWORD *)(*(_QWORD *)v10 + 760LL), "qcom,phy-sequence", &v264);
  if ( (_DWORD)v264 )
  {
    v142 = devm_kmalloc(v141 + 16, (int)v264, 3520);
    *(_QWORD *)(v10 + 1624) = v142;
    if ( !v142 )
      goto LABEL_405;
    v143 = (unsigned __int64)(int)v264 >> 2;
    *(_DWORD *)(v10 + 1620) = (int)v264 / 0xCuLL;
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(v141 + 760), "qcom,phy-sequence", v142, v143, 0) & 0x80000000) != 0 )
    {
LABEL_286:
      LODWORD(optional) = -22;
      goto LABEL_406;
    }
  }
  else if ( v10 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: phy sequence is not present in DT\n",
      "msm_pcie_get_phy",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: phy sequence is not present in DT\n",
      "msm_pcie_get_phy",
      *(_DWORD *)(v10 + 1348));
  }
  v1 = *(const char **)v10;
  LODWORD(v264) = 0;
  of_get_property(*((_QWORD *)v1 + 95), "iommu-map", &v264);
  if ( !(_DWORD)v264 )
  {
    if ( v10 )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: PCIe: RC%d: iommu-map is not present in DT.\n",
        "msm_pcie_get_iommu_map",
        *(_DWORD *)(v10 + 1348));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: PCIe: RC%d: iommu-map is not present in DT.\n",
        "msm_pcie_get_iommu_map",
        *(_DWORD *)(v10 + 1348));
    }
    goto LABEL_308;
  }
  v144 = (int)v264;
  v145 = _kmalloc_noprof((int)v264, 3520);
  if ( !v145 )
    goto LABEL_405;
  while ( 2 )
  {
    of_property_read_variable_u32_array(*((_QWORD *)v1 + 95), "iommu-map", v145, (unsigned __int64)(int)v264 >> 2, 0);
    v146 = 16LL * (unsigned int)((int)v264 >> 4);
    *(_DWORD *)(v10 + 1648) = (int)v264 >> 4;
    v147 = devm_kmalloc(v1 + 16, v146, 3520);
    *(_QWORD *)(v10 + 1656) = v147;
    if ( !v147 )
    {
      kfree(v145);
      goto LABEL_405;
    }
    if ( *(_DWORD *)(v10 + 1648) )
    {
      v148 = 0;
      while ( 1 )
      {
        v149 = 16LL * (int)v148;
        if ( (v148 & 0x80000000) != 0 )
          break;
        if ( v144 < v149 )
          break;
        if ( v144 - v149 < 4 )
          break;
        v150 = 16LL * (int)v148;
        if ( v144 < v150 )
          break;
        if ( v144 - v150 < 4 )
          break;
        v151 = v149 | 8;
        v152 = v144 >= v151;
        v153 = v144 - v151;
        *(_WORD *)(*(_QWORD *)(v10 + 1656) + 16LL * (int)v148) = *(_DWORD *)(v145 + 16LL * (int)v148);
        if ( !v152 || v153 < 4 || v144 < (v150 | 8) || v144 - (v150 | 8) < 4 )
          break;
        ++v148;
        *(_DWORD *)(*(_QWORD *)(v10 + 1656) + v150 + 8) = *(_DWORD *)(v145 + v150 + 8);
        *(_BYTE *)(*(_QWORD *)(v10 + 1656) + v150 + 2) = *(_BYTE *)(*(_QWORD *)(v10 + 1656) + v150 + 8)
                                                       - *(_DWORD *)(v10 + 1236);
        if ( v148 >= *(_DWORD *)(v10 + 1648) )
          goto LABEL_305;
      }
LABEL_382:
      __break(1u);
LABEL_383:
      _fortify_panic(16, -1, 120);
      goto LABEL_384;
    }
LABEL_305:
    kfree(v145);
LABEL_308:
    v154 = *(const char **)v10;
    *(_DWORD *)(v10 + 952) = 0;
    named_gpio = of_get_named_gpio(*((_QWORD *)v154 + 95), *(_QWORD *)(v10 + 256), 0);
    if ( named_gpio < 0 )
    {
      if ( *(_BYTE *)(v10 + 280) == 1 )
        goto LABEL_379;
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: Could not get optional GPIO %s\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 256));
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: Could not get optional GPIO %s\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 256));
      }
    }
    else
    {
      v156 = *(_DWORD *)(v10 + 952);
      *(_DWORD *)(v10 + 264) = named_gpio;
      *(_DWORD *)(v10 + 952) = v156 + 1;
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: GPIO num for %s is %d\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 256),
          named_gpio);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: GPIO num for %s is %d\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 256),
          *(_DWORD *)(v10 + 264));
      }
    }
    named_gpio = of_get_named_gpio(*(_QWORD *)(*(_QWORD *)v10 + 760LL), *(_QWORD *)(v10 + 288), 0);
    if ( (named_gpio & 0x80000000) == 0 )
    {
      v157 = *(_DWORD *)(v10 + 952);
      *(_DWORD *)(v10 + 296) = named_gpio;
      *(_DWORD *)(v10 + 952) = v157 + 1;
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: GPIO num for %s is %d\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 288),
          named_gpio);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: GPIO num for %s is %d\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 288),
          *(_DWORD *)(v10 + 296));
      }
      goto LABEL_320;
    }
    if ( (*(_BYTE *)(v10 + 312) & 1) != 0 )
    {
      v175 = (const char **)(v10 + 288);
LABEL_378:
      v256 = v175;
LABEL_379:
      v176 = named_gpio;
      if ( v10 )
      {
        ipc_log_string(*(_QWORD *)(v10 + 1704), "ERR:%s: Could not get required GPIO %s\n", "msm_pcie_get_gpio", *v256);
        ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: Could not get required GPIO %s\n", "msm_pcie_get_gpio", *v256);
      }
      printk(&unk_2B066);
      LODWORD(optional) = v176;
      goto LABEL_406;
    }
    if ( v10 )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: Could not get optional GPIO %s\n",
        "msm_pcie_get_gpio",
        *(const char **)(v10 + 288));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: Could not get optional GPIO %s\n",
        "msm_pcie_get_gpio",
        *(const char **)(v10 + 288));
    }
LABEL_320:
    named_gpio = of_get_named_gpio(*(_QWORD *)(*(_QWORD *)v10 + 760LL), *(_QWORD *)(v10 + 320), 0);
    if ( (named_gpio & 0x80000000) == 0 )
    {
      v158 = *(_DWORD *)(v10 + 952);
      *(_DWORD *)(v10 + 328) = named_gpio;
      *(_DWORD *)(v10 + 952) = v158 + 1;
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: GPIO num for %s is %d\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 320),
          named_gpio);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: GPIO num for %s is %d\n",
          "msm_pcie_get_gpio",
          *(const char **)(v10 + 320),
          *(_DWORD *)(v10 + 328));
      }
      goto LABEL_326;
    }
    if ( (*(_BYTE *)(v10 + 344) & 1) != 0 )
    {
      v175 = (const char **)(v10 + 320);
      goto LABEL_378;
    }
    if ( v10 )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: Could not get optional GPIO %s\n",
        "msm_pcie_get_gpio",
        *(const char **)(v10 + 320));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: Could not get optional GPIO %s\n",
        "msm_pcie_get_gpio",
        *(const char **)(v10 + 320));
    }
LABEL_326:
    v159 = *(unsigned int *)(v10 + 296);
    *(_DWORD *)(v10 + 944) = 0;
    if ( (_DWORD)v159 )
    {
      v160 = gpio_to_desc(v159);
      *(_DWORD *)(v10 + 944) = gpiod_to_irq(v160);
    }
    LODWORD(v264) = 0;
    v161 = *(const char **)v10;
    if ( v10 )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: PCIe: RC%d: Enter\n",
        "msm_pcie_get_parf_status_reg",
        *(_DWORD *)(v10 + 1348));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: PCIe: RC%d: Enter\n",
        "msm_pcie_get_parf_status_reg",
        *(_DWORD *)(v10 + 1348));
    }
    of_get_property(*((_QWORD *)v161 + 95), "qcom,parf-debug-reg", &v264);
    if ( (_DWORD)v264 )
    {
      v162 = _kmalloc_noprof((int)v264, 3264);
      *(_QWORD *)(v10 + 3096) = v162;
      if ( !v162 )
        goto LABEL_405;
      v163 = (unsigned __int64)(int)v264 >> 2;
      *(_DWORD *)(v10 + 3088) = (int)v264 >> 2;
      if ( (of_property_read_variable_u32_array(*((_QWORD *)v161 + 95), "qcom,parf-debug-reg", v162, v163, 0)
          & 0x80000000) != 0 )
      {
        kfree(*(_QWORD *)(v10 + 3096));
        *(_QWORD *)(v10 + 3096) = 0;
        LODWORD(optional) = -22;
        goto LABEL_406;
      }
      if ( v10 )
      {
        ipc_log_string(
          *(_QWORD *)(v10 + 1704),
          "DBG1:%s: PCIe: RC%d: no of parf dbg regs:%lu size:%u\n",
          "msm_pcie_get_parf_status_reg",
          *(_DWORD *)(v10 + 1348),
          (unsigned __int64)(int)v264 >> 2,
          (_DWORD)v264);
        ipc_log_string(
          *(_QWORD *)(v10 + 1696),
          "%s: PCIe: RC%d: no of parf dbg regs:%lu size:%u\n",
          "msm_pcie_get_parf_status_reg",
          *(_DWORD *)(v10 + 1348),
          (unsigned __int64)(int)v264 >> 2,
          (_DWORD)v264);
        goto LABEL_337;
      }
LABEL_384:
      LODWORD(v264) = 0;
      __break(1u);
LABEL_385:
      off_C18 = nullptr;
      LODWORD(v264) = 0;
      __break(1u);
      v144 = (int)v264;
      StatusReg = _ReadStatusReg(SP_EL0);
      v178 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &msm_pcie_get_iommu_map__alloc_tag;
      v145 = _kmalloc_noprof(v144, 3520);
      *(_QWORD *)(StatusReg + 80) = v178;
      if ( !v145 )
        goto LABEL_405;
      continue;
    }
    break;
  }
  if ( !v10 )
    goto LABEL_385;
  ipc_log_string(
    *(_QWORD *)(v10 + 1704),
    "DBG1:%s: PCIe: RC%d: parf debug registers not present in DT\n",
    "msm_pcie_get_parf_status_reg",
    *(_DWORD *)(v10 + 1348));
  ipc_log_string(
    *(_QWORD *)(v10 + 1696),
    "%s: PCIe: RC%d: parf debug registers not present in DT\n",
    "msm_pcie_get_parf_status_reg",
    *(_DWORD *)(v10 + 1348));
  *(_QWORD *)(v10 + 3096) = 0;
LABEL_337:
  LODWORD(v264) = 0;
  v164 = *(const char **)v10;
  ipc_log_string(
    *(_QWORD *)(v10 + 1704),
    "DBG1:%s: PCIe: RC%d: Enter\n",
    "msm_pcie_get_dbi_status_reg",
    *(_DWORD *)(v10 + 1348));
  ipc_log_string(
    *(_QWORD *)(v10 + 1696),
    "%s: PCIe: RC%d: Enter\n",
    "msm_pcie_get_dbi_status_reg",
    *(_DWORD *)(v10 + 1348));
  of_get_property(*((_QWORD *)v164 + 95), "qcom,dbi-debug-reg", &v264);
  if ( !(_DWORD)v264 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: dbi debug registers not present in DT\n",
      "msm_pcie_get_dbi_status_reg",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: dbi debug registers not present in DT\n",
      "msm_pcie_get_dbi_status_reg",
      *(_DWORD *)(v10 + 1348));
    *(_QWORD *)(v10 + 3112) = 0;
    goto LABEL_342;
  }
  v165 = _kmalloc_noprof((int)v264, 3264);
  *(_QWORD *)(v10 + 3112) = v165;
  if ( !v165 )
    goto LABEL_405;
  v166 = (unsigned __int64)(int)v264 >> 2;
  *(_DWORD *)(v10 + 3104) = (int)v264 >> 2;
  if ( (of_property_read_variable_u32_array(*((_QWORD *)v164 + 95), "qcom,dbi-debug-reg", v165, v166, 0) & 0x80000000) != 0 )
  {
    kfree(*(_QWORD *)(v10 + 3112));
    *(_QWORD *)(v10 + 3112) = 0;
    LODWORD(optional) = -22;
    goto LABEL_406;
  }
  ipc_log_string(
    *(_QWORD *)(v10 + 1704),
    "DBG1:%s: PCIe: RC%d: no of dbi dbg regs:%lu size:%u\n",
    "msm_pcie_get_dbi_status_reg",
    *(_DWORD *)(v10 + 1348),
    (unsigned __int64)(int)v264 >> 2,
    (_DWORD)v264);
  ipc_log_string(
    *(_QWORD *)(v10 + 1696),
    "%s: PCIe: RC%d: no of dbi dbg regs:%lu size:%u\n",
    "msm_pcie_get_dbi_status_reg",
    *(_DWORD *)(v10 + 1348),
    (unsigned __int64)(int)v264 >> 2,
    (_DWORD)v264);
LABEL_342:
  LODWORD(v264) = 0;
  v167 = *(const char **)v10;
  ipc_log_string(
    *(_QWORD *)(v10 + 1704),
    "DBG1:%s: PCIe: RC%d: Enter\n",
    "msm_pcie_get_phy_status_reg",
    *(_DWORD *)(v10 + 1348));
  ipc_log_string(
    *(_QWORD *)(v10 + 1696),
    "%s: PCIe: RC%d: Enter\n",
    "msm_pcie_get_phy_status_reg",
    *(_DWORD *)(v10 + 1348));
  of_get_property(*((_QWORD *)v167 + 95), "qcom,phy-debug-reg", &v264);
  if ( (_DWORD)v264 )
  {
    v168 = _kmalloc_noprof((int)v264, 3264);
    *(_QWORD *)(v10 + 3080) = v168;
    if ( !v168 )
    {
      LODWORD(optional) = -12;
      goto LABEL_406;
    }
    v169 = (unsigned __int64)(int)v264 >> 2;
    *(_DWORD *)(v10 + 3072) = (int)v264 >> 2;
    if ( (of_property_read_variable_u32_array(*((_QWORD *)v167 + 95), "qcom,phy-debug-reg", v168, v169, 0) & 0x80000000) != 0 )
    {
      kfree(*(_QWORD *)(v10 + 3080));
      LODWORD(optional) = -22;
      *(_QWORD *)(v10 + 3080) = 0;
      goto LABEL_406;
    }
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: no of phy dbg regs:%lu size:%u\n",
      "msm_pcie_get_phy_status_reg",
      *(_DWORD *)(v10 + 1348),
      (unsigned __int64)(int)v264 >> 2,
      (_DWORD)v264);
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: no of phy dbg regs:%lu size:%u\n",
      "msm_pcie_get_phy_status_reg",
      *(_DWORD *)(v10 + 1348),
      (unsigned __int64)(int)v264 >> 2,
      (_DWORD)v264);
    v2 = v259;
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: phy debug registers not present in DT\n",
      "msm_pcie_get_phy_status_reg",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: phy debug registers not present in DT\n",
      "msm_pcie_get_phy_status_reg",
      *(_DWORD *)(v10 + 1348));
    *(_QWORD *)(v10 + 3080) = 0;
  }
  ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_get_resources", *(_DWORD *)(v10 + 1348));
  ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: RC%d: exit\n", "msm_pcie_get_resources", *(_DWORD *)(v10 + 1348));
  if ( *(_QWORD *)(v10 + 928) )
    *(_QWORD *)(v10 + 3064) = msm_pcie_rumi_init;
  if ( !*(_QWORD *)(v10 + 3128) )
  {
LABEL_427:
    if ( *(_BYTE *)(v10 + 1992) == 1 )
    {
      v212 = _register_rpmsg_driver(&msm_pcie_drv_rpmsg_driver, &_this_module);
      if ( v212 != -16 )
      {
        if ( v212 )
        {
          v254 = v212;
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "ERR:%s: PCIe %d: DRV: rpmsg register fail: ret: %d\n",
            "msm_pcie_probe",
            *(_DWORD *)(v10 + 1348),
            v212);
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: PCIe %d: DRV: rpmsg register fail: ret: %d\n",
            "msm_pcie_probe",
            *(_DWORD *)(v10 + 1348),
            v254);
          printk(&unk_28A02);
          *(_BYTE *)(v10 + 1992) = 0;
        }
      }
    }
    goto LABEL_431;
  }
  ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: pcie CESTA is supported\n", "msm_pcie_probe");
  ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: pcie CESTA is supported\n", "msm_pcie_probe");
  v179 = of_property_read_variable_u32_array(v258, "qcom,pcie-clkreq-pin", v10 + 3152, 1, 0);
  if ( v179 < 0 )
  {
    v241 = v179 & (v179 >> 31);
    ipc_log_string(*(_QWORD *)(v10 + 1704), "ERR:%s: Couldn't find clkreq gpio %d\n", "msm_pcie_cesta_init", v241);
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: Couldn't find clkreq gpio %d\n", "msm_pcie_cesta_init", v241);
    printk(&unk_2D1CD);
    LODWORD(optional) = v241;
    goto LABEL_406;
  }
  LODWORD(v264) = 0;
  v180 = *(const char **)v10;
  of_get_property(*(_QWORD *)(*(_QWORD *)v10 + 760LL), "qcom,pcie-sm-seq", &v264);
  if ( !(_DWORD)v264 )
  {
    v242 = "%s: PCIe: RC%d: state manager seq is not present in DT\n";
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: state manager seq is not present in DT\n",
      "msm_pcie_cesta_get_sm_seq",
      *(unsigned int *)(v10 + 1348));
LABEL_474:
    ipc_log_string(*(_QWORD *)(v10 + 1696), v242, "msm_pcie_cesta_get_sm_seq", *(unsigned int *)(v10 + 1348));
    goto LABEL_475;
  }
  v181 = devm_kmalloc(v180 + 16, 48, 3520);
  if ( !v181 )
    goto LABEL_405;
  v182 = (int)v264;
  v183 = v181;
  v184 = (int)v264 >> 2;
  *(_DWORD *)(v181 + 32) = (int)v264 >> 2;
  v185 = devm_kmalloc(v180 + 16, v182, 3520);
  *(_QWORD *)(v183 + 8) = v185;
  if ( !v185 )
    goto LABEL_405;
  if ( (of_property_read_variable_u32_array(*((_QWORD *)v180 + 95), "qcom,pcie-sm-seq", v185, v184, 0) & 0x80000000) != 0
    || (of_property_read_variable_u32_array(*((_QWORD *)v180 + 95), "qcom,pcie-sm-branch-offset", v183, 1, 0)
      & 0x80000000) != 0
    || (of_property_read_variable_u32_array(*((_QWORD *)v180 + 95), "qcom,pcie-sm-start-offset", v183 + 4, 1, 0)
      & 0x80000000) != 0 )
  {
    goto LABEL_475;
  }
  of_get_property(*((_QWORD *)v180 + 95), "qcom,pcie-sm-branch-seq", &v264);
  v186 = (int)v264;
  if ( !(_DWORD)v264 )
  {
    v242 = "%s: PCIe: RC%d: sm branch seq is not present in DT\n";
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: sm branch seq is not present in DT\n",
      "msm_pcie_cesta_get_sm_seq",
      *(unsigned int *)(v10 + 1348));
    goto LABEL_474;
  }
  *(_DWORD *)(v183 + 36) = (int)v264 >> 2;
  v187 = devm_kmalloc(v180 + 16, v186, 3520);
  *(_QWORD *)(v183 + 16) = v187;
  if ( !v187 )
    goto LABEL_405;
  if ( (of_property_read_variable_u32_array(
          *((_QWORD *)v180 + 95),
          "qcom,pcie-sm-branch-seq",
          v187,
          *(int *)(v183 + 36),
          0)
      & 0x80000000) != 0 )
  {
LABEL_475:
    LODWORD(optional) = -5;
    goto LABEL_406;
  }
  of_get_property(*((_QWORD *)v180 + 95), "qcom,pcie-sm-debug", &v264);
  v188 = (int)v264;
  if ( !(_DWORD)v264 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d: sm debugs regs are not present in DT\n",
      "msm_pcie_cesta_get_sm_seq",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: sm debugs regs are not present in DT\n",
      "msm_pcie_cesta_get_sm_seq",
      *(_DWORD *)(v10 + 1348));
    goto LABEL_417;
  }
  *(_DWORD *)(v183 + 40) = (int)v264 >> 2;
  v189 = devm_kmalloc(v180 + 16, v188, 3520);
  *(_QWORD *)(v183 + 24) = v189;
  if ( !v189 )
    goto LABEL_405;
  if ( (of_property_read_variable_u32_array(*((_QWORD *)v180 + 95), "qcom,pcie-sm-debug", v189, *(int *)(v183 + 40), 0)
      & 0x80000000) != 0 )
    *(_DWORD *)(v183 + 40) = 0;
LABEL_417:
  v193 = *(_DWORD *)(v10 + 1348);
  v194 = dword_30B88;
  v195 = dword_30B80;
  v196 = *(_QWORD *)(v10 + 3128);
  *(_QWORD *)(v10 + 3136) = v183;
  v197 = (unsigned int)(v195 + v194 * v193);
  writel_relaxed_0(0, (unsigned int *)(v196 + v197));
  readl_relaxed_0((unsigned int *)(v196 + v197));
  v198 = *(_QWORD *)(v10 + 3128);
  v199 = (unsigned int)(dword_30B84 + dword_30B88 * *(_DWORD *)(v10 + 1348));
  writel_relaxed_0(0, (unsigned int *)(v198 + v199));
  readl_relaxed_0((unsigned int *)(v198 + v199));
  if ( *(int *)(v183 + 32) >= 1 )
  {
    v200 = 0;
    do
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: sm seq val 0x%x\n",
        "msm_pcie_cesta_load_sm_seq",
        *(_DWORD *)(*(_QWORD *)(v183 + 8) + 4 * v200));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: sm seq val 0x%x\n",
        "msm_pcie_cesta_load_sm_seq",
        *(_DWORD *)(*(_QWORD *)(v183 + 8) + 4 * v200));
      v201 = *(_QWORD *)(v10 + 3128);
      v202 = (4 * v200) & 0xFFFFFFFCLL;
      writel_relaxed_0(*(_DWORD *)(*(_QWORD *)(v183 + 8) + 4 * v200), (unsigned int *)(v201 + v202));
      readl_relaxed_0((unsigned int *)(v201 + v202));
      ++v200;
    }
    while ( v200 < *(int *)(v183 + 32) );
  }
  if ( *(int *)(v183 + 36) >= 1 )
  {
    v203 = 0;
    v204 = 0;
    do
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "DBG1:%s: branch seq val 0x%x\n",
        "msm_pcie_cesta_load_sm_seq",
        *(_DWORD *)(*(_QWORD *)(v183 + 16) + 4 * v204));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: branch seq val 0x%x\n",
        "msm_pcie_cesta_load_sm_seq",
        *(_DWORD *)(*(_QWORD *)(v183 + 16) + 4 * v204));
      v205 = *(_QWORD *)(v10 + 3128);
      v206 = (unsigned int)(v203 + *(_DWORD *)v183);
      writel_relaxed_0(*(_DWORD *)(*(_QWORD *)(v183 + 16) + 4 * v204), (unsigned int *)(v205 + v206));
      readl_relaxed_0((unsigned int *)(v205 + v206));
      ++v204;
      v203 += 4;
    }
    while ( v204 < *(int *)(v183 + 36) );
  }
  v207 = *(_QWORD *)(v10 + 3128);
  v208 = *(unsigned int *)(v183 + 4);
  v209 = readl_relaxed_0((unsigned int *)(v207 + v208));
  writel_relaxed_0(v209 | 1, (unsigned int *)(v207 + v208));
  readl_relaxed_0((unsigned int *)(v207 + v208));
  device = crm_get_device("pcie_crm");
  *(_QWORD *)(v10 + 3120) = device;
  if ( device >= 0xFFFFFFFFFFFFF001LL )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "ERR:%s: PCIe: RC%d: fail to get crm_dev\n",
      "msm_pcie_cesta_init",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: fail to get crm_dev\n",
      "msm_pcie_cesta_init",
      *(_DWORD *)(v10 + 1348));
    printk(&unk_2936C);
    if ( *(_QWORD *)(v10 + 3128) )
      goto LABEL_431;
    goto LABEL_427;
  }
  v211 = *(_DWORD *)(v10 + 992);
  *(_QWORD *)(v10 + 1864) = 0xFFFFFFFE00000LL;
  dword_4BC = v211 + 1;
  dword_4C0 = v211 + 1;
  dword_4C8 = v211 + 1;
  *(_QWORD *)(v10 + 1872) = v10 + 1872;
  *(_QWORD *)(v10 + 1880) = v257;
  *(_QWORD *)(v10 + 1888) = msm_pcie_drv_cesta_connect_worker;
  if ( !*(_QWORD *)(v10 + 3128) )
    goto LABEL_427;
LABEL_431:
  v213 = devm_pinctrl_get(v2 + 16);
  *(_QWORD *)(v10 + 1728) = v213;
  if ( v213 && v213 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_BYTE *)(v10 + 1720) = 1;
    goto LABEL_434;
  }
  ipc_log_string(
    *(_QWORD *)(v10 + 1704),
    "ERR:%s: PCIe: RC%d failed to get pinctrl\n",
    "msm_pcie_get_pinctrl",
    *(_DWORD *)(v10 + 1348));
  ipc_log_string(
    *(_QWORD *)(v10 + 1696),
    "%s: PCIe: RC%d failed to get pinctrl\n",
    "msm_pcie_get_pinctrl",
    *(_DWORD *)(v10 + 1348));
  printk(&unk_2D221);
  if ( (*(_BYTE *)(v10 + 1720) & 1) != 0 )
  {
LABEL_434:
    v214 = ((__int64 (*)(void))pinctrl_lookup_state)();
    *(_QWORD *)(v10 + 1736) = v214;
    if ( v214 >= 0xFFFFFFFFFFFFF001LL )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "ERR:%s: PCIe: RC%d could not get pinctrl default state\n",
        "msm_pcie_get_pinctrl",
        *(_DWORD *)(v10 + 1348));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: PCIe: RC%d could not get pinctrl default state\n",
        "msm_pcie_get_pinctrl",
        *(_DWORD *)(v10 + 1348));
      printk(&unk_2311A);
      *(_QWORD *)(v10 + 1736) = 0;
    }
    v215 = pinctrl_lookup_state(*(_QWORD *)(v10 + 1728), "sleep");
    *(_QWORD *)(v10 + 1744) = v215;
    if ( v215 >= 0xFFFFFFFFFFFFF001LL )
    {
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "ERR:%s: PCIe: RC%d could not get pinctrl sleep state\n",
        "msm_pcie_get_pinctrl",
        *(_DWORD *)(v10 + 1348));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: PCIe: RC%d could not get pinctrl sleep state\n",
        "msm_pcie_get_pinctrl",
        *(_DWORD *)(v10 + 1348));
      printk(&unk_261E7);
      *(_QWORD *)(v10 + 1744) = 0;
    }
  }
  ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: RC%d\n", "msm_pcie_gpio_init", *(_DWORD *)(v10 + 1348));
  ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: RC%d\n", "msm_pcie_gpio_init", *(_DWORD *)(v10 + 1348));
  v216 = *(unsigned int *)(v10 + 952);
  v217 = (_QWORD *)(v10 + 888);
  if ( (_DWORD)v216 )
  {
    v218 = 0;
    for ( k = 0; k < v216; ++k )
    {
      if ( v218 == 128 )
        goto LABEL_501;
      v223 = v10 + v218;
      v224 = *(unsigned int *)(v10 + v218 + 264);
      if ( (_DWORD)v224 )
      {
        v225 = gpio_request(v224, *(_QWORD *)(v223 + 256));
        if ( v225 )
        {
          v222 = v225;
          ipc_log_string(
            *(_QWORD *)(v10 + 1704),
            "ERR:%s: PCIe: RC%d can't get gpio %s; %d\n",
            "msm_pcie_gpio_init",
            *(_DWORD *)(v10 + 1348),
            *(const char **)(v10 + v218 + 256),
            v225);
          ipc_log_string(
            *(_QWORD *)(v10 + 1696),
            "%s: PCIe: RC%d can't get gpio %s; %d\n",
            "msm_pcie_gpio_init",
            *(_DWORD *)(v10 + 1348),
            *(const char **)(v10 + v218 + 256),
            v222);
          printk(&unk_2E327);
LABEL_495:
          if ( v218 )
          {
            gpio_free(*(unsigned int *)(v10 + v218 + 232));
            if ( v218 != 32 )
            {
              gpio_free(*(unsigned int *)(v10 + v218 + 200));
              if ( v218 != 64 )
              {
                gpio_free(*(unsigned int *)(v10 + v218 + 168));
                if ( v218 != 96 )
                  gpio_free(*(unsigned int *)(v10 + v218 + 136));
              }
            }
          }
          v253 = *(_QWORD *)(v10 + 3096);
          *(_QWORD *)(v10 + 872) = 0;
          *(_QWORD *)(v10 + 3128) = 0;
          *v217 = 0;
          *(_QWORD *)(v10 + 896) = 0;
          *(_QWORD *)(v10 + 904) = 0;
          *(_QWORD *)(v10 + 912) = 0;
          *(_QWORD *)(v10 + 920) = 0;
          *(_QWORD *)(v10 + 928) = 0;
          kfree(v253);
          kfree(*(_QWORD *)(v10 + 3112));
          kfree(*(_QWORD *)(v10 + 3080));
          *(_QWORD *)(v10 + 3096) = 0;
          LODWORD(optional) = v222;
          *(_QWORD *)(v10 + 3112) = 0;
          *(_QWORD *)(v10 + 3080) = 0;
          goto LABEL_406;
        }
        v226 = *(unsigned int *)(v223 + 264);
        if ( *(_BYTE *)(v10 + v218 + 268) == 1 )
        {
          v220 = *(_DWORD *)(v10 + v218 + 276);
          v221 = gpio_to_desc(v226);
          v222 = gpiod_direction_output_raw(v221, v220);
          if ( v222 )
            goto LABEL_448;
        }
        else
        {
          v227 = gpio_to_desc(v226);
          v222 = gpiod_direction_input(v227);
          if ( v222 )
          {
LABEL_448:
            ipc_log_string(
              *(_QWORD *)(v10 + 1704),
              "ERR:%s: PCIe: RC%d can't set direction for GPIO %s:%d\n",
              "msm_pcie_gpio_init",
              *(_DWORD *)(v10 + 1348),
              *(const char **)(v10 + v218 + 256),
              v222);
            ipc_log_string(
              *(_QWORD *)(v10 + 1696),
              "%s: PCIe: RC%d can't set direction for GPIO %s:%d\n",
              "msm_pcie_gpio_init",
              *(_DWORD *)(v10 + 1348),
              *(const char **)(v10 + v218 + 256),
              v222);
            printk(&unk_23150);
            gpio_free(*(unsigned int *)(v10 + v218 + 264));
            goto LABEL_495;
          }
        }
        v216 = *(unsigned int *)(v10 + 952);
      }
      v218 += 32;
    }
  }
  v228 = *(const char **)v10;
  ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: RC%d\n", "msm_pcie_irq_init", *(_DWORD *)(v10 + 1348));
  ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: RC%d\n", "msm_pcie_irq_init", *(_DWORD *)(v10 + 1348));
  v229 = *((_QWORD *)v228 + 16);
  if ( !v229 )
    v229 = *((_QWORD *)v228 + 2);
  v230 = wakeup_source_register(v228 + 16, v229);
  *(_QWORD *)(v10 + 1200) = v230;
  if ( !v230 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "ERR:%s: PCIe: RC%d: failed to register wakeup source\n",
      "msm_pcie_irq_init",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: failed to register wakeup source\n",
      "msm_pcie_irq_init",
      *(_DWORD *)(v10 + 1348));
    printk(&unk_26251);
    v240 = -12;
LABEL_480:
    v246 = *(_QWORD *)(v10 + 3096);
    *(_QWORD *)(v10 + 872) = 0;
    *(_QWORD *)(v10 + 3128) = 0;
    *v217 = 0;
    *(_QWORD *)(v10 + 896) = 0;
    *(_QWORD *)(v10 + 904) = 0;
    *(_QWORD *)(v10 + 912) = 0;
    *(_QWORD *)(v10 + 920) = 0;
    *(_QWORD *)(v10 + 928) = 0;
    kfree(v246);
    kfree(*(_QWORD *)(v10 + 3112));
    kfree(*(_QWORD *)(v10 + 3080));
    *(_QWORD *)(v10 + 3096) = 0;
    *(_QWORD *)(v10 + 3112) = 0;
    *(_QWORD *)(v10 + 3080) = 0;
    ((void (__fastcall *)(__int64))msm_pcie_gpio_deinit)(v10);
    LODWORD(optional) = v240;
    goto LABEL_406;
  }
  v231 = *(unsigned int *)(v10 + 640);
  if ( (_DWORD)v231 )
  {
    v232 = devm_request_threaded_irq(
             v228 + 16,
             v231,
             handle_global_irq,
             handle_aer_irq,
             8193,
             *(_QWORD *)(v10 + 632),
             v10);
    if ( v232 )
    {
      v240 = v232;
      ipc_log_string(
        *(_QWORD *)(v10 + 1704),
        "ERR:%s: PCIe: RC%d: Unable to request global_int interrupt: %d\n",
        "msm_pcie_irq_init",
        *(_DWORD *)(v10 + 1348),
        *(_DWORD *)(v10 + 640));
      ipc_log_string(
        *(_QWORD *)(v10 + 1696),
        "%s: PCIe: RC%d: Unable to request global_int interrupt: %d\n",
        "msm_pcie_irq_init",
        *(_DWORD *)(v10 + 1348),
        *(_DWORD *)(v10 + 640));
      printk(&unk_26285);
      goto LABEL_480;
    }
  }
  v233 = *(unsigned int *)(v10 + 944);
  if ( !(_DWORD)v233 )
    goto LABEL_457;
  v234 = devm_request_threaded_irq(v228 + 16, v233, handle_wake_irq, 0, 2, "msm_pcie_wake", v10);
  if ( v234 )
  {
    v240 = v234;
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "ERR:%s: PCIe: RC%d: Unable to request wake interrupt\n",
      "msm_pcie_irq_init",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: Unable to request wake interrupt\n",
      "msm_pcie_irq_init",
      *(_DWORD *)(v10 + 1348));
    v245 = &unk_246D0;
LABEL_479:
    printk(v245);
    goto LABEL_480;
  }
  *(_QWORD *)(v10 + 1360) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 1368) = v10 + 1368;
  *(_QWORD *)(v10 + 1376) = v10 + 1368;
  *(_QWORD *)(v10 + 1392) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 1384) = handle_wake_func;
  *(_QWORD *)(v10 + 1400) = v10 + 1400;
  *(_QWORD *)(v10 + 1408) = v10 + 1400;
  v235 = *(unsigned int *)(v10 + 944);
  *(_QWORD *)(v10 + 1416) = handle_sbr_func;
  v236 = irq_set_irq_wake(v235, 1);
  if ( v236 )
  {
    v240 = v236;
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "ERR:%s: PCIe: RC%d: Unable to enable wake interrupt\n",
      "msm_pcie_irq_init",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d: Unable to enable wake interrupt\n",
      "msm_pcie_irq_init",
      *(_DWORD *)(v10 + 1348));
    v245 = &unk_2F2ED;
    goto LABEL_479;
  }
LABEL_457:
  v237 = *(_QWORD *)v10 + 16LL;
  *(_QWORD *)(v10 + 2000) = 0;
  *(_QWORD *)(v10 + 2008) = 0x80000007FLL;
  *(_QWORD *)(v10 + 2016) = v10 + 2024;
  if ( (unsigned int)sysfs_create_group(v237, &msm_pcie_debug_attr_group) )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1712),
      "DBG_FS:%s: RC%d: failed to create sysfs debug group\n",
      "msm_pcie_sysfs_init",
      *(_DWORD *)(v10 + 1348));
    printk(&unk_29CA0);
  }
  if ( (unsigned int)sysfs_create_group(*(_QWORD *)v10 + 16LL, &msm_aer_stats_attr_group) )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1712),
      "DBG_FS:%s: RC%d: failed to create sysfs debug group\n",
      "msm_pcie_sysfs_init",
      *(_DWORD *)(v10 + 1348));
    printk(&unk_29CA0);
  }
  v238 = *(_BYTE *)(v10 + 1332);
  *(_BYTE *)(v10 + 1356) = 1;
  if ( (v238 & 1) != 0 )
  {
    ipc_log_string(
      *(_QWORD *)(v10 + 1704),
      "DBG1:%s: PCIe: RC%d will be enumerated by client or endpoint.\n",
      "msm_pcie_probe",
      *(_DWORD *)(v10 + 1348));
    ipc_log_string(
      *(_QWORD *)(v10 + 1696),
      "%s: PCIe: RC%d will be enumerated by client or endpoint.\n",
      "msm_pcie_probe",
      *(_DWORD *)(v10 + 1348));
  }
  else
  {
    v243 = msm_pcie_enumerate(v262);
    if ( v243 )
      v244 = &unk_27978;
    else
      v244 = &unk_269E5;
    v247 = v243 == 0;
    if ( v243 )
      v248 = "%s: PCIe: RC%d is not enabled during bootup; it will be enumerated upon client request.\n";
    else
      v248 = "%s: RC%d is enabled in bootup\n";
    v249 = *(_QWORD *)(v10 + 1704);
    v250 = *(unsigned int *)(v10 + 1348);
    if ( v247 )
      ipc_log_string(v249, "ERR:%s: RC%d is enabled in bootup\n", "msm_pcie_probe", v250);
    else
      ipc_log_string(
        v249,
        "ERR:%s: PCIe: RC%d is not enabled during bootup; it will be enumerated upon client request.\n",
        "msm_pcie_probe",
        v250);
    ipc_log_string(*(_QWORD *)(v10 + 1696), v248, "msm_pcie_probe", *(unsigned int *)(v10 + 1348));
    printk(v244);
    v251 = *(const char **)(v2 + 128);
    if ( !v251 )
      v251 = *(const char **)(v2 + 16);
    ipc_log_string(*(_QWORD *)(v10 + 1704), "DBG1:%s: PCIe probed %s\n", "msm_pcie_probe", v251);
    v252 = *(const char **)(v2 + 128);
    if ( !v252 )
      v252 = *(const char **)(v2 + 16);
    ipc_log_string(*(_QWORD *)(v10 + 1696), "%s: PCIe probed %s\n", "msm_pcie_probe", v252);
  }
  v126 = 0;
LABEL_464:
  mutex_unlock(&unk_30CD8);
  _ReadStatusReg(SP_EL0);
  return v126;
}
