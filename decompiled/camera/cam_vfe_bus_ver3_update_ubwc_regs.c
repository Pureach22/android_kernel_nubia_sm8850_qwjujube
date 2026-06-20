__int64 __fastcall cam_vfe_bus_ver3_update_ubwc_regs(__int64 result, _DWORD *a2, __int64 a3, _DWORD *a4)
{
  __int64 v4; // x7
  _DWORD *v5; // x19
  int v6; // w8
  int v7; // w9
  __int64 v8; // x8
  int v9; // w10
  char v10; // w9
  __int64 v11; // x7
  int v12; // w8
  int v13; // w9
  __int64 v14; // x8
  int v15; // w10
  char v16; // w9
  __int64 v17; // x7
  int v18; // w8
  int v19; // w9
  __int64 v20; // x8
  int v21; // w10
  char v22; // w9
  __int64 v23; // x7
  int v24; // w8
  int v25; // w9
  __int64 v26; // x8
  int v27; // w10
  char v28; // w9
  __int64 v29; // x7
  int v30; // w8
  int v31; // w9
  __int64 v32; // x8
  int v33; // w10
  char v34; // w9
  __int64 v35; // x7
  int v36; // w8
  int v37; // w9
  __int64 v38; // x8
  int v39; // w10
  char v40; // w9
  __int64 v41; // x7
  int v42; // w8
  int v43; // w9
  __int64 v44; // x8
  int v45; // w10
  char v46; // w8
  __int64 v47; // x20
  _DWORD *v48; // x21
  _DWORD *v49; // x19
  _DWORD *v50; // [xsp+8h] [xbp-18h]
  _DWORD *v51; // [xsp+8h] [xbp-18h]
  _DWORD *v52; // [xsp+8h] [xbp-18h]
  _DWORD *v53; // [xsp+8h] [xbp-18h]
  _DWORD *v54; // [xsp+8h] [xbp-18h]
  _DWORD *v55; // [xsp+8h] [xbp-18h]
  _DWORD *v56; // [xsp+8h] [xbp-18h]
  _DWORD *v57; // [xsp+8h] [xbp-18h]
  _DWORD *v58; // [xsp+8h] [xbp-18h]
  _DWORD *v59; // [xsp+8h] [xbp-18h]
  _DWORD *v60; // [xsp+8h] [xbp-18h]
  _DWORD *v61; // [xsp+8h] [xbp-18h]
  __int64 v62; // [xsp+10h] [xbp-10h]
  __int64 v63; // [xsp+10h] [xbp-10h]
  __int64 v64; // [xsp+10h] [xbp-10h]
  __int64 v65; // [xsp+10h] [xbp-10h]
  __int64 v66; // [xsp+10h] [xbp-10h]
  __int64 v67; // [xsp+10h] [xbp-10h]
  __int64 v68; // [xsp+10h] [xbp-10h]
  __int64 v69; // [xsp+10h] [xbp-10h]
  __int64 v70; // [xsp+10h] [xbp-10h]
  __int64 v71; // [xsp+10h] [xbp-10h]
  __int64 v72; // [xsp+10h] [xbp-10h]
  __int64 v73; // [xsp+10h] [xbp-10h]
  _DWORD *v74; // [xsp+18h] [xbp-8h]
  _DWORD *v75; // [xsp+18h] [xbp-8h]
  _DWORD *v76; // [xsp+18h] [xbp-8h]
  _DWORD *v77; // [xsp+18h] [xbp-8h]
  _DWORD *v78; // [xsp+18h] [xbp-8h]
  _DWORD *v79; // [xsp+18h] [xbp-8h]
  _DWORD *v80; // [xsp+18h] [xbp-8h]
  _DWORD *v81; // [xsp+18h] [xbp-8h]
  _DWORD *v82; // [xsp+18h] [xbp-8h]
  _DWORD *v83; // [xsp+18h] [xbp-8h]
  _DWORD *v84; // [xsp+18h] [xbp-8h]
  _DWORD *v85; // [xsp+18h] [xbp-8h]
  _DWORD *v86; // [xsp+18h] [xbp-8h]
  __int64 v87; // [xsp+38h] [xbp+18h]
  __int64 v88; // [xsp+38h] [xbp+18h]
  __int64 v89; // [xsp+38h] [xbp+18h]
  __int64 v90; // [xsp+38h] [xbp+18h]
  __int64 v91; // [xsp+38h] [xbp+18h]
  __int64 v92; // [xsp+38h] [xbp+18h]
  __int64 v93; // [xsp+38h] [xbp+18h]
  __int64 v94; // [xsp+38h] [xbp+18h]
  __int64 v95; // [xsp+38h] [xbp+18h]
  __int64 v96; // [xsp+38h] [xbp+18h]
  __int64 v97; // [xsp+38h] [xbp+18h]
  __int64 v98; // [xsp+38h] [xbp+18h]
  __int64 v99; // [xsp+38h] [xbp+18h]
  __int64 v100; // [xsp+38h] [xbp+18h]

  if ( !result || !a2 || !a3 || !a4 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_bus_ver3_update_ubwc_regs",
             3737,
             "Invalid args");
  v4 = (unsigned int)*a4;
  v5 = *(_DWORD **)(*(_QWORD *)(result + 8) + 88LL);
  if ( (unsigned int)v4 >= 0x1A3 )
  {
    v93 = result;
    v80 = a2;
    v47 = a3;
    v48 = a4;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3746,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      420);
    a2 = v80;
    result = v93;
    a4 = v48;
    a3 = v47;
  }
  else
  {
    v6 = *(_DWORD *)(result + 156);
    v7 = v5[1];
    *a4 = v4 + 1;
    *(_DWORD *)(a3 + 4 * v4) = v7 + v6;
    v8 = (unsigned int)*a4;
    v9 = a2[2];
    *a4 = v8 + 1;
    *(_DWORD *)(a3 + 4 * v8) = v9;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v74 = a2;
    v87 = result;
    v50 = a4;
    v62 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3748,
      "VFE:%u WM:%d meta stride 0x%X",
      *(_DWORD *)(*(_QWORD *)result + 8LL),
      *(_DWORD *)(result + 120),
      *(_DWORD *)(a3 + 4LL * (unsigned int)(*a4 - 1)));
    a4 = v50;
    a3 = v62;
    a2 = v74;
    result = v87;
  }
  if ( *(_BYTE *)(*(_QWORD *)result + 34669LL) == 1 )
  {
    v10 = debug_mdl;
    a2[3] &= ~v5[9];
    if ( (v10 & 8) != 0 && !debug_priority )
    {
      v86 = a2;
      v99 = result;
      v61 = a4;
      v73 = a3;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v10 & 8,
        4,
        "cam_vfe_bus_ver3_update_ubwc_regs",
        3754,
        "Force disable UBWC compression on VFE:%u WM:%d",
        *(_DWORD *)(*(_QWORD *)result + 8LL),
        *(_DWORD *)(result + 120));
      a4 = v61;
      a3 = v73;
      a2 = v86;
      result = v99;
    }
  }
  v11 = (unsigned int)*a4;
  if ( (unsigned int)v11 >= 0x1A3 )
  {
    v94 = result;
    v81 = a2;
    v56 = a4;
    v68 = a3;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3759,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      420);
    a4 = v56;
    a3 = v68;
    a2 = v81;
    result = v94;
    v16 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_18;
  }
  else
  {
    v12 = *(_DWORD *)(result + 156);
    v13 = v5[2];
    *a4 = v11 + 1;
    *(_DWORD *)(a3 + 4 * v11) = v13 + v12;
    v14 = (unsigned int)*a4;
    v15 = a2[3];
    *a4 = v14 + 1;
    *(_DWORD *)(a3 + 4 * v14) = v15;
    v16 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_18;
  }
  if ( !debug_priority )
  {
    v75 = a2;
    v88 = result;
    v51 = a4;
    v63 = a3;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v16 & 8,
      4,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3761,
      "VFE:%u WM:%d ubwc_mode_cfg 0x%X",
      *(_DWORD *)(*(_QWORD *)result + 8LL),
      *(_DWORD *)(result + 120),
      *(_DWORD *)(a3 + 4LL * (unsigned int)(*a4 - 1)));
    a4 = v51;
    a3 = v63;
    a2 = v75;
    result = v88;
  }
