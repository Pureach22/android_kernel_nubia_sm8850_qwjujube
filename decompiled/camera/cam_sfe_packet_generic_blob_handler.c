__int64 __fastcall cam_sfe_packet_generic_blob_handler(
        unsigned int **a1,
        unsigned int a2,
        unsigned int a3,
        _DWORD *src)
{
  unsigned int v5; // w8
  unsigned int *v7; // x21
  unsigned int v8; // w9
  __int64 v9; // x19
  __int64 result; // x0
  __int64 v11; // x10
  __int64 v12; // x6
  const char *v13; // x5
  unsigned int v14; // w19
  __int64 v15; // x4
  const char *v16; // x5
  __int64 v17; // x4
  __int64 v18; // x6
  __int64 v19; // x7
  const char *v20; // x5
  unsigned int v21; // w19
  __int64 v22; // x4
  __int64 v23; // x7
  const char *v24; // x5
  __int64 v25; // x4
  int v26; // w9
  const char *v27; // x5
  __int64 v28; // x4
  __int64 v29; // x6
  unsigned __int64 v30; // x7
  __int64 v31; // x6
  __int64 v32; // x6
  unsigned __int64 v33; // x9
  int v34; // w10
  __int64 v35; // x4
  __int64 v36; // x6
  __int64 v37; // x7
  size_t v38; // x2
  __int64 v39; // x19
  unsigned int v40; // w0
  __int64 v41; // x6
  int v42; // [xsp+0h] [xbp-20h]

  v5 = a3;
  if ( !a1 || !a3 || !src )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_sfe_packet_generic_blob_handler",
      14074,
      "Invalid args data %pK size %d info %pK",
      src,
      a3,
      a1);
    return 4294967274LL;
  }
  v7 = *a1;
  v8 = a2;
  if ( !*a1 || (v9 = *((_QWORD *)v7 + 2)) == 0 )
  {
    v16 = "Failed. prepare is NULL, blob_type %d";
    v17 = 14081;
    v18 = a2;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_sfe_packet_generic_blob_handler",
      v17,
      v16,
      v18);
    return 4294967274LL;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_sfe_packet_generic_blob_handler",
      14087,
      "Context[%pK][%u] blob_type: %d, blob_size: %d",
      (const void *)v9,
      *(_DWORD *)(v9 + 56),
      a2,
      a3);
    v8 = a2;
    v5 = a3;
    if ( a2 > 0x25 )
    {
LABEL_88:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_sfe_packet_generic_blob_handler",
        14496,
        "Invalid blob type: %u, ctx_idx: %u",
        v8,
        *(_DWORD *)(v9 + 56));
      return 0;
    }
  }
  result = 0;
  switch ( v8 )
  {
    case 0u:
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
    case 8u:
    case 9u:
    case 0xAu:
    case 0xCu:
    case 0xDu:
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x1Cu:
    case 0x1Du:
    case 0x20u:
    case 0x21u:
    case 0x22u:
    case 0x23u:
    case 0x24u:
    case 0x25u:
      return result;
    case 0xFu:
      if ( v5 < 0xC )
      {
        v26 = *(_DWORD *)(v9 + 56);
        v27 = "Invalid blob size %u expected %lu ctx_idx: %u";
        v28 = 14306;
        v29 = v5;
        v30 = 12;
        goto LABEL_74;
      }
      if ( *(_BYTE *)(v9 + 9387) != 1 )
        return 0;
      v11 = *((_QWORD *)v7 + 40);
      *(_DWORD *)(*(_QWORD *)(v9 + 9360) + 8LL) = src[1];
      *(_DWORD *)(v11 + 4284) = src[1];
      result = cam_isp_blob_sfe_update_fetch_core_cfg(a1, v7);
      if ( (_DWORD)result )
      {
        v12 = *(unsigned int *)(v9 + 56);
        v13 = "SFE dynamic enable/disable for fetch failed, ctx_idx: %u";
        v14 = result;
        v15 = 14323;
        goto LABEL_84;
      }
      return result;
    case 0x10u:
      if ( v5 <= 0x2F )
      {
        v26 = *(_DWORD *)(v9 + 56);
        v27 = "Invalid blob size %u ctx_idx: %u";
        v28 = 14401;
        v29 = v5;
        v30 = 48;
        goto LABEL_74;
      }
      result = cam_isp_validate_bw_limiter_blob(v5, src);
      if ( (_DWORD)result )
        return result;
      result = cam_isp_blob_bw_limit_update(a1, src, v7, 7);
      if ( !(_DWORD)result )
        return result;
      v19 = *(unsigned int *)(v9 + 56);
      v20 = "BW limit update failed for SFE rc: %d, ctx_idx: %u";
      v21 = result;
      v22 = 14418;
      goto LABEL_78;
    case 0x14u:
      if ( *(_DWORD *)(*((_QWORD *)v7 + 40) + 8LL) == 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          2,
          "cam_sfe_packet_generic_blob_handler",
          14429,
          "Detected SFE FCG blob in INIT packet, ignore it");
        return 0;
      }
      if ( (byte_3A85A1 & 1) == 0 )
      {
        v18 = *(unsigned int *)(v9 + 56);
        v16 = "FCG is not supported by SFE hardware, ctx_idx: %u";
        v17 = 14435;
        goto LABEL_15;
      }
      if ( v5 <= 0x87 )
      {
        v26 = *(_DWORD *)(v9 + 56);
        v27 = "Invalid blob size %u, fcg config size: %u, ctx_idx: %u";
        v28 = 14444;
        v29 = v5;
        v30 = 136;
        goto LABEL_74;
      }
      v40 = cam_isp_validate_fcg_configs(src, (unsigned int)dword_3A8594, (unsigned int)dword_3A859C, v9);
      if ( v40 )
      {
        v12 = *(unsigned int *)(v9 + 56);
        v13 = "Failed in validating FCG configs, ctx_idx: %u";
        v14 = v40;
        v15 = 14457;
        goto LABEL_84;
      }
      result = cam_isp_blob_fcg_config_prepare(src, v7, 7);
      if ( !(_DWORD)result )
        return result;
      v19 = *(unsigned int *)(v9 + 56);
      v20 = "FCG configuration preparation failed, rc: %d, ctx_idx: %d";
      v22 = 14466;
      v21 = result;
      v41 = (unsigned int)result;
      goto LABEL_79;
    case 0x15u:
      if ( v5 <= 0x1F )
      {
        v23 = *(unsigned int *)(v9 + 56);
        v24 = "Invalid blob size %u, ctx_idx: %u";
        v25 = 14097;
        goto LABEL_39;
      }
      v31 = (unsigned int)src[1];
      if ( (unsigned int)(v31 - 6) <= 0xFFFFFFFA )
      {
        v23 = *(unsigned int *)(v9 + 56);
        v24 = "Invalid num_rdi %u in clock config, ctx_idx: %u";
        v25 = 14106;
        goto LABEL_66;
      }
      v38 = 8LL * (unsigned int)(v31 - 1) + 32;
      if ( v38 > v5 )
      {
        v34 = *(_DWORD *)(v9 + 56);
        v37 = 8 * v31 + 24;
        v35 = 14129;
        v36 = v5;
        goto LABEL_60;
      }
      v39 = *((_QWORD *)v7 + 40);
      memcpy((void *)(v39 + 1880), src, v38);
      *(_BYTE *)(v39 + 1944) = 1;
      return 0;
    case 0x16u:
      if ( v5 >= 0x28 )
        return cam_isp_blob_sfe_core_cfg_update(src, v7);
      v26 = *(_DWORD *)(v9 + 56);
      v27 = "Invalid blob size: %u expected: %u ctx_idx: %u";
      v28 = 14254;
      v29 = v5;
      v30 = 40;
      goto LABEL_74;
    case 0x17u:
      if ( v5 <= 0x37 )
      {
        v26 = *(_DWORD *)(v9 + 56);
        v27 = "Invalid blob size %u ctx_idx: %u";
        v28 = 14149;
        v29 = v5;
        v30 = 56;
        goto LABEL_74;
      }
      v32 = (unsigned int)*src;
      if ( (int)v32 - 1 >= (unsigned int)max_sfe_out_res )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_sfe_packet_generic_blob_handler",
          14161,
          "Invalid num_ports:%u in sfe out config, ctx_idx: %u",
          v32,
          (unsigned int)max_sfe_out_res,
          *(_DWORD *)(v9 + 56));
        return 4294967274LL;
      }
      v33 = 48LL * (unsigned int)(v32 - 1) + 56;
      if ( v33 > v5 )
      {
        v34 = *(_DWORD *)(v9 + 56);
        v35 = 14185;
        v36 = v5;
        v37 = v33;
LABEL_60:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
          3,
          8,
          1,
          "cam_sfe_packet_generic_blob_handler",
          v35,
          "Invalid blob size %u expected %lu ctx_idx: %u",
          v36,
          v37,
          v34);
        return 4294967274LL;
      }
      result = cam_isp_blob_vfe_out_update(23, a1, src, v7, (unsigned int)max_sfe_out_res, 7);
      if ( !(_DWORD)result )
        return result;
      v19 = *(unsigned int *)(v9 + 56);
      v20 = "SFE out update failed rc: %d, ctx_idx: %u";
      v21 = result;
      v22 = 14194;
      goto LABEL_78;
    case 0x18u:
      if ( v5 <= 0x1F )
      {
        v23 = *(unsigned int *)(v9 + 56);
        v24 = "Invalid blob size %u, ctx_idx: %u";
        v25 = 14202;
        goto LABEL_39;
      }
      v31 = (unsigned int)*src;
      if ( (int)v31 - 1 >= (unsigned int)max_sfe_out_res )
      {
        v23 = *(unsigned int *)(v9 + 56);
        v24 = "Invalid num_ports %u in HFR config, ctx_idx: %u";
        v25 = 14211;
        goto LABEL_66;
      }
      v30 = 24LL * (unsigned int)(v31 - 1) + 32;
      if ( v30 > v5 )
      {
        v26 = *(_DWORD *)(v9 + 56);
        v27 = "Invalid blob size %u expected %lu, ctx_idx: %u";
        v28 = 14237;
        goto LABEL_73;
      }
      result = cam_isp_blob_hfr_update(24, a1, src, v7);
      if ( !(_DWORD)result )
        return result;
      v12 = *(unsigned int *)(v9 + 56);
      v13 = "HFR Update Failed, ctx_idx: %u";
      v14 = result;
      v15 = 14245;
      goto LABEL_84;
    case 0x19u:
      if ( v5 < 0x40 )
      {
        v26 = *(_DWORD *)(v9 + 56);
        v27 = "Invalid blob size %u expected %lu ctx_idx: %u";
        v28 = 14286;
        v29 = v5;
        v30 = 64;
        goto LABEL_74;
      }
      result = cam_isp_blob_fe_update(src, v7);
      if ( (_DWORD)result )
      {
        v19 = *(unsigned int *)(v9 + 56);
        v20 = "FS Update Failed rc: %d, ctx_idx: %u";
        v21 = result;
        v22 = 14296;
LABEL_78:
        v41 = v21;
LABEL_79:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_sfe_packet_generic_blob_handler",
          v22,
          v20,
          v41,
          v19);
        return v21;
      }
      return result;
    case 0x1Au:
      result = cam_isp_validate_scratch_buffer_blob(v5, v9, src);
      if ( (_DWORD)result )
        return result;
      result = cam_isp_blob_sfe_scratch_buf_update(src, v7);
      if ( !(_DWORD)result )
        return result;
      v19 = *(unsigned int *)(v9 + 56);
      v20 = "SFE scratch buffer update failed rc: %d ctx_idx: %u";
      v21 = result;
      v22 = 14278;
      goto LABEL_78;
    case 0x1Bu:
      if ( (*(_BYTE *)(v9 + 9387) & 1) == 0 )
      {
        v23 = *(unsigned int *)(v9 + 56);
        v24 = "Blob %u supported only for sHDR streams,  ctx_idx: %u";
        v25 = 14333;
        v31 = 27;
LABEL_66:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
          3,
          8,
          1,
          "cam_sfe_packet_generic_blob_handler",
          v25,
          v24,
          v31,
          v23,
          v42);
        return 4294967274LL;
      }
      if ( v5 <= 0x1F )
      {
        v23 = *(unsigned int *)(v9 + 56);
        v24 = "Invalid blob size %u, ctx_idx: %u";
        v25 = 14340;
LABEL_39:
        v31 = v5;
        goto LABEL_66;
      }
      v31 = (unsigned int)*src;
      if ( (unsigned int)(v31 - 4) <= 0xFFFFFFFC )
      {
        v23 = *(unsigned int *)(v9 + 56);
        v24 = "Invalid num_ports %u in exp order config, ctx_idx: %u";
        v25 = 14351;
        goto LABEL_66;
      }
      v30 = 24LL * (unsigned int)(v31 - 1) + 32;
      if ( v30 > v5 )
      {
        v26 = *(_DWORD *)(v9 + 56);
        v27 = "Invalid blob size: %u expected: %lu ctx_idx: %u";
        v28 = 14382;
LABEL_73:
        v29 = v5;
LABEL_74:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, int))cam_print_log)(
          3,
          8,
          1,
          "cam_sfe_packet_generic_blob_handler",
          v28,
          v27,
          v29,
          v30,
          v26);
        return 4294967274LL;
      }
      result = cam_isp_blob_sfe_exp_order_update(*a1[1], src, v7);
      if ( (_DWORD)result )
      {
        v12 = *(unsigned int *)(v9 + 56);
        v13 = "SFE exp order update failed, ctx_idx: %u";
        v14 = result;
        v15 = 14390;
LABEL_84:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_sfe_packet_generic_blob_handler",
          v15,
          v13,
          v12);
        return v14;
      }
      return result;
    default:
      goto LABEL_88;
  }
}
