__int64 __fastcall _cam_isp_ctx_config_dev_in_top_state(__int64 a1, __int64 a2)
{
  __int64 v4; // x24
  unsigned int *v5; // x20
  __int64 v6; // x21
  unsigned int **v7; // x8
  __int64 v8; // x9
  unsigned int inited; // w25
  __int64 v10; // x22
  size_t v11; // x0
  size_t v12; // x23
  __int64 v13; // x10
  __int64 *v14; // x9
  __int64 (__fastcall *v15)(__int64, __int64 *); // x8
  __int64 v16; // x0
  unsigned int v17; // w0
  unsigned __int64 v18; // x6
  __int64 v19; // x7
  unsigned __int64 v20; // x6
  int v21; // w10
  __int64 v22; // x9
  unsigned int *v23; // x28
  int v24; // w8
  __int64 v25; // x23
  __int64 v26; // x9
  __int64 v27; // x25
  __int64 v28; // x9
  int v29; // w8
  void *v30; // x0
  __int64 v31; // x8
  __int64 *v32; // x8
  _DWORD *v33; // x9
  __int64 v34; // x0
  __int64 v35; // x25
  int v36; // w8
  unsigned int *v37; // x9
  unsigned int v38; // w8
  unsigned int i; // w28
  unsigned int obj_ref; // w0
  __int64 v41; // x8
  signed int v42; // w0
  unsigned int v43; // w0
  __int64 v44; // x7
  const char *v45; // x5
  __int64 v46; // x4
  __int64 v47; // x6
  int v48; // w8
  __int64 v49; // x23
  __int64 v50; // x6
  unsigned int v51; // w8
  __int64 v52; // x6
  __int64 v53; // x7
  int v54; // w6
  __int64 v55; // x1
  bool v56; // w8
  unsigned __int64 v57; // x23
  __int64 v58; // x28
  bool v59; // cc
  signed int v60; // w0
  unsigned int *v61; // x1
  __int64 (__fastcall *v63)(_QWORD); // x8
  unsigned int v64; // w9
  unsigned int v65; // w10
  unsigned int v66; // w0
  int v67; // [xsp+8h] [xbp-248h]
  __int64 v68; // [xsp+40h] [xbp-210h] BYREF
  unsigned int *v69; // [xsp+48h] [xbp-208h]
  __int64 v70; // [xsp+50h] [xbp-200h]
  __int64 v71; // [xsp+58h] [xbp-1F8h]
  __int64 v72; // [xsp+60h] [xbp-1F0h]
  __int64 v73; // [xsp+68h] [xbp-1E8h]
  __int64 v74; // [xsp+70h] [xbp-1E0h]
  __int64 v75; // [xsp+78h] [xbp-1D8h]
  __int64 v76; // [xsp+80h] [xbp-1D0h]
  __int64 v77; // [xsp+88h] [xbp-1C8h]
  __int64 v78; // [xsp+90h] [xbp-1C0h]
  __int64 v79; // [xsp+98h] [xbp-1B8h]
  __int64 v80; // [xsp+A0h] [xbp-1B0h] BYREF
  __int64 v81; // [xsp+A8h] [xbp-1A8h]
  __int64 *v82; // [xsp+B0h] [xbp-1A0h]
  unsigned __int64 v83; // [xsp+B8h] [xbp-198h] BYREF
  __int64 v84; // [xsp+C0h] [xbp-190h]
  __int64 v85; // [xsp+C8h] [xbp-188h]
  __int64 v86; // [xsp+D0h] [xbp-180h]
  unsigned int *v87; // [xsp+D8h] [xbp-178h] BYREF
  _QWORD s[46]; // [xsp+E0h] [xbp-170h] BYREF

  s[44] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87 = nullptr;
  memset(s, 0, 0x160u);
  v4 = *(_QWORD *)(a1 + 256);
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = nullptr;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = nullptr;
  v70 = 0;
  v68 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_config_dev_in_top_state",
      7927,
      "get free request object......ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  raw_spin_lock_bh(a1 + 120);
  v6 = a1 + 176;
  v5 = *(unsigned int **)(a1 + 176);
  if ( v5 == (unsigned int *)(a1 + 176) )
  {
    raw_spin_unlock_bh(a1 + 120);
LABEL_12:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_top_state",
      7940,
      "No more request obj free, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    inited = -12;
    goto LABEL_102;
  }
  v7 = *((unsigned int ***)v5 + 1);
  if ( *v7 == v5 && (v8 = *(_QWORD *)v5, *(unsigned int **)(*(_QWORD *)v5 + 8LL) == v5) )
  {
    *(_QWORD *)(v8 + 8) = v7;
    *v7 = (unsigned int *)v8;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 176));
  }
  *(_QWORD *)v5 = v5;
  *((_QWORD *)v5 + 1) = v5;
  raw_spin_unlock_bh(a1 + 120);
  if ( !v5 )
    goto LABEL_12;
  if ( *((_QWORD *)v5 + 17) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "__cam_isp_ctx_config_dev_in_top_state",
      7946,
      "[%s][%d] Missing free request %llu local packet",
      (const char *)a1,
      *(_DWORD *)(a1 + 32),
      *((_QWORD *)v5 + 3));
    inited = -22;
    goto LABEL_98;
  }
  v10 = *((_QWORD *)v5 + 4);
  v11 = cam_context_parse_config_cmd(a1, a2, &v87);
  inited = (unsigned int)v87;
  if ( !v87 || (unsigned __int64)v87 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_98;
  v12 = v11;
  if ( (unsigned int)cam_packet_util_validate_packet(v87, v11) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_top_state",
      7960,
      "Invalid packet params");
    inited = -22;
LABEL_97:
    cam_common_mem_free((__int64)v87);
LABEL_98:
    raw_spin_lock_bh(a1 + 120);
    *((_QWORD *)v5 + 17) = 0;
    v61 = *(unsigned int **)(a1 + 184);
    if ( v5 == v61 || *(_QWORD *)v61 != v6 )
    {
      _list_add_valid_or_report(v5);
    }
    else
    {
      *(_QWORD *)(a1 + 184) = v5;
      *(_QWORD *)v5 = v6;
      *((_QWORD *)v5 + 1) = v61;
      *(_QWORD *)v61 = v5;
    }
    raw_spin_unlock_bh(a1 + 120);
    goto LABEL_102;
  }
  v13 = *(_QWORD *)(v4 + 37296);
  LODWORD(v68) = 5;
  v69 = v87;
  v14 = *(__int64 **)(a1 + 208);
  LODWORD(v81) = 0;
  v80 = v13;
  v82 = &v68;
  v15 = (__int64 (__fastcall *)(__int64, __int64 *))v14[12];
  v16 = *v14;
  if ( *((_DWORD *)v15 - 1) != 1863972096 )
    __break(0x8228u);
  v17 = v15(v16, &v80);
  if ( v17 )
  {
    inited = v17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_top_state",
      7975,
      "HW command failed, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    goto LABEL_97;
  }
  if ( (_DWORD)v70 == 1 )
  {
    v19 = *((_QWORD *)v87 + 1);
    v20 = *(unsigned int *)(a1 + 464);
    if ( v19 - 1 < v20 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_config_dev_in_top_state",
        7992,
        "last flushed req is %lld, config dev(init) for req %lld, ctx_idx: %u, link: 0x%x",
        v20,
        v19,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      inited = -53;
      goto LABEL_97;
    }
  }
  else if ( (_DWORD)v70 == 2 )
  {
    v18 = *((_QWORD *)v87 + 1);
    if ( v18 <= *(unsigned int *)(a1 + 464) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_ctx_config_dev_in_top_state",
        7984,
        "request %lld has been flushed, reject packet, ctx_idx: %u, link: 0x%x",
        v18,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      inited = -53;
      goto LABEL_97;
    }
  }
  s[0] = v87;
  s[1] = v12;
  v21 = *(_DWORD *)(a1 + 476);
  v22 = *(_QWORD *)(v4 + 37296);
  v23 = v5 + 28;
  LODWORD(s[3]) = *(_DWORD *)(a1 + 468);
  v24 = *(_DWORD *)(a1 + 472);
  s[2] = v22;
  v25 = *(_QWORD *)(v10 + 4432);
  v26 = *(_QWORD *)(v10 + 8);
  HIDWORD(s[5]) = v21;
  v27 = *(_QWORD *)(v10 + 4400);
  HIDWORD(s[7]) = v24;
  s[4] = v26;
  s[6] = *(_QWORD *)(v10 + 24);
  v28 = *(_QWORD *)(v10 + 40);
  s[42] = v5 + 32;
  s[40] = v10 + 80;
  LODWORD(s[7]) = 0;
  LODWORD(s[9]) = 0;
  s[8] = v28;
  v29 = *(_DWORD *)(v4 + 45756);
  s[41] = v5 + 28;
  LODWORD(s[43]) = v29;
  memset((void *)(v10 + 80), 0, 0x1110u);
  *(_QWORD *)(v10 + 4400) = v27;
  v30 = *(void **)(v10 + 24);
  *(_QWORD *)(v10 + 4432) = v25;
  memset(v30, 0, (unsigned __int64)*(unsigned int *)(a1 + 476) << 6);
  v31 = s[41];
  *(_QWORD *)s[41] = s[41];
  *(_QWORD *)(v31 + 8) = v31;
  v32 = *(__int64 **)(a1 + 208);
  v33 = (_DWORD *)v32[7];
  v34 = *v32;
  if ( *(v33 - 1) != 1863972096 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD *))v33)(v34, s) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_top_state",
      8031,
      "Prepare config packet failed in HW layer, ctx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    inited = -14;
