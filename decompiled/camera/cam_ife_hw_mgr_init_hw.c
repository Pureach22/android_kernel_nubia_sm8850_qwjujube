__int64 __fastcall cam_ife_hw_mgr_init_hw(__int64 a1)
{
  __int64 *v2; // x20
  unsigned int inited; // w0
  __int64 v4; // x6
  __int64 v5; // x7
  unsigned int v6; // w22
  const char *v7; // x5
  __int64 v8; // x4
  __int64 *v9; // x20
  unsigned int v10; // w0
  int v11; // w8
  __int64 v12; // x20
  unsigned int v13; // w0
  int v14; // w8
  __int64 v15; // x1
  __int64 *v16; // x20
  unsigned int v17; // w0
  int v18; // w7
  unsigned int v19; // w19
  __int64 result; // x0
  int v21; // w8
  __int64 v22; // x20
  unsigned int v23; // w0
  __int64 *v24; // x20
  unsigned int v25; // w0
  unsigned int v26; // w0
  unsigned int v27; // w20

  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_init_hw",
      1958,
      "INIT IFE SRC in ctx id:%u",
      *(_DWORD *)(a1 + 56));
  v2 = (__int64 *)(a1 + 224);
  while ( 1 )
  {
    v2 = (__int64 *)*v2;
    if ( v2 == (__int64 *)(a1 + 224) )
      break;
    inited = cam_ife_hw_mgr_init_hw_res(v2);
    if ( inited )
    {
      v4 = *((unsigned int *)v2 + 5);
      v5 = *(unsigned int *)(a1 + 56);
      v6 = inited;
      v7 = "Can not INIT IFE SRC (%d), ctx_idx:%u";
      v8 = 1963;
LABEL_58:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_init_hw",
        v8,
        v7,
        v4,
        v5);
      *(_BYTE *)(a1 + 9377) = 1;
      cam_ife_hw_mgr_deinit_hw(a1);
      return v6;
    }
  }
  if ( *(_DWORD *)(a1 + 9312) == 2 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_init_hw",
        1971,
        "INIT SFE Resource in ctx id:%d",
        *(_DWORD *)(a1 + 56));
    v9 = (__int64 *)(a1 + 240);
    while ( 1 )
    {
      v9 = (__int64 *)*v9;
      if ( v9 == (__int64 *)(a1 + 240) )
        break;
      v10 = cam_ife_hw_mgr_init_hw_res(v9);
      if ( v10 )
      {
        v4 = *((unsigned int *)v9 + 5);
        v5 = *(unsigned int *)(a1 + 56);
        v6 = v10;
        v7 = "Can not INIT SFE SRC res (%d), ctx_idx:%u";
        v8 = 1977;
        goto LABEL_58;
      }
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_init_hw",
        1983,
        "INIT SFE OUT RESOURCES in ctx id:%u",
        *(_DWORD *)(a1 + 56));
      if ( *(_DWORD *)(a1 + 8516) )
      {
LABEL_19:
        v11 = 0;
        while ( 1 )
        {
          v12 = v11;
          v13 = cam_ife_hw_mgr_init_hw_res(*(_QWORD *)(a1 + 280) + ((__int64)v11 << 7));
          if ( v13 )
            break;
          v11 = v12 + 1;
          if ( (unsigned int)(v12 + 1) >= *(_DWORD *)(a1 + 8516) )
            goto LABEL_22;
        }
        v5 = *(unsigned int *)(a1 + 56);
        v6 = v13;
        v7 = "Can not INIT SFE OUT (%d), ctx_idx:%u";
        v8 = 1989;
        v4 = *(unsigned int *)(*(_QWORD *)(a1 + 280) + (v12 << 7) + 20);
        goto LABEL_58;
      }
    }
    else if ( *(_DWORD *)(a1 + 8516) )
    {
      goto LABEL_19;
    }
  }
