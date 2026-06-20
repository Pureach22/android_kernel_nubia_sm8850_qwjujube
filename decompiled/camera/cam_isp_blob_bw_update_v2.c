__int64 __fastcall cam_isp_blob_bw_update_v2(int *a1, __int64 a2)
{
  void *v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  unsigned __int64 v7; // x8
  int v8; // w9
  int v9; // w10
  unsigned __int64 v10; // x24
  _DWORD *v11; // x27
  __int64 v12; // x23
  const char *v13; // x0
  _QWORD *v14; // x21
  __int64 result; // x0
  __int64 v16; // x10
  _DWORD *v17; // x8
  __int64 v18; // x0
  unsigned int v19; // w25
  __int64 v20; // x10
  _DWORD *v21; // x8
  __int64 v22; // x0
  unsigned int v23; // w25
  char v24; // w9
  _BOOL4 v25; // w21
  _QWORD *v26; // x22
  __int64 v27; // x10
  _DWORD *v28; // x8
  __int64 v29; // x0
  unsigned int v30; // w26
  __int64 v31; // x10
  _DWORD *v32; // x8
  __int64 v33; // x0
  unsigned int v34; // w26
  const char *v35; // [xsp+38h] [xbp-508h]
  const char *v36; // [xsp+40h] [xbp-500h]
  const char *v37; // [xsp+48h] [xbp-4F8h]
  int v38; // [xsp+50h] [xbp-4F0h]
  int v39; // [xsp+54h] [xbp-4ECh]
  _BYTE v40[4]; // [xsp+58h] [xbp-4E8h] BYREF
  _BYTE v41[4]; // [xsp+5Ch] [xbp-4E4h] BYREF
  _QWORD v42[77]; // [xsp+60h] [xbp-4E0h] BYREF
  _QWORD s[79]; // [xsp+2C8h] [xbp-278h] BYREF

  s[77] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x268u);
  v4 = memset(v42, 0, sizeof(v42));
  v7 = (unsigned int)a1[1];
  v41[0] = 0;
  v40[0] = 0;
  if ( !(_DWORD)v7 )
  {
LABEL_8:
    v14 = *(_QWORD **)(a2 + 224);
    if ( v14 != (_QWORD *)(a2 + 224) )
    {
      result = 4294967274LL;
      while ( 1 )
      {
        if ( !v14[4] )
          goto LABEL_24;
        memset(&s[1], 0, 0x260u);
        result = cam_isp_classify_vote_info(v14, a1, &s[1], 2, 0, v41, v40, 0);
        if ( (_DWORD)result )
          goto LABEL_63;
        if ( !LODWORD(s[1]) )
          goto LABEL_23;
        v16 = *(_QWORD *)(v14[4] + 16LL);
        if ( !v16 )
          break;
        v17 = *(_DWORD **)(v16 + 88);
        if ( !v17 )
          break;
        v18 = *(_QWORD *)(v16 + 112);
        s[0] = v14[4];
        if ( *(v17 - 1) != -1055839300 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v17)(v18, 11, s, 616);
        if ( (_DWORD)result )
        {
          v19 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            1,
            "cam_isp_blob_bw_update_v2",
            7458,
            "BW Update failed rc: %d, ctx_idx: %u",
            result,
            *(_DWORD *)(a2 + 56));
          result = v19;
        }
LABEL_24:
        if ( v14[5] )
        {
          memset(&s[1], 0, 0x260u);
          result = cam_isp_classify_vote_info(v14, a1, &s[1], 2, 1, v41, v40, 0);
          if ( (_DWORD)result )
            goto LABEL_63;
          if ( LODWORD(s[1]) )
          {
            v20 = *(_QWORD *)(v14[5] + 16LL);
            if ( v20 )
            {
              v21 = *(_DWORD **)(v20 + 88);
              if ( v21 )
              {
                v22 = *(_QWORD *)(v20 + 112);
                s[0] = v14[5];
                if ( *(v21 - 1) != -1055839300 )
                  __break(0x8228u);
                result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v21)(v22, 11, s, 616);
                if ( (_DWORD)result )
                {
                  v23 = result;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x2000000,
                    1,
                    "cam_isp_blob_bw_update_v2",
                    7458,
                    "BW Update failed rc: %d, ctx_idx: %u",
                    result,
                    *(_DWORD *)(a2 + 56));
                  result = v23;
                }
                goto LABEL_12;
              }
            }
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              2,
              "cam_isp_blob_bw_update_v2",
              7460,
              "NULL hw_intf!, ctx_idx: %u",
              *(_DWORD *)(a2 + 56));
          }
          result = 0;
        }
LABEL_12:
        v14 = (_QWORD *)*v14;
        if ( v14 == (_QWORD *)(a2 + 224) )
          goto LABEL_34;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_isp_blob_bw_update_v2",
        7460,
        "NULL hw_intf!, ctx_idx: %u",
        *(_DWORD *)(a2 + 56));