LABEL_96:
    cam_smmu_buffer_tracker_putref(v23);
    cam_mem_put_kref(*(_DWORD *)(v10 + 4328));
    goto LABEL_97;
  }
  v35 = v10 + 4096;
  *(_DWORD *)(v10 + 16) = s[5];
  *(_DWORD *)(v10 + 32) = s[7];
  v36 = s[9];
  *(_WORD *)(v10 + 4504) = 0;
  v37 = v87;
  *(_QWORD *)(v10 + 52) = 0;
  *(_BYTE *)(v10 + 4506) = 0;
  *(_DWORD *)(v10 + 48) = v36;
  *(_QWORD *)(v10 + 4320) = v37;
  *((_QWORD *)v5 + 16) = v5;
  *((_QWORD *)v5 + 17) = v37;
  v38 = *(_DWORD *)(v10 + 32);
  if ( v38 )
  {
    for ( i = 0; i < v38; ++i )
    {
      obj_ref = cam_sync_get_obj_ref(*(_DWORD *)(*(_QWORD *)(v10 + 24) + ((__int64)(int)i << 6) + 16));
      v41 = *(_QWORD *)(v10 + 24);
      if ( obj_ref )
      {
        v44 = *(unsigned int *)(a1 + 32);
        inited = obj_ref;
        v45 = "Can't get ref for fence %d, ctx_idx: %u, link: 0x%x";
        v47 = *(unsigned int *)(v41 + ((__int64)(int)i << 6) + 16);
        v48 = *(_DWORD *)(a1 + 64);
        v46 = 8052;
        goto LABEL_41;
      }
      v42 = *(_DWORD *)(v41 + ((__int64)(int)i << 6) + 20);
      if ( v42 >= 1 )
      {
        v43 = cam_sync_get_obj_ref(v42);
        if ( v43 )
        {
          v44 = *(unsigned int *)(a1 + 32);
          inited = v43;
          v45 = "Can't get ref for early fence %d, ctx_idx: %u, link: 0x%x";
          v46 = 8062;
          v47 = *(unsigned int *)(*(_QWORD *)(v10 + 24) + ((__int64)(int)i << 6) + 20);
          v48 = *(_DWORD *)(a1 + 64);
LABEL_41:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_config_dev_in_top_state",
            v46,
            v45,
            v47,
            v44,
            v48);
          goto LABEL_87;
        }
      }
      v38 = *(_DWORD *)(v10 + 32);
    }
    v37 = v87;
    v35 = v10 + 4096;
  }
  else
  {
    i = 0;
  }
  v49 = v4 + 45584;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_config_dev_in_top_state",
      8072,
      "packet req-id:%lld, opcode:%d, num_entry:%d, num_fence_out: %d, num_fence_in: %d, ctx_idx: %u, link: 0x%x",
      *((_QWORD *)v37 + 1),
      *(_DWORD *)(v10 + 88),
      *(_DWORD *)(v10 + 16),
      v38,
      *(_DWORD *)(v10 + 48),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    v37 = v87;
  }
  v50 = *((_QWORD *)v37 + 1);
  v5[4] = 1;
  *((_QWORD *)v5 + 3) = v50;
  v51 = *(_DWORD *)(a1 + 240);
  if ( *(_DWORD *)(v10 + 88) == 1 )
  {
    if ( v51 > 4 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, int))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_config_dev_in_top_state",
        8113,
        "Received INIT pkt in wrong state:%d, ctx:%u, link:0x%x",
        v51,
        *(unsigned int *)(a1 + 32),
        *(_DWORD *)(a1 + 64),
        v67);
    }
    else
    {
      v52 = *(unsigned int *)(v4 + 45756);
      if ( !(_DWORD)v52 )
      {
        inited = _cam_isp_ctx_enqueue_init_request(a1, v5);
        if ( inited )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_config_dev_in_top_state",
            8084,
            "Enqueue INIT pkt failed, ctx: %u, link: 0x%x",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
        *(_BYTE *)(v4 + 45741) = 1;
LABEL_77:
        v56 = *(_BYTE *)(v4 + 45738) == 1 && *((_QWORD *)v5 + 3);
        *(_BYTE *)(v4 + 45739) = v56;
        if ( *(_DWORD *)(a1 + 240) == 4 )
        {
          ++*(_DWORD *)(v4 + 45700);
          if ( !inited )
            goto LABEL_63;
LABEL_87:
          if ( (int)(i - 1) >= 0 )
          {
            v57 = (unsigned __int64)(i - 1) << 6;
            v58 = i - 1 + 1LL;
            do
            {
              if ( (unsigned int)cam_sync_put_obj_ref(*(_DWORD *)(*(_QWORD *)(v10 + 24) + v57 + 16)) )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x80000,
                  1,
                  "__cam_isp_ctx_config_dev_in_top_state",
                  8183,
                  "Failed to put ref of fence %d, ctx_idx: %u, link: 0x%x",
                  *(_DWORD *)(*(_QWORD *)(v10 + 24) + v57 + 16),
                  *(_DWORD *)(a1 + 32),
                  *(_DWORD *)(a1 + 64));
              v60 = *(_DWORD *)(*(_QWORD *)(v10 + 24) + v57 + 20);
              if ( v60 >= 1 && (unsigned int)cam_sync_put_obj_ref(v60) )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x80000,
                  1,
                  "__cam_isp_ctx_config_dev_in_top_state",
                  8190,
                  "Failed to put ref of early fence %d, ctx_idx: %u, link: 0x%x",
                  *(_DWORD *)(*(_QWORD *)(v10 + 24) + v57 + 20),
                  *(_DWORD *)(a1 + 32),
                  *(_DWORD *)(a1 + 64));
              v59 = v58-- <= 1;
              v57 -= 64LL;
            }
            while ( !v59 );
          }
          v23 = v5 + 28;
          goto LABEL_96;
        }
