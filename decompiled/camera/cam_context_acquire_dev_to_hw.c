__int64 __fastcall cam_context_acquire_dev_to_hw(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w8
  __int64 result; // x0
  __int64 v6; // x9
  int v7; // w7
  __int64 v8; // x10
  int v9; // w11
  __int64 v10; // x9
  __int64 v11; // x0
  __int64 v12; // x23
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x7
  const char *v17; // x5
  __int64 v18; // x4
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x6
  __int64 *v29; // x9
  __int64 v30; // x11
  __int64 *v31; // x12
  bool v32; // zf
  __int64 *v33; // x8
  __int64 (__fastcall *v34)(__int64, __int64 *); // x9
  __int64 v35; // x0
  unsigned int v36; // w0
  unsigned int v37; // w20
  int v38; // w5
  int v39; // w4
  int v40; // w8
  __int64 v41; // x9
  __int64 v42; // x10
  int device_hdl; // w0
  __int64 *v44; // x9
  _DWORD *v45; // x8
  __int64 v46; // x0
  int v47; // [xsp+0h] [xbp-130h]
  _QWORD v48[2]; // [xsp+28h] [xbp-108h] BYREF
  __int128 v49; // [xsp+38h] [xbp-F8h] BYREF
  __int64 v50; // [xsp+48h] [xbp-E8h]
  __int64 v51; // [xsp+50h] [xbp-E0h]
  __int64 v52; // [xsp+58h] [xbp-D8h]
  __int64 v53; // [xsp+60h] [xbp-D0h] BYREF
  __int64 v54; // [xsp+68h] [xbp-C8h]
  __int64 v55; // [xsp+70h] [xbp-C0h]
  __int64 v56; // [xsp+78h] [xbp-B8h]
  __int64 v57; // [xsp+80h] [xbp-B0h]
  __int64 v58; // [xsp+88h] [xbp-A8h]
  __int64 v59; // [xsp+90h] [xbp-A0h]
  __int64 v60; // [xsp+98h] [xbp-98h]
  __int64 v61; // [xsp+A0h] [xbp-90h]
  __int64 v62; // [xsp+A8h] [xbp-88h]
  __int64 v63; // [xsp+B0h] [xbp-80h]
  __int64 v64; // [xsp+B8h] [xbp-78h]
  __int64 v65; // [xsp+C0h] [xbp-70h]
  __int64 v66; // [xsp+C8h] [xbp-68h]
  __int64 v67; // [xsp+D0h] [xbp-60h]
  __int64 v68; // [xsp+D8h] [xbp-58h]
  __int64 v69; // [xsp+E0h] [xbp-50h]
  __int64 v70; // [xsp+E8h] [xbp-48h]
  __int64 v71; // [xsp+F0h] [xbp-40h]
  __int64 v72; // [xsp+F8h] [xbp-38h]
  __int64 v73; // [xsp+100h] [xbp-30h]
  __int64 v74; // [xsp+108h] [xbp-28h]
  __int64 v75; // [xsp+110h] [xbp-20h]
  __int64 v76; // [xsp+118h] [xbp-18h]
  __int64 v77; // [xsp+120h] [xbp-10h]
  __int64 v78; // [xsp+128h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v51 = 0;
  v52 = 0;
  v50 = 0;
  v48[1] = 0;
  v49 = 0u;
  v48[0] = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_acquire_dev_to_hw",
      741,
      "Invalid input params %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
    goto LABEL_69;
  }
  if ( !*(_QWORD *)(a1 + 208) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_acquire_dev_to_hw",
      748,
      "[%s][%d] HW interface is not ready",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    result = 4294967282LL;
    goto LABEL_69;
  }
  if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x80000,
      4,
      "cam_context_acquire_dev_to_hw",
      755,
      "ses hdl: %x, num_res: %d, type: %d, res: %lld",
      a2[1],
      a2[4],
      a2[3],
      *((_QWORD *)a2 + 3));
  v4 = a2[4];
  if ( v4 >= 0x15 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_acquire_dev_to_hw",
      759,
      "[%s][%d] resource[%d] limit exceeded",
      a1,
      *(unsigned int *)(a1 + 32),
      v4);
