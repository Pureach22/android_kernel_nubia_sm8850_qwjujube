__int64 __fastcall cam_isp_blob_frameheader_cfg(__int64 a1, __int64 a2)
{
  __int64 v3; // x27
  unsigned __int64 v5; // x23
  int *v6; // x28
  unsigned int v7; // w25
  __int64 v8; // x4
  const char *v9; // x5
  __int64 result; // x0
  unsigned int v11; // w6
  unsigned int v12; // w8
  __int64 v13; // x21
  __int64 v14; // x9
  __int64 v15; // x7
  __int64 v16; // x0
  __int64 v17; // x5
  __int64 v18; // x25
  int v19; // w8
  __int64 v20; // x1
  unsigned int v21; // w26
  unsigned int v22; // w0
  unsigned int cpu_buf; // w0
  __int64 v24; // x8
  __int64 v25; // x10
  const void *v26; // x9
  __int64 v27; // x11
  const void *v28; // x10
  __int64 v29; // x0
  const char *v30; // x5
  __int64 v31; // x4
  __int64 v32; // x9
  __int64 v33; // x8
  __int64 v34; // x10
  __int64 i; // x9
  __int64 v36; // x12
  int v37; // w11
  __int64 v38; // [xsp+10h] [xbp-40h]
  unsigned __int64 v39; // [xsp+18h] [xbp-38h]
  unsigned __int64 v40; // [xsp+20h] [xbp-30h]
  unsigned int v41; // [xsp+28h] [xbp-28h]
  unsigned __int64 v42; // [xsp+30h] [xbp-20h] BYREF
  __int64 v43; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v44[2]; // [xsp+40h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 16);
  if ( (byte_3A85D4 & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&cam_isp_blob_frameheader_cfg__rs, "cam_isp_blob_frameheader_cfg") )
      v29 = 3;
    else
      v29 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v29,
      8,
      2,
      "cam_isp_blob_frameheader_cfg",
      12059,
      "[FRMHDR] No support for using frameheader in verifying buf done, req_id: %llu, ctx_idx:%u",
      *(_QWORD *)(*(_QWORD *)a2 + 8LL),
      *(_DWORD *)(v3 + 56));
    result = 0;
    goto LABEL_61;
  }
  if ( (unsigned int)(*(_DWORD *)(a2 + 40) + 1) >= *(_DWORD *)(a2 + 24) )
  {
    v30 = "[FRMHDR] Insufficient HW entries: %d max: %d req_id: %llu, ctx_idx: %u";
    v31 = 12069;
LABEL_59:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_frameheader_cfg",
      v31,
      v30);
