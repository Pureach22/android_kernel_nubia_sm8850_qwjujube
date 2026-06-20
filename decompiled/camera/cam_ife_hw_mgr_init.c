__int64 __fastcall cam_ife_hw_mgr_init(_QWORD *a1, _DWORD *a2, int a3)
{
  int *v4; // x23
  int v5; // w19
  __int64 *v6; // x26
  __int64 v7; // x24
  __int64 v8; // x20
  void (__fastcall *v9)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v10; // x0
  void (__fastcall *v11)(__int64, __int64, __int64 *, __int64); // x8
  char v12; // w8
  int v13; // w8
  int v14; // w8
  int v15; // w10
  __int64 v16; // x8
  __int64 v17; // x11
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 *v20; // x24
  __int64 v21; // x23
  int v22; // w19
  __int64 v23; // x0
  unsigned int (__fastcall *v24)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v25; // x22
  int v26; // w19
  __int64 *v27; // x25
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 (__fastcall *v30)(__int64, __int64, __int64 *, __int64); // x8
  int v31; // w0
  const char *v32; // x5
  __int64 v33; // x4
  __int64 v34; // x19
  _BYTE *v35; // x20
  __int64 v36; // x8
  _DWORD *v37; // x9
  __int64 v38; // x0
  void (__fastcall *v39)(__int64, void *, __int64); // x8
  __int64 v40; // x0
  void (__fastcall *v41)(__int64, void *, __int64); // x8
  __int64 v42; // x0
  void (__fastcall *v43)(__int64, void *, __int64); // x8
  __int64 v44; // x0
  void (__fastcall *v45)(__int64, void *, __int64); // x8
  __int64 v46; // x0
  void (__fastcall *v47)(__int64, void *, __int64); // x8
  __int64 v48; // x0
  void (__fastcall *v49)(__int64, void *, __int64); // x8
  __int64 v50; // x0
  void (__fastcall *v51)(__int64, void *, __int64); // x8
  __int64 v52; // x0
  void (__fastcall *v53)(__int64, void *, __int64); // x8
  __int64 v54; // x0
  unsigned int handle; // w0
  unsigned int v56; // w19
  __int64 result; // x0
  int v58; // w8
  __int64 v59; // x22
  char *v60; // x19
  char *v61; // x25
  char *v62; // x27
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x10
  char *v68; // x9
  char *v69; // x8
  char *v70; // x0
  char **v71; // x1
  __int64 v72; // x8
  char **v73; // x1
  __int64 v74; // x6
  const char *v75; // x5
  __int64 v76; // x4
  __int64 v77; // x20
  __int64 v78; // x22
  _QWORD *v79; // x8
  int v80; // w8
  _QWORD *v81; // x0
  _QWORD *v82; // x0
  unsigned int v83; // w0
  __int64 v84; // x25
  unsigned int v85; // w22
  int scid; // w0
  unsigned int v87; // w24
  int v88; // w0
  int v89; // w0
  int v90; // w0
  int v91; // w0
  int v92; // w0
  int v93; // w19
  unsigned int v94; // w24
  int v95; // w8
  _BYTE *v96; // x19
  __int64 v97; // x26
  int v98; // w27
  __int64 v99; // x4
  const char *v100; // x5
  bool v101; // cf
  unsigned int v102; // w20
  int v103; // w0
  unsigned int v104; // w24
  __int64 v105; // x22
  int v106; // w25
  char v107; // w9
  int v108; // w10
  __int64 v109; // x0
  __int64 v110; // x0
  int v111; // w0
  int v112; // w0
  int v113; // w0
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  int v119; // w8
  __int64 v120; // x0
  int v121; // w19
  int v122; // w19
  int v123; // w19
  int v124; // w19
  unsigned __int64 StatusReg; // x19
  __int64 v126; // x20
  unsigned int v127; // [xsp+24h] [xbp-ACh]
  char v128; // [xsp+28h] [xbp-A8h]
  int v129; // [xsp+30h] [xbp-A0h]
  unsigned int v130; // [xsp+30h] [xbp-A0h]
  __int64 v133; // [xsp+48h] [xbp-88h] BYREF
  __int64 v134; // [xsp+50h] [xbp-80h]
  __int64 v135; // [xsp+58h] [xbp-78h]
  __int64 v136; // [xsp+60h] [xbp-70h]
  __int64 v137; // [xsp+68h] [xbp-68h]
  __int64 v138; // [xsp+70h] [xbp-60h]
  __int64 v139; // [xsp+78h] [xbp-58h]
  __int64 v140; // [xsp+80h] [xbp-50h]
  __int64 v141; // [xsp+88h] [xbp-48h]
  __int64 v142; // [xsp+90h] [xbp-40h] BYREF
  int v143; // [xsp+9Ch] [xbp-34h] BYREF
  __int64 v144; // [xsp+A0h] [xbp-30h] BYREF
  __int64 v145; // [xsp+A8h] [xbp-28h]
  __int64 v146; // [xsp+B0h] [xbp-20h]
  int v147; // [xsp+B8h] [xbp-18h]
  __int64 v148; // [xsp+C0h] [xbp-10h]

  v148 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v142 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v133 = 0;
  memset(g_ife_hw_mgr, 0, 0x13FE0u);
  v144 = 0;
  v145 = 0;
  v146 = 0;
  v147 = 0;
  qword_3A8698 = -1;
  qword_3A86A0 = -1;
  byte_3A86B0 = 0;
  qword_3A86C0 = -1;
  qword_3A86C8 = -1;
  byte_3A86D8 = 0;
  qword_3A86E8 = -1;
  qword_3A86F0 = -1;
  byte_3A8700 = 0;
  qword_3A8710 = -1;
  qword_3A8718 = -1;
  byte_3A8728 = 0;
  qword_3A8738 = -1;
  qword_3A8740 = -1;
  byte_3A8750 = 0;
  qword_3A8760 = -1;
  qword_3A8768 = -1;
  byte_3A8778 = 0;
  qword_3A8788 = -1;
  qword_3A8790 = -1;
  byte_3A87A0 = 0;
  qword_3A87B0 = -1;
  qword_3A87B8 = -1;
  byte_3A87C8 = 0;
  qword_3A87D8 = -1;
  qword_3A87E0 = -1;
  byte_3A87F0 = 0;
  qword_3A8800 = -1;
  qword_3A8808 = -1;
  byte_3A8818 = 0;
  _mutex_init(&unk_394A30, "&g_ife_hw_mgr.ctx_mutex", &cam_ife_hw_mgr_init___key);
  v4 = nullptr;
  v5 = 0;
  v6 = &qword_394998;
  unk_3A8588 = 0;
  do
  {
    if ( (unsigned int)((__int64 (__fastcall *)(__int64 *, _QWORD))cam_vfe_hw_init)(v6, (unsigned int)v4) )
    {
      v6[11] = 0;
    }
    else
    {
      v7 = *(_QWORD *)*v6;
      v8 = *(_QWORD *)(v7 + 112);
      if ( !v5 )
      {
        v9 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(v7 + 88);
        v10 = *(_QWORD *)(v7 + 112);
        if ( *((_DWORD *)v9 - 1) != -1055839300 )
          __break(0x8228u);
        v9(v10, 44, &v133, 72);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_init",
            20084,
            "max VFE out resources: 0x%x num perf counters: 0x%x; IFE/MC_TFE: max FCG channels/contexts: %u, max FCG pred"
            "ictions: %u, FCG supported: %u",
            v133,
            HIDWORD(v133),
            v135,
            HIDWORD(v135),
            BYTE4(v136));
        v11 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(v7 + 88);
        if ( *((_DWORD *)v11 - 1) != -1055839300 )
          __break(0x8228u);
        v11(v8, 60, &v144, 28);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_init",
            20092,
            "received %d path-port mappings",
            v144);
      }
      v12 = debug_mdl;
      v6[11] = v8 + 384;
      if ( (v12 & 8) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v12 & 8,
          4,
          "cam_ife_hw_mgr_init",
          20101,
          "reg_map: mem base = %pK cam_base = 0x%llx",
          *(const void **)(v8 + 384),
          *(unsigned int *)(v8 + 392));
      ++v5;
      if ( *(_DWORD *)(*v6 + 8) )
        byte_3A88D0 = 1;
    }
    v4 = (int *)((char *)v4 + 1);
    ++v6;
  }
  while ( v4 != &dword_8 );
  if ( !v5 )
  {
    v32 = "no valid IFE HW";
    v33 = 20112;
LABEL_110:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      v33,
      v32);
    result = 4294967274LL;
    goto LABEL_158;
  }
  byte_3A85C4 = BYTE5(v136);
  byte_3A85D4 = BYTE4(v138);
  dword_3A85B4 = v134;
  dword_3A85AC = HIDWORD(v133);
  dword_3A85A4 = v133;
  v13 = (unsigned __int8)v133;
  v133 = 0;
  v134 = 0;
  dword_3A8598 = HIDWORD(v135);
  dword_3A8590 = v135;
  byte_3A85A0 = BYTE4(v136);
  max_ife_out_res = v13;
  byte_3A85C8 = v137;
  v14 = HIDWORD(v137);
  v15 = v138;
  v135 = 0;
  v136 = 0;
  v137 = 0;
  v138 = 0;
  dword_3A85CC = v14;
  dword_3A85D0 = v15;
  v17 = v139;
  v16 = v140;
  v18 = v141;
  v139 = 0;
  v140 = 0;
  v141 = 0;
  qword_3A85D8 = v17;
  qword_3A85E0 = v16;
  v19 = (unsigned int)v144;
  qword_3A85E8 = v18;
  if ( (_DWORD)v144 )
  {
    dword_3A85F4 = HIDWORD(v144);
    dword_3A85F8 = v145;
    if ( (_DWORD)v144 != 1 )
    {
      dword_3A85FC = HIDWORD(v145);
      dword_3A8600 = v146;
      if ( (_DWORD)v144 != 2 )
      {
        dword_3A8604 = HIDWORD(v146);
        dword_3A8608 = v147;
        if ( (_DWORD)v144 != 3 )
        {
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v126 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &cam_ife_hw_mgr_init__alloc_tag_43;
          v114 = _kvmalloc_node_noprof(4LL * *(unsigned int *)(v19 + 1452), 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(StatusReg + 80) = v126;
          goto LABEL_230;
        }
      }
    }
  }
  v20 = &qword_394958;
  v21 = 0;
  v22 = 0;
  dword_3A85F0 = v144;
  dword_3A8694 = a3;
  do
  {
    if ( !(unsigned int)cam_ife_csid_hw_init(v20, v21) )
    {
      if ( !v22 )
      {
        v23 = *(_QWORD *)(*v20 + 112);
        v24 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(*v20 + 88);
        if ( *((_DWORD *)v24 - 1) != -1055839300 )
          __break(0x8228u);
        if ( v24(v23, 44, &v133, 72) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_init",
            20175,
            "Invalid num of DT supported: %u",
            v136);
          result = 4294967274LL;
          goto LABEL_158;
        }
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_init",
            20168,
            "Max DT supported: %u num_csid_perf_counters: %u",
            v136,
            HIDWORD(v134));
        dword_3A85BC = HIDWORD(v134);
        dword_3A85C0 = v136;
      }
      ++v22;
    }
    ++v21;
    ++v20;
  }
  while ( v21 != 8 );
  if ( !v22 )
  {
    v32 = "no valid IFE CSID HW";
    v33 = 20183;
    goto LABEL_110;
  }
  v25 = 0;
  v26 = 0;
  v27 = &qword_3949D8;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v133 = 0;
  do
  {
    if ( !(unsigned int)((__int64 (__fastcall *)(__int64 *, _QWORD))cam_sfe_hw_init)(v27, (unsigned int)v25) )
    {
      if ( v26 )
      {
LABEL_40:
        ++v26;
        goto LABEL_41;
      }
      v28 = *(_QWORD *)*v27;
      v29 = *(_QWORD *)(v28 + 112);
      v30 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v28 + 88);
      if ( *((_DWORD *)v30 - 1) != -1055839300 )
        __break(0x8228u);
      v31 = v30(v29, 44, &v133, 72);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v129 = v31;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_init",
          20209,
          "max SFE out resources: 0x%x num_perf_counters: 0x%x; SFE: max FCG channels: %u, max FCG predictions: %u, FCG supported: %d",
          v133,
          HIDWORD(v133),
          v135,
          HIDWORD(v135),
          BYTE4(v136));
        if ( v129 )
        {
LABEL_50:
          if ( *(_DWORD *)(*v27 + 8) )
            byte_3A88D0 = 1;
          goto LABEL_40;
        }
      }
      else if ( v31 )
      {
        goto LABEL_50;
      }
      dword_3A85B0 = HIDWORD(v133);
      dword_3A8594 = v135;
      dword_3A85A8 = v133;
      dword_3A85B8 = v134;
      dword_3A859C = HIDWORD(v135);
      byte_3A85A1 = BYTE4(v136);
      max_sfe_out_res = (unsigned __int8)v133;
      goto LABEL_50;
    }
