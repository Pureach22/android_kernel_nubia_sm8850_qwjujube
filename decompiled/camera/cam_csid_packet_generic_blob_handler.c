__int64 __fastcall cam_csid_packet_generic_blob_handler(_QWORD *a1, int a2, unsigned int a3, int *a4)
{
  unsigned int v5; // w10
  _QWORD *v6; // x8
  __int64 v8; // x1
  _DWORD *v9; // x20
  __int64 result; // x0
  int v11; // w8
  const char *v12; // x5
  __int64 v13; // x4
  __int64 v14; // x6
  unsigned __int64 v15; // x7
  __int64 v16; // x6
  const char *v17; // x5
  unsigned int v18; // w19
  __int64 v19; // x4
  int v20; // w6
  int v21; // w7
  unsigned int v22; // w19
  __int64 v23; // x9
  int v24; // [xsp+0h] [xbp-30h]
  int v25; // [xsp+14h] [xbp-1Ch]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v5 = a3;
  v6 = a1;
  if ( !a1 || !a3 || !a4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_csid_packet_generic_blob_handler",
      13933,
      "Invalid args data %pK size %d info %pK",
      a4,
      a3,
      a1);
    return 4294967274LL;
  }
  v8 = *a1;
  if ( !*a1 || (v9 = *(_DWORD **)(v8 + 16)) == nullptr )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_csid_packet_generic_blob_handler",
      13940,
      "Failed. prepare is NULL, blob_type %d",
      a2);
    return 4294967274LL;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v28 = *a1;
    v25 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_csid_packet_generic_blob_handler",
      13946,
      "Context[%pK][%u] blob_type=%d, blob_size=%d",
      v9,
      v9[14],
      a2,
      a3);
    a2 = v25;
    v8 = v28;
    v6 = a1;
    v5 = a3;
  }
  result = 0;
  if ( a2 > 15 )
  {
    if ( (unsigned int)a2 <= 0x25 )
    {
      if ( ((1LL << a2) & 0x1F3FFF0000LL) != 0 )
        return result;
      if ( a2 == 31 )
      {
        if ( v5 < 0x20 )
        {
          v12 = "Invalid IPP IRQ comp cfg blob size, %u, expected %u";
          v13 = 13988;
          v14 = v5;
          v15 = 32;
LABEL_37:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, int))cam_print_log)(
            3,
            8,
            1,
            "cam_csid_packet_generic_blob_handler",
            v13,
            v12,
            v14,
            v15,
            v24);
          return 4294967274LL;
        }
        result = cam_isp_blob_csid_irq_comp_cfg(v9, v8, v6, a4);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v20 = *a4;
          v21 = a4[1];
          v22 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_csid_packet_generic_blob_handler",
            13998,
            "IRQ comp cfg blob, ipp_src_ctxt_mask: 0x%x, ipp_dest_ctxt_mask: 0x%x",
            v20,
            v21);
          return v22;
        }
        return result;
      }
      if ( a2 == 37 )
      {
        if ( v5 <= 0x27 )
        {
          v11 = v9[14];
          v12 = "Invalid blob size %u expected %lu ctx_idx: %u";
          v13 = 14024;
          v14 = v5;
          v15 = 40;
LABEL_36:
          v24 = v11;
          goto LABEL_37;
        }
        v23 = (unsigned int)a4[3];
        if ( (_DWORD)v23 == -1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_csid_packet_generic_blob_handler",
            14032,
            "Invalid num_dt_info:%u ctx_idx: %u",
            -1,
            v9[14]);
          return 4294967274LL;
        }
        v15 = 32 * v23 + 40;
        if ( v15 > v5 )
        {
          v11 = v9[14];
          v12 = "Invalid blob size %u expected %lu ctx_idx: %u";
          v13 = 14044;
          v14 = v5;
          goto LABEL_36;
        }
        result = cam_isp_blob_csid_dynamic_switch_update_v2(v6, a4, v8);
        if ( (_DWORD)result )
        {
          v16 = (unsigned int)v9[14];
          v17 = "Dynamic switch blob update failed, ctx_idx: %u";
          v18 = result;
          v19 = 14052;
          goto LABEL_40;
        }
        return result;
      }
    }
LABEL_30:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_csid_packet_generic_blob_handler",
      14057,
      "Invalid blob type %d, ctx_idx: %u",
      a2,
      v9[14]);
    return 0;
  }
  if ( (unsigned int)a2 < 0xB || (unsigned int)(a2 - 12) < 2 )
    return result;
  if ( a2 != 15 )
    goto LABEL_30;
  if ( v5 < 0xC )
  {
    v11 = v9[14];
    v12 = "Invalid blob size %u expected %lu ctx_idx: %u";
    v13 = 14007;
    v14 = v5;
    v15 = 12;
    goto LABEL_36;
  }
  result = cam_isp_blob_csid_dynamic_switch_update(a4);
  if ( (_DWORD)result )
  {
    v16 = (unsigned int)v9[14];
    v17 = "MUP Update Failed, ctx_idx: %u";
    v18 = result;
    v19 = 14015;
LABEL_40:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_csid_packet_generic_blob_handler",
      v19,
      v17,
      v16);
    return v18;
  }
  return result;
}
