__int64 __fastcall cam_vfe_rdi_process_cmd(__int64 a1, int a2, _DWORD *a3, int a4)
{
  __int64 v4; // x20
  __int64 (__fastcall *v5)(_QWORD); // x8
  int v8; // w0
  unsigned int v9; // w6
  int v10; // w19
  const char *v11; // x3
  const char *v12; // x5
  __int64 v13; // x4
  __int64 result; // x0
  __int64 v15; // x10
  _DWORD *v16; // x8
  _DWORD *v17; // x11
  int *v18; // x10
  int v19; // w7
  _DWORD *v20; // x9
  __int64 v21; // x0
  _DWORD *v22; // x20
  _DWORD v23[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v11 = "cam_vfe_rdi_process_cmd";
    v12 = "Error! Invalid input arguments";
    v13 = 351;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v11,
      v13,
      v12);
    goto LABEL_14;
  }
  if ( a2 != 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_rdi_process_cmd",
      362,
      "unsupported RDI process command:%d",
      a2);
    goto LABEL_14;
  }
  if ( a4 != 56 )
  {
    v11 = "cam_vfe_rdi_get_reg_update";
    v12 = "Error - Invalid cmd size";
    v13 = 165;
    goto LABEL_12;
  }
  if ( !*(_QWORD *)a3 )
  {
    v11 = "cam_vfe_rdi_get_reg_update";
    v12 = "Error - Invalid args";
    v13 = 170;
    goto LABEL_12;
  }
  v4 = *(_QWORD *)(*(_QWORD *)a3 + 48LL);
  if ( !v4 )
  {
    v11 = "cam_vfe_rdi_get_reg_update";
    v12 = "Error - Invalid CDM ops";
    v13 = 176;
    goto LABEL_12;
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
      "cam_vfe_rdi_get_reg_update",
      185,
      "Error - buf size:%d is not sufficient, expected: %d",
      v9,
      v10);
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v15 = *(_QWORD *)(a1 + 24);
  v16 = a3;
  v17 = *(_DWORD **)(v15 + 24);
  v18 = *(int **)(v15 + 48);
  v23[0] = *v17;
  v19 = *v18;
  v23[1] = *v18;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_rdi_get_reg_update",
      193,
      "RDI%d reg_update_cmd %x",
      *(_DWORD *)(a1 + 4) - 3,
      v19);
    v16 = a3;
  }
  v20 = *(_DWORD **)(v4 + 120);
  v21 = *((_QWORD *)v16 + 2);
  v22 = v16;
  if ( *(v20 - 1) != -1401492769 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, __int64, _DWORD *))v20)(v21, 1, v23);
  result = 0;
  v22[7] = v10;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
