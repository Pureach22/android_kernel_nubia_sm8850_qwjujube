__int64 __fastcall cam_ife_hw_mgr_acquire_res_ife_csid_pxl(__int64 a1, __int64 a2, char a3, char a4)
{
  int v7; // w6
  int v8; // w28
  __int64 *v9; // x22
  __int64 **v10; // x8
  __int64 *v11; // x9
  int v12; // w8
  __int64 result; // x0
  int v14; // w9
  int v15; // w12
  __int64 v16; // x2
  __int64 *v17; // x1
  unsigned int v18; // w23
  const char *v19; // x8
  unsigned __int8 v20; // w24
  int v21; // w10
  char v22; // w8
  bool v23; // zf
  int v24; // w9
  __int64 v25; // x8
  int v26; // w8
  __int64 v27; // x9
  unsigned int v28; // w0
  __int64 v29; // x8
  __int64 v30; // x9
  int v31; // w8
  __int64 v32; // x8
  char v33; // w10
  const char *v34; // x6
  const char *v35; // x10
  __int64 v36; // x8
  __int64 v37; // x8
  int v38; // w10
  __int64 (__fastcall *v39)(__int64, __int64, __int64 *, __int64); // x11
  __int64 v40; // x0
  __int64 v41; // x8
  int v42; // w7
  unsigned int v43; // w19
  char v44; // w9
  __int64 v45; // x8
  int v46; // w10
  __int64 (__fastcall *v47)(__int64, __int64, __int64 *, __int64); // x11
  __int64 v48; // x0
  char v49; // w20
  char v50; // w9
  const char *v51; // [xsp+18h] [xbp-A8h]
  char v52; // [xsp+24h] [xbp-9Ch]
  __int64 v53; // [xsp+28h] [xbp-98h] BYREF
  __int64 v54; // [xsp+30h] [xbp-90h] BYREF
  __int64 v55; // [xsp+38h] [xbp-88h]
  __int64 v56; // [xsp+40h] [xbp-80h]
  __int64 v57; // [xsp+48h] [xbp-78h]
  __int64 v58; // [xsp+50h] [xbp-70h]
  __int64 v59; // [xsp+58h] [xbp-68h]
  __int64 v60; // [xsp+60h] [xbp-60h]
  __int64 v61; // [xsp+68h] [xbp-58h]
  __int64 v62; // [xsp+70h] [xbp-50h]
  __int64 v63; // [xsp+78h] [xbp-48h]
  __int64 v64; // [xsp+80h] [xbp-40h]
  __int64 v65; // [xsp+88h] [xbp-38h]
  __int64 (__fastcall *v66)(__int64, unsigned int, _DWORD *); // [xsp+90h] [xbp-30h]
  __int64 v67; // [xsp+98h] [xbp-28h]
  __int64 v68; // [xsp+A0h] [xbp-20h]
  __int64 v69; // [xsp+A8h] [xbp-18h]
  __int64 v70; // [xsp+B0h] [xbp-10h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  v69 = 0;
  v66 = nullptr;
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
  v53 = 0;
  if ( (a3 & 1) == 0 )
  {
LABEL_12:
    v8 = 6;
    goto LABEL_14;
  }
  if ( *(_DWORD *)a2 != 3 )
  {
LABEL_13:
    v8 = 5;
    goto LABEL_14;
  }
  v7 = *(_DWORD *)(a2 + 208);
  if ( v7 <= 31 )
  {
    if ( v7 > 7 )
    {
      if ( v7 == 8 )
      {
        v8 = 0;
      }
      else
      {
        if ( v7 != 16 )
          goto LABEL_85;
        v8 = 1;
      }
      goto LABEL_14;
    }
    if ( v7 != 1 )
    {
      if ( v7 != 2 )
        goto LABEL_85;
      goto LABEL_12;
    }
    goto LABEL_13;
  }
  if ( v7 <= 127 )
  {
    if ( v7 == 32 )
    {
      v8 = 2;
    }
    else
    {
      if ( v7 != 64 )
        goto LABEL_85;
      v8 = 3;
    }
  }
  else
  {
    switch ( v7 )
    {
      case 128:
        v8 = 4;
        break;
      case 512:
        v8 = 11;
        break;
      case 256:
        v8 = 10;
        break;
      default:
LABEL_85:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_util_process_csid_path_res",
          4560,
          "Invalid csid path ID: 0x%x",
          v7);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_acquire_res_ife_csid_pxl",
          4586,
          "Error in processing csid path resource rc:%d",
          -22);
        result = 4294967274LL;
        goto LABEL_73;
    }
  }
