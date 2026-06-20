__int64 __fastcall _cam_req_mgr_process_req(unsigned int *a1, __int64 a2)
{
  __int64 v2; // x28
  unsigned int *v3; // x26
  const char *v5; // x24
  __int64 v6; // x21
  __int64 v8; // x23
  unsigned int v9; // w20
  __int64 v10; // x6
  __int64 v11; // x9
  __int64 result; // x0
  __int64 v13; // x27
  __int64 v14; // x20
  __int64 v15; // x1
  __int64 v16; // x8
  unsigned int v17; // w8
  _DWORD *v18; // x25
  int v19; // w22
  __int64 v20; // x1
  __int64 v21; // x1
  unsigned int v22; // w8
  __int64 v23; // x8
  __int64 v24; // x9
  int v25; // w0
  const char *v26; // x9
  __int64 v27; // x9
  __int64 v28; // x9
  __int64 v29; // x8
  unsigned int v30; // w0
  __int64 v31; // x22
  unsigned int v32; // w9
  unsigned int v33; // w8
  _QWORD *v34; // x14
  unsigned int *v35; // x12
  _DWORD *v36; // x20
  __int64 v37; // x10
  __int64 v38; // x11
  int v39; // w11
  _QWORD *v40; // x12
  unsigned int v41; // w9
  unsigned int (__fastcall *v42)(_QWORD); // x8
  unsigned int v43; // w21
  __int64 v44; // x0
  char v45; // w25
  __int64 v46; // x22
  __int64 v47; // x8
  __int64 v48; // x25
  __int64 v49; // x1
  __int64 v50; // x2
  __int64 v51; // x4
  const char *v52; // x5
  _QWORD *v53; // x25
  __int64 v54; // x27
  int v55; // w8
  const char *v56; // x7
  __int64 v57; // x8
  void (__fastcall *v58)(_QWORD); // x8
  __int64 (__fastcall *v59)(_QWORD); // x10
  unsigned int v60; // w0
  _QWORD *v61; // x27
  __int64 v62; // x25
  int v63; // w0
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x22
  int v67; // w25
  __int64 v68; // x27
  unsigned int *v69; // x25
  __int64 v70; // x8
  int v71; // w7
  __int64 v72; // x8
  __int64 v73; // x8
  void (__fastcall *v74)(_QWORD); // x8
  signed int v75; // w10
  int v76; // w11
  unsigned int v77; // w13
  __int64 v78; // x11
  int v79; // w12
  __int64 v80; // x15
  __int64 v81; // x13
  int v82; // w10
  int v83; // w11
  __int64 v84; // x11
  __int64 v85; // x1
  __int64 v86; // x8
  __int64 (__fastcall *v87)(_QWORD); // x8
  __int64 v88; // x1
  __int64 v89; // x8
  _QWORD *v90; // x25
  __int64 v91; // x7
  unsigned int *v92; // x27
  __int64 v93; // x8
  __int64 v94; // x9
  __int64 v95; // x9
  __int64 v96; // x10
  __int64 v97; // x9
  int v98; // w6
  __int64 v99; // x1
  _QWORD *v100; // x22
  int v101; // w12
  unsigned int *v102; // x13
  int v103; // w10
  __int64 v104; // x11
  unsigned int v105; // w11
  __int64 v106; // x11
  unsigned int v107; // w11
  __int64 v108; // x10
  unsigned int v109; // w10
  unsigned int v110; // w25
  __int64 v111; // x0
  __int64 v112; // x8
  __int64 v113; // x22
  __int64 v114; // x20
  bool v115; // cc
  __int64 v116; // x8
  unsigned int v117; // w11
  unsigned int *v118; // x8
  unsigned int v119; // w10
  __int64 v120; // x8
  void (__fastcall *v121)(_QWORD); // x8
  const char *v122; // x6
  const void *v123; // x10
  unsigned int v124; // w22
  int v126; // w8
  __int64 v127; // x20
  __int64 v128; // x9
  unsigned int v129; // w11
  _QWORD *v130; // x9
  unsigned int v131; // w10
  __int64 v132; // x9
  void (__fastcall *v133)(unsigned __int64 *, __int64); // x9
  _QWORD *v134; // x20
  int v135; // w20
  const char *v136; // x7
  unsigned int v137; // w20
  unsigned int v143; // w10
  __int64 v144; // [xsp+30h] [xbp-240h]
  __int64 v145; // [xsp+38h] [xbp-238h]
  __int64 v146; // [xsp+40h] [xbp-230h]
  __int64 v147; // [xsp+40h] [xbp-230h]
  int v148; // [xsp+4Ch] [xbp-224h]
  int v149; // [xsp+4Ch] [xbp-224h]
  int v150; // [xsp+4Ch] [xbp-224h]
  int v151; // [xsp+50h] [xbp-220h]
  __int64 v152; // [xsp+58h] [xbp-218h]
  __int64 v153; // [xsp+60h] [xbp-210h]
  __int64 v154; // [xsp+68h] [xbp-208h]
  int v155; // [xsp+74h] [xbp-1FCh]
  unsigned int *v156; // [xsp+78h] [xbp-1F8h]
  _DWORD *v157; // [xsp+80h] [xbp-1F0h]
  __int64 v158; // [xsp+88h] [xbp-1E8h]
  __int64 v159; // [xsp+90h] [xbp-1E0h]
  unsigned int *v160; // [xsp+98h] [xbp-1D8h]
  _QWORD *v161; // [xsp+A0h] [xbp-1D0h]
  unsigned int v162; // [xsp+ACh] [xbp-1C4h] BYREF
  unsigned __int64 v163; // [xsp+B0h] [xbp-1C0h] BYREF
  __int64 v164; // [xsp+B8h] [xbp-1B8h]
  __int64 v165; // [xsp+C0h] [xbp-1B0h]
  __int64 v166; // [xsp+C8h] [xbp-1A8h]
  __int64 v167; // [xsp+D0h] [xbp-1A0h]
  __int64 v168; // [xsp+D8h] [xbp-198h]
  __int64 v169; // [xsp+E0h] [xbp-190h]
  __int64 v170; // [xsp+E8h] [xbp-188h] BYREF
  __int64 v171; // [xsp+F0h] [xbp-180h]
  __int64 v172; // [xsp+F8h] [xbp-178h]
  __int64 v173; // [xsp+100h] [xbp-170h]
  __int64 v174; // [xsp+108h] [xbp-168h]
  __int64 v175; // [xsp+110h] [xbp-160h]
  __int64 link_priv; // [xsp+118h] [xbp-158h] BYREF
  __int64 v177; // [xsp+120h] [xbp-150h]
  __int64 v178; // [xsp+128h] [xbp-148h]
  _QWORD s[40]; // [xsp+130h] [xbp-140h] BYREF

  v3 = a1 + 0x2000;
  s[38] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((const char **)a1 + 4145);
  LODWORD(v6) = *(_DWORD *)(a2 + 16);
  v162 = 0;
  v177 = 0;
  v178 = 0;
  link_priv = 0;
  if ( !v5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      2,
      "__cam_req_mgr_process_req",
      2232,
      "session ptr NULL %x",
      *a1);
    result = 4294967274LL;
    goto LABEL_12;
  }
  mutex_lock(v5 + 56);
  v8 = 33216;
  raw_spin_lock_bh(a1 + 8304);
  v9 = v3[96];
  raw_spin_unlock_bh(a1 + 8304);
  if ( v9 == 1 )
  {
    mutex_unlock(v5 + 56);
    result = 0xFFFFFFFFLL;
    goto LABEL_12;
  }
  v13 = *((_QWORD *)a1 + 6);
  v14 = 16777232;
  v15 = debug_mdl & 0x1000010;
  if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
  {
    v16 = *(unsigned int *)(v13 + 3464);
    if ( (unsigned int)v16 >= 0x30 )
      goto LABEL_325;
    if ( (_DWORD)v6 == 1 )
      v122 = "SOF";
    else
      v122 = "EOF";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v15,
      4,
      "__cam_req_mgr_process_req",
      2263,
      "%s Req[%lld] idx %d req_status %d link_hdl %x wd_timeout %d ms trigger:%d",
      v122,
      *(_QWORD *)(v13 + 72LL * (unsigned int)v16 + 24),
      v16,
      *(_DWORD *)(v13 + 72LL * (unsigned int)v16 + 16),
      *a1,
      *(_DWORD *)(v13 + 72LL * (unsigned int)v16 + 36),
      v6);
    v14 = 16777232;
  }
  v16 = *(unsigned int *)(v13 + 3464);
  if ( (unsigned int)v16 > 0x30 )
    goto LABEL_325;
  if ( (unsigned int)(v6 - 3) < 0xFFFFFFFE )
    goto LABEL_9;
  v11 = 72;
  v2 = v13 + 8 + 72LL * (unsigned int)v16;
  if ( (_DWORD)v6 == 2 )
  {
    if ( !v3[143] )
    {
      LODWORD(v14) = 0;
      if ( (debug_mdl & 0x10) == 0 || debug_priority )
        goto LABEL_10;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_process_req",
        2273,
        "Not any request to schedule at EOF");
      goto LABEL_9;
    }
    v18 = (_DWORD *)(v2 + 8);
    v17 = *(_DWORD *)(v2 + 8);
    if ( v17 != 4 )
    {
      v159 = v13 + 8;
      if ( v17 != 3 )
        goto LABEL_17;
LABEL_27:
      v25 = _cam_req_mgr_inject_delay(*((_QWORD *)a1 + 7), *(unsigned int *)v2, (unsigned int)v6);
      if ( (v25 & 0x80000000) == 0 )
        goto LABEL_65;
      LODWORD(v14) = v25;
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      {
        v26 = "SOF";
        if ( (_DWORD)v6 == 2 )
          v26 = "EOF";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "__cam_req_mgr_process_req",
          2413,
          "linx_hdl %x Req: %lld needs to inject delay at %s",
          *a1,
          *(_QWORD *)(v2 + 16),
          v26);
      }