LABEL_41:
    ++v25;
    ++v27;
  }
  while ( v25 != 3 );
  if ( !v26 )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      20234,
      "no valid SFE HW devices");
  v34 = 0;
  v35 = &unk_3A8348;
  do
  {
    v36 = g_ife_hw_mgr[v34 + 12];
    if ( v36 )
    {
      v37 = *(_DWORD **)(v36 + 8);
      if ( v37 )
      {
        v38 = *(_QWORD *)(v36 + 112);
        if ( *(v37 - 1) != 1989616049 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _BYTE *, __int64))v37)(v38, v35, 36);
        byte_3A88D2 = v35[29];
        byte_3A88D1 = v35[30];
        byte_3A88D3 = v35[32];
      }
    }
    ++v34;
    v35 += 36;
  }
  while ( v34 != 8 );
  if ( qword_394998 )
  {
    v39 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_394998 + 8LL);
    if ( v39 )
    {
      v40 = *(_QWORD *)(*(_QWORD *)qword_394998 + 112LL);
      if ( *((_DWORD *)v39 - 1) != 1989616049 )
        __break(0x8228u);
      v39(v40, &unk_3A8468, 16);
    }
  }
  if ( qword_3949A0 )
  {
    v41 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_3949A0 + 8LL);
    if ( v41 )
    {
      v42 = *(_QWORD *)(*(_QWORD *)qword_3949A0 + 112LL);
      if ( *((_DWORD *)v41 - 1) != 1989616049 )
        __break(0x8228u);
      v41(v42, &unk_3A8478, 16);
    }
  }
  if ( qword_3949A8 )
  {
    v43 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_3949A8 + 8LL);
    if ( v43 )
    {
      v44 = *(_QWORD *)(*(_QWORD *)qword_3949A8 + 112LL);
      if ( *((_DWORD *)v43 - 1) != 1989616049 )
        __break(0x8228u);
      v43(v44, &unk_3A8488, 16);
    }
  }
  if ( qword_3949B0 )
  {
    v45 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_3949B0 + 8LL);
    if ( v45 )
    {
      v46 = *(_QWORD *)(*(_QWORD *)qword_3949B0 + 112LL);
      if ( *((_DWORD *)v45 - 1) != 1989616049 )
        __break(0x8228u);
      v45(v46, &unk_3A8498, 16);
    }
  }
  if ( qword_3949B8 )
  {
    v47 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_3949B8 + 8LL);
    if ( v47 )
    {
      v48 = *(_QWORD *)(*(_QWORD *)qword_3949B8 + 112LL);
      if ( *((_DWORD *)v47 - 1) != 1989616049 )
        __break(0x8228u);
      v47(v48, &unk_3A84A8, 16);
    }
  }
  if ( qword_3949C0 )
  {
    v49 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_3949C0 + 8LL);
    if ( v49 )
    {
      v50 = *(_QWORD *)(*(_QWORD *)qword_3949C0 + 112LL);
      if ( *((_DWORD *)v49 - 1) != 1989616049 )
        __break(0x8228u);
      v49(v50, &unk_3A84B8, 16);
    }
  }
  if ( qword_3949C8 )
  {
    v51 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_3949C8 + 8LL);
    if ( v51 )
    {
      v52 = *(_QWORD *)(*(_QWORD *)qword_3949C8 + 112LL);
      if ( *((_DWORD *)v51 - 1) != 1989616049 )
        __break(0x8228u);
      v51(v52, &unk_3A84C8, 16);
    }
  }
  if ( qword_3949D0 )
  {
    v53 = *(void (__fastcall **)(__int64, void *, __int64))(*(_QWORD *)qword_3949D0 + 8LL);
    if ( v53 )
    {
      v54 = *(_QWORD *)(*(_QWORD *)qword_3949D0 + 112LL);
      if ( *((_DWORD *)v53 - 1) != 1989616049 )
        __break(0x8228u);
      v53(v54, &unk_3A84D8, 16);
    }
  }
  qword_394A68 = (__int64)&qword_394A68;
  qword_394A70 = (__int64)&qword_394A68;
  qword_394A78 = (__int64)&qword_394A78;
  qword_394A80 = (__int64)&qword_394A78;
  handle = cam_smmu_get_handle("ife", &dword_394938);
  if ( handle != -114 && handle )
  {
    v32 = "Can not get iommu handle";
    v33 = 20253;
    goto LABEL_110;
  }
  v56 = handle;
  if ( (unsigned int)cam_smmu_get_handle("cam-secure", &dword_39493C) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      20259,
      "Failed to get secure iommu handle");
