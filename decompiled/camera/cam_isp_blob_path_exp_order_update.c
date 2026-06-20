__int64 __fastcall cam_isp_blob_path_exp_order_update(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x24
  char v5; // w21
  unsigned __int64 v6; // x20
  __int64 v7; // x27
  const char *v8; // x11
  unsigned int *v9; // x22
  unsigned int v10; // w7
  char v11; // w8
  int v12; // w6
  unsigned int v13; // w8
  int v14; // w8
  unsigned __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x10
  unsigned int v19; // w9
  int v20; // w7
  const char *v21; // x22
  const char *v22; // x5
  __int64 v23; // x4
  __int64 v24; // x6
  __int64 result; // x0
  int v26; // w10
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x20
  unsigned int *v29; // x21
  __int64 v30; // x9
  __int64 v31; // x10
  __int64 (__fastcall *v32)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v33; // x23
  __int64 v34; // x0
  int v35; // w0
  int v36; // w8
  unsigned int v37; // w21
  int v38; // w9
  const char *v39; // x5
  __int64 v40; // x4
  __int64 v41; // x21
  __int64 v42; // x20
  __int64 v43; // x21
  __int64 v44; // [xsp+0h] [xbp-50h]
  __int64 v45; // [xsp+8h] [xbp-48h]
  int v46; // [xsp+10h] [xbp-40h]
  __int64 v47; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+28h] [xbp-28h]
  __int64 v49; // [xsp+30h] [xbp-20h]
  __int64 v50; // [xsp+30h] [xbp-20h]
  __int64 v51; // [xsp+38h] [xbp-18h] BYREF
  __int64 v52; // [xsp+40h] [xbp-10h]
  __int64 v53; // [xsp+48h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  v51 = 0;
  v52 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v42 = a1;
    v43 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_path_exp_order_update",
      440,
      "Exp order update blob opcode:%u req_id:%llu ctx_idx:%u num_process_exp:%u num_sensor_out_exp:%u num_path_exp_info:%u",
      *(_DWORD *)(a3 + 8),
      a2,
      *(_DWORD *)(a1 + 56),
      *(_DWORD *)(a3 + 2032),
      *(_DWORD *)(a3 + 2036),
      *(_DWORD *)(a3 + 2040));
    a3 = v43;
    a1 = v42;
    if ( !*(_DWORD *)(v43 + 2040) )
      goto LABEL_64;
  }
  else if ( !*(_DWORD *)(a3 + 2040) )
  {
    goto LABEL_64;
  }
  v5 = 0;
  v6 = 0;
  v7 = a3 + 2068;
  v8 = "cam_isp_blob_path_exp_order_update";
  while ( 1 )
  {
    v9 = (unsigned int *)(v7 + 48 * v6);
    v10 = *v9;
    if ( *v9 - 9 <= 0xFFFFFFF7 )
    {
      v22 = "Invalid hw_type:%u at idx:%d for exp order update req_id:%llu ctx_idx:%u";
      v23 = 448;
      v24 = v10;
      LODWORD(v45) = *(_DWORD *)(a1 + 56);
      goto LABEL_41;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      break;
    if ( v10 != 8 )
      goto LABEL_9;
LABEL_29:
    if ( v9[3] == 1 )
    {
      v16 = *((unsigned __int8 *)v9 + 4);
      v17 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8496) + v16);
      if ( v17 == 255 )
      {
        v38 = *(_DWORD *)(a1 + 56);
        v39 = "[FRMHDR] Invalid index:%d for out_map, req_id:%llu ctx_idx:%u";
        v40 = 500;
        goto LABEL_60;
      }
      v18 = *(_QWORD *)(a1 + 272) + (v17 << 7);
      if ( !v18 || !*(_QWORD *)(v18 + 32) )
      {
        v38 = *(_DWORD *)(a1 + 56);
        v39 = "[FRMHDR] Res node or HW not acquired for res_id: 0x%x, req_id:%llu ctx_idx:%u";
        v40 = 508;
LABEL_60:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_path_exp_order_update",
          v40,
          v39,
          *((unsigned __int8 *)v9 + 4),
          a2,
          v38);
        result = 4294967274LL;
        goto LABEL_65;
      }
      v19 = v9[2];
      if ( v19 >= 4 )
      {
        LODWORD(v44) = v9[2];
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, __int64, _DWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_path_exp_order_update",
          516,
          "[FRMHDR] Invalid hw ctxt_id specified at i: %d for res_id: 0x%x, hw_ctxt_id: 0x%x, req_id:%llu ctx_idx:%u",
          (unsigned int)v6,
          *((unsigned __int8 *)v9 + 4),
          v44,
          a2,
          *(_DWORD *)(a1 + 56));
        goto LABEL_42;
      }
      *(_DWORD *)(v18 + 96) = v19;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v20 = v9[2];
        v50 = a1;
        v48 = a3;
        v21 = v8;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          v8,
          526,
          "[FRMHDR] Last ctxt for res_id: 0x%x updated to: %u, req_id:%llu ctx_idx:%u",
          v16,
          v20,
          a2,
          *(_DWORD *)(a1 + 56));
        a3 = v48;
        a1 = v50;
        v8 = v21;
      }
    }
