__int64 __fastcall cam_ife_mgr_acquire_hw_for_ctx(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _DWORD *a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x28
  __int64 result; // x0
  __int64 v14; // x21
  int v15; // w24
  unsigned int v16; // w0
  __int64 v17; // x6
  const char *v18; // x5
  unsigned int v19; // w19
  __int64 v20; // x4
  unsigned int v21; // w0
  unsigned int v22; // w8
  int v23; // w22
  unsigned int *v24; // x25
  unsigned int ife_csid_rdi_res_type; // w24
  int v26; // w0
  char v27; // w9
  unsigned int v28; // w22
  unsigned int v29; // w22
  unsigned int v30; // w0
  int v31; // w7
  const char *v32; // x6
  const char *v33; // x6
  unsigned int v34; // w9
  __int64 v35; // x7
  int v36; // w8
  unsigned int v37; // w24
  unsigned int v38; // w0
  int v39; // w0
  unsigned int v40; // w20
  unsigned int v41; // w0
  unsigned int v42; // w0
  unsigned int v43; // w0
  unsigned int v44; // w0
  unsigned int v45; // w0
  unsigned int v46; // w0
  __int64 v47; // [xsp+18h] [xbp-8h]

  v7 = a1 + 0x2000;
  *(_BYTE *)(a1 + 9381) = *(_DWORD *)(a2 + 128) != 0;
  *(_BYTE *)(a1 + 9379) = *(_DWORD *)(a2 + 80) != 0;
  if ( *(_BYTE *)(a2 + 221) == 1 && (*(_BYTE *)(a1 + 9391) & 1) == 0 )
    *(_BYTE *)(a1 + 9391) = 1;
  if ( *(_DWORD *)(a1 + 96) )
  {
    if ( *(_DWORD *)(a1 + 100) != *(_DWORD *)(a2 + 8) && (*(_BYTE *)(a1 + 9378) & 1) == 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_acquire_res_root",
        4957,
        "No Free resource for this context, ctx_idx: %u",
        *(_DWORD *)(a1 + 56));
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_acquire_hw_for_ctx",
        5765,
        "Can not acquire root resource, ctx_idx: %u",
        *(_DWORD *)(a1 + 56));
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 96) = 1;
    *(_DWORD *)(a1 + 100) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(a1 + 104) = *(_DWORD *)(a2 + 80);
  }
  if ( *(_DWORD *)(a2 + 164) )
  {
    v14 = a1 + 72;
  }
  else
  {
    if ( !*(_DWORD *)(a2 + 172) && !*(_DWORD *)(a2 + 168) && !*(_DWORD *)(a2 + 180) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_acquire_hw_for_ctx",
        5773,
        "No PIX or RDI or PPP or LCR resource, ctx_idx: %u",
        *(_DWORD *)(a1 + 56));
      return 4294967274LL;
    }
    v14 = a1 + 72;
    if ( !*(_DWORD *)(a2 + 180) )
      goto LABEL_19;
  }
  if ( *(_DWORD *)(a1 + 9312) != 2
    || (!*(_DWORD *)(*(_QWORD *)v14 + 80488LL) || *(_DWORD *)(a2 + 80)) && !*(_DWORD *)(a2 + 184) )
  {
    v15 = 1;
    goto LABEL_21;
  }
LABEL_19:
  v15 = 0;
LABEL_21:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_is_need_csid_ipp",
      4524,
      "Need CSID PIX %u, Ctx_type: %u, ctx_idx: %u",
      v15,
      *(_DWORD *)(a1 + 9312),
      *(_DWORD *)(a1 + 56));
    if ( !v15 )
      goto LABEL_28;
  }
  else if ( !v15 )
  {
    goto LABEL_28;
  }
  v16 = cam_ife_hw_mgr_acquire_res_ife_csid_pxl(a1, a2, 1, 1);
  if ( v16 )
  {
    v17 = *(unsigned int *)(a1 + 56);
    v18 = "Acquire IFE CSID IPP/LCR resource Failed, ctx_idx: %u";
    v19 = v16;
    v20 = 5784;
    goto LABEL_46;
  }
