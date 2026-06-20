__int64 __fastcall cam_vfe_init_hw(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 result; // x0
  _QWORD *v6; // x21
  unsigned int v7; // w21
  _DWORD *v8; // x8
  unsigned int v9; // w0
  unsigned int v10; // w0
  const char *v11; // x5
  unsigned int v12; // w6
  __int64 v13; // x4
  __int64 *v14; // x8
  _DWORD *v15; // x9
  __int64 v16; // x0
  unsigned int v17; // w0
  __int64 *v18; // x8
  _DWORD *v19; // x9
  __int64 v20; // x0
  unsigned int v21; // w0
  _DWORD *v22; // x8
  __int64 *v23; // x8
  _DWORD *v24; // x9
  __int64 v25; // x0
  unsigned int v26; // w0
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( a1 )
      goto LABEL_4;
LABEL_43:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_init_hw",
      94,
      "Invalid arguments");
    result = 4294967274LL;
    goto LABEL_44;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_vfe_init_hw",
    92,
    "Enter");
  if ( !a1 )
    goto LABEL_43;
LABEL_4:
  mutex_lock(a1);
  v4 = *(_DWORD *)(a1 + 88) + 1;
  *(_DWORD *)(a1 + 88) = v4;
  mutex_unlock(a1);
  if ( v4 < 2 )
  {
    v6 = *(_QWORD **)(a1 + 3680);
    if ( (unsigned int)cam_vfe_enable_soc_resources(a1 + 96) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_init_hw",
        114,
        "Enable SOC failed");
      v7 = -14;
    }
    else
    {
      if ( !a2 )
        goto LABEL_17;
      v8 = *(_DWORD **)(a2 + 72);
      if ( !v8 )
        goto LABEL_17;
      if ( *(v8 - 1) != -827858501 )
        __break(0x8228u);
      v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v8)(a2, 0, 0);
      if ( v9 )
      {
        v7 = v9;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_init_hw",
          123,
          "init Failed rc=%d",
          v9);
      }
      else
      {
LABEL_17:
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_init_hw",
            128,
            "Enable soc done");
        v10 = cam_vfe_reset(a1, &v27, 4);
        if ( v10 )
        {
          v11 = "Reset Failed rc=%d";
          v12 = v10;
          v13 = 133;
        }
        else
        {
          v14 = (__int64 *)v6[3];
          v15 = (_DWORD *)v14[2];
          v16 = *v14;
          if ( *(v15 - 1) != 1989616049 )
            __break(0x8229u);
          v17 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v15)(v16, 0, 0);
          if ( v17 )
          {
            v11 = "Bus HW init Failed rc=%d";
            v12 = v17;
            v13 = 140;
          }
          else
          {
            v18 = (__int64 *)v6[2];
            v19 = (_DWORD *)v18[2];
            v20 = *v18;
            if ( *(v19 - 1) != 1989616049 )
              __break(0x8229u);
            v21 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v19)(v20, 0, 0);
            if ( v21 )
            {
              v11 = "Top HW init Failed rc=%d";
              v12 = v21;
              v13 = 147;
            }
            else
            {
              v23 = (__int64 *)v6[4];
              if ( !v23 )
                goto LABEL_41;
              v24 = (_DWORD *)v23[2];
              v25 = *v23;
              if ( *(v24 - 1) != 1989616049 )
                __break(0x8229u);
              v26 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v24)(v25, 0, 0);
              if ( !v26 )
              {
LABEL_41:
                result = 0;
                *(_DWORD *)(a1 + 92) = 1;
                goto LABEL_44;
              }
              v11 = "Bus RD HW init Failed rc=%d";
              v12 = v26;
              v13 = 156;
            }
          }
        }
        v7 = v12;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_init_hw",
          v13,
          v11);
        if ( a2 )
        {
          v22 = *(_DWORD **)(a2 + 80);
          if ( v22 )
          {
            if ( *(v22 - 1) != -827858501 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, _QWORD))v22)(a2, 0, 0);
          }
        }
      }
      cam_vfe_disable_soc_resources(a1 + 96);
    }
    mutex_lock(a1);
    --*(_DWORD *)(a1 + 88);
    mutex_unlock(a1);
    result = v7;
  }
  else
  {
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_init_hw",
        103,
        "VFE has already been initialized cnt %d",
        *(_DWORD *)(a1 + 88));
      result = 0;
    }
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
