__int64 __fastcall cam_camsstop_setup_regbase_indices(__int64 a1, __int64 a2, int a3)
{
  unsigned int v4; // w6
  __int64 result; // x0
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  if ( a3 >= 11 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_camsstop_setup_regbase_indices",
      46,
      "invalid num_reg_map=%d",
      a3);
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v4 = *(_DWORD *)(a1 + 120);
  if ( v4 >= 9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_camsstop_setup_regbase_indices",
      52,
      "invalid num_mem_block=%d",
      v4);
    goto LABEL_9;
  }
  if ( (unsigned int)cam_common_util_get_string_index(a1 + 128, v4, "cam_camss", (int *)&v7) || v7 >= a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_camsstop_setup_regbase_indices",
      61,
      "regbase not found for CAM_CPAS_REG_CAMSS");
    goto LABEL_9;
  }
  result = 0;
  *(_DWORD *)(a2 + 8) = v7;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
