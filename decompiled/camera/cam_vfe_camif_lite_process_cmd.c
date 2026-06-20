__int64 __fastcall cam_vfe_camif_lite_process_cmd(__int64 a1, int a2, _DWORD *a3, int a4)
{
  __int64 v4; // x19
  __int64 (__fastcall *v5)(_QWORD); // x8
  int v8; // w0
  unsigned int v9; // w6
  int v10; // w20
  const char *v11; // x3
  const char *v12; // x5
  __int64 v13; // x4
  __int64 result; // x0
  __int64 v15; // x9
  _DWORD *v16; // x8
  __int64 v17; // x10
  int *v18; // x9
  int v19; // w7
  int v20; // w6
  _DWORD *v21; // x9
  __int64 v22; // x0
  _DWORD *v23; // x19
  _DWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v11 = "cam_vfe_camif_lite_process_cmd";
    v12 = "Invalid input arguments";
    v13 = 363;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v11,
      v13,
      v12);
    goto LABEL_15;
  }
  if ( a2 == 39 )
  {
    result = 0;
    goto LABEL_16;
  }
  if ( a2 == 19 )
    goto LABEL_15;
  if ( a2 != 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_process_cmd",
      379,
      "unsupported process command:%d",
      a2);
    goto LABEL_15;
  }
  if ( a4 != 56 )
  {
    v11 = "cam_vfe_camif_lite_get_reg_update";
    v12 = "Invalid cmd size";
    v13 = 171;
    goto LABEL_14;
  }
  if ( !*(_QWORD *)a3 )
  {
    v11 = "cam_vfe_camif_lite_get_reg_update";
    v12 = "Invalid args";
    v13 = 176;
    goto LABEL_14;
  }
  v4 = *(_QWORD *)(*(_QWORD *)a3 + 48LL);
  if ( !v4 )
  {
    v11 = "cam_vfe_camif_lite_get_reg_update";
    v12 = "Invalid CDM ops";
    v13 = 183;
    goto LABEL_14;
  }
  v5 = *(__int64 (__fastcall **)(_QWORD))(v4 + 24);
  if ( *((_DWORD *)v5 - 1) != 2010610996 )
    __break(0x8228u);
  v8 = v5(1);
  v9 = a3[6];
  v10 = 4 * v8;
  if ( 4 * v8 > v9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_get_reg_update",
      191,
      "buf size:%d is not sufficient, expected: %d",
      v9,
      v8);
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  v15 = *(_QWORD *)(a1 + 24);
  v16 = a3;
  v17 = *(_QWORD *)(v15 + 16);
  v18 = *(int **)(v15 + 32);
  v19 = *(_DWORD *)(v17 + 20);
  v24[0] = v19;
  v20 = *v18;
  v24[1] = *v18;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_get_reg_update",
      199,
      "CAMIF Lite reg_update_cmd %x offset %x",
      v20,
      v19);
    v16 = a3;
  }
  v21 = *(_DWORD **)(v4 + 120);
  v22 = *((_QWORD *)v16 + 2);
  v23 = v16;
  if ( *(v21 - 1) != -1401492769 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, __int64, _DWORD *))v21)(v22, 1, v24);
  result = 0;
  v23[7] = v10;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
