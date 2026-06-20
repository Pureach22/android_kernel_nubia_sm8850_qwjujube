__int64 __fastcall _cam_isp_ctx_dump_req_info(_DWORD *a1, _QWORD *a2, _QWORD *a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v8; // x7
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x6
  unsigned __int64 v11; // x7
  __int64 result; // x0
  unsigned int v13; // w0
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 v17; // x7
  int v18; // w8
  const char *v19; // x5
  unsigned int v20; // w19
  __int64 v21; // x4
  unsigned int v22; // w0
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  _QWORD **v26; // x21
  unsigned int v27; // w0
  _QWORD *v28; // x24
  __int64 v29; // x26
  _QWORD *v30; // x25
  int v31; // w27
  __int64 v32; // x28
  const char *v33; // x0
  unsigned int v34; // w0
  char v35; // [xsp+0h] [xbp-10h]
  char v36; // [xsp+0h] [xbp-10h]
  char v37; // [xsp+0h] [xbp-10h]
  char v38; // [xsp+0h] [xbp-10h]

  if ( !a1 || !a2 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_dump_req_info",
      6268,
      "Invalid parameters %pK %pK %pK",
      a2,
      a1,
      a3);
    return 4294967274LL;
  }
  v9 = a3[2];
  v8 = a3[3];
  v10 = v9 - v8;
  if ( v9 <= v8 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_dump_req_info",
      6276,
      "Dump buffer overshoot len %zu offset %zu, ctx_idx: %u, link: 0x%x",
      a3[2],
      v8,
      a1[8],
      a1[16]);
    return 4294967268LL;
  }
  v11 = (unsigned int)(16 * *(_DWORD *)(a2[4] + 32LL) + 144);
  if ( v10 < v11 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_dump_req_info",
      6288,
      "Dump buffer exhaust remain %zu min %u, ctx_idx: %u, link: 0x%x",
      v10,
      v11,
      a1[8],
      a1[16]);
    return 4294967268LL;
  }
  v13 = cam_common_user_dump_helper(
          a3,
          (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_req_list,
          (__int64)(a1 + 36),
          8,
          "ISP_OUT_FENCE_PENDING_REQUESTS:",
          a6,
          v10,
          v11,
          v35);
  if ( v13 )
  {
    v17 = (unsigned int)a1[8];
    v18 = a1[16];
    v19 = "CAM_ISP_CONTEXT:Pending request dump failed, rc:%d, ctx:%u, link:0x%x";
    v20 = v13;
    v21 = 6298;
  }
  else
  {
    v22 = cam_common_user_dump_helper(
            a3,
            (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_req_list,
            (__int64)(a1 + 40),
            8,
            "ISP_OUT_FENCE_APPLIED_REQUESTS:",
            v14,
            v15,
            v16,
            v36);
    if ( v22 )
    {
      v17 = (unsigned int)a1[8];
      v18 = a1[16];
      v19 = "CAM_ISP_CONTEXT: Applied request dump failed, rc:%d, ctx:%u, link:0x%x";
      v20 = v22;
      v21 = 6308;
    }
    else
    {
      v26 = (_QWORD **)(a1 + 32);
      v27 = cam_common_user_dump_helper(
              a3,
              (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_req_list,
              (__int64)(a1 + 32),
              8,
              "ISP_OUT_FENCE_ACTIVE_REQUESTS:",
              v23,
              v24,
              v25,
              v37);
      if ( v27 )
      {
        v17 = (unsigned int)a1[8];
        v18 = a1[16];
        v19 = "CAM_ISP_CONTEXT: Active request dump failed, rc:%d, ctx:%u, link:0x%x";
        v20 = v27;
        v21 = 6318;
      }
      else
      {
        v28 = *v26;
        if ( *v26 == v26 )
          return 0;
        while ( 1 )
        {
          v29 = v28[4];
          v30 = (_QWORD *)*v28;
          if ( *(_DWORD *)(v29 + 32) )
            break;
LABEL_17:
          result = 0;
          v28 = v30;
          if ( v30 == v26 )
            return result;
        }
        v31 = 0;
        while ( 1 )
        {
          v32 = *(_QWORD *)(v29 + 24) + ((__int64)v31 << 6);
          v33 = _cam_isp_ife_sfe_resource_handle_id_to_type(*(_DWORD *)v32);
          v34 = cam_common_user_dump_helper(
                  a3,
                  (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_active_requests,
                  (__int64)v28,
                  8,
                  "ISP_OUT_FENCE_REQUEST_ACTIVE.%s.%u.%d:",
                  (__int64)v33,
                  *(_QWORD *)(v32 + 32),
                  *(unsigned int *)(v32 + 16),
                  v38);
          if ( v34 )
            break;
          if ( (unsigned int)++v31 >= *(_DWORD *)(v29 + 32) )
            goto LABEL_17;
        }
        v17 = (unsigned int)a1[8];
        v18 = a1[16];
        v19 = "CAM_ISP_CONTEXT DUMP_REQ_INFO: Dump failed, rc: %d, ctx_idx: %u, link: 0x%x";
        v20 = v34;
        v21 = 6339;
      }
    }
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
    3,
    8,
    1,
    "__cam_isp_ctx_dump_req_info",
    v21,
    v19,
    v20,
    v17,
    v18);
  return v20;
}