LABEL_68:
    result = 4294967284LL;
    goto LABEL_69;
  }
  if ( a2[3] != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_acquire_dev_to_hw",
      767,
      "[%s][%d] Only user pointer is supported",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    result = 4294967274LL;
    goto LABEL_69;
  }
  v6 = *(_QWORD *)(a1 + 232);
  v7 = *(_DWORD *)(a1 + 32);
  v8 = *(_QWORD *)(a1 + 504);
  LODWORD(v57) = a2[4];
  v9 = *a2;
  v55 = v6;
  v10 = *((_QWORD *)a2 + 3);
  v53 = a1;
  LODWORD(v54) = v7;
  v76 = v8;
  v58 = v10;
  LODWORD(v77) = v9;
  if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x80000,
      4,
      "cam_context_allocate_mem_hw_entries",
      88,
      "%s[%d] num: max_hw %u in_map %u out_map %u req %u",
      (const char *)a1,
      v7,
      *(_DWORD *)(a1 + 468),
      *(_DWORD *)(a1 + 472),
      *(_DWORD *)(a1 + 476),
      *(_DWORD *)(a1 + 200));
  if ( mem_trace_en == 1 )
  {
    v11 = cam_mem_trace_alloc(
            8LL * *(unsigned int *)(a1 + 200),
            0xCC0u,
            0,
            "cam_context_allocate_mem_hw_entries",
            0x5Bu);
    *(_QWORD *)(a1 + 480) = v11;
    if ( v11 )
      goto LABEL_17;
LABEL_27:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_allocate_mem_hw_entries",
      95,
      "%s[%d] no memory for hw_update_entry",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
LABEL_67:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_acquire_dev_to_hw",
      786,
      "[%s][%d] Alloc entries failed",
      a1,
      *(unsigned int *)(a1 + 32),
      v47);
    goto LABEL_68;
  }
  v15 = _kvmalloc_node_noprof(8LL * *(unsigned int *)(a1 + 200), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 480) = v15;
  if ( !v15 )
    goto LABEL_27;
LABEL_17:
  if ( *(_DWORD *)(a1 + 200) )
  {
    v12 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v13 = mem_trace_en == 1
          ? cam_mem_trace_alloc(
              32LL * *(unsigned int *)(a1 + 468),
              0xCC0u,
              0,
              "cam_context_allocate_mem_hw_entries",
              0x65u)
          : _kvmalloc_node_noprof(32LL * *(unsigned int *)(a1 + 468), 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(*(_QWORD *)(a1 + 480) + 8 * v12) = v13;
      if ( !*(_QWORD *)(*(_QWORD *)(a1 + 480) + 8 * v12) )
        break;
      v14 = *(unsigned int *)(a1 + 200);
      if ( ++v12 >= v14 )
      {
        v19 = 8 * v14;
        goto LABEL_30;
      }
    }
    v16 = *(unsigned int *)(a1 + 32);
    v17 = "%s[%d] no memory for hw_update_entry: %u";
    v18 = 105;
    goto LABEL_65;
  }
  v19 = 0;
LABEL_30:
  if ( mem_trace_en == 1 )
  {
    v20 = cam_mem_trace_alloc(v19, 0xCC0u, 0, "cam_context_allocate_mem_hw_entries", 0x71u);
    *(_QWORD *)(a1 + 488) = v20;
    if ( v20 )
      goto LABEL_32;
LABEL_41:
    v16 = *(unsigned int *)(a1 + 32);
    v17 = "%s[%d] no memory for in_map_entries";
    v18 = 117;
LABEL_56:
    v28 = a1;
LABEL_66:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_allocate_mem_hw_entries",
      v18,
      v17,
      v28,
      v16,
      v47);
    cam_context_free_mem_hw_entries((_QWORD *)a1);
    goto LABEL_67;
  }
  v23 = _kvmalloc_node_noprof(8LL * *(unsigned int *)(a1 + 200), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 488) = v23;
  if ( !v23 )
    goto LABEL_41;
LABEL_32:
  if ( *(_DWORD *)(a1 + 200) )
  {
    v12 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v21 = mem_trace_en == 1
          ? cam_mem_trace_alloc(
              (unsigned __int64)*(unsigned int *)(a1 + 472) << 6,
              0xCC0u,
              0,
              "cam_context_allocate_mem_hw_entries",
              0x7Cu)
          : _kvmalloc_node_noprof((unsigned __int64)*(unsigned int *)(a1 + 472) << 6, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(*(_QWORD *)(a1 + 488) + 8 * v12) = v21;
      if ( !*(_QWORD *)(*(_QWORD *)(a1 + 488) + 8 * v12) )
        break;
      v22 = *(unsigned int *)(a1 + 200);
      if ( ++v12 >= v22 )
      {
        v24 = 8 * v22;
        goto LABEL_44;
      }
    }
    v16 = *(unsigned int *)(a1 + 32);
    v17 = "%s[%d] no memory for in_map_entries: %u";
    v18 = 128;
    goto LABEL_65;
  }
  v24 = 0;
