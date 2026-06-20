__int64 __fastcall cam_ife_hw_mgr_acquire_sfe_bus_rd(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  _QWORD *v4; // x23
  _QWORD *v5; // x20
  _QWORD *v6; // x8
  __int64 v8; // x9
  int v9; // w6
  __int64 v10; // x10
  char v11; // w8
  int v12; // w9
  __int64 v13; // x6
  __int64 v14; // x8
  __int64 *v15; // x8
  __int64 v16; // x24
  __int64 (__fastcall *v17)(__int64, __int64 *, __int64); // x8
  __int64 v18; // x0
  int v19; // w0
  __int64 *v20; // x8
  __int64 result; // x0
  __int64 *v22; // x8
  __int64 (__fastcall *v23)(__int64, __int64 *, __int64); // x8
  __int64 v24; // x0
  char v25; // w8
  int v26; // w8
  __int64 v27; // x2
  _QWORD *v28; // x1
  const char *v29; // x5
  __int64 v30; // x4
  __int64 (__fastcall *v31)(__int64, __int64 *, __int64); // x8
  __int64 v32; // x0
  __int64 *v33; // x8
  __int64 (__fastcall *v34)(__int64, __int64 *, __int64); // x8
  __int64 v35; // x0
  unsigned int v36; // w9
  __int64 v37; // [xsp+20h] [xbp-60h] BYREF
  __int64 v38; // [xsp+28h] [xbp-58h]
  __int64 v39; // [xsp+30h] [xbp-50h]
  __int64 (__fastcall *v40)(); // [xsp+38h] [xbp-48h]
  __int64 v41; // [xsp+40h] [xbp-40h]
  __int64 v42; // [xsp+48h] [xbp-38h]
  __int64 v43; // [xsp+50h] [xbp-30h]
  __int64 v44; // [xsp+58h] [xbp-28h]
  __int64 v45; // [xsp+60h] [xbp-20h]
  __int64 v46; // [xsp+68h] [xbp-18h]
  __int64 v47; // [xsp+70h] [xbp-10h]
  __int64 v48; // [xsp+78h] [xbp-8h]

  v2 = a1 + 288;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v4 = *(_QWORD **)(a1 + 72);
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = nullptr;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v37 = 0;
  v5 = *(_QWORD **)(a1 + 288);
  if ( v5 == (_QWORD *)(a1 + 288) )
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
      "cam_ife_hw_mgr_acquire_sfe_bus_rd",
      3936,
      "No more free hw mgr resource, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    result = 0xFFFFFFFFLL;
    goto LABEL_52;
  }
  v6 = (_QWORD *)v5[1];
  if ( (_QWORD *)*v6 == v5 && (v8 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
  {
    *(_QWORD *)(v8 + 8) = v6;
    *v6 = v8;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 288));
  }
  *v5 = v5;
  v5[1] = v5;
  v9 = *(_DWORD *)(a2 + 196);
  if ( (unsigned int)(v9 - 20481) >= 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_sfe_bus_rd",
      3942,
      "Invalid sfe rd type: 0x%x ctx_idx: %u",
      v9,
      *(_DWORD *)(a1 + 56));
    result = 4294967274LL;
    if ( !v5 )
      goto LABEL_52;
    goto LABEL_48;
  }
  if ( *(_DWORD *)(a2 + 80) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_hw_mgr_acquire_sfe_bus_rd",
      3949,
      "DUAL mode not supported for BUS RD [RDIs], ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    v9 = *(_DWORD *)(a2 + 196);
  }
  LODWORD(v37) = 11;
  v10 = *(_QWORD *)(a1 + 8728);
  v39 = a1;
  v40 = cam_ife_hw_mgr_event_handler;
  v11 = *(_BYTE *)(a1 + 9380);
  v12 = *(_DWORD *)(a2 + 136);
  LODWORD(v43) = v9;
  v13 = *(unsigned int *)(a1 + 60);
  BYTE4(v45) = v11;
  v14 = *(_QWORD *)(a1 + 16);
  LODWORD(v45) = v12;
  LOBYTE(v12) = *(_BYTE *)(a2 + 216);
  v44 = v10;
  v38 = v14;
  BYTE5(v45) = v12;
  if ( (unsigned int)v13 < 3 )
  {
    v22 = (__int64 *)v4[v13 + 28];
    if ( v22 )
    {
      v16 = *v22;
      v23 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v22 + 40);
      v24 = *(_QWORD *)(v16 + 112);
      if ( *((_DWORD *)v23 - 1) != 1989616049 )
        __break(0x8228u);
      v19 = v23(v24, &v37, 88);
      goto LABEL_23;
    }
    v29 = "No valid sfe devices for idx:%d";
    v30 = 3986;
