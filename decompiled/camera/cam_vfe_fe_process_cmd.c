__int64 __fastcall cam_vfe_fe_process_cmd(__int64 a1, int a2, _DWORD *a3, int a4)
{
  __int64 v4; // x10
  __int64 result; // x0
  const char *v6; // x3
  const char *v7; // x5
  __int64 v8; // x4
  __int64 v9; // x10
  int v10; // w6
  char v11; // w9
  int v12; // w7
  __int64 v13; // x19
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x22
  _DWORD *v16; // x21
  int v17; // w0
  unsigned int v18; // w6
  int v19; // w20
  int v20; // w10
  __int64 v21; // x1
  __int64 v22; // x12
  int v23; // w6
  __int64 v24; // x9
  _DWORD *v25; // x8
  int v26; // w7
  int v27; // w6
  _DWORD *v28; // x9
  __int64 v29; // x0
  _DWORD *v30; // x19
  __int64 v31; // x19
  _DWORD *v32; // x20
  __int64 v33; // x19
  _DWORD *v34; // x20
  __int64 v35; // x19
  _DWORD *v36; // x20
  __int64 v37; // x19
  _DWORD *v38; // x20
  _DWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v6 = "cam_vfe_fe_process_cmd";
    v7 = "Invalid input arguments";
    v8 = 473;
    goto LABEL_8;
  }
  if ( a2 <= 21 )
  {
    if ( a2 != 3 )
    {
      if ( a2 == 18 )
      {
        v4 = *(_QWORD *)(a1 + 24);
        result = 0;
        *(_BYTE *)(v4 + 84) = *a3 == 1;
        goto LABEL_10;
      }
      goto LABEL_16;
    }
    if ( a4 == 56 )
    {
      if ( *(_QWORD *)a3 )
      {
        v13 = *(_QWORD *)(*(_QWORD *)a3 + 48LL);
        if ( v13 )
        {
          v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 24);
          v15 = a1;
          v16 = a3;
          if ( *((_DWORD *)v14 - 1) != 2010610996 )
            __break(0x8228u);
          v17 = v14(1);
          v18 = v16[6];
          v19 = 4 * v17;
          if ( 4 * v17 > v18 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_fe_get_reg_update",
              140,
              "buf size:%d is not sufficient, expected: %d",
              v18,
              v17);
            goto LABEL_9;
          }
          v24 = *(_QWORD *)(v15 + 24);
          v25 = v16;
          v26 = *(_DWORD *)(*(_QWORD *)(v24 + 16) + 36LL);
          v27 = *(_DWORD *)(*(_QWORD *)(v24 + 32) + 72LL);
          v39[0] = v26;
          v39[1] = v27;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_fe_get_reg_update",
              148,
              "CAMIF reg_update_cmd 0x%x offset 0x%x",
              v27,
              v26);
            v25 = v16;
          }
          v28 = *(_DWORD **)(v13 + 120);
          v29 = *((_QWORD *)v25 + 2);
          v30 = v25;
          if ( *(v28 - 1) != -1401492769 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _DWORD *))v28)(v29, 1, v39);
          result = 0;
          v30[7] = v19;
          goto LABEL_10;
        }
        v6 = "cam_vfe_fe_get_reg_update";
        v7 = "Invalid CDM ops";
        v8 = 132;
      }
      else
      {
        v6 = "cam_vfe_fe_get_reg_update";
        v7 = "Invalid args";
        v8 = 125;
      }
    }
    else
    {
      v6 = "cam_vfe_fe_get_reg_update";
      v7 = "Invalid cmd size";
      v8 = 120;
    }
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v6,
      v8,
      v7);
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( a2 == 22 )
  {
    if ( a4 != 72 )
    {
      v6 = "cam_vfe_fe_update";
      v7 = "Invalid cmd size";
      v8 = 81;
      goto LABEL_8;
    }
    v20 = debug_priority;
    v21 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v31 = a1;
      v32 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v21,
        4,
        "cam_vfe_fe_update",
        90,
        "fe_update->min_vbi = 0x%x",
        a3[4]);
      v20 = debug_priority;
      a1 = v31;
      a3 = v32;
      v21 = debug_mdl & 8;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_30;
    }
    else if ( (debug_mdl & 8) == 0 )
    {
      goto LABEL_30;
    }
    if ( !v20 )
    {
      v33 = a1;
      v34 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v21,
        4,
        "cam_vfe_fe_update",
        92,
        "fe_update->hbi_count = 0x%x",
        a3[7]);
      v20 = debug_priority;
      a1 = v33;
      a3 = v34;
      v21 = debug_mdl & 8;
    }
LABEL_30:
    if ( v21 && !v20 )
    {
      v35 = a1;
      v36 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v21,
        4,
        "cam_vfe_fe_update",
        93,
        "fe_update->fs_mode = 0x%x",
        a3[5]);
      v20 = debug_priority;
      a1 = v35;
      a3 = v36;
      v21 = debug_mdl & 8;
      if ( (debug_mdl & 8) != 0 )
      {
LABEL_33:
        if ( !v20 )
        {
          v37 = a1;
          v38 = a3;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v21,
            4,
            "cam_vfe_fe_update",
            95,
            "fe_update->fs_line_sync_en = 0x%x",
            a3[6]);
          v20 = debug_priority;
          a1 = v37;
          a3 = v38;
          v21 = debug_mdl & 8;
        }
      }
    }
    else if ( v21 )
    {
      goto LABEL_33;
    }
    v22 = *(_QWORD *)(a1 + 24);
    result = 0;
    v23 = a3[4] | (a3[5] << 8) | a3[6];
    *(_DWORD *)(v22 + 92) = v23;
    *(_DWORD *)(v22 + 96) = a3[7];
    if ( v21 && !v20 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v21,
        4,
        "cam_vfe_fe_update",
        105,
        "fe_cfg_data = 0x%x",
        v23);
      result = 0;
    }
    goto LABEL_10;
  }
  if ( a2 != 39 )
  {
LABEL_16:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_process_cmd",
      493,
      "unsupported process command:%d",
      a2);
    goto LABEL_9;
  }
  v9 = *(_QWORD *)(a1 + 24);
  v10 = *a3;
  v11 = debug_mdl;
  *(_DWORD *)(v9 + 76) = *a3;
  v12 = a3[1];
  *(_DWORD *)(v9 + 80) = v12;
  if ( (v11 & 8) != 0 )
  {
    result = 0;
    if ( !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v11 & 8,
        4,
        "cam_vfe_fe_blanking_update",
        462,
        "hbi:%d vbi:%d",
        v10,
        v12);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
