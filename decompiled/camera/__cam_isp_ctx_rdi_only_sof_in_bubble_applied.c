__int64 __fastcall _cam_isp_ctx_rdi_only_sof_in_bubble_applied(__int64 a1, __int64 *a2)
{
  __int64 v2; // x22
  __int64 *v5; // x25
  __int64 v6; // x7
  __int64 *v7; // x20
  __int64 v8; // x26
  __int64 v9; // x0
  int v10; // w8
  __int64 **v11; // x8
  __int64 v12; // x9
  __int64 v13; // x2
  __int64 *v14; // x1
  int v15; // w7
  unsigned __int64 v16; // x1
  __int64 v17; // x0
  unsigned int v18; // w2
  char v19; // w8

  v2 = *(_QWORD *)a1;
  if ( *(_BYTE *)(a1 + 45749) == 1 && (*(_BYTE *)(a1 + 45752) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_applied",
      7135,
      "Bubble Recovery Disabled");
    goto LABEL_31;
  }
  v5 = (__int64 *)(a1 + 37304);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_applied",
      7148,
      "frame id: %lld time stamp:0x%llx, ctx_idx: %u, link: 0x%x",
      *(_QWORD *)(a1 + 8),
      *v5,
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
  _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
  v6 = *v5;
  if ( *v5 != *a2 )
  {
    ++*(_QWORD *)(a1 + 8);
    v6 = *a2;
    *v5 = *a2;
    *(_QWORD *)(a1 + 37312) = a2[1];
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_applied",
      7155,
      "frame id: %lld time stamp:0x%llx, ctx_idx: %u, link: 0x%x",
      *(_QWORD *)(a1 + 8),
      v6,
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
  v7 = *(__int64 **)(v2 + 160);
  if ( v7 == (__int64 *)(v2 + 160) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_applied",
      7163,
      "No wait request, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    *(_DWORD *)(a1 + 20) = 0;
LABEL_31:
    _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
    return 0;
  }
  v8 = v7[4];
  *(_BYTE *)(v8 + 4504) = 1;
  if ( (unsigned int)__ratelimit(
                       &_cam_isp_ctx_rdi_only_sof_in_bubble_applied__rs,
                       "__cam_isp_ctx_rdi_only_sof_in_bubble_applied") )
    v9 = 3;
  else
    v9 = 2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    v9,
    8,
    3,
    "__cam_isp_ctx_rdi_only_sof_in_bubble_applied",
    7177,
    "Ctx:%u link: 0x%x Report Bubble flag %d req id:%lld",
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64),
    *(_DWORD *)(v8 + 72),
    v7[3]);
  v10 = *(_DWORD *)(v8 + 72);
  *(_DWORD *)(v8 + 4448) = 2;
  *(_BYTE *)(v8 + 4505) = 0;
  if ( v10 )
  {
    _cam_isp_ctx_notify_error_util(1, v7[3], (__int64 *)a1);
    *(_DWORD *)(a1 + 24) = 1;
  }
  v11 = (__int64 **)v7[1];
  if ( *v11 == v7 && (v12 = *v7, *(__int64 **)(*v7 + 8) == v7) )
  {
    *(_QWORD *)(v12 + 8) = v11;
    *v11 = (__int64 *)v12;
  }
  else
  {
    _list_del_entry_valid_or_report(v7);
  }
  *v7 = (__int64)v7;
  v13 = v2 + 128;
  v7[1] = (__int64)v7;
  v14 = *(__int64 **)(v2 + 136);
  if ( v7 == (__int64 *)(v2 + 128) || v7 == v14 || *v14 != v13 )
  {
    _list_add_valid_or_report(v7);
  }
  else
  {
    *(_QWORD *)(v2 + 136) = v7;
    *v7 = v13;
    v7[1] = (__int64)v14;
    *v14 = (__int64)v7;
  }
  v15 = *(_DWORD *)(a1 + 37320) + 1;
  *(_DWORD *)(a1 + 37320) = v15;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_applied",
      7197,
      "move request %lld to active list(cnt = %d), ctx_idx: %u, link: 0x%x",
      v7[3],
      v15,
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    if ( *(_DWORD *)(v8 + 72) )
      goto LABEL_34;
  }
  else if ( *(_DWORD *)(v8 + 72) )
  {
LABEL_34:
    v17 = a1;
    v16 = 0;
    v18 = 0;
    goto LABEL_35;
  }
  v16 = v7[3];
  if ( v16 <= *(_QWORD *)(a1 + 37328) )
    goto LABEL_34;
  *(_QWORD *)(a1 + 37328) = v16;
  v17 = a1;
  v18 = 1;
LABEL_35:
  _cam_isp_ctx_send_sof_timestamp(v17, v16, v18);
  v19 = debug_mdl;
  *(_DWORD *)(a1 + 20) = 3;
  if ( (v19 & 8) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v19 & 8,
      4,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_applied",
      7216,
      "next Substate[%s], ctx_idx: %u, link: 0x%x",
      "BUBBLE",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
  return 0;
}
