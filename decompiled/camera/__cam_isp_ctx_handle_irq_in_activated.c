__int64 __fastcall _cam_isp_ctx_handle_irq_in_activated(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w23
  __int64 v5; // x20
  __int64 v8; // x2
  char v9; // w26
  unsigned int v10; // w0
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  char v12; // w23
  const char *v14; // x0
  int v15; // w21
  const char *v16; // x0
  const char *v17; // x0

  v5 = *(_QWORD *)(a1 + 256);
  raw_spin_lock(a1 + 120);
  v8 = *(unsigned int *)(v5 + 20);
  if ( a3 )
  {
    if ( (int)a2 > 2 )
    {
      if ( a2 - 5 < 2 || a2 == 3 || a2 == 4 )
        goto LABEL_13;
    }
    else if ( a2 <= 2 )
    {
      goto LABEL_13;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v3 = *(_DWORD *)(v5 + 20);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_get_event_ts",
        1560,
        "Invalid Event Type %d",
        a2);
      v8 = v3;
    }
  }
LABEL_13:
  v9 = debug_mdl;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( a2 < 7 )
      goto LABEL_16;
LABEL_30:
    __break(0x5512u);
LABEL_31:
    v15 = *(_DWORD *)(a1 + 240);
    v16 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v5 + 20));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v3 & 8,
      4,
      "__cam_isp_ctx_handle_irq_in_activated",
      10396,
      "Exit: State %d Substate[%s], ctx: %u link: 0x%x",
      v15,
      v16,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    goto LABEL_28;
  }
  v3 = *(_DWORD *)(a1 + 240);
  v14 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v5 + 20));
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v9 & 8,
    4,
    "__cam_isp_ctx_handle_irq_in_activated",
    10376,
    "Enter: State %d, Substate[%s], evt id %d, ctx:%u link: 0x%x",
    v3,
    v14,
    a2,
    *(_DWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 64));
  if ( a2 >= 7 )
    goto LABEL_30;
LABEL_16:
  v10 = *(_DWORD *)(v5 + 20);
  v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v5 + 40) + 56LL * v10 + 8LL * a2);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != -1019304031 )
      __break(0x8228u);
    LODWORD(a3) = v11(v5, a3, v8);
    if ( a2 == 4 )
      goto LABEL_25;
  }
  else
  {
    v12 = debug_mdl;
    LODWORD(a3) = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v17 = _cam_isp_ctx_substate_val_to_type(v10);
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v12 & 8,
        4,
        "__cam_isp_ctx_handle_irq_in_activated",
        10385,
        "No handle function for Substate[%s], evt id %d, ctx:%u link: 0x%x",
        v17,
        a2,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      LODWORD(a3) = 0;
      if ( a2 == 4 )
        goto LABEL_25;
    }
    else if ( a2 == 4 )
    {
LABEL_25:
      _cam_isp_ctx_update_frame_timing_record(a2, v5);
      goto LABEL_26;
    }
  }
  if ( (a2 & 5) == 1 )
    goto LABEL_25;
LABEL_26:
  _cam_isp_ctx_notify_cpas((const char *)a1, a2);
  LOBYTE(v3) = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    goto LABEL_31;
LABEL_28:
  raw_spin_unlock(a1 + 120);
  return (unsigned int)a3;
}
