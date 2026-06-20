__int64 __fastcall cam_cpastop_setup_regbase_indices(__int64 a1, unsigned int *a2, unsigned int a3)
{
  const char *v4; // x5
  __int64 v5; // x4
  __int64 v6; // x6
  __int64 result; // x0
  int string_index; // w0
  unsigned int v11; // w19
  int v12; // w6
  int v13; // w6
  int v14; // w6
  int v15; // w6
  int v16; // w6
  int v17; // w6
  int v18; // w6
  int v19; // w6
  unsigned int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  if ( (int)a3 >= 11 )
  {
    v4 = "invalid num_reg_map=%d";
    v5 = 450;
    v6 = a3;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_setup_regbase_indices",
      v5,
      v4,
      v6);
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  v6 = *(unsigned int *)(a1 + 120);
  if ( (unsigned int)v6 >= 9 )
  {
    v4 = "invalid num_mem_block=%d";
    v5 = 456;
    goto LABEL_5;
  }
  string_index = cam_common_util_get_string_index(a1 + 128, v6, "cam_cpas_top", (int *)&v20);
  if ( string_index )
  {
    v11 = string_index;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_setup_regbase_indices",
      465,
      "failed to get index for CPASTOP rc=%d",
      string_index);
    result = v11;
    goto LABEL_7;
  }
  if ( v20 >= a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_setup_regbase_indices",
      469,
      "regbase not found for CPASTOP, rc=%d, %d %d",
      0);
    goto LABEL_6;
  }
  *a2 = v20;
  v12 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "cam_camnoc", (int *)&v20);
  if ( v12 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        485,
        "regbase not found for CAMNOC, rc=%d, %d %d",
        v12,
        v20,
        a3);
    a2[1] = -1;
  }
  else
  {
    a2[1] = v20;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        482,
        "regbase found for CAMNOC, rc=%d, %d %d",
        0);
  }
  v13 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "cam_camnoc_rt", (int *)&v20);
  if ( v13 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        498,
        "regbase not found for CAMNOC RT, rc=%d, %d %d",
        v13,
        v20,
        a3);
    a2[5] = -1;
  }
  else
  {
    a2[5] = v20;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        495,
        "regbase found for CAMNOC RT, rc=%d, %d %d",
        0);
  }
  v14 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "cam_camnoc_nrt", (int *)&v20);
  if ( v14 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        511,
        "regbase not found for CAMNOC NRT, rc=%d, %d %d",
        v14,
        v20,
        a3);
    a2[6] = -1;
  }
  else
  {
    a2[6] = v20;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        508,
        "regbase found for CAMNOC NRT, rc=%d, %d %d",
        0);
  }
  v15 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "cam_camnoc_pdx", (int *)&v20);
  if ( v15 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        524,
        "regbase not found for CAMNOC PDX, rc=%d, %d %d",
        v15,
        v20,
        a3);
    a2[7] = -1;
  }
  else
  {
    a2[7] = v20;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        521,
        "regbase found for CAMNOC PDX, rc=%d, %d %d",
        0);
  }
  v16 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "cam_rpmh", (int *)&v20);
  if ( v16 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        537,
        "regbase not found for RPMH, rc=%d, %d %d",
        v16,
        v20,
        a3);
    a2[3] = -1;
  }
  else
  {
    a2[3] = v20;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        534,
        "regbase found for RPMH, rc=%d, %d %d",
        0);
  }
  v17 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "cam_cesta", (int *)&v20);
  if ( v17 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        550,
        "regbase not found for cesta, rc=%d, %d %d",
        v17,
        v20,
        a3);
    a2[4] = -1;
  }
  else
  {
    a2[4] = v20;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        547,
        "regbase found for cesta, rc=%d, %d %d",
        0);
  }
  v18 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "cam_cpas_secure", (int *)&v20);
  if ( v18 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        563,
        "regbase not found for secure, rc=%d, %d %d",
        v18,
        v20,
        a3);
    a2[8] = -1;
  }
  else
  {
    a2[8] = v20;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        560,
        "regbase found for secure, rc=%d, %d %d",
        0);
  }
  v19 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "llcc_regbase", (int *)&v20);
  if ( v19 || v20 >= a3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        576,
        "regbase not found for llcc, rc=%d, %d %d",
        v19,
        v20,
        a3);
    result = 0;
    a2[9] = -1;
  }
  else
  {
    a2[9] = v20;
    result = 0;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_setup_regbase_indices",
        573,
        "regbase found for llcc, rc=%d, %d %d",
        0);
      result = 0;
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
