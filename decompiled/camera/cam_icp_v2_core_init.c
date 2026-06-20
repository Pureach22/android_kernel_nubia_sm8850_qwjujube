__int64 __fastcall cam_icp_v2_core_init(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x21
  unsigned int v3; // w6
  int v4; // w22
  unsigned int string_index; // w0
  __int64 v8; // x7
  __int64 v9; // x6
  unsigned int v10; // w0
  unsigned int v11; // w0
  const char *v12; // x5
  __int64 v13; // x4
  __int64 result; // x0
  int v15; // w0
  unsigned int v16; // w9
  int v17; // w6
  unsigned int v18; // w8
  int v19; // w6
  int v20; // w8
  unsigned int v21; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3296);
  v3 = *(_DWORD *)(a1 + 120);
  v21 = 0;
  v4 = *(_DWORD *)(v2 + 8);
  if ( v3 < 9 )
  {
    string_index = cam_common_util_get_string_index(a1 + 128, v3, "icp_csr", (int *)&v21);
    v8 = v21;
    v9 = string_index;
    if ( string_index || v21 > 4 )
    {
      v12 = "Failed to get index for icp_csr, rc: %d index: %u num_reg_map: %u";
      v13 = 1405;
      goto LABEL_13;
    }
    a2[6] = v21;
    v10 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "icp_wd0", (int *)&v21);
    v8 = v21;
    v9 = v10;
    if ( v10 || v21 >= 5 )
    {
      v12 = "Failed to get index for icp_wd0, rc: %d index: %u num_reg_map: %u";
      v13 = 1416;
      goto LABEL_13;
    }
    a2[8] = v21;
    if ( v4 == 512 )
    {
      v11 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "icp_cirq", (int *)&v21);
      v8 = v21;
      v9 = v11;
      if ( v11 || v21 >= 5 )
      {
        v12 = "Failed to get index for icp_cirq, rc: %d index: %u num_reg_map: %u";
        v13 = 1428;
LABEL_13:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_v2_setup_register_base_indexes",
          v13,
          v12,
          v9,
          v8,
          5);
        goto LABEL_14;
      }
    }
    else
    {
      LODWORD(v8) = -1;
    }
    a2[7] = v8;
    v15 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "icp_sys", (int *)&v21);
    if ( v15 || v21 >= 5 )
    {
      v16 = -1;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_v2_setup_register_base_indexes",
          1444,
          "Failed to get index for icp_sys, rc: %d index: %u num_reg_map: %u",
          v15,
          v21,
          5);
        v16 = -1;
      }
    }
    else
    {
      v16 = v21;
    }
    a2[9] = v16;
    v17 = cam_common_util_get_string_index(a1 + 128, *(_DWORD *)(a1 + 120), "icp_dom_mask", (int *)&v21);
    if ( v17 || (v18 = v21, v21 >= 5) )
    {
      v18 = -1;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_v2_setup_register_base_indexes",
          1456,
          "Failed to get index for icp_dom_mask, rc: %d index: %u num_reg_map: %u",
          v17,
          v21,
          5);
        v18 = -1;
      }
    }
    a2[10] = v18;
    v19 = *(_DWORD *)(v2 + 8);
    if ( v19 == 512 )
    {
      v20 = a2[7];
    }
    else
    {
      if ( v19 != 513 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_v2_core_init",
          1489,
          "Unsupported ICP HW version: %u",
          v19);
        result = 4294967274LL;
        goto LABEL_34;
      }
      v20 = a2[6];
    }
    result = 0;
    a2[14] = v20;
LABEL_34:
    a2[13] = 2;
    goto LABEL_15;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_v2_setup_register_base_indexes",
    1394,
    "Invalid number of mem blocks: %d",
    v3);
LABEL_14:
  result = 4294967274LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
