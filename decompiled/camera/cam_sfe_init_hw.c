__int64 __fastcall cam_sfe_init_hw(__int64 a1)
{
  unsigned int v2; // w20
  __int64 result; // x0
  _QWORD *v4; // x20
  unsigned int v5; // w20
  __int64 *v6; // x9
  _DWORD *v7; // x8
  __int64 v8; // x0
  unsigned int v9; // w0
  const char *v10; // x5
  unsigned int v11; // w6
  __int64 v12; // x4
  __int64 *v13; // x9
  _DWORD *v14; // x8
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 *v17; // x9
  _DWORD *v18; // x8
  __int64 v19; // x0
  unsigned int v20; // w0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_init_hw",
      49,
      "Invalid arguments");
    return 4294967274LL;
  }
  mutex_lock(a1);
  v2 = *(_DWORD *)(a1 + 88) + 1;
  *(_DWORD *)(a1 + 88) = v2;
  mutex_unlock(a1);
  if ( v2 < 2 )
  {
    v4 = *(_QWORD **)(a1 + 3680);
    if ( (unsigned int)cam_sfe_enable_soc_resources(a1 + 96) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_init_hw",
        69,
        "Enable SOC failed");
      v5 = -14;
    }
    else
    {
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_init_hw",
          74,
          "SFE SOC resource enabled");
      v6 = (__int64 *)v4[1];
      v7 = (_DWORD *)v6[2];
      if ( !v7 )
        goto LABEL_17;
      v8 = *v6;
      if ( *(v7 - 1) != 1989616049 )
        __break(0x8228u);
      v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v7)(v8, 0, 0);
      if ( v9 )
      {
        v10 = "Top init failed rc=%d";
        v11 = v9;
        v12 = 79;
      }
      else
      {
LABEL_17:
        v13 = (__int64 *)v4[2];
        v14 = (_DWORD *)v13[2];
        if ( !v14 )
          goto LABEL_22;
        v15 = *v13;
        if ( *(v14 - 1) != 1989616049 )
          __break(0x8228u);
        v16 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v14)(v15, 0, 0);
        if ( v16 )
        {
          v10 = "Bus WR init failed rc=%d";
          v11 = v16;
          v12 = 87;
        }
        else
        {
LABEL_22:
          v17 = (__int64 *)v4[3];
          v18 = (_DWORD *)v17[2];
          if ( !v18 )
            goto LABEL_30;
          v19 = *v17;
          if ( *(v18 - 1) != 1989616049 )
            __break(0x8228u);
          v20 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v18)(v19, 0, 0);
          if ( !v20 )
          {
LABEL_30:
            *(_DWORD *)(a1 + 92) = 1;
            return 0;
          }
          v10 = "Bus RD init failed rc=%d";
          v11 = v20;
          v12 = 95;
        }
      }
      v5 = v11;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_init_hw",
        v12,
        v10);
    }
    cam_sfe_deinit_hw(a1);
    return v5;
  }
  else
  {
    result = 0;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_init_hw",
        58,
        "SFE has already been initialized cnt: %d",
        *(_DWORD *)(a1 + 88));
      return 0;
    }
  }
  return result;
}