LABEL_164:
      _cam_req_mgr_notify_frame_skip(a1, (unsigned int)v6);
      _cam_req_mgr_validate_crm_wd_timer(a1);
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  v18 = (_DWORD *)(v2 + 8);
  v22 = *(_DWORD *)(v2 + 8);
  if ( !v22 )
  {
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_process_req",
        2283,
        "No Pending req");
    _cam_req_mgr_notify_frame_skip(a1, 1);
    goto LABEL_9;
  }
  if ( v22 == 4 )
  {
LABEL_9:
    LODWORD(v14) = 0;
    goto LABEL_10;
  }
  v23 = *((_QWORD *)v3 + 66);
  v159 = v13 + 8;
  *((_QWORD *)v3 + 67) = v23;
  v24 = *(_QWORD *)(a2 + 24);
  *((_QWORD *)v3 + 66) = v24;
  v14 = 16777232;
  *((_BYTE *)v3 + 592) = (unsigned int)jiffies_to_msecs(jiffies - *((_QWORD *)v3 + 73), v15) < (v24 - v23) / 0x1E8480uLL;
  *((_QWORD *)v3 + 73) = jiffies;
  if ( *v18 == 3 )
    goto LABEL_27;
LABEL_17:
  if ( *(_DWORD *)(v2 + 24) == 1 )
  {
    v19 = *(_DWORD *)(v2 + 36);
    if ( v19 )
    {
      if ( v19 >= 1 )
      {
        link_priv = cam_get_link_priv(*(unsigned int *)(v2 + 40), v15);
        if ( v19 != 1 )
        {
          v177 = cam_get_link_priv(*(unsigned int *)(v2 + 44), v20);
          if ( v19 != 2 )
          {
            v178 = cam_get_link_priv(*(unsigned int *)(v2 + 48), v21);
            if ( v19 != 3 )
              goto LABEL_325;
          }
        }
      }
    }
    else
    {
      v19 = v3[120];
      if ( v19 >= 1 )
      {
        link_priv = *((_QWORD *)v3 + 57);
        if ( v19 != 1 )
        {
          v177 = *((_QWORD *)v3 + 58);
          if ( v19 != 2 )
          {
            v16 = *((_QWORD *)v3 + 59);
            v178 = v16;
            if ( v19 != 3 )
              goto LABEL_325;
          }
        }
      }
    }
    v30 = _cam_req_mgr_check_multi_sync_link_ready(a1, &link_priv, v2, (unsigned int)v19, (unsigned int)v6);
  }
  else
  {
    if ( *((_BYTE *)v3 + 510) == 1 )
    {
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "__cam_req_mgr_process_req",
          2340,
          "Settings master-slave non sync mode for link 0x%x",
          *a1);
      v16 = v3[120];
      *((_BYTE *)v3 + 510) = 0;
      *((_QWORD *)v3 + 64) = -1;
      if ( (int)v16 >= 1 )
      {
        v27 = *((_QWORD *)v3 + 57);
        if ( v27 )
        {
          *(_QWORD *)(v27 + 33280) = -1;
          *(_BYTE *)(v27 + 33278) = 0;
          v16 = v3[120];
        }
        if ( (int)v16 >= 2 )
        {
          v28 = *((_QWORD *)v3 + 58);
          if ( v28 )
          {
            *(_QWORD *)(v28 + 33280) = -1;
            *(_BYTE *)(v28 + 33278) = 0;
            v16 = v3[120];
          }
          if ( (int)v16 >= 3 )
          {
            v11 = *((_QWORD *)v3 + 59);
            if ( v11 )
            {
              v29 = v11 + 0x8000;
              v11 = -1;
              *(_QWORD *)(v29 + 512) = -1;
              *(_BYTE *)(v29 + 510) = 0;
              v16 = v3[120];
            }
            if ( (int)v16 > 3 )
              goto LABEL_325;
          }
        }
      }
    }
    v30 = _cam_req_mgr_check_link_is_ready(a1, *(unsigned int *)v2, 1);
    if ( v30 )
      goto LABEL_157;
    v30 = _cam_req_mgr_inject_delay(*((_QWORD *)a1 + 7), *(unsigned int *)v2, (unsigned int)v6);
    if ( (v30 & 0x80000000) != 0 )
    {
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      {
        if ( (_DWORD)v6 == 2 )
          v136 = "EOF";
        else
          v136 = "SOF";
        v137 = v30;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "__cam_req_mgr_process_req",
          2366,
          "Req: %lld needs to inject delay at %s",
          *(_QWORD *)(v2 + 16),
          v136);
        v30 = v137;
      }
      goto LABEL_157;
    }
    v30 = _cam_req_mgr_check_link_is_ready(a1, *(unsigned int *)v2, 0);
  }
  if ( (v30 & 0x80000000) != 0 )
  {
LABEL_157:
    v14 = v30;
    *v18 = 2;
    raw_spin_lock_bh(a1 + 8304);
    if ( v3[96] == 3 )
    {
      v63 = __ratelimit(&_cam_req_mgr_process_req__rs, "__cam_req_mgr_process_req");
      LODWORD(v10) = *(_DWORD *)(v13 + 3464);
      if ( (unsigned int)v10 > 0x2F )
        goto LABEL_325;
      if ( v63 )
        v64 = 3;
      else
        v64 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v64,
        16,
        1,
        "__cam_req_mgr_process_req",
        2391,
        "FATAL recovery cant finish idx %d status %d",
        v10,
        *(_DWORD *)(v159 + 72LL * (unsigned int)v10 + 8));
      LODWORD(v14) = -1;
    }
    raw_spin_unlock_bh(a1 + 8304);
    goto LABEL_164;
  }
  v11 = 1;
  *v18 = 3;
  *((_BYTE *)v3 + 594) = 1;
  v15 = debug_mdl & 0x1000010;
  if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
  {
    v16 = *(unsigned int *)(v13 + 3464);
    if ( (unsigned int)v16 > 0x2F )
      goto LABEL_325;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v15,
      4,
      "__cam_req_mgr_process_req",
      2404,
      "linx_hdl %x Req[%lld] idx %d ready to apply",
      *a1,
      *(_QWORD *)(v159 + 72LL * (unsigned int)v16 + 16),
      *(_DWORD *)(v13 + 3464));
  }
