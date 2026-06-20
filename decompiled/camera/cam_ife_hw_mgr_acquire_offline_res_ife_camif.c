__int64 __fastcall cam_ife_hw_mgr_acquire_offline_res_ife_camif(
        __int64 a1,
        __int64 a2,
        char a3,
        _DWORD *a4,
        __int64 a5)
{
  __int64 v6; // x8
  __int64 v7; // x24
  _QWORD *v8; // x20
  __int64 v9; // x23
  _QWORD *v10; // x8
  __int64 v13; // x9
  __int64 v14; // x8
  char v15; // w10
  __int64 v16; // x9
  int v17; // w10
  __int64 *v18; // x8
  int v19; // w9
  __int64 v20; // x25
  __int64 (__fastcall *v21)(__int64, __int64 *, __int64); // x8
  __int64 v22; // x0
  int v23; // w0
  __int64 v24; // x27
  __int64 v25; // x8
  __int64 v26; // x6
  int v27; // w8
  __int64 result; // x0
  __int64 *v29; // x8
  __int64 (__fastcall *v30)(__int64, __int64 *, __int64); // x8
  __int64 v31; // x0
  __int64 *v32; // x8
  __int64 (__fastcall *v33)(__int64, __int64 *, __int64); // x8
  __int64 v34; // x0
  __int64 *v35; // x8
  __int64 (__fastcall *v36)(__int64, __int64 *, __int64); // x8
  __int64 v37; // x0
  __int64 *v38; // x8
  __int64 (__fastcall *v39)(__int64, __int64 *, __int64); // x8
  __int64 v40; // x0
  __int64 *v41; // x8
  __int64 (__fastcall *v42)(__int64, __int64 *, __int64); // x8
  __int64 v43; // x0
  __int64 *v44; // x8
  __int64 (__fastcall *v45)(__int64, __int64 *, __int64); // x8
  __int64 v46; // x0
  __int64 *v47; // x8
  __int64 (__fastcall *v48)(__int64, __int64 *, __int64); // x8
  __int64 v49; // x0
  unsigned int v50; // w21
  _QWORD *v51; // x1
  __int64 v52; // x8
  int v53; // w8
  __int64 v54; // x2
  _QWORD *v55; // x1
  __int64 *v56; // x8
  __int64 (__fastcall *v57)(__int64, __int64 *, __int64); // x8
  __int64 v58; // x0
  int v59; // w0
  __int64 v60; // x24
  __int64 *v61; // x8
  __int64 (__fastcall *v62)(__int64, __int64 *, __int64); // x8
  __int64 v63; // x0
  __int64 *v64; // x8
  __int64 (__fastcall *v65)(__int64, __int64 *, __int64); // x8
  __int64 v66; // x0
  __int64 *v67; // x8
  __int64 (__fastcall *v68)(__int64, __int64 *, __int64); // x8
  __int64 v69; // x0
  __int64 *v70; // x8
  __int64 (__fastcall *v71)(__int64, __int64 *, __int64); // x8
  __int64 v72; // x0
  __int64 *v73; // x8
  __int64 (__fastcall *v74)(__int64, __int64 *, __int64); // x8
  __int64 v75; // x0
  __int64 *v76; // x8
  __int64 (__fastcall *v77)(__int64, __int64 *, __int64); // x8
  __int64 v78; // x0
  __int64 *v79; // x8
  __int64 v80; // x10
  char v81; // w9
  __int64 (__fastcall *v82)(__int64, __int64 *, __int64); // x8
  __int64 v83; // x0
  int v84; // w8
  __int64 v85; // x6
  int v86; // w8
  int v87; // w7
  unsigned int v88; // w19
  __int64 v89; // x8
  int v90; // w8
  __int64 v91; // [xsp+8h] [xbp-78h] BYREF
  __int64 v92; // [xsp+10h] [xbp-70h]
  __int64 v93; // [xsp+18h] [xbp-68h]
  __int64 (__fastcall *v94)(); // [xsp+20h] [xbp-60h]
  __int64 v95; // [xsp+28h] [xbp-58h]
  __int64 v96; // [xsp+30h] [xbp-50h]
  __int64 v97; // [xsp+38h] [xbp-48h]
  __int64 v98; // [xsp+40h] [xbp-40h]
  __int64 v99; // [xsp+48h] [xbp-38h]
  __int64 v100; // [xsp+50h] [xbp-30h]
  __int64 v101; // [xsp+58h] [xbp-28h]
  __int64 v102; // [xsp+60h] [xbp-20h]
  __int64 v103; // [xsp+68h] [xbp-18h]
  __int64 v104; // [xsp+70h] [xbp-10h]
  __int64 v105; // [xsp+78h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 256);
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = nullptr;
  v91 = 0;
  v92 = 0;
  if ( !v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_offline_res_ife_camif",
      5287,
      "BUS RD resource has not been acquired, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    result = 4294967274LL;
    goto LABEL_163;
  }
  v7 = *(_QWORD *)(a1 + 72);
  v8 = *(_QWORD **)(a1 + 288);
  v9 = a1 + 288;
  if ( v8 == (_QWORD *)(a1 + 288) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_get_res",
      2078,
      "No more free ife hw mgr ctx");
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_offline_res_ife_camif",
      5294,
      "No free resource, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    result = 0xFFFFFFFFLL;
    goto LABEL_163;
  }
  v10 = (_QWORD *)v8[1];
  if ( (_QWORD *)*v10 == v8 && (v13 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
  {
    *(_QWORD *)(v13 + 8) = v10;
    *v10 = v13;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 288));
    a2 = v80;
    a3 = v81;
  }
  *v8 = v8;
  v8[1] = v8;
  LODWORD(v91) = 4;
  v14 = *(_QWORD *)(a1 + 8728);
  v15 = *(_BYTE *)(a1 + 9380);
  v93 = a1;
  v94 = cam_ife_hw_mgr_event_handler;
  v16 = *(_QWORD *)(a1 + 16);
  v100 = v14;
  LOBYTE(v14) = *(_BYTE *)(a1 + 9378);
  v92 = v16;
  LOBYTE(v103) = v14;
  v102 = a2;
  LODWORD(v14) = *(unsigned __int8 *)(v7 + 81883);
  BYTE1(v103) = v15;
  BYTE2(v103) = 1;
  if ( (_DWORD)v14 == 1 )
    BYTE2(v103) = *(_DWORD *)(a1 + 9312) == 2;
  v17 = *(unsigned __int8 *)(a1 + 9379);
  v18 = *(__int64 **)(v7 + 160);
  if ( (a3 & 1) != 0 )
    v19 = 9;
  else
    v19 = 0;
  LODWORD(v98) = v19;
  LODWORD(v101) = v17;
  if ( v18 && (v20 = *v18) != 0 )
  {
    v21 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
    v22 = *(_QWORD *)(v20 + 112);
    if ( *((_DWORD *)v21 - 1) != 1989616049 )
      __break(0x8228u);
    v23 = v21(v22, &v91, 112);
    if ( !v23 )
    {
      v24 = 0;
      v25 = v97;
      if ( v97 )
        goto LABEL_17;
      goto LABEL_64;
    }
  }
  else
  {
    v23 = 0;
  }
  v29 = *(__int64 **)(v7 + 168);
  if ( !v29 )
    goto LABEL_27;
  v20 = *v29;
  if ( !*v29 )
    goto LABEL_27;
  v30 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
  v31 = *(_QWORD *)(v20 + 112);
  if ( *((_DWORD *)v30 - 1) != 1989616049 )
    __break(0x8228u);
  v23 = v30(v31, &v91, 112);
  if ( !v23 )
  {
    v24 = 1;
    v25 = v97;
    if ( !v97 )
      goto LABEL_64;
  }
  else
  {
LABEL_27:
    v32 = *(__int64 **)(v7 + 176);
    if ( !v32 )
      goto LABEL_32;
    v20 = *v32;
    if ( !*v32 )
      goto LABEL_32;
    v33 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
    v34 = *(_QWORD *)(v20 + 112);
    if ( *((_DWORD *)v33 - 1) != 1989616049 )
      __break(0x8228u);
    v23 = v33(v34, &v91, 112);
    if ( !v23 )
    {
      v24 = 2;
      v25 = v97;
      if ( !v97 )
        goto LABEL_64;
    }
    else
    {
LABEL_32:
      v35 = *(__int64 **)(v7 + 184);
      if ( !v35 )
        goto LABEL_37;
      v20 = *v35;
      if ( !*v35 )
        goto LABEL_37;
      v36 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
      v37 = *(_QWORD *)(v20 + 112);
      if ( *((_DWORD *)v36 - 1) != 1989616049 )
        __break(0x8228u);
      v23 = v36(v37, &v91, 112);
      if ( !v23 )
      {
        v24 = 3;
        v25 = v97;
        if ( !v97 )
          goto LABEL_64;
      }
      else
      {
LABEL_37:
        v38 = *(__int64 **)(v7 + 192);
        if ( !v38 )
          goto LABEL_42;
        v20 = *v38;
        if ( !*v38 )
          goto LABEL_42;
        v39 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
        v40 = *(_QWORD *)(v20 + 112);
        if ( *((_DWORD *)v39 - 1) != 1989616049 )
          __break(0x8228u);
        v23 = v39(v40, &v91, 112);
        if ( !v23 )
        {
          v24 = 4;
          v25 = v97;
          if ( !v97 )
            goto LABEL_64;
        }
        else
        {
LABEL_42:
          v41 = *(__int64 **)(v7 + 200);
          if ( !v41 )
            goto LABEL_47;
          v20 = *v41;
          if ( !*v41 )
            goto LABEL_47;
          v42 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
          v43 = *(_QWORD *)(v20 + 112);
          if ( *((_DWORD *)v42 - 1) != 1989616049 )
            __break(0x8228u);
          v23 = v42(v43, &v91, 112);
          if ( !v23 )
          {
            v24 = 5;
            v25 = v97;
            if ( !v97 )
              goto LABEL_64;
          }
          else
          {
LABEL_47:
            v44 = *(__int64 **)(v7 + 208);
            if ( !v44 )
              goto LABEL_52;
            v20 = *v44;
            if ( !*v44 )
              goto LABEL_52;
            v45 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
            v46 = *(_QWORD *)(v20 + 112);
            if ( *((_DWORD *)v45 - 1) != 1989616049 )
              __break(0x8228u);
            v23 = v45(v46, &v91, 112);
            if ( !v23 )
            {
              v24 = 6;
              v25 = v97;
              if ( !v97 )
                goto LABEL_64;
            }
            else
            {
LABEL_52:
              v47 = *(__int64 **)(v7 + 216);
              if ( !v47 )
                goto LABEL_65;
              v20 = *v47;
              if ( !*v47 )
                goto LABEL_65;
              v48 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
              v49 = *(_QWORD *)(v20 + 112);
              if ( *((_DWORD *)v48 - 1) != 1989616049 )
                __break(0x8228u);
              v23 = v48(v49, &v91, 112);
              if ( v23 )
                goto LABEL_65;
              v24 = 7;
              v25 = v97;
              if ( !v97 )
              {
LABEL_64:
                v23 = 0;
LABEL_65:
                v50 = v23;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_ife_hw_mgr_acquire_offline_res_ife_camif",
                  5341,
                  "Failed to acquire IFE LEFT rc: %d, ctx_idx: %u",
                  v23,
                  *(_DWORD *)(a1 + 56));
                if ( v8 )
                {
                  v51 = *(_QWORD **)(a1 + 296);
                  if ( v51 == v8 || *v51 != v9 )
                  {
                    _list_add_valid_or_report(v8);
                    result = v50;
                  }
                  else
                  {
                    *(_QWORD *)(a1 + 296) = v8;
                    result = v50;
                    *v8 = v9;
                    v8[1] = v51;
                    *v51 = v8;
                  }
                }
                else
                {
                  result = v50;
                }
                goto LABEL_163;
              }
            }
          }
        }
      }
    }
  }
