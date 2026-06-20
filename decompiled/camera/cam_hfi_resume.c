__int64 __fastcall cam_hfi_resume(unsigned int a1)
{
  __int64 v2; // x21
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x20
  int v7; // w8
  __int64 v8; // x1
  unsigned int v9; // w20
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0
  int v13; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v9 = -22;
LABEL_23:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_resume",
      972,
      "Failed to get hfi info rc: %d for hdl:%d",
      v9,
      a1);
    goto LABEL_24;
  }
  v2 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v9 = -19;
    goto LABEL_23;
  }
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 304);
  if ( !v3 )
    goto LABEL_21;
  v4 = *(_QWORD *)(v2 + 984);
  if ( *((_DWORD *)v3 - 1) != -1437795666 )
    __break(0x8228u);
  v5 = v3(v4);
  if ( v5 > 0xFFFFFFFFFFFFF000LL || (v6 = v5) == 0 )
  {
LABEL_21:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_resume",
      980,
      "[%s] Invalid HFI interface address for hdl:%d",
      (const char *)(v2 + 1004),
      a1);
    v9 = -22;
    goto LABEL_24;
  }
  cam_io_w_mb(*(unsigned int *)(v2 + 16), v5 + 24);
  cam_io_w_mb(*(unsigned int *)(v2 + 112), v6 + 40);
  cam_io_w_mb(*(unsigned int *)(v2 + 160), v6 + 16);
  cam_io_w_mb(*(unsigned int *)(v2 + 144), v6 + 20);
  cam_io_w_mb(*(unsigned int *)(v2 + 136), v6 + 28);
  cam_io_w_mb(*(unsigned int *)(v2 + 120), v6 + 32);
  cam_io_w_mb(*(unsigned int *)(v2 + 184), v6 + 44);
  cam_io_w_mb(*(unsigned int *)(v2 + 168), v6 + 48);
  cam_io_w_mb(*(unsigned int *)(v2 + 208), v6 + 52);
  cam_io_w_mb(*(unsigned int *)(v2 + 192), v6 + 56);
  cam_io_w_mb(*(unsigned int *)(v2 + 232), v6 + 60);
  cam_io_w_mb(*(unsigned int *)(v2 + 216), v6 + 64);
  cam_io_w_mb(*(unsigned int *)(v2 + 256), v6 + 68);
  cam_io_w_mb(*(unsigned int *)(v2 + 240), v6 + 72);
  cam_io_w_mb(*(unsigned int *)(v2 + 280), v6 + 76);
  cam_io_w_mb(*(unsigned int *)(v2 + 264), v6 + 80);
  cam_io_w_mb(1, v6 + 8);
  v7 = debug_priority;
  v8 = debug_mdl & 0x40000;
  if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v8,
      4,
      "cam_hfi_resume",
      1026,
      "IO1 : [0x%x 0x%x] IO2 [0x%x 0x%x]",
      *(_DWORD *)(v2 + 208),
      *(_QWORD *)(v2 + 192),
      *(_DWORD *)(v2 + 232),
      *(_QWORD *)(v2 + 216));
    v7 = debug_priority;
    v8 = debug_mdl & 0x40000;
    if ( (debug_mdl & 0x40000) == 0 )
      goto LABEL_13;
  }
  else if ( !v8 )
  {
    goto LABEL_13;
  }
  if ( !v7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v8,
      4,
      "cam_hfi_resume",
      1030,
      "FwUncached : [0x%x 0x%x] Shared [0x%x 0x%x]",
      *(_DWORD *)(v2 + 256),
      *(_QWORD *)(v2 + 240),
      *(_DWORD *)(v2 + 160),
      *(_QWORD *)(v2 + 144));
    v7 = debug_priority;
    v8 = debug_mdl & 0x40000;
  }
LABEL_13:
  if ( v8 && !v7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v8,
      4,
      "cam_hfi_resume",
      1034,
      "SecHeap : [0x%x 0x%x] QDSS [0x%x 0x%x]",
      *(_DWORD *)(v2 + 136),
      *(_QWORD *)(v2 + 120),
      *(_DWORD *)(v2 + 184),
      *(_QWORD *)(v2 + 168));
    v7 = debug_priority;
    v8 = debug_mdl & 0x40000;
    if ( (debug_mdl & 0x40000) != 0 )
    {
LABEL_16:
      if ( !v7 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v8,
          4,
          "cam_hfi_resume",
          1039,
          "QTbl : [0x%x 0x%x] Sfr [0x%x 0x%x] Device [0x%x 0x%x]",
          *(_DWORD *)(v2 + 16),
          *(_QWORD *)v2,
          *(_DWORD *)(v2 + 112),
          *(_QWORD *)(v2 + 96),
          *(_DWORD *)(v2 + 280),
          *(_QWORD *)(v2 + 264));
    }
  }
  else if ( v8 )
  {
    goto LABEL_16;
  }
  if ( (unsigned int)cam_common_read_poll_timeout((const void *)(v6 + 12), 0xAu, 1500000, 0xFFFFFFFF, 1, &v13) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_resume",
      1046,
      "[%s] response poll timed out: status=0x%08x hfi hdl: %d",
      (const char *)(v2 + 1004),
      v13,
      a1);
    v9 = -110;
  }
  else
  {
    v11 = *(void (__fastcall **)(_QWORD))(v2 + 296);
    if ( v11 )
    {
      v12 = *(_QWORD *)(v2 + 984);
      if ( *((_DWORD *)v11 - 1) != 251140989 )
        __break(0x8228u);
      v11(v12);
    }
    v9 = 0;
    if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000,
        4,
        "cam_hfi_resume",
        1053,
        "[%s] hfi hdl: %d fw version : [0x%x]",
        (const char *)(v2 + 1004),
        a1,
        *(_DWORD *)(v2 + 1000));
      v9 = 0;
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v9;
}