LABEL_65:
  mutex_unlock(v5 + 56);
  v31 = *((_QWORD *)a1 + 6);
  v174 = 0;
  v175 = 0;
  v172 = 0;
  v173 = 0;
  v170 = 0;
  v171 = 0;
  memset(s, 0, 0x130u);
  v32 = v3[130];
  LODWORD(v170) = *a1;
  if ( v32 )
    LOBYTE(v175) = *(_BYTE *)(g_crm_core_dev + 64) == 1;
  v168 = 0;
  v169 = 0;
  v166 = 0;
  v167 = 0;
  v164 = 0;
  v165 = 0;
  v163 = 0;
  raw_spin_lock_bh(a1 + 8304);
  BYTE1(v175) = v3[96] == 3;
  raw_spin_unlock_bh(a1 + 8304);
  LODWORD(v10) = a1[2];
  if ( (unsigned int)v10 >= 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_send_req",
      1263,
      "link->max_delay is out of bounds: %d",
      v10);
LABEL_69:
    v8 = 0;
    result = 4294967274LL;
    goto LABEL_70;
  }
  v16 = *(unsigned int *)(v31 + 3464);
  v34 = &unk_393000;
  v156 = (unsigned int *)v2;
  v157 = v18;
  v158 = v13;
  LODWORD(v154) = *(_DWORD *)(v31 + 3464);
  if ( (unsigned int)v16 >= 0x31 )
    goto LABEL_325;
  v35 = a1 + 36;
  v161 = a1 + 18;
  if ( (int)a1[1] < 1 )
  {
    v62 = v13;
    goto LABEL_231;
  }
  v36 = *((_DWORD **)a1 + 5);
  v153 = v31 + 8;
  v37 = a1[1];
  v160 = a1 + 36;
  while ( 1 )
  {
    if ( v36[71] == 1 )
    {
      v38 = *((_QWORD *)v36 + 38);
      if ( v38 )
      {
        if ( *(_QWORD *)(v38 + 40) )
        {
          v39 = *(_DWORD *)(*((_QWORD *)v36 + 2) + 4LL);
          v40 = &v161[3 * v39];
          if ( *((_DWORD *)v40 + 4) || (v40[1] & 0x8000000000000000LL) != 0 )
            break;
        }
      }
    }
    --v37;
    v36 += 80;
    if ( !v37 )
    {
      v45 = 0;
      goto LABEL_101;
    }
  }
  v41 = *a1;
  v164 = *(_QWORD *)&v160[6 * v39 + 2];
  v163 = __PAIR64__(*v36, v41);
  HIDWORD(v165) = 9;
  raw_spin_lock_bh(a1 + 8304);
  LOBYTE(v166) = v3[96] == 3;
  raw_spin_unlock_bh(a1 + 8304);
  v42 = *(unsigned int (__fastcall **)(_QWORD))(*((_QWORD *)v36 + 38) + 40LL);
  if ( *((_DWORD *)v42 - 1) != -662406558 )
    __break(0x8228u);
  if ( v42(&v163) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_send_req",
      1288,
      "Failed to send FRAME_SKIP_AVALIABLE on link 0x%x dev 0x%x",
      *a1,
      *v36);
    goto LABEL_69;
  }
  v45 = v166;
  v34 = &unk_393000;
  if ( (int)a1[1] < 1 )
    goto LABEL_166;