LABEL_17:
  v8[4] = v25;
  v26 = *(unsigned int *)(v20 + 4);
  if ( (unsigned int)v26 >= g_num_ife_available )
  {
    if ( g_num_ife_lite_available + g_num_ife_available <= (unsigned int)v26 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_convert_hw_idx_to_ife_hw_num",
        3449,
        "hw idx %d out-of-bounds",
        v26);
    }
    else if ( (unsigned int)(v26 - g_num_ife_available) < 5 )
    {
      v27 = dword_4514F0[(unsigned int)(v26 - g_num_ife_available)];
      goto LABEL_72;
    }
  }
  else if ( (unsigned int)v26 < 3 )
  {
    v27 = dword_4514E4[v26];
    goto LABEL_72;
  }
  v27 = 0;
LABEL_72:
  *a4 |= v27;
  v52 = *(unsigned int *)(v8[4] + 4LL);
  if ( (unsigned int)v52 > 9 )
    v53 = 0;
  else
    v53 = dword_4514BC[v52];
  *(_DWORD *)(a5 + 4 * v24) |= v53;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_offline_res_ife_camif",
      5352,
      "Acquired VFE:%d CAMIF for LEFT, ctx_idx: %u",
      *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL),
      *(_DWORD *)(a1 + 56));
  *((_DWORD *)v8 + 4) = v91;
  *((_DWORD *)v8 + 5) = v98;
  *((_DWORD *)v8 + 6) = *(unsigned __int8 *)(a1 + 9379);
  if ( v8 )
  {
    v54 = a1 + 224;
    v55 = *(_QWORD **)(a1 + 232);
    if ( v8 == (_QWORD *)(a1 + 224) || v55 == v8 || *v55 != v54 )
    {
      _list_add_valid_or_report(v8);
    }
    else
    {
      *(_QWORD *)(a1 + 232) = v8;
      *v8 = v54;
      v8[1] = v55;
      *v55 = v8;
    }
  }
  if ( *(_BYTE *)(a1 + 9379) != 1 )
    goto LABEL_162;
  v56 = *(__int64 **)(v7 + 160);
  v97 = 0;
  LODWORD(v101) = 2;
  if ( v56 && *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) )
  {
    v20 = *v56;
    v57 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v56 + 40);
    v58 = *(_QWORD *)(v20 + 112);
    if ( *((_DWORD *)v57 - 1) != 1989616049 )
      __break(0x8228u);
    v59 = v57(v58, &v91, 112);
    if ( !v59 )
    {
      v60 = 0;
      goto LABEL_145;
    }
  }
  else
  {
    v59 = 0;
  }
  v61 = *(__int64 **)(v7 + 168);
  if ( !v61 || *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) == 1 )
    goto LABEL_96;
  v20 = *v61;
  v62 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v61 + 40);
  v63 = *(_QWORD *)(v20 + 112);
  if ( *((_DWORD *)v62 - 1) != 1989616049 )
    __break(0x8228u);
  v59 = v62(v63, &v91, 112);
  if ( v59 )
  {
LABEL_96:
    v64 = *(__int64 **)(v7 + 176);
    if ( !v64 || *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) == 2 )
      goto LABEL_101;
    v20 = *v64;
    v65 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v64 + 40);
    v66 = *(_QWORD *)(v20 + 112);
    if ( *((_DWORD *)v65 - 1) != 1989616049 )
      __break(0x8228u);
    v59 = v65(v66, &v91, 112);
    if ( v59 )
    {
LABEL_101:
      v67 = *(__int64 **)(v7 + 184);
      if ( !v67 || *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) == 3 )
        goto LABEL_106;
      v20 = *v67;
      v68 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v67 + 40);
      v69 = *(_QWORD *)(v20 + 112);
      if ( *((_DWORD *)v68 - 1) != 1989616049 )
        __break(0x8228u);
      v59 = v68(v69, &v91, 112);
      if ( v59 )
      {
LABEL_106:
        v70 = *(__int64 **)(v7 + 192);
        if ( !v70 || *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) == 4 )
          goto LABEL_111;
        v20 = *v70;
        v71 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v70 + 40);
        v72 = *(_QWORD *)(v20 + 112);
        if ( *((_DWORD *)v71 - 1) != 1989616049 )
          __break(0x8228u);
        v59 = v71(v72, &v91, 112);
        if ( v59 )
        {
LABEL_111:
          v73 = *(__int64 **)(v7 + 200);
          if ( !v73 || *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) == 5 )
            goto LABEL_116;
          v20 = *v73;
          v74 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v73 + 40);
          v75 = *(_QWORD *)(v20 + 112);
          if ( *((_DWORD *)v74 - 1) != 1989616049 )
            __break(0x8228u);
          v59 = v74(v75, &v91, 112);
          if ( v59 )
          {
LABEL_116:
            v76 = *(__int64 **)(v7 + 208);
            if ( !v76 || *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) == 6 )
              goto LABEL_121;
            v20 = *v76;
            v77 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v76 + 40);
            v78 = *(_QWORD *)(v20 + 112);
            if ( *((_DWORD *)v77 - 1) != 1989616049 )
              __break(0x8228u);
            v59 = v77(v78, &v91, 112);
            if ( v59 )
            {
LABEL_121:
              v79 = *(__int64 **)(v7 + 216);
              if ( v79 && *(_DWORD *)(*(_QWORD *)(v8[4] + 16LL) + 4LL) != 7 )
              {
                v20 = *v79;
                v82 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v79 + 40);
                v83 = *(_QWORD *)(v20 + 112);
                if ( *((_DWORD *)v82 - 1) != 1989616049 )
                  __break(0x8228u);
                v59 = v82(v83, &v91, 112);
                v84 = v59;
                if ( v59 )
                  goto LABEL_150;
                v60 = 7;
              }
              else
              {
                v60 = 8;
              }
            }
            else
            {
              v60 = 6;
            }
          }
          else
          {
            v60 = 5;
          }
        }
        else
        {
          v60 = 4;
        }
      }
      else
      {
        v60 = 3;
      }
    }
    else
    {
      v60 = 2;
    }
  }
  else
  {
    v60 = 1;
  }
