__int64 __fastcall cam_ife_hw_mgr_acquire_csid_rdi_util(__int64 a1, __int64 a2, int a3, _DWORD *a4)
{
  __int64 v4; // x21
  __int64 *v6; // x20
  __int64 **v7; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w9
  int v13; // w6
  int v14; // w8
  unsigned int v15; // w23
  __int64 *v16; // x1
  __int64 v17; // x8
  char v18; // w9
  unsigned int v19; // w10
  __int64 v20; // x2
  _DWORD *v22; // x10
  __int64 v23; // x9
  const char *v24; // x10
  _DWORD *v25; // x23
  _DWORD *v26; // [xsp+18h] [xbp-98h]
  _DWORD *v27; // [xsp+18h] [xbp-98h]
  __int64 v28; // [xsp+20h] [xbp-90h]
  __int64 v29; // [xsp+20h] [xbp-90h]
  __int64 v30; // [xsp+20h] [xbp-90h]
  int v31; // [xsp+28h] [xbp-88h] BYREF
  unsigned int v32; // [xsp+2Ch] [xbp-84h]
  __int64 v33; // [xsp+30h] [xbp-80h]
  _DWORD *v34; // [xsp+38h] [xbp-78h]
  __int64 v35; // [xsp+40h] [xbp-70h]
  __int64 v36; // [xsp+48h] [xbp-68h]
  __int64 v37; // [xsp+50h] [xbp-60h]
  __int64 v38; // [xsp+58h] [xbp-58h]
  __int64 v39; // [xsp+60h] [xbp-50h]
  __int64 v40; // [xsp+68h] [xbp-48h]
  __int64 v41; // [xsp+70h] [xbp-40h]
  __int64 v42; // [xsp+78h] [xbp-38h]
  __int64 v43; // [xsp+80h] [xbp-30h]
  __int64 (__fastcall *v44)(__int64, unsigned int, _DWORD *); // [xsp+88h] [xbp-28h]
  __int64 v45; // [xsp+90h] [xbp-20h]
  __int64 v46; // [xsp+98h] [xbp-18h]
  __int64 v47; // [xsp+A0h] [xbp-10h]
  __int64 v48; // [xsp+A8h] [xbp-8h]

  v4 = a1 + 288;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(__int64 **)(a1 + 288);
  if ( v6 == (__int64 *)(a1 + 288) )
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
      "cam_ife_hw_mgr_acquire_csid_rdi_util",
      4770,
      "No more free hw mgr resource, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    v15 = -1;
    goto LABEL_42;
  }
  v7 = (__int64 **)v6[1];
  if ( *v7 == v6 && (v9 = *v6, *(__int64 **)(*v6 + 8) == v6) )
  {
    *(_QWORD *)(v9 + 8) = v7;
    *v7 = (__int64 *)v9;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 288));
    a4 = v22;
    a2 = v23;
  }
  *v6 = (__int64)v6;
  v6[1] = (__int64)v6;
  v31 = 3;
  v32 = a3;
  v43 = 0;
  v44 = cam_ife_hw_mgr_event_handler;
  v10 = *(_QWORD *)(a1 + 16);
  v11 = *(_QWORD *)(a1 + 8728);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = v10;
  LODWORD(v10) = *(_DWORD *)(a1 + 9312);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = a2;
  v34 = a4;
  v46 = a1;
  v47 = 0;
  v45 = 0;
  v43 = v11;
  if ( (_DWORD)v10 == 2 )
    LOBYTE(v47) = 1;
  if ( a4 )
  {
    if ( (unsigned int)(*a4 - 24576) > 2 || ((*(_BYTE *)(a1 + 9388) | *(_BYTE *)(a1 + 9387)) & 1) == 0 )
      goto LABEL_21;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v26 = a4;
      v28 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_acquire_csid_rdi_util",
        4792,
        "setting inline shdr mode for res: 0x%x, ctx_idx: %u",
        *a4,
        *(_DWORD *)(a1 + 56));
      a4 = v26;
      a2 = v28;
    }
    v12 = *(unsigned __int8 *)(a1 + 9391);
    BYTE2(v39) = 1;
    if ( v12 != 1 )
      goto LABEL_21;
    v13 = *a4;
    if ( (unsigned int)(*a4 - 24576) >= *(_DWORD *)(a1 + 9352)
      && (BYTE4(v38) = 1, LODWORD(v38) = 1, (debug_mdl & 8) != 0)
      && !debug_priority )
    {
      v27 = a4;
      v29 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_acquire_csid_rdi_util",
        4807,
        "Secondary SOF evt enabled for path: 0x%x, ctx_idx: %u",
        v13,
        *(_DWORD *)(a1 + 56));
      a4 = v27;
      a2 = v29;
      if ( *v27 == 24576 )
        goto LABEL_18;
    }
    else if ( v13 == 24576 )
    {
LABEL_18:
      BYTE4(v38) = 1;
      LODWORD(v38) = 6;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v30 = a2;
        v25 = a4;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_acquire_csid_rdi_util",
          4818,
          "Secondary EPOCH & frame drop evt enabled for path: 0x%x, ctx_idx: %u",
          24576,
          *(_DWORD *)(a1 + 56));
        a2 = v30;
        a4 = v25;
      }
    }