LABEL_101:
  v14 = 0;
  v46 = 0;
  LOBYTE(v155) = v45;
  while ( 1 )
  {
    v48 = *((_QWORD *)a1 + 5);
    LODWORD(v2) = *(_DWORD *)(v48 + v14 + 288);
    if ( (int)v2 >= 3 )
    {
      v49 = 16;
      v50 = 2;
      v51 = 1305;
      v52 = "pd %d greater than max";
      v10 = (unsigned int)v2;
      goto LABEL_106;
    }
    v16 = (__int64)(a1 + 18);
    v11 = (__int64)&v161[3 * (int)v2];
    LODWORD(v10) = *(_DWORD *)v11;
    if ( *(_DWORD *)v11 > 0x30u )
      goto LABEL_325;
    v54 = *(_QWORD *)(v48 + v14 + 16) + 48LL * (unsigned int)v10;
    v55 = *(_DWORD *)(v54 + 64);
    if ( (unsigned int)(v55 - 5) < 0xFFFFFFFC )
    {
      if ( (v34[458] & 0x10) == 0 || debug_priority )
        goto LABEL_103;
      v56 = (const char *)(v48 + v14 + 28);
      v53 = v34;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v34[458] & 0x10LL,
        4,
        "__cam_req_mgr_send_req",
        1316,
        "No special ops detected for slot %d dev %s num_dev %d",
        v10,
        v56,
        v55);
      goto LABEL_107;
    }
    v10 = *(unsigned int *)(v48 + v14);
    if ( (_DWORD)v10 != *(_DWORD *)(v54 + 68)
      && (v55 == 1
       || (_DWORD)v10 != *(_DWORD *)(v54 + 72)
       && (v55 == 2 || (_DWORD)v10 != *(_DWORD *)(v54 + 76) && (v55 == 3 || (_DWORD)v10 != *(_DWORD *)(v54 + 80)))) )
    {
      if ( (v34[458] & 0x10) == 0 || debug_priority )
        goto LABEL_103;
      v49 = v34[458] & 0x10LL;
      v50 = 4;
      v51 = 1329;
      v52 = "Dev_hdl : %d Not matched";
LABEL_106:
      v53 = v34;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v49,
        v50,
        "__cam_req_mgr_send_req",
        v51,
        v52,
        v10);
LABEL_107:
      v34 = v53;
      goto LABEL_103;
    }
    if ( (((unsigned __int64)*(unsigned int *)(v54 + 48) >> *(_QWORD *)(v48 + v14 + 8)) & 1) == 0 )
      break;
LABEL_103:
    v47 = (int)a1[1];
    ++v46;
    v14 += 320;
    if ( v46 >= v47 )
    {
      v45 = v155;
      goto LABEL_167;
    }
  }
  if ( *(_DWORD *)(v11 + 16) || (v16 = *(_QWORD *)(v11 + 8), v16 < 0) )
  {
    v16 = v34[458];
    if ( (v16 & 0x10) != 0 && !debug_priority )
    {
      v61 = v34;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v34[458] & 0x10LL,
        4,
        "__cam_req_mgr_send_req",
        1342,
        "dev %s skip %d req_id %lld",
        v48 + v14 + 28);
      v16 = v48 + v14;
      v34 = v61;
      LODWORD(v10) = *(_DWORD *)(v48 + v14);
    }
    HIDWORD(v170) = v10;
    if ( (unsigned int)v2 > 2 )
      goto LABEL_325;
    HIDWORD(v173) = v6;
    LODWORD(v173) = 0;
    v11 = *(_QWORD *)&v160[6 * (int)v2 + 2];
    v16 = a1[2];
    v171 = v11;
    if ( (unsigned int)v16 > 2 )
      goto LABEL_325;
    v172 = *(_QWORD *)&v160[6 * (unsigned int)v16 + 2];
    v57 = *(_QWORD *)(v48 + v14 + 304);
    if ( !v57 )
      goto LABEL_103;
    v58 = *(void (__fastcall **)(_QWORD))(v57 + 24);
    if ( !v58 )
      goto LABEL_103;
    v53 = v34;
    if ( *((_DWORD *)v58 - 1) != 1415584157 )
      __break(0x8228u);
    v58(&v170);
    goto LABEL_107;
  }
  if ( (_DWORD)v6 == 2 )
  {
    if ( (*(_BYTE *)(v54 + 84) & 1) != 0 )
    {
      v151 = 1;
      goto LABEL_141;
    }
    v45 = v155;
    if ( (v34[458] & 0x10) == 0 || debug_priority )
      goto LABEL_166;
    v134 = v34;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v34[458] & 0x10LL,
      4,
      "__cam_req_mgr_send_req",
      1365,
      "NO EOF DATA FOR REQ: %llu",
      v16);
