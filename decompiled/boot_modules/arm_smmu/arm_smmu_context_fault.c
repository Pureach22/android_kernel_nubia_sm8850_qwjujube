__int64 __fastcall arm_smmu_context_fault(__int64 a1, __int64 **a2)
{
  __int64 *v3; // x19
  unsigned int v4; // w20
  __int64 v5; // x22
  __int64 (__fastcall **v6)(__int64 *, __int64, __int64); // x8
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64 *, __int64, __int64); // x8
  __int64 i; // x0
  unsigned int v10; // w22
  __int64 (__fastcall **v11)(__int64 *, __int64, __int64); // x8
  __int64 v12; // x1
  __int64 (__fastcall *v13)(__int64 *, __int64, __int64); // x8
  unsigned int v14; // w0
  __int64 (__fastcall **v15)(__int64 *, __int64, __int64); // x8
  unsigned int v16; // w23
  __int64 v17; // x1
  __int64 (__fastcall *v18)(__int64 *, __int64, __int64); // x8
  unsigned int v19; // w0
  __int64 v20; // x8
  unsigned int v21; // w24
  __int64 v22; // x1
  __int64 (__fastcall *v23)(__int64 *, __int64, __int64); // x8
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x1
  _DWORD *v27; // x8
  unsigned int v28; // w20
  unsigned int v29; // w8
  unsigned int v36; // w10
  __int64 v37; // x1
  __int64 v38; // x25
  __int64 (__fastcall **v39)(__int64 *, __int64, __int64); // x8
  int v40; // w23
  __int64 (__fastcall *v41)(__int64 *, __int64, __int64); // x8
  int v42; // w0
  __int64 (__fastcall **v43)(__int64 *, __int64, __int64); // x8
  int v44; // w26
  __int64 v45; // x1
  __int64 (__fastcall *v46)(__int64 *, __int64, __int64); // x8
  int v47; // w0
  __int64 (__fastcall **v48)(__int64 *, __int64, __int64); // x8
  int v49; // w27
  __int64 v50; // x1
  __int64 (__fastcall *v51)(__int64 *, __int64, __int64); // x8
  unsigned int v52; // w0
  __int64 v53; // x8
  __int64 v54; // x1
  __int64 (__fastcall *v55)(__int64 *, __int64, __int64); // x8
  __int64 v56; // x0
  _DWORD **v57; // x8
  __int64 v58; // x28
  __int64 v59; // x23
  _DWORD *v60; // x8
  unsigned __int16 v61; // w0
  const char **v62; // x8
  unsigned __int16 v63; // w24
  const char *v64; // x2
  __int64 v65; // x8
  __int64 v66; // x28
  __int64 v67; // x1
  __int64 (__fastcall *v68)(__int64 *, __int64, __int64); // x8
  const void *v69; // x0
  const char *v70; // x8
  const char *v71; // x10
  const char *v72; // x11
  const char *v73; // x3
  const char *v74; // x4
  const char *v75; // x12
  const char *v76; // x5
  const char *v77; // x6
  const char *v78; // x10
  const char *v79; // x7
  const char *v80; // x8
  const char *v81; // x9
  __int64 v82; // x26
  __int64 (__fastcall **v83)(__int64 *, __int64, __int64); // x8
  __int64 v84; // x1
  __int64 (__fastcall *v85)(__int64 *, __int64, __int64); // x8
  unsigned int v86; // w0
  unsigned int (__fastcall **v87)(__int64 *, __int64, __int64); // x8
  __int64 v88; // x26
  __int64 v89; // x1
  unsigned int (__fastcall *v90)(__int64 *, __int64, __int64); // x8
  __int64 v91; // x2
  __int64 (__fastcall *v92)(__int64 *, __int64, __int64); // x8
  const void *v93; // x0
  __int64 v94; // x8
  __int64 v95; // x1
  __int64 (__fastcall *v96)(__int64 *, __int64, __int64); // x8
  __int64 v97; // x0
  _DWORD **v98; // x8
  __int64 v99; // x26
  __int64 v100; // x1
  _DWORD *v101; // x8
  int v102; // w0
  __int64 (__fastcall **v103)(__int64 *, __int64, __int64); // x8
  unsigned int v104; // w27
  int v105; // w28
  __int64 v106; // x1
  __int64 (__fastcall *v107)(__int64 *, __int64, __int64); // x8
  int v108; // w0
  _DWORD **v109; // x8
  __int64 v110; // x26
  _DWORD *v111; // x8
  int v112; // w0
  __int64 (__fastcall **v113)(__int64 *, __int64, __int64); // x8
  __int64 v114; // x26
  __int64 v115; // x1
  __int64 (__fastcall *v116)(__int64 *, __int64, __int64); // x8
  int v117; // w0
  __int64 (__fastcall **v118)(__int64 *, __int64, __int64); // x8
  int v119; // w27
  __int64 v120; // x1
  __int64 (__fastcall *v121)(__int64 *, __int64, __int64); // x8
  int v122; // w0
  int v123; // w9
  __int64 (__fastcall **v124)(__int64 *, __int64, __int64); // x8
  __int64 v125; // x1
  __int64 (__fastcall *v126)(__int64 *, __int64, __int64); // x8
  unsigned int v127; // w0
  __int64 v128; // x8
  unsigned int v129; // w24
  __int64 v130; // x1
  __int64 (__fastcall *v131)(__int64 *, __int64, __int64); // x8
  __int64 v132; // x0
  _DWORD **v133; // x8
  __int64 v134; // x25
  _DWORD *v135; // x8
  unsigned __int16 v136; // w0
  unsigned __int16 v137; // w23
  int v138; // w24
  __int64 v139; // x23
  _BOOL4 v140; // w25
  void (__fastcall *v141)(_QWORD); // x8
  __int64 v142; // x24
  __int64 *v143; // x2
  __int64 v144; // x8
  __int64 v145; // x1
  __int64 (__fastcall *v146)(__int64 *, __int64, __int64, __int64); // x8
  __int64 v147; // x21
  __int64 v149; // x0
  int v150; // [xsp+30h] [xbp-40h]
  unsigned int v151; // [xsp+34h] [xbp-3Ch]
  __int64 v152; // [xsp+38h] [xbp-38h] BYREF
  int v153; // [xsp+40h] [xbp-30h]
  int v154; // [xsp+44h] [xbp-2Ch]
  __int64 v155; // [xsp+48h] [xbp-28h] BYREF
  __int64 v156; // [xsp+50h] [xbp-20h] BYREF
  __int64 v157; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v158[2]; // [xsp+60h] [xbp-10h] BYREF

  v158[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = *((unsigned __int8 *)a2 + 48);
  v5 = **a2;
  if ( (*(_WORD *)(v5 + 488) & 7) == 0 && (_pm_runtime_resume(**a2, 4) & 0x80000000) != 0 )
  {
    v29 = *(_DWORD *)(v5 + 480);
    while ( 1 )
    {
      if ( !v29 )
      {
        v28 = 0;
        goto LABEL_162;
      }
      _X12 = (unsigned int *)(v5 + 480);
      __asm { PRFM            #0x11, [X12] }
      do
      {
        v36 = __ldxr(_X12);
        if ( v36 != v29 )
          goto LABEL_30;
      }
      while ( __stlxr(v29 - 1, _X12) );
      __dmb(0xBu);
LABEL_30:
      v28 = 0;
      _ZF = v36 == v29;
      v29 = v36;
      if ( _ZF )
        goto LABEL_162;
    }
  }
  v6 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v7 = *((_DWORD *)v3 + 6) + v4;
  if ( v6 )
  {
    v8 = *v6;
    if ( v8 )
      goto LABEL_142;
  }
  for ( i = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v7 << *((_DWORD *)v3 + 7)) + 88)); ; i = v8(v3, v7, 88) )
  {
    v10 = i;
    if ( (i & 0xC00001FE) == 0 )
    {
      v28 = 0;
      goto LABEL_160;
    }
    if ( (i & 0x80) != 0 && (*((_DWORD *)v3 + 9) & 1) != 0 )
    {
      v149 = dev_err(*v3, "Took an address size fault.  Refusing to recover.\n");
      __break(0x800u);
      return arm_smmu_context_fault_irq(v149, 0x805F000000000000LL);
    }
    v11 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
    v12 = *((_DWORD *)v3 + 6) + v4;
    if ( v11 && (v13 = *v11) != nullptr )
    {
      if ( *((_DWORD *)v13 - 1) != 616069899 )
        __break(0x8228u);
      v14 = v13(v3, v12, 88);
    }
    else
    {
      v14 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v12 << *((_DWORD *)v3 + 7)) + 88));
    }
    v15 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
    v16 = v14;
    v17 = *((_DWORD *)v3 + 6) + v4;
    if ( v15 && (v18 = *v15) != nullptr )
    {
      if ( *((_DWORD *)v18 - 1) != 616069899 )
        __break(0x8228u);
      v19 = v18(v3, v17, 104);
    }
    else
    {
      v19 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v17 << *((_DWORD *)v3 + 7)) + 104));
    }
    v20 = v3[6];
    v21 = v19;
    v22 = *((_DWORD *)v3 + 6) + v4;
    if ( v20 && (v23 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v20 + 16)) != nullptr )
    {
      if ( *((_DWORD *)v23 - 1) != 1426685181 )
        __break(0x8228u);
      v24 = v23(v3, v22, 96);
    }
    else
    {
      v24 = readq_relaxed((_QWORD *)(v3[1] + (int)((_DWORD)v22 << *((_DWORD *)v3 + 7)) + 96));
    }
    i = report_iommu_fault(a2 + 23, *v3, v24, v16 & 0x18 | (4 * ((v16 >> 1) & 1)) | (v16 >> 25) & 0x20 | (v21 >> 4) & 1);
    if ( (_DWORD)i == -16 )
      goto LABEL_25;
    if ( (_DWORD)i != -38 )
      goto LABEL_22;
    if ( (unsigned int)__ratelimit(&arm_smmu_context_fault__rs, "arm_smmu_context_fault") )
      break;
    v8 = (__int64 (__fastcall *)(__int64 *, __int64, __int64))*((unsigned __int8 *)a2 + 136);
    if ( ((unsigned __int8)v8 & 1) != 0 )
      goto LABEL_22;