LABEL_145:
  v84 = v59;
  if ( v59 || !v97 )
  {
LABEL_150:
    v87 = *(_DWORD *)(a1 + 56);
    v88 = v84;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_offline_res_ife_camif",
      5382,
      "Failed to acquire IFE RIGHT rc: %d, ctx_idx: %u",
      v84,
      v87);
    result = v88;
    goto LABEL_163;
  }
  v8[5] = v97;
  v85 = *(unsigned int *)(v20 + 4);
  if ( (unsigned int)v85 >= g_num_ife_available )
  {
    if ( g_num_ife_lite_available + g_num_ife_available <= (unsigned int)v85 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_convert_hw_idx_to_ife_hw_num",
        3449,
        "hw idx %d out-of-bounds",
        v85);
    }
    else if ( (unsigned int)(v85 - g_num_ife_available) < 5 )
    {
      v86 = dword_4514F0[(unsigned int)(v85 - g_num_ife_available)];
      goto LABEL_156;
    }
  }
  else if ( (unsigned int)v85 < 3 )
  {
    v86 = dword_4514E4[v85];
    goto LABEL_156;
  }
  v86 = 0;
LABEL_156:
  *a4 |= v86;
  v89 = *(unsigned int *)(v8[5] + 4LL);
  if ( (unsigned int)v89 > 9 )
    v90 = 0;
  else
    v90 = dword_4514BC[v89];
  result = 0;
  *(_DWORD *)(a5 + 4 * v60) |= v90;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_offline_res_ife_camif",
      5395,
      "Acquired VFE:%d CAMIF for RIGHT, ctx_idx: %u",
      *(_DWORD *)(*(_QWORD *)(v8[5] + 16LL) + 4LL),
      *(_DWORD *)(a1 + 56));
LABEL_162:
    result = 0;
  }
LABEL_163:
  _ReadStatusReg(SP_EL0);
  return result;
}
