__int64 __fastcall cam_ife_mgr_prog_default_settings(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v8; // x22
  __int64 v9; // x27
  char v10; // w21
  unsigned int *v11; // x20
  int v12; // w6
  unsigned int v13; // w19
  __int64 v14; // x25
  __int64 v15; // x23
  _QWORD *v16; // x28
  __int64 v17; // x20
  __int64 v18; // x8
  __int64 v19; // x24
  unsigned int v20; // w8
  __int64 v21; // x3
  unsigned int v22; // w8
  __int64 v23; // x3
  unsigned __int64 v24; // x27
  const void **v25; // x23
  __int64 v26; // x9
  __int64 v27; // x28
  __int64 v28; // x22
  __int64 v29; // x26
  _QWORD *v30; // x20
  unsigned int v31; // w7
  unsigned int v32; // w7
  char v33; // [xsp+24h] [xbp-1Ch]
  __int64 v34; // [xsp+28h] [xbp-18h]
  __int64 v35; // [xsp+30h] [xbp-10h]
  char v36; // [xsp+3Ch] [xbp-4h]

  v8 = a4 + 0x2000;
  v36 = a3;
  v34 = result;
  v33 = a2;
  if ( *(_DWORD *)(a4 + 9312) != 2 || (v9 = *(_QWORD *)(a4 + 9360), (*(_BYTE *)(v9 + 136) & 1) != 0) )
  {
    v10 = 1;
LABEL_4:
    v11 = *(unsigned int **)(a4 + 9368);
    if ( !v11 || !*v11 || (v11[22] & 1) != 0 )
    {
LABEL_7:
      if ( (v36 & 1) != 0 )
        return 0;
      if ( (v34 & 0x8000000000000000LL) == 0 && (*(_BYTE *)(v8 + 1208) & 1) != 0 )
        cam_isp_mgr_drv_config(a4, v34, v33 & 1, 0);
      result = cam_isp_config_csid_rup_aup((_DWORD *)a4, v10 & 1);
      if ( (_DWORD)result )
      {
        v12 = *(_DWORD *)(a4 + 56);
        v13 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_prog_default_settings",
          16361,
          "RUP/AUP update failed for scratch buffers in ctx: %u",
          v12);
        return v13;
      }
      return result;
    }
    v24 = 0;
    v25 = (const void **)(v11 + 8);
    v35 = *(_QWORD *)(a4 + 272);
    while ( 1 )
    {
      if ( v24 == 2 )
        goto LABEL_91;
      a7 = *(unsigned int *)v25;
      v26 = *(unsigned __int8 *)(*(_QWORD *)(a4 + 8496) + (unsigned __int8)*(_DWORD *)v25);
      if ( v26 == 255 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_configure_scratch_for_ife",
          16169,
          "Invalid index:%d for out_map",
          (unsigned __int8)*(_DWORD *)v25);
        return 4294967274LL;
      }
      v27 = v8;
      v28 = v35 + (v26 << 7);
      v29 = 1LL << v24;
      a3 = *(_QWORD *)(v28 + 32);
      if ( a3 )
      {
        if ( (v36 & 1) != 0 && ((unsigned int)v29 & *(_DWORD *)(*(_QWORD *)(a4 + 9368) + 4LL)) != 0 )
          goto LABEL_45;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_configure_scratch_for_ife",
            16188,
            "Configure scratch for IFE res: 0x%x io_addr %pK ctx_idx: %u",
            a7,
            *(v25 - 1),
            *(_DWORD *)(a4 + 56));
        result = cam_isp_sfe_send_scratch_buf_upd(0, 56);
        v10 = 0;
        if ( (_DWORD)result )
          return result;
      }
      a3 = *(_QWORD *)(v28 + 40);
      if ( a3 && ((v36 & 1) == 0 || ((unsigned int)v29 & *(_DWORD *)(*(_QWORD *)(a4 + 9368) + 4LL)) == 0) )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_configure_scratch_for_ife",
            16188,
            "Configure scratch for IFE res: 0x%x io_addr %pK ctx_idx: %u",
            *(_DWORD *)v25,
            *(v25 - 1),
            *(_DWORD *)(a4 + 56));
        result = cam_isp_sfe_send_scratch_buf_upd(0, 56);
        v10 = 0;
        if ( (_DWORD)result )
          return result;
      }