LABEL_141:
    __break(0x800u);
LABEL_142:
    if ( *((_DWORD *)v8 - 1) != 616069899 )
      __break(0x8228u);
  }
  v37 = *((_DWORD *)v3 + 6) + v4;
  v38 = *(_QWORD *)(v3[10] + 48LL * v4 + 40);
  v39 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v40 = *(_DWORD *)(v38 + 12);
  if ( v39 && (v41 = *v39) != nullptr )
  {
    if ( *((_DWORD *)v41 - 1) != 616069899 )
      __break(0x8228u);
    v42 = v41(v3, v37, 88);
  }
  else
  {
    v42 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v37 << *((_DWORD *)v3 + 7)) + 88));
  }
  v43 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v44 = v42;
  v45 = *((_DWORD *)v3 + 6) + v4;
  if ( v43 && (v46 = *v43) != nullptr )
  {
    if ( *((_DWORD *)v46 - 1) != 616069899 )
      __break(0x8228u);
    v47 = v46(v3, v45, 104);
  }
  else
  {
    v47 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v45 << *((_DWORD *)v3 + 7)) + 104));
  }
  v48 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v49 = v47;
  v50 = *((_DWORD *)v3 + 6) + v4;
  if ( v48 && (v51 = *v48) != nullptr )
  {
    if ( *((_DWORD *)v51 - 1) != 616069899 )
      __break(0x8228u);
    v52 = v51(v3, v50, 108);
  }
  else
  {
    v52 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v50 << *((_DWORD *)v3 + 7)) + 108));
  }
  v53 = v3[6];
  v150 = v40;
  v151 = v52;
  v54 = *((_DWORD *)v3 + 6) + v4;
  if ( v53 && (v55 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v53 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v55 - 1) != 1426685181 )
      __break(0x8228u);
    v56 = v55(v3, v54, 96);
  }
  else
  {
    v56 = readq_relaxed((_QWORD *)(v3[1] + (int)((_DWORD)v54 << *((_DWORD *)v3 + 7)) + 96));
  }
  v57 = (_DWORD **)v3[6];
  v58 = v56;
  v59 = (4LL * (unsigned __int8)v4) | 0x400;
  if ( v57 && (v60 = *v57) != nullptr )
  {
    if ( *(v60 - 1) != 616069899 )
      __break(0x8228u);
    v61 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v60)(v3, 1, (unsigned int)v59);
  }
  else
  {
    v61 = readl_relaxed_0((unsigned int *)(v3[1] + (1 << *((_DWORD *)v3 + 7)) + v59));
  }
  v62 = (const char **)a2[1];
  v63 = v61;
  v64 = v62[14];
  if ( !v64 )
    v64 = *v62;
  dev_err(*v3, "Unhandled arm-smmu context fault from %s!\n", v64);
  dev_err(*v3, "FAR    = 0x%016lx\n", v58);
  v65 = v3[6];
  v66 = *v3;
  v67 = *((_DWORD *)v3 + 6) + v4;
  if ( v65 && (v68 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v65 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v68 - 1) != 1426685181 )
      __break(0x8228u);
    v69 = (const void *)v68(v3, v67, 80);
  }
  else
  {
    v69 = (const void *)readq_relaxed((_QWORD *)(v3[1] + (int)((_DWORD)v67 << *((_DWORD *)v3 + 7)) + 80));
  }
  dev_err(v66, "PAR    = 0x%pK\n", v69);
  v70 = "TF W ";
  if ( (v49 & 0x10) == 0 )
    v70 = "TF R ";
  v71 = "PF W ";
  v72 = (const char *)&unk_17C28;
  if ( (v49 & 0x10) == 0 )
    v71 = "PF R ";
  if ( (v44 & 2) != 0 )
    v73 = v70;
  else
    v73 = (const char *)&unk_17C28;
  if ( (v44 & 4) != 0 )
    v74 = "AFF ";
  else
    v74 = (const char *)&unk_17C28;
  v75 = "UUT ";
  if ( (v44 & 8) != 0 )
    v76 = v71;
  else
    v76 = (const char *)&unk_17C28;
  if ( (v44 & 0x10) != 0 )
    v77 = "EF ";
  else
    v77 = (const char *)&unk_17C28;
  v78 = "ASF ";
  if ( (v44 & 0x20) != 0 )
    v79 = "TLBMCF ";
  else
    v79 = (const char *)&unk_17C28;
  v80 = "TLBLKF ";
  if ( (v44 & 0x40) == 0 )
    v80 = (const char *)&unk_17C28;
  if ( (v44 & 0x80) == 0 )
    v78 = (const char *)&unk_17C28;
  if ( (v44 & 0x100) == 0 )
    v75 = (const char *)&unk_17C28;
  if ( (v44 & 0x40000000) != 0 )
    v81 = "SS ";
  else
    v81 = (const char *)&unk_17C28;
  if ( v44 < 0 )
    v72 = "MULTI ";
  dev_err(
    *v3,
    "FSR    = 0x%08x [%s%s%s%s%s%s%s%s%s%s]\n",
    (unsigned int)v44,
    v73,
    v74,
    v76,
    v77,
    v79,
    v80,
    v78,
    v75,
    v81,
    v72);
  dev_err(*v3, "FSYNR0    = 0x%x\n", v49);
  dev_err(*v3, "FSYNR1    = 0x%x\n", v151);
  dev_err(*v3, "context bank#    = 0x%x\n", v4);
  v82 = *v3;
  v83 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v84 = *((_DWORD *)v3 + 6) + v4;
  if ( *(_DWORD *)(v38 + 16) == 3 )
  {
    if ( v83 && (v85 = *v83) != nullptr )
    {
      if ( *((_DWORD *)v85 - 1) != 616069899 )
        __break(0x8228u);
      v86 = v85(v3, v84, 32);
    }
    else
    {
      v86 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v84 << *((_DWORD *)v3 + 7)) + 32));
    }
    dev_err(v82, "TTBR0  = 0x%pK\n", (const void *)v86);
    v87 = (unsigned int (__fastcall **)(__int64 *, __int64, __int64))v3[6];
    v88 = *v3;
    v89 = *((_DWORD *)v3 + 6) + v4;
    if ( v87 && (v90 = *v87) != nullptr )
    {
      if ( *((_DWORD *)v90 - 1) != 616069899 )
        __break(0x8228u);
      v91 = v90(v3, v89, 40);
    }
    else
    {
      v91 = (unsigned int)readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v89 << *((_DWORD *)v3 + 7)) + 40));
    }
