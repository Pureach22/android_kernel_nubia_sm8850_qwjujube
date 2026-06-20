__int64 __fastcall cam_sfe_deinit_hw(__int64 a1)
{
  int v2; // w8
  int v3; // w20
  __int64 result; // x0
  _QWORD *v5; // x20
  __int64 *v6; // x9
  _DWORD *v7; // x8
  __int64 v8; // x0
  int v9; // w0
  __int64 *v10; // x9
  _DWORD *v11; // x8
  __int64 v12; // x0
  int v13; // w0
  __int64 *v14; // x9
  _DWORD *v15; // x8
  __int64 v16; // x0
  int v17; // w0
  unsigned int v18; // w22
  int v19; // w8
  unsigned int v20; // w19

  if ( a1 )
  {
    mutex_lock(a1);
    v2 = *(_DWORD *)(a1 + 88);
    if ( v2 )
    {
      v3 = v2 - 1;
      *(_DWORD *)(a1 + 88) = v2 - 1;
      mutex_unlock(a1);
      if ( v3 )
      {
        result = 0;
        if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_deinit_hw",
            139,
            "open_cnt non-zero: %d",
            *(_DWORD *)(a1 + 88));
          return 0;
        }
      }
      else
      {
        v5 = *(_QWORD **)(a1 + 3680);
        v6 = (__int64 *)v5[3];
        v7 = (_DWORD *)v6[3];
        if ( v7 )
        {
          v8 = *v6;
          if ( *(v7 - 1) != 1989616049 )
            __break(0x8228u);
          v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v7)(v8, 0, 0);
          if ( v9 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_deinit_hw",
              150,
              "Bus RD deinit failed rc=%d",
              v9);
        }
        v10 = (__int64 *)v5[2];
        v11 = (_DWORD *)v10[3];
        if ( v11 )
        {
          v12 = *v10;
          if ( *(v11 - 1) != 1989616049 )
            __break(0x8228u);
          v13 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v11)(v12, 0, 0);
          if ( v13 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_deinit_hw",
              156,
              "Bus WR deinit failed rc=%d",
              v13);
        }
        v14 = (__int64 *)v5[1];
        v15 = (_DWORD *)v14[3];
        if ( v15 )
        {
          v16 = *v14;
          if ( *(v15 - 1) != 1989616049 )
            __break(0x8228u);
          v17 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v15)(v16, 0, 0);
          if ( v17 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_deinit_hw",
              162,
              "Top deinit failed rc=%d",
              v17);
        }
        if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_deinit_hw",
            166,
            "Disable SFE SOC resource");
        result = cam_sfe_disable_soc_resources(a1 + 96);
        if ( (_DWORD)result )
        {
          v18 = result;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_deinit_hw",
            169,
            "Disable SOC failed");
          result = v18;
        }
        v19 = debug_mdl;
        *(_DWORD *)(a1 + 92) = 0;
        if ( (v19 & 0x40000000) != 0 && !debug_priority )
        {
          v20 = result;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v19 & 0x40000000,
            4,
            "cam_sfe_deinit_hw",
            173,
            "SFE deinit done rc: %d",
            result);
          return v20;
        }
      }
    }
    else
    {
      mutex_unlock(a1);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_deinit_hw",
        131,
        "Unbalanced deinit");
      return 4294967282LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_deinit_hw",
      124,
      "Invalid arguments");
    return 4294967274LL;
  }
  return result;
}