LABEL_44:
  if ( mem_trace_en != 1 )
  {
    v27 = _kvmalloc_node_noprof(8LL * *(unsigned int *)(a1 + 200), 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a1 + 496) = v27;
    if ( v27 )
      goto LABEL_46;
    goto LABEL_55;
  }
  v25 = cam_mem_trace_alloc(v24, 0xCC0u, 0, "cam_context_allocate_mem_hw_entries", 0x88u);
  *(_QWORD *)(a1 + 496) = v25;
  if ( !v25 )
  {
LABEL_55:
    v16 = *(unsigned int *)(a1 + 32);
    v17 = "%s[%d] no memory for out_map_entries";
    v18 = 140;
    goto LABEL_56;
  }
LABEL_46:
  if ( *(_DWORD *)(a1 + 200) )
  {
    v12 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v26 = mem_trace_en == 1
          ? cam_mem_trace_alloc(
              (unsigned __int64)*(unsigned int *)(a1 + 476) << 6,
              0xCC0u,
              0,
              "cam_context_allocate_mem_hw_entries",
              0x93u)
          : _kvmalloc_node_noprof((unsigned __int64)*(unsigned int *)(a1 + 476) << 6, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(*(_QWORD *)(a1 + 496) + 8 * v12) = v26;
      if ( !*(_QWORD *)(*(_QWORD *)(a1 + 496) + 8 * v12) )
        break;
      if ( ++v12 >= (unsigned __int64)*(unsigned int *)(a1 + 200) )
        goto LABEL_57;
    }
    v16 = *(unsigned int *)(a1 + 32);
    v17 = "%s[%d] no memory for out_map_entries: %u";
    v18 = 151;
LABEL_65:
    v28 = a1;
    v47 = v12;
    goto LABEL_66;
  }
LABEL_57:
  v29 = *(__int64 **)(a1 + 176);
  if ( v29 != (__int64 *)(a1 + 176) )
  {
    do
    {
      v30 = *((unsigned int *)v29 + 23);
      v31 = (__int64 *)*v29;
      v32 = *v29 == a1 + 176;
      v29[5] = *(_QWORD *)(*(_QWORD *)(a1 + 480) + 8 * v30);
      v29[7] = *(_QWORD *)(*(_QWORD *)(a1 + 488) + 8 * v30);
      v29[9] = *(_QWORD *)(*(_QWORD *)(a1 + 496) + 8 * v30);
      v29 = v31;
    }
    while ( !v32 );
  }
  v33 = *(__int64 **)(a1 + 208);
  v34 = (__int64 (__fastcall *)(__int64, __int64 *))v33[3];
  v35 = *v33;
  if ( *((_DWORD *)v34 - 1) != 1863972096 )
    __break(0x8229u);
  v36 = v34(v35, &v53);
  if ( v36 )
  {
    v37 = v36;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_acquire_dev_to_hw",
      796,
      "[%s][%d] Acquire device failed session hdl: 0x%x dev hdl: 0x%x",
      (const char *)a1,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 56),
      *(_DWORD *)(a1 + 60));
    result = v37;
  }
  else
  {
    v38 = v60;
    v39 = *(_DWORD *)(a1 + 32);
    *(_QWORD *)(a1 + 264) = v59;
    *(_DWORD *)(a1 + 272) = v38;
    snprintf((char *)(a1 + 276), 0x80u, "%s_ctx[%d]_hwmgrctx[%d]_Done", (const char *)a1, v39, v38);
    v40 = a2[1];
    v41 = *(_QWORD *)(a1 + 224);
    v42 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)((char *)&v49 + 4) = 0;
    LODWORD(v49) = v40;
    v51 = v41;
    v52 = a1;
    v50 = v42;
    device_hdl = cam_create_device_hdl((__int64)&v49);
    *(_DWORD *)(a1 + 60) = device_hdl;
    if ( device_hdl <= 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_acquire_dev_to_hw",
        821,
        "[%s][%d] Can not create device handle",
        (const char *)a1,
        *(_DWORD *)(a1 + 32));
      v44 = *(__int64 **)(a1 + 208);
      v48[0] = *(_QWORD *)(a1 + 264);
      v45 = (_DWORD *)v44[4];
      v46 = *v44;
      if ( *(v45 - 1) != 1863972096 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v45)(v46, v48);
      *(_QWORD *)(a1 + 264) = 0;
      result = 4294967282LL;
      *(_DWORD *)(a1 + 60) = -1;
    }
    else
    {
      a2[2] = device_hdl;
      *(_DWORD *)(a1 + 56) = a2[1];
      ((void (__fastcall *)(__int64, __int64, _QWORD, const char *, __int64, const char *, __int64))cam_print_log)(
        2,
        0x80000,
        0,
        "cam_context_acquire_dev_to_hw",
        830,
        "Ctx[%s]: session_hdl 0x%x, dev_hdl 0x%x",
        a1 + 276);
      result = 0;
    }
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