LABEL_316:
    v34 = v134;
    goto LABEL_166;
  }
  if ( *(_BYTE *)(v54 + 84) == 1 )
  {
    v45 = v155;
    if ( (v34[458] & 0x10) == 0 || debug_priority )
      goto LABEL_166;
    v134 = v34;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v34[458] & 0x10LL,
      4,
      "__cam_req_mgr_send_req",
      1358,
      "EOF event cannot be applied at SOF");
    goto LABEL_316;
  }
  v151 = 0;
LABEL_141:
  HIDWORD(v170) = *(_DWORD *)(v48 + v14);
  v171 = v16;
  HIDWORD(v173) = v6;
  v11 = *(_QWORD *)(v48 + v14 + 304);
  if ( v11 )
  {
    v59 = *(__int64 (__fastcall **)(_QWORD))(v11 + 16);
    if ( v59 )
    {
      if ( *((_DWORD *)v59 - 1) != 1415584157 )
        __break(0x822Au);
      v60 = v59(&v170);
      if ( v60 )
      {
        v124 = v60;
        _cam_req_mgr_notify_frame_skip(a1, (unsigned int)v6);
        result = v124;
        if ( (v124 & 0x80000000) != 0 )
        {
          v13 = v158;
          v2 = (__int64)v156;
          v8 = v48 + v14;
          goto LABEL_285;
        }
LABEL_331:
        v62 = v158;
        v92 = v156;
        v34 = &unk_393000;
LABEL_236:
        v100 = v34;
        v14 = (unsigned int)result;
        if ( v3[130] )
          v3[130] = 0;
        _cam_req_mgr_validate_crm_wd_timer(a1);
        raw_spin_lock_bh((char *)a1 + v8);
        if ( v3[96] == 3 )
        {
          LODWORD(v6) = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            2,
            "__cam_req_mgr_process_req",
            2477,
            "Err recovery done idx %d",
            *(_DWORD *)(v62 + 3464));
          v3[96] = 2;
        }
        raw_spin_unlock_bh((char *)a1 + v8);
        if ( *((_BYTE *)v3 + 484) == 1 )
          *((_BYTE *)v3 + 484) = 0;
        v11 = a1[1];
        if ( (int)v11 < 1 )
        {
LABEL_250:
          *v157 = 4;
          if ( (v100[458] & 0x10) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v100[458] & 0x10LL,
              4,
              "__cam_req_mgr_process_req",
              2513,
              "req %d is applied on link %x success",
              *((_QWORD *)v92 + 2),
              *a1);
          v103 = v3[120];
          v11 = *(unsigned int *)(v62 + 3464);
          v16 = a1[2];
          v162 = *(_DWORD *)(v62 + 3464);
          if ( v103 >= 1 )
          {
            if ( (unsigned int)(v103 - 4) < 0xFFFFFFFD )
              goto LABEL_325;
            v104 = *((_QWORD *)v3 + 57);
            if ( v104 )
            {
              if ( *((_BYTE *)v3 + 510) == 1 )
              {
                v105 = *(_DWORD *)(v104 + 8);
                if ( v105 > (unsigned int)v16 )
                  LODWORD(v16) = v105;
              }
            }
            if ( v103 != 1 )
            {
              v106 = *((_QWORD *)v3 + 58);
              if ( v106 )
              {
                if ( *((_BYTE *)v3 + 510) == 1 )
                {
                  v107 = *(_DWORD *)(v106 + 8);
                  if ( v107 > (unsigned int)v16 )
                    LODWORD(v16) = v107;
                }
              }
              if ( v103 != 2 )
              {
                v108 = *((_QWORD *)v3 + 59);
                if ( v108 )
                {
                  if ( *((_BYTE *)v3 + 510) == 1 )
                  {
                    v109 = *(_DWORD *)(v108 + 8);
                    if ( v109 > (unsigned int)v16 )
                      LODWORD(v16) = v109;
                  }
                }
              }
            }
          }
          *(_DWORD *)(v62 + 3472) = v11;
          cam_common_dec_idx(&v162, (unsigned int)(v16 + 1));
          _cam_req_mgr_reset_req_slot(a1, v162);
          result = (unsigned int)v14;
LABEL_270:
          *((_BYTE *)v3 + 594) = 0;
          goto LABEL_12;
        }
        v16 = *((_QWORD *)a1 + 5);
        result = (unsigned int)v14;
        while ( 1 )
        {
          v101 = *(_DWORD *)(v16 + 288);
          if ( v101 >= 3 )
            break;
          v102 = (unsigned int *)&v161[3 * v101];
          if ( *v102 > 0x30 )
            goto LABEL_325;
          if ( *((_QWORD *)v102 + 1) != -1
            && *(_DWORD *)(*(_QWORD *)(v16 + 16) + 48LL * *v102 + 48) != *(_DWORD *)(*(_QWORD *)(v16 + 16) + 12LL) )
          {
            goto LABEL_270;
          }
          --v11;
          v16 += 320;
          if ( !v11 )
            goto LABEL_250;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "__cam_req_mgr_process_req",
          2494,
          "link_hdl %x dev %s pd %d greater than max",
          *a1,
          (const char *)(v16 + 28),
          v101);
        LODWORD(v14) = -22;
LABEL_10:
        mutex_unlock(v5 + 56);
        goto LABEL_11;
      }
      *(_DWORD *)(v54 + 48) |= 1LL << *(_QWORD *)(v48 + v14 + 8);
      s[1] = v171;
      LODWORD(s[0]) = 3;
      LODWORD(s[2]) = HIDWORD(v170);
      s[3] = -1;
      ((void (__fastcall *)(unsigned int *, _QWORD *))_cam_req_mgr_update_state_monitor_array)(a1, s);
      v34 = &unk_393000;
      v15 = debug_mdl & 0x1000010;
      if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v15,
          4,
          "__cam_req_mgr_send_req",
          1399,
          "SEND: link_hdl %x dev %s pd %d req_id %lld",
          *a1,
          (const char *)(v48 + v14 + 28),
          v2,
          v171);
        v34 = &unk_393000;
        if ( !v151 )
          goto LABEL_103;