LABEL_21:
    *((_DWORD *)v6 + 26) = a4[6];
  }
  v14 = *(_DWORD *)(a2 + 80);
  LOWORD(v39) = 257;
  LODWORD(v35) = v14 != 0;
  v15 = cam_ife_hw_mgr_acquire_csid_hw(a1, (__int64)&v31, a2);
  if ( !v15 )
  {
    v17 = v37;
    if ( v37 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v24 = "N";
        if ( *((_DWORD *)v6 + 26) )
          v24 = "Y";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_acquire_csid_rdi_util",
          4855,
          "acquired csid[%u] rdi path rsrc %u successfully, is_secure: %s, ctx_idx: %u",
          *(_DWORD *)(*(_QWORD *)(v37 + 16) + 4LL),
          *(_DWORD *)(v37 + 4),
          v24,
          *(_DWORD *)(a1 + 56));
        v17 = v37;
      }
      v18 = BYTE4(v39);
      *(_BYTE *)(a1 + 9400) = BYTE3(v47);
      v19 = v32;
      *(_BYTE *)(a1 + 9384) = v18;
      *((_DWORD *)v6 + 4) = 3;
      *(__int64 *)((char *)v6 + 20) = v19;
      v6[4] = v17;
      v6[5] = 0;
      *((_BYTE *)v6 + 120) = BYTE1(v47);
      if ( *(_DWORD *)(a1 + 60) == 8 )
        *(_DWORD *)(a1 + 60) = *(_DWORD *)(*(_QWORD *)(v17 + 16) + 4LL);
      if ( !*(_QWORD *)(a1 + 9336) && v41 )
        *(_QWORD *)(a1 + 9336) = v41;
      if ( !v6 )
      {
        v15 = 0;
        goto LABEL_42;
      }
      v20 = a1 + 208;
      v16 = *(__int64 **)(a1 + 216);
      if ( v6 == (__int64 *)(a1 + 208) || v16 == v6 || *v16 != v20 )
      {
        _list_add_valid_or_report(v6);
        v15 = 0;
        goto LABEL_42;
      }
      v15 = 0;
      *(_QWORD *)(a1 + 216) = v6;
      *v6 = v20;
      goto LABEL_41;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_csid_rdi_util",
      4846,
      "Acquire CSID RDI rsrc failed, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    if ( !v6 )
      goto LABEL_42;
LABEL_24:
    v16 = *(__int64 **)(a1 + 296);
    if ( v16 == v6 || *v16 != v4 )
    {
      _list_add_valid_or_report(v6);
      goto LABEL_42;
    }
    *(_QWORD *)(a1 + 296) = v6;
    *v6 = v4;
LABEL_41:
    v6[1] = (__int64)v16;
    *v16 = (__int64)v6;
    goto LABEL_42;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_acquire_csid_rdi_util",
    4841,
    "CSID Path reserve failed  rc=%d res_id=%d ctx_idx: %u",
    v15,
    a3,
    *(_DWORD *)(a1 + 56));
  if ( v6 )
    goto LABEL_24;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v15;
}
