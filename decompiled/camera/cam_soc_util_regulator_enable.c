__int64 __fastcall cam_soc_util_regulator_enable(
        __int64 a1,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int v12; // w0
  const char *v13; // x5
  unsigned int v14; // w20
  __int64 v15; // x4
  __int64 result; // x0
  unsigned int v17; // w0
  unsigned int v18; // w0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_regulator_enable",
      3933,
      "Invalid NULL parameter");
    return 4294967274LL;
  }
  if ( (int)cam_wrapper_regulator_count_voltages(a1) >= 1 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_regulator_enable",
        3939,
        "[%s] voltage min=%d, max=%d",
        a2,
        a3,
        a4);
    v12 = cam_wrapper_regulator_set_voltage(a1, a3, a4);
    if ( v12 )
    {
      v13 = "%s set voltage failed";
      v14 = v12;
      v15 = 3944;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_regulator_enable",
        v15,
        v13,
        a2);
      return v14;
    }
    v17 = cam_wrapper_regulator_set_load(a1, a5);
    if ( v17 )
    {
      v13 = "%s set optimum mode failed";
      v14 = v17;
      v15 = 3951;
      goto LABEL_13;
    }
  }
  v18 = cam_wrapper_regulator_enable(a1, a2);
  if ( v18 )
  {
    v13 = "%s regulator_enable failed";
    v14 = v18;
    v15 = 3958;
    goto LABEL_13;
  }
  result = a6;
  if ( a6 >= 0x15 )
  {
    msleep(a6);
    return 0;
  }
  if ( a6 )
  {
    usleep_range_state(1000 * a6, 1000 * a6 + 1000, 2);
    return 0;
  }
  return result;
}