LABEL_112:
        if ( !inited )
          goto LABEL_63;
        goto LABEL_87;
      }
      if ( (_DWORD)v52 == 1 )
      {
        v53 = *(unsigned int *)(v4 + 45760);
        if ( (unsigned int)v53 >= 2 )
        {
          _cam_isp_ctx_enqueue_request_in_order(a1, v5, 1);
          inited = 0;
          v54 = *(_DWORD *)(v4 + 45756) + 1;
          *(_DWORD *)(v4 + 45756) = v54;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "__cam_isp_ctx_config_dev_in_top_state",
              8093,
              "Enqueue init req with count: %d, max_delay:%d, ctx: %u, link: 0x%x",
              v54,
              *(_DWORD *)(v4 + 45760),
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 64));
            inited = 0;
          }
          goto LABEL_77;
        }
      }
      else
      {
        v53 = *(unsigned int *)(v4 + 45760);
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _DWORD, _DWORD))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_config_dev_in_top_state",
        8099,
        "Received wrong init req cnt:%d, max_delay:%d, ctx_idx: %u, link: 0x%x",
        v52,
        v53,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    }
LABEL_86:
    inited = -22;
    goto LABEL_87;
  }
  if ( v51 <= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_top_state",
      8120,
      "Received update req %lld in wrong state:%d, ctx_idx: %u, link: 0x%x",
      v50,
      v51,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    goto LABEL_86;
  }
  if ( v51 == 4 && *(_DWORD *)(v4 + 45700) <= 1u )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_top_state",
      8130,
      "Received update req %lld in wrong state:%d, ctx_idx: %u, link: 0x%x, still waiting on INITs to resume num_inits: %u",
      v50,
      4,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(v4 + 45700));
    inited = 0;
    goto LABEL_87;
  }
  if ( (*(_BYTE *)(v4 + 45737) & 1) == 0 && (*(_BYTE *)(v4 + 45738) & 1) == 0 )
  {
    v63 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 216) + 16LL);
    if ( !v63 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_config_dev_in_top_state",
        8157,
        "Unable to add request: req id=%llu,ctx: %u,link: 0x%x",
        v50,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      inited = -19;
      goto LABEL_87;
    }
    v65 = *(_DWORD *)(a1 + 60);
    v64 = *(_DWORD *)(a1 + 64);
    v85 = 0;
    v86 = 0;
    v84 = v50;
    v83 = __PAIR64__(v65, v64);
    BYTE1(v86) = *(_BYTE *)(v35 + 272);
    if ( *((_DWORD *)v63 - 1) != -1947527126 )
      __break(0x8228u);
    v66 = v63(&v83);
    v49 = v4 + 45584;
    if ( v66 )
    {
      inited = v66;
      if ( v66 == -53 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "__cam_isp_ctx_config_dev_in_top_state",
          8147,
          "Add req failed: req id=%llu, it has been flushed on link 0x%x ctx %u",
          *((_QWORD *)v5 + 3),
          *(_DWORD *)(a1 + 64),
          *(_DWORD *)(a1 + 32));
        inited = -53;
        goto LABEL_87;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_config_dev_in_top_state",
        8151,
        "Add req failed: req id=%llu on link 0x%x ctx %u",
        *((_QWORD *)v5 + 3),
        *(_DWORD *)(a1 + 64),
        *(_DWORD *)(a1 + 32));
      v49 = v4 + 45584;
      goto LABEL_112;
    }
  }
  _cam_isp_ctx_enqueue_request_in_order(a1, v5, 1);
LABEL_63:
  if ( byte_3A8B90 )
    cam_isp_ctx_dump_req(v10);
  v55 = debug_mdl & 0x1000008;
  if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v55,
      4,
      "__cam_isp_ctx_config_dev_in_top_state",
      8169,
      "Preprocessing Config req_id %lld successful on ctx %u, link: 0x%x",
      *((_QWORD *)v5 + 3),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  if ( *(_BYTE *)(v49 + 153) == 1 && *(_DWORD *)v49 )
  {
    _cam_isp_ctx_schedule_apply_req(v4, v55);
    inited = 0;
  }
  else if ( *(_BYTE *)(v49 + 154) == 1 && *(_DWORD *)(v10 + 88) != 1 )
  {
    _cam_isp_ctx_apply_pending_req(v4, v55);
    inited = 0;
  }
  else
  {
    inited = 0;
  }
LABEL_102:
  _ReadStatusReg(SP_EL0);
  return inited;
}
