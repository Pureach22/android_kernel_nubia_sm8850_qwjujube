__int64 __fastcall priv_dump_chaninfo(__int64 a1)
{
  __int64 v1; // x27
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x0
  unsigned int v8; // w21
  unsigned int v9; // w20
  __int64 v10; // x8
  int v11; // w0
  char v12; // w26
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w20
  unsigned int v19; // w21
  __int64 v20; // x8
  int v21; // w0
  unsigned int v22; // w21
  __int64 v23; // x8
  int v24; // w9
  __int64 v25; // x10
  __int64 v26; // x8
  __int64 v27; // x1
  unsigned int v28; // w20
  unsigned int v29; // w22
  __int64 v30; // x8
  int v31; // w0
  __int64 v32; // x8
  int v33; // w9
  __int64 v34; // x10
  __int64 v35; // x8
  __int64 v36; // x1
  unsigned int v37; // w20
  unsigned int v38; // w22
  __int64 v39; // x8
  int v40; // w0
  __int64 v41; // x8
  int v42; // w9
  unsigned int v43; // w20
  __int64 v44; // x10
  __int64 v45; // x8
  __int64 v46; // x21
  unsigned int v47; // w23
  unsigned int v48; // w22
  __int64 v49; // x8
  int v50; // w0
  int v51; // w22
  int v52; // w9
  __int64 v53; // x8
  unsigned int v54; // w20
  unsigned int v55; // w21
  __int64 v56; // x8
  int v57; // w0
  __int64 result; // x0
  int i; // w28
  int v60; // w9
  __int64 v61; // x10
  __int64 v62; // x8
  __int64 v63; // x0
  unsigned int v64; // w22
  unsigned int v65; // w26
  __int64 v66; // x8
  int v67; // w0
  unsigned int v68; // w26
  int m; // w26
  int v70; // w9
  __int64 v71; // x10
  __int64 v72; // x8
  __int64 v73; // x0
  unsigned int v74; // w21
  unsigned int v75; // w25
  __int64 v76; // x8
  int v77; // w0
  unsigned int v78; // w25
  __int64 v79; // x8
  int v80; // w9
  __int64 v81; // x10
  __int64 v82; // x8
  __int64 v83; // x1
  unsigned int v84; // w20
  unsigned int v85; // w21
  __int64 v86; // x8
  int v87; // w0
  __int64 v88; // x8
  int v89; // w9
  __int64 v90; // x10
  __int64 v91; // x8
  __int64 v92; // x1
  unsigned int v93; // w21
  unsigned int v94; // w20
  __int64 v95; // x8
  int v96; // w0
  int k; // w28
  int v98; // w9
  __int64 v99; // x10
  __int64 v100; // x8
  __int64 v101; // x0
  unsigned int v102; // w22
  unsigned int v103; // w26
  __int64 v104; // x8
  int v105; // w0
  unsigned __int16 v106; // w26
  int ii; // w26
  int v108; // w9
  __int64 v109; // x10
  __int64 v110; // x8
  __int64 v111; // x0
  unsigned int v112; // w21
  unsigned int v113; // w25
  __int64 v114; // x8
  int v115; // w0
  unsigned __int16 v116; // w25
  int j; // w28
  int v118; // w9
  __int64 v119; // x10
  __int64 v120; // x8
  __int64 v121; // x0
  unsigned int v122; // w22
  unsigned int v123; // w26
  __int64 v124; // x8
  int v125; // w0
  unsigned int v126; // w26
  int n; // w26
  int v128; // w9
  __int64 v129; // x10
  __int64 v130; // x8
  __int64 v131; // x0
  unsigned int v132; // w21
  unsigned int v133; // w25
  __int64 v134; // x8
  int v135; // w0
  unsigned int v136; // w25
  int v137; // [xsp+8h] [xbp-18h]
  char v138; // [xsp+Ch] [xbp-14h]
  _QWORD v139[2]; // [xsp+10h] [xbp-10h] BYREF

  v1 = a1 + 28672;
  v139[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 31089);
  v139[0] = 0;
  v5 = v3 + 106496;
  v6 = *(_QWORD *)(a1 + 30720);
  v7 = v5 + 672;
  if ( v4 == 1 && (v8 = v7 - v6, (unsigned int)(v7 - v6) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
    v9 = (v8 >> 19) & 0x3F | 0x40000000;
    writel_4(v9, *(_QWORD *)(a1 + 30720) + 12920LL);
    v10 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v1 + 2420) = (v8 >> 19) & 0x3F;
    v11 = readl_4(v10 + 12920);
    if ( v11 != v9 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v9,
        v11,
        12920);
    v12 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v8 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
  }
  else
  {
    v12 = readl_4(v7);
  }
  qdf_trace_msg(61, 5, "%s: E", "priv_dump_chaninfo");
  v13 = *(_QWORD *)(a1 + 40);
  v14 = *(unsigned __int8 *)(v1 + 2417);
  v139[0] = 0;
  v15 = v13 + 106496;
  v16 = *(_QWORD *)(a1 + 30720);
  v17 = v15 + 880;
  if ( v14 == 1 && (v18 = v17 - v16, (unsigned int)(v17 - v16) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
    v19 = (v18 >> 19) & 0x3F | 0x40000000;
    writel_4(v19, *(_QWORD *)(a1 + 30720) + 12920LL);
    v20 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v1 + 2420) = (v18 >> 19) & 0x3F;
    v21 = readl_4(v20 + 12920);
    if ( v21 != v19 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v19,
        v21,
        12920);
    v22 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v18 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
    if ( (v12 & 1) == 0 )
    {
LABEL_19:
      if ( (v12 & 2) == 0 )
        goto LABEL_28;
      goto LABEL_20;
    }
  }
  else
  {
    v22 = readl_4(v17);
    if ( (v12 & 1) == 0 )
      goto LABEL_19;
  }
  v23 = *(_QWORD *)(a1 + 40);
  v24 = *(unsigned __int8 *)(v1 + 2417);
  v139[0] = 0;
  v25 = v23 + 102400;
  v26 = *(_QWORD *)(a1 + 30720);
  v27 = v25 + 2196;
  if ( v24 == 1 )
  {
    v28 = v27 - v26;
    if ( (unsigned int)(v27 - v26) >> 19 )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
      v29 = (v28 >> 19) & 0x3F | 0x40000000;
      writel_4(v29, *(_QWORD *)(a1 + 30720) + 12920LL);
      v30 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(v1 + 2420) = (v28 >> 19) & 0x3F;
      v31 = readl_4(v30 + 12920);
      if ( v31 != v29 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v29,
          v31,
          12920);
      writel_4(2147496448LL, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v28 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
      goto LABEL_19;
    }
  }
  writel_4(2147496448LL, v27);
  if ( (v12 & 2) == 0 )
    goto LABEL_28;
LABEL_20:
  v32 = *(_QWORD *)(a1 + 40);
  v33 = *(unsigned __int8 *)(v1 + 2417);
  v139[0] = 0;
  v34 = v32 + 106496;
  v35 = *(_QWORD *)(a1 + 30720);
  v36 = v34 + 2196;
  if ( v33 == 1 && (v37 = v36 - v35, (unsigned int)(v36 - v35) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
    v38 = (v37 >> 19) & 0x3F | 0x40000000;
    writel_4(v38, *(_QWORD *)(a1 + 30720) + 12920LL);
    v39 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v1 + 2420) = (v37 >> 19) & 0x3F;
    v40 = readl_4(v39 + 12920);
    if ( v40 != v38 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v38,
        v40,
        12920);
    writel_4(2147496448LL, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v37 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
  }
  else
  {
    writel_4(2147496448LL, v36);
  }
LABEL_28:
  v41 = *(_QWORD *)(a1 + 40);
  v42 = *(unsigned __int8 *)(v1 + 2417);
  v43 = v22 >> 4;
  v139[0] = 0;
  v44 = v41 + 106496;
  v45 = *(_QWORD *)(a1 + 30720);
  v46 = v44 + 880;
  if ( v42 == 1 && (v47 = v46 - v45, (unsigned int)(v46 - v45) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
    v48 = (v47 >> 19) & 0x3F | 0x40000000;
    writel_4(v48, *(_QWORD *)(a1 + 30720) + 12920LL);
    v49 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v1 + 2420) = (v47 >> 19) & 0x3F;
    v50 = readl_4(v49 + 12920);
    if ( v50 != v48 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v48,
        v50,
        12920);
    v51 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v47 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
  }
  else
  {
    v51 = readl_4(v44 + 880);
  }
  v52 = *(unsigned __int8 *)(v1 + 2417);
  v53 = *(_QWORD *)(a1 + 30720);
  v139[0] = 0;
  v137 = v43 & 0x30;
  if ( v52 != 1 || (v54 = v46 - v53, !((unsigned int)(v46 - v53) >> 19)) )
  {
    writel_4(v51 & 0xFFFFFFF7, v46);
    v138 = v12;
    if ( (v12 & 1) == 0 )
      goto LABEL_41;
    goto LABEL_43;
  }
  pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
  v55 = (v54 >> 19) & 0x3F | 0x40000000;
  writel_4(v55, *(_QWORD *)(a1 + 30720) + 12920LL);
  v56 = *(_QWORD *)(a1 + 30720);
  *(_DWORD *)(v1 + 2420) = (v54 >> 19) & 0x3F;
  v57 = readl_4(v56 + 12920);
  if ( v57 != v55 )
    qdf_trace_msg(
      61,
      2,
      "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
      "hif_reg_write_result_check",
      v55,
      v57,
      12920);
  writel_4(v51 & 0xFFFFFFF7, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v54 & 0x7FFFFLL) + 0x80000);
  pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
  v138 = v12;
  if ( (v12 & 1) != 0 )
  {
LABEL_43:
    if ( v137 )
    {
      for ( i = 0; i != 60; ++i )
      {
        v60 = *(unsigned __int8 *)(v1 + 2417);
        v61 = *(_QWORD *)(a1 + 40);
        v62 = *(_QWORD *)(a1 + 30720);
        v139[0] = 0;
        v63 = v61 + 104600;
        if ( v60 == 1 && (v64 = v63 - v62, (unsigned int)(v63 - v62) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
          v65 = (v64 >> 19) & 0x3F | 0x40000000;
          writel_4(v65, *(_QWORD *)(a1 + 30720) + 12920LL);
          v66 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(v1 + 2420) = (v64 >> 19) & 0x3F;
          v67 = readl_4(v66 + 12920);
          if ( v67 != v65 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v65,
              v67,
              12920);
          v68 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v64 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        }
        else
        {
          v68 = readl_4(v63);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", HIWORD(v68));
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", (unsigned __int16)v68);
        if ( (i & 1) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_chaninfo");
      }
      v79 = *(_QWORD *)(a1 + 40);
      v80 = *(unsigned __int8 *)(v1 + 2417);
      v139[0] = 0;
      v81 = v79 + 102400;
      v82 = *(_QWORD *)(a1 + 30720);
      v83 = v81 + 2196;
      if ( v80 == 1 && (v84 = v83 - v82, (unsigned int)(v83 - v82) >> 19) )
      {
        pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        v85 = (v84 >> 19) & 0x3F | 0x40000000;
        writel_4(v85, *(_QWORD *)(a1 + 30720) + 12920LL);
        v86 = *(_QWORD *)(a1 + 30720);
        *(_DWORD *)(v1 + 2420) = (v84 >> 19) & 0x3F;
        v87 = readl_4(v86 + 12920);
        if ( v87 != v85 )
          qdf_trace_msg(
            61,
            2,
            "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
            "hif_reg_write_result_check",
            v85,
            v87,
            12920);
        writel_4(2147496704LL, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v84 & 0x7FFFFLL) + 0x80000);
        pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
      }
      else
      {
        writel_4(2147496704LL, v83);
      }
      for ( j = 0; j != 61; ++j )
      {
        v118 = *(unsigned __int8 *)(v1 + 2417);
        v119 = *(_QWORD *)(a1 + 40);
        v120 = *(_QWORD *)(a1 + 30720);
        v139[0] = 0;
        v121 = v119 + 104600;
        if ( v118 == 1 && (v122 = v121 - v120, (unsigned int)(v121 - v120) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
          v123 = (v122 >> 19) & 0x3F | 0x40000000;
          writel_4(v123, *(_QWORD *)(a1 + 30720) + 12920LL);
          v124 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(v1 + 2420) = (v122 >> 19) & 0x3F;
          v125 = readl_4(v124 + 12920);
          if ( v125 != v123 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v123,
              v125,
              12920);
          v126 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v122 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        }
        else
        {
          v126 = readl_4(v121);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", HIWORD(v126));
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", (unsigned __int16)v126);
        if ( (j & 1) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_chaninfo");
      }
    }
    else
    {
      for ( k = 0; k != 53; ++k )
      {
        v98 = *(unsigned __int8 *)(v1 + 2417);
        v99 = *(_QWORD *)(a1 + 40);
        v100 = *(_QWORD *)(a1 + 30720);
        v139[0] = 0;
        v101 = v99 + 104600;
        if ( v98 == 1 && (v102 = v101 - v100, (unsigned int)(v101 - v100) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
          v103 = (v102 >> 19) & 0x3F | 0x40000000;
          writel_4(v103, *(_QWORD *)(a1 + 30720) + 12920LL);
          v104 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(v1 + 2420) = (v102 >> 19) & 0x3F;
          v105 = readl_4(v104 + 12920);
          if ( v105 != v103 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v103,
              v105,
              12920);
          v106 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v102 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        }
        else
        {
          v106 = readl_4(v101);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", v106);
        if ( (k & 3) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_chaninfo");
      }
    }
  }
LABEL_41:
  if ( (v138 & 2) != 0 )
  {
    if ( v137 )
    {
      for ( m = 0; m != 60; ++m )
      {
        v70 = *(unsigned __int8 *)(v1 + 2417);
        v71 = *(_QWORD *)(a1 + 40);
        v72 = *(_QWORD *)(a1 + 30720);
        v139[0] = 0;
        v73 = v71 + 108696;
        if ( v70 == 1 && (v74 = v73 - v72, (unsigned int)(v73 - v72) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
          v75 = (v74 >> 19) & 0x3F | 0x40000000;
          writel_4(v75, *(_QWORD *)(a1 + 30720) + 12920LL);
          v76 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(v1 + 2420) = (v74 >> 19) & 0x3F;
          v77 = readl_4(v76 + 12920);
          if ( v77 != v75 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v75,
              v77,
              12920);
          v78 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v74 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        }
        else
        {
          v78 = readl_4(v73);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x", "priv_dump_chaninfo", HIWORD(v78));
        qdf_trace_msg(56, 8, "%s: 0x%x", "priv_dump_chaninfo", (unsigned __int16)v78);
        if ( (m & 1) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_chaninfo");
      }
      v88 = *(_QWORD *)(a1 + 40);
      v89 = *(unsigned __int8 *)(v1 + 2417);
      v139[0] = 0;
      v90 = v88 + 106496;
      v91 = *(_QWORD *)(a1 + 30720);
      v92 = v90 + 2196;
      if ( v89 == 1 && (v93 = v92 - v91, (unsigned int)(v92 - v91) >> 19) )
      {
        pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        v94 = (v93 >> 19) & 0x3F | 0x40000000;
        writel_4(v94, *(_QWORD *)(a1 + 30720) + 12920LL);
        v95 = *(_QWORD *)(a1 + 30720);
        *(_DWORD *)(v1 + 2420) = (v93 >> 19) & 0x3F;
        v96 = readl_4(v95 + 12920);
        if ( v96 != v94 )
          qdf_trace_msg(
            61,
            2,
            "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
            "hif_reg_write_result_check",
            v94,
            v96,
            12920);
        writel_4(2147496704LL, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v93 & 0x7FFFFLL) + 0x80000);
        pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
      }
      else
      {
        writel_4(2147496704LL, v92);
      }
      for ( n = 0; n != 61; ++n )
      {
        v128 = *(unsigned __int8 *)(v1 + 2417);
        v129 = *(_QWORD *)(a1 + 40);
        v130 = *(_QWORD *)(a1 + 30720);
        v139[0] = 0;
        v131 = v129 + 108696;
        if ( v128 == 1 && (v132 = v131 - v130, (unsigned int)(v131 - v130) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
          v133 = (v132 >> 19) & 0x3F | 0x40000000;
          writel_4(v133, *(_QWORD *)(a1 + 30720) + 12920LL);
          v134 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(v1 + 2420) = (v132 >> 19) & 0x3F;
          v135 = readl_4(v134 + 12920);
          if ( v135 != v133 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v133,
              v135,
              12920);
          v136 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v132 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        }
        else
        {
          v136 = readl_4(v131);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", HIWORD(v136));
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", (unsigned __int16)v136);
        if ( (n & 1) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_chaninfo");
      }
    }
    else
    {
      for ( ii = 0; ii != 53; ++ii )
      {
        v108 = *(unsigned __int8 *)(v1 + 2417);
        v109 = *(_QWORD *)(a1 + 40);
        v110 = *(_QWORD *)(a1 + 30720);
        v139[0] = 0;
        v111 = v109 + 108696;
        if ( v108 == 1 && (v112 = v111 - v110, (unsigned int)(v111 - v110) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v139);
          v113 = (v112 >> 19) & 0x3F | 0x40000000;
          writel_4(v113, *(_QWORD *)(a1 + 30720) + 12920LL);
          v114 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(v1 + 2420) = (v112 >> 19) & 0x3F;
          v115 = readl_4(v114 + 12920);
          if ( v115 != v113 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v113,
              v115,
              12920);
          v116 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v112 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v139);
        }
        else
        {
          v116 = readl_4(v111);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_chaninfo", v116);
        if ( (ii & 3) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_chaninfo");
      }
    }
  }
  result = qdf_trace_msg(61, 5, "%s: X", "priv_dump_chaninfo");
  _ReadStatusReg(SP_EL0);
  return result;
}
