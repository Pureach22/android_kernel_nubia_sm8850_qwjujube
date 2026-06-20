__int64 __fastcall _cam_isp_context_try_match_buf_done_with_other_ports(
        int *a1,
        unsigned int *a2,
        __int64 a3,
        __int64 *a4,
        char a5)
{
  int *v9; // x28
  unsigned __int64 v10; // x25
  unsigned int *v11; // x27
  _BOOL4 v12; // w8
  unsigned __int64 v13; // x9
  unsigned int v14; // w10
  int v15; // w11
  __int64 v16; // x8
  int v17; // w12
  __int64 v18; // x24
  __int64 v19; // x26
  char v20; // w23
  __int64 v21; // x28
  __int64 v22; // x9
  unsigned int v23; // w24
  __int64 v24; // x23
  unsigned int v25; // w8
  __int64 v26; // x8
  __int64 *v27; // x8
  __int64 (__fastcall *v28)(__int64, __int64 *); // x9
  __int64 v29; // x0
  unsigned int v30; // w0
  char is_expanded_memory; // w0
  char v32; // w24
  int v33; // w23
  char v34; // w23
  const char *v35; // x0
  const char *v36; // x0
  unsigned int v37; // w8
  unsigned int v38; // w9
  const char *v39; // x0
  __int64 v42; // [xsp+38h] [xbp-88h] BYREF
  __int64 v43; // [xsp+40h] [xbp-80h]
  __int64 v44; // [xsp+48h] [xbp-78h]
  __int64 v45; // [xsp+50h] [xbp-70h]
  __int64 v46; // [xsp+58h] [xbp-68h]
  __int64 v47; // [xsp+60h] [xbp-60h]
  __int64 v48; // [xsp+68h] [xbp-58h]
  __int64 v49; // [xsp+70h] [xbp-50h]
  __int64 v50; // [xsp+78h] [xbp-48h]
  __int64 v51; // [xsp+80h] [xbp-40h]
  __int64 v52; // [xsp+88h] [xbp-38h]
  __int64 v53; // [xsp+90h] [xbp-30h]
  __int64 v54; // [xsp+98h] [xbp-28h] BYREF
  __int64 v55; // [xsp+A0h] [xbp-20h]
  __int64 *v56; // [xsp+A8h] [xbp-18h]
  __int64 v57; // [xsp+B0h] [xbp-10h]

  v9 = a1;
  v10 = 0;
  v11 = a2 + 1;
  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  while ( 1 )
  {
    v13 = *a2;
    if ( v10 >= v13 )
    {
      v23 = 0;
      goto LABEL_36;
    }
    if ( v10 == 36 )
      __break(0x5512u);
    v14 = v11[v10];
    if ( v14 == *(_DWORD *)(a3 + 4) )
      goto LABEL_2;
    v15 = *((_DWORD *)a4 + 8);
    if ( !v15 )
      break;
    v16 = a4[3];
    v17 = 0;
    while ( 1 )
    {
      v18 = v17;
      v19 = v16 + ((__int64)v17 << 6);
      if ( v14 != *(_DWORD *)v19 )
        goto LABEL_9;
      if ( (a5 & 1) == 0 )
        break;
      if ( (*(_BYTE *)(v19 + 24) & 1) != 0 )
      {
        v20 = debug_mdl;
        v21 = *a4;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v36 = _cam_isp_resource_handle_id_to_type(a1[11395], *(_DWORD *)v19);
          v37 = *(_DWORD *)(v19 + 4);
          v38 = __clz(__rbit32(v37));
          if ( !v37 )
            v38 = -1;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v20 & 8,
            4,
            "__cam_isp_context_try_match_buf_done_with_other_ports",
            2632,
            "[FRMHDR] Match buf done with other res: %s, frmhdr addr: %pK, hw_ctxt_id: %u, local_id: %u, req_id: %llu, ct"
            "x %u, link: 0x%x",
            v36,
            *(const void **)(v19 + 8),
            v38,
            *(_DWORD *)(*(_QWORD *)(v19 + 8) + 12LL),
            *(_QWORD *)(v21 + 24),
            *(_DWORD *)(*(_QWORD *)a1 + 32LL),
            *(_DWORD *)(*(_QWORD *)a1 + 64LL));
          v16 = a4[3];
          v21 = *a4;
        }
        v22 = *(_QWORD *)(v21 + 24);
        v9 = a1;
        v12 = v22 == *(_DWORD *)(*(_QWORD *)(v16 + (v18 << 6) + 8) + 12LL);
        goto LABEL_3;
      }
LABEL_9:
      ++v17;
      if ( v15 == (_DWORD)v18 + 1 )
        goto LABEL_16;
    }
    v55 = 0;
    v24 = *(_QWORD *)v9;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v25 = *(_DWORD *)v19;
    *(_DWORD *)(a3 + 12) = 0;
    LODWORD(v55) = 0;
    *(_DWORD *)(a3 + 4) = v25;
    v26 = *((_QWORD *)v9 + 4662);
    v43 = a3;
    v56 = &v42;
    v54 = v26;
    LODWORD(v42) = 12;
    v27 = *(__int64 **)(v24 + 208);
    v28 = (__int64 (__fastcall *)(__int64, __int64 *))v27[12];
    v29 = *v27;
    if ( *((_DWORD *)v28 - 1) != 1863972096 )
      __break(0x8229u);
    v30 = v28(v29, &v54);
    if ( v30 )
    {
      v23 = v30;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_context_match_last_consumed_addr_with_other_port",
        2568,
        "HW command failed, ctx %u, link: 0x%x",
        *(_DWORD *)(v24 + 32),
        *(_DWORD *)(v24 + 64));
      goto LABEL_36;
    }
    is_expanded_memory = cam_smmu_is_expanded_memory();
    v32 = debug_mdl;
    if ( (is_expanded_memory & 1) != 0 )
      v33 = *(_QWORD *)(v19 + 32) >> 8;
    else
      v33 = *(_QWORD *)(v19 + 32);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v39 = _cam_isp_resource_handle_id_to_type(v9[11395], *(_DWORD *)(a3 + 4));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v32 & 8,
        4,
        "__cam_isp_context_match_last_consumed_addr_with_other_port",
        2580,
        "Get res %s last_consumed_addr:0x%x cmp_addr:0x%x",
        v39,
        *(_DWORD *)(a3 + 12),
        v33);
    }
    if ( *(_DWORD *)(a3 + 12) != v33 )
    {
LABEL_2:
      v12 = 0;
      goto LABEL_3;
    }
    v34 = debug_mdl;
    v12 = 1;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v35 = _cam_isp_resource_handle_id_to_type(v9[11395], *(_DWORD *)(a3 + 4));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v34 & 8,
        4,
        "__cam_isp_context_match_last_consumed_addr_with_other_port",
        2584,
        "Consumed addr compare success for res:%s ",
        v35);
      v12 = 1;
    }
LABEL_3:
    ++v10;
    if ( v12 )
    {
      v23 = 1;
      goto LABEL_36;
    }
  }
LABEL_16:
  v12 = 0;
  v23 = 0;
  if ( v10 != (_DWORD)v13 - 1 )
    goto LABEL_3;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v23;
}