LABEL_157:
    cam_smmu_destroy_handle(dword_394938);
    result = v56;
    dword_394938 = -1;
    goto LABEL_158;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_init",
      20265,
      "iommu_handles: non-secure[0x%x], secure[0x%x]",
      dword_394938,
      dword_39493C);
  if ( (unsigned int)cam_cdm_get_iommu_handle("ife3", (__int64)&v142) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      &print_fmt_cam_irq_activated[3],
      (unsigned int)"Failed to acquire CDM iommu handle");
    v58 = -1;
    dword_394940 = -1;
  }
  else
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_init",
        20270,
        "Successfully acquired CDM iommu handles 0x%x, 0x%x",
        v142,
        HIDWORD(v142));
    v58 = HIDWORD(v142);
    dword_394940 = v142;
  }
  v59 = 0;
  v4 = (int *)&unk_2FD000;
  v60 = (char *)g_ife_hw_mgr;
  dword_394944 = v58;
  _ReadStatusReg(SP_EL0);
  dword_394A60 = 0;
  while ( 2 )
  {
    v61 = (char *)&g_ife_hw_mgr[1251 * v59];
    v62 = v61 + 400;
    *((_QWORD *)v61 + 50) = v61 + 400;
    *((_QWORD *)v61 + 51) = v61 + 400;
    *((_QWORD *)v61 + 60) = v61 + 480;
    *((_QWORD *)v61 + 61) = v61 + 480;
    *((_QWORD *)v61 + 76) = v61 + 608;
    *((_QWORD *)v61 + 77) = v61 + 608;
    *((_QWORD *)v61 + 78) = v61 + 624;
    *((_QWORD *)v61 + 79) = v61 + 624;
    *((_QWORD *)v61 + 80) = v61 + 640;
    *((_QWORD *)v61 + 81) = v61 + 640;
    *((_QWORD *)v61 + 82) = v61 + 656;
    *((_QWORD *)v61 + 83) = v61 + 656;
    if ( mem_trace_en != 1 )
    {
      v64 = _kvmalloc_node_noprof((unsigned int)max_ife_out_res, 0, 3520, 0xFFFFFFFFLL);
      *((_QWORD *)v61 + 1112) = v64;
      if ( v64 )
        goto LABEL_126;
LABEL_146:
      v74 = *((unsigned int *)v61 + 114);
      v75 = "Alloc failed for ife out res list, ctx_idx: %u";
      v76 = 20296;
LABEL_147:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_init",
        v76,
        v75,
        v74);
      v56 = -12;
      goto LABEL_148;
    }
    v63 = cam_mem_trace_alloc((unsigned int)max_ife_out_res, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4F44u);
    *((_QWORD *)v61 + 1112) = v63;
    if ( !v63 )
      goto LABEL_146;