LABEL_14:
  v9 = *(__int64 **)(a1 + 288);
  if ( v9 == (__int64 *)(a1 + 288) )
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
      "cam_ife_hw_mgr_acquire_res_ife_csid_pxl",
      4598,
      "No more free hw mgr resource, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    result = 0xFFFFFFFFLL;
    goto LABEL_73;
  }
  v10 = (__int64 **)v9[1];
  if ( *v10 == v9 && (v11 = (__int64 *)*v9, *(__int64 **)(*v9 + 8) == v9) )
  {
    v11[1] = (__int64)v10;
    *v10 = v11;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 288));
    a4 = v44;
  }
  *v9 = (__int64)v9;
  v9[1] = (__int64)v9;
  *((_DWORD *)v9 + 4) = 3;
  *((_DWORD *)v9 + 5) = v8;
  *(_BYTE *)(a1 + 9379) = *(_DWORD *)(a2 + 80) != 0;
  if ( *(_DWORD *)(a2 + 80) && (a3 & 1) != 0 )
  {
    *((_DWORD *)v9 + 6) = 1;
    v12 = *(_DWORD *)(a2 + 144);
    if ( !v12 )
      goto LABEL_29;
  }
  else
  {
    *((_DWORD *)v9 + 6) = 0;
    LODWORD(v57) = 0;
    v12 = *(_DWORD *)(a2 + 144);
    if ( !v12 )
      goto LABEL_29;
  }
  v14 = 0;
  while ( 1 )
  {
    v15 = *(_DWORD *)(*(_QWORD *)(a2 + 224) + 44LL * v14 + 24);
    if ( v15 )
      break;
    if ( v12 == ++v14 )
      goto LABEL_29;
  }
  *((_DWORD *)v9 + 26) = v15;
LABEL_29:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v49 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_res_ife_csid_pxl",
      4623,
      "CSID Acquire: Enter, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    a4 = v49;
    if ( !v9 )
      goto LABEL_36;
  }
  else if ( !v9 )
  {
    goto LABEL_36;
  }
  v16 = a1 + 208;
  v17 = *(__int64 **)(a1 + 216);
  if ( v9 == (__int64 *)(a1 + 208) || v17 == v9 || *v17 != v16 )
  {
    _list_add_valid_or_report(v9);
    a4 = v50;
  }
  else
  {
    *(_QWORD *)(a1 + 216) = v9;
    *v9 = v16;
    v9[1] = (__int64)v17;
    *v17 = (__int64)v9;
  }
