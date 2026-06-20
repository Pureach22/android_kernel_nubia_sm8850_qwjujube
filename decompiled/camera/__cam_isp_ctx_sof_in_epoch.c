__int64 __fastcall _cam_isp_ctx_sof_in_epoch(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x21
  _QWORD *v5; // x22
  __int64 v6; // x2
  __int64 result; // x0
  __int64 v8; // x8
  const char *v9; // x8
  char v10; // w22
  int v11; // w20
  int v12; // w21
  __int64 v13; // x23
  const char *v14; // x0

  if ( a2 )
  {
    v2 = *(_QWORD *)a1;
    *(_QWORD *)(a1 + 45656) = jiffies;
    v5 = (_QWORD *)(a1 + 37304);
    if ( *(_DWORD *)(a1 + 45560) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_ctx_sof_in_epoch",
        4227,
        "Apply is in progress at the time of SOF, ctx: %u, link: 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    if ( *v5 != *a2 )
    {
      ++*(_QWORD *)(a1 + 8);
      *v5 = *a2;
      v5[1] = a2[1];
    }
    if ( *(_QWORD *)(v2 + 128) == v2 + 128 )
    {
      v6 = 0;
      *(_DWORD *)(a1 + 20) = 0;
    }
    else
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_sof_in_epoch",
          4237,
          "Still need to wait for the buf done, ctx: %u, link: 0x%x",
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
      v6 = *(_QWORD *)(*(_QWORD *)(v2 + 136) + 24LL);
    }
    _cam_isp_ctx_update_state_monitor_array(a1, 3, v6);
    if ( *(_QWORD *)(a1 + 8) == 1 )
    {
      v8 = *(unsigned int *)(a1 + 20);
      if ( (unsigned int)v8 > 6 )
        v9 = "INVALID";
      else
        v9 = off_451850[v8];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_ctx_sof_in_epoch",
        4250,
        "First SOF in EPCR ctx:%u link: 0x%x frame_id:%lld next substate %s",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64),
        1,
        v9);
    }
    v10 = debug_mdl;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v11 = *(_DWORD *)(v2 + 32);
      v12 = *(_DWORD *)(v2 + 64);
      v13 = *(_QWORD *)(a1 + 8);
      v14 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(a1 + 20));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v10 & 8,
        4,
        "__cam_isp_ctx_sof_in_epoch",
        4255,
        "SOF in epoch ctx:%u link: 0x%x frame_id:%lld next substate:%s",
        v11,
        v12,
        v13,
        v14);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_sof_in_epoch",
      4219,
      "in valid sof event data");
    return 4294967274LL;
  }
  return result;
}