LABEL_101:
    dev_err(v88, "TTBR1  = 0x%pK\n", (const void *)v91);
    goto LABEL_102;
  }
  if ( v83 && (v92 = v83[2]) != nullptr )
  {
    if ( *((_DWORD *)v92 - 1) != 1426685181 )
      __break(0x8228u);
    v93 = (const void *)v92(v3, v84, 32);
  }
  else
  {
    v93 = (const void *)readq_relaxed((_QWORD *)(v3[1] + (int)((_DWORD)v84 << *((_DWORD *)v3 + 7)) + 32));
  }
  dev_err(v82, "TTBR0  = 0x%pK\n", v93);
  if ( v150 )
  {
    v94 = v3[6];
    v88 = *v3;
    v95 = *((_DWORD *)v3 + 6) + v4;
    if ( v94 && (v96 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v94 + 16)) != nullptr )
    {
      if ( *((_DWORD *)v96 - 1) != 1426685181 )
        __break(0x8228u);
      v97 = v96(v3, v95, 40);
    }
    else
    {
      v97 = readq_relaxed((_QWORD *)(v3[1] + (int)((_DWORD)v95 << *((_DWORD *)v3 + 7)) + 40));
    }
    v91 = v97;
    goto LABEL_101;
  }
LABEL_102:
  v98 = (_DWORD **)v3[6];
  v99 = *v3;
  v100 = *((_DWORD *)v3 + 6) + v4;
  if ( v98 && (v101 = *v98) != nullptr )
  {
    if ( *(v101 - 1) != 616069899 )
      __break(0x8228u);
    v102 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v101)(v3, v100, 0);
  }
  else
  {
    v102 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v100 << *((_DWORD *)v3 + 7))));
  }
  v103 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v104 = 4 * v4;
  v105 = v102;
  v106 = *((_DWORD *)v3 + 6) + v4;
  if ( v103 && (v107 = *v103) != nullptr )
  {
    if ( *((_DWORD *)v107 - 1) != 616069899 )
      __break(0x8228u);
    v108 = v107(v3, v106, 4);
  }
  else
  {
    v108 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v106 << *((_DWORD *)v3 + 7)) + 4));
  }
  dev_err(v99, "SCTLR  = 0x%08x ACTLR  = 0x%08x\n", v105, v108);
  v109 = (_DWORD **)v3[6];
  v110 = *v3;
  if ( v109 && (v111 = *v109) != nullptr )
  {
    if ( *(v111 - 1) != 616069899 )
      __break(0x8228u);
    v112 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v111)(v3, 1, v104);
  }
  else
  {
    v112 = readl_relaxed_0((unsigned int *)(v3[1] + (1 << *((_DWORD *)v3 + 7)) + v104));
  }
  dev_err(v110, "CBAR  = 0x%08x\n", v112);
  v113 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v114 = *v3;
  v115 = *((_DWORD *)v3 + 6) + v4;
  if ( v113 && (v116 = *v113) != nullptr )
  {
    if ( *((_DWORD *)v116 - 1) != 616069899 )
      __break(0x8228u);
    v117 = v116(v3, v115, 56);
  }
  else
  {
    v117 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v115 << *((_DWORD *)v3 + 7)) + 56));
  }
  v118 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v119 = v117;
  v120 = *((_DWORD *)v3 + 6) + v4;
  if ( v118 && (v121 = *v118) != nullptr )
  {
    if ( *((_DWORD *)v121 - 1) != 616069899 )
      __break(0x8228u);
    v122 = v121(v3, v120, 60);
  }
  else
  {
    v122 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v120 << *((_DWORD *)v3 + 7)) + 60));
  }
  dev_err(v114, "MAIR0   = 0x%08x MAIR1   = 0x%08x\n", v119, v122);
  dev_err(*v3, "SID = 0x%x\n", v63);
  dev_err(
    *v3,
    "Client info: BID=0x%lx, PID=0x%lx, MID=0x%lx\n",
    (unsigned __int16)v151 >> 13,
    ((unsigned __int64)v151 >> 8) & 0x1F,
    (unsigned __int8)v151);
  v123 = *((_DWORD *)v3 + 6);
  v124 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))v3[6];
  v155 = 0;
  v156 = 0;
  v125 = v123 + v4;
  if ( v124 && (v126 = *v124) != nullptr )
  {
    if ( *((_DWORD *)v126 - 1) != 616069899 )
      __break(0x8228u);
    v127 = v126(v3, v125, 104);
  }
  else
  {
    v127 = readl_relaxed_0((unsigned int *)(v3[1] + (int)((_DWORD)v125 << *((_DWORD *)v3 + 7)) + 104));
  }
  v128 = v3[6];
  v129 = v127;
  v130 = *((_DWORD *)v3 + 6) + v4;
  if ( v128 && (v131 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v128 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v131 - 1) != 1426685181 )
      __break(0x8228u);
    v132 = v131(v3, v130, 96);
  }
  else
  {
    v132 = readq_relaxed((_QWORD *)(v3[1] + (int)((_DWORD)v130 << *((_DWORD *)v3 + 7)) + 96));
  }
  v133 = (_DWORD **)v3[6];
  v134 = v132;
  if ( v133 && (v135 = *v133) != nullptr )
  {
    if ( *(v135 - 1) != 616069899 )
      __break(0x8228u);
    v136 = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v135)(v3, 1, (unsigned int)v59);
  }
  else
  {
    v136 = readl_relaxed_0((unsigned int *)(v3[1] + (1 << *((_DWORD *)v3 + 7)) + (unsigned int)v59));
  }
  v137 = v136;
  v158[0] = arm_smmu_iova_to_phys((__int64)(a2 + 23), v134);
  dev_err(*v3, "soft iova-to-phys=%pa\n", v158);
  v138 = (v129 >> 4) & 7;
  v152 = v134;
  v153 = v138;
  v154 = v137;
  v139 = arm_smmu_iova_to_phys_hard((__int64)(a2 + 23), (__int64)&v152);
  v157 = v139;
  if ( v139 )
  {
    v140 = 0;
  }
  else
  {
    v153 = 2;
    v156 = arm_smmu_iova_to_phys_hard((__int64)(a2 + 23), (__int64)&v152);
    v140 = v156 != 0;
  }
  v141 = (void (__fastcall *)(_QWORD))a2[24][4];
  if ( v141 )
  {
    if ( *((_DWORD *)v141 - 1) != -1056074712 )
      __break(0x8228u);
    v141(a2 + 23);
  }
  v153 = v138;
  v142 = arm_smmu_iova_to_phys_hard((__int64)(a2 + 23), (__int64)&v152);
  v155 = v142;
  if ( v140 )
  {
    dev_err(*v3, "ATOS results differed across access privileges...\nBefore: %pa After: %pa\n", &v157, &v156);
    v139 = v157;
  }
  if ( v139 != v142 )
  {
    dev_err(*v3, "ATOS results differed across TLBIALL...\nBefore: %pa After: %pa\n", &v157, &v155);
    v142 = v157;
  }
  if ( v142 )
    v143 = &v157;
  else
    v143 = &v155;
  dev_err(*v3, "hard iova-to-phys (ATOS)=%pa\n", v143);
  v8 = (__int64 (__fastcall *)(__int64 *, __int64, __int64))*((unsigned __int8 *)a2 + 136);
  if ( ((unsigned __int8)v8 & 1) == 0 )
    goto LABEL_141;
