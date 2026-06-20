__int64 __fastcall cam_ife_mgr_regspace_data_cb(int a1, __int64 a2, _QWORD *a3, _DWORD *a4)
{
  __int64 *v4; // x1
  __int64 *v5; // x21
  __int64 *v6; // t1
  __int64 v7; // x9
  __int64 *v8; // x8
  __int64 v9; // x10
  _DWORD *v10; // x9
  __int64 v12; // x0
  _DWORD *v14; // x19
  unsigned int v15; // w0
  unsigned int v16; // w19
  __int64 *v17; // x1
  __int64 *v18; // x21
  __int64 *v19; // t1
  __int64 v20; // x9
  __int64 *v21; // x8
  __int64 v22; // x10
  _DWORD *v23; // x9
  __int64 v25; // x0
  unsigned int v27; // w0
  __int64 *v28; // x1
  __int64 *v29; // x20
  __int64 *v30; // t1
  __int64 v31; // x9
  __int64 *v32; // x8
  __int64 v33; // x10
  _DWORD *v34; // x9
  __int64 v35; // x0
  unsigned int v37; // w0
  __int64 *v38; // x1
  __int64 *v39; // x20
  __int64 *v40; // t1
  __int64 v41; // x9
  __int64 *v42; // x8
  __int64 v43; // x10
  _DWORD *v44; // x9
  __int64 v45; // x0
  unsigned int v47; // w0
  __int64 *v48; // x1
  __int64 *v49; // x20
  __int64 *v50; // t1
  __int64 v51; // x9
  __int64 *v52; // x8
  __int64 v53; // x10
  _DWORD *v54; // x9
  __int64 v55; // x0
  unsigned int v57; // w0
  __int64 result; // x0
  __int64 *v59; // x1
  __int64 *v60; // x20
  __int64 *v61; // t1
  __int64 v62; // x9
  __int64 *v63; // x8
  __int64 v64; // x10
  _DWORD *v65; // x9
  __int64 v66; // x0
  unsigned int v68; // w0
  __int64 v69; // x1
  __int64 v70; // x6
  _QWORD v71[2]; // [xsp+10h] [xbp-10h] BYREF

  v71[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a3 = 0;
  if ( a1 <= 3 )
  {
    switch ( a1 )
    {
      case 1:
        goto LABEL_17;
      case 2:
        v61 = *(__int64 **)(a2 + 224);
        v59 = (__int64 *)(a2 + 224);
        v60 = v61;
        v71[0] = 0;
        if ( v61 == v59 )
          goto LABEL_71;
        while ( 1 )
        {
          v62 = v60[5];
          v63 = (__int64 *)*v60;
          if ( v62 )
          {
            v64 = *(_QWORD *)(v62 + 16);
            if ( v64 )
            {
              v65 = *(_DWORD **)(v64 + 88);
              if ( v65 )
                break;
            }
          }
          v60 = (__int64 *)*v60;
          if ( v63 == v59 )
            goto LABEL_71;
        }
        v66 = *(_QWORD *)(v64 + 112);
        v14 = a4;
        if ( *(v65 - 1) != -1055839300 )
          __break(0x8229u);
        v68 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v65)(v66, 30, v71, 8);
        if ( v68 )
        {
          v16 = v68;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, unsigned int))cam_print_log)(
            3,
            8,
            1,
            "__cam_ife_mgr_get_hw_soc_info",
            962,
            "Failed in %d regspace data query res_id: %u split idx: %d rc : %d",
            2,
            *((unsigned int *)v60 + 5),
            1,
            v68);
          goto LABEL_59;
        }
        *a3 = v71[0];
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_ife_mgr_get_hw_soc_info",
            969,
            "Obtained soc info for split %d for hw_type %d",
            1,
            2);
        goto LABEL_94;
      case 3:
