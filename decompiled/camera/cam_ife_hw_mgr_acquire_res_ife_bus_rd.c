__int64 __fastcall cam_ife_hw_mgr_acquire_res_ife_bus_rd(__int64 a1, __int64 a2)
{
  __int64 v2; // x6
  __int64 v3; // x9
  __int64 v5; // x25
  _QWORD *v6; // x20
  __int64 v7; // x21
  _QWORD *v8; // x8
  __int64 v9; // x10
  __int64 v10; // x10
  char v11; // w8
  __int64 v12; // x6
  int v13; // w11
  __int64 v14; // x10
  __int64 v15; // x27
  unsigned int v16; // w22
  __int64 v17; // x21
  __int64 v18; // x23
  __int64 *v19; // x8
  __int64 v20; // x28
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 (__fastcall *v23)(__int64, __int64 *, __int64); // x8
  __int64 v24; // x9
  const char *v25; // x5
  __int64 v26; // x4
  __int64 *v27; // x8
  unsigned int (__fastcall *v28)(__int64, __int64 *, __int64); // x8
  __int64 v29; // x0
  int v30; // w9
  __int64 v31; // x2
  _QWORD *v32; // x1
  __int64 v33; // x6
  __int64 *v34; // x8
  __int64 v35; // x21
  unsigned int (__fastcall *v36)(__int64, __int64 *, __int64); // x8
  __int64 v37; // x0
  int v38; // w6
  char v39; // w8
  __int64 v40; // x10
  _QWORD *v41; // x1
  __int64 v43; // [xsp+10h] [xbp-80h]
  __int64 v44; // [xsp+18h] [xbp-78h] BYREF
  __int64 v45; // [xsp+20h] [xbp-70h]
  __int64 v46; // [xsp+28h] [xbp-68h]
  __int64 (__fastcall *v47)(__int64, unsigned int, _DWORD *); // [xsp+30h] [xbp-60h]
  __int64 v48; // [xsp+38h] [xbp-58h]
  __int64 v49; // [xsp+40h] [xbp-50h]
  __int64 v50; // [xsp+48h] [xbp-48h]
  __int64 v51; // [xsp+50h] [xbp-40h]
  __int64 v52; // [xsp+58h] [xbp-38h]
  __int64 v53; // [xsp+60h] [xbp-30h]
  __int64 v54; // [xsp+68h] [xbp-28h]
  __int64 v55; // [xsp+70h] [xbp-20h]
  __int64 v56; // [xsp+78h] [xbp-18h]
  __int64 v57; // [xsp+80h] [xbp-10h]
  __int64 v58; // [xsp+88h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a1 + 60);
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = nullptr;
  v44 = 0;
  v45 = 0;
  if ( (unsigned int)v2 >= 8 )
    goto LABEL_61;
  v3 = *(_QWORD *)(a1 + 72);
  v5 = v3 + 160;
  if ( !*(_QWORD *)(v3 + 160 + 8 * v2) )
  {
    v25 = "ife_devices[%d] is NULL";
    v26 = 3810;
LABEL_22:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
      v26,
      v25,
      v2);
    v16 = -19;
    goto LABEL_60;
  }
  v6 = *(_QWORD **)(a1 + 288);
  v7 = a1 + 288;
  if ( v6 == (_QWORD *)(a1 + 288) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_get_res",
      2078,
      "No more free ife hw mgr ctx");
    v2 = *(unsigned int *)(a1 + 56);
    v25 = "No more free hw mgr resource, ctx_idx: %u";
    v26 = 3816;
    goto LABEL_22;
  }
  v8 = (_QWORD *)v6[1];
  if ( (_QWORD *)*v8 == v6 && (v9 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
  {
    *(_QWORD *)(v9 + 8) = v8;
    *v8 = v9;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 288));
    a2 = v40;
  }
  *v6 = v6;
  v6[1] = v6;
  LODWORD(v44) = 5;
  v10 = *(_QWORD *)(a1 + 8728);
  v46 = a1;
  v47 = cam_ife_hw_mgr_event_handler;
  v11 = *(_BYTE *)(a1 + 9380);
  v12 = *(unsigned int *)(a1 + 60);
  v13 = *(_DWORD *)(a2 + 136);
  v52 = v10;
  LODWORD(v10) = *(unsigned __int8 *)(a1 + 9379);
  BYTE4(v53) = v11;
  LODWORD(v51) = 2;
  HIDWORD(v51) = v10;
  v14 = *(_QWORD *)(a1 + 16);
  LODWORD(v53) = v13;
  v45 = v14;
  if ( (unsigned int)v12 < 8 )
  {
    v27 = *(__int64 **)(v5 + 8 * v12);
    if ( !v27 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
        3865,
        "IFE device %d is NULL.",
        v12);
      v16 = 0;
      if ( !v6 )
        goto LABEL_60;
      goto LABEL_57;
    }
    v20 = *v27;
    v43 = a1 + 288;
    v28 = *(unsigned int (__fastcall **)(__int64, __int64 *, __int64))(*v27 + 40);
    v29 = *(_QWORD *)(v20 + 112);
    if ( *((_DWORD *)v28 - 1) != 1989616049 )
      __break(0x8228u);
    if ( v28(v29, &v44, 112) || (v24 = v50) == 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
        3876,
        "Failed to acquire VFE:%d BUS RD for LEFT, ctx_idx: %u",
        *(_DWORD *)(a1 + 60),
        *(_DWORD *)(a1 + 56));
      v7 = a1 + 288;
      v16 = -19;
      if ( !v6 )
        goto LABEL_60;
      goto LABEL_57;
    }
