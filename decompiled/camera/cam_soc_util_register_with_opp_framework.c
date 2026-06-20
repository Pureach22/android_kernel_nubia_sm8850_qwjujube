__int64 __fastcall cam_soc_util_register_with_opp_framework(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v4; // x0
  unsigned int v5; // w0
  __int64 v6; // x8
  unsigned int v7; // w21
  __int64 result; // x0
  const char *v9; // x6
  unsigned int v10; // w19
  _QWORD v11[10]; // [xsp+8h] [xbp-68h] BYREF
  _QWORD v12[3]; // [xsp+58h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned int *)(a1 + 2796);
  if ( (unsigned int)v1 >= 0x20 )
    goto LABEL_8;
  v2 = a1 + 872;
  v4 = *(_QWORD *)(a1 + 8);
  v12[0] = *(_QWORD *)(v2 + 8 * v1);
  v12[1] = 0;
  v11[0] = v12;
  memset(&v11[1], 0, 72);
  v5 = devm_pm_opp_set_config(v4, v11);
  if ( v5 )
  {
    v6 = *(unsigned int *)(a1 + 2796);
    if ( (unsigned int)v6 <= 0x1F )
    {
      v7 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_register_with_opp_framework",
        4368,
        "%s: Failed to set the SRC clk name (%s) to OPP",
        *(const char **)(a1 + 24),
        *(const char **)(v2 + 8 * v6));
      result = v7;
      goto LABEL_7;
    }
LABEL_8:
    __break(0x5512u);
  }
  result = devm_pm_opp_of_add_table(*(_QWORD *)(a1 + 8));
  if ( (_DWORD)result )
  {
    v9 = *(const char **)(a1 + 24);
    v10 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_register_with_opp_framework",
      4374,
      "%s: Failed to add OPP table",
      v9);
    result = v10;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
