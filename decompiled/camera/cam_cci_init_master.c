__int64 __fastcall cam_cci_init_master(__int64 a1, unsigned int a2)
{
  int v2; // w8
  int v5; // w21
  int v6; // w24
  __int64 v7; // x25
  __int64 v8; // x26
  unsigned __int8 v9; // w9
  _DWORD *v10; // x28
  unsigned int v11; // w21
  unsigned int v12; // w0
  int v13; // w8
  __int64 v14; // x1
  __int64 v15; // x0
  __int64 v16; // x8

  v2 = *(_DWORD *)(a1 + 3960);
  if ( v2 == 269090816 )
  {
    v5 = 32;
    v6 = 1024;
  }
  else if ( v2 == 268566537 )
  {
    v5 = 16;
    v6 = 64;
  }
  else
  {
    v5 = 32;
    v6 = 128;
  }
  v7 = a1 + 5136;
  v8 = *(_QWORD *)(a1 + 672);
  v9 = *(_BYTE *)(a1 + 5136 + a2) + 1;
  *(_BYTE *)(a1 + 5136 + a2) = v9;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_init_master",
      38,
      "CCI%d_I2C_M%d active slave: %d",
      *(_DWORD *)(a1 + 404),
      a2,
      v9);
  v10 = (_DWORD *)(a1 + 544LL * a2 + 4040);
  if ( (*(_BYTE *)(a1 + 544LL * a2 + 4450) & 1) != 0 )
    return 0;
  v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))cam_soc_util_select_pinctrl_state)(a1 + 384, a2, 1);
  if ( v12 )
  {
    v11 = v12;
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_init_master",
      45);
LABEL_13:
    --*(_BYTE *)(v7 + a2);
    return v11;
  }
  v13 = *(unsigned __int8 *)(a1 + 3964);
  *(_DWORD *)(a1 + 544LL * a2 + 4136) = 0;
  *(_DWORD *)(a1 + 544LL * a2 + 4104) = 0;
  *(_DWORD *)(a1 + 544LL * a2 + 4296) = 0;
  *(_DWORD *)(a1 + 544LL * a2 + 4328) = 0;
  *(_BYTE *)(a1 + 544LL * a2 + 4054) = 1;
  *v10 = 0;
  if ( v13 == 1 )
  {
    cam_io_w_mb(259257335, v8 + 4);
    v14 = v8 + 4;
    v15 = 1;
  }
  else
  {
    v14 = v8 + 4;
    if ( a2 )
      v15 = 258049;
    else
      v15 = 1009;
  }
  cam_io_w_mb(v15, v14);
  if ( !cam_common_wait_for_completion_timeout(a1 + 544LL * a2 + 4104) )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_init_master",
      75);
    v11 = -110;
    goto LABEL_13;
  }
  _flush_workqueue(*(_QWORD *)(a1 + 8LL * a2 + 5280));
  v16 = a1 + 32LL * a2;
  *(_DWORD *)(v16 + 3972) = v6;
  *(_DWORD *)(v16 + 3988) = v5;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_init_master",
      93,
      "CCI%d_I2C_M%d:: Q0: %d Q1: %d",
      *(_DWORD *)(a1 + 404),
      a2,
      v6,
      v5);
  v11 = 0;
  *v10 = 0;
  *(_BYTE *)(a1 + 544LL * a2 + 4450) = 1;
  *(_BYTE *)(a1 + a2 + 5828) = 0;
  return v11;
}