LABEL_22:
  v25 = v3[6];
  v26 = *((_DWORD *)v3 + 6) + v4;
  if ( v25 && (v27 = *(_DWORD **)(v25 + 8)) != nullptr )
  {
    if ( *(v27 - 1) != -1008624849 )
      __break(0x8228u);
    i = ((__int64 (__fastcall *)(__int64 *, __int64, __int64, _QWORD))v27)(v3, v26, 88, v10);
    __dsb(0xEu);
    if ( (v10 & 0x40000000) == 0 )
      goto LABEL_25;
  }
  else
  {
    i = writel_relaxed_0(v10, (unsigned int *)(v3[1] + (int)((_DWORD)v26 << *((_DWORD *)v3 + 7)) + 88));
    __dsb(0xEu);
    if ( (v10 & 0x40000000) == 0 )
    {
LABEL_25:
      v28 = 1;
      goto LABEL_160;
    }
  }
  v144 = v3[6];
  v145 = *((_DWORD *)v3 + 6) + v4;
  if ( v144 && (v146 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64, __int64))(v144 + 8)) != nullptr )
  {
    v28 = 1;
    if ( *((_DWORD *)v146 - 1) != -1008624849 )
      __break(0x8228u);
    i = v146(v3, v145, 8, 1);
  }
  else
  {
    v28 = 1;
    i = writel_relaxed_0(1u, (unsigned int *)(v3[1] + (int)((_DWORD)v145 << *((_DWORD *)v3 + 7)) + 8));
  }
LABEL_160:
  if ( (*(_WORD *)(*v3 + 488) & 7) == 0 )
  {
    v147 = *v3;
    *(_QWORD *)(v147 + 520) = ktime_get_mono_fast_ns(i);
    _pm_runtime_suspend(*v3, 13);
  }
LABEL_162:
  _ReadStatusReg(SP_EL0);
  return v28;
}