LABEL_149:
        if ( *(_BYTE *)(v54 + 84) != 1 )
          goto LABEL_103;
        *(_BYTE *)(v54 + 84) = 0;
        if ( (int)v3[143] < 1 )
        {
          if ( !v3[143] )
            goto LABEL_300;
        }
        else
        {
          _X8 = v3 + 143;
          __asm { PRFM            #0x11, [X8] }
          do
            v143 = __ldxr(_X8);
          while ( __stxr(v143 - 1, _X8) );
          if ( v3[143] )
            goto LABEL_330;
LABEL_300:
          if ( (v3[149] & 1) == 0 )
          {
            v126 = a1[1];
            if ( v126 >= 1 )
            {
              v62 = v158;
              v92 = v156;
              v127 = 0;
              v6 = 304;
              do
              {
                v128 = *((_QWORD *)a1 + 5);
                HIDWORD(v165) = 10;
                v129 = *a1;
                v130 = (_QWORD *)(v128 + v6);
                v131 = *((_DWORD *)v130 - 76);
                LOBYTE(v166) = 0;
                v163 = __PAIR64__(v131, v129);
                v132 = *v130;
                if ( v132 )
                {
                  v133 = *(void (__fastcall **)(unsigned __int64 *, __int64))(v132 + 40);
                  if ( v133 )
                  {
                    if ( *((_DWORD *)v133 - 1) != -662406558 )
                      __break(0x8229u);
                    v133(&v163, v15);
                    v126 = a1[1];
                  }
                }
                ++v127;
                LODWORD(result) = 0;
                v6 += 320;
                v34 = &unk_393000;
              }
              while ( v127 < v126 );
              goto LABEL_236;
            }
          }
        }
LABEL_330:
        LODWORD(result) = 0;
        goto LABEL_331;
      }
      if ( v151 )
        goto LABEL_149;
      goto LABEL_103;
    }
  }
  v45 = v155;
  v15 = v34[458] & 0x1000010LL;
  if ( v15 && !debug_priority )
  {
    LODWORD(v10) = *a1;
    v14 = (__int64)v34;
    if ( !v11 )
      goto LABEL_326;
    v123 = *(const void **)(v11 + 16);
LABEL_327:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v15,
      4,
      "__cam_req_mgr_send_req",
      1386,
      "link_hdl: %x pd: %d req_id %lld ops %p apply_req %p",
      v10,
      v2,
      v16,
      (const void *)v11,
      v123);
    v45 = v155;
    v34 = (_QWORD *)v14;
  }
LABEL_166:
  LODWORD(v47) = a1[1];