LABEL_17:
        v19 = *(__int64 **)(a2 + 224);
        v17 = (__int64 *)(a2 + 224);
        v18 = v19;
        v71[0] = 0;
        if ( v19 == v17 )
          goto LABEL_71;
        while ( 1 )
        {
          v20 = v18[4];
          v21 = (__int64 *)*v18;
          if ( v20 )
          {
            v22 = *(_QWORD *)(v20 + 16);
            if ( v22 )
            {
              v23 = *(_DWORD **)(v22 + 88);
              if ( v23 )
                break;
            }
          }
          v18 = (__int64 *)*v18;
          if ( v21 == v17 )
            goto LABEL_71;
        }
        v25 = *(_QWORD *)(v22 + 112);
        v14 = a4;
        if ( *(v23 - 1) != -1055839300 )
          __break(0x8229u);
        v27 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v23)(v25, 30, v71, 8);
        if ( v27 )
        {
          v16 = v27;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, unsigned int))cam_print_log)(
            3,
            8,
            1,
            "__cam_ife_mgr_get_hw_soc_info",
            962,
            "Failed in %d regspace data query res_id: %u split idx: %d rc : %d",
            2,
            *((unsigned int *)v18 + 5),
            0,
            v27);
          goto LABEL_59;
        }
        *a3 = v71[0];
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_ife_mgr_get_hw_soc_info",
            969,
            "Obtained soc info for split %d for hw_type %d",
            0,
            2);
          if ( a1 == 1 )
            goto LABEL_94;
          goto LABEL_80;
        }
        if ( a1 != 1 )
          goto LABEL_80;
        goto LABEL_94;
    }
LABEL_70:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_regspace_data_cb",
      1060,
      "Unrecognized reg base type: %u, ctx_idx: %u",
      a1,
      *(_DWORD *)(a2 + 56));
LABEL_71:
    result = 4294967274LL;
    goto LABEL_72;
  }
  if ( a1 > 6 )
  {
    if ( a1 == 7 )
    {
      v50 = *(__int64 **)(a2 + 240);
      v48 = (__int64 *)(a2 + 240);
      v49 = v50;
      v71[0] = 0;
      if ( v50 == v48 )
        goto LABEL_71;
      while ( 1 )
      {
        v51 = v49[4];
        v52 = (__int64 *)*v49;
        if ( v51 )
        {
          v53 = *(_QWORD *)(v51 + 16);
          if ( v53 )
          {
            v54 = *(_DWORD **)(v53 + 88);
            if ( v54 )
              break;
          }
        }
        v49 = (__int64 *)*v49;
        if ( v52 == v48 )
          goto LABEL_71;
      }
      v55 = *(_QWORD *)(v53 + 112);
      v14 = a4;
      if ( *(v54 - 1) != -1055839300 )
        __break(0x8229u);
      v57 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v54)(v55, 30, v71, 8);
      if ( v57 )
      {
        v16 = v57;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, unsigned int))cam_print_log)(
          3,
          8,
          1,
          "__cam_ife_mgr_get_hw_soc_info",
          962,
          "Failed in %d regspace data query res_id: %u split idx: %d rc : %d",
          7,
          *((unsigned int *)v49 + 5),
          0,
          v57);
        goto LABEL_59;
      }
      *a3 = v71[0];
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_94;
      v69 = debug_mdl & 8;
      v70 = 0;
LABEL_87:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        v69,
        4,
        "__cam_ife_mgr_get_hw_soc_info",
        969,
        "Obtained soc info for split %d for hw_type %d",
        v70,
        7);
      goto LABEL_94;
    }
    if ( a1 == 8 )
    {
      v30 = *(__int64 **)(a2 + 240);
      v28 = (__int64 *)(a2 + 240);
      v29 = v30;
      v71[0] = 0;
      if ( v30 == v28 )
        goto LABEL_71;
      while ( 1 )
      {
        v31 = v29[5];
        v32 = (__int64 *)*v29;
        if ( v31 )
        {
          v33 = *(_QWORD *)(v31 + 16);
          if ( v33 )
          {
            v34 = *(_DWORD **)(v33 + 88);
            if ( v34 )
              break;
          }
        }
        v29 = (__int64 *)*v29;
        if ( v32 == v28 )
          goto LABEL_71;
      }
      v35 = *(_QWORD *)(v33 + 112);
      v14 = a4;
      if ( *(v34 - 1) != -1055839300 )
        __break(0x8229u);
      v37 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v34)(v35, 30, v71, 8);
      if ( v37 )
      {
        v16 = v37;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, unsigned int))cam_print_log)(
          3,
          8,
          1,
          "__cam_ife_mgr_get_hw_soc_info",
          962,
          "Failed in %d regspace data query res_id: %u split idx: %d rc : %d",
          7,
          *((unsigned int *)v29 + 5),
          1,
          v37);
        goto LABEL_59;
      }
      *a3 = v71[0];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v69 = debug_mdl & 8;
        v70 = 1;
        goto LABEL_87;
      }