LABEL_23:
      result = 0;
      goto LABEL_24;
    }
    result = 4294967274LL;
LABEL_34:
    v41[0] = 0;
    v24 = *(_BYTE *)(a2 + 9388);
    v40[0] = 0;
    v25 = (v24 & 1) != 0 || *(_BYTE *)(a2 + 9387) == 1;
    v26 = *(_QWORD **)(a2 + 240);
    if ( v26 == (_QWORD *)(a2 + 240) )
    {
LABEL_63:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    while ( 1 )
    {
      if ( !v26[4] )
        goto LABEL_54;
      memset(&v42[1], 0, 0x260u);
      result = cam_isp_classify_vote_info(v26, a1, &v42[1], 7, 0, v41, v40, v25);
      if ( (_DWORD)result )
        goto LABEL_63;
      if ( !LODWORD(v42[1]) )
        goto LABEL_53;
      v27 = *(_QWORD *)(v26[4] + 16LL);
      if ( !v27 )
        break;
      v28 = *(_DWORD **)(v27 + 88);
      if ( !v28 )
        break;
      v29 = *(_QWORD *)(v27 + 112);
      v42[0] = v26[4];
      if ( *(v28 - 1) != -1055839300 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v28)(v29, 11, v42, 616);
      if ( (_DWORD)result )
      {
        v30 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          1,
          "cam_isp_blob_bw_update_v2",
          7506,
          "BW Update failed rc: %d, ctx_idx: %u",
          result,
          *(_DWORD *)(a2 + 56));
        result = v30;
      }
LABEL_54:
      if ( v26[5] )
      {
        memset(&v42[1], 0, 0x260u);
        result = cam_isp_classify_vote_info(v26, a1, &v42[1], 7, 1, v41, v40, v25);
        if ( (_DWORD)result )
          goto LABEL_63;
        if ( LODWORD(v42[1]) )
        {
          v31 = *(_QWORD *)(v26[5] + 16LL);
          if ( v31 )
          {
            v32 = *(_DWORD **)(v31 + 88);
            if ( v32 )
            {
              v33 = *(_QWORD *)(v31 + 112);
              v42[0] = v26[5];
              if ( *(v32 - 1) != -1055839300 )
                __break(0x8228u);
              result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v32)(v33, 11, v42, 616);
              if ( (_DWORD)result )
              {
                v34 = result;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x2000000,
                  1,
                  "cam_isp_blob_bw_update_v2",
                  7506,
                  "BW Update failed rc: %d, ctx_idx: %u",
                  result,
                  *(_DWORD *)(a2 + 56));
                result = v34;
              }
              goto LABEL_42;
            }
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "cam_isp_blob_bw_update_v2",
            7508,
            "NULL hw_intf!, ctx_idx: %u",
            *(_DWORD *)(a2 + 56));
        }
        result = 0;
      }
LABEL_42:
      v26 = (_QWORD *)*v26;
      if ( v26 == (_QWORD *)(a2 + 240) )
        goto LABEL_63;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_isp_blob_bw_update_v2",
      7508,
      "NULL hw_intf!, ctx_idx: %u",
      *(_DWORD *)(a2 + 56));
LABEL_53:
    result = 0;
    goto LABEL_54;
  }
  v8 = debug_mdl;
  v9 = debug_priority;
  v10 = 0;
  v11 = a1 + 5;
  while ( 1 )
  {
    v12 = v8 & 0x2000008;
    if ( (v8 & 0x2000008) == 0 || v9 )
      goto LABEL_3;
    if ( v10 >= 0x28 )
      break;
    v38 = *(_DWORD *)(a2 + 56);
    v39 = *a1;
    v37 = (const char *)cam_isp_util_usage_data_to_string((unsigned int)*(v11 - 3));
    v36 = cam_cpas_axi_util_path_type_to_string(*(v11 - 1));
    v35 = cam_cpas_axi_util_trans_type_to_string(*(v11 - 2));
    v13 = cam_cpas_axi_util_drv_vote_lvl_to_string(*v11);
    v4 = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   v12,
                   4,
                   "cam_isp_blob_bw_update_v2",
                   7419,
                   "ctx_idx: %u ISP_BLOB usage_type=%u [%s] [%s] [%s] [%s] [%llu] [%llu] [%llu]",
                   v38,
                   v39,
                   v37,
                   v36,
                   v35,
                   v13,
                   *(_QWORD *)(v11 + 1),
                   *(_QWORD *)(v11 + 3),
                   *(_QWORD *)(v11 + 5));
    v8 = debug_mdl;
    v9 = debug_priority;
    v7 = (unsigned int)a1[1];
LABEL_3:
    ++v10;
    v11 += 10;
    if ( v10 >= v7 )
      goto LABEL_8;
  }
  __break(0x5512u);
  return cam_ife_mgr_print_blob_info(v4, v5, v6);
}
