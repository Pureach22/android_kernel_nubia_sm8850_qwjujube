__int64 __fastcall cam_ife_hw_mgr_acquire_csid_hw(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w9
  __int64 v5; // x26
  int v6; // w20
  __int64 v7; // x10
  int v8; // w13
  __int64 result; // x0
  int v10; // w13
  int v11; // w12
  _BOOL4 v12; // w12
  int v13; // w7
  int v14; // w6
  __int64 *v15; // x25
  __int64 v16; // x22
  _QWORD *v17; // x11
  __int64 v18; // x9
  char v19; // w8
  const char *v20; // x26
  __int64 v21; // x9
  char v22; // w23
  int v23; // w8
  __int64 v24; // x28
  __int64 v25; // x6
  __int64 v26; // x8
  __int64 (__fastcall *v27)(_QWORD); // x8
  __int64 v28; // x0
  _QWORD *v29; // x24
  __int64 v30; // x19
  __int64 v31; // x19
  __int64 v32; // x1
  unsigned int v33; // w26
  __int64 v34; // x4
  const char *v35; // x5
  _QWORD *v36; // x24
  const char *v37; // x10
  int v38; // w10
  __int64 v39; // x11
  int v40; // w19
  int v41; // w26
  unsigned int v42; // w21
  int v43; // w24
  __int64 v44; // x22
  __int64 v45; // x8
  unsigned int v46; // w9
  __int64 v47; // x6
  __int64 v48; // x23
  __int64 (__fastcall *v49)(_QWORD); // x9
  __int64 v50; // x0
  __int64 v51; // x23
  __int64 v52; // x1
  __int64 v53; // x4
  const char *v54; // x5
  unsigned int v55; // w19
  unsigned int v56; // w19
  unsigned int v57; // w9
  __int64 v58; // x19
  bool v59; // w23
  __int64 v60; // [xsp+20h] [xbp-40h]
  __int64 v61; // [xsp+30h] [xbp-30h]
  unsigned int v62; // [xsp+30h] [xbp-30h]
  __int64 v63; // [xsp+38h] [xbp-28h]
  int v64; // [xsp+48h] [xbp-18h]
  bool v65; // [xsp+54h] [xbp-Ch]

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_csid_hw",
      4365,
      "Invalid args ife hw ctx %pK csid_acquire %pK",
      (const void *)a1,
      (const void *)a2);
    return 4294967274LL;
  }
  v3 = *(_DWORD *)(a3 + 144);
  v5 = *(_QWORD *)(a1 + 72);
  v6 = *(_DWORD *)(a1 + 9312);
  if ( v3 )
  {
    v7 = *(_QWORD *)(a3 + 224);
    if ( *(_DWORD *)(v7 + 24) )
    {
      v8 = 0;
    }
    else
    {
      v10 = 1;
      do
      {
        v11 = v10;
        if ( v3 == v10 )
          break;
        ++v10;
      }
      while ( !*(_DWORD *)(v7 + 44LL * v11 + 24) );
      v8 = v11 >= v3;
    }
  }
  else
  {
    v8 = 1;
  }
  v64 = v8;
  *(_BYTE *)(a1 + 9379) = *(_DWORD *)(a3 + 80) != 0;
  if ( v6 == 2 )
    goto LABEL_14;
  v13 = *(unsigned __int8 *)(a1 + 9385);
  if ( (v13 & 1) != 0 || (v14 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 8) + 218LL), (v14 & 1) != 0) )
  {
    LOBYTE(v12) = 1;
    goto LABEL_18;
  }
  v57 = *(_DWORD *)(a2 + 4);
  if ( v57 > 3 )
  {
LABEL_14:
    LOBYTE(v12) = 0;
  }
  else
  {
    v12 = (*(_BYTE *)(a1 + 9378) & 1) == 0 && *(_BYTE *)(a1 + 9381) != 1;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v58 = a2;
      v59 = v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_check_can_use_lite",
        3791,
        "in_port lite hint %d, rdi_only: %d can_use_lite: %d res_id: %u ctx_idx: %u",
        v14,
        v13,
        v12,
        v57,
        *(_DWORD *)(a1 + 56));
      v8 = v64;
      LOBYTE(v12) = v59;
      a2 = v58;
    }
  }