LABEL_126:
    if ( !max_sfe_out_res )
      goto LABEL_132;
    if ( mem_trace_en != 1 )
    {
      v66 = _kvmalloc_node_noprof((unsigned int)max_sfe_out_res, 0, 3520, 0xFFFFFFFFLL);
      *((_QWORD *)v61 + 1113) = v66;
      if ( v66 )
        goto LABEL_131;
LABEL_145:
      v74 = *((unsigned int *)v61 + 114);
      v75 = "Alloc failed for SFE out res list, ctx_idx: %u";
      v76 = 20306;
      goto LABEL_147;
    }
    v65 = cam_mem_trace_alloc((unsigned int)max_sfe_out_res, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4F4Eu);
    *((_QWORD *)v61 + 1113) = v65;
    if ( !v65 )
      goto LABEL_145;
LABEL_131:
    memset(*((void **)v61 + 1113), 255, (unsigned int)max_sfe_out_res);
LABEL_132:
    v67 = 0;
    v68 = v61 + 688;
    *((_QWORD *)v61 + 86) = v61 + 688;
    *((_QWORD *)v61 + 87) = v61 + 688;
    do
    {
      v69 = &v60[v67];
      v70 = v69 + 704;
      *((_QWORD *)v69 + 88) = v69 + 704;
      *((_QWORD *)v69 + 89) = v69 + 704;
      v71 = *((char ***)v61 + 87);
      if ( &v60[v67 + 704] == (char *)v71 || *v71 != v68 )
      {
        _list_add_valid_or_report(v70);
      }
      else
      {
        *((_QWORD *)v61 + 87) = v70;
        *((_QWORD *)v69 + 88) = v68;
        *((_QWORD *)v69 + 89) = v71;
        *v71 = v70;
      }
      v67 += 128;
    }
    while ( v67 != 0x2000 );
    *((_DWORD *)v61 + 114) = 8;
    *((_QWORD *)v61 + 59) = g_ife_hw_mgr;
    cam_tasklet_init(&g_ife_hw_mgr[v59], (__int64)(v61 + 400), v59);
    v72 = g_ife_hw_mgr[v59];
    *((_DWORD *)v61 + 2316) = 0;
    *((_QWORD *)v61 + 52) = v72;
    _init_swait_queue_head(v61 + 9272, "&x->wait", &init_completion___key_8);
    v73 = (char **)qword_394A70;
    if ( (char *)qword_394A70 == v62 || *(__int64 **)qword_394A70 != &qword_394A68 )
    {
      _list_add_valid_or_report(v61 + 400);
    }
    else
    {
      qword_394A70 = (__int64)(v61 + 400);
      *((_QWORD *)v61 + 50) = &qword_394A68;
      *((_QWORD *)v61 + 51) = v73;
      *v73 = v62;
    }
    ++v59;
    v60 += 10008;
    if ( v59 != 8 )
      continue;
    break;
  }
  v83 = cam_req_mgr_workq_create(
          "cam_ife_worker",
          0xAu,
          &qword_3A84E8,
          0,
          0,
          (__int64)cam_req_mgr_process_workq_cam_ife_worker);
  if ( (v83 & 0x80000000) != 0 )
  {
    v56 = v83;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      20342,
      "Unable to create worker, ctx_idx: %u",
      *((_DWORD *)v61 + 114));