LABEL_37:
    if ( ++v6 >= *(unsigned int *)(a3 + 2040) )
    {
      if ( (v5 & 1) != 0 )
      {
LABEL_44:
        v26 = *(_DWORD *)(a3 + 2036);
        v27 = *(unsigned int *)(a1 + 8716);
        LODWORD(v51) = *(_DWORD *)(a3 + 2032);
        HIDWORD(v51) = v26;
        if ( (_DWORD)v27 )
        {
          v28 = 0;
          v29 = (unsigned int *)(a1 + 8584);
          do
          {
            if ( v28 == 11 )
              goto LABEL_66;
            if ( !v29[2] )
            {
              v30 = *v29;
              if ( (unsigned int)v30 > 7 )
                goto LABEL_66;
              v31 = *(_QWORD *)(v4 + 96 + 8 * v30);
              if ( v31 )
              {
                v32 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v31 + 88);
                if ( v32 )
                {
                  v33 = a1;
                  v34 = *(_QWORD *)(v31 + 112);
                  if ( *((_DWORD *)v32 - 1) != -1055839300 )
                    __break(0x8229u);
                  v35 = v32(v34, 83, &v51, 16);
                  if ( v35 )
                  {
                    v36 = *v29;
                    v37 = v35;
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x2000000,
                      1,
                      "cam_isp_blob_path_exp_order_update",
                      553,
                      "Exp info update failed req_id:%d i:%d hw_idx=%d rc:%d ctx_idx: %u",
                      a2,
                      v28,
                      v36,
                      v35,
                      *(_DWORD *)(v33 + 56));
                    result = v37;
                    goto LABEL_65;
                  }
                  v27 = *(unsigned int *)(v33 + 8716);
                  a1 = v33;
                }
              }
            }
            ++v28;
            v29 += 3;
          }
          while ( v28 < v27 );
        }
      }
LABEL_64:
      result = 0;
      goto LABEL_65;
    }
LABEL_38:
    if ( v6 == 40 )
LABEL_66:
      __break(0x5512u);
  }
  v49 = a1;
  v47 = a3;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_isp_blob_path_exp_order_update",
    457,
    "Per path exp order update idx:%d hw_type:%u res_id:0x%x hw_ctxt_id:0x%x exp_order:0x%x",
    v6,
    v10,
    v9[1],
    v9[2],
    v9[3]);
  a3 = v47;
  a1 = v49;
  v8 = "cam_isp_blob_path_exp_order_update";
  v10 = *v9;
  if ( *v9 == 8 )
    goto LABEL_29;
LABEL_9:
  if ( v10 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_path_exp_order_update",
      532,
      "hw_type:%u at idx:%d not supported for exp order update req_id:%llu ctx_idx:%u",
      v10,
      v6,
      a2,
      *(_DWORD *)(a1 + 56));
    result = 4294967277LL;
    goto LABEL_65;
  }
  v11 = *(_BYTE *)(a3 + 3988);
  if ( v5 & 1 | ((v11 & 1) == 0) )
  {
    v5 |= v11;
    goto LABEL_37;
  }
  if ( v9[3] != 1 || (v12 = v9[1], (unsigned int)(v12 - 8) > 0x78) )
  {
    v5 = 0;
    goto LABEL_37;
  }
  v13 = (unsigned __int8)v9[1];
  if ( v13 > 0x1F )
  {
    switch ( v13 )
    {
      case 0x20u:
        v14 = 2;
        break;
      case 0x40u:
        v14 = 3;
        break;
      case 0x80u:
        v14 = 4;
        break;
      default:
        goto LABEL_62;
    }
LABEL_26:
    v15 = *(unsigned int *)(a3 + 2040);
    ++v6;
    v5 = 1;
    HIDWORD(v52) = v14;
    LOBYTE(v52) = 1;
    if ( v6 >= v15 )
      goto LABEL_44;
    goto LABEL_38;
  }
  if ( v13 == 8 )
  {
    v14 = 0;
    goto LABEL_26;
  }
  if ( v13 == 16 )
  {
    v14 = 1;
    goto LABEL_26;
  }
LABEL_62:
  v41 = a1;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_mgr_util_process_csid_path_res",
    4560,
    "Invalid csid path ID: 0x%x",
    v12);
  v24 = v9[1];
  v22 = "Invalid csid res_id:%u at idx:%d for exp order update req_id:%llu ctx_idx:%u";
  LODWORD(v45) = *(_DWORD *)(v41 + 56);
  v23 = 483;
LABEL_41:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, __int64, __int64, int))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_path_exp_order_update",
    v23,
    v22,
    v24,
    (unsigned int)v6,
    a2,
    v45,
    v46);
LABEL_42:
  result = 4294967274LL;
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
