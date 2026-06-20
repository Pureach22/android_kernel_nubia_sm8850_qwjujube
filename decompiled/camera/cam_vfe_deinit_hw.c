__int64 __fastcall cam_vfe_deinit_hw(__int64 a1, __int64 a2)
{
  _DWORD *v3; // x8
  int v4; // w8
  int v5; // w22
  __int64 result; // x0
  __int64 v7; // x22
  __int64 *v8; // x8
  _DWORD *v9; // x9
  __int64 v10; // x0
  int v11; // w0
  __int64 *v12; // x8
  _DWORD *v13; // x9
  __int64 v14; // x0
  int v15; // w0
  int v16; // w0
  unsigned int v17; // w22
  char v18; // w8
  unsigned int v19; // w19
  __int64 v20; // x22
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( a1 )
      goto LABEL_4;
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_deinit_hw",
      188,
      "Invalid arguments");
    result = 4294967274LL;
    goto LABEL_35;
  }
  v20 = a2;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_vfe_deinit_hw",
    186,
    "Enter");
  a2 = v20;
  if ( !a1 )
    goto LABEL_34;
LABEL_4:
  if ( a2 )
  {
    v3 = *(_DWORD **)(a2 + 80);
    if ( v3 )
    {
      if ( *(v3 - 1) != -827858501 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v3)(a2, 0, 0) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_deinit_hw",
          196,
          "deinit failed");
    }
  }
  mutex_lock(a1);
  v4 = *(_DWORD *)(a1 + 88);
  if ( v4 )
  {
    v5 = v4 - 1;
    *(_DWORD *)(a1 + 88) = v4 - 1;
    mutex_unlock(a1);
    if ( v5 )
    {
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_deinit_hw",
          208,
          "open_cnt non-zero =%d",
          *(_DWORD *)(a1 + 88));
        result = 0;
      }
    }
    else
    {
      v7 = *(_QWORD *)(a1 + 3680);
      v8 = *(__int64 **)(v7 + 24);
      v9 = (_DWORD *)v8[3];
      v10 = *v8;
      if ( *(v9 - 1) != 1989616049 )
        __break(0x8229u);
      v11 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v9)(v10, 0, 0);
      if ( v11 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_deinit_hw",
          219,
          "Bus HW deinit Failed rc=%d",
          v11);
      v12 = *(__int64 **)(v7 + 32);
      if ( v12 )
      {
        v13 = (_DWORD *)v12[3];
        v14 = *v12;
        if ( *(v13 - 1) != 1989616049 )
          __break(0x8229u);
        v15 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v13)(v14, 0, 0);
        if ( v15 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_deinit_hw",
            226,
            "Bus HW deinit Failed rc=%d",
            v15);
      }
      v16 = cam_vfe_reset(a1, (__int64)&v21, 4u);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_deinit_hw",
          232,
          "Disable SOC resource, rc: %d",
          v16);
      result = cam_vfe_disable_soc_resources(a1 + 96);
      if ( (_DWORD)result )
      {
        v17 = result;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_deinit_hw",
          235,
          "Disable SOC failed");
        result = v17;
      }
      v18 = debug_mdl;
      *(_DWORD *)(a1 + 92) = 0;
      if ( (v18 & 8) != 0 && !debug_priority )
      {
        v19 = result;
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v18 & 8,
          4,
          "cam_vfe_deinit_hw",
          239,
          "Exit");
        result = v19;
      }
    }
  }
  else
  {
    mutex_unlock(a1);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_deinit_hw",
      202,
      "Error. Unbalanced deinit");
    result = 4294967282LL;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