LABEL_36:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_sfe_bus_rd",
      v30,
      v29);
    result = 4294967277LL;
    if ( !v5 )
      goto LABEL_52;
    goto LABEL_48;
  }
  if ( !*(_DWORD *)(a2 + 184) )
  {
    v29 = "The acquired hw idx %d is invalid and it isn't FE usecase";
    v30 = 3979;
    goto LABEL_36;
  }
  v15 = (__int64 *)v4[28];
  if ( v15 )
  {
    v16 = *v15;
    v17 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v15 + 40);
    v18 = *(_QWORD *)(v16 + 112);
    if ( *((_DWORD *)v17 - 1) != 1989616049 )
      __break(0x8228u);
    v19 = v17(v18, &v37, 88);
    if ( !v19 )
      goto LABEL_23;
    v20 = (__int64 *)v4[29];
    if ( !v20 )
      goto LABEL_43;
  }
  else
  {
    v19 = 0;
    v16 = 0;
    v20 = (__int64 *)v4[29];
    if ( !v20 )
      goto LABEL_43;
  }
  v16 = *v20;
  v31 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v20 + 40);
  v32 = *(_QWORD *)(v16 + 112);
  if ( *((_DWORD *)v31 - 1) != 1989616049 )
    __break(0x8228u);
  v19 = v31(v32, &v37, 88);
  if ( v19 )
  {
LABEL_43:
    v33 = (__int64 *)v4[30];
    if ( v33 )
    {
      v16 = *v33;
      v34 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(*v33 + 40);
      v35 = *(_QWORD *)(v16 + 112);
      if ( *((_DWORD *)v34 - 1) != 1989616049 )
        __break(0x8228u);
      v19 = v34(v35, &v37, 88);
      if ( v19 )
        goto LABEL_47;
    }
  }
LABEL_23:
  if ( v42 && !v19 && v16 )
  {
    v5[4] = v42;
    v25 = debug_mdl;
    *(_DWORD *)(a1 + 60) = *(_DWORD *)(v16 + 4);
    if ( (v25 & 8) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v25 & 8,
        4,
        "cam_ife_hw_mgr_acquire_sfe_bus_rd",
        4010,
        "SFE RD left [%u] acquired success for path: %u is_dual: %d res: %s res_id: 0x%x ctx_idx: %u",
        *(_DWORD *)(*(_QWORD *)(v5[4] + 16LL) + 4LL),
        *(_DWORD *)(a2 + 196),
        *(_DWORD *)(a2 + 80),
        (const char *)(v5[4] + 128LL),
        *(_DWORD *)(v5[4] + 4LL),
        *(_DWORD *)(a1 + 56));
    v26 = *(_DWORD *)(a2 + 196);
    *((_DWORD *)v5 + 4) = v37;
    *((_DWORD *)v5 + 5) = v26;
    *((_DWORD *)v5 + 6) = *(_DWORD *)(a2 + 80);
    *((_DWORD *)v5 + 26) = *(unsigned __int8 *)(a2 + 216);
    if ( !v5 )
    {
      result = 0;
      goto LABEL_52;
    }
    v27 = a1 + 256;
    v28 = *(_QWORD **)(a1 + 264);
    if ( v5 == (_QWORD *)(a1 + 256) || v28 == v5 || *v28 != v27 )
    {
      _list_add_valid_or_report(v5);
      result = 0;
      goto LABEL_52;
    }
    result = 0;
    *(_QWORD *)(a1 + 264) = v5;
    *v5 = v27;
    goto LABEL_51;
  }
LABEL_47:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_acquire_sfe_bus_rd",
    3999,
    "Failed to acquire SFE RD: 0x%x, ctx_idx: %u",
    *(_DWORD *)(a2 + 196),
    *(_DWORD *)(a1 + 56));
  result = 4294967277LL;
  if ( v5 )
  {
LABEL_48:
    v28 = *(_QWORD **)(a1 + 296);
    if ( v28 == v5 || *v28 != v2 )
    {
      _list_add_valid_or_report(v5);
      result = v36;
      goto LABEL_52;
    }
    *(_QWORD *)(a1 + 296) = v5;
    *v5 = v2;
LABEL_51:
    v5[1] = v28;
    *v28 = v5;
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