LABEL_22:
  v14 = debug_priority;
  v15 = debug_mdl & 8;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v15,
      4,
      "cam_ife_hw_mgr_init_hw",
      1996,
      "INIT IFE csid ... in ctx id:%u",
      *(_DWORD *)(a1 + 56));
    v14 = debug_priority;
    v15 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 )
    {
LABEL_25:
      if ( !v14 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v15,
          4,
          "cam_ife_hw_mgr_init_hw",
          2000,
          "INIT IFE BUS RD in ctx id:%u",
          *(_DWORD *)(a1 + 56));
    }
  }
  else if ( (debug_mdl & 8) != 0 )
  {
    goto LABEL_25;
  }
  v16 = (__int64 *)(a1 + 256);
  while ( 1 )
  {
    v16 = (__int64 *)*v16;
    if ( v16 == (__int64 *)(a1 + 256) )
      break;
    v17 = cam_ife_hw_mgr_init_hw_res(v16);
    if ( v17 )
    {
      v18 = *(_DWORD *)(a1 + 56);
      v19 = v17;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_init_hw",
        2005,
        "Can not IFE BUS RD (%d), ctx_idx:%u",
        *((_DWORD *)v16 + 5),
        v18);
      return v19;
    }
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_init_hw",
      2012,
      "INIT IFE OUT RESOURCES in ctx id:%u",
      *(_DWORD *)(a1 + 56));
    if ( *(_DWORD *)(a1 + 8512) )
    {
LABEL_34:
      v21 = 0;
      while ( 1 )
      {
        v22 = v21;
        v23 = cam_ife_hw_mgr_init_hw_res(*(_QWORD *)(a1 + 272) + ((__int64)v21 << 7));
        if ( v23 )
          break;
        v21 = v22 + 1;
        if ( (unsigned int)(v22 + 1) >= *(_DWORD *)(a1 + 8512) )
          goto LABEL_37;
      }
      v5 = *(unsigned int *)(a1 + 56);
      v6 = v23;
      v7 = "Can not INIT IFE OUT (%d), ctx_idx:%u";
      v8 = 2018;
      v4 = *(unsigned int *)(*(_QWORD *)(a1 + 272) + (v22 << 7) + 20);
      goto LABEL_58;
    }
  }
  else if ( *(_DWORD *)(a1 + 8512) )
  {
    goto LABEL_34;
  }
LABEL_37:
  v24 = (__int64 *)(a1 + 208);
  while ( 1 )
  {
    v24 = (__int64 *)*v24;
    if ( v24 == (__int64 *)(a1 + 208) )
      break;
    v25 = cam_ife_hw_mgr_init_hw_res(v24);
    if ( v25 )
    {
      v4 = *((unsigned int *)v24 + 5);
      v5 = *(unsigned int *)(a1 + 56);
      v6 = v25;
      v7 = "Can not INIT IFE CSID(id :%d), ctx_idx:%u";
      v8 = 2028;
      goto LABEL_58;
    }
  }
  if ( (*(_BYTE *)(a1 + 9393) & 1) != 0 )
  {
    v26 = cam_cpas_activate_llcc(0);
    if ( v26 )
    {
      v6 = v26;
      v27 = 0;
LABEL_56:
      v5 = *(unsigned int *)(a1 + 56);
      v7 = "Failed to activate cache: %d, ctx_idx:%u";
      v8 = 2039;
      v4 = v27;
      goto LABEL_58;
    }
  }
  if ( *(_BYTE *)(a1 + 9394) == 1 )
  {
    v27 = 1;
    LODWORD(result) = cam_cpas_activate_llcc(1);
    if ( (_DWORD)result )
      goto LABEL_55;
  }
  if ( *(_BYTE *)(a1 + 9395) == 1 && (v27 = 2, LODWORD(result) = cam_cpas_activate_llcc(2), (_DWORD)result)
    || *(_BYTE *)(a1 + 9396) == 1 && (v27 = 3, LODWORD(result) = cam_cpas_activate_llcc(3), (_DWORD)result)
    || *(_BYTE *)(a1 + 9397) == 1 && (v27 = 4, LODWORD(result) = cam_cpas_activate_llcc(4), (_DWORD)result) )
  {
LABEL_55:
    v6 = result;
    goto LABEL_56;
  }
  if ( *(_BYTE *)(a1 + 9398) == 1 )
  {
    v27 = 5;
    result = cam_cpas_activate_llcc(5);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_55;
  }
  return 0;
}
