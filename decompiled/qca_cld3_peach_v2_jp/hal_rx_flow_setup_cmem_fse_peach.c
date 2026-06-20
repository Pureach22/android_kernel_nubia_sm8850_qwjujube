__int64 __fastcall hal_rx_flow_setup_cmem_fse_peach(__int64 a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v4; // w19
  __int64 v7; // x25
  unsigned int v8; // w24
  __int64 v9; // x1
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x1
  unsigned int v12; // w22
  __int64 v13; // x8
  int v14; // w0
  unsigned int v15; // w22
  __int64 v16; // x1
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  __int64 v18; // x1
  unsigned int v19; // w23
  __int64 v20; // x8
  int v21; // w0
  unsigned int v22; // w26
  unsigned int v23; // w22
  __int64 v24; // x1
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  __int64 v26; // x1
  unsigned int v27; // w23
  __int64 v28; // x8
  int v29; // w0
  unsigned int v30; // w26
  unsigned int v31; // w22
  __int64 v32; // x1
  __int64 (__fastcall *v33)(__int64, __int64); // x8
  __int64 v34; // x1
  unsigned int v35; // w23
  __int64 v36; // x8
  int v37; // w0
  unsigned int v38; // w26
  unsigned int v39; // w22
  __int64 v40; // x1
  __int64 (__fastcall *v41)(__int64, __int64); // x8
  __int64 v42; // x1
  unsigned int v43; // w23
  __int64 v44; // x8
  int v45; // w0
  unsigned int v46; // w26
  unsigned int v47; // w22
  __int64 v48; // x1
  __int64 (__fastcall *v49)(__int64, __int64); // x8
  __int64 v50; // x1
  unsigned int v51; // w23
  __int64 v52; // x8
  int v53; // w0
  unsigned int v54; // w26
  unsigned int v55; // w22
  __int64 v56; // x1
  __int64 (__fastcall *v57)(__int64, __int64); // x8
  __int64 v58; // x1
  unsigned int v59; // w23
  __int64 v60; // x8
  int v61; // w0
  unsigned int v62; // w26
  unsigned int v63; // w22
  __int64 v64; // x1
  __int64 (__fastcall *v65)(__int64, __int64); // x8
  __int64 v66; // x1
  unsigned int v67; // w23
  __int64 v68; // x8
  int v69; // w0
  unsigned int v70; // w26
  unsigned int v71; // w22
  __int64 v72; // x1
  __int64 (__fastcall *v73)(__int64, __int64); // x8
  __int64 v74; // x1
  unsigned int v75; // w23
  __int64 v76; // x8
  int v77; // w0
  int v78; // w8
  int v79; // w9
  unsigned int v80; // w26
  unsigned int v81; // w22
  __int64 v82; // x1
  __int64 (__fastcall *v83)(__int64, __int64); // x8
  __int64 v84; // x1
  unsigned int v85; // w23
  __int64 v86; // x8
  int v87; // w0
  unsigned int v88; // w26
  unsigned int v89; // w22
  __int64 v90; // x1
  __int64 (__fastcall *v91)(__int64, __int64); // x8
  __int64 v92; // x1
  unsigned int v93; // w23
  __int64 v94; // x8
  int v95; // w0
  unsigned int v96; // w23
  __int64 v97; // x1
  __int64 (__fastcall *v98)(__int64, __int64); // x8
  __int64 v99; // x1
  unsigned int v100; // w22
  __int64 v101; // x8
  int v102; // w0
  unsigned int v103; // w23
  __int64 v104; // x1
  __int64 (__fastcall *v105)(__int64, __int64); // x8
  __int64 v106; // x1
  unsigned int v107; // w22
  __int64 v108; // x8
  int v109; // w0
  unsigned int v110; // w23
  __int64 v111; // x1
  __int64 (__fastcall *v112)(__int64, __int64); // x8
  __int64 v113; // x1
  unsigned int v114; // w22
  __int64 v115; // x8
  int v116; // w0
  int v117; // w8
  int v118; // w9
  unsigned int v119; // w22
  __int64 v120; // x1
  __int64 (__fastcall *v121)(__int64, __int64); // x8
  __int64 v122; // x1
  unsigned int v123; // w21
  __int64 v124; // x8
  int v125; // w0
  _QWORD v127[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a2 + (a3 << 6);
  v7 = a1 + 73728;
  v8 = v4 + 36;
  v127[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v127[0] = 0;
  if ( v4 + 36 < 0x80000 || (*(_BYTE *)(a1 + 74224) & 1) == 0 )
  {
    v11 = *(_QWORD *)(a1 + 16) + v8;
LABEL_8:
    writel_7(0, v11);
    goto LABEL_11;
  }
  if ( *(_BYTE *)(a1 + 74248) == 1 )
  {
    v9 = *(_QWORD *)(a1 + 16) + v8;
    v10 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 74392) + 48LL);
    if ( *((_DWORD *)v10 - 1) != 925895004 )
      __break(0x8228u);
    v11 = v10(a1, v9);
    goto LABEL_8;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v12 = (v8 >> 19) & 0x3F | 0x40000000;
  writel_7(v12, *(_QWORD *)(a1 + 16) + 12920LL);
  v13 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v8 >> 19) & 0x3F;
  v14 = readl_8(v13 + 12920);
  if ( v14 != v12 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v12, v14);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(0, *(_QWORD *)(a1 + 16) + (v8 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_11:
  v15 = a4[4];
  v127[0] = 0;
  if ( v4 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v18 = *(_QWORD *)(a1 + 16) + v4;
LABEL_18:
    writel_7(v15, v18);
    goto LABEL_21;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v16 = *(_QWORD *)(a1 + 16) + v4;
    v17 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v17 - 1) != 925895004 )
      __break(0x8228u);
    v18 = v17(a1, v16);
    goto LABEL_18;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v19 = (v4 >> 19) & 0x3F | 0x40000000;
  writel_7(v19, *(_QWORD *)(a1 + 16) + 12920LL);
  v20 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v4 >> 19) & 0x3F;
  v21 = readl_8(v20 + 12920);
  if ( v21 != v19 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v19, v21);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v15, *(_QWORD *)(a1 + 16) + (v4 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_21:
  v22 = v4 + 4;
  v23 = a4[5];
  v127[0] = 0;
  if ( v4 + 4 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v26 = *(_QWORD *)(a1 + 16) + v22;
LABEL_28:
    writel_7(v23, v26);
    goto LABEL_31;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v24 = *(_QWORD *)(a1 + 16) + v22;
    v25 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v25 - 1) != 925895004 )
      __break(0x8228u);
    v26 = v25(a1, v24);
    goto LABEL_28;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v27 = (v22 >> 19) & 0x3F | 0x40000000;
  writel_7(v27, *(_QWORD *)(a1 + 16) + 12920LL);
  v28 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v22 >> 19) & 0x3F;
  v29 = readl_8(v28 + 12920);
  if ( v29 != v27 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v27, v29);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v23, *(_QWORD *)(a1 + 16) + (v22 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_31:
  v30 = v4 + 8;
  v31 = a4[6];
  v127[0] = 0;
  if ( v4 + 8 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v34 = *(_QWORD *)(a1 + 16) + v30;
LABEL_38:
    writel_7(v31, v34);
    goto LABEL_41;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v32 = *(_QWORD *)(a1 + 16) + v30;
    v33 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v33 - 1) != 925895004 )
      __break(0x8228u);
    v34 = v33(a1, v32);
    goto LABEL_38;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v35 = (v30 >> 19) & 0x3F | 0x40000000;
  writel_7(v35, *(_QWORD *)(a1 + 16) + 12920LL);
  v36 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v30 >> 19) & 0x3F;
  v37 = readl_8(v36 + 12920);
  if ( v37 != v35 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v35, v37);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v31, *(_QWORD *)(a1 + 16) + (v30 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_41:
  v38 = v4 + 12;
  v39 = a4[7];
  v127[0] = 0;
  if ( v4 + 12 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v42 = *(_QWORD *)(a1 + 16) + v38;
LABEL_48:
    writel_7(v39, v42);
    goto LABEL_51;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v40 = *(_QWORD *)(a1 + 16) + v38;
    v41 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v41 - 1) != 925895004 )
      __break(0x8228u);
    v42 = v41(a1, v40);
    goto LABEL_48;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v43 = (v38 >> 19) & 0x3F | 0x40000000;
  writel_7(v43, *(_QWORD *)(a1 + 16) + 12920LL);
  v44 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v38 >> 19) & 0x3F;
  v45 = readl_8(v44 + 12920);
  if ( v45 != v43 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v43, v45);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v39, *(_QWORD *)(a1 + 16) + (v38 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_51:
  v46 = v4 + 16;
  v47 = *a4;
  v127[0] = 0;
  if ( v4 + 16 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v50 = *(_QWORD *)(a1 + 16) + v46;
LABEL_58:
    writel_7(v47, v50);
    goto LABEL_61;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v48 = *(_QWORD *)(a1 + 16) + v46;
    v49 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v49 - 1) != 925895004 )
      __break(0x8228u);
    v50 = v49(a1, v48);
    goto LABEL_58;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v51 = (v46 >> 19) & 0x3F | 0x40000000;
  writel_7(v51, *(_QWORD *)(a1 + 16) + 12920LL);
  v52 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v46 >> 19) & 0x3F;
  v53 = readl_8(v52 + 12920);
  if ( v53 != v51 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v51, v53);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v47, *(_QWORD *)(a1 + 16) + (v46 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_61:
  v54 = v4 + 20;
  v55 = a4[1];
  v127[0] = 0;
  if ( v4 + 20 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v58 = *(_QWORD *)(a1 + 16) + v54;
LABEL_68:
    writel_7(v55, v58);
    goto LABEL_71;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v56 = *(_QWORD *)(a1 + 16) + v54;
    v57 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v57 - 1) != 925895004 )
      __break(0x8228u);
    v58 = v57(a1, v56);
    goto LABEL_68;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v59 = (v54 >> 19) & 0x3F | 0x40000000;
  writel_7(v59, *(_QWORD *)(a1 + 16) + 12920LL);
  v60 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v54 >> 19) & 0x3F;
  v61 = readl_8(v60 + 12920);
  if ( v61 != v59 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v59, v61);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v55, *(_QWORD *)(a1 + 16) + (v54 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_71:
  v62 = v4 + 24;
  v63 = a4[2];
  v127[0] = 0;
  if ( v4 + 24 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v66 = *(_QWORD *)(a1 + 16) + v62;
LABEL_78:
    writel_7(v63, v66);
    goto LABEL_81;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v64 = *(_QWORD *)(a1 + 16) + v62;
    v65 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v65 - 1) != 925895004 )
      __break(0x8228u);
    v66 = v65(a1, v64);
    goto LABEL_78;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v67 = (v62 >> 19) & 0x3F | 0x40000000;
  writel_7(v67, *(_QWORD *)(a1 + 16) + 12920LL);
  v68 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v62 >> 19) & 0x3F;
  v69 = readl_8(v68 + 12920);
  if ( v69 != v67 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v67, v69);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v63, *(_QWORD *)(a1 + 16) + (v62 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_81:
  v70 = v4 + 28;
  v71 = a4[3];
  v127[0] = 0;
  if ( v4 + 28 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v74 = *(_QWORD *)(a1 + 16) + v70;
LABEL_88:
    writel_7(v71, v74);
    goto LABEL_91;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v72 = *(_QWORD *)(a1 + 16) + v70;
    v73 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v73 - 1) != 925895004 )
      __break(0x8228u);
    v74 = v73(a1, v72);
    goto LABEL_88;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v75 = (v70 >> 19) & 0x3F | 0x40000000;
  writel_7(v75, *(_QWORD *)(a1 + 16) + 12920LL);
  v76 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v70 >> 19) & 0x3F;
  v77 = readl_8(v76 + 12920);
  if ( v77 != v75 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v75, v77);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v71, *(_QWORD *)(a1 + 16) + (v70 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_91:
  v78 = *((unsigned __int16 *)a4 + 16);
  v79 = *((unsigned __int16 *)a4 + 17);
  v80 = v4 + 32;
  v127[0] = 0;
  v81 = v79 | (v78 << 16);
  if ( v4 + 32 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v84 = *(_QWORD *)(a1 + 16) + v80;
LABEL_98:
    writel_7(v81, v84);
    goto LABEL_101;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v82 = *(_QWORD *)(a1 + 16) + v80;
    v83 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v83 - 1) != 925895004 )
      __break(0x8228u);
    v84 = v83(a1, v82);
    goto LABEL_98;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v85 = (v80 >> 19) & 0x3F | 0x40000000;
  writel_7(v85, *(_QWORD *)(a1 + 16) + 12920LL);
  v86 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v80 >> 19) & 0x3F;
  v87 = readl_8(v86 + 12920);
  if ( v87 != v85 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v85, v87);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v81, *(_QWORD *)(a1 + 16) + (v80 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_101:
  v88 = v4 + 40;
  v89 = a4[11];
  v127[0] = 0;
  if ( v4 + 40 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v92 = *(_QWORD *)(a1 + 16) + v88;
LABEL_108:
    writel_7(v89, v92);
    goto LABEL_111;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v90 = *(_QWORD *)(a1 + 16) + v88;
    v91 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v91 - 1) != 925895004 )
      __break(0x8228u);
    v92 = v91(a1, v90);
    goto LABEL_108;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v93 = (v88 >> 19) & 0x3F | 0x40000000;
  writel_7(v93, *(_QWORD *)(a1 + 16) + 12920LL);
  v94 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v88 >> 19) & 0x3F;
  v95 = readl_8(v94 + 12920);
  if ( v95 != v93 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v93, v95);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v89, *(_QWORD *)(a1 + 16) + (v88 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_111:
  v96 = v4 + 44;
  v127[0] = 0;
  if ( v4 + 44 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v99 = *(_QWORD *)(a1 + 16) + v96;
LABEL_118:
    writel_7(0, v99);
    goto LABEL_121;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v97 = *(_QWORD *)(a1 + 16) + v96;
    v98 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v98 - 1) != 925895004 )
      __break(0x8228u);
    v99 = v98(a1, v97);
    goto LABEL_118;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v100 = (v96 >> 19) & 0x3F | 0x40000000;
  writel_7(v100, *(_QWORD *)(a1 + 16) + 12920LL);
  v101 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v96 >> 19) & 0x3F;
  v102 = readl_8(v101 + 12920);
  if ( v102 != v100 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v100, v102);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(0, *(_QWORD *)(a1 + 16) + (v96 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_121:
  v103 = v4 + 48;
  v127[0] = 0;
  if ( v4 + 48 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v106 = *(_QWORD *)(a1 + 16) + v103;
LABEL_128:
    writel_7(0, v106);
    goto LABEL_131;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v104 = *(_QWORD *)(a1 + 16) + v103;
    v105 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v105 - 1) != 925895004 )
      __break(0x8228u);
    v106 = v105(a1, v104);
    goto LABEL_128;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v107 = (v103 >> 19) & 0x3F | 0x40000000;
  writel_7(v107, *(_QWORD *)(a1 + 16) + 12920LL);
  v108 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v103 >> 19) & 0x3F;
  v109 = readl_8(v108 + 12920);
  if ( v109 != v107 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v107, v109);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(0, *(_QWORD *)(a1 + 16) + (v103 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_131:
  v110 = v4 + 52;
  v127[0] = 0;
  if ( v4 + 52 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v113 = *(_QWORD *)(a1 + 16) + v110;
LABEL_138:
    writel_7(0, v113);
    goto LABEL_141;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v111 = *(_QWORD *)(a1 + 16) + v110;
    v112 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v112 - 1) != 925895004 )
      __break(0x8228u);
    v113 = v112(a1, v111);
    goto LABEL_138;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v114 = (v110 >> 19) & 0x3F | 0x40000000;
  writel_7(v114, *(_QWORD *)(a1 + 16) + 12920LL);
  v115 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v110 >> 19) & 0x3F;
  v116 = readl_8(v115 + 12920);
  if ( v116 != v114 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v114, v116);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(0, *(_QWORD *)(a1 + 16) + (v110 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_141:
  v117 = *((unsigned __int8 *)a4 + 36);
  v118 = *((unsigned __int8 *)a4 + 40);
  v127[0] = 0;
  v119 = v117 & 0xE0FFFFFF | (v118 << 30) | ((*((_BYTE *)a4 + 41) & 0x1F) << 24);
  if ( v8 < 0x80000 || (*(_BYTE *)(v7 + 496) & 1) == 0 )
  {
    v122 = *(_QWORD *)(a1 + 16) + v8;
LABEL_148:
    writel_7(v119 | 0x100, v122);
    goto LABEL_151;
  }
  if ( *(_BYTE *)(v7 + 520) == 1 )
  {
    v120 = *(_QWORD *)(a1 + 16) + v8;
    v121 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
    if ( *((_DWORD *)v121 - 1) != 925895004 )
      __break(0x8228u);
    v122 = v121(a1, v120);
    goto LABEL_148;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
  v123 = (v8 >> 19) & 0x3F | 0x40000000;
  writel_7(v123, *(_QWORD *)(a1 + 16) + 12920LL);
  v124 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(v7 + 500) = (v8 >> 19) & 0x3F;
  v125 = readl_8(v124 + 12920);
  if ( v125 != v123 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v123, v125);
    if ( a1 )
      ++*(_DWORD *)(v7 + 676);
  }
  writel_7(v119 | 0x100, *(_QWORD *)(a1 + 16) + (v8 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v127);
LABEL_151:
  _ReadStatusReg(SP_EL0);
  return v4;
}
