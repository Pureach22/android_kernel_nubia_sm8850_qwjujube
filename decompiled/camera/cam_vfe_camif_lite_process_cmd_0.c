__int64 __fastcall cam_vfe_camif_lite_process_cmd_0(__int64 a1, int a2, _DWORD *a3, int a4)
{
  const char *v4; // x3
  const char *v5; // x5
  __int64 v6; // x4
  __int64 result; // x0
  __int64 v8; // x20
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x24
  _DWORD *v11; // x23
  int v12; // w0
  unsigned int v13; // w6
  int v14; // w21
  _DWORD *v15; // x9
  __int64 v16; // x10
  _DWORD *v17; // x9
  int v18; // w11
  int v19; // w10
  _DWORD *v20; // x8
  __int64 v21; // x0
  _DWORD *v22; // x19
  __int64 v23; // x20
  _DWORD *v24; // x21
  _DWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v4 = "cam_vfe_camif_lite_process_cmd";
    v5 = "Invalid input arguments";
    v6 = 765;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v4,
      v6,
      v5);
    goto LABEL_9;
  }
  if ( a2 > 24 )
  {
    if ( a2 == 25 )
    {
      v15 = *(_DWORD **)(a1 + 24);
      result = 0;
      v15[13] = a3[3];
      v15[14] = a3[4];
      v15[15] = a3[5];
      v15[16] = a3[6];
      v15[17] = a3[7];
      v15[18] = a3[8];
      v15[19] = a3[9];
      v15[20] = a3[10];
      v15[21] = a3[11];
      v15[22] = a3[12];
      goto LABEL_10;
    }
    if ( a2 == 39 )
    {
      result = 0;
      goto LABEL_10;
    }
    goto LABEL_14;
  }
  if ( a2 != 3 )
  {
    if ( a2 == 19 )
    {
      *(_DWORD *)(*(_QWORD *)(a1 + 24) + 156LL) = *a3;
LABEL_9:
      result = 4294967274LL;
      goto LABEL_10;
    }
LABEL_14:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_process_cmd",
      787,
      "unsupported process command:%d",
      a2);
    goto LABEL_9;
  }
  if ( a4 != 56 )
  {
    v4 = "cam_vfe_camif_lite_get_reg_update";
    v5 = "Invalid cmd size";
    v6 = 177;
    goto LABEL_8;
  }
  if ( !*(_QWORD *)a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_get_reg_update",
      183,
      "Invalid args: cdm args %pK",
      a3);
    goto LABEL_9;
  }
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    v8 = *(_QWORD *)(*(_QWORD *)a3 + 48LL);
    if ( v8 )
      goto LABEL_20;
    goto LABEL_34;
  }
  v23 = a1;
  v24 = a3;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_vfe_camif_lite_get_reg_update",
    188,
    "CAMIF LITE:%d %s get RUP",
    *(_DWORD *)(a1 + 4),
    (const char *)(a1 + 128));
  a1 = v23;
  a3 = v24;
  v8 = *(_QWORD *)(*(_QWORD *)v24 + 48LL);
  if ( !v8 )
  {
LABEL_34:
    v4 = "cam_vfe_camif_lite_get_reg_update";
    v5 = "Invalid CDM ops";
    v6 = 193;
    goto LABEL_8;
  }
LABEL_20:
  v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 24);
  v10 = a1;
  v11 = a3;
  if ( *((_DWORD *)v9 - 1) != 2010610996 )
    __break(0x8228u);
  v12 = v9(1);
  v13 = v11[6];
  v14 = 4 * v12;
  if ( 4 * v12 > v13 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_get_reg_update",
      201,
      "buf size:%d is not sufficient, expected: %d",
      v13,
      v12);
    goto LABEL_9;
  }
  v16 = *(_QWORD *)(v10 + 24);
  v17 = v11;
  v18 = *(_DWORD *)(*(_QWORD *)(v16 + 16) + 40LL);
  v19 = *(_DWORD *)(*(_QWORD *)(v16 + 32) + 12LL);
  v25[0] = v18;
  v25[1] = v19;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_get_reg_update",
      210,
      "CAMIF LITE:%d %s reg_update_cmd 0x%X offset 0x%X",
      *(_DWORD *)(v10 + 4),
      (const char *)(v10 + 128),
      v19,
      v18);
    v17 = v11;
  }
  v20 = *(_DWORD **)(v8 + 120);
  v21 = *((_QWORD *)v17 + 2);
  v22 = v17;
  if ( *(v20 - 1) != -1401492769 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _DWORD *))v20)(v21, 1, v25);
  result = 0;
  v22[7] = v14;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