LABEL_167:
  if ( (int)v47 < 1 )
  {
    v62 = v158;
    v35 = v160;
LABEL_231:
    LODWORD(result) = 0;
    v91 = -1;
LABEL_232:
    v92 = v156;
    v93 = v161[6];
    v94 = v161[7];
    *((_QWORD *)v35 + 8) = v161[8];
    *((_QWORD *)v35 + 6) = v93;
    *((_QWORD *)v35 + 7) = v94;
    v95 = v161[3];
    *((_QWORD *)v35 + 2) = v161[2];
    *((_QWORD *)v35 + 3) = v95;
    v96 = v161[5];
    *((_QWORD *)v35 + 4) = v161[4];
    *((_QWORD *)v35 + 5) = v96;
    v97 = v161[1];
    *(_QWORD *)v35 = *v161;
    *((_QWORD *)v35 + 1) = v97;
    if ( v91 >= 1 )
    {
      v98 = v3[122] - 1;
      v3[122] = v98;
      v99 = v34[458] & 0x1000010LL;
      if ( v99 )
      {
        if ( !debug_priority )
        {
          v135 = result;
          v6 = (__int64)v34;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v99,
            4,
            "__cam_req_mgr_send_req",
            1575,
            "Open_reqs: %u after successfully applying req:%d",
            v98,
            v91);
          v34 = (_QWORD *)v6;
          LODWORD(result) = v135;
        }
      }
    }
    goto LABEL_236;
  }
  v65 = 0;
  v155 = v45 & 1;
  v66 = 0;
  LODWORD(result) = 0;
  v154 = v153 + 72LL * (unsigned int)v154;
  _ReadStatusReg(SP_EL0);
  v152 = -1;
  do
  {
    v14 = *((_QWORD *)a1 + 5);
    v68 = v65;
    v69 = (unsigned int *)(v14 + v65);
    if ( v14 + v65 )
    {
      v70 = v14 + v65;
      LODWORD(v2) = *(_DWORD *)(v14 + v68 + 288);
      if ( (int)v2 >= 3 )
      {
        v67 = result;
        v2 = (__int64)v34;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          2,
          "__cam_req_mgr_send_req",
          1435,
          "pd %d greater than max",
          *(_DWORD *)(v14 + v68 + 288));
LABEL_170:
        v34 = (_QWORD *)v2;
        LODWORD(result) = v67;
        goto LABEL_171;
      }
      if ( (*(_DWORD *)(v70 + 296) & (unsigned int)v6) != 0 )
      {
        v11 = (__int64)&v161[3 * (int)v2];
        v71 = *(_DWORD *)(v11 + 16);
        if ( !v71 )
        {
          v16 = *(_QWORD *)(v11 + 8);
          if ( (v16 & 0x8000000000000000LL) == 0 )
          {
            v75 = *(_DWORD *)v11;
            v76 = *v69;
            v171 = *(_QWORD *)(v11 + 8);
            HIDWORD(v170) = v76;
            if ( (unsigned int)v75 >= 0x30 )
              goto LABEL_325;
            v77 = v3[130];
            v11 = v153 + 72LL * v75;
            v78 = *(_QWORD *)(v14 + v68 + 16);
            v79 = *(_DWORD *)(v11 + 12);
            LODWORD(v173) = v79;
            if ( v77 && !v79 && *((_BYTE *)v3 + 544) == 1 )
              LOBYTE(v175) = 1;
            v80 = v14 + v68;
            v81 = v78 + 48LL * v75;
            if ( (((unsigned __int64)*(unsigned int *)(v81 + 48) >> *(_QWORD *)(v14 + v68 + 8)) & 1) != 0 )
              goto LABEL_171;
            v82 = *(_DWORD *)(v81 + 64);
            if ( v82 )
            {
              v83 = *v69;
              if ( *v69 == *(_DWORD *)(v81 + 68) )
              {
LABEL_194:
                if ( (_DWORD)v6 == 2 )
                {
                  if ( *(_BYTE *)(v81 + 84) != 1 )
                    goto LABEL_171;
                }
                else if ( (_DWORD)v6 == 1 && (*(_BYTE *)(v81 + 84) & 1) != 0 )
                {
                  goto LABEL_171;
                }
              }
              else if ( v82 != 1 )
              {
                if ( v83 == *(_DWORD *)(v81 + 72) )
                  goto LABEL_194;
                if ( v82 != 2 )
                {
                  if ( v83 == *(_DWORD *)(v81 + 76) )
                    goto LABEL_194;
                  if ( v82 != 3 )
                  {
                    if ( v83 == *(_DWORD *)(v81 + 80) )
                      goto LABEL_194;
                    if ( v82 != 4 )
                      goto LABEL_325;
                  }
                }
              }
            }
            HIDWORD(v173) = v6;
            v84 = v14 + v68;
            v174 = 0;
            BYTE3(v175) = v155;
            if ( *(_DWORD *)(v14 + v68 + 284) == 4 && !*(_DWORD *)(v11 + 64) )
              v174 = *((_QWORD *)v3 + 77);
            v85 = v34[458] & 0x1000010LL;
            if ( v85 && !debug_priority )
            {
              v150 = result;
              v147 = v81;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v85,
                4,
                "__cam_req_mgr_send_req",
                1522,
                "SEND: link_hdl %x dev %s pd %d req_id %lld frame_duration_changing %d",
                *a1,
                (const char *)(v14 + v68 + 28),
                v2,
                v16,
                v155);
              v84 = v14 + v68;
              v80 = v14 + v68;
              v34 = &unk_393000;
              v81 = v147;
              LODWORD(result) = v150;
            }
            v86 = *(_QWORD *)(v14 + v68 + 304);
            if ( v86 )
            {
              v87 = *(__int64 (__fastcall **)(_QWORD))(v86 + 16);
              if ( v87 )
              {
                v144 = v84;
                v145 = v80;
                v146 = v81;
                if ( *((_DWORD *)v87 - 1) != 1415584157 )
                  __break(0x8228u);
                LODWORD(result) = v87(&v170);
                if ( (result & 0x80000000) != 0 )
                {
                  v110 = result;
                  v8 = v14 + v68;
                  goto LABEL_273;
                }
                v84 = v144;
                v34 = &unk_393000;
                *(_DWORD *)(v146 + 48) |= 1LL << *(_QWORD *)(v145 + 8);
              }
            }
            v148 = result;
            if ( *(_DWORD *)(v84 + 284) == 1 )
            {
              *((_QWORD *)v3 + 77) = v174;
              v88 = v34[458] & 0x1000010LL;
              if ( v88 )
              {
                if ( !debug_priority )
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                    3,
                    v88,
                    4,
                    "__cam_req_mgr_send_req",
                    1536,
                    "Apply req:%lld done with last_applied_done_timestamp:0x%llx",
                    v171);
              }
            }
            s[1] = v171;
            LODWORD(s[0]) = 3;
            LODWORD(s[2]) = HIDWORD(v170);
            s[3] = -1;
            ((void (__fastcall *)(unsigned int *, _QWORD *))_cam_req_mgr_update_state_monitor_array)(a1, s);
            v89 = v152;
            if ( (_DWORD)v2 == a1[3] )
              v89 = v171;
            v152 = v89;
            LODWORD(result) = v148;
            v34 = &unk_393000;
            goto LABEL_171;
          }
        }
        v16 = v34[458];
        if ( (v16 & 0x10) != 0 && !debug_priority )
        {
          if ( (unsigned int)v2 > 2 )
            goto LABEL_325;
          v149 = result;
          v90 = v34;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v34[458] & 0x10LL,
            4,
            "__cam_req_mgr_send_req",
            1450,
            "dev %s skip %d req_id %lld prev_apply_req:%lld frame_duration_changing:%d",
            (const char *)(v14 + v68 + 28),
            v71,
            *(_QWORD *)(v11 + 8),
            *(_QWORD *)&v160[6 * (int)v2 + 2],
            v155);
          LODWORD(result) = v149;
          v34 = v90;
          HIDWORD(v170) = *(_DWORD *)(v14 + v68);
        }
        else
        {
          v16 = *v69;
          HIDWORD(v170) = *v69;
          if ( (unsigned int)v2 > 2 )
            goto LABEL_325;
        }
        HIDWORD(v173) = v6;
        LODWORD(v173) = 0;
        v11 = *(_QWORD *)&v160[6 * (int)v2 + 2];
        v16 = a1[2];
        v171 = v11;
        if ( (unsigned int)v16 > 2 )
          goto LABEL_325;
        v172 = *(_QWORD *)&v160[6 * (unsigned int)v16 + 2];
        v72 = *(_QWORD *)(v154 + 16);
        BYTE3(v175) = v155;
        BYTE2(v175) = v72 == -1;
        v73 = *(_QWORD *)(v14 + v68 + 304);
        if ( v73 )
        {
          v74 = *(void (__fastcall **)(_QWORD))(v73 + 24);
          if ( v74 )
          {
            v67 = result;
            v2 = (__int64)v34;
            if ( *((_DWORD *)v74 - 1) != 1415584157 )
              __break(0x8228u);
            v74(&v170);
            goto LABEL_170;
          }
        }
      }
    }