LABEL_60:
    result = 4294967274LL;
    goto LABEL_61;
  }
  if ( !*(_DWORD *)(a1 + 4) )
  {
LABEL_32:
    result = 0;
LABEL_33:
    v32 = *(unsigned int *)(v3 + 8512);
    if ( (_DWORD)v32 )
      goto LABEL_42;
    goto LABEL_61;
  }
  v5 = 0;
  v6 = (int *)(a1 + 40);
  while ( 1 )
  {
    v11 = v6[2];
    if ( v11 >= 0x6000 && v11 <= max_sfe_out_res + 24576 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_frameheader_cfg",
        12082,
        "[FRMHDR] SFE resource does not support using frameheader in verifying buf done 0x%x, req_id: %llu, ctx_idx:%u",
        v11,
        *(_QWORD *)(*(_QWORD *)a2 + 8LL),
        *(_DWORD *)(v3 + 56));
      goto LABEL_41;
    }
    v12 = v6[3];
    v13 = (unsigned __int8)v6[2];
    if ( v12 - 5 <= 0xFFFFFFFB )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _DWORD, __int64, unsigned __int64, unsigned __int64, unsigned int))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_frameheader_cfg",
        12092,
        "[FRMHDR] Invalid hw ctxt id: 0x%x in frameheader config for res id: %u, req_id: %llu, ctx_idx: %u",
        v12,
        (unsigned __int8)v6[2],
        *(_QWORD *)(*(_QWORD *)a2 + 8LL),
        *(_DWORD *)(v3 + 56),
        v38,
        v39,
        v40,
        v41);
      goto LABEL_41;
    }
    v14 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 8496) + v13);
    v15 = __clz(__rbit32(v12));
    if ( v14 == 255 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _QWORD, _DWORD, __int64, unsigned __int64, unsigned __int64, unsigned int))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_frameheader_cfg",
        12103,
        "[FRMHDR] Invalid index for res_id: %u, ctxt_id: %d, req_id: %llu, ctx_idx: %u",
        (unsigned __int8)v6[2],
        v15,
        *(_QWORD *)(*(_QWORD *)a2 + 8LL),
        *(_DWORD *)(v3 + 56),
        v38,
        v39,
        v40,
        v41);
      goto LABEL_41;
    }
    v16 = (unsigned int)*v6;
    v17 = *(_QWORD *)(a2 + 328);
    v18 = *(_QWORD *)(v3 + 272) + (v14 << 7);
    v19 = *(unsigned __int8 *)(v18 + 121);
    v20 = *(unsigned int *)(*(_QWORD *)(v3 + 72) + 64LL);
    v43 = 0;
    v44[0] = 0;
    v42 = 0;
    if ( v19 )
      v21 = v15;
    else
      v21 = 0;
    v22 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, unsigned __int64 *, _QWORD, __int64))cam_mem_get_io_buf)(
            v16,
            v20,
            v44,
            &v42,
            0,
            v17);
    if ( v22 || !v44[0] || !v42 )
    {
      v7 = v22;
      v41 = v22;
      v8 = 11991;
      v9 = "[FRMHDR] Error getting iova for buf_handle: 0x%x for res_id: 0x%x, req_id: %llu, ctx_idx:%u, ctxt_id: %u, iov"
           "a: %pK, len: %d, rc: %d";
      v39 = v44[0];
      v40 = v42;
      LODWORD(v38) = v21;
      goto LABEL_6;
    }
    cpu_buf = cam_mem_get_cpu_buf(*v6, &v43, &v42);
    v24 = v43;
    if ( cpu_buf || !v43 || !v42 )
    {
      v7 = cpu_buf;
      LODWORD(v40) = cpu_buf;
      v38 = v43;
      v39 = v42;
      v8 = 12000;
      v9 = "[FRMHDR] Error getting cpu va for buf_handle: 0x%x, for res_id: 0x%x, req_id: %llu, ctx_idx:%u, ctxt_id: %u, "
           "cpuva: %pK, len: %d, rc: %d";
LABEL_6:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_process_frameheader_blob_util",
        v8,
        v9);
      result = v7;
      if ( v7 )
        goto LABEL_33;
      goto LABEL_7;
    }
    v25 = (unsigned int)v6[1];
    if ( v42 < (unsigned int)(v25 + 64) )
    {
      LODWORD(v38) = *v6;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _DWORD, __int64, unsigned __int64, unsigned __int64, unsigned int))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_process_frameheader_blob_util",
        12009,
        "[FRMHDR] Buffer offset for res_id: 0x%x, ctxt_id: %u req_id: %llu, ctx_idx:%u exceeds size of buffer allocated w"
        "ith buf_handle: 0x%x: %u",
        (unsigned int)v13,
        v21,
        *(_QWORD *)(*(_QWORD *)a2 + 8LL),
        *(_DWORD *)(v3 + 56),
        v38,
        v42,
        v40,
        v41);
      goto LABEL_40;
    }
    v26 = (const void *)(v44[0] + v25);
    if ( LOBYTE(v44[0]) + (_BYTE)v25 )
      break;
    v27 = v18 + 8LL * v21;
    *(_QWORD *)(v27 + 72) = v26;
    v28 = (const void *)(v24 + (v6[1] & 0xFFFFFFFC));
    *(_QWORD *)(v27 + 48) = v28;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_process_frameheader_blob_util",
        12036,
        "[FRMHDR] buf for res_id: %u, ctx: %u, req_id: %llu, ctx_idx:%u, iova: %pK, cpu_addr: %pK",
        v13,
        v21,
        *(_QWORD *)(*(_QWORD *)a2 + 8LL),
        *(_DWORD *)(v3 + 56),
        v26,
        v28);
LABEL_7:
    ++v5;
    v6 += 12;
    if ( v5 >= *(unsigned int *)(a1 + 4) )
      goto LABEL_32;
  }
  LODWORD(v38) = v6[1];
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _DWORD, __int64, unsigned __int64, unsigned __int64, unsigned int))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_process_frameheader_blob_util",
    12021,
    "[FRMHDR] Buffer offset for res_id: 0x%x, ctxt_id: %u req_id: %llu, ctx_idx:%u not aligned with 256 bytes: offset: 0x%x",
    (unsigned int)v13,
    v21,
    *(_QWORD *)(*(_QWORD *)a2 + 8LL),
    *(_DWORD *)(v3 + 56),
    v38,
    v39,
    v40,
    v41);
LABEL_40:
  cam_mem_put_cpu_buf(*v6);
LABEL_41:
  result = 4294967274LL;
  v32 = *(unsigned int *)(v3 + 8512);
  if ( (_DWORD)v32 )
  {
LABEL_42:
    v33 = *(_QWORD *)(v3 + 272);
    v34 = v32 << 7;
    for ( i = 0; v34 != i; i += 128 )
    {
      v36 = v33 + i;
      if ( *(_BYTE *)(v33 + i + 121) == 1 )
      {
        v37 = *(_DWORD *)(v36 + 112);
        if ( (v37 & 1) != 0 && (!*(_QWORD *)(v36 + 48) || !*(_QWORD *)(v36 + 72))
          || (v37 & 2) != 0 && (!*(_QWORD *)(v33 + i + 56) || !*(_QWORD *)(v33 + i + 80))
          || (v37 & 4) != 0 && (!*(_QWORD *)(v33 + i + 64) || !*(_QWORD *)(v33 + i + 88)) )
        {
          v30 = "[FRMHDR] Buffer not configured for res_id: %u, ctxt_id %u, is_mc: %s, req_id: %llu, ctx_idx: %u";
          v31 = 12145;
          goto LABEL_59;
        }
      }
      else if ( !*(_QWORD *)(v36 + 48) || !*(_QWORD *)(v33 + i + 72) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_frameheader_cfg",
          12131,
          "[FRMHDR] Buffer not configured for res_id: %u, ctxt_id 0, is_mc: %s, req_id: %llu, ctx_idx: %u",
          *(unsigned __int8 *)(v33 + i + 20),
          "N",
          *(_QWORD *)(*(_QWORD *)a2 + 8LL),
          *(_DWORD *)(v3 + 56));
        goto LABEL_60;
      }
    }
  }
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
