__int64 __fastcall cam_icp_mgr_update_hfi_frame_process(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int first_zero_bit; // w0
  unsigned int v7; // w19
  __int64 result; // x0
  __int64 v10; // x28
  __int64 v11; // x9
  _QWORD *v12; // x8
  __int64 *v13; // x24
  int v14; // w10
  unsigned int v15; // w25
  __int64 v16; // x27
  int *v17; // x26
  unsigned int v18; // w26
  __int64 v20; // x20
  __int64 v21; // x22
  __int64 v22; // x0
  int v23; // w8
  unsigned int v24; // w8
  int v25; // w10
  __int64 v26; // x9
  int v27; // w10
  unsigned __int64 v33; // x9
  unsigned __int64 v35; // x9
  _QWORD *v36; // [xsp+0h] [xbp-40h]
  unsigned int *v37; // [xsp+8h] [xbp-38h]
  __int64 v38; // [xsp+18h] [xbp-28h]
  __int64 v39; // [xsp+20h] [xbp-20h] BYREF
  unsigned int v40; // [xsp+28h] [xbp-18h]
  int v41; // [xsp+2Ch] [xbp-14h]
  _QWORD *v42; // [xsp+30h] [xbp-10h]
  __int64 v43; // [xsp+38h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  first_zero_bit = find_first_zero_bit(*(_QWORD *)(a1 + 1720), *(_QWORD *)(a1 + 1728));
  v7 = first_zero_bit;
  if ( first_zero_bit >= 0x28 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_update_hfi_frame_process",
      7284,
      "%s request idx is wrong: %d",
      (const char *)(a1 + 29824),
      first_zero_bit);
    result = 4294967274LL;
    goto LABEL_27;
  }
  _X8 = *(unsigned __int64 **)(a1 + 1720);
  v10 = first_zero_bit & 0x3F;
  __asm { PRFM            #0x11, [X8] }
  do
    v33 = __ldxr(_X8);
  while ( __stxr(v33 | (1LL << first_zero_bit), _X8) );
  v11 = *(_QWORD *)(a2 + 8);
  v12 = (_QWORD *)(a1 + (v10 << 6));
  *(_QWORD *)(a1 + 1784 + 8 * v10) = v11;
  v12[3288] = v11;
  v12[3289] = 0;
  v13 = v12 + 3289;
  v12[3295] = a2;
  v14 = *(_DWORD *)(a2 + 28);
  v39 = a1;
  v41 = 0;
  v40 = first_zero_bit;
  v42 = v12 + 3289;
  if ( v14 )
  {
    v15 = 0;
    v36 = v12 + 3288;
    v37 = a3;
    v38 = 1LL << first_zero_bit;
    v16 = a2 + (*(_DWORD *)(a2 + 24) & 0xFFFFFFFC) + 56;
    do
    {
      v17 = (int *)(v16 + 24LL * (int)v15);
      result = cam_packet_util_validate_cmd_desc(v17);
      if ( (_DWORD)result )
        goto LABEL_15;
      if ( v17[3] && v17[5] == 1 )
      {
        result = cam_packet_util_process_generic_cmd_buffer(
                   (int *)(v16 + 24LL * (int)v15),
                   cam_icp_packet_generic_blob_handler,
                   (__int64)&v39);
        if ( (_DWORD)result )
        {
          v18 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_process_generic_cmd_buffer",
            7219,
            "Failed in processing blobs %d",
            result);
          result = v18;
        }
      }
      else
      {
        result = 0;
      }
      ++v15;
    }
    while ( v15 < *(_DWORD *)(a2 + 28) );
    if ( (_DWORD)result )
    {
LABEL_15:
      _X8 = *(unsigned __int64 **)(a1 + 1720);
      __asm { PRFM            #0x11, [X8] }
      do
        v35 = __ldxr(_X8);
      while ( __stxr(v35 & ~v38, _X8) );
      *(_QWORD *)(a1 + 1784 + 8 * v10) = -1;
      goto LABEL_27;
    }
    v20 = *v13;
    if ( *v13 )
    {
      v21 = *(_QWORD *)(a2 + 8);
      if ( mem_trace_en == 1 )
      {
        v22 = cam_mem_trace_alloc(24, 0x820u, 0, "cam_icp_mgr_process_cfg_io_cmd", 0x1C41u);
        if ( v22 )
          goto LABEL_19;
      }
      else
      {
        v22 = _kvmalloc_node_noprof(24, 0, 2336, 0xFFFFFFFFLL);
        if ( v22 )
        {
LABEL_19:
          v23 = *(_DWORD *)(a1 + 29224);
          *(_QWORD *)(v22 + 16) = a1;
          *(_DWORD *)(v22 + 4) = v23;
          v24 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 8LL) - 2;
          if ( v24 >= 3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_mgr_process_cfg_io_cmd",
              7257,
              "%s: Invalid device type %u not supported",
              a1 + 29824);
            result = 4294967274LL;
          }
          else
          {
            v25 = dword_452050[v24];
            v26 = v22;
            result = 0;
            *((_DWORD *)v36 + 5) = dword_452068[v24];
            *((_DWORD *)v36 + 6) = v25;
            *((_DWORD *)v36 + 4) = 40;
            v27 = *(_DWORD *)(a1 + 72);
            *((_DWORD *)v36 + 13) = v20;
            *((_DWORD *)v36 + 11) = 1;
            *((_DWORD *)v36 + 12) = v27;
            *(_QWORD *)((char *)v36 + 28) = v26;
            *(_QWORD *)((char *)v36 + 36) = v21;
          }
          goto LABEL_25;
        }
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_process_cfg_io_cmd",
        7235,
        "Failed in allocating memory for ICP ctx info");
      result = 4294967284LL;
    }
    else
    {
      result = 0;
    }
LABEL_25:
    a3 = v37;
    goto LABEL_26;
  }
  result = 0;
LABEL_26:
  *a3 = v7;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