LABEL_94:
      result = 0;
      *v14 = 0;
      goto LABEL_72;
    }
    goto LABEL_70;
  }
  if ( (unsigned int)(a1 - 4) >= 2 )
  {
    v40 = *(__int64 **)(a2 + 208);
    v38 = (__int64 *)(a2 + 208);
    v39 = v40;
    v71[0] = 0;
    if ( v40 == v38 )
      goto LABEL_71;
    while ( 1 )
    {
      v41 = v39[5];
      v42 = (__int64 *)*v39;
      if ( v41 )
      {
        v43 = *(_QWORD *)(v41 + 16);
        if ( v43 )
        {
          v44 = *(_DWORD **)(v43 + 88);
          if ( v44 )
            break;
        }
      }
      v39 = (__int64 *)*v39;
      if ( v42 == v38 )
        goto LABEL_71;
    }
    v45 = *(_QWORD *)(v43 + 112);
    v14 = a4;
    if ( *(v44 - 1) != -1055839300 )
      __break(0x8229u);
    v47 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v44)(v45, 30, v71, 8);
    if ( v47 )
    {
      v16 = v47;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, unsigned int))cam_print_log)(
        3,
        8,
        1,
        "__cam_ife_mgr_get_hw_soc_info",
        962,
        "Failed in %d regspace data query res_id: %u split idx: %d rc : %d",
        0,
        *((unsigned int *)v39 + 5),
        1,
        v47);
      goto LABEL_59;
    }
    *a3 = v71[0];
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_ife_mgr_get_hw_soc_info",
        969,
        "Obtained soc info for split %d for hw_type %d",
        1,
        0);
    goto LABEL_94;
  }
  v6 = *(__int64 **)(a2 + 208);
  v4 = (__int64 *)(a2 + 208);
  v5 = v6;
  v71[0] = 0;
  if ( v6 == v4 )
    goto LABEL_71;
  while ( 1 )
  {
    v7 = v5[4];
    v8 = (__int64 *)*v5;
    if ( v7 )
    {
      v9 = *(_QWORD *)(v7 + 16);
      if ( v9 )
      {
        v10 = *(_DWORD **)(v9 + 88);
        if ( v10 )
          break;
      }
    }
    v5 = (__int64 *)*v5;
    if ( v8 == v4 )
      goto LABEL_71;
  }
  v12 = *(_QWORD *)(v9 + 112);
  v14 = a4;
  if ( *(v10 - 1) != -1055839300 )
    __break(0x8229u);
  v15 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v10)(v12, 30, v71, 8);
  if ( !v15 )
  {
    *a3 = v71[0];
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_ife_mgr_get_hw_soc_info",
        969,
        "Obtained soc info for split %d for hw_type %d",
        0,
        0);
      if ( a1 == 5 )
        goto LABEL_94;
    }
    else if ( a1 == 5 )
    {
      goto LABEL_94;
    }
LABEL_80:
    result = 0;
    *v14 = 1;
    goto LABEL_72;
  }
  v16 = v15;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, unsigned int))cam_print_log)(
    3,
    8,
    1,
    "__cam_ife_mgr_get_hw_soc_info",
    962,
    "Failed in %d regspace data query res_id: %u split idx: %d rc : %d",
    0,
    *((unsigned int *)v5 + 5),
    0,
    v15);
LABEL_59:
  result = v16;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
