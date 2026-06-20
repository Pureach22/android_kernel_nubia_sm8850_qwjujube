__int64 __fastcall cam_isp_blob_ife_rdi_lcr_config(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  __int64 v6; // x25
  __int64 v7; // x21
  int v8; // w6
  int v9; // w0
  int v10; // w23
  __int64 *v11; // x28
  unsigned int v12; // w21
  int v13; // w8
  __int64 v14; // x24
  unsigned int v15; // w9
  __int64 v16; // x8
  __int64 v17; // x2
  __int64 (__fastcall *v18)(__int64, __int64, __int64, __int64); // x9
  __int64 v19; // x0
  int v20; // w0
  int v21; // w9
  int v22; // w8
  __int64 result; // x0
  int v24; // w19
  __int64 v25; // x19
  int ife_csid_rdi_res_type; // w0
  __int64 v27; // x2
  int v28; // w23
  const char *v29; // x5
  unsigned int v30; // w19
  __int64 v31; // x4
  __int64 v32; // x6
  __int64 v33; // x7
  __int64 v34; // x4
  __int64 *i; // x0
  __int64 v36; // x9
  int v37; // w9
  bool v38; // zf
  __int64 v39; // x9
  int v40; // w9
  bool v41; // zf
  _DWORD *v42; // x9
  __int64 v43; // x19
  __int64 v44; // [xsp+28h] [xbp-28h]

  v6 = a1 + 0x2000;
  _ReadStatusReg(SP_EL0);
  v7 = *(_QWORD *)(a2 + 320);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v43 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_ife_rdi_lcr_config",
      12298,
      "Blob opcode %u res %u ctx_type %u shdr %u rdi_lcr %u ctx_idx: %u",
      *(_DWORD *)(v7 + 8),
      *a4,
      *(_DWORD *)(a1 + 9312),
      *(unsigned __int8 *)(a1 + 9387),
      *(unsigned __int8 *)(a1 + 9392),
      *(_DWORD *)(a1 + 56));
    a3 = v43;
  }
  v8 = *(_DWORD *)(v7 + 8);
  if ( v8 != 1 )
  {
    v21 = *(unsigned __int8 *)(v6 + 1200);
    v22 = *(unsigned __int8 *)(v6 + 1195);
    if ( v21 != 1 || (v22 & 1) == 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_ife_rdi_lcr_config",
        12320,
        "Unexpected Blob opcode %u res %u ctx_type %u shdr %u rdi_lcr %u ctx_idx: %u",
        v8,
        *a4,
        *(_DWORD *)(a1 + 9312),
        v22,
        v21,
        *(_DWORD *)(a1 + 56));
      result = 4294967274LL;
      goto LABEL_45;
    }