LABEL_28:
    v6[4] = v24;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
        3885,
        "Acquired VFE:%d BUS RD for LEFT, ctx_idx: %u",
        *(_DWORD *)(a1 + 60),
        *(_DWORD *)(a1 + 56));
    v30 = v44;
    *(_DWORD *)(a1 + 60) = *(_DWORD *)(v20 + 4);
    *((_DWORD *)v6 + 4) = v30;
    *((_DWORD *)v6 + 5) = v51;
    *((_DWORD *)v6 + 6) = *(unsigned __int8 *)(a1 + 9379);
    if ( v6 )
    {
      v31 = a1 + 256;
      v32 = *(_QWORD **)(a1 + 264);
      if ( v6 == (_QWORD *)(a1 + 256) || v32 == v6 || *v32 != v31 )
      {
        _list_add_valid_or_report(v6);
      }
      else
      {
        *(_QWORD *)(a1 + 264) = v6;
        *v6 = v31;
        v6[1] = v32;
        *v32 = v6;
      }
    }
    if ( *(_BYTE *)(a1 + 9379) != 1 )
    {
      v16 = 0;
      goto LABEL_60;
    }
    v33 = *(unsigned int *)(a1 + 64);
    if ( (unsigned int)v33 <= 7 )
    {
      v34 = *(__int64 **)(v5 + 8 * v33);
      if ( v34 )
      {
        v35 = *v34;
        v36 = *(unsigned int (__fastcall **)(__int64, __int64 *, __int64))(*v34 + 40);
        v37 = *(_QWORD *)(v35 + 112);
        if ( *((_DWORD *)v36 - 1) != 1989616049 )
          __break(0x8228u);
        v16 = 0;
        if ( !v36(v37, &v44, 112) )
        {
          if ( v50 )
          {
            v6[5] = v50;
            v16 = 0;
            v38 = *(_DWORD *)(v35 + 4);
            v39 = debug_mdl;
            *(_DWORD *)(a1 + 64) = v38;
            if ( (v39 & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v39 & 8,
                4,
                "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
                3911,
                "Acquired VFE:%d BUS RD for RIGHT, ctx: %u",
                v38,
                *(_DWORD *)(a1 + 56));
              v16 = 0;
            }
          }
        }
        goto LABEL_60;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
        3895,
        "ife_devices[%d] is NULL",
        v33);
      v7 = v43;
      v16 = 0;
      if ( !v6 )
        goto LABEL_60;
      goto LABEL_57;
    }
LABEL_61:
    __break(0x5512u);
  }
  if ( !*(_DWORD *)(a2 + 184) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
      3858,
      "The acquired hw idx %d is invalid and it isn't FE usecase",
      v12);
    v16 = -19;
    if ( !v6 )
      goto LABEL_60;
    goto LABEL_57;
  }
  v43 = a1 + 288;
  v15 = 0;
  v16 = 0;
  v17 = v3 + 80752;
  v18 = v3 + 216;
  do
  {
    v19 = *(__int64 **)(v18 + 8 * v15);
    if ( v19 )
    {
      v20 = *v19;
      v21 = *(unsigned int *)(*v19 + 4);
      if ( (unsigned int)v21 > 7 )
        goto LABEL_61;
      if ( (*(_BYTE *)(v17 + 16 * v21 + 12) & 1) == 0 )
      {
        v50 = 0;
        v22 = *(_QWORD *)(v20 + 112);
        v23 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
        if ( *((_DWORD *)v23 - 1) != 1989616049 )
          __break(0x8228u);
        v16 = v23(v22, &v44, 112);
        if ( !v16 )
        {
          v24 = v50;
          if ( v50 )
            goto LABEL_28;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
          3849,
          "IFE[%d] acquire failed (rc=%d), ctx_idx: %u",
          v15 + 7,
          v16,
          *(_DWORD *)(a1 + 56));
      }
    }
    --v15;
  }
  while ( v15 != -8 );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_acquire_res_ife_bus_rd",
    3852,
    "Can't find free IFE for ctx_idx: %u",
    *(_DWORD *)(a1 + 56));
  v7 = a1 + 288;
  if ( v6 )
  {
LABEL_57:
    v41 = *(_QWORD **)(a1 + 296);
    if ( v41 == v6 || *v41 != v7 )
    {
      _list_add_valid_or_report(v6);
    }
    else
    {
      *(_QWORD *)(a1 + 296) = v6;
      *v6 = v7;
      v6[1] = v41;
      *v41 = v6;
    }
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return v16;
}
