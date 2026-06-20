__int64 __fastcall _cam_isp_ctx_acquire_dev_in_available(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x28
  _QWORD *v6; // x25
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x10
  int device_hdl; // w0
  int v11; // w8
  __int64 result; // x0
  __int64 v13; // x0
  _QWORD *v14; // x21
  int v15; // w8
  __int64 *v16; // x9
  int v17; // w19
  _DWORD *v18; // x10
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x23
  size_t v22; // x22
  unsigned int v23; // w8
  int v24; // w0
  __int64 v25; // x6
  __int64 v26; // x7
  const char *v27; // x5
  int v28; // w19
  __int64 v29; // x4
  __int64 *v30; // x8
  __int64 (__fastcall *v31)(__int64, __int64 *); // x9
  __int64 v32; // x0
  int v33; // w0
  unsigned int v34; // w19
  __int64 *v35; // x10
  __int64 (__fastcall *v36)(__int64, __int64 *); // x8
  __int64 v37; // x0
  int v38; // w0
  int v39; // w20
  unsigned int v40; // w9
  __int64 (__fastcall **v41)(); // x8
  void *v42; // x9
  __int64 v43; // x8
  int v44; // w9
  _QWORD v45[2]; // [xsp+28h] [xbp-188h] BYREF
  __int64 v46; // [xsp+38h] [xbp-178h]
  __int64 v47; // [xsp+40h] [xbp-170h]
  __int64 v48; // [xsp+48h] [xbp-168h]
  __int64 v49; // [xsp+50h] [xbp-160h]
  __int64 v50; // [xsp+58h] [xbp-158h]
  __int64 v51; // [xsp+60h] [xbp-150h]
  __int64 v52; // [xsp+68h] [xbp-148h]
  __int64 v53; // [xsp+70h] [xbp-140h]
  __int64 v54; // [xsp+78h] [xbp-138h]
  __int64 v55; // [xsp+80h] [xbp-130h]
  __int64 v56; // [xsp+88h] [xbp-128h] BYREF
  __int64 v57; // [xsp+90h] [xbp-120h]
  _QWORD *v58; // [xsp+98h] [xbp-118h]
  _QWORD v59[2]; // [xsp+A0h] [xbp-110h] BYREF
  __int128 v60; // [xsp+B0h] [xbp-100h] BYREF
  __int64 v61; // [xsp+C0h] [xbp-F0h]
  __int64 v62; // [xsp+C8h] [xbp-E8h]
  __int64 v63; // [xsp+D0h] [xbp-E0h]
  __int64 v64; // [xsp+D8h] [xbp-D8h] BYREF
  __int64 v65; // [xsp+E0h] [xbp-D0h]
  __int64 v66; // [xsp+E8h] [xbp-C8h]
  __int64 (__fastcall *v67)(__int64, __int64); // [xsp+F0h] [xbp-C0h]
  __int64 v68; // [xsp+F8h] [xbp-B8h]
  _QWORD *v69; // [xsp+100h] [xbp-B0h]
  __int64 v70; // [xsp+108h] [xbp-A8h]
  __int64 v71; // [xsp+110h] [xbp-A0h]
  __int64 v72; // [xsp+118h] [xbp-98h]
  __int64 v73; // [xsp+120h] [xbp-90h]
  __int64 v74; // [xsp+128h] [xbp-88h]
  __int64 v75; // [xsp+130h] [xbp-80h]
  __int64 v76; // [xsp+138h] [xbp-78h]
  __int64 v77; // [xsp+140h] [xbp-70h]
  __int64 v78; // [xsp+148h] [xbp-68h]
  __int64 v79; // [xsp+150h] [xbp-60h]
  __int64 v80; // [xsp+158h] [xbp-58h]
  __int64 v81; // [xsp+160h] [xbp-50h]
  __int64 v82; // [xsp+168h] [xbp-48h]
  __int64 v83; // [xsp+170h] [xbp-40h]
  __int64 v84; // [xsp+178h] [xbp-38h]
  __int64 v85; // [xsp+180h] [xbp-30h]
  __int64 v86; // [xsp+188h] [xbp-28h]
  __int64 v87; // [xsp+190h] [xbp-20h]
  __int64 v88; // [xsp+198h] [xbp-18h]
  __int64 v89; // [xsp+1A0h] [xbp-10h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 208);
  v4 = *(_QWORD *)(a1 + 256);
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
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
  v67 = nullptr;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v60 = 0u;
  v59[0] = 0;
  v59[1] = 0;
  v57 = 0;
  v58 = nullptr;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45[1] = 0;
  v46 = 0;
  v45[0] = 0;
  if ( !v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_dev_in_available",
      8433,
      "HW interface is not ready, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    result = 4294967282LL;
    goto LABEL_46;
  }
  v6 = (_QWORD *)(v4 + 37296);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_acquire_dev_in_available",
      8441,
      "session_hdl 0x%x, num_resources %d, hdl type %d, res %lld, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a2 + 4),
      *(_DWORD *)(a2 + 16),
      *(_DWORD *)(a2 + 12),
      *(_QWORD *)(a2 + 24),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  *(_DWORD *)(v4 + 45616) = cam_req_mgr_get_id_subscribed();
  v7 = *(unsigned int *)(a2 + 16);
  if ( (_DWORD)v7 == -16843010 )
  {
    *(_BYTE *)(v4 + 45742) = 1;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_acquire_dev_in_available",
        8448,
        "Acquire dev handle, ctx_idx: %u, link: 0x%x",
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    goto LABEL_9;
  }
  if ( (unsigned int)v7 >= 0x19 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_dev_in_available",
      8454,
      "Too much resources in the acquire, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    result = 4294967284LL;
    goto LABEL_46;
  }
  if ( *(_DWORD *)(a2 + 12) != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_dev_in_available",
      8462,
      "Only user pointer is supported, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    result = 4294967274LL;
    goto LABEL_46;
  }
  if ( mem_trace_en == 1 )
    v13 = cam_mem_trace_alloc(24 * v7, 0xCC0u, 0, "__cam_isp_ctx_acquire_dev_in_available", 0x2114u);
  else
    v13 = _kvmalloc_node_noprof(24LL * *(unsigned int *)(a2 + 16), 0, 3520, 0xFFFFFFFFLL);
  v14 = (_QWORD *)v13;
  if ( !v13 )
  {
    result = 4294967284LL;
    goto LABEL_46;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_acquire_dev_in_available",
      8475,
      "start copy %d resources from user, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a2 + 16),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  v20 = *(unsigned int *)(a2 + 16);
  if ( (unsigned int)v20 >= 0x5555556 )
  {
    __break(0x800u);
    goto LABEL_34;
  }
  v21 = *(_QWORD *)(a2 + 24);
  v22 = 24 * v20;
  _check_object_size(v14, 24 * v20, 0);
  if ( !inline_copy_from_user_5((int)v14, v21, v22) )
  {
    v66 = *(_QWORD *)(a1 + 232);
    v67 = cam_context_dump_pf_info;
    v23 = *(_DWORD *)(a2 + 16);
    v87 = 0;
    v88 = 0;
    v85 = 0;
    v86 = 0;
    v83 = 0;
    v84 = 0;
    v81 = 0;
    v82 = 0;
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
    v64 = a1;
    v65 = 0;
    v68 = v23;
    v69 = v14;
    v70 = 0;
    v24 = _cam_isp_ctx_allocate_mem_hw_entries(a1, &v64);
    if ( v24 )
    {
      v25 = *(unsigned int *)(a1 + 32);
      v26 = *(unsigned int *)(a1 + 64);
      v27 = "Ctx[%u] link: 0x%x allocate hw entry fail";
      v28 = v24;
      v29 = 8493;
LABEL_41:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_acquire_dev_in_available",
        v29,
        v27,
        v25,
        v26);
      v15 = v28;
      goto LABEL_42;
    }
    v30 = *(__int64 **)(a1 + 208);
    v31 = (__int64 (__fastcall *)(__int64, __int64 *))v30[3];
    v32 = *v30;
    if ( *((_DWORD *)v31 - 1) != 1863972096 )
      __break(0x8229u);
    v33 = v31(v32, &v64);
    if ( v33 )
    {
      v25 = *(unsigned int *)(a1 + 32);
      v26 = *(unsigned int *)(a1 + 64);
      v27 = "Acquire device failed, ctx_idx: %u, link: 0x%x";
      v28 = v33;
      v29 = 8502;
      goto LABEL_41;
    }
    v35 = *(__int64 **)(a1 + 208);
    LODWORD(v45[0]) = 4;
    LODWORD(v57) = 0;
    v56 = v70;
    v36 = (__int64 (__fastcall *)(__int64, __int64 *))v35[12];
    v58 = v45;
    v37 = *v35;
    if ( *((_DWORD *)v36 - 1) != 1863972096 )
      __break(0x8228u);
    v38 = v36(v37, &v56);
    if ( v38 )
    {
      v39 = v38;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_acquire_dev_in_available",
        8515,
        "HW command failed, ctx_idx: %u, link: 0x%x",
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      v15 = v39;
LABEL_21:
      v59[0] = *v6;
      if ( *(_BYTE *)(v4 + 45740) == 1 )
      {
        v16 = *(__int64 **)(a1 + 208);
        v17 = v15;
        v18 = (_DWORD *)v16[4];
        v19 = *v16;
        if ( *(v18 - 1) != 1863972096 )
          __break(0x822Au);
        ((void (__fastcall *)(__int64, _QWORD *))v18)(v19, v59);
        v15 = v17;
      }
      *v6 = 0;
      *(_BYTE *)(v4 + 45740) = 0;
      goto LABEL_42;
    }
    v40 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 3);
    switch ( v46 )
    {
      case 1LL:
        if ( v40 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_acquire_dev_in_available",
            8534,
            "FS2 Session has PIX, RD and RDI, ctx_idx: %u, link: 0x%x",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
        v41 = cam_isp_ctx_fs2_state_machine_irq;
        v42 = &cam_isp_ctx_fs2_state_machine;
        break;
      case 4LL:
        if ( v40 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_acquire_dev_in_available",
            8542,
            "offline Session has PIX and RD resources, ctx_idx: %u, link: 0x%x",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
        *(_QWORD *)(v4 + 40) = &cam_isp_ctx_offline_state_machine_irq;
        goto LABEL_67;
      case 2LL:
        if ( v40 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_acquire_dev_in_available",
            8525,
            "RDI only session Context, ctx_idx: %u, link: 0x%x",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
        *(_QWORD *)(v4 + 32) = &cam_isp_ctx_rdi_only_activated_state_machine;
        *(_QWORD *)(v4 + 40) = &cam_isp_ctx_rdi_only_activated_state_machine_irq;
        *(_BYTE *)(v4 + 45736) = 1;
        goto LABEL_67;
      default:
        if ( v40 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_acquire_dev_in_available",
            8548,
            "Session has PIX or PIX and RDI resources, ctx_idx: %u, link: 0x%x",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
        v41 = cam_isp_ctx_activated_state_machine_irq;
        v42 = &cam_isp_ctx_activated_state_machine;
        break;
    }
    *(_QWORD *)(v4 + 32) = v42;
    *(_QWORD *)(v4 + 40) = v41;
LABEL_67:
    v43 = v70;
    *(_BYTE *)(v4 + 45742) = 0;
    *(_BYTE *)(v4 + 45740) = 1;
    *v6 = v43;
    v44 = (unsigned __int8)v47;
    *(_QWORD *)(a1 + 264) = v43;
    *(_BYTE *)(v4 + 45749) = v44;
    *(_QWORD *)(v4 + 37400) = -1;
    *(_QWORD *)(v4 + 45232) = -1;
    *(_QWORD *)(v4 + 42112) = -1;
    *(_QWORD *)(v4 + 42120) = -1;
    *(_QWORD *)(v4 + 42128) = -1;
    *(_QWORD *)(v4 + 42136) = -1;
    *(_QWORD *)(v4 + 42144) = -1;
    *(_QWORD *)(v4 + 42152) = -1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_acquire_dev_in_available",
      8567,
      "Ctx_type: %u, ctx_id: %u, hw_mgr_ctx: %u bubble_recover %d",
      v46,
      *(_DWORD *)(a1 + 32),
      v71,
      v44);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v14, 0);
    else
      kvfree(v14);
LABEL_9:
    v8 = *(_DWORD *)(a2 + 4);
    v9 = *(_QWORD *)(a1 + 224);
    *(_QWORD *)((char *)&v60 + 4) = 0;
    LODWORD(v60) = v8;
    v62 = v9;
    v63 = a1;
    v61 = 8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_acquire_dev_in_available",
        8581,
        "get device handle form bridge, ctx_idx: %u, link: 0x%x",
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    device_hdl = cam_create_device_hdl((__int64)&v60);
    *(_DWORD *)(a1 + 60) = device_hdl;
    if ( device_hdl > 0 )
    {
      v11 = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(a2 + 8) = device_hdl;
      *(_DWORD *)(a1 + 240) = 2;
      *(_DWORD *)(a1 + 56) = v11;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_ctx_acquire_dev_in_available",
        8598,
        "Acquire success: session_hdl 0x%x num_rsrces %d ctx %u link: 0x%x",
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(a2 + 16),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      result = 0;
      goto LABEL_46;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_dev_in_available",
      8586,
      "Can not create device handle, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    v14 = nullptr;
    v15 = -14;
    goto LABEL_21;
  }
LABEL_34:
  v15 = -14;
LABEL_42:
  v34 = v15;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v14, 0);
  else
    kvfree(v14);
  result = v34;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
