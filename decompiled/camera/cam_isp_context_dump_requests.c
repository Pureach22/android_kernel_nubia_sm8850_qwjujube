__int64 __fastcall cam_isp_context_dump_requests(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x22
  int v6; // w8
  const char *v7; // x6
  __int64 result; // x0
  _QWORD *v9; // x26
  _QWORD *v10; // x25
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  _QWORD *v16; // x26
  _QWORD *v17; // x25
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  _QWORD *v23; // x26
  _QWORD *v24; // x25
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  int v30; // w7
  int v31; // w8
  unsigned int v32; // w19

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_dump_requests",
      10665,
      "Invalid ctx %pK or pf args %pK",
      (const void *)a1,
      (const void *)a2);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 256) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_dump_requests",
      10671,
      "Invalid isp ctx");
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a2 + 56) & 1) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_isp_context_dump_requests",
      10680,
      "Iterating over active list for isp ctx %u link: 0x%x state %d",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 240));
    v9 = *(_QWORD **)(a1 + 128);
    while ( v9 != (_QWORD *)(a1 + 128) )
    {
      v10 = (_QWORD *)*v9;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_isp_context_find_faulted_context",
        10638,
        "List req_id: %llu ctx id: %u link: 0x%x",
        v9[3],
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      if ( (unsigned int)cam_context_dump_pf_info_to_hw(a1, a2, (__int64)(v9 + 16), v11, v12, v13, v14, v15) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_context_find_faulted_context",
          10643,
          "Failed to dump pf info, ctx_idx: %u, link: 0x%x",
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
      v9 = v10;
      if ( *(_DWORD *)(a2 + 8) )
        goto LABEL_5;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_isp_context_dump_requests",
      10688,
      "Iterating over waiting list of isp ctx %u link: 0x%x state %d",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 240));
    v16 = *(_QWORD **)(a1 + 160);
    while ( v16 != (_QWORD *)(a1 + 160) )
    {
      v17 = (_QWORD *)*v16;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_isp_context_find_faulted_context",
        10638,
        "List req_id: %llu ctx id: %u link: 0x%x",
        v16[3],
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      if ( (unsigned int)cam_context_dump_pf_info_to_hw(a1, a2, (__int64)(v16 + 16), v18, v19, v20, v21, v22) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_context_find_faulted_context",
          10643,
          "Failed to dump pf info, ctx_idx: %u, link: 0x%x",
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
      v16 = v17;
      if ( *(_DWORD *)(a2 + 8) )
        goto LABEL_5;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_isp_context_dump_requests",
      10704,
      "Iterating over pending req list of isp ctx %u link: 0x%x state %d",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 240));
    v23 = *(_QWORD **)(a1 + 144);
    do
    {
      if ( v23 == (_QWORD *)(a1 + 144) )
        break;
      v24 = (_QWORD *)*v23;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_isp_context_find_faulted_context",
        10638,
        "List req_id: %llu ctx id: %u link: 0x%x",
        v23[3],
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      if ( (unsigned int)cam_context_dump_pf_info_to_hw(a1, a2, (__int64)(v23 + 16), v25, v26, v27, v28, v29) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_context_find_faulted_context",
          10643,
          "Failed to dump pf info, ctx_idx: %u, link: 0x%x",
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
      v23 = v24;
    }
    while ( !*(_DWORD *)(a2 + 8) );
  }
LABEL_5:
  v4 = *(_DWORD *)(a2 + 12);
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 256);
    v6 = *(_DWORD *)(v5 + 45580);
    switch ( v6 )
    {
      case 65555:
        goto LABEL_9;
      case 65552:
        if ( v4 > 0xF )
          v7 = "Invalid_Resource_Type";
        else
          v7 = off_4517A8[(int)v4 - 1];
        break;
      case 65538:
LABEL_9:
        v7 = _cam_isp_ife_sfe_resource_handle_id_to_type(v4);
        break;
      default:
        v7 = "INVALID_DEV_TYPE";
        break;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_isp_context_dump_requests",
      10719,
      "Page fault on resource:%s (0x%x) ctx id:%u link: 0x%x frame id:%d reported id:%lld applied id:%lld",
      v7,
      v4,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_QWORD *)(v5 + 8),
      *(_QWORD *)(v5 + 37328),
      *(_QWORD *)(v5 + 37352));
  }
  if ( (*(_BYTE *)(a2 + 48) & 1) == 0 && *(_BYTE *)(a2 + 49) != 1 )
    return 0;
  result = cam_context_send_pf_evt(a1, (__int64 *)a2);
  if ( (_DWORD)result )
  {
    v30 = *(_DWORD *)(a1 + 32);
    v31 = *(_DWORD *)(a1 + 64);
    v32 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_dump_requests",
      10733,
      "Failed to notify PF event to userspace rc: %d, ctx id:%u link: 0x%x",
      result,
      v30,
      v31);
    return v32;
  }
  return result;
}