LABEL_28:
  if ( *(_DWORD *)(a2 + 168) )
  {
    v21 = cam_ife_hw_mgr_acquire_res_ife_csid_pxl(a1, a2, 0, *(_DWORD *)(a2 + 164) != 0);
    if ( v21 )
    {
      v17 = *(unsigned int *)(a1 + 56);
      v18 = "Acquire IFE CSID PPP resource Failed, ctx_idx: %u";
      v19 = v21;
      v20 = 5805;
      goto LABEL_46;
    }
  }
  if ( !*(_DWORD *)(a2 + 172) )
    goto LABEL_49;
  v22 = *(_DWORD *)(a2 + 144);
  if ( !v22 )
  {
    ife_csid_rdi_res_type = 12;
    v27 = debug_mdl;
    if ( (debug_mdl & 8) != 0 )
      goto LABEL_43;
LABEL_44:
    if ( !v22 )
      goto LABEL_49;
    goto LABEL_45;
  }
  v23 = 0;
  v47 = a4;
  while ( 1 )
  {
    v24 = (unsigned int *)(*(_QWORD *)(a2 + 224) + 44LL * v23);
    ife_csid_rdi_res_type = cam_ife_hw_mgr_get_ife_csid_rdi_res_type(*v24);
    if ( ife_csid_rdi_res_type != 12 )
      break;
LABEL_34:
    if ( (unsigned int)++v23 >= *(_DWORD *)(a2 + 144) )
    {
      v22 = 0;
      goto LABEL_42;
    }
  }
  v26 = cam_ife_hw_mgr_acquire_csid_rdi_util(a1, a2, ife_csid_rdi_res_type, v24);
  if ( !v26 )
  {
    *a5 |= 1 << ife_csid_rdi_res_type;
    goto LABEL_34;
  }
  v28 = v26;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_acquire_res_ife_csid_rdi",
    4933,
    "Ctx: %u Res %d acquire failed rc %d",
    *(_DWORD *)(a1 + 56),
    ife_csid_rdi_res_type,
    v26);
  v22 = v28;
LABEL_42:
  a4 = v47;
  v27 = debug_mdl;
  if ( (debug_mdl & 8) == 0 )
    goto LABEL_44;
LABEL_43:
  if ( debug_priority )
    goto LABEL_44;
  v29 = v22;
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v27 & 8,
    4,
    "cam_ife_hw_mgr_acquire_res_ife_csid_rdi",
    4939,
    "Ctx: %u  rdi: %d",
    *(_DWORD *)(a1 + 56),
    ife_csid_rdi_res_type);
  v22 = v29;
  if ( v29 )
  {
LABEL_45:
    v17 = *(unsigned int *)(a1 + 56);
    v18 = "Acquire IFE CSID RDI resource Failed, ctx_idx: %u";
    v19 = v22;
    v20 = 5817;
    goto LABEL_46;
  }
LABEL_49:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    if ( *(_BYTE *)(v7 + 1187) )
      v33 = "Y";
    else
      v33 = "N";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, _DWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_acquire_hw_for_ctx",
      5824,
      "Acquired CSID resource, is_dual:%s left_hw_idx:%d right_hw_idx:%d",
      v33,
      *(unsigned int *)(a1 + 60),
      *(_DWORD *)(a1 + 64));
    if ( !*(_DWORD *)(a2 + 184) )
      goto LABEL_64;
LABEL_52:
    if ( *(_DWORD *)(a1 + 9312) == 2 )
    {
      v30 = cam_ife_hw_mgr_acquire_sfe_bus_rd(a1, a2);
      if ( !v30 )
        goto LABEL_64;
    }
    else
    {
      v30 = cam_ife_hw_mgr_acquire_res_ife_bus_rd(a1, a2);
      if ( !v30 )
        goto LABEL_64;
    }
    v31 = *(_DWORD *)(a1 + 56);
    if ( *(_DWORD *)(a1 + 9312) == 2 )
      v32 = "SFE";
    else
      v32 = "IFE";
    v19 = v30;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire_hw_for_ctx",
      5836,
      "Acquire %s BUS RD resource Failed, ctx_idx: %u",
      v32,
      v31);
    return v19;
  }
  if ( *(_DWORD *)(a2 + 184) )
    goto LABEL_52;
LABEL_64:
  if ( *(_DWORD *)(a1 + 9312) != 2 )
    goto LABEL_83;
  v34 = *(_DWORD *)(*(_QWORD *)v14 + 80488LL);
  if ( v34 )
  {
    v35 = 12;
    v36 = 2;
    if ( !*(_DWORD *)(a2 + 80) )
    {
      v37 = __clz(__rbit32(v34));
      if ( v37 != 12 )
      {
        if ( ((1LL << v37) & (unsigned int)*a5) != 0 )
        {
          v36 = 2;
          goto LABEL_70;
        }
        v39 = cam_ife_hw_mgr_acquire_csid_rdi_util(a1, a2, v37, 0);
        if ( v39 )
        {
          v40 = v39;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_get_csid_rdi_for_sfe_ipp_input",
            4901,
            "Acquire RDI Ctx: %u rdi:%d rc %d",
            *(_DWORD *)(a1 + 56),
            v37,
            v39);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_acquire_hw_for_ctx",
            5850,
            "Acquire RDI for SFE IPP failed Ctx: %u rc %d",
            *(_DWORD *)(a1 + 56),
            v40);
          return v40;
        }
        *a5 |= 1LL << v37;
        v36 = *(_DWORD *)(a1 + 9312);
LABEL_70:
        v35 = v37;
      }
    }
  }
  else
  {
    v35 = 12;
    v36 = 2;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_get_csid_rdi_for_sfe_ipp_input",
      4908,
      "Ctx: %u rdi_res:%d ctx_type %d rc %d",
      *(_DWORD *)(a1 + 56),
      v35,
      v36,
      0);
    if ( *(_DWORD *)(a1 + 9312) == 2 )
      goto LABEL_75;
    goto LABEL_83;
  }
  if ( v36 != 2 )
    goto LABEL_83;