LABEL_171:
    ++v66;
    v65 = v68 + 320;
  }
  while ( v66 < (int)a1[1] );
  if ( (result & 0x80000000) == 0 )
  {
    v62 = v158;
    v35 = v160;
    v91 = v152;
    goto LABEL_232;
  }
  v110 = result;
  v8 = 0;
LABEL_273:
  v5 = "__cam_req_mgr_send_req";
  if ( (unsigned int)__ratelimit(&_cam_req_mgr_send_req__rs, "__cam_req_mgr_send_req") )
    v111 = 3;
  else
    v111 = 2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    v111,
    16,
    2,
    "__cam_req_mgr_send_req",
    1554,
    "APPLY FAILED pd %d req_id %lld",
    *(_DWORD *)(v14 + v68 + 288),
    v171);
  v13 = v158;
  v2 = (__int64)v156;
  if ( (v66 & 0x80000000) == 0 )
  {
    v112 = 5 * v66;
    v113 = v66 + 1;
    v5 = (_BYTE *)(&_ksymtab_cam_cci_dump_registers + 1);
    v114 = v112 << 6;
    do
    {
      v116 = *((_QWORD *)a1 + 5);
      HIDWORD(v165) = 0;
      v117 = *a1;
      v118 = (unsigned int *)(v116 + v114);
      v119 = *v118;
      v164 = v171;
      LODWORD(v166) = 1;
      v163 = __PAIR64__(v119, v117);
      v120 = *((_QWORD *)v118 + 38);
      if ( v120 )
      {
        v121 = *(void (__fastcall **)(_QWORD))(v120 + 40);
        if ( v121 )
        {
          if ( *((_DWORD *)v121 - 1) != -662406558 )
            __break(0x8228u);
          v121(&v163);
        }
      }
      v115 = v113-- <= 1;
      v114 -= 320;
    }
    while ( !v115 );
  }
  _cam_req_mgr_notify_frame_skip(a1, (unsigned int)v6);
  result = v110;
LABEL_285:
  v18 = v157;
LABEL_70:
  *v18 = 2;
  *((_BYTE *)v3 + 594) = 0;
  if ( !v8 || (v3[148] & 1) != 0 )
  {
    v43 = result;
    if ( (unsigned int)__ratelimit(&_cam_req_mgr_process_req__rs_150, "__cam_req_mgr_process_req") )
      v44 = 3;
    else
      v44 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v44,
      16,
      2,
      "__cam_req_mgr_process_req",
      2466,
      "workqueue congestion, last applied idx:%d rd idx:%d",
      *(_DWORD *)(v13 + 3472),
      *(_DWORD *)(v13 + 3464));
    result = v43;
    goto LABEL_12;
  }
  v33 = v3[130];
  if ( (_DWORD)result != -11 )
    v3[130] = ++v33;
  if ( v33 >= 3 )
  {
    v16 = debug_mdl;
    v14 = (unsigned int)result;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      v11 = *(unsigned int *)(v13 + 3464);
      if ( (unsigned int)v11 <= 0x2F )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "__cam_req_mgr_process_req",
          2435,
          "Max retry attempts (count %d) reached on link[0x%x] for req [%lld]",
          3,
          *a1,
          *(_QWORD *)(v159 + 72LL * (unsigned int)v11 + 16));
        goto LABEL_77;
      }
    }
    else
    {
LABEL_77:
      cam_req_mgr_debug_delay_detect();
      v16 = *(unsigned int *)(v13 + 3464);
      if ( (unsigned int)v16 <= 0x2F )
      {
        trace_cam_delay_detect(*(_QWORD *)(v159 + 72LL * (unsigned int)v16 + 16), *a1, (unsigned int)v14);
        if ( !*(_DWORD *)(v2 + 32) )
          *((_BYTE *)v3 + 593) = 1;
        _cam_req_mgr_notify_error_on_link(a1, v8);
        if ( *((_BYTE *)v3 + 593) == 1 )
        {
          ++*(_DWORD *)(v2 + 32);
          *((_BYTE *)v3 + 593) = 0;
        }
        v3[130] = 0;
LABEL_11:
        result = (unsigned int)v14;
        goto LABEL_12;
      }
    }
LABEL_325:
    __break(0x5512u);
LABEL_326:
    v123 = nullptr;
    goto LABEL_327;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
