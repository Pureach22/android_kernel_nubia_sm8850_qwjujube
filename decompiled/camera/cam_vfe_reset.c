__int64 __fastcall cam_vfe_reset(__int64 a1, __int64 a2, unsigned int a3)
{
  int ***v4; // x25
  int *v5; // x24
  __int64 result; // x0
  char v7; // w8
  __int64 v8; // x21
  unsigned int v9; // w20
  __int64 v10; // x0
  int v11; // w0
  char v12; // w8
  __int64 v13; // x19
  int **v14; // x8
  int *v15; // x9
  int *v16; // x0
  int v17; // w6
  unsigned int v18; // w19
  unsigned int v19; // w19
  __int64 v20; // x20
  unsigned int v21; // w21
  _QWORD v22[4]; // [xsp+10h] [xbp-20h] BYREF

  v22[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v22, 0, 20);
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( a1 )
      goto LABEL_4;
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_reset",
      255,
      "Invalid input arguments");
    result = 4294967274LL;
    goto LABEL_26;
  }
  v20 = a2;
  v21 = a3;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_vfe_reset",
    251,
    "Enter");
  a2 = v20;
  a3 = v21;
  if ( !a1 )
    goto LABEL_25;
LABEL_4:
  v4 = *(int ****)(a1 + 3680);
  v5 = **v4;
  if ( (v5[4] & 0x40) == 0 )
  {
    result = 0;
    v7 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_26;
LABEL_22:
    if ( !debug_priority )
    {
      v19 = result;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v7 & 8,
        4,
        "cam_vfe_reset",
        307,
        "Exit");
      result = v19;
    }
    goto LABEL_26;
  }
  *(_QWORD *)((char *)&v22[1] + 4) = 0;
  v8 = a2;
  v9 = a3;
  *(_QWORD *)((char *)v22 + 4) = 0;
  v10 = (__int64)v4[1];
  LODWORD(v22[0]) = v5[1];
  v11 = cam_irq_controller_subscribe_irq(
          v10,
          0,
          (__int64)v22,
          a1,
          (__int64)cam_vfe_reset_irq_top_half,
          0,
          0,
          nullptr,
          0);
  *v5 = v11;
  if ( v11 <= 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_reset",
      278,
      "subscribe irq controller failed");
    *v5 = 0;
    result = 4294967282LL;
    goto LABEL_26;
  }
  v12 = debug_mdl;
  *(_DWORD *)(a1 + 56) = 0;
  v13 = a1 + 56;
  if ( (v12 & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v12 & 8,
      4,
      "cam_vfe_reset",
      285,
      "Calling RESET on VFE");
  v14 = v4[2];
  v15 = v14[4];
  v16 = *v14;
  if ( *(v15 - 1) != 1989616049 )
    __break(0x8229u);
  ((void (__fastcall *)(int *, __int64, _QWORD))v15)(v16, v8, v9);
  v17 = cam_common_wait_for_completion_timeout(v13);
  if ( v17 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_reset",
        297,
        "Reset complete (%d)",
        v17);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_reset",
      295,
      "Reset Timeout");
  }
  result = ((__int64 (__fastcall *)(int **, _QWORD))cam_irq_controller_unsubscribe_irq)(v4[1], (unsigned int)*v5);
  if ( (_DWORD)result )
  {
    v18 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_reset",
      303,
      "Error. Unsubscribe failed");
    result = v18;
  }
  *v5 = 0;
  v7 = debug_mdl;
  if ( (debug_mdl & 8) != 0 )
    goto LABEL_22;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