LABEL_18:
  if ( *(_BYTE *)(v5 + 81883) == 1 && *(_DWORD *)(a1 + 9312) != 2 )
    *(_BYTE *)(a2 + 122) = 1;
  v63 = v5 + 77824;
  v65 = v12;
  v15 = *(__int64 **)(a1 + 208);
  v60 = v5;
  if ( v15 == (__int64 *)(a1 + 208) )
  {
    result = 4294967274LL;
LABEL_58:
    v38 = v6;
    v39 = v63;
    v40 = 0;
    v41 = 0;
    if ( v6 == 2 )
      v42 = 0;
    else
      v42 = 7;
    if ( v6 == 2 )
      v43 = 1;
    else
      v43 = -1;
    v44 = v60 + 80464;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v38 == 2 )
        {
          if ( (int)v42 >= 8 )
            goto LABEL_94;
        }
        else if ( (v42 & 0x80000000) != 0 )
        {
LABEL_94:
          if ( v41 == v40 )
          {
            v56 = result;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_acquire_csid_hw",
              4501,
              "all compatible CSIDs are busy, ctx_idx: %u",
              *(_DWORD *)(a1 + 56));
            return v56;
          }
          return result;
        }
        if ( v42 >= 8 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_acquire_csid_hw",
            4455,
            "Invalid index for csid device i: %d",
            v42);
          return 4294967274LL;
        }
        v45 = *(_QWORD *)(v60 + 96 + 8LL * v42);
        if ( !v45 )
          goto LABEL_67;
        v46 = *(_DWORD *)(v39 + 3192);
        if ( v46 <= 7 && v42 != v46 )
          goto LABEL_67;
        v47 = *(unsigned int *)(v45 + 4);
        if ( (unsigned int)v47 > 7 )
          goto LABEL_108;
        if ( v12 || (*(_BYTE *)(v44 + 36LL * (unsigned int)v47 + 28) & 1) == 0 )
          break;
        if ( (debug_mdl & 8) != 0 )
        {
          v38 = v6;
          v39 = v63;
          if ( debug_priority )
            goto LABEL_67;
          v51 = a2;
          v52 = debug_mdl & 8;
          v62 = result;
          v53 = 4471;
          v54 = "CSID[%u] cannot use lite, ctx_idx: %u";
          goto LABEL_91;
        }
LABEL_89:
        v38 = v6;
        v39 = v63;
        v42 += v43;
      }
      ++v41;
      if ( *(_BYTE *)(v44 + 36LL * (unsigned int)v47 + 33) != 1 || *(_DWORD *)(a1 + 9312) != 2 )
        goto LABEL_82;
      if ( (unsigned int)v47 > 2 )
        goto LABEL_108;
      if ( !*(_QWORD *)(v60 + 224 + 8 * v47) )
      {
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_89;
        v38 = v6;
        v39 = v63;
        if ( debug_priority )
          goto LABEL_67;
        v51 = a2;
        v52 = debug_mdl & 8;
        v62 = result;
        v53 = 4481;
        v54 = "No sfe_device with idx: %d, ctx_idx: %u";
LABEL_91:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v52,
          4,
          "cam_ife_hw_mgr_acquire_csid_hw",
          v53,
          v54);
        LOBYTE(v12) = v65;
        v39 = v63;
        a2 = v51;
        v38 = v6;
        result = v62;
        v42 += v43;
      }
      else
      {
LABEL_82:
        *(_BYTE *)(a2 + 124) = 1;
        v48 = a2;
        v49 = *(__int64 (__fastcall **)(_QWORD))(v45 + 40);
        v50 = *(_QWORD *)(v45 + 112);
        if ( *((_DWORD *)v49 - 1) != 1989616049 )
          __break(0x8229u);
        result = v49(v50);
        if ( (_DWORD)result != -16 )
        {
          if ( !(_DWORD)result )
            return result;
          v55 = result;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_acquire_csid_hw",
            4495,
            "CSID[%d] acquire failed (rc=%d), ctx_idx: %u",
            v42,
            (unsigned int)result,
            *(_DWORD *)(a1 + 56));
          return v55;
        }
        v38 = v6;
        v39 = v63;
        ++v40;
        LOBYTE(v12) = v65;
        a2 = v48;
LABEL_67:
        v42 += v43;
      }
    }
  }
  v61 = v5 + 224;
  v16 = v5 + 80464;
  result = 4294967274LL;
  v17 = &unk_393000;
