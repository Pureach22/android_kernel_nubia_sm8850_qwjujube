__int64 __fastcall cam_icp_process_stream_settings(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x27
  __int64 v8; // x25
  _QWORD *v9; // x19
  unsigned int v10; // w8
  unsigned int v11; // w23
  unsigned int *v12; // x28
  unsigned __int64 v13; // x8
  _DWORD *v14; // x11
  __int64 v15; // x7
  const char *v16; // x5
  __int64 v17; // x6
  __int64 v18; // x4
  __int64 v19; // x8
  int v20; // w22
  __int64 v21; // x0
  __int64 v22; // x21
  __int64 v23; // x0
  char v24; // w8
  int v25; // w9
  int v26; // w8
  int v27; // w8
  unsigned int v28; // w0
  __int64 v29; // x6
  unsigned int v30; // w20
  __int64 v31; // x0
  __int64 v32; // x22
  __int64 v33; // x1
  __int64 v34; // x23
  _QWORD *v35; // x0
  __int64 v36; // x0
  __int64 v37; // x24
  __int64 v38; // x1
  __int64 v39; // x25
  int v40; // w0
  const char *v41; // x7
  int v42; // [xsp+0h] [xbp-50h]
  const void *v43; // [xsp+8h] [xbp-48h]
  unsigned int v44; // [xsp+10h] [xbp-40h]
  __int64 v46; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v47[2]; // [xsp+40h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  v46 = 0;
  v47[0] = 0;
  if ( *(_DWORD *)(v4 + 8) == 4 )
  {
    result = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_process_stream_settings",
        6620,
        "%s OFE FW does not support map/unmap operations",
        (const char *)(a1 + 29824));
      result = 0;
    }
    goto LABEL_59;
  }
  v6 = *(_QWORD *)(a1 + 8);
  v8 = 8LL * (unsigned int)(*(_DWORD *)(a2 + 4) - 1);
  if ( mem_trace_en == 1 )
  {
    v9 = (_QWORD *)cam_mem_trace_alloc(v8 + 20, 0xCC0u, 0, "cam_icp_process_stream_settings", 0x19E4u);
    if ( !v9 )
      goto LABEL_58;
  }
  else
  {
    v9 = (_QWORD *)_kvmalloc_node_noprof(v8 + 20, 0, 3520, 0xFFFFFFFFLL);
    if ( !v9 )
    {
LABEL_58:
      result = 4294967284LL;
      goto LABEL_59;
    }
  }
  v10 = *(_DWORD *)(a2 + 4);
  if ( !v10 )
  {
LABEL_23:
    *((_DWORD *)v9 + 2) = v10;
    *v9 = 0;
    v19 = 8LL * (unsigned int)(*(_DWORD *)(a2 + 4) - 1);
    v20 = v19 + 56;
    if ( mem_trace_en == 1 )
      v21 = cam_mem_trace_alloc(v19 + 56, 0xCC0u, 0, "cam_icp_process_stream_settings", 0x1A12u);
    else
      v21 = _kvmalloc_node_noprof(v19 + 56, 0, 3520, 0xFFFFFFFFLL);
    v22 = v21;
    if ( v21 )
    {
      if ( mem_trace_en )
      {
        v23 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_icp_process_stream_settings", 0x1A18u);
        v24 = a3;
        if ( v23 )
        {
LABEL_29:
          v25 = *(_DWORD *)(a1 + 29224);
          if ( (v24 & 1) != 0 )
            v26 = 14;
          else
            v26 = 15;
          *(_QWORD *)(v23 + 16) = a1;
          *(_DWORD *)(v23 + 4) = v25;
          *(_DWORD *)(v22 + 8) = v26;
          *(_DWORD *)v22 = v20;
          *(_DWORD *)(v22 + 4) = 16842762;
          *(_DWORD *)(v22 + 28) = 1;
          v27 = *(_DWORD *)(a1 + 72);
          *(_QWORD *)(v22 + 12) = v23;
          *(_QWORD *)(v22 + 20) = 0;
          *(_DWORD *)(v22 + 32) = v27;
          memcpy((void *)(v22 + 36), v9, v8 + 20);
          *(_DWORD *)(a1 + 29192) = 0;
          v28 = hfi_write_cmd(*(unsigned int *)(v6 + 156), v22);
          if ( v28 )
          {
            v29 = a1 + 29824;
            v30 = v28;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_process_stream_settings",
              6705,
              "%s: hfi write failed  rc %d",
              v29);
          }
          else
          {
            if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            {
              if ( (a3 & 1) != 0 )
                v41 = "Map";
              else
                v41 = "Unmap";
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x100,
                4,
                "cam_icp_process_stream_settings",
                6710,
                "%s: Sent FW %s cmd",
                (const char *)(a1 + 29824),
                v41);
            }
            v31 = ktime_get_with_offset(1);
            v32 = ns_to_timespec64(v31);
            v34 = v33;
            if ( cam_common_wait_for_completion_timeout(a1 + 29192) )
            {
              v30 = 0;
            }
            else
            {
              v36 = ktime_get_with_offset(1);
              v37 = ns_to_timespec64(v36);
              v39 = v38;
              v40 = jiffies_to_msecs(1250, v38);
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_process_stream_settings",
                6716,
                "%s: FW response timeout for process stream setting handle command (timeout: %ums start: timestamp:[%lld:"
                "%06lld] end: timestamp:[%lld:%06lld])",
                (const char *)(a1 + 29824),
                v40,
                v32,
                v34 / 1000,
                v37,
                v39 / 1000);
              cam_icp_dump_debug_info(*(_QWORD *)(a1 + 8), 0);
              v30 = -110;
            }
          }
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v9, 0);
          else
            kvfree(v9);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free((_QWORD *)v22, 0);
          else
            kvfree(v22);
          result = v30;
          goto LABEL_59;
        }
      }
      else
      {
        v23 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
        v24 = a3;
        if ( v23 )
          goto LABEL_29;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_process_stream_settings",
        6682,
        "Failed in allocating memory for ICP ctx info");
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v9, 0);
      else
        kvfree(v9);
      v35 = (_QWORD *)v22;
      if ( mem_trace_en != 1 )
        goto LABEL_43;
    }
    else
    {
      v35 = v9;
      if ( !mem_trace_en )
      {
LABEL_43:
        kvfree(v35);
        goto LABEL_58;
      }
    }
    cam_mem_trace_free(v35, 0);
    goto LABEL_58;
  }
  v11 = 0;
  while ( 1 )
  {
    v12 = (unsigned int *)(a2 + 8 + 16LL * (int)v11);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, __int64 *, _QWORD *, _QWORD, _QWORD))cam_mem_get_io_buf)(
                         *v12,
                         *(unsigned int *)(v6 + 148),
                         &v46,
                         v47,
                         0,
                         0) )
    {
      v15 = *v12;
      v16 = "%s: Failed to get cmd region iova for handle %u";
      v17 = a1 + 29824;
      v18 = 6639;
      goto LABEL_19;
    }
    v13 = v12[1];
    if ( v47[0] <= v13 )
      break;
    v14 = (_DWORD *)&v9[(int)v11++ + 1] + 1;
    *v14 = v13 + v46;
    v14[1] = v47[0];
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      LODWORD(v43) = v46;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_process_stream_settings",
        6663,
        "%s: Region %u mem_handle %d iova %pK len %u",
        (const char *)(a1 + 29824),
        v11,
        *v12,
        v43,
        LODWORD(v47[0]));
    }
    v10 = *(_DWORD *)(a2 + 4);
    if ( v11 >= v10 )
      goto LABEL_23;
  }
  v15 = *v12;
  v44 = v12[1];
  v16 = "%s: Mem region offset exceeds length of the buffer, mem handle: 0x%x, iova: %pK, len: %u, offset: 0x%x";
  LODWORD(v43) = v47[0];
  v17 = a1 + 29824;
  v18 = 6650;
  v42 = v46;
LABEL_19:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, _DWORD, unsigned int))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_process_stream_settings",
    v18,
    v16,
    v17,
    v15,
    v42,
    (_DWORD)v43,
    v44);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v9, 0);
  else
    kvfree(v9);
  result = 4294967274LL;
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