LABEL_148:
    v77 = 0;
    v78 = 0;
    do
    {
      cam_tasklet_deinit(&g_ife_hw_mgr[v78]);
      v80 = (unsigned __int8)mem_trace_en;
      v81 = (_QWORD *)g_ife_hw_mgr[v77 + 1112];
      g_ife_hw_mgr[v77 + 1142] = 0;
      if ( v80 == 1 )
        cam_mem_trace_free(v81, 0);
      else
        kvfree(v81);
      v82 = (_QWORD *)g_ife_hw_mgr[v77 + 1113];
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v82, 0);
      else
        kvfree(v82);
      ++v78;
      v79 = &g_ife_hw_mgr[v77];
      v77 += 1251;
      v79[52] = 0;
      v79[1112] = 0;
      v79[1113] = 0;
    }
    while ( v78 != 8 );
    cam_smmu_destroy_handle(dword_39493C);
    dword_39493C = -1;
    goto LABEL_157;
  }
  v143 = 0;
  dword_3A860C = 0;
  if ( !qword_3949D8 )
    goto LABEL_218;
  v84 = qword_3949E0;
  byte_3A8668 = 0;
  word_3A8669 = 0;
  qword_3A8658 = 0xFFFFFFFF00000000LL;
  qword_3A8660 = -1;
  if ( qword_3949E0 )
  {
    qword_3A866C = 0xFFFFFFFF00000000LL;
    byte_3A867C = 0;
    word_3A867D = 0;
    qword_3A8674 = -1;
    if ( qword_3949E8 )
    {
      v85 = 3;
      v128 = 0;
      byte_3A8690 = 0;
      word_3A8691 = 0;
      qword_3A8680 = 0xFFFFFFFF00000000LL;
      qword_3A8688 = -1;
    }
    else
    {
      v85 = 2;
      v128 = 1;
    }
  }
  else
  {
    v128 = 0;
    v85 = 1;
  }
  scid = cam_cpas_get_scid(0);
  dword_3A8610 = 0;
  dword_3A8614 = scid;
  if ( scid < 0 )
  {
    v87 = 0;
  }
  else
  {
    v87 = 1;
    ++dword_3A860C;
  }
  v88 = cam_cpas_get_scid(1);
  dword_3A861C = 1;
  dword_3A8620 = v88;
  if ( (v88 & 0x80000000) == 0 )
  {
    ++v87;
    ++dword_3A860C;
  }
  v89 = cam_cpas_get_scid(2);
  dword_3A8628 = 2;
  dword_3A862C = v89;
  if ( v89 < 0 )
  {
    v130 = 0;
  }
  else
  {
    ++dword_3A860C;
    v130 = 1;
  }
  v90 = cam_cpas_get_scid(3);
  dword_3A8634 = 3;
  dword_3A8638 = v90;
  if ( (v90 & 0x80000000) == 0 )
  {
    ++v130;
    ++dword_3A860C;
  }
  v91 = cam_cpas_get_scid(4);
  dword_3A8640 = 4;
  dword_3A8644 = v91;
  if ( (v91 & 0x80000000) == 0 )
  {
    ++v130;
    ++dword_3A860C;
  }
  v92 = cam_cpas_get_scid(5);
  dword_3A864C = 5;
  dword_3A8650 = v92;
  if ( (v92 & 0x80000000) == 0 )
  {
    ++v130;
    ++dword_3A860C;
  }
  if ( v87 )
  {
    v93 = v87 % v85;
    if ( (dword_3A8614 & 0x80000000) == 0 )
      cam_ife_hw_mgr_attach_sfe_sys_cache_id(v93 != 0, (unsigned int)dword_3A8610, &v143, v85);
    if ( v87 != 1 && (dword_3A8620 & 0x80000000) == 0 )
      cam_ife_hw_mgr_attach_sfe_sys_cache_id(v93 != 0, (unsigned int)dword_3A861C, &v143, v85);
  }
  v127 = v87;
  v94 = v130;
  v95 = 0;
  v96 = &unk_3A8630;
  v97 = -4;
  v143 = 0;
  v98 = v130 % v85;
  while ( 2 )
  {
    if ( (*((_DWORD *)v96 - 1) & 0x80000000) == 0 )
    {
      cam_ife_hw_mgr_attach_sfe_sys_cache_id(v98 != 0, *((unsigned int *)v96 - 2), &v143, v85);
      v102 = v97 + 6;
      *v96 = 0;
      v103 = cam_cpas_configure_staling_llcc((int)v97 + 6, 2, 1, 1);
      if ( v94 == 1 )
      {
        if ( !v84 || v103 != -95 )
          goto LABEL_199;
        v99 = 20012;
        v100 = "Fatal error llcc staling feature is not supported cache: %d";
LABEL_189:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_populate_sys_cache_id",
          v99,
          v100,
          v102);
        v95 = -14;
      }
      else
      {
        if ( !v103 && v94 )
        {
          v99 = 20016;
          v100 = "Fatal error llcc staling feature is supported more large cache %d";
          goto LABEL_189;
        }
LABEL_199:
        if ( v103 )
        {
          if ( v103 == -95 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_mgr_populate_sys_cache_id",
              20020,
              "llcc staling feature is not supported cache: %d",
              v102);
            v95 = -95;
          }
          else
          {
            v104 = v85;
            v105 = v84;
            v106 = v103;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_mgr_populate_sys_cache_id",
              20023,
              "llcc staling feature enabling failing cache: %d",
              v102);
            v95 = v106;
            v84 = v105;
            v85 = v104;
            v94 = v130;
          }
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "cam_ife_mgr_populate_sys_cache_id",
            20026,
            "llcc staling feature supported: %d rc = %d",
            v102,
            0);
          v95 = 0;
          *v96 = 1;
        }
      }
    }
    v101 = __CFADD__(v97++, 1);
    v96 += 12;
    if ( !v101 )
      continue;
    break;
  }
  v107 = debug_mdl;
  v108 = debug_priority;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v121 = v95;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_populate_sys_cache_id",
      20031,
      "Num SCIDs Small:%u Large: %u",
      v127,
      v94);
    v107 = debug_mdl;
    v95 = v121;
    v108 = debug_priority;
    if ( (debug_mdl & 8) != 0 )
      goto LABEL_207;
  }
  else if ( (debug_mdl & 8) != 0 )
  {
LABEL_207:
    if ( !v108 )
    {
      v122 = v95;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v107 & 8,
        4,
        "cam_ife_mgr_populate_sys_cache_id",
        20034,
        "SFE[%u] available SCIDs 0x%x",
        0,
        qword_3A8658);
      v107 = debug_mdl;
      v95 = v122;
      v108 = debug_priority;
    }
  }
  if ( v84 )
  {
    if ( (v107 & 8) != 0 && !v108 )
    {
      v123 = v95;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v107 & 8,
        4,
        "cam_ife_mgr_populate_sys_cache_id",
        20034,
        "SFE[%u] available SCIDs 0x%x",
        1,
        qword_3A866C);
      v107 = debug_mdl;
      v95 = v123;
      v108 = debug_priority;
      if ( (v128 & 1) == 0 )
      {
LABEL_213:
        if ( (v107 & 8) != 0 && !v108 )
        {
          v124 = v95;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v107 & 8,
            4,
            "cam_ife_mgr_populate_sys_cache_id",
            20034,
            "SFE[%u] available SCIDs 0x%x",
            2,
            qword_3A8680);
          v95 = v124;
        }
      }
    }
    else if ( (v128 & 1) == 0 )
    {
      goto LABEL_213;
    }
  }
  if ( v95 == -14 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      20349,
      "LLCC stall notif enable fault");
    v56 = -14;
    goto LABEL_148;
  }