LABEL_18:
  v17 = (unsigned int)*a4;
  if ( (unsigned int)v17 >= 0x1A3 )
  {
    v95 = result;
    v82 = a2;
    v57 = a4;
    v69 = a3;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3765,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      420);
    a4 = v57;
    a3 = v69;
    a2 = v82;
    result = v95;
    v22 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_22;
  }
  else
  {
    v18 = *(_DWORD *)(result + 156);
    v19 = v5[4];
    *a4 = v17 + 1;
    *(_DWORD *)(a3 + 4 * v17) = v19 + v18;
    v20 = (unsigned int)*a4;
    v21 = a2[5];
    *a4 = v20 + 1;
    *(_DWORD *)(a3 + 4 * v20) = v21;
    v22 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_22;
  }
  if ( !debug_priority )
  {
    v76 = a2;
    v89 = result;
    v52 = a4;
    v64 = a3;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v22 & 8,
      4,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3767,
      "VFE:%u WM:%d ubwc_ctrl_2 0x%X",
      *(_DWORD *)(*(_QWORD *)result + 8LL),
      *(_DWORD *)(result + 120),
      *(_DWORD *)(a3 + 4LL * (unsigned int)(*a4 - 1)));
    a4 = v52;
    a3 = v64;
    a2 = v76;
    result = v89;
  }