LABEL_27:
    v25 = a3;
    ife_csid_rdi_res_type = cam_ife_hw_mgr_get_ife_csid_rdi_res_type(*a4);
    if ( ife_csid_rdi_res_type > 2 )
    {
      switch ( ife_csid_rdi_res_type )
      {
        case 3:
          v28 = 6;
          v27 = v25;
          goto LABEL_48;
        case 4:
          v27 = v25;
          v28 = 7;
          goto LABEL_48;
        case 12:
          v32 = (unsigned int)*a4;
          v33 = *(unsigned int *)(a1 + 56);
          v34 = 12177;
LABEL_41:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_update_ife_pdaf_cfg",
            v34,
            "Invalid res_id %u, ctx_idx: %u",
            v32,
            v33);
LABEL_42:
          v30 = -22;
LABEL_43:
          v29 = "IFE param failed %u res %u ctx_type %u shdr %u rdi_lcr %u ctx_idx: %u";
          v31 = 12331;
          goto LABEL_44;
      }
    }
    else
    {
      if ( !ife_csid_rdi_res_type )
      {
        v28 = 3;
        v27 = v25;
        goto LABEL_48;
      }
      v27 = v25;
      if ( ife_csid_rdi_res_type == 1 )
      {
        v28 = 4;
        goto LABEL_48;
      }
      if ( ife_csid_rdi_res_type == 2 )
      {
        v28 = 5;
LABEL_48:
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_update_ife_pdaf_cfg",
            12190,
            "Ctx %d res: %u lcr %u id %u ctx_type %u",
            *(_DWORD *)(a1 + 56),
            v28,
            *a4,
            **(_DWORD **)(v27 + 8),
            *(_DWORD *)(a1 + 9312));
        for ( i = *(__int64 **)(a1 + 224); i != (__int64 *)(a1 + 224); i = (__int64 *)*i )
        {
          if ( *((_DWORD *)i + 4) )
          {
            if ( (v36 = i[4]) != 0
              && ((v37 = *(_DWORD *)(v36 + 4)) == 0 ? (v38 = *(_DWORD *)(a1 + 9312) == 2) : (v38 = 0), v38 || v37 == v28)
              || (v39 = i[5]) != 0
              && ((v40 = *(_DWORD *)(v39 + 4)) == 0 ? (v41 = *(_DWORD *)(a1 + 9312) == 2) : (v41 = 0), v41 || v40 == v28) )
            {
              result = cam_isp_hw_mgr_add_cmd_buf_util();
              if ( !(_DWORD)result )
                goto LABEL_45;
              v42 = *(_DWORD **)(v25 + 8);
              v30 = result;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_update_ife_pdaf_cfg",
                12218,
                "Ctx %u res: %u lcr %u id %u ctx_type %u rc %u",
                *(_DWORD *)(a1 + 56),
                v28,
                *a4,
                *v42,
                *(_DWORD *)(a1 + 9312),
                result);
              goto LABEL_43;
            }
          }
        }
        goto LABEL_42;
      }
    }
    v32 = (unsigned int)*a4;
    v33 = *(unsigned int *)(a1 + 56);
    v34 = 12184;
    goto LABEL_41;
  }
  v44 = a3;
  v9 = cam_ife_hw_mgr_get_ife_csid_rdi_res_type(*a4);
  v10 = v9;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_config_rdi_lcr_csid_init_params",
      12244,
      "Ctx: %u csid_res_id: %u rdi_lcr: %u sfe_shdr %u ctx_ctype %u",
      *(_DWORD *)(a1 + 56),
      v9,
      *a4,
      *(unsigned __int8 *)(v6 + 1195),
      *(_DWORD *)(a1 + 9312));
  v11 = *(__int64 **)(a1 + 208);
  if ( v11 == (__int64 *)(a1 + 208) )
    goto LABEL_32;
  v12 = 0;
  v13 = -22;
  while ( 1 )
  {
    if ( !*((_DWORD *)v11 + 4) )
      goto LABEL_10;
    v14 = v11[4];
    if ( !v14 )
      goto LABEL_10;
    v15 = *((_DWORD *)v11 + 5);
    if ( v15 > 2 || (*(_BYTE *)(v6 + 1195) & 1) == 0 && v15 != v10 )
      goto LABEL_10;
    v16 = *(_QWORD *)(v14 + 16);
    v17 = v11[4];
    v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v16 + 88);
    v19 = *(_QWORD *)(v16 + 112);
    if ( *((_DWORD *)v18 - 1) != -1055839300 )
      __break(0x8229u);
    v20 = v18(v19, 72, v17, 152);
    v12 |= 1LL << *(_DWORD *)(v14 + 4);
    if ( v20 )
      break;
    v13 = 0;
LABEL_10:
    v11 = (__int64 *)*v11;
    if ( v11 == (__int64 *)(a1 + 208) )
      goto LABEL_24;
  }
  v24 = v20;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_config_rdi_lcr_csid_init_params",
    12268,
    "Ctx: %u csid_res_id: %u rdi_lcr: %u sfe_shdr %u ctx_ctype %u",
    *(_DWORD *)(a1 + 56),
    v10,
    *a4,
    *(unsigned __int8 *)(v6 + 1195),
    *(_DWORD *)(a1 + 9312));
  v13 = v24;
LABEL_24:
  if ( (((unsigned __int64)v12 >> v10) & 1) == 0 )
  {
LABEL_32:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_config_rdi_lcr_csid_init_params",
      12277,
      "Ctx: %u Unacquired csid_res_id: %u rdi_lcr: %u sfe_shdr %u ctx_ctype %u",
      *(_DWORD *)(a1 + 56),
      v10,
      *a4,
      *(unsigned __int8 *)(v6 + 1195),
      *(_DWORD *)(a1 + 9312));
    v13 = -22;
    goto LABEL_33;
  }
  if ( !v13 )
  {
    a3 = v44;
    *(_BYTE *)(v6 + 1200) = 1;
    goto LABEL_27;
  }
LABEL_33:
  v29 = "CSID param failed Ctx: %d rdi_lcr: %u ctx_type: %u ctx_idx: %u";
  v30 = v13;
  v31 = 12306;
LABEL_44:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_ife_rdi_lcr_config",
    v31,
    v29);
  result = v30;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