LABEL_75:
  if ( *(_DWORD *)(a2 + 164) || *(_DWORD *)(a2 + 172) )
  {
    v38 = cam_ife_hw_mgr_acquire_res_sfe_src(a1, a2, a3, a4, a5, a6, a7, v35);
    if ( v38 )
    {
      v17 = *(unsigned int *)(a1 + 56);
      v18 = "Acquire SFE SRC resource failed, ctx_idx: %u";
      v19 = v38;
      v20 = 5862;
      goto LABEL_46;
    }
LABEL_83:
    if ( !*(_DWORD *)(a2 + 164) )
      goto LABEL_90;
    if ( *(_DWORD *)(a1 + 9312) == 2 )
    {
      if ( *(_DWORD *)(a2 + 200) )
      {
        v41 = cam_ife_hw_mgr_acquire_ife_src_for_sfe(a1, a2, a3, a4);
        goto LABEL_88;
      }
      goto LABEL_90;
    }
    v41 = cam_ife_hw_mgr_acquire_res_ife_src(a1, a2, 0, 0, a3, a4);
LABEL_88:
    if ( v41 )
    {
      v17 = *(unsigned int *)(a1 + 56);
      v18 = "Acquire IFE IPP SRC resource Failed, ctx_idx: %u";
      v19 = v41;
      v20 = 5883;
      goto LABEL_46;
    }
LABEL_90:
    if ( *(_DWORD *)(a2 + 172) )
    {
      if ( *(_DWORD *)(a1 + 9312) != 2 )
      {
        v42 = cam_ife_hw_mgr_acquire_res_ife_src(a1, a2, 0, 0, a3, a4);
        if ( v42 )
        {
          v17 = *(unsigned int *)(a1 + 56);
          v18 = "Acquire IFE RDI SRC resource Failed, ctx_idx: %u";
          v19 = v42;
          v20 = 5898;
          goto LABEL_46;
        }
      }
    }
  }
  if ( *(_DWORD *)(a2 + 180) )
  {
    v43 = cam_ife_hw_mgr_acquire_res_ife_src(a1, a2, 1, 0, a3, a4);
    if ( v43 )
    {
      v17 = *(unsigned int *)(a1 + 56);
      v18 = "Acquire IFE LCR SRC resource Failed, ctx_idx: %u";
      v19 = v43;
      v20 = 5910;
      goto LABEL_46;
    }
  }
  if ( *(_DWORD *)(a2 + 168) )
  {
    v44 = cam_ife_hw_mgr_acquire_res_ife_src(a1, a2, 0, 1, a3, a4);
    if ( v44 )
    {
      v17 = *(unsigned int *)(a1 + 56);
      v18 = "Acquire IFE PPP SRC resource Failed, ctx_idx: %u";
      v19 = v44;
      v20 = 5921;
      goto LABEL_46;
    }
  }
  v45 = cam_ife_hw_mgr_acquire_res_ife_out(a1, a2);
  if ( v45 )
  {
    v17 = *(unsigned int *)(a1 + 56);
    v18 = "Acquire IFE OUT resource Failed, ctx_idx: %u";
    v19 = v45;
    v20 = 5929;
    goto LABEL_46;
  }
  if ( *(_DWORD *)(a1 + 9312) == 2 )
  {
    v46 = cam_ife_hw_mgr_acquire_res_sfe_out(a1, a2);
    if ( v46 )
    {
      v17 = *(unsigned int *)(a1 + 56);
      v18 = "Acquire SFE OUT resource Failed, ctx_idx: %u";
      v19 = v46;
      v20 = 5937;
LABEL_46:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_acquire_hw_for_ctx",
        v20,
        v18,
        v17);
      return v19;
    }
  }
  result = 0;
  if ( *(_BYTE *)(a2 + 217) == 1 )
    *(_DWORD *)(a1 + 9316) |= 4u;
  return result;
}
