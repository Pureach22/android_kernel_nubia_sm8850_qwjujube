__int64 __fastcall cam_isp_blob_ubwc_update(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x26
  __int64 v4; // x8
  __int64 v5; // x23
  _DWORD *v6; // x24
  __int64 v7; // x20
  unsigned __int64 v8; // x22
  __int64 result; // x0
  int v10; // w19
  int *v11; // x21
  int v12; // w25
  unsigned int v13; // w9
  int v14; // w11
  unsigned int v15; // w5
  __int64 v16; // x9
  __int64 v17; // x10
  unsigned int *v18; // x13
  unsigned int v19; // w7
  __int64 v20; // x6
  __int64 *v21; // x9
  unsigned __int64 v22; // x14
  __int64 **v23; // x9
  __int64 v24; // x9
  __int64 v25; // x13
  __int64 v26; // x10
  __int64 v27; // x25
  const char *v28; // x5
  __int64 v29; // x4
  unsigned int v30; // w21
  __int64 v31; // x22
  char v32; // w4
  unsigned int v33; // w19
  unsigned int v35; // [xsp+14h] [xbp-1Ch]
  __int64 v36; // [xsp+18h] [xbp-18h]
  int v37; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+28h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 16);
  v37 = 0;
  if ( !v3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_ubwc_update",
      9548,
      "Invalid ctx");
LABEL_36:
    result = 4294967274LL;
    goto LABEL_37;
  }
  if ( (unsigned int)(*(_DWORD *)(a3 + 40) + 1) >= *(_DWORD *)(a3 + 24) )
  {
    v28 = "Insufficient HW entries :%d max:%d ctx_idx: %u";
    v29 = 9557;
LABEL_35:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_ubwc_update",
      v29,
      v28);
    goto LABEL_36;
  }
  if ( *a2 != 1 )
  {
    v28 = "Invalid UBWC API Version %d ctx_idx: %u";
    v29 = 9654;
    goto LABEL_35;
  }
  v4 = a1;
  v5 = a3;
  v6 = a2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_ubwc_update",
      9565,
      "ctx_idx: %u num_ports= %d",
      *(_DWORD *)(v3 + 56),
      a2[1]);
    a2 = v6;
    a3 = v5;
    v4 = a1;
    if ( v6[1] )
      goto LABEL_7;
  }
  else if ( a2[1] )
  {
LABEL_7:
    v7 = *(_QWORD *)(v4 + 16);
    v8 = 0;
    result = 0;
    v10 = 0;
    v11 = a2 + 2;
    while ( 1 )
    {
      v12 = *v11;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v35 = result;
        v36 = v4;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_blob_ubwc_update",
          9573,
          "UBWC config idx %d, port_type=%d ctx_idx: %u",
          v8,
          v12,
          *(_DWORD *)(v3 + 56));
        result = v35;
        v4 = v36;
        a2 = v6;
        a3 = v5;
      }
      if ( (unsigned __int8)v12 >= (unsigned int)max_ife_out_res )
      {
        v28 = "Invalid port type:%x, ctx_idx: %u";
        v29 = 9577;
        goto LABEL_35;
      }
      v13 = *(_DWORD *)(v7 + 20);
      v14 = *(_DWORD *)(v7 + 24);
      v15 = v13 - (v14 + v10);
      if ( v13 <= v14 + v10 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_ubwc_update",
          9591,
          "no free kmd memory for base=%d bytes_used=%u buf_size=%u ctx_idx: %u",
          **(_DWORD **)(v4 + 8),
          v37,
          v13,
          *(_DWORD *)(v3 + 56));
        result = 4294967284LL;
        goto LABEL_37;
      }
      v16 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 8496) + (unsigned __int8)v12);
      if ( v16 == 255 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_ubwc_update",
          9601,
          "Invalid index:%d for out_map",
          (unsigned __int8)v12);
        goto LABEL_36;
      }
      v17 = *(_QWORD *)(v3 + 272) + (v16 << 7);
      if ( !v17 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_ubwc_update",
          9608,
          "Invalid hw_mgr_res, ctx_idx: %u",
          *(_DWORD *)(v3 + 56));
        goto LABEL_36;
      }
      v18 = *(unsigned int **)(v4 + 8);
      v19 = v18[2];
      v20 = *v18;
      if ( v19 == 7 )
      {
        if ( (unsigned int)v20 > 2 )
          goto LABEL_51;
        v22 = (8 * v20) | 0xE0;
        v23 = (__int64 **)&g_ife_hw_mgr[v20 + 28];
      }
      else
      {
        if ( v19 != 2 )
        {
          if ( v19 )
            goto LABEL_38;
          if ( (unsigned int)v20 >= 8 )
          {
LABEL_51:
            __break(0x5512u);
LABEL_52:
            __break(1u);
            return cam_isp_blob_ubwc_update_v2(result, a2);
          }
          v21 = &g_ife_hw_mgr[v20 + 12];
          goto LABEL_28;
        }
        if ( (unsigned int)v20 > 7 )
          goto LABEL_51;
        v22 = 8 * v20 + 160;
        v23 = (__int64 **)((char *)g_ife_hw_mgr + v22);
      }
      if ( v22 > 0x13FD8 )
        goto LABEL_52;
      v21 = *v23;
LABEL_28:
      v24 = *v21;
      if ( !v24 || (v25 = v18[1], (unsigned int)v25 >= 2) )
      {
LABEL_38:
        v28 = "Invalid base %u type %u";
        v29 = 9618;
        goto LABEL_35;
      }
      v26 = *(_QWORD *)(v17 + 8 * v25 + 32);
      if ( v26 )
      {
        v27 = v4;
        result = cam_isp_add_cmd_buf_update(
                   v26,
                   v24,
                   3,
                   0x10u,
                   (const void *)(*(_QWORD *)(v7 + 8) + (v10 & 0xFFFFFFFC) + (v14 & 0xFFFFFFFC)),
                   v15,
                   (__int64)v11,
                   &v37);
        if ( (result & 0x80000000) != 0 )
        {
          v33 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_ubwc_update",
            9638,
            "Failed cmd_update, base_idx=%d, bytes_used=%u, res_id_out=0x%X ctx_idx: %u",
            **(_DWORD **)(v27 + 8),
            v37,
            *v11,
            *(_DWORD *)(v3 + 56));
          result = v33;
          goto LABEL_37;
        }
        a3 = v5;
        a2 = v6;
        v10 += v37;
        v4 = v27;
      }
      ++v8;
      v11 += 20;
      if ( v8 >= (unsigned int)a2[1] )
      {
        if ( v10 )
        {
          v30 = result;
          v31 = v4;
          v32 = *(_BYTE *)(v4 + 24) == 1
             && *(_DWORD *)(*(_QWORD *)(a3 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a3 + 40) - 1) + 12) == 2;
          cam_isp_update_hw_entry(2, a3, v7, v10, v32);
          result = v30;
          *(_BYTE *)(v31 + 24) = 1;
        }
        goto LABEL_37;
      }
    }
  }
  result = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
