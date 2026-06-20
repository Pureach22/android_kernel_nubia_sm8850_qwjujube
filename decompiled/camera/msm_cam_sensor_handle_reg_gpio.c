__int64 __fastcall msm_cam_sensor_handle_reg_gpio(unsigned int a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x20
  __int64 v5; // x8
  __int64 v7; // x23
  __int64 v8; // x21
  unsigned int v9; // w22

  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      3,
      "msm_cam_sensor_handle_reg_gpio",
      2125,
      "Input Parameters are not proper");
    return 0;
  }
  v5 = debug_mdl;
  if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
  {
    if ( a1 < 0xE )
      goto LABEL_5;
LABEL_12:
    __break(0x5512u);
LABEL_13:
    v8 = a2;
    v9 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v5 & 0x800000000LL,
      4,
      "msm_cam_sensor_handle_reg_gpio",
      2135,
      "VALID GPIO offset: %d, seqtype: %d",
      a1,
      a1);
    a2 = v8;
    a3 = v9;
LABEL_8:
    cam_res_mgr_gpio_set_value(*(unsigned __int16 *)(a2 + 2 * v3), a3);
    return 0;
  }
  v3 = a3;
  v7 = a2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x800000000LL,
    4,
    "msm_cam_sensor_handle_reg_gpio",
    2129,
    "Seq type: %d, config: %d",
    a1,
    a3);
  a2 = v7;
  a3 = v3;
  if ( a1 >= 0xE )
    goto LABEL_12;
LABEL_5:
  v3 = (int)a1;
  if ( *(_BYTE *)(a2 + (int)a1 + 28) == 1 )
  {
    v5 = debug_mdl;
    if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
      goto LABEL_8;
    goto LABEL_13;
  }
  return 0;
}