LABEL_45:
      ++v24;
      v25 += 5;
      v8 = v27;
      if ( v24 >= *v11 )
        goto LABEL_7;
    }
  }
  v14 = *(_QWORD *)(a4 + 280);
  v15 = 0;
  v16 = (_QWORD *)(a4 + 256);
  v17 = v9 + 16;
  v10 = 1;
  do
  {
    v18 = *(unsigned __int8 *)(*(_QWORD *)(a4 + 8504) + v15);
    if ( v18 != 255 )
    {
      v19 = v14 + (v18 << 7);
      a3 = *(_QWORD *)(v19 + 32);
      if ( a3 )
      {
        a7 = *(unsigned int *)(a3 + 4);
        v20 = a7 - 24576;
        if ( *(_DWORD *)(a4 + 9352) > (unsigned int)(a7 - 24576)
          && (*(_BYTE *)(v8 + 1195) != 1 || (*(_BYTE *)(a4 + 9316) & 4) == 0 || *(_DWORD *)(a4 + 9444) > v20)
          && ((v36 & 1) == 0 || (((unsigned __int64)*(unsigned int *)(v9 + 4) >> a7) & 1) == 0) )
        {
          if ( v20 > 3 )
            goto LABEL_91;
          v21 = v17 + 40LL * v20;
          if ( (*(_BYTE *)(v21 + 32) & 1) == 0 )
          {
LABEL_89:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_mgr_configure_scratch_for_sfe",
              16253,
              "No scratch buffer config found for res: %u on ctx: %u",
              a7,
              *(_DWORD *)(a4 + 56));
            return 4294967282LL;
          }
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_mgr_configure_scratch_for_sfe",
              16263,
              "RDI%d res_id 0x%x idx %u io_addr %pK ctx_idx: %u",
              v15,
              a7,
              v20,
              *(const void **)(v21 + 16),
              *(_DWORD *)(a4 + 56));
          result = cam_isp_sfe_send_scratch_buf_upd(0, 56);
          v10 = 0;
          if ( (_DWORD)result )
            return result;
        }
      }
      a3 = *(_QWORD *)(v19 + 40);
      if ( a3 )
      {
        a7 = *(unsigned int *)(a3 + 4);
        v22 = a7 - 24576;
        if ( *(_DWORD *)(a4 + 9352) > (unsigned int)(a7 - 24576)
          && (*(_BYTE *)(v8 + 1195) != 1 || (*(_BYTE *)(a4 + 9316) & 4) == 0 || *(_DWORD *)(a4 + 9444) > v22)
          && ((v36 & 1) == 0 || (((unsigned __int64)*(unsigned int *)(v9 + 4) >> a7) & 1) == 0) )
        {
          if ( v22 > 3 )
          {
LABEL_91:
            __break(0x5512u);
            return cam_ife_mgr_csid_start_hw(result, a2, a3, a4, a5, a6, a7);
          }
          v23 = v17 + 40LL * v22;
          if ( *(_BYTE *)(v23 + 32) != 1 )
            goto LABEL_89;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_mgr_configure_scratch_for_sfe",
              16263,
              "RDI%d res_id 0x%x idx %u io_addr %pK ctx_idx: %u",
              v15,
              a7,
              v22,
              *(const void **)(v23 + 16),
              *(_DWORD *)(a4 + 56));
          result = cam_isp_sfe_send_scratch_buf_upd(0, 56);
          v10 = 0;
          if ( (_DWORD)result )
            return result;
        }
      }
    }
    ++v15;
  }
  while ( v15 != 3 );
  v30 = (_QWORD *)*v16;
  if ( (_QWORD *)*v16 == v16 )
    goto LABEL_4;
  while ( 1 )
  {
    a3 = v30[4];
    if ( a3 )
    {
      a7 = *(unsigned int *)(a3 + 4);
      v31 = a7 - 20481;
      if ( *(_DWORD *)(a4 + 9352) > (unsigned int)(a7 - 20481)
        && (*(_BYTE *)(v8 + 1195) != 1 || (*(_BYTE *)(a4 + 9316) & 4) == 0 || *(_DWORD *)(a4 + 9444) > v31)
        && ((v36 & 1) == 0 || (((unsigned __int64)*(unsigned int *)(v9 + 4) >> v31) & 1) == 0) )
      {
        if ( v31 > 3 )
          goto LABEL_91;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_configure_scratch_for_sfe",
            16300,
            "RD res_id 0x%x idx %u io_addr %pK ctx_idx: %u",
            a7,
            v31,
            *(const void **)(*(_QWORD *)(a4 + 9360) + 40LL * v31 + 32),
            *(_DWORD *)(a4 + 56));
        result = cam_isp_sfe_send_scratch_buf_upd(0, 57);
        v10 = 0;
        if ( (_DWORD)result )
          return result;
      }
    }
    a3 = v30[5];
    if ( a3 )
    {
      a7 = *(unsigned int *)(a3 + 4);
      v32 = a7 - 20481;
      if ( *(_DWORD *)(a4 + 9352) > (unsigned int)(a7 - 20481)
        && (*(_BYTE *)(v8 + 1195) != 1 || (*(_BYTE *)(a4 + 9316) & 4) == 0 || *(_DWORD *)(a4 + 9444) > v32)
        && ((v36 & 1) == 0 || (((unsigned __int64)*(unsigned int *)(v9 + 4) >> v32) & 1) == 0) )
      {
        if ( v32 > 3 )
          goto LABEL_91;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_configure_scratch_for_sfe",
            16300,
            "RD res_id 0x%x idx %u io_addr %pK ctx_idx: %u",
            a7,
            v32,
            *(const void **)(*(_QWORD *)(a4 + 9360) + 40LL * v32 + 32),
            *(_DWORD *)(a4 + 56));
        result = cam_isp_sfe_send_scratch_buf_upd(0, 57);
        v10 = 0;
        if ( (_DWORD)result )
          return result;
      }
    }
    v30 = (_QWORD *)*v30;
    if ( v30 == v16 )
      goto LABEL_4;
  }
}
