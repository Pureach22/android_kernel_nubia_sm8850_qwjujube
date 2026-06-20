__int64 __fastcall cam_isp_add_csid_reg_update(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  unsigned int v4; // w6
  unsigned int v5; // w7
  __int64 v6; // x21
  int v7; // w23
  int v8; // w9
  __int64 v11; // x10
  __int64 v14; // x8
  __int64 (__fastcall *v15)(__int64, __int64); // x9
  __int64 v16; // x0
  __int64 result; // x0
  int v18; // w21
  __int64 v19; // x2
  unsigned int v20; // w6
  unsigned int v21; // w7
  int v22; // w10
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x8
  __int64 (__fastcall *v27)(__int64, __int64); // x9
  __int64 v28; // x0
  int v29; // w8
  int v30; // w3
  const char *v31; // x5
  __int64 v32; // x4
  int vars0; // [xsp+0h] [xbp+0h]

  if ( (unsigned int)(*(_DWORD *)(a1 + 40) + 1) >= *(_DWORD *)(a1 + 24) )
  {
    v31 = "Insufficient  HW entries :%d %d";
    v32 = 1880;
LABEL_22:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_csid_reg_update",
      v32,
      v31);
    return 4294967274LL;
  }
  if ( !*(_DWORD *)(a3 + 112) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_csid_reg_update",
      1887,
      "No Res for Reg Update");
    return 4294967274LL;
  }
  v4 = *(_DWORD *)(a2 + 20);
  v5 = *(_DWORD *)(a2 + 24);
  if ( v4 <= v5 )
  {
    v31 = "no free mem %u %u %u";
    v32 = 1896;
    goto LABEL_22;
  }
  *(_DWORD *)(a3 + 12) = 0;
  v6 = *(_QWORD *)(a3 + 16);
  v7 = *(unsigned __int8 *)(a3 + 129);
  v8 = *(_DWORD *)(a2 + 24);
  v11 = *(_QWORD *)(a2 + 8);
  *(_DWORD *)(a3 + 8) = v4 - v5;
  *(_WORD *)(a3 + 128) = 0;
  *(_QWORD *)a3 = v11 + (v8 & 0xFFFFFFFC);
  v14 = *(_QWORD *)(v6 + 16);
  v15 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 88);
  v16 = *(_QWORD *)(v14 + 112);
  if ( *((_DWORD *)v15 - 1) != -1055839300 )
    __break(0x8229u);
  result = v15(v16, 3);
  if ( !(_DWORD)result )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_add_csid_reg_update",
        1921,
        "Reg update added for res %d hw_id %d",
        *(_DWORD *)(v6 + 4),
        *(_DWORD *)(*(_QWORD *)(v6 + 16) + 4LL));
    v18 = *(_DWORD *)(a3 + 12);
    v19 = a3;
    if ( v18 )
    {
      cam_isp_update_hw_entry(1, a1, a2, v18, a4 & 1);
      v19 = a3;
    }
    if ( !v7 )
      return 0;
    v20 = *(_DWORD *)(a2 + 20);
    v21 = *(_DWORD *)(a2 + 24) + v18;
    if ( v20 <= v21 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_isp_add_csid_reg_update",
        1937,
        "no free mem %u %u %u",
        v20,
        v21,
        vars0);
      return 0;
    }
    *(_DWORD *)(v19 + 12) = 0;
    v22 = *(_DWORD *)(a2 + 24);
    v23 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(v19 + 8) = v20 - v21;
    v24 = v23 + (v22 & 0xFFFFFFFC);
    v25 = *(_QWORD *)(v19 + 16);
    *(_QWORD *)v19 = v24 + (v18 & 0xFFFFFFFC);
    *(_WORD *)(v19 + 128) = 256;
    v26 = *(_QWORD *)(v25 + 16);
    v27 = *(__int64 (__fastcall **)(__int64, __int64))(v26 + 88);
    v28 = *(_QWORD *)(v26 + 112);
    if ( *((_DWORD *)v27 - 1) != -1055839300 )
      __break(0x8229u);
    v29 = v27(v28, 3);
    result = 0;
    if ( !v29 )
    {
      v30 = *(_DWORD *)(a3 + 12);
      if ( v30 )
        cam_isp_update_hw_entry(4, a1, a2, v30, 0);
      return 0;
    }
  }
  return result;
}