LABEL_22:
  v23 = (unsigned int)*a4;
  if ( (unsigned int)v23 >= 0x1A3 )
  {
    v96 = result;
    v83 = a2;
    v58 = a4;
    v70 = a3;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3772,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      420);
    a4 = v58;
    a3 = v70;
    a2 = v83;
    result = v96;
    v28 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_26;
  }
  else
  {
    v24 = *(_DWORD *)(result + 156);
    v25 = v5[5];
    *a4 = v23 + 1;
    *(_DWORD *)(a3 + 4 * v23) = v25 + v24;
    v26 = (unsigned int)*a4;
    v27 = a2[6];
    *a4 = v26 + 1;
    *(_DWORD *)(a3 + 4 * v26) = v27;
    v28 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_26;
  }
  if ( !debug_priority )
  {
    v77 = a2;
    v90 = result;
    v53 = a4;
    v65 = a3;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v28 & 8,
      4,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3774,
      "VFE:%u WM:%d lossy_thresh0 0x%X",
      *(_DWORD *)(*(_QWORD *)result + 8LL),
      *(_DWORD *)(result + 120),
      *(_DWORD *)(a3 + 4LL * (unsigned int)(*a4 - 1)));
    a4 = v53;
    a3 = v65;
    a2 = v77;
    result = v90;
  }
LABEL_26:
  v29 = (unsigned int)*a4;
  if ( (unsigned int)v29 >= 0x1A3 )
  {
    v97 = result;
    v84 = a2;
    v59 = a4;
    v71 = a3;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3779,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      420);
    a4 = v59;
    a3 = v71;
    a2 = v84;
    result = v97;
    v34 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_30;
  }
  else
  {
    v30 = *(_DWORD *)(result + 156);
    v31 = v5[6];
    *a4 = v29 + 1;
    *(_DWORD *)(a3 + 4 * v29) = v31 + v30;
    v32 = (unsigned int)*a4;
    v33 = a2[7];
    *a4 = v32 + 1;
    *(_DWORD *)(a3 + 4 * v32) = v33;
    v34 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_30;
  }
  if ( !debug_priority )
  {
    v78 = a2;
    v91 = result;
    v54 = a4;
    v66 = a3;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v34 & 8,
      4,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3781,
      "VFE:%u WM:%d lossy_thresh1 0x%X",
      *(_DWORD *)(*(_QWORD *)result + 8LL),
      *(_DWORD *)(result + 120),
      *(_DWORD *)(a3 + 4LL * (unsigned int)(*a4 - 1)));
    a4 = v54;
    a3 = v66;
    a2 = v78;
    result = v91;
  }
LABEL_30:
  v35 = (unsigned int)*a4;
  if ( (unsigned int)v35 >= 0x1A3 )
  {
    v98 = result;
    v85 = a2;
    v60 = a4;
    v72 = a3;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3786,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      420);
    a4 = v60;
    a3 = v72;
    a2 = v85;
    result = v98;
    v40 = debug_mdl;
    if ( (debug_mdl & 8) != 0 )
    {
LABEL_32:
      if ( !debug_priority )
      {
        v79 = a2;
        v92 = result;
        v55 = a4;
        v67 = a3;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v40 & 8,
          4,
          "cam_vfe_bus_ver3_update_ubwc_regs",
          3788,
          "VFE:%u WM:%d off_lossy_var 0x%X",
          *(_DWORD *)(*(_QWORD *)result + 8LL),
          *(_DWORD *)(result + 120),
          *(_DWORD *)(a3 + 4LL * (unsigned int)(*a4 - 1)));
        a4 = v55;
        a3 = v67;
        a2 = v79;
        result = v92;
      }
    }
  }
  else
  {
    v36 = *(_DWORD *)(result + 156);
    v37 = v5[7];
    *a4 = v35 + 1;
    *(_DWORD *)(a3 + 4 * v35) = v37 + v36;
    v38 = (unsigned int)*a4;
    v39 = a2[8];
    *a4 = v38 + 1;
    *(_DWORD *)(a3 + 4 * v38) = v39;
    v40 = debug_mdl;
    if ( (debug_mdl & 8) != 0 )
      goto LABEL_32;
  }
  if ( a2[9] > 0xFFFEu )
    return result;
  v41 = (unsigned int)*a4;
  if ( (unsigned int)v41 >= 0x1A3 )
  {
    v100 = result;
    v49 = a2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_ubwc_regs",
      3798,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      420);
    result = v100;
    a2 = v49;
    v46 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      return result;
  }
  else
  {
    v42 = *(_DWORD *)(result + 156);
    v43 = v5[8];
    *a4 = v41 + 1;
    *(_DWORD *)(a3 + 4 * v41) = v43 + v42;
    v44 = (unsigned int)*a4;
    v45 = a2[9];
    *a4 = v44 + 1;
    *(_DWORD *)(a3 + 4 * v44) = v45;
    v46 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      return result;
  }
  if ( !debug_priority )
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v46 & 8,
             4,
             "cam_vfe_bus_ver3_update_ubwc_regs",
             3801,
             "VFE:%u WM:%d ubwc bw limit 0x%X",
             *(_DWORD *)(*(_QWORD *)result + 8LL),
             *(_DWORD *)(result + 120),
             a2[9]);
  return result;
}