LABEL_24:
  v18 = 0;
  v19 = 1;
  v20 = "left";
  while ( 1 )
  {
    v21 = v15[v18 + 4];
    v22 = v19;
    if ( !v21 )
      goto LABEL_26;
    v23 = *((_DWORD *)v15 + 26);
    if ( !*(_DWORD *)(a3 + 144) )
      break;
    if ( v23 != v8 )
      goto LABEL_32;
LABEL_26:
    v19 = 0;
    v20 = "right";
    v18 = 1;
    if ( (v22 & 1) == 0 )
    {
      v15 = (__int64 *)*v15;
      if ( v15 == (__int64 *)(a1 + 208) )
        goto LABEL_58;
      goto LABEL_24;
    }
  }
  if ( v23 == 1 )
    goto LABEL_26;
LABEL_32:
  v24 = *(_QWORD *)(v21 + 16);
  v25 = *(unsigned int *)(v24 + 4);
  if ( (unsigned int)v25 > 8 )
    goto LABEL_108;
  v26 = v16 + 36LL * (unsigned int)v25;
  if ( !v12 && (*(_BYTE *)(v26 + 28) & 1) != 0 )
  {
    if ( (v17[458] & 8) == 0 || debug_priority )
      goto LABEL_26;
    v31 = a2;
    v32 = v17[458] & 8LL;
    v33 = result;
    v34 = 4415;
    v35 = "CSID[%u] cannot use lite, ctx_idx: %u";
LABEL_47:
    v36 = v17;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v32,
      4,
      "cam_ife_hw_mgr_acquire_csid_hw",
      v34,
      v35);
    v8 = v64;
    LOBYTE(v12) = v65;
    v17 = v36;
    a2 = v31;
    result = v33;
    goto LABEL_26;
  }
  if ( *(_BYTE *)(v26 + 33) == 1 && *(_DWORD *)(a1 + 9312) == 2 )
  {
    if ( (unsigned int)v25 > 2 )
    {
LABEL_108:
      __break(0x5512u);
      return cam_convert_hw_idx_to_ife_hw_num(result);
    }
    if ( !*(_QWORD *)(v61 + 8 * v25) )
    {
      if ( (v17[458] & 8) == 0 || debug_priority )
        goto LABEL_26;
      v31 = a2;
      v32 = v17[458] & 8LL;
      v33 = result;
      v34 = 4423;
      v35 = "No sfe_device with idx: %d, ctx_idx: %u";
      goto LABEL_47;
    }
  }
  v27 = *(__int64 (__fastcall **)(_QWORD))(v24 + 40);
  v28 = *(_QWORD *)(v24 + 112);
  v29 = v17;
  v30 = a2;
  if ( *((_DWORD *)v27 - 1) != 1989616049 )
    __break(0x8228u);
  result = v27(v28);
  if ( (_DWORD)result == -16 )
  {
    v8 = v64;
    v17 = v29;
    if ( (v29[458] & 8) != 0 )
    {
      LOBYTE(v12) = v65;
      a2 = v30;
      if ( !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v29[458] & 8LL,
          4,
          "cam_ife_hw_mgr_acquire_csid_hw",
          4432,
          "Resource not available from hw_idx %d, ctx_idx: %u",
          *(_DWORD *)(v24 + 4),
          *(_DWORD *)(a1 + 56));
        v8 = v64;
        LOBYTE(v12) = v65;
        v17 = v29;
        a2 = v30;
        result = 4294967280LL;
      }
    }
    else
    {
      LOBYTE(v12) = v65;
      a2 = v30;
    }
    goto LABEL_26;
  }
  if ( (_DWORD)result )
  {
    v55 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_csid_hw",
      4437,
      "Failed to acquire from existing hw idx: %u ctx_idx: %u rc: %d",
      *(unsigned int *)(v24 + 4),
      *(unsigned int *)(a1 + 56),
      result);
    return v55;
  }
  if ( (v29[458] & 8) != 0 && !debug_priority )
  {
    v37 = "Y";
    if ( !*((_DWORD *)v15 + 26) )
      v37 = "N";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v29[458] & 8LL,
      4,
      "cam_ife_hw_mgr_acquire_csid_hw",
      4446,
      "acquired from old csid(%s)=%d successfully, is_secure: %s, ctx_idx: %u",
      v20,
      *(_DWORD *)(v24 + 4),
      v37,
      *(_DWORD *)(a1 + 56));
    return 0;
  }
  return result;
}