LABEL_218:
  *a1 = g_ife_hw_mgr;
  a1[1] = cam_ife_mgr_get_hw_caps;
  a1[5] = cam_ife_mgr_start_hw;
  a1[6] = &cam_ife_mgr_stop_hw;
  a1[3] = &cam_ife_mgr_acquire;
  a1[4] = cam_ife_mgr_release_hw;
  a1[7] = &cam_ife_mgr_prepare_hw_update;
  a1[9] = cam_ife_mgr_config_hw;
  a1[10] = cam_ife_mgr_read;
  a1[11] = cam_ife_mgr_write;
  a1[12] = &cam_ife_mgr_cmd;
  a1[16] = &cam_ife_mgr_reset;
  a1[17] = &cam_ife_mgr_dump;
  a1[18] = cam_ife_mgr_recover_hw;
  if ( a2 )
    *a2 = dword_394938;
  dword_3A8570 = 8;
  v109 = cam_ife_hw_mgr_debug_register();
  v110 = cam_ife_mgr_count_functional_ife(v109);
  cam_ife_mgr_count_functional_sfe(v110);
  cam_vfe_get_num_ifes(&g_num_ife_available);
  v111 = cam_cpas_prepare_subpart_info(0, g_num_ife_available, g_num_ife_functional);
  if ( v111 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      20382,
      "Failed to populate num_ifes, rc: %d",
      v111);
  cam_vfe_get_num_ife_lites(&g_num_ife_lite_available);
  v112 = cam_cpas_prepare_subpart_info(1u, g_num_ife_lite_available, g_num_ife_lite_functional);
  if ( v112 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      20388,
      "Failed to populate num_ife_lites, rc: %d",
      v112);
  cam_sfe_get_num_hws(&g_num_sfe_available);
  v113 = cam_cpas_prepare_subpart_info(2u, g_num_sfe_available, g_num_sfe_functional);
  if ( v113 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_init",
      20394,
      "Failed to populate num_sfes, rc: %d",
      v113);
  cam_common_register_mini_dump_cb((__int64)cam_ife_hw_mgr_mini_dump_cb, "CAM_ISP", 0);
  if ( dword_3A85AC )
  {
    if ( mem_trace_en == 1 )
      v114 = cam_mem_trace_alloc(4LL * (unsigned int)dword_3A85AC, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4FB4u);
    else
      v114 = _kvmalloc_node_noprof(4LL * (unsigned int)dword_3A85AC, 0, 3520, 0xFFFFFFFFLL);
LABEL_230:
    qword_3A8530 = v114;
  }
  if ( dword_3A85B0 )
  {
    if ( *((_BYTE *)v4 + 2904) == 1 )
      v115 = cam_mem_trace_alloc(4LL * (unsigned int)dword_3A85B0, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4FBAu);
    else
      v115 = _kvmalloc_node_noprof(4LL * (unsigned int)dword_3A85B0, 0, 3520, 0xFFFFFFFFLL);
    qword_3A8538 = v115;
  }
  if ( dword_3A85B4 )
  {
    if ( *((_BYTE *)v4 + 2904) == 1 )
      v116 = cam_mem_trace_alloc(4LL * (unsigned int)dword_3A85B4, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4FC1u);
    else
      v116 = _kvmalloc_node_noprof(4LL * (unsigned int)dword_3A85B4, 0, 3520, 0xFFFFFFFFLL);
    qword_3A8548 = v116;
  }
  if ( dword_3A85B8 )
  {
    if ( *((_BYTE *)v4 + 2904) == 1 )
      v117 = cam_mem_trace_alloc(4LL * (unsigned int)dword_3A85B8, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4FC7u);
    else
      v117 = _kvmalloc_node_noprof(4LL * (unsigned int)dword_3A85B8, 0, 3520, 0xFFFFFFFFLL);
    qword_3A8550 = v117;
  }
  if ( dword_3A85BC )
  {
    if ( *((_BYTE *)v4 + 2904) == 1 )
      v118 = cam_mem_trace_alloc(4LL * (unsigned int)dword_3A85BC, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4FCEu);
    else
      v118 = _kvmalloc_node_noprof(4LL * (unsigned int)dword_3A85BC, 0, 3520, 0xFFFFFFFFLL);
    v119 = *((unsigned __int8 *)v4 + 2904);
    qword_3A8560 = v118;
    if ( v119 == 1 )
      v120 = cam_mem_trace_alloc(4LL * (unsigned int)dword_3A85BC, 0xCC0u, 0, "cam_ife_hw_mgr_init", 0x4FD1u);
    else
      v120 = _kvmalloc_node_noprof(4LL * (unsigned int)dword_3A85BC, 0, 3520, 0xFFFFFFFFLL);
    qword_3A8568 = v120;
  }
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_init",
      20436,
      "Exit");
    result = 0;
  }
LABEL_158:
  _ReadStatusReg(SP_EL0);
  return result;
}