LABEL_36:
  v52 = a3;
  v18 = *((_DWORD *)v9 + 6);
  if ( (v18 & 0x80000000) != 0 )
  {
LABEL_63:
    if ( (v52 & 1) == 0 || !*((_DWORD *)v9 + 6) || *(_BYTE *)(a1 + 9384) != 1 )
    {
      result = 0;
      goto LABEL_73;
    }
    v36 = v9[4];
    if ( v36 )
    {
      v37 = *(_QWORD *)(v36 + 16);
      v38 = *(_DWORD *)(a1 + 64);
      v39 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v37 + 88);
      v40 = *(_QWORD *)(v37 + 112);
      LODWORD(v53) = 1;
      HIDWORD(v53) = v38;
      if ( *((_DWORD *)v39 - 1) != -1055839300 )
        __break(0x822Bu);
      result = v39(v40, 52, &v53, 8);
      v41 = v9[5];
      if ( !v41 )
        goto LABEL_73;
    }
    else
    {
      result = 0;
      v41 = v9[5];
      if ( !v41 )
        goto LABEL_73;
    }
    v45 = *(_QWORD *)(v41 + 16);
    v46 = *(_DWORD *)(a1 + 60);
    v47 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v45 + 88);
    v48 = *(_QWORD *)(v45 + 112);
    LODWORD(v53) = 2;
    HIDWORD(v53) = v46;
    if ( *((_DWORD *)v47 - 1) != -1055839300 )
      __break(0x822Bu);
    result = v47(v48, 52, &v53, 8);
    goto LABEL_73;
  }
  v19 = "PPP";
  v20 = a4 & 1;
  if ( (v52 & 1) != 0 )
    v19 = "IPP";
  v51 = v19;
  v21 = debug_priority;
  v22 = debug_mdl;
  while ( 1 )
  {
    v24 = *((_DWORD *)v9 + 6);
    if ( (v22 & 8) != 0 && !v21 )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v22 & 8,
        4,
        "cam_ife_hw_mgr_acquire_res_ife_csid_pxl",
        4629,
        "ctx_idx: %u i %d is_dual %d",
        *(_DWORD *)(a1 + 56),
        v18,
        v24);
      v24 = *((_DWORD *)v9 + 6);
    }
    v25 = *(_QWORD *)(a2 + 224);
    LODWORD(v54) = 3;
    HIDWORD(v54) = v8;
    v59 = 0;
    v55 = a2;
    v56 = v25;
    v66 = cam_ife_hw_mgr_event_handler;
    v68 = a1;
    LOWORD(v61) = v20;
    BYTE4(v69) = 0;
    if ( v24 )
    {
      if ( v18 )
        v26 = 2;
      else
        v26 = 1;
      LODWORD(v57) = v26;
    }
    v27 = *(_QWORD *)(a1 + 8728);
    v62 = *(_QWORD *)(a1 + 16);
    v65 = v27;
    v28 = cam_ife_hw_mgr_acquire_csid_hw(a1, (__int64)&v54, a2);
    if ( v28 )
      break;
    if ( v18 >= 2 )
      __break(0x5512u);
    v29 = v59;
    v9[v18 + 4] = v59;
    v30 = *(__int64 *)((char *)&qword_10 + v29);
    v31 = *(_DWORD *)(v30 + 4);
    if ( v18 )
    {
      *(_DWORD *)(a1 + 64) = v31;
    }
    else
    {
      *(_DWORD *)(a1 + 60) = v31;
      v32 = v64;
      *(_QWORD *)(a1 + 9336) = v63;
      *(_QWORD *)(a1 + 9344) = v32;
    }
    v33 = BYTE3(v69);
    *(_BYTE *)(a1 + 9384) = BYTE4(v61);
    *(_BYTE *)(a1 + 9400) = v33;
    v22 = debug_mdl;
    v21 = debug_priority;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      if ( v18 )
        v34 = "right";
      else
        v34 = "left";
      v35 = "Y";
      if ( !*((_DWORD *)v9 + 26) )
        v35 = "N";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_acquire_res_ife_csid_pxl",
        4678,
        "acquired csid(%s)=%d ctx_idx: %u pxl path rsrc %s successfully, is_secure: %s",
        v34,
        *(_DWORD *)(v30 + 4),
        *(_DWORD *)(a1 + 56),
        v51,
        v35);
      v22 = debug_mdl;
      v21 = debug_priority;
    }
    v23 = v18 == 1;
    v18 = 0;
    if ( !v23 )
      goto LABEL_63;
  }
  v42 = *(_DWORD *)(a1 + 56);
  v43 = v28;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_acquire_res_ife_csid_pxl",
    4654,
    "Cannot acquire ife csid pxl path rsrc %s, ctx_idx: %u",
    v51,
    v42);
  result = v43;
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
